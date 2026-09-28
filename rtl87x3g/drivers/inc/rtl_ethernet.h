/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef RTL_ETHERNET_H_
#define RTL_ETHERNET_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_ethernet_def.h"
#include "rtl_ethernet_cpu_reg.h"

/*============================================================================*
 *                          Private Macros
 *============================================================================*/

/// Defines the MAC address length
#define MAC_ADDR_LEN                    6

/// Defines the ethernet max tx packet size
#define ETH_MAX_TX_PACKET_SIZE                          1514

/// Defines the ethernet receive packet first desc data offset
#define ETH_RX_PACKET_FIRST_DESC_DATA_OFFSET            2

#define ETH_CPU_ETH_0X130_DEFAULT_VALUE 0x01010100UL
#define ETH_CPU_ETH_0X138_DEFAULT_VALUE 0x31000000UL
#define ETH_CPU_ETH_0X134_DEFAULT_VALUE 0x40081000UL

//bit definition of tx descriptor status register
#define ETH_TX_DESC_OWN                 BIT31
#define ETH_TX_DESC_EOR                 BIT30
#define ETH_TX_DESC_FS                  BIT29
#define ETH_TX_DESC_LS                  BIT28
#define ETH_TX_DESC_CRC                 BIT23

//bit definition of rx descriptor status register
#define ETH_RX_DESC_OWN                 BIT31
#define ETH_RX_DESC_EOR                 BIT30
#define ETH_RX_DESC_FS                  BIT29
#define ETH_RX_DESC_LS                  BIT28

/** @addtogroup 87x3g_ETHERNET Ethernet
  * @brief Ethernet driver module.
  * @{
  */
/*============================================================================*
 *                         Constants
 *============================================================================*/
/** @defgroup ETH_Exported_Constants Ethernet Exported Constants
  * @{
  */

/**
 * \brief       Ethernet Link Status
 */
typedef enum
{
    ETH_LINK_UP = 0,    //!< Ethernet link up.
    ETH_LINK_DOWN = 1   //!< Ethernet link down.
} ETHLinkStatus_Typedef;

/**
 * \brief       Ethernet Duplex Mode
 */
typedef enum
{
    ETH_HALF_DUPLEX = 0,  //!< Ethernet half duplex mode.
    ETH_FULL_DUPLEX = 1   //!< Ethernet full duplex mode.
} ETHDuplexMode_Typedef;

/**
 * \brief       Ethernet Speed
 */
typedef enum
{
    ETH_SPEED_100M = 0x0,         //!< The speed of ethernet is 100M.
    ETH_SPEED_10M = 0x1,          //!< The speed of ethernet is 10M.
    ETH_SPEED_NOT_SUPPORT = 0x2,  //!< The speed of ethernet is not support.
    ETH_SPEED_NOT_ALLOWED = 0x3,  //!< The speed of ethernet is not allowed.
} ETHLinkSpeed_Typedef;

/**
 * \brief       Ethernet Status
 */
typedef enum
{
    ETH_STATUS_OK,            //!< The status of ethernet is ok.
    ETH_STATUS_ERROR,         //!< The status of ethernet is error.
} ETHErrorStatus_Typedef;

/**
 * \brief       Ethernet Receive Frame Status
 */
typedef enum
{
    ETH_RX_INVALID_PARAMETER,     //!< The parameter of receive is invalid.
    ETH_RX_NO_DATA,               //!< There is no data in RX.
    ETH_RX_FRAME_ERROR,           //!< The RX frame is error.
    ETH_RX_FRAME_SUCCESS,         //!< The RX frame is success.
    ETH_RX_COPY_DATA_LEN_ERROR,   //!< The length of data is error when copy RX data.
    ETH_RX_COPY_DATA_SUCCESS,     //!< Copy RX data success.
} ETHReceiveFrameStatus_Typedef;

/**
 * \brief       Ethernet Send Frame Status
 */
typedef enum
{
    ETH_TX_INVALID_PARAMETER,     //!< The parameter of send is invalid.
    ETH_TX_PACKET_SIZE_OVERFLOW,  //!< The size of TX packet is overflow.
    ETH_TX_DSC_IS_FULL,           //!< The descriptor for TX is full.
    ETH_TX_FRAME_SUCCESS,         //!< The TX frame is success.
    ETH_TX_COPY_DATA_SUCCESS,     //!< Copy TX data success.
} ETHSendFrameStatus_Typedef;

/**
 * \brief       Operation Mode for PHY
 */
typedef enum
{
    PHY_REG_READ_MODE = 0x00,     //!< Read PHY.
    PHY_REG_WRITE_MODE = 0x01,    //!< Write PHY.
} PHYRegOperationMode_Typedef;

/**
 * \brief       TX Change Phase
 */
typedef enum
{
    ETH_TX_CHANGE_ON_FALLING_EDGE = 0x00,   //!< TX change on falling edge.
    ETH_TX_CHANGE_ON_RISING_EDGE = 0x01,    //!< TX change on rising edge.
} ETHTxRefclkPhase_TypeDef;

/**
 * \brief       RX Sample Phase
 */
typedef enum
{
    ETH_RX_SAMPLE_ON_FALLING_EDGE = 0x0,    //!< RX sample on falling edge.
    ETH_RX_SAMPLE_ON_RISING_EDGE = 0x1,     //!< RX sample on rising edge.
} ETHRxRefclkPhase_TypeDef;

/**
 * \brief       PHY Mode
 */
typedef enum
{
    ETH_PHY_NORMAL_MODE = 0x0,          //!< PHY normal mode.
    ETH_PHY_LOOPBACK_MODE = 0x1,        //!< PHY loopback mode.
} ETHPhyMode_TypeDef;

/**
 * \brief       Ethernet Mode
 */
