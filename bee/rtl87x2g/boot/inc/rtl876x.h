
/**
 ******************************************************************************************
 *       Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
 ******************************************************************************************
 * @file    rtl876x.h
 * @brief   CMSIS Cortex-M4 Peripheral Access Layer Header File for
 *          RTL876X from Realtek Semiconductor.
 * @date    2021.10.25
 * @version v1.0
 * @date    25. Oct. 2021
 * @note    Generated with SVDConv Vx.xxp
 *          from CMSIS SVD File 'RTL876X.xml' Version x.xC.
 * @par     Copyright (c) 2021 Realtek Semiconductor. All Rights Reserved.
 *          The information contained herein is property of Realtek Semiconductor.
 *          Terms and conditions of usage are described in detail in Realtek
 *          EMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *          Licensees are granted free, non-transferable use of the information. NO
 *          WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 *          the file.
 ******************************************************************************************
 * @attention
 * <h2><center>&copy; COPYRIGHT 2021 Realtek Semiconductor Corporation</center></h2>
 ******************************************************************************************
 */

#ifndef RTL876X_H
#define RTL876X_H

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup RTL876X RTL876X
  * @brief    CMSIS Cortex-M33 peripheral access layer header file for
  *           RTL876X from Realtek Semiconductor.
  * @{
  */


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */
/** @defgroup Configuration_of_CMSIS Configuration of CMSIS
  * @brief   Configuration of the armv8m mainline Processor and Core Peripherals
  * @{
  */
/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __ARMv8MML_REV            0x0001U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __FPU_DP                  0U        /* single precision FPU */
#define __DSP_PRESENT             1U        /* DSP extension present */
#define __ICACHE_PRESENT          1U
#define __DCACHE_PRESENT          1U
/** @} */ /* End of group Configuration_of_CMSIS */

/* ================================================================================ */
/*                                       Types                                      */
/* ================================================================================ */
/** @defgroup RTL876x_Exported_types RTL876X Exported types
 * @{
 */
//compatible define
#define UART                            UART0

/** Brief Interrupt Number Definition */
typedef enum IRQn
{
    /* -------------------  Cortex-M4 Processor Exceptions Numbers  ------------------- */
    NonMaskableInt_IRQn           = -14,      /**< 2 Non Maskable Interrupt */
    HardFault_IRQn                = -13,      /**< 3 HardFault Interrupt */
    MemoryManagement_IRQn         = -12,      /**< 4 Memory Management Interrupt */
    BusFault_IRQn                 = -11,      /**< 5 Bus Fault Interrupt */
    UsageFault_IRQn               = -10,      /**< 6 Usage Fault Interrupt */
    SecureFault_IRQn              =  -9,      /**< 7 Secure Fault Interrupt */
    SVCall_IRQn                   =  -5,      /**< 11 SV Call Interrupt */
    DebugMonitor_IRQn             =  -4,      /**< 12 Debug Monitor Interrupt */
    PendSV_IRQn                   =  -2,      /**< 14 Pend SV Interrupt */
    SysTick_IRQn                  =  -1,      /**< 15 System Tick Interrupt */

    /* INT_NUMBER = 95 + 16 */
    System_IRQn = 0,
    WDT_IRQn,
    RXI300_IRQn,
    RXI300_SEC_IRQn,
    Zigbee_IRQn,
    BTMAC_IRQn,
    Peripheral_IRQn,
    RSVD4_IRQn,
    RTC_IRQn,
    GPIO_A0_IRQn,
    GPIO_A1_IRQn,
    GPIO_A_2_7_IRQn,
    GPIO_A_8_15_IRQn,
    GPIO_A_16_23_IRQn,
    GPIO_A_24_31_IRQn,
    GPIO_B_0_7_IRQn,
    GPIO_B_8_15_IRQn,
    GPIO_B_16_23_IRQn,
    GPIO_B_24_31_IRQn,
    GDMA0_Channel0_IRQn,
    GDMA0_Channel1_IRQn,
    GDMA0_Channel2_IRQn,
    GDMA0_Channel3_IRQn,
    GDMA0_Channel4_IRQn,
    GDMA0_Channel5_IRQn,
    GDMA0_Channel6_IRQn,
    GDMA0_Channel7_IRQn,
    GDMA0_Channel8_IRQn,
    GDMA0_Channel9_IRQn,
    PPE_IRQn,
    I2C0_IRQn,
    I2C1_IRQn,
    I2C2_IRQn,
    I2C3_IRQn,
    UART0_IRQn,
    UART1_IRQn,
    UART2_IRQn,
    UART3_IRQn,
    UART4_IRQn,
    UART5_IRQn,
    SPI_3Wire_IRQn,
    SPI0_IRQn,
    SPI1_IRQn,
    SPI_Slave_IRQn,
    Timer0_IRQn,
    Timer1_IRQn,
    Timer2_IRQn,
    Timer3_IRQn,
    Timer4_IRQn,
    Timer5_IRQn,
    Timer6_IRQn,
    Timer7_IRQn,
    Enhanced_Timer0_IRQn,
    Enhanced_Timer1_IRQn,
    Enhanced_Timer2_IRQn,
    Enhanced_Timer3_IRQn,
    ADC_24bit_IRQn,
    SAR_ADC_IRQn,
    KEYSCAN_IRQn,
    AON_QDEC_IRQn,
    IR_IRQn,
    SDHC_IRQn,
    ISO7816_IRQn,
    Display_IRQn,
    SPORT0_RX_IRQn,
    SPORT0_TX_IRQn,
    SPORT1_RX_IRQn,
    SPORT1_TX_IRQn,
    SHA256_IRQn,
    Public_Key_Engine_IRQn,
    Flash_SEC_IRQn,
    SegCom_CTL_IRQn,
    CAN_IRQn,
    ETH_IRQn,
    IMDC_IRQn,
    Slave_Port_Monitor_IRQn,
    PTA_Mailbox_IRQn,
    USB_IRQn,
    USB_SUSPEND_N_IRQn,
    USB_Endp_Multi_Proc_IRQn,
    USB_IN_EP_0_IRQn,
    USB_IN_EP_1_IRQn,
    USB_IN_EP_2_IRQn,
    USB_IN_EP_3_IRQn,
    USB_IN_EP_4_IRQn,
    USB_IN_EP_5_IRQn,
    USB_OUT_EP_0_IRQn,
    USB_OUT_EP_1_IRQn,
    USB_OUT_EP_2_IRQn,
    USB_OUT_EP_3_IRQn,
    USB_OUT_EP_4_IRQn,
    USB_OUT_EP_5_IRQn,
    USB_Sof_IRQn,
    TMETER_IRQn,
    PF_RTC_IRQn,
    BTMAC_WRAP_AROUND_IRQn,

    /* second level interrupt (BTMAC_IRQn), not directly connect to NVIC */
    Timer_A0_A1_IRQn,
    BT_Bluewiz_IRQn,
    RSVD5_IRQn,
    BT_BZ_DMA_IRQn,
    Proprietary_protocol_IRQn,
    RSVD6_IRQn,

    /* second level interrupt (Peripheral_IRQn) */
    SPIC0_IRQn,
    SPIC1_IRQn,
    SPIC2_IRQn,
    TRNG_IRQn,
    LPCOMP_IRQn,
    SPI_PHY1_IRQn,
    RSVD7_IRQn,
} IRQn_Type, *PIRQn_Type;

#define FIRST_LEVEL_First_IRQn   System_IRQn
#define FIRST_LEVEL_Last_IRQn    PF_RTC_IRQn

#define Peripheral_First_IRQn    SPIC0_IRQn
#define Peripheral_Last_IRQn     RSVD7_IRQn

#define BTMAC_First_IRQn         Timer_A0_A1_IRQn
#define BTMAC_Last_IRQn          RSVD6_IRQn

#define GPIOA0_IRQn              GPIO_A0_IRQn
#define GPIOA1_IRQn              GPIO_A1_IRQn
#define GPIOA2_IRQn              GPIO_A_2_7_IRQn
#define GPIOA3_IRQn              GPIO_A_2_7_IRQn
#define GPIOA4_IRQn              GPIO_A_2_7_IRQn
#define GPIOA5_IRQn              GPIO_A_2_7_IRQn
#define GPIOA6_IRQn              GPIO_A_2_7_IRQn
#define GPIOA7_IRQn              GPIO_A_2_7_IRQn
#define GPIOA8_IRQn              GPIO_A_8_15_IRQn
#define GPIOA9_IRQn              GPIO_A_8_15_IRQn
#define GPIOA10_IRQn             GPIO_A_8_15_IRQn
#define GPIOA11_IRQn             GPIO_A_8_15_IRQn
#define GPIOA12_IRQn             GPIO_A_8_15_IRQn
#define GPIOA13_IRQn             GPIO_A_8_15_IRQn
#define GPIOA14_IRQn             GPIO_A_8_15_IRQn
#define GPIOA15_IRQn             GPIO_A_8_15_IRQn
#define GPIOA16_IRQn             GPIO_A_16_23_IRQn
#define GPIOA17_IRQn             GPIO_A_16_23_IRQn
#define GPIOA18_IRQn             GPIO_A_16_23_IRQn
#define GPIOA19_IRQn             GPIO_A_16_23_IRQn
#define GPIOA20_IRQn             GPIO_A_16_23_IRQn
#define GPIOA21_IRQn             GPIO_A_16_23_IRQn
#define GPIOA22_IRQn             GPIO_A_16_23_IRQn
#define GPIOA23_IRQn             GPIO_A_16_23_IRQn
#define GPIOA24_IRQn             GPIO_A_24_31_IRQn
#define GPIOA25_IRQn             GPIO_A_24_31_IRQn
#define GPIOA26_IRQn             GPIO_A_24_31_IRQn
#define GPIOA27_IRQn             GPIO_A_24_31_IRQn
#define GPIOA28_IRQn             GPIO_A_24_31_IRQn
#define GPIOA29_IRQn             GPIO_A_24_31_IRQn
#define GPIOA30_IRQn             GPIO_A_24_31_IRQn
#define GPIOA31_IRQn             GPIO_A_24_31_IRQn

#define GPIOB0_IRQn              GPIO_B_0_7_IRQn
#define GPIOB1_IRQn              GPIO_B_0_7_IRQn
#define GPIOB2_IRQn              GPIO_B_0_7_IRQn
#define GPIOB3_IRQn              GPIO_B_0_7_IRQn
#define GPIOB4_IRQn              GPIO_B_0_7_IRQn
#define GPIOB5_IRQn              GPIO_B_0_7_IRQn
#define GPIOB6_IRQn              GPIO_B_0_7_IRQn
#define GPIOB7_IRQn              GPIO_B_0_7_IRQn
#define GPIOB8_IRQn              GPIO_B_8_15_IRQn
#define GPIOB9_IRQn              GPIO_B_8_15_IRQn
#define GPIOB10_IRQn             GPIO_B_8_15_IRQn
#define GPIOB11_IRQn             GPIO_B_8_15_IRQn
#define GPIOB12_IRQn             GPIO_B_8_15_IRQn
#define GPIOB13_IRQn             GPIO_B_8_15_IRQn
#define GPIOB14_IRQn             GPIO_B_8_15_IRQn
#define GPIOB15_IRQn             GPIO_B_8_15_IRQn
#define GPIOB16_IRQn             GPIO_B_16_23_IRQn
#define GPIOB17_IRQn             GPIO_B_16_23_IRQn
#define GPIOB18_IRQn             GPIO_B_16_23_IRQn
#define GPIOB19_IRQn             GPIO_B_16_23_IRQn
#define GPIOB20_IRQn             GPIO_B_16_23_IRQn
#define GPIOB21_IRQn             GPIO_B_16_23_IRQn
#define GPIOB22_IRQn             GPIO_B_16_23_IRQn
#define GPIOB23_IRQn             GPIO_B_16_23_IRQn
#define GPIOB24_IRQn             GPIO_B_24_31_IRQn
#define GPIOB25_IRQn             GPIO_B_24_31_IRQn
#define GPIOB26_IRQn             GPIO_B_24_31_IRQn
#define GPIOB27_IRQn             GPIO_B_24_31_IRQn
#define GPIOB28_IRQn             GPIO_B_24_31_IRQn
#define GPIOB29_IRQn             GPIO_B_24_31_IRQn
#define GPIOB30_IRQn             GPIO_B_24_31_IRQn
#define GPIOB31_IRQn             GPIO_B_24_31_IRQn

/** @} */ /* End of group RTL876x_Exported_types */

/*============================================================================*
 *                               Header Files
*============================================================================*/
#include "core_cm55.h"                       /* Processor and core peripherals */

/* ================================================================================ */
/* ================                      Types                     ================ */
/* ================================================================================ */
/** @addtogroup RTL876x_Exported_types RTL876X Exported types
  * @{
  */

typedef enum
{
    RESET = 0,
    SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))
//typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/** @} */ /* End of group RTL876x_Exported_types */


/* ================================================================================ */
/* ================    Peripheral Block Control Peripheral Clock   ================ */
/* ================================================================================ */

/**
  * @brief Peripheral Block Control Peripheral Clock. (PERI_BLKCTRL_PERI_CLK), PERIBLKCTRL_PERICLK_REG_BASE
  */
