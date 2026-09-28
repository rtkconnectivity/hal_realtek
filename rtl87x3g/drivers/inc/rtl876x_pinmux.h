/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */


#ifndef _RTL876X_PINMUX_H_
#define _RTL876X_PINMUX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "pin_def.h"
#include "cpu_setting.h"
#include "io.h"


/******************* Reference: pin_mux_20250115_v0.xlsx *******************/
/**
  * @brief Pinmux. (Pinmux)
  */

#define PINMUX_REG0_NUM                        (28)

typedef struct                                      /*!< Pinmux Structure */
{
    __IO uint32_t
    CFG[PINMUX_REG0_NUM];                              /*!<                                            */
} PINMUX_TypeDef;

#define PINMUX_REG0_BASE                       0x40000500UL
#define PINMUX_REG1_BASE                       0x40000C00UL
#define PINMUX0                                ((PINMUX_TypeDef           *) PINMUX_REG0_BASE)
#define PINMUX1                                ((PINMUX_TypeDef           *) PINMUX_REG1_BASE)

#define PAD_BIT_TABLE_OFFSET                   (12)
#define PAD_ITEM(reg_addr, bit_num)            ((bit_num << PAD_BIT_TABLE_OFFSET) | (reg_addr))
#define PAD_ITEM_ADDR(item)                    (item & 0xFFF)
#define PAD_ITEM_BIT_OFFSET(item)              ((item & 0xF000) >> PAD_BIT_TABLE_OFFSET)
#define PAD_ITEM_EMPTY                         (0)

/** @addtogroup 87x3g_PINMUX PINMUX
  * @brief PINMUX driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/


/** @defgroup 87x3g_PINMUX_Exported_Constants PINMUX Exported Constants
  * @{
  */

/** @defgroup 87x3g_Pin_Function_Number Pin Function Number
  * @{
  */

