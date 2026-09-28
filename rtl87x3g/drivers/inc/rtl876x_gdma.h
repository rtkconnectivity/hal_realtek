/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef __RTL876X_GDMA_H
#define __RTL876X_GDMA_H



#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "rtl876x_gdma_def.h"

/** @addtogroup 87x3g_GDMA GDMA
  * @brief GDMA driver module
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/

/** @defgroup 87x3g_GDMA_Exported_Constants GDMA Exported Constants
  * @{
  */

/**
 * \defgroup 87x3g_GDMA_CHANNEL_NUM GDMA Channel Number
  * @{
 */
#define GDMA_CH_NUM0             (0)    /*!< GDMA channel number 0. */
#define GDMA_CH_NUM1             (1)    /*!< GDMA channel number 1. */
#define GDMA_CH_NUM2             (2)    /*!< GDMA channel number 2. */
#define GDMA_CH_NUM3             (3)    /*!< GDMA channel number 3. */
#define GDMA_CH_NUM4             (4)    /*!< GDMA channel number 4. */
#define GDMA_CH_NUM5             (5)    /*!< GDMA channel number 5. */
#if (CHIP_GDMA_CHANNEL_NUM >= 9)
#define GDMA_CH_NUM6             (6)    /*!< GDMA channel number 6. */
#define GDMA_CH_NUM7             (7)    /*!< GDMA channel number 7. */
#define GDMA_CH_NUM8             (8)    /*!< GDMA channel number 8. */
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 10)
#define GDMA_CH_NUM9             (9)    /*!< GDMA channel number 9. */
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 12)
#define GDMA_CH_NUM10            (10)   /*!< GDMA channel number 10. */
#define GDMA_CH_NUM11            (11)   /*!< GDMA channel number 11. */
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 16)
#define GDMA_CH_NUM12            (12)   /*!< GDMA channel number 12. */
#define GDMA_CH_NUM13            (13)   /*!< GDMA channel number 13. */
#define GDMA_CH_NUM14            (14)   /*!< GDMA channel number 14. */
#define GDMA_CH_NUM15            (15)   /*!< GDMA channel number 15. */
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 24)
#define GDMA_CH_NUM16            (16)   /*!< GDMA channel number 16. */
#define GDMA_CH_NUM17            (17)   /*!< GDMA channel number 17. */
#define GDMA_CH_NUM18            (18)   /*!< GDMA channel number 18. */
#define GDMA_CH_NUM19            (19)   /*!< GDMA channel number 19. */
#define GDMA_CH_NUM20            (20)   /*!< GDMA channel number 20. */
#define GDMA_CH_NUM21            (21)   /*!< GDMA channel number 21. */
#define GDMA_CH_NUM22            (22)   /*!< GDMA channel number 22. */
#define GDMA_CH_NUM23            (23)   /*!< GDMA channel number 23. */
#endif
#if (CHIP_GDMA_CHANNEL_NUM >= 33)
#define GDMA_CH_NUM24            (24)   /*!< GDMA channel number 24. */
#define GDMA_CH_NUM25            (25)   /*!< GDMA channel number 25. */
#define GDMA_CH_NUM26            (26)   /*!< GDMA channel number 26. */
#define GDMA_CH_NUM27            (27)   /*!< GDMA channel number 27. */
#define GDMA_CH_NUM28            (28)   /*!< GDMA channel number 28. */
#define GDMA_CH_NUM29            (29)   /*!< GDMA channel number 29. */
#define GDMA_CH_NUM30            (30)   /*!< GDMA channel number 30. */
#define GDMA_CH_NUM31            (31)   /*!< GDMA channel number 31. */
#define GDMA_CH_NUM32            (32)   /*!< GDMA channel number 32. */
#endif

#define IS_GDMA_ChannelNum(NUM)  ((NUM) < CHIP_GDMA_CHANNEL_NUM)  //!< The max channel num of GDMA is 16.
#define GDMA_MAX_HP_CH_COUNT (2)  //!< The GDMA high performance channel count.
/** End of 87x3g_GDMA_CHANNEL_NUM
  * @}
  */

/**
 * \defgroup   87x3g_GDMA_data_transfer_direction GDMA Data Transfer Direction
  * @{
 */

typedef enum
{
    GDMA_DIR_MemoryToMemory = 0x0,          //!< Configure the direction of GDMA as memory to memory.
    GDMA_DIR_MemoryToPeripheral = 0x1,      //!< Configure the direction of GDMA as memory to peripheral.
    GDMA_DIR_PeripheralToMemory = 0x2,      //!< Configure the direction of GDMA as peripheral to memory.
    GDMA_DIR_PeripheralToPeripheral = 0x3,  //!< Configure the direction of GDMA as peripheral to peripheral.
} GDMADirection_TypeDef;

