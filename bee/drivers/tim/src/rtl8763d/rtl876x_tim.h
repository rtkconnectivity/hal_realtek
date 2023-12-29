/**
*********************************************************************************************************
*               Copyright(c) 2015, Realtek Semiconductor Corporation. All rights reserved.
*********************************************************************************************************
* @file      rtl876x_tim.h
* @brief
* @details
* @author    elliot chen
* @date      2015-05-15
* @version   v1.0
* *********************************************************************************************************
*/

#ifndef __RTL876X_TIM_H
#define __RTL876X_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "rtl876x.h"
#include "rtl876x_bitfields.h"

#define TIMER0_LOAD_COUNT2 *((volatile uint32_t *)0x400020b0UL)
#define TIMER1_LOAD_COUNT2 *((volatile uint32_t *)0x400020b4UL)

#define TIMER2_LOAD_COUNT2 *((volatile uint32_t *)0x400020b8UL)
#define TIMER3_LOAD_COUNT2 *((volatile uint32_t *)0x400020bCUL)
#define TIMER4_LOAD_COUNT2 *((volatile uint32_t *)0x400020C0UL)
#define TIMER5_LOAD_COUNT2 *((volatile uint32_t *)0x400020c4UL)
#define TIMER6_LOAD_COUNT2 *((volatile uint32_t *)0x400020c8UL)
#define TIMER7_LOAD_COUNT2 *((volatile uint32_t *)0x400020ccUL)

#define TIMER8_LOAD_COUNT2  *((volatile uint32_t *)0x402820b0UL)
#define TIMER9_LOAD_COUNT2  *((volatile uint32_t *)0x402820b4UL)
#define TIMER10_LOAD_COUNT2 *((volatile uint32_t *)0x402820b8UL)
#define TIMER11_LOAD_COUNT2 *((volatile uint32_t *)0x402820bCUL)
#define TIMER12_LOAD_COUNT2 *((volatile uint32_t *)0x402820c0UL)
#define TIMER13_LOAD_COUNT2 *((volatile uint32_t *)0x402820c4UL)
#define TIMER14_LOAD_COUNT2 *((volatile uint32_t *)0x402820c8UL)
#define TIMER15_LOAD_COUNT2 *((volatile uint32_t *)0x402820ccUL)
/* TIM Private Defines */
#define TIMER_PWM2_CR *((volatile uint32_t *)0x40000364UL)
#define TIMER_PWM3_CR *((volatile uint32_t *)0x40000368UL)

/** @addtogroup 87x3d_TIM TIM
  * @brief TIM driver module
  * @{
  */

/*============================================================================*
 *                         Types
 *============================================================================*/


/** @defgroup TIM_Exported_Types TIM Exported Types
  * @{
  */

/**
  * @brief  TIM Init structure definition
  */
typedef struct
{
    uint16_t TIM_ClockSrc;          /*!< <b>Deprecated</b> use RCC instead*/
    uint16_t TIM_DIV;               /*!< Clock fix at 40Mhz,add this parameter div the clock*/

    uint16_t TIM_SOURCE_DIV;        /*!< Specifies the clock source div.
                                            This parameter can be a value of @ref TIM_Clock_Divider*/
    uint16_t TIM_SOURCE_DIV_En;     /*!< timer source clock div enable*/
    uint16_t TIM_Mode;              /*!< Specifies the counter mode.
                                        This parameter can be a value of @ref TIM_Mode */

    uint16_t TIM_PWM_En;            /*!< Specifies the PWM mode.
                                        This parameter can be a value of DISABLE or ENABLE */
    uint32_t TIM_Period;            /*!< Specifies the period value to be loaded into the active
                                         Auto-Reload Register at the next update event.
                                        This parameter must range from 0x0000 to 0xFFFFFFFF.  */
    uint32_t TIM_PWM_High_Count;    /*!< Specifies the PWM High Count.
                                        This parameter must range from 0x0000 to 0xFFFFFFFF. */
    uint32_t TIM_PWM_Low_Count;     /*!< Specifies the PWM Low Count.
                                        This parameter must range from 0x0000 to 0xFFFFFFFF. */
    uint32_t TIM_EventMode;         /*!< Specifies the TIM event mode */

    uint32_t TIM_EventIndex;        /*!< Specifies the TIM event index */

    uint32_t TIM_EventDuration;     /*!< Specifies the TIM event duration*/

    uint8_t  ClockDepend;           /*!< Specifies TIM Source depend.
                                        timer3 depend timer2 ,timer5 depend timer4 timer7 depend timer6
                                        This parameter can be a value of ENABLE or DISABLE */

    uint32_t PWM_Deazone_Size;      /*!<Size of deadzone time, DeadzoneTime=deadzonesize/32000 or 32768
                                        This parameter must range from 1 to 0xffffffff */
    uint16_t PWMDeadZone_En;        /*!<PWM Deadzone enable, pwm0_pn: timer2, pwm1_pn:timer3
                                        This parameter can be a value of ENABLE or DISABLE */
    uint16_t PWM_Stop_State_P;      /*!< Specifies the PWM P stop state.
                                        This parameter can be a value of @ref PWMDeadZone_Stop_state */
    uint16_t PWM_Stop_State_N;      /*!< Specifies the PWM N stop state.
                                        This parameter can be a value of @ref PWMDeadZone_Stop_state */
} TIM_TimeBaseInitTypeDef;

