/**
**********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     rtl_enhtimer_def.h
* @brief    ENH_TIM Registers Structures Section
* @details
* @author   Grace_yan
* @date     2023.02.14
* @version  v1.0.1
*********************************************************************************************************
*/
#ifndef RTL_ENHTIM_DEF_H
#define RTL_ENHTIM_DEF_H

#include <stdint.h>
#include <stdbool.h>
#include "rtl876x.h"

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ================================================================================ */
/* ================                  ENHTIM  Defines               ================ */
/* ================================================================================ */
/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/**
 * \defgroup ENHTIM_Defines ENHTIM Defines
 * \{
 * \ingroup  ENHTIM_Exported_Constants
 */
#define CHIP_ENHTIM_CHANNEL_NUM                        (8)
#define ENHTIM_SUPPORT_LATCH_CNT_0                     (1)
#define ENHTIM_SUPPORT_LATCH_CNT_1                     (0)
#define ENHTIM_SUPPORT_LATCH_CNT_2                     (0)
#define ENHTIM_SUPPORT_PWM_PHASE_SHIFT                 (0)
#define ENHTIM_SUPPORT_PWM_SRC_SELECT                  (0)
#define ENHTIM_SUPPORT_ONESHOT_CMD                     (0)

/** End of ENHTIM_Defines
  * \}
  */

/** End of ENHTIM_Exported_Constants
  * \}
  */


/*============================================================================*
 *                         ENHTIM Registers Memory Map
 *============================================================================*/
typedef struct
{
    __I  uint32_t ENHTIM_CUR_CNT;                /*!< 0x00 */
    __I  uint32_t ENHTIM_LATCH_CNT_0;            /*!< 0x04 */
    __I  uint32_t ENHTIM_LATCH_CNT_1;            /*!< 0x08 */
    __I  uint32_t ENHTIM_LATCH_CNT_2;            /*!< 0x0C */
    __IO uint32_t ENHTIM_CONFIGURE;              /*!< 0x10 */
    __IO uint32_t ENHTIM_MAX_CNT;                /*!< 0x14 */
    __IO uint32_t ENHTIM_CCR;                    /*!< 0x18 */
    __IO uint32_t ENHTIM_CCR_FIFO_ENTRY;         /*!< 0x1C */
} ENHTIM_TypeDef;

typedef struct
{
    __IO uint32_t ENHTIM_LACTH_FIFO_TH_STATUS;   /*!< 0x120 */
    __IO uint32_t ENHTIM_LATCH_CNT_FIFO_STATUS;  /*!< 0x124 */
    __I  uint32_t ENHTIM_CCR_FIFO_STATUS;        /*!< 0x128 */
    __IO uint32_t ENHTIM_FIFO_CLR;               /*!< 0x12C */
    __IO uint32_t ENHTIM_CONTROL;                /*!< 0x130 */
    __IO uint32_t ENHTIM_INT_CONTROL;            /*!< 0x134 */
    __IO uint32_t ENHTIM_STATUS;                 /*!< 0x138 */
    __I  uint32_t ENHTIM_INT_STATUS;             /*!< 0x13C */
    __IO uint32_t ENHTIM_LATCH_INT_CONTROL_0;    /*!< 0x140 */
    __IO uint32_t RESERVED0;                     /*!< 0x144 */
    __IO uint32_t ENHTIM_LATCH_INT_CONTROL_2;    /*!< 0x148 */
    __IO uint32_t RESERVED1;                     /*!< 0x14C */
    __I  uint32_t ENHTIM0_LATCH_FIFO_DEPTH;      /*!< 0x150 */
    __I  uint32_t ENHTIM1_LATCH_FIFO_DEPTH;      /*!< 0x154 */
    __I  uint32_t ENHTIM2_LATCH_FIFO_DEPTH;      /*!< 0x158 */
    __I  uint32_t ENHTIM3_LATCH_FIFO_DEPTH;      /*!< 0x15C */
    __I  uint32_t ENHTIM4_LATCH_FIFO_DEPTH;      /*!< 0x160 */
    __I  uint32_t ENHTIM5_LATCH_FIFO_DEPTH;      /*!< 0x164 */
    __I  uint32_t ENHTIM6_LATCH_FIFO_DEPTH;      /*!< 0x168 */
    __I  uint32_t ENHTIM7_LATCH_FIFO_DEPTH;      /*!< 0x16C */
    __I  uint32_t ENHTIM_TOGGLE_STATE;           /*!< 0x170 */
} ENHTIM_ShareTypeDef;

