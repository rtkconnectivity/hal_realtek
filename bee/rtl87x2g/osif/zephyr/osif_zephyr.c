/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "zephyr/kernel.h"
#include "zephyr/kernel/thread.h"
#include <zephyr/multi_heap/shared_multi_heap.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <kernel_internal.h> //for z_idle_threads and arch_kernel_init
#include <zephyr/linker/linker-defs.h>

#include "os_queue.h"
#include "os_msg.h"
#include "os_mem.h"
#include "os_sched.h"
#include "os_sync.h"
#include "os_timer.h"
#include "os_task.h"
#include "os_trace.h"
#include "os_pm.h"

#include "osif_zephyr.h"
#include "trace.h"
#include "mem_types.h"
#include "mem_config.h"
#include "system_rtl876x.h"
#include "rom_api_for_zephyr.h"//for power_manager_slave_register_function_to_return
#include "power_manager_unit_platform.h"//for platform_pm_register_callback_func_with_priority

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(osif);

#define TCM0_START   DT_REG_ADDR(DT_NODELABEL(tcm0))
#define TCM0_SIZE    DT_REG_SIZE(DT_NODELABEL(tcm0))

#define TCM1_START   DT_REG_ADDR(DT_NODELABEL(tcm1))
#define TCM1_SIZE    DT_REG_SIZE(DT_NODELABEL(tcm1))

#define TCM_HEAP_START       DT_REG_ADDR(DT_NODELABEL(tcm_heap))
#define TCM_HEAP_SIZE        DT_REG_SIZE(DT_NODELABEL(tcm_heap))

#define TCM_START 0x100c00
#define TCM_END   0x13cc00
#define TCM_MAX_SIZE   (240 * 1024)

#define EXTRAM_HEAP_START       DT_REG_ADDR(DT_NODELABEL(ext_data_ram_heap))
#define EXTRAM_HEAP_SIZE        DT_REG_SIZE(DT_NODELABEL(ext_data_ram_heap))

#define EXTRAM_START       DT_REG_ADDR(DT_NODELABEL(ext_data_ram))
#define EXTRAM_SIZE        DT_REG_SIZE(DT_NODELABEL(ext_data_ram))

#define EXTRAM_MAX_SIZE   (16 * 1024)

#define END_ADDRESS(start, size) ((start) + (size))

BUILD_ASSERT(EXTRAM_START >= 0x200000 &&
             END_ADDRESS(EXTRAM_START, EXTRAM_SIZE) <= 0x204000,
             "EXTRAM Region is out of bounds");

BUILD_ASSERT(EXTRAM_HEAP_START >= 0x200000 &&
             END_ADDRESS(EXTRAM_HEAP_START, EXTRAM_HEAP_SIZE) <= 0x204000,
             "EXTRAM_HEAP Region is out of bounds");

BUILD_ASSERT(END_ADDRESS(EXTRAM_START, EXTRAM_SIZE) <= EXTRAM_HEAP_START,
             "EXTRAM end address overlaps with EXTRAM_HEAP start address");

BUILD_ASSERT(EXTRAM_SIZE + EXTRAM_HEAP_SIZE <= EXTRAM_MAX_SIZE,
             "Total size of EXTRAM & EXTRAM_HEAP regions exceeds 16KB!");

// Assert for TCM0 Region
BUILD_ASSERT(TCM0_START >= TCM_START &&
             END_ADDRESS(TCM0_START, TCM0_SIZE) <= TCM_END,
             "TCM0 Region is out of bounds");

// Assert for TCM1 Region
BUILD_ASSERT(TCM1_START >= TCM_START &&
             END_ADDRESS(TCM1_START, TCM1_SIZE) <= TCM_END,
             "TCM1 Region is out of bounds");

// Assert for TCM_HEAP Region
BUILD_ASSERT(TCM_HEAP_START >= TCM_START &&
             END_ADDRESS(TCM_HEAP_START, TCM_HEAP_SIZE) <= TCM_END,
             "TCM_HEAP Region is out of bounds");

// Assert for Overlap
BUILD_ASSERT(END_ADDRESS(TCM0_START, TCM0_SIZE) <= TCM1_START,
             "TCM0 end address overlaps with TCM1 start address");

BUILD_ASSERT(END_ADDRESS(TCM1_START, TCM1_SIZE) <= TCM_HEAP_START,
             "TCM1 end address overlaps with TCM_HEAP start address");

// Assert for Total Size
BUILD_ASSERT(TCM0_SIZE + TCM1_SIZE + TCM_HEAP_SIZE <= TCM_MAX_SIZE,
             "Total size of Three regions exceeds 240KB!");

task_sem_item task_sem_array[TASK_SEM_ARRAY_NUMBER] = {0};
Timer_Info timer_number_array[TIMER_NUMBER_MAX];

extern struct k_thread *z_swap_next_thread(void);
extern void os_queue_func_init(void);
/************************************************************ OS INIT & SCHEDULAR ************************************************************/
static struct k_heap data_on_heap;
static struct k_heap buffer_on_heap;
static struct k_heap ext_data_heap;

void os_heap_init_zephyr(void)
{
    // init heap in data on region
    // RAM_TYPE: RAM_TYPE_DATA_ON
    k_heap_init(&data_on_heap, (void *)TCM_HEAP_START, TCM_HEAP_SIZE);

    // init heap in bufferON region
    // RAM_TYPE: RAM_TYPE_BUFFER_ON
    k_heap_init(&buffer_on_heap, (void *)BUFFER_ON_HEAP_ADDR, BUFFER_ON_HEAP_SIZE);

    //  init heap in ext_data_ram region
    // RAM_TYPE: RAM_TYPE_EXT_DATA_SRAM
    k_heap_init(&ext_data_heap, (void *)EXTRAM_HEAP_START, EXTRAM_HEAP_SIZE);
}

void os_init_zephyr(void)
{
    os_heap_init_zephyr();

    return;
}

void os_delay_zephyr(uint32_t ms)
{
    k_sleep(K_MSEC(ms));

    return;
}

uint64_t os_sys_time_get_zephyr(void)
{
    return (uint64_t)k_ticks_to_ms_floor64(sys_clock_tick_get_32());
}

uint64_t os_sys_tick_get_zephyr(void)
{
    return (uint64_t)sys_clock_tick_get_32();
}

