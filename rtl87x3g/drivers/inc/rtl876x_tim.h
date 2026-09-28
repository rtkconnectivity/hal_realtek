/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL876X_TIM_H
#define RTL876X_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x_tim_def.h"

/** @addtogroup 87x3g_TIM TIM
  * @brief TIM driver module.
  * @{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup 87x3g_TIM_Exported_Constants TIM Exported Constants
  * @{
  */

/** @defgroup 87x3g_TIM_Case TIM Case
  * @{
  */
typedef enum
{
    TIM_CASE1 = 1,    //!< The TIM Case 1.
    TIM_CASE7 = 2,    //!< The TIM Case 7.
    TIM_CASE6 = 3,    //!< The TIM Case 6.
    TIM_CASE2 = 4,    //!< The TIM Case 2.
    TIM_CASE3 = 5,    //!< The TIM Case 3.
    TIM_CASE4 = 6,    //!< The TIM Case 4.
    TIM_CASE5 = 7,    //!< The TIM Case 5.
} TIMCASE_TypeDef;

/** End of group 87x3g_TIM_Case
  * @}
  */

/** @defgroup 87x3g_TIM_Mode TIM Mode
  * @{
  */
typedef enum
{
    TIM_Mode_FreeRun = 0x0,   //!< Select the TIM mode as free-running mode.
    TIM_Mode_UserDefine_Auto = 0x1,   //!< Select the TIM mode as user-defined auto mode.
    TIM_Mode_UserDefine = 0x2,        //!< Select the TIM mode as user-defined mode.
} TIMMode_TypeDef;

#define IS_TIM_MODE(mode) (((mode) == TIM_Mode_FreeRun) || \
                           ((mode) == TIM_Mode_UserDefine_Auto) || \
                           ((mode) == TIM_Mode_UserDefine))   //!< Check whether is the TIM mode.

/** End of group 87x3g_TIM_Mode
  * @}
  */

#if (TIM_SUPPORT_PWM_FUNCTION == 1)
/** @defgroup 87x3g_TIM_PWM_En PWM Mode Enable
  * @{
  */

#define IS_PWM_En(mode) (((mode) == ENABLE) || \
                         ((mode) == DISABLE))   //!< Check whether is the status of PWM mode.

/** End of group 87x3g_TIM_PWM_En
  * @}
  */

/** @defgroup 87x3g_PWM_Polarity PWM Polarity
  * @{
  */

typedef enum
{
    PWM_START_WITH_LOW = 0x00,    //!< PWM start with output low.
    PWM_START_WITH_HIGH = 0x01,   //!< PWM start with output high.
} PWMPolarity_TypeDef;

#define IS_PWM_POLARITY(Pol) (((Pol) == PWM_START_WITH_HIGH) || \
                              ((Pol) == PWM_START_WITH_LOW))  //!< Check whether is the PWM polarity.

/** End of group 87x3g_PWM_Polarity
  * @}
  */

/** @defgroup 87x3g_PWM_Output_Mode PWM Output Mode
  * @{
  */
typedef enum
{
    PWM_PUSH_PULL = 0x0,    //!< PWM output mode is push pull.
    PWM_OPEN_DRAIN = 0x1,   //!< PWM output mode is open drain.
}
PWMOutputMode_TypeDef;

/** End of group 87x3g_PWM_Output_Mode
  * @}
  */

#if (TIM_SUPPORT_PWM_DEADZONE == 1)
/** @defgroup 87x3g_PWM_DeadZone_Enable PWM DeadZone Enable
  * @{
  */

#define IS_PWM_DeadZone_En(mode) (((mode) == ENABLE) || \
                                  ((mode) == DISABLE))  //!< Check whether is the status of PWM deadzone.

/** End of group 87x3g_PWM_DeadZone_Enable
  * @}
  */

/** @defgroup 87x3g_PWM_DeadZone_Clock_Source PWM DeadZone Clock Source
  * @{
  */

typedef enum
{
    PWM_DZ_CLOCK_TIMER     = 0x0,   //!< PWM DeadZone clock source is same with TIMER.
    PWM_DZ_CLOCK_32K       = 0x1,   //!< PWM DeadZone clock source is 32KHz.
} PWMDZClockSrc_TypeDef;

#define IS_PWM_DeadZone_SOURCE(PERIPH) (((PERIPH) == PWM_DZ_CLOCK_TIMER) || \
                                        ((PERIPH) == PWM_DZ_CLOCK_32K)) //!< Check whether is the PWM DeadZone clock source.

/** End of group 87x3g_PWM_DeadZone_Clock_Source
  * @}
  */

/** @defgroup 87x3g_PWMDeadZone_Stop_state PWM Dead Zone Stop State
  * @{
  */

typedef enum
{
    PWM_DZ_STOP_AT_LOW = 0x0,     //!< PWM DeadZone stop at low level.
    PWM_DZ_STOP_AT_HIGH = 0x1,    //!< PWM DeadZone stop at high level.
} PWMDZStopState_TypeDef;