typedef struct
{
    __IO uint32_t ENHTIMER_PWM_WRAP_CFG;         /*!< 0x270 */
} ENHPWM_TypeDef;

typedef struct
{
    __I  uint32_t ENHTIM_IP_VER;                 /*!< 0x360 */
} ENHTIM_IP_VER_TypeDef;

/*============================================================================*
 *                         ENHTIM Declaration
 *============================================================================*/
#define ENH_TIM0           ((ENHTIM_TypeDef        *) ENHANCED_TIMER0_REG_BASE)
#define ENH_TIM1           ((ENHTIM_TypeDef        *) ENHANCED_TIMER1_REG_BASE)
#define ENH_TIM2           ((ENHTIM_TypeDef        *) ENHANCED_TIMER2_REG_BASE)
#define ENH_TIM3           ((ENHTIM_TypeDef        *) ENHANCED_TIMER3_REG_BASE)
#define ENH_TIM4           ((ENHTIM_TypeDef        *) ENHANCED_TIMER4_REG_BASE)
#define ENH_TIM5           ((ENHTIM_TypeDef        *) ENHANCED_TIMER5_REG_BASE)
#define ENH_TIM6           ((ENHTIM_TypeDef        *) ENHANCED_TIMER6_REG_BASE)
#define ENH_TIM7           ((ENHTIM_TypeDef        *) ENHANCED_TIMER7_REG_BASE)
#define ENH_TIM_SHARE      ((ENHTIM_ShareTypeDef   *) ENHTIM_SHARE_REG_BASE)
#define ENH_TIM0_PWM       ((ENHPWM_TypeDef        *) ENHTIM0_PWM_REG_BASE)
#define ENH_TIM1_PWM       ((ENHPWM_TypeDef        *) ENHTIM1_PWM_REG_BASE)
#define ENH_TIM2_PWM       ((ENHPWM_TypeDef        *) ENHTIM2_PWM_REG_BASE)
#define ENH_TIM3_PWM       ((ENHPWM_TypeDef        *) ENHTIM3_PWM_REG_BASE)
#define ENH_TIM4_PWM       ((ENHPWM_TypeDef        *) ENHTIM4_PWM_REG_BASE)
#define ENH_TIM5_PWM       ((ENHPWM_TypeDef        *) ENHTIM5_PWM_REG_BASE)
#define ENH_TIM6_PWM       ((ENHPWM_TypeDef        *) ENHTIM6_PWM_REG_BASE)
#define ENH_TIM7_PWM       ((ENHPWM_TypeDef        *) ENHTIM7_PWM_REG_BASE)
#define ENH_TIM8_PWM       ((ENHPWM_TypeDef        *) ENHTIM8_PWM_REG_BASE)
#define ENHTIM_IP_VER      ((ENHTIM_IP_VER_TypeDef *) (ENHANCED_TIMER_REG_BASE+0X360))

/*============================================================================*
 *                         ENHTIM Private Defines
 *============================================================================*/
#define ENHTIM_CLK_CTRL      *((volatile uint32_t *)0x400E2174UL)

/*============================================================================*
 *                         ENHTIM Registers and Field Descriptions
 *============================================================================*/