/** End of group TIM_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup TIM_Exported_constants TIM Exported Constants
  * @{
  */

#define IS_TIM_ALL_PERIPH(PERIPH) (((PERIPH) == TIM0) || \
                                   ((PERIPH) == TIM1) || \
                                   ((PERIPH) == TIM2) || \
                                   ((PERIPH) == TIM3) || \
                                   ((PERIPH) == TIM4) || \
                                   ((PERIPH) == TIM5) || \
                                   ((PERIPH) == TIM6) || \
                                   ((PERIPH) == TIM7) || \
                                   ((PERIPH) == TIM8) || \
                                   ((PERIPH) == TIM9) || \
                                   ((PERIPH) == TIM10)|| \
                                   ((PERIPH) == TIM11)|| \
                                   ((PERIPH) == TIM12)|| \
                                   ((PERIPH) == TIM13)|| \
                                   ((PERIPH) == TIM14)||\
                                   ((PERIPH) == TIM15))


/** @defgroup TIM_Clock_Divider TIM clock divider
  * @{
  */


#define TIM_CLOCK_DIVIDER_1                           ((uint16_t)0x0)
#define TIM_CLOCK_DIVIDER_2                           ((uint16_t)0x4)
#define TIM_CLOCK_DIVIDER_4                           ((uint16_t)0x5)
#define TIM_CLOCK_DIVIDER_8                           ((uint16_t)0x6)
#define TIM_CLOCK_DIVIDER_40                          ((uint16_t)0x7)
#define IS_TIM_SOURCE_DIVIDER(DIV)              (((DIV) == TIM_CLOCK_DIVIDER_1) || \
                                                 ((DIV) == TIM_CLOCK_DIVIDER_2) || \
                                                 ((DIV) == TIM_CLOCK_DIVIDER_4) || \
                                                 ((DIV) == TIM_CLOCK_DIVIDER_8) ||\
                                                 ((DIV) == TIM_CLOCK_DIVIDER_40))

/** End of group TIM_Exported_constants
  * @}
  */

/** @defgroup TIM_Mode TIM Mode
  * @{
  */

#define TIM_Mode_FreeRun                    ((uint16_t)0x0000)
#define TIM_Mode_UserDefine                 ((uint16_t)0x0001)
#define IS_TIM_MODE(mode) (((mode) == TIM_Mode_FreeRun) || \
                           ((mode) == TIM_Mode_UserDefine))
/** End of group TIM_Mode
  * @}
  */

/** @defgroup TIM_PWM_En TIM PWM Mode Enable
  * @{
  */

#define PWM_ENABLE                        ((uint16_t)0x1)
#define PWM_DISABLE                       ((uint16_t)0x0)
#define IS_TIM_PWM_En(mode) (((mode) == PWM_ENABLE) || \
                             ((mode) == PWM_DISABLE))
/** End of group TIM_PWM_En
  * @}
  */

/** @defgroup TIM_Event_Duration TIM Event Duration
  * @{
  */

#define TIM_EventDuration_32us                    ((uint16_t)0x0000)
#define TIM_EventDuration_64us                    ((uint16_t)0x0001)
#define TIM_EventDuration_128us                   ((uint16_t)0x0002)
#define TIM_EventDuration_256us                   ((uint16_t)0x0003)

#define IS_TIM_Event_DURATION(duration) (((duration) == TIM_EventDuration_32us) || \
                                         ((duration) == TIM_EventDuration_64us) || \
                                         ((duration) == TIM_EventDuration_128us) || \
                                         ((duration) == TIM_EventDuration_256us))
/** End of group TIM_Event_Duration
  * @}
  */

/** @defgroup PWMDeadZone_En PWM DeadZone enable
* @{
*/

#define DEADZONE_ENABLE                        ((uint16_t)0x1)
#define DEADZONE_DISABLE                       ((uint16_t)0x0)
#define IS_TIM_PWM_DeadZone_En(mode) (((mode) == DEADZONE_ENABLE) || \
                                      ((mode) == DEADZONE_DISABLE))
/** End of group PWMDeadZone_En
  * @}
  */

/** @defgroup PWMDeadZone_Stop_state PWM DeadZone stop state
* @{
*/