#define IS_PWM_DeadZone_STOP_STATE(STATE) (((STATE) == PWM_DZ_STOP_AT_LOW) || \
                                           ((STATE) == PWM_DZ_STOP_AT_HIGH))  //!< Check whether is the PWM DeadZone stop state.

/** End of group 87x3g_PWMDeadZone_Stop_state
  * @}
  */

/** @defgroup 87x3g_PWM_Reference PWM Reference
  * @{
  */

typedef enum
{
    PWM_DZ_REF_PWMPN = 0x0,   //!< PWM reference is PWMPN.
    PWM_DZ_REF_PWMNN = 0x1,   //!< PWM reference is PWMNN.
    PWM_DZ_REF_PWMPP = 0x2,   //!< PWM reference is PWMPP.
    PWM_DZ_REF_PWMNP = 0x3,   //!< PWM reference is PWMNP.
} PWMDZRef_TypeDef;

#define IS_PWM_DeadZone_Refenrence(STATE) (((STATE) == PWM_DZ_REF_PWMPN) || \
                                           ((STATE) == PWM_DZ_REF_PWMNN) || \
                                           ((STATE) == PWM_DZ_REF_PWMPP) || \
                                           ((STATE) == PWM_DZ_REF_PWMNP))   //!< Check whether is the PWM reference.
/** End of group 87x3g_PWM_Reference
  * @}
  */
#endif
#endif

#if (TIM_SUPPORT_LATCH_CNT_0 == 1)
/** @defgroup 87x3g_TIM_Latch_Trigger_Mode TIM Latch Trigger Mode
  * @{
  */

typedef enum
{
    TIM_LATCH_TRIGGER_RISING_EDGE = 0x00,  //!< Latch count 0 trigger mode is rising edge.
    TIM_LATCH_TRIGGER_FALLING_EDGE = 0x01,  //!< Latch count 0 trigger mode is falling edge.
    TIM_LATCH_TRIGGER_BOTH_EDGE = 0x02,     //!< Latch count 0 trigger mode is both rising and falling edge.
} TIMLatchTriggleMode_TypeDef;

#define IS_TIM_LATCH_TRIG_Mode(mode) (((mode) == TIM_LATCH_TRIGGER_BOTH_EDGE) || \
                                      ((mode) == TIM_LATCH_TRIGGER_FALLING_EDGE) || \
                                      ((mode) == TIM_LATCH_TRIGGER_RISING_EDGE))    //!< Check whether is the TIM latch trigger mode.

/** End of group 87x3g_TIM_Latch_Trigger_Mode
  * @}
  */
#endif

#if (TIM_SUPPORT_DMA_FUNCTION == 1)
/** @defgroup 87x3g_TIM_GDMA_Target TIM GDMA Target
  * @{
  */

typedef enum
{
    TIM_DMA_CCR_FIFO = 0x00,   //!< TIM GDMA target is capture/compare FIFO.
    TIM_DMA_LC_FIFO = 0x01,    //!< TIM GDMA target is latch count 0 FIFO.
} TIMDmaTarget_TypeDef;

#define IS_TIM_DMA_TARGET(mode) (((mode) == TIM_DMA_CCR_FIFO) || \
                                 ((mode) == TIM_DMA_LC_FIFO))   //!< Check whether is the TIM GDMA target.

/** End of group 87x3g_TIM_GDMA_Target
  * @}
  */
#endif

/** @defgroup 87x3g_TIM_Interrupts TIM Interrupts
  * @{
  */

#define TIM_INT_TIMEOUT                        (1 << 0)   //!< The timeout interrupt will be triggered when the count reaches 0.
#define TIM_INT_LATCH_CNT_FIFO_FULL            (1 << 1)   //!< When the latch count 0 FIFO data number is greater than or equal to the threshold level, this interrupt is triggered.
#define TIM_INT_LATCH_CNT_FIFO_THD             (1 << 2)   //!< When the latch count 0 FIFO is full, this interrupt is triggered.
#define TIM_INT_PAUSE                          (1 << 3)   //!< The pause interrupt will be triggered when PWM completes the last cycle and counter reaches 0.

#define IS_TIM_INT(INT) (((INT) == TIM_INT_TIMEOUT) || \
                         ((INT) == TIM_INT_LATCH_CNT_FIFO_FULL)  || \
                         ((INT) == TIM_INT_LATCH_CNT_FIFO_THD)   || \
                         ((INT) == TIM_INT_PAUSE))    //!< Check whether is the TIM interrupt.

/** End of group 87x3g_TIM_Interrupts
  * @}
  */

/** @defgroup 87x3g_TIM_Flags TIM Flags
  * @{
  */

#define TIM_FLAG_CCR_FIFO_EMPTY                (0)  //!< TIM capture/compare FIFO empty status.
#define TIM_FLAG_CCR_FIFO_FULL                 (1)  //!< TIM capture/compare FIFO full status.
#define TIM_FLAG_LATCH_CNT_FIFO_EMPTY          (2)  //!< TIM latch count 0 FIFO empty status.

