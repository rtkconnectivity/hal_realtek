/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef PCK600_SNAPSHOT_H
#define PCK600_SNAPSHOT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#if defined (CONFIG_SOC_SERIES_RTL87X3J)
#include "debug/src/device/rtl87x3j/pck600_snapshot_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X3K)
#include "debug/src/device/rtl87x3k/pck600_snapshot_def.h"
#elif defined (CONFIG_SOC_SERIES_RTL87X2J)
#include "debug/src/device/rtl87x2j/pck600_snapshot_def.h"
#endif

/**
 * @defgroup PCK600_SNAPSHOT PCK600 Snapshot
 * @brief PCK600 snapshot definitions.
 * @ingroup DIGITAL_DEBUG
 * @{
 */

typedef enum
{
    PCK600_SNAPSHOT_SUCCESS          = 0,    /**< Snapshot succeeded. */
    PCK600_SNAPSHOT_FAIL_KEEP_ACTIVE = 1,    /**< Snapshot failed; module kept active. */
    PCK600_SNAPSHOT_FAIL_RE_WAKEUP   = 2,    /**< Snapshot failed; re-wakeup required. */
    PCK600_SNAPSHOT_FAIL_MAX         = 3,    /**< Maximum snapshot failure status value. */
} PCK600_SNAPSHOT_STATUS_T;

/**
 * @brief  Get the status of all module when entering lpm.
 *
 * @return The status of all module.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     uint64_t mask = pck600_snapshot_get_device_mask();
 * }
 * @endcode
 */
uint64_t pck600_snapshot_get_device_mask(void);

/**
 * @brief  Get the status of the specified module when entering lpm.
 * @param[in] device Can be @ref PCK600_SNAPSHOT_DEVICE_T.
 *
 * @return The status of module @ref PCK600_SNAPSHOT_STATUS_T.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     pck600_snapshot_get_device_status(PCK600_SNAPSHOT_UART0);
 * }
 * @endcode
 */
PCK600_SNAPSHOT_STATUS_T pck600_snapshot_get_device_status(PCK600_SNAPSHOT_DEVICE_T device);

/**
 * @brief  Clear all the status of the qch.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void debug_port_sample(void)
 * {
 *     pck600_snapshot_clear_all_device_status();
 * }
 * @endcode
 */
void pck600_snapshot_clear_all_device_status(void);

/** @} */ /* End of group PCK600_SNAPSHOT */

#ifdef __cplusplus
}
#endif

#endif /* PCK600_SNAPSHOT_H */