#define IDLE_MODE                   0   //!< Function for entering idle mode.
#define UART4_TX                    1   //!< Transmit function for UART4 line.
#define UART4_RX                    2   //!< Receive function for UART4 line.
#define UART4_CTS                   3   //!< Function for UART4 CTS.
#define UART4_RTS                   4   //!< Function for UART4 RTS.
#define I2C0_CLK                    5   //!< Function for I2C0 clock line.
#define I2C0_DAT                    6   //!< Function for I2C0 data line.
#define I2C1_CLK                    7   //!< Function for I2C1 clock line.
#define I2C1_DAT                    8   //!< Function for I2C1 data line.
#define PWM9_P                      9   //!< Positive terminal for PWM9 function.
#define PWM9_N                      10  //!< Negative terminal for PWM9 function.
#define PWM4                        11  //!< Function for PWM4.
#define PWM5                        12  //!< Function for PWM5.
#define PWM6_P                      13  //!< Positive terminal for PWM6 function.
#define PWM7_P                      14  //!< Positive terminal for PWM7 function.
#define PWM8_P                      15  //!< Positive terminal for PWM8 function.
#define UART3_TX                    17  //!< Transmit function for UART3 line.
#define UART3_RX                    18  //!< Receive function for UART3 line.
#define UART3_CTS                   19  //!< Function for UART3 CTS.
#define UART3_RTS                   20  //!< Function for UART3 RTS.
#define QDEC_PHASE_A_X              21  //!< Qdecoder phase A function for axis X.
#define QDEC_PHASE_B_X              22  //!< Qdecoder phase B function for axis X.
#define QDEC_PHASE_A_Y              23  //!< Qdecoder phase A function for axis Y.
#define QDEC_PHASE_B_Y              24  //!< Qdecoder phase B function for axis Y.
#define QDEC_PHASE_A_Z              25  //!< Qdecoder phase A function for axis Z.
#define QDEC_PHASE_B_Z              26  //!< Qdecoder phase B function for axis Z.
#define UART1_TX                    27  //!< Transmit function for UART1 line.
#define UART1_RX                    28  //!< Receive function for UART1 line.
#define UART2_TX                    29  //!< Transmit function for UART2 line.
#define UART2_RX                    30  //!< Receive function for UART2 line.
#define UART2_CTS                   31  //!< Function for UART2 CTS.
#define UART2_RTS                   32  //!< Function for UART2 RTS.
#define IRDA_TX                     33  //!< Transmit function for IRDA.
#define IRDA_RX                     34  //!< Receive function for IRDA.
#define UART0_TX                    35  //!< Transmit function for UART0 line.
#define UART0_RX                    36  //!< Receive function for UART0 line.
#define UART0_CTS                   37  //!< Function for UART0 CTS.
#define UART0_RTS                   38  //!< Function for UART0 RTS.
#define SPI1_SS_N_0_MASTER          39  //!< Slave select 0 function for SPI1 in master mode.
#define SPI1_SS_N_1_MASTER          40  //!< Slave select 1 function for SPI1 in master mode.
#define SPI1_SS_N_2_MASTER          41  //!< Slave select 2 function for SPI1 in master mode.
#define SPI1_CLK_MASTER             42  //!< Clock line function for SPI1 in master mode.
#define SPI1_MO_MASTER              43  //!< Master output function for SPI1 in master mode.
#define SPI1_MI_MASTER              44  //!< Master input function for SPI1 in master mode.
#define SPI_SS_N_0_SLAVE            45  //!< Slave select 0 function for SPI in slave mode.
#define SPI_CLK_SLAVE               46  //!< Clock line function for SPI in slave mode.
#define SPI_SO_SLAVE                47  //!< Slave output function for SPI in slave mode.
#define SPI_SI_SLAVE                48  //!< Slave input function for SPI in slave mode.
#define SPI0_SS_N_0_MASTER          49  //!< Slave select 0 function for SPI0 in master mode.
#define SPI0_CLK_MASTER             50  //!< Clock line function for SPI0 in master mode.
#define SPI0_MO_MASTER              51  //!< Master output function for SPI0 in master mode.
#define SPI0_MI_MASTER              52  //!< Master input function for SPI0 in master mode.
#define PWM6_N                      53  //!< Negative terminal for PWM6 function.
#define PWM7_N                      54  //!< Negative terminal for PWM7 function.
#define PWM8_N                      55  //!< Negative terminal for PWM8 function.
#define SWD_CLK                     56  //!< Clock line function for Serial Wire Debug (SWD).
#define SWD_DIO                     57  //!< Data input/output function for Serial Wire Debug (SWD).
#define KEY_COL_0                   58  //!< Function for key column 0.
#define KEY_COL_1                   59  //!< Function for key column 1.
#define KEY_COL_2                   60  //!< Function for key column 2.
#define KEY_COL_3                   61  //!< Function for key column 3.
#define KEY_COL_4                   62  //!< Function for key column 4.
#define KEY_COL_5                   63  //!< Function for key column 5.
#define KEY_COL_6                   64  //!< Function for key column 6.
#define KEY_COL_7                   65  //!< Function for key column 7.
#define KEY_COL_8                   66  //!< Function for key column 8.
#define KEY_COL_9                   67  //!< Function for key column 9.
#define KEY_COL_10                  68  //!< Function for key column 10.
#define KEY_COL_11                  69  //!< Function for key column 11.
#define KEY_COL_12                  70  //!< Function for key column 12.
#define KEY_COL_13                  71  //!< Function for key column 13.
#define KEY_COL_14                  72  //!< Function for key column 14.
#define KEY_COL_15                  73  //!< Function for key column 15.
#define KEY_COL_16                  74  //!< Function for key column 16.
#define KEY_COL_17                  75  //!< Function for key column 17.
#define KEY_COL_18                  76  //!< Function for key column 18.
#define KEY_COL_19                  77  //!< Function for key column 19.
#define KEY_ROW_0                   78  //!< Function for key row 0.
#define KEY_ROW_1                   79  //!< Function for key row 1.
#define KEY_ROW_2                   80  //!< Function for key row 2.
#define KEY_ROW_3                   81  //!< Function for key row 3.
#define KEY_ROW_4                   82  //!< Function for key row 4.
#define KEY_ROW_5                   83  //!< Function for key row 5.
#define KEY_ROW_6                   84  //!< Function for key row 6.
#define KEY_ROW_7                   85  //!< Function for key row 7.
#define KEY_ROW_8                   86  //!< Function for key row 8.
#define KEY_ROW_9                   87  //!< Function for key row 9.
#define KEY_ROW_10                  88  //!< Function for key row 10.
#define KEY_ROW_11                  89  //!< Function for key row 11.
#define DWGPIO                      90  //!< Function for GPIO.
#define LRC_SPORT1                  91  //!< Function for LRC SPORT1.
#define BCLK_SPORT1                 92  //!< Function for BCLK SPORT1.
#define ADCDAT_SPORT1               93  //!< Function for ADCDAT SPORT1.
#define DACDAT_SPORT1               94  //!< Function for DACDAT SPORT1.
#define DMIC1_CLK                   96  //!< Function for clock line for DMIC1.
#define DMIC1_DAT                   97  //!< Function for data line for DMIC1.
#define LRC_I_CODEC_SLAVE           98  //!< Function for LRC_I_CODEC in slave mode.
#define BCLK_I_CODEC_SLAVE          99  //!< Function for BCLK_I_CODEC in slave mode.
#define SDI_CODEC_SLAVE             100 //!< Function for SDI_CODEC in slave mode.
#define SDO_CODEC_SLAVE             101 //!< Function for SDO_CODEC in slave mode.
#define LRC_I_PCM                   102 //!< Function for LRC_I_PCM.
#define BCLK_I_PCM                  103 //!< Function for BCLK_I_PCM.
#define SDI_PCM                     104 //!< Function for serial data in for PCM.
#define SDO_PCM                     105 //!< Function for serial data out for PCM.
#define BT_COEX_I_0                 106 //!< Function for BT_COEX input 0.
#define BT_COEX_I_1                 107 //!< Function for BT_COEX input 1.
#define BT_COEX_I_2                 108 //!< Function for BT_COEX input 2.
#define BT_COEX_I_3                 109 //!< Function for BT_COEX input 3.
#define BT_COEX_O_0                 110 //!< Function for BT_COEX output 0.
#define BT_COEX_O_1                 111 //!< Function for BT_COEX output 1.
#define BT_COEX_O_2                 112 //!< Function for BT_COEX output 2.
#define BT_COEX_O_3                 113 //!< Function for BT_COEX output 3.
#define PTA_I2C_CLK_SLAVE           114 //!< Function for I2C clock line for PTA in slave mode.
#define PTA_I2C_DAT_SLAVE           115 //!< Function for I2C data line for PTA in slave mode.
#define PTA_I2C_INT_OUT             116 //!< Function for interrupt output for PTA I2C.
#define DSP_GPIO_OUT                117 //!< Function for GPIO output for DSP.
#define DSP_JTCK                    118 //!< Function for JTAG clock for DSP.
#define DSP_JTDI                    119 //!< Function for JTAG data in for DSP.
#define DSP_JTDO                    120 //!< Function for JTAG data out for DSP.
#define DSP_JTMS                    121 //!< Function for JTAG mode select for DSP.
#define DSP_JTRST                   122 //!< Function for JTAG reset for DSP.
#define LRC_SPORT0                  123 //!< Function for LRC SPORT0.
#define BCLK_SPORT0                 124 //!< Function for BCLK SPORT0.
#define ADCDAT_SPORT0               125 //!< Function for ADCDAT SPORT0.
#define DACDAT_SPORT0               126 //!< Function for DACDAT SPORT0.
#define MCLK_M                      127 //!< Function for MCLK_M.
#define SPI0_SS_N_1_MASTER          128 //!< Slave select 1 function for SPI0 in master mode.
#define SPI0_SS_N_2_MASTER          129 //!< Slave select 2 function for SPI0 in master mode.
#define SPI2_SS_N_0_MASTER          130 //!< Slave select 0 function for SPI2 in master mode.
#define SPI2_CLK_MASTER             131 //!< Clock line function for SPI2 in master mode.
#define SPI2_MO_MASTER              132 //!< Master output function for SPI2 in master mode.
#define SPI2_MI_MASTER              133 //!< Master input function for SPI2 in master mode.
#define I2C2_CLK                    134 //!< Clock line function for I2C2.
#define I2C2_DAT                    135 //!< Data line function for I2C2.
#define ISO7816_RST                 136 //!< Reset line function for ISO7816.
#define ISO7816_CLK                 137 //!< Clock line function for ISO7816.
#define ISO7816_IO                  138 //!< Input/output line function for ISO7816.
#define ISO7816_VCC_EN              139 //!< VCC enable function for ISO7816.
#define UART5_TX                    140 //!< Transmit function for UART5 line.
#define UART5_RX                    141 //!< Receive function for UART5 line.
#define UART5_CTS                   142 //!< Function for UART5 CTS.
#define UART5_RTS                   143 //!< Function for UART5 RTS.
#define DMIC2_CLK                   144 //!< Function for clock line for DMIC2.
#define DMIC2_DAT                   145 //!< Function for data line for DMIC2.
#define DMIC3_CLK                   146 //!< Function for clock line for DMIC3.
#define DMIC3_DAT                   147 //!< Function for data line for DMIC3.
#define DMIC4_CLK                   148 //!< Function for clock line for DMIC4.
#define DMIC4_DAT                   149 //!< Function for data line for DMIC4.
#define ADCDAT_SPORT2               150 //!< Function for ADCDAT SPORT2.
#define BCLK_SPORT2                 151 //!< Function for BCLK SPORT2.
#define CAN0_TX                     155 //!< Transmit function for CAN0.
#define CAN0_RX                     156 //!< Receive function for CAN0.
#define CAN1_TX                     157 //!< Transmit function for CAN1.
#define CAN1_RX                     158 //!< Receive function for CAN1.
#define CAN2_TX                     159 //!< Transmit function for CAN2.
#define CAN2_RX                     160 //!< Receive function for CAN2.
#define EN_EXPA                     163 //!< Enable function for EXPA.
#define EN_EXLNA                    164 //!< Enable function for EXLNA.
#define WL_BT_GNT_I                 165 //!< Function for WL_BT grant input.
#define ANT_CTL_O                   166 //!< Function for antenna control output.
#define UART1_CTS                   167 //!< Function for UART1 CTS.
#define UART1_RTS                   168 //!< Function for UART1 RTS.
#define SPIC0_SCK_FUNC              169 //!< Clock line function for SPIC0.
#define SPIC0_CSN_FUNC              170 //!< Chip select line function for SPIC0.
#define SPIC0_SIO_0                 171 //!< Serial input/output line 0 function for SPIC0.
#define SPIC0_SIO_1                 172 //!< Serial input/output line 1 function for SPIC0.
#define SPIC0_SIO_2                 173 //!< Serial input/output line 2 function for SPIC0.
#define SPIC0_SIO_3                 174 //!< Serial input/output line 3 function for SPIC0.
#define LRC_RX_CODEC_SLAVE          175 //!< LRC receive function for codec in slave mode.
#define LRC_RX_SPORT0               176 //!< LRC receive function for SPORT0.
#define LRC_RX_SPORT1               177 //!< LRC receive function for SPORT1.
#define LRC_RX_SPORT2               178 //!< LRC receive function for SPORT2.
#define CLK_CPUDIVIDEDBY2           180 //!< Function for CPU clock divided by 2.
#define CLK_DSPDIVIDEDBY2           181 //!< Function for DSP clock divided by 2.
#define PDM_DATA                    193 //!< Function for PDM data.
#define PDM_CLK                     194 //!< Function for PDM clock.
#define KEY_ROW_12                  200 //!< Function for key row 12.
#define KEY_ROW_13                  201 //!< Function for key row 13.
#define KEY_ROW_14                  202 //!< Function for key row 14.
#define KEY_ROW_15                  203 //!< Function for key row 15.
#define KEY_ROW_16                  204 //!< Function for key row 16.
#define KEY_ROW_17                  205 //!< Function for key row 17.
#define ANT_SW0_AOA_AOD             229 //!< Function for antenna switch 0 for AOA/AOD.
#define ANT_SW1_AOA_AOD             230 //!< Function for antenna switch 1 for AOA/AOD.
#define ANT_SW2_AOA_AOD             231 //!< Function for antenna switch 2 for AOA/AOD.
#define ANT_SW3_AOA_AOD             232 //!< Function for antenna switch 3 for AOA/AOD.
#define ANT_SW4_AOA_AOD             233 //!< Function for antenna switch 4 for AOA/AOD.
#define ANT_SW5_AOA_AOD             234 //!< Function for antenna switch 5 for AOA/AOD.
#define DIGI_DEBUG                  255 //!< Function for digital debugging.