#define IS_TIM_FLAG(flag) (((flag) == TIM_FLAG_CCR_FIFO_FULL) || \
                           ((flag) == TIM_FLAG_CCR_FIFO_EMPTY) || \
                           ((flag) == TIM_FLAG_LATCH_CNT_FIFO_EMPTY)) //!< Check whether is the TIM flag.

/** End of group 87x3g_TIM_Flags
  * @}
  */

/** @defgroup 87x3g_TIM_FIFO_Clear_Flags TIM FIFO Clear Flags
  * @{
  */

#define TIM_FIFO_CLR_CCR                      (0)   //!< Clear TIM capture/compare FIFO.
#define TIM_FIFO_CLR_CNT                      (1)   //!< Clear TIM latch count 0 FIFO.

/** End of group 87x3g_TIM_FIFO_Clear_Flags
  * @}
  */

/** @defgroup 87x3g_TIM_Clock_Source TIM Clock Source
  * @{
  * TIM1_CH6, TIM1_CH7, and TIM1_CH8 supports CK_PLL1_TIMER and CK_PLL2_TIMER and CK_PLL3_TIMER and CK_40M_TIMER.
  * The other channels of timer only support CK_40M_TIMER.
  */

typedef enum
{
    CK_PLL2_TIMER = 0x0,    //!< The TIM clock source is PLL2.
    CK_PLL3_TIMER = 0x1,    //!< The TIM clock source is PLL3.
    CK_PLL1_TIMER = 0x2,    //!< The TIM clock source is PLL1.
    CK_40M_TIMER  = 0x3,    //!< The TIM clock source is 40MHz.
} TIMClockSrc_TypeDef;

#define IS_TIM_CLK_SOURCE(PERIPH)     (((PERIPH) == CK_PLL2_TIMER) || \
                                       ((PERIPH) == CK_PLL3_TIMER) || \
                                       ((PERIPH) == CK_PLL1_TIMER) || \
                                       ((PERIPH) == CK_40M_TIMER))  //!< Check whether is the TIM clock source.

/** End of group 87x3g_TIM_Clock_Source
  * @}
  */

/** @defgroup 87x3g_TIM_Clock_Divider TIM Clock Divider
  * @{
  */

typedef enum
{
    TIM_CLOCK_DIVIDER_1 = 0x0,      //!< The TIM clock divider is 1.
    TIM_CLOCK_DIVIDER_2 = 0x1,      //!< The TIM clock divider is 2.
    TIM_CLOCK_DIVIDER_4 = 0x2,      //!< The TIM clock divider is 4.
    TIM_CLOCK_DIVIDER_8 = 0x3,      //!< The TIM clock divider is 8.
    TIM_CLOCK_DIVIDER_16 = 0x4,     //!< The TIM clock divider is 16.
    TIM_CLOCK_DIVIDER_32 = 0x5,     //!< The TIM clock divider is 32.
    TIM_CLOCK_DIVIDER_40 = 0x6,     //!< The TIM clock divider is 40.
    TIM_CLOCK_DIVIDER_64 = 0x7,     //!< The TIM clock divider is 64.
} TIMClockDiv_TypeDef;

#define IS_TIM_CLK_DIV(DIV) (((DIV) == TIM_CLOCK_DIVIDER_1) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_2) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_4) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_8) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_16) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_32) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_40) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_64))   //!< Check whether is the TIM clock divider.

/** End of group 87x3g_TIM_Clock_Divider
  * @}
  */

/** End of group 87x3g_TIM_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/


/** @defgroup 87x3g_TIM_Exported_Types TIM Exported Types
  * @{
  */

#if (TIM_SUPPORT_PWM_DEADZONE == 1)
/**
  * @brief  PWM deadzone init structure definition.
  */
typedef struct
{
    PWMDZClockSrc_TypeDef PWM_DZClockSrc;     /*!< Specifies the PWM deazone clock source.
                                                   This parameter can be a value of @ref x3g_PWM_DeadZone_Clock_Source. */

    TIMClockDiv_TypeDef PWM_DZClockDiv;       /*!< Specifies the PWM deazone clock divider.
                                                  This parameter can be a value of @ref x3g_TIM_Clock_Divider. */

    uint32_t PWM_DZSize;                      /*!< Specifies the PWM deadzone size.
                                                   This parameter must range from 0x1 to 0xff.
                                                    The calculation formula for deadzone time is as follows:
                                                    Deadzone time = (PWM_DZSize) / deadzone clock. */

    FunctionalState
    PWM_DZEn;                 /*!< Enable or disable the PWM complementary output and deadzone.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    PWMDZStopState_TypeDef PWM_DZStopStateP;  /*!< Specifies the PWM P stop state.
                                                This parameter can be a value of @ref x3g_PWMDeadZone_Stop_state. */

    PWMDZStopState_TypeDef PWM_DZStopStateN;  /*!< Specifies the PWM N stop state.
                                                This parameter can be a value of @ref x3g_PWMDeadZone_Stop_state. */

    FunctionalState PWM_DZInvertP;            /*!< Specifies invertion of PWM P.
                                                   This parameter can be a value of ENABLE or DISABLE. */

    FunctionalState PWM_DZInvertN;            /*!< Specifies invertion of PWM N.
                                                   This parameter can be a value of ENABLE or DISABLE. */
} PWM_DeadZoneTypeDef;
#endif