bool os_sched_start_zephyr(void)
{
    return true;
}

bool os_sched_stop_zephyr(void)
{
    return true;
}

bool os_sched_suspend_zephyr(void)
{
    k_sched_lock();
    return true;
}

bool os_sched_resume_zephyr(void)
{
    k_sched_unlock();
    return true;
}

bool os_sched_state_get_zephyr(long *p_state)
{
    if (z_swap_next_thread() == NULL)
    {
        *p_state = SCHEDULER_NOT_STARTED;
    }
    else if (_current->base.sched_locked != 0U)
    {
        *p_state = SCHEDULER_SUSPENDED;
    }
    else
    {
        *p_state = SCHEDULER_RUNNING;
    }
    return true;
}

bool os_sched_is_start_zephyr(void)
{
    if (z_swap_next_thread() != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/************************************************************ TASK ************************************************************/
/****************************************************************************/
/* Create os secure task stack so that the task can call NSC APIs           */
/****************************************************************************/
bool os_alloc_secure_ctx_zephyr(uint32_t stack_size)
{
    return true;
}

#ifdef CONFIG_BT
K_THREAD_STACK_DEFINE(lowstack_stack, 768 * 4);
struct k_thread lowstack_thread_data;
#endif
bool os_task_create_zephyr(void **pp_handle, const char *p_name, void (*p_routine)(void *),
                           void *p_param, uint16_t stack_size, uint16_t priority)
{
    k_tid_t ret_thread_handle;

    if (priority > 6 || priority < 0)
    {
        DBG_DIRECT("%s: Invalid priority. Priority is expected to 0 ~ 6.", __func__);
        return false;
    }

    /* The lowstack thread must be able to preempt all native cooperative threads in Zephyr
    (such as bt tx thread, mesh adv thread, BT Mesh settings workq and so on..).
    Otherwise, if lowstack thread is not processed in a timely manner within approximately 40ms,
    it may result in lowstack crashing and subsequently causing no event reply after hci command is sent, leading to a hardfault.

    Therefore, we need to make the lowstack thread a "Meta-IRQ thread", which can preempt coop threads and meta-irq threads.
    Specifically, the priority of lowstack thread is set to K_HIGHEST_THREAD_PRIO with CONFIG_NUM_METAIRQ_PRIORITIES=1.

    Reference: https://docs.zephyrproject.org/latest/kernel/services/threads/index.html#meta-irq-priorities  */

    if (strcmp(p_name, "low_stack_task") == 0)
#ifdef CONFIG_BT
    {
        ret_thread_handle = k_thread_create(&lowstack_thread_data, lowstack_stack, 768 * 4,
                                            (k_thread_entry_t) p_routine, p_param, NULL, NULL,
                                            K_HIGHEST_THREAD_PRIO, 0, K_MSEC(10));
        k_thread_name_set(ret_thread_handle, p_name);
        *pp_handle = &lowstack_thread_data;
        return true;
    }
#else
    {
        DBG_DIRECT("CONFIG_BT not enabled, do not create Lowerstack Task!");
        return true;
    }
#endif

    k_tid_t thread_handle;

    int switch_priority = CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority;

    thread_handle = (struct k_thread *) k_heap_alloc(&data_on_heap,
                                                     sizeof(struct k_thread), K_NO_WAIT);
    if (thread_handle != NULL)
    {
        memset(thread_handle, 0, sizeof(struct k_thread));
    }
    else
    {
        LOG_ERR("alloc thread object failed because data ram heap is full\n");
        return false;
    }
    /****************************** dynamic stack ******************************/
    k_thread_stack_t *stack_buffer;

    stack_buffer = (k_thread_stack_t *) k_heap_aligned_alloc(&data_on_heap, 8,
                                                             stack_size, K_NO_WAIT);
    if (stack_buffer == NULL)
    {
        k_heap_free(&data_on_heap, thread_handle);
        thread_handle = NULL;
        LOG_ERR("alloc thread stack failed because data ram heap is full\n");
        return false;
    }
    memset(stack_buffer, 0, stack_size);
    ret_thread_handle = k_thread_create(thread_handle, stack_buffer, stack_size,
                                        (k_thread_entry_t) p_routine, p_param, NULL, NULL,
                                        switch_priority, 0, K_MSEC(10));

    if (ret_thread_handle != NULL)
    {
        k_thread_name_set(ret_thread_handle, p_name);
    }

    *pp_handle = thread_handle;

    return true;
}

bool os_task_delete_zephyr(void *p_handle)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    if (obj == NULL)
    {
        k_thread_abort(_current);
    }

    k_thread_abort(obj);
    //task signal todo
    return true;
}

bool os_task_suspend_zephyr(void *p_handle)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    k_thread_suspend(obj);

    return true;
}

bool os_task_resume_zephyr(void *p_handle)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    k_thread_resume(obj);

    return true;
}

bool os_task_yield_zephyr(void)
{
    k_yield();

    return true;
}

bool os_task_handle_get_zephyr(void **pp_handle)
{
    if (pp_handle == NULL)
    {
        return false;
    }

    *pp_handle = _current;

    return true;
}

bool os_task_priority_get_zephyr(void *p_handle, uint16_t *p_priority)
{
    if (p_priority == NULL)
    {
        return false;
    }
    struct k_thread *obj;
    uint16_t priority;

    if (p_handle != NULL)
    {
        obj = (struct k_thread *)p_handle;
    }
    else
    {
        obj = _current;
    }
    priority = k_thread_priority_get(obj);
    *p_priority = CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority;

    return true;
}

bool os_task_priority_set_zephyr(void *p_handle, uint16_t priority)
{
    struct k_thread *obj;
    if (priority > 6 || priority < 0)
    {
        DBG_DIRECT("%s: Invalid priority. Priority is expected to 0 ~ 6.", __func__);
        return false;
    }
    uint16_t switch_priority = CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority;

    if (p_handle != NULL)
    {
        obj = (struct k_thread *)p_handle;
    }
    else
    {
        obj = _current;
    }

    k_thread_priority_set(obj, switch_priority);

    return true;
}

