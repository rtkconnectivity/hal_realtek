/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_PLATFORM_H_
#define _PATCH_PLATFORM_H_

#include <patch.h>
#include "platform_utils_int.h"
#include "pmu_manager.h"
#include "power_manager_interface.h"
#include "power_manager_master.h"
#include "power_manager_slave.h"
#include "power_manager_unit_platform.h"
#include "os_pm.h"
#include "phy_common_int.h"
#include "rfc_int.h"
#include "modem_int.h"
#include "phy_int.h"
#include "thermal.h"
#include "rtl876x_gdma.h"
#include <debug_port.h>
#include "flash_nor_basic.h"
#include "efuse.h"

#ifdef __cplusplus
extern "C" {
#endif

//extern BOOL_PATCH_FUNC patch_set_cpu_clock;
//extern BOOL_PATCH_FUNC patch_set_flash_clock;
//extern BOOL_PATCH_FUNC patch_set_40M_clock;
//extern BOOL_PATCH_FUNC patch_SystemInit;
extern BOOL_PATCH_FUNC patch_hal_setup_hardware;
extern BOOL_PATCH_FUNC patch_hal_setup_cpu;
//extern BOOL_PATCH_FUNC patch_debug_monitor_enable;
extern BOOL_PATCH_FUNC patch_main;
extern VOID_PATCH_FUNC patch_fw_sim;
extern BOOL_PATCH_FUNC Patch_Dump_CPU_Register_and_Memory;
extern BOOL_PATCH_FUNC patch_hw_aes_decrypt_code_init_slim;
extern BOOL_PATCH_FUNC patch_hw_aes_decrypt_16byte;
extern BOOL_PATCH_FUNC patch_hw_aes_operate;
extern BOOL_PATCH_FUNC patch_share_cache_ram;
extern BOOL_PATCH_FUNC patch_SystemCall;
extern BOOL_PATCH_FUNC patch_SystemCall_Stack;
extern BOOL_PATCH_FUNC patch_mp_read_cmd;
extern BOOL_PATCH_FUNC patch_mp_parse_cmd;
extern BOOL_PATCH_FUNC patch_feature_check_timer_callback;
//[FreeRTOS]
extern BOOL_PATCH_FUNC patch_vTaskStartScheduler;
extern BOOL_PATCH_FUNC patch_prvIdleTask;
extern BOOL_PATCH_FUNC patch_vApplicationIdleHook;
extern BOOL_PATCH_FUNC patch_vTaskSwitchContext;
extern BOOL_PATCH_FUNC patch_traceTaskSwitchIn;
extern BOOL_PATCH_FUNC patch_vApplicationMallocFailedHook;
extern BOOL_PATCH_FUNC patch_vApplicationStackOverflowHook;
extern BOOL_PATCH_FUNC patch_traceDISABLE_IRQ PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_traceENABLE_IRQ PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_tracePORT_RAISE_BASE_PRI PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_tracePORT_SET_BASE_PRI PATCH_POINTER_SECTION;
//extern BOOL_PATCH_FUNC patch_AliOSInit PATCH_POINTER_SECTION;
//extern BOOL_PATCH_FUNC patch_AliOSStart PATCH_POINTER_SECTION;
//extern BOOL_PATCH_FUNC patch_AliOSTaskCreate PATCH_POINTER_SECTION;
//extern BOOL_PATCH_FUNC patch_AliOSTick PATCH_POINTER_SECTION;
//[DLPS]
//extern BOOL_PATCH_FUNC patch_dlps_processing;
//[Log]
extern BOOL_PATCH_FUNC patch_LogUARTDriverInit;
extern BOOL_PATCH_FUNC patch_LogUartTxChar;
extern BOOL_PATCH_FUNC patch_log_timestamp_get;
extern BOOL_PATCH_FUNC patch_log_direct;
extern BOOL_PATCH_FUNC patch_log_buffer;
extern BOOL_PATCH_FUNC patch_log_snoop;
extern BOOL_PATCH_FUNC patch_trace_bdaddr;
extern BOOL_PATCH_FUNC patch_trace_string;
extern BOOL_PATCH_FUNC patch_trace_binary;
extern BOOL_PATCH_FUNC patch_LogBuffer_LS;
extern BOOL_PATCH_FUNC patch_LogBufferLowerStack;
extern BOOL_PATCH_FUNC patch_LogBuffer_LSData;
extern BOOL_PATCH_FUNC patch_LogBufferLowerStackData;
extern BOOL_PATCH_FUNC patch_log_buffer_optimise_enable PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_PPB_Init;
extern BOOL_PATCH_FUNC patch_PPB_Write;
extern BOOL_PATCH_FUNC patch_LogDMA_SM_Init;
extern BOOL_PATCH_FUNC patch_LogDMA_SM_Dispatch;
extern BOOL_PATCH_FUNC patch_LogUartDMAInit;
extern BOOL_PATCH_FUNC patch_hw_timer_log_timestamp_init;
extern BOOL_PATCH_FUNC patch_hardfault_print_buffered_log;
extern BOOL_PATCH_FUNC patch_log_pm_check;
extern BOOL_PATCH_FUNC patch_log_buffer_lowerstack;
//[Heap]
extern BOOL_PATCH_FUNC patch_pvPortMalloc;
extern BOOL_PATCH_FUNC patch_vPortFree;
extern BOOL_PATCH_FUNC patch_prvHeapInit;
// eflash
#if (PLATFORM_SUPPORT_ROM_FTL == 1)
extern BOOL_PATCH_FUNC patch_ftl_init;
extern BOOL_PATCH_FUNC patch_ftl_read;
extern BOOL_PATCH_FUNC patch_ftl_write;
extern BOOL_PATCH_FUNC patch_ftl_get_error;
extern BOOL_PATCH_FUNC patch_ftl_ioctl;
extern BOOL_PATCH_FUNC patch_ftl_page_garbage_collect_Imp;
extern BOOL_PATCH_FUNC patch_ftl_record_check;
extern BOOL_PATCH_FUNC patch_ftl_page_can_addr_drop;
extern BOOL_PATCH_FUNC patch_read_mapping_table;
extern BOOL_PATCH_FUNC patch_write_mapping_table;
extern BOOL_PATCH_FUNC patch_ftl_mapping_table_init;
extern BOOL_PATCH_FUNC patch_ftl_page_garbage_collect;
extern BOOL_PATCH_FUNC patch_ftl_save_to_storage;
extern BOOL_PATCH_FUNC patch_ftl_load_from_storage;
extern BOOL_PATCH_FUNC patch_ftl_page_read;
extern BOOL_PATCH_FUNC patch_ftl_page_write;
extern BOOL_PATCH_FUNC patch_ftl_page_erase;
extern BOOL_PATCH_FUNC patch_ftl_page_format;
#else
extern BOOL_PATCH_FUNC patch_ftl_save_to_storage PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_ftl_load_from_storage PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_ftl_garbage_collect_in_idle PATCH_POINTER_SECTION;

extern BOOL_PATCH_FUNC patch_ftl_ioctl PATCH_POINTER_SECTION;
extern BOOL_PATCH_FUNC patch_ftl_init PATCH_POINTER_SECTION;
#endif

//[Nor flash]
extern BOOL_PATCH_FUNC patch_flash_nor_ioctl;

//[Boot check]
extern BOOL_PATCH_FUNC patch_check_image_crc16;
extern BOOL_PATCH_FUNC patch_check_image_sha256;

//OTA
//extern BOOL_PATCH_FUNC  patch_dfu_timer_init;
//extern BOOL_PATCH_FUNC  patch_dfu_handle_btif_message;
extern BOOL_PATCH_FUNC  patch_dfu_prepare_image;
//extern BOOL_PATCH_FUNC  patch_dfu_copy_img;
extern BOOL_PATCH_FUNC  patch_dfu_reset;
//extern BOOL_PATCH_FUNC  patch_dfu_report_target_fw_info;
//extern BOOL_PATCH_FUNC  patch_dfu_update;
//extern BOOL_PATCH_FUNC  patch_erase_temp_bank_header;
//extern BOOL_PATCH_FUNC  patch_dfu_check_checksum;
//extern BOOL_PATCH_FUNC  patch_dfu_fw_active_reset;
//extern BOOL_PATCH_FUNC  patch_dfu_init;
//extern BOOL_PATCH_FUNC  patch_dfu_erase_img_flash_area;
//extern BOOL_PATCH_FUNC  patch_dfu_report_target_ic_type;
//extern BOOL_PATCH_FUNC  patch_dfu_flash_erase;
//extern BOOL_PATCH_FUNC  patch_dfu_checkbufcrc;
//extern BOOL_PATCH_FUNC  patch_BufferCheckProc;
//extern BOOL_PATCH_FUNC  patch_dfu_flash_check_blank;

extern BOOL_PATCH_FUNC patch_HardFaultRecord_TryToSave;
//extern BOOL_PATCH_FUNC patch_HardFaultRecord_DumpOldHistory;

/* =============================== Patch of efuse =============================== */
void efuse_write_protect_unlock_rom(void);
void efuse_write_protect_lock_rom(void);
void efuse_write_enable_rom(bool enable);
bool efuse_operate_rom(EFUSE_OPERATION_TYPE type, uint16_t addr, uint8_t *data);
void efuse_set_read_protect_rom(void);
void efuse_set_write_protect_rom(void);
/* ============================================================================== */

///* ================================= Patch of platform ENHTIMER =========================================== */
void proprietary_set_enhance_timer_rom(bool enable, uint8_t cnt);

///* ================================= Patch of platform RTC =========================================== */
void platform_rtc_write_safe_rom(uint32_t offset, uint32_t data);
void platform_rtc_aon_init_rom(void);
void platform_rtc_reset_rom(void);
void platform_rtc_run_cmd_rom(bool);
uint32_t platform_rtc_get_counter_rom(void);
void platform_rtc_set_comp_intr_config_rom(PFRTCComparator comp_bitmap, bool isr_type, bool enable);
void platform_rtc_set_comp_wk_config_rom(PFRTCComparator comp_bitmap, bool enable);
void platform_rtc_set_intr_group_config_rom(bool enable);
void platform_rtc_set_wk_group_config_rom(bool enable);
bool platform_rtc_get_intr_group_config_rom(void);
bool platform_rtc_get_wk_group_config_rom(void);
void platform_rtc_set_comp_rom(PFRTCComparator comp, uint32_t value);
uint32_t platform_rtc_get_comp_rom(PFRTCComparator comp);
PFRTCComparator platform_rtc_get_comp_intr_status_rom(void);
PFRTCComparator platform_rtc_get_comp_wk_status_rom(void);
void platform_rtc_set_comp_manual_intr_rom(PFRTCComparator comp_bitmap);
PFRTCComparator platform_rtc_get_comp_manual_intr_rom(void);
void platform_rtc_clear_comp_intr_status_rom(PFRTCComparator comp_bitmap);
void platform_rtc_clear_comp_wk_status_rom(PFRTCComparator comp_bitmap);
////* ===================================== End of platform RTC ======================================== */

///* ============================== Patch of PMU Manager ================================== */
void pmu_set_en_dr_fix_rom(bool enable);
void si_flow_data_init_rom(void);
void si_flow_before_power_on_sequence_restart_rom(void);
void si_flow_after_power_on_sequence_restart_rom(void);
void si_flow_before_enter_low_power_mode_rom(void);
void si_flow_after_exit_low_power_mode_rom(void);

void lop_pof_setting_rom(PlatformPowerMode power_mode);
void lop_pon_setting_rom(PlatformPowerMode power_mode);
void lop_setting_rom(PlatformPowerMode power_mode);
void pos_reg_setting_rom(POS_TYPE pos_type);
void pos_setting_rom(void);

uint8_t pmu_get_swr_vddcore_hq_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
uint8_t pmu_get_swr_vddcore_lq_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
uint8_t pmu_get_swr_vddana_hq_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
uint8_t pmu_get_swr_vddana_lq_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
uint8_t pmu_get_ldo_vddcore_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
uint8_t pmu_get_ldo_vddana_tune_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);