#define IS_GDMA_DIR(DIR) (((DIR) == GDMA_DIR_MemoryToMemory) || \
                          ((DIR) == GDMA_DIR_MemoryToPeripheral) || \
                          ((DIR) == GDMA_DIR_PeripheralToMemory) ||\
                          ((DIR) == GDMA_DIR_PeripheralToPeripheral))   //!< Check whether is the direction of GDMA.

/** End of 87x3g_GDMA_data_transfer_direction
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_source_incremented_mode GDMA Source Incremented Mode
  * @{
 */

typedef enum
{
    DMA_SourceInc_Inc = 0x0,    //!< Configure the source address as incremented.
    DMA_SourceInc_Fix = 0x2,    //!< Configure the source address as fixed.
} GDMASrcInc_TypeDef;

#define IS_GDMA_SourceInc(STATE) (((STATE) == DMA_SourceInc_Inc) || \
                                  ((STATE) == DMA_SourceInc_Fix))   //!< Check whether is the source address mode.

/** End of 87x3g_GDMA_source_incremented_mode
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_destination_incremented_mode GDMA Destination Incremented Mode
  * @{
 */

typedef enum
{
    DMA_DestinationInc_Inc = 0x0,   //!< Configure the destination address as incremented.
    DMA_DestinationInc_Fix = 0x2,   //!< Configure the destination address as fixed.
} GDMADestInc_TypeDef;

#define IS_GDMA_DestinationInc(STATE) (((STATE) == DMA_DestinationInc_Inc) || \
                                       ((STATE) == DMA_DestinationInc_Fix))   //!< Check whether is the destination address mode.

/** End of 87x3g_GDMA_destination_incremented_mode
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_data_size GDMA Data Size
  * @{
 */

typedef enum
{
    GDMA_DataSize_Byte     = 0x0,   //!< Configure the source or destination data size as byte.
    GDMA_DataSize_HalfWord = 0x1,   //!< Configure the source or destination data size as half word.
    GDMA_DataSize_Word     = 0x2,   //!< Configure the source or destination data size as word.
} GDMADataSize_TypeDef;

#define IS_GDMA_DATA_SIZE(SIZE) (((SIZE) == GDMA_DataSize_Byte) || \
                                 ((SIZE) == GDMA_DataSize_HalfWord) || \
                                 ((SIZE) == GDMA_DataSize_Word))    //!< Check whether is the GDMA data size.

/** End of 87x3g_GDMA_data_size
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_Msize GDMA Msize
  * @{
 */

typedef enum
{
    GDMA_Msize_1   = 0x0,     //!< Configure the burst transaction length as 1.
    GDMA_Msize_4   = 0x1,     //!< Configure the burst transaction length as 4.
    GDMA_Msize_8   = 0x2,     //!< Configure the burst transaction length as 8.
    GDMA_Msize_16  = 0x3,     //!< Configure the burst transaction length as 16.
    GDMA_Msize_32  = 0x4,     //!< Configure the burst transaction length as 32.
    GDMA_Msize_64  = 0x5,     //!< Configure the burst transaction length as 64.
    GDMA_Msize_128 = 0x6,     //!< Configure the burst transaction length as 128.
} GDMAMSize_TypeDef;

#define IS_GDMA_MSIZE(SIZE) (((SIZE) == GDMA_Msize_1) || \
                             ((SIZE) == GDMA_Msize_4) || \
                             ((SIZE) == GDMA_Msize_8) || \
                             ((SIZE) == GDMA_Msize_16) || \
                             ((SIZE) == GDMA_Msize_32) || \
                             ((SIZE) == GDMA_Msize_64) || \
                             ((SIZE) == GDMA_Msize_128))    //!< Check whether is the burst transaction length.

/** End of 87x3g_GDMA_Msize
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_Status GDMA Operate Return Value
  * @{
 */
typedef enum _GDMA_CMD_RETURN_VAL
{
    GDMA_ENABLE_SUCCESS,    //!< Enable GDMA success.
    GDMA_ENABLE_FAIL,       //!< Enable GDMA failed.
    GDMA_DISABLE_SUCCESS,   //!< Disable GDMA success.
    GDMA_DISABLE_FAIL,      //!< Disable GDMA failed.
    GDMA_DISABLE_ALREADY,   //!< GDMA has been disabled..
    GDMA_STATUS_NONE,
} GDMA_Status;

/** End of 87x3g_GDMA_Status
  * @}
  */

/** @defgroup 87x3g_GDMA_interrupts_definition GDMA Interrupts Definition
  * @{
  */

#define GDMA_INT_Transfer               (BIT0)  //!< The interrupt is generated on GDMA transfer completion to the destination.
#define GDMA_INT_Block                  (BIT1)  //!< The interrupt is generated on GDMA block transfer completion to the destination.
#define GDMA_INT_Error                  (BIT4)  //!< The interrupt is generated when an ERROR response is received from the slave on the SRESP bus during a GDMA transfer.
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
#define GDMA_INT_Half_Block             (BIT5)  /*!< The interrupt is generated on GDMA half block transfer completion to the destination. */
#endif

