#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "zephyr/kernel.h"
#include "zephyr/kernel/thread.h"
#include <zephyr/sys/sys_heap.h>
#include <zephyr/sys/multi_heap.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <kernel_internal.h> //for z_idle_threads and arch_kernel_init

#include "patch_os.h"
#include "os_pm.h"
#include "os_queue.h"
#include "mem_types.h"
#include "osif_zephyr.h"
#include "dlps.h"
#include "trace.h"

// extern function
extern void sys_clock_announce_only_add_ticks(int32_t ticks);
extern void z_thread_timeout(struct _timeout *t);
extern struct _timeout *get_first_timeout(void);
extern struct _timeout *get_next_timeout(struct _timeout *t);
typedef void (*PMFuncToReturn)(void);
extern void power_manager_slave_register_function_to_return(PMFuncToReturn func);
extern void (*platform_pm_register_callback_func_with_priority)(void *, PlatformPMStage, int8_t);
extern struct k_thread *z_swap_next_thread(void);
extern void platform_pm_register_schedule_bottom_half_callback_func(PlatformPMScheduleBottomHalfFunc
                                                                    cb_func);
// extern variable
extern T_OS_QUEUE lpm_excluded_handle[PLATFORM_PM_EXCLUDED_TYPE_MAX];

/************************************************************ Mem Management ************************************************************/
static struct k_heap k_heap_array[RAM_TYPE_NUM];
struct sys_multi_heap multi_heap;

#define MULTI_HEAP_ADD(ram_type, node_label) \
    k_heap_init(&k_heap_array[ram_type],    \
                (void *)(DT_REG_ADDR(DT_NODELABEL(node_label))),    \
                DT_REG_SIZE(DT_NODELABEL(node_label))); \
    sys_multi_heap_add_heap(&multi_heap, &k_heap_array[ram_type].heap, NULL);

static void *os_heap_choice(struct sys_multi_heap *mheap, void *cfg, size_t align, size_t size)
{
    void *p = NULL;
    RAM_TYPE ram_type = (RAM_TYPE)cfg;

    p = k_heap_aligned_alloc(&k_heap_array[ram_type], align, size, K_NO_WAIT);

    if (p == NULL)
    {
        DBG_DIRECT("os_mem_alloc_intern_zephyr alloc failed! ram_type:%d alloc_size:0x%x", ram_type, size);
#ifdef CONFIG_SYS_HEAP_RUNTIME_STATS
        extern bool os_mem_peek_zephyr(RAM_TYPE ram_type, size_t *p_size);
        size_t p_size;
        os_mem_peek_zephyr(RAM_TYPE_DATA_ON, &p_size);
        os_mem_peek_zephyr(RAM_TYPE_BUFFER_ON, &p_size);
#endif
    }

    return p;
}

void os_heap_init_zephyr(void)
{
    // init all heap region, such as data on region, bufferON region

    static atomic_t state;

    if (!atomic_cas(&state, 0, 1))
    {
        DBG_DIRECT("os_heap_ini atomic operation failed!");
        return;
    }
    sys_multi_heap_init(&multi_heap, os_heap_choice);
    atomic_set(&state, 1);

    /* ram type: RAM_TYPE_DATA_ON */
    MULTI_HEAP_ADD(RAM_TYPE_DATA_ON, heap0);

    /* ram type: RAM_TYPE_BUFFER_ON */
    MULTI_HEAP_ADD(RAM_TYPE_BUFFER_ON, heap1);

}

bool os_init_zephyr(void)
{
    os_heap_init_zephyr();

    return true;
}

/****************************************************************************/
/* Allocate memory                                                          */
/****************************************************************************/
bool os_mem_alloc_intern_zephyr(RAM_TYPE ram_type, size_t size,
                                const char *p_func, uint32_t file_line, void **pp)
{
    ARG_UNUSED(p_func);
    ARG_UNUSED(file_line);
    *pp = NULL;
    *pp = sys_multi_heap_alloc(&multi_heap, (void *)ram_type, size);
    if (*pp == NULL)
    {
        DBG_DIRECT("os_mem_alloc_intern_zephyr alloc failed!");
    }
    return true;
}

bool os_mem_zalloc_intern_zephyr(RAM_TYPE ram_type, size_t size,
                                 const char *p_func, uint32_t file_line, void **pp)
{
    ARG_UNUSED(p_func);
    ARG_UNUSED(file_line);
    *pp = NULL;
    *pp = sys_multi_heap_alloc(&multi_heap, (void *)ram_type, size);
    if (*pp == NULL)
    {
        DBG_DIRECT("os_mem_zalloc_intern_zephyr alloc failed! ram_type:%d", ram_type);
    }
    else
    {
        memset(*pp, 0, size);
    }
    return true;
}

/****************************************************************************/
/* Allocate aligned memory                                                  */
/****************************************************************************/
bool os_mem_aligned_alloc_intern_zephyr(RAM_TYPE ram_type, size_t size, uint8_t alignment,
                                        const char *p_func, uint32_t file_line, void **pp)
{
    ARG_UNUSED(p_func);
    ARG_UNUSED(file_line);
    *pp = NULL;
    *pp = sys_multi_heap_aligned_alloc(&multi_heap, (void *)ram_type,
                                       alignment, size);
    if (*pp == NULL)
    {
        DBG_DIRECT("os_mem_aligned_alloc_intern_zephyr alloc failed!");
        return 0;
    }
    return true;
}