#if (TIM_SUPPORT_LATCH_CNT_0 == 1)
/**
  * @brief  Latch count init structure definition.
  */
typedef struct
{
    FunctionalState TIM_LatchCountEn[3];    /*!< Enable or disable the TIM latch count function.
                                                 This parameter can be a value of ENABLE or DISABLE. */

    TIMLatchTriggleMode_TypeDef
    TIM_LatchCountTrigger[3];               /*!< Specifies TIM latch count trigger mode.
                                                  This parameter can be a value of @ref x3g_TIM_Latch_Trigger_Mode. */

    uint16_t TIM_LatchCountThd;             /*!< Specifies TIM latch count 0 FIFO threshold.
                                                 This parameter can be value of 0 ~ 8. */

    uint16_t TIM_LatchTriggerPad;           /*!< Specifies the TIM latch count 0 trigger PAD.
                                                 This parameter can be a value of ADC_0 to DAOUT2_N. */

    uint16_t TIM_LatchTriggerDebSize;       /*!< Specifies the TIM latch count 0 trigger debounce size.
                                                 This parameter must range from 0 to 65535. */

    FunctionalState
    TIM_LatchTriggerDebEn;  /*!< Enable or disable the TIM latch count 0 trigger debounce function.
                                                 This parameter can be a value of ENABLE or DISABLE. */

    TIMClockDiv_TypeDef
    TIM_LatchTrigDebClkDiv;                 /*!< Specifies the TIM latch count 0 trigger debounce clock divider.
                                                 This parameter can be a value of @ref x3g_TIM_Clock_Divider. */
} TIM_LatchCountTypeDef;
#endif

/**
  * @brief  TIM init structure definition.
  */

typedef struct
{
    TIMClockSrc_TypeDef TIM_ClockSrc;       /*!< Specifies the clock source.
                                                 This parameter can be a value of @ref x3g_TIM_Clock_Source. */

    TIMClockDiv_TypeDef TIM_ClockDiv;       /*!< Specifies the clock divider.
                                                 This parameter can be a value of @ref x3g_TIM_Clock_Divider. */

    TIMMode_TypeDef TIM_Mode;               /*!< Specifies the operating mode.
                                                 This parameter can be a value of @ref x3g_TIM_Mode. */

    uint32_t TIM_Period;                    /*!< Specifies the period value to be loaded into the active
                                                 auto-reload register at the next update event.
                                                 This parameter must range from 1 to 2^32-2.
                                                 period = PWM high count + PWM low count */

    FunctionalState TIM_OneShotEn;          /*!< Enable or disable the one shot mode.
                                                 This parameter can be a value of ENABLE or DISABLE. */

#if (TIM_SUPPORT_PWM_FUNCTION == 1)
    FunctionalState PWM_En;                 /*!< Enable or disable the PWM mode.
                                                 This parameter can be a value of ENABLE or DISABLE. */

    uint32_t PWM_HighCount;                 /*!< Specify the PWM high count.
                                                 This parameter must range from 0x0 to 2^32-2. */

    PWMPolarity_TypeDef PWM_Polarity;       /*!< Specifies the PWM polarity.
                                                 This parameter can be a value of @ref x3g_PWM_Polarity. */

    PWMOutputMode_TypeDef PWM_OutputMode;   /*!< Specifies the PWM output mode.
                                                 This parameter can be a value of @ref x3g_PWM_Output_Mode. */
#endif

#if (TIM_SUPPORT_PWM_DEADZONE == 1)
    PWM_DeadZoneTypeDef PWM_DZ;             /*!< Specifies PWM deadzone initialization parameters. */
#endif

#if (TIM_SUPPORT_LATCH_CNT_0 == 1)
    TIM_LatchCountTypeDef TIM_LC;           /*!< Specifies latch count initialization parameters. */
#endif

#if (TIM_SUPPORT_DMA_FUNCTION == 1)
    FunctionalState TIM_DmaEn;              /*!< Enable or disable the TIM GDMA.
                                                 This parameter can be a value of ENABLE or DISABLE. */

    TIMDmaTarget_TypeDef TIM_DmaTarget;     /*!< Specifies TIM GDMA target.
                                                 This parameter can be a value of @ref x3g_TIM_GDMA_Target. */
#endif

#if (TIM_SUPPORT_AUTO_CLOCK == 1)
    FunctionalState TIM_DynConfigEn;        /*!< Specifies the functon to dynamic adjustment of
                                                 CCR & MAX_CNT.  When this feature is enabled,
                                                 dynamic adjustment is supported. When this feature
                                                 is disabled, dynamic adjustment is not supported,
                                                 resulting in lower power consumption.
                                                 This parameter can be a value of ENABLE or DISABLE. */
#endif
} TIM_TimeBaseInitTypeDef;

