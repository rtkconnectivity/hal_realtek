#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "stdbool.h"
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#include "cmsis_armclang.h"   // replace with cmsis_compiler.h ?
#endif

/** @defgroup VECTOR_TABLE  Vector table
  * @brief
  * @{
  */

/** @defgroup VECTOR_TABLE_Exported_Types Vector table Exported Types
  * @brief
  * @{
  */

typedef void (*IRQ_Fun)(void);       /**< ISR Handler Prototype */

typedef enum
{
    InitialSP_VECTORn = 0,
    Reset_VECTORn,
    NMI_VECTORn,
    HardFault_VECTORn,
    MemMang_VECTORn,
    BusFault_VECTORn,
    UsageFault_VECTORn,
    RSVD0_VECTORn,
    RSVD1_VECTORn,
    RSVD2_VECTORn,
    RSVD3_VECTORn,
    SVC_VECTORn,
    DebugMonitor_VECTORn,
    RSVD4_VECTORn,
    PendSV_VECTORn,
    SysTick_VECTORn,

    System_VECTORn = 16,
    WDT_VECTORn,
    RXI300_VECTORn,
    RXI300_SEC_VECTORn,
    Zigbee_VECTORn,
    BTMAC_VECTORn,
    Peripheral_VECTORn,
    RSVD5_VECTORn,
    RTC_VECTORn,
    GPIO_A0_VECTORn,
    GPIO_A1_VECTORn,
    GPIO_A_2_7_VECTORn,
    GPIO_A_8_15_VECTORn,
    GPIO_A_16_23_VECTORn,
    GPIO_A_24_31_VECTORn,
    GPIO_B_0_7_VECTORn,
    GPIO_B_8_15_VECTORn,
    GPIO_B_16_23_VECTORn,
    GPIO_B_24_31_VECTORn,
    GDMA0_Channel0_VECTORn,
    GDMA0_Channel1_VECTORn,
    GDMA0_Channel2_VECTORn,
    GDMA0_Channel3_VECTORn,
    GDMA0_Channel4_VECTORn,
    GDMA0_Channel5_VECTORn,
    GDMA0_Channel6_VECTORn,
    GDMA0_Channel7_VECTORn,
    GDMA0_Channel8_VECTORn,
    GDMA0_Channel9_VECTORn,
    PPE_VECTORn,
    I2C0_VECTORn,
    I2C1_VECTORn,
    I2C2_VECTORn,
    I2C3_VECTORn,
    UART0_VECTORn,
    UART1_VECTORn,
    UART2_VECTORn,
    UART3_VECTORn,
    UART4_VECTORn,
    UART5_VECTORn,
    SPI_3Wire_VECTORn,
    SPI0_VECTORn,
    SPI1_VECTORn,
    SPI_Slave_VECTORn,
    Timer0_VECTORn,
    Timer1_VECTORn,
    Timer2_VECTORn,
    Timer3_VECTORn,
    Timer4_VECTORn,
    Timer5_VECTORn,
    Timer6_VECTORn,
    Timer7_VECTORn,
    Enhanced_Timer0_VECTORn,
    Enhanced_Timer1_VECTORn,
    Enhanced_Timer2_VECTORn,
    Enhanced_Timer3_VECTORn,
    ADC_24bit_VECTORn,
    SAR_ADC_VECTORn,
    KEYSCAN_VECTORn,
    AON_QDEC_VECTORn,
    IR_VECTORn,
    SDIO_VECTORn,
    ISO7816_VECTORn,
    Display_VECTORn,
    SPORT0_RX_VECTORn,
    SPORT0_TX_VECTORn,
    SPORT1_RX_VECTORn,
    SPORT1_TX_VECTORn,
    SHA256_VECTORn,
    Public_Key_Engine_VECTORn,
    Flash_SEC_VECTORn,
    SegCom_CTL_VECTORn,
    CAN_VECTORn,
    ETH_VECTORn,
    RTZIP_VECTORn,
    Slave_Port_Monitor_VECTORn,
    PTA_Mailbox_VECTORn,
    USB_VECTORn,
    USB_SUSPEND_N_VECTORn,
    USB_Endp_Muti_Proc_VECTORn,
    USB_IN_EP_0_VECTORn,
    USB_IN_EP_1_VECTORn,
    USB_IN_EP_2_VECTORn,
    USB_IN_EP_3_VECTORn,
    USB_IN_EP_4_VECTORn,
    USB_IN_EP_5_VECTORn,
    USB_OUT_EP_0_VECTORn,
    USB_OUT_EP_1_VECTORn,
    USB_OUT_EP_2_VECTORn,
    USB_OUT_EP_3_VECTORn,
    USB_OUT_EP_4_VECTORn,
    USB_OUT_EP_5_VECTORn,
    USB_Sof_VECTORn,
    TMETER_VECTORn,
    PF_RTC_VECTORn,
    BTMAC_WRAP_AROUND_VECTORn,

    /* second level interrupt (BTMAC_IRQn), not directly connect to NVIC */
    Timer_A0_A1_VECTORn,
    BT_Bluewiz_VECTORn,
    RSVD6_VECTORn,
    BT_BZ_DMA_VECTORn,
    Proprietary_protocol_VECTORn,
    RSVD7_VECTORn,

    /* second level interrupt (Peripheral_VECTORn) */
    SPIC0_VECTORn,
    SPIC1_VECTORn,
    SPIC2_VECTORn,
    TRNG_VECTORn,
    LPCOMP_VECTORn,
    SPI_PHY1_VECTORn,
    RSVD8_VECTORn,

    /* gpio sub interrupt */
    GPIOA2_VECTORn,
    GPIOA3_VECTORn,
    GPIOA4_VECTORn,
    GPIOA5_VECTORn,
    GPIOA6_VECTORn,
    GPIOA7_VECTORn,
    GPIOA8_VECTORn,
    GPIOA9_VECTORn,
    GPIOA10_VECTORn,
    GPIOA11_VECTORn,
    GPIOA12_VECTORn,
    GPIOA13_VECTORn,
    GPIOA14_VECTORn,
    GPIOA15_VECTORn,
    GPIOA16_VECTORn,
    GPIOA17_VECTORn,
    GPIOA18_VECTORn,
    GPIOA19_VECTORn,
    GPIOA20_VECTORn,
    GPIOA21_VECTORn,
    GPIOA22_VECTORn,
    GPIOA23_VECTORn,
    GPIOA24_VECTORn,
    GPIOA25_VECTORn,
    GPIOA26_VECTORn,
    GPIOA27_VECTORn,
    GPIOA28_VECTORn,
    GPIOA29_VECTORn,
    GPIOA30_VECTORn,
    GPIOA31_VECTORn,

    GPIOB0_VECTORn,
    GPIOB1_VECTORn,
    GPIOB2_VECTORn,
    GPIOB3_VECTORn,
    GPIOB4_VECTORn,
    GPIOB5_VECTORn,
    GPIOB6_VECTORn,
    GPIOB7_VECTORn,
    GPIOB8_VECTORn,
    GPIOB9_VECTORn,
    GPIOB10_VECTORn,
    GPIOB11_VECTORn,
    GPIOB12_VECTORn,
    GPIOB13_VECTORn,
    GPIOB14_VECTORn,
    GPIOB15_VECTORn,
    GPIOB16_VECTORn,
    GPIOB17_VECTORn,
    GPIOB18_VECTORn,
    GPIOB19_VECTORn,
    GPIOB20_VECTORn,
    GPIOB21_VECTORn,
    GPIOB22_VECTORn,
    GPIOB23_VECTORn,
    GPIOB24_VECTORn,
    GPIOB25_VECTORn,
    GPIOB26_VECTORn,
    GPIOB27_VECTORn,
    GPIOB28_VECTORn,
    GPIOB29_VECTORn,
    GPIOB30_VECTORn,
    GPIOB31_VECTORn,

    MAX_VECTORn,
} VECTORn_Type;