typedef enum
{
    ETH_NORMAL_MODE = 0,                //!< Ethernet normal mode.
    ETH_LOOPBACK_R2T_MODE = 1,          //!< Ethernet loopback R2T mode.
    ETH_LOOPBACK_T2R_MODE = 3,          //!< Ethernet loopback T2R mode.
} ETHMode_TypeDef;

/**
 * \brief       Ethernet Force Speed
 */
typedef enum
{
    ETH_LOOPBACK_FORCE_SPEED_100M = 0x0,  //!< Ethernet force speed 100M.
    ETH_LOOPBACK_FORCE_SPEED_10M = 0x1,   //!< Ethernet force speed 10M.
} ETHForceSpeed_Typedef;

/**
 * \brief       Ethernet Interpacket Gap
 */
typedef enum
{
    ETH_IFG_0 = 0,        //!< The IFG of ethernet is 0.
    ETH_IFG_1 = 1,        //!< The IFG of ethernet is 1.
    ETH_IFG_2 = 2,        //!< The IFG of ethernet is 2.
    ETH_IFG_3 = 3,        //!< The IFG of ethernet is 3.
    ETH_IFG_4 = 4,        //!< The IFG of ethernet is 4.
    ETH_IFG_5 = 5,        //!< The IFG of ethernet is 5.
    ETH_IFG_6 = 6,        //!< The IFG of ethernet is 6.
    ETH_IFG_7 = 7,        //!< The IFG of ethernet is 7.
} ETHInterFrameGapTime_TypeDef;

/**
 * \brief       Ethernet RX Config
 */
typedef enum
{
    ETH_RX_CONFIG_AAP = BIT0,       //!< Ethernet RX config AAP.
    ETH_RX_CONFIG_APM = BIT1,       //!< Ethernet RX config APM.
    ETH_RX_CONFIG_AM = BIT2,        //!< Ethernet RX config AM.
    ETH_RX_CONFIG_AB = BIT3,        //!< Ethernet RX config AB.
    ETH_RX_CONFIG_AR = BIT4,        //!< Ethernet RX config AR.
    ETH_RX_CONFIG_AER = BIT5,       //!< Ethernet RX config AER.
    ETH_RX_CONFIG_AFC = BIT6,       //!< Ethernet RX config AFC.
    ETH_RX_CONFIG_HOME_PNA = BIT7,  //!< Ethernet RX config PNA.
} ETHRxConfig_TypeDef;

/**
 * \brief       Ethernet RX Jumbo Config
 */
typedef enum
{
    ETH_RX_JUMBO_DISABLE = 0x0,     //!< Ethernet RX jumbo disable.
    ETH_RX_JUMBO_ENABLE = 0x1,      //!< Ethernet RX jumbo enable.
} ETHRxJumboConfig_TypeDef;

/**
 * \brief       Ethernet TX Threshold
 */
typedef enum
{
    ETH_TX_THRESHOLD_128B = 0,      //!< The TX threshold is 128B.
    ETH_TX_THRESHOLD_256B = 1,      //!< The TX threshold is 256B.
    ETH_TX_THRESHOLD_512B = 2,      //!< The TX threshold is 512B.
    ETH_TX_THRESHOLD_1024B = 3,     //!< The TX threshold is 1024B.
} ETHTxThreshold_TypeDef;

/**
 * \brief       Ethernet RX Threshold
 */
typedef enum
{
    ETH_RX_THRESHOLD_1024B = 0,     //!< The RX threshold is 1024B.
    ETH_RX_THRESHOLD_128B = 1,      //!< The RX threshold is 128B.
    ETH_RX_THRESHOLD_256B = 2,      //!< The RX threshold is 256B.
    ETH_RX_THRESHOLD_512B = 3,      //!< The RX threshold is 512B.
} ETHRxThreshold_TypeDef;

/**
 * \brief       Ethernet TX Trigger Level
 */
typedef enum
{
    ETH_TX_TRIGGER_LEVEL_1_PKT = 0,   //!< The TX trigger level is 1 packet.
    ETH_TX_TRIGGER_LEVEL_4_PKTS = 1,  //!< The TX trigger level is 4 packet.
    ETH_TX_TRIGGER_LEVEL_8_PKTS = 2,  //!< The TX trigger level is 8 packet.
    ETH_TX_TRIGGER_LEVEL_12_PKTS = 3, //!< The TX trigger level is 12 packet.
    ETH_TX_TRIGGER_LEVEL_16_PKTS = 4, //!< The TX trigger level is 16 packet.
    ETH_TX_TRIGGER_LEVEL_20_PKTS = 5, //!< The TX trigger level is 20 packet.
    ETH_TX_TRIGGER_LEVEL_24_PKTS = 6, //!< The TX trigger level is 24 packet.
    ETH_TX_TRIGGER_LEVEL_28_PKTS = 7, //!< The TX trigger level is 28 packet.
} ETHTxTriggerLevel_TypeDef;

/**
 * \brief       Ethernet RX Trigger Level
 */
typedef enum
{
    ETH_RX_TRIGGER_LEVEL_1_PKT = 0,     //!< The RX trigger level is 1 packet.
    ETH_RX_TRIGGER_LEVEL_4_PKTS = 1,    //!< The RX trigger level is 4 packet.
    ETH_RX_TRIGGER_LEVEL_8_PKTS = 2,    //!< The RX trigger level is 8 packet.
    ETH_RX_TRIGGER_LEVEL_12_PKTS = 3,   //!< The RX trigger level is 12 packet.
    ETH_RX_TRIGGER_LEVEL_16_PKTS = 4,   //!< The RX trigger level is 16 packet.
    ETH_RX_TRIGGER_LEVEL_20_PKTS = 5,   //!< The RX trigger level is 20 packet.
    ETH_RX_TRIGGER_LEVEL_24_PKTS = 6,   //!< The RX trigger level is 24 packet.
    ETH_RX_TRIGGER_LEVEL_28_PKTS = 7,   //!< The RX trigger level is 28 packet.
} ETHRxTriggerLevel_TypeDef;

