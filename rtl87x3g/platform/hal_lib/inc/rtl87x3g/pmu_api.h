/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __PMU_API_H_
#define __PMU_API_H_


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup 87x3g_PMU PMU
  * @brief PMU driver module.
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup 87x3g_PMU_Exported_Types PMU Exported Types
  * @{
  */

/**
  * @brief  PMU module.
  */
typedef enum _X3G_PMU_MODULE
{
    PMU_CODEC   = 0x01,     //!< PMU codec.
    PMU_USB     = 0x02,     //!< PMU USB.
} PMU_MODULE;

/** End of Group 87x3g_PMU_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup 87x3g_PMU_Exported_Functions PMU Exported Functions
  * @{
  */

/**
 *
 * \brief   Enable or disable 32k clock in power down mode.
 *
 * \param[in]  para: Enable or disable 32k clock in power down mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     pmu_set_clk_32k_power_in_powerdown(true);
 * }
 * \endcode
 *
 */
void pmu_set_clk_32k_power_in_powerdown(bool para);

/**
 *
 * \brief   Set vcore2 to PON domain.
 *
 *
 * \param[in] pmu_module: PMU module. @ref _X3G_PMU_MODULE.
 *            - PMU_CODEC: Codec set vcore2 to PON domain.
 *            - PMU_USB: USB set vcore2 to PON domain.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     pmu_vcore2_pon_domain_enable(PMU_CODEC);
 * }
 * \endcode
 *
 */
void pmu_vcore2_pon_domain_enable(PMU_MODULE pmu_module);

/**
 *
 * \brief   Set vcore2 to CORE domain.
 *
 *
 * \param[in] pmu_module: PMU module. @ref _X3G_PMU_MODULE.
 *            - PMU_CODEC: Codec set vcore2 to core domain.
 *            - PMU_USB: USB set vcore2 to core domain.
 *
 * <b>Example usage</b>
 * \code{.c}
 * int test(void)
 * {
 *     pmu_vcore2_pon_domain_disable(PMU_CODEC);
 * }
 * \endcode
 *
 * \ingroup  PMU
 */
void pmu_vcore2_pon_domain_disable(PMU_MODULE pmu_module);

#ifdef __cplusplus
}
#endif

#endif