/** End of group 87x3g_TIM_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup 87x3g_TIM_Exported_Functions TIM Exported Functions
  * @{
  */

/**
  * \brief  Enable or Disable TIM peripheral clock.
  *
  * \param[in] TIMx: Selected TIM peripheral.
  * \param[in] is_enable: New state of the specified TIM peripheral clock.
  *            This parameter can be one of the following values:
  *            - true: Enable the TIM peripheral clock.
  *            - false: Disable the TIM peripheral clock.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     TIM_HardwareClock(TIM1_CH6, true);
  * }
  * \endcode
  */
void TIM_HardwareClock(TIM_TypeDef *TIMx, bool is_enable);

/**
 * \brief   Initialize the TIM peripheral according to
 *          the specified parameters in TIM_TimeBaseInitStruct.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef
 *            structure that contains the configuration information for the specified TIM peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER1, APBPeriph_TIMER1_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_ClockSrc = CK_40M_TIMER;
 *     TIM_InitStruct.TIM_ClockDiv = TIM_CLOCK_DIVIDER_40;
 *     TIM_InitStruct.TIM_Period = 40000;
 *     TIM_TimeBaseInit(TIM1_CH6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_TimeBaseInit(TIM_TypeDef *TIMx, TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * \brief   Fills each TIM_TimeBaseInitStruct member with its default value.
 *
 * \note    The default settings for the TIM_TimeBaseInitStruct member are shown in the following table:
 *          | TIM_TimeBaseInitStruct Member    | Default Value                        |
 *          |:--------------------------------:|:------------------------------------:|
 *          | TIM_ClockSrc                     | \ref CK_40M_TIMER                    |
 *          | TIM_ClockDiv                     | \ref TIM_CLOCK_DIVIDER_1             |
 *          | TIM_Mode                         | \ref TIM_Mode_UserDefine             |
 *          | TIM_Period                       | 0xfffffff                            |
 *          | TIM_OneShotEn                    | DISABLE                              |
 *          | PWM_En                           | DISABLE                              |
 *          | PWM_Polarity                     | \ref PWM_START_WITH_HIGH             |
 *          | PWM_OutputMode                   | \ref PWM_PUSH_PULL                   |
 *          | PWM_HighCount                    | 0                                    |
 *          | PWM_DZ.PWM_DZClockSrc            | \ref PWM_DZ_CLOCK_TIMER              |
 *          | PWM_DZ.PWM_DZClockDiv            | \ref TIM_CLOCK_DIVIDER_1             |
 *          | PWM_DZ.PWM_DZStopStateP          | \ref PWM_DZ_STOP_AT_LOW              |
 *          | PWM_DZ.PWM_DZStopStateN          | \ref PWM_DZ_STOP_AT_HIGH             |
 *          | PWM_DZ.PWM_DZInvertP             | DISABLE                              |
 *          | PWM_DZ.PWM_DZInvertN             | DISABLE                              |
 *          | PWM_DZ.PWM_DZEn                  | DISABLE                              |
 *          | PWM_DZ.PWM_DZSize                | 10                                   |
 *          | TIM_LC.TIM_LatchCountEn[0]       | DISABLE                              |
 *          | TIM_LC.TIM_LatchCountTrigger[0]  | \ref TIM_LATCH_TRIGGER_RISING_EDGE   |
 *          | TIM_LC.TIM_LatchCountThd         | 0                                    |
 *          | TIM_LC.TIM_LatchTriggerPad       | 0                                    |
 *          | TIM_LC.TIM_LatchTriggerDebEn     | DISABLE                              |
 *          | TIM_LC.TIM_LatchTriggerDebSize   | 10                                   |
 *          | TIM_LC.TIM_LatchTrigDebClkDiv    | \ref TIM_CLOCK_DIVIDER_1             |
 *          | TIM_LC.TIM_LatchCountEn[1]       | DISABLE                              |
 *          | TIM_LC.TIM_LatchCountTrigger[1]  | \ref TIM_LATCH_TRIGGER_RISING_EDGE   |
 *          | TIM_LC.TIM_LatchCountEn[2]       | DISABLE                              |
 *          | TIM_LC.TIM_LatchCountTrigger[2]  | \ref TIM_LATCH_TRIGGER_RISING_EDGE   |
 *          | TIM_DmaEn                        | DISABLE                              |
 *          | TIM_DmaTarget                    | \ref TIM_DMA_CCR_FIFO                |
 *          | TIM_DynConfigEn                  | ENABLE                               |
 *
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef structure which will be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER1, APBPeriph_TIMER1_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_ClockSrc = CK_40M_TIMER;
 *     TIM_InitStruct.TIM_ClockDiv = TIM_CLOCK_DIVIDER_40;
 *     TIM_InitStruct.TIM_Period = 40000;
 *     TIM_TimeBaseInit(TIM1_CH6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_StructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * \brief   Enable or disable the specified TIM peripheral.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in] NewState: New state of the TIM peripheral.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified TIM peripheral.
 *            - DISABLE: Disable the specified TIM peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER1, APBPeriph_TIMER1_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_ClockSrc = CK_40M_TIMER;
 *     TIM_InitStruct.TIM_ClockDiv = TIM_CLOCK_DIVIDER_40;
 *     TIM_InitStruct.TIM_Period = 40000;
 *     TIM_TimeBaseInit(TIM1_CH6, &TIM_InitStruct);
 *     TIM_Cmd(TIM1_CH6, ENABLE);
 * }
 * \endcode
 */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
 * \brief       Enable or disable the specified TIM interrupt.
 *
 * \param[in]   TIMx: Selected TIM peripheral.
 * \param[in]  TIM_INT: Specifies the TIM interrupt sources to be enabled or disabled, refer to \ref x3g_TIM_Interrupts.
 *             This parameter can be any combination of the following values:
 *             - TIM_INT_TIMEOUT: The timeout interrupt will be triggered when the count reaches 0.
 *             - TIM_INT_LATCH_CNT_FIFO_FULL: When the latch count 0 FIFO data number is greater than or equal to the threshold level, this interrupt is triggered.
 *             - TIM_INT_LATCH_CNT_FIFO_THD: When the latch count 0 FIFO is full, this interrupt is triggered.
 *             - TIM_INT_PAUSE: The pause interrupt will be triggered when PWM completes the last cycle and counter reaches 0.
 * \param[in] NewState: New state of the specified TIM interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the timeout interrupt.
 *            - DISABLE: Disable the timeout interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_timer_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMER1, APBPeriph_TIMER1_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_InitStruct.TIM_ClockSrc = CK_40M_TIMER;
 *     TIM_InitStruct.TIM_ClockDiv = TIM_CLOCK_DIVIDER_40;
 *     TIM_InitStruct.TIM_Period = 40000;
 *     TIM_TimeBaseInit(TIM1_CH6, &TIM_InitStruct);
 *     TIM_Cmd(TIM1_CH6, ENABLE);
 *     TIM_ClearInterrupt(TIM1_CH6, TIM_INT_TIMEOUT);
 *     TIM_InterruptConfig(TIM1_CH6, TIM_INT_TIMEOUT, ENABLE);
 *     RamVectorTableUpdate(TIMER1_CH6_VECTORn, (IRQ_Fun)tim_handler);
 *
 *     NVIC_InitTypeDef nvic_param;
 *     nvic_param.NVIC_IRQChannel = TIMER1_CH6_VECTORn;
 *     nvic_param.NVIC_IRQChannelPriority = 3;
 *     nvic_param.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&nvic_param);
 * }
 * \endcode
 */