/****************************************************************************/
/* Free memory                                                              */
/****************************************************************************/

/*
 * Original sys_multi_heap_free() using sys_heap API is not processing in critical section.
 * Implement sys_multi_heap_free_kheap() with kheap API to make sure os_mem_free is thread-safe.
 */
void sys_multi_heap_free_kheap(struct sys_multi_heap *mheap, void *block)
{
    const struct sys_multi_heap_rec *heap;

    heap = sys_multi_heap_get_heap(mheap, block);

    if (heap != NULL)
    {
        k_heap_free((struct k_heap *)heap->heap, block);
    }
}

bool os_mem_free_zephyr(void *p_block)
{
    sys_multi_heap_free_kheap(&multi_heap, p_block);
    return true;
}

/****************************************************************************/
/* Free aligned memory                                                      */
/****************************************************************************/
bool os_mem_aligned_free_zephyr(void *p_block)
{
    sys_multi_heap_free_kheap(&multi_heap, p_block);
    return true;
}

/****************************************************************************/
/* Peek unused (available) memory size                                      */
/****************************************************************************/
bool os_mem_peek_zephyr(RAM_TYPE ram_type, size_t *p_size)
{

#ifdef CONFIG_SYS_HEAP_RUNTIME_STATS
    struct sys_memory_stats stats;
    uint32_t heap_size;

    sys_heap_runtime_stats_get(&(k_heap_array[ram_type].heap), &stats);
    *p_size = stats.free_bytes;
    if (ram_type == RAM_TYPE_DATA_ON)
    {
        heap_size =  DT_REG_SIZE(DT_NODELABEL(heap0));
    }
    else
    {
        heap_size =  DT_REG_SIZE(DT_NODELABEL(heap1));
    }

    /* use DBG_DIRECT when zephyr log system is not initialized*/
    DBG_DIRECT("RAM type of heap: %d, heap size: %d, allocated %d, free %d, max allocated %d\n",
               ram_type, heap_size, stats.allocated_bytes, stats.free_bytes,
               stats.max_allocated_bytes);

#else
    DBG_DIRECT("System heap runtime statistics not enabled");
#endif
    return true;
}
void os_mem_peek_printf_zephyr(void)
{
    size_t a;
    os_mem_peek_zephyr(0, &a);
    os_mem_peek_zephyr(1, &a);
    return;
}
/****************************************************************************/
/* Check os heap usage                                                      */
/****************************************************************************/
void os_mem_check_heap_usage_zephyr(void)
{
    DBG_DIRECT("Zephyr does not support os_mem_check_heap_usage yet!");
    return;
}

/************************************************************ msg queue ************************************************************/
bool os_msg_queue_create_intern_zephyr(void **pp_handle, uint32_t msg_num, uint32_t msg_size,
                                       const char *p_func, uint32_t file_line, bool *p_result)
{
    int ret;
    struct k_msgq *queue_obj;
    void *queue_buffer;
    size_t total_size = msg_size * msg_num;
    if (pp_handle)
    {
        /* alloc k_msgq */
        queue_obj = sys_multi_heap_alloc(&multi_heap, (void *)RAM_TYPE_DATA_ON, sizeof(struct k_msgq));
        if (queue_obj != NULL)
        {
            memset(queue_obj, 0, sizeof(struct k_msgq));
            *pp_handle = queue_obj;

            /* alloc msgq buffer */
            queue_buffer = sys_multi_heap_aligned_alloc(&multi_heap, (void *)RAM_TYPE_DATA_ON,
                                                        4, total_size);
            if (queue_buffer != NULL)
            {
                k_msgq_init(queue_obj, queue_buffer, msg_size, msg_num);
                queue_obj->flags = K_MSGQ_FLAG_ALLOC;
                ret = 0;
            }
            else
            {
                sys_multi_heap_free_kheap(&multi_heap, queue_obj);
                DBG_DIRECT("alloc queue buffer failed because data ram heap is full");
                ret = -ENOMEM;
            }
        }
        else
        {
            DBG_DIRECT("alloc queue object failed because data ram heap is full");
            ret = -ENOMEM;
        }

        *p_result = (ret == 0) ? true : false;

    }
    else
    {
        *p_result = false;
    }
    return true;
}

bool os_msg_queue_delete_intern_zephyr(void *p_handle, const char *p_func, uint32_t file_line,
                                       bool *p_result)
{
    struct k_msgq *obj;

    obj = (struct k_msgq *)p_handle;

    if ((obj->flags & K_MSGQ_FLAG_ALLOC) != 0U)
    {
        sys_multi_heap_free_kheap(&multi_heap, obj->buffer_start);
        obj->buffer_start = NULL;
        obj->flags &= ~K_MSGQ_FLAG_ALLOC;
        sys_multi_heap_free_kheap(&multi_heap, obj);
        *p_result = true;
        return true;
    }
    *p_result = false;
    return true;
}

bool os_msg_queue_peek_intern_zephyr(void *p_handle, uint32_t *p_msg_num,
                                     const char *p_func, uint32_t file_line, bool *p_result)
{
    struct k_msgq *obj;

    if (p_handle)
    {
        obj = (struct k_msgq *)p_handle;
        // *p_msg_num = obj->used_msgs;
        *p_msg_num = k_msgq_num_used_get(obj);
        *p_result = true;
    }
    else
    {
        *p_result = false;
    }
    return true;
}