/** End of group 87x3g_Pin_Function_Number
  * @}
  */

/** End of group 87x3g_PINMUX_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/

/** @defgroup 87x3g_PINMUX_Exported_Types PINMUX Exported Types
  * @{
  */

/** @cond private
  * @defgroup 87x3g_AON_FAST_REG_PAD_TYPE AON Fast Register Pad Type
  * @{
  */
typedef union _AON_FAST_REG_PAD_TYPE
{
    uint16_t d16;
    struct
    {
        uint16_t HS_MUX: 1;
        uint16_t HS_HS_FUNC_SEL: 1;
        uint16_t PAD_WKUP_DEB_EN: 1;
        uint16_t PAD_S_VCORE2: 1;
        uint16_t PAD_S: 1;
        uint16_t PAD_SMT: 1;
        uint16_t PAD_E3: 1;
        uint16_t PAD_E2: 1;
        uint16_t PAD_SHDN: 1;
        uint16_t AON_PAD_E: 1;
        uint16_t PAD_WKPOL: 1;
        uint16_t PAD_WKEN: 1;
        uint16_t AON_PAD_O: 1;
        uint16_t PAD_PUPDC: 1;
        uint16_t PAD_PU: 1;
        uint16_t PAD_PU_EN: 1;
    };
} AON_FAST_REG_PAD_TYPE;

/** End of Group 87x3g_AON_FAST_REG_PAD_TYPE
  * @}
  * @endcond
  */

/** @cond private
  * @defgroup 87x3g_AON_FAST_PAD_BIT_POS_TYPE AON Fast Pad Pos Type
  * @{
  */
typedef enum _AON_FAST_PAD_POS_TYPE
{
    PAD_HS_MUX        = 0,
    PAD_HS_FUNC_SEL   = 1,
    PAD_WKUP_DEB_EN   = 2,
    PAD_S_VCORE2      = 3,
    PAD_PINMUX_M_EN   = 4,
    PAD_SMT           = 5,
    PAD_E3            = 6,
    PAD_E2            = 7,
    PAD_SHDN          = 8,
    AON_PAD_E         = 9,
    PAD_WKPOL         = 10,
    PAD_WKEN          = 11,
    AON_PAD_O         = 12,
    PAD_PUPDC         = 13,
    PAD_PU            = 14,
    PAD_PU_EN         = 15,
} AON_FAST_PAD_BIT_POS_TYPE;

/** End of Group 87x3g_AON_FAST_PAD_BIT_POS_TYPE
  * @}
  * @endcond
  */

/** @defgroup 87x3g_PAD_Pull_Mode PAD Pull Mode
  * @{
  */
/**
 * @brief Pad pull mode definition.
 */
typedef enum _PAD_Pull_Mode
{
    PAD_PULL_DOWN,     //!< Enable the pull-down resistor function for the pad.
    PAD_PULL_UP,       //!< Enable the pull-up resistor function for the pad.
    PAD_PULL_NONE,     //!< Pad is in a floating state.
} PAD_Pull_Mode;

/** End of group 87x3g_PAD_Pull_Mode
  * @}
  */

/** @defgroup 87x3g_PAD_Pull_Value PAD Pull Value
  * @{
  */
/**
 * @brief Pad pull value definition.
 */
typedef enum _PAD_Pull_Value
{
    PAD_PULL_HIGH, //!< PAD pull value is high level.
    PAD_PULL_LOW, //!< PAD pull value is low level.

} PAD_Pull_VALUE;

/** End of group 87x3g_PAD_Pull_Value
  * @}
  */

/** @defgroup 87x3g_PAD_Pull_EN PAD Pull Enable
  * @{
  */
/**
 * @brief Pad pull function definition.
 */
typedef enum _PAD_Pull_EN
{
    PAD_PULL_DISABLE, //!< Enable pad pull.
    PAD_PULL_ENABLE //!< Disable pad pull.
} PAD_Pull_EN;


/** End of group 87x3g_PAD_Pull_EN
  * @}
  */

/** @defgroup 87x3g_PAD_Mode PAD Mode
  * @{
  */
/**
 * @brief Pad mode definition.
 */
typedef enum _PAD_Mode
{
    PAD_SW_MODE, //!< PAD pin is configured in software mode.
    PAD_PINMUX_MODE //!< PAD pin is configured in pinmux mode.
} PAD_Mode;

/** End of group 87x3g_PAD_Mode
  * @}
  */

/** @defgroup 87x3g_PAD_Power_Mode PAD Power Mode
  * @{
  */
/**
 * @brief Pad power mode definition.
 */
typedef enum _PAD_PWR_Mode
{
    PAD_SHUTDOWN, //!< Shutdown power of pad.
    PAD_IS_PWRON = 1 //!< Enable power of pad.
} PAD_PWR_Mode;

/** End of group 87x3g_PAD_Power_Mode
  * @}
  */

/** @defgroup 87x3g_PAD_Output_Config PAD Output Config
  * @{
  */
/**
 * @brief Pad output function definition.
 */
typedef enum _PAD_OUTPUT_ENABLE_Mode
{
    PAD_OUT_DISABLE,   //!< Disable pad output.
    PAD_OUT_ENABLE     //!< Enable pad output.
} PAD_OUTPUT_ENABLE_Mode;

/** End of group 87x3g_PAD_Output_Config
  * @}
  */

/** @defgroup 87x3g_PAD_Output_Value PAD Output Value
  * @{
  */
/**
 * @brief Pad output value definition.
 */
typedef enum _PAD_OUTPUT_VAL
{
    PAD_OUT_LOW,     //!< The pad outputs a low level.
    PAD_OUT_HIGH     //!< The pad outputs a high level.
} PAD_OUTPUT_VAL;

/** End of group 87x3g_PAD_Output_Value
  * @}
  */

/** @defgroup 87x3g_PAD_Function_Config PAD Function Config
  * @{
  */
/**
 * @brief Pad function config value definition.
 */
#define PAD_AON_MUX_TYPE         (0x10)
typedef enum _PAD_FUNCTION_CONFIG_VALUE
{
    AON_GPIO = 0, //!< Default GPIO function.
    CLK_REQ  = 4, //!< Clock request, internal debug function.
    XTAL_CLK = 7, //!< XTAL clock.
    LED0     = PAD_AON_MUX_TYPE | 0, //!< SLEEP LED channel 0.
    LED1     = PAD_AON_MUX_TYPE | 2, //!< SLEEP LED channel 1.
    LED2     = PAD_AON_MUX_TYPE | 4, //!< SLEEP LED channel 2.
    LP_PWM   = PAD_AON_MUX_TYPE | 6, //!< LP PWM function.
} PAD_FUNCTION_CONFIG_VAL;

/** End of group 87x3g_PAD_Function_Config
  * @}
  */

/** @defgroup 87x3g_PAD_WakeUp_Polarity_Value PAD Wake Up Polarity Value
  * @{
  */
/**
 * @brief Pad wake up polarity definition.
 */
typedef enum _PAD_WAKEUP_POL_VAL
{
    PAD_WAKEUP_POL_HIGH,    //!< PAD wakeup polarity is high.
    PAD_WAKEUP_POL_LOW,     //!< PAD wakeup polarity is low.
    PAD_WAKEUP_NONE         //!< PAD wakeup polarity is none.
} PAD_WAKEUP_POL_VAL;

/** End of group 87x3g_PAD_WakeUp_Polarity_Value
  * @}
  */