#define PWM_STOP_AT_HIGH                        ((uint16_t)0x1)
#define PWM_STOP_AT_LOW                         ((uint16_t)0x0)

/** End of group PWMDeadZone_Stop_state
  * @}
  */

/** @defgroup PWMDeadZone_Perioheral PWMDeadZone
* @{
*/


#define IS_PWM_ALL_PERIPH(PERIPH) (((PERIPH) == PWM0_PN) || \
                                   ((PERIPH) == PWM1_PN))

/** End of group PWMDeadZone_Perioheral
  * @}
  */

/** End of group TIM_Exported_constants
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/


/** @defgroup TIM_Exported_Functions TIM Exported Functions
  * @{
  */

/**
 * rtl876x_tim.h
 *
 * \brief   Deinitializes the TIMx peripheral registers to their default reset values.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_driver_init(void)
 * {
 *     TIM_DeInit();
 * }
 * \endcode
 */
void TIM_DeInit(void);

/**
 * rtl876x_tim.h
 *
 * \brief   Initialize the TIMx time base unit peripheral according to
 *          the specified parameters in TIM_TimeBaseInitStruct.
 *
 * \param[in] TIMx: where x can be 0 to 15 to select the TIM peripheral.
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef
 *            structure that contains the configuration information for the selected TIM peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_driver_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMERA, APBPeriph_TIMERA_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *
 *     TIM_InitStruct.TIM_PWM_En = PWM_DISABLE;
 *     TIM_InitStruct.TIM_Period = 2000 * 10 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_TimeBaseInit(TIM_TypeDef *TIMx, TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * rtl876x_tim.h
 *
 * \brief   Fills each TIM_InitStruct member with its default value.
 *
 * \param[in] TIM_TimeBaseInitStruct: Pointer to a TIM_TimeBaseInitTypeDef structure which will be initialized.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_driver_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMERA, APBPeriph_TIMERA_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *
 *     TIM_InitStruct.TIM_PWM_En = PWM_DISABLE;
 *     TIM_InitStruct.TIM_Period = 2000 * 10 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 * }
 * \endcode
 */
void TIM_StructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);

/**
 * rtl876x_tim.h
 *
 * \brief   Enable or disable the specified TIM peripheral.
 *
 * \param[in] TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 * \param[in] NewState: New state of the TIMx peripheral.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified TIM peripheral.
 *            \arg DISABLE: Disable the specified TIM peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_driver_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_TIMERA, APBPeriph_TIMERA_CLOCK, ENABLE);
 *
 *     TIM_TimeBaseInitTypeDef TIM_InitStruct;
 *     TIM_StructInit(&TIM_InitStruct);
 *
 *     TIM_InitStruct.TIM_PWM_En = PWM_DISABLE;
 *     TIM_InitStruct.TIM_Period = 2000 * 10 - 1;
 *     TIM_InitStruct.TIM_Mode = TIM_Mode_UserDefine;
 *     TIM_TimeBaseInit(TIM6, &TIM_InitStruct);
 *     TIM_Cmd(TIM6, DISABLE);
 * }
 * \endcode
 */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
 * rtl876x_tim.h
 *
 * \brief       Change TIM period value.
 *
 * \param[in]   TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 * \param[in]   period: Period value to be changed.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t new_period = 2000 * 10 - 1;
 *     TIM_Cmd(TIM6, DISABLE);
 *     TIM_ChangePeriod(TIM6, new_period);
 *     TIM_Cmd(TIM6, ENABLE);
 * }
 * \endcode
 */
void TIM_ChangePeriod(TIM_TypeDef *TIMx, uint32_t period);

/**
 * rtl876x_tim.h
 *
 * \brief     Enable or disable the specified TIMx interrupt.
 *
 * \param[in] TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 * \param[in] NewState: New state of the TIMx peripheral.
 *            This parameter can be one of the following values:
 *            \arg ENABLE: Enable the specified TIMx interrupt.
 *            \arg DISABLE: Disable the specified TIMx interrupt.
 *
 * \return    None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_driver_init(void)
 * {
 *     TIM_ClearINT(TIM6);
 *     TIM_INTConfig(TIM6, ENABLE);
 *     RamVectorTableUpdate(Timer6_VECTORn, (IRQ_Fun)tim_handler);
 *
 *     //Enable TIM6 IRQ
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = TIM6_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 */
void TIM_INTConfig(TIM_TypeDef *TIMx, FunctionalState NewState);

/**
 * rtl876x_tim.h
 *
 * \brief   Change PWM freq and duty according high_cnt and low_cnt.
 *
 * \param[in] TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 * \param[in] high_count: Set the PWM high count.
 * \param[in] low_count: Set the PWM low count.
 *
 * \return   None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *     uint32_t high_count = 500;
 *     uint32_t low_count = 500;
 *     TIM_PWMChangeFreqAndDuty(TIM6, high_count, low_count);
 * }
 * \endcode
 */