void TIM_InterruptConfig(TIM_TypeDef *TIMx, uint8_t TIM_INT, FunctionalState NewState);


/**
 * \brief   Get the specified TIM interrupt status.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in]  TIM_INT: Specifies the TIM interrupt status flag to check, refer to \ref x3g_TIM_Interrupts.
 *             This parameter can be any combination of the following values:
 *             - TIM_INT_TIMEOUT: The timeout interrupt will be triggered when the count reaches 0.
 *             - TIM_INT_LATCH_CNT_FIFO_FULL: When the latch count 0 FIFO data number is greater than or equal to the threshold level, this interrupt is triggered.
 *             - TIM_INT_LATCH_CNT_FIFO_THD: When the latch count 0 FIFO is full, this interrupt is triggered.
 *             - TIM_INT_PAUSE: The pause interrupt will be triggered when PWM completes the last cycle and counter reaches 0.
 *
 * \return  The new state of TIM interrupt status flag.
 * \retval SET: The specified TIM interrupt status flag is set.
 * \retval RESET: The specified TIM interrupt status flag is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     ITStatus int_status = TIM_GetInterruptStatus(TIM1_CH6, TIM_INT_TIMEOUT);
 * }
 * \endcode
 */
ITStatus TIM_GetInterruptStatus(TIM_TypeDef *TIMx, uint8_t TIM_INT);

/**
 * \brief   Clear the specified TIM interrupt.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in]  TIM_INT: Specifies the TIM interrupt pending bit to clear, refer to \ref x3g_TIM_Interrupts.
 *             This parameter can be any combination of the following values:
 *             - TIM_INT_TIMEOUT: The timeout interrupt will be triggered when the count reaches 0.
 *             - TIM_INT_LATCH_CNT_FIFO_FULL: When the latch count 0 FIFO data number is greater than or equal to the threshold level, this interrupt is triggered.
 *             - TIM_INT_LATCH_CNT_FIFO_THD: When the latch count 0 FIFO is full, this interrupt is triggered.
 *             - TIM_INT_PAUSE: The pause interrupt will be triggered when PWM completes the last cycle and counter reaches 0.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     TIM_ClearInterrupt(TIM1_CH6, TIM_INT_TIMEOUT);
 * }
 * \endcode
 */
void TIM_ClearInterrupt(TIM_TypeDef *TIMx, uint8_t TIM_INT);