/** @defgroup 87x3g_PAD_WakeUp_EN PAD Wake Up Enable
  * @{
  */
/**
 * @brief Pad wake up function definition.
 */
typedef enum
{
    PAD_WAKEUP_DISABLE, //!< Disable wakeup debounce.
    PAD_WAKEUP_ENABLE //!< Enable wakeup debounce.
} PADWakeupCmd_TypeDef;

/** End of group 87x3g_PAD_WakeUp_EN
  * @}
  */

/** @defgroup 87x3g_PAD_Pull_Value PAD Pull Value
  * @{
  */
/**
 * @brief Pad resistance pull value definition.
 */
typedef enum _PAD_PULL_CONFIG_VAL
{
    PAD_WEAKLY_PULL, //!< Resistance weak pull.
    PAD_STRONG_PULL //!< Resistance strong pull.
} PAD_PULL_VAL;
/** End of group 87x3g_PAD_Pull_Value
  * @}
  */

/** @defgroup 87x3g_PAD_DRIVING_CURRENT PAD Driving Current Value
  * @{
  */
/**
 * @brief Pad driving current level definition.
 */
typedef enum _DRIVER_LEVEL
{
    PAD_DRIVING_LEVEL0, //!< The PAD driving current is set to level 0.
    PAD_DRIVING_LEVEL1, //!< The PAD driving current is set to level 1.
    PAD_DRIVING_LEVEL2, //!< The PAD driving current is set to level 2.
    PAD_DRIVING_LEVEL3, //!< The PAD driving current is set to level 3.
} T_PAD_DRIVING_LEVEL;

/** End of group 87x3g_PAD_DRIVING_CURRENT
  * @}
  */

/** @defgroup 87x3g_PAD_POWER_GROUP Pad Power Supply Voltage
  * @{
  */
/**
 * @brief Pad pin power group definition.
 */
typedef enum _PIN_POWER_GROUP
{
    INVALID_PIN_GROUP  = 0,      //!< Invalid pad power group.
    VDDIO1             = 1,      //!< Pad power group of VDDIO1 pin.
    VDDIO2             = 2,      //!< Pad power group of VDDIO2 pin.
    VDDIO3             = 3,      //!< Pad power group of VDDIO3 pin.
    VDDIO4             = 4,      //!< Pad power group of VDDIO4 pin.
} T_PIN_POWER_GROUP;

/** End of group 87x3g_PAD_POWER_GROUP
  * @}
  */

/** @defgroup 87x3g_PAD_LDO_Type PAD LDO Type
  * @{
  */
/**
 * @brief Pad LDO type definition.
 */
typedef enum _PAD_LDO_TYPE
{
    PAD_LDOAUX1, //!< PAD LDO type is AUX1.
    PAD_LDOAUX2 //!< PAD LDO type is AUX2.
} PAD_LDO_TYPE;

/** End of group 87x3g_PAD_LDO_Type
  * @}
  */

/** @defgroup 87x3g_PAD_AON_STATUS PAD AON Status
  * @{
  */
/**
 * @brief Pad AON status definition.
 */
typedef enum _PAD_AON_Status
{
    PAD_AON_OUTPUT_LOW,        //!< Pad AON output low level.
    PAD_AON_OUTPUT_HIGH,       //!< Pad AON output high level.
    PAD_AON_OUTPUT_DISABLE,    //!< Pad AON output disable.
    PAD_AON_PINMUX_ON,         //!< Pad AON pinmux on.
    PAD_AON_PIN_ERR            //!< Pad AON pin error.
} PAD_AON_Status;
/** End of group 87x3g_PAD_AON_STATUS
  * @}
  */

/** @defgroup 87x3g_WAKEUP_POLARITY PAD Wake Up Polartity
  * @{
  */
/**
 * @brief Pad wake up polarity definition.
 */
typedef enum _WAKEUP_POL
{
    POL_HIGH,    //!< PAD high-level trigger wakeup.
    POL_LOW,     //!< PAD low-level trigger wakeup.
} WAKEUP_POL;
/** End of group 87x3g_WAKEUP_POLARITY
  * @}
  */

/** @defgroup 87x3g_WAKEUP_ENABLE PAD Wake Up Enable Mode
  * @{
  */
/**
 * @brief Pad wake up mode definition.
 */
typedef enum _WAKEUP_EN_MODE
{
    ADP_MODE,    //!< Wake up by adapter.
    BAT_MODE,    //!< Wake up by battery.
    MFB_MODE,    //!< Wake up by MFB.
    USB_MODE,    //!< Wake up by USB.
} WAKEUP_EN_MODE;
/** End of group 87x3g_WAKEUP_ENABLE
  * @}
  */

/** @defgroup 87x3g_ANA_MODE PAD Analog/Digital Mode
  * @{
  */
/**
 * @brief Pad analog/digital mode for CODEC hybrid IO.
 */
typedef enum _ANA_MODE
{
    PAD_ANALOG_MODE,      //!< Config hybrid pad analog function.
    PAD_DIGITAL_MODE,     //!< Config hybrid pad digital function.
} ANA_MODE;

/** End of group 87x3g_ANA_MODE
  * @}
  */
/** @defgroup 87x3g_PAD_HS_MUX_SEL_TYPE PAD High Speed Mux Select Type
 * @{
 */
/**
 * @brief Pad high speed mux select type definition.
 */
typedef enum _PAD_HS_MUX_SEL_TYPE
{
    FROM_AON_DOMAIN, //!< PAD high speed mux select AON domain.
    FROM_CORE_DOMAIN, //!< PAD high speed mux select CORE domain.
} PAD_HS_MUX_SEL_TYPE;
/** End of group 87x3g_PAD_HS_MUX_SEL_TYPE
  * @}
  */

/** @defgroup 87x3g_PAD_HS_FUNC_SEL_TYPE PAD High Speed Function Select Type
 * @{
 */
/**
 * @brief Pad high speed function select type definition.
 */
typedef enum _PAD_HS_FUNC_SEL_TYPE
{
    HS_Func0, //!< PAD high speed select function0.
    HS_Func1, //!< PAD high speed select function1.
} PAD_HS_FUNC_SEL_TYPE;
/** End of group 87x3g_PAD_HS_FUNC_SEL_TYPE
  * @}
  */


/** End of group 87x3g_PINMUX_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/

/** @defgroup 87x3g_PINMUX_Exported_Functions PINMUX Exported Functions
  * @{
  */

/** @cond private
  * @{
  */
/**
  * @brief  According to the mode set to the pin , write the regster of AON which the pin coresponding .
  * @param  mode: mean one IO function, please refer to rtl876x_pinmux.h "Pin_Function_Number" part.
  *     @arg SHDN: use software mode.
  *     @arg PAD_OUT_EN: use pinmux mode.
        ......
        reference of bit of AON register mean in pinmux.h
  * @param  Pin_Num: pin number.
  *     This parameter is from ADC_0 to P4_1, please refer to pin_def.h "Pin_Number" part.
  * @param  value: value of the register bit ,0 or 1.
  * @retval None
  */

void Pad_TableConfig(AON_FAST_PAD_BIT_POS_TYPE pad_bit_set, uint8_t Pin_Num, uint8_t value);

#define Pad_WKTableConfig       Pad_TableConfig

/**
  * @}
  * @endcond
  */

/**
 *
 * \brief Reset all pin to default value.
 * \note  Two SWD pins will also be reset. Please use this function carefully.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pinmux_Reset();
 * }
 * \endcode
 */
void Pinmux_Reset(void);

/**
 *
 * \brief     Configure the specified pin to idle mode.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pinmux_Deinit(P2_2);
 * }
 * \endcode
 */
void Pinmux_Deinit(uint8_t Pin_Num);

/**
 *
 * \brief     Config the selected pin to its corresponding IO function.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] Pin_Func: IO function of pin, can be a value of \ref x3g_Pin_Function_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_uart_init(void)
 * {
 *     Pad_Config(P2_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE,
               PAD_OUT_HIGH);
 *     Pad_Config(P2_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE,
               PAD_OUT_HIGH);

 *     Pinmux_Config(P2_0, UART0_TX);
 *     Pinmux_Config(P2_1, UART0_RX);
 * }
 * \endcode
 */