void pmu_set_pos_div_clk_rom(POS_TYPE pos_type, uint8_t div_clk);
void pmu_set_pos_pon_tune_rom(POS_TYPE pos_type, uint8_t tune);
void pmu_set_pos_pof_tune_rom(POS_TYPE pos_type, uint8_t tune);
uint8_t pmu_get_pos_pon_delay_rom(POS_TYPE pos_type);
uint8_t pmu_get_pos_pof_delay_rom(POS_TYPE pos_type);

void set_clk_32k_power_in_powerdown_rom(bool on);
uint32_t pmu_estimate_delay_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
void pmu_check_ldo_vddcore_rom(PlatformPowerMode power_mode);
void pmu_check_ldo_ret_rom(PlatformPowerMode power_mode);
void pmu_check_ldo_vddana_rom(PlatformPowerMode power_mode);
void pmu_check_ldo_ana_rom(PlatformPowerMode power_mode);
void pmu_check_swr_vddcore_rom(PlatformPowerMode power_mode);
void pmu_check_swr_vddana_rom(PlatformPowerMode power_mode);
void pmu_check_swr_core_rom(PlatformPowerMode power_mode);
void pmu_check_vcore_rom(PlatformPowerMode power_mode);
void pmu_check_ldo_311_rom(PlatformPowerMode power_mode);
void pmu_check_mbias_rom(PlatformPowerMode power_mode);
void pmu_check_delay_rom(PlatformPowerMode power_mode);

