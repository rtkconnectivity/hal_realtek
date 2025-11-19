/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _OSIF_ZEPHYR_H_
#define _OSIF_ZEPHYR_H_
#include <zephyr/kernel.h>

#define TIMER_NUMBER_MAX 64
#define TASK_SEM_ARRAY_NUMBER 5

typedef struct
{
    void *task_handle;
    void *sem_handle;
} task_sem_item;

struct unstart_thread_data
{
    struct k_thread *init_thread;
};
typedef enum
{
    SCHEDULER_SUSPENDED = 0,
    SCHEDULER_NOT_STARTED = 1,
    SCHEDULER_RUNNING = 2
} SCHEDULER_STATE;

typedef struct timer_info
{
    void *timer_handle;
    uint32_t timer_id;
} Timer_Info;

typedef void (*pend_func_t)(void *para1, uint32_t para2);

struct pend_call
{
    struct k_work work;
    pend_func_t pend_func;
    void *para1;
    uint32_t para2;
};

#endif
