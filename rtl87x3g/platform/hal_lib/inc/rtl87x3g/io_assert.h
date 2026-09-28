/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __IO_ASSERT_H__
#define __IO_ASSERT_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "rtl876x.h"

/** @defgroup HAL_87x3g_IO_Assert IO Assert
 * @brief IO assert.
 * @{
 */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_IO_Assert_Exported_Functions IO Assert Exported Functions
 * @{
 */

/**
 *
 * \brief  IO parameter check fail.
 *
 * \param[in]  file: __FILE__.
 * \param[in]  line: __LINE__.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void io_assert_demo(void)
 * {
 *     io_assert_failed((uint8_t *)__FILE__, __LINE__);
 * }
 * \endcode
 */
void io_assert_failed(uint8_t *file, uint32_t line);

/**
 *
 * \brief  IO parameter check report.
 *
 * \param[in]  file: __FILE__.
 * \param[in]  line: __LINE__.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void io_assert_demo(void)
 * {
 *     io_assert_report((uint8_t *)__FILE__, __LINE__);
 * }
 * \endcode
 */
void io_assert_report(uint8_t *file, uint32_t line);

#ifdef __cplusplus
}
#endif

#endif /*__IO_ASSERT_H__*/

/** @} */ /* End of group 87x3g_IO_Assert_Exported_Functions */
/** End of group HAL_87x3g_IO_Assert
  * @}
  */
