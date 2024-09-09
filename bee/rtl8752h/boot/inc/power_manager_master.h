/**
*********************************************************************************************************
*               Copyright(c) 2022, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file         power_manager_master.h
* @brief        Power Manager Master implementation head file.
* @details
* @author       Kellan Ho, js.lin
* @date         2022-08-29
* @version      v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __POWER_MANAGER_MASTER_H
#define __POWER_MANAGER_MASTER_H


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "stdint.h"
#include "stdbool.h"
#include "power_manager_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PM_GET_GROUP_COMP_TYPE(slave, comp_bitmap)  (comp_bitmap & slave##_GROUP)

typedef enum PMRTCComparator
{
    PM_SLAVE_INVALID_COMP   = 0x0000,
    PM_SLAVE_0_COMP0        = 0x0001,
    PM_SLAVE_0_COMP1        = 0x0002,
    PM_SLAVE_0_COMP2        = 0x0004,
    PM_SLAVE_0_COMP3        = 0x0008,
    PM_SLAVE_0_GROUP        = 0x000F,
    PM_SLAVE_0_COMP_DEF_MAX = 0xFFFF,
} PMRTCComparator;

typedef enum ProfilingPMStage
{
    PROFILING_PM_CHECK,
    PROFILING_PM_STORE_ENTER,
    PROFILING_PM_EXIT_RESTORE,
    PROFILING_PM_STAGE_MAX,
} ProfilingPMStage;

typedef struct ProfilingPMData
{
    uint32_t stage_start;
    uint32_t stage_end;
    uint32_t stage_time[PROFILING_PM_STAGE_MAX];
    uint32_t stage_time_max[PROFILING_PM_STAGE_MAX];
    uint32_t stage_time_min[PROFILING_PM_STAGE_MAX];
} ProfilingPMData;

typedef struct PowerManagerUnit
{
    struct PowerManagerUnit *prev;
    struct PowerManagerUnit *next;

    PMUnitID unit_id;
    PMRTCComparator comp;
    bool pendable;

    volatile PMUnitStatus status;
    volatile PMCheckResult check_result;

    uint32_t check_clk;
    uint32_t wakeup_time_diff;

    uint32_t suspended;

    ProfilingPMData *profiling_data;
} PowerManagerUnit;

typedef struct PowerManagerUnitList
{
    PowerManagerUnit header;
} PowerManagerUnitList;

typedef struct PowerManagerMasterSystem
{
    PowerManagerUnitList unit_list[PM_SYSTEM_LEVEL_DEF_MAX];
    PMSystemLevel cur_sys_lvl;
    PMSystemLevel timing_guarantee_sys_lvl;

    PowerManagerUnit *inactivate_candidate[PM_SYSTEM_LEVEL_DEF_MAX];
    PMSystemLevel inactivate_candidate_sys_lvl;

    PowerManagerUnit *activate_candidate[PM_SYSTEM_LEVEL_DEF_MAX];
    PMSystemLevel activate_candidate_sys_lvl;

    uint32_t unit_num;
} PowerManagerMasterSystem;

typedef union PowerManagerMasterFeatureConfig
{
    uint8_t value[1];
    struct
    {
        uint8_t profiling_mode:                     1;
        uint8_t m2s_inact_msg_dbg:                  1;
        uint8_t s2m_inact_msg_dbg:                  1;
        uint8_t m2s_act_msg_dbg:                    1;
        uint8_t s2m_act_msg_dbg:                    1;
        uint8_t pf_rtc_dbg:                         1;
        uint8_t rsvd:                               2;
    };
} PowerManagerMasterFeatureConfig;

extern void (*power_manager_master_wait_m2s_act_msg_ready)(PMSlave slave);
extern void (*power_manager_master_send_m2s_act_msg)(PMSlave slave,
                                                     PMM2SActivateMessage *p_pm_m2s_act_msg);
extern void (*power_manager_master_wait_m2s_inact_msg_ready)(PMSlave slave);
extern void (*power_manager_master_send_m2s_inact_msg)(PMSlave slave,
                                                       PMM2SInactivateMessage *p_pm_m2s_inact_msg);
extern void (*power_manager_master_receive_s2m_inact_msg)(PMSlave slave,
                                                          PMS2MInactivateMessage *p_pm_s2m_inact_msg);
extern void (*power_manager_master_receive_s2m_act_msg)(PMSlave slave,
                                                        PMS2MActivateMessage *p_pm_s2m_act_msg);

extern PMSlave(*power_manager_master_get_another_slave)(PMSlave slave);
extern PowerManagerUnit *(*power_manager_master_get_system_level_header_unit)(PMSlave slave,
                                                                              PMSystemLevel sys_lvl);

extern void (*power_manager_master_init_inactivate_candidate)(PMSlave slave);
extern bool (*power_manager_master_find_inactivate_candidate)(PMSlave slave, PMSystemLevel sys_lvl);
extern PowerManagerUnit *(*power_manager_master_get_inactivate_candidate)(PMSlave slave);
extern PMSystemLevel(*power_manager_master_get_inactivate_candidate_system_level)(PMSlave slave);
extern bool (*power_manager_master_is_inactivate_candidate)(PMSlave slave, PMUnitID unit_id);
extern bool (*power_manager_master_is_inactivate_candidate_syste_level_end)(PMSlave slave);

extern void (*power_manager_master_init_activate_candidate)(PMSlave slave);
extern bool (*power_manager_master_find_activate_candidate)(PMSlave slave, PMSystemLevel sys_lvl,
                                                            PMRTCComparator wakeup_comp, PMRTCComparator *activate_comp);
extern PowerManagerUnit *(*power_manager_master_get_activate_candidate)(PMSlave slave);
extern PMSystemLevel(*power_manager_master_get_activate_candidate_system_level)(PMSlave slave);
extern bool (*power_manager_master_is_activate_candidate)(PMSlave slave, PMUnitID unit_id);
extern void (*power_manager_master_set_activate_flow_idle)(PMSlave slave, bool enable);
extern bool (*power_manager_master_get_activate_flow_idle)(PMSlave slave);
extern bool (*power_manager_master_check_activate_valid)(PMSlave slave, PMSystemLevel sys_lvl);

extern bool (*power_manager_master_is_slave_idle)(PMSlave slave);

extern bool (*power_manager_master_find_system_level_check_result)(PMSlave slave,
                                                                   PMSystemLevel sys_lvl, bool equal, PMCheckResult check_result);
extern uint32_t (*power_manager_master_get_system_level_status_unit_num)(PMSlave slave,
                                                                         PMSystemLevel sys_lvl, PMUnitStatus status);
extern bool (*power_manager_master_get_system_level_wakeup_time)(PMSlave slave,
                                                                 PMSystemLevel sys_lvl, uint32_t *sys_lvl_wakeup_time);
extern void (*power_manager_master_check_update_result)(PMSlave slave, PMCheckResult check_result,
                                                        uint32_t wakeup_time_diff);
extern void (*power_manager_master_get_unit_pf_occupied_time_diff)(PMSlave slave,
                                                                   uint32_t check_clk, uint32_t *unit_occupied_start_time_diff, uint32_t *unit_occupied_end_time_diff);
extern void (*power_manager_master_get_unit_occupied_time_diff)(PMSlave slave, uint32_t check_clk,
                                                                uint32_t *unit_occupied_time_diff);

extern bool (*power_manager_master_check)(PMSlave slave, uint32_t check_clk,
                                          uint32_t pre_sys_lvl_wakeup_time_diff);
extern void (*power_manager_master_store_enter_update_status)(PMSlave slave);
extern void (*power_manager_master_store_enter)(PMSlave slave);
extern void (*power_manager_master_exit_restore_update_status)(PMSlave slave);
extern void (*power_manager_master_exit_restore)(PMSlave slave);

extern void (*power_manager_master_inactivate_flow)(PMSlave slave);
extern void (*power_manager_master_activate_flow)(PMSlave slave, PMRTCComparator wakeup_comp,
                                                  PMRTCComparator *activate_comp);

extern void (*power_manager_master_get_nearest_slave_wakeup_time_diff)(uint32_t *cur_clk,
                                                                       PMSlave *nearest_slave, uint32_t *nearest_slave_wakeup_time_diff);
extern PowerManagerUnit *(*power_manager_master_get_unit)(PMSlave slave, PMSystemLevel sys_lvl,
                                                          PMUnitID unit_id);
extern PMUnitStatus(*power_manager_master_get_unit_status)(PMSlave slave, PMSystemLevel sys_lvl,
                                                           PMUnitID unit_id);

extern void (*power_manager_master_init)(void);

extern void (*power_manager_master_profile_process)(PMSlave slave, ProfilingPMStage stage,
                                                    bool is_processing);

extern void (*power_manager_master_idle_check_receive_request)(PMSlave slave);
extern void (*power_manager_master_idle_check_receive_continue)(PMSlave slave);
extern void (*power_manager_master_idle_check_send_response)(PMSlave slave);
extern void (*power_manager_master_check_send_request)(PMSlave slave, PMUnitID unit_id,
                                                       uint32_t check_clk, uint32_t pre_sys_lv_wakeup_time_diff);
extern void (*power_manager_master_check_receive_response)(PMSlave slave, PMUnitID unit_id,
                                                           PMCheckResult check_result, uint32_t wakeup_time_diff);
extern void (*power_manager_master_store_enter_send_request)(PMSlave slave, PMUnitID unit_id);
extern void (*power_manager_master_store_enter_receive_response)(PMSlave slave, PMUnitID unit_id);
extern void (*power_manager_master_exit_restore_send_request)(PMSlave slave, PMUnitID unit_id);
extern void (*power_manager_master_exit_restore_receive_response)(PMSlave slave, PMUnitID unit_id);

extern void (*power_manager_master_inact_msg_handler)(PMSlave slave,
                                                      const PMS2MInactivateMessage *p_pm_s2m_inact_msg);
extern void (*power_manager_master_act_msg_handler)(PMSlave slave,
                                                    const PMS2MActivateMessage *p_pm_s2m_act_msg);

extern void (*power_manager_master_inact_action_handler)(void);
extern void (*power_manager_master_act_action_handler)(void);

extern void (*power_manager_master_comp_handler)(void);

void NMI_Handler(void);
void PF_RTC_Handler(void);

#ifdef __cplusplus
}
#endif

#endif  /* __POWER_MANAGER_MASTER_H */