void Pinmux_Config(uint8_t Pin_Num, uint8_t Pin_Func);

/**
 *
 * \brief     Configure the relevant operation mode,
 *            peripheral circuit and output level value in software mode of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] AON_PAD_Mode: Use software mode or PINMUX mode. Please refer to \ref x3g_PAD_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SW_MODE: Use software mode.
 *            - PAD_PINMUX_MODE: Use PINMUX mode.
 * \param[in] AON_PAD_PwrOn: Config power of pad. Please refer to \ref x3g_PAD_Power_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SHUTDOWN: Shutdown power of pad.
 *            - PAD_IS_PWRON: Enable power of pad.
 * \param[in] AON_PAD_Pull: Config pad pull mode. Please refer to \ref x3g_PAD_Pull_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_PULL_NONE: No pull.
 *            - PAD_PULL_UP: Pull this pin up.
 *            - PAD_PULL_DOWN: Pull this pin down.
 * \param[in] AON_PAD_E: Config pad output function, which only valid when PAD_SW_MODE. Please refer to \ref x3g_PAD_Output_Config.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_DISABLE: Disable pin output.
 *            - PAD_OUT_ENABLE: Enable pad output.
 * \param[in] AON_PAD_O: Config pin output level, which only valid when PAD_SW_MODE and output mode. Please refer to \ref x3g_PAD_Output_Value.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_LOW: Pad output low.
 *            - PAD_OUT_HIGH: Pad output high.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_adc_init(void)
 * {
 *     Pad_Config(P2_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_HIGH);
 *     Pad_Config(P2_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_HIGH);
 * }
 * \endcode
 */
void Pad_Config(uint8_t Pin_Num,
                PAD_Mode AON_PAD_Mode,
                PAD_PWR_Mode AON_PAD_PwrOn,
                PAD_Pull_Mode AON_PAD_Pull,
                PAD_OUTPUT_ENABLE_Mode AON_PAD_E,
                PAD_OUTPUT_VAL AON_PAD_O);

/**
 *
 * \brief     Configure the relevant operation mode, peripheral circuit, pull resistor value and
 *            output level value in software mode of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] AON_PAD_Mode: Use software mode or PINMUX mode. Please refer to \ref x3g_PAD_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SW_MODE: Use software mode.
 *            - PAD_PINMUX_MODE: Use PINMUX mode.
 * \param[in] AON_PAD_PwrOn: Config power of pad. Please refer to \ref x3g_PAD_Power_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SHUTDOWN: Shutdown power of pad.
 *            - PAD_IS_PWRON: Enable power of pad.
 * \param[in] AON_PAD_Pull: Config pad pull mode. Please refer to \ref x3g_PAD_Pull_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_PULL_NONE: No pull.
 *            - PAD_PULL_UP: Pull this pin up.
 *            - PAD_PULL_DOWN: Pull this pin down.
 * \param[in] AON_PAD_E: Config pad output function, which only valid when PAD_SW_MODE. Please refer to \ref x3g_PAD_Output_Config.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_DISABLE: Disable pin output.
 *            - PAD_OUT_ENABLE: Enable pad output.
 * \param[in] AON_PAD_O: Config pin output level, which only valid when PAD_SW_MODE and output mode. Please refer to \ref x3g_PAD_Output_Value.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_LOW: Pad output low.
 *            - PAD_OUT_HIGH: Pad output high.
 * \param[in] AON_PAD_P: Config resistor value. Please refer to \ref x3g_PAD_Pull_Value.
 *            This parameter can be one of the following values:
 *            - PAD_STRONG_PULL: Pad pull 150k resistance.
 *            - PAD_WEAKLY_PULL: Pad pull 15k resistance.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_adc_init(void)
 * {
 *     Pad_ConfigExt(P2_0, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_WEAKLY_PULL);
 *     Pad_ConfigExt(P2_1, PAD_PINMUX_MODE, PAD_IS_PWRON, PAD_PULL_UP, PAD_OUT_DISABLE, PAD_OUT_LOW, PAD_STRONG_PULL);
 * }
 * \endcode
 */
void Pad_ConfigExt(uint8_t Pin_Num,
                   PAD_Mode AON_PAD_Mode,
                   PAD_PWR_Mode AON_PAD_PwrOn,
                   PAD_Pull_Mode AON_PAD_Pull,
                   PAD_OUTPUT_ENABLE_Mode AON_PAD_E,
                   PAD_OUTPUT_VAL AON_PAD_O,
                   PAD_PULL_VAL AON_PAD_P);

/**
 *
 * \brief   Set all pins to the default state.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_AllConfigDefault();
 * }
 * \endcode
 */
void Pad_AllConfigDefault(void);

/**
 *
 * \brief   Enable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] Polarity: Polarity to wake up. Please refer to \ref x3g_PAD_WakeUp_Polarity_Value.
 *            This parameter can be the following:
 *            - PAD_WAKEUP_POL_HIGH: Use high level wakeup.
 *            - PAD_WAKEUP_POL_LOW: Use low level wakeup.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //IO enter DLPS call back function.
 * void io_uart_dlps_enter(void)
 * {
 *     // Switch pad to software mode
 *     Pad_ControlSelectValue(P2_0, PAD_SW_MODE);//TX pin
 *     Pad_ControlSelectValue(P2_1, PAD_SW_MODE);//RX pin
 *
 *     System_WakeUpPinEnable(P2_1, PAD_WAKEUP_POL_LOW);
 * }
 * \endcode
 */
void System_WakeUpPinEnable(uint8_t Pin_Num, uint8_t Polarity);

/**
 *
 * \brief   Disable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define UART_RX_PIN   P4_1
 *
 * //System interrupt handler function, for wakeup pin.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(UART_RX_PIN);
 *         System_WakeUpPinDisable(UART_RX_PIN);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
void System_WakeUpPinDisable(uint8_t Pin_Num);

/**
 *
 * \brief   Configure the adpater wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState: Enable or disable adpater wake up.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable adpater wake up system at specified polarity.
 *            - DISABLE: Disable adpater wake up system.
 * \param[in] pol: Polarity to wake up. Please refer to \ref x3g_WAKEUP_POLARITY.
 *            This parameter can be the following:
 *            - POL_HIGH: Use high level wakeup.
 *            - POL_LOW: Use low level wakeup.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is wake_up_power_off
 *     System_SetAdpWakeUpFunction(ENABLE, POL_HIGH);
 * }
 * \endcode
 */
void System_SetAdpWakeUpFunction(FunctionalState NewState, WAKEUP_POL pol);

/**
 *
 * \brief   Configure the MFB wake-up system functions in power off(shipping) mode.
 *
 * \param[in] NewState: Enable or disable MFB wake up.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable MFB wake up system.
 *            - DISABLE: Disable MFB wake up system.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //io_test_set_mfb_mode is POWER_OFF_WAKEUP_TEST
 * void mfb_wake_up_enable(void)
 * {
 *     System_SetMFBWakeUpFunction(ENABLE);
 * }
 * \endcode
 */
void System_SetMFBWakeUpFunction(FunctionalState NewState);

/**
 *
 * \brief   Disable the function of the wake-up system interrupt of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //System interrupt handler function.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(P2_5) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(P2_5);
 *         System_WakeUpInterruptDisable(P2_5);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
void System_WakeUpInterruptDisable(uint8_t Pin_Num);

/**
 *
 * \brief   Enable the function of the wake-up system interrupt of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //IO enter DLPS call back function.
 * void io_uart_dlps_enter(void)
 * {
 *     // Switch pad to software mode
 *     Pad_ControlSelectValue(P2_0, PAD_SW_MODE);//TX pin
 *     Pad_ControlSelectValue(P2_1, PAD_SW_MODE);//RX pin
 *
 *     System_WakeUpInterruptEnable(P2_1);
 * }
 * \endcode
 */
void System_WakeUpInterruptEnable(uint8_t Pin_Num);