/* reference: Bee4_PERI-ON_20221017_v2.xlsx */
typedef struct
{
    /* 0x300        0x4000_2300
        3:0     R/W    r_spic0_div_sel                 4'h0
        4       R/W    r_spic0_div_en                  1'h0
        5       R/W    r_spic0_clk_src_en              1'h1
        6       R/W    RSVD                            1'h0
        7       R/W    RSVD                            1'h0
        8       R/W    r_spic0_mux_1_clk_cg_en         1'h1
        9       R/W    r_spic0_clk_src_sel0            1'h0
        10      R/W    r_spic0_clk_src_sel1            1'h0
        11      R/W    RSVD                            1'h0
        15:12   R/W    RSVD                            4'h0
        17:16   R/W    r_flash0_phy_clk_sel            2'h0
        18      R/W    r_flash0_clk_inv_en             1'b0
        26:19   R/W    r_pon_dlysel_spic0              8'h0
        27      R/W    spic0_phy_func_en               1'h0
        28      R/W    spic0_phy_str_en                1'h1
        29      R/W    RSVD                            1'h0
        30      R/W    spic0_ck_en                     1'h0
        31      R/W    spic0_func_en                   1'h0
    */
    union
    {
        __IO uint32_t REG_PERI_SPIC0_CTL;
        struct
        {
            __IO uint32_t r_spic0_div_sel: 4;
            __IO uint32_t r_spic0_div_en: 1;
            __IO uint32_t r_spic0_clk_src_en: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_spic0_mux_1_clk_cg_en: 1;
            __IO uint32_t r_spic0_clk_src_sel0: 1;
            __IO uint32_t r_spic0_clk_src_sel1: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 4;
            __IO uint32_t r_flash0_phy_clk_sel: 2;
            __IO uint32_t r_flash0_clk_inv_en: 1;
            __IO uint32_t r_pon_dlysel_spic0: 8;
            __IO uint32_t spic0_phy_func_en: 1;
            __IO uint32_t spic0_phy_str_en: 1;
            __IO uint32_t RESERVED_0: 1;
            __IO uint32_t spic0_ck_en: 1;
            __IO uint32_t spic0_func_en: 1;
        } BITS_300;
    } u_300;

    /* 0x304        0x4000_2304
        3:0     R/W    r_spic1_div_sel                 4'h0
        4       R/W    r_spic1_div_en                  1'h0
        5       R/W    r_spic1_clk_src_en              1'h1
        6       R/W    RSVD                            1'h0
        7       R/W    RSVD                            1'h0
        8       R/W    r_spic1_mux_1_clk_cg_en         1'h0
        9       R/W    r_spic1_clk_src_sel0            1'h0
        10      R/W    r_spic1_clk_src_sel1            1'h0
        11      R/W    RSVD                            1'h0
        15:12   R/W    RSVD                            4'h0
        17:16   R/W    r_spic1_phy_clk_sel             2'h0
        18      R/W    r_spic1_clk_inv_en              1'b0
        26:19   R/W    r_pon_dlysel_spic1              8'h0
        27      R/W    spic1_phy_func_en               1'h0
        28      R/W    spic1_phy_str_en                1'h0
        29      R/W    spic1_phy_apb_ck_en             1'h0
        30      R/W    spic1_ck_en                     1'h0
        31      R/W    spic1_func_en                   1'h0
    */
    union
    {
        __IO uint32_t REG_PERI_SPIC1_CTL;
        struct
        {
            __IO uint32_t r_spic1_div_sel: 4;
            __IO uint32_t r_spic1_div_en: 1;
            __IO uint32_t r_spic1_clk_src_en: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t r_spic1_mux_1_clk_cg_en: 1;
            __IO uint32_t r_spic1_clk_src_sel0: 1;
            __IO uint32_t r_spic1_clk_src_sel1: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 4;
            __IO uint32_t r_spic1_phy_clk_sel: 2;
            __IO uint32_t r_spic1_clk_inv_en: 1;
            __IO uint32_t r_pon_dlysel_spic1: 8;
            __IO uint32_t spic1_phy_func_en: 1;
            __IO uint32_t spic1_phy_str_en: 1;
            __IO uint32_t spic1_phy_apb_ck_en: 1;
            __IO uint32_t spic1_ck_en: 1;
            __IO uint32_t spic1_func_en: 1;
        } BITS_304;
    } u_304;

    /* 0x308        0x4000_2308
        3:0     R/W    r_spic2_div_sel                 4'h0
        4       R/W    r_spic2_div_en                  1'h0
        5       R/W    r_spic2_clk_src_en              1'h1
        6       R/W    RSVD                            1'h0
        7       R/W    RSVD                            1'h0
        8       R/W    r_spic2_mux_1_clk_cg_en         1'h0
        9       R/W    r_spic2_clk_src_sel0            1'h0
        10      R/W    r_spic2_clk_src_sel1            1'h0
        11      R/W    RSVD                            1'h0
        15:12   R/W    RSVD                            4'h0
        17:16   R/W    r_spic2_phy_clk_sel             2'h0
        18      R/W    r_spic2_clk_inv_en              1'b0
        26:19   R/W    r_pon_dlysel_spic2              8'h0
        27      R/W    spic2_phy_func_en               1'h0
        28      R/W    spic2_phy_str_en                1'h0
        29      R/W    RSVD                            1'h0
        30      R/W    spic2_ck_en                     1'h0
        31      R/W    spic2_func_en                   1'h0
    */
    union
    {
        __IO uint32_t REG_PERI_SPIC2_CTL;
        struct
        {
            __IO uint32_t r_spic2_div_sel: 4;
            __IO uint32_t r_spic2_div_en: 1;
            __IO uint32_t r_spic2_clk_src_en: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_spic2_mux_1_clk_cg_en: 1;
            __IO uint32_t r_spic2_clk_src_sel0: 1;
            __IO uint32_t r_spic2_clk_src_sel1: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 4;
            __IO uint32_t r_spic2_phy_clk_sel: 2;
            __IO uint32_t r_spic2_clk_inv_en: 1;
            __IO uint32_t r_pon_dlysel_spic2: 8;
            __IO uint32_t spic2_phy_func_en: 1;
            __IO uint32_t spic2_phy_str_en: 1;
            __IO uint32_t RESERVED_0: 1;
            __IO uint32_t spic2_ck_en: 1;
            __IO uint32_t spic2_func_en: 1;
        } BITS_308;
    } u_308;

    /* 0x30C        0x4000_230c
        0       R/W    gdma0_func_en                   1'h0
        1       R/W    gdma0_ck_en                     1'h0
        31:2    R/W    RSVD                            30'h0
    */
    union
    {
        __IO uint32_t REG_DMA_CTRL0;
        struct
        {
            __IO uint32_t gdma0_func_en: 1;
            __IO uint32_t gdma0_ck_en: 1;
            __IO uint32_t RESERVED_0: 30;
        } BITS_30C;
    } u_30C;

    /* 0x310        0x4000_2310
        0       R/W    spi0_func_en                    1'h0
        1       R/W    spi0_ck_en                      1'h0
        2       R/W    spi0_div_en                     1'h0
        5:3     R/W    spi0_div_sel                    3'b000
        6       R/W    spi0_brg_en                     1'h0
        7       R/W    spi0_hs_ck_en                   1'h0
        8       R/W    spi1_func_en                    1'h0
        9       R/W    spi1_ck_en                      1'h0
        10      R/W    spi1_div_en                     1'h0
        13:11   R/W    spi1_div_sel                    3'b000
        14      R/W    spi1_brg_en                     1'h0
        15      R/W    PON_SPI0_MST                    1'h0
        16      R/W    spi0_s_func_en                  1'h0
        17      R/W    spi0_s_ck_en                    1'h0
        18      R/W    spi0_s_div_en                   1'h0
        21:19   R/W    spi0_s_div_sel                  3'b000
        22      R/W    RSVD                            1'h0
        23      R/W    RSVD                            1'h0
        24      R/W    spi0_src_clk_sel0               1'h0
        25      R/W    spi0_src_clk_sel1               1'h0
        26      R/W    spi0_s_src_clk_sel0             1'h0
        27      R/W    spi0_s_src_clk_sel1             1'h0
        28      R/W    spi0_mux_clk_cg_en              1'h0
        29      R/W    spi0_s_mux_clk_cg_en            1'h0
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_SPI_PERI_CTL0;
        struct
        {
            __IO uint32_t spi0_func_en: 1;
            __IO uint32_t spi0_ck_en: 1;
            __IO uint32_t spi0_div_en: 1;
            __IO uint32_t spi0_div_sel: 3;
            __IO uint32_t spi0_brg_en: 1;
            __IO uint32_t spi0_hs_ck_en: 1;
            __IO uint32_t spi1_func_en: 1;
            __IO uint32_t spi1_ck_en: 1;
            __IO uint32_t spi1_div_en: 1;
            __IO uint32_t spi1_div_sel: 3;
            __IO uint32_t spi1_brg_en: 1;
            __IO uint32_t PON_SPI0_MST: 1;
            __IO uint32_t spi0_s_func_en: 1;
            __IO uint32_t spi0_s_ck_en: 1;
            __IO uint32_t spi0_s_div_en: 1;
            __IO uint32_t spi0_s_div_sel: 3;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t spi0_src_clk_sel0: 1;
            __IO uint32_t spi0_src_clk_sel1: 1;
            __IO uint32_t spi0_s_src_clk_sel0: 1;
            __IO uint32_t spi0_s_src_clk_sel1: 1;
            __IO uint32_t spi0_mux_clk_cg_en: 1;
            __IO uint32_t spi0_s_mux_clk_cg_en: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_310;
    } u_310;

    /* 0x314        0x4000_2314
        0       R/W    i2c0_func_en                    1'h0
        1       R/W    i2c0_ck_en                      1'h0
        2       R/W    i2c0_div_en                     1'h0
        5:3     R/W    i2c0_div_sel                    3'b000
        7:6     R/W    RSVD                            2'h0
        8       R/W    i2c1_func_en                    1'h0
        9       R/W    i2c1_ck_en                      1'h0
        10      R/W    i2c1_div_en                     1'h0
        13:11   R/W    i2c1_div_sel                    3'b000
        15:14   R/W    RSVD                            2'h0
        16      R/W    i2c2_func_en                    1'h0
        17      R/W    i2c2_ck_en                      1'h0
        18      R/W    i2c2_div_en                     1'h0
        21:19   R/W    i2c2_div_sel                    3'b000
        23:22   R/W    RSVD                            2'h0
        24      R/W    i2c3_func_en                    1'h0
        25      R/W    i2c3_ck_en                      1'h0
        26      R/W    i2c3_div_en                     1'h0
        29:27   R/W    i2c3_div_sel                    3'b000
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_I2C_PERI_CTL0;
        struct
        {
            __IO uint32_t i2c0_func_en: 1;
            __IO uint32_t i2c0_ck_en: 1;
            __IO uint32_t i2c0_div_en: 1;
            __IO uint32_t i2c0_div_sel: 3;
            __IO uint32_t RESERVED_3: 2;
            __IO uint32_t i2c1_func_en: 1;
            __IO uint32_t i2c1_ck_en: 1;
            __IO uint32_t i2c1_div_en: 1;
            __IO uint32_t i2c1_div_sel: 3;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t i2c2_func_en: 1;
            __IO uint32_t i2c2_ck_en: 1;
            __IO uint32_t i2c2_div_en: 1;
            __IO uint32_t i2c2_div_sel: 3;
            __IO uint32_t RESERVED_1: 2;
            __IO uint32_t i2c3_func_en: 1;
            __IO uint32_t i2c3_ck_en: 1;
            __IO uint32_t i2c3_div_en: 1;
            __IO uint32_t i2c3_div_sel: 3;
            __IO uint32_t RESERVED_0: 2;
        } BITS_314;
    } u_314;

    /* 0x318        0x4000_2318
        0       R/W    r_PMUX_1_WIRE_UART0_EN          1'h0
        1       R/W    rtk_uart0_func_en               1'h0
        2       R/W    rtk_uart0_ck_en                 1'h0
        3       R/W    rtk_uart0_div_en                1'h0
        6:4     R/W    rtk_uart0_div_sel               3'b000
        7       R/W    RSVD                            1'h0
        8       R/W    r_PMUX_1_WIRE_UART1_EN          1'h0
        9       R/W    rtk_uart1_func_en               1'h0
        10      R/W    rtk_uart1_ck_en                 1'h0
        11      R/W    rtk_uart1_div_en                1'h0
        14:12   R/W    rtk_uart1_div_sel               3'b000
        15      R/W    RSVD                            1'h0
        16      R/W    r_PMUX_1_WIRE_UART2_EN          1'h0
        17      R/W    rtk_uart2_func_en               1'h0
        18      R/W    rtk_uart2_ck_en                 1'h0
        19      R/W    rtk_uart2_div_en                1'h0
        22:20   R/W    rtk_uart2_div_sel               3'b000
        23      R/W    RSVD                            1'h0
        24      R/W    r_PMUX_1_WIRE_UART3_EN          1'h0
        25      R/W    rtk_uart3_func_en               1'h0
        26      R/W    rtk_uart3_ck_en                 1'h0
        27      R/W    rtk_uart3_div_en                1'h0
        30:28   R/W    rtk_uart3_div_sel               3'b000
        31      R/W    RSVD                            1'h0
    */
    union
    {
        __IO uint32_t REG_UART_PERI_CTL0;
        struct
        {
            __IO uint32_t r_PMUX_1_WIRE_UART0_EN: 1;
            __IO uint32_t rtk_uart0_func_en: 1;
            __IO uint32_t rtk_uart0_ck_en: 1;
            __IO uint32_t rtk_uart0_div_en: 1;
            __IO uint32_t rtk_uart0_div_sel: 3;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_PMUX_1_WIRE_UART1_EN: 1;
            __IO uint32_t rtk_uart1_func_en: 1;
            __IO uint32_t rtk_uart1_ck_en: 1;
            __IO uint32_t rtk_uart1_div_en: 1;
            __IO uint32_t rtk_uart1_div_sel: 3;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t r_PMUX_1_WIRE_UART2_EN: 1;
            __IO uint32_t rtk_uart2_func_en: 1;
            __IO uint32_t rtk_uart2_ck_en: 1;
            __IO uint32_t rtk_uart2_div_en: 1;
            __IO uint32_t rtk_uart2_div_sel: 3;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t r_PMUX_1_WIRE_UART3_EN: 1;
            __IO uint32_t rtk_uart3_func_en: 1;
            __IO uint32_t rtk_uart3_ck_en: 1;
            __IO uint32_t rtk_uart3_div_en: 1;
            __IO uint32_t rtk_uart3_div_sel: 3;
            __IO uint32_t RESERVED_0: 1;
        } BITS_318;
    } u_318;

    /* 0x31C        0x4000_231c
        0       R/W    auxadc_func_en                  1'h0
        1       R/W    auxadc_ck_en                    1'h0
        2       R/W    adc24b_func_en                  1'h0
        3       R/W    adc24b_ck_en                    1'h0
        4       R/W    RSVD                            1'h0
        5       R/W    RSVD                            1'h0
        6       R/W    keyscan_func_en                 1'h0
        7       R/W    keyscan_ck_en                   1'h0
        8       R/W    RSVD                            1'h0
        9       R/W    RSVD                            1'h0
        10      R/W    ppe_func_en                     1'h0
        11      R/W    ppe_ck_en                       1'h0
        12      R/W    gmac_func_en                    1'h0
        13      R/W    RSVD                            1'h0
        14      R/W    spi3w_func_en                   1'h0
        15      R/W    spi3w_ck_en                     1'h0
        16      R/W    RSVD                            1'h0
        17      R/W    RSVD                            1'h0
        18      R/W    segcom_func_en                  1'h0
        19      R/W    segcom_ck_en                    1'h0
        20      R/W    bt_mac_func_en                  1'h1
        21      R/W    bt_mac_ck_en                    1'h1
        22      R/W    bt_phy_func_en                  1'h0
        23      R/W    bt_phy_ck_en                    1'h0
        24      R/W    zb_mac_func_en                  1'h0
        25      R/W    zb_mac_ck_en                    1'h0
        26      R/W    bt_vendor_ck_en                 1'h1
        27      R/W    bt_cal32k_ck_en                 1'h0
        28      R/W    pdck_func_en                    1'h0
        29      R/W    pdck_ck_en                      1'h0
        30      R/W    aac_xtal_func_en                1'h0
        31      R/W    aac_xtal_ck_en                  1'h0
    */
    union
    {
        __IO uint32_t REG_GENERAL_PERI_CTL0;
        struct
        {
            __IO uint32_t auxadc_func_en: 1;
            __IO uint32_t auxadc_ck_en: 1;
            __IO uint32_t adc24b_func_en: 1;
            __IO uint32_t adc24b_ck_en: 1;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t keyscan_func_en: 1;
            __IO uint32_t keyscan_ck_en: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t ppe_func_en: 1;
            __IO uint32_t ppe_ck_en: 1;
            __IO uint32_t gmac_func_en: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t spi3w_func_en: 1;
            __IO uint32_t spi3w_ck_en: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 1;
            __IO uint32_t segcom_func_en: 1;
            __IO uint32_t segcom_ck_en: 1;
            __IO uint32_t bt_mac_func_en: 1;
            __IO uint32_t bt_mac_ck_en: 1;
            __IO uint32_t bt_phy_func_en: 1;
            __IO uint32_t bt_phy_ck_en: 1;
            __IO uint32_t zb_mac_func_en: 1;
            __IO uint32_t zb_mac_ck_en: 1;
            __IO uint32_t bt_vendor_ck_en: 1;
            __IO uint32_t bt_cal32k_ck_en: 1;
            __IO uint32_t pdck_func_en: 1;
            __IO uint32_t pdck_ck_en: 1;
            __IO uint32_t aac_xtal_func_en: 1;
            __IO uint32_t aac_xtal_ck_en: 1;
        } BITS_31C;
    } u_31C;

    /* 0x320        0x4000_2320
        0       R/W    gpio_a_func_en                  1'h0
        1       R/W    gpio_a_ck_en                    1'h0
        2       R/W    gpio_a_deb_ck_en                1'h0
        3       R/W    gpio_a_deb_clk_sel              1'h0
        4       R/W    gpio_b_func_en                  1'h0
        5       R/W    gpio_b_ck_en                    1'h0
        6       R/W    gpio_b_deb_ck_en                1'h0
        7       R/W    gpio_b_deb_clk_sel              1'h0
        8       R/W    RSVD                            1'h0
        9       R/W    simc_ck_en                      1'h0
        10      R/W    simc_func_en                    1'h0
        11      R/W    RSVD                            1'h0
        12      R/W    RSVD                            1'h0
        13      R/W    RSVD                            1'h0
        14      R/W    RSVD                            1'h0
        15      R/W    r_ir_mux_clk_cg_en              1'h0
        16      R/W    r_pll_ir_div_sel                1'h0
        17      R/W    r_pll_ir_src_sel                1'h0
        18      R/W    r_sclk_ir_src_sel               1'h0
        19      R/W    ir_ck_en                        1'h0
        20      R/W    ir_func_en                      1'h0
        22:21   R/W    r_can_lp_scan_div_sel           2'h0
        23      R/W    r_can_scan_div_sel              1'h0
        24      R/W    can_ck_en                       1'h0
        25      R/W    can_func_en                     1'h0
        29:26   R/W    RSVD                            4'h0
        30      R/W    RSVD                            1'h0
        31      R/W    RSVD                            1'h0
    */
    union
    {
        __IO uint32_t REG_GENERAL_PERI_CTL1;
        struct
        {
            __IO uint32_t gpio_a_func_en: 1;
            __IO uint32_t gpio_a_ck_en: 1;
            __IO uint32_t gpio_a_deb_ck_en: 1;
            __IO uint32_t gpio_a_deb_clk_sel: 1;
            __IO uint32_t gpio_b_func_en: 1;
            __IO uint32_t gpio_b_ck_en: 1;
            __IO uint32_t gpio_b_deb_ck_en: 1;
            __IO uint32_t gpio_b_deb_clk_sel: 1;
            __IO uint32_t RESERVED_7: 1;
            __IO uint32_t simc_ck_en: 1;
            __IO uint32_t simc_func_en: 1;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_ir_mux_clk_cg_en: 1;
            __IO uint32_t r_pll_ir_div_sel: 1;
            __IO uint32_t r_pll_ir_src_sel: 1;
            __IO uint32_t r_sclk_ir_src_sel: 1;
            __IO uint32_t ir_ck_en: 1;
            __IO uint32_t ir_func_en: 1;
            __IO uint32_t r_can_lp_scan_div_sel: 2;
            __IO uint32_t r_can_scan_div_sel: 1;
            __IO uint32_t can_ck_en: 1;
            __IO uint32_t can_func_en: 1;
            __IO uint32_t RESERVED_2: 4;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 1;
        } BITS_320;
    } u_320;

    /* 0x324        0x4000_2324
        2:0     R/W    RSVD                            1'h0
        3       R/W    RSVD                            1'h0
        4       R/W    RSVD                            1'h0
        5       R/W    RSVD                            1'h0
        6       R/W    RSVD                            1'h0
        7       R/W    rtzip_ck_en                     1'h0
        8       R/W    rtzip_func_en                   1'h0
        15:9    R/W    RSVD                            7'h0
        18:16   R/W    r_disp_div_sel                  3'h0
        19      R/W    r_disp_div_en                   1'h0
        20      R/W    r_disp_mux_clk_cg_en            1'h0
        21      R/W    r_disp_clk_src_sel1             1'h0
        22      R/W    r_disp_clk_src_sel0             1'h0
        23      R/W    disp_ck_en                      1'h0
        24      R/W    disp_func_en                    1'h0
        31:25   R/W    RSVD                            7'h0
    */
    union
    {
        __IO uint32_t REG_GENERAL_PERI_CTL2;
        struct
        {
            __IO uint32_t RESERVED_6: 3;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t rtzip_ck_en: 1;
            __IO uint32_t rtzip_func_en: 1;
            __IO uint32_t RESERVED_1: 7;
            __IO uint32_t r_disp_div_sel: 3;
            __IO uint32_t r_disp_div_en: 1;
            __IO uint32_t r_disp_mux_clk_cg_en: 1;
            __IO uint32_t r_disp_clk_src_sel1: 1;
            __IO uint32_t r_disp_clk_src_sel0: 1;
            __IO uint32_t disp_ck_en: 1;
            __IO uint32_t disp_func_en: 1;
            __IO uint32_t RESERVED_0: 7;
        } BITS_324;
    } u_324;

    /* 0x328        0x4000_2328
        2:0     R/W    r_timer_1_div_sel               3'h0
        3       R/W    r_timer_1_div_en                1'h0
        4       R/W    RSVD                            1'h0
        7:5     R/W    RSVD                            3'h0
        8       R/W    RSVD                            1'h0
        9       R/W    RSVD                            1'h0
        10      R/W    RSVD                            1'h0
        11      R/W    RSVD                            1'h0
        15:12   R/W    RSVD                            4'h0
        18:16   R/W    r_timer_2_div_sel               3'h0
        19      R/W    r_timer_2_div_en                1'h0
        20      R/W    RSVD                            1'h0
        23:21   R/W    RSVD                            3'h0
        24      R/W    RSVD                            1'h0
        25      R/W    RSVD                            1'h0
        26      R/W    RSVD                            1'h0
        27      R/W    RSVD                            1'h0
        28      R/W    RSVD                            1'h0
        29      R/W    slv_clk_timer_apb_g             1'h0
        30      R/W    r_timer_func_en                 1'h0
        31      R/W    r_timer_ck_en                   1'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_0_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_timer_1_div_sel: 3;
            __IO uint32_t r_timer_1_div_en: 1;
            __IO uint32_t RESERVED_13: 1;
            __IO uint32_t RESERVED_12: 3;
            __IO uint32_t RESERVED_11: 1;
            __IO uint32_t RESERVED_10: 1;
            __IO uint32_t RESERVED_9: 1;
            __IO uint32_t RESERVED_8: 1;
            __IO uint32_t RESERVED_7: 4;
            __IO uint32_t r_timer_2_div_sel: 3;
            __IO uint32_t r_timer_2_div_en: 1;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 3;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 1;
            __IO uint32_t slv_clk_timer_apb_g: 1;
            __IO uint32_t r_timer_func_en: 1;
            __IO uint32_t r_timer_ck_en: 1;
        } BITS_328;
    } u_328;

    /* 0x32C        0x4000_232c
        2:0     R/W    r_timer_3_div_sel               3'h0
        3       R/W    r_timer_3_div_en                1'h0
        4       R/W    r_timer_3_clk_sel2              1'h0
        8:5     R/W    RSVD                            4'h0
        9       R/W    r_timer_pwm_wrap3_clk_sel       1'h0
        10      R/W    r_timer_pwm_wrap3_func_en       1'h0
        11      R/W    r_timer_pwm_wrap3_ck_en         1'h0
        12      R/W    r_timer_3_clk_sel1              1'h0
        13      R/W    r_timer_3_clk_sel0              1'h0
        15:14   R/W    RSVD                            2'h0
        18:16   R/W    r_timer_4_div_sel               3'h0
        19      R/W    r_timer_4_div_en                1'h0
        20      R/W    r_timer_4_clk_sel2              1'h0
        24:21   R/W    RSVD                            4'h0
        25      R/W    r_timer_pwm_wrap4_clk_sel       1'h0
        26      R/W    r_timer_pwm_wrap4_func_en       1'h0
        27      R/W    r_timer_pwm_wrap4_ck_en         1'h0
        28      R/W    r_timer_4_clk_sel1              1'h0
        29      R/W    r_timer_4_clk_sel0              1'h0
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_1_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_timer_3_div_sel: 3;
            __IO uint32_t r_timer_3_div_en: 1;
            __IO uint32_t r_timer_3_clk_sel2: 1;
            __IO uint32_t RESERVED_3: 4;
            __IO uint32_t r_timer_pwm_wrap3_clk_sel: 1;
            __IO uint32_t r_timer_pwm_wrap3_func_en: 1;
            __IO uint32_t r_timer_pwm_wrap3_ck_en: 1;
            __IO uint32_t r_timer_3_clk_sel1: 1;
            __IO uint32_t r_timer_3_clk_sel0: 1;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t r_timer_4_div_sel: 3;
            __IO uint32_t r_timer_4_div_en: 1;
            __IO uint32_t r_timer_4_clk_sel2: 1;
            __IO uint32_t RESERVED_1: 4;
            __IO uint32_t r_timer_pwm_wrap4_clk_sel: 1;
            __IO uint32_t r_timer_pwm_wrap4_func_en: 1;
            __IO uint32_t r_timer_pwm_wrap4_ck_en: 1;
            __IO uint32_t r_timer_4_clk_sel1: 1;
            __IO uint32_t r_timer_4_clk_sel0: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_32C;
    } u_32C;

    /* 0x330        0x4000_2330
        2:0     R/W    r_timer_5_div_sel               3'h0
        3       R/W    r_timer_5_div_en                1'h0
        4       R/W    r_timer_5_clk_sel2              1'h0
        11:5    R/W    RSVD                            7'h0
        12      R/W    r_timer_5_clk_sel1              1'h0
        13      R/W    r_timer_5_clk_sel0              1'h0
        15:14   R/W    RSVD                            2'h0
        18:16   R/W    r_timer_6_div_sel               3'h0
        19      R/W    r_timer_6_div_en                1'h0
        20      R/W    r_timer_6_clk_sel2              1'h0
        27:21   R/W    RSVD                            7'h0
        28      R/W    r_timer_6_clk_sel1              1'h0
        29      R/W    r_timer_6_clk_sel0              1'h0
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_2_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_timer_5_div_sel: 3;
            __IO uint32_t r_timer_5_div_en: 1;
            __IO uint32_t r_timer_5_clk_sel2: 1;
            __IO uint32_t RESERVED_3: 7;
            __IO uint32_t r_timer_5_clk_sel1: 1;
            __IO uint32_t r_timer_5_clk_sel0: 1;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t r_timer_6_div_sel: 3;
            __IO uint32_t r_timer_6_div_en: 1;
            __IO uint32_t r_timer_6_clk_sel2: 1;
            __IO uint32_t RESERVED_1: 7;
            __IO uint32_t r_timer_6_clk_sel1: 1;
            __IO uint32_t r_timer_6_clk_sel0: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_330;
    } u_330;

    /* 0x334        0x4000_2334
        2:0     R/W    r_timer_7_div_sel               3'h0
        3       R/W    r_timer_7_div_en                1'h0
        4       R/W    r_timer_7_clk_sel2              1'h0
        11:5    R/W    RSVD                            7'h0
        12      R/W    r_timer_7_clk_sel1              1'h0
        13      R/W    r_timer_7_clk_sel0              1'h0
        15:14   R/W    RSVD                            2'h0
        18:16   R/W    r_timer_8_div_sel               3'h0
        19      R/W    r_timer_8_div_en                1'h0
        20      R/W    r_timer_8_clk_sel2              1'h0
        27:21   R/W    RSVD                            7'h0
        28      R/W    r_timer_8_clk_sel1              1'h0
        29      R/W    r_timer_8_clk_sel0              1'h0
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_3_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_timer_7_div_sel: 3;
            __IO uint32_t r_timer_7_div_en: 1;
            __IO uint32_t r_timer_7_clk_sel2: 1;
            __IO uint32_t RESERVED_3: 7;
            __IO uint32_t r_timer_7_clk_sel1: 1;
            __IO uint32_t r_timer_7_clk_sel0: 1;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t r_timer_8_div_sel: 3;
            __IO uint32_t r_timer_8_div_en: 1;
            __IO uint32_t r_timer_8_clk_sel2: 1;
            __IO uint32_t RESERVED_1: 7;
            __IO uint32_t r_timer_8_clk_sel1: 1;
            __IO uint32_t r_timer_8_clk_sel0: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_334;
    } u_334;

    /* 0x338        0x4000_2338
        31:0    R/W    RSVD                           32'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_PWM_WRAP_0_CFG;
        struct
        {
            __IO uint32_t RESERVED_0: 32;
        } BITS_338;
    } u_338;

    /* 0x33C        0x4000_233c
        7:0     R/W    timer_pwm_3_dead_zone_size      8'h0
        8       R/W    timer_pwm_3_emg_stop            1'h0
        9       R/W    timer_pwm_3_stop_state[0]       1'h0
        10      R/W    timer_pwm_3_stop_state[1]       1'h0
        11      R/W    timer_pwm_3_dummy_b11           1'h0
        12      R/W    timer_pwm_3_dead_zone_en        1'h0
        13      R/W    timer_pwm_3_pwm_pn_invserse_sel 1'h0
        14      R/W    timer_pwm_3_dummy_b14           1'h0
        15      R/W    timer_pwm_3_dummy_b15           1'h0
        23:16   R/W    timer_pwm_4_dead_zone_size      8'h0
        24      R/W    timer_pwm_4_emg_stop            1'h0
        25      R/W    timer_pwm_4_stop_state[0]       1'h0
        26      R/W    timer_pwm_4_stop_state[1]       1'h0
        27      R/W    timer_pwm_4_dummy_b11           1'h0
        28      R/W    timer_pwm_4_dead_zone_en        1'h0
        29      R/W    timer_pwm_4_pwm_pn_invserse_sel 1'h0
        30      R/W    timer_pwm_4_dummy_b14           1'h0
        31      R/W    timer_pwm_4_dummy_b15           1'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_PWM_WRAP_1_CFG;
        struct
        {
            __IO uint32_t timer_pwm_3_dead_zone_size: 8;
            __IO uint32_t timer_pwm_3_emg_stop: 1;
            __IO uint32_t timer_pwm_3_stop_state_0: 1;
            __IO uint32_t timer_pwm_3_stop_state_1: 1;
            __IO uint32_t timer_pwm_3_dummy_b11: 1;
            __IO uint32_t timer_pwm_3_dead_zone_en: 1;
            __IO uint32_t timer_pwm_3_pwm_pn_invserse_sel: 1;
            __IO uint32_t timer_pwm_3_dummy_b14: 1;
            __IO uint32_t timer_pwm_3_dummy_b15: 1;
            __IO uint32_t timer_pwm_4_dead_zone_size: 8;
            __IO uint32_t timer_pwm_4_emg_stop: 1;
            __IO uint32_t timer_pwm_4_stop_state_0: 1;
            __IO uint32_t timer_pwm_4_stop_state_1: 1;
            __IO uint32_t timer_pwm_4_dummy_b11: 1;
            __IO uint32_t timer_pwm_4_dead_zone_en: 1;
            __IO uint32_t timer_pwm_4_pwm_pn_invserse_sel: 1;
            __IO uint32_t timer_pwm_4_dummy_b14: 1;
            __IO uint32_t timer_pwm_4_dummy_b15: 1;
        } BITS_33C;
    } u_33C;

    /* 0x340        0x4000_2340
        31:0    R/W    RSVD                            32'h0
    */
    union
    {
        __IO uint32_t REG_TIMER_PWM_WRAP_2_CFG;
        struct
        {
            __IO uint32_t RESERVED_0: 32;
        } BITS_340;
    } u_340;

    /* 0x344        0x4000_2344
        2:0     R/W    r_etimer_0_div_sel              3'h0
        3       R/W    r_etimer_0_div_en               1'h0
        4       R/W    r_etimer_01_clk_src_sel2        1'h0
        5       R/W    r_etimer_01_clk_src_sel1        1'h0
        6       R/W    r_etimer_01_clk_src_sel0        1'h0
        9:7     R/W    r_etimer_pwm_0_div_sel          3'h0
        10      R/W    r_etimer_pwm_0_div_en           1'h0
        11      R/W    r_etimer_pwm_0_clk_src_sel      1'h0
        12      R/W    r_etimer_pwm_0_func_en          1'h0
        13      R/W    r_etimer_pwm_0_ck_en            1'h0
        15:14   R/W    RSVD                            2'h0
        18:16   R/W    r_etimer_1_div_sel              3'h0
        19      R/W    r_etimer_1_div_en               1'h0
        22:20   R/W    RSVD                            3'h0
        25:23   R/W    r_etimer_pwm_1_div_sel          3'h0
        26      R/W    r_etimer_pwm_1_div_en           1'h0
        27      R/W    r_etimer_pwm_1_clk_src_sel      1'h0
        28      R/W    r_etimer_pwm_1_func_en          1'h0
        29      R/W    r_etimer_pwm_1_ck_en            1'h0
        30      R/W    r_etimer_func_en                1'h0
        31      R/W    r_etimer_ck_en                  1'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_1_0_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_etimer_0_div_sel: 3;
            __IO uint32_t r_etimer_0_div_en: 1;
            __IO uint32_t r_etimer_01_clk_src_sel2: 1;
            __IO uint32_t r_etimer_01_clk_src_sel1: 1;
            __IO uint32_t r_etimer_01_clk_src_sel0: 1;
            __IO uint32_t r_etimer_pwm_0_div_sel: 3;
            __IO uint32_t r_etimer_pwm_0_div_en: 1;
            __IO uint32_t r_etimer_pwm_0_clk_src_sel: 1;
            __IO uint32_t r_etimer_pwm_0_func_en: 1;
            __IO uint32_t r_etimer_pwm_0_ck_en: 1;
            __IO uint32_t RESERVED_1: 2;
            __IO uint32_t r_etimer_1_div_sel: 3;
            __IO uint32_t r_etimer_1_div_en: 1;
            __IO uint32_t RESERVED_0: 3;
            __IO uint32_t r_etimer_pwm_1_div_sel: 3;
            __IO uint32_t r_etimer_pwm_1_div_en: 1;
            __IO uint32_t r_etimer_pwm_1_clk_src_sel: 1;
            __IO uint32_t r_etimer_pwm_1_func_en: 1;
            __IO uint32_t r_etimer_pwm_1_ck_en: 1;
            __IO uint32_t r_etimer_func_en: 1;
            __IO uint32_t r_etimer_ck_en: 1;
        } BITS_344;
    } u_344;

    /* 0x348        0x4000_2348
        2:0     R/W    r_etimer_2_div_sel              3'h0
        3       R/W    r_etimer_2_div_en               1'h0
        4       R/W    r_etimer_23_clk_src_sel2        1'h0
        5       R/W    r_etimer_23_clk_src_sel1        1'h0
        6       R/W    r_etimer_23_clk_src_sel0        1'h0
        9:7     R/W    r_etimer_pwm_2_div_sel          3'h0
        10      R/W    r_etimer_pwm_2_div_en           1'h0
        11      R/W    r_etimer_pwm_2_clk_src_sel      1'h0
        12      R/W    r_etimer_pwm_2_func_en          1'h0
        13      R/W    r_etimer_pwm_2_ck_en            1'h0
        15:14   R/W    RSVD                            2'h0
        18:16   R/W    r_etimer_3_div_sel              3'h0
        19      R/W    r_etimer_3_div_en               1'h0
        22:20   R/W    RSVD                            3'h0
        25:23   R/W    r_etimer_pwm_3_div_sel          3'h0
        26      R/W    r_etimer_pwm_3_div_en           1'h0
        27      R/W    r_etimer_pwm_3_clk_src_sel      1'h0
        28      R/W    r_etimer_pwm_3_func_en          1'h0
        29      R/W    r_etimer_pwm_3_ck_en            1'h0
        31:30   R/W    RSVD                            2'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_3_2_CLOCK_CTRL;
        struct
        {
            __IO uint32_t r_etimer_2_div_sel: 3;
            __IO uint32_t r_etimer_2_div_en: 1;
            __IO uint32_t r_etimer_23_clk_src_sel2: 1;
            __IO uint32_t r_etimer_23_clk_src_sel1: 1;
            __IO uint32_t r_etimer_23_clk_src_sel0: 1;
            __IO uint32_t r_etimer_pwm_2_div_sel: 3;
            __IO uint32_t r_etimer_pwm_2_div_en: 1;
            __IO uint32_t r_etimer_pwm_2_clk_src_sel: 1;
            __IO uint32_t r_etimer_pwm_2_func_en: 1;
            __IO uint32_t r_etimer_pwm_2_ck_en: 1;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t r_etimer_3_div_sel: 3;
            __IO uint32_t r_etimer_3_div_en: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t r_etimer_pwm_3_div_sel: 3;
            __IO uint32_t r_etimer_pwm_3_div_en: 1;
            __IO uint32_t r_etimer_pwm_3_clk_src_sel: 1;
            __IO uint32_t r_etimer_pwm_3_func_en: 1;
            __IO uint32_t r_etimer_pwm_3_ck_en: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_348;
    } u_348;

    /* 0x34C        0x4000_234c
        7:0     R/W    GPIOA_G0_CNT_LIMIT              8'h1
        8       R/W    GPIOA_G0_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOA_G0_DEB_CLK_DIV            3'h0
        12      R/W    GPIOA_G0_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOA_G1_CNT_LIMIT              8'h1
        24      R/W    GPIOA_G1_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOA_G1_DEB_CLK_DIV            3'h0
        28      R/W    GPIOA_G1_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOA_DEB_CLK_CTL_0;
        struct
        {
            __IO uint32_t GPIOA_G0_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G0_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G0_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G0_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOA_G1_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G1_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G1_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G1_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_34C;
    } u_34C;

    /* 0x350        0x4000_2350
        7:0     R/W    GPIOA_G2_CNT_LIMIT              8'h1
        8       R/W    GPIOA_G2_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOA_G2_DEB_CLK_DIV            3'h0
        12      R/W    GPIOA_G2_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOA_G3_CNT_LIMIT              8'h1
        24      R/W    GPIOA_G3_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOA_G3_DEB_CLK_DIV            3'h0
        28      R/W    GPIOA_G3_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOA_DEB_CLK_CTL_1;
        struct
        {
            __IO uint32_t GPIOA_G2_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G2_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G2_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G2_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOA_G3_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G3_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G3_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G3_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_350;
    } u_350;

    /* 0x354        0x4000_2354
        7:0     R/W    GPIOA_G4_CNT_LIMIT              8'h1
        8       R/W    GPIOA_G4_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOA_G4_DEB_CLK_DIV            3'h0
        12      R/W    GPIOA_G4_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOA_G5_CNT_LIMIT              8'h1
        24      R/W    GPIOA_G5_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOA_G5_DEB_CLK_DIV            3'h0
        28      R/W    GPIOA_G5_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOA_DEB_CLK_CTL_2;
        struct
        {
            __IO uint32_t GPIOA_G4_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G4_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G4_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G4_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOA_G5_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G5_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G5_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G5_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_354;
    } u_354;

    /* 0x358        0x4000_2358
        7:0     R/W    GPIOA_G6_CNT_LIMIT              8'h1
        8       R/W    GPIOA_G6_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOA_G6_DEB_CLK_DIV            3'h0
        12      R/W    GPIOA_G6_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOA_G7_CNT_LIMIT              8'h1
        24      R/W    GPIOA_G7_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOA_G7_DEB_CLK_DIV            3'h0
        28      R/W    GPIOA_G7_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOA_DEB_CLK_CTL_3;
        struct
        {
            __IO uint32_t GPIOA_G6_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G6_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G6_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G6_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOA_G7_CNT_LIMIT: 8;
            __IO uint32_t GPIOA_G7_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOA_G7_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOA_G7_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_358;
    } u_358;

    /* 0x35C        0x4000_235c
        31:0    R/W    GPIOA_x_DEB_FUNC_EN             32'h0
    */
    union
    {
        __IO uint32_t GPIOA_DEB_FUN_CTL;
        struct
        {
            __IO uint32_t GPIOA_x_DEB_FUNC_EN: 32;
        } BITS_35C;
    } u_35C;

    /* 0x360        0x4000_2360
        7:0     R/W    GPIOB_G0_CNT_LIMIT              8'h1
        8       R/W    GPIOB_G0_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOB_G0_DEB_CLK_DIV            3'h0
        12      R/W    GPIOB_G0_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOB_G1_CNT_LIMIT              8'h1
        24      R/W    GPIOB_G1_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOB_G1_DEB_CLK_DIV            3'h0
        28      R/W    GPIOB_G1_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOB_DEB_CLK_CTL_0;
        struct
        {
            __IO uint32_t GPIOB_G0_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G0_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G0_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G0_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOB_G1_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G1_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G1_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G1_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_360;
    } u_360;

    /* 0x364        0x4000_2364
        7:0     R/W    GPIOB_G2_CNT_LIMIT              8'h1
        8       R/W    GPIOB_G2_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOB_G2_DEB_CLK_DIV            3'h0
        12      R/W    GPIOB_G2_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOB_G3_CNT_LIMIT              8'h1
        24      R/W    GPIOB_G3_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOB_G3_DEB_CLK_DIV            3'h0
        28      R/W    GPIOB_G3_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOB_DEB_CLK_CTL_1;
        struct
        {
            __IO uint32_t GPIOB_G2_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G2_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G2_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G2_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOB_G3_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G3_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G3_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G3_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_364;
    } u_364;

    /* 0x368        0x4000_2368
        7:0     R/W    GPIOB_G4_CNT_LIMIT              8'h1
        8       R/W    GPIOB_G4_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOB_G4_DEB_CLK_DIV            3'h0
        12      R/W    GPIOB_G4_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOB_G5_CNT_LIMIT              8'h1
        24      R/W    GPIOB_G5_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOB_G5_DEB_CLK_DIV            3'h0
        28      R/W    GPIOB_G5_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOB_DEB_CLK_CTL_2;
        struct
        {
            __IO uint32_t GPIOB_G4_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G4_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G4_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G4_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOB_G5_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G5_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G5_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G5_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_368;
    } u_368;

    /* 0x36C        0x4000_236c
        7:0     R/W    GPIOB_G6_CNT_LIMIT              8'h1
        8       R/W    GPIOB_G6_DEB_CLK_SEL            1'h0
        11:9    R/W    GPIOB_G6_DEB_CLK_DIV            3'h0
        12      R/W    GPIOB_G6_DEB_CNT_EN             1'b0
        15:13   R/W    RSVD                            3'h0
        23:16   R/W    GPIOB_G7_CNT_LIMIT              8'h1
        24      R/W    GPIOB_G7_DEB_CLK_SEL            1'h0
        27:25   R/W    GPIOB_G7_DEB_CLK_DIV            3'h0
        28      R/W    GPIOB_G7_DEB_CNT_EN             1'b0
        31:29   R/W    RSVD                            3'h0
    */
    union
    {
        __IO uint32_t GPIOB_DEB_CLK_CTL_3;
        struct
        {
            __IO uint32_t GPIOB_G6_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G6_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G6_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G6_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t GPIOB_G7_CNT_LIMIT: 8;
            __IO uint32_t GPIOB_G7_DEB_CLK_SEL: 1;
            __IO uint32_t GPIOB_G7_DEB_CLK_DIV: 3;
            __IO uint32_t GPIOB_G7_DEB_CNT_EN: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_36C;
    } u_36C;

    /* 0x370        0x4000_2370
        31:0    R/W    GPIOB_x_DEB_FUNC_EN             32'h0
    */
    union
    {
        __IO uint32_t GPIOB_DEB_FUN_CTL;
        struct
        {
            __IO uint32_t GPIOB_x_DEB_FUNC_EN: 32;
        } BITS_370;
    } u_370;

    /* 0x374        0x4000_2374
        0       R/W    sdio_ck_en                      1'h0
        1       R/W    sdio_func_en                    1'h0
        2       R/W    r_sdio_clk_src_en               1'h0
        6:3     R/W    r_sdio_div_sel                  4'h0
        7       R/W    r_sdio_div_en                   1'h0
        8       R/W    r_sdio_mux_clk_cg_en            1'h0
        9       R/W    r_sdio_clk_src_sel1             1'h0
        10      R/W    r_sdio_clk_src_sel0             1'h0
        31:11   R/W    RSVD                            21'h0
    */
    union
    {
        __IO uint32_t REG_SDH_CTL;
        struct
        {
            __IO uint32_t sdio_ck_en: 1;
            __IO uint32_t sdio_func_en: 1;
            __IO uint32_t r_sdio_clk_src_en: 1;
            __IO uint32_t r_sdio_div_sel: 4;
            __IO uint32_t r_sdio_div_en: 1;
            __IO uint32_t r_sdio_mux_clk_cg_en: 1;
            __IO uint32_t r_sdio_clk_src_sel1: 1;
            __IO uint32_t r_sdio_clk_src_sel0: 1;
            __IO uint32_t RESERVED_0: 21;
        } BITS_374;
    } u_374;

    /* 0x378        0x4000_2378
        7:0     R/W    r_sdh_drv_dly_sel               8'h0
        15:8    R/W    r_sdh_sample_dly_sel            8'h0
        17:16   R/W    r_sdh_clk_sel_drv               2'h0
        19:18   R/W    r_sdh_clk_sel_sample            2'h0
        20      R/W    r_sdh_bypass_shift_drv          1'h0
        21      R/W    r_sdh_bypass_shift_sample       1'h0
        22      R/W    r_sdh_bypass_delay_drv          1'h0
        23      R/W    r_sdh_bypass_delay_sample       1'h0
        31:24   R/W    r_sdh_clk_out_dly_sel           8'h0
    */
    union
    {
        __IO uint32_t REG_SDH_PHY0;
        struct
        {
            __IO uint32_t r_sdh_drv_dly_sel: 8;
            __IO uint32_t r_sdh_sample_dly_sel: 8;
            __IO uint32_t r_sdh_clk_sel_drv: 2;
            __IO uint32_t r_sdh_clk_sel_sample: 2;
            __IO uint32_t r_sdh_bypass_shift_drv: 1;
            __IO uint32_t r_sdh_bypass_shift_sample: 1;
            __IO uint32_t r_sdh_bypass_delay_drv: 1;
            __IO uint32_t r_sdh_bypass_delay_sample: 1;
            __IO uint32_t r_sdh_clk_out_dly_sel: 8;
        } BITS_378;
    } u_378;

    /* 0x37C        0x4000_237c
        7:0     R/W    r_sdh_cmd_out_dly_sel           8'h0
        15:8    R/W    r_sdh_dat0_dly_sel              8'h0
        23:16   R/W    r_sdh_dat1_dly_sel              8'h0
        31:24   R/W    r_sdh_dat2_dly_sel              8'h0
    */
    union
    {
        __IO uint32_t REG_SDH_PHY1;
        struct
        {
            __IO uint32_t r_sdh_cmd_out_dly_sel: 8;
            __IO uint32_t r_sdh_dat0_dly_sel: 8;
            __IO uint32_t r_sdh_dat1_dly_sel: 8;
            __IO uint32_t r_sdh_dat2_dly_sel: 8;
        } BITS_37C;
    } u_37C;

    /* 0x380        0x4000_2380
        7:0     R/W    r_sdh_dat3_dly_sel              8'h0
        15:8    R/W    r_sdh_dat4_dly_sel              8'h0
        23:16   R/W    r_sdh_dat5_dly_sel              8'h0
        31:24   R/W    r_sdh_dat6_dly_sel              8'h0
    */
    union
    {
        __IO uint32_t REG_SDH_PHY2;
        struct
        {
            __IO uint32_t r_sdh_dat3_dly_sel: 8;
            __IO uint32_t r_sdh_dat4_dly_sel: 8;
            __IO uint32_t r_sdh_dat5_dly_sel: 8;
            __IO uint32_t r_sdh_dat6_dly_sel: 8;
        } BITS_380;
    } u_380;

    /* 0x384        0x4000_2384
        7:0     R/W    r_sdh_dat7_dly_sel              8'h0
        19:8    R/W    r_sdh_dbg_sel                   12'h0
        21:20   R/W    r_sdh_dbg_en_i                  2'h0
        22      R/W    r_sdh_cclk_in_drv               1'h0
        23      R/W    r_sdh_cclk_sample_drv           1'h0
        24      R/W    r_sdh_cclk_in_div_enable        1'h1
        31:25   R/W    RSVD                            7'h0
    */
    union
    {
        __IO uint32_t REG_SDH_PHY3;
        struct
        {
            __IO uint32_t r_sdh_dat7_dly_sel: 8;
            __IO uint32_t r_sdh_dbg_sel: 12;
            __IO uint32_t r_sdh_dbg_en_i: 2;
            __IO uint32_t r_sdh_cclk_in_drv: 1;
            __IO uint32_t r_sdh_cclk_sample_drv: 1;
            __IO uint32_t r_sdh_cclk_in_div_enable: 1;
            __IO uint32_t RESERVED_0: 7;
        } BITS_384;
    } u_384;

    /* 0x388        0x4000_2388
        5:0     R/W    r_bt_ahb_wait_cnt               6'hC
        31:6    R/W    RSVD                            26'h0
    */
    union
    {
        __IO uint32_t REG_BT_MISC;
        struct
        {
            __IO uint32_t r_bt_ahb_wait_cnt: 6;
            __IO uint32_t RESERVED_0: 26;
        } BITS_388;
    } u_388;

    /* 0x38C        0x4000_238c
        0       R/W    r_PMUX_1_WIRE_UART4_EN          1'h0
        1       R/W    rtk_uart4_func_en               1'h0
        2       R/W    rtk_uart4_ck_en                 1'h0
        3       R/W    rtk_uart4_div_en                1'h0
        6:4     R/W    rtk_uart4_div_sel               3'b000
        7       R/W    RSVD                            1'h0
        8       R/W    r_PMUX_1_WIRE_UART5_EN          1'h0
        9       R/W    rtk_uart5_func_en               1'h0
        10      R/W    rtk_uart5_ck_en                 1'h0
        11      R/W    rtk_uart5_div_en                1'h0
        14:12   R/W    rtk_uart5_div_sel               3'b000
        31:15   R/W    RSVD                            17'h0
    */
    union
    {
        __IO uint32_t REG_UART_PERI_CTL1;
        struct
        {
            __IO uint32_t r_PMUX_1_WIRE_UART4_EN: 1;
            __IO uint32_t rtk_uart4_func_en: 1;
            __IO uint32_t rtk_uart4_ck_en: 1;
            __IO uint32_t rtk_uart4_div_en: 1;
            __IO uint32_t rtk_uart4_div_sel: 3;
            __IO uint32_t RESERVED_13: 1;
            __IO uint32_t r_PMUX_1_WIRE_UART5_EN: 1;
            __IO uint32_t rtk_uart5_func_en: 1;
            __IO uint32_t rtk_uart5_ck_en: 1;
            __IO uint32_t rtk_uart5_div_en: 1;
            __IO uint32_t rtk_uart5_div_sel: 3;
            __IO uint32_t RESERVED_0: 17;
        } BITS_38C;
    } u_38C;

    /* 0x390        0x4000_2390
        1:0     R/W    GMAC_LX_BUS_TIMEOUT_THRESHOLD   2'h0
        2       R/W    GMAC_LX_BUS_TIMEOUT_EN          1'h0
        3       R/W    GMAC_LX_BUS_DMA_LOCK_IN         1'h0
        5:4     R/W    GMAC_MII_LX_TIMEOUT_THRESHOLD   2'h0
        6       R/W    GMAC_MII_LX_TIMEOUT_EN          1'h0
        31:7    R/W    RSVD                            25'b0
    */
    union
    {
        __IO uint32_t REG_GMAC_BUS;
        struct
        {
            __IO uint32_t GMAC_LX_BUS_TIMEOUT_THRESHOLD: 2;
            __IO uint32_t GMAC_LX_BUS_TIMEOUT_EN: 1;
            __IO uint32_t GMAC_LX_BUS_DMA_LOCK_IN: 1;
            __IO uint32_t GMAC_MII_LX_TIMEOUT_THRESHOLD: 2;
            __IO uint32_t GMAC_MII_LX_TIMEOUT_EN: 1;
            __IO uint32_t RESERVED_0: 25;
        } BITS_390;
    } u_390;

    /* 0x394        0x4000_2394
        18:0    R/W    gmac_base_addr                  19'h20020
        31:19   R/W    RSVD                            13'b0
    */
    union
    {
        __IO uint32_t REG_GMAC_BASE_ADDR;
        struct
        {
            __IO uint32_t gmac_base_addr: 19;
            __IO uint32_t RESERVED_0: 13;
        } BITS_394;
    } u_394;

    /* 0x398        0x4000_2398
        18:0    R/W    gmac_base_addr_1                19'h28020
        31:19   R/W    RSVD                            13'b0
    */
    union
    {
        __IO uint32_t REG_GMAC_BASE_ADDR_1;
        struct
        {
            __IO uint32_t gmac_base_addr_1: 19;
            __IO uint32_t RESERVED_0: 13;
        } BITS_398;
    } u_398;

    /* 0x39C        0x4000_239c
        5:0     R/W    gmac2fephy_phy_ad               6'b0
        31:6    R/W    RSVD                            26'b0
    */
    union
    {
        __IO uint32_t REG_GMAC_PHY_AD;
        struct
        {
            __IO uint32_t gmac2fephy_phy_ad: 6;
            __IO uint32_t RESERVED_0: 26;
        } BITS_39C;
    } u_39C;

    /* 0x3A0        0x4000_23a0
        31:0    R/W    r_sdh0_phy_dbg                  32'h0
    */
    union
    {
        __IO uint32_t REG_SDH0_DBG0;
        struct
        {
            __IO uint32_t r_sdh0_phy_dbg: 32;
        } BITS_3A0;
    } u_3A0;

    /* 0x3A4        0x4000_23a4
        31:0    R/W    r_sdh0_dbg                      32'h0
    */
    union
    {
        __IO uint32_t REG_SDH0_DBG1;
        struct
        {
            __IO uint32_t r_sdh0_dbg: 32;
        } BITS_3A4;
    } u_3A4;

    /* 0x3A8        0x4000_23a8
        7:0     R/W    r_sdh0_cmd_out_oe_dly_sel       8'h0
        15:8    R/W    r_sdh0_dat0_oe_dly_sel          8'h0
        23:16   R/W    r_sdh0_dat1_oe_dly_sel          8'h0
        31:24   R/W    r_sdh0_dat2_oe_dly_sel          8'h0
    */
    union
    {
        __IO uint32_t REG_SDH0_PHY4;
        struct
        {
            __IO uint32_t r_sdh0_cmd_out_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat0_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat1_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat2_oe_dly_sel: 8;
        } BITS_3A8;
    } u_3A8;

    /* 0x3AC        0x4000_23ac
        7:0     R/W    r_sdh0_dat3_oe_dly_sel          8'h0
        15:8    R/W    r_sdh0_dat4_oe_dly_sel          8'h0
        23:16   R/W    r_sdh0_dat5_oe_dly_sel          8'h0
        31:24   R/W    r_sdh0_dat6_oe_dly_sel          8'h0
    */
    union
    {
        __IO uint32_t REG_SDIO0_PHY5;
        struct
        {
            __IO uint32_t r_sdh0_dat3_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat4_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat5_oe_dly_sel: 8;
            __IO uint32_t r_sdh0_dat6_oe_dly_sel: 8;
        } BITS_3AC;
    } u_3AC;

    /* 0x3B0        0x4000_23b0
        7:0     R/W    r_sdh0_dat7_oe_dly_sel          8'h0
        15:8    R/W    RSVD                            8'h0
        23:16   R/W    RSVD                            8'h0
        31:24   R/W    RSVD                            8'h0
    */
    union
    {
        __IO uint32_t REG_SDH0_PHY8;
        struct
        {
            __IO uint32_t r_sdh0_dat7_oe_dly_sel: 8;
            __IO uint32_t RESERVED_2: 8;
            __IO uint32_t RESERVED_1: 8;
            __IO uint32_t RESERVED_0: 8;
        } BITS_3B0;
    } u_3B0;

    /* 0x3B4        0x4000_23b4
        31:0    R/W    sdh_dummy_reg_1                 32'h0
    */
    union
    {
        __IO uint32_t SDIO_DUMMY_REG1;
        struct
        {
            __IO uint32_t sdh_dummy_reg_1: 32;
        } BITS_3B4;
    } u_3B4;

    /* 0x3B8        0x4000_23b8
        31:0    R/W    sdh_dummy_reg_2                 32'h0
    */
    union
    {
        __IO uint32_t SDIO_DUMMY_REG2;
        struct
        {
            __IO uint32_t sdh_dummy_reg_2: 32;
        } BITS_3B8;
    } u_3B8;

    /* 0x3BC        0x4000_23bc
        31:0    R/W    sdh_dummy_reg_3                 32'h0
    */
    union
    {
        __IO uint32_t SDIO_DUMMY_REG3;
        struct
        {
            __IO uint32_t sdh_dummy_reg_3: 32;
        } BITS_3BC;
    } u_3BC;

    /* 0x3C0        0x4000_23c0
        31:0    R/W    sdh_dummy_reg_4                 32'h0
    */
    union
    {
        __IO uint32_t SDIO_DUMMY_REG4;
        struct
        {
            __IO uint32_t sdh_dummy_reg_4: 32;
        } BITS_3C0;
    } u_3C0;

} PERI_BLKCTRL_PERI_CLK_TypeDef;

/* reference: Bee4_PERI-ON_20221017_v2.xlsx */
typedef struct
{
    /* 0x700        0x4000_2700
        0       R/W    sport0_func_en          1'h0
        1       R/W    sport0_ck_en            1'h0
        2       R/W    sport1_func_en          1'h0
        3       R/W    sport1_ck_en            1'h0
        4       R/W    RSVD                    1'h0
        5       R/W    RSVD                    1'h0
        6       R/W    RSVD                    1'h0
        7       R/W    RSVD                    1'h0
        8       R/W    audio_func_en           1'h0
        9       R/W    audio_ck_en             1'h0
        10      R/W    r_CLK_EN_SPORT_40M      1'h0
        13:11   R/W    sp0_dsp_clk_sel         3'h0
        14      R/W    RSVD                    1'h0
        17:15   R/W    sp1_dsp_clk_sel         3'h0
        18      R/W    RSVD                    1'h0
        21:19   R/W    RSVD                    3'h0
        22      R/W    RSVD                    1'h0
        25:23   R/W    RSVD                    3'h0
        26      R/W    RSVD                    1'h0
        27      R/W    RSVD                    1'h0
        28      R/W    r_sport_pll2_ck_en      1'h0
        31:29   R/W    RSVD                    3'h0
    */
    union
    {
        __IO uint32_t REG_SOC_AUDIO_IF_EN;
        struct
        {
            __IO uint32_t sport0_func_en: 1;
            __IO uint32_t sport0_ck_en: 1;
            __IO uint32_t sport1_func_en: 1;
            __IO uint32_t sport1_ck_en: 1;
            __IO uint32_t RESERVED_11: 1;
            __IO uint32_t RESERVED_10: 1;
            __IO uint32_t RESERVED_9: 1;
            __IO uint32_t RESERVED_8: 1;
            __IO uint32_t audio_func_en: 1;
            __IO uint32_t audio_ck_en: 1;
            __IO uint32_t r_CLK_EN_SPORT_40M: 1;
            __IO uint32_t sp0_dsp_clk_sel: 3;
            __IO uint32_t RESERVED_7: 1;
            __IO uint32_t sp1_dsp_clk_sel: 3;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 3;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 3;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t r_sport_pll2_ck_en: 1;
            __IO uint32_t RESERVED_0: 3;
        } BITS_700;
    } u_700;

    /* 0x704        0x4000_2704
        7:0     R/W    r_PLL_DIV0_SETTING      8'h0
        15:8    R/W    r_PLL_DIV1_SETTING      8'h0
        23:16   R/W    RSVD                    8'h0
        31:24   R/W    RSVD                    8'h0
    */
    union
    {
        __IO uint32_t REG_AUDIO_PERI_CTL0;
        struct
        {
            __IO uint32_t r_PLL_DIV0_SETTING: 8;
            __IO uint32_t r_PLL_DIV1_SETTING: 8;
            __IO uint32_t RESERVED_1: 8;
            __IO uint32_t RESERVED_0: 8;
        } BITS_704;
    } u_704;

    /* 0x708        0x4000_2708
        0       R/W    r_CODEC_i2s0_master_sel 1'h0
        1       R/W    r_CODEC_i2s1_master_sel 1'h0
        2       R/W    RSVD                    1'h0
        3       R/W    RSVD                    1'h0
        4       R/W    r_SPORT0_EXT_CODEC      1'h0
        5       R/W    r_SPORT1_EXT_CODEC      1'h0
        6       R/W    RSVD                    1'h0
        7       R/W    RSVD                    1'h0
        8       R/W    r_SPORT0_MCLK_OUT       1'h0
        9       R/W    r_SPORT1_MCLK_OUT       1'h0
        10      R/W    RSVD                    1'h0
        11      R/W    RSVD                    1'h0
        31:12   R/W    RSVD                    20'h0
    */
    union
    {
        __IO uint32_t REG_AUDIO_PERI_CTL1;
        struct
        {
            __IO uint32_t r_CODEC_i2s0_master_sel: 1;
            __IO uint32_t r_CODEC_i2s1_master_sel: 1;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t r_SPORT0_EXT_CODEC: 1;
            __IO uint32_t r_SPORT1_EXT_CODEC: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_SPORT0_MCLK_OUT: 1;
            __IO uint32_t r_SPORT1_MCLK_OUT: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 20;
        } BITS_708;
    } u_708;

    /* 0x70C        0x4000_270c
        0       R/W    mclk2_en                1'h0
        1       R/W    mclk2_out_sel           1'h0
        3:2     R/W    RSVD                    2'h0
        4       R/W    mclk2_src_sel_0         2'h0
        5       R/W    mclk2_src_sel_1         2'h0
        7:6     R/W    RSVD                    2'h0
        15:8    R/W    mclk2_div_setting       8'h0
        16      R/W    mclk2_pmux_sel          1'h0
        31:17   R/W    RSVD                    15'h0
    */
    union
    {
        __IO uint32_t REG_AUDIO_PERI_CTL2;
        struct
        {
            __IO uint32_t mclk2_en: 1;
            __IO uint32_t mclk2_out_sel: 1;
            __IO uint32_t RESERVED_2: 2;
            __IO uint32_t mclk2_src_sel_0: 1;
            __IO uint32_t mclk2_src_sel_1: 1;
            __IO uint32_t RESERVED_1: 2;
            __IO uint32_t mclk2_div_setting: 8;
            __IO uint32_t mclk2_pmux_sel: 1;
            __IO uint32_t RESERVED_0: 15;
        } BITS_70C;
    } u_70C;

} PERIBLKCTRL_AUDIO_TypeDef;

/* reference: Bee4_PERI-ON_20221017_v2.xlsx */
typedef struct
{
    /* 0xA00        0x4000_2a00
        31:0    R      RSVD                        32'h0
    */
    __IO uint32_t REG_MISC6;

    /* 0xA04        0x4000_2a04
        1:0     R/W    DEBUG_G0_bit                2'h0
        7:2     R/W    DEBUG_G0_INDEX              6'h0
        9:8     R/W    DEBUG_G1_bit                2'h0
        15:10   R/W    DEBUG_G1_INDEX              6'h0
        17:16   R/W    DEBUG_G2_bit                2'h0
        23:18   R/W    DEBUG_G2_INDEX              8'h0
        25:24   R/W    DEBUG_G3_bit                2'h0
        31:26   R/W    DEBUG_G3_INDEX              6'h0
    */
    union
    {
        __IO uint32_t REG_MISC7;
        struct
        {
            __IO uint32_t DEBUG_G0_bit: 2;
            __IO uint32_t DEBUG_G0_INDEX: 6;
            __IO uint32_t DEBUG_G1_bit: 2;
            __IO uint32_t DEBUG_G1_INDEX: 6;
            __IO uint32_t DEBUG_G2_bit: 2;
            __IO uint32_t DEBUG_G2_INDEX: 6;
            __IO uint32_t DEBUG_G3_bit: 2;
            __IO uint32_t DEBUG_G3_INDEX: 6;
        } BITS_A04;
    } u_A04;

    /* 0xA08        0x4000_2a08
        2:0     R/W    DBG_P0_SEL3_0               3'h0
        5:3     R/W    DBG_P0_SEL7_4               3'h0
        8:6     R/W    DBG_P1_SEL3_0               3'h0
        11:9    R/W    DBG_P1_SEL7_4               3'h0
        14:12   R/W    DBG_P2_SEL3_0               3'h0
        17:15   R/W    DBG_P2_SEL7_4               3'h0
        20:18   R/W    DBG_P3_SEL3_0               3'h0
        23:21   R/W    DBG_P3_SEL7_4               3'h0
        26:24   R/W    DBG_P4_SEL3_0               3'h0
        29:27   R/W    DBG_P4_SEL7_4               3'h0
        31:30   R/W    RSVD                        2'h0
    */
    union
    {
        __IO uint32_t REG_MISC8;
        struct
        {
            __IO uint32_t DBG_P0_SEL3_0: 3;
            __IO uint32_t DBG_P0_SEL7_4: 3;
            __IO uint32_t DBG_P1_SEL3_0: 3;
            __IO uint32_t DBG_P1_SEL7_4: 3;
            __IO uint32_t DBG_P2_SEL3_0: 3;
            __IO uint32_t DBG_P2_SEL7_4: 3;
            __IO uint32_t DBG_P3_SEL3_0: 3;
            __IO uint32_t DBG_P3_SEL7_4: 3;
            __IO uint32_t DBG_P4_SEL3_0: 3;
            __IO uint32_t DBG_P4_SEL7_4: 3;
            __IO uint32_t RESERVED_0: 2;
        } BITS_A08;
    } u_A08;

    /* 0xA0C        0x4000_2a0c
        2:0     R/W    DBG_P5_SEL3_0               3'h0
        5:3     R/W    DBG_P5_SEL7_4               3'h0
        8:6     R/W    RSVD                        3'h0
        11:9    R/W    RSVD                        3'h0
        14:12   R/W    RSVD                        3'h0
        17:15   R/W    RSVD                        3'h0
        20:18   R/W    DBG_P8_SEL3_0               3'h0
        23:21   R/W    RSVD                        3'h0
        26:24   R/W    DBG_P9_SEL3_0               3'h0
        29:27   R/W    DBG_P9_SEL7_4               3'h0
        31:30   R/W    RSVD                        2'h0
    */
    union
    {
        __IO uint32_t REG_MISC9;
        struct
        {
            __IO uint32_t DBG_P5_SEL3_0: 3;
            __IO uint32_t DBG_P5_SEL7_4: 3;
            __IO uint32_t RESERVED_5: 3;
            __IO uint32_t RESERVED_4: 3;
            __IO uint32_t RESERVED_3: 3;
            __IO uint32_t RESERVED_2: 3;
            __IO uint32_t DBG_P8_SEL3_0: 3;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t DBG_P9_SEL3_0: 3;
            __IO uint32_t DBG_P9_SEL7_4: 3;
            __IO uint32_t RESERVED_0: 2;
        } BITS_A0C;
    } u_A0C;

    /* 0xA10        0x4000_2a10
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_MISC10;

    /* 0xA14        0x4000_2a14
        31:0    R      RSVD                        32'b0
    */
    __IO uint32_t REG_MISC11;

    /* 0xA18        0x4000_2a18
        7:0     R/W    PMUX_TEST_MODE_SEL          8'h0
        31:8    R/W    RSVD                        24'h0
    */
    union
    {
        __IO uint32_t TESTMODE_SEL_VCORE2;
        struct
        {
            __IO uint32_t PMUX_TEST_MODE_SEL: 8;
            __IO uint32_t RESERVED_0: 24;
        } BITS_A18;
    } u_A18;

    /* 0xA1C        0x4000_2a1c
        7:0     R/W    DIG_DEBUG_MODE_SEL          8'h0
        11:8    R/W    SPIC_MON_SEL                4'h0
        31:12   R/W    RSVD                        20'h0
    */
    union
    {
        __IO uint32_t DIG_DEBUG_SEL_VCORE2;
        struct
        {
            __IO uint32_t DIG_DEBUG_MODE_SEL: 8;
            __IO uint32_t SPIC_MON_SEL: 4;
            __IO uint32_t RESERVED_0: 20;
        } BITS_A1C;
    } u_A1C;

    /* 0xA20        0x4000_2a20
        0       R/W    FLASH_FT_MODE_EN            1'b0
        1       R/W    FLASH_MP_MODE_EN            1'b0
        31:2    R/W    RSVD                        30'h0
    */
    union
    {
        __IO uint32_t FLASH_FT_MP_MODE;
        struct
        {
            __IO uint32_t FLASH_FT_MODE_EN: 1;
            __IO uint32_t FLASH_MP_MODE_EN: 1;
            __IO uint32_t RESERVED_0: 30;
        } BITS_A20;
    } u_A20;

    /* 0xA24        0x4000_2a24
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t KM4_TRACE_DLY;

    /* 0xA28        0x4000_2a28
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_1;

    /* 0xA2C        0x4000_2a2c
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_2;

    /* 0xA30        0x4000_2a30
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_3;

    /* 0xA34        0x4000_2a34
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_4;

    /* 0xA38        0x4000_2a38
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_5;

    /* 0xA3C        0x4000_2a3c
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_6;

    /* 0xA40        0x4000_2a40
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_7;

    /* 0xA44        0x4000_2a44
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_8;

    /* 0xA48        0x4000_2a48
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_9;

    /* 0xA4C        0x4000_2a4c
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_10;

    /* 0xA50        0x4000_2a50
        31:0    R/W    RSVD                        32'h0
    */
    __IO uint32_t REG_SDIO_MBIST_CTRL_11;

    /* 0xA54        0x4000_2a54
        28:0    R/W    RSVD                        29'h0
        29      R/W    reg_aon_w1o_spic0_ft_dis    1'b0
        30      R/W    reg_aon_w1o_spic0_mp_dis    1'b0
        31      R/W    reg_aon_w1o_spic0_dbg_dis   1'b0
    */
    union
    {
        __IO uint32_t REG_FLASH_DBG;
        struct
        {
            __IO uint32_t RESERVED_0: 29;
            __IO uint32_t reg_aon_w1o_spic0_ft_dis: 1;
            __IO uint32_t reg_aon_w1o_spic0_mp_dis: 1;
            __IO uint32_t reg_aon_w1o_spic0_dbg_dis: 1;
        } BITS_A54;
    } u_A54;
} PERI_BLKCTRL_INTERNAL_AUTO_TypeDef;

typedef struct
{
    /* 0xB00        0x4000_2b00
        2:0     R/W    rf_0_remap_table            3'b0
        3       R      RSVD                        1'b0
        6:4     R/W    rf_4_remap_table            3'b001
        7       R      RSVD                        1'b0
        10:8    R/W    rf_5_remap_table            3'b010
        11      R      RSVD                        1'b0
        14:12   R/W    rf_6_remap_table            3'b011
        15      R      RSVD                        1'b0
        18:16   R/W    rf_7_remap_table            3'b100
        30:19   R      RSVD                        12'b0
        31      R/W    auto_switch_update          1'b0
    */
    union
    {
        __IO uint32_t REG_AUTO_TABLE_MAP;
        struct
        {
            __IO uint32_t rf_0_remap_table: 3;
            __I uint32_t RESERVED_4: 1;
            __IO uint32_t rf_4_remap_table: 3;
            __I uint32_t RESERVED_3: 1;
            __IO uint32_t rf_5_remap_table: 3;
            __I uint32_t RESERVED_2: 1;
            __IO uint32_t rf_6_remap_table: 3;
            __I uint32_t RESERVED_1: 1;
            __IO uint32_t rf_7_remap_table: 3;
            __I uint32_t RESERVED_0: 12;
            __IO uint32_t auto_switch_update: 1;
        } BITS_B00;
    } u_B00;

    /* 0xB04        0x4000_2b04
        0       R/W    CORE_BUCK_FPWM_H            1'b1
        1       RW     CORE_BUCK_PFM_AOT_EN        1'b0
        2       RW     CORE_BUCK_PFM_COT_EN        1'b1
        3       RW     CORE_BUCK_ENOFFSAWPFM_H     1'b1
        5:4     R/W    CORE_BUCK_OCPRES_H          2'b01
        8:6     R/W    CORE_BUCK_VREFOCP_H         3'b001
        14:9    R/W    CORE_BUCK_SWRTUNE_H         6'b011101
        18:15   R/W    CORE_BUCK_VREFPFM_H         4'b1011
        24:19   RW     CORE_D300k_REG_MANU_CCOT    6'b010000
        25      R/W    CORE_LDO_ENPC_LDODIGI       1'b0
        31:26   R/W    CORE_BUCK_LDOTUNE_H         6'b0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW0_0;
        struct
        {
            __IO uint32_t CORE_BUCK_FPWM_H: 1;
            __IO uint32_t CORE_BUCK_PFM_AOT_EN: 1;
            __IO uint32_t CORE_BUCK_PFM_COT_EN: 1;
            __IO uint32_t CORE_BUCK_ENOFFSAWPFM_H: 1;
            __IO uint32_t CORE_BUCK_OCPRES_H: 2;
            __IO uint32_t CORE_BUCK_VREFOCP_H: 3;
            __IO uint32_t CORE_BUCK_SWRTUNE_H: 6;
            __IO uint32_t CORE_BUCK_VREFPFM_H: 4;
            __IO uint32_t CORE_D300k_REG_MANU_CCOT: 6;
            __IO uint32_t CORE_LDO_ENPC_LDODIGI: 1;
            __IO uint32_t CORE_BUCK_LDOTUNE_H: 6;
        } BITS_B04;
    } u_B04;

    /* 0xB08        0x4000_2b08
        0       R/W    CORE_BUCK_FPWM_H            1'b1
        1       RW     CORE_BUCK_PFM_AOT_EN        1'b0
        2       RW     CORE_BUCK_PFM_COT_EN        1'b1
        3       RW     CORE_BUCK_ENOFFSAWPFM_H     1'b1
        5:4     R/W    CORE_BUCK_OCPRES_H          2'b01
        8:6     R/W    CORE_BUCK_VREFOCP_H         3'b001
        14:9    R/W    CORE_BUCK_SWRTUNE_H         6'b011101
        18:15   R/W    CORE_BUCK_VREFPFM_H         4'b1011
        24:19   RW     CORE_D300k_REG_MANU_CCOT    6'b010000
        25      R/W    CORE_LDO_ENPC_LDODIGI       1'b0
        31:26   R/W    CORE_BUCK_LDOTUNE_H         6'b0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW4_0;
        struct
        {
            __IO uint32_t CORE_BUCK_FPWM_H: 1;
            __IO uint32_t CORE_BUCK_PFM_AOT_EN: 1;
            __IO uint32_t CORE_BUCK_PFM_COT_EN: 1;
            __IO uint32_t CORE_BUCK_ENOFFSAWPFM_H: 1;
            __IO uint32_t CORE_BUCK_OCPRES_H: 2;
            __IO uint32_t CORE_BUCK_VREFOCP_H: 3;
            __IO uint32_t CORE_BUCK_SWRTUNE_H: 6;
            __IO uint32_t CORE_BUCK_VREFPFM_H: 4;
            __IO uint32_t CORE_D300k_REG_MANU_CCOT: 6;
            __IO uint32_t CORE_LDO_ENPC_LDODIGI: 1;
            __IO uint32_t CORE_BUCK_LDOTUNE_H: 6;
        } BITS_B08;
    } u_B08;

    /* 0xB0C        0x4000_2b0c
        0       R/W    CORE_BUCK_FPWM_H            1'b1
        1       RW     CORE_BUCK_PFM_AOT_EN        1'b0
        2       RW     CORE_BUCK_PFM_COT_EN        1'b1
        3       RW     CORE_BUCK_ENOFFSAWPFM_H     1'b1
        5:4     R/W    CORE_BUCK_OCPRES_H          2'b01
        8:6     R/W    CORE_BUCK_VREFOCP_H         3'b001
        14:9    R/W    CORE_BUCK_SWRTUNE_H         6'b011101
        18:15   R/W    CORE_BUCK_VREFPFM_H         4'b1011
        24:19   RW     CORE_D300k_REG_MANU_CCOT    6'b010000
        25      R/W    CORE_LDO_ENPC_LDODIGI       1'b0
        31:26   R/W    CORE_BUCK_LDOTUNE_H         6'b0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW5_0;
        struct
        {
            __IO uint32_t CORE_BUCK_FPWM_H: 1;
            __IO uint32_t CORE_BUCK_PFM_AOT_EN: 1;
            __IO uint32_t CORE_BUCK_PFM_COT_EN: 1;
            __IO uint32_t CORE_BUCK_ENOFFSAWPFM_H: 1;
            __IO uint32_t CORE_BUCK_OCPRES_H: 2;
            __IO uint32_t CORE_BUCK_VREFOCP_H: 3;
            __IO uint32_t CORE_BUCK_SWRTUNE_H: 6;
            __IO uint32_t CORE_BUCK_VREFPFM_H: 4;
            __IO uint32_t CORE_D300k_REG_MANU_CCOT: 6;
            __IO uint32_t CORE_LDO_ENPC_LDODIGI: 1;
            __IO uint32_t CORE_BUCK_LDOTUNE_H: 6;
        } BITS_B0C;
    } u_B0C;

    /* 0xB10        0x4000_2b10
        0       R/W    CORE_BUCK_FPWM_H            1'b1
        1       RW     CORE_BUCK_PFM_AOT_EN        1'b0
        2       RW     CORE_BUCK_PFM_COT_EN        1'b1
        3       RW     CORE_BUCK_ENOFFSAWPFM_H     1'b1
        5:4     R/W    CORE_BUCK_OCPRES_H          2'b01
        8:6     R/W    CORE_BUCK_VREFOCP_H         3'b001
        14:9    R/W    CORE_BUCK_SWRTUNE_H         6'b011101
        18:15   R/W    CORE_BUCK_VREFPFM_H         4'b1011
        24:19   RW     CORE_D300k_REG_MANU_CCOT    6'b010000
        25      R/W    CORE_LDO_ENPC_LDODIGI       1'b0
        31:26   R/W    CORE_BUCK_LDOTUNE_H         6'b0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW6_0;
        struct
        {
            __IO uint32_t CORE_BUCK_FPWM_H: 1;
            __IO uint32_t CORE_BUCK_PFM_AOT_EN: 1;
            __IO uint32_t CORE_BUCK_PFM_COT_EN: 1;
            __IO uint32_t CORE_BUCK_ENOFFSAWPFM_H: 1;
            __IO uint32_t CORE_BUCK_OCPRES_H: 2;
            __IO uint32_t CORE_BUCK_VREFOCP_H: 3;
            __IO uint32_t CORE_BUCK_SWRTUNE_H: 6;
            __IO uint32_t CORE_BUCK_VREFPFM_H: 4;
            __IO uint32_t CORE_D300k_REG_MANU_CCOT: 6;
            __IO uint32_t CORE_LDO_ENPC_LDODIGI: 1;
            __IO uint32_t CORE_BUCK_LDOTUNE_H: 6;
        } BITS_B10;
    } u_B10;

    /* 0xB14        0x4000_2b14
        0       R/W    CORE_BUCK_FPWM_H            1'b1
        1       RW     CORE_BUCK_PFM_AOT_EN        1'b0
        2       RW     CORE_BUCK_PFM_COT_EN        1'b1
        3       RW     CORE_BUCK_ENOFFSAWPFM_H     1'b1
        5:4     R/W    CORE_BUCK_OCPRES_H          2'b01
        8:6     R/W    CORE_BUCK_VREFOCP_H         3'b001
        14:9    R/W    CORE_BUCK_SWRTUNE_H         6'b011101
        18:15   R/W    CORE_BUCK_VREFPFM_H         4'b1011
        24:19   RW     CORE_D300k_REG_MANU_CCOT    6'b010000
        25      R/W    CORE_LDO_ENPC_LDODIGI       1'b0
        31:26   R/W    CORE_BUCK_LDOTUNE_H         6'b0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW7_0;
        struct
        {
            __IO uint32_t CORE_BUCK_FPWM_H: 1;
            __IO uint32_t CORE_BUCK_PFM_AOT_EN: 1;
            __IO uint32_t CORE_BUCK_PFM_COT_EN: 1;
            __IO uint32_t CORE_BUCK_ENOFFSAWPFM_H: 1;
            __IO uint32_t CORE_BUCK_OCPRES_H: 2;
            __IO uint32_t CORE_BUCK_VREFOCP_H: 3;
            __IO uint32_t CORE_BUCK_SWRTUNE_H: 6;
            __IO uint32_t CORE_BUCK_VREFPFM_H: 4;
            __IO uint32_t CORE_D300k_REG_MANU_CCOT: 6;
            __IO uint32_t CORE_LDO_ENPC_LDODIGI: 1;
            __IO uint32_t CORE_BUCK_LDOTUNE_H: 6;
        } BITS_B14;
    } u_B14;

    /* 0xB18        0x4000_2b18
        1:0     RW     CORE_XTAL_LPS_CAP_STEP      2'b01
        3:2     RW     CORE_XTAL_LPS_CAP_CYC       2'b00
        6:4     RW     CORE_XTAL_OV_UNIT           3'b000
        8:7     RW     CORE_XTAL_OV_RATIO          2'b01
        11:9    RW     CORE_XTAL_MODE              3'b100
        13:12   RW     CORE_XTAL_MODE_DLY          2'b00
        14      RW     CORE_XTAL_MODE_NMPC         1b'0
        15      RW     XTAL_LDOPC_SEL              1'b0
        16      RW     XTAL_GATED_RFP              1'b0
        17      RW     XTAL_GATED_RFN              1'b0
        18      RW     XTAL_GATED_AFEP             1'b0
        19      RW     XTAL_GATED_AFEN             1'b0
        31:20   RW     RSVD                        12'h0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW0_1;
        struct
        {
            __IO uint32_t CORE_XTAL_LPS_CAP_STEP: 2;
            __IO uint32_t CORE_XTAL_LPS_CAP_CYC: 2;
            __IO uint32_t CORE_XTAL_OV_UNIT: 3;
            __IO uint32_t CORE_XTAL_OV_RATIO: 2;
            __IO uint32_t CORE_XTAL_MODE: 3;
            __IO uint32_t CORE_XTAL_MODE_DLY: 2;
            __IO uint32_t CORE_XTAL_MODE_NMPC: 1;
            __IO uint32_t XTAL_LDOPC_SEL: 1;
            __IO uint32_t XTAL_GATED_RFP: 1;
            __IO uint32_t XTAL_GATED_RFN: 1;
            __IO uint32_t XTAL_GATED_AFEP: 1;
            __IO uint32_t XTAL_GATED_AFEN: 1;
            __IO uint32_t RESERVED_0: 12;
        } BITS_B18;
    } u_B18;

    /* 0xB1C        0x4000_2b1c
        1:0     RW     CORE_XTAL_LPS_CAP_STEP      2'b01
        3:2     RW     CORE_XTAL_LPS_CAP_CYC       2'b00
        6:4     RW     CORE_XTAL_OV_UNIT           3'b000
        8:7     RW     CORE_XTAL_OV_RATIO          2'b01
        11:9    RW     CORE_XTAL_MODE              3'b100
        13:12   RW     CORE_XTAL_MODE_DLY          2'b00
        14      RW     CORE_XTAL_MODE_NMPC         1b'0
        15      RW     XTAL_LDOPC_SEL              1'b0
        16      RW     XTAL_GATED_RFP              1'b0
        17      RW     XTAL_GATED_RFN              1'b0
        18      RW     XTAL_GATED_AFEP             1'b0
        19      RW     XTAL_GATED_AFEN             1'b0
        31:20   RW     RSVD                        12'h0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW4_1;
        struct
        {
            __IO uint32_t CORE_XTAL_LPS_CAP_STEP: 2;
            __IO uint32_t CORE_XTAL_LPS_CAP_CYC: 2;
            __IO uint32_t CORE_XTAL_OV_UNIT: 3;
            __IO uint32_t CORE_XTAL_OV_RATIO: 2;
            __IO uint32_t CORE_XTAL_MODE: 3;
            __IO uint32_t CORE_XTAL_MODE_DLY: 2;
            __IO uint32_t CORE_XTAL_MODE_NMPC: 1;
            __IO uint32_t XTAL_LDOPC_SEL: 1;
            __IO uint32_t XTAL_GATED_RFP: 1;
            __IO uint32_t XTAL_GATED_RFN: 1;
            __IO uint32_t XTAL_GATED_AFEP: 1;
            __IO uint32_t XTAL_GATED_AFEN: 1;
            __IO uint32_t RESERVED_0: 12;
        } BITS_B1C;
    } u_B1C;

    /* 0xB20        0x4000_2b20
        1:0     RW     CORE_XTAL_LPS_CAP_STEP      2'b01
        3:2     RW     CORE_XTAL_LPS_CAP_CYC       2'b00
        6:4     RW     CORE_XTAL_OV_UNIT           3'b000
        8:7     RW     CORE_XTAL_OV_RATIO          2'b01
        11:9    RW     CORE_XTAL_MODE              3'b100
        13:12   RW     CORE_XTAL_MODE_DLY          2'b00
        14      RW     CORE_XTAL_MODE_NMPC         1b'0
        15      RW     XTAL_LDOPC_SEL              1'b0
        16      RW     XTAL_GATED_RFP              1'b0
        17      RW     XTAL_GATED_RFN              1'b0
        18      RW     XTAL_GATED_AFEP             1'b0
        19      RW     XTAL_GATED_AFEN             1'b0
        31:20   RW     RSVD                        12'h0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW5_1;
        struct
        {
            __IO uint32_t CORE_XTAL_LPS_CAP_STEP: 2;
            __IO uint32_t CORE_XTAL_LPS_CAP_CYC: 2;
            __IO uint32_t CORE_XTAL_OV_UNIT: 3;
            __IO uint32_t CORE_XTAL_OV_RATIO: 2;
            __IO uint32_t CORE_XTAL_MODE: 3;
            __IO uint32_t CORE_XTAL_MODE_DLY: 2;
            __IO uint32_t CORE_XTAL_MODE_NMPC: 1;
            __IO uint32_t XTAL_LDOPC_SEL: 1;
            __IO uint32_t XTAL_GATED_RFP: 1;
            __IO uint32_t XTAL_GATED_RFN: 1;
            __IO uint32_t XTAL_GATED_AFEP: 1;
            __IO uint32_t XTAL_GATED_AFEN: 1;
            __IO uint32_t RESERVED_0: 12;
        } BITS_B20;
    } u_B20;

    /* 0xB24        0x4000_2b24
        1:0     RW     CORE_XTAL_LPS_CAP_STEP      2'b01
        3:2     RW     CORE_XTAL_LPS_CAP_CYC       2'b00
        6:4     RW     CORE_XTAL_OV_UNIT           3'b000
        8:7     RW     CORE_XTAL_OV_RATIO          2'b01
        11:9    RW     CORE_XTAL_MODE              3'b100
        13:12   RW     CORE_XTAL_MODE_DLY          2'b00
        14      RW     CORE_XTAL_MODE_NMPC         1b'0
        15      RW     XTAL_LDOPC_SEL              1'b0
        16      RW     XTAL_GATED_RFP              1'b0
        17      RW     XTAL_GATED_RFN              1'b0
        18      RW     XTAL_GATED_AFEP             1'b0
        19      RW     XTAL_GATED_AFEN             1'b0
        31:20   RW     RSVD                        12'h0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW6_1;
        struct
        {
            __IO uint32_t CORE_XTAL_LPS_CAP_STEP: 2;
            __IO uint32_t CORE_XTAL_LPS_CAP_CYC: 2;
            __IO uint32_t CORE_XTAL_OV_UNIT: 3;
            __IO uint32_t CORE_XTAL_OV_RATIO: 2;
            __IO uint32_t CORE_XTAL_MODE: 3;
            __IO uint32_t CORE_XTAL_MODE_DLY: 2;
            __IO uint32_t CORE_XTAL_MODE_NMPC: 1;
            __IO uint32_t XTAL_LDOPC_SEL: 1;
            __IO uint32_t XTAL_GATED_RFP: 1;
            __IO uint32_t XTAL_GATED_RFN: 1;
            __IO uint32_t XTAL_GATED_AFEP: 1;
            __IO uint32_t XTAL_GATED_AFEN: 1;
            __IO uint32_t RESERVED_0: 12;
        } BITS_B24;
    } u_B24;

    /* 0xB28        0x4000_2b28
        1:0     RW     CORE_XTAL_LPS_CAP_STEP      2'b01
        3:2     RW     CORE_XTAL_LPS_CAP_CYC       2'b00
        6:4     RW     CORE_XTAL_OV_UNIT           3'b000
        8:7     RW     CORE_XTAL_OV_RATIO          2'b01
        11:9    RW     CORE_XTAL_MODE              3'b100
        13:12   RW     CORE_XTAL_MODE_DLY          2'b00
        14      RW     CORE_XTAL_MODE_NMPC         1b'0
        15      RW     XTAL_LDOPC_SEL              1'b0
        16      RW     XTAL_GATED_RFP              1'b0
        17      RW     XTAL_GATED_RFN              1'b0
        18      RW     XTAL_GATED_AFEP             1'b0
        19      RW     XTAL_GATED_AFEN             1'b0
        31:20   RW     RSVD                        12'h0
    */
    union
    {
        __IO uint32_t REG0X_AUTO_SW7_1;
        struct
        {
            __IO uint32_t CORE_XTAL_LPS_CAP_STEP: 2;
            __IO uint32_t CORE_XTAL_LPS_CAP_CYC: 2;
            __IO uint32_t CORE_XTAL_OV_UNIT: 3;
            __IO uint32_t CORE_XTAL_OV_RATIO: 2;
            __IO uint32_t CORE_XTAL_MODE: 3;
            __IO uint32_t CORE_XTAL_MODE_DLY: 2;
            __IO uint32_t CORE_XTAL_MODE_NMPC: 1;
            __IO uint32_t XTAL_LDOPC_SEL: 1;
            __IO uint32_t XTAL_GATED_RFP: 1;
            __IO uint32_t XTAL_GATED_RFN: 1;
            __IO uint32_t XTAL_GATED_AFEP: 1;
            __IO uint32_t XTAL_GATED_AFEN: 1;
            __IO uint32_t RESERVED_0: 12;
        } BITS_B28;
    } u_B28;

} PERI_BLKCTRL_AUTO_SWITCH_TypeDef;


/* ================================================================================ */
/* ================                     random generator           ================ */
/* ================================================================================ */

/**
  * @brief random generator. (RAN_GEN)
  */

typedef struct                              /*!< RAN_GEN Structure */
{
    union
    {
        __IO uint32_t CTL;                  /*!< 0x00              */
        struct
        {
            __IO uint32_t rand_gen_en: 1;
            __IO uint32_t seed_upd: 1;
            __IO uint32_t random_req: 1;
            __IO uint32_t opt_rand_upd: 1;
            __IO uint32_t soft_rst: 1;
            __IO uint32_t rsvd: 27;
        } CTL_BITS;
    } u_00;
    __IO uint32_t POLYNOMIAL;               /*!< 0x04              */
    __IO uint32_t SEED;                     /*!< 0x08              */
    __IO uint32_t RAN_NUM;                  /*!< 0x0C              */
} RAN_GEN_TypeDef;


/* ================================================================================ */
/* ================    Peripheral Block Control Platform Clock    ================ */
/* ================================================================================ */

/**
  * @brief Peripheral Block Control Platform Clock. (PERI_BLKCTRL_PF_CLK), PERIBLKCTRL_PF_CLK_REG_BASE
  */
/* reference: Bee4_PERI-ON_20221011.xlsx */
typedef struct
{
    /* 0x000        0x4000_2000
        3:0     R/W    r_cpu_div_sel                   4'h4
        4       R/W    r_cpu_div_en                    1'h1
        15:5    R/W    RSVD                            11'h0
        16      R/W    r_cpu_clk_src_sel               1'h0
        17      R/W    RSVD                            1'h0
        20:18   R/W    RSVD                            3'h0
        24:21   R/W    RSVD                            4'h0
        25      R/W    r_cpu_slp_bus_clk_ck_en         1'h1
        26      R/W    r_cpu_clk_src_en                1'h1
        27      R/W    r_cpu_clk_mux_0_cg_en           1'h0
        28      R/W    r_cpu_xtal_clk_cg_en            1'h1
        29      R/W    r_cpu_osc40_clk_cg_en           1'h1
        30      R/W    r_cpu_pll_clk_cg_en             1'h0
        31      R/W    r_cpu_pll_clk_src_sel           1'h0
    */
    union
    {
        __IO uint32_t REG_CPU_CLK_SEL;
        struct
        {
            __IO uint32_t r_cpu_div_sel: 4;
            __IO uint32_t r_cpu_div_en: 1;
            __IO uint32_t RESERVED_3: 11;
            __IO uint32_t r_cpu_clk_src_sel: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 3;
            __IO uint32_t RESERVED_0: 4;
            __IO uint32_t r_cpu_slp_bus_clk_ck_en: 1;
            __IO uint32_t r_cpu_clk_src_en: 1;
            __IO uint32_t r_cpu_clk_mux_0_cg_en: 1;
            __IO uint32_t r_cpu_xtal_clk_cg_en: 1;
            __IO uint32_t r_cpu_osc40_clk_cg_en: 1;
            __IO uint32_t r_cpu_pll_clk_cg_en: 1;
            __IO uint32_t r_cpu_pll_clk_src_sel: 1;
        } BITS_000;
    } u_000;

    /* 0x004        0x4000_2004
        0       R/W    r_cpu_slow_en                   1'h0
        1       R/W    r_cpu_slow_opt_wfi              1'h0
        2       R/W    RSVD                            1'h0
        3       R/W    r_cpu_auto_slow_filter_en       1'h1
        7:4     R/W    r_cpu_div_sel_slow              4'h4
        8       R/W    RSVD                            1'h0
        12:9    R/W    r_cpu_low_rate_valid_num1       4'h3
        13      R/W    r_cpu_div_en_slow               1'h0
        14      R/W    r_cpu_auto_slow_filter1_en      1'h1
        15      R/W    RSVD                            1'h0
        16      R/W    r_cpu_auto_slow_force_update    1'h0
        27:17   R/W    RSVD                            11'h0
        31:28   R/W    r_cpu_low_rate_valid_num        4'h3
    */
    union
    {
        __IO uint32_t REG_CPU_AUTO_SLOW_CTL;
        struct
        {
            __IO uint32_t r_cpu_slow_en: 1;
            __IO uint32_t r_cpu_slow_opt_wfi: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t r_cpu_auto_slow_filter_en: 1;
            __IO uint32_t r_cpu_div_sel_slow: 4;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t r_cpu_low_rate_valid_num1: 4;
            __IO uint32_t r_cpu_div_en_slow: 1;
            __IO uint32_t r_cpu_auto_slow_filter1_en: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t r_cpu_auto_slow_force_update: 1;
            __IO uint32_t RESERVED_0: 11;
            __IO uint32_t r_cpu_low_rate_valid_num: 4;
        } BITS_004;
    } u_004;

    /* 0x008        0x4000_2008
        31:0    R/W    RSVD                            32'h0
    */
    __IO uint32_t REG_DSP_CLK_SEL_1;

    /* 0x00C        0x4000_200c
        2:0     R/W    RSVD                            3'h0
        3       R/W    RSVD                            1'h0
        6:4     R/W    RSVD                            3'h0
        7       R/W    RSVD                            1'h0
        10:8    R/W    RSVD                            3'h0
        11      R/W    RSVD                            1'h0
        14:12   R/W    clk_low_div_sel                 3'h2
        15      R/W    clk_low_div_en                  1'h1
        18:16   R/W    bus_clk_div_sel                 3'h0
        19      R/W    bus_clk_div_en                  1'h1
        20      R/W    r_40m_clk_src_sel               1'h0
        21      R/W    r_40m_clk_ck_en                 1'h1
        31:22   R/W    RSVD                            10'h0
    */
    union
    {
        __IO uint32_t REG_APB_CLK_CTL;
        struct
        {
            __IO uint32_t RESERVED_6: 3;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t RESERVED_4: 3;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 3;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t clk_low_div_sel: 3;
            __IO uint32_t clk_low_div_en: 1;
            __IO uint32_t bus_clk_div_sel: 3;
            __IO uint32_t bus_clk_div_en: 1;
            __IO uint32_t r_40m_clk_src_sel: 1;
            __IO uint32_t r_40m_clk_ck_en: 1;
            __IO uint32_t RESERVED_0: 10;
        } BITS_00C;
    } u_00C;

    /* 0x010        0x4000_2010
        31:0    R/W    dummy_010                       32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_10_CTRL;
        struct
        {
            __IO uint32_t dummy_010: 32;
        } BITS_010;
    } u_010;

    /* 0x014        0x4000_2014
        31:0    R/W    dummy_014                       32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_14_CTRL;
        struct
        {
            __IO uint32_t dummy_014: 32;
        } BITS_014;
    } u_014;

    /* 0x18         0x4000_2018
        0       R/W    wdg_ck_en                       1'h0
        1       R/W    otp_ck_en                       1'h0
        2       R/W    otp_func_en                     1'h0
        3       R/W    data_ram_ck_en                  1'h0
        4       R/W    data_ram_func_en                1'h0
        5       R/W    soc_vendor_ck_en                1'h0
        6       R/W    ctrlap_ck_en                    1'h0
        31:7    R/W    RSVD                            25'h0
    */
    union
    {
        __IO uint32_t REG_PLATFORM_CTRL0;
        struct
        {
            __IO uint32_t wdg_ck_en: 1;
            __IO uint32_t otp_ck_en: 1;
            __IO uint32_t otp_func_en: 1;
            __IO uint32_t data_ram_ck_en: 1;
            __IO uint32_t data_ram_func_en: 1;
            __IO uint32_t soc_vendor_ck_en: 1;
            __IO uint32_t ctrlap_ck_en: 1;
            __IO uint32_t RESERVED_0: 25;
        } BITS_018;
    } u_018;

    __IO uint32_t RSVD_0x1c[2];

    /* 0x24         0x4000_2024
        0       R/W    r_cpu_slow_opt_gdma             1'h0
        1       R/W    r_cpu_slow_opt_ppe              1'h0
        2       R/W    r_cpu_slow_opt_bt_sram          1'h0
        3       R/W    r_cpu_slow_opt_sdio             1'h0
        4       R/W    r_cpu_slow_opt_spic0            1'h0
        5       R/W    r_cpu_slow_opt_spic1            1'h0
        6       R/W    r_cpu_slow_opt_spic2            1'h0
        7       R/W    r_cpu_slow_opt_disp             1'h0
        8       R/W    r_cpu_slow_opt_at_tx            1'h0
        9       R/W    r_cpu_slow_opt_at_rx            1'h0
        10      R/W    r_cpu_slow_opt_usb              1'h0
        11      R/W    r_cpu_slow_opt_gmac             1'h0
        12      R/W    r_cpu_slow_opt_spi0_hs          1'h0
        13      R/W    r_cpu_auto_slow_new0            1'h0
        14      R/W    r_cpu_auto_slow_new1            1'h0
        15      R/W    r_cpu_auto_slow_new2            1'h0
        16      R/W    r_cpu_auto_slow_new3            1'h0
        17      R/W    r_cpu_auto_slow_new4            1'h0
        18      R/W    r_cpu_auto_slow_new5            1'h0
        19      R/W    r_cpu_auto_slow_new6            1'h0
        20      R/W    r_cpu_auto_slow_new7            1'h0
        21      R/W    r_cpu_auto_slow_new8            1'h0
        22      R/W    r_cpu_auto_slow_new9            1'h0
        23      R/W    r_cpu_auto_slow_new10           1'h0
        31:24   R/W    RSVD                            8'h0
    */
    union
    {
        __IO uint32_t REG_AUTO_SLOW_CTRL0;
        struct
        {
            __IO uint32_t r_cpu_slow_opt_gdma: 1;
            __IO uint32_t r_cpu_slow_opt_ppe: 1;
            __IO uint32_t r_cpu_slow_opt_bt_sram: 1;
            __IO uint32_t r_cpu_slow_opt_sdio: 1;
            __IO uint32_t r_cpu_slow_opt_spic0: 1;
            __IO uint32_t r_cpu_slow_opt_spic1: 1;
            __IO uint32_t r_cpu_slow_opt_spic2: 1;
            __IO uint32_t r_cpu_slow_opt_disp: 1;
            __IO uint32_t r_cpu_slow_opt_at_tx: 1;
            __IO uint32_t r_cpu_slow_opt_at_rx: 1;
            __IO uint32_t r_cpu_slow_opt_usb: 1;
            __IO uint32_t r_cpu_slow_opt_gmac: 1;
            __IO uint32_t r_cpu_slow_opt_spi0_hs: 1;
            __IO uint32_t r_cpu_auto_slow_new0: 1;
            __IO uint32_t r_cpu_auto_slow_new1: 1;
            __IO uint32_t r_cpu_auto_slow_new2: 1;
            __IO uint32_t r_cpu_auto_slow_new3: 1;
            __IO uint32_t r_cpu_auto_slow_new4: 1;
            __IO uint32_t r_cpu_auto_slow_new5: 1;
            __IO uint32_t r_cpu_auto_slow_new6: 1;
            __IO uint32_t r_cpu_auto_slow_new7: 1;
            __IO uint32_t r_cpu_auto_slow_new8: 1;
            __IO uint32_t r_cpu_auto_slow_new9: 1;
            __IO uint32_t r_cpu_auto_slow_new10: 1;
            __IO uint32_t RESERVED_0: 8;
        } BITS_024;
    } u_024;

    __IO uint32_t RSVD_0028[1];
    __IO uint32_t RSVD_002c[1];

} PERI_BLKCTRL_PF_CLK_TypeDef;

/* ================================================================================ */
/* ================       Peripheral Block Control Internal       ================ */
/* ================================================================================ */

/**
  * @brief Peripheral Block Control Internal. (PERI_BLKCTRL_INTERNAL), PERIBLKCTRL_INTERNAL_REG_BASE
  */
/* reference: Bee4_PERI-ON_20221201_v1.xlsx.xlsx */
typedef struct
{
    /* 0xC00        0x4000_2c00
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC0;

    /* 0xC04        0x4000_2c04
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC1;

    /* 0xC08        0x4000_2c08
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC2;

    /* 0xC0C        0x4000_2c0c
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC3;

    /* 0xC10        0x4000_2c10
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC4;

    /* 0xC14        0x4000_2c14
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC5;

    /* 0xC18        0x4000_2c18
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC6;

    /* 0xC1C        0x4000_2c1c
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC7;

    /* 0xC20        0x4000_2c20
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC8;

    /* 0xC24        0x4000_2c24
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC9;

    /* 0xC28        0x4000_2c28
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC10;

    /* 0xC2C        0x4000_2c2c
        31:0    R/W    RSVD                    32'h0
    */
    __IO uint32_t REG_MISC11;

    /* 0xC30        0x4000_2c30
        0       R/W    pke_irom_wr_en_fpga     1'h0
        2:1     R/W    sdio_cclk_in_sel_fpga   2'h0
        4:3     R/W    flash_clk_sel_fpga      2'h0
        6:5     R/W    debug_port_sel_fpga     2'h0
        7       R/W    DUMMY2                  1'h0
        9:8     R/W    utmi_clk_sel_fpga       2'h0
        10      R/W    fake_trace_addr_en      1'h1
        15:11   R/W    DUMMY1                  5'h0
        17:16   R/W    occ_debug_en            2'h0
        20:18   R/W    occ_debug_clk_sel0      3'h0
        23:21   R/W    occ_debug_clk_sel1      3'h0
        31:24   R/W    DUMMY                   8'h0
    */
    union
    {
        __IO uint32_t REG_MISC12;
        struct
        {
            __IO uint32_t pke_irom_wr_en_fpga: 1;
            __IO uint32_t sdio_cclk_in_sel_fpga: 2;
            __IO uint32_t flash_clk_sel_fpga: 2;
            __IO uint32_t debug_port_sel_fpga: 2;
            __IO uint32_t DUMMY2: 1;
            __IO uint32_t utmi_clk_sel_fpga: 2;
            __IO uint32_t fake_trace_addr_en: 1;
            __IO uint32_t DUMMY1: 5;
            __IO uint32_t occ_debug_en: 2;
            __IO uint32_t occ_debug_clk_sel0: 3;
            __IO uint32_t occ_debug_clk_sel1: 3;
            __IO uint32_t RESERVED_0: 8;
        } BITS_C30;
    } u_C30;

    __IO uint32_t RSVD_0xc34[2];

    /* 0xC3C        0x4000_2c3c
        0       R/W    pdck_reset_n            1'b0
        1       R/W    EN_XTAL_PDCK_DIGI       1'b0
        2       R/W    PDCK_SEARCH_MODE        1'b0
        4:3     R/W    PDCK_WAIT_CYC           2'b01
        10:5    R/W    VREF_MANUAL             6'h3F
        16:11   R/W    VREF_INIT               6'h3F
        18:17   R/W    XTAL_PDCK_UNIT          2'b01
        24:19   R/W    XPDCK_VREF_SEL          6'h0
        25      R/W    PDCK_LPOW               1'b0
        27:26   R/W    DUMMY3                  2'h0
        31:28   R      pdck_state              4'h0
    */
    union
    {
        __IO uint32_t REG_XTAL_PDCK;
        struct
        {
            __IO uint32_t pdck_reset_n: 1;
            __IO uint32_t EN_XTAL_PDCK_DIGI: 1;
            __IO uint32_t PDCK_SEARCH_MODE: 1;
            __IO uint32_t PDCK_WAIT_CYC: 2;
            __IO uint32_t VREF_MANUAL: 6;
            __IO uint32_t VREF_INIT: 6;
            __IO uint32_t XTAL_PDCK_UNIT: 2;
            __IO uint32_t XPDCK_VREF_SEL: 6;
            __IO uint32_t PDCK_LPOW: 1;
            __IO uint32_t DUMMY3: 2;
            __I uint32_t pdck_state: 4;
        } BITS_C3C;
    } u_C3C;

    /* 0xC40        0x4000_2c40
        0       R/W    TMETER_IN_EN            1'b0
        1       R      TMETER_OK               1'h0
        31:2    R/W    REG_TMETER_DUMMY        30'h0
    */
    union
    {
        __IO uint32_t REG_TMETER;
        struct
        {
            __IO uint32_t TMETER_IN_EN: 1;
            __I uint32_t TMETER_OK: 1;
            __IO uint32_t REG_TMETER_DUMMY: 30;
        } BITS_C40;
    } u_C40;

    __IO uint32_t RSVD_0xc44[1];

    /* 0xC48        0x4000_2c48
        31:0    R      GPIO_RDATA_SCAN         32'h0
    */
    union
    {
        __IO uint32_t REG_MISC15;
        struct
        {
            __I uint32_t GPIO_RDATA_SCAN: 32;
        } BITS_C48;
    } u_C48;

    __IO uint32_t RSVD_0xc4c[5];

    /* 0xC60        0x4000_2c60
        0       RW     rst_n_aac               1'b0
        1       RW     offset_plus             1'b0
        7:2     RW     XAAC_GM_offset          6'h0
        8       RW     GM_STEP                 1'b0
        14:9    RW     GM_INIT                 6'h3F
        17:15   RW     XTAL_CLK_SET            3'b101
        23:18   RW     GM_STUP                 6'h3F
        29:24   RW     GM_MANUAL               6'h1F
        30      RW     r_EN_XTAL_AAC_DIGI      1'b0
        31      RW     r_EN_XTAL_AAC_TRIG      1'b0
    */
    union
    {
        __IO uint32_t REG_AAC_CTRL0;
        struct
        {
            __IO uint32_t rst_n_aac: 1;
            __IO uint32_t offset_plus: 1;
            __IO uint32_t XAAC_GM_offset: 6;
            __IO uint32_t GM_STEP: 1;
            __IO uint32_t GM_INIT: 6;
            __IO uint32_t XTAL_CLK_SET: 3;
            __IO uint32_t GM_STUP: 6;
            __IO uint32_t GM_MANUAL: 6;
            __IO uint32_t r_EN_XTAL_AAC_DIGI: 1;
            __IO uint32_t r_EN_XTAL_AAC_TRIG: 1;
        } BITS_C60;
    } u_C60;

    /* 0xC64        0x4000_2c64
        0       R      XAAC_BUSY               1'b0
        1       R      XAAC_READY              1'b0
        7:2     R      XTAL_GM_OUT             6'h1F
        11:8    R      xaac_curr_state         4'h0
        12      R/W    EN_XTAL_AAC_GM          1'b0
        13      R/W    EN_XTAL_AAC_PKDET       1'b0
        14      R      XTAL_PKDET_OUT          1'b0
        15      R/W    RSVD                    1'b0
        31:16   R/W    RSVD                    16'h0129
    */
    union
    {
        __IO uint32_t REG_AAC_CTRL1;
        struct
        {
            __I uint32_t XAAC_BUSY: 1;
            __I uint32_t XAAC_READY: 1;
            __I uint32_t XTAL_GM_OUT: 6;
            __I uint32_t xaac_curr_state: 4;
            __IO uint32_t EN_XTAL_AAC_GM: 1;
            __IO uint32_t EN_XTAL_AAC_PKDET: 1;
            __I uint32_t XTAL_PKDET_OUT: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 16;
        } BITS_C64;
    } u_C64;

    __IO uint32_t RSVD_0xc68[30];

    /* 0xCE0        0x4000_2ce0
        0       R/W    det_enable              1'b0
        1       R/W    vbus_det                1'b0
        2       R/W    skip_sec_det            1'b0
        3       R/W    DUMMY6                  1'b0
        7:4     R/W    DUMMY5                  4'h0
        8       R      sdp_op5a                1'h0
        9       R      dcp_cdp_1p5a            1'h0
        10      R      cdp_det                 1'h0
        11      R      dcp_det                 1'h0
        12      R      others_op5a             1'h0
        13      R      apple_1p0a              1'h0
        14      R      apple_2p1a              1'h0
        15      R      apple_2p4a              1'h0
        16      R      det_is_done             1'h0
        17      R      note_2p0a               1'h0
        18      R      sony_charger            1'h0
        28:19   R/W    DUMMY4                  9'h0
        29      R/W    dcp_option              1'h1
        30      R/W    bypass_non_std_det      1'h0
        31      R/W    bypass_dcd_dbnc         1'h0
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL1;
        struct
        {
            __IO uint32_t det_enable: 1;
            __IO uint32_t vbus_det: 1;
            __IO uint32_t skip_sec_det: 1;
            __IO uint32_t DUMMY6: 1;
            __IO uint32_t DUMMY5: 4;
            __I uint32_t sdp_op5a: 1;
            __I uint32_t dcp_cdp_1p5a: 1;
            __I uint32_t cdp_det: 1;
            __I uint32_t dcp_det: 1;
            __I uint32_t others_op5a: 1;
            __I uint32_t apple_1p0a: 1;
            __I uint32_t apple_2p1a: 1;
            __I uint32_t apple_2p4a: 1;
            __I uint32_t det_is_done: 1;
            __I uint32_t note_2p0a: 1;
            __I uint32_t sony_charger: 1;
            __IO uint32_t DUMMY4: 10;
            __IO uint32_t dcp_option: 1;
            __IO uint32_t bypass_non_std_det: 1;
            __IO uint32_t bypass_dcd_dbnc: 1;
        } BITS_CE0;
    } u_CE0;

    /* 0xCE4        0x4000_2ce4
        6:0     R/W    fw_write_bus            7'h0
        7       R/W    DUMMY9                  1'h0
        8       R/W    fw_ctrl_mode            1'b0
        15:9    R/W    DUMMY8                  7'h0
        25:16   R      fw_read_bus             10'h0
        31:26   R/W    DUMMY7                  6'h0
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL2;
        struct
        {
            __IO uint32_t fw_write_bus: 7;
            __IO uint32_t DUMMY9: 1;
            __IO uint32_t fw_ctrl_mode: 1;
            __IO uint32_t DUMMY8: 7;
            __I uint32_t fw_read_bus: 10;
            __IO uint32_t DUMMY7: 6;
        } BITS_CE4;
    } u_CE4;

    /* 0xCE8        0x4000_2ce8
        15:0    R/W    DCD_A_MIN_TIME          16'h200
        31:16   R/W    DCD_B_MIN_TIME          16'h3E80
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL3;
        struct
        {
            __IO uint32_t DCD_A_MIN_TIME: 16;
            __IO uint32_t DCD_B_MIN_TIME: 16;
        } BITS_CE8;
    } u_CE8;

    /* 0xCEC        0x4000_2cec
        15:0    R/W    PRI_DET_MIN_TIME        16'h500
        31:16   R/W    NOTE_DET_MIN_TIME       16'h140
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL4;
        struct
        {
            __IO uint32_t PRI_DET_MIN_TIME: 16;
            __IO uint32_t NOTE_DET_MIN_TIME: 16;
        } BITS_CEC;
    } u_CEC;

    /* 0xCF0        0x4000_2cf0
        15:0    R/W    WAIT_A_MIN_TIME         16'h280
        31:16   R/W    SECOND_DET_MIN_TIME     16'h540
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL5;
        struct
        {
            __IO uint32_t WAIT_A_MIN_TIME: 16;
            __IO uint32_t SECOND_DET_MIN_TIME: 16;
        } BITS_CF0;
    } u_CF0;

    /* 0xCF4        0x4000_2cf4
        15:0    R/W    APPLE_DET_MIN_TIME      16'h140
        31:16   R/W    DUMMY10                 16'h0
    */
    union
    {
        __IO uint32_t REG_BC12_CTRL6;
        struct
        {
            __IO uint32_t APPLE_DET_MIN_TIME: 16;
            __IO uint32_t DUMMY10: 16;
        } BITS_CF4;
    } u_CF4;

} PERI_BLKCTRL_INTERNAL_TypeDef;

/* reference: Bee4_PERI-ON_20221017_v2.xlsx */
typedef struct
{
    union
    {
        __IO uint32_t REG_SEC_CTRL0;
        struct
        {
            __IO uint32_t rng_func_en: 1;
            __IO uint32_t rng_ck_en: 1;
            __IO uint32_t rng_sfosc_sel: 1;
            __IO uint32_t rng_sfosc_div_sel: 3;
            __IO uint32_t RESERVED_9: 8;
            __IO uint32_t RESERVED_8: 1;
            __IO uint32_t RESERVED_7: 1;
            __IO uint32_t RESERVED_6: 1;
            __IO uint32_t RESERVED_5: 1;
            __IO uint32_t RESERVED_4: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t sha2_ck_en: 1;
            __IO uint32_t sha2_func_en: 1;
            __IO uint32_t aes_ck_en: 1;
            __IO uint32_t aes_func_en: 1;
            __IO uint32_t pke_ck_en: 1;
            __IO uint32_t pke_func_en: 1;
            __IO uint32_t pke_clk_always_enable: 1;
            __IO uint32_t pke_clk_always_disable: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 2;
        } BITS_400;
    } u_400;

    __IO uint32_t REG_SEC_CTRL1;

    __IO uint32_t REG_SEC_CTRL2;

    __IO uint32_t REG_SEC_CTRL3;

    __IO uint32_t REG_SEC_CTRL4;

    __IO uint32_t REG_SEC_CTRL5;

    __IO uint32_t REG_SEC_CTRL6;

    __IO uint32_t REG_SEC_CTRL7;

} SECURE_PERIPHERAL_CLOCK_CONTROL_TypeDef;

/**
  * @brief Peripheral. (Peripheral)
  */
/* ================================================================================ */
/* ================                   PERI_ON     0x40000200              ================ */
/* ================================================================================ */
typedef struct                                      /*!< Peripheral Structure */
{
    __IO uint32_t    SYS_CLK_SEL;       /*!< 0x200 */
    __IO uint32_t    SYS_CLK_SEL_2;     /*!< 0x204 */
    __IO uint32_t    SYS_CLK_SEL_3;     /*!< 0x208 */
    __IO uint32_t    r_PON_FUN0_EN;     /*!< 0x210 */
    __IO uint32_t    RSVD0;             /*!< 0x214 */
} PHERION_TypeDef;

/* ================================================================================ */
/* ================              Peripheral Interrupt              ================ */
/* ================================================================================ */
#define PERI_IRQ_BIT_MBIAS_MFB_DET_L     BIT0
#define PERI_IRQ_BIT_mailbox_int         BIT1
#define PERI_IRQ_BIT_utmi_suspend_n      BIT2
#define PERI_IRQ_BIT_dig_trda_int_r      BIT3
#define PERI_IRQ_BIT_rng_int             BIT4
#define PERI_IRQ_BIT_psram_intr          BIT5
#define PERI_IRQ_BIT_dig_lpcomp_int_r    BIT6
#define PERI_IRQ_BIT_timer_intr_5        BIT7
#define PERI_IRQ_BIT_timer_intr_6        BIT8
#define PERI_IRQ_BIT_timer_intr_7        BIT9
#define PERI_IRQ_BIT_dig_lpcomp_int      BIT11
#define PERI_IRQ_BIT_MBIAS_VBAT_DET_L    BIT12
#define PERI_IRQ_BIT_MBIAS_ADP_DET_L     BIT13
#define PERI_IRQ_BIT_HW_ASRC_ISR1        BIT14
#define PERI_IRQ_BIT_HW_ASRC_ISR2        BIT15
#define PERI_IRQ_BIT_gpio_intr_31_6      BIT16
#define PERI_IRQ_BIT_dsp_wdt_to_mcu_intr BIT18
#define PERI_IRQ_BIT_flash_pwr_intr      BIT19
#define PERI_IRQ_BIT_sp0_intr_tx         BIT25
#define PERI_IRQ_BIT_sp0_intr_rx         BIT26
#define PERI_IRQ_BIT_sp1_intr_tx         BIT27
#define PERI_IRQ_BIT_sp1_intr_rx         BIT28

typedef enum
{
    TRIGGER_MODE_HGIH_LEVEL,
    TRIGGER_MODE_EDGE,
} TRIGGER_MODE;

typedef enum
{
    EDGE_MODE_RISING,
    EDGE_MODE_BOTH,
} EDGE_MODE;



/**
  * @brief SoC Vendor, SOC_VENDOR_REG_BASE
  */
/* reference: Bee4_Reg_SoC_202201012_v0.xlsx */
typedef struct
{
    /* 0x0000       0x4000_3000
        31:0    R/W    RSVD                            32'h0
    */
    __IO uint32_t RSVD_0000;

    /* 0x0004       0x4000_3004
        0       R/W1C  spic0_intr_r                    1'h0
        1       R/W1C  spic1_intr_r                    1'h0
        2       R/W1C  spic2_intr_r                    1'h0
        3       R/W1C  trng_intr_r                     1'h0
        4       R/W1C  lpcomp_intr_r                   1'h0
        5       R/W1C  spi_phy1_intr_r                 1'h0
        30:6    R      RSVD                            25'h0
        31      R/W1C  utmi_suspend_n_r                1'h0
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_STATUS;
        struct
        {
            __IO uint32_t spic0_intr_r: 1;
            __IO uint32_t spic1_intr_r: 1;
            __IO uint32_t spic2_intr_r: 1;
            __IO uint32_t trng_intr_r: 1;
            __IO uint32_t lpcomp_intr_r: 1;
            __IO uint32_t spi_phy1_intr_r: 1;
            __I uint32_t RESERVED_0: 25;
            __IO uint32_t utmi_suspend_n_r: 1;
        } BITS_004;
    } u_004;

    /* 0x0008       0x4000_3008
        31:0    R/W    low_pri_int_mode                32'hFFFFFFFF
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_MODE;
        struct
        {
            __IO uint32_t low_pri_int_mode: 32;
        } BITS_008;
    } u_008;

    /* 0x000C       0x4000_300c
        31:0    R/W    low_pri_int_en                  32'h0
    */
    union
    {
        __IO uint32_t REG_LOW_PRI_INT_EN;
        struct
        {
            __IO uint32_t low_pri_int_en: 32;
        } BITS_00C;
    } u_00C;

    /* 0x0010       0x4000_3010
        0       R      timer_intr1_intr0_r             1'h0
        1       R      bluewiz_intr_r                  1'h0
        2       R      RSVD                            1'h0
        3       R      bluewiz_dma_intr_r              1'h0
        4       R      pro_intr_r                      1'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t BT_MAC_INTERRUPT;
        struct
        {
            __I uint32_t timer_intr1_intr0_r: 1;
            __I uint32_t bluewiz_intr_r: 1;
            __I uint32_t RESERVED_1: 1;
            __I uint32_t bluewiz_dma_intr_r: 1;
            __I uint32_t pro_intr_r: 1;
            __I uint32_t RESERVED_0: 27;
        } BITS_010;
    } u_010;

    /* 0x0014       0x4000_3014
        23:0     R       RSVD                                           24'h0
        26:24    R/W     RSVD                                           3'h0
        31:27    R       RSVD                                           5'h0
    */
    union
    {
        __IO uint32_t RXI_INTERRUPT;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_014;
    } u_014;

    /* 0x0018       0x4000_3018
        31:0    R/W    low_pri_int_pol                 32'h0
    */
    union
    {
        __IO uint32_t INTERRUPT_EDGE_OPTION;
        struct
        {
            __IO uint32_t low_pri_int_pol: 32;
        } BITS_018;
    } u_018;

    /* 0x001C       0x4000_301c
        11:0    RW     debug_sel                       12'h0
        15:12   R      RSVD                            4'h0
        23:16   R/W    can_dbg_sel                     8'h0
        24      R/W    can_dbg_en                      1'h0
        28:25   R      RSVD                            4'h0
        29      R/W    spi_speed_up_sim                1'h0
        30      R      RSVD                            1'h0
        31      R/W    RSVD                            1'h0
    */
    union
    {
        __IO uint32_t REG_DEBUG_SEL;
        struct
        {
            __IO uint32_t debug_sel: 12;
            __I uint32_t RESERVED_3: 4;
            __IO uint32_t can_dbg_sel: 8;
            __IO uint32_t can_dbg_en: 1;
            __I uint32_t RESERVED_2: 4;
            __IO uint32_t spi_speed_up_sim: 1;
            __I uint32_t RESERVED_1: 1;
            __IO uint32_t RESERVED_0: 1;
        } BITS_01C;
    } u_01C;

    /* 0x0014       0x4000_3014
        11:0     R       RSVD                                           12'h0
        31:12    R/W     RSVD                                           12'h0
    */
    union
    {
        __IO uint32_t REG_DATA_FIFO_SWAP_CTRL;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_020;
    } u_020;

    /* 0x0024       0x4000_3024
        0       R      timer0_toggle                   1'h0
        1       R      timer1_toggle                   1'h0
        2       R      timer2_toggle                   1'h0
        3       R      timer3_toggle                   1'h0
        4       R      timer4_toggle                   1'h0
        5       R      timer5_toggle                   1'h0
        6       R      timer6_toggle                   1'h0
        7       R      timer7_toggle                   1'h0
        8       R/W    spic0_mem_wr_en                 1'h0
        9       R/W    spic1_mem_wr_en                 1'h0
        10      R/W    spic2_mem_wr_en                 1'h0
        11      W1O    spic_mem_wr_lock                1'h0
        12      R/W    RSVD                            1'h0
        13      R/W    RSVD                            1'h0
        14      R/W    dmac_clk_always_disable         1'h0
        15      R/W    dmac_clk_always_enable          1'h1
        16      R/W    RSVD                            1'h0
        24:17   W1O    timer_dma_en                    1'h0
        26:25   R/W    uart_force_cg_en                2'h3
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t REG_MISC;
        struct
        {
            __I uint32_t timer0_toggle: 1;
            __I uint32_t timer1_toggle: 1;
            __I uint32_t timer2_toggle: 1;
            __I uint32_t timer3_toggle: 1;
            __I uint32_t timer4_toggle: 1;
            __I uint32_t timer5_toggle: 1;
            __I uint32_t timer6_toggle: 1;
            __I uint32_t timer7_toggle: 1;
            __IO uint32_t spic0_mem_wr_en: 1;
            __IO uint32_t spic1_mem_wr_en: 1;
            __IO uint32_t spic2_mem_wr_en: 1;
            __IO uint32_t spic_mem_wr_lock: 1;
            __IO uint32_t RESERVED_3: 1;
            __IO uint32_t RESERVED_2: 1;
            __IO uint32_t dmac_clk_always_disable: 1;
            __IO uint32_t dmac_clk_always_enable: 1;
            __IO uint32_t RESERVED_1: 1;
            __IO uint32_t timer_dma_en: 8;
            __IO uint32_t uart_force_cg_en: 2;
            __I uint32_t RESERVED_0: 5;
        } BITS_024;
    } u_024;

    /* 0x0028       0x4000_3028
        0       R/W    spic0_dma_tx_sel                1'h0
        1       R/W    spic0_dma_rx_sel                1'h0
        2       R/W    spic1_dma_tx_sel                1'h0
        3       R/W    spic1_dma_rx_sel                1'h0
        4       R/W    spic2_dma_tx_sel                1'h0
        5       R/W    spic2_dma_rx_sel                1'h0
        31:6    R      RSVD                            26'h0
    */
    union
    {
        __IO uint32_t REG_SPIC_DMAC_HS_SHARE;
        struct
        {
            __IO uint32_t spic0_dma_tx_sel: 1;
            __IO uint32_t spic0_dma_rx_sel: 1;
            __IO uint32_t spic1_dma_tx_sel: 1;
            __IO uint32_t spic1_dma_rx_sel: 1;
            __IO uint32_t spic2_dma_tx_sel: 1;
            __IO uint32_t spic2_dma_rx_sel: 1;
            __I uint32_t RESERVED_0: 26;
        } BITS_028;
    } u_028;

    /* 0x002C       0x4000_302c
        31:0    R      RSVD                            32'h0
    */
    union
    {
        __IO uint32_t REG_DMAC_SUSPEND_RESUME;
        struct
        {
            __I uint32_t RESERVED_0: 32;
        } BITS_02C;
    } u_02C;

    /* 0x0030       0x4000_3030
        0       R      km4_mve_inactive                1'h1
        1       R      km4_pbus_inactive               1'h1
        2       R      km4_tcm_dma_inactive            1'h1
        3       R      rxi350_dmac0_inactive           1'h1
        4       R      spic0_inactive                  1'h1
        5       R      spic1_inactive                  1'h1
        6       R      spic2_inactive                  1'h1
        7       R      spic0_mem_inactive              1'h1
        8       R      spic1_mem_inactive              1'h1
        9       R      spic2_mem_inactive              1'h1
        10      R      ppe_inactive                    1'h1
        11      R      display_inactive                1'h1
        12      R      usbotg_inactive                 1'h1
        13      R      sdio_host0_inactive             1'h1
        14      R      gmac_inactive                   1'h1
        15      R      gmac_ctrl_inactive              1'h1
        31:16   R      RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_PLATFORM_STATUS;
        struct
        {
            __I uint32_t km4_mve_inactive: 1;
            __I uint32_t km4_pbus_inactive: 1;
            __I uint32_t km4_tcm_dma_inactive: 1;
            __I uint32_t rxi350_dmac0_inactive: 1;
            __I uint32_t spic0_inactive: 1;
            __I uint32_t spic1_inactive: 1;
            __I uint32_t spic2_inactive: 1;
            __I uint32_t spic0_mem_inactive: 1;
            __I uint32_t spic1_mem_inactive: 1;
            __I uint32_t spic2_mem_inactive: 1;
            __I uint32_t ppe_inactive: 1;
            __I uint32_t display_inactive: 1;
            __I uint32_t usbotg_inactive: 1;
            __I uint32_t sdio_host0_inactive: 1;
            __I uint32_t gmac_inactive: 1;
            __I uint32_t gmac_ctrl_inactive: 1;
            __I uint32_t RESERVED_0: 16;
        } BITS_030;
    } u_030;

    /* 0x0034       0x4000_3034
        0       R/W    km4_nmi_ctrl_enable             1'h0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_NMI_CTRL;
        struct
        {
            __IO uint32_t km4_nmi_ctrl_enable: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_034;
    } u_034;

    __IO uint32_t RSVD_0x38[5];

    /* 0x004C       0x4000_304c
        0       R/W    data_ram_err_flag_en            1'h0
        1       R/W    data_ram_err_int_en             1'h0
        2       R/W    data_ram_err_flag_clr           1'h0
        3       R/W    data_ram_err_int_clr            1'h0
        10:4    R      RSVD                            7'h0
        27:11   R      data_ram_err_flag_addr          17'h0
        28      R      data_ram_err_flag_we            1'h0
        29      R      data_ram_err_flag_re            1'h0
        30      R      data_ram_err_flag_valid         1'h0
        31      R      data_ram_err_int                1'h0
    */
    union
    {
        __IO uint32_t REG_DATA_RAM_ERR_FLAG;
        struct
        {
            __IO uint32_t data_ram_err_flag_en: 1;
            __IO uint32_t data_ram_err_int_en: 1;
            __IO uint32_t data_ram_err_flag_clr: 1;
            __IO uint32_t data_ram_err_int_clr: 1;
            __I uint32_t RESERVED_0: 7;
            __I uint32_t data_ram_err_flag_addr: 17;
            __I uint32_t data_ram_err_flag_we: 1;
            __I uint32_t data_ram_err_flag_re: 1;
            __I uint32_t data_ram_err_flag_valid: 1;
            __I uint32_t data_ram_err_int: 1;
        } BITS_04C;
    } u_04C;

    /* 0x0050       0x4000_3050
        31:0    R/W    km4_keep_0                      32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_KEEP_0_BOUNDARY;
        struct
        {
            __IO uint32_t km4_keep_0: 32;
        } BITS_050;
    } u_050;

    /* 0x0054       0x4000_3054
        31:0    R/W    km4_keep_1                      32'hFFFFFFFF
    */
    union
    {
        __IO uint32_t REG_KM4_KEEP_1_BOUNDARY;
        struct
        {
            __IO uint32_t km4_keep_1: 32;
        } BITS_054;
    } u_054;

    /* 0x0058       0x4000_3058
        31:0    R/W    km4_initpbusrange               32'h4000E000
    */
    union
    {
        __IO uint32_t REG_KM4_INITPBUSRANGE;
        struct
        {
            __IO uint32_t km4_initpbusrange: 32;
        } BITS_058;
    } u_058;

    /* 0x005C       0x4000_305c
        31:0    R/W    km4_initzwfrange                32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_INITZWFRANGE;
        struct
        {
            __IO uint32_t km4_initzwfrange: 32;
        } BITS_05C;
    } u_05C;

    /* 0x0060       0x4000_3060
        26:0    R/W    km4_init_xo_range_top           27'h00000ff
        27      R/W    km4_init_xo_range_en            1'h1
        28      W1O    km4_xo_range_lock               1'h0
        31:29   R      RSVD                            3'h0
    */
    union
    {
        __IO uint32_t REG_KM4_XO_CFG_0;
        struct
        {
            __IO uint32_t km4_init_xo_range_top: 27;
            __IO uint32_t km4_init_xo_range_en: 1;
            __IO uint32_t km4_xo_range_lock: 1;
            __I uint32_t RESERVED_0: 3;
        } BITS_060;
    } u_060;

    /* 0x0064       0x4000_3064
        26:0    R/W    km4_init_xo_range_base          27'h0
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t REG_KM4_XO_CFG_1;
        struct
        {
            __IO uint32_t km4_init_xo_range_base: 27;
            __I uint32_t RESERVED_0: 5;
        } BITS_064;
    } u_064;

    /* 0x0068       0x4000_3068
        0       R/W    km4_retention_mode              1'h0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_RET_CFG_0;
        struct
        {
            __IO uint32_t km4_retention_mode: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_068;
    } u_068;

    /* 0x006C       0x4000_306c
        0       R/W    r_km4_dvfs_en                   1'h0
        31:1   R      RSVD                             31'h0
    */
    union
    {
        __IO uint32_t REG_KM4_DVFS_CTRL;
        struct
        {
            __IO uint32_t r_km4_dvfs_en: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_06C;
    } u_06C;

    /* 0x0070       0x4000_3070
        29:0    R      RSVD                            30'h0
        30      R/W    ppe_clk_always_disable          1'h0
        31      R/W    ppe_clk_always_enable           1'h1
    */
    union
    {
        __IO uint32_t REG_PPE_CTRL;
        struct
        {
            __I uint32_t RESERVED_0: 30;
            __IO uint32_t ppe_clk_always_disable: 1;
            __IO uint32_t ppe_clk_always_enable: 1;
        } BITS_070;
    } u_070;

    __IO uint32_t RSVD_0x74[3];

    /* 0x0080       0x4000_3080
        0       R/W    r_sys_32bits_timer_rst_sel      1'h1
        1       R/W    r_sys_32bits_timer_manual_rstb  1'h0
        31:2    R      RSVD                            30'h0
    */
    union
    {
        __IO uint32_t REG_KM4_SYS_CNT_CFG_0;
        struct
        {
            __IO uint32_t r_sys_32bits_timer_rst_sel: 1;
            __IO uint32_t r_sys_32bits_timer_manual_rstb: 1;
            __I uint32_t RESERVED_0: 30;
        } BITS_080;
    } u_080;

    /* 0x0084       0x4000_3084
        31:0    R      cpu_sys_32bits_timer_cnt        32'h0
    */
    union
    {
        __IO uint32_t REG_KM4_SYS_CNT_CFG_1;
        struct
        {
            __I uint32_t cpu_sys_32bits_timer_cnt: 32;
        } BITS_084;
    } u_084;

    /* 0x0088       0x4000_3088
        0       R/W    r_epalna_od                     1'b0
        31:1    R      RSVD                            31'h0
    */
    union
    {
        __IO uint32_t REG_TESTMODE_SEL_RF;
        struct
        {
            __IO uint32_t r_epalna_od: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_088;
    } u_088;

    __IO uint32_t RSVD_0x8c[1];

    /* 0x0090       0x4000_3090
        31:0    R/W    OUT_DATA0                       32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_0;
        struct
        {
            __IO uint32_t OUT_DATA0: 32;
        } BITS_090;
    } u_090;

    /* 0x0094       0x4000_3094
        31:0    R/W    OUT_DATA1                       32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_1;
        struct
        {
            __IO uint32_t OUT_DATA1: 32;
        } BITS_094;
    } u_094;

    /* 0x0098       0x4000_3098
        31:0    R      IN_DATA0                        32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_2;
        struct
        {
            __I uint32_t IN_DATA0: 32;
        } BITS_098;
    } u_098;

    /* 0x009C       0x4000_309c
        31:0    R      IN_DATA1                        32'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_3;
        struct
        {
            __I uint32_t IN_DATA1: 32;
        } BITS_09C;
    } u_09C;

    /* 0x00A0       0x4000_30a0
        0       WAC    outbox_rdy_r                    1'h0
        1       R/W    out_empty_inten                 1'h0
        2       R/W    out_int_mode                    1'h0
        3       W1C    out_edge_sts                    1'h0
        4       R      rx_data_crc_ok                  1'h0
        15:5    R      RSVD                            11'h0
        16      W1C    inbox_rdy_r                     1'h0
        17      R/W    in_rdy_inten                    1'h0
        30:18   R      RSVD                            13'h0
        31      R/W    pta_i2c_en                      1'h0
    */
    union
    {
        __IO uint32_t REG_I2C_MAILBOX_4;
        struct
        {
            __IO uint32_t outbox_rdy_r: 1;
            __IO uint32_t out_empty_inten: 1;
            __IO uint32_t out_int_mode: 1;
            __IO uint32_t out_edge_sts: 1;
            __I uint32_t rx_data_crc_ok: 1;
            __I uint32_t RESERVED_1: 11;
            __IO uint32_t inbox_rdy_r: 1;
            __IO uint32_t in_rdy_inten: 1;
            __I uint32_t RESERVED_0: 13;
            __IO uint32_t pta_i2c_en: 1;
        } BITS_0A0;
    } u_0A0;

    __IO uint32_t RSVD_0xa4[5];

    /* 0x00B8       0x4000_30b8
        0       R/W    reg_fwpi_enable                 1'h1
        31:1    R      RSVD                            30'h0
    */
    union
    {
        __IO uint32_t REG_MODEMRFCPI_APB_WRAPPER;
        struct
        {
            __IO uint32_t reg_fwpi_enable: 1;
            __I uint32_t RESERVED_0: 31;
        } BITS_0B8;
    } u_0B8;

    __IO uint32_t RSVD_0xbc[1];

    /* 0x00C0       0x4000_30c0
        31:0    R/W    reg_enhtimer_0_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_0_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_0_latch_trig_0_sel: 32;
        } BITS_0C0;
    } u_0C0;

    /* 0x00C4       0x4000_30c4
        31:0    R/W    reg_enhtimer_1_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_1_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_1_latch_trig_0_sel: 32;
        } BITS_0C4;
    } u_0C4;

    /* 0x00C8       0x4000_30c8
        31:0    R/W    reg_enhtimer_2_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_2_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_2_latch_trig_0_sel: 32;
        } BITS_0C8;
    } u_0C8;

    /* 0x00CC       0x4000_30cc
        31:0    R/W    reg_enhtimer_3_latch_trig_0_sel 32'h0
    */
    union
    {
        __IO uint32_t REG_ENHTIMER_3_LATCH_TRIG_0_SEL;
        struct
        {
            __IO uint32_t reg_enhtimer_3_latch_trig_0_sel: 32;
        } BITS_0CC;
    } u_0CC;

    /* 0x00D0       0x4000_30d0
        2:0     R/W    reg_bt_gpio_trig_sel            3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_GPIO_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_gpio_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D0;
    } u_0D0;

    /* 0x00D4       0x4000_30d4
        2:0     R/W    reg_bt_tx_on_trig_sel           3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_TX_ON_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_tx_on_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D4;
    } u_0D4;

    /* 0x00D8       0x4000_30d8
        2:0     R/W    reg_bt_acc_hit_trig_sel         3'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_BT_ACC_HIT_TRIG_ENHTIMER_CTRL;
        struct
        {
            __IO uint32_t reg_bt_acc_hit_trig_sel: 3;
            __IO uint32_t RESERVED_0: 29;
        } BITS_0D8;
    } u_0D8;

    __IO uint32_t RSVD_0xdc[5];

    /* 0x00F0       0x4000_30f0
        31:0    R/W    soc_vendor_dummy_reg_0          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_0;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_0: 32;
        } BITS_0F0;
    } u_0F0;

    /* 0x00F4       0x4000_30f4
        31:0    R/W    soc_vendor_dummy_reg_1          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_1;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_1: 32;
        } BITS_0F4;
    } u_0F4;

    /* 0x00F8       0x4000_30f8
        31:0    R/W    soc_vendor_dummy_reg_2          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_2;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_2: 32;
        } BITS_0F8;
    } u_0F8;

    /* 0x00FC       0x4000_30fc
        31:0    R/W    soc_vendor_dummy_reg_3          32'h0
    */
    union
    {
        __IO uint32_t REG_DUMMY_3;
        struct
        {
            __IO uint32_t soc_vendor_dummy_reg_3: 32;
        } BITS_0FC;
    } u_0FC;

    /* 0x0100       0x4000_3100
        15:0    R/W    km4_wdt_wp                      16'h0
        31:16   R/W    RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_WP;
        struct
        {
            __IO uint32_t km4_wdt_wp: 16;
            __IO uint32_t RESERVED_0: 16;
        } BITS_100;
    } u_100;

    /* 0x0104       0x4000_3104
        15:0    R/W    km4_wdt_clk_div_factor          16'hC80
        27:16   R/W    km4_wdt_cnt_limit               12'h64
        29:28   R/W    km4_wdt_mode                    2'h3
        30      R/W1C  km4_wdt_timeout_flag            1'h0
        31      R/W    km4_wdt_enable                  1'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_CONFIG;
        struct
        {
            __IO uint32_t km4_wdt_clk_div_factor: 16;
            __IO uint32_t km4_wdt_cnt_limit: 12;
            __IO uint32_t km4_wdt_mode: 2;
            __IO uint32_t km4_wdt_timeout_flag: 1;
            __IO uint32_t km4_wdt_enable: 1;
        } BITS_104;
    } u_104;

    /* 0x0108       0x4000_3108
        15:0    R/WAC  km4_wdt_cnt_reset               16'h0
        31:16   R/WAC  RSVD                            16'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_CNT_RESET;
        struct
        {
            __IO uint32_t km4_wdt_cnt_reset: 16;
            __IO uint32_t RESERVED_0: 16;
        } BITS_108;
    } u_108;

    /* 0x010C       0x4000_310c
        0       R/W    km4_wdt_wp_sec                  1'h0
        1       R/W    km4_wdt_config_sec              1'h0
        2       R/W    km4_wdt_cnt_reset_sec           1'h0
        31:3    R/W    RSVD                            29'h0
    */
    union
    {
        __IO uint32_t REG_KM4_WDT_SEC;
        struct
        {
            __IO uint32_t km4_wdt_wp_sec: 1;
            __IO uint32_t km4_wdt_config_sec: 1;
            __IO uint32_t km4_wdt_cnt_reset_sec: 1;
            __IO uint32_t RESERVED_0: 29;
        } BITS_10C;
    } u_10C;

    __IO uint32_t RSVD_0x110[60];

    /* 0x200        0x4000_3200
        0       R      bt_mac_1024x16_drf_start_pause  1'h0
        1       R      bt_mac_1024x16_drf_bist_fail    1'h0
        2       R      bt_mac_1024x16_drf_bist_done    1'h0
        3       R      bt_mac_1024x16_bist_fail        1'h0
        4       R      bt_mac_1024x16_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_1024x16_bist_grp_en      1'h0
        26      R/W    bt_mac_1024x16_dyn_read_en      1'h0
        27      R/W    bt_mac_1024x16_bist_loop_mode   1'h0
        28      R/W    bt_mac_1024x16_drf_test_resume  1'h0
        29      R/W    bt_mac_1024x16_drf_bist_mode    1'h0
        30      R/W    bt_mac_1024x16_bist_mode        1'h0
        31      R/W    bt_mac_1024x16_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x200;
        struct
        {
            __I uint32_t bt_mac_1024x16_drf_start_pause: 1;
            __I uint32_t bt_mac_1024x16_drf_bist_fail: 1;
            __I uint32_t bt_mac_1024x16_drf_bist_done: 1;
            __I uint32_t bt_mac_1024x16_bist_fail: 1;
            __I uint32_t bt_mac_1024x16_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_1024x16_bist_grp_en: 1;
            __IO uint32_t bt_mac_1024x16_dyn_read_en: 1;
            __IO uint32_t bt_mac_1024x16_bist_loop_mode: 1;
            __IO uint32_t bt_mac_1024x16_drf_test_resume: 1;
            __IO uint32_t bt_mac_1024x16_drf_bist_mode: 1;
            __IO uint32_t bt_mac_1024x16_bist_mode: 1;
            __IO uint32_t bt_mac_1024x16_bist_rstn: 1;
        } BITS_200;
    } u_200;

    /* 0x204        0x4000_3204
        0       R      bt_mac_512x16_drf_start_pause   1'h0
        1       R      bt_mac_512x16_drf_bist_fail     1'h0
        2       R      bt_mac_512x16_drf_bist_done     1'h0
        3       R      bt_mac_512x16_bist_fail         1'h0
        4       R      bt_mac_512x16_bist_done         1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_512x16_bist_grp_en       1'h0
        26      R/W    bt_mac_512x16_dyn_read_en       1'h0
        27      R/W    bt_mac_512x16_bist_loop_mode    1'h0
        28      R/W    bt_mac_512x16_drf_test_resume   1'h0
        29      R/W    bt_mac_512x16_drf_bist_mode     1'h0
        30      R/W    bt_mac_512x16_bist_mode         1'h0
        31      R/W    bt_mac_512x16_bist_rstn         1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x204;
        struct
        {
            __I uint32_t bt_mac_512x16_drf_start_pause: 1;
            __I uint32_t bt_mac_512x16_drf_bist_fail: 1;
            __I uint32_t bt_mac_512x16_drf_bist_done: 1;
            __I uint32_t bt_mac_512x16_bist_fail: 1;
            __I uint32_t bt_mac_512x16_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_512x16_bist_grp_en: 1;
            __IO uint32_t bt_mac_512x16_dyn_read_en: 1;
            __IO uint32_t bt_mac_512x16_bist_loop_mode: 1;
            __IO uint32_t bt_mac_512x16_drf_test_resume: 1;
            __IO uint32_t bt_mac_512x16_drf_bist_mode: 1;
            __IO uint32_t bt_mac_512x16_bist_mode: 1;
            __IO uint32_t bt_mac_512x16_bist_rstn: 1;
        } BITS_204;
    } u_204;

    /* 0x208        0x4000_3208
        0       R      bt_mac_128x32_0_drf_start_pause 1'h0
        1       R      bt_mac_128x32_0_drf_bist_fail   1'h0
        2       R      bt_mac_128x32_0_drf_bist_done   1'h0
        3       R      bt_mac_128x32_0_bist_fail       1'h0
        4       R      bt_mac_128x32_0_bist_done       1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_128x32_0_bist_grp_en     1'h0
        26      R/W    bt_mac_128x32_0_dyn_read_en     1'h0
        27      R/W    bt_mac_128x32_0_bist_loop_mode  1'h0
        28      R/W    bt_mac_128x32_0_drf_test_resume 1'h0
        29      R/W    bt_mac_128x32_0_drf_bist_mode   1'h0
        30      R/W    bt_mac_128x32_0_bist_mode       1'h0
        31      R/W    bt_mac_128x32_0_bist_rstn       1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x208;
        struct
        {
            __I uint32_t bt_mac_128x32_0_drf_start_pause: 1;
            __I uint32_t bt_mac_128x32_0_drf_bist_fail: 1;
            __I uint32_t bt_mac_128x32_0_drf_bist_done: 1;
            __I uint32_t bt_mac_128x32_0_bist_fail: 1;
            __I uint32_t bt_mac_128x32_0_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_128x32_0_bist_grp_en: 1;
            __IO uint32_t bt_mac_128x32_0_dyn_read_en: 1;
            __IO uint32_t bt_mac_128x32_0_bist_loop_mode: 1;
            __IO uint32_t bt_mac_128x32_0_drf_test_resume: 1;
            __IO uint32_t bt_mac_128x32_0_drf_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_0_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_0_bist_rstn: 1;
        } BITS_208;
    } u_208;

    /* 0x20C        0x4000_320c
        0       R      bt_mac_128x32_1_drf_start_pause 1'h0
        1       R      bt_mac_128x32_1_drf_bist_fail   1'h0
        2       R      bt_mac_128x32_1_drf_bist_done   1'h0
        3       R      bt_mac_128x32_1_bist_fail       1'h0
        4       R      bt_mac_128x32_1_bist_done       1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_128x32_1_bist_grp_en     1'h0
        26      R/W    bt_mac_128x32_1_dyn_read_en     1'h0
        27      R/W    bt_mac_128x32_1_bist_loop_mode  1'h0
        28      R/W    bt_mac_128x32_1_drf_test_resume 1'h0
        29      R/W    bt_mac_128x32_1_drf_bist_mode   1'h0
        30      R/W    bt_mac_128x32_1_bist_mode       1'h0
        31      R/W    bt_mac_128x32_1_bist_rstn       1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x20C;
        struct
        {
            __I uint32_t bt_mac_128x32_1_drf_start_pause: 1;
            __I uint32_t bt_mac_128x32_1_drf_bist_fail: 1;
            __I uint32_t bt_mac_128x32_1_drf_bist_done: 1;
            __I uint32_t bt_mac_128x32_1_bist_fail: 1;
            __I uint32_t bt_mac_128x32_1_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_128x32_1_bist_grp_en: 1;
            __IO uint32_t bt_mac_128x32_1_dyn_read_en: 1;
            __IO uint32_t bt_mac_128x32_1_bist_loop_mode: 1;
            __IO uint32_t bt_mac_128x32_1_drf_test_resume: 1;
            __IO uint32_t bt_mac_128x32_1_drf_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_1_bist_mode: 1;
            __IO uint32_t bt_mac_128x32_1_bist_rstn: 1;
        } BITS_20C;
    } u_20C;

    /* 0x210        0x4000_3210
        0       R      bt_mac_640x32_drf_start_pause   1'h0
        1       R      bt_mac_640x32_drf_bist_fail     1'h0
        2       R      bt_mac_640x32_drf_bist_done     1'h0
        3       R      bt_mac_640x32_bist_fail         1'h0
        4       R      bt_mac_640x32_bist_done         1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_640x32_bist_grp_en       1'h0
        26      R/W    bt_mac_640x32_dyn_read_en       1'h0
        27      R/W    bt_mac_640x32_bist_loop_mode    1'h0
        28      R/W    bt_mac_640x32_drf_test_resume   1'h0
        29      R/W    bt_mac_640x32_drf_bist_mode     1'h0
        30      R/W    bt_mac_640x32_bist_mode         1'h0
        31      R/W    bt_mac_640x32_bist_rstn         1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x210;
        struct
        {
            __I uint32_t bt_mac_640x32_drf_start_pause: 1;
            __I uint32_t bt_mac_640x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_640x32_drf_bist_done: 1;
            __I uint32_t bt_mac_640x32_bist_fail: 1;
            __I uint32_t bt_mac_640x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_640x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_640x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_640x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_640x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_640x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_640x32_bist_mode: 1;
            __IO uint32_t bt_mac_640x32_bist_rstn: 1;
        } BITS_210;
    } u_210;

    /* 0x214        0x4000_3214
        0       R      bt_mac_96x32_drf_start_pause    1'h0
        1       R      bt_mac_96x32_drf_bist_fail      1'h0
        2       R      bt_mac_96x32_drf_bist_done      1'h0
        3       R      bt_mac_96x32_bist_fail          1'h0
        4       R      bt_mac_96x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_96x32_bist_grp_en        1'h0
        26      R/W    bt_mac_96x32_dyn_read_en        1'h0
        27      R/W    bt_mac_96x32_bist_loop_mode     1'h0
        28      R/W    bt_mac_96x32_drf_test_resume    1'h0
        29      R/W    bt_mac_96x32_drf_bist_mode      1'h0
        30      R/W    bt_mac_96x32_bist_mode          1'h0
        31      R/W    bt_mac_96x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x214;
        struct
        {
            __I uint32_t bt_mac_96x32_drf_start_pause: 1;
            __I uint32_t bt_mac_96x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_96x32_drf_bist_done: 1;
            __I uint32_t bt_mac_96x32_bist_fail: 1;
            __I uint32_t bt_mac_96x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_96x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_96x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_96x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_96x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_96x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_96x32_bist_mode: 1;
            __IO uint32_t bt_mac_96x32_bist_rstn: 1;
        } BITS_214;
    } u_214;

    /* 0x218        0x4000_3218
        0       R      bt_mac_64x32_drf_start_pause    1'h0
        1       R      bt_mac_64x32_drf_bist_fail      1'h0
        2       R      bt_mac_64x32_drf_bist_done      1'h0
        3       R      bt_mac_64x32_bist_fail          1'h0
        4       R      bt_mac_64x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    bt_mac_64x32_bist_grp_en        1'h0
        26      R/W    bt_mac_64x32_dyn_read_en        1'h0
        27      R/W    bt_mac_64x32_bist_loop_mode     1'h0
        28      R/W    bt_mac_64x32_drf_test_resume    1'h0
        29      R/W    bt_mac_64x32_drf_bist_mode      1'h0
        30      R/W    bt_mac_64x32_bist_mode          1'h0
        31      R/W    bt_mac_64x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x218;
        struct
        {
            __I uint32_t bt_mac_64x32_drf_start_pause: 1;
            __I uint32_t bt_mac_64x32_drf_bist_fail: 1;
            __I uint32_t bt_mac_64x32_drf_bist_done: 1;
            __I uint32_t bt_mac_64x32_bist_fail: 1;
            __I uint32_t bt_mac_64x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t bt_mac_64x32_bist_grp_en: 1;
            __IO uint32_t bt_mac_64x32_dyn_read_en: 1;
            __IO uint32_t bt_mac_64x32_bist_loop_mode: 1;
            __IO uint32_t bt_mac_64x32_drf_test_resume: 1;
            __IO uint32_t bt_mac_64x32_drf_bist_mode: 1;
            __IO uint32_t bt_mac_64x32_bist_mode: 1;
            __IO uint32_t bt_mac_64x32_bist_rstn: 1;
        } BITS_218;
    } u_218;

    /* 0x21C        0x4000_321c
        0       R      zb_mac_16x32_drf_start_pause    1'h0
        1       R      zb_mac_16x32_drf_bist_fail      1'h0
        2       R      zb_mac_16x32_drf_bist_done      1'h0
        3       R      zb_mac_16x32_bist_fail          1'h0
        4       R      zb_mac_16x32_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    zb_mac_16x32_bist_grp_en        1'h0
        26      R/W    zb_mac_16x32_dyn_read_en        1'h0
        27      R/W    zb_mac_16x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_16x32_drf_test_resume    1'h0
        29      R/W    zb_mac_16x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_16x32_bist_mode          1'h0
        31      R/W    zb_mac_16x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x21C;
        struct
        {
            __I uint32_t zb_mac_16x32_drf_start_pause: 1;
            __I uint32_t zb_mac_16x32_drf_bist_fail: 1;
            __I uint32_t zb_mac_16x32_drf_bist_done: 1;
            __I uint32_t zb_mac_16x32_bist_fail: 1;
            __I uint32_t zb_mac_16x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t zb_mac_16x32_bist_grp_en: 1;
            __IO uint32_t zb_mac_16x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_16x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_16x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_16x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_16x32_bist_mode: 1;
            __IO uint32_t zb_mac_16x32_bist_rstn: 1;
        } BITS_21C;
    } u_21C;

    /* 0x220        0x4000_3220
        0       R      zb_mac_40x32_drf_start_pause    1'h0
        2:1     R      zb_mac_40x32_drf_bist_fail      2'h0
        3       R      zb_mac_40x32_drf_bist_done      1'h0
        5:4     R      zb_mac_40x32_bist_fail          2'h0
        6       R      zb_mac_40x32_bist_done          1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    zb_mac_40x32_bist_grp_en        2'h0
        26      R/W    zb_mac_40x32_dyn_read_en        1'h0
        27      R/W    zb_mac_40x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_40x32_drf_test_resume    1'h0
        29      R/W    zb_mac_40x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_40x32_bist_mode          1'h0
        31      R/W    zb_mac_40x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x220;
        struct
        {
            __I uint32_t zb_mac_40x32_drf_start_pause: 1;
            __I uint32_t zb_mac_40x32_drf_bist_fail: 2;
            __I uint32_t zb_mac_40x32_drf_bist_done: 1;
            __I uint32_t zb_mac_40x32_bist_fail: 2;
            __I uint32_t zb_mac_40x32_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t zb_mac_40x32_bist_grp_en: 2;
            __IO uint32_t zb_mac_40x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_40x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_40x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_40x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_40x32_bist_mode: 1;
            __IO uint32_t zb_mac_40x32_bist_rstn: 1;
        } BITS_220;
    } u_220;

    /* 0x224        0x4000_3224
        0       R      zb_mac_32x32_drf_start_pause    1'h0
        4:1     R      zb_mac_32x32_drf_bist_fail      4'h0
        5       R      zb_mac_32x32_drf_bist_done      1'h0
        9:6     R      zb_mac_32x32_bist_fail          4'h0
        10      R      zb_mac_32x32_bist_done          1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    zb_mac_32x32_bist_grp_en        4'h0
        26      R/W    zb_mac_32x32_dyn_read_en        1'h0
        27      R/W    zb_mac_32x32_bist_loop_mode     1'h0
        28      R/W    zb_mac_32x32_drf_test_resume    1'h0
        29      R/W    zb_mac_32x32_drf_bist_mode      1'h0
        30      R/W    zb_mac_32x32_bist_mode          1'h0
        31      R/W    zb_mac_32x32_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x224;
        struct
        {
            __I uint32_t zb_mac_32x32_drf_start_pause: 1;
            __I uint32_t zb_mac_32x32_drf_bist_fail: 4;
            __I uint32_t zb_mac_32x32_drf_bist_done: 1;
            __I uint32_t zb_mac_32x32_bist_fail: 4;
            __I uint32_t zb_mac_32x32_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t zb_mac_32x32_bist_grp_en: 4;
            __IO uint32_t zb_mac_32x32_dyn_read_en: 1;
            __IO uint32_t zb_mac_32x32_bist_loop_mode: 1;
            __IO uint32_t zb_mac_32x32_drf_test_resume: 1;
            __IO uint32_t zb_mac_32x32_drf_bist_mode: 1;
            __IO uint32_t zb_mac_32x32_bist_mode: 1;
            __IO uint32_t zb_mac_32x32_bist_rstn: 1;
        } BITS_224;
    } u_224;

    /* 0x228        0x4000_3228
        0       R      btphy_128x12x4_drf_start_pause  1'h0
        4:1     R      btphy_128x12x4_drf_bist_fail    4'h0
        5       R      btphy_128x12x4_drf_bist_done    1'h0
        9:6     R      btphy_128x12x4_bist_fail        4'h0
        10      R      btphy_128x12x4_bist_done        1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    btphy_128x12x4_bist_grp_en      4'h0
        26      R/W    btphy_128x12x4_dyn_read_en      1'h0
        27      R/W    btphy_128x12x4_bist_loop_mode   1'h0
        28      R/W    btphy_128x12x4_drf_test_resume  1'h0
        29      R/W    btphy_128x12x4_drf_bist_mode    1'h0
        30      R/W    btphy_128x12x4_bist_mode        1'h0
        31      R/W    btphy_128x12x4_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x228;
        struct
        {
            __I uint32_t btphy_128x12x4_drf_start_pause: 1;
            __I uint32_t btphy_128x12x4_drf_bist_fail: 4;
            __I uint32_t btphy_128x12x4_drf_bist_done: 1;
            __I uint32_t btphy_128x12x4_bist_fail: 4;
            __I uint32_t btphy_128x12x4_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t btphy_128x12x4_bist_grp_en: 4;
            __IO uint32_t btphy_128x12x4_dyn_read_en: 1;
            __IO uint32_t btphy_128x12x4_bist_loop_mode: 1;
            __IO uint32_t btphy_128x12x4_drf_test_resume: 1;
            __IO uint32_t btphy_128x12x4_drf_bist_mode: 1;
            __IO uint32_t btphy_128x12x4_bist_mode: 1;
            __IO uint32_t btphy_128x12x4_bist_rstn: 1;
        } BITS_228;
    } u_228;

    /* 0x22C        0x4000_322c
        0       R      btphy_lr_ram_drf_start_pause    1'h0
        5:1     R      btphy_lr_ram_drf_bist_fail      5'h0
        6       R      btphy_lr_ram_drf_bist_done      1'h0
        11:7    R      btphy_lr_ram_bist_fail          5'h0
        12      R      btphy_lr_ram_bist_done          1'h0
        20:13   R      RSVD                            8'h0
        25:21   R/W    btphy_lr_ram_bist_grp_en        5'h0
        26      R/W    btphy_lr_ram_dyn_read_en        1'h0
        27      R/W    btphy_lr_ram_bist_loop_mode     1'h0
        28      R/W    btphy_lr_ram_drf_test_resume    1'h0
        29      R/W    btphy_lr_ram_drf_bist_mode      1'h0
        30      R/W    btphy_lr_ram_bist_mode          1'h0
        31      R/W    btphy_lr_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x22C;
        struct
        {
            __I uint32_t btphy_lr_ram_drf_start_pause: 1;
            __I uint32_t btphy_lr_ram_drf_bist_fail: 5;
            __I uint32_t btphy_lr_ram_drf_bist_done: 1;
            __I uint32_t btphy_lr_ram_bist_fail: 5;
            __I uint32_t btphy_lr_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 8;
            __IO uint32_t btphy_lr_ram_bist_grp_en: 5;
            __IO uint32_t btphy_lr_ram_dyn_read_en: 1;
            __IO uint32_t btphy_lr_ram_bist_loop_mode: 1;
            __IO uint32_t btphy_lr_ram_drf_test_resume: 1;
            __IO uint32_t btphy_lr_ram_drf_bist_mode: 1;
            __IO uint32_t btphy_lr_ram_bist_mode: 1;
            __IO uint32_t btphy_lr_ram_bist_rstn: 1;
        } BITS_22C;
    } u_22C;

    /* 0x230        0x4000_3230
        0       R      km4_itcm0_bist_done             1'h0
        25:1    R      RSVD                            25'h0
        29:26   R/W    km4_itcm0_bist_grp_en           4'h0
        30      R/W    km4_itcm0_bist_mode             1'h0
        31      R/W    km4_itcm0_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x230;
        struct
        {
            __I uint32_t km4_itcm0_bist_done: 1;
            __I uint32_t RESERVED_0: 25;
            __IO uint32_t km4_itcm0_bist_grp_en: 4;
            __IO uint32_t km4_itcm0_bist_mode: 1;
            __IO uint32_t km4_itcm0_bist_rstn: 1;
        } BITS_230;
    } u_230;

    /* 0x234        0x4000_3234
        31:0    R      km4_itcm0_misr_dataout_0_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x234;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_0_31_00: 32;
        } BITS_234;
    } u_234;

    /* 0x238        0x4000_3238
        31:0    R      km4_itcm0_misr_dataout_0_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x238;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_0_63_32: 32;
        } BITS_238;
    } u_238;

    /* 0x23C        0x4000_323c
        31:0    R      km4_itcm0_misr_dataout_1_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x23C;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_1_31_00: 32;
        } BITS_23C;
    } u_23C;

    /* 0x240        0x4000_3240
        31:0    R      km4_itcm0_misr_dataout_1_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x240;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_1_63_32: 32;
        } BITS_240;
    } u_240;

    /* 0x244        0x4000_3244
        31:0    R      km4_itcm0_misr_dataout_2_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x244;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_2_31_00: 32;
        } BITS_244;
    } u_244;

    /* 0x248        0x4000_3248
        31:0    R      km4_itcm0_misr_dataout_2_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x248;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_2_63_32: 32;
        } BITS_248;
    } u_248;

    /* 0x24C        0x4000_324c
        31:0    R      km4_itcm0_misr_dataout_3_31_00  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x24C;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_3_31_00: 32;
        } BITS_24C;
    } u_24C;

    /* 0x250        0x4000_3250
        31:0    R      km4_itcm0_misr_dataout_3_63_32  32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x250;
        struct
        {
            __I uint32_t km4_itcm0_misr_dataout_3_63_32: 32;
        } BITS_250;
    } u_250;

    /* 0x254        0x4000_3254
        13:0    R      RSVD                            14'h0
        25:14   R/W    km4_itcm1_bist_grp_en           12'h0
        26      R/W    km4_itcm1_dyn_read_en           1'h0
        27      R/W    km4_itcm1_bist_loop_mode        1'h0
        28      R/W    km4_itcm1_drf_test_resume       1'h0
        29      R/W    km4_itcm1_drf_bist_mode         1'h0
        30      R/W    km4_itcm1_bist_mode             1'h0
        31      R/W    km4_itcm1_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x254;
        struct
        {
            __I uint32_t RESERVED_0: 14;
            __IO uint32_t km4_itcm1_bist_grp_en: 12;
            __IO uint32_t km4_itcm1_dyn_read_en: 1;
            __IO uint32_t km4_itcm1_bist_loop_mode: 1;
            __IO uint32_t km4_itcm1_drf_test_resume: 1;
            __IO uint32_t km4_itcm1_drf_bist_mode: 1;
            __IO uint32_t km4_itcm1_bist_mode: 1;
            __IO uint32_t km4_itcm1_bist_rstn: 1;
        } BITS_254;
    } u_254;

    /* 0x258        0x4000_3258
        0       R      km4_itcm1_drf_start_pause       1'h0
        12:1    R      km4_itcm1_drf_bist_fail         12'h0
        13      R      km4_itcm1_drf_bist_done         1'h0
        25:14   R      km4_itcm1_bist_fail             12'h0
        26      R      km4_itcm1_bist_done             1'h0
        31:27   R      RSVD                            5'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x258;
        struct
        {
            __I uint32_t km4_itcm1_drf_start_pause: 1;
            __I uint32_t km4_itcm1_drf_bist_fail: 12;
            __I uint32_t km4_itcm1_drf_bist_done: 1;
            __I uint32_t km4_itcm1_bist_fail: 12;
            __I uint32_t km4_itcm1_bist_done: 1;
            __I uint32_t RESERVED_0: 5;
        } BITS_258;
    } u_258;

    /* 0x25C        0x4000_325c
        0       R      km4_dtcm0_drf_start_pause       1'h0
        4:1     R      km4_dtcm0_drf_bist_fail         4'h0
        5       R      km4_dtcm0_drf_bist_done         1'h0
        9:6     R      km4_dtcm0_bist_fail             4'h0
        10      R      km4_dtcm0_bist_done             1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    km4_dtcm0_bist_grp_en           4'h0
        26      R/W    km4_dtcm0_dyn_read_en           1'h0
        27      R/W    km4_dtcm0_bist_loop_mode        1'h0
        28      R/W    km4_dtcm0_drf_test_resume       1'h0
        29      R/W    km4_dtcm0_drf_bist_mode         1'h0
        30      R/W    km4_dtcm0_bist_mode             1'h0
        31      R/W    km4_dtcm0_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x25C;
        struct
        {
            __I uint32_t km4_dtcm0_drf_start_pause: 1;
            __I uint32_t km4_dtcm0_drf_bist_fail: 4;
            __I uint32_t km4_dtcm0_drf_bist_done: 1;
            __I uint32_t km4_dtcm0_bist_fail: 4;
            __I uint32_t km4_dtcm0_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t km4_dtcm0_bist_grp_en: 4;
            __IO uint32_t km4_dtcm0_dyn_read_en: 1;
            __IO uint32_t km4_dtcm0_bist_loop_mode: 1;
            __IO uint32_t km4_dtcm0_drf_test_resume: 1;
            __IO uint32_t km4_dtcm0_drf_bist_mode: 1;
            __IO uint32_t km4_dtcm0_bist_mode: 1;
            __IO uint32_t km4_dtcm0_bist_rstn: 1;
        } BITS_25C;
    } u_25C;

    /* 0x260        0x4000_3260
        0       R      km4_dtcm1_drf_start_pause       1'h0
        4:1     R      km4_dtcm1_drf_bist_fail         4'h0
        5       R      km4_dtcm1_drf_bist_done         1'h0
        9:6     R      km4_dtcm1_bist_fail             4'h0
        10      R      km4_dtcm1_bist_done             1'h0
        21:11   R      RSVD                            11'h0
        25:22   R/W    km4_dtcm1_bist_grp_en           4'h0
        26      R/W    km4_dtcm1_dyn_read_en           1'h0
        27      R/W    km4_dtcm1_bist_loop_mode        1'h0
        28      R/W    km4_dtcm1_drf_test_resume       1'h0
        29      R/W    km4_dtcm1_drf_bist_mode         1'h0
        30      R/W    km4_dtcm1_bist_mode             1'h0
        31      R/W    km4_dtcm1_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x260;
        struct
        {
            __I uint32_t km4_dtcm1_drf_start_pause: 1;
            __I uint32_t km4_dtcm1_drf_bist_fail: 4;
            __I uint32_t km4_dtcm1_drf_bist_done: 1;
            __I uint32_t km4_dtcm1_bist_fail: 4;
            __I uint32_t km4_dtcm1_bist_done: 1;
            __I uint32_t RESERVED_0: 11;
            __IO uint32_t km4_dtcm1_bist_grp_en: 4;
            __IO uint32_t km4_dtcm1_dyn_read_en: 1;
            __IO uint32_t km4_dtcm1_bist_loop_mode: 1;
            __IO uint32_t km4_dtcm1_drf_test_resume: 1;
            __IO uint32_t km4_dtcm1_drf_bist_mode: 1;
            __IO uint32_t km4_dtcm1_bist_mode: 1;
            __IO uint32_t km4_dtcm1_bist_rstn: 1;
        } BITS_260;
    } u_260;

    /* 0x264        0x4000_3264
        15:0    R      RSVD                            16'h0
        25:16   R/W    km4_cache_bist_grp_en           10'h0
        26      R/W    km4_cache_dyn_read_en           1'h0
        27      R/W    km4_cache_bist_loop_mode        1'h0
        28      R/W    km4_cache_drf_test_resume       1'h0
        29      R/W    km4_cache_drf_bist_mode         1'h0
        30      R/W    km4_cache_bist_mode             1'h0
        31      R/W    km4_cache_bist_rstn             1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x264;
        struct
        {
            __I uint32_t RESERVED_0: 16;
            __IO uint32_t km4_cache_bist_grp_en: 10;
            __IO uint32_t km4_cache_dyn_read_en: 1;
            __IO uint32_t km4_cache_bist_loop_mode: 1;
            __IO uint32_t km4_cache_drf_test_resume: 1;
            __IO uint32_t km4_cache_drf_bist_mode: 1;
            __IO uint32_t km4_cache_bist_mode: 1;
            __IO uint32_t km4_cache_bist_rstn: 1;
        } BITS_264;
    } u_264;

    /* 0x268        0x4000_3268
        0       R      km4_cache_drf_start_pause       1'h0
        10:1    R      km4_cache_drf_bist_fail         10'h0
        11      R      km4_cache_drf_bist_done         1'h0
        21:12   R      km4_cache_bist_fail             10'h0
        22      R      km4_cache_bist_done             1'h0
        31:23   R      RSVD                            9'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x268;
        struct
        {
            __I uint32_t km4_cache_drf_start_pause: 1;
            __I uint32_t km4_cache_drf_bist_fail: 10;
            __I uint32_t km4_cache_drf_bist_done: 1;
            __I uint32_t km4_cache_bist_fail: 10;
            __I uint32_t km4_cache_bist_done: 1;
            __I uint32_t RESERVED_0: 9;
        } BITS_268;
    } u_268;

    /* 0x26C        0x4000_326c
        0       R      buffer_ram_drf_start_pause      1'h0
        3:1     R      buffer_ram_drf_bist_fail        3'h0
        4       R      buffer_ram_drf_bist_done        1'h0
        7:5     R      buffer_ram_bist_fail            3'h0
        8       R      buffer_ram_bist_done            1'h0
        22:9    R      RSVD                            14'h0
        25:23   R/W    buffer_ram_bist_grp_en          3'h0
        26      R/W    buffer_ram_dyn_read_en          1'h0
        27      R/W    buffer_ram_bist_loop_mode       1'h0
        28      R/W    buffer_ram_drf_test_resume      1'h0
        29      R/W    buffer_ram_drf_bist_mode        1'h0
        30      R/W    buffer_ram_bist_mode            1'h0
        31      R/W    buffer_ram_bist_rstn            1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x26C;
        struct
        {
            __I uint32_t buffer_ram_drf_start_pause: 1;
            __I uint32_t buffer_ram_drf_bist_fail: 3;
            __I uint32_t buffer_ram_drf_bist_done: 1;
            __I uint32_t buffer_ram_bist_fail: 3;
            __I uint32_t buffer_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 14;
            __IO uint32_t buffer_ram_bist_grp_en: 3;
            __IO uint32_t buffer_ram_dyn_read_en: 1;
            __IO uint32_t buffer_ram_bist_loop_mode: 1;
            __IO uint32_t buffer_ram_drf_test_resume: 1;
            __IO uint32_t buffer_ram_drf_bist_mode: 1;
            __IO uint32_t buffer_ram_bist_mode: 1;
            __IO uint32_t buffer_ram_bist_rstn: 1;
        } BITS_26C;
    } u_26C;

    /* 0x270        0x4000_3270
        0       R      data_ram_drf_start_pause        1'h0
        1       R      data_ram_drf_bist_fail          1'h0
        2       R      data_ram_drf_bist_done          1'h0
        3       R      data_ram_bist_fail              1'h0
        4       R      data_ram_bist_done              1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    data_ram_bist_grp_en            1'h0
        26      R/W    data_ram_dyn_read_en            1'h0
        27      R/W    data_ram_bist_loop_mode         1'h0
        28      R/W    data_ram_drf_test_resume        1'h0
        29      R/W    data_ram_drf_bist_mode          1'h0
        30      R/W    data_ram_bist_mode              1'h0
        31      R/W    data_ram_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x270;
        struct
        {
            __I uint32_t data_ram_drf_start_pause: 1;
            __I uint32_t data_ram_drf_bist_fail: 1;
            __I uint32_t data_ram_drf_bist_done: 1;
            __I uint32_t data_ram_bist_fail: 1;
            __I uint32_t data_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t data_ram_bist_grp_en: 1;
            __IO uint32_t data_ram_dyn_read_en: 1;
            __IO uint32_t data_ram_bist_loop_mode: 1;
            __IO uint32_t data_ram_drf_test_resume: 1;
            __IO uint32_t data_ram_drf_bist_mode: 1;
            __IO uint32_t data_ram_bist_mode: 1;
            __IO uint32_t data_ram_bist_rstn: 1;
        } BITS_270;
    } u_270;

    /* 0x274        0x4000_3274
        0       R      usb_2176x35_drf_start_pause     1'h0
        1       R      usb_2176x35_drf_bist_fail       1'h0
        2       R      usb_2176x35_drf_bist_done       1'h0
        3       R      usb_2176x35_bist_fail           1'h0
        4       R      usb_2176x35_bist_done           1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    usb_2176x35_bist_grp_en         1'h0
        26      R/W    usb_2176x35_dyn_read_en         1'h0
        27      R/W    usb_2176x35_bist_loop_mode      1'h0
        28      R/W    usb_2176x35_drf_test_resume     1'h0
        29      R/W    usb_2176x35_drf_bist_mode       1'h0
        30      R/W    usb_2176x35_bist_mode           1'h0
        31      R/W    usb_2176x35_bist_rstn           1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x274;
        struct
        {
            __I uint32_t usb_2176x35_drf_start_pause: 1;
            __I uint32_t usb_2176x35_drf_bist_fail: 1;
            __I uint32_t usb_2176x35_drf_bist_done: 1;
            __I uint32_t usb_2176x35_bist_fail: 1;
            __I uint32_t usb_2176x35_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t usb_2176x35_bist_grp_en: 1;
            __IO uint32_t usb_2176x35_dyn_read_en: 1;
            __IO uint32_t usb_2176x35_bist_loop_mode: 1;
            __IO uint32_t usb_2176x35_drf_test_resume: 1;
            __IO uint32_t usb_2176x35_drf_bist_mode: 1;
            __IO uint32_t usb_2176x35_bist_mode: 1;
            __IO uint32_t usb_2176x35_bist_rstn: 1;
        } BITS_274;
    } u_274;

    /* 0x278        0x4000_3278
        0       R      sdio_ram_drf_start_pause        1'h0
        1       R      sdio_ram_drf_bist_fail          1'h0
        2       R      sdio_ram_drf_bist_done          1'h0
        3       R      sdio_ram_bist_fail              1'h0
        4       R      sdio_ram_bist_done              1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    sdio_ram_bist_grp_en            1'h0
        26      R/W    sdio_ram_dyn_read_en            1'h0
        27      R/W    sdio_ram_bist_loop_mode         1'h0
        28      R/W    sdio_ram_drf_test_resume        1'h0
        29      R/W    sdio_ram_drf_bist_mode          1'h0
        30      R/W    sdio_ram_bist_mode              1'h0
        31      R/W    sdio_ram_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x278;
        struct
        {
            __I uint32_t sdio_ram_drf_start_pause: 1;
            __I uint32_t sdio_ram_drf_bist_fail: 1;
            __I uint32_t sdio_ram_drf_bist_done: 1;
            __I uint32_t sdio_ram_bist_fail: 1;
            __I uint32_t sdio_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t sdio_ram_bist_grp_en: 1;
            __IO uint32_t sdio_ram_dyn_read_en: 1;
            __IO uint32_t sdio_ram_bist_loop_mode: 1;
            __IO uint32_t sdio_ram_drf_test_resume: 1;
            __IO uint32_t sdio_ram_drf_bist_mode: 1;
            __IO uint32_t sdio_ram_bist_mode: 1;
            __IO uint32_t sdio_ram_bist_rstn: 1;
        } BITS_278;
    } u_278;

    /* 0x27C        0x4000_327c
        0       R      display_128x32_drf_start_pause  1'h0
        1       R      display_128x32_drf_bist_fail    1'h0
        2       R      display_128x32_drf_bist_done    1'h0
        3       R      display_128x32_bist_fail        1'h0
        4       R      display_128x32_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    display_128x32_bist_grp_en      1'h0
        26      R/W    display_128x32_dyn_read_en      1'h0
        27      R/W    display_128x32_bist_loop_mode   1'h0
        28      R/W    display_128x32_drf_test_resume  1'h0
        29      R/W    display_128x32_drf_bist_mode    1'h0
        30      R/W    display_128x32_bist_mode        1'h0
        31      R/W    display_128x32_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x27C;
        struct
        {
            __I uint32_t display_128x32_drf_start_pause: 1;
            __I uint32_t display_128x32_drf_bist_fail: 1;
            __I uint32_t display_128x32_drf_bist_done: 1;
            __I uint32_t display_128x32_bist_fail: 1;
            __I uint32_t display_128x32_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t display_128x32_bist_grp_en: 1;
            __IO uint32_t display_128x32_dyn_read_en: 1;
            __IO uint32_t display_128x32_bist_loop_mode: 1;
            __IO uint32_t display_128x32_drf_test_resume: 1;
            __IO uint32_t display_128x32_drf_bist_mode: 1;
            __IO uint32_t display_128x32_bist_mode: 1;
            __IO uint32_t display_128x32_bist_rstn: 1;
        } BITS_27C;
    } u_27C;

    /* 0x280        0x4000_3280
        0       R      display_672x24_drf_start_pause  1'h0
        1       R      display_672x24_drf_bist_fail    1'h0
        2       R      display_672x24_drf_bist_done    1'h0
        3       R      display_672x24_bist_fail        1'h0
        4       R      display_672x24_bist_done        1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    display_672x24_bist_grp_en      1'h0
        26      R/W    display_672x24_dyn_read_en      1'h0
        27      R/W    display_672x24_bist_loop_mode   1'h0
        28      R/W    display_672x24_drf_test_resume  1'h0
        29      R/W    display_672x24_drf_bist_mode    1'h0
        30      R/W    display_672x24_bist_mode        1'h0
        31      R/W    display_672x24_bist_rstn        1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x280;
        struct
        {
            __I uint32_t display_672x24_drf_start_pause: 1;
            __I uint32_t display_672x24_drf_bist_fail: 1;
            __I uint32_t display_672x24_drf_bist_done: 1;
            __I uint32_t display_672x24_bist_fail: 1;
            __I uint32_t display_672x24_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t display_672x24_bist_grp_en: 1;
            __IO uint32_t display_672x24_dyn_read_en: 1;
            __IO uint32_t display_672x24_bist_loop_mode: 1;
            __IO uint32_t display_672x24_drf_test_resume: 1;
            __IO uint32_t display_672x24_drf_bist_mode: 1;
            __IO uint32_t display_672x24_bist_mode: 1;
            __IO uint32_t display_672x24_bist_rstn: 1;
        } BITS_280;
    } u_280;

    /* 0x284        0x4000_3284
        0       R      gmac_512x32_drf_start_pause     1'h0
        2:1     R      gmac_512x32_drf_bist_fail       2'h0
        3       R      gmac_512x32_drf_bist_done       1'h0
        5:4     R      gmac_512x32_bist_fail           2'h0
        6       R      gmac_512x32_bist_done           1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    gmac_512x32_bist_grp_en         2'h0
        26      R/W    gmac_512x32_dyn_read_en         1'h0
        27      R/W    gmac_512x32_bist_loop_mode      1'h0
        28      R/W    gmac_512x32_drf_test_resume     1'h0
        29      R/W    gmac_512x32_drf_bist_mode       1'h0
        30      R/W    gmac_512x32_bist_mode           1'h0
        31      R/W    gmac_512x32_bist_rstn           1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x284;
        struct
        {
            __I uint32_t gmac_512x32_drf_start_pause: 1;
            __I uint32_t gmac_512x32_drf_bist_fail: 2;
            __I uint32_t gmac_512x32_drf_bist_done: 1;
            __I uint32_t gmac_512x32_bist_fail: 2;
            __I uint32_t gmac_512x32_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t gmac_512x32_bist_grp_en: 2;
            __IO uint32_t gmac_512x32_dyn_read_en: 1;
            __IO uint32_t gmac_512x32_bist_loop_mode: 1;
            __IO uint32_t gmac_512x32_drf_test_resume: 1;
            __IO uint32_t gmac_512x32_drf_bist_mode: 1;
            __IO uint32_t gmac_512x32_bist_mode: 1;
            __IO uint32_t gmac_512x32_bist_rstn: 1;
        } BITS_284;
    } u_284;

    /* 0x288        0x4000_3288
        0       R      pke_rom_bist_done               1'h0
        28:1    R      RSVD                            28'h0
        29      R/W    pke_rom_bist_grp_en             1'h0
        30      R/W    pke_rom_bist_mode               1'h0
        31      R/W    pke_rom_bist_rstn               1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x288;
        struct
        {
            __I uint32_t pke_rom_bist_done: 1;
            __I uint32_t RESERVED_0: 28;
            __IO uint32_t pke_rom_bist_grp_en: 1;
            __IO uint32_t pke_rom_bist_mode: 1;
            __IO uint32_t pke_rom_bist_rstn: 1;
        } BITS_288;
    } u_288;

    /* 0x28C        0x4000_328c
        31:0    R      pke_rom_misr_dataout_0_31_00    32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x28C;
        struct
        {
            __I uint32_t pke_rom_misr_dataout_0_31_00: 32;
        } BITS_28C;
    } u_28C;

    /* 0x290        0x4000_3290
        31:0    R      pke_rom_misr_dataout_0_63_32    32'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x290;
        struct
        {
            __I uint32_t pke_rom_misr_dataout_0_63_32: 32;
        } BITS_290;
    } u_290;

    /* 0x294        0x4000_3294
        0       R      pke_mmem_drf_start_pause        1'h0
        2:1     R      pke_mmem_drf_bist_fail          2'h0
        3       R      pke_mmem_drf_bist_done          1'h0
        5:4     R      pke_mmem_bist_fail              2'h0
        6       R      pke_mmem_bist_done              1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    pke_mmem_bist_grp_en            2'h0
        26      R/W    pke_mmem_dyn_read_en            1'h0
        27      R/W    pke_mmem_bist_loop_mode         1'h0
        28      R/W    pke_mmem_drf_test_resume        1'h0
        29      R/W    pke_mmem_drf_bist_mode          1'h0
        30      R/W    pke_mmem_bist_mode              1'h0
        31      R/W    pke_mmem_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x294;
        struct
        {
            __I uint32_t pke_mmem_drf_start_pause: 1;
            __I uint32_t pke_mmem_drf_bist_fail: 2;
            __I uint32_t pke_mmem_drf_bist_done: 1;
            __I uint32_t pke_mmem_bist_fail: 2;
            __I uint32_t pke_mmem_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t pke_mmem_bist_grp_en: 2;
            __IO uint32_t pke_mmem_dyn_read_en: 1;
            __IO uint32_t pke_mmem_bist_loop_mode: 1;
            __IO uint32_t pke_mmem_drf_test_resume: 1;
            __IO uint32_t pke_mmem_drf_bist_mode: 1;
            __IO uint32_t pke_mmem_bist_mode: 1;
            __IO uint32_t pke_mmem_bist_rstn: 1;
        } BITS_294;
    } u_294;

    /* 0x298        0x4000_3298
        0       R      pke_tmem_drf_start_pause        1'h0
        2:1     R      pke_tmem_drf_bist_fail          2'h0
        3       R      pke_tmem_drf_bist_done          1'h0
        5:4     R      pke_tmem_bist_fail              2'h0
        6       R      pke_tmem_bist_done              1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    pke_tmem_bist_grp_en            2'h0
        26      R/W    pke_tmem_dyn_read_en            1'h0
        27      R/W    pke_tmem_bist_loop_mode         1'h0
        28      R/W    pke_tmem_drf_test_resume        1'h0
        29      R/W    pke_tmem_drf_bist_mode          1'h0
        30      R/W    pke_tmem_bist_mode              1'h0
        31      R/W    pke_tmem_bist_rstn              1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x298;
        struct
        {
            __I uint32_t pke_tmem_drf_start_pause: 1;
            __I uint32_t pke_tmem_drf_bist_fail: 2;
            __I uint32_t pke_tmem_drf_bist_done: 1;
            __I uint32_t pke_tmem_bist_fail: 2;
            __I uint32_t pke_tmem_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t pke_tmem_bist_grp_en: 2;
            __IO uint32_t pke_tmem_dyn_read_en: 1;
            __IO uint32_t pke_tmem_bist_loop_mode: 1;
            __IO uint32_t pke_tmem_drf_test_resume: 1;
            __IO uint32_t pke_tmem_drf_bist_mode: 1;
            __IO uint32_t pke_tmem_bist_mode: 1;
            __IO uint32_t pke_tmem_bist_rstn: 1;
        } BITS_298;
    } u_298;

    /* 0x29C        0x4000_329c
        0       R      audio_ad_ram_drf_start_pause    1'h0
        2:1     R      audio_ad_ram_drf_bist_fail      2'h0
        3       R      audio_ad_ram_drf_bist_done      1'h0
        5:4     R      audio_ad_ram_bist_fail          2'h0
        6       R      audio_ad_ram_bist_done          1'h0
        23:7    R      RSVD                            17'h0
        25:24   R/W    audio_ad_ram_bist_grp_en        2'h0
        26      R/W    audio_ad_ram_dyn_read_en        1'h0
        27      R/W    audio_ad_ram_bist_loop_mode     1'h0
        28      R/W    audio_ad_ram_drf_test_resume    1'h0
        29      R/W    audio_ad_ram_drf_bist_mode      1'h0
        30      R/W    audio_ad_ram_bist_mode          1'h0
        31      R/W    audio_ad_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x29C;
        struct
        {
            __I uint32_t audio_ad_ram_drf_start_pause: 1;
            __I uint32_t audio_ad_ram_drf_bist_fail: 2;
            __I uint32_t audio_ad_ram_drf_bist_done: 1;
            __I uint32_t audio_ad_ram_bist_fail: 2;
            __I uint32_t audio_ad_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 17;
            __IO uint32_t audio_ad_ram_bist_grp_en: 2;
            __IO uint32_t audio_ad_ram_dyn_read_en: 1;
            __IO uint32_t audio_ad_ram_bist_loop_mode: 1;
            __IO uint32_t audio_ad_ram_drf_test_resume: 1;
            __IO uint32_t audio_ad_ram_drf_bist_mode: 1;
            __IO uint32_t audio_ad_ram_bist_mode: 1;
            __IO uint32_t audio_ad_ram_bist_rstn: 1;
        } BITS_29C;
    } u_29C;

    /* 0x2A0        0x4000_32a0
        0       R      audio_da_ram_drf_start_pause    1'h0
        1       R      audio_da_ram_drf_bist_fail      1'h0
        2       R      audio_da_ram_drf_bist_done      1'h0
        3       R      audio_da_ram_bist_fail          1'h0
        4       R      audio_da_ram_bist_done          1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    audio_da_ram_bist_grp_en        1'h0
        26      R/W    audio_da_ram_dyn_read_en        1'h0
        27      R/W    audio_da_ram_bist_loop_mode     1'h0
        28      R/W    audio_da_ram_drf_test_resume    1'h0
        29      R/W    audio_da_ram_drf_bist_mode      1'h0
        30      R/W    audio_da_ram_bist_mode          1'h0
        31      R/W    audio_da_ram_bist_rstn          1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x2A0;
        struct
        {
            __I uint32_t audio_da_ram_drf_start_pause: 1;
            __I uint32_t audio_da_ram_drf_bist_fail: 1;
            __I uint32_t audio_da_ram_drf_bist_done: 1;
            __I uint32_t audio_da_ram_bist_fail: 1;
            __I uint32_t audio_da_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t audio_da_ram_bist_grp_en: 1;
            __IO uint32_t audio_da_ram_dyn_read_en: 1;
            __IO uint32_t audio_da_ram_bist_loop_mode: 1;
            __IO uint32_t audio_da_ram_drf_test_resume: 1;
            __IO uint32_t audio_da_ram_drf_bist_mode: 1;
            __IO uint32_t audio_da_ram_bist_mode: 1;
            __IO uint32_t audio_da_ram_bist_rstn: 1;
        } BITS_2A0;
    } u_2A0;

    /* 0x2A4        0x4000_32a4
        0       R      can_ram_drf_start_pause         1'h0
        1       R      can_ram_drf_bist_fail           1'h0
        2       R      can_ram_drf_bist_done           1'h0
        3       R      can_ram_bist_fail               1'h0
        4       R      can_ram_bist_done               1'h0
        24:5    R      RSVD                            20'h0
        25      R/W    can_ram_bist_grp_en             1'h0
        26      R/W    can_ram_dyn_read_en             1'h0
        27      R/W    can_ram_bist_loop_mode          1'h0
        28      R/W    can_ram_drf_test_resume         1'h0
        29      R/W    can_ram_drf_bist_mode           1'h0
        30      R/W    can_ram_bist_mode               1'h0
        31      R/W    can_ram_bist_rstn               1'h0
    */
    union
    {
        __IO uint32_t reg_bist_0x2A4;
        struct
        {
            __I uint32_t can_ram_drf_start_pause: 1;
            __I uint32_t can_ram_drf_bist_fail: 1;
            __I uint32_t can_ram_drf_bist_done: 1;
            __I uint32_t can_ram_bist_fail: 1;
            __I uint32_t can_ram_bist_done: 1;
            __I uint32_t RESERVED_0: 20;
            __IO uint32_t can_ram_bist_grp_en: 1;
            __IO uint32_t can_ram_dyn_read_en: 1;
            __IO uint32_t can_ram_bist_loop_mode: 1;
            __IO uint32_t can_ram_drf_test_resume: 1;
            __IO uint32_t can_ram_drf_bist_mode: 1;
            __IO uint32_t can_ram_bist_mode: 1;
            __IO uint32_t can_ram_bist_rstn: 1;
        } BITS_2A4;
    } u_2A4;

    __IO uint32_t RSVD_0x2a8[9];

    /* 0x2CC        0x4000_32cc
        31:0    R/W    spic0_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_0: 32;
        } BITS_2CC;
    } u_2CC;

    /* 0x2D0        0x4000_32d0
        31:0    R/W    spic0_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_1: 32;
        } BITS_2D0;
    } u_2D0;

    /* 0x2D4        0x4000_32d4
        31:0    R/W    spic0_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_2: 32;
        } BITS_2D4;
    } u_2D4;

    /* 0x2D8        0x4000_32d8
        31:0    R/W    spic0_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_3: 32;
        } BITS_2D8;
    } u_2D8;

    /* 0x2DC        0x4000_32dc
        31:0    R/W    spic0_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_4: 32;
        } BITS_2DC;
    } u_2DC;

    /* 0x2E0        0x4000_32e0
        31:0    R/W    spic0_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_5: 32;
        } BITS_2E0;
    } u_2E0;

    /* 0x2E4        0x4000_32e4
        31:0    R/W    spic0_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_6: 32;
        } BITS_2E4;
    } u_2E4;

    /* 0x2E8        0x4000_32e8
        31:0    R/W    spic0_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_init_7: 32;
        } BITS_2E8;
    } u_2E8;

    /* 0x2EC        0x4000_32ec
        4:0     R/W    spic0_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC0_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic0_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_2EC;
    } u_2EC;

    /* 0x2F0        0x4000_32f0
        31:0    R/W    spic1_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_0: 32;
        } BITS_2F0;
    } u_2F0;

    /* 0x2F4        0x4000_32f4
        31:0    R/W    spic1_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_1: 32;
        } BITS_2F4;
    } u_2F4;

    /* 0x2F8        0x4000_32f8
        31:0    R/W    spic1_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_2: 32;
        } BITS_2F8;
    } u_2F8;

    /* 0x2FC        0x4000_32fc
        31:0    R/W    spic1_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_3: 32;
        } BITS_2FC;
    } u_2FC;

    /* 0x300        0x4000_3300
        31:0    R/W    spic1_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_4: 32;
        } BITS_300;
    } u_300;

    /* 0x304        0x4000_3304
        31:0    R/W    spic1_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_5: 32;
        } BITS_304;
    } u_304;

    /* 0x308        0x4000_3308
        31:0    R/W    spic1_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_6: 32;
        } BITS_308;
    } u_308;

    /* 0x30C        0x4000_330c
        31:0    R/W    spic1_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_init_7: 32;
        } BITS_30C;
    } u_30C;

    /* 0x310        0x4000_3310
        4:0     R/W    spic1_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC1_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic1_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_310;
    } u_310;

    /* 0x314        0x4000_3314
        31:0    R/W    spic2_pgm_fifo_init_0           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_0;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_0: 32;
        } BITS_314;
    } u_314;

    /* 0x318        0x4000_3318
        31:0    R/W    spic2_pgm_fifo_init_1           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_1;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_1: 32;
        } BITS_318;
    } u_318;

    /* 0x31C        0x4000_331c
        31:0    R/W    spic2_pgm_fifo_init_2           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_2;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_2: 32;
        } BITS_31C;
    } u_31C;

    /* 0x320        0x4000_3320
        31:0    R/W    spic2_pgm_fifo_init_3           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_3;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_3: 32;
        } BITS_320;
    } u_320;

    /* 0x324        0x4000_3324
        31:0    R/W    spic2_pgm_fifo_init_4           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_4;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_4: 32;
        } BITS_324;
    } u_324;

    /* 0x328        0x4000_3328
        31:0    R/W    spic2_pgm_fifo_init_5           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_5;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_5: 32;
        } BITS_328;
    } u_328;

    /* 0x32C        0x4000_332c
        31:0    R/W    spic2_pgm_fifo_init_6           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_6;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_6: 32;
        } BITS_32C;
    } u_32C;

    /* 0x330        0x4000_3330
        31:0    R/W    spic2_pgm_fifo_init_7           32'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_INIT_7;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_init_7: 32;
        } BITS_330;
    } u_330;

    /* 0x334        0x4000_3334
        4:0     R/W    spic2_pgm_fifo_wptr_init        5'h0
        31:5    R      RSVD                            27'h0
    */
    union
    {
        __IO uint32_t REG_SPIC2_PGM_FIFO_WPTR_INIT;
        struct
        {
            __IO uint32_t spic2_pgm_fifo_wptr_init: 5;
            __I uint32_t RESERVED_0: 27;
        } BITS_334;
    } u_334;

} SoC_VENDOR_REG_TypeDef;



/* ======================================================= */
/* ================                      ICG                     ================ */
/* ======================================================= */

/**
  * @brief cache for flash
  */
typedef struct
{
    __IO uint32_t CTRL0;            /*!< ICG cells control address register0, Address Offset: 0x00*/
    __IO uint32_t CTRL1;            /*!< ICG cells control address register1, Address Offset: 0x04*/
    __IO uint32_t CACHE_RAM_CTRL;   /*!< icache twoway control, Address Offset: 0x08*/
} ICG_TypeDef;

/* ======================================================= */
/* ================                      CACHE                     ================ */
/* ======================================================= */

/**
  * @brief cache for flash
  */
typedef struct
{
    __IO uint32_t CACHE_ENABLE;          /*!< SPIC cache Enable Register, Address Offset: 0x00*/
    __IO uint32_t FLUSH;                 /*!< Cache Flush register, Address Offset: 0x04*/
    __IO uint32_t INTR;                  /*!< Cache Interrupt register, Address Offset: 0x08*/
    __IO uint32_t RST_CNT;           /*!< Cache Reset Counter register, Address Offset: 0x0C*/
    __IO uint32_t RD_EVT_CNT;        /*!< Cache Read Event Counter register, Address Offset: 0x10*/
    __IO uint32_t HIT_EVT_CNT;       /*!< Cache HIT Event Counter register, Address Offset: 0x14*/
    __IO uint32_t HIT_LSTW_EVT_CNT;  /*!< Cache Hit lastway event counter register, Offset: 0x18*/
    __IO uint32_t RD_PND_CNT;        /*!< Cache Read pending counter register, Offset: 0x1c*/
} CACHE_TypeDef;

/* ================================================================================ */
/* ================                      SPIC                      ================ */
/* ================================================================================ */
typedef struct
{
    __IO uint32_t CTRLR0;               /*!< Control reg 0,                         offset: 0x000 */
    __IO uint32_t RX_NDF;               /*!< User mode rx data data frame counter,  offset: 0x004 */
    __IO uint32_t SSIENR;               /*!< Enable reg,                            offset: 0x008 */
    __IO uint32_t MWCR;                 /*!< N/A,                                   offset: 0x00C */
    __IO uint32_t SER;                  /*!< Slave enable reg,                      offset: 0x010 */
    __IO uint32_t BAUDR;                /*!< Baudrate select reg,                   offset: 0x014 */
    __IO uint32_t TXFTLR;               /*!< Tx FIFO threshold level,               offset: 0x018 */
    __IO uint32_t RXFTLR;               /*!< Rx FIFO threshold level,               offset: 0x01C */
    __IO uint32_t TXFLR;                /*!< Tx FIFO level reg,                     offset: 0x020 */
    __IO uint32_t RXFLR;                /*!< Rx FIFO level reg,                     offset: 0x024 */
    __IO uint32_t SR;                   /*!< Status reg,                            offset: 0x028 */
    __IO uint32_t IMR;                  /*!< Interrupt mask reg,                    offset: 0x02C */
    __IO uint32_t ISR;                  /*!< Interrupt status reg,                  offset: 0x030 */
    __IO uint32_t RISR;                 /*!< Raw interrupt status reg,              offset: 0x034 */
    __IO uint32_t TXOICR;               /*!< Tx FIFO overflow interrupt clear reg,  offset: 0x038 */
    __IO uint32_t RXOICR;               /*!< Rx FIFO overflow interrupt clear reg,  offset: 0x03C */
    __IO uint32_t RXUICR;               /*!< Rx FIFO underflow interrupt clear reg, offset: 0x040 */
    __IO uint32_t MSTICR;               /*!< Master error interrupt clear reg,      offset: 0x044 */
    __IO uint32_t ICR;                  /*!< Interrupt clear reg,                   offset: 0x048 */
    __IO uint32_t DMACR;                /*!< DMA control reg,                       offset: 0x04C */
    __IO uint32_t DMATDLR;              /*!< DMA transimit data level reg,          offset: 0x050 */
    __IO uint32_t DMARDLR;              /*!< DMA revceive data level reg,           offset: 0x054 */
    __IO uint32_t IDR;                  /*!< Identiation reg,                       offset: 0x058 */
    __IO uint32_t SPIC_VERSION;         /*!< Version ID reg,                        offset: 0x05C */
    union
    {
        __IO uint8_t  BYTE;
        __IO uint16_t HALF;
        __IO uint32_t WORD;
    } DR[16];                           /*!< Data reg,                              offset: 0x060 */
    __IO uint32_t DM_DR[16];            /*!< Data mask data register,               offset: 0x0A0 */
    __IO uint32_t READ_FAST_SINGLE;     /*!< Fast read data cmd of flash,           offset: 0x0E0 */
    __IO uint32_t READ_DUAL_DATA;       /*!< Dual output read cmd of flash,         offset: 0x0E4 */
    __IO uint32_t READ_DUAL_ADDR_DATA;  /*!< Dual I/O read cmd of flash,            offset: 0x0E8 */
    __IO uint32_t READ_QUAD_DATA;       /*!< Quad output read cmd of flash,         offset: 0x0EC */
    __IO uint32_t READ_QUAD_ADDR_DATA;  /*!< Quad I/O read cmd of flash,            offset: 0x0F0 */
    __IO uint32_t WRITE_SINGLE;         /*!< Page program cmd of flash,             offset: 0x0F4 */
    __IO uint32_t WRITE_DUAL_DATA;      /*!< Dual data input program cmd of flash,  offset: 0x0F8 */
    __IO uint32_t WRITE_DUAL_ADDR_DATA; /*!< Dual addr & data program cmd of flash, offset: 0x0FC */
    __IO uint32_t WRITE_QUAD_DATA;      /*!< Quad data input program cmd of flash,  offset: 0x100 */
    __IO uint32_t WRITE_QUAD_ADDR_DATA; /*!< Quad addr & data program cmd of flash, offset: 0x104 */
    __IO uint32_t WRITE_ENABLE;         /*!< Write enabe cmd of flash,              offset: 0x108 */
    __IO uint32_t READ_STATUS;          /*!< Read status cmd of flash,              offset: 0x10C */
    __IO uint32_t CTRLR2;               /*!< Control reg 2,                         offset: 0x110 */
    __IO uint32_t FBAUDR;               /*!< Fast baudrate select,                  offset: 0x114 */
    __IO uint32_t USER_LENGTH;          /*!< Addr length reg,                       offset: 0x118 */
    __IO uint32_t AUTO_LENGTH;          /*!< Auto addr length reg,                  offset: 0x11C */
    __IO uint32_t VALID_CMD;            /*!< Valid cmd reg,                         offset: 0x120 */
    __IO uint32_t FLASH_SIZE;           /*!< Flash size reg,                        offset: 0x124 */
    __IO uint32_t FLUSH_FIFO;           /*!< Flush FIFO reg,                        offset: 0x128 */
    __IO uint32_t DUM_BYTE;             /*!< Dummy byte value,                      offset: 0x12C */
    __IO uint32_t TX_NDF;               /*!< Tx NDF,                                offset: 0x130 */
    __IO uint32_t DEVICE_INFO;          /*!< Device info,                           offset: 0x134 */
    __IO uint32_t TPR0;                 /*!< Timing parameters,                     offset: 0x138 */
    __IO uint32_t AUTO_LENGTH2;         /*!< Auto addr length reg 2,                offset: 0x13C */
} SPIC_TypeDef;

/* ================================================================================ */
/* ================                      PSRAM                     ================ */
/* ================================================================================ */
typedef struct
{
    __IO uint32_t CCR;           /*!< Configuration control register,          Address offset: 0x000 */
    __IO uint32_t DCR;           /*!< Device configuration control register,   Address offset: 0x004 */
    __IO uint32_t IOCR0;         /*!< I/O configuration control regsiter0,     Address offset: 0x008 */
    __IO uint32_t CSR;           /*!< Controller status register,              Address offset: 0x00c */
    __IO uint32_t DRR;           /*!< Device refresh/power-up register,        Address offset: 0x010 */
    __IO uint32_t RSVD0[4];      /*!< Reserved 0,                              Address offset: 0x014 */
    __IO uint32_t CMD_DPIN_NDGE; /*!< Device cmd/addr pin register (NEDGE),    Address offset: 0x024 */
    __IO uint32_t CMD_DPIN;      /*!< Device cmd/addr pin regsiter (PEDGE),    Address offset: 0x028 */
    __IO uint32_t CR_TDPIN;      /*!< Tie DPIN register (sw ctrl dfi_reset_n), Address offset: 0x02c */
    __IO uint32_t MR_INFO;       /*!< Mode latency information regster,        Address offset: 0x030 */
    __IO uint32_t MR0;           /*!< Device CR0 register,                     Address offset: 0x034 */
    __IO uint32_t MR1;           /*!< Device CR1 register,                     Address offset: 0x038 */
    __IO uint32_t RSVD1[9];      /*!< Reserved 1,                              Address offset: 0x03c */
    __IO uint32_t DPDRI;         /*!< DPIN data index register,                Address offset: 0x060 */
    __IO uint32_t DPDR;          /*!< DPIN data register,                      Address offset: 0x064 */
    __IO uint32_t RSVD2[35];     /*!< Reserved 2,                              Address offset: 0x068 */
    __IO uint32_t PCTL_SVN_ID;   /*!< PSRAM_LPC_CTRL version number,           Address offset: 0x0f4 */
    __IO uint32_t PCTL_IDR;      /*!< PSRAM_LPC_CTRL identification register,  Address offset: 0x0f8 */
    __IO uint32_t RSVD3[193];    /*!< Reserved 3,                              Address offset: 0x0fc */
    __IO uint32_t USER0_INDEX;   /*!< User extended index,                     Address offset: 0x400 */
    __IO uint32_t USER0_DATA;    /*!< User extended data,                      Address offset: 0x404 */
} PSRAMC_TypeDef;



/*============================================================================*
 *                              Macros
 *============================================================================*/

/** @defgroup RTL876X_Exported_Macros RTL876X Exported Macros
  * @brief
  * @{
  */
/* ================================================================================ */
/* ================       Secure Peripheral memory map             ================ */
/* ================================================================================ */
#define SYSTEM_REG_BASE                    0x40000000UL
#define PERIBLKCTRL_PF_CLK_REG_BASE        0x40002000UL
#define PERIBLKCTRL_PERICLK_REG_BASE0      0x40002300UL
#define PERIBLKCTRL_SEC_PERICLK_REG_BASE   0x40002400UL
#define PERIBLKCTRL_AUDIO_REG_BASE         0x40002700UL
#define PERIBLKCTRL_INTERNAL_AUTO_REG_BASE 0x40002A00UL
#define PERIBLKCTRL_AUTO_SWITCH_REG_BASE   0x40002B00UL
#define PERIBLKCTRL_INTERNAL_REG_BASE      0x40002C00UL
#define PERIBLKCTRL_SECURITY_REG_BASE      0x40002F00UL
#define PINMUX_REG_BASE                    0x40002500UL

#define PINMUX_CODEC_REG_BASE              0xA00E2A00UL    //bee4 need check this

/*****************************  AON Register table    ****************************/
/*********** Reference: RLE1155_AON_Autogen_table_2021_1208_CFCHIN_2.xlsx FY******/
/* non-secure aon */
#define RTC_REG_BASE                       0x40001800UL
#define LPC_REG_BASE                       0x40001850UL
#define LPC0_REG_BASE                      0x40001850UL
#define PAD_REG_BASE                       0x40001900UL
#define PAD_STS_REG_BASE                   0x40001AA0UL
#define AON_WDG_REG_BASE                   0x40001B60UL
#define AUXADC_REG_BASE                    0x40001B90UL
#define QUAD_DECODER_REG_BASE              0x40001BD0UL
#define WDT_REG_BASE                       0x40001C00UL

/* ================================================================================ */
/* =========== Refence: Bee4_AddrMap_IRQs_DmaPorts_20220913v0.xlsx   ============== */
/* ================================================================================ */
#define PERI_ON_REG_BASE                   0x40002000UL
#define PERI_ON_RCC_REG_BASE               0x40002300UL
#define GPIOA_DEB_REG_BASE                 0x4000234CUL
#define GPIOB_DEB_REG_BASE                 0x40002360UL
#define TIMER_PWM_REG_BASE                 0x4000233CUL
#define SOC_VENDOR_REG_BASE                0x40003000UL
#define QDEC_REG_BASE                      0x40009000UL
#define SPI0_REG_BASE                      0x40013000UL
#define SPI1_REG_BASE                      0x40013400UL
#define SPI_SLAVE_REG_BASE                 0x40013800UL
#define ENHANCED_TIMER_REG_BASE            0x40017000UL
#define MODEMRFCPI_REG_BASE                0x40018000UL
#define I2S0_REG_BASE                      0x40020000UL
#define I2S1_REG_BASE                      0x40021000UL
#define SPI_CODEC_REG_BASE                 0x40022000UL
#define DISPLAY_CTRL_REG_BASE              0x40023000UL
#define RXI350_DMAC0_CFG_REG_BASE          0x40024000UL
#define PPE_CFG_REG_BASE                   0x40025000UL
#define ISO7816_REG_BASE                   0x40026000UL
#define SEGCOM_CTL_REG_BASE                0x40027000UL
#define CAN_REG_BASE                       0x40028000UL
#define SPIC_PHY_REG_BASE                  0x40029000UL

#define PUBLIC_KEY_ENGINE_REG_BASE         0x40080000UL
#define FLASH_SEC_REG_BASE                 0x400C0000UL
#define AES_REG_BASE                       0x400C1000UL
#define SHA256_REG_BASE                    0x400C2000UL
#define TRNG_REG_BASE                      0x400C2400UL
#define EFUSE_CONTROLLER_REG_BASE          0x400C2800UL
#define USB_OTG_CFG_REG_BASE               0x40100000UL
#define SPIC0_REG_BASE                     0x40140000UL
#define SDHC_REG_BASE                      0x40150000UL
#define SPIC1_REG_BASE                     0x40160000UL
#define SPIC2_REG_BASE                     0x40170000UL
#define GPIOA_REG_BASE                     0x40030000UL
#define GPIOB_REG_BASE                     0x40030800UL
#define TIMER_REG_BASE                     0x40031000UL
#define SAR_ADC_REG_BASE                   0x40032000UL
#define ADC_24BIT_REG_BASE                 0x40033000UL
#define UART0_REG_BASE                     0x40034000UL
#define UART1_REG_BASE                     0x40034400UL
#define UART2_REG_BASE                     0x40034800UL
#define UART3_REG_BASE                     0x40034C00UL
#define UART4_REG_BASE                     0x40035000UL
#define UART5_REG_BASE                     0x40035400UL
#define I2C0_REG_BASE                      0x40035800UL
#define I2C1_REG_BASE                      0x40035C00UL
#define I2C2_REG_BASE                      0x40036000UL
#define I2C3_REG_BASE                      0x40036400UL
#define SPI_3WIRE_REG_BASE                 0x40036800UL
#define KEYSCAN_REG_BASE                   0x40037000UL
#define IR_RC_REG_BASE                     0x40038000UL
#define ETH_CTRL_REG_BASE                  0x40040000UL
#define BLUEWIZ_REG_BASE                   0x40050000UL
#define BT_DMA_UART_BASE                   0x40051000UL
#define BT_DMA_BASE                        0x40055000UL
#define BT_VENDOR_REG_BASE                 0x40058000UL
#define ZIGBEE_REG_BASE                    0x4005C000UL
#define SPI0_HS_REG_BASE                   0x40060000UL
#define IMDC_REG_BASE                     0x40070000UL

#define GPIOA_REG2_BASE                    (GPIOA_REG_BASE + 0x0100)
#define GPIOB_REG2_BASE                    (GPIOB_REG_BASE + 0x0100)
#define GDMA0_CHANNEL_REG_BASE             RXI350_DMAC0_CFG_REG_BASE
#define GDMA0_REG_BASE                     (GDMA0_CHANNEL_REG_BASE + 0x02c0)
#define GDMA0_Channel0_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0000)
#define GDMA0_Channel1_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0058)
#define GDMA0_Channel2_BASE                (GDMA0_CHANNEL_REG_BASE + 0x00b0)
#define GDMA0_Channel3_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0108)
#define GDMA0_Channel4_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0160)
#define GDMA0_Channel5_BASE                (GDMA0_CHANNEL_REG_BASE + 0x01b8)
#define GDMA0_Channel6_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0210)
#define GDMA0_Channel7_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0268)
#define GDMA0_Channel8_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0400)
#define GDMA0_Channel9_BASE                (GDMA0_CHANNEL_REG_BASE + 0x0458)

#define TIMER_0_REG_BASE                   (TIMER_REG_BASE + 0x0000)
#define TIMER_1_REG_BASE                   (TIMER_REG_BASE + 0x0014)
#define TIMER_2_REG_BASE                   (TIMER_REG_BASE + 0x0028)
#define TIMER_3_REG_BASE                   (TIMER_REG_BASE + 0x003c)
#define TIMER_4_REG_BASE                   (TIMER_REG_BASE + 0x0050)
#define TIMER_5_REG_BASE                   (TIMER_REG_BASE + 0x0064)
#define TIMER_6_REG_BASE                   (TIMER_REG_BASE + 0x0078)
#define TIMER_7_REG_BASE                   (TIMER_REG_BASE + 0x008c)

#define ENHANCED_TIMER0_REG_BASE           (ENHANCED_TIMER_REG_BASE + 0x0000)
#define ENHANCED_TIMER1_REG_BASE           (ENHANCED_TIMER_REG_BASE + 0x0024)
#define ENHANCED_TIMER2_REG_BASE           (ENHANCED_TIMER_REG_BASE + 0x0048)
#define ENHANCED_TIMER3_REG_BASE           (ENHANCED_TIMER_REG_BASE + 0x006c)
#define ENHTIM_SHARE_REG_BASE              (ENHANCED_TIMER_REG_BASE + 0x0120)
#define ENHANCED_PWM0_REG_BASE             (ENHANCED_TIMER_REG_BASE + 0x0300)
#define ENHANCED_PWM1_REG_BASE             (ENHANCED_TIMER_REG_BASE + 0x0304)
#define ENHANCED_PWM2_REG_BASE             (ENHANCED_TIMER_REG_BASE + 0x0308)
#define ENHANCED_PWM3_REG_BASE             (ENHANCED_TIMER_REG_BASE + 0x030C)

#define REG_ENHTIMER_ONESHOT_CFG           (ENHANCED_TIMER_REG_BASE + 0x0320)

#define WDG_REG_BASE                       (SOC_VENDOR_REG_BASE + 0x100)


/****************************End of Secure register base*****************************/

/* ================================================================================ */
/* ================         Secure Peripheral declaration          ================ */
/* ================================================================================ */
/** @brief System */
#define SoC_VENDOR                      ((SoC_VENDOR_REG_TypeDef    *) SOC_VENDOR_REG_BASE)
#define PERIBLKCTRL_PF_CLK              ((PERI_BLKCTRL_PF_CLK_TypeDef   *) PERIBLKCTRL_PF_CLK_REG_BASE)
#define PERIBLKCTRL_PERI_CLK            ((PERI_BLKCTRL_PERI_CLK_TypeDef *) PERIBLKCTRL_PERICLK_REG_BASE0)
#define PERIBLKCTRL_INTERNAL_AUTO       ((PERI_BLKCTRL_INTERNAL_AUTO_TypeDef *) PERIBLKCTRL_INTERNAL_AUTO_REG_BASE)
#define PERIBLKCTRL_AUTO_SWITCH         ((PERI_BLKCTRL_AUTO_SWITCH_TypeDef *) PERIBLKCTRL_AUTO_SWITCH_REG_BASE)
#define PERIBLKCTRL_INTERNAL            ((PERI_BLKCTRL_INTERNAL_TypeDef *) PERIBLKCTRL_INTERNAL_REG_BASE)
#define SECURE_PERIPHERAL_CLOCK_CONTROL ((SECURE_PERIPHERAL_CLOCK_CONTROL_TypeDef *) PERIBLKCTRL_SEC_PERICLK_REG_BASE)
#define PERIBLKCTRL_AUDIO               ((PERIBLKCTRL_AUDIO_TypeDef *) PERIBLKCTRL_AUDIO_REG_BASE)

/** @brief IO */
#define HWAES                           ((HW_AES_TypeDef           *) AES_REG_BASE)
#define HWSHA256                        ((HW_SHA256_TypeDef        *) SHA256_REG_BASE)
//#define ICG                             ((ICG_TypeDef              *) ICG_REG_BASE)
//#define RAN_GEN                         ((RAN_GEN_TypeDef          *) RANDOM_GEN_REG_BASE)
#define SPIC0                           ((SPIC_TypeDef             *) SPIC0_REG_BASE)
#define SPIC1                           ((SPIC_TypeDef             *) SPIC1_REG_BASE)
#define SPIC2                           ((SPIC_TypeDef             *) SPIC2_REG_BASE)
/***********************************End of Secure************************************/


/* ================================================================================ */
/* ================   Non-Secure Peripheral Memory Map             ================ */
/* ================================================================================ */

/******************   Non-Secure Peripheral Register Base  **************************/


/*********************************End of Non-Secure**********************************/

#define PERI_REG_ADDR_TO_SECURE(addr)        ((uint32_t)addr | BIT28)
#define PERI_REG_ADDR_TO_NONSECURE(addr)     ((uint32_t)addr & ~BIT28)

/************************ For lowerstack-dev ************************/
#define TIM0_REG_BASE                         TIMER_0_REG_BASE
#define TIMER_A0_REG_BASE                     TIMER_0_REG_BASE
#define TIMA_CH0                              TIM0
#define TIMA_CH1                              TIM1
#define VENDOR_REG_BASE                       SOC_VENDOR_REG_BASE
#define LOW_STACK_BZDMA_REG_BASE              BT_VENDOR_REG_BASE
#define LOW_STACK_BT_DMA_REG_BASE_ADDR        BT_DMA_BASE
#define LOW_STACK_BT_DMA_UART_BASE_ADDRESS    BT_DMA_UART_BASE
#define LOW_STACK_BB_BASE_ADDR                BLUEWIZ_REG_BASE

/******************************* end ********************************/

/* ================================================================================ */
/* ================                   Vendor macros                ================ */
/* ================================================================================ */
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN                        0
#endif

#ifndef BIG_ENDIAN
#define BIG_ENDIAN                           1
#endif

#define SYSTEM_ENDIAN                        LITTLE_ENDIAN

#define SWAP32(x) ((uint32_t)(                         \
                                                       (((uint32_t)(x) & (uint32_t)0x000000ff) << 24) |            \
                                                       (((uint32_t)(x) & (uint32_t)0x0000ff00) <<  8) |            \
                                                       (((uint32_t)(x) & (uint32_t)0x00ff0000) >>  8) |            \
                                                       (((uint32_t)(x) & (uint32_t)0xff000000) >> 24)))

#define WAP16(x) ((uint16_t)(                         \
                                                      (((uint16_t)(x) & (uint16_t)0x00ff) <<  8) |            \
                                                      (((uint16_t)(x) & (uint16_t)0xff00) >>  8)))