#define IS_GDMA_CONFIG_IT(IT) ((((IT) & 0xFFFFFFE0) == 0x00) && ((IT) != 0x00)) //!< Check whether is the GDMA interrupt.

/** End of Group 87x3g_GDMA_interrupts_definition
  * @}
  */

/**
 * \defgroup    87x3g_GDMA_Multiblock_Mode GDMA Multi-Block Mode
  * @{
 */

#define AUTO_RELOAD_WITH_CONTIGUOUS_SAR                            (BIT31)    //!< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to auto-reload.
#define AUTO_RELOAD_WITH_CONTIGUOUS_DAR                            (BIT30)    //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to continuous.
#define AUTO_RELOAD_TRANSFER                                       (BIT30 | BIT31)  //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to auto-reload.
#define LLI_WITH_CONTIGUOUS_SAR                                    (BIT27)    //!< Configure the multi-block transfer mode with the source address set to continuous and the destination address set to LLI.
#define LLI_WITH_AUTO_RELOAD_SAR                                   (BIT27 | BIT30)  //!< Configure the multi-block transfer mode with the source address set to auto-reload and the destination address set to LLI.
#define LLI_WITH_CONTIGUOUS_DAR                                    (BIT28)    //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to continuous.
#define LLI_WITH_AUTO_RELOAD_DAR                                   (BIT28 | BIT31)  //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to auto-reload.
#define LLI_TRANSFER                                               (BIT27 | BIT28)  //!< Configure the multi-block transfer mode with the source address set to LLI and the destination address set to LLI.

#define IS_GDMA_MULTIBLOCKMODE(MODE) (((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_SAR) || ((MODE) == AUTO_RELOAD_WITH_CONTIGUOUS_DAR)\
                                      ||((MODE) == AUTO_RELOAD_TRANSFER) || ((MODE) == LLI_WITH_CONTIGUOUS_SAR)\
                                      ||((MODE) == LLI_WITH_AUTO_RELOAD_SAR) || ((MODE) == LLI_WITH_CONTIGUOUS_DAR)\
                                      ||((MODE) == LLI_WITH_AUTO_RELOAD_DAR) || ((MODE) == LLI_TRANSFER)) //!< Check whether is the GDMA multi-block transfer mode.

/** End of 87x3g_GDMA_Multiblock_Mode
  * @}
  */

/** @cond private
 * \defgroup    87x3g_GDMA_Multiblock_Select_Bit GDMA Multi-Block Select Bit
  * @{
 */

#define AUTO_RELOAD_SELECTED_BIT        (BIT30 | BIT31)   //!< The bit for GDMA auto-reload.
#define LLP_SELECTED_BIT                (BIT27 | BIT28)   //!< The bit for GDMA LLI.

/** End of 87x3g_GDMA_Multiblock_Select_Bit
  * @}
  * @endcond
  */

/**
 * \defgroup    87x3g_DMA_Suspend_definition GDMA Suspend Definition
  * @{
 */
#define GDMA_SUSPEND_TRANSMISSSION      (BIT(8))    //!< The bit for GDMA suspend transmisssion.
#define GDMA_FIFO_STATUS                (BIT(9))    //!< The bit for GDMA FIFO status.
#define GDMA_SUSPEND_CHANNEL_STATUS     (BIT(0))    //!< The bit for GDMA suspend channel status.
#define GDMA_SUSPEND_CMD_STATUS         (BIT(2) | BIT(1))   //!< The bit for GDMA suspend command.

/** End of 87x3g_DMA_Suspend_definition
  * @}
  */

/** End of Group 87x3g_GDMA_Exported_Constants
  * @}
  */


/*============================================================================*
 *                         Types
 *============================================================================*/
/** \defgroup 87x3g_GDMA_Exported_Types GDMA Exported Types
  * @{
  */

/**
  * @brief  GDMA Init structure definition.
  */
