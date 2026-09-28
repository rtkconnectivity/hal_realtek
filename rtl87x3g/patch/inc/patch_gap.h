/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_GAP_H_
#define _PATCH_GAP_H_

#include <patch.h>
#include <btif.h>
#include <gap_adv.h>
#include <gap.h>
#include <gap_conn_le.h>
#include <gap_chann_int.h>
#include <profile_client_def.h>
#include <gap_link_mgr.h>
#include <gap_storage_le.h>
#include <profile_server_def.h>
#include <gap_ext_adv.h>
#include <gap_bond_manager.h>
#include <gap_storage_flash_int.h>
#include <gap_aox_connless_transmitter_int.h>
#include <gap_le_types.h>
#include <gap_big_mgr_int.h>
#include <gap_pa_sync_int.h>
#include <gap_cig_mgr_int.h>
#include <gap_br.h>
#include <gap_pa_adv.h>
#include <gatt_server_service_change.h>

#ifdef __cplusplus
extern "C" {
#endif

/* le */
extern BOOL_PATCH_FUNC(*patch_gap_le_handle_btif_msg)(T_BTIF_UP_MSG *p_msg, bool *release);
extern BOOL_PATCH_FUNC(*patch_gap_gap_handle_btif_msg)(T_BTIF_UP_MSG *p_msg, bool *release);
extern BOOL_PATCH_FUNC(*patch_gap_le_set_gap_param)(uint16_t param, uint8_t len, void *p_value,
                                                    T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_get_gap_param)(uint16_t param, void *p_value,
                                                    T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_get_conn_param)(T_LE_CONN_PARAM_TYPE param, void *p_value,
                                                     uint8_t conn_id, T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_send_dev_state)(uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_le_gap_init)(uint8_t link_num, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_start_advertising_by_steps)(void);
extern BOOL_PATCH_FUNC(*patch_gap_server_register_services)(bool *result);
extern BOOL_PATCH_FUNC(*patch_gap_client_send_gatt_discovery_req)(T_GAP_CHANN *p_client_chann,
                                                                  T_BTIF_GATT_DISCOVERY_TYPE discovery_type,
                                                                  T_DISCOVERY_STATE discovery_state,
                                                                  T_CLIENT_ID client_id,
                                                                  uint16_t uuid16,
                                                                  uint8_t *p_uuid128,
                                                                  uint16_t start_handle,
                                                                  uint16_t end_handle, T_GAP_CAUSE *result);
extern BOOL_PATCH_FUNC(*patch_gap_client_get_chann)(const char *p_func_name, uint16_t conn_handle,
                                                    uint16_t cid,
                                                    T_CLIENT_ID client_id, T_GAP_CHANN **p_client_chann);
extern BOOL_PATCH_FUNC(*patch_gap_client_attr_pre_write_continue)(T_GAP_CHANN *p_client_chann,
                                                                  T_GAP_WRITE_LONG *p_write_long, T_CLIENT_ID client_id,  T_GAP_CAUSE *result);
extern BOOL_PATCH_FUNC(*patch_gap_client_handle_gatt_discovery_ind)(T_BTIF_GATT_DISCOVERY_IND
                                                                    *disc_ind);
extern BOOL_PATCH_FUNC(*patch_gap_le_link_find_by_link_id)(uint16_t link_id, T_LE_LINK **p_link);
extern BOOL_PATCH_FUNC(*patch_gap_le_link_find_by_bd_addr)(uint8_t *bd_addr, uint8_t bd_type,
                                                           T_LE_LINK **p_link);
extern BOOL_PATCH_FUNC(*patch_gap_le_link_check_conn_id_internal)(const char *p_func_name,
                                                                  uint8_t conn_id, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_connect)(uint8_t init_phys,
                                              uint8_t *remote_bd, T_GAP_REMOTE_ADDR_TYPE remote_bd_type,
                                              T_GAP_LOCAL_ADDR_TYPE local_bd_type, uint16_t scan_timeout, T_GAP_CAUSE *result);
extern BOOL_PATCH_FUNC(*patch_gap_acl_get_remote_client_supported_features)(uint16_t conn_handle,
                                                                            uint8_t *p_client_supp_feats_len,
                                                                            uint8_t *p_client_supp_feats, uint8_t **pp_client_supp_feats, bool copy_value_flag,
                                                                            T_GAP_CAUSE *result);
extern BOOL_PATCH_FUNC(*patch_gap_le_delete_key_entry)(T_LE_KEY_ENTRY *p_entry);
extern BOOL_PATCH_FUNC(*patch_gap_le_get_key)(T_LE_KEY_ENTRY *p_entry, T_GAP_KEY_TYPE key_type,
                                              uint8_t *key, uint8_t *key_len);
extern BOOL_PATCH_FUNC(*patch_gap_le_save_key)(T_LE_KEY_ENTRY *p_entry, T_GAP_KEY_TYPE key_type,
                                               uint8_t key_length,
                                               uint8_t *key, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_find_key_entry)(uint8_t *bd_addr,
                                                     T_GAP_REMOTE_ADDR_TYPE bd_type, T_LE_KEY_ENTRY **p_entry);
extern BOOL_PATCH_FUNC(*patch_gap_init_steps)(bool *skip);
extern BOOL_PATCH_FUNC(*patch_gap_server_ext_send_data)(uint16_t conn_handle, uint16_t cid,
                                                        T_SERVER_ID service_id,
                                                        uint16_t attrib_index,
                                                        uint8_t *p_data,
                                                        uint16_t data_len,
                                                        T_GATT_PDU_TYPE type, uint8_t *result);
extern BOOL_PATCH_FUNC(*patch_gatt_add_builtin_services)(bool use_ext, bool gatt_service,
                                                         bool gap_service, bool *ret);

extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_get_param)(T_LE_EXT_ADV_PARAM_TYPE param,
                                                        void *p_value, T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_find_by_handle)(uint8_t adv_handle,
                                                             T_LE_EXT_ADV **p_adv);
extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_find_by_conn_handle)(uint16_t conn_handle,
                                                                  T_LE_EXT_ADV **p_adv);
extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_state_info)(uint8_t adv_handle,
                                                         T_GAP_EXT_ADV_STATE state, uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_set_by_steps)(void);
extern BOOL_PATCH_FUNC(*patch_gap_le_ext_adv_send_setting_result)(uint16_t cause,
                                                                  uint8_t adv_handle, uint8_t flag);

extern BOOL_PATCH_FUNC(*patch_gap_le_ext_scan_state_info)(uint16_t cause, uint8_t state);

#if F_BT_LE_5_0_PA_ADV_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_send_pa_adv_state)(uint8_t adv_handle, T_GAP_PA_ADV_STATE state,
                                                     uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_check_support_periodic_adv)(uint8_t adv_handle,
                                                                        uint16_t adv_event_prop, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_find_by_handle)(uint8_t adv_handle,
                                                            T_LE_PA_ADV **p_pa_adv);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_allocate)(uint8_t adv_handle, T_LE_PA_ADV **p_pa_adv);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_check_pa_adv_state_idle_internal)(
    const char *p_func_name, uint8_t adv_handle, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_trigger_pa_adv_state)(uint16_t cause,
                                                                  uint8_t adv_handle,
                                                                  T_GAP_EXT_ADV_STATE ext_adv_state);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_set_by_steps)(void);
#if F_BT_LE_5_2_ISOC_BIS_BROADCASTER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_set_big_used_param)(uint8_t adv_handle, bool enable);
#endif
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_adv_send_setting_result)(uint16_t cause, uint8_t adv_handle,
                                                                 uint8_t flag);
#endif

#if F_BT_LE_5_0_PA_SYNC_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_send_pa_sync_dev_state)(uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_send_pa_sync_state)(uint8_t sync_id, uint16_t sync_handle,
                                                      T_GAP_PA_SYNC_STATE state,
                                                      bool sync_transfer_received_flag, uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_allocate)(uint8_t *adv_addr, uint8_t adv_addr_type,
                                                       uint8_t adv_sid, T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_release)(T_LE_PA_SYNC *p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_sync_id)(uint8_t sync_id,
                                                              T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_sync_handle)(uint16_t sync_handle,
                                                                  T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_periodic_adv_info)(uint8_t *adv_addr,
                                                                        uint8_t adv_addr_type,
                                                                        uint8_t adv_sid,  T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_terminate_sync_flag)(
    bool pa_terminate_sync_flag,
    uint8_t *p_pa_sync_idx, T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_get_sync_num)(bool active, uint8_t *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_check_sync_id_internal)(const char *p_func_name,
                                                                     uint8_t sync_id, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_init)(uint8_t sync_handle_num, T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_get_param)(T_GAP_PA_SYNC_PARAM_TYPE param,
                                                        void *p_value, uint8_t sync_id, T_GAP_CAUSE *ret);