bool os_msg_send_intern_zephyr(void *p_handle, void *p_msg, uint32_t wait_ms,
                               const char *p_func, uint32_t file_line, bool *p_result)
{
    int ret;
    struct k_msgq *obj;
    k_timeout_t wait_ticks;

    obj = (struct k_msgq *)p_handle;

    wait_ticks = (wait_ms == 0xFFFFFFFFUL) ? K_FOREVER : K_MSEC(wait_ms);
    ret = k_msgq_put(obj, p_msg, wait_ticks);

    *p_result = (ret == 0) ? true : false;
    return true;
}

bool os_msg_recv_intern_zephyr(void *p_handle, void *p_msg, uint32_t wait_ms,
                               const char *p_func, uint32_t file_line, bool *p_result)
{
    int ret;
    struct k_msgq *obj;
    k_timeout_t wait_ticks;

    obj = (struct k_msgq *)p_handle;

    wait_ticks = (wait_ms == 0xFFFFFFFFUL) ? K_FOREVER : K_MSEC(wait_ms);
    ret = k_msgq_get(obj, p_msg, wait_ticks);

    *p_result = (ret == 0) ? true : false;
    return true;
}
/************************************************************ SCHEDULAR ************************************************************/
bool os_sched_start_zephyr(bool *p_result)
{
    DBG_DIRECT("Zephyr doesnot support os_sched_start!");
    *p_result = true;
    return true;
}

bool os_sched_suspend_zephyr(bool *p_result)
{
    *p_result = true;
    k_sched_lock();
    return true;
}

bool os_sched_resume_zephyr(bool *p_result)
{
    *p_result = true;
    k_sched_unlock();
    return true;
}

bool os_sched_state_get_zephyr(SCHEDULER_STATE *p_result)
{

    if (z_swap_next_thread() == NULL)
    {
        *p_result = SCHEDULER_NOT_STARTED;
    }
    else if (_current->base.sched_locked != 0U)
    {
        *p_result = SCHEDULER_SUSPENDED;
    }
    else
    {
        *p_result = SCHEDULER_RUNNING;
    }
    return true;
}

bool os_sched_is_start_zephyr(bool *p_result)
{
    if (z_swap_next_thread() != NULL)
    {
        *p_result = true;
    }
    else
    {
        *p_result = false;
    }
    return true;
}

bool os_delay_zephyr(uint32_t ms)
{
    k_sleep(K_MSEC(ms));
    return true;
}

/************************************************************ SYSTICK ************************************************************/

bool os_sys_time_get_zephyr(uint64_t *p_time_ms)
{
    *p_time_ms = (uint64_t)k_ticks_to_ms_floor64(sys_clock_tick_get_32());
    return true;
}

bool os_sys_tick_get_zephyr(uint64_t *p_sys_tick)
{
    *p_sys_tick = (uint64_t)sys_clock_tick_get_32();
    return true;
}

bool os_systick_handler_zephyr(void)
{
    sys_clock_announce_only_add_ticks(1);
    return true;
}

bool os_sys_tick_increase_zephyr(uint32_t tick_increment,
                                 k_ticks_t *p_old_tick)
{
    *p_old_tick = sys_clock_tick_get();
    sys_clock_announce_only_add_ticks(tick_increment);
    return true;
}
/************************************************************ sync ************************************************************/

bool os_lock_zephyr(uint32_t *p_flags)
{
    *p_flags = arch_irq_lock();
    return true;
}

bool os_unlock_zephyr(uint32_t flags)
{
    arch_irq_unlock(flags);
    return true;
}

bool os_sem_create_zephyr(void **pp_handle, const char *p_name, uint32_t init_count,
                          uint32_t max_count, bool *p_result)
{
    struct k_sem *sem_obj;
    sem_obj = (struct k_sem *) sys_multi_heap_alloc(&multi_heap, RAM_TYPE_DATA_ON,
                                                    sizeof(struct k_sem));

    if (sem_obj != NULL)
    {
        memset(sem_obj, 0, sizeof(struct k_sem));
        *pp_handle = sem_obj;
    }
    else
    {
        DBG_DIRECT("alloc sem object failed because data ram heap is full");
        *p_result = false;
    }

    k_sem_init(sem_obj, init_count, max_count);
    *p_result = true;
    return true;
}

bool os_sem_delete_zephyr(void *p_handle, bool *p_result)
{
    struct k_sem *obj;

    if (p_handle == NULL)
    {
        DBG_DIRECT("%s: Sem to delete is a NULL pointer!", __func__);
        *p_result = false;
        return true;
    }

    obj = (struct k_sem *)p_handle;

    sys_multi_heap_free_kheap(&multi_heap, obj);
    *p_result = true;
    return true;
}

bool os_sem_take_zephyr(void *p_handle, uint32_t wait_ms, bool *p_result)
{
    int ret;
    struct k_sem *obj;
    k_timeout_t wait_ticks;

    if (p_handle == NULL)
    {
        *p_result = false;
        return true;
    }

    obj = (struct k_sem *)p_handle;

    wait_ticks = (wait_ms == 0xFFFFFFFFUL) ? K_FOREVER : K_MSEC(wait_ms);
    ret = k_sem_take(obj, wait_ticks);

    *p_result = (ret == 0) ? true : false;
    return true;
}