typedef struct
{
    uint8_t GDMA_ChannelNum;         /*!< Specifies the channel number for GDMA.
                                                    This parameter can be set from 0 to 15. */

    GDMADirection_TypeDef
    GDMA_DIR;                /*!< Specifies if the peripheral is the source or destination.
                                                    This parameter can be a value of @ref x3g_GDMA_data_transfer_direction. */

    uint32_t GDMA_BufferSize;        /*!< Specifies the buffer size. The data unit is equal to the configuration set in GDMA_SourceDataSize.
                                                    This parameter can be set from 1 to 1048575. */

    GDMASrcInc_TypeDef
    GDMA_SourceInc;          /*!< Specifies whether the source address register is incremented or not.
                                                    This parameter can be a value of @ref x3g_GDMA_source_incremented_mode. */

    GDMADestInc_TypeDef
    GDMA_DestinationInc;     /*!< Specifies whether the destination address register is incremented or not.
                                                    This parameter can be a value of @ref x3g_GDMA_destination_incremented_mode. */

    GDMADataSize_TypeDef GDMA_SourceDataSize;    /*!< Specifies the source data width.
                                                    This parameter can be a value of @ref x3g_GDMA_data_size. */

    GDMADataSize_TypeDef GDMA_DestinationDataSize;/*!< Specifies the destination data width.
                                                    This parameter can be a value of @ref x3g_GDMA_data_size. */

    GDMAMSize_TypeDef GDMA_SourceMsize;      /*!< Specifies the burst transaction length.
                                                    This parameter can be a value of @ref x3g_GDMA_Msize. */

    GDMAMSize_TypeDef GDMA_DestinationMsize; /*!< Specifies  the burst transaction length.
                                                    This parameter can be a value of @ref x3g_GDMA_Msize. */

    uint32_t GDMA_SourceAddr;       /*!< Specifies the source address for GDMA channelx. */

    uint32_t GDMA_DestinationAddr;  /*!< Specifies the destination address for GDMA channelx. */

    uint32_t GDMA_ChannelPriority;   /*!< Specifies the software priority for the GDMA channelx.
                                                    This parameter can be set from 0 to 15, and 0 is the highest priority value. */

    uint32_t GDMA_Multi_Block_Mode;      /*!< Specifies the multi block transfer mode.
                                                    This parameter can be a value of @ref x3g_GDMA_Multiblock_Mode. */

    uint32_t GDMA_Multi_Block_Struct; /*!< Specifies the pointer to the first struct of LLI. */

    uint8_t  GDMA_Multi_Block_En;     /*!< Specifies whether to enable the multi-block function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint8_t  GDMA_SourceHandshake;       /*!< Specifies the handshake index in source.
                                                    This parameter can be a value of @ref x3g_GDMA_Handshake_Type. */

    uint8_t  GDMA_DestHandshake;          /*!< Specifies the handshake index in destination.
                                                    This parameter can be a value of @ref x3g_GDMA_Handshake_Type. */

#if (GDMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    uint8_t  GDMA_Gather_En;          /*!< Specifies whether to enable the gather function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint32_t GDMA_GatherCount;        /*!< Specifies the source gather count.
                                                    This parameter can be set from 0x0 to 0xffff. */

    uint32_t GDMA_GatherInterval;     /*!< Specifies the source gather interval.
                                                    This parameter can be set from 0x0 to 0xfffff. */

    uint8_t  GDMA_Scatter_En;         /*!< Specifies whether to enable the scatter function.
                                                    This parameter can be a value of ENABLE or DISABLE. */

    uint32_t GDMA_ScatterCount;          /*!< Specifies the destination scatter count.
                                                    This parameter can be set from 0x0 to 0xffff. */

    uint32_t GDMA_ScatterInterval;      /*!< Specifies the destination scatter interval.
                                                    This parameter can be set from 0x0 to 0xfffff. */

    uint32_t GDMA_GatherCircularStreamingNum;  /*!< Specifies the circular gather number.
                                                    This parameter can be set from 0x1 to 0xf. */

    uint32_t GDMA_ScatterCircularStreamingNum; /*!< Specifies the circular scatter number.
                                                    This parameter can be set from 0x1 to 0xf. */
#endif

} GDMA_InitTypeDef;

/**
  * @brief  GDMA Link List Item structure definition.
  */
typedef struct
{
    __IO uint32_t SAR;
    __IO uint32_t DAR;
    __IO uint32_t LLP;
    __IO uint32_t CTL_LOW;
    __IO uint32_t CTL_HIGH;
} GDMA_LLIDef;

/** End of Group 87x3g_GDMA_Exported_Types
  * @}
  */


/*============================================================================*
 *                         Functions
 *============================================================================*/
/** \defgroup 87x3g_GDMA_Exported_Functions GDMA Exported Functions
  * @{
  */

/**
 * \brief  Enable or Disable GDMA peripheral clock.
 *
 * \param[in]  GDMAx: GDMA base. \ref x3g_GDMA_Declaration.
 * \param[in]  enable: Enable or disable GDMA hardware clock.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the GDMA clock.
 *             - DISABLE: Disable the GDMA clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     GDMA_HwClock(GDMA0, ENABLE);
 * }
 * \endcode
 */
void GDMA_HwClock(GDMA_TypeDef *GDMAx, bool enable);;

/**
 *
 * \brief  Deinitializes the GDMA registers to their default reset values and GDMA clock will be closed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     GDMA_DeInit();
 * }
 * \endcode
 */
void GDMA_DeInit(void);

