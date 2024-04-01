/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_tim_def.h
* @brief    TIMER related definitions for RTL87x2G
* @details
* @author   grace_ysn
* @date     2023.02.17
* @version  v1.0.0
*********************************************************************************************************
*/

#ifndef RTL_TIM_DEF_H
#define RTL_TIM_DEF_H

#include "utils/rtl_utils.h"
#include "address_map.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/*============================================================================*
 *                          TIM Defines
 *============================================================================*/
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
#define CHIP_PWM_DEAD_ZONE_NUM                         (2)
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
    __IO uint32_t TIMER_PWM_WRAP_CFG;    /*!< 0x33C */
} PWM_TypeDef;

/*============================================================================*
 *                         TIMER Declaration
 *============================================================================*/
/** \defgroup 87X2G_TIM         TIM
  * \brief
  * \{
  */

/** \defgroup TIM_Declaration TIM Declaration
  * \brief
  * \{
  */
#define TIMER_0_REG_BASE                   (TIMER_REG_BASE + 0x0000)
#define TIMER_1_REG_BASE                   (TIMER_REG_BASE + 0x0014)
#define TIMER_2_REG_BASE                   (TIMER_REG_BASE + 0x0028)
#define TIMER_3_REG_BASE                   (TIMER_REG_BASE + 0x003c)
#define TIMER_4_REG_BASE                   (TIMER_REG_BASE + 0x0050)
#define TIMER_5_REG_BASE                   (TIMER_REG_BASE + 0x0064)
#define TIMER_6_REG_BASE                   (TIMER_REG_BASE + 0x0078)
#define TIMER_7_REG_BASE                   (TIMER_REG_BASE + 0x008c)

#define TIM0               ((TIM_TypeDef *) TIMER_0_REG_BASE)
#define TIM1               ((TIM_TypeDef *) TIMER_1_REG_BASE)
#define TIM2               ((TIM_TypeDef *) TIMER_2_REG_BASE)
#define TIM3               ((TIM_TypeDef *) TIMER_3_REG_BASE)
#define TIM4               ((TIM_TypeDef *) TIMER_4_REG_BASE)
#define TIM5               ((TIM_TypeDef *) TIMER_5_REG_BASE)
#define TIM6               ((TIM_TypeDef *) TIMER_6_REG_BASE)
#define TIM7               ((TIM_TypeDef *) TIMER_7_REG_BASE)

#define TIM0_REG_BASE                         TIMER_0_REG_BASE
#define TIMER_A0_REG_BASE                     TIMER_0_REG_BASE
#define TIMA_CH0                              TIM0
#define TIMA_CH1                              TIM1

/** End of TIM_Declaration
  * \}
  */

/* Reasons for the definition of PWMx
   PWM2 and PWM3 share the same register(TIMER_PWM_WRAP_CFG: 0x4000233CUL). When the
   register is 32 bits, PWM2 and PWM3 cannot be distinguished in the function. When
   the register is 16 bits, the function of PWM2 and PWM3 can be opened separately,
   but cannot be opened simultaneously. So the definition of PWM2 and PWM3 is just to
   make a distinction.
*/

/** \defgroup PWM_Declaration PWM Declaration
  * \brief
  * \{
  */

#define PWM2               ((PWM_TypeDef *) 1)
#define PWM3               ((PWM_TypeDef *) 0)

/** End of PWM_Declaration
  * \}
  */

/** End of TIM
  * \}
  */

/*============================================================================*
 *                         TIMER Private Defines
 *============================================================================*/
#define TIMER0_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xB0))
#define TIMER1_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xB4))
#define TIMER2_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xB8))
#define TIMER3_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xBC))
#define TIMER4_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xC0))
#define TIMER5_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xC4))
#define TIMER6_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xC8))
#define TIMER7_LOAD_COUNT2       *((volatile uint32_t *)(TIMER_REG_BASE+0xCC))

#define TIMER_CLK_SOURCE_REG_328 *((volatile uint32_t *)0x40002328UL)

#define TIMER_PWM_CLK_CR         *((volatile uint32_t *)0x4000232CUL)
#define TIMER_PWM_CR             *((volatile uint32_t *)0x4000233CUL)