bool os_sem_give_zephyr(void *p_handle, bool *p_result)
{
    struct k_sem *obj;

    if (p_handle == NULL)
    {
        *p_result  = false;
        return true;
    }
    else
    {
        obj = (struct k_sem *)p_handle;
        if (k_sem_count_get(obj) == obj->limit)
        {
            DBG_DIRECT("%s: All tokens have already been released", __func__);
            *p_result  = false;
            return true;
        }
        k_sem_give(obj);

        *p_result  = true;
        return true;
    }
}

bool os_mutex_create_zephyr(void **pp_handle, bool *p_result)
{
    struct k_mutex *mutex_obj;
    mutex_obj = (struct k_mutex *) sys_multi_heap_alloc(&multi_heap, RAM_TYPE_DATA_ON,
                                                        sizeof(struct k_mutex));

    if (mutex_obj != NULL)
    {
        memset(mutex_obj, 0, sizeof(struct k_mutex));
        *pp_handle = mutex_obj;
        k_mutex_init(mutex_obj);
        *p_result  = true;
        return true;
    }
    else
    {
        DBG_DIRECT("alloc mutex object failed because data ram heap is full");
        *p_result  = false;
        return true;
    }
}

bool os_mutex_delete_zephyr(void *p_handle, bool *p_result)
{
    struct k_mutex *obj;

    if (p_handle == NULL)
    {
        *p_result  = false;
        return true;
    }

    obj = (struct k_mutex *)p_handle;

    sys_multi_heap_free_kheap(&multi_heap, obj);
    *p_result  = true;
    return true;
}

bool os_mutex_take_zephyr(void *p_handle, uint32_t wait_ms, bool *p_result)
{
    int ret;

    struct k_mutex *obj;
    k_timeout_t wait_ticks;

    if (p_handle == NULL)
    {
        *p_result  = false;
        return true;
    }

    obj = (struct k_mutex *)p_handle;

    wait_ticks = (wait_ms == 0xFFFFFFFFUL) ? K_FOREVER : K_MSEC(wait_ms);
    ret = k_mutex_lock(obj, wait_ticks);

    *p_result = (ret == 0) ? true : false;
    return true;
}

bool os_mutex_give_zephyr(void *p_handle, bool *p_result)
{
    int ret;

    struct k_mutex *obj;

    if (p_handle == NULL)
    {
        *p_result  = false;
        return true;
    }

    obj = (struct k_mutex *)p_handle;

    ret = k_mutex_unlock(obj);

    *p_result = (ret == 0) ? true : false;
    return true;

}
/* ************************************************* OSIF TASK ************************************************* */
task_sem_item task_sem_array[TASK_SEM_ARRAY_NUMBER] = {0};
#ifdef CONFIG_BT
struct k_thread lowstack_thread_handle;
#endif
bool os_task_create_zephyr(void **pp_handle, const char *p_name, void (*p_routine)(void *),
                           void *p_param, uint16_t stack_size, uint16_t priority, bool *p_is_create_success)
{
    k_tid_t thread_id;

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
        /* place lowstack_stack(3KB) at RAM_TYPE_BUFFER_ON */
        k_thread_stack_t *lowstack_stack;
        lowstack_stack = (k_thread_stack_t *) \
                         sys_multi_heap_aligned_alloc(&multi_heap, (void *)RAM_TYPE_BUFFER_ON,
                                                      8, CONFIG_REALTEK_BT_CONTROLLER_STACK_SIZE);
        if (lowstack_stack == NULL)
        {
            DBG_DIRECT("alloc thread stack failed because buffer ram heap is full");
            *p_is_create_success = false;
            return true;
        }
        *pp_handle = &lowstack_thread_handle;
        thread_id = k_thread_create(&lowstack_thread_handle, lowstack_stack,
                                    CONFIG_REALTEK_BT_CONTROLLER_STACK_SIZE,
                                    (k_thread_entry_t) p_routine, p_param, NULL, NULL,
                                    K_HIGHEST_THREAD_PRIO, 0, K_MSEC(10));//need to wait thread signal created
        k_thread_name_set(thread_id, p_name);
        *p_is_create_success = true;
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

    thread_handle = (struct k_thread *) sys_multi_heap_alloc(&multi_heap, RAM_TYPE_DATA_ON,
                                                             sizeof(struct k_thread));
    if (thread_handle != NULL)
    {
        memset(thread_handle, 0, sizeof(struct k_thread));
        *pp_handle = thread_handle;
    }
    else
    {
        DBG_DIRECT("alloc thread object failed because data ram heap is full");
        *p_is_create_success = false;
        return true;
    }

    k_thread_stack_t *stack_buffer;
    stack_buffer = (k_thread_stack_t *) sys_multi_heap_aligned_alloc(&multi_heap, RAM_TYPE_DATA_ON,
                                                                     8, stack_size);
    if (stack_buffer == NULL)
    {
        sys_multi_heap_free_kheap(&multi_heap, thread_handle);
        thread_handle = NULL;
        DBG_DIRECT("alloc thread stack failed because data ram heap is full");
        *p_is_create_success = false;
        return true;
    }
    memset(stack_buffer, 0, stack_size);
    thread_id = k_thread_create(*pp_handle, stack_buffer, stack_size,
                                (k_thread_entry_t) p_routine, p_param, NULL, NULL,
                                switch_priority, 0, K_MSEC(10));

    if (thread_id != NULL)
    {
        k_thread_name_set(thread_id, p_name);
    }

    *p_is_create_success = true;
    return true;

}