/**
 *
 * \brief     Initializes the GDMA channelx according to the specified
 *            parameters in the GDMA_InitStruct.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 8 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] GDMA_InitStruct: Pointer to a \ref _X3G_GDMA_InitTypeDef structure that
 *            contains the configuration information for the specified GDMA Channel.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 * #define UART_TX_DMA_CHANNEL    DMA_CH_BASE(uart_tx_dma_ch_num)
 * #define UART_TX_DMA_IRQ        DMA_CH_IRQ(uart_tx_dma_ch_num)
 * uint8_t GDMA_SendBuffer[100];
 *
 * void driver_gdma_init(void)
 * {
 *     uint16_t  strLen = 0;
 *     char *demoStr = "### Welcome to use RealTek Bumblebee ###\r\n";
 *     strLen = strlen(demoStr);
 *     memcpy(GDMA_SendBuffer, demoStr, strLen);
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = UART_TX_DMA_CHANNEL_NUM;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = strLen;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendBuffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART->RB_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA_Handshake_UART0_TX;
 *     GDMA_Init(UART_TX_DMA_CHANNEL, &GDMA_InitStruct);
 * }
 * \endcode
 */
void GDMA_Init(GDMA_ChannelTypeDef *GDMA_Channelx, GDMA_InitTypeDef *GDMA_InitStruct);

/**
 *
 * \brief     Fills each GDMA_InitStruct member with its default value.
 *
 * \param[in] GDMA_InitStruct: Pointer to a \ref _X3G_GDMA_InitTypeDef structure which will be initialized.
 *
 * \note   The default settings for the GDMA_InitStruct member are shown in the following table:
 *         | GDMA_InitStruct Member      | Default Value                      |
 *         |:---------------------------:|:----------------------------------:|
 *         | GDMA_ChannelNum             | 0                                  |
 *         | GDMA_DIR                    | \ref GDMA_DIR_PeripheralToMemory   |
 *         | GDMA_BufferSize             | 200                                |
 *         | GDMA_SourceInc              | \ref DMA_SourceInc_Fix             |
 *         | GDMA_DestinationInc         | \ref DMA_DestinationInc_Inc        |
 *         | GDMA_SourceDataSize         | \ref GDMA_DataSize_Byte            |
 *         | GDMA_DestinationDataSize    | \ref GDMA_DataSize_Byte            |
 *         | GDMA_SourceMsize            | \ref GDMA_Msize_1                  |
 *         | GDMA_DestinationMsize       | \ref GDMA_Msize_1                  |
 *         | GDMA_SourceAddr             | 0                                  |
 *         | GDMA_DestinationAddr        | 0                                  |
 *         | GDMA_ChannelPriority        | 0                                  |
 *         | GDMA_Multi_Block_Mode       | \ref LLI_TRANSFER                  |
 *         | GDMA_SourceHandshake        | 0                                  |
 *         | GDMA_DestHandshake          | 0                                  |
 *         | GDMA_Multi_Block_En         | DISABLE                            |
 *         | GDMA_Scatter_En             | DISABLE                            |
 *         | GDMA_Gather_En              | DISABLE                            |
 *         | GDMA_Source_Cir_Gather_Num  | 1                                  |
 *         | GDMA_Dest_Cir_Sca_Num       | 1                                  |
 *         | GDMA_Multi_Block_Struct     | 0                                  |
 *         | GDMA_ScatterCount           | 0                                  |
 *         | GDMA_ScatterInterval        | 0                                  |
 *         | GDMA_GatherCount            | 0                                  |
 *         | GDMA_GatherInterval         | 0                                  |
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 * #define UART_TX_DMA_CHANNEL    DMA_CH_BASE(uart_tx_dma_ch_num)
 * #define UART_TX_DMA_IRQ        DMA_CH_IRQ(uart_tx_dma_ch_num)
 * uint8_t GDMA_SendBuffer[100];
 *
 * void driver_gdma_init(void)
 * {
 *     uint16_t  strLen = 0;
 *     char *demoStr = "### Welcome to use RealTek Bumblebee ###\r\n";
 *     strLen = strlen(demoStr);
 *     memcpy(GDMA_SendBuffer, demoStr, strLen);
 *
 *     GDMA_InitTypeDef GDMA_InitStruct;
 *     GDMA_StructInit(&GDMA_InitStruct);
 *     GDMA_InitStruct.GDMA_ChannelNum      = UART_TX_DMA_CHANNEL_NUM;
 *     GDMA_InitStruct.GDMA_DIR             = GDMA_DIR_MemoryToPeripheral;
 *     GDMA_InitStruct.GDMA_BufferSize      = strLen;//determine total transfer size
 *     GDMA_InitStruct.GDMA_SourceInc       = DMA_SourceInc_Inc;
 *     GDMA_InitStruct.GDMA_DestinationInc  = DMA_DestinationInc_Fix;
 *     GDMA_InitStruct.GDMA_SourceDataSize  = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_DestinationDataSize = GDMA_DataSize_Byte;
 *     GDMA_InitStruct.GDMA_SourceMsize      = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_DestinationMsize = GDMA_Msize_1;
 *     GDMA_InitStruct.GDMA_SourceAddr      = (uint32_t)GDMA_SendBuffer;
 *     GDMA_InitStruct.GDMA_DestinationAddr = (uint32_t)(&(UART->RB_THR));
 *     GDMA_InitStruct.GDMA_DestHandshake   = GDMA_Handshake_UART0_TX;
 *     GDMA_Init(UART_TX_DMA_CHANNEL, &GDMA_InitStruct);
 * }
 * \endcode
 */