/**
 *
 * \brief   Check wake up pin interrupt status.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return   Pin interrupt status.
 * \retval 1: Pin wake up system.
 * \retval 0: The pin does not wake up the system.
 *
 * <b>Example usage</b>
 * \code{.c}
 * #define UART_RX_PIN                P4_1
 *
 * //System interrupt handler function.
 * void System_Handler(void)
 * {
 *     if (System_WakeUpInterruptValue(UART_RX_PIN) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(UART_RX_PIN);
 *         System_WakeUpPinDisable(UART_RX_PIN);
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
uint8_t System_WakeUpInterruptValue(uint8_t Pin_Num);

/**
 *
 * \brief   Config pad output function.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: This parameter sets whether the pin outputs the level in software mode. Please refer to \ref x3g_PAD_Output_Config.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_DISABLE: Disable pin output.
 *            - PAD_OUT_ENABLE: Enable pin output.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_OutputEnableValue(P2_0, PAD_OUT_ENABLE);
 * }
 * \endcode
 */
#define Pad_OutputEnableValue(Pin_Num, value) Pad_TableConfig(AON_PAD_E, Pin_Num, value)

/**
 *
 * \brief   Config pad pull enable or not.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Enable or disable pad pull-up / pull-down resistance function.
 *            This parameter can be one of the following values:
 *            - DISABLE: Disable pad pull-up / pull-down function.
 *            - ENABLE: Enable  pad pull-up / pull-down function.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_PullEnableValue(P2_0, ENABLE);
 * }
 * \endcode
 */
#define Pad_PullEnableValue(Pin_Num, value) Pad_TableConfig(PAD_PU_EN, Pin_Num, value)

/**
 *
 * \brief     Enable or disable the pull direction for the pad.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Enable or disable the pull direction for the pad.
 *            This parameter can be one of the following values:
 *            - 0: The pad pull direction is disabled.
 *            - 1: The pad pull direction is enabled.
 * \param[in] Pull_Direction_value: Config pad pull mode. Please refer to \ref x3g_PAD_Pull_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_PULL_NONE: No pull.
 *            - PAD_PULL_UP: Pull this pin up.
 *            - PAD_PULL_DOWN: Pull this pin down.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void driver_gpio_init(void)
 * {
 *     Pad_SetPullMode(pin_index, 1, PAD_PULL_DOWN);
 * }
 * \endcode
 */
void Pad_SetPullMode(uint8_t Pin_Num, PAD_Pull_Mode pull_mode);
#define Pad_PullEnableValue_Dir(Pin_Num, value, pull_direction)        Pad_SetPullMode(Pin_Num, pull_direction)

/**
 *
 * \brief   Config pad pull up or down.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value : This parameter sets whether the pin pull-up or pull-down.
 *            This parameter can be one of the following values:
 *            - 0: Config pad pull-down function.
 *            - 1: Config pad pull-up function.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_PullUpOrDownValue(P2_0, 1);
 * }
 * \endcode
 */
void Pad_PullUpOrDownValue(uint8_t Pin_Num, uint8_t value);

/**
 *
 * \brief   Config the pad control selected value.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Use software mode or PINMUX mode. Please refer to \ref x3g_PAD_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SW_MODE: Use software mode, aon control.
 *            - PAD_PINMUX_MODE: Use PINMUX mode, core control.
 *
 * <b>Example usage</b>
 * \code{.c}
 * //IO enter DLPS call back function.
 * void io_uart_dlps_enter(void)
 * {
 *     // Switch pad to software mode
 *     Pad_ControlSelectValue(P2_0, PAD_SW_MODE);//TX pin
 *     Pad_ControlSelectValue(P2_1, PAD_SW_MODE);//RX pin
 *
 *     System_WakeUpPinEnable(P2_1, PAD_WAKEUP_POL_LOW);
 * }
 * \endcode
 */
void Pad_ControlSelectValue(uint8_t Pin_Num, uint8_t value);

/**
 *
 * \brief     Configure the pad output level when pad set to SW mode.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Config pin output level. Please refer to \ref x3g_PAD_Output_Value.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_LOW: Pad output low.
 *            - PAD_OUT_HIGH: Pad output high.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_OutputControlValue(P2_0, PAD_OUT_HIGH);
 * }
 * \endcode
 */
#define Pad_OutputControlValue(Pin_Num, value) Pad_TableConfig(AON_PAD_O, Pin_Num, value)


/**
 *
 * \brief     Enable the function of the wake-up system of the specified pin.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value:  Enable or disable wake-up system function.
 *            - ENABLE: Enable pad to wake up system from DLPS.
 *            - DISABLE: Disable pad to wake up system from DLPS.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void board_xxx_init(void)
 * {
 *     Pad_WakeupEnableValue(P2_0, ENABLE);
 * }
 * \endcode
 */
#define Pad_WakeupEnableValue(Pin_Num, value) Pad_WKTableConfig(PAD_WKEN, Pin_Num, value)


/**
 *
 * \brief     Config the pad wake up polarity.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] Polarity: Polarity of wake-up system. Please refer to \ref x3g_PAD_WakeUp_Polarity_Value.
 *            This parameter can be the following:
 *            - PAD_WAKEUP_POL_LOW: Use low level wakeup.
 *            - PAD_WAKEUP_POL_HIGH: Use high level wakeup.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_WakeupPolarityValue(P2_0, PAD_WAKEUP_POL_LOW);
 * }
 * \endcode
 */
#define Pad_WakeupPolarityValue(Pin_Num, value) Pad_WKTableConfig(PAD_WKPOL, Pin_Num, value)

/**
 *
 * \brief   Config pad wake up interrupt.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Enable or disable pad wake up interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable pad wake up to trigger system interrupt.
 *            - DISABLE: Disable pad wake up to trigger system interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_WakeupInterruptEnable(P2_0, ENABLE);
 * }
 * \endcode
 */
void Pad_WakeupInterruptEnable(uint8_t Pin_Num, uint8_t value);

/**
 *
 * \brief   Check pad wake up pin interrupt status.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return   Pin interrupt status.
 * \retval 1: Pin wake up system.
 * \retval 0: The pin does not wake up the system.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void System_Handler(void)
 * {
 *     if (Pad_WakeupInterruptValue(P4_1) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(P4_1);
 *     }
 *     NVIC_DisableIRQ(System_IRQn);
 *     NVIC_ClearPendingIRQ(System_IRQn);
 * }
 * \endcode
 */
FlagStatus Pad_WakeupInterruptValue(uint8_t Pin_Num);

/**
 *
 * \brief   Clear pad wake up pin interrupt pending bit.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void System_Handler(void)
 * {
 *     if (Pad_WakeupInterruptValue(P4_1) == SET)
 *     {
 *         Pad_ClearWakeupINTPendingBit(P4_1);
 *     }
 *     NVIC_DisableIRQ(System_IRQn);
 *     NVIC_ClearPendingIRQ(System_IRQn);
 * }
 * \endcode
 */
void Pad_ClearWakeupINTPendingBit(uint8_t Pin_Num);

/**
 *
 * \brief   Clear all wake up pin interrupt pending bit.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void dlps_io_enter_cb(void)
 * {
 *     io_dlps_callback(&io_dlps_enter_q);
 *
 *     //clear aon fast 0x12E ~ 0x131, 0x133 (PAD wake up INT status), write one clear
 *     Pad_ClearAllWakeupINT();
 *
 *     if (power_mode_get() == POWER_DLPS_MODE)
 *     {
 *         dlps_io_store();
 *     }
 * }
 * \endcode
 */
void Pad_ClearAllWakeupINT(void);

/**
 *
 * \brief   Config pin power mode.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: This parameter sets the power supply mode of the pin,
 *                   and the value is enumeration PAD_PWR_Mode One of the values. Please refer to \ref x3g_PAD_Power_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SHUTDOWN: Power off.
 *            - PAD_IS_PWRON: Power on.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_PowerOrShutDownValue(P2_0, PAD_IS_PWRON);
 * }
 * \endcode
 */