void pmu_handle_swr_core_lq_rom(PMUFlowType flow_type, PlatformPowerMode power_mode);
void pmu_handle_ldo_318_rf_rom(PlatformPowerMode power_mode);

void pmu_apply_voltage_tune_rom(void);
void pmu_pm_check_rom(PlatformPowerMode power_mode);
void pmu_pm_enter_rom(PlatformPowerMode power_mode);
void pmu_pm_exit_rom(void);
void pmu_power_on_sequence_restart_rom(void);
///* ============================== End of PMU Manager ================================== */

///* ============================== Patch of power manager master API ================================== */
void power_manager_master_wait_m2s_act_msg_ready_rom(PMSlave slave);
void power_manager_master_send_m2s_act_msg_rom(PMSlave slave,
                                               PMM2SActivateMessage *p_pm_m2s_act_msg);
void power_manager_master_wait_m2s_inact_msg_ready_rom(PMSlave slave);
void power_manager_master_send_m2s_inact_msg_rom(PMSlave slave,
                                                 PMM2SInactivateMessage *p_pm_m2s_inact_msg);
void power_manager_master_receive_s2m_inact_msg_rom(PMSlave slave,
                                                    PMS2MInactivateMessage *p_pm_s2m_inact_msg);
void power_manager_master_receive_s2m_act_msg_rom(PMSlave slave,
                                                  PMS2MActivateMessage *p_pm_s2m_act_msg);
PMSlave power_manager_master_get_another_slave_rom(PMSlave slave);
PowerManagerUnit *power_manager_master_get_system_level_header_unit_rom(PMSlave slave,
                                                                        PMSystemLevel sys_lvl);
void power_manager_master_init_inactivate_candidate_rom(PMSlave slave);
bool power_manager_master_find_inactivate_candidate_rom(PMSlave slave, PMSystemLevel sys_lvl);
PowerManagerUnit *power_manager_master_get_inactivate_candidate_rom(PMSlave slave);
PMSystemLevel power_manager_master_get_inactivate_candidate_system_level_rom(PMSlave slave);
bool power_manager_master_is_inactivate_candidate_rom(PMSlave slave, PMUnitID unit_id);
bool power_manager_master_is_inactivate_candidate_syste_level_end_rom(PMSlave slave);
void power_manager_master_init_activate_candidate_rom(PMSlave slave);
bool power_manager_master_find_activate_candidate_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                                      PMRTCComparator wakeup_comp, PMRTCComparator *activate_comp);
PowerManagerUnit *power_manager_master_get_activate_candidate_rom(PMSlave slave);
PMSystemLevel power_manager_master_get_activate_candidate_system_level_rom(PMSlave slave);
bool power_manager_master_is_activate_candidate_rom(PMSlave slave, PMUnitID unit_id);
bool power_manager_master_get_activate_flow_idle_rom(PMSlave slave);
bool power_manager_master_check_activate_valid_rom(PMSlave slave, PMSystemLevel sys_lvl);
bool power_manager_master_is_slave_idle_rom(PMSlave slave);
bool power_manager_master_find_system_level_check_result_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                                             bool equal, PMCheckResult check_result);
uint32_t power_manager_master_get_system_level_status_unit_num_rom(PMSlave slave,
                                                                   PMSystemLevel sys_lvl, PMUnitStatus status);