bool os_task_delete_zephyr(void *p_handle, bool *p_result)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    if (obj == NULL)
    {
        k_thread_abort(_current);
    }

    k_thread_abort(obj);

    *p_result = true;
    return true;
}

bool os_task_suspend_zephyr(void *p_handle, bool *p_result)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    k_thread_suspend(obj);

    *p_result = true;
    return true;
}

bool os_task_resume_zephyr(void *p_handle, bool *p_result)
{
    struct k_thread *obj;

    obj = (struct k_thread *)p_handle;

    k_thread_resume(obj);

    *p_result = true;
    return true;
}

bool os_task_yield_zephyr(bool *p_result)
{
    k_yield();

    *p_result = true;
    return true;
}

bool os_task_handle_get_zephyr(void **pp_handle, bool *p_result)
{
    if (pp_handle == NULL)
    {
        *p_result = false;
        return true;
    }
    else
    {
        *pp_handle = k_current_get();
        *p_result = true;
        return true;
    }
}

bool os_task_priority_get_zephyr(void *p_handle, uint16_t *p_priority, bool *p_result)
{
    if (p_priority == NULL)
    {
        *p_result = false;
        return true;
    }
    struct k_thread *obj;
    uint16_t priority;

    if (p_handle != NULL)
    {
        obj = (struct k_thread *)p_handle;
    }
    else
    {
        obj = k_current_get();
    }
    priority = k_thread_priority_get(obj);
    *p_priority = CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority;

    *p_result = true;
    return true;
}

bool os_task_priority_set_zephyr(void *p_handle, uint16_t priority, bool *p_result)
{
    struct k_thread *obj;

    if (priority > 6 || priority < 0)
    {
        *p_result = false;
        DBG_DIRECT("%s: Invalid priority. Priority is expected to 0 ~ 6.", __func__);
        return true;
    }

    uint16_t switch_priority = CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority;

    if (p_handle != NULL)
    {
        obj = (struct k_thread *)p_handle;
    }
    else
    {
        obj = k_current_get();
    }

    k_thread_priority_set(obj, switch_priority);

    *p_result = true;
    return true;
}

bool os_task_signal_create_zephyr(void *p_handle, uint32_t count, bool *p_result)
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
    sem_obj = (struct k_sem *) sys_multi_heap_alloc(&multi_heap, RAM_TYPE_DATA_ON,
                                                    sizeof(struct k_sem));

    if (sem_obj != NULL)
    {
        memset(sem_obj, 0, sizeof(struct k_sem));
    }
    else
    {
        DBG_DIRECT("alloc sem object failed because data ram heap is full");
        *p_result = false;
        return true;
    }

    if (i < TASK_SEM_ARRAY_NUMBER)
    {
        int ret = k_sem_init(sem_obj, count, 0xFFFF);
        if (ret == 0)
        {
            uint32_t key = arch_irq_lock();
            task_sem_array[i].task_handle = p_handle;
            task_sem_array[i].sem_handle = sem_obj ;
            arch_irq_unlock(key);
            *p_result = true;
        }
        else
        {
            DBG_DIRECT("k_sem_init failed");
            sys_multi_heap_free_kheap(&multi_heap, sem_obj);
            *p_result = false;
        }
    }
    else
    {
        DBG_DIRECT("out of TASK_SEM_ARRAY_NUMBER");
        sys_multi_heap_free_kheap(&multi_heap, sem_obj);
        *p_result = false;

    }

    return true;
}
bool os_task_notify_take_zephyr(long xClearCountOnExit, uint32_t xTicksToWait,
                                uint32_t *p_notify, bool *p_result)
{
    k_timeout_t wait_ticks;
    wait_ticks = (xTicksToWait == 0xFFFFFFFFUL) ? K_FOREVER : K_TICKS(xTicksToWait);
    struct k_thread *thread_obj = k_current_get();

    for (uint8_t i = 0; i < TASK_SEM_ARRAY_NUMBER; i++)
    {

        if (task_sem_array[i].task_handle == thread_obj)
        {
            struct k_sem *sem = task_sem_array[i].sem_handle;
            int ret = k_sem_take(sem, wait_ticks);
            if (ret == 0)
            {
                *p_notify = sem->count + 1;
                *p_result = true;
            }
            else
            {
                *p_notify = 0;
                *p_result = false;
            }

            if (xClearCountOnExit == true)
            {
                sem->count = 0;
            }

            return true;
        }
    }
    *p_notify = 0;
    *p_result = false;
    return true;

}

bool os_task_notify_give_zephyr(void *p_handle, bool *p_result)
{
    *p_result = false;
    struct k_sem *sem;
    for (uint8_t i = 0; i < TASK_SEM_ARRAY_NUMBER; i++)
    {
        if (task_sem_array[i].task_handle == p_handle)
        {
            sem = task_sem_array[i].sem_handle;
            k_sem_give(sem);
            *p_result = true;
            return true;
        }
    }
    return true;
}

