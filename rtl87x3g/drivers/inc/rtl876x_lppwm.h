/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef _RTL876X_LPPWM_H_
#define _RTL876X_LPPWM_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtl876x_lppwm_def.h"

/** @addtogroup 87x3g_LPPWM LPPWM
  * @brief LPPWM driver module.
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/

/** @defgroup 87x3g_LPPWM_Exported_Types LPPWM Exported Types
  * @{
  */

/**
 * @brief LPPWM initialize parameters.
 */

typedef struct
{
    uint8_t LPPWM_Polarity;        /*!< Specifies the LPPWM output polarity.
                                        This parameter can be a value of @ref x3g_LPPWM_Output_Polarity. */
    uint16_t LPPWM_PeriodHigh;     /*!< Specifies the LPPWM high count.
                                        This parameter can be a value of 0-65535. */
    uint16_t LPPWM_PeriodLow;      /*!< Specifies the LPPWM low count.
                                        This parameter can be a value of 0-65535. */
} LPPWM_InitTypeDef;

/** End of group 87x3g_LPPWM_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup 87x3g_LPPWM_Exported_Constants LPPWM Exported Constants
  * @{
  */

/** @defgroup 87x3g_LPPWM_Output_Polarity LPPWM Output Polarity
  * @{
  */
typedef enum
{
    LPPWM_POLARITY_NORMAL = 0x0,      //!< Non-inverting output.
    LPPWM_POLARITY_INVERT = 0x1,      //!< Inverting output.
} LPPWMOutputPolarity_TypeDef;

#define IS_LPPWM_OUTPUT_MODE(MODE)    (((MODE) == LPPWM_POLARITY_NORMAL) || \
                                       ((MODE) == LPPWM_POLARITY_INVERT))   //!< Check whether is the LPPWM output polarity.
/** End of group 87x3g_LPPWM_Output_Polarity
  * @}
  */

/** End of group 87x3g_LPPWM_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup 87x3g_LPPWM_Exported_Functions LPPWM Exported Functions
 * @{
 */

/**
 *
 * \brief   Restore all the LPPWM registers to their default values.
 *
 * \param[in] LPPWMx: Selected LPPWM peripheral, which can be LPPWM.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_Reset(LPPWM);
 * }
 * \endcode
 */
void LPPWM_Reset(LPPWM_TypeDef *LPPWMx);


/**
 *
 * \brief  Initialize the LPPWM according to the specified parameters in the LPPWM_InitStruct.
 *
 * \param[in] LPPWMx: Selected LPPWM peripheral, which can be LPPWM.
 * \param[in] LPPWM_InitStruct: Pointer to a LPPWM_InitTypeDef structure that contains the configuration information for the LPPWM.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_Reset(LPPWM);
 *     LPPWM_InitTypeDef LPPWM_InitStruct;
 *     LPPWM_StructInit(&LPPWM_InitStruct);
 *     LPPWM_InitStruct.LPPWM_Polarity                   = LPPWM_POLARITY_NORMAL;
 *     LPPWM_InitStruct.LPPWM_PeriodHigh                 = 32;
 *     LPPWM_InitStruct.LPPWM_PeriodLow                  = 32;
 *     LPPWM_Init(LPPWM, &LPPWM_InitStruct);
 *     LPPWM_Cmd(LPPWM, ENABLE);
 * }
 * \endcode
 */
void LPPWM_Init(LPPWM_TypeDef *LPPWMx, LPPWM_InitTypeDef *LPPWM_InitStruct);


/**
 *
 * \brief   Fill each LPPWM_InitStruct member with its default value.
 *
 * \note   The default settings for the LPPWM_InitStruct member are shown in the following table:
 *         | LPPWM_InitStruct Member   | Default Value                       |
 *         |:-------------------------:|:-----------------------------------:|
 *         | LPPWM_Polarity            | \ref LPPWM_POLARITY_NORMAL          |
 *         | LPPWM_PeriodHigh          | 0                                   |
 *         | LPPWM_PeriodLow           | 0                                   |
 *
 * \param[in] LPPWM_InitStruct: Pointer to a LPPWM_InitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_Reset(LPPWM);
 *     LPPWM_InitTypeDef LPPWM_InitStruct;
 *     LPPWM_StructInit(&LPPWM_InitStruct);
 *     LPPWM_InitStruct.LPPWM_Polarity                   = LPPWM_POLARITY_NORMAL;
 *     LPPWM_InitStruct.LPPWM_PeriodHigh                 = 32;
 *     LPPWM_InitStruct.LPPWM_PeriodLow                  = 32;
 *     LPPWM_Init(LPPWM, &LPPWM_InitStruct);
 *     LPPWM_Cmd(LPPWM, ENABLE);
 * }
 * \endcode
 */
void LPPWM_StructInit(LPPWM_InitTypeDef *LPPWM_InitStruct);

/**
 *
 * \brief   Enable or disable the LPPWM peripheral.
 *
 * \param[in] LPPWMx: Selected LPPWM peripheral, which can be LPPWM.
 * \param[in] NewState: New state of the LPPWM peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the LPPWM peripheral.
 *            - DISABLE: Disable the LPPWM peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     LPPWM_Cmd(LPPWM, ENABLE);
 * }
 * \endcode
 */
void LPPWM_Cmd(LPPWM_TypeDef *LPPWMx, FunctionalState NewState);

/**
 *
 * \brief   Change LPPWM frequency and duty according period_high and period_low.
 *
 * \param[in] LPPWMx: Selected LPPWM peripheral, which can be LPPWM.
 * \param[in] period_high: Specifies the LPPWM high count. This parameter can be a value of 0-65535.
 * \param[in] period_low: Specifies the LPPWM low count. This parameter can be a value of 0-65535.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     uint32_t high_count = 500;
 *     uint32_t low_count = 500;
 *     LPPWM_ChangeFreqAndDuty(LPPWM, high_count, low_count);
 * }
 * \endcode
 */
void LPPWM_ChangeFreqAndDuty(LPPWM_TypeDef *LPPWMx, uint16_t period_high, uint16_t period_low);

/**
 *
 * \brief   Get the current value of LPPWM's internal counter.
 *
 * \param[in] LPPWMx: Selected LPPWM peripheral, which can be LPPWM.
 *
 * \return  Current value of LPPWM's internal counter.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_lppwm_init(void)
 * {
 *     uint32_t cur_value = LPPWM_GetCurrentValue(LPPWM);
 * }
 * \endcode
 */
uint32_t LPPWM_GetCurrentValue(LPPWM_TypeDef *LPPWMx);

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_LPPWM_H_ */

/** @} */ /* End of group 87x3g_LPPWM_Exported_Functions */
/** @} */ /* End of group 87x3g_LPPWM */