bool os_task_signal_create_zephyr(void *p_handle, uint32_t count)
{
    uint8_t i = 0;
    for (i = 0; i < TASK_SEM_ARRAY_NUMBER; i++)
    {
        if (task_sem_array[i].task_handle == NULL && task_sem_array[i].sem_handle == NULL)
        {
            break;
        }
    }

    struct k_sem *sem_obj;
    sem_obj = (struct k_sem *) k_heap_alloc(&data_on_heap, sizeof(struct k_sem), K_NO_WAIT);

    if (sem_obj != NULL)
    {
        memset(sem_obj, 0, sizeof(struct k_sem));
    }
    else
    {
        LOG_ERR("alloc sem object failed because data ram heap is full\n");
        return false;
    }

    int ret = k_sem_init(sem_obj, count, 0xFFFF);

    if (ret == 0 && i < TASK_SEM_ARRAY_NUMBER)
    {
        uint32_t key = arch_irq_lock();
        task_sem_array[i].task_handle = p_handle;
        task_sem_array[i].sem_handle = sem_obj ;
        arch_irq_unlock(key);

        return true;
    }
    else
    {
        return false;
    }
}
/****************************************************************************/
/* Take notify in target task                                              */
/****************************************************************************/
bool os_task_notify_take_zephyr(long xClearCountOnExit, uint32_t xTicksToWait,
                                uint32_t *p_notify)
{
    k_timeout_t wait_ticks;
    if (xTicksToWait == 0xFFFFFFFFUL)
    {
        wait_ticks = K_FOREVER;
    }
    else
    {
        wait_ticks.ticks = xTicksToWait;
    }

    struct k_thread *thread_obj = _current;

    for (uint8_t i = 0; i < TASK_SEM_ARRAY_NUMBER; i++)
    {

        if (task_sem_array[i].task_handle == thread_obj)
        {
            struct k_sem *sem = task_sem_array[i].sem_handle;
            int ret = k_sem_take(sem, wait_ticks);
            if (ret == 0)
            {
                *p_notify = sem->count + 1;
            }
            if (xClearCountOnExit == true)
            {
                sem->count = 0;
            }
            if (ret == 0)
            {
                return true;
            }
        }
    }
    *p_notify = 0;
    return false;
}

/****************************************************************************/
/* Give notify in target task                                              */
/****************************************************************************/
bool os_task_notify_give_zephyr(void *p_handle)
{
    for (uint8_t i = 0; i < TASK_SEM_ARRAY_NUMBER; i++)
    {
        if (task_sem_array[i].task_handle == p_handle)
        {
            struct k_sem *sem = task_sem_array[i].sem_handle;

            k_sem_give(sem);

            return true;
        }
    }
    return false;
}

/****************************************************************************/
/* Task signal recive & send. But these two APIs are difficult to port.
Not recommend to use when not using FreeRTOS */
/****************************************************************************/
bool os_task_signal_send_zephyr(void *p_handle, uint32_t signal)
{
    return true;
}

bool os_task_signal_recv_zephyr(uint32_t *p_signal, uint32_t wait_ms)
{
    return true;
}

void os_task_status_dump_zephyr(void)
{
    return;
}

uint32_t os_lock_zephyr(void)
{
    uint32_t key = arch_irq_lock();

    return key;
}

void os_unlock_zephyr(uint32_t flags)
{
    arch_irq_unlock(flags);
    return;
}

/************************************************************ Sync ************************************************************/
bool os_sem_create_zephyr(void **pp_handle, const char *p_name, uint32_t init_count,
                          uint32_t max_count)
{
    struct k_sem *sem_obj;
    sem_obj = (struct k_sem *) k_heap_alloc(&data_on_heap, sizeof(struct k_sem), K_NO_WAIT);

    if (sem_obj != NULL)
    {
        memset(sem_obj, 0, sizeof(struct k_sem));
    }
    else
    {
        LOG_ERR("alloc sem object failed because data ram heap is full\n");
        return false;
    }

    k_sem_init(sem_obj, init_count, max_count);

    *pp_handle = sem_obj;

    return true;

}

bool os_sem_delete_zephyr(void *p_handle)
{
    struct k_sem *obj;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_sem *)p_handle;

    k_heap_free(&data_on_heap, obj);

    return true;
}

bool os_sem_take_zephyr(void *p_handle, uint32_t wait_ms)
{
    int ret;

    struct k_sem *obj;
    k_timeout_t wait_ticks;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_sem *)p_handle;

    if (wait_ms == 0xFFFFFFFFUL)
    {
        wait_ticks = K_FOREVER;
    }
    else
    {
        wait_ticks = K_MSEC(wait_ms);
    }

    ret = k_sem_take(obj, wait_ticks);

    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool os_sem_give_zephyr(void *p_handle)
{
    struct k_sem *obj;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_sem *)p_handle;
    if (k_sem_count_get(obj) == obj->limit)
    {
        DBG_DIRECT("%s: All tokens have already been released", __func__);
        return false;
    }
    k_sem_give(obj);
    return true;
}

bool os_mutex_create_zephyr(void **pp_handle)
{
    struct k_mutex *mutex_obj;
    mutex_obj = (struct k_mutex *) k_heap_alloc(&data_on_heap, sizeof(struct k_mutex), K_NO_WAIT);

    if (mutex_obj != NULL)
    {
        memset(mutex_obj, 0, sizeof(struct k_mutex));
    }
    else
    {
        LOG_ERR("alloc mutex object failed because data ram heap is full\n");
        return false;
    }

    k_mutex_init(mutex_obj);

    *pp_handle = mutex_obj;

    return true;
}

bool os_mutex_delete_zephyr(void *p_handle)
{
    struct k_mutex *obj;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_mutex *)p_handle;

    k_heap_free(&data_on_heap, obj);

    return true;
}