void TIM_PWMChangeFreqAndDuty(TIM_TypeDef *TIMx, uint32_t high_count, uint32_t low_count);


/**
 * rtl876x_tim.h
 *
 * \brief   Get TIMx current value when timer is running.
 *
 * \param[in]   TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 *
 * \return  The counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_demo(void)
 * {
 *     TIM_Cmd(TIM6, ENABLE);
 *     uint32_t cur_value1 = TIM_GetCurrentValue(TIM6);
 *     I2C_MasterWrite(I2C0, I2C_DATA, 1);
 *     uint32_t cur_value2 = TIM_GetCurrentValue(TIM6);
 *     APP_PRINT_INFO1("I2C_MasterWrite time = %d", cur_value2 - cur_value1);
 *     TIM_Cmd(TIM6, DISABLE);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE uint32_t TIM_GetCurrentValue(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return TIMx->CurrentValue;
}

/**
 * rtl876x_tim.h
 *
 * \brief  Get TIMx elapsed value when timer is running.
 *
 * \param[in]  TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 *
 * \return The elapsed counter value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void i2c_demo(void)
 * {
 *     TIM_Cmd(TIM6, ENABLE);
 *     I2C_MasterWrite(I2C0, I2C_DATA, 1);
 *     uint32_t elapsed_value = TIM_GetElapsedValue(TIM6);
 *     APP_PRINT_INFO1("I2C_MasterWrite time = %d", elapsed_value);
 *     TIM_Cmd(TIM6, DISABLE);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE uint32_t TIM_GetElapsedValue(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    return (TIMx->LoadCount - TIMx->CurrentValue);
}

/**
 * rtl876x_tim.h
 *
 * \brief   Checks whether the TIM has been enabled or disabled.
 *
 * \param[in]   TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 *
 * \return The state of the TIM.
 * \retval ENABLE: The TIM peripheral has been enabled.
 * \retval DISABLE: The TIM peripheral has been disabled.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void timer_demo(void)
 * {
 *    if (TIM_GetStatus(TIM6) == ENABLE)
 *    {
 *        // add user code here
 *    }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE FunctionalState TIM_GetStatus(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIMx->ControlReg & BIT(0))
    {
        return ENABLE;
    }
    else
    {
        return DISABLE;
    }
}

/**
 * rtl876x_tim.h
 *
 * \brief   Check whether the TIM interrupt has occurred or not.
 *
 * \param[in]   TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 *
 * \return The new state of of the TIM_IT.
 * \retval SET: The TIM interrupt has occurred.
 * \retval RESET: The TIM interrupt has not occurred.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_handler(void)
 * {
 *    if (TIM_GetINTStatus(TIM6) == SET)
 *    {
 *        TIM_ClearINT(TIM6);
 *        TIM_Cmd(TIM6, DISABLE);
 *        // add user code here
 *    }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE ITStatus TIM_GetINTStatus(TIM_TypeDef *TIMx)
{
    ITStatus bitstatus = RESET;
    uint16_t itstatus = (uint16_t)TIMx->IntStatus;

    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (itstatus != (uint16_t)RESET)
    {
        bitstatus = SET;
    }

    return bitstatus;
}

/**
 * rtl876x_tim.h
 *
 * \brief   Clear TIM interrupt.
 *
 * \param[in]   TIMx: where x can be 0 to 15 to select the TIMx peripheral.
 *
 * \return  None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void tim_handler(void)
 * {
 *    if (TIM_GetINTStatus(TIM6) == SET)
 *    {
 *        TIM_ClearINT(TIM6);
 *        // add user code here
 *    }
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void TIM_ClearINT(TIM_TypeDef *TIMx)
{
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    /* Clear the IT */
    (void)TIMx->EOI;
}

/**
 * rtl876x_tim.h
 *
 * \brief   PWM_deadzone mode emergency stop.
 *
 * \param[in]  PWMx: where x can be 0_PN to 1_PN to select the PWMx peripheral.
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void test_timer_pwmdeadzone(void)
 * {
 *    PWM_Deadzone_EMStop(PWM0_PN);
 * }
 * \endcode
 */
__STATIC_ALWAYS_INLINE void PWM_Deadzone_EMStop(PWM_TypeDef *PWMx)
{
    /* Check the parameters */
    assert_param(IS_PWM_ALL_PERIPH(PWMx));

    PWMx->CR |= BIT(8);
}

#ifdef __cplusplus
}
#endif

#endif /*__RTL876X_TIM_H*/

/** @} */ /* End of group TIM_Exported_Functions */
/** @} */ /* End of group 87x3d_TIM */


/******************* (C) COPYRIGHT 2015 Realtek Semiconductor Corporation *****END OF FILE****/

