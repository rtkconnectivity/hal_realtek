/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_tim_def.h
* @brief    TIMER related definitions for RTL87x2F
* @details
* @author   grace_ysn
* @date     2023.02.17
* @version  v1.0.0
*********************************************************************************************************
*/

#ifndef RTL_TIM_DEF_H
#define RTL_TIM_DEF_H

#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */


/* ================================================================================ */
/* ================                  TIM  Defines                  ================ */
/* ================================================================================ */
/** \defgroup TIM_Exported_Constants TIM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup TIM_Defines TIM Defines
 * \{
 * \ingroup  TIM_Exported_Constants
 */
#define CHIP_TIM_NUM                                   (4+6)
#define CHIP_PWM_NUM                                   (4)
#define TIM_SUPPORT_CLOCK_DEPEND                       (0)
#define TIM_SUPPORT_EVENT_DURATION                     (0)

/** End of TIM_Defines
  * \}
  */

/** End of TIM_Exported_Constants
  * \}
  */


/*============================================================================*
 *                         TIMER Registers Memory Map
 *============================================================================*/
typedef struct
{
    __IO uint32_t TIMER_LOADCOUNT;        /*!< 0x00 */
    __I  uint32_t TIMER_CURRENTVALUE;     /*!< 0x04 */
    __IO uint32_t TIMER_CONTROLREG;       /*!< 0x08 */
    __I  uint32_t TIMER_EOI;              /*!< 0x0C */
    __I  uint32_t TIMER_INTSTATUS;        /*!< 0x10 */
} TIM_TypeDef;

typedef struct
{
    __IO uint32_t TIMER_B_PWM_WRAP_CFG;   /*!< 0x260 */
} PWM_TypeDef;
/*============================================================================*
 *                         TIMER Declaration
 *============================================================================*/
//#define TIMA_0             ((TIM_TypeDef *) TIMER_A0_REG_BASE)
//#define TIMA_1             ((TIM_TypeDef *) TIMER_A1_REG_BASE)
//#define TIMA_2             ((TIM_TypeDef *) TIMER_A2_REG_BASE)
#define TIMB_0             ((TIM_TypeDef *) TIMER_B0_REG_BASE)
#define TIMB_1             ((TIM_TypeDef *) TIMER_B1_REG_BASE)
#define TIMB_2             ((TIM_TypeDef *) TIMER_B2_REG_BASE)
#define TIMB_3             ((TIM_TypeDef *) TIMER_B3_REG_BASE)
#define TIMC_0             ((TIM_TypeDef *) TIMER_C0_REG_BASE)
#define TIMC_1             ((TIM_TypeDef *) TIMER_C1_REG_BASE)
#define TIMC_2             ((TIM_TypeDef *) TIMER_C2_REG_BASE)
#define TIMC_3             ((TIM_TypeDef *) TIMER_C3_REG_BASE)
#define TIMC_4             ((TIM_TypeDef *) TIMER_C4_REG_BASE)
#define TIMC_5             ((TIM_TypeDef *) TIMER_C5_REG_BASE)

#define PWMB_0             ((PWM_TypeDef *) TIMER_B0_PWM_REG_BASE)
#define PWMB_1             ((PWM_TypeDef *) TIMER_B1_PWM_REG_BASE)
#define PWMB_2             ((PWM_TypeDef *) TIMER_B2_PWM_REG_BASE)
#define PWMB_3             ((PWM_TypeDef *) TIMER_B3_PWM_REG_BASE)

/*============================================================================*
 *                         TIMER Private Defines
 *============================================================================*/
#define TIMERB_CH0_LOAD_COUNT2      *((volatile uint32_t *)(TIMER_B_REG_BASE+0xB0))
#define TIMERB_CH1_LOAD_COUNT2      *((volatile uint32_t *)(TIMER_B_REG_BASE+0xB4))
#define TIMERB_CH2_LOAD_COUNT2      *((volatile uint32_t *)(TIMER_B_REG_BASE+0xB8))
#define TIMERB_CH3_LOAD_COUNT2      *((volatile uint32_t *)(TIMER_B_REG_BASE+0xBC))