/*============================================================================*
 *                         TIM Private Types
 *============================================================================*/
typedef struct
{
    uint32_t tim_reg[29];
} TIMStoreReg_Typedef;

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
        uint32_t TimerNLoadCount: 32;
    } b;
} TIMER_LOADCOUNT_TypeDef;



/* 0x04
   31:0    R      TimerNCurrentValue                  0x0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        const uint32_t TimerNCurrentValue: 32;
    } b;
} TIMER_CURRENTVALUE_TypeDef;



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
        uint32_t TimerEnable: 1;
        uint32_t TimerMode: 1;
        uint32_t TimerInterruptMask: 1;
        uint32_t TIMER_PWM: 1;
        const uint32_t reserved_0: 28;
    } b;
} TIMER_CONTROLREG_TypeDef;



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
        const uint32_t TimerNEndofInterrupt: 1;
        const uint32_t reserved_0: 31;
    } b;
} TIMER_EOI_TypeDef;



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
        const uint32_t TimerNInterruptStatus: 1;
        const uint32_t reserved_0: 31;
    } b;
} TIMER_INTSTATUS_TypeDef;



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
        uint32_t timer_pwm_2_dead_zone_size: 8;
        uint32_t timer_pwm_2_emg_stop: 1;
        uint32_t timer_pwm_2_stop_state_0: 1;
        uint32_t timer_pwm_2_stop_state_1: 1;
        uint32_t timer_pwm_2_dummy_b11: 1;
        uint32_t timer_pwm_2_dead_zone_en: 1;
        uint32_t timer_pwm_2_pwm_pn_invserse_sel: 1;
        uint32_t timer_pwm_2_dummy_b14: 1;
        uint32_t timer_pwm_2_dummy_b15: 1;
        uint32_t timer_pwm_3_dead_zone_size: 8;
        uint32_t timer_pwm_3_emg_stop: 1;
        uint32_t timer_pwm_3_stop_state_0: 1;
        uint32_t timer_pwm_3_stop_state_1: 1;
        uint32_t timer_pwm_3_dummy_b11: 1;
        uint32_t timer_pwm_3_dead_zone_en: 1;
        uint32_t timer_pwm_3_pwm_pn_invserse_sel: 1;
        uint32_t timer_pwm_3_dummy_b14: 1;
        uint32_t timer_pwm_3_dummy_b15: 1;
    } b;
} TIMER_PWM_WRAP_CFG_TypeDef;

/* ================================================================================ */
/* ================                   TIMER  Constants             ================ */
/* ================================================================================ */
/** \defgroup TIM_Exported_Constants TIM Exported Constants
  * \brief
  * \{
  */

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

#define IS_TIM_CLK_SOURCE(PERIPH)     (((PERIPH) == CK_40M_TIMER) || \
                                       ((PERIPH) == CK_32K_TIMER) || \
                                       ((PERIPH) == CK_PLL2_TIMER) || \
                                       ((PERIPH) == CK_PLL1_TIMER))

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

/*============================================================================*
 *                          TIM TYPE/API Wrappers
 *============================================================================*/
/** \defgroup TIM_Exported_Constants TIM Exported Constants
  * \brief
  * \{
  */

/**
* \brief       To be compatible with the previous driver.
* \defgroup    TIM_InitStruct_Wrapper TIM InitStruct Wrapper
* \{
* \ingroup     TIM_Exported_Constants
*/

#define TIM_ClockSrcDiv              TIM_SOURCE_DIV
#define TIM_ClockSrcDiv_En           TIM_SOURCE_DIV_En

/** End of TIM InitStruct Wrapper
  * \}
  */

/**
 * \brief       To be compatible with the previous driver.
 * \defgroup    TIM_API_Wrapper TIM API Wrapper
 * \{
 * \ingroup     TIM_Exported_Constants
 */
#define TIM_GetStatus      TIM_GetOperationStatus

/** End of TIM_API_Wrapper
  * \}
  */

/** End of TIM_Exported_Constants
  * \}
  */

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_TIM_DEF_H */