/* 0x00
   31:0    R      Enhtimer_cur_cnt                            32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer_cur_cnt: 32;
    } b;
} ENHTIM_CUR_CNT_t;



/* 0x04
   31:0    R      Enhtimer_latch_cnt_0                        32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer_latch_cnt_0: 32;
    } b;
} ENHTIM_LATCH_CNT_0_t;



/* 0x08
   31:0    R      RSVD                        32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t reserved: 32;
    } b;
} ENHTIM_LATCH_CNT_1_t;



/* 0x0C
   31:0    R      RSVD                        32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t reserved: 32;
    } b;
} ENHTIM_LATCH_CNT_2_t;



/* 0x10
   1:0     R/W    Enhtimer_mode                               2'h0
   2       R/W    Enhtimer_PWM_polarity                       1'h0
   3       R/W    Enhtimer_PWM_output_en                      1'h0
   5:4     R/W    Enhtimer_latch_cnt_0_trig_mode              2'h0
   7:6     R/W    RSVD                                        2'h0
   9:8     R/W    RSVD                                        2'h0
   10      R/W    Enhtimer_Latch_cnt_0_en                     1'h0
   11      R/W    RSVD                                        1'h0
   12      R/W    RSVD                                        1'h0
   17:13   R/W    Enhtimer_latch_cnt_0_fifo_th                5'h1
   22:18   R/W    RSVD                                        5'h1
   27:23   R/W    RSVD                                        5'h1
   28      R/W    Enhtimer_dma_en                             1'h0
   29      R/W    Enhtimer_dma_mode                           1'h0
   31:30   R/W    Enhtimer_dma_target                         2'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer_mode: 2;
        __IO uint32_t Enhtimer_PWM_polarity: 1;
        __IO uint32_t Enhtimer_PWM_output_en: 1;
        __IO uint32_t Enhtimer_latch_cnt_0_trig_mode: 2;
        __IO uint32_t reserved_5: 2;
        __IO uint32_t reserved_4: 2;
        __IO uint32_t Enhtimer_Latch_cnt_0_en: 1;
        __IO uint32_t reserved_3: 1;
        __IO uint32_t reserved_2: 1;
        __IO uint32_t Enhtimer_latch_cnt_0_fifo_th: 5;
        __IO uint32_t reserved_1: 5;
        __IO uint32_t reserved_0: 5;
        __IO uint32_t Enhtimer_dma_en: 1;
        __IO uint32_t Enhtimer_dma_mode: 1;
        __IO uint32_t Enhtimer_dma_target: 2;
    } b;
} ENHTIM_CONFIGURE_t;



/* 0x14
   31:0    R/W    Enhtimer_max_cnt                            32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer_max_cnt: 32;
    } b;
} ENHTIM_MAX_CNT_t;



/* 0x18
   31:0    R/W    Enhtimer_ccr                                32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer_ccr: 32;
    } b;
} ENHTIM_CCR_t;



/* 0x1C
   31:0    R/W    Enhtimer_ccr_fifo_entry                     32'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer_ccr_fifo_entry: 32;
    } b;
} ENHTIM_CCR_FIFO_ENTRY_t;




/* 0x120
   0       R/W1C  Enhtimer0_latch_cnt_0_fifo_met_th           1'h0
   1       R/W1C  Enhtimer1_latch_cnt_0_fifo_met_th           1'h0
   2       R/W1C  Enhtimer2_latch_cnt_0_fifo_met_th           1'h0
   3       R/W1C  Enhtimer3_latch_cnt_0_fifo_met_th           1'h0
   4       R/W1C  Enhtimer4_latch_cnt_0_fifo_met_th           1'h0
   5       R/W1C  Enhtimer5_latch_cnt_0_fifo_met_th           1'h0
   6       R/W1C  Enhtimer6_latch_cnt_0_fifo_met_th           1'h0
   7       R/W1C  Enhtimer7_latch_cnt_0_fifo_met_th           1'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer0_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_met_th: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_met_th: 1;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM_LACTH_FIFO_TH_STATUS_t;



/* 0x124
   0       R/W1C  Enhtimerr0_latch_cnt_0_fifo_full            1'h0
   1       R      Enhtimer0_latch_cnt_0_fifo_empty            1'h1
   2       R/W1C  Enhtimer1_latch_cnt_0_fifo_full             1'h0
   3       R      Enhtimer1_latch_cnt_0_fifo_empty            1'h1
   4       R/W1C  Enhtimer2_latch_cnt_0_fifo_full             1'h0
   5       R      Enhtimer2_latch_cnt_0_fifo_empty            1'h1
   6       R/W1C  Enhtimer3_latch_cnt_0_fifo_full             1'h0
   7       R      Enhtimer3_latch_cnt_0_fifo_empty            1'h1
   8       R/W1C  Enhtimer4_latch_cnt_0_fifo_full             1'h0
   9       R      Enhtimer4_latch_cnt_0_fifo_empty            1'h1
   10      R/W1C  Enhtimer5_latch_cnt_0_fifo_full             1'h0
   11      R      Enhtimer5_latch_cnt_0_fifo_empty            1'h1
   12      R/W1C  Enhtimer6_latch_cnt_0_fifo_full             1'h0
   13      R      Enhtimer6_latch_cnt_0_fifo_empty            1'h1
   14      R/W1C  Enhtimer7_latch_cnt_0_fifo_full             1'h0
   15      R      Enhtimer7_latch_cnt_0_fifo_empty            1'h1
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimerr0_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer0_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer1_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer2_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer3_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer4_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer5_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer6_latch_cnt_0_fifo_empty: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_full: 1;
        __I uint32_t Enhtimer7_latch_cnt_0_fifo_empty: 1;
        __I uint32_t reserved_0: 16;
    } b;
} ENHTIM_LATCH_CNT_FIFO_STATUS_t;



/* 0x128
   0       R      Enhtimerr0_ccr_fifo_full                    1'h0
   1       R      Enhtimer0_ccr_fifo_empty                    1'h1
   2       R      Enhtimer1_ccr_fifo_full                     1'h0
   3       R      Enhtimer1_ccr_fifo_empty                    1'h1
   4       R      Enhtimer2_ccr_fifo_full                     1'h0
   5       R      Enhtimer2_ccr_fifo_empty                    1'h1
   6       R      Enhtimer3_ccr_fifo_full                     1'h0
   7       R      Enhtimer3_ccr_fifo_empty                    1'h1
   8       R      Enhtimer4_ccr_fifo_full                     1'h0
   9       R      Enhtimer4_ccr_fifo_empty                    1'h1
   10      R      Enhtimer5_ccr_fifo_full                     1'h0
   11      R      Enhtimer5_ccr_fifo_empty                    1'h1
   12      R      Enhtimer6_ccr_fifo_full                     1'h0
   13      R      Enhtimer6_ccr_fifo_empty                    1'h1
   14      R      Enhtimer7_ccr_fifo_full                     1'h0
   15      R      Enhtimer7_ccr_fifo_empty                    1'h1
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimerr0_ccr_fifo_full: 1;
        __I uint32_t Enhtimer0_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer1_ccr_fifo_full: 1;
        __I uint32_t Enhtimer1_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer2_ccr_fifo_full: 1;
        __I uint32_t Enhtimer2_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer3_ccr_fifo_full: 1;
        __I uint32_t Enhtimer3_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer4_ccr_fifo_full: 1;
        __I uint32_t Enhtimer4_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer5_ccr_fifo_full: 1;
        __I uint32_t Enhtimer5_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer6_ccr_fifo_full: 1;
        __I uint32_t Enhtimer6_ccr_fifo_empty: 1;
        __I uint32_t Enhtimer7_ccr_fifo_full: 1;
        __I uint32_t Enhtimer7_ccr_fifo_empty: 1;
        __I uint32_t reserved_0: 16;
    } b;
} ENHTIM_CCR_FIFO_STATUS_t;



/* 0x12C
   0       R/W1C  Enhtimer0_ccr_fifo_clr                      1'h0
   1       R/W1C  Enhtimer1_ccr_fifo_clr                      1'h0
   2       R/W1C  Enhtimer2_ccr_fifo_clr                      1'h0
   3       R/W1C  Enhtimer3_ccr_fifo_clr                      1'h0
   4       R/W1C  Enhtimer4_ccr_fifo_clr                      1'h0
   5       R/W1C  Enhtimer5_ccr_fifo_clr                      1'h0
   6       R/W1C  Enhtimer6_ccr_fifo_clr                      1'h0
   7       R/W1C  Enhtimer7_ccr_fifo_clr                      1'h0
   8       R/W1C  Enhtimer0_latch_cnt_0_fifo_clr              1'h0
   9       R/W1C  Enhtimer1_latch_cnt_0_fifo_clr              1'h0
   10      R/W1C  Enhtimer2_latch_cnt_0_fifo_clr              1'h0
   11      R/W1C  Enhtimer3_latch_cnt_0_fifo_clr              1'h0
   12      R/W1C  Enhtimer4_latch_cnt_0_fifo_clr              1'h0
   13      R/W1C  Enhtimer5_latch_cnt_0_fifo_clr              1'h0
   14      R/W1C  Enhtimer6_latch_cnt_0_fifo_clr              1'h0
   15      R/W1C  Enhtimer7_latch_cnt_0_fifo_clr              1'h0
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer0_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer1_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer2_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer3_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer4_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer5_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer6_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer7_ccr_fifo_clr: 1;
        __IO uint32_t Enhtimer0_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_clr: 1;
        __IO uint32_t reserved_0: 16;
    } b;
} ENHTIM_FIFO_CLR_t;



/* 0x130
   0       R/W    Enhtimer0_enable                            1'h0
   1       R/W    Enhtimer1_enable                            1'h0
   2       R/W    Enhtimer2_enable                            1'h0
   3       R/W    Enhtimer3_enable                            1'h0
   4       R/W    Enhtimer4_enable                            1'h0
   5       R/W    Enhtimer5_enable                            1'h0
   6       R/W    Enhtimer6_enable                            1'h0
   7       R/W    Enhtimer7_enable                            1'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer0_enable: 1;
        __IO uint32_t Enhtimer1_enable: 1;
        __IO uint32_t Enhtimer2_enable: 1;
        __IO uint32_t Enhtimer3_enable: 1;
        __IO uint32_t Enhtimer4_enable: 1;
        __IO uint32_t Enhtimer5_enable: 1;
        __IO uint32_t Enhtimer6_enable: 1;
        __IO uint32_t Enhtimer7_enable: 1;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM_CONTROL_t;



/* 0x134
   0       R/W    Enhtimer0_Interrupt_enable                  1'h0
   1       R/W    Enhtimer1_Interrupt_enable                  1'h0
   2       R/W    Enhtimer2_Interrupt_enable                  1'h0
   3       R/W    Enhtimer3_Interrupt_enable                  1'h0
   4       R/W    Enhtimer4_Interrupt_enable                  1'h0
   5       R/W    Enhtimer5_Interrupt_enable                  1'h0
   6       R/W    Enhtimer6_Interrupt_enable                  1'h0
   7       R/W    Enhtimer7_Interrupt_enable                  1'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer0_Interrupt_enable: 1;
        __IO uint32_t Enhtimer1_Interrupt_enable: 1;
        __IO uint32_t Enhtimer2_Interrupt_enable: 1;
        __IO uint32_t Enhtimer3_Interrupt_enable: 1;
        __IO uint32_t Enhtimer4_Interrupt_enable: 1;
        __IO uint32_t Enhtimer5_Interrupt_enable: 1;
        __IO uint32_t Enhtimer6_Interrupt_enable: 1;
        __IO uint32_t Enhtimer7_Interrupt_enable: 1;
        __IO uint32_t reserved_0: 24;
    } b;
} ENHTIM_INT_CONTROL_t;



/* 0x138
   0       R/W1C  Enhtimer0_Status                            1'h0
   1       R/W1C  Enhtimer1_Status                            1'h0
   2       R/W1C  Enhtimer2_Status                            1'h0
   3       R/W1C  Enhtimer3_Status                            1'h0
   4       R/W1C  Enhtimer4_Status                            1'h0
   5       R/W1C  Enhtimer5_Status                            1'h0
   6       R/W1C  Enhtimer6_Status                            1'h0
   7       R/W1C  Enhtimer7_Status                            1'h0
   8       R/W1C  Enhtimer0_latch_cnt_0_fifo_intr_status      1'h0
   9       R/W1C  Enhtimer1_latch_cnt_0_fifo_intr_status      1'h0
   10      R/W1C  Enhtimer2_latch_cnt_0_fifo_intr_status      1'h0
   11      R/W1C  Enhtimer3_latch_cnt_0_fifo_intr_status      1'h0
   12      R/W1C  Enhtimer4_latch_cnt_0_fifo_intr_status      1'h0
   13      R/W1C  Enhtimer5_latch_cnt_0_fifo_intr_status      1'h0
   14      R/W1C  Enhtimer6_latch_cnt_0_fifo_intr_status      1'h0
   15      R/W1C  Enhtimer7_latch_cnt_0_fifo_intr_status      1'h0
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t Enhtimer0_Status: 1;
        __IO uint32_t Enhtimer1_Status: 1;
        __IO uint32_t Enhtimer2_Status: 1;
        __IO uint32_t Enhtimer3_Status: 1;
        __IO uint32_t Enhtimer4_Status: 1;
        __IO uint32_t Enhtimer5_Status: 1;
        __IO uint32_t Enhtimer6_Status: 1;
        __IO uint32_t Enhtimer7_Status: 1;
        __IO uint32_t Enhtimer0_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_intr_status: 1;
        __IO uint32_t reserved_0: 16;
    } b;
} ENHTIM_STATUS_t;



/* 0x13C
   0       R      reg_timer_0_interrupt_masked                1'h0
   1       R      reg_timer_1_interrupt_masked                1'h0
   2       R      reg_timer_2_interrupt_masked                1'h0
   3       R      reg_timer_3_interrupt_masked                1'h0
   4       R      reg_timer_4_interrupt_masked                1'h0
   5       R      reg_timer_5_interrupt_masked                1'h0
   6       R      reg_timer_6_interrupt_masked                1'h0
   7       R      reg_timer_7_interrupt_masked                1'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t reg_timer_0_interrupt_masked: 1;
        __I uint32_t reg_timer_1_interrupt_masked: 1;
        __I uint32_t reg_timer_2_interrupt_masked: 1;
        __I uint32_t reg_timer_3_interrupt_masked: 1;
        __I uint32_t reg_timer_4_interrupt_masked: 1;
        __I uint32_t reg_timer_5_interrupt_masked: 1;
        __I uint32_t reg_timer_6_interrupt_masked: 1;
        __I uint32_t reg_timer_7_interrupt_masked: 1;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM_INT_STATUS_t;



/* 0x140
   7:0     R      RSVD                                        8'h0
   8       R/W    Enhtimer0_latch_cnt_0_fifo_full_intr_en     1'h0
   9       R/W    Enhtimer1_latch_cnt_0_fifo_full_intr_en     1'h0
   10      R/W    Enhtimer2_latch_cnt_0_fifo_full_intr_en     1'h0
   11      R/W    Enhtimer3_latch_cnt_0_fifo_full_intr_en     1'h0
   12      R/W    Enhtimer4_latch_cnt_0_fifo_full_intr_en     1'h0
   13      R/W    Enhtimer5_latch_cnt_0_fifo_full_intr_en     1'h0
   14      R/W    Enhtimer6_latch_cnt_0_fifo_full_intr_en     1'h0
   15      R/W    Enhtimer7_latch_cnt_0_fifo_full_intr_en     1'h0
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t reserved_16: 8;
        __IO uint32_t Enhtimer0_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_full_intr_en: 1;
        __IO uint32_t reserved_0: 16;
    } b;
} ENHTIM_LATCH_INT_CONTROL_0_t;



/* 0x148
   7:0     R      RSVD                                        8'h0
   8       R/W    Enhtimer0_latch_cnt_0_fifo_met_th_intr_en   1'h0
   9       R/W    Enhtimer1_latch_cnt_0_fifo_met_th_intr_en   1'h0
   10      R/W    Enhtimer2_latch_cnt_0_fifo_met_th_intr_en   1'h0
   11      R/W    Enhtimer3_latch_cnt_0_fifo_met_th_intr_en   1'h0
   12      R/W    Enhtimer4_latch_cnt_0_fifo_met_th_intr_en   1'h0
   13      R/W    Enhtimer5_latch_cnt_0_fifo_met_th_intr_en   1'h0
   14      R/W    Enhtimer6_latch_cnt_0_fifo_met_th_intr_en   1'h0
   15      R/W    Enhtimer7_latch_cnt_0_fifo_met_th_intr_en   1'h0
   31:16   R      RSVD                                        16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I  uint32_t reserved_1: 8;
        __IO uint32_t Enhtimer0_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer1_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer2_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer3_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer4_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer5_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer6_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t Enhtimer7_latch_cnt_0_fifo_met_th_intr_en: 1;
        __IO uint32_t reserved_0: 16;
    } b;
} ENHTIM_LATCH_INT_CONTROL_2_t;




/* 0x150
   7:0     R      Enhtimer0_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer0_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM0_LATCH_FIFO_DEPTH_t;



/* 0x154
   7:0     R      Enhtimer1_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer1_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM1_LATCH_FIFO_DEPTH_t;



/* 0x158
   7:0     R      Enhtimer2_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer2_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM2_LATCH_FIFO_DEPTH_t;



/* 0x15C
   7:0     R      Enhtimer3_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer3_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM3_LATCH_FIFO_DEPTH_t;



/* 0x160
   7:0     R      Enhtimer4_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer4_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM4_LATCH_FIFO_DEPTH_t;



/* 0x164
   7:0     R      Enhtimer5_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer5_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM5_LATCH_FIFO_DEPTH_t;



/* 0x168
   7:0     R      Enhtimer6_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer6_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM6_LATCH_FIFO_DEPTH_t;



/* 0x16C
   7:0     R      Enhtimer7_latch_cnt_0_fifo_depth            8'h0
   31:8    R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer7_latch_cnt_0_fifo_depth: 8;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM7_LATCH_FIFO_DEPTH_t;



/* 0x170
   0       R      Enhtimer0_toggle_state                      1'h0
   1       R      Enhtimer1_toggle_state                      1'h0
   2       R      Enhtimer2_toggle_state                      1'h0
   3       R      Enhtimer3_toggle_state                      1'h0
   4       R      Enhtimer4_toggle_state                      1'h0
   5       R      Enhtimer5_toggle_state                      1'h0
   6       R      Enhtimer6_toggle_state                      1'h0
   7       R      Enhtimer7_toggle_state                      1'h0
   31:24   R      RSVD                                        24'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t Enhtimer0_toggle_state: 1;
        __I uint32_t Enhtimer1_toggle_state: 1;
        __I uint32_t Enhtimer2_toggle_state: 1;
        __I uint32_t Enhtimer3_toggle_state: 1;
        __I uint32_t Enhtimer4_toggle_state: 1;
        __I uint32_t Enhtimer5_toggle_state: 1;
        __I uint32_t Enhtimer6_toggle_state: 1;
        __I uint32_t Enhtimer7_toggle_state: 1;
        __I uint32_t reserved_0: 24;
    } b;
} ENHTIM_TOGGLE_STATE_t;



/* 0x270
   7:0     R/W    enhtimer_pwm_0_dead_zone_size       8'h0
   8       R/W    enhtimer_pwm_0_emg_stop             1'h0
   9       R/W    enhtimer_pwm_0_stop_state[0]        1'h0
   10      R/W    enhtimer_pwm_0_stop_state[1]        1'h0
   11      R/W    enhtimer_pwm_0_dummy_b11            1'h0
   12      R/W    enhtimer_pwm_0_dead_zone_en         1'h0
   13      R/W    enhtimer_pwm_0_pwm_pn_invserse_sel  1'h0
   14      R/W    enhtimer_pwm_0_dummy_b14            1'h0
   15      R/W    enhtimer_pwm_0_dummy_b15            1'h0
   31:16   R      RSVD                                16'h0
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __IO uint32_t enhtimer_pwm_dead_zone_size: 8;
        __IO uint32_t enhtimer_pwm_emg_stop: 1;
        __IO uint32_t enhtimer_pwm_stop_state_0: 1;
        __IO uint32_t enhtimer_pwm_stop_state_1: 1;
        __IO uint32_t enhtimer_pwm_dummy_b11: 1;
        __IO uint32_t enhtimer_pwm_dead_zone_en: 1;
        __IO uint32_t enhtimer_pwm_pwm_pn_invserse_sel: 1;
        __IO uint32_t enhtimer_pwm_dummy_b14: 1;
        __IO uint32_t enhtimer_pwm_dummy_b15: 1;
        __I uint32_t reserved_0: 16;
    } b;
} ENHTIMER_PWM_WRAP_CFG_t;



/* 0x360
   31:0   R      timer_ip_ver                          32'h2108162a
*/
typedef union
{
    uint32_t d32;
    uint8_t d8[4];
    struct
    {
        __I uint32_t timer_ip_ver: 32;
    } b;
} ENHTIM_IP_VER_t;


