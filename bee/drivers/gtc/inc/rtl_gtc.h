/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef RTL_GTC_H
#define RTL_GTC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "utils/rtl_utils.h"
#include "utils.h"

/**
 * @defgroup GTC_DRIVER Driver
 * @brief GTC driver module.
 * @ingroup GTC
 * @{
 */


/**
 * @brief     Get the counter value of GTC.
 *
 *
 * @return The counter value.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gtc_demo(void)
 * {
 *     uint32_t counter = GTC_GetCounter();
 * }
 * @endcode
 */
uint32_t GTC_GetCounter(void);

/**
 * @brief     Convert GTC counter value to microseconds.
 *
 * @param[in] Counter The counter value to convert.
 * @param[in] round_type The rounding type for conversion @ref RoundType.
 *
 * @return The counter value converted to microseconds.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gtc_demo(void)
 * {
 *     uint32_t counter = GTC_GetCounter();
 *     uint32_t time_us = GTC_CounterToUs(counter, ROUND_UP);
 * }
 * @endcode
 */
uint32_t GTC_CounterToUs(uint32_t Counter, RoundType round_type);

/**
 * @brief     Convert microseconds to GTC counter value.
 *
 * @param[in] TimeUs The time in microseconds to convert.
 * @param[in] round_type The rounding type for conversion @ref RoundType.
 *
 * @return The time value converted to counter units.
 *
 * <b>Example usage</b>
 * @code{.c}
 *
 * void gtc_demo(void)
 * {
 *     uint32_t time_us = 1000;
 *     uint32_t counter = GTC_UsToCounter(time_us, ROUND_UP);
 * }
 * @endcode
 */
uint32_t GTC_UsToCounter(uint32_t TimeUs, RoundType round_type);

/** @} */ /* End of group GTC_DRIVER */

#ifdef __cplusplus
}
#endif

#endif /* RTL_GTC_H */