#define Pad_PowerOrShutDownValue(Pin_Num, value) Pad_TableConfig(PAD_SHDN, Pin_Num, value)

/**
 *
 * \brief     Configure the strength of pull-up/pull-down resistance.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: This parameter sets the strength of pull-up/pull-down resistance. Please refer to \ref x3g_PAD_Pull_Value.
 *            This parameter can be one of the following values:
 *            - PAD_STRONG_PULL: Pad pull 150k resistance.
 *            - PAD_WEAKLY_PULL: Pad pull 15k resistance.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     Pad_PullConfigValue(P2_0, PAD_150K_PULL);
 * }
 * \endcode
 */
#define Pad_PullConfigValue(Pin_Num, value) Pad_TableConfig(PAD_PUPDC, Pin_Num, value)

/**
 *
 * \brief   Config driving current value.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] e2_value: Set driving current value.
 *            This parameter can be one of the following values:
 *            - 0: Set driving current value to low level.
 *            - 1: Set driving current value to high level.
 * \param[in] e3_value: Set driving current value.
 *            This parameter can be one of the following values:
 *            - 0: Set driving current value to low level.
 *            - 1: Set driving current value to high level.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_DrivingCurrentControl(P2_0, 1, 1);
 * }
 * \endcode
 */
bool Pad_DrivingCurrentControl(uint8_t Pin_Num, bool e2_value, bool e3_value);

/**
 *
 * \brief   Config Pad Function.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] value: Config value \ref x3g_PAD_Function_Config.
 *            This parameter can be one of the following values:
 *            - AON_GPIO: Default GPIO function.
 *            - LED0: SLEEP LED channel 0.
 *            - LED1: SLEEP LED channel 1.
 *            - LED2: SLEEP LED channel 2.
 *            - CLK_REQ: Clock request, internal debug function.
 *            - XTAL_CLK: XTAL clock.
 *            - LP_PWM: LP PWM function.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_FunctionConfig(P2_0, AON_GPIO);
 * }
 * \endcode
 */
void Pad_FunctionConfig(uint8_t Pin_Num, PAD_FUNCTION_CONFIG_VAL value);


/**
 *
 * \brief   Get pad current output/input setting.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return The pad current output/input setting. Please refer to \ref x3g_PAD_AON_STATUS.
 * \retval PAD_AON_OUTPUT_LOW: Pad AON output low level.
 * \retval PAD_AON_OUTPUT_HIGH: Pad AON output high level.
 * \retval PAD_AON_OUTPUT_DISABLE: Pad AON output disable.
 * \retval PAD_AON_PINMUX_ON: Pad AON PINMUX on.
 * \retval PAD_AON_PIN_ERR: Pad AON pin error.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     if (Pad_GetOutputCtrl(P2_1) == PAD_AON_OUTPUT_LOW)
 *     {
 *         //Add user code here.
 *     }
 * }
 * \endcode
 */
uint8_t Pad_GetOutputCtrl(uint8_t Pin_Num);

/**
 *
 * \brief   Config the system wakeup mode.
 *
 * \param[in] mode: The mode of set, this parameter can refer to \ref x3g_WAKEUP_ENABLE.
 *            This parameter can be one of the following values:
 *            - ADP_MODE: Wake up by adapter.
 *            - BAT_MODE: Wake up by battery.
 *            - MFB_MODE: Wake up by MFB.
 *            - USB_MODE: Wake up by USB.
 * \param[in] pol: The polarity to wake up. Please refer to \ref x3g_WAKEUP_POLARITY.
 *            This parameter can be the following:
 *            - POL_HIGH: Use high level wakeup.
 *            - POL_LOW: Use low level wakeup.
 * \param[in] NewState: Enable or disable wake up.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the system wake up at specified polarity.
 *            - DISABLE: Disable the system wake up at specified polarity.
 *
 * \return     Config the system wakeup mode fail or success.
 * \retval 0   Config success.
 * \retval 1   Config fail due to wrong mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void adapter_wake_up_enable(void)
 * {
 *     //adapter mode is WAKE_UP_GENERAL
 *     Pad_WakeUpCmd(ADP_MODE, POL_HIGH, ENABLE);
 * }
 * \endcode
 */
uint8_t Pad_WakeUpCmd(WAKEUP_EN_MODE mode, WAKEUP_POL pol, FunctionalState NewState);

/**
 *
 * \brief   Config hybrid pad analog/digital functions.
 *
 * \param[in] pin: The pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] mode: Please refer to \ref x3g_ANA_MODE.
 *            - This parameter can be: PAD_ANALOG_MODE/PAD_DIGITAL_MODE.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_AnalogMode(P2_1, PAD_ANALOG_MODE);
 * }
 * \endcode
 */
void Pad_AnalogMode(uint8_t pin, ANA_MODE mode);

/**
 *
 * \brief   Config PAD high speed mux select.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] Pad_Hs_Mux: This parameter can be: FROM_AON_DOMAIN/FROM_HS_DOMAIN, please refer to \ref x3g_PAD_HS_MUX_SEL_TYPE.
 *
 * \return    1 means Pin_Num not correct.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_HighSpeedMuxSel(P6_0, FROM_CORE_DOMAIN);
 * }
 * \endcode
 */
bool Pad_HighSpeedMuxSel(uint8_t Pin_Num, PAD_HS_MUX_SEL_TYPE Pad_Hs_Mux);

/**
 *
 * \brief   PAD high speed mode function select.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] Pad_HS_Func_Sel: Pad high speed function select. This parameter can be: HS_Func0/HS_Func1, please refer to \ref x3g_PAD_HS_FUNC_SEL_TYPE.
 *           P1_2~P1_5: 0 SPI2, 1 SDH1;
 *           P3_2~P3_3: 0 GMAC, 1 SDH1;
 *           P4_2~P4_5: 0 LCDC, 1 SPI1;
 *           P5_0~P5_5: 0 SDH0, 1 GMAC;
 *           P6_0~P6_2: 0 LCDC, 1 SDH0;
 *           P8_0~P8_3: 0 LCDC, 1 SPI0;
 *           P9_0~P9_5: 0 LCDC, 1 SPI2.
 * \return    1 means Pin_Num not correct.
 * @retval true: Set high speed function select success.
 * @retval false: Set high speed function select failed due to invalid pinmux.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_HighSpeedFuncSel(P6_0, HS_Func0);
 * }
 * \endcode
 */
bool Pad_HighSpeedFuncSel(uint8_t Pin_Num, PAD_HS_FUNC_SEL_TYPE Pad_HS_Func_Sel);

/**
 *
 * \brief   Config hybrid pad analog/digital functions.
 *
 * \param[in] pin: The pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] mode: Please refer to \ref x3g_ANA_MODE.
 *            - This parameter can be: PAD_ANALOG_MODE/PAD_DIGITAL_MODE.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_AnalogMode(P2_1, PAD_ANALOG_MODE);
 * }
 * \endcode
 */
void Pad_AnalogMode(uint8_t Pin_Num, ANA_MODE mode);

/**
 * \brief  Get debounce wake up status.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return Debounce wake up status.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     uint8_t WakeupDebounceStatus = System_WakeupDebounceStatus(P0_0);
 * }
 * \endcode
 */
uint8_t System_WakeupDebounceStatus(uint8_t Pin_Num);

/**
 * \brief  Clear debounce wake up status. Call this API will clear the debunce wakeup status bit.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void dlps_store(void)
 * {
 *     System_WakeupDebounceClear(P0_0);
 * }
 * \endcode
 */
void System_WakeupDebounceClear(uint8_t Pin_Num);

/**
 * \brief   Enable a pin with an independent wake-up debounce time.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return The result of the setting.
 * \retval true: Enable success.
 * \retval false:Enable failed due to invalid pin num or no free debounce group.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceEnable(P0_0);
 * }
 * \endcode
 */
bool System_WakeUpDebounceEnable(uint8_t Pin_Num);

/**
 * \brief   Disable a pin with an independent wake-up debounce time.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return The result of the setting.
 * \retval true: Disable success.
 * \retval false:Disable failed due to invalid pin num or this pin does not have an independent wake-up debounce time.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceDisable(P0_0);
 * }
 * \endcode
 */