void GDMA_StructInit(GDMA_InitTypeDef *GDMA_InitStruct);

/**
 *
 * \brief  Enables or disables the selected GDMA channel.
 *
 * \param[in]  GDMA_ChannelNum: GDMA channel number, which can be 0~15.
 * \param[in]  NewState: New state of the selected GDMA channel.
 *             This parameter can be one of the following values:
 *             - ENABLE: Enable the selected GDMA channel.
 *             - DISABLE: Disable the selected GDMA channel.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 *
 * void driver_gdma_init(void)
 * {
 *     GDMA_Cmd(UART_TX_DMA_CHANNEL_NUM, ENABLE);
 * }
 * \endcode
 */
uint8_t GDMA_Cmd(uint8_t GDMA_ChannelNum, FunctionalState NewState);

/**
 *
 * \brief   Enable or disable the specified GDMA channelx interrupt source.
 *
 * \param[in] GDMA_ChannelNum: GDMA channel number, which can be 0~15.
 * \param[in] GDMA_IT: Specifies the GDMA interrupt source to be enabled or disabled. \ref x3g_DMA_interrupts_definition.
 *            This parameter can be any combination of the following values:
 *            - GDMA_INT_Transfer: The interrupt is generated on GDMA transfer completion to the destination.
 *            - GDMA_INT_Block: The interrupt is generated on GDMA block transfer completion to the destination.
 *            - GDMA_INT_Half_Block: The interrupt is generated on GDMA half block transfer completion to the destination.
 *            - GDMA_INT_Error: The interrupt is generated when an ERROR response is received from the slave on the SRESP bus during a GDMA transfer.
 * \param[in] NewState: New state of the specified GDMA interrupt source.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified GDMA channelx interrupt source.
 *            - DISABLE: Disable the specified GDMA channelx interrupt source.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 * #define UART_TX_DMA_CHANNEL    DMA_CH_BASE(uart_tx_dma_ch_num)
 * #define UART_TX_DMA_IRQ        DMA_CH_IRQ(uart_tx_dma_ch_num)
 * uint8_t GDMA_SendBuffer[100];
 *
 * void driver_gdma_init(void)
 * {
 *     GDMA_INTConfig(UART_TX_DMA_CHANNEL_NUM, GDMA_INT_Transfer, ENABLE);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = UART_TX_DMA_IRQ;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = (FunctionalState)ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);
 * }
 * \endcode
 */
void GDMA_INTConfig(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT, FunctionalState NewState);

/**
 *
 * \brief  Clear the specified GDMA channelx interrupt pending bit.
 *
 * \param[in] GDMA_ChannelNum: GDMA channel number, which can be 0~15.
 *
 * \param[in] GDMA_IT: Specifies the GDMA interrupt source to be enabled or disabled. \ref x3g_DMA_interrupts_definition.
 *            This parameter can be any combination of the following values:
 *            - GDMA_INT_Transfer: The interrupt is generated on GDMA transfer completion to the destination.
 *            - GDMA_INT_Block: The interrupt is generated on GDMA block transfer completion to the destination.
 *            - GDMA_INT_Half_Block: The interrupt is generated on GDMA half block transfer completion to the destination.
 *            - GDMA_INT_Error: The interrupt is generated when an ERROR response is received from the slave on the SRESP bus during a GDMA transfer.
 *
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 *
 * void UART_TX_GDMA_Handler(void)
 * {
 *     GDMA_ClearINTPendingBit(UART_TX_DMA_CHANNEL_NUM, GDMA_INT_Transfer);
 *     //Add user code here.
 * }
 * \endcode
 */
void GDMA_ClearINTPendingBit(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT);

/**
 *
 * \brief  Suspend GDMA transmission safe from the source. Please check GDMA FIFO empty to guarnatee without losing data.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return The result of suspend GDMA transmission.
 * \retval true: Suspend GDMA transmission success.
 * \retval false: Suspend GDMA transmission failed.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_rx_dma_ch_num = 0xa5;
 * #define UART_RX_DMA_CHANNEL_NUM   uart_rx_dma_ch_num
 * #define UART_RX_DMA_CHANNEL       DMA_CH_BASE(uart_rx_dma_ch_num)
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SafeSuspend(UART_RX_DMA_CHANNEL);
 *     //Add user code here.
 * }
 * \endcode
 */