/**
 * \brief       RTL8201FR TX Setup time
 */
typedef enum
{
    ETH_PHY_TX_SETUP_TIME_6NS,          //!< The TX set up time of RTL8201FR is 6ns.
    ETH_PHY_TX_SETUP_TIME_8NS,          //!< The TX set up time of RTL8201FR is 8ns.
    ETH_PHY_TX_SETUP_TIME_10NS,         //!< The TX set up time of RTL8201FR is 10ns.
    ETH_PHY_TX_SETUP_TIME_12NS,         //!< The TX set up time of RTL8201FR is 12ns.
    ETH_PHY_TX_SETUP_TIME_14NS,         //!< The TX set up time of RTL8201FR is 14ns.
    ETH_PHY_TX_SETUP_TIME_16NS,         //!< The TX set up time of RTL8201FR is 16ns.
    ETH_PHY_TX_SETUP_TIME_18NS,         //!< The TX set up time of RTL8201FR is 18ns.
    ETH_PHY_TX_SETUP_TIME_NUM,          //!< The TX set up time of RTL8201FR.
} ETHPhyTxSetupTime_TypeDef;

/**
 * \brief       RTL8201FR RX Setup time
 */
typedef enum
{
    ETH_PHY_RX_SETUP_TIME_8NS,          //!< The RX set up time of RTL8201FR is 8ns.
    ETH_PHY_RX_SETUP_TIME_10NS,         //!< The RX set up time of RTL8201FR is 10ns.
    ETH_PHY_RX_SETUP_TIME_12NS,         //!< The RX set up time of RTL8201FR is 12ns.
    ETH_PHY_RX_SETUP_TIME_14NS,         //!< The RX set up time of RTL8201FR is 14ns.
    ETH_PHY_RX_SETUP_TIME_16NS,         //!< The RX set up time of RTL8201FR is 16ns.
    ETH_PHY_RX_SETUP_TIME_18NS,         //!< The RX set up time of RTL8201FR is 18ns.
    ETH_PHY_RX_SETUP_TIME_NUM,          //!< The RX set up time of RTL8201FR.
} ETHPhyRxSetupTime_TypeDef;

/**
 * \brief       Ethernet Interrupt
 */
typedef enum
{
    ETH_INT_ROK = BIT0,                 //!< Receive ok.
    ETH_INT_CNT_WRAP = BIT1,            //!< TX/RX counter wrap.
    ETH_INT_RER_RUNT = BIT2,            //!< RX error caused by runt error characterized by the frame length in bytes being less than 64 bytes.
    ETH_INT_RER_OVF = BIT4,             //!< RX fifo overflow.
    ETH_INT_RDU = BIT5,                 //!< RX descriptor unavailable for ring1.
    ETH_INT_TOK = BIT6,                 //!< Transmit ok.
    ETH_INT_TER = BIT7,                 //!< Transmit error.
    ETH_INT_LINK_CHANGE = BIT8,         //!< Link change.
    ETH_INT_TDU = BIT9,                 //!< TX descriptor unavailable.
    ETH_INT_SW_INT = BIT10,             //!< Software interrupt pending.
    ETH_INT_RDU2 = BIT11,               //!< RX descriptor unavailable for ring2.
    ETH_INT_RDU3 = BIT12,               //!< RX descriptor unavailable for ring3.
    ETH_INT_RDU4 = BIT13,               //!< RX descriptor unavailable for ring4.
    ETH_INT_RDU5 = BIT14,               //!< RX descriptor unavailable for ring5.
    ETH_INT_RDU6 = BIT15,               //!< RX descriptor unavailable for ring6.
} ETHINT_TypeDef;

#define IS_ETH_INT       (status)     (((status) == ETH_INT_ROK) || \
                                       ((status) == ETH_INT_CNT_WRAP) || \
                                       ((status) == ETH_INT_RER_RUNT) || \
                                       ((status) == ETH_INT_RER_OVF) || \
                                       ((status) == ETH_INT_RDU) || \
                                       ((status) == ETH_INT_TOK) || \
                                       ((status) == ETH_INT_TER) || \
                                       ((status) == ETH_INT_LINK_CHANGE) || \
                                       ((status) == ETH_INT_TDU) || \
                                       ((status) == ETH_INT_SW_INT) || \
                                       ((status) == ETH_INT_RDU2) || \
                                       ((status) == ETH_INT_RDU3) || \
                                       ((status) == ETH_INT_RDU4) || \
                                       ((status) == ETH_INT_RDU5) || \
                                       ((status) == ETH_INT_RDU6))      //!< Check whether is ethernet interrupt.


/**
  \brief TX Descriptor Structure
*/
typedef struct
{
    uint32_t dw1;    //!< Offset 0.
    uint32_t addr;   //!< Offset 4.
    uint32_t dw2;    //!< Offset 8.
    uint32_t dw3;    //!< Offset 12.
    uint32_t dw4;    //!< Offset 16.
} ETHTxDesc_TypeDef;

/**
  \brief RX Descriptor Structure
*/
typedef struct
{
    uint32_t dw1;    //!< Offset 0.
    uint32_t addr;   //!< Offset 4.
    uint32_t dw2;    //!< Offset 8.
    uint32_t dw3;    //!< Offset 12.
} ETHRxDesc_TypeDef;

/** @defgroup 87x3g_Ethernet_Descriptor_Size  Ethernet Descriptor Size
  * @{
  */