bool System_WakeUpDebounceDisable(uint8_t Pin_Num);

/**
 * \brief   Configure independent wake-up debounce time.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \param[in] time_ms: Debounce time.
 *
 * \return The result of the setting.
 * \retval true: Set debounce time success.
 * \retval false:Set debounce time failed due to invalid pin num or this pin does not have an independent wake-up debounce time.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_WakeUpDebounceTime(P0_0, 10);
 * }
 * \endcode
 */
bool System_WakeUpDebounceTime(uint8_t Pin_Num, uint8_t time_ms);

/**
 * \brief  Enable or disable independent wake-up debounce function.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \param[in] Status: wake-up system debounce enable or disable \ref x3g_PAD_WakeUp_EN.
 *            - PAD_WAKEUP_DISABLE: Disable wakeup debounce.
 *            - PAD_WAKEUP_ENABLE: Enable wakeup debounce.
 *
 * \return The result of the setting.
 * \retval true: Config wake up debounce success.
 * \retval false:Set Config wake up debounce failed due to invalid pin num or this pin does not have an independent wake-up debounce time.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *void pad_wake_up_test(uint8_t Pin_Num, uint8_t Polarity)
 *{
 *    System_WakeUpDebounceEnable(Pin_Num);
 *    System_WakeUpDebounceTime(Pin_Num, 10);
 *    System_WakeUpDebounceCmd(Pin_Num, PAD_WAKEUP_ENABLE);
 *    System_WakeUpPinEnable(Pin_Num, PAD_WAKEUP_POL_LOW);
 *}
 * \endcode
 */
bool System_WakeUpDebounceCmd(uint8_t Pin_Num, PADWakeupCmd_TypeDef Status);

/**
 * \brief   Enable a pin to use a shared wake-up debounce time.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return The result of the setting.
 * \retval true: Enable success.
 * \retval false:Enable failed due to invalid pin num.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_GroupWakeUpDebounceEnable(P0_0);
 * }
 * \endcode
 */
bool System_GroupWakeUpDebounceEnable(uint8_t Pin_Num);

/**
 * \brief   Disable a pin with a shared wake-up debounce time.
 *
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return The result of the setting.
 * \retval true: Disable success.
 * \retval false:Disable failed due to invalid pin num.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_GroupWakeUpDebounceDisable(P0_0);
 * }
 * \endcode
 */
bool System_GroupWakeUpDebounceDisable(uint8_t Pin_Num);

/**
 * \brief   Configure shared wake-up debounce time.
 *
 * \param[in] time_ms: Debounce time.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void board_xxx_init(void)
 * {
 *     System_GroupWakeUpDebounceTime(10);
 * }
 * \endcode
 */
void System_GroupWakeUpDebounceTime(uint8_t time_ms);

/**
 * \brief  Enable or disable shared wake-up debounce function.
 *
 * \param  Status: wake-up system debounce enable or disable \ref x3g_PAD_WakeUp_EN.
 *         - PAD_WAKEUP_DISABLE: Disable wakeup debounce.
 *         - PAD_WAKEUP_ENABLE: Enable wakeup debounce.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *void pad_wake_up_test(uint8_t Pin_Num, uint8_t Polarity)
 *{
 *    System_GroupWakeUpDebounceEnable(Pin_Num);
 *    System_GroupWakeUpDebounceTime(10);
 *    System_GroupWakeUpDebounceCmd(PAD_WAKEUP_ENABLE);
 *    System_WakeUpPinEnable(Pin_Num, PAD_WAKEUP_POL_LOW);
 *}
 * \endcode
 */
void System_GroupWakeUpDebounceCmd(PADWakeupCmd_TypeDef Status);

/**
 * \brief  Disable pad wake up debounce function.
 * \param[in] Pin_Num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void set_pad_wake_up(void)
 * {
 *   Pad_WakeUpDebouceDisable(P0_0);
 *  }
 * \endcode
 */
void Pad_WakeUpDebouceDisable(uint8_t Pin_Num);

/**
 * \brief   Configure the driving current of the pin.
 *
 * \param[in] pin: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] driver_level: Refer to the \ref x3g_PAD_DRIVING_CURRENT.
 *            This parameter can be: PAD_DRIVING_LEVEL0, PAD_DRIVING_LEVEL1, PAD_DRIVING_LEVEL2, PAD_DRIVING_LEVEL3.
 *
 * \return   The driving current of the pin set succeeded or failed.
 * \retval true    Driving current is set successfully.
 * \retval false   Driving current set fail. The failure reasons could be one of the following one:
 *                 Invalid pin number or driving current setting is not supported for the setting pin.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_SetPinDrivingCurrent(P2_1, PAD_DRIVING_LEVEL1);
 * }
 * \endcode
 */
bool Pad_SetPinDrivingCurrent(uint8_t pin, T_PAD_DRIVING_LEVEL driver_level);

/**
 * \brief   Get the pin name in string.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return   The pin name or null. When null is returned, it indicates that the pin index is invalid.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pad_GetPinName(P2_1);
 * }
 * \endcode
 */
const char *Pad_GetPinName(uint8_t pin_num);

/**
 *
 * \brief   Get the pin mux config for pin.
 *
 * \xrefitem Added_API_2_14_0_0 "Added Since 2.14.0.0" "Added API"
 *
 * \param[in] Pin_Num: The pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return   The pinmux function or 0xFF. When 0xFF is returned, it indicates that the pin index is invalid.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *     Pinmux_GetConfig(P2_1);
 * }
 * \endcode
 */
uint8_t Pinmux_GetConfig(uint8_t Pin_Num);

/**
 * \brief   Get the pad config.
 *
 * \param[in] pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 * \param[in] mode: Use software mode or PINMUX mode. Please refer to \ref x3g_PAD_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SW_MODE: Use software mode.
 *            - PAD_PINMUX_MODE: Use PINMUX mode.
 * \param[in] pwr_mode: Config power of pad. Please refer to \ref x3g_PAD_Power_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_SHUTDOWN: Shutdown power of pad.
 *            - PAD_IS_PWRON: Enable power of pad.
 * \param[in] pullup_config: Config pad pull mode. Please refer to \ref x3g_PAD_Pull_Mode.
 *            This parameter can be one of the following values:
 *            - PAD_PULL_NONE: No pull.
 *            - PAD_PULL_UP: Pull this pin up.
 *            - PAD_PULL_DOWN: Pull this pin down.
 * \param[in] output_en: Config pad output function, which only valid when PAD_SW_MODE. Please refer to \ref x3g_PAD_Output_Config.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_DISABLE: Disable pin output.
 *            - PAD_OUT_ENABLE: Enable pad output.
 * \param[in] output_val: Config pin output level, which only valid when PAD_SW_MODE and output mode. Please refer to \ref x3g_PAD_Output_Value.
 *            This parameter can be one of the following values:
 *            - PAD_OUT_LOW: Pad output low.
 *            - PAD_OUT_HIGH: Pad output high.
 *
 * @return   The result of get pad config is success or fail.
 * @retval 0   The pad config is get success.
 * @retval -1  The pad config is get failure.
 *
 * <b>Example usage</b>
 * \code{.c}
 * void pad_demo(void)
 * {
 *    int32_t  get_result;
 *    get_result = Pad_GetConfig(P2_0, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_NONE, PAD_OUT_DISABLE, PAD_OUT_LOW);
 * }
 * \endcode
 */
int32_t Pad_GetConfig(uint8_t pin_num,
                      PAD_Mode *mode,
                      PAD_PWR_Mode *pwr_mode,
                      PAD_Pull_Mode *pullup_config,
                      PAD_OUTPUT_ENABLE_Mode *output_en,
                      PAD_OUTPUT_VAL *output_val);

#ifdef __cplusplus
}
#endif

#endif /* _RTL876X_PINMUX_H_ */

/** @} */ /* End of group 87x3g_PINMUX_Exported_Functions */
/** @} */ /* End of group 87x3g_PINMUX */