bool os_task_status_dump_zephyr(void)
{
    struct k_thread *current_thread  = k_current_get();
    uint16_t priority = k_thread_priority_get(current_thread);
    /* To check */
    DBG_DIRECT("pxCurrentTCB %p, pxTopOfStack %p,taks_pri:%d",
               current_thread, current_thread ->callee_saved.psp,
               CONFIG_REALTEK_OSIF_MAX_TASK_PRIORITY - priority);
    return true;
}
/* ************************************************* OSIF TIMER ************************************************* */
K_MEM_SLAB_DEFINE(osif_timer_slab, sizeof(struct osif_timer),
                  CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT, __alignof__(struct osif_timer));

/* To support Timer Index or Timer Number Mechanism. */
static struct osif_timer *osif_timer_pool[CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT];

bool os_timer_create_zephyr(void **pp_handle, const char *p_timer_name, uint32_t timer_id,
                            uint32_t interval_ms, bool reload, void (*p_timer_callback)(), bool *p_result)
{
    *p_result = false;
    struct osif_timer *timer;

    if (reload != TimerOnce && reload != TimerPeriodic)
    {
        *p_result = false;
        return true;
    }

    if (k_mem_slab_alloc(&osif_timer_slab, (void **)&timer, K_NO_WAIT) == 0)
    {
        (void)memset(timer, 0, sizeof(struct osif_timer));
    }
    else
    {
        DBG_DIRECT("Exceed Max number of timers: %d!", CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT);
        *p_result = false;
        return true;
    }

    timer->name = p_timer_name;
    timer->timer_id = timer_id;
    timer->interval_ms = interval_ms;
    timer->status = NOT_ACTIVE;
    timer->type = reload;

    k_timer_init(&timer->ztimer, (k_timer_expiry_t) p_timer_callback, NULL);

    uint32_t key = irq_lock();
    *pp_handle = timer;
    // Attempt to store the timer in the pool
    bool stored = false;
    for (int i = 0; i < CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT; i++)
    {
        if (osif_timer_pool[i] == NULL)
        {
            osif_timer_pool[i] = timer;
            stored = true;
            break; // Timer stored successfully, exit the loop
        }
    }
    irq_unlock(key);

    if (!stored)
    {
        // If storing the timer failed, clean up and release resources
        k_mem_slab_free(&osif_timer_slab, (void *)timer);
        *pp_handle = NULL;
        DBG_DIRECT("Failed to store timer in pool, pool is full.");
    }

    *p_result = stored;
    return true;

}

bool os_timer_id_get_zephyr(void **pp_handle, uint32_t *p_timer_id, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: Variable timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL, or not declare a timer handle pointer!", __func__);
        *p_result = false;
        return true;
    }
    *p_timer_id = timer->timer_id;
    *p_result = true;
    return true;
}

bool os_timer_start_zephyr(void **pp_handle, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *p_result = false;
        return true;
    }

    if (timer->type == TimerPeriodic)
    {
        k_timer_start(&timer->ztimer, K_MSEC(timer->interval_ms), K_MSEC(timer->interval_ms));
    }
    else if (timer->type == TimerOnce)
    {
        k_timer_start(&timer->ztimer, K_MSEC(timer->interval_ms), K_NO_WAIT);
    }

    timer->status = ACTIVE;

    *p_result = true;
    return true;
}

bool os_timer_restart_zephyr(void **pp_handle, uint32_t interval_ms, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *p_result = false;
        return true;
    }

    uint32_t key = irq_lock();
    timer->interval_ms = interval_ms;
    irq_unlock(key);

    if (timer->type == TimerPeriodic)
    {
        k_timer_start(&timer->ztimer, K_MSEC(timer->interval_ms), K_MSEC(timer->interval_ms));
    }
    else if (timer->type == TimerOnce)
    {
        k_timer_start(&timer->ztimer, K_MSEC(timer->interval_ms), K_NO_WAIT);
    }

    timer->status = ACTIVE;

    *p_result = true;
    return true;
}

bool os_timer_stop_zephyr(void **pp_handle, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *p_result = false;
        return true;
    }

    if (timer->status == NOT_ACTIVE)
    {
        DBG_DIRECT("%s: timer is inactive, cannot stop!", __func__);
        *p_result = false;
        return true;
    }

    k_timer_stop(&timer->ztimer);

    *p_result = true;
    return true;
}

bool os_timer_delete_zephyr(void **pp_handle, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *p_result = false;
        return true;
    }

    if (timer->status == ACTIVE)
    {
        k_timer_stop(&timer->ztimer);
        timer->status = NOT_ACTIVE;
    }

    k_mem_slab_free(&osif_timer_slab, (void *)timer);

    uint32_t key = irq_lock();

    for (int i = 0; i < CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT; i++)
    {
        if (osif_timer_pool[i] == timer)
        {
            osif_timer_pool[i] = NULL;
            break;
        }
    }
    *pp_handle = NULL;
    irq_unlock(key);

    *p_result = true;
    return true;
}


bool os_timer_dump_zephyr(bool *p_result)
{
    return true;
}