/* ================================================================================ */
/* ================               ENH-TIMER  Constants             ================ */
/* ================================================================================ */
/** \defgroup ENHTIM_Exported_Constants ENHTIM Exported Constants
  * \brief
  * \{
  */

/**
 * \brief    ENHTIM_Clock_Source ENHTIM Clock Source
 *
 * \ingroup  ENHTIM_Exported_Types
 */
typedef enum
{
    ENHTIM_SOURCE_CLOCK_40M = 0x00,
    ENHTIM_SOURCE_CLOCK_32K = 0x04,
    ENHTIM_SOURCE_CLOCK_PLL2 = 0x02,
    ENHTIM_SOURCE_CLOCK_PLL1 = 0x01,
} ENHTIM_CLK_SOURCE_T;

/** \} */
#define IS_ENHTIM_CLK_SOURCE(src) (((src) == ENHTIM_SOURCE_CLOCK_40M) || \
                                   ((src) == ENHTIM_SOURCE_CLOCK_32K)|| \\
                                   ((src) == ENHTIM_SOURCE_CLOCK_PLL2)|| \\
                                   ((src) == ENHTIM_SOURCE_CLOCK_PLL1))

/** End of ENHTIM_Exported_Constants
  * \}
  */


#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* RTL_ENHTIM_DEF_H */
