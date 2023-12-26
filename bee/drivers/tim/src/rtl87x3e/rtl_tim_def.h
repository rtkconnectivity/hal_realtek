/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_tim_def.h
* @brief    TIMER related definitions for RTL87x3E
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
#define CHIP_TIM_NUM                                   (8)
#define CHIP_PWM_NUM                                   (2)
#define TIM_SUPPORT_CLOCK_DEPEND                       (1)
#define TIM_SUPPORT_EVENT_DURATION                     (1)

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
    __IO uint32_t TIMER_PWM_WRAP_CFG;    /*!< 0x33C */
} PWM_TypeDef;

/*============================================================================*
 *                         TIMER Declaration
 *============================================================================*/
#define TIM0               ((TIM_TypeDef *) TIMER_0_REG_BASE)
#define TIM1               ((TIM_TypeDef *) TIMER_1_REG_BASE)
#define TIM2               ((TIM_TypeDef *) TIMER_2_REG_BASE)
#define TIM3               ((TIM_TypeDef *) TIMER_3_REG_BASE)
#define TIM4               ((TIM_TypeDef *) TIMER_4_REG_BASE)
#define TIM5               ((TIM_TypeDef *) TIMER_5_REG_BASE)
#define TIM6               ((TIM_TypeDef *) TIMER_6_REG_BASE)
#define TIM7               ((TIM_TypeDef *) TIMER_7_REG_BASE)

#define PWM2               ((PWM_TypeDef *) PWM2_REG_BASE)
#define PWM3               ((PWM_TypeDef *) PWM3_REG_BASE)

/*============================================================================*
 *                         TIMER Private Defines
 *============================================================================*/
#define TIMER0_LOAD_COUNT2 *((volatile uint32_t *)0x400250b0UL)
#define TIMER1_LOAD_COUNT2 *((volatile uint32_t *)0x400250b4UL)
#define TIMER2_LOAD_COUNT2 *((volatile uint32_t *)0x400250b8UL)
#define TIMER3_LOAD_COUNT2 *((volatile uint32_t *)0x400250bCUL)
#define TIMER4_LOAD_COUNT2 *((volatile uint32_t *)0x400250C0UL)
#define TIMER5_LOAD_COUNT2 *((volatile uint32_t *)0x400250c4UL)
#define TIMER6_LOAD_COUNT2 *((volatile uint32_t *)0x400250c8UL)
#define TIMER7_LOAD_COUNT2 *((volatile uint32_t *)0x400250ccUL)

#define TIMER_PWM2_CR      *((volatile uint32_t *)0x40000364UL)
#define TIMER_PWM3_CR      *((volatile uint32_t *)0x40000368UL)

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



/* 0x33C
   7:0     R/W    timer_pwm_2_dead_zone_size        8'h0
   8       R/W    timer_pwm_2_emg_stop              1'h0
   9       R/W    timer_pwm_2_stop_state[0]         1'h0
   10      R/W    timer_pwm_2_stop_state[1]         1'h0
   11      R/W    timer_pwm_2_dummy_b11             1'h0
   12      R/W    timer_pwm_2_dead_zone_en          1'h0
   13      R/W    timer_pwm_2_pwm_pn_invserse_sel   1'h0
   14      R/W    timer_pwm_2_dummy_b14             1'h0
   15      R/W    timer_pwm_2_dummy_b15             1'h0
   23:16   R/W    timer_pwm_3_dead_zone_size        8'h0
   24      R/W    timer_pwm_3_emg_stop              1'h0
   25      R/W    timer_pwm_3_stop_state[0]         1'h0
   26      R/W    timer_pwm_3_stop_state[1]         1'h0
   27      R/W    timer_pwm_3_dummy_b11             1'h0
   28      R/W    timer_pwm_3_dead_zone_en          1'h0
   29      R/W    timer_pwm_3_pwm_pn_invserse_sel   1'h0
   30      R/W    timer_pwm_3_dummy_b14             1'h0
   31      R/W    timer_pwm_3_dummy_b15             1'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t timer_pwm_2_dead_zone_size: 8;
        __IO uint32_t timer_pwm_2_emg_stop: 1;
        __IO uint32_t timer_pwm_2_stop_state_0: 1;
        __IO uint32_t timer_pwm_2_stop_state_1: 1;
        __IO uint32_t timer_pwm_2_dummy_b11: 1;
        __IO uint32_t timer_pwm_2_dead_zone_en: 1;
        __IO uint32_t timer_pwm_2_pwm_pn_invserse_sel: 1;
        __IO uint32_t timer_pwm_2_dummy_b14: 1;
        __IO uint32_t timer_pwm_2_dummy_b15: 1;
        __IO uint32_t timer_pwm_3_dead_zone_size: 8;
        __IO uint32_t timer_pwm_3_emg_stop: 1;
        __IO uint32_t timer_pwm_3_stop_state_0: 1;
        __IO uint32_t timer_pwm_3_stop_state_1: 1;
        __IO uint32_t timer_pwm_3_dummy_b11: 1;
        __IO uint32_t timer_pwm_3_dead_zone_en: 1;
        __IO uint32_t timer_pwm_3_pwm_pn_invserse_sel: 1;
        __IO uint32_t timer_pwm_3_dummy_b14: 1;
        __IO uint32_t timer_pwm_3_dummy_b15: 1;
    } b;
} TIMER_PWM_WRAP_CFG_t;


/* ================================================================================ */
/* ================                   TIMER  Constants             ================ */
/* ================================================================================ */

/**
 * \brief       TIM Clock Source
 *
 * \ingroup     TIM_Exported_Constants
 */
typedef enum
{
    CK_40M_TIMER = 0x0,
    CK_32K_TIMER = 0x1,
    CK_PLL2_TIMER = 0x2,
    CK_PLL1_TIMER = 0x3,
} TIMClockSrc_TypeDef;

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


/* ================================================================================ */
/* ================               TIM  WRAPPER                     ================ */
/* ================================================================================ */
/**
 * \brief    TIMER Macro Wrapper
 *
 * \ingroup  TIMER_Exported_Constants
 */
#define PWM_ENABLE                   ENABLE
#define PWM_DISABLE                  DISABLE
#define DEADZONE_ENABLE              ENABLE
#define DEADZONE_DISABLE             DISABLE

#define TIM_ClockSrcDiv              TIM_SOURCE_DIV
#define TIM_ClockSrcDiv_En           TIM_SOURCE_DIV_En

#define TIM_GetStatus                TIM_GetOperationStatus


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_TIM_DEF_H */