#if (TIM_SUPPORT_CCR_FIFO == 1 || TIM_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Get the specified TIM flag status.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in]  TIM_FLAG: Specifies the TIM flag to check, refer to \ref x3g_TIM_Flags.
  *            This parameter can be one of the following values:
  *            - TIM_FLAG_CCR_FIFO_EMPTY: TIM capture/compare FIFO empty status.
  *            - TIM_FLAG_CCR_FIFO_FULL: TIM capture/compare FIFO full status.
  *            - TIM_FLAG_LATCH_CNT_FIFO_EMPTY: TIM latch count 0 FIFO empty status.
  *
  * \return  The status of TIM flag.
  * \retval SET: The specified TIM flag is set.
  * \retval RESET: The specified TIM flag is unset.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     FlagStatus flag_status = TIM_GetFIFOFlagStatus(TIM1_CH6, TIM_FLAG_CCR_FIFO_EMPTY);
  * }
  * \endcode
  */
FlagStatus TIM_GetFIFOFlagStatus(TIM_TypeDef *TIMx, uint32_t TIM_FLAG);
#endif

/**
 * \brief       Change the specified TIM period value.
 *
 * \param[in]   TIMx: Selected TIM peripheral.
 * \param[in]   period: Period value to be changed. This parameter must range from 1 to 2^32-2.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t new_period = 20000;
 *     TIM_Cmd(TIM1_CH6, DISABLE);
 *     TIM_ChangePeriod(TIM1_CH6, new_period);
 *     TIM_Cmd(TIM1_CH6, ENABLE);
 * }
 * \endcode
 */
void TIM_ChangePeriod(TIM_TypeDef *TIMx, uint32_t period);

/**
 * \brief   Get the specified TIM period value.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 *
 * \return  The specified TIM period value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t period = TIM_GetPeriod(TIM1_CH6);
 * }
 * \endcode
 */
uint32_t TIM_GetPeriod(TIM_TypeDef *TIMx);

/**
 * \brief   Get the specified TIM current value when timer is running.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 *
 * \return  The current counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t cur_value = TIM_GetCurrentValue(TIM1_CH6);
 * }
 * \endcode
 */
uint32_t TIM_GetCurrentValue(TIM_TypeDef *TIMx);

/**
 * \brief Get the specified TIM elapsed value when timer is running.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 *
 * \return The elapsed counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t value = TIM_GetElapsedValue(TIM1_CH6);
 * }
 * \endcode
 */
uint32_t TIM_GetElapsedValue(TIM_TypeDef *TIMx);

/**
 * \brief   Get the enabled status of the specified TIM.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 *
 * \return The new state of the specified TIM.
 * \retval SET: The timer is enabled.
 * \retval RESET: The timer is disabled.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     FlagStatus status = TIM_GetOperationStatus(TIM1_CH6);
 * }
 * \endcode
 */
FlagStatus TIM_GetOperationStatus(TIM_TypeDef *TIMx);

/**
  * \brief  Enable or disable TIM pause function.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in] NewState: New state of the TIM peripheral.
  *            This parameter can be one of the following values:
  *            - ENABLE: Enable the TIM pause function.
  *            - DISABLE: Disable the TIM pause function.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     TIM_PauseCmd(TIM1_CH6, ENABLE);
  * }
  * \endcode
  */
void TIM_PauseCmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
  * \brief  Activates one shot mode of the specified TIM peripheral.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void hw_timer_start(void)
  * {
  *     TIM_OneShotEnable(TIM1_CH6);
  * }
  * \endcode
  */
void TIM_OneShotEnable(TIM_TypeDef *TIMx);

/**
  * \brief  Get the running status of the specified TIM peripheral in one shot mode.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  *
  * \return The new state of the specified TIM.
  * \retval SET: The timer is running.
  * \retval RESET: The timer is not running.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     FlagStatus status = TIM_GetOneshotStatus(TIM1_CH6);
  * }
  * \endcode
  */
FlagStatus TIM_GetOneshotStatus(TIM_TypeDef *TIMx);

#if (TIM_SUPPORT_CCR_FIFO == 1)
/**
  * \brief  Send data to TIM capture/compare FIFO for user-define auto mode.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in]  value: The data to send. This parameter must range from 0 to 2^32-2.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     TIM_WriteCCFIFO(TIM1_CH9, 100);
  * }
  * \endcode
  */
void TIM_WriteCCFIFO(TIM_TypeDef *TIMx, uint32_t value);
#endif

#if (TIM_SUPPORT_CCR_FIFO == 1 || TIM_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Clear TIM capture/compare FIFO or latch count 0 FIFO.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in]  FIFO_CLR: Specifies the FIFO type which to be clear, refer to \ref x3g_TIM_FIFO_Clear_Flags.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     TIM_ClearFIFO(TIM1_CH9, TIM_FIFO_CLR_CNT);
  * }
  * \endcode
  */
void TIM_ClearFIFO(TIM_TypeDef *TIMx, uint8_t FIFO_CLR);
#endif