#if F_BT_LE_5_0_PA_SYNC_SCAN_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_create_sync_flag)(bool pa_create_sync_flag,
                                                                       uint8_t *p_pa_sync_idx, T_LE_PA_SYNC **p_pa_sync);
extern BOOL_PATCH_FUNC(*patch_gap_pa_sync_trigger_pa_sync_state)(uint16_t cause, uint8_t state);
#endif
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_handle_sync_terminated)(uint16_t sync_handle,
                                                                     uint16_t cause);
#if ((F_BT_LE_5_0_PA_SYNC_SUPPORT && F_BT_LE_5_1_SUPPORT) || F_BT_LE_5_1_PAST_RECIPIENT_SUPPORT)
extern BOOL_PATCH_FUNC(*patch_gap_le_pa_sync_find_by_pa_receive_enable_flag)(
    bool pa_receive_enable_flag,
    uint8_t *p_pa_sync_idx, T_LE_PA_SYNC **p_pa_sync);
#endif
#endif
#if F_BT_LE_5_2_ISOC_BIS_RECEIVER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_pa_sync_set_big_used_param)(uint16_t sync_handle, bool enable);
#endif

#if F_BT_LE_5_1_AOX_CONNLESS_TRANSMITTER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_send_aox_connless_transmitter_state)(uint8_t adv_handle,
                                                                       T_GAP_AOX_CONNLESS_TRANSMITTER_STATE state, uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_le_aox_connless_transmitter_trigger_transmit_state)(
    uint16_t cause, uint8_t adv_handle,
    bool ext_adv_state_flag, T_GAP_EXT_ADV_STATE ext_adv_state, bool pa_adv_state_flag,
    T_GAP_PA_ADV_STATE pa_adv_state);
extern BOOL_PATCH_FUNC(*patch_gap_le_aox_connless_transmitter_check_support_cte_transmitter)(
    uint8_t adv_handle,
    T_GAP_PHYS_TYPE secondary_adv_phy, bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_le_aox_connless_transmitter_find_by_handle)(uint8_t adv_handle,
                                                                              T_LE_AOX_CONNLESS_TRANSMITTER **p_aox_connless_transmitter);
extern BOOL_PATCH_FUNC(*patch_gap_le_aox_connless_transmitter_allocate)(uint8_t adv_handle,
                                                                        T_LE_AOX_CONNLESS_TRANSMITTER **p_aox_connless_transmitter);
#endif

#if F_BT_LE_5_2_ISOC_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_le_isoch_find_by_handle)(uint16_t handle, bool common_handle_flag,
                                                           T_LE_ISOCH **p_isoch);
#endif

#if F_BT_LE_5_2_ISOC_BIS_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_find_by_big_handle)(uint8_t big_handle,
                                                              T_LE_BIG_HANDLE **p_big_handle);
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_release_big_handle)(uint8_t big_handle);
#if F_BT_LE_5_2_ISOC_BIS_BROADCASTER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_send_isoc_broadcast_state)(uint8_t big_handle, uint8_t adv_handle,
                                                             T_GAP_BIG_ISOC_BROADCAST_STATE new_state, uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_trigger_isoc_broadcast_state)(uint16_t cause,
                                                                        uint8_t adv_handle,
                                                                        bool ext_adv_state_flag, T_GAP_EXT_ADV_STATE ext_adv_state,  bool pa_adv_state_flag,
                                                                        T_GAP_PA_ADV_STATE pa_adv_state);
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_isoc_broadcaster_find_big_by_big_handle)(
    uint8_t big_handle, T_BIG_ISOC_BROADCASTER_ENTRY **p_big);
#endif
#if F_BT_LE_5_2_ISOC_BIS_RECEIVER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_sync_receiver_send_dev_state)(uint8_t big_handle,
                                                                        uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_sync_receiver_send_sync_state)(uint8_t big_handle,
                                                                         uint8_t sync_id,
                                                                         uint16_t sync_handle, T_GAP_BIG_SYNC_RECEIVER_SYNC_STATE new_state, uint16_t cause);
