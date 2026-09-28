/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATH_UPPERSTACK_H_
#define _PATH_UPPERSTACK_H_

#include <patch.h>
#include <bte_api.h>
#include <mem_types.h>
#include <hci_if.h>
#include <l2c_int.h>
#include <sm_api.h>
#include <sm_int.h>
#include <gatt_int.h>
#include <sdp_int.h>
#include <btif_int.h>
#include <btif_api.h>
#include <hci_int.h>

extern BOOL_PATCH_FUNC(*patch_upperstack_bte_utils_generate_random_value)(uint32_t *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_init)(bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_queue_msg_send_intern)(T_BTE_Q *p_queue, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_queue_msg_recv_intern)(T_BTE_Q *p_queue, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_queue_msg_peek_intern)(T_BTE_Q *p_queue, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_entry_msg_send_intern)(uint8_t handle, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_entry_msg_recv_intern)(uint8_t handle, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_entry_msg_peek_intern)(uint8_t handle, T_MSG *p_msg,
                                                                    const char *p_func, uint32_t file_line,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_pool_create_intern)(uint8_t *p_handle,
                                                                 RAM_TYPE ram_type, uint16_t buf_size,
                                                                 uint16_t buf_count, const char *p_func,
                                                                 uint32_t file_line, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_pool_extend_intern)(uint8_t handle, uint16_t buf_size,
                                                                 uint16_t buf_count,
                                                                 const char *p_func, uint32_t file_line, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_pool_heap_init)(RAM_TYPE ram_type, uint32_t fix_size,
                                                             uint32_t shrink_size, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_pool_dump)(uint8_t handle);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_buffer_callback_set_intern)(void *p_buf,
                                                                         P_BTE_BUFFER_CALLBACK p_cb_func, void *p_cb_param,
                                                                         const char *p_func, uint32_t file_line, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_buffer_get_intern)(uint8_t handle, uint16_t buf_size,
                                                                const char *p_func, uint32_t file_line, void **p_buf);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_buffer_put_intern)(void *p_buf, const char *p_func,
                                                                uint32_t file_line, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_coroutine_create)(uint8_t *p_handle,
                                                               P_COROUTINE_ENTRY p_cr_entry, void *p_cr_param, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_coroutine_delete)(uint8_t handle, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_sched_trigger)(void);
extern BOOL_PATCH_FUNC(*patch_upperstack_bte_sched_handler)(void);

extern BOOL_PATCH_FUNC(*patch_upperstack_hci_entry)(T_HCI *p_hci);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_send_pkt)(void);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_handle_evt_ind)(T_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_cmd_cmpl_evt)(uint8_t *p, uint16_t len);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_cmd_status_evt)(uint8_t *p);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_le_cmd_cmpl_evt)(uint16_t opcode, uint16_t status,
                                                              uint8_t *p);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_handle_le_evt)(uint8_t *p, uint16_t len);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_send_init_cmd)(void);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_send_cmd_msg)(uint16_t opcode, uint8_t *buf,
                                                           uint8_t len, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_adjust_link_quota)(T_HCI_LINK *p_link);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_if_callback)(T_HCI_IF_EVT evt, bool status,
                                                          uint8_t *p_buf, uint32_t len, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_hci_if_confirm)(uint8_t *p_buf, bool *ret);

extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_entry)(T_L2C *p_l2c);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_handle_data_ind)(T_MSG *p_msg, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2cu_send_data)(uint8_t conn_type, T_MSG *p_msg,
                                                         bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_segment_msg)(T_L2C_CHANN *p_chann, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_sdu_msg)(T_L2C_CHANN *p_chann, T_MSG *p_msg,
                                                           bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_pdu_msg)(uint16_t remote_cid, T_ACL_LINK *p_acl,
                                                           T_MSG *p_msg, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_fragment_msg)(T_ACL_LINK *p_acl, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_signal_msg)(T_L2C_CHANN *p_chann,
                                                              T_ACL_LINK *p_acl, uint8_t cmd_code,
                                                              uint8_t *p_param, uint16_t len, uint16_t timeout);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_handle_signal_pkt)(T_ACL_LINK *p_acl, T_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_change_state)(T_L2C_CHANN *p_chann, uint16_t event,
                                                           void *p_data);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_create_chann)(T_ACL_LINK *p_acl, uint16_t remote_cid,
                                                           T_L2C_CHANN **p_chann);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_handle_le_pdu_msg)(T_ACL_LINK *p_acl, uint16_t lcid,
                                                                T_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_handle_sdu_msg)(T_L2C_CHANN *p_chann, T_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_sframe)(T_L2C_CHANN *p_chann, uint16_t sframe,
                                                          uint16_t pf_bit);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_send_iframe)(T_L2C_CHANN *p_chann);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_retrans_iframe)(T_L2C_CHANN *p_chann);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_set_local_busy)(uint16_t cid, bool busy);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_delete_chann)(T_L2C_CHANN *p_chann, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_ecfc_send_segment_msg)(T_L2C_CHANN *p_chann,
                                                                    bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_ecfc_send_sdu_msg)(T_L2C_CHANN *p_chann, T_MSG *p_msg,
                                                                bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_ecfc_handle_sdu_msg)(T_L2C_CHANN *p_chann,
                                                                  T_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2cu_handle_conn_cmpl)(T_L2C_CHANN *p_chann,
                                                                uint16_t status);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2cu_handle_disconn_ind)(T_L2C_CHANN *p_chann,
                                                                  uint16_t status);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2cu_handle_disconn_rsp)(T_L2C_CHANN *p_chann,
                                                                  uint16_t result);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2cu_handle_authen_ind)(T_L2C_CHANN *p_chann,
                                                                 uint8_t outgoing);
extern BOOL_PATCH_FUNC(*patch_upperstack_l2c_handle_signal_cmd)(T_ACL_LINK *p_acl,
                                                                T_L2C_CMD l2c_cmd);

extern BOOL_PATCH_FUNC(*patch_upperstack_sm_entry)(T_SM *p_sm);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_check_process_security)(T_SM_LINK *p_link);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_change_sec_status)(T_SM_LINK *p_link, uint8_t state,
                                                               uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_check_br_sec_entry)(T_BR_SECURITY *p_entry, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_handle_br_authen_rsp)(uint8_t *bd_addr,
                                                                  uint16_t status);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_authen_cmpl)(T_SM_LINK *p_link, uint16_t cause,
                                                         T_SM_TYPE type);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_sc_check_public_key)(T_SM_LINK *p_link,
                                                                 uint8_t *result);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_le_key_exchange)(T_SM_LINK *p_link);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_handle_acl_disconnect)(uint8_t *bd_addr,
                                                                   uint8_t bd_type, uint16_t status);
extern BOOL_PATCH_FUNC(*patch_upperstack_ecc_make_key)(uint8_t public_key[64],
                                                       uint8_t private_key[32], uint64_t *random, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_sm_get_local_ident_addr)(T_SM_LINK *p_link,
                                                                  uint8_t **pp_addr, uint8_t *p_addr_type);

extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_entry)(T_GATT *p_gatt);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_send_discovery_ind)(uint16_t status,
                                                                  uint16_t conn_handle, uint16_t cid, uint16_t type,
                                                                  uint16_t count, uint16_t length, uint8_t *p_list, T_GATT_CURR_PROC *p_curr_proc,
                                                                  uint16_t *last_handle);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_handle_security_status)(uint8_t id, uint8_t *bd_addr,
                                                                      uint8_t bd_type, uint16_t cause,
                                                                      uint8_t key_type, uint8_t key_size);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_write_attr)(T_GATT_CHANN *p_chann, uint16_t handle,
                                                          uint8_t *p_att_value,
                                                          int *p_size, uint8_t type, uint32_t *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_search_attr)(T_GATT_CHANN *p_chann,
                                                           uint16_t type, bool prim, uint16_t *p_start_handle, uint16_t end_handle, int cmp_len,
                                                           uint8_t *p_cmp_value, int *p_cnt, uint8_t *p_list, int *p_size, int entry_size, uint32_t *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_att_tx_data_release)(T_GATT_CHANN *p_chann,
                                                              bool release_all);