#define Peripheral_First_VECTORn    SPIC0_VECTORn
#define Peripheral_Last_VECTORn     RSVD7_VECTORn

#define BTMAC_First_VECTORn         Timer_A0_A1_IRQn
#define BTMAC_Last_VECTORn          RSVD6_VECTORn

#define GPIOA_First_VECTORn         GPIOA2_VECTORn
#define GPIOA_Last_VECTORn          GPIOA31_VECTORn
#define GPIOB_First_VECTORn         GPIOB0_VECTORn
#define GPIOB_Last_VECTORn          GPIOB31_VECTORn

extern void *RamVectorTable[];

extern void Default_Handler_rom(void);
extern void BTMAC_Handler(void);

/** End of VECTOR_TABLE_Exported_Types
  * @}
  */

/*============================================================================*
*                              Functions
*============================================================================*/
/** @defgroup VECTOR_TABLE_Exported_Functions Vector table Exported Functions
  * @brief
  * @{
  */
/**
 * @brief  Initialize RAM vector table to a given RAM address.
 * @param  ram_vector_addr: RAM Vector Address.
 * @retval true: Success
 *         false: Fail
 * @note   When using vector table relocation, the base address of the new vector
 *         table must be aligned to the size of the vector table extended to the
 *         next larger power of 2. In RTL8763, the base address is aligned at 0x100.
 */
bool RamVectorTableInit(uint32_t ram_vector_addr);

/**
 * @brief  Update ISR Handler in RAM Vector Table.
 * @param  v_num: Vector number(index)
 * @param  isr_handler: User defined ISR Handler.
 * @retval true: Success
 *         false: Fail
 */
bool RamVectorTableUpdate(VECTORn_Type v_num, IRQ_Fun isr_handler);

/** End of VECTOR_TABLE_Exported_Functions
  * @}
  */

/** End of VECTOR_TABLE
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif // VECTOR_TABLE_H