#if (TIM_SUPPORT_LATCH_CNT_0 == 1)
/**
  * \brief  Get data from TIM latch count 0 FIFO.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[out]  pBuf: Buffer to save data read from TIM latch count 0 FIFO.
  * \param[in]  length: Number of data to be read, max 8.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     uint8_t fifo_count = 0;
  *     uint16_t data[8] = {0, 0, 0};
  *
  *     fifo_count = TIM_GetLatchCountFIFOLength(TIM1_CH9);
  *     TIM_ReadLatchCountFIFO(TIM1_CH9, data, fifo_count);
  * }
  * \endcode
  */
void TIM_ReadLatchCountFIFO(TIM_TypeDef *TIMx, uint32_t *pBuf, uint8_t length);

/**
  * \brief  Get the length of TIM latch count 0 FIFO.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  *
  * \return Current data length of TIM latch count 0 FIFO.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void timer_demo(void)
  * {
  *     uint8_t fifo_count = 0;
  *     uint16_t data[8] = {0, 0, 0};
  *
  *     fifo_count = TIM_GetLatchCountFIFOLength(TIM1_CH9);
  *     TIM_ReadLatchCountFIFO(TIM1_CH9, data, fifo_count);
  * }
  * \endcode
  */
uint8_t TIM_GetLatchCountFIFOLength(TIM_TypeDef *TIMx);
#endif

#if (TIM_SUPPORT_PWM_FUNCTION == 1)
/**
 * \brief   Change the PWM frequency and duty cycle of the specified TIM according to period and high_count.
 *
 * \param[in]  TIMx: Selected TIM peripheral.
 * \param[in]  period: Set the PWM period value. This parameter must range from 1 to 2^32-2.
 * \param[in]  high_count: Set the PWM high count value. This parameter must range from 0 to 2^32-2.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t period = 1000;
 *     uint32_t high_count = 500;
 *     TIM_PWMChangeFreqAndDuty(TIM1_CH6, period, high_count);
 * }
 * \endcode
 */
void TIM_PWMChangeFreqAndDuty(TIM_TypeDef *TIMx, uint32_t period, uint32_t high_count);

/**
  * \brief  Get TIM toggle state
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  *
  * \return The toggle state of the specified TIM.
  * \retval true: The timer is toggled.
  * \retval false: The timer is not toggled.
  *
  * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     bool state = TIM_GetToggleState(TIM1_CH6);
 * }
 * \endcode
  */
bool TIM_GetToggleState(TIM_TypeDef *TIMx);

#if (TIM_SUPPORT_PWM_PHASE_SHIFT == 1)
/**
  * \brief  Change PWM phase shift count
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in]  PhaseShiftCnt: PWM phase shift count. This parameter can be 0 to capture/compare value;
  *
  * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *    TIM_PhaseShiftCnt(TIM1_CH6, 1000);
 * }
 * \endcode
  */
void TIM_PhaseShiftCnt(TIM_TypeDef *TIMx, uint32_t PhaseShiftCnt);
#endif

#if (TIM_SUPPORT_PWM_DEADZONE == 1)
/**
  * \brief  Select PWM reference.
  *
  * \param[in]  TIMx: Selected TIM peripheral.
  * \param[in]  PWMSrcSel: PWM reference, refer to \ref x3g_PWM_Reference.
  *
  * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *    TIM_PWMDZRefSel(TIM1_CH8, PWM_DZ_REF_PWMPN);
 * }
 * \endcode
  */
void TIM_PWMDZRefSel(TIM_TypeDef *TIMx, PWMDZRef_TypeDef PWMSrcSel);
#endif

/**
 * \brief   PWM complementary output emergency stop and resume.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in] NewState: New state of complementary output.
 *            \ref DISABLE: Resume PWM complementary output.
 *            \ref ENABLE: PWM complementary output emergency stop.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void test_timer_pwmdeadzone(void)
 * {
 *    TIM_PWMComplOutputEMCmd(TIM1_CH6, ENABLE);
 * }
 * \endcode
 */
void TIM_PWMComplOutputEMCmd(TIM_TypeDef *TIMx, FunctionalState NewState);
#endif

/**
 * \brief  Config the TIM clock source and clock divider.
 *
 * \param[in] TIMx: Selected TIM peripheral.
 * \param[in] ClockSrc: specifies the TIM clock source. \ref x3g_TIM_Clock_Source.
 * \param[in] ClockDiv: specifies the TIM clock divider. \ref x3g_TIM_Clock_Divider.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *    TIM_ClkConfig(TIM1_CH6, CK_40M_TIMER, TIM_CLOCK_DIVIDER_40);
 * }
 * \endcode
 */
void TIM_ClkConfig(TIM_TypeDef *TIMx, uint16_t ClockSrc, uint16_t ClockDiv);

#ifdef __cplusplus
}
#endif

#endif /*_RTL876X_TIM_H_*/

/** @} */ /* End of group 87x3g_TIM_Exported_Functions */
/** @} */ /* End of group 87x3g_TIM */