/*============================================================================*
 *                         TIMER Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R/W    TimerNLoadCount                     0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t TimerNLoadCount: 32;
    } b;
} TIMER_LOADCOUNT_t;



/* 0x04
   31:0    R      TimerNCurrentValue                  0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t TimerNCurrentValue: 32;
    } b;
} TIMER_CURRENTVALUE_t;



/* 0x08
   0       R/W    TimerEnable                         0x0
   1       R/W    TimerMode                           0x0
   2       R/W    TimerInterruptMask                  0x0
   3       R/W    TIMER_PWM                           0x0
   31:4    R      Reserved                            0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t TimerEnable: 1;
        __IO uint32_t TimerMode: 1;
        __IO uint32_t TimerInterruptMask: 1;
        __IO uint32_t TIMER_PWM: 1;
        __I uint32_t reserved_0: 28;
    } b;
} TIMER_CONTROLREG_t;



/* 0x0C
   0       R      TimerNEndofInterrupt                0x0
   31:1    R      Reserved                            0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t TimerNEndofInterrupt: 1;
        __I uint32_t reserved_0: 31;
    } b;
} TIMER_EOI_t;



/* 0x10
   0       R      TimerNInterruptStatus               0x0
   31:1    R      Reserved                            0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t TimerNInterruptStatus: 1;
        __I uint32_t reserved_0: 31;
    } b;
} TIMER_INTSTATUS_t;



/* 0x260
   7:0     R/W    timer_b_pwm_dead_zone_size        8'h0
   8       R/W    timer_b_pwm_emg_stop              1'h0
   9       R/W    timer_b_pwm_stop_state[0]         1'h0
   10      R/W    timer_b_pwm_stop_state[1]         1'h0
   11      R/W    timer_b_pwm_dummy_b11             1'h0
   12      R/W    timer_b_pwm_dead_zone_en          1'h0
   13      R/W    timer_b_pwm_pwm_pn_invserse_sel   1'h0
   14      R/W    timer_b_pwm_dummy_b14             1'h0
   15      R/W    timer_b_pwm_dummy_b15             1'h0
   31:16   R      RSVD                              16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t timer_b_pwm_dead_zone_size: 8;
        __IO uint32_t timer_b_pwm_emg_stop: 1;
        __IO uint32_t timer_b_pwm_stop_state_0: 1;
        __IO uint32_t timer_b_pwm_stop_state_1: 1;
        __IO uint32_t timer_b_pwm_dummy_b11: 1;
        __IO uint32_t timer_b_pwm_dead_zone_en: 1;
        __IO uint32_t timer_b_pwm_pwm_pn_invserse_sel: 1;
        __IO uint32_t timer_b_pwm_dummy_b14: 1;
        __IO uint32_t timer_b_pwm_dummy_b15: 1;
        __I uint32_t reserved_0: 16;
    } b;
} TIMER_B_PWM_WRAP_CFG_t;


/* ================================================================================ */
/* ================                   TIMER  Constants             ================ */
/* ================================================================================ */
/** \defgroup TIM_Exported_Constants TIM Exported Constants
  * \brief
  * \{
  */

#define TIM3               TIMB_0
#define TIM4               TIMB_1
#define TIM5               TIMB_2
#define TIM6               TIMB_3
#define TIM7               TIMC_0
#define TIM8               TIMC_1
#define TIM9               TIMC_2
#define TIM10              TIMC_3
#define TIM11              TIMC_4
#define TIM12              TIMC_5

#define Timer3_IRQn                Timer_B0_IRQn
#define Timer4_IRQn                Timer_B1_IRQn
#define Timer5_IRQn                Timer_B2_IRQn
#define Timer6_IRQn                Timer_B3_IRQn
#define Timer7_IRQn                Timer_C0_IRQn
#define Timer8_IRQn                Timer_C1_IRQn
#define Timer9_IRQn                Timer_C2_IRQn
#define Timer10_IRQn               Timer_C3_IRQn
#define Timer11_IRQn               Timer_C4_IRQn
#define Timer12_IRQn               Timer_C5_IRQn

#define TIM3_Handler               TIM_B0_Handler
#define TIM4_Handler               TIM_B1_Handler
#define TIM5_Handler               TIM_B2_Handler
#define TIM6_Handler               TIM_B3_Handler
#define TIM7_Handler               TIM_C0_Handler
#define TIM8_Handler               TIM_C1_Handler
#define TIM9_Handler               TIM_C2_Handler
#define TIM10_Handler              TIM_C3_Handler
#define TIM11_Handler              TIM_C4_Handler
#define TIM12_Handler              TIM_C5_Handler

/**
 * \brief       TIM Clock Source
 *
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    CK_40M_TIMER = 0x0,
    CK_32K_TIMER = 0x1,
} TIMClockSrc_TypeDef;

#define IS_TIM_CLK_SOURCE(PERIPH)     (((PERIPH) == CK_40M_TIMER) || \
                                       ((PERIPH) == CK_32K_TIMER))

/**
 * \brief       TIM Clock Divider
 *
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    TIM_CLOCK_DIVIDER_1 = 0x0,
    TIM_CLOCK_DIVIDER_2 = 0x1,
    TIM_CLOCK_DIVIDER_4 = 0x2,
    TIM_CLOCK_DIVIDER_8 = 0x3,
    TIM_CLOCK_DIVIDER_16 = 0x4,
    TIM_CLOCK_DIVIDER_32 = 0x5,
    TIM_CLOCK_DIVIDER_40 = 0x6,
    TIM_CLOCK_DIVIDER_64 = 0x7,
} TIMClockDiv_TypeDef;

#define IS_TIM_CLK_DIV(DIV) (((DIV) == TIM_CLOCK_DIVIDER_1) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_2) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_4) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_8) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_16) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_32) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_40) || \
                             ((DIV) == TIM_CLOCK_DIVIDER_64))

/** End of TIM_Exported_Constants
  * \}
  */


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_TIM_DEF_H */
