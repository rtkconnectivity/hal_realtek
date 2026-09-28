/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_PROFILE_H_
#define _PATCH_PROFILE_H_

#include <patch.h>

#ifdef __cplusplus
extern "C" {
#endif

/* jitter buffer_process patch function pointer */
extern BOOL_PATCH_FUNC patch_jb_state_machine;
extern BOOL_PATCH_FUNC patch_jb_state_machine_vendor_codec;
extern BOOL_PATCH_FUNC patch_jb_update_asrc_offet;
extern BOOL_PATCH_FUNC patch_jb_update_jb_timestamp_t1_asrc;
extern BOOL_PATCH_FUNC patch_jb_routine;


/* rws patch function pointer */
extern BOOL_PATCH_FUNC patch_rtkdtp_callback;
extern BOOL_PATCH_FUNC patch_rws_rx_data_ind;
extern BOOL_PATCH_FUNC patch_rws_rtkdtp_callback;
extern BOOL_PATCH_FUNC patch_rws_pairing_process;
extern BOOL_PATCH_FUNC patch_rws_send_out;
extern BOOL_PATCH_FUNC patch_rws_set_sw_timer;
extern BOOL_PATCH_FUNC patch_rws_sw_timer_process;
extern BOOL_PATCH_FUNC patch_rws_hw_timer_process;
extern BOOL_PATCH_FUNC patch_rws_exception_process;
extern BOOL_PATCH_FUNC patch_rws_update_acl_scan_win;
extern BOOL_PATCH_FUNC patch_rws_judge_role;
extern BOOL_PATCH_FUNC patch_rws_spk2_check_resume;
extern BOOL_PATCH_FUNC patch_rws_sync_execution;
extern BOOL_PATCH_FUNC patch_rws_spk1_send_stream_process;

/* rba patch function pointer */
extern BOOL_PATCH_FUNC patch_rba_command_handler;
extern BOOL_PATCH_FUNC patch_rba_event_handler;
extern BOOL_PATCH_FUNC patch_rba_csb_slave_start_to_play_process;
extern BOOL_PATCH_FUNC patch_rba_csb_set_pbd_high_priority;
extern BOOL_PATCH_FUNC patch_rba_csb_broadcast_pbd_process;
extern BOOL_PATCH_FUNC patch_rba_csb_mac_tx_complete;
extern BOOL_PATCH_FUNC patch_rba_csb_rx_pbd_process;

/* a2dp patch function pointer */
extern BOOL_PATCH_FUNC patch_a2dp_init;
extern BOOL_PATCH_FUNC patch_a2dp_tout_callback;
extern BOOL_PATCH_FUNC patch_a2dp_callback;
extern BOOL_PATCH_FUNC patch_a2dp_parsing_vendor_codec_param;

/* avdtp patch function pointer */
extern BOOL_PATCH_FUNC patch_avdtp_init;
extern BOOL_PATCH_FUNC patch_avdtp_tout_callback;
extern BOOL_PATCH_FUNC patch_avdtp_vendor_codec_handler;
extern BOOL_PATCH_FUNC patch_avdtp_send_cmd;
extern BOOL_PATCH_FUNC patch_avdtp_parsing_capability;
extern BOOL_PATCH_FUNC patch_avdtp_set_cfg_cmd_proc;
extern BOOL_PATCH_FUNC patch_avdtp_cmd_error_check_proc;
extern BOOL_PATCH_FUNC patch_avdtp_callback;
extern BOOL_PATCH_FUNC patch_avdtp_handle_rx_signal_ind;
extern BOOL_PATCH_FUNC patch_avdtp_rx_cmd_proc;
extern BOOL_PATCH_FUNC patch_avdtp_rx_rsp_proc;

/* avrcp patch function pointer */
extern BOOL_PATCH_FUNC patch_avrcp_init;
extern BOOL_PATCH_FUNC patch_avrcp_tout_callback;
extern BOOL_PATCH_FUNC patch_avrcp_handle_cmd;
extern BOOL_PATCH_FUNC patch_avrcp_handle_rsp;

/* avctp patch function pointer */
extern BOOL_PATCH_FUNC patch_avctp_callback;
extern BOOL_PATCH_FUNC patch_avctp_send_data2buf;

/* hfp patch function pointer */
extern BOOL_PATCH_FUNC patch_hfp_init;
extern BOOL_PATCH_FUNC patch_hfp_tout_callback;
extern BOOL_PATCH_FUNC patch_hfp_handle_rfc_msg;
extern BOOL_PATCH_FUNC patch_hfp_rfc_data_ind;
extern BOOL_PATCH_FUNC patch_hfp_rx_at_cmd_rsp;
extern BOOL_PATCH_FUNC patch_hfp_srv_level_proc;
extern BOOL_PATCH_FUNC patch_hfp_at_cmd_queue_in;
extern BOOL_PATCH_FUNC patch_hfp_at_cmd_queue_out;
extern BOOL_PATCH_FUNC patch_hfp_try_send_at_cmd;
extern BOOL_PATCH_FUNC patch_hfp_send_at_cmd;

/* rfcomm patch function pointer */
extern BOOL_PATCH_FUNC patch_profile_rfc_conn_req;
extern BOOL_PATCH_FUNC patch_profile_rfc_conn_cfm;
extern BOOL_PATCH_FUNC patch_profile_rfc_disc_req;
extern BOOL_PATCH_FUNC patch_profile_rfc_data_req;
extern BOOL_PATCH_FUNC patch_profile_rfc_check_send_credit;
extern BOOL_PATCH_FUNC patch_profile_rfc_handle_l2c_msg;
extern BOOL_PATCH_FUNC patch_profile_rfc_handle_timeout;
extern BOOL_PATCH_FUNC patch_profile_rfc_close_data_chann;
extern BOOL_PATCH_FUNC patch_profile_rfc_check_disconn_ctrl_chann;
extern BOOL_PATCH_FUNC patch_profile_rfc_handle_authen_rsp;
extern BOOL_PATCH_FUNC patch_profile_rfc_handle_l2c_data_ind;

/* obex patch function pointer */
extern BOOL_PATCH_FUNC patch_obex_init;
extern BOOL_PATCH_FUNC patch_obex_handle_rfc_callback;
extern BOOL_PATCH_FUNC patch_obex_handle_l2c_callback;
extern BOOL_PATCH_FUNC patch_obex_handle_rcv_data;
extern BOOL_PATCH_FUNC patch_obex_parse_packet;

/* pbap patch function pointer */
extern BOOL_PATCH_FUNC patch_pbap_handle_obex_callback;
extern BOOL_PATCH_FUNC patch_pbap_get_vcard_listing_by_number;
extern BOOL_PATCH_FUNC patch_pbap_get_vcard_listing;
extern BOOL_PATCH_FUNC patch_pbap_get_vcard_entry;
extern BOOL_PATCH_FUNC patch_pbap_conn_req;

/* iap patch function pointer */
extern BOOL_PATCH_FUNC patch_iap_handle_rcv_packet;
extern BOOL_PATCH_FUNC patch_iap_send_cmd;
extern BOOL_PATCH_FUNC patch_iap2_send_cmd;
extern BOOL_PATCH_FUNC patch_iap2_handle_ctrl_session_packet;
extern BOOL_PATCH_FUNC patch_iap_access_cp;
extern BOOL_PATCH_FUNC patch_iap2_wrap_id_packet;
extern BOOL_PATCH_FUNC patch_iap2_wrap_msg;

/* spp patch function pointer */
extern BOOL_PATCH_FUNC patch_spp_init;
extern BOOL_PATCH_FUNC patch_spp_tout_callback;
extern BOOL_PATCH_FUNC patch_spp_handle_rfc_cb;

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_PROFILE_H_ */
