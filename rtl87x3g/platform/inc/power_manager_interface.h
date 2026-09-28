/**
*********************************************************************************************************
*               Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file         power_manager_interface.h
* @brief        Power Manager Interface implementation head file.
* @details
* @author       Kellan Ho
* @date         2021-11-16
* @version      v0.1
*********************************************************************************************************
*/

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __POWER_MANAGER_INTERFACE_H
#define __POWER_MANAGER_INTERFACE_H


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "power_manager_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define PM_INVALID_WAKEUP_TIME_DIFF 0xffffffff

typedef enum PMSlave
{
    PM_SLAVE_0                  = 0,
    PM_SLAVE_DEF_MAX,
} PMSlave;

/** @defgroup POWER_MANAGER_Exported_Types Power Manager Exported Types
  * @{
  */
// Macro to generate a unit enum value
#define GENERATE_UNIT_ENUM(name, level, index) \
    name = ((((level) & 0x07) << 4) | ((index) & 0x0F)),

// Track the starting point of unit ID generation
enum { PM_UNIT_ID_COUNTER_START = __COUNTER__ };

/**
 * @enum PMUnitID
 * @brief Enumeration of power manager unit IDs.
 *        Values are generated using a macro to ensure consistency and uniqueness.
 */
typedef enum
{
    PM_UNIT_HEADER_ID        = 0x80,
#define UNIT(name, level) GENERATE_UNIT_ENUM(name, level, __COUNTER__ - PM_UNIT_ID_COUNTER_START - 1)
    UNIT_LIST  /**< Macro to expand the list of units */
#undef UNIT
    PM_UNIT_MAX_NUM = __COUNTER__ - PM_UNIT_ID_COUNTER_START - 1, /**< Maximum number of power manager units. */
} PMUnitID;

#if ((PM_UNIT_MAX_NUM >= PM_UNIT_NUM_LIMIT) || (PM_UNIT_MAX_NUM >= 0x0F))
#error "exceed maximum unit num!"
#endif

typedef enum PMRTCComparator
{
    PM_SLAVE_INVALID_COMP   = 0x0000,
    PM_SLAVE_0_GROUP = (0x1 << (PM_UNIT_NUM_LIMIT)) - 1,
    PM_SLAVE_0_COMP_DEF_MAX = 0xFFFF,
} PMRTCComparator;

// Macro to generate a system level enum value
#define GENERATE_SYSTEM_LEVEL_ENUM(name, level) \
    name##_SYS_LEVEL = (level),
/**
 * @enum PMSystemLevel
 * @brief Enumeration of power manager system levels.
 */
typedef enum
{
#define UNIT(name, level) GENERATE_SYSTEM_LEVEL_ENUM(name, level)
    UNIT_LIST  /**< Macro to expand the list of system levels */
#undef UNIT
    PM_SYSTEM_LEVEL_PF = PM_UNIT_PLATFORM_SYS_LEVEL,
    PM_SYSTEM_LEVEL_DEF_MAX,
} PMSystemLevel;

/**
 * @def PM_GET_SYS_LVL(unit_id)
 * @brief Macro to get the system level from a unit ID.
 *        Extracts the system level by shifting and masking the unit ID.
 * @param unit_id The unit ID to extract the system level from.
 * @returns The system level of the given unit ID.
 */
#define PM_GET_SYS_LVL(unit_id) (((unit_id) >> 4) & 0x07)
#define PM_GET_UNIT_INDEX(unit_id) ((unit_id) & 0xF)

typedef enum PMUnitStatus
{
    PM_UNIT_UNKNOWN             = 0,
    PM_UNIT_PEND                = 1,
    PM_UNIT_INACTIVE            = 2,
    PM_UNIT_ACTIVE              = 3,
} PMUnitStatus;

typedef enum PMCheckResult
{
    PM_CHECK_FAIL               = 0,
    PM_CHECK_PASS               = 1,
    PM_CHECK_PEND               = 2,
} PMCheckResult;

typedef enum PMAciton
{
    PM_ACTION_IDLE_CHECK_REQUEST,
    PM_ACTION_IDLE_CHECK_CONTINUE,
    PM_ACTION_IDLE_CHECK_RESPONSE,
    PM_ACTION_CHECK_REQUEST,
    PM_ACTION_CHECK_RESPONSE,
    PM_ACTION_STORE_ENTER_REQUEST,
    PM_ACTION_STORE_ENTER_RESPONSE,
    PM_ACTION_EXIT_RESTORE_REQUEST,
    PM_ACTION_EXIT_RESTORE_RESPONSE,
    PM_ACTION_DEF_MAX,
} PMAciton;

extern void (*power_manager_master_initiate_wakeup)(PMSlave slave, PMSystemLevel sys_lvl,
                                                    PMUnitID unit_id);
extern void (*power_manager_master_suspend_unit)(PMSlave slave, PMSystemLevel sys_lvl,
                                                 PMUnitID unit_id);
extern void (*power_manager_master_resume_unit)(PMSlave slave, PMSystemLevel sys_lvl,
                                                PMUnitID unit_id);
#if (PM_SUPPORT_ADJUST_GUARANTEE_SYS_LEVEL == 1)
extern void (*power_manager_master_set_timing_guarantee_sys_lvl)(PMSlave slave,
                                                                 PMSystemLevel timing_guarantee_sys_lvl);
#endif
extern void (*power_manager_master_register_unit)(PMSlave slave, PMSystemLevel sys_lvl,
                                                  PMUnitID unit_id);
extern void (*power_manager_master_reset_slave)(PMSlave slave);

void power_manager_interface_init_unit_status(void);
PMUnitStatus power_manager_interface_get_unit_status(PMSlave slave, PMUnitID unit_id);
void power_manager_interface_set_unit_status(PMSlave slave, PMUnitID unit_id, PMUnitStatus status);
bool power_manager_interface_check_unit_active(PMSlave slave, PMUnitID unit_id);
bool power_manager_interface_check_unit_active_from_isr(PMSlave slave, PMUnitID unit_id);

#ifdef __cplusplus
}
#endif

#endif  /* __POWER_MANAGER_INTERFACE_H */