bool GDMA_SafeSuspend(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief   Get the selected GDMA channel status.
 *
 * \param[in] GDMA_Channel_Num: GDMA channel number, which can be 0~15.
 *
 * \return  The status of GDMA channel.
 * \retval  SET: Channel is be used.
 * \retval  RESET: Channel is free.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void Data_Uart_Handler(void)
 * {
 *     if (UART_GetFlagState(UART, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         UART_INTConfig(UART, UART_INT_IDLE, DISABLE);
 *         if (GDMA_GetChannelStatus(UART_RX_DMA_CHANNEL_NUM))
 *         {
 *             GDMA_SuspendCmd(UART_RX_DMA_CHANNEL, ENABLE);
 *         }
 *     }
 * }
 * \endcode
 */
FlagStatus GDMA_GetChannelStatus(uint8_t GDMA_Channel_Num);

/**
 *
 * \brief  Check whether GDMA Channel transfer interrupt is set.
 *
 * \param[in] GDMA_Channel_Num: GDMA channel number, which can be 0~15.
 *
 * \return  Transfer interrupt status, SET or RESET.
 * \retval SET: GDMA Channel transfer interrupt is set.
 * \retval RESET: GDMA Channel transfer interrupt is unset.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * #define LCD_RST                          P4_0
 * #define LCD_DMA_CHANNEL_NUM              lcd_dma_ch_num
 *
 * void lcd_wait_dma_transfer(void)
 * {
 *     while (GDMA_GetTransferINTStatus(LCD_DMA_CHANNEL_NUM) != SET);
 *     GDMA_ClearINTPendingBit(LCD_DMA_CHANNEL_NUM, GDMA_INT_Transfer);
 * }
 * \endcode
 */
ITStatus GDMA_GetTransferINTStatus(uint8_t GDMA_Channel_Num);

/**
 *
 * \brief     Clear GDMA channelx all type interrupt.
 *
 * \param[in] GDMA_Channel_Num: GDMA channel number, which can be 0~15.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t uart_tx_dma_ch_num = 0xa5;
 * uint8_t UART_TX_DMA_CHANNEL_NUM = uart_tx_dma_ch_num;
 *
 * void gdma_demo(void)
 * {
 *     GDMA_ClearAllTypeINT(UART_TX_DMA_CHANNEL_NUM);
 * }
 * \endcode
 */
void GDMA_ClearAllTypeINT(uint8_t GDMA_Channel_Num);

/**
 *
 * \brief     Set GDMA transmission source address.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 8 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] Address: Source address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t console_tx_dma_ch_num = 0xa5;
 * #define UART_TX_DMA_CHANNEL         DMA_CH_BASE(console_tx_dma_ch_num)
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     GDMA_SetSourceAddress(UART_TX_DMA_CHANNEL, (uint32_t)data_buf);
 * }
 * \endcode
 */
void GDMA_SetSourceAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address);

/**
 *
 * \brief     Set GDMA transmission destination address.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] Address: Destination address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t console_rx_dma_ch_num = 0xa5;
 * #define UART_RX_DMA_CHANNEL    DMA_CH_BASE(console_rx_dma_ch_num)
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf[10] = {0};
 *     GDMA_SetDestinationAddress(UART_RX_DMA_CHANNEL, (uint32_t)data_buf);
 * }
 * \endcode
 */
void GDMA_SetDestinationAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address);

/**
 *
 * \brief     Set GDMA buffer size.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] buffer_size: Set GDMA BufferSize, max size is 1048575.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * uint8_t console_tx_dma_ch_num = 0xa5;
 * #define UART_TX_DMA_CHANNEL         DMA_CH_BASE(console_tx_dma_ch_num)
 *
 * void gdma_demo(void)
 * {
 *     uint32_t data_buf_size = 4095;
 *     GDMA_SetBufferSize(UART_TX_DMA_CHANNEL, data_buf_size);
 * }
 * \endcode
 */
void GDMA_SetBufferSize(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t buffer_size);

/**
 * \brief  Get GDMA source address.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return Source address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t address = GDMA_GetSrcTransferAddress(GDMA2_Channel0);
 * }
 * \endcode
 */
uint32_t GDMA_GetSrcTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 * \brief  Get GDMA destination address.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return Destination address.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     uint32_t address = GDMA_GetDstTransferAddress(GDMA2_Channel0);
 * }
 * \endcode
 */