bool os_timer_state_get_zephyr(void **pp_handle, uint32_t *p_timer_state, bool *p_result)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *p_result = false;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *p_result = false;
        return true;
    }

    uint32_t key = irq_lock();
    if (!(k_timer_remaining_get(&timer->ztimer)))
    {
        *p_timer_state = 0; // timer has expired or stopped.
    }
    else
    {
        *p_timer_state = 1; // timer is running.
    }
    irq_unlock(key);

    *p_result = true;
    return true;
}

bool os_timer_is_timer_active_zephyr(void **pp_handle, bool *is_active)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        *is_active = 0;
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        *is_active = 0;
        return true;
    }

    uint32_t key = irq_lock();
    if (!(k_timer_remaining_get(&timer->ztimer)))
    {
        *is_active = 0; // timer has expired or stopped.
    }
    else
    {
        *is_active = 1; // timer is running.
    }
    irq_unlock(key);

    return true;
}

bool os_timer_init_zephyr(void)
{
    return true;
}

bool os_timer_number_get_zephyr(void **pp_handle, uint32_t *p_timer_num, bool *p_result)
{
    if (*p_timer_num >= CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT)
    {
        DBG_DIRECT("%s: input timer_index %d is out of bound! Max timer number:%d", __func__, *p_timer_num,
                   CONFIG_REALTEK_OSIF_TIMER_MAX_COUNT);
        return NULL;
    }
    return osif_timer_pool[*p_timer_num];
}

bool os_timer_get_auto_reload_zephyr(void **pp_handle, long *p_autoreload)
{
    if (pp_handle == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is not declared!", __func__);
        return true;
    }

    struct osif_timer *timer = (struct osif_timer *)*pp_handle;

    if (timer == NULL)
    {
        DBG_DIRECT("%s: timer handle pointer is NULL!", __func__);
        return false;
    }

    *p_autoreload = timer->type;
    return true;
}

