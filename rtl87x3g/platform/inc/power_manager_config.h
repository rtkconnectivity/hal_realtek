#ifndef __POWER_MANAGER_CONFIG_H
#define __POWER_MANAGER_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @def UNIT_LIST
 * @brief List of all units and their corresponding system levels.
 *
 * This list defines each unit in the power manager and assigns a system level to each.
 * The format is: UNIT(UNIT_NAME, SYSTEM_LEVEL)
 *
 * Example:
 * @code
 * UNIT(PM_UNIT_PLATFORM, 2)
 * UNIT(PM_UNIT_BTMAC, 1)
 * UNIT(PM_UNIT_PROPRIETARY, 0)
 * UNIT(PM_UNIT_ZIGBEE, 0)
 * @endcode
 *
 * @note The unit PM_UNIT_PLATFORM must be present and should have the highest system level.
 *       Adjust the system levels according to the project's requirements.
 */
#define UNIT_LIST \
    UNIT(PM_UNIT_PLATFORM, 2)       \
    UNIT(PM_UNIT_BTMAC, 1)          \
    UNIT(PM_UNIT_PROPRIETARY, 0)    \
    UNIT(PM_UNIT_ZIGBEE, 0)

/**
 * @def PM_UNIT_NUM_LIMIT
 * @brief Defines the maximum number of units that can be handled.
 *
 * This limit is usually dictated by the number of hardware channels available for the power manager,
 * such as Platform RTC or Schedule Plan.
 *
 * @note Adjust this value based on the capabilities of your hardware.
 */
#define PM_UNIT_NUM_LIMIT     4  // Adjust according to the number of HW driver channels, e.g., Platform RTC or Schedule Plan

/**
 * @def PM_SUPPORT_ADJUST_GUARANTEE_SYS_LEVEL
 * @brief Enable or disable support for adjusting restore interrupt type (NMI or interrupt).
 *
 * This feature requires hardware support to be effective. Setting this to 1 enables the feature,
 * while 0 disables it.
 *
 * @note Ensure that your hardware supports this feature before enabling it.
 */
#define PM_SUPPORT_ADJUST_GUARANTEE_SYS_LEVEL   1

/* for naming compatibility */
#define PM_SLAVE_BTMAC                  PM_SLAVE_0
#define PM_SLAVE_ZIGBEE                 PM_SLAVE_0
#define PM_SLAVE_PROPRIETARY            PM_SLAVE_0

#ifdef __cplusplus
}
#endif

#endif