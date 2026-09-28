/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef HAL_DEBUG_H
#define HAL_DEBUG_H

#include "platform_ext.h"

/** @defgroup  HAL_DEBUG    HAL Debug
    * @brief HAL debug API.
    * @{
    */


/*============================================================================*
  *                                   Types
  *============================================================================*/
/** @defgroup HAL_DEBUG_TPYE HAL Debug Exported Types
   * @brief
   * @{
   */
typedef enum
{
    TASK_READY, /* A task is querying the state of itself, so must be running. */
    TASK_RUNNING, /* The task being queried is in a read or pending ready list. */
    TASK_BLOCKED, /* The task being queried is in the Blocked state. */
    TASK_SUSPENDED,/* The task being queried is in the Suspended state, or is in the Blocked state with an infinite time out. */
    TASK_DELETED,   /* The task being queried has been deleted, but its TCB has not yet been freed. */
} T_TASK_STATE_TYPE;


typedef struct
{
    uint32_t taskId;
    char taskName[16];
    uint8_t taskPriority;
    T_TASK_STATE_TYPE taskState;
    uint32_t stackSize;
    uint32_t stackFree;
    uint32_t taskProportion;
} T_TASK_INFO ;

/** End of HAL_DEBUG_TPYE
    * @}
    */

/** @defgroup HAL_DEBUG_Exported_Macros HAL Debug Exported Macros
    * @brief
    * @{
    */
#define F_HAL_DEBUG_TASK_SCHEDULING         1
#define F_HAL_DEBUG_HIT_RATE_PRINT          1
#define F_HAL_DEBUG_HEAP_USAGE_INFO         1
#define F_HAL_DEBUG_PC_SAMPLING             1
#define F_HAL_DEBUG_QUEUE_USAGE             1
#define F_HAL_DEBUG_TASK_TIME_PROPORTION    1
#define F_HAL_DEBUG_HW_TIMER_IRQ            1
#define F_HAL_DEBUG_MALLOC_DEBUG_INFO       0
#define F_HAL_DEBUG_DBG_MONITOR_CB_ENABLE   1
/** End of HAL_DEBUG_Exported_Macros
    * @}
    */
/** @defgroup HAL_Debug_Exported_Functions HAL Debug Exported Functions
    * @brief
    * @{
    */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief This CB is used for registering cb in debug monitor isr. */
typedef void (* HAL_DEBUG_DEBUG_MONITOR_CB)(void);
typedef void (* HAL_DEBUG_EXCEPTION_HANDLER_CB)(void);
/**
    * @brief  Register app debug timer callback function.
    * @note   App_init_timer should be called before hal_debug_init.
    */
void hal_debug_init(void);
/**
    * @brief  Allocate task information record buffer.
    * @param  task_num Specify the max task count to record task information.
    */
void hal_debug_task_schedule_init(uint32_t task_num);
/**
    * @brief  Print task name and task context switch out time.
    */
void hal_debug_print_task_info(void);
/**
    * @brief Init cache hit and debug timer.
    * @param  period_ms Specify cache hit rate period.
    */
void hal_debug_cache_hit_count_init(uint32_t period_ms);
/**
    * @brief  Trigger raw memory dump.
    */
void hal_debug_memory_dump(void);
/**
    * @brief  Set queue handler to monitor and init debug timer.
    * @param  period_ms Specify queue usage statistic period.
    * @param  queue_handle1 Specify the monitor message queue handle 1.
    * @param  queue_handle2 Specify the monitor message queue handle 2.
    * @param  queue_handle3 Specify the monitor message queue handle 3.
    */
void hal_debug_msg_queue_usage_monitor(uint32_t period_ms, void *queue_handle1, void *queue_handle2,
                                       void *queue_handle3);
/**
    * @brief  Init hal debug task time statistic proportion environment.
    * @param  period_ms Specify task statistic proportion period.
    */
void hal_debug_task_time_proportion_init(uint32_t period_ms);
/**
    * @brief  Print pc/lr sampling record data.
    */
void hal_debug_print_pc_sampling(void);
/**
    * @brief  Init hal debug pc sampling environment.
    * @param  num Specify the pc sampling count.
    * @param  period_us Specify pc sampling period.
    */
void hal_debug_pc_sampling_init(uint8_t num, uint32_t period_us);
/**
    * @brief  Debug the hw timer timeout time.
    */
void hal_debug_hw_timer_irq_init(void);

/**
    * @brief  Register cb in debug monitor isr.
    * @param  cb Register in debug monitor isr.
    */
void hal_debug_debug_monitor_cb_register(HAL_DEBUG_DEBUG_MONITOR_CB cb);

/**
    * @brief  Set debug monitor for task stackoverflow
    * @param  index Debug monitor idex.
    * @param  task_handle Handle of task to be detected.
    */
void hal_debug_stackoverflow_debug_monitor_set(T_WATCH_POINT_INDEX index, void *task_handle);

/**
 * @brief Retrieve information of all current tasks in the system.
 *
 * This function populates the caller-provided buffer with information about
 * tasks that are currently present in the system. It is typically used for
 * debugging or monitoring purposes to inspect each task's status, priority,
 * stack usage, etc.
 *
 * @param[out] info     Pointer to an array of T_TASK_INFO where the task
 *                      information will be stored. The caller must provide
 *                      a buffer that can hold at least @p max_num entries.
 * @param[in]  max_num  Maximum number of task entries that can be written
 *                      into @p info.
 *
 * @return int32_t
 *         - >= 0: The actual number of task entries written to @p info.
 *         - < 0 : A negative error code (e.g., invalid parameter, internal
 *                 query failure).
 *
 * @note
 * - If the number of tasks exceeds @p max_num, only the first @p max_num
 *   entries will be written. You may compare the return value with
 *   hal_debug_get_current_task_num() to decide whether to enlarge the buffer
 *   and retry.
 * - The T_TASK_INFO structure must be defined and included by the caller.
 *   Its fields (task name, priority, stack high-water mark, state, etc.)
 *   depend on the system implementation.
 */
int32_t hal_debug_get_all_task_info(T_TASK_INFO *info, uint32_t max_num);

/**
 * @brief Get the current number of valid tasks in the system.
 *
 * Returns the total count of tasks that are currently created and observable
 * by the debug subsystem. This is commonly used to size the buffer before
 * calling hal_debug_get_all_task_info().
 *
 * @return uint32_t
 *         The number of tasks currently present in the system (excluding
 *         deleted or invalid tasks).
 *
 * @note
 * - In a multi-threaded environment, the returned count may change over time.
 *   If consistent data is required, consider calling this function within a
 *   critical section or with scheduling suspended, or tolerate momentary
 *   inconsistencies.
 */
uint32_t hal_debug_get_current_task_num(void);

void hal_debug_exception_cb_register(HAL_DEBUG_EXCEPTION_HANDLER_CB cb);
#ifdef __cplusplus
}
#endif
/** @} */ /* End of group HAL_Debug_Exported_Functions */
/** @} */ /* End of group HAL_DEBUG */
#endif