uint32_t os_pm_next_timeout_value_get_zephyr(void)
{
    /* Solution without the exclude timer mechanism. */
    // uint32_t ticks = z_get_next_timeout_expiry();
    // return ticks;

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
        /** kernel timer's timeout function is z_timer_expiration_handler
         *  exclude selectd kernel timer
         */
        if (t->fn == z_timer_expiration_handler)
        {
            timer = CONTAINER_OF(t, struct k_timer, timeout);
            T_OS_QUEUE_ELEM *p_cur_queue_item = lpm_excluded_handle[PLATFORM_PM_EXCLUDED_TIMER].p_first;
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
                            DBG_DIRECT("[PM]!!handle=0x%x, exclude timer cannot be auto_reload", cur_excluded_handle);
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
        /** thread k_sleep's timeout function is z_thread_timeout
         *  exclude selectd thread
         */
        else if (t->fn == z_thread_timeout)
        {
            thread = CONTAINER_OF(t, struct k_thread, base.timeout);
            T_OS_QUEUE_ELEM *p_cur_queue_item = lpm_excluded_handle[PLATFORM_PM_EXCLUDED_TASK].p_first;
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
        /* other timeout (e.g. time slice, work queue) */
        else
        {

            timeout_tick_res = timeout_tick;
            break;
        }
    }

    return timeout_tick_res;
}

uint32_t os_sys_tick_rate_get_zephyr(void)
{
    return (uint32_t)CONFIG_SYS_CLOCK_TICKS_PER_SEC;
}

uint32_t os_sys_tick_clk_get_zephyr(void)
{
    return (uint32_t)CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC;
}

void os_task_dlps_return_idle_task_zephyr(void)
{
    arch_kernel_init();//perform arm initialization: including fault exception init & msp setting.

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

void os_pm_store_zephyr(void)
{
    os_pm_store_tickcount();
}

void os_pm_restore_zephyr(void)
{
    //os_pm_restore_tickcount();
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

/* ************************************************* OSIF PATCH ************************************************* */
void osif_mem_func_init_zephyr()
{
    patch_osif_os_mem_alloc_intern         = (BOOL_PATCH_FUNC)os_mem_alloc_intern_zephyr;
    patch_osif_os_mem_zalloc_intern        = (BOOL_PATCH_FUNC)os_mem_zalloc_intern_zephyr;
    patch_osif_os_mem_aligned_alloc_intern = (BOOL_PATCH_FUNC)os_mem_aligned_alloc_intern_zephyr;
    patch_osif_os_mem_free                 = (BOOL_PATCH_FUNC)os_mem_free_zephyr;
    patch_osif_os_mem_aligned_free         = (BOOL_PATCH_FUNC)os_mem_aligned_free_zephyr;
    patch_osif_os_mem_peek                 = (BOOL_PATCH_FUNC)os_mem_peek_zephyr;
    patch_osif_os_mem_check_heap_usage     = (BOOL_PATCH_FUNC)os_mem_check_heap_usage_zephyr;
}

void osif_msg_func_init_zephyr()
{
    patch_osif_os_msg_queue_create_intern = (BOOL_PATCH_FUNC)os_msg_queue_create_intern_zephyr;
    patch_osif_os_msg_queue_delete_intern = (BOOL_PATCH_FUNC)os_msg_queue_delete_intern_zephyr;
    patch_osif_os_msg_queue_peek_intern   = (BOOL_PATCH_FUNC)os_msg_queue_peek_intern_zephyr;
    patch_osif_os_msg_send_intern = (BOOL_PATCH_FUNC)os_msg_send_intern_zephyr;
    patch_osif_os_msg_recv_intern = (BOOL_PATCH_FUNC)os_msg_recv_intern_zephyr;
}

void osif_sched_func_init_zephyr(void)
{
    patch_osif_os_init = os_init_zephyr;
    patch_osif_os_delay = os_delay_zephyr;
    patch_osif_os_sys_time_get = os_sys_time_get_zephyr;
    patch_osif_os_sys_tick_get = os_sys_tick_get_zephyr;
    patch_osif_os_sched_start = os_sched_start_zephyr;
    patch_osif_os_sched_suspend = os_sched_suspend_zephyr;
    patch_osif_os_sched_resume = os_sched_resume_zephyr;
    patch_osif_os_sched_state_get = os_sched_state_get_zephyr;
    patch_osif_os_sched_is_start = os_sched_is_start_zephyr;
}

void osif_sync_func_init_zephyr(void)
{
    patch_osif_os_lock = os_lock_zephyr;
    patch_osif_os_unlock = os_unlock_zephyr;
    patch_osif_os_sem_create = os_sem_create_zephyr;
    patch_osif_os_sem_delete = os_sem_delete_zephyr;
    patch_osif_os_sem_take = os_sem_take_zephyr;
    patch_osif_os_sem_give = os_sem_give_zephyr;
    patch_osif_os_mutex_create = os_mutex_create_zephyr;
    patch_osif_os_mutex_delete = os_mutex_delete_zephyr;
    patch_osif_os_mutex_take = os_mutex_take_zephyr;
    patch_osif_os_mutex_give = os_mutex_give_zephyr;
}

void osif_task_func_init_zephyr(void)
{
    patch_osif_os_task_create  = (BOOL_PATCH_FUNC)os_task_create_zephyr;
    patch_osif_os_task_delete  = (BOOL_PATCH_FUNC)os_task_delete_zephyr;
    patch_osif_os_task_suspend = (BOOL_PATCH_FUNC)os_task_suspend_zephyr;
    patch_osif_os_task_resume  = (BOOL_PATCH_FUNC)os_task_resume_zephyr;
    patch_osif_os_task_yield   = (BOOL_PATCH_FUNC)os_task_yield_zephyr;
    patch_osif_os_task_handle_get    = (BOOL_PATCH_FUNC)os_task_handle_get_zephyr;
    patch_osif_os_task_priority_get  = (BOOL_PATCH_FUNC)os_task_priority_get_zephyr;
    patch_osif_os_task_priority_set  = (BOOL_PATCH_FUNC)os_task_priority_set_zephyr;
    patch_osif_os_task_signal_create = (BOOL_PATCH_FUNC)os_task_signal_create_zephyr;
    patch_osif_os_task_notify_take   = (BOOL_PATCH_FUNC)os_task_notify_take_zephyr;
    patch_osif_os_task_notify_give   = (BOOL_PATCH_FUNC)os_task_notify_give_zephyr;
    patch_osif_os_task_status_dump   = (BOOL_PATCH_FUNC)os_task_status_dump_zephyr;
}

void osif_timer_func_init_zephyr(void)
{
    patch_osif_os_timer_id_get  = (BOOL_PATCH_FUNC)os_timer_id_get_zephyr;
    patch_osif_os_timer_create  = (BOOL_PATCH_FUNC)os_timer_create_zephyr;
    patch_osif_os_timer_start   = (BOOL_PATCH_FUNC)os_timer_start_zephyr;
    patch_osif_os_timer_restart = (BOOL_PATCH_FUNC)os_timer_restart_zephyr;
    patch_osif_os_timer_stop    = (BOOL_PATCH_FUNC)os_timer_stop_zephyr;
    patch_osif_os_timer_delete  = (BOOL_PATCH_FUNC)os_timer_delete_zephyr;
    patch_osif_os_timer_dump    = (BOOL_PATCH_FUNC)os_timer_dump_zephyr;
    patch_osif_os_timer_state_get  = (BOOL_PATCH_FUNC)os_timer_state_get_zephyr;
    patch_osif_os_timer_init       = (BOOL_PATCH_FUNC)os_timer_init_zephyr;
    patch_osif_os_timer_number_get = (BOOL_PATCH_FUNC)os_timer_number_get_zephyr;
    patch_osif_os_timer_is_timer_active = (BOOL_PATCH_FUNC)os_timer_is_timer_active_zephyr;
}

void os_pm_init_zephyr(void)
{
    power_manager_slave_register_function_to_return(os_task_dlps_return_idle_task_zephyr);

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

void osif_pm_func_init_zephyr(void)
{
    os_pm_init = os_pm_init_zephyr;
    patch_osif_os_task_dlps_return_idle_task = (BOOL_PATCH_FUNC)os_task_dlps_return_idle_task_zephyr;
    patch_osif_os_sys_tick_increase = os_sys_tick_increase_zephyr;
    patch_osif_os_systick_handler = os_systick_handler_zephyr;
    os_pm_next_timeout_value_get = os_pm_next_timeout_value_get_zephyr;
}

void os_zephyr_patch_init(void)
{
    osif_mem_func_init_zephyr();
    osif_msg_func_init_zephyr();
    osif_sched_func_init_zephyr();
    osif_sync_func_init_zephyr();
    osif_task_func_init_zephyr();
    osif_timer_func_init_zephyr();

    osif_pm_func_init_zephyr();
}