extern BOOL_PATCH_FUNC(*patch_gap_big_mgr_sync_receiver_find_big_by_big_handle)(uint8_t big_handle,
                                                                                T_BIG_SYNC_RECEIVER_ENTRY **p_big);
#endif
#endif

#if F_BT_LE_5_2_ISOC_CIS_CENTRAL_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_cig_mgr_find_cis_by_id)(uint8_t cis_id, T_CIS_ENTRY **p_cis);
extern BOOL_PATCH_FUNC(*patch_gap_cig_mgr_find_cig_by_id)(uint8_t cig_id, T_CIG_ENTRY **p_cig);
extern BOOL_PATCH_FUNC(*patch_gap_cig_mgr_update_cig_inactive_state)(uint8_t cig_id);
#endif

#if F_BT_LE_5_2_ISOC_DATA_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_iso_data_cfm)(void *p_buf, bool *ret);
#endif

#if F_BT_4_0_GATT_SERVER_SERVICE_CHANGE_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_acl_update_service_change_state)(
    T_GATT_SERVER_SERVICE_CHANGE_UPDATE_SERVICE_CHANGE_STATE_PARAM *p_param, bool btif_msg,
    bool clear_all_conn_handle, T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_gatt_server_service_change_handle_service_change_state)(
    uint8_t service_change,
    uint16_t conn_handle, uint8_t service_change_state, bool btif_msg, bool send_indication_to_client);
#endif

#if F_BT_5_1_GATT_CACHING_SERVER_SUPPORT
extern BOOL_PATCH_FUNC(*patch_gap_gatt_caching_server_check_send_data)(uint16_t conn_handle,
                                                                       bool check_attrib,
                                                                       uint8_t service_id,
                                                                       uint16_t attrib_index, bool *restrict);
extern BOOL_PATCH_FUNC(*patch_gap_gatt_caching_server_handle_service_change)(void);
#endif

/* legacy */
extern BOOL_PATCH_FUNC(*patch_gap_legacy_handle_btif_msg)(T_BTIF_UP_MSG *p_msg);
extern BOOL_PATCH_FUNC(*patch_gap_legacy_set_gap_param)(T_GAP_BR_PARAM_TYPE type, uint8_t len,
                                                        void *p_value, T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC patch_legacy_vendor_handle_btif_msg;

/* common */
extern BOOL_PATCH_FUNC(*patch_gap_gap_handle_msg)(uint8_t event);
extern BOOL_PATCH_FUNC(*patch_gap_imp_flash_save)(void *p_data, uint16_t start_offset,
                                                  uint16_t block_size,
                                                  uint8_t size, uint8_t idx, uint32_t *result);
extern BOOL_PATCH_FUNC(*patch_gap_imp_flash_load)(void *p_data, uint16_t start_offset,
                                                  uint16_t block_size,
                                                  uint8_t size, uint8_t idx, uint32_t *result);
extern BOOL_PATCH_FUNC(*patch_gap_bond_priority_queue_add)(T_DEV_TYPE type, uint8_t idx,
                                                           bool *result);
extern BOOL_PATCH_FUNC(*patch_gap_bond_priority_queue_delete)(T_DEV_TYPE type, uint8_t idx,
                                                              bool *ret);
extern BOOL_PATCH_FUNC(*patch_gap_bond_set_high_priority)(T_DEV_TYPE type, uint8_t idx,
                                                          bool *result);
extern BOOL_PATCH_FUNC(*patch_gap_get_param)(T_GAP_PARAM_TYPE param, void *p_value,
                                             T_GAP_CAUSE *ret);
extern BOOL_PATCH_FUNC(*patch_gap_set_param)(T_GAP_PARAM_TYPE param, uint8_t len, void *p_value,
                                             T_GAP_CAUSE *ret);

extern BOOL_PATCH_FUNC(*patch_gap_chann_check_conn_state_internal)(const char *p_func_name,
                                                                   uint16_t conn_handle,
                                                                   uint16_t cid, T_GAP_CHANN **p_gap_chann);
extern BOOL_PATCH_FUNC(*patch_gap_cccd_handle_store_ind)(T_GATT_SERVER_STORE_IND *store_ind,
                                                         T_CCCD_DATA **p_cccd_data);
extern BOOL_PATCH_FUNC(*patch_gap_chann_del)(T_GAP_CHANN *p_gap_chann);
extern BOOL_PATCH_FUNC(*patch_flash_storage_common_init)(void);

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_GAP_H_ */