bool os_mutex_take_zephyr(void *p_handle, uint32_t wait_ms)
{
    int ret;

    struct k_mutex *obj;
    k_timeout_t wait_ticks;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_mutex *)p_handle;

    if (wait_ms == 0xFFFFFFFFUL)
    {
        wait_ticks = K_FOREVER;
    }
    else
    {
        wait_ticks = K_MSEC(wait_ms);
    }

    ret = k_mutex_lock(obj, wait_ticks);

    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool os_mutex_give_zephyr(void *p_handle)
{
    int ret;

    struct k_mutex *obj;

    if (p_handle == NULL)
    {
        return false;
    }

    obj = (struct k_mutex *)p_handle;

    ret = k_mutex_unlock(obj);

    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/************************************************************ msg queue ************************************************************/
bool os_msg_queue_create_intern_zephyr(void **pp_handle, const char *p_name, uint32_t msg_num,
                                       uint32_t msg_size,
                                       const char *p_func, uint32_t file_line)
{
    int ret;
    struct k_msgq *queue_obj;
    void *queue_buffer;
    size_t total_size = msg_size * msg_num;
    if (pp_handle)
    {
        queue_obj = (struct k_msgq *) k_heap_alloc(&data_on_heap, sizeof(struct k_msgq), K_NO_WAIT);
        if (queue_obj != NULL)
        {
            memset(queue_obj, 0, sizeof(struct k_msgq));
        }
        else
        {
            LOG_ERR("alloc queue object failed because data ram heap is full\n");
            return false;
        }

        queue_buffer = k_heap_aligned_alloc(&data_on_heap, 4, total_size, K_NO_WAIT);
        if (queue_buffer != NULL)
        {
            k_msgq_init(queue_obj, queue_buffer, msg_size, msg_num);
            queue_obj->flags = K_MSGQ_FLAG_ALLOC;
            ret = 0;
        }
        else
        {
            k_heap_free(&data_on_heap, queue_obj);
            LOG_ERR("alloc queue buffer failed because data ram heap is full\n");
            ret = -ENOMEM;
        }

        if (ret == 0)
        {
            *pp_handle = queue_obj;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool os_msg_queue_delete_intern_zephyr(void *p_handle, const char *p_func, uint32_t file_line)
{
    struct k_msgq *obj;

    obj = (struct k_msgq *)p_handle;

    if ((obj->flags & K_MSGQ_FLAG_ALLOC) != 0U)
    {
        k_heap_free(&data_on_heap, obj->buffer_start);
        obj->buffer_start = NULL;
        obj->flags &= ~K_MSGQ_FLAG_ALLOC;
        k_heap_free(&data_on_heap, obj);
        return true;
    }

    return false;
}

bool os_msg_queue_peek_intern_zephyr(void *p_handle, uint32_t *p_msg_num,
                                     const char *p_func, uint32_t file_line)
{
    struct k_msgq *obj;

    if (p_handle)
    {
        obj = (struct k_msgq *)p_handle;
        *p_msg_num = obj->used_msgs;
        return true;
    }
    else
    {
        return false;
    }
}

bool os_msg_send_intern_zephyr(void *p_handle, void *p_msg, uint32_t wait_ms,
                               const char *p_func, uint32_t file_line)
{
    int ret;
    struct k_msgq *obj;
    k_timeout_t wait_ticks;

    obj = (struct k_msgq *)p_handle;

    if (wait_ms == 0xFFFFFFFFUL)
    {
        wait_ticks = K_FOREVER;
    }
    else
    {
        wait_ticks = K_MSEC(wait_ms);
    }

    ret = k_msgq_put(obj, p_msg, wait_ticks);

    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool os_msg_recv_intern_zephyr(void *p_handle, void *p_msg, uint32_t wait_ms,
                               const char *p_func, uint32_t file_line)
{
    int ret;
    struct k_msgq *obj;
    k_timeout_t wait_ticks;

    obj = (struct k_msgq *)p_handle;

    if (wait_ms == 0xFFFFFFFFUL)
    {
        wait_ticks = K_FOREVER;
    }
    else
    {
        wait_ticks = K_MSEC(wait_ms);
    }

    ret = k_msgq_get(obj, p_msg, wait_ticks);

    if (ret == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/************************************************************ Mem Management ************************************************************/
/****************************************************************************/
/* Allocate memory                                                          */
/****************************************************************************/
void *os_mem_alloc_intern_zephyr(RAM_TYPE ram_type, size_t size,
                                 const char *p_func, uint32_t file_line)
{
    void *p = NULL;

    switch (ram_type)
    {
    case RAM_TYPE_DATA_ON:
        p = k_heap_alloc(&data_on_heap, size, K_NO_WAIT);
        break;
    case RAM_TYPE_BUFFER_ON:
        p = k_heap_alloc(&buffer_on_heap, size, K_NO_WAIT);
        break;
    case RAM_TYPE_EXT_DATA_SRAM:
        p = k_heap_alloc(&ext_data_heap, size, K_NO_WAIT);
        break;
    default:
        break;
    }

    if (p == NULL)
    {
        LOG_ERR("os_mem_alloc_intern_zephyr alloc failed!\n");
    }

    return p;
}

void *os_mem_zalloc_intern_zephyr(RAM_TYPE ram_type, size_t size,
                                  const char *p_func, uint32_t file_line)
{
    void *p = NULL;
    switch (ram_type)
    {
    case RAM_TYPE_DATA_ON:
        p = k_heap_alloc(&data_on_heap, size, K_NO_WAIT);
        break;
    case RAM_TYPE_BUFFER_ON:
        p = k_heap_alloc(&buffer_on_heap, size, K_NO_WAIT);
        break;
    case RAM_TYPE_EXT_DATA_SRAM:
        p = k_heap_alloc(&ext_data_heap, size, K_NO_WAIT);
        break;
    default:
        break;
    }
    if (p == NULL)
    {
        LOG_ERR("os_mem_zalloc_intern_zephyr alloc failed!\n");
    }
    else
    {
        memset(p, 0, size);
    }
    return p;
}

/****************************************************************************/
/* Allocate aligned memory                                                  */
/****************************************************************************/
void *os_mem_aligned_alloc_intern_zephyr(RAM_TYPE ram_type, size_t size, uint8_t alignment,
                                         const char *p_func, uint32_t file_line)
{
    void *p = NULL;
    switch (ram_type)
    {
    case RAM_TYPE_DATA_ON:
        p = k_heap_aligned_alloc(&data_on_heap, alignment, size, K_NO_WAIT);
        break;
    case RAM_TYPE_BUFFER_ON:
        p = k_heap_aligned_alloc(&buffer_on_heap, alignment, size, K_NO_WAIT);
        break;
    case RAM_TYPE_EXT_DATA_SRAM:
        p = k_heap_aligned_alloc(&ext_data_heap, alignment, size, K_NO_WAIT);
        break;
    default:
        break;
    }
    if (p == NULL)
    {
        LOG_ERR("os_mem_aligned_alloc_intern_zephyr alloc failed!\n");
    }
    return p;
}

/****************************************************************************/
/* Free memory                                                              */
/****************************************************************************/
void os_mem_free_zephyr(void *p_block)
{
    if (p_block == NULL)
    {
        LOG_ERR("Memory free failed, because it is a NULL pointer.\n");
        return;
    }

    if (p_block >= (void *)BUFFER_ON_HEAP_ADDR)
    {
        k_heap_free(&buffer_on_heap, p_block);
    }
    else if (p_block >= (void *)EXT_DATA_SRAM_HEAP_ADDR)
    {
        k_heap_free(&ext_data_heap, p_block);
    }
    else if (p_block >= (void *)DT_REG_ADDR(DT_NODELABEL(tcm_heap)))
    {
        k_heap_free(&data_on_heap, p_block);
    }
    else
    {
        LOG_ERR("Memory free failed, because it is not in the legitable heap region.\n");
    }
    return;
}

/****************************************************************************/
/* Free aligned memory                                                      */
/****************************************************************************/
void os_mem_aligned_free_zephyr(void *p_block)
{
    if (p_block == NULL)
    {
        LOG_ERR("Memory aligned free failed, because it is a NULL pointer.\n");
        return;
    }

    void *p;

    memcpy(&p, (uint8_t *)p_block - sizeof(void *), sizeof(void *));

    if (p >= (void *)BUFFER_ON_HEAP_ADDR)
    {
        k_heap_free(&buffer_on_heap, p);
    }
    else if (p >= (void *)EXT_DATA_SRAM_HEAP_ADDR)
    {
        k_heap_free(&ext_data_heap, p);
    }
    else if (p >= (void *)DT_REG_ADDR(DT_NODELABEL(tcm_heap)))
    {
        k_heap_free(&data_on_heap, p);
    }
    else
    {
        LOG_ERR("Memory aligned free failed, because it is not in the legitable heap region.\n");
    }

    return;
}

/****************************************************************************/
/* Peek unused (available) memory size                                      */
/****************************************************************************/
size_t os_mem_peek_zephyr(RAM_TYPE ram_type)
{
#ifdef CONFIG_SYS_HEAP_RUNTIME_STATS
    struct sys_memory_stats stats;
    uint32_t heap_size;
    switch (ram_type)
    {
    case RAM_TYPE_DATA_ON:
        sys_heap_runtime_stats_get(&data_on_heap.heap, &stats);
        heap_size =  DT_REG_SIZE(DT_NODELABEL(tcm_heap));
        break;
    case RAM_TYPE_BUFFER_ON:
        sys_heap_runtime_stats_get(&buffer_on_heap.heap, &stats);
        heap_size = BUFFER_ON_HEAP_SIZE;
        break;
    case RAM_TYPE_EXT_DATA_SRAM:
        sys_heap_runtime_stats_get(&ext_data_heap.heap, &stats);
        heap_size = EXT_DATA_SRAM_HEAP_SIZE;
        break;
    default:
        printk("Invalid ram_type for os_mem_peek_zephyr!\n");
        return true;
        break;
    }
    printk("RAM type of heap: %d, heap size: %zu, allocated %zu, free %zu, max allocated %zu\n",
           ram_type, heap_size, stats.allocated_bytes, stats.free_bytes,
           stats.max_allocated_bytes);

    /* use DBG_DIRECT when zephyr log system is not initialized*/
    // DBG_DIRECT("RAM type of heap: %d, heap size: %d, allocated %d, free %d, max allocated %d\n",
    //  ram_type, heap_size, stats.allocated_bytes, stats.free_bytes,
    //  stats.max_allocated_bytes);
#endif

    return true;
}
void os_mem_peek_printf_zephyr(void)
{
    return;
}
/****************************************************************************/
/* Check os heap usage                                                      */
/****************************************************************************/
void os_mem_check_heap_usage_zephyr(void)
{
    return;
}

/************************************************************ SW TIMER ************************************************************/


bool os_timer_id_get_zephyr(void **pp_handle, uint32_t *p_timer_id)
{
    uint32_t key = arch_irq_lock();
    if (pp_handle && *pp_handle)
    {
        for (uint8_t i = 0; i < TIMER_NUMBER_MAX; i++)
        {
            if (timer_number_array[i].timer_handle == *pp_handle)
            {
                *p_timer_id = timer_number_array[i].timer_id;
                arch_irq_unlock(key);
                return true;
            }
        }
    }
    arch_irq_unlock(key);
    return false;
}

bool os_timer_create_zephyr(void **pp_handle, const char *p_timer_name, uint32_t timer_id,
                            uint32_t interval_ms, bool reload, void (*p_timer_callback)())
{
    k_timeout_t timer_ticks;
    uint8_t i;

    if (*pp_handle != NULL)
    {
        LOG_ERR("Timer has been created!");
        return false;
    }

    timer_ticks = K_MSEC(interval_ms);

    uint32_t key = arch_irq_lock();

    for (i = 0; i < TIMER_NUMBER_MAX; i++)
    {
        if (timer_number_array[i].timer_handle == 0)
        {
            break;
        }
    }

    if (i == TIMER_NUMBER_MAX)
    {
        arch_irq_unlock(key);
        return false;
    }

    arch_irq_unlock(key);

    struct k_timer *timer_obj;

    timer_obj = (struct k_timer *) k_heap_alloc(&data_on_heap, sizeof(struct k_timer), K_NO_WAIT);
    if (timer_obj != NULL)
    {
        memset(timer_obj, 0, sizeof(struct k_timer));
    }
    else
    {
        LOG_ERR("Alloc timer object failed because data ram heap is full, timer name:%s", p_timer_name);
        return false;
    }

    if (reload == true)
    {
        k_timer_init(timer_obj, (k_timer_expiry_t) p_timer_callback, NULL);
        timer_obj->period = timer_ticks;
    }
    else
    {
        k_timer_init(timer_obj, (k_timer_expiry_t) p_timer_callback, NULL);
        timer_obj->period = K_NO_WAIT;
    }

    k_timeout_t *duration = k_heap_alloc(&data_on_heap, sizeof(k_timeout_t), K_NO_WAIT);

    if (duration != NULL)
    {
        *duration = timer_ticks;
        k_timer_user_data_set(timer_obj, (void *)duration);
    }
    else
    {
        LOG_ERR("Alloc timer userdata failed because data ram heap is full, timer name:%s\n",
                p_timer_name);
        return false;
    }

    key = arch_irq_lock();

    *pp_handle = timer_obj;

    timer_number_array[i].timer_handle = (void *)(*pp_handle);
    timer_number_array[i].timer_id = timer_id;

    arch_irq_unlock(key);

    LOG_DBG("Create timer: %x, timer name:%s\n",
            (unsigned int)*pp_handle, p_timer_name);

    return true;
}

bool os_timer_start_zephyr(void **pp_handle)
{
    struct k_timer *timer = *pp_handle;
    k_timeout_t *tmp;
    if (timer)
    {
        if (!K_TIMEOUT_EQ(timer->period, K_NO_WAIT))
        {
            k_timer_start(timer, timer->period, timer->period);
        }
        else
        {
            tmp = k_timer_user_data_get(timer);
            if (tmp == NULL)
            {
                LOG_ERR("User data in timer %x is NULL! Timer start failed!\n", (unsigned int)timer);
                return false;
            }
            k_timer_start(timer, *tmp, K_NO_WAIT);

        }
        return true;
    }
    LOG_ERR("Timer pointer is NULL! Timer start fail! Second Pointer Addr: %x\n",
            (unsigned int)pp_handle);

    return false;
}

bool os_timer_restart_zephyr(void **pp_handle, uint32_t interval_ms)
{
    struct k_timer *timer = *pp_handle;
    k_timeout_t timer_ticks;
    k_timeout_t *tmp;

    timer_ticks = K_MSEC(interval_ms);

    if (timer && (timer_ticks.ticks > 0))
    {
        if (!K_TIMEOUT_EQ(timer->period, K_NO_WAIT))
        {
            k_timer_start(timer, timer_ticks, timer_ticks);
        }
        else
        {
            tmp = k_timer_user_data_get(timer);
            if (tmp == NULL)
            {
                LOG_ERR("User data in timer %x is NULL! Timer restart failed!\n", (unsigned int)timer);
                return false;
            }
            tmp->ticks = timer_ticks.ticks;
            k_timer_start(timer, timer_ticks, K_NO_WAIT);
        }
        return true;
    }

    LOG_ERR("Timer pointer is NULL! Timer restart fail! Second Pointer Addr: %x\n",
            (unsigned int)pp_handle);
    return false;
}

bool os_timer_stop_zephyr(void **pp_handle)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        return false;
    }

    struct k_timer *timer = *pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL! Timer handle pointer address: %x", __func__,
                   pp_handle);
        return false;
    }

    if (k_timer_remaining_get(timer) == 0)
    {
        DBG_DIRECT("%s: timer is inactive, cannot stop! Timer handle pointer address: %x", __func__,
                   pp_handle);
        return false;
    }

    k_timer_stop(timer);

    return true;
}

bool os_timer_delete_zephyr(void **pp_handle)
{
    struct k_timer *timer = *pp_handle;
    k_timeout_t *tmp;

    if (timer)
    {
        uint32_t key = arch_irq_lock();
        for (uint8_t i = 0; i < TIMER_NUMBER_MAX; i++)
        {
            if (timer_number_array[i].timer_handle == timer)
            {
                timer_number_array[i].timer_handle = 0;
                break;
            }
        }

        k_timer_stop(timer);

        tmp = k_timer_user_data_get(timer);
        if (tmp == NULL)
        {
            LOG_ERR("User data in timer %x is NULL! Timer delete fail!\n", (unsigned int)timer);
            return false;
        }
        k_heap_free(&data_on_heap, tmp);
        timer->user_data = NULL;

        k_heap_free(&data_on_heap, timer);
        *pp_handle = NULL;

        arch_irq_unlock(key);

        return true;
    }

    LOG_ERR("Timer pointer is NULL! Timer delete fail! Second Pointer Addr: %x\n",
            (unsigned int)pp_handle);
    return false;
}

bool os_timer_is_timer_active_zephyr(void **pp_handle)
{
    bool res = false;
    if (pp_handle && *pp_handle)
    {
        struct k_timer *obj = (struct k_timer *)*pp_handle;

        uint32_t key = arch_irq_lock();

        if (k_timer_remaining_get(obj) == 0)
        {
            res = false;
        }
        else
        {
            res = true;
        }
        arch_irq_unlock(key);
    }
    return res;
}

bool os_timer_state_get_zephyr(void **pp_handle, uint32_t *p_timer_state)
{
    if (pp_handle && *pp_handle)
    {
        struct k_timer *obj = (struct k_timer *)*pp_handle;

        uint32_t key = arch_irq_lock();

        if (k_timer_remaining_get(obj) == 0)
        {
            *p_timer_state = 0;
        }
        else
        {
            *p_timer_state = 1;
        }
        arch_irq_unlock(key);

        return true;
    }
    return false;
}

bool os_timer_get_auto_reload_zephyr(void **pp_handle, long *p_autoreload)
{
    if (pp_handle && *pp_handle)
    {
        struct k_timer *obj = (struct k_timer *)*pp_handle;

        uint32_t key = arch_irq_lock();
        if (K_TIMEOUT_EQ(obj->period, K_NO_WAIT))
        {
            *p_autoreload = 0;
        }
        else
        {
            *p_autoreload = 1;
        }
        arch_irq_unlock(key);
    }
    return true;
}

bool os_timer_get_timer_number_zephyr(void **pp_handle, uint8_t *p_timer_num)
{
    uint32_t key = arch_irq_lock();

    if (pp_handle && *pp_handle)
    {
        for (uint8_t i = 0; i < TIMER_NUMBER_MAX; i++)
        {
            if (timer_number_array[i].timer_handle == *pp_handle)
            {
                *p_timer_num = i;
                arch_irq_unlock(key);
                return true;
            }
        }
    }
    *p_timer_num = 0xFF;
    LOG_ERR("Get timer number error! Second Timer Pointer:%x", (unsigned int)pp_handle);
    arch_irq_unlock(key);
    return false;
}

bool os_timer_dump_zephyr(void)
{
    return true;
}

void os_timer_init_zephyr(void)
{
    return;
}

/************************************************************ PM ************************************************************/
/****************************************************************************/
/*dlps restore os kernel scheduler processing                               */
/****************************************************************************/
/* from realtek */
extern void os_pm_store_tickcount(void);
extern PMCheckResult os_pm_check(uint32_t *wakeup_time_diff);
extern T_OS_QUEUE lpm_excluded_handle[PLATFORM_PM_EXCLUDED_TYPE_MAX];
/* from zephyr */
extern int32_t z_get_next_timeout_expiry(void);
extern struct _timeout *get_first_timeout(void);
extern struct _timeout *get_next_timeout(struct _timeout *);
extern void z_timer_expiration_handler(struct _timeout *t);
extern void z_thread_timeout(struct _timeout *t);
extern void sys_clock_announce_only_add_ticks(int32_t ticks);

void os_pm_return_to_idle_task_zephyr(void)
{
    arch_kernel_init();//perform arm v81mainline initialization: including fault exception init & msp setting.

    RamVectorTableUpdate(GDMA0_Channel9_VECTORn, _isr_wrapper);

    NVIC_SetPriority(PendSV_IRQn, 0xff);
    NVIC_SetPriority(SysTick_IRQn, 0xff);

    uint32_t z_idle_stack_ptr;
    struct k_thread *thread = &z_idle_threads[0];

    z_idle_stack_ptr = thread->stack_info.start + thread->stack_info.size - thread->stack_info.delta;

    __set_PSP(z_idle_stack_ptr);
    __ISB();

    __set_CONTROL(__get_CONTROL() | BIT1);
    __ISB();

    extern void z_thread_entry(k_thread_entry_t, void *, void *, void *);
    extern void idle(void *, void *, void *);
    z_thread_entry(idle, 0, 0, 0);
    return;
}

bool os_sched_restore_zephyr(void)
{
    extern void prvSetupFPU(void); //do zephyr need it?
    prvSetupFPU();

    return true;
}

void os_pm_store_zephyr(void)
{
    os_pm_store_tickcount();
}

void os_pm_restore_zephyr(void)
{
    //os_pm_restore_tickcount();

    os_sched_restore_zephyr();
}

void os_systick_handler_zephyr(void)
{
    sys_clock_announce_only_add_ticks(1);
    return;
}

uint64_t os_sys_tick_increase_zephyr(uint32_t tick_increment)
{
    int64_t old_tick = sys_clock_tick_get();
    sys_clock_announce_only_add_ticks(tick_increment);
    return old_tick;
}

uint32_t os_sys_tick_rate_get_zephyr(void)
{
    return (uint32_t)CONFIG_SYS_CLOCK_TICKS_PER_SEC;
}

uint32_t os_sys_tick_clk_get_zephyr(void)
{
    return (uint32_t)CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC;
}

uint32_t os_pm_next_timeout_value_get_zephyr(void)
{
    /* Solution with the exclude timer mechanism. */
    uint32_t timeout_tick_res = 0xFFFFFFFF;
    uint32_t timeout_tick = 0;
    struct k_timer *timer;
    struct k_thread *thread;

    bool handle_checked;

    for (struct _timeout *t = get_first_timeout(); t != NULL; t = get_next_timeout(t))
    {
        handle_checked = true;
        timeout_tick += t->dticks;

        if (t->fn == z_timer_expiration_handler) //z_timer_expiration_handler
        {
            timer = CONTAINER_OF(t, struct k_timer, timeout);
            T_OS_QUEUE_ELEM *p_cur_queue_item = lpm_excluded_handle[0].p_first;
            while (p_cur_queue_item != NULL)
            {
                void *cur_excluded_handle = *(((PlatformPMExcludedHandleQueueElem *)p_cur_queue_item)->handle);
                if (cur_excluded_handle != NULL)
                {
                    if (timer == cur_excluded_handle)
                    {
                        long is_auto_reload;
                        os_timer_get_auto_reload_zephyr(&cur_excluded_handle, &is_auto_reload);
                        if (is_auto_reload)
                        {
                            LOG_ERR("[PM]!!handle=0x%x, exclude timer cannot be auto_reload\n",
                                    (unsigned int)cur_excluded_handle);
                            __ASSERT(0, "[PM]!!handle=0x%x", (unsigned int) cur_excluded_handle);
                        }
                        handle_checked = false;
                        break;
                    }
                }
                p_cur_queue_item = p_cur_queue_item->p_next;
            }

            if (handle_checked)
            {
                timeout_tick_res = timeout_tick;
                break;
            }
        }
        else if (t->fn == z_thread_timeout) //z_thread_timeout
        {
            thread = CONTAINER_OF(t, struct k_thread, base.timeout);

            T_OS_QUEUE_ELEM *p_cur_queue_item = lpm_excluded_handle[1].p_first;
            while (p_cur_queue_item != NULL)
            {
                void *cur_excluded_handle = *(((PlatformPMExcludedHandleQueueElem *)p_cur_queue_item)->handle);
                if (cur_excluded_handle != NULL)
                {
                    if (thread == cur_excluded_handle)
                    {
                        handle_checked = false;
                        break;
                    }
                }
                p_cur_queue_item = p_cur_queue_item->p_next;
            }
            if (handle_checked)
            {
                timeout_tick_res = timeout_tick;
                break;
            }
        }
        else//other timeout type(e.g. workqueue item)
        {
            timeout_tick_res = timeout_tick;
            break;
        }
    }

    return timeout_tick_res;
}

#define RTK_PM_WORKQ_STACK_SIZE 768
#define RTK_PM_WORKQ_PRIORITY   K_HIGHEST_THREAD_PRIO

K_THREAD_STACK_DEFINE(rtk_pm_workq_stack_area, RTK_PM_WORKQ_STACK_SIZE);

struct k_work_q rtk_pm_workq;
static struct pend_call pc;

void pendcall_handler(struct k_work *item)
{
    struct pend_call *pc = CONTAINER_OF(item, struct pend_call, work);
    pc->pend_func(pc->para1, pc->para2);
}

void os_pm_bottom_half_zephyr(void (*pend_func)(void))
{
    pc.pend_func = (pend_func_t)pend_func;
    pc.para1 = NULL;
    pc.para2 = 0;
    k_work_init(&pc.work, pendcall_handler);
    k_work_submit_to_queue(&rtk_pm_workq, &pc.work);
}

void os_pm_init_zephyr(void)
{
    power_manager_slave_register_function_to_return(os_pm_return_to_idle_task_zephyr);

    platform_pm_register_schedule_bottom_half_callback_func(os_pm_bottom_half_zephyr);

    platform_pm_register_callback_func_with_priority((void *)os_pm_check, PLATFORM_PM_CHECK, 1);
    platform_pm_register_callback_func_with_priority((void *)os_pm_store_zephyr, PLATFORM_PM_STORE, 1);
    platform_pm_register_callback_func_with_priority((void *)os_pm_restore_zephyr, PLATFORM_PM_RESTORE,
                                                     1);

    k_work_queue_init(&rtk_pm_workq);
    k_work_queue_start(&rtk_pm_workq, rtk_pm_workq_stack_area,
                       K_THREAD_STACK_SIZEOF(rtk_pm_workq_stack_area), RTK_PM_WORKQ_PRIORITY,
                       NULL);
    return;
}

/* ************************************************* OSIF PATCH ************************************************* */
void osif_mem_func_init_zephyr()
{
    os_mem_alloc_intern = os_mem_alloc_intern_zephyr;
    os_mem_zalloc_intern = os_mem_zalloc_intern_zephyr;
    os_mem_aligned_alloc_intern = os_mem_aligned_alloc_intern_zephyr;
    os_mem_free = os_mem_free_zephyr;
    os_mem_aligned_free = os_mem_aligned_free_zephyr;
    os_mem_peek = os_mem_peek_zephyr;
    os_mem_peek_printf = os_mem_peek_printf_zephyr;
    os_mem_check_heap_usage = os_mem_check_heap_usage_zephyr;
}

void osif_msg_func_init_zephyr()
{
    os_msg_queue_create_intern = os_msg_queue_create_intern_zephyr;
    os_msg_queue_delete_intern = os_msg_queue_delete_intern_zephyr;
    os_msg_queue_peek_intern = os_msg_queue_peek_intern_zephyr;
    os_msg_send_intern = os_msg_send_intern_zephyr;
    os_msg_recv_intern = os_msg_recv_intern_zephyr;
}

void osif_sched_func_init_zephyr(void)
{
    os_init = os_init_zephyr;

    os_delay = os_delay_zephyr;
    os_sys_time_get = os_sys_time_get_zephyr;
    os_sys_tick_get = os_sys_tick_get_zephyr;
    os_sched_start = os_sched_start_zephyr;
    os_sched_stop = os_sched_stop_zephyr;
    os_sched_suspend = os_sched_suspend_zephyr;
    os_sched_resume = os_sched_resume_zephyr;
    os_sched_state_get = os_sched_state_get_zephyr;
    os_sched_is_start = os_sched_is_start_zephyr;
}

void osif_sync_func_init_zephyr(void)
{
    os_lock = os_lock_zephyr;
    os_unlock = os_unlock_zephyr;
    os_sem_create = os_sem_create_zephyr;
    os_sem_delete = os_sem_delete_zephyr;
    os_sem_take = os_sem_take_zephyr;
    os_sem_give = os_sem_give_zephyr;
    os_mutex_create = os_mutex_create_zephyr;
    os_mutex_delete = os_mutex_delete_zephyr;
    os_mutex_take = os_mutex_take_zephyr;
    os_mutex_give = os_mutex_give_zephyr;
}

void osif_task_func_init_zephyr(void)
{
    os_alloc_secure_ctx = os_alloc_secure_ctx_zephyr;
    os_task_create = os_task_create_zephyr;
    os_task_delete = os_task_delete_zephyr;
    os_task_suspend = os_task_suspend_zephyr;
    os_task_resume = os_task_resume_zephyr;
    os_task_yield = os_task_yield_zephyr;
    os_task_handle_get = os_task_handle_get_zephyr;
    os_task_priority_get = os_task_priority_get_zephyr;
    os_task_priority_set = os_task_priority_set_zephyr;
    os_task_signal_send = os_task_signal_send_zephyr;
    os_task_signal_recv = os_task_signal_recv_zephyr;
    os_task_signal_create = os_task_signal_create_zephyr;
    os_task_notify_take = os_task_notify_take_zephyr;
    os_task_notify_give = os_task_notify_give_zephyr;
    os_task_status_dump = os_task_status_dump_zephyr;
}

void osif_timer_func_init_zephyr(void)
{
    os_timer_id_get = os_timer_id_get_zephyr;
    os_timer_create = os_timer_create_zephyr;
    os_timer_start = os_timer_start_zephyr;
    os_timer_restart = os_timer_restart_zephyr;
    os_timer_stop = os_timer_stop_zephyr;
    os_timer_delete = os_timer_delete_zephyr;
    os_timer_is_timer_active = os_timer_is_timer_active_zephyr;
    os_timer_state_get = os_timer_state_get_zephyr;
    os_timer_get_auto_reload = os_timer_get_auto_reload_zephyr;
    os_timer_get_timer_number = os_timer_get_timer_number_zephyr;
    os_timer_dump = os_timer_dump_zephyr;
    os_timer_init = os_timer_init_zephyr;
}

extern bool os_register_pm_excluded_handle_imp(void **handle, PlatformExcludedHandleType type);
extern bool os_unregister_pm_excluded_handle_imp(void **handle, PlatformExcludedHandleType type);
void osif_pm_func_init_zephyr(void)
{
    os_pm_init = os_pm_init_zephyr;
    os_sched_restore = os_sched_restore_zephyr;
    os_systick_handler = os_systick_handler_zephyr;
    os_sys_tick_rate_get = os_sys_tick_rate_get_zephyr;
    os_sys_tick_clk_get = os_sys_tick_clk_get_zephyr;
    os_sys_tick_increase = os_sys_tick_increase_zephyr;

    os_pm_next_timeout_value_get = os_pm_next_timeout_value_get_zephyr;

    os_register_pm_excluded_handle = os_register_pm_excluded_handle_imp;
    os_unregister_pm_excluded_handle = os_unregister_pm_excluded_handle_imp;
}

void os_zephyr_patch_init(void)
{
    osif_mem_func_init_zephyr();
    osif_msg_func_init_zephyr();
    os_queue_func_init();
    osif_sched_func_init_zephyr();
    osif_sync_func_init_zephyr();
    osif_task_func_init_zephyr();
    osif_timer_func_init_zephyr();
    osif_pm_func_init_zephyr();
}
