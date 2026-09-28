/**
*********************************************************************************************************
*               Copyright(c) 2020, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file         dvfs.h
* @brief        Dynamic Voltage Frequency Scaling Fucntcions implementation Header File.
* @details
* @author       Kellan Ho
* @date         2020-09-18
* @version      v0.1
*********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __DVFS_H
#define __DVFS_H


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "os_queue.h"
#include "pmu_manager.h"
#include "clock_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                              Types
*============================================================================*/
/** @defgroup POWER_MANAGER_Exported_Types Power Manager Exported Types
  * @{
  */

#define DVFS_VDD_TYPE_NUM           1
#define DVFS_NORMAL_VDD_MODE_NUM    2

typedef enum
{
    DVFS_NORMAL_VDD                 = 0,
} DVFSVDDType;

typedef enum
{
    DVFS_VDD_1V1                    = 0,
    DVFS_VDD_1V0                    = 1,
} DVFSVDDMode;

typedef enum
{
    DVFS_CONTROL_MCU                = 0,
    DVFS_CONTROL_DSP                = 1,
    DVFS_CONTROL_FW_MAX             = 2,
    DVFS_CONTROL_HW_AUTO            = 2,
} DVFSControlType;

typedef enum
{
    DVFS_SUSPEND_SRAM               = 0x0,
    DVFS_RESUME_SRAM                = 0x1,
} DVFSControlSRAM;

typedef enum
{
    DVFS_STATE_IDLE                 = 0,
    DVFS_STATE_BUSY                 = 1,
} DVFSState;

typedef enum
{
    DVFS_SUCCESS                    = 0x0,
    DVFS_BUSY                       = 0x1,
    DVFS_VOLTAGE_FAIL               = 0x2,
    DVFS_CONDITION_FAIL             = 0x4,
    DVFS_SRAM_FAIL                  = 0x8,
    DVFS_NOT_SUPPORT                = 0x10,
} DVFSErrorCode;

typedef enum
{
    PROFILING_DVFS_CHECK_CONDITION  = 0,
    PROFILING_DVFS_CHANGE_VOLTAGE   = 1,
    PROFILING_DVFS_CHANGE_PARAMETER = 2,
    PROFILING_DVFS_STAGE_MAX        = 3
} ProfilingDVFSStage;

typedef bool (*DVFSCheckFunc)(void);
typedef bool (*DVFSVoltageFunc)(DVFSVDDMode);

typedef struct _DVFSCheckFuncQueueElem
{
    struct DVFSCheckFuncQueueElem *pNext;
    void *check_func;
} DVFSCheckFuncQueueElem;

typedef union _DVFSSNPSROMPara
{
    uint16_t d16;
    struct
    {
        uint16_t rm: 4;
        uint16_t rme: 1;
        uint16_t test_1: 1;
        uint16_t rsvd: 10;
    };
} DVFSSNPSROMPara;

typedef union _DVFSSNPSSRAMPara
{
    uint16_t d16;
    struct
    {
        uint16_t rm: 4;
        uint16_t rme: 1;
        uint16_t ra: 2;
        uint16_t wa: 3;
        uint16_t wpulse: 3;
        uint16_t test_1: 1;
        uint16_t rsvd: 2;
    };
} DVFSSNPSSRAMPara;

typedef union _DVFSRTKSRAMPara
{
    uint16_t d16;
    struct
    {
        uint16_t rm: 4;
        uint16_t saw: 2;
        uint16_t wa: 3;
        uint16_t wm: 4;
        uint16_t wae: 1;
        uint16_t rsvd: 2;
    };
} DVFSRTKSRAMPara;

typedef struct _DVFSNormalVDDPara
{
    SWR_CORE_TUNE_TYPE swr_core_tune_type;
    LDO_DIG_TUNE_TYPE ldo_dig_tune_type;
    CLK_FREQ_TYPE clock_freq_limit[DVFS_LIMIT_CLK_MAX];

    DVFSSNPSROMPara snps_rom;
    DVFSSNPSSRAMPara snps_sram;
    DVFSRTKSRAMPara rtk_sram_small;
    DVFSRTKSRAMPara rtk_sram_large;
} DVFSNormalVDDPara;

typedef struct _ProfilingDVFSData
{
    uint32_t stage_start;
    uint32_t stage_end;
    uint32_t stage_time[PROFILING_DVFS_STAGE_MAX];
} ProfilingDVFSData;

typedef struct _DVFSSystem
{
    DVFSState state;

    DVFSVoltageFunc voltage_func[DVFS_VDD_TYPE_NUM];

    DVFSNormalVDDPara normal_vdd[DVFS_NORMAL_VDD_MODE_NUM];

    T_OS_QUEUE check_func_queue;

    ProfilingDVFSData *profiling_data;
} DVFSSystem;

typedef union
{
    uint8_t value;
    struct
    {
        uint8_t enable: 1;
        uint8_t profiling_mode: 1;
        uint8_t dsp_vsel_opt: 1;
        uint8_t rsvd: 5;
    };
} DVFSFeatureConfig;

/*============================================================================*
 *                              Variables
*============================================================================*/
/** @defgroup POWER_MANAGER_Exported_Variables Power Manager Exported Variables
  * @{
  */

extern DVFSFeatureConfig dvfs_feature_cfg;
extern DVFSSystem dvfs_manager_system;

extern bool (*dvfs_check_condition)(DVFSVDDType, DVFSVDDMode);
extern bool (*dvfs_change_voltage)(DVFSVDDType, DVFSVDDMode);
extern void (*dvfs_pre_set_vsel_rom_sram_para)(void);
extern void (*dvfs_set_non_vsel_rom_sram_para)(DVFSVDDType, DVFSVDDMode, DVFSControlType);
extern void (*dvfs_set_vsel_rom_sram_para)(DVFSVDDType, DVFSVDDMode, DVFSControlType);
extern void (*dvfs_set_rf_control)(bool);
extern bool (*dvfs_wait_rf_control_ready)(uint32_t);
extern bool (*dvfs_control_sram_access)(DVFSVDDType, DVFSControlType, DVFSControlSRAM);
extern bool (*dvfs_change_rom_sram_paras)(DVFSVDDType, DVFSVDDMode);

extern DVFSVDDMode(*dvfs_get_mode)(DVFSVDDType);
extern DVFSErrorCode(*dvfs_set_mode)(DVFSVDDType, DVFSVDDMode);

extern void (*dvfs_init)(void);

extern bool (*dvfs_voltage_func_normal_vdd)(DVFSVDDMode);

/** @} */ /* End of group POWER_MANAGER_Exported_Variables */

/*============================================================================*
 *                              Functions
*============================================================================*/

/** @defgroup POWER_MANAGER_Exported_Functions Power Manager Exported Functions
  * @{
  */

void dvfs_register_check_func(void *);
void dvfs_register_voltage_func(DVFSVDDType, DVFSVoltageFunc);

CLK_FREQ_TYPE dvfs_get_clock_freq_limit(DVFSVDDMode vdd_mode, ACTIVE_CLK_TYPE active_clk_type);
LDO_DIG_TUNE_TYPE dvfs_get_ldo_dig_tune_type(DVFSVDDMode);
SWR_CORE_TUNE_TYPE dvfs_get_swr_core_tune_type(DVFSVDDMode);

/** @} */ /* End of group POWER_MANAGER_Exported_Functions */

/** @} */ /* End of group POWER_MANAGER */


#ifdef __cplusplus
}
#endif

#endif  /* __POWER_MANAGER_H */