#if SYSTEM_ENDIAN == LITTLE_ENDIAN
#ifndef rtk_le16_to_cpu
#define rtk_cpu_to_le32(x)      ((uint32_t)(x))
#define rtk_le32_to_cpu(x)      ((uint32_t)(x))
#define rtk_cpu_to_le16(x)      ((uint16_t)(x))
#define rtk_le16_to_cpu(x)      ((uint16_t)(x))
#define rtk_cpu_to_be32(x)      SWAP32((x))
#define rtk_be32_to_cpu(x)      SWAP32((x))
#define rtk_cpu_to_be16(x)      WAP16((x))
#define rtk_be16_to_cpu(x)      WAP16((x))
#endif

#elif SYSTEM_ENDIAN == BIG_ENDIAN
#ifndef rtk_le16_to_cpu
#define rtk_cpu_to_le32(x)      SWAP32((x))
#define rtk_le32_to_cpu(x)      SWAP32((x))
#define rtk_cpu_to_le16(x)      WAP16((x))
#define rtk_le16_to_cpu(x)      WAP16((x))
#define rtk_cpu_to_be32(x)      ((uint32_t)(x))
#define rtk_be32_to_cpu(x)      ((uint32_t)(x))
#define rtk_cpu_to_be16(x)      ((uint16_t)(x))
#define rtk_be16_to_cpu(x)      ((uint16_t)(x))
#endif
#endif

