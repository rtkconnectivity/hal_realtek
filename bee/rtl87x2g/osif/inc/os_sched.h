/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OS_SCHED_H_
#define _OS_SCHED_H_

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * \defgroup    OS_SCHED Kernel Scheduler
 *
 * \brief       Manage the kernel scheduler functions.
 *
 */

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup OS_SCHED_Exported_Functions OS Scheduler Exported Functions
  * \ingroup  OS_SCHED
  * @{
  */


/**
 * os_sched.h
 *
 * \brief       Delay current task for a given period in milliseconds.
 *
 * \param       ms  The amout of timer in milliseconds that the current task
 *                  should block.
 *
 * \return      None.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     for (;;)
 *     {
 *          // Task code goes here.
 *          os_delay(100);
 *
 *          // Do something here per 100ms.
 *     }
 * }
 * \endcode
 *
 */
extern void (*os_delay)(uint32_t ms);

/**
 * os_sched.h
 *
 * \brief   Get the time in milliseconds since os_sched_start() API function was called.
 *
 * \param   None
 *
 * \return  The time in milliseconds. Note the time represented by a 64-bit integer
 *          may be overflowed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     uint64_t last_time;
 *
 *     // Get the last timestamp.
 *     last_time = os_sys_time_get();
 *
 *     for (;;)
 *     {
 *          // Wait for the next cycle.
 *          os_delay(100);
 *
 *          // Do something here per 100ms.
 *     }
 * }
 * \endcode
 *
 */
extern uint64_t (*os_sys_time_get)(void);

/**
 * os_sched.h
 *
 * \brief   Get the time in milliseconds since os_sched_start() API function was called.
 *
 * \param   None
 *
 * \return  The time in os tick. Note the time represented by a 64-bit integer
 *          may be overflowed.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     uint64_t last_tick;
 *
 *     // Get the last timestamp.
 *     last_tick = os_sys_tick_get();
 *
 *     for (;;)
 *     {
 *          // Wait for the next cycle.
 *          os_delay(100);
 *
 *          // Do something here per 100ms.
 *     }
 * }
 * \endcode
 *
 */
extern uint64_t (*os_sys_tick_get)(void);

/**
 * os_sched.h
 *
 * \brief   Start the RTOS kernel scheduler.
 *
 * \param   None
 *
 * \return  The status of starting kernel scheduler.
 * \retval  true      Scheduler was started successfully.
 * \retval  false     Scheduler was failed to start.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     // Create at least one task before starting kernel scheduler.
 *     if (os_task_create(&p_handle, "task", task_routine,
 *                        NULL, STACK_SIZE, TASK_PRIORITY) == true)
 *     {
 *         // Task created successfully.
 *     }
 *     else
 *     {
 *         // Task failed to create.
 *         return -1;
 *     }
 *
 *     // Start the kernel scheduler.
 *     os_sched_start();
 *
 *     // Will not get here unless a task calls os_sched_stop().
 * }
 * \endcode
 *
 */
extern bool (*os_sched_start)(void);

/**
 * os_sched.h
 *
 * \brief   Stop the RTOS kernel scheduler. All created tasks will be automatically
 *          deleted and multitasking (either preemptive or cooperative) stops.
 *
 * \param   None
 *
 * \return  The status of stopping kernel scheduler.
 * \retval  true      Scheduler was stopped successfully.
 * \retval  false     Scheduler was failed to stop.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     for (;;)
 *     {
 *          // Task code goes here.
 *
 *          // At some point we want to end the real time kernel processing.
 *          os_sched_stop();
 *     }
 * }
 *
 * int test(void)
 * {
 *     // Create at least one task before starting kernel scheduler.
 *     if (os_task_create(&p_handle, "task", task_routine,
 *                        NULL, STACK_SIZE, TASK_PRIORITY) == true)
 *     {
 *         // Task created successfully.
 *     }
 *     else
 *     {
 *         // Task failed to create.
 *         return -1;
 *     }
 *
 *     // Start the kernel scheduler.
 *     os_sched_start();
 *
 *     // Will not get here unless a task calls os_sched_stop().
 * }
 * \endcode
 *
 * \ingroup  Schedule
 */
extern bool (*os_sched_stop)(void);

/**
 * os_sched.h
 *
 * \brief   Suspends the kernel scheduler without disabling interrupts. Context
 *          switches will not occur while the scheduler is suspended. After calling
 *          os_sched_suspend(), the calling task will continue to execute without
 *          risk of being swapped out until a call to os_sched_resume() has been made.
 *
 * \param   None
 *
 * \return  The status of suspending kernel scheduler.
 * \retval  true      Scheduler was suspended successfully.
 * \retval  false     Scheduler was failed to suspend.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     for (;;)
 *     {
 *          // Task code goes here.
 *
 *          // At some point the task wants to perform a long operation, and do not
 *          // want to get swapped out.
 *          os_sched_suspend();
 *
 *          // The long operation.
 *
 *          // The operation is completed, and resume the scheduler.
 *          os_sched_resume();
 *     }
 * }
 * \endcode
 *
 */
extern bool (*os_sched_suspend)(void);

/**
 * os_sched.h
 *
 * \brief   Resume the kernel scheduler after it was suspended by a call
 *          to os_sched_suspend().
 *
 * \param   None
 *
 * \return  The status of resuming kernel scheduler.
 * \retval  true      Scheduler was resumed successfully.
 * \retval  false     Scheduler was failed to resume.
 *
 * <b>Example usage</b>
 * \code{.c}
 * // Task routine implementation.
 * void task_routine(void *p_param)
 * {
 *     for (;;)
 *     {
 *          // Task code goes here.
 *
 *          // At some point the task wants to perform a long operation, and do not
 *          // want to get swapped out.
 *          os_sched_suspend();
 *
 *          // The long operation.
 *
 *          // The operation is completed, and resume the scheduler.
 *          os_sched_resume();
 *     }
 * }
 * \endcode
 *
 */
extern bool (*os_sched_resume)(void);

/**
  * @brief  Check if os scheduler has already been started
  * @param  None
  * @return The status of os scheduler.
  * \retval  true      Scheduler has already been started.
  * \retval  false     Scheduler has not already been started.
  */
extern bool (*os_sched_is_start)(void);

/**
  * @brief  Get state of os scheduler
  * @param  p_state current state of os scheduler, 0: suspended; 1: not started; 2: running
  * @return The result of os scheduler state get.
  * \retval  true      Scheduler state get sucess.
  * \retval  false     Scheduler state get fail.
  */
extern bool (*os_sched_state_get)(long *p_state);

/** End of group OS_SCHED_Exported_Functions
  * @}
  */

/** End of OS_SCHED
  * @}
  */

extern void (*os_vector_table_update)(void);
extern void (*os_init)(void);

#ifdef __cplusplus
}
#endif

#endif /* _OS_SCHED_H_ */