bool power_manager_master_get_system_level_wakeup_time_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                                           uint32_t *sys_lvl_wakeup_time);
void power_manager_master_check_update_result_rom(PMSlave slave, PMCheckResult check_result,
                                                  uint32_t wakeup_time_diff);
void power_manager_master_get_unit_pf_occupied_time_diff_rom(PMSlave slave, uint32_t check_clk,
                                                             uint32_t *unit_occupied_start_time_diff, uint32_t *unit_occupied_end_time_diff);
void power_manager_master_get_unit_occupied_time_diff_rom(PMSlave slave, uint32_t check_clk,
                                                          uint32_t *unit_occupied_time_diff);
bool power_manager_master_check_rom(PMSlave slave, uint32_t check_clk,
                                    uint32_t pre_sys_lvl_wakeup_time_diff);
void power_manager_master_store_enter_update_status_rom(PMSlave slave);
void power_manager_master_store_enter_rom(PMSlave slave);
void power_manager_master_exit_restore_update_status_rom(PMSlave slave);
void power_manager_master_exit_restore_rom(PMSlave slave);
void power_manager_master_inactivate_flow_rom(PMSlave slave);
void power_manager_master_activate_flow_rom(PMSlave slave, PMRTCComparator wakeup_comp,
                                            PMRTCComparator *activate_comp);
void power_manager_master_get_nearest_slave_wakeup_time_diff_rom(uint32_t *cur_clk,
                                                                 PMSlave *nearest_slave, uint32_t *nearest_slave_wakeup_time_diff);

PowerManagerUnit *power_manager_master_get_unit_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                                    PMUnitID unit_id);
PMUnitStatus power_manager_master_get_unit_status_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                                      PMUnitID unit_id);
void power_manager_master_initiate_wakeup_rom(PMSlave slave, PMSystemLevel sys_lvl,
                                              PMUnitID unit_id);
void power_manager_master_suspend_unit_rom(PMSlave slave, PMSystemLevel sys_lvl, PMUnitID unit_id);
void power_manager_master_resume_unit_rom(PMSlave slave, PMSystemLevel sys_lvl, PMUnitID unit_id);
void power_manager_master_set_timing_guarantee_sys_lvl_rom(PMSlave slave,
                                                           PMSystemLevel timing_guarantee_sys_lvl);
void power_manager_master_register_unit_rom(PMSlave slave, PMSystemLevel sys_lvl, PMUnitID unit_id);
void power_manager_master_reset_slave_rom(PMSlave slave);
void power_manager_master_init_rom(void);
void power_manager_master_profile_process_rom(PMSlave slave, ProfilingPMStage stage,
                                              bool is_processing);
void power_manager_master_idle_check_receive_request_rom(PMSlave slave);
void power_manager_master_idle_check_receive_continue_rom(PMSlave slave);
void power_manager_master_idle_check_send_response_rom(PMSlave slave);
void power_manager_master_check_send_request_rom(PMSlave slave, PMUnitID unit_id,
                                                 uint32_t check_clk, uint32_t pre_sys_lv_wakeup_time_diff);
void power_manager_master_check_receive_response_rom(PMSlave slave, PMUnitID unit_id,
                                                     PMCheckResult check_result, uint32_t wakeup_time_diff);
void power_manager_master_store_enter_send_request_rom(PMSlave slave, PMUnitID unit_id);
void power_manager_master_store_enter_receive_response_rom(PMSlave slave, PMUnitID unit_id);
void power_manager_master_exit_restore_send_request_rom(PMSlave slave, PMUnitID unit_id);
void power_manager_master_exit_restore_receive_response_rom(PMSlave slave, PMUnitID unit_id);
void power_manager_master_inact_msg_handler_rom(PMSlave slave,
                                                const PMS2MInactivateMessage *p_pm_s2m_inact_msg);
void power_manager_master_act_msg_handler_rom(PMSlave slave,
                                              const PMS2MActivateMessage *p_pm_s2m_act_msg);
void power_manager_master_inact_action_handler_rom(void);
void power_manager_master_act_action_handler_rom(void);
void power_manager_master_comp_handler_rom(void);
///* ============================== End of power manager master API ================================== */

///* ============================== Patch of power manager slave API ================================== */
bool power_manager_slave_check_rom(const PMM2SInactivateMessage *p_pm_m2s_inact_msg);
void power_manager_slave_store_and_enter_rom(const PMM2SInactivateMessage *p_pm_m2s_inact_msg);
void power_manager_slave_exit_and_restore_rom(const PMM2SActivateMessage *p_pm_m2s_act_msg);
void power_manager_slave_cpu_sleep_rom(bool enter_wfi);
bool power_manager_slave_check_interrupt_occur_rom(void);
void power_manager_slave_handle_irq_rom(bool enable_irq, bool *is_interrupt);
void power_manager_slave_init_rom(void);

uint32_t power_manager_slave_align_clk_rom(const uint32_t cur_clk, uint32_t *clk,
                                           uint32_t *time_diff, uint32_t size);
PMCheckResult power_manager_slave_align_wakeup_time_rom(PMCheckWakeupTimeFunc check_cb_func,
                                                        const uint32_t cur_clk, uint32_t *wakeup_time_diff);
void power_manager_slave_update_master_occupied_time_rom(const PMM2SInactivateMessage
                                                         *p_pm_m2s_inact_msg);