uint32_t GDMA_GetDstTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief     Suspend GDMA transmission from the source. Please check GDMA FIFO empty to guarnatee without losing data.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] NewState: Enable or disable suspend GDMA transmission.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable suspend GDMA transmission.
 *            - DISABLE: Disable suspend GDMA transmission.
 *
 * \note      To prevent data loss, it is necessary to check whether FIFO data transmission is completed
 *            after suspend, and judge by checking whether GDMA FIFO is empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void Data_Uart_Handler(void)
 * {
 *     uint16_t rx_count;
 *     if (UART_GetFlagState(UART, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         //restart GDMA receive
 *         GDMA_SetDestinationAddress(UART_RX_DMA_CHANNEL, (uint32_t)uart_receive_buf);
 *         GDMA_SuspendCmd(UART_RX_DMA_CHANNEL, DISABLE);
 *         GDMA_Cmd(UART_RX_DMA_CHANNEL_NUM, ENABLE);
 *
 *         UART_INTConfig(UART0, UART_INT_IDLE, ENABLE);
 *     }
 * }
 * \endcode
 */
void GDMA_SuspendCmd(GDMA_ChannelTypeDef *GDMA_Channelx, FunctionalState NewState);

/**
 *
 * \brief     Check whether GDMA FIFO is empty.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return The status of GDMA FIFO.
 * \retval SET: GDMA FIFO is empty.
 * \retval RESET: GDMA FIFO is not empty.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void Data_Uart_Handler(void)
 * {
 *     uint16_t rx_count;
 *     if (UART_GetFlagState(UART, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         UART_INTConfig(UART, UART_INT_IDLE, DISABLE);
 *         if (GDMA_GetChannelStatus(UART_RX_DMA_CHANNEL_NUM))
 *         {
 *             GDMA_SuspendCmd(UART_RX_DMA_CHANNEL, ENABLE);
 *         }
 *         while (GDMA_GetFIFOStatus(UART_RX_DMA_CHANNEL) != SET);
 *     }
 * }
 * \endcode
 */
FlagStatus GDMA_GetFIFOStatus(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief     Get GDMA transfer data length.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return    GDMA transfer data length.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void Data_Uart_Handler(void)
 * {
 *     uint16_t rx_count;
 *     if (UART_GetFlagState(UART, UART_FLAG_RX_IDLE) == SET)
 *     {
 *         //read GDMA total transfer count
 *         rx_count = GDMA_GetTransferLen(UART_RX_DMA_CHANNEL);
 *         APP_PRINT_INFO1("rx_count:%d", rx_count);
 *     }
 * }
 * \endcode
 */
uint16_t GDMA_GetTransferLen(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief     Set GDMA LLP stucture address.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] Address: The address of LLP stucture.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_LLIDef GDMA_LLIStruct[4000];
 *     GDMA_SetLLPAddress(GDMA2_Channel0,(uint32_t)GDMA_LLIStruct);
 * }
 * \endcode
 */
void GDMA_SetLLPAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address);

/**
 * \brief     Get GDMA Channelx of the specified DMA Channel Number.
 *
 * \param[in] GDMA_Channel_Num: GDMA channel number, which can be 0~15.
 *
 * \return    GDMA_Channelx.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gdma_init(void)
 * {
 *     uint8_t channel_num = GDMA_ChannelNum;
 *     GDMA_ChannelTypeDef *GDMA_Channelx = GDMA_GetGDMAChannelx(GDMA_ChannelNum);
 * }
 * \endcode
 */
GDMA_ChannelTypeDef *GDMA_GetGDMAChannelx(uint8_t GDMA_ChannelNum);
#define DMA_CH_BASE(ChNum) (GDMA_GetGDMAChannelx(ChNum))

/**
 *
 * \brief  Check GDMA suspend channel status.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return GDMA suspend channel status.
 * \retval SET: The GDMA suspend channel is inactive.
 * \retval RESET: The GDMA suspend channel is active.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     //add user code here.
 *     while (GDMA_GetSuspendChannelStatus(GDMA_Channel0) != SET);
 * }
 * \endcode
 */
FlagStatus GDMA_GetSuspendChannelStatus(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief  Check GDMA suspend command status.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 *
 * \return GDMA suspend command status.
 * \retval SET: The GDMA channel is suspended.
 * \retval RESET: The GDMA channel is not suspended.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     FlagStatus flag_status = GDMA_GetSuspendCmdStatus(GDMA2_Channel0);
 * }
 * \endcode
 */
FlagStatus GDMA_GetSuspendCmdStatus(GDMA_ChannelTypeDef *GDMA_Channelx);

/**
 *
 * \brief  Update GDMA LLP mode in multi-block.
 *
 * \param[in] GDMA_Channelx: Where x can be 0 to 15 to select the GDMA Channel. \ref x3g_GDMA_Declaration.
 * \param[in] GDMA LLP mode. \ref x3g_GDMA_Multiblock_Mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SetLLPMode(LLI_TRANSFER);
 * }
 * \endcode
 */
void GDMA_SetLLPMode(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t mode);

/**
 * rtl876x_gdma.h
 *
 * \brief  Disable GDMA auto restore.
 *
 * \param[in]  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
 *
 * \return None.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gdma_demo(void)
 * {
 *     GDMA_SetLLPMode(LLI_TRANSFER);
 * }
 * \endcode
 */
void GDMA_DisableAutoRestore(uint8_t GDMA_Channel_Num);

#ifdef __cplusplus
}
#endif

#endif /*__RTL8762X_GDMA_H*/

/** @} */ /* End of group 87x3g_GDMA_Exported_Functions */
/** @} */ /* End of group 87x3g_GDMA */