#define HAL_READ32(base, addr)            \
    rtk_le32_to_cpu(*((volatile uint32_t *)(base + addr)))

#define HAL_WRITE32(base, addr, value32)  \
    ((*((volatile uint32_t *)(base + addr))) = rtk_cpu_to_le32(value32))

#define HAL_UPDATE32(addr, mask, value32)  \
    HAL_WRITE32(0, addr, (HAL_READ32(0, addr) & ~(mask)) | ((value32) & (mask)))

#define HAL_READ16(base, addr)            \
    rtk_le16_to_cpu(*((volatile uint16_t *)(base + addr)))

#define HAL_WRITE16(base, addr, value)  \
    ((*((volatile uint16_t *)(base + addr))) = rtk_cpu_to_le16(value))

#define HAL_UPDATE16(addr, mask, value16)  \
    HAL_WRITE16(0, addr, (HAL_READ16(0, addr) & ~(mask)) | ((value16) & (mask)))

#define HAL_READ8(base, addr)            \
    (*((volatile uint8_t *)(base + addr)))

#define HAL_WRITE8(base, addr, value)  \
    ((*((volatile uint8_t *)(base + addr))) = value)

#define HAL_UPDATE8(addr, mask, value8)  \
    HAL_WRITE8(0, addr, (HAL_READ8(0, addr) & ~(mask)) | ((value8) & (mask)))