#define ETH_TX_DESC_SIZE               sizeof(ETHTxDesc_TypeDef)  //!< The size of TX descriptor.
#define ETH_RX_DESC_SIZE               sizeof(ETHRxDesc_TypeDef)  //!< The size of RX descriptor.

/** End of group 87x3g_Ethernet_Descriptor_Size
  * @}
  */

/** End of group ETH_Exported_Constants
  * @}
  */
/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup ETH_Exported_Types Ethernet Exported Types
  * @{
  */

/**
 * \brief       Ethernet init structure definition.
 */
typedef struct
{
    ETHTxRefclkPhase_TypeDef ETH_TxRefclkPhase;       /*!< Specifies the TX clock phase.
                                                           This parameter can be a value of @ref ETHTxRefclkPhase_TypeDef. */
    ETHRxRefclkPhase_TypeDef ETH_RxRefclkPhase;       /*!< Specifies the RX clock phase.
                                                           This parameter can be a value of @ref ETHRxRefclkPhase_TypeDef. */
    ETHPhyMode_TypeDef ETH_PhyMode;                   /*!< Specifies the PHY mode.
                                                           This parameter can be a value of @ref ETHPhyMode_TypeDef. */
    ETHMode_TypeDef ETH_Mode;                         /*!< Specifies the ethernet mode.
                                                           This parameter can be a value of @ref ETHMode_TypeDef. */
    ETHInterFrameGapTime_TypeDef ETH_InterFrameGapTime;   /*!< Specifies the interpacket gap.
                                                           This parameter can be a value of @ref ETHInterFrameGapTime_TypeDef. */
    uint8_t ETH_MacAddr[6];                           /*!< Specifies the MAC address.*/
    uint8_t ETH_ReceiveConfig;                        /*!< Specifies the RX receive config. */
    ETHRxJumboConfig_TypeDef ETH_RxJumboConfig;       /*!< Specifies the RX jumbo config.
                                                           This parameter can be a value of @ref ETHRxJumboConfig_TypeDef. */
    ETHTxThreshold_TypeDef ETH_TxThreshold;           /*!< Specifies the TX threshold.
                                                           This parameter can be a value of @ref ETHTxThreshold_TypeDef. */
    ETHRxThreshold_TypeDef ETH_RxThreshold;           /*!< Specifies the RX threshold.
                                                           This parameter can be a value of @ref ETHRxThreshold_TypeDef. */
    ETHTxTriggerLevel_TypeDef ETH_TxTriggerLevel;     /*!< Specifies the TX trigger level.
                                                           This parameter can be a value of @ref ETHTxTriggerLevel_TypeDef. */
    ETHRxTriggerLevel_TypeDef ETH_RxTriggerLevel;     /*!< Specifies the RX trigger level.
                                                           This parameter can be a value of @ref ETHRxTriggerLevel_TypeDef. */
    ETHPhyTxSetupTime_TypeDef ETH_PhyTxSetupTime;     /*!< Specifies the PHY TX set up time.
                                                           This parameter can be a value of @ref ETHPhyTxSetupTime_TypeDef. */
    ETHPhyRxSetupTime_TypeDef ETH_PhyRxSetupTime;     /*!< Specifies the PHY RX set up time.
                                                           This parameter can be a value of @ref ETHPhyRxSetupTime_TypeDef. */
    uint8_t ETH_TxDescNum;                            /*!< Specifies the TX descriptor number.
                                                           This parameter can be a value from 0 to 0xFF. */
    uint8_t ETH_RxDescNum;                            /*!< Specifies the RX descriptor number.
                                                           This parameter can be a value from 0 to 0xFF. */
    volatile ETHTxDesc_TypeDef *ETH_TxDesc;           /*!< Specifies the first TX descriptor address. */
    volatile ETHRxDesc_TypeDef *ETH_RxDesc;           /*!< Specifies the first RX descriptor address. */
    volatile uint8_t
    *ETH_TxPktBuf;                   /*!< Specifies the first TX packet buffer address. */
    volatile uint8_t
    *ETH_RxPktBuf;                   /*!< Specifies the first RX packet buffer address. */
    uint8_t ETH_TxDescCurrentNum;                     /*!< Specifies the current TX descriptor number. */
    uint8_t ETH_RxDescCurrentNum;                     /*!< Specifies the current RX descriptor number. */
    uint8_t ETH_RxFrameStartDescIdx;                  /*!< Specifies the start descriptor index of RX frame. */
    uint32_t ETH_RxFrameLen;                          /*!< Specifies the length of RX frame. */
    uint32_t ETH_RxSegmentCount;                      /*!< Specifies the segment count of RX frame. */
    uint16_t ETH_TxAllocBufSize;                      /*!< Specifies the alloc size of TX buffer. */
    uint16_t ETH_RxAllocBufSize;                      /*!< Specifies the alloc size of RX buffer. */
    uint16_t ETH_TxBufSize;                           /*!< Specifies the size of TX buffer. */
    uint16_t ETH_RxBufSize;                           /*!< Specifies the size of RX buffer. */
    ETHForceSpeed_Typedef ETH_ForceSpeed;             /*!< Specifies the force speed of ethernet.
                                                           This parameter can be a value of @ref ETHForceSpeed_Typedef. */
} ETH_InitTypeDef;

/**
 * \brief       Ethernet PHY operations structure.
 */
typedef struct
{
    bool (*ETH_ResetPHY)(void);                       /*!< Specifies ethernet reset PHY api. */
    bool (*ETH_WaitPHYLinkUp)(
        void);                                        /*!< Specifies ethernet wait PHY link up api.*/
    bool (*ETH_PHYConfig)(ETH_InitTypeDef
                          *ETH_InitStruct);     /*!< Specifies ethernet config PHY api.*/
    bool (*ETH_PHYLoopback)(ETH_InitTypeDef
                            *ETH_InitStruct);         /*!< Specifies ethernet PHY config loopback.*/
} ETHPHYOps_TypeDef;

/** End of group ETH_Exported_Types
  * @}
  */
/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup ETH_Exported_Functions Ethernet Exported Functions
 * @{
 */

/**
  * \brief  Init PHY operations.
  * \param[in]  phy_ops: PHY operations \ref ETHPHYOps_TypeDef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void PHY_RTL8201FRRegisterOps(void)
  * {
  *   ETHPHYOps_TypeDef phy_ops;
  *
  *   phy_ops.ETH_ResetPHY = PHY_RTL8201FRReset;
  *   phy_ops.ETH_WaitPHYLinkUp = PHY_RTL8201FRWaitLinkUp;
  *   phy_ops.ETH_PHYConfig = PHY_RTL8201FRConfig;
  *   phy_ops.ETH_PHYLoopback = PHY_RTL8201FRLoopback;
  *
  *   ETH_PHYOpsInit(&phy_ops);
  * }
  * \endcode
  */
void ETH_PHYOpsInit(ETHPHYOps_TypeDef *phy_ops);

/**
  * \brief  Write PHY register.
  * \param[in]  phy_addr: PHY address.
  * \param[in]  address: PHY's register address.
  * \param[in]  data: The data to be written to the above register address.
  * \return The result of the write operation.
  * \retval true: Write success.
  * \retval false: Write failed.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void PHY_Write(void)
  * {
  *   PHY_RTL8201FR_PAGE0_REG0_TypeDef page0_reg0 = {.d16 = 0};
  *   page0_reg0.b.reset = 1;
  *   ETH_WritePHYRegister(PHY_RTL8201FR_ADDR, PHY_RTL8201FR_PAGE0_REG0_CTL_ADDR, page0_reg0.d16);
  * }
  * \endcode
  */
bool ETH_WritePHYRegister(uint8_t phy_addr, uint8_t reg_address, uint16_t reg_data);

/**
  * \brief  Read PHY register.
  * \param[in]  phy_addr: PHY address.
  * \param[in]  address: PHY's register address.
  * \return The result of the read register data.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void PHY_Write(void)
  * {
  *   PHY_RTL8201FR_PAGE0_REG0_TypeDef page0_reg0 = {.d16 = 0};
  *   page0_reg0.d16 = ETH_ReadPHYRegister(PHY_RTL8201FR_ADDR, PHY_RTL8201FR_PAGE0_REG0_CTL_ADDR);
  * }
  * \endcode
  */
uint16_t ETH_ReadPHYRegister(uint8_t phy_addr, uint8_t reg_address);

/**
  * \brief  Set the TX/RX descriptor number.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  tx_desc_no: The specified TX descriptor number.
  * \param[in]  rx_desc_no: The specified RX descriptor number.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SetDescNum(&ETH_InitStruct, ETH_TX_DESC_NUM, ETH_RX_DESC_NUM);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_SetDescNum(ETH_InitTypeDef *ETH_InitStruct, uint8_t tx_desc_no,
                                      uint8_t rx_desc_no);

/**
  * \brief  Set the start address of TX/RX descriptor ring.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  tx_desc: The start address of TX descriptor ring.
  * \param[in]  rx_desc: The start address of RX descriptor ring.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SetDescAddr(&ETH_InitStruct, pTmpTxDesc, pTmpRxDesc);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_SetDescAddr(ETH_InitTypeDef *ETH_InitStruct, uint8_t *tx_desc,
                                       uint8_t *rx_desc);

/**
  * \brief  Set the start address of TX/RX packet buffer.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  tx_pkt_buf: The start address of TX packet buffer.
  * \param[in]  rx_pkt_buf: The start address of RX packet buffer.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SetPktBuf(&ETH_InitStruct, pTmpTxPktBuf, pTmpRxPktBuf);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_SetPktBuf(ETH_InitTypeDef *ETH_InitStruct, uint8_t *tx_pkt_buf,
                                     uint8_t *rx_pkt_buf);

/**
  * \brief  Set the ethernet MAC address.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  addr: The specified MAC address.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   uint8_t id[6] = {MAC_ADDR1, MAC_ADDR2, MAC_ADDR3, MAC_ADDR4, MAC_ADDR5, MAC_ADDR6};
  *   ETH_SetMacAddr(&ETH_InitStruct, id);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_SetMacAddr(ETH_InitTypeDef *ETH_InitStruct, uint8_t *addr);


/**
  * \brief  Get the ethernet MAC address.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[out]  addr: The buffer of MAC address.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   uint8_t id[6] = {0};
  *   ETH_GetMacAddr(&ETH_InitStruct, id);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_GetMacAddr(ETH_InitTypeDef *ETH_InitStruct, uint8_t *addr);

/**
  * \brief  Set buffer size.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  tx_alloc_buf_size: Allocated TX buffer size.
  * \param[in]  rx_alloc_buf_size: Allocated RX buffer size.
  * \param[in]  tx_buf_size: The TX buffer size that can be used actually.
  * \param[in]  rx_buf_size: The RX buffer size that can be used actually.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SetBufSize(&ETH_InitStruct, ETH_TX_ALLOC_BUF_SIZE, ETH_RX_ALLOC_BUF_SIZE, ETH_TX_BUF_SIZE,
  *                 ETH_RX_BUF_SIZE);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_SetBufSize(ETH_InitTypeDef *ETH_InitStruct, uint16_t tx_alloc_buf_size,
                                      uint16_t rx_alloc_buf_size, uint16_t tx_buf_size, uint16_t rx_buf_size);

/**
  * @brief  Init the pins of ethernet.
  * \note   The default settings for the pin member are shown in the following table:
  *         | Pin Name      | Function  |
  *         |:-------------:|:---------:|
  *         | P5_2          | TXD0      |
  *         | P5_1          | TXD1      |
  *         | P3_2          | CRS_DV    |
  *         | P3_3          | RX_ERR    |
  *         | P5_5          | RXD0      |
  *         | P5_4          | RXD1      |
  *         | P5_3          | REF_CLK   |
  *         | P5_0          | TX_EN     |
  *         | P1_1          | MDC       |
  *         | P1_0          | MDIO      |
  *
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_PinInit();
  * }
  * \endcode
  */
void ETH_PinInit(void);

/**
  * @brief  Init ETH clock.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_ClkInit();
  * }
  * \endcode
  */
void ETH_ClkInit(void);

/**
  * \brief  Initialize the ethernet MAC controller and PHY RTL8201FR.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \return ETHErrorStatus_Typedef: The status of ethernet. \ref ETHErrorStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_Init(&ETH_InitStruct);
  * }
  * \endcode
  */
ETHErrorStatus_Typedef ETH_Init(ETH_InitTypeDef *ETH_InitStruct);

/**
  * \brief  Initialize \ref ETH_InitTypeDef.
  *
  * \note   The default settings for the QDEC_InitStruct member are shown in the following table:
  *         | QDEC_InitStruct Member    | Default Value                                                                             |
  *         |:-------------------------:|:-----------------------------------------------------------------------------------------:|
  *         | ETH_InterFrameGapTime     | \ref ETH_IFG_3                                                                            |
  *         | ETH_Mode                  | \ref ETH_NORMAL_MODE                                                                      |
  *         | ETH_PhyMode               | \ref ETH_PhyMode                                                                          |
  *         | ETH_PhyRxSetupTime        | \ref ETH_PHY_RX_SETUP_TIME_16NS                                                           |
  *         | ETH_PhyTxSetupTime        | \ref ETH_PHY_TX_SETUP_TIME_6NS                                                            |
  *         | ETH_ReceiveConfig         | \ref ETH_RX_CONFIG_AAP \ref ETH_RX_CONFIG_APM \ref ETH_RX_CONFIG_AM \ref ETH_RX_CONFIG_AB |
  *         | ETH_RxJumboConfig         | \ref ETH_RX_JUMBO_ENABLE                                                                  |
  *         | ETH_RxRefclkPhase         | \ref ETH_RX_SAMPLE_ON_FALLING_EDGE                                                        |
  *         | ETH_TxRefclkPhase         | \ref ETH_TX_CHANGE_ON_FALLING_EDGE                                                        |
  *         | ETH_RxThreshold           | \ref ETH_RX_THRESHOLD_256B                                                                |
  *         | ETH_TxThreshold           | \ref ETH_TX_THRESHOLD_256B                                                                |
  *         | ETH_RxTriggerLevel        | \ref ETH_RX_TRIGGER_LEVEL_1_PKT                                                           |
  *         | ETH_TxTriggerLevel        | \ref ETH_TX_TRIGGER_LEVEL_1_PKT                                                           |
  *         | ETH_RxDescNum             | 8                                                                                         |
  *         | ETH_TxDescNum             | 8                                                                                         |
  *         | ETH_RxDesc                | NULL                                                                                      |
  *         | ETH_TxDesc                | NULL                                                                                      |
  *         | ETH_RxPktBuf              | NULL                                                                                      |
  *         | ETH_TxPktBuf              | NULL                                                                                      |
  *         | ETH_RxDescCurrentNum      | 0                                                                                         |
  *         | ETH_TxDescCurrentNum      | 0                                                                                         |
  *         | ETH_RxFrameStartDescIdx   | 0                                                                                         |
  *         | ETH_RxFrameLen            | 0                                                                                         |
  *         | ETH_RxSegmentCount        | 0                                                                                         |
  *         | ETH_TxAllocBufSize        | 1600                                                                                      |
  *         | ETH_RxAllocBufSize        | 1600                                                                                      |
  *         | ETH_TxBufSize             | 1524                                                                                      |
  *         | ETH_RxBufSize             | 1524                                                                                      |
  *         | ETH_ForceSpeed            | \ref ETH_LOOPBACK_FORCE_SPEED_100M                                                        |
  *
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_StructInit(&ETH_InitStruct);
  *   ETH_InitStruct.ETH_PhyMode = ETH_PHY_LOOPBACK_MODE;
  *   ETH_InitStruct.ETH_PhyRxSetupTime = ETH_PHY_RX_SETUP_TIME_16NS;
  *   ETH_InitStruct.ETH_PhyTxSetupTime = ETH_PHY_TX_SETUP_TIME_6NS;
  *
  *   PHY_RTL8201FRRegisterOps();
  *   ETH_Init(&ETH_InitStruct);
  * }
  * \endcode
  */
void ETH_StructInit(ETH_InitTypeDef *ETH_InitStruct);

/**
  * \brief  Get ethernet link speed.
  * \return ETHLinkSpeed_Typedef: ethernet link speed. \ref ETHLinkSpeed_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETHLinkSpeed_Typedef speed = ETH_GetLinkSpeed();
  * }
  * \endcode
  */
ETHLinkSpeed_Typedef ETH_GetLinkSpeed(void);

/**
  * \brief  Get ethernet duplex mode.
  * \return ETHDuplexMode_Typedef: ethernet duplex mode. \ref ETHDuplexMode_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETHDuplexMode_Typedef mode = ETH_GetDuplexMode();
  * }
  * \endcode
  */
ETHDuplexMode_Typedef ETH_GetDuplexMode(void);

/**
  * \brief  Enable ethernet RX.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_EnableRx();
  * }
  * \endcode
  */
void ETH_EnableRx(void);

/**
  * \brief  Close the clock of ethernet and disable intterrupt.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_DeInit();
  * }
  * \endcode
  */
void ETH_DeInit(void);

/**
  * \brief  To send frame.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  FrameLength: The length of data to be sent.
  * \return ETHSendFrameStatus_Typedef: The result of the operation. \ref ETHSendFrameStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SendFrame(&ETH_InitStruct, BUFFER_SIZE);
  * }
  * \endcode
  */
ETHSendFrameStatus_Typedef ETH_SendFrame(ETH_InitTypeDef *ETH_InitStruct, uint32_t FrameLength);

/**
  * \brief  Copy data to ethernet TX buffer.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  send_data: The address of data to be sent, must be continuous.
  * \param[in]  send_len: The len of data to be sent.
  * \return ETHSendFrameStatus_Typedef: The result of the operation. \ref ETHSendFrameStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_CopyDataToTxBuffer(&ETH_InitStruct, send_pdata, BUFFER_SIZE);
  * }
  * \endcode
  */
ETHSendFrameStatus_Typedef ETH_CopyDataToTxBuffer(ETH_InitTypeDef *ETH_InitStruct,
                                                  uint8_t *send_data, uint32_t send_len);

/**
  * \brief  Enable 1st Priority DMA Ethernet Transmit.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_Enable1stPriorityTxDMAETH();
  * }
  * \endcode
  */
void ETH_Enable1stPriorityTxDMAETH(void);

/**
  * \brief  Check TX descriptor is available.
  * \return The result of the TX descriptor.
  * \retval true: TX descriptor is available.
  * \retval false: TX descriptor is not available.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   bool result = ETH_IsTxDescAvailable(ETH_InitStruct->ETH_TxDesc[tx_serach_idx].dw1);
  * }
  * \endcode
  */
bool ETH_IsTxDescAvailable(uint32_t dw1);

/**
  * \brief  Check RX descriptor is available.
  * \return The result of the RX descriptor.
  * \retval true: RX descriptor is available.
  * \retval false: RX descriptor is not available.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   bool result = ETH_IsRxDescAvailable(ETH_InitStruct->ETH_RxDesc[rx_desc_current_num].dw1);
  * }
  * \endcode
  */
bool ETH_IsRxDescAvailable(uint32_t dw1);

/**
  * \brief  Config ethernet interrupt.
  * \param[in]  ETH_INT: The interrupt of ethernet. \ref ETHINT_TypeDef.
  *             This parameter parameter can be one of the following values:
  *             -  ETH_INT_ROK: Receive ok.
  *             -  ETH_INT_CNT_WRAP: TX/RX counter wrap.
  *             -  ETH_INT_RER_RUNT: RX error caused by runt error characterized by the frame length in bytes being less than 64 bytes.
  *             -  ETH_INT_RER_OVF: RX fifo overflow.
  *             -  ETH_INT_RDU: RX descriptor unavailable for ring1.
  *             -  ETH_INT_TOK: Transmit ok.
  *             -  ETH_INT_TER: Transmit error.
  *             -  ETH_INT_LINK_CHANGE: Link change.
  *             -  ETH_INT_TDU: TX descriptor unavailable.
  *             -  ETH_INT_SW_INT: Software interrupt pending.
  *             -  ETH_INT_RDU2: RX descriptor unavailable for ring2.
  *             -  ETH_INT_RDU3: RX descriptor unavailable for ring3.
  *             -  ETH_INT_RDU4: RX descriptor unavailable for ring4.
  *             -  ETH_INT_RDU5: RX descriptor unavailable for ring5.
  *             -  ETH_INT_RDU6: RX descriptor unavailable for ring6.
  * \param[in]  newState: Disable or enable ethernet interrupt.
  *            This parameter can be one of the following values:
  *            - ENABLE: Enable the specified ethernet interrupt.
  *            - DISABLE: Disable the specified ethernet interrupt.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_INTConfig(ETH_INT_TOK, ENABLE);
  * }
  * \endcode
  */
void ETH_INTConfig(ETHINT_TypeDef ETH_INT, FunctionalState newState);

/**
  * \brief  Check ethernet interrupt is enable.
  * \param[in]  ETH_INT: The interrupt of ethernet. \ref ETHINT_TypeDef.
  *             This parameter parameter can be one of the following values:
  *             -  ETH_INT_ROK: Receive ok.
  *             -  ETH_INT_CNT_WRAP: TX/RX counter wrap.
  *             -  ETH_INT_RER_RUNT: RX error caused by runt error characterized by the frame length in bytes being less than 64 bytes.
  *             -  ETH_INT_RER_OVF: RX fifo overflow.
  *             -  ETH_INT_RDU: RX descriptor unavailable for ring1.
  *             -  ETH_INT_TOK: Transmit ok.
  *             -  ETH_INT_TER: Transmit error.
  *             -  ETH_INT_LINK_CHANGE: Link change.
  *             -  ETH_INT_TDU: TX descriptor unavailable.
  *             -  ETH_INT_SW_INT: Software interrupt pending.
  *             -  ETH_INT_RDU2: RX descriptor unavailable for ring2.
  *             -  ETH_INT_RDU3: RX descriptor unavailable for ring3.
  *             -  ETH_INT_RDU4: RX descriptor unavailable for ring4.
  *             -  ETH_INT_RDU5: RX descriptor unavailable for ring5.
  *             -  ETH_INT_RDU6: RX descriptor unavailable for ring6.
  *
  * \return The result of the interrupt.
  * \retval SET: The interrupt is enable.
  * \retval RESET: The interrupt is disable.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_IsINTEnable(ETH_INT_TOK);
  * }
  * \endcode
  */
ITStatus ETH_IsINTEnable(ETHINT_TypeDef ETH_INT);

/**
  * \brief  Get ethernet interrupt status.
  * \param[in]  ETH_INT: The interrupt of ethernet. \ref ETHINT_TypeDef.
  *             This parameter parameter can be one of the following values:
  *             -  ETH_INT_ROK: Receive ok.
  *             -  ETH_INT_CNT_WRAP: TX/RX counter wrap.
  *             -  ETH_INT_RER_RUNT: RX error caused by runt error characterized by the frame length in bytes being less than 64 bytes.
  *             -  ETH_INT_RER_OVF: RX fifo overflow.
  *             -  ETH_INT_RDU: RX descriptor unavailable for ring1.
  *             -  ETH_INT_TOK: Transmit ok.
  *             -  ETH_INT_TER: Transmit error.
  *             -  ETH_INT_LINK_CHANGE: Link change.
  *             -  ETH_INT_TDU: TX descriptor unavailable.
  *             -  ETH_INT_SW_INT: Software interrupt pending.
  *             -  ETH_INT_RDU2: RX descriptor unavailable for ring2.
  *             -  ETH_INT_RDU3: RX descriptor unavailable for ring3.
  *             -  ETH_INT_RDU4: RX descriptor unavailable for ring4.
  *             -  ETH_INT_RDU5: RX descriptor unavailable for ring5.
  *             -  ETH_INT_RDU6: RX descriptor unavailable for ring6.
  *
  * \return The result of the interrupt.
  * \retval SET: The interrupt is pending.
  * \retval RESET: The interrupt is not pending.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_GetINTStatus(ETH_INT_TOK);
  * }
  * \endcode
  */
ITStatus ETH_GetINTStatus(ETHINT_TypeDef ETH_INT);

/**
  * \brief  Clear ethernet interrupt status.
  * \param[in]  ETH_INT: The interrupt of ethernet. \ref ETHINT_TypeDef.
  *             This parameter parameter can be one of the following values:
  *             -  ETH_INT_ROK: Receive ok.
  *             -  ETH_INT_CNT_WRAP: TX/RX counter wrap.
  *             -  ETH_INT_RER_RUNT: RX error caused by runt error characterized by the frame length in bytes being less than 64 bytes.
  *             -  ETH_INT_RER_OVF: RX fifo overflow.
  *             -  ETH_INT_RDU: RX descriptor unavailable for ring1.
  *             -  ETH_INT_TOK: Transmit ok.
  *             -  ETH_INT_TER: Transmit error.
  *             -  ETH_INT_LINK_CHANGE: Link change.
  *             -  ETH_INT_TDU: TX descriptor unavailable.
  *             -  ETH_INT_SW_INT: Software interrupt pending.
  *             -  ETH_INT_RDU2: RX descriptor unavailable for ring2.
  *             -  ETH_INT_RDU3: RX descriptor unavailable for ring3.
  *             -  ETH_INT_RDU4: RX descriptor unavailable for ring4.
  *             -  ETH_INT_RDU5: RX descriptor unavailable for ring5.
  *             -  ETH_INT_RDU6: RX descriptor unavailable for ring6.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_ClearINTStatus(ETH_INT_TOK);
  * }
  * \endcode
  */
void ETH_ClearINTStatus(ETHINT_TypeDef ETH_INT);

/**
  * \brief  Get ethernet link status.
  * \return ETHLinkStatus_Typedef: Ethernet link status. \ref ETHLinkStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_GetLinkStatus();
  * }
  * \endcode
  */
ETHLinkStatus_Typedef ETH_GetLinkStatus(void);

/**
  * \brief  Set RX descriptor back to ethernet.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[in]  rx_desc_index: RX descriptor index.
  * \param[in]  buffer_size: RX descriptor buffer size.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_SetRxDescBackToETH(ETH_InitStruct, rx_serach_idx, ETH_InitStruct->ETH_RxBufSize);
  * }
  * \endcode
  */
void ETH_SetRxDescBackToETH(ETH_InitTypeDef *ETH_InitStruct, uint8_t rx_desc_index,
                            uint16_t buffer_size);

/**
  * \brief  To receive frame.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \return ETHReceiveFrameStatus_Typedef: Receive frame result. \ref ETHReceiveFrameStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_ReceiveFrame(&ETH_InitStruct);
  * }
  * \endcode
  */
ETHReceiveFrameStatus_Typedef ETH_ReceiveFrame(ETH_InitTypeDef *ETH_InitStruct);

/**
  * \brief  Copy ethernet RX buffer to data.
  * \param[in]  ETH_InitStruct: The pointer to \ref ETH_InitTypeDef.
  * \param[out]  recv_data: The address of data to be received, must be continuous.
  * \param[out]  recv_len: The len of data to be received.
  * \param[in]  data_size: The len of recv_data, must be large enough to receive data.
  * \return ETHReceiveFrameStatus_Typedef: Copy frame result. \ref ETHReceiveFrameStatus_Typedef.
  *
  * <b>Example usage</b>
  * \code{.c}
  *
  * void ETH_Init(void)
  * {
  *   ETH_CopyRxBufferToData(&ETH_InitStruct, recv_pdata, &len,
  *                                 BUFFER_SIZE);
  * }
  * \endcode
  */
ETHReceiveFrameStatus_Typedef ETH_CopyRxBufferToData(ETH_InitTypeDef *ETH_InitStruct,
                                                     uint8_t *recv_data, uint32_t *recv_len, uint32_t data_size);

/** \} */ /* End of group ETH_Exported_Functions */
/** \} */ /* End of group 87x3g_ETHERNET */

#ifdef  __cplusplus
}
#endif

#endif /* RTL_ETHERNET_H */