extern BOOL_PATCH_FUNC(*patch_upperstack_att_send_req)(T_GATT_CHANN *p_chann, int len,
                                                       uint8_t opcode, uint16_t start_handle,
                                                       uint16_t end_handle, uint8_t *p_req_buf, int req_len, uint16_t  *status);
extern BOOL_PATCH_FUNC(*patch_upperstack_att_handle_rx_data)(T_GATT_CHANN *p_chann, uint8_t *p_head,
                                                             uint8_t offset, int len,
                                                             bool *release, bool deferred_msg, bool *p_att_handled);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_disconnected)(uint16_t handle, uint16_t result,
                                                            bool cfm);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_handle_le_conn_cmpl_evt)(uint16_t handle,
                                                                       uint16_t status, uint8_t role,
                                                                       uint8_t own_addr_type,
                                                                       uint8_t peer_addr_type,
                                                                       uint8_t *peer_addr, uint16_t conn_interval, uint16_t conn_latency,
                                                                       uint16_t supv_timeout, uint8_t adv_handle, uint16_t sync_handle);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_attr_check_perm)(T_GATT_CHANN *p_chann,
                                                               uint16_t handle,
                                                               T_GATT_ATTR *p_attr, bool write, uint32_t *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_gatt_handle_data_ind)(uint16_t handle, uint16_t cid,
                                                               T_MSG *p_msg);
#if F_BT_5_1_GATT_CACHING_SERVER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_upperstack_att_gatt_caching_handle_rx_data)(T_GATT_CHANN *p_chann,
                                                                          uint8_t *p_head, uint8_t offset,
                                                                          int len, bool *p_release, bool deferred_msg, bool *p_att_handled, bool *ret);
#endif

extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_entry)(T_SDP *p_sdp);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_handle_l2c_data)(uint16_t cid, uint8_t *p,
                                                              uint16_t length);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_decode_elem)(uint8_t *p_start, uint8_t *p_end,
                                                          uint32_t *p_len, uint8_t *p_type, uint8_t **p_patch_ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_db_search_attr)(uint32_t handle, uint16_t attr,
                                                             uint32_t *attr_len, uint16_t *p_next_attr, uint8_t **p_patch_ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_set_new_eir)(void);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_create_attr_list)(uint8_t *p_buf, uint16_t buf_size,
                                                               uint16_t index, uint16_t start_pos,
                                                               uint16_t max_cnt, uint8_t *p_attr_list, uint32_t handle, uint8_t delete_empty, uint16_t *patch_ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_sdp_client_error)(T_SDP_CHANN *p_chann, uint8_t status);

extern BOOL_PATCH_FUNC(*patch_upperstack_btif_entry)(T_BTIF *p_btif);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_user_defined)(void *p_buf);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_sdp_conn_cmpl)(uint8_t *bd_addr, uint16_t cid,
                                                             uint16_t status);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_gatt_conn_cmpl)(uint8_t *bd_addr, uint16_t handle,
                                                              uint16_t frame_size, uint16_t *p_param);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_send_msg)(T_BTIF_DOWN_MSG *p_msg, bool alloc,
                                                        bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_send_event)(T_BTIF_UP_MSG *p_msg, bool alloc,
                                                          bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_handle_command)(T_BTIF_DOWN_MSG *p_msg, bool *ret);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_gatt_disconn_ind)(uint16_t status, uint8_t *bd_addr);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_decode_rfc_attr)(uint8_t *bd_addr,
                                                               uint8_t *p_attr_start, uint16_t attr_len);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_data_get_cfm)(uint16_t status, T_DEV_DATA *p_data);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_sw_reset_rsp)(uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_upperstack_btif_sdp_disconnect)(T_BTIF_LINK *p_link, uint16_t status);

#endif /* _PATCH_UPPERSTACK_H_ */