#define BIT0        0x00000001
#define BIT1        0x00000002
#define BIT2        0x00000004
#define BIT3        0x00000008
#define BIT4        0x00000010
#define BIT5        0x00000020
#define BIT6        0x00000040
#define BIT7        0x00000080
#define BIT8        0x00000100
#define BIT9        0x00000200
#define BIT10       0x00000400
#define BIT11       0x00000800
#define BIT12       0x00001000
#define BIT13       0x00002000
#define BIT14       0x00004000
#define BIT15       0x00008000
#define BIT16       0x00010000
#define BIT17       0x00020000
#define BIT18       0x00040000
#define BIT19       0x00080000
#define BIT20       0x00100000
#define BIT21       0x00200000
#define BIT22       0x00400000
#define BIT23       0x00800000
#define BIT24       0x01000000
#define BIT25       0x02000000
#define BIT26       0x04000000
#define BIT27       0x08000000
#define BIT28       0x10000000
#define BIT29       0x20000000
#define BIT30       0x40000000
#define BIT31       0x80000000

#ifndef BIT
#define BIT(_n)     (uint32_t)(1U << (_n))
#endif
#define BIT64(_n)   (1ULL << (_n))

/* Uncomment the line below to expanse the "assert_param" macro in the
   Standard Peripheral Library drivers code */
//#define USE_FULL_ASSERT


/** @} */ /* End of group RTL876X_Exported_Macros */


/*============================================================================*
 *                                Functions
 *============================================================================*/
/** @defgroup RTL876X_Exported_Functions RTL876X Exported Functions
    * @brief
    * @{
    */
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports
  *         the name of the source file and the source line number of the call
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0 : io_assert_failed((uint8_t *)__FILE__, __LINE__))
void io_assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

/** End of RTL876X_Exported_Functions
  * @}
  */

/** End of RTL876X
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif  /* RTL876X_H */