void power_manager_slave_set_occupied_time_descending_rom(const uint32_t cur_clk,
                                                          const PMOccupyTimeInfo *occupy_time_info, PMTimePeriod *time_period, uint8_t num_units);
bool power_manager_slave_check_occupied_time_rom(const PMTimePeriod *occuped_time_list,
                                                 const uint8_t occuped_time_list_size, uint32_t *pon_start_time_diff, uint32_t pon_duration,
                                                 uint32_t pof_duration);
void power_manager_slave_register_resource_rom(PMUnitID unit_id, uint32_t cur_clk,
                                               uint32_t occupy_start_time_diff, uint32_t duration);
void power_manager_slave_unregister_resource_rom(PMUnitID unit_id);
bool power_manager_slave_request_resource_rom(const uint32_t cur_clk,
                                              uint32_t *unit_wakeup_time_diff, PowerManagerSlaveRequestResource *unit_rqst);

bool power_manager_slave_inact_msg_handler_rom(const PMM2SInactivateMessage *p_pm_m2s_inact_msg,
                                               bool *p_is_interrupt);
void power_manager_slave_act_msg_handler_rom(const PMM2SActivateMessage *p_pm_m2s_act_msg);
void power_manager_slave_inact_action_handler_rom(void);
void power_manager_slave_act_action_handler_rom(void);
///* ============================== End of power manager slave API ================================== */

///* ============================== Patch of Power Manager Unit Platform API ================================== */
uint32_t platform_pm_get_extra_wait_cnt_rom(void);
void platfom_pm_callback_queue_in_rom(T_OS_QUEUE *p_callback_queue,
                                      PlatformPMCbFuncQueueElem *p_new_queue_elem, bool descending);
void platform_pm_register_callback_func_with_priority_rom(void *cb_func,
                                                          PlatformPMStage pf_pm_stage, int8_t priority);
void platform_pm_register_callback_func_rom(void *cb_func, PlatformPMStage pf_pm_stage);
PMCheckResult platform_pm_wakeup_time_rom(const uint32_t cur_clk,
                                          const uint32_t pre_sys_lv_wakeup_time_diff,
                                          uint32_t *unit_wakeup_time_diff);
PMCheckResult platform_pm_check_rom(const uint32_t cur_clk,
                                    const uint32_t pre_sys_lv_wakeup_time_diff,
                                    uint32_t *unit_wakeup_time_diff);
void platform_pm_store_rom(void);
void platform_pm_statistics_rom(void);
void platform_pm_restore_rom(void);
void platform_pm_hw_enter_flow_rom(void);
void platform_pm_enter_rom(void);
void platform_pm_hw_exit_flow_rom(void);
void platform_pm_exit_rom(void);
void platform_pm_pend_rom(void);
void platform_pm_init_rom(void);
///* ============================== End of Power Manager Unit Platform API ================================== */

///* ============================== Patch of os_pm API ================================== */
bool os_sched_restore_rom(void);
uint32_t os_sys_tick_rate_get_rom(void);
uint32_t os_sys_tick_clk_get_rom(void);
uint32_t os_pm_next_timeout_value_get_rom(void);
bool os_register_pm_excluded_handle_rom(void **handle, PlatformExcludedHandleType type);
bool os_unregister_pm_excluded_handle_rom(void **handle, PlatformExcludedHandleType type);
void os_pm_store_tickcount_rom(void);
void os_pm_restore_tickcount_rom(void);
PMCheckResult os_pm_check_rom(uint32_t *wakeup_time_diff);
void os_pm_store_rom(void);
void os_pm_restore_rom(void);
void os_pm_init_rom(void);
///* ============================== End of os_pm API ================================== */

uint32_t cal_quotient_remainder_rom(const uint64_t divisor_upper,
                                    const uint64_t divisor_lower,
                                    const uint32_t dividend, uint32_t *remainder);

/* ============================ Patch of PHY Common ==================================== */
void phy_init_script_execute_rom(const uint16_t *script_array, uint16_t length);
/* ============================================================================== */

/* ============================ Patch of PHY ==================================== */
void phy_hw_control_init_rom(bool dlps_flow);

void phy_auto_gated_on_rom(void);
void phy_auto_gated_off_rom(void);

void rck_init_rom(void);
void rxadck_rom(void);

#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void get_valid_txgain_flatk_rom(int8_t *txgain_flatk);
void txgain_flatk_post_processing_rom(int8_t *txgain_flatk);
void txgain_flatk_rom(void);
#endif

uint32_t get_rxgaink_value_rom(uint8_t *rxgaink_result);
void rxgaink_rom(void);

void get_iqk_lok_rom(uint16_t *lok, uint16_t *iqk_x, uint16_t *iqk_y);
void set_iqk_lok_rom(uint16_t lok, uint16_t iqk_x, uint16_t iqk_y);
void iqk_lok_init_rom(void);

void phy_init_rom(uint8_t dlps_flow);

void phy_store_platform_rom(void);
void phy_restore_mac_rom(void);
void phy_restore_platform_rom(void);

int8_t get_txgaink_value_rom(RF_MODE rf_mode);

void tx_power_track_offset_update_rom(void);
void tx_power_system_init_rom(void);

void thermal_timer_handler_rom(void *timer_handle);
void thermal_timer_init_rom(void);

#if (SUPPORT_LEGACY == 1)
uint8_t legacy_get_max_tx_step_index_rom(RF_MODE rf_mode);
uint8_t legacy_get_min_tx_step_index_rom(RF_MODE rf_mode);
uint8_t legacy_get_default_tx_step_index_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

