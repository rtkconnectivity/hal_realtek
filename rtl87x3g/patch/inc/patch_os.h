/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_OS_H_
#define _PATCH_OS_H_

#include <patch.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "stddef.h"
#include "mem_types.h"
#include "os_queue.h"


/* OSIF patch function */
extern bool (*patch_osif_os_delay)(uint32_t ms);
extern bool (*patch_osif_os_sys_time_get)(uint64_t *ret);
extern bool (*patch_osif_os_sched_start)(bool *ret);
extern bool (*patch_osif_os_sched_stop)(bool *ret);
extern bool (*patch_osif_os_sched_suspend)(bool *ret);
extern bool (*patch_osif_os_sched_resume)(bool *ret);
extern bool (*patch_osif_os_sched_state_get)(long *p_state, bool *ret);
extern bool (*patch_osif_os_sched_in_restore)(bool *ret);

extern bool (*patch_osif_os_task_create)(void **pp_handle, const char *p_name,
                                         void (*p_routine)(void *),
                                         void *p_param, uint16_t stack_size, uint16_t priority, bool *ret);
extern bool (*patch_osif_os_task_delete)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_task_suspend)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_task_resume)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_task_yield)(bool *ret);
extern bool (*patch_osif_os_task_handle_get)(void **pp_handle, bool *ret);
extern bool (*patch_osif_os_task_priority_get)(void *p_handle, uint16_t *p_priority, bool *ret);
extern bool (*patch_osif_os_task_priority_set)(void *p_handle, uint16_t priority, bool *ret);
extern bool (*patch_osif_os_task_signal_send)(void *p_handle, uint32_t signal, bool *ret);
extern bool (*patch_osif_os_task_signal_recv)(uint32_t *p_signal, uint32_t wait_ms, bool *ret);
extern bool (*patch_osif_os_task_signal_clear)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_task_signal_create)(void *p_handle, uint32_t count, bool *ret);

extern bool (*patch_osif_os_lock)(uint32_t *ret);
extern bool (*patch_osif_os_unlock)(uint32_t s);
extern bool (*patch_osif_os_sem_create)(void **pp_handle, const char *p_name, uint32_t init_count,
                                        uint32_t max_count, bool *ret);
extern bool (*patch_osif_os_sem_delete)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_sem_take)(void *p_handle, uint32_t wait_ms, bool *ret);
extern bool (*patch_osif_os_sem_give)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_mutex_create)(void **pp_handle, bool *ret);
extern bool (*patch_osif_os_mutex_delete)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_mutex_take)(void *p_handle, uint32_t wait_ms, bool *ret);
extern bool (*patch_osif_os_mutex_give)(void *p_handle, bool *ret);

extern bool (*patch_osif_os_msg_queue_create_intern)(void **pp_handle, const char *p_name,
                                                     uint32_t msg_num,
                                                     uint32_t msg_size, bool *ret);
extern bool (*patch_osif_os_msg_queue_delete_intern)(void *p_handle, bool *ret);
extern bool (*patch_osif_os_msg_queue_peek_intern)(void *p_handle, uint32_t *p_msg_num, bool *ret);
extern bool (*patch_osif_os_msg_send_intern)(void *p_handle, void *p_msg, uint32_t wait_ms,
                                             bool *ret);
extern bool (*patch_osif_os_msg_recv_intern)(void *p_handle, void *p_msg, uint32_t wait_ms,
                                             bool *ret);
extern bool (*patch_osif_os_msg_peek_intern)(void *p_handle, void *p_msg, uint32_t wait_ms,
                                             bool *ret);

extern bool (*patch_osif_os_mem_alloc_intern)(RAM_TYPE ram_type, size_t size, void **ret);
extern bool (*patch_osif_os_mem_aligned_alloc_intern)(RAM_TYPE ram_type, size_t size,
                                                      uint8_t alignment, void **ret);
extern bool (*patch_osif_os_mem_zalloc_intern)(RAM_TYPE ram_type, size_t size, void **ret);
extern bool (*patch_osif_os_mem_free)(void *p_block);
extern bool (*patch_osif_os_mem_aligned_free)(void *p_block);
extern bool (*patch_osif_os_mem_peek)(RAM_TYPE ram_type, size_t *ret);

extern bool (*patch_osif_os_queue_in)(T_OS_QUEUE *p_queue, void *p_elem);
extern bool (*patch_osif_os_queue_out)(T_OS_QUEUE *p_queue, void **ret);
extern bool (*patch_osif_os_queue_peek)(T_OS_QUEUE *p_queue, int32_t index, void **ret);
extern bool (*patch_osif_os_queue_search)(T_OS_QUEUE *p_queue, void *p_elem, bool *ret);
extern bool (*patch_osif_os_queue_insert)(T_OS_QUEUE *p_queue, void *p_elem, void *p_new_elem);
extern bool (*patch_osif_os_queue_delete)(T_OS_QUEUE *p_queue, void *p_elem, bool *ret);

extern bool (*patch_osif_os_timer_id_get)(void **pp_handle, uint32_t *p_timer_id, bool *ret);
extern bool (*patch_osif_os_timer_create)(void **pp_handle, const char *p_timer_name,
                                          uint32_t timer_id,
                                          uint32_t interval_ms, bool reload, void (*p_timer_callback)(void *), bool *ret);
extern bool (*patch_osif_os_timer_start)(void **pp_handle, bool *ret);
extern bool (*patch_osif_os_timer_restart)(void **pp_handle, uint32_t interval_ms, bool *ret);
extern bool (*patch_osif_os_timer_stop)(void **pp_handle, bool *ret);
extern bool (*patch_osif_os_timer_delete)(void **pp_handle, bool *ret);
extern bool (*patch_osif_os_timer_pend_function_call)(void (*p_pend_function)(void *, uint32_t),
                                                      void *pvParameter1, uint32_t ulParameter2, bool *ret);
extern bool (*patch_osif_os_timer_auto_reload_get)(void **pp_handle, long *p_autoreload, bool *ret);
extern bool (*patch_osif_os_timer_get_next_timeout_item)(void **pxListItem,
                                                         unsigned long *puxListNum,
                                                         uint8_t xListType, bool *ret);
extern bool (*patch_osif_os_timer_state_get)(void **pp_handle, uint8_t *p_timer_state, bool *ret);
extern bool (*patch_osif_os_timer_handle_get)(void **pp_handle, uint8_t id, bool *ret);

extern bool (*patch_osif_os_trace_isr_create)(void **pp_handle, const char *p_name,
                                              uint32_t priority, bool *ret);
extern bool (*patch_osif_os_trace_isr_begin)(void *pp_handle, bool *ret);
extern bool (*patch_osif_os_trace_isr_end)(bool *ret);

extern bool (*patch_vTaskSwitchContext)();
#ifdef __cplusplus
}
#endif

#endif /* _PATCH_OS_H_ */
