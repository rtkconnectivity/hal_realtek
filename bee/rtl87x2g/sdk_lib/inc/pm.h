/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __PM_H_
#define __PM_H_


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "clock.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @defgroup POWER_MANAGER Power Manager
  * @brief
  * @{
  */

/*============================================================================*
 *                              Types
*============================================================================*/
/** @defgroup POWER_MANAGER_Exported_Types Power Manager Exported Types
  * @{
  */
typedef enum POWER_CheckResult
{
    POWER_CHECK_PEND               = 0,
    POWER_CHECK_FAIL               = 1,
    POWER_CHECK_PASS               = 2,
} POWER_CheckResult;

typedef enum
{
    BTPOWER_DEEP_SLEEP        = 0,   /**< Deep sleep */
    BTPOWER_ACTIVE            = 1,   /**< Active     */
} BtPowerMode;


/** @brief POWER STAGE struct */
typedef enum
{
    POWER_STAGE_STORE           = 0,
    POWER_STAGE_RESTORE         = 1,
} POWERStage;

/** @brief LPSMode struct */
typedef enum
{
//    POWER_POWEROFF_MODE    = 0,
    POWER_POWERDOWN_MODE   = 1,   /**< Power down */
    POWER_DLPS_MODE        = 2,   /**< DLPS       */
    POWER_ACTIVE_MODE      = 3,    /**< Active     */
    POWER_MODE_MAX         = 4
} POWERMode;

typedef enum
{
    POWER_DLPS_PFM_MODE = 0,    /**< default one */
    POWER_DLPS_RET_MODE = 1,
} POWERDlpsMode;

typedef enum
{
    PM_WAKEUP_UNKNOWN              = 0x00000000,
    PM_WAKEUP_PRE_SYSTEM_LEVEL     = 0x00000001,
    PM_WAKEUP_PF_RTC               = 0x00000100,
    PM_WAKEUP_RTC                  = 0x00000200,
    PM_WAKEUP_MAC                  = 0x00000400,
    PM_WAKEUP_GPIO                 = 0x00000800,
    PM_WAKEUP_REASON_USB           = 0x00001000,
    PM_WAKEUP_REASON_LPCOMP        = 0x00002000,
    PM_WAKEUP_REASON_AON_QUAD_DEC  = 0x00004000,
    PM_WAKEUP_DEF_MAX              = 0xFFFFFFFF,
} PowerModeWakeupReason;

typedef enum
{
    PM_ERROR_UNKNOWN               = 0x0,
    PM_ERROR_POWER_MODE            = 0x1,
    PM_ERROR_DISABLE_DLPS_TIME     = 0x2,
    PM_ERROR_32K_CHECK_LOCK        = 0x3,
    PM_ERROR_LOG_DMA_NOT_IDLE      = 0x4,
    PM_ERROR_LOG_BUFFER_NOT_EMPTY  = 0x5,
    PM_ERROR_CALLBACK_CHECK        = 0x6,
    PM_ERROR_INTERRUPT_OCCURRED    = 0x7,
    PM_ERROR_WAKEUP_TIME           = 0x8,
    PM_ERROR_FREE_BLOCK_STORE      = 0x9,
} PowerModeErrorCode;

typedef enum
{
    PM_EXCLUDED_TIMER,
    PM_EXCLUDED_TASK,
    PM_EXCLUDED_TYPE_MAX,
} PowerModeExcludedHandleType;

typedef enum
{
    PM_SUCCESS                         = 0x0,
    PM_DVFS_BUSY                       = -0x1,
    PM_DVFS_VOLTAGE_FAIL               = -0x2,
    PM_DVFS_CONDITION_FAIL             = -0x4,
    PM_DVFS_SRAM_FAIL                  = -0x8,
    PM_DVFS_NOT_SUPPORT                = -0x10,
} PMErrorCode;

/** @brief This CB is used for any module which needs to be checked before entering DLPS */
typedef POWER_CheckResult(*POWERCheckFunc)();

/** @brief This CB is used for any module which needs to control the hw before entering or after exiting from DLPS */
typedef void (*POWERStageFunc)();

/** @} */ /* End of group POWER_MANAGER_Exported_Types */

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup POWER_MANAGER_Exported_Functions Power Manager Exported Functions
  * @{
  */

/**
 * @brief  Set BT Power mode
 * @param  mode BT Power mode
 * @return none
*/
void bt_power_mode_set(BtPowerMode mode);

/**
 * @brief  Get BT Power mode
 * @param  none
 * @return BT Power mode
*/
BtPowerMode bt_power_mode_get(void);

/**
 * @brief Register Check CB to Power module which will call it before entering Dlps.
 * @param  func  DLPSEnterCheckFunc.
 * @return  Status of Operation.
*/
int32_t power_check_cb_register(POWERCheckFunc func);


/**
 * @brief Register HW Control CB to Power module which will call it before entering power mode or after exiting from power mode (according to POWERStage) .
 * @param  func  POWERStageFunc.
 * @param  stage  tell the Power module the CB should be called when @ref POWER_STAGE_STORE or POWER_STAGE_RESTORE.
 * @return  Status of Operation.
*/
int32_t power_stage_cb_register(POWERStageFunc func, POWERStage stage);

/**
 * @brief  Set Platform power mode
 * @param  mode Platform power mode
 * @return  none
*/
int32_t power_mode_set(POWERMode mode);

/**
 * @brief  Get Platform power mode
 * @param  none
 * @return Platform power mode
*/
POWERMode power_mode_get(void);

/**
 * @brief  Set dlps mode
 * @param  mode  default value is DLPS_PFM.
 * @return status of operation
 * @note   switch dlps mode between DLPS_PFM and DLPF_RET
*/
int32_t power_dlps_mode_select(POWERDlpsMode mode);

/**
 * @brief  Get dlps mode
 * @param  none
 * @return current dlps mode
*/
POWERDlpsMode power_dlps_mode_get(void);

/**
 * @brief  Suspend system to prevent to enter low power mode
 * @param  none
 * @return  void
*/
int32_t power_mode_pause(void);

/**
 * @brief  Resume system to alow to enter low power mode
 * @param  none
 * @return  void
*/
int32_t power_mode_resume(void);

/**
 * @brief  Get callback func which prevent system to enter low power mode
 * @param  none
 * @return address of callback function which prevent system to enter low power mode
*/
uint32_t *power_get_refuse_reason();

/**
 * @brief  Get wakeup reason when low power mode is exited
 * @param  none
 * @return wakeup reason
*/
PowerModeWakeupReason power_get_wakeup_reason();

/**
 * @brief  Get error reason when low power mode is not allowed
 * @param  none
 * @return error reason which prevent system to enter low power mode
*/
PowerModeErrorCode power_get_error_code(void);

/**
 * @brief  stop all of the sw timers which will wakeup low power mode
 * @param  none
 * @return none
*/
void power_stop_all_non_excluded_timer(void);

/**
 * @brief  Exclude timer or task from low power wake list
 * @param  timer or task handle
 * @param  timer or task type
 * @return operation status
*/
bool power_register_excluded_handle(void **handle, PowerModeExcludedHandleType type);

/**
 * @brief  Cancel exclude timer or task from low power wake list
 * @param  timer or task handle
 * @param  timer or task type
 * @return operation status
*/
bool power_unregister_excluded_handle(void **handle, PowerModeExcludedHandleType type);

/**
 * @brief  Get debug information of dlps mode
 * @param  wakeup_count:  total counts of entering and exiting dlps
 * @param  last_wakeup_clk: last wakeup clock, unit: 31.25us
 * @param  last_sleep_clk: last sleep clock, unit: 31.25us
 * @return none
*/
void power_get_statistics(uint32_t *wakeup_count, uint32_t *last_wakeup_clk,
                          uint32_t *last_sleep_clk);

/** End of POWER_MANAGER_Exported_Functions
  * @}
  */

/** End of POWER_MANAGER
  * @}
  */

/**
 * @brief  shut down spic pin before entering dlps
 * @param  enable whether to shut down spic pin
 * @return none
*/
void shutdown_spic_pin(bool enable);

POWER_CheckResult power_clock_check_cb(void);

void usb_set_pon_domain(void);

#ifdef __cplusplus
}
#endif

#endif