int8_t legacy_get_tx_power_rom(uint8_t step_index, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
#endif
int8_t tx_power_apply_compensation_rom(int8_t tx_power, TXGAIN_TYPE txgain_type,
                                       RF_MODE rf_mode, bool inverse);
bool get_valid_txgain_index_from_tx_power_rom(int8_t tx_power_request, TXGAIN_TYPE txgain_type,
                                              RF_MODE rf_mode, bool dbm_resolution, uint8_t *actual_txgain_index, int8_t *actual_tx_power);
#if (SUPPORT_LEGACY == 1)
bool legacy_get_valid_tx_gain_from_step_index_rom(uint8_t step_index, TXGAIN_TYPE txgain_type,
                                                  RF_MODE rf_mode, uint8_t *actual_txgain_index, int8_t *actual_tx_power);
#endif

int8_t get_phy_rssi0_dbm_rom(RF_MODE rf_mode);
int8_t get_rssi_offset_rom(int8_t lna_idx, int8_t channel, RF_MODE rf_mode);
int8_t calculate_log_from_rssi_rom(uint16_t rssi_raw, uint8_t channel, RF_MODE rf_mode);

#if (SUPPORT_LEGACY == 1)
bool legacy_lbt_check_rom(uint8_t step_index, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
#endif
void update_lbt_threshold_rom(void);
/* ============================================================================== */

/* ============================ Patch of Modem ==================================== */
uint16_t modem_pi_read_rom(uint8_t modem_page, uint8_t addr);
void modem_pi_write_rom(uint8_t modem_page, uint8_t addr, uint16_t wdata);
void modem_pi_update_rom(uint8_t modem_page, uint8_t addr, uint16_t mask, uint16_t wdata);

void modem_hw_control_init_rom(bool dlps_flow);

void modem_init_rom(void);

void modem_set_rxadck_rom(uint16_t rxadck);
#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void modem_set_flatk_rom(int8_t *txgain_flatk);
#endif
#if (SUPPORT_IQM_MODE == 1)
void modem_set_rxgaink_iqm_mode(uint32_t rxgaink);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_set_rxgaink_tpm_mode(uint32_t rxgaink);
#endif
#if (SUPPORT_IQM_MODE == 1)
void modem_get_iqk_rom(uint16_t *iqk_x, uint16_t *iqk_y);
void modem_set_iqk_rom(uint16_t iqk_x, uint16_t iqk_y);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_tpmk_bank_assign_rom(uint16_t *tpmk_bank);
#endif

void modem_store_platform_rom(void);
void modem_restore_platform_rom(void);
void modem_restore_mac_rom(void);

void modem_set_lbt_threshold_rom(void);
void modem_lbt_init_rom(void);
#if (SUPPORT_IQM_MODE == 1)
void modem_set_lbt_txg_max_th_val_iqm_mode(uint8_t lbt_txg_max_th_val);
#endif
#if (SUPPORT_TPM_MODE == 1)
void modem_set_lbt_txg_max_th_val_tpm_mode(uint8_t lbt_txg_max_th_val);
#endif

uint8_t modem_psd_get_entry_num_rom(void);
RF_MODE modem_psd_get_rf_mode_rom(void);
void modem_psd_init_rom(MODEM_PSD_SCAN_MODE mode);
void modem_psd_set_report_address_rom(uint32_t addr);

void modem_mse_init_rom(void);

bool lbt_check_rom(int8_t tx_power, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

#if (MODEM_SRAM_DEBUG == 1)
void btrf_modem_sram_debug_set_size_rom(uint8_t size);
void btrf_modem_sram_debug_set_en_rom(bool enable);
void btrf_modem_sram_debug_set_rst_rom(bool reset);
void btrf_modem_sram_debug_set_mode_rom(uint8_t mode);
void btrf_modem_sram_debug_init_rom(MODEM_SRAM_DEBUG_MANAGER *modem_sram_debug_manager);
#endif

#if (SUPPORT_ZIGBEE == 1)
void modem_set_zb_cca_sfd_detect_en_rom(bool enable);
void modem_set_zb_cca_combination_rom(ZB_CCA_COMB comb);
void modem_set_zb_cca_energy_detect_threshold_rom(uint8_t thres, ZB_CCA_ED_RES_TYPE res);
void modem_set_zb_cca_carrier_sense_threshold_rom(uint8_t thres, uint8_t times, uint8_t cont_times);
#endif

#if (SUPPORT_PROPRIETARY == 1)
void modem_set_proprietary_en_rom(bool enable);
void modem_set_proprietary_base_rom(uint8_t base_index, uint32_t base);
uint32_t modem_get_proprietary_base_rom(uint8_t base_index);
void modem_set_proprietary_2_rx_match_mode_en_rom(bool enable);
#endif

/* ============================================================================== */

/* ============================ Patch of RFC ==================================== */
void mac_rfc_function_register_rom(MAC_RFC_FUNC_NAME func_name, void *func_ptr);

uint16_t rfc_reg_read_rom(uint8_t addr);
void rfc_reg_write_rom(uint8_t addr, uint16_t wdata);
void rfc_reg_update_rom(uint8_t addr, uint16_t mask, uint16_t wdata);

void rfc_hw_control_init_rom(bool dlps_flow);
void rfc_control_set_rom(bool enable);
bool rfc_control_get_rom(void);
bool rfc_control_wait_ready_us_rom(uint32_t wait_us);
bool rfc_control_wait_ready_rom(uint32_t wait_count);

uint8_t rfc_get_rck_rom(void);
void rfc_set_rck_rom(uint8_t rck);
#if ((SUPPORT_POLAR_TX == 1) || (SUPPORT_IQM_MODE == 1))
void rf_set_flatk_rom(int8_t *txgain_flatk);
#endif
#if (SUPPORT_IQM_MODE == 1)
void rfc_set_vco_tx_currentk_rom(uint8_t vco_tx_currentk);
void rfc_set_vco_rx_currentk_rom(uint8_t vco_rx_currentk);
uint16_t rfc_get_lok_rom(void);
void rfc_set_lok_rom(uint16_t lok);
#endif
void rfc_set_rxiqk_rom(uint8_t rxiqk);

void rfc_init_rom(void);

void rfc_store_platform_rom(void);
void rfc_restore_platform_rom(void);
void rfc_restore_mac_rom(void);

void execute_post_processing_rom(uint8_t *txgain, TXGAIN_TYPE txgain_type, RF_MODE rf_mode,
                                 bool inverse);
#if (SUPPORT_POLAR_TX == 1)
int8_t txgain_to_power_conversion_polar_tx_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_polar_tx_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif
#if (SUPPORT_IQM_MODE == 1)
int8_t txgain_to_power_conversion_iqm_mode_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_iqm_mode_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif
#if (SUPPORT_TPM_MODE == 1)
int8_t txgain_to_power_conversion_tpm_mode_rom(uint8_t txgain, TXGAIN_TYPE txgain_type);
uint8_t power_to_txgain_conversion_tpm_mode_rom(int8_t txpower, TXGAIN_TYPE txgain_type);
#endif

int8_t get_config_max_tx_power_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t get_tx_power_upperbound_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t get_tx_power_lowerbound_rom(TXGAIN_TYPE txgain_type, RF_MODE rf_mode);
int8_t tx_power_fit_pmax_rom(int8_t tx_power, TXGAIN_TYPE txgain_type, RF_MODE rf_mode);

void rfc_set_lut_syn_if_table_rom(uint16_t index, uint32_t value);
/* ============================================================================== */

/* ======================== Patch of Thermal ==================================== */
uint8_t get_thermal_meter_rom(void);
int16_t get_thermal_meter_celsius_rom(void);
int16_t get_thermal_meter_celsius_delta_rom(uint8_t thermal_minuend, uint8_t thermal_subtrahend);
void thermal_meter_trigger_rom(void);
void thermal_meter_read_rom(void);
void thermal_meter_update_rom(void);
void thermal_meter_init_rom(void);
bool thermal_tracking_register_callback_func_rom(void *);
void thermal_tracking_rom(void);
/* ============================================================================== */


// parse occd function pointers
bool get_cfg_entry_imp(void *hdr, int32_t *remain_size, void *entry);
bool apply_cfg_to_mem_imp(void *cfg_entry, uint8_t *mem, uint32_t size);
extern BOOL_PATCH_FUNC patch_parse_sys_cfg_to_mem;

/* ============================ Patch of debug port ============================= */
void debug_port_set_pin_bit_map_rom(T_PIN_GROUP pin_group, uint32_t dbg_bitmap);
void debug_port_open_rom(T_DEBUG_MODE debug_mode);

/* ======================== Patch of Ram Control ==================================== */
void mcu_ram_power_control_init_rom(PlatformPowerMode power_mode);
void ram_power_control_init_rom(PlatformPowerMode power_mode);
void other_ram_power_control_init_rom(PlatformPowerMode power_mode);

/* ======================== Patch of log and swd Control ==================================== */
void deinit_swd_pinmux_rom(void);
void log_uart_hw_deinit_rom(void);

/* ======================= Patch of Flash Driver ============================== */
FLASH_NOR_RET_TYPE flash_nor_cmd_rx_rom(FLASH_NOR_IDX_TYPE idx, SPIC_ACCESS_INFO *info,
                                        uint8_t *buf, uint8_t buf_len);
FLASH_NOR_RET_TYPE flash_nor_cmd_tx_rom(FLASH_NOR_IDX_TYPE idx, SPIC_ACCESS_INFO *info,
                                        uint8_t *buf,
                                        uint8_t buf_len);
FLASH_NOR_RET_TYPE flash_nor_get_status_wip_rom(FLASH_NOR_IDX_TYPE idx,
                                                bool *is_wip);
FLASH_NOR_RET_TYPE flash_nor_wait_busy_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_set_auto_mode_rom(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_BIT_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_load_query_info_rom(FLASH_NOR_IDX_TYPE idx);
void flash_nor_config_spic_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_dp_ctrl_rom(FLASH_NOR_IDX_TYPE idx, bool enable);
FLASH_NOR_RET_TYPE flash_nor_sw_reset_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_update_mxic_cmd_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_update_gd_cmd_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_update_zbit_cmd_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_update_puya_cmd_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_update_new_vendor_cmd_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_write_enable_rom(FLASH_NOR_IDX_TYPE idx,
                                              FLASH_NOR_WREN_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_get_regs_bits_rom(FLASH_NOR_IDX_TYPE idx, uint32_t *reg_bits,
                                               uint32_t reg_mask);
FLASH_NOR_RET_TYPE flash_nor_set_regs_bits_rom(FLASH_NOR_IDX_TYPE idx, uint32_t reg_bits,
                                               uint32_t reg_mask);
FLASH_NOR_RET_TYPE flash_nor_set_bit_mode_rom(FLASH_NOR_IDX_TYPE idx,
                                              FLASH_NOR_BIT_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_get_bit_mode_rom(FLASH_NOR_IDX_TYPE idx,
                                              FLASH_NOR_BIT_MODE *mode);
FLASH_NOR_RET_TYPE flash_nor_set_dum_byte_rom(FLASH_NOR_IDX_TYPE idx);
FLASH_NOR_RET_TYPE flash_nor_get_bp_lv_rom(FLASH_NOR_IDX_TYPE idx,
                                           uint8_t *bp_lv);
FLASH_NOR_RET_TYPE flash_nor_set_bp_lv_rom(FLASH_NOR_IDX_TYPE idx,
                                           uint8_t bp_lv);
FLASH_NOR_RET_TYPE flash_nor_read_rom(uint32_t addr, uint8_t *data,
                                      uint32_t byte_len);
FLASH_NOR_RET_TYPE flash_nor_write_rom(uint32_t addr, uint8_t *data,
                                       uint32_t byte_len);
FLASH_NOR_RET_TYPE flash_nor_erase_rom(uint32_t addr,
                                       FLASH_NOR_ERASE_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_unlock_bp_by_addr_rom(uint32_t addr,
                                                   uint8_t *bp_lv);
FLASH_NOR_RET_TYPE flash_nor_unlock_write_rom(uint32_t addr, uint8_t *data,
                                              uint32_t byte_len);
FLASH_NOR_RET_TYPE flash_nor_unlock_erase_rom(uint32_t addr,
                                              FLASH_NOR_ERASE_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_enter_lpm_rom(FLASH_NOR_IDX_TYPE idx,
                                           bool backup_spic);
FLASH_NOR_RET_TYPE flash_nor_exit_lpm_rom(FLASH_NOR_IDX_TYPE idx,
                                          bool restore_spic);
FLASH_NOR_RET_TYPE flash_nor_set_cal_addr_rom(FLASH_NOR_IDX_TYPE idx,
                                              uint32_t cal_addr);
FLASH_NOR_RET_TYPE flash_nor_set_physical_cyc_rom(FLASH_NOR_IDX_TYPE idx,
                                                  uint32_t cyc);
FLASH_NOR_RET_TYPE flash_nor_find_cyc_cnt_rom(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                              bool is_cal_rd_dummy_len, uint32_t cfg_max);
FLASH_NOR_RET_TYPE flash_nor_cal_dly_cyc_rom(FLASH_NOR_IDX_TYPE idx,
                                             uint32_t cal_addr);
FLASH_NOR_RET_TYPE flash_nor_cal_dummy_cyc_rom(FLASH_NOR_IDX_TYPE idx, uint32_t cal_addr,
                                               FLASH_NOR_BIT_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_calibration_rom(FLASH_NOR_IDX_TYPE idx, FLASH_NOR_BIT_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_try_high_speed_mode_rom(FLASH_NOR_IDX_TYPE idx,
                                                     FLASH_NOR_BIT_MODE bit_mode);
FLASH_NOR_RET_TYPE flash_nor_get_tb_bit_rom(FLASH_NOR_IDX_TYPE idx, bool *from_bottom);
FLASH_NOR_RET_TYPE flash_nor_set_tb_bit_rom(FLASH_NOR_IDX_TYPE idx, bool from_bottom);
bool flash_nor_lock_rom(FLASH_NOR_REQ_TYPE req);
void flash_nor_unlock_rom(FLASH_NOR_REQ_TYPE req);
FLASH_NOR_RET_TYPE flash_nor_erase_locked_rom(uint32_t addr, FLASH_NOR_ERASE_MODE mode);
FLASH_NOR_RET_TYPE flash_nor_write_locked_rom(uint32_t addr, uint8_t *data, uint32_t byte_len);
FLASH_NOR_RET_TYPE flash_nor_read_locked_rom(uint32_t addr, uint8_t *data, uint32_t byte_len);
void check_flash_bp_before_ota_copy_rom(void);
uint8_t flash_nor_get_default_bp_lv_rom(void);
FLASH_NOR_RET_TYPE flash_nor_unlock_bp_all_rom(uint8_t *pre_bp_lv);
FLASH_NOR_RET_TYPE flash_nor_unlock_bp_by_addr_locked_rom(uint32_t unlock_addr, uint8_t *old_bp_lv);
FLASH_NOR_RET_TYPE flash_nor_set_bp_lv_locked_rom(FLASH_NOR_IDX_TYPE idx, uint8_t bp_lv);
FLASH_NOR_RET_TYPE flash_nor_set_tb_bit_locked_rom(FLASH_NOR_IDX_TYPE idx, bool from_bottom);
FLASH_NOR_RET_TYPE flash_nor_get_bp_lv_locked_rom(FLASH_NOR_IDX_TYPE idx, uint8_t *bp_lv);
bool spic_lock_rom(SPIC_TypeDef *spic, uint8_t *lock_flag);
bool spic_unlock_rom(SPIC_TypeDef *spic, uint8_t *lock_flag);
bool spic_cmd_rx_rom(SPIC_TypeDef *spic, SPIC_ACCESS_INFO *info, uint8_t *buf, uint8_t buf_len);
bool spic_cmd_tx_rom(SPIC_TypeDef *spic, SPIC_ACCESS_INFO *info, uint8_t *buf, uint8_t buf_len);
FLASH_NOR_RET_TYPE flash_nor_auto_dma_read_locked_rom(FLASH_NOR_DMA_TYPE dma_type, FlashCB flash_cb,
                                                      uint32_t src_addr, uint32_t dst_addr, uint32_t data_len);
void flash_nor_dma_init_rom(FLASH_NOR_DMA_TYPE dma_type, uint32_t src_addr, uint32_t dst_addr,
                            uint32_t data_len);

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_PLATFORM_H_ */
