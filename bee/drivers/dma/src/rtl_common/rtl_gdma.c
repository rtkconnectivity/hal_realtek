/**
*********************************************************************************************************
*               Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* \file     rtl_gdma.c
* \brief    This file provides all the DMA firmware functions.
* \details
* \author   Bert
* \date     2023-10-17
* \version  v1.0
*********************************************************************************************************
*/

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_gdma.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                          Private Functions
 *============================================================================*/
extern GDMA_ChannelTypeDef *GDMA_GetGDMAChannelx(uint8_t GDMA_ChannelNum);
extern uint8_t GDMA_GetHandshakeNum(GDMA_ChannelTypeDef *GDMA_Channelx, uint8_t handshake);
extern uint8_t GDMA_GetGDMAChannelNum(uint8_t GDMA_ChannelNum);
extern GDMA_TypeDef *GDMA_GetGDMAxByCh(uint8_t GDMA_ChannelNum);
extern GDMA_TypeDef *GDMA_GetGDMAx(GDMA_ChannelTypeDef *GDMA_Channelx);
extern bool GDMA_IsValidHandshake(uint8_t handshake);

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Deinitializes the GDMA registers to their default reset values.
  * \param  None
  * \return None
  */
void GDMA_DeInit(void)
{
    /* Disable GDMA clock */
#if (CHIP_GDMA_NUM == 1)
    RCC_PeriphClockCmd(APBPeriph_GDMA, APBPeriph_GDMA_CLOCK, DISABLE);
#elif (CHIP_GDMA_NUM == 2)
    RCC_PeriphClockCmd(APBPeriph_GDMA1, APBPeriph_GDMA1_CLOCK, DISABLE);
    RCC_PeriphClockCmd(APBPeriph_GDMA2, APBPeriph_GDMA2_CLOCK, DISABLE);
#endif
}

/**
  * \brief  Initializes the GDMA Channelx according to the specified
  *         parameters in the GDMA_InitStruct.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
  * \param  GDMA_InitStruct: pointer to a GDMA_InitTypeDef structure that
  *         contains the configuration information for the specified DMA Channel.
  * \return None.
  */
void GDMA_Init(GDMA_ChannelTypeDef *GDMA_Channelx, GDMA_InitTypeDef *GDMA_InitStruct)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));
    assert_param(IS_GDMAx_ChannelNum(GDMA_InitStruct->GDMA_ChannelNum));
    assert_param(IS_GDMA_DIR(GDMA_InitStruct->GDMA_DIR));
    assert_param(IS_GDMA_SourceInc(GDMA_InitStruct->GDMA_SourceInc));
    assert_param(IS_GDMA_DestinationInc(GDMA_InitStruct->GDMA_DestinationInc));
    assert_param(IS_GDMA_DATA_SIZE(GDMA_InitStruct->GDMA_SourceDataSize));
    assert_param(IS_GDMA_DATA_SIZE(GDMA_InitStruct->GDMA_DestinationDataSize));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAx(GDMA_Channelx);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_InitStruct->GDMA_ChannelNum);
    uint8_t temp_hs_src = GDMA_GetHandshakeNum(GDMA_Channelx, GDMA_InitStruct->GDMA_SourceHandshake);
    uint8_t temp_hs_dst = GDMA_GetHandshakeNum(GDMA_Channelx, GDMA_InitStruct->GDMA_DestHandshake);
    uint32_t temp_bit = 0;

    /* ---------------- Configure source and destination address of GDMA ---------------- */
    /* Program SARx register to set source address */
    GDMA_Channelx->GDMA_SARx = GDMA_InitStruct->GDMA_SourceAddr;
    /* Program DARx register to set destination address */
    GDMA_Channelx->GDMA_DARx = GDMA_InitStruct->GDMA_DestinationAddr;

    /* Enable GDMA in DmaCfgReg*/
    GDMAx->GDMA_DmaCfgReg = 0x01;

    /* Read ChEnReg to check channel is busy or not */
    temp_bit = 0;
    if (channel_num < 8)
    {
        temp_bit = BIT(channel_num);
    }
    else
    {
        temp_bit = BIT(channel_num + 16 - 8);
    }
    if (GDMAx->GDMA_ChEnReg & temp_bit)
    {
        //channel is be used
        //error handle code
        //while (1);
    }

    /* ---------------- GDMA Configuration ---------------- */
    /* Clear pending interrupts of corresponding GDMA channel */
    temp_bit = BIT(channel_num);
    GDMAx->GDMA_ClearTfr |= temp_bit;
    GDMAx->GDMA_ClearBlock |= temp_bit;
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
    GDMAx->GDMA_ClearHalfBlock |= temp_bit;
#endif
    GDMAx->GDMA_ClearErr |= temp_bit;
    GDMAx->GDMA_ClearErrNonSecure |= temp_bit;

    /* Mask pending interrupts of corresponding GDMA channel */
    temp_bit = 0;
    if (channel_num < 8)
    {
        temp_bit = BIT(channel_num + 8);
    }
    else
    {
        temp_bit = BIT(channel_num + 24 - 8);
    }
    /* Mask write enable */
    GDMAx->GDMA_MaskTfr = temp_bit;
    GDMAx->GDMA_MaskBlock = temp_bit;
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
    GDMAx->GDMA_MaskHalfBlock = temp_bit;
#endif
    GDMAx->GDMA_MaskErr = temp_bit;
    GDMAx->GDMA_MaskErrNonSecure = temp_bit;

    /* ---------------- Configure CTL register ---------------- */
    /* Config low 32 bits of CTL register  */
    GDMA_CTL_LOWx_TypeDef gdma_0x18 = {.d32 = GDMA_Channelx->GDMA_CTL_LOWx};
    gdma_0x18.b.INT_EN = ENABLE;
    gdma_0x18.b.DST_TR_WIDTH = GDMA_InitStruct->GDMA_DestinationDataSize;
    gdma_0x18.b.SRC_TR_WIDTH = GDMA_InitStruct->GDMA_SourceDataSize;
    gdma_0x18.b.DINC = GDMA_InitStruct->GDMA_DestinationInc;
    gdma_0x18.b.SINC = GDMA_InitStruct->GDMA_SourceInc;
    gdma_0x18.b.DEST_MSIZE = GDMA_InitStruct->GDMA_DestinationMsize;
    gdma_0x18.b.SRC_MSIZE = GDMA_InitStruct->GDMA_SourceMsize;
    gdma_0x18.b.TT_FC = GDMA_InitStruct->GDMA_DIR;
    GDMA_Channelx->GDMA_CTL_LOWx = gdma_0x18.d32;

    /* Config high 32 bits of CTL register */
    GDMA_Channelx->GDMA_CTL_HIGHx = GDMA_InitStruct->GDMA_BufferSize;

    /* ---------------- Configure CFG register ---------------- */
    GDMA_CFG_LOWx_TypeDef gdma_0x40 = {.d32 = GDMA_Channelx->GDMA_CFG_LOWx};
    switch (GDMA_InitStruct->GDMA_DIR)
    {
    case GDMA_DIR_MemoryToMemory:
        gdma_0x40.b.HS_SEL_DST = 0x1;
        gdma_0x40.b.HS_SEL_SRC = 0x1;
        break;
    case GDMA_DIR_MemoryToPeripheral:
        gdma_0x40.b.HS_SEL_DST = 0x0;
        gdma_0x40.b.HS_SEL_SRC = 0x1;
        break;
    case GDMA_DIR_PeripheralToMemory:
        gdma_0x40.b.HS_SEL_DST = 0x1;
        gdma_0x40.b.HS_SEL_SRC = 0x0;
        break;
    case GDMA_DIR_PeripheralToPeripheral:
        gdma_0x40.b.HS_SEL_DST = 0x0;
        gdma_0x40.b.HS_SEL_SRC = 0x0;
        break;
    default:
        gdma_0x40.b.HS_SEL_DST = 0x0;
        gdma_0x40.b.HS_SEL_SRC = 0x0;
        break;
    }
    GDMA_Channelx->GDMA_CFG_LOWx = gdma_0x40.d32;

    /* Set for secure mode */
    GDMA_CFG_HIGHx_TypeDef gdma_0x44 = {.d32 = GDMA_Channelx->GDMA_CFG_HIGHx};
    if (GDMA_InitStruct->GDMA_Secure_En == 1)
    {
        gdma_0x44.b.PROTCTL = 0x0;
    }
    GDMA_Channelx->GDMA_CFG_HIGHx = gdma_0x44.d32;

    /* Config multi-block mode */
    if (GDMA_InitStruct->GDMA_Multi_Block_En == 1)
    {
        /* Clear automatic source/destination reload */
        gdma_0x40.b.RELOAD_SRC = 0x0;
        gdma_0x40.b.RELOAD_DST = 0x0;
        GDMA_Channelx->GDMA_CFG_LOWx = gdma_0x40.d32;
        /* Clear LLI for source/destination */
        gdma_0x18.b.LLP_DST_EN = 0x0;
        gdma_0x18.b.LLP_SRC_EN = 0x0;
        GDMA_Channelx->GDMA_CTL_LOWx = gdma_0x18.d32;

        if (GDMA_InitStruct->GDMA_Multi_Block_Mode & LLP_SELECTED_BIT)
        {
            GDMA_Channelx->GDMA_LLPx = GDMA_InitStruct->GDMA_Multi_Block_Struct;
            gdma_0x18.b.LLP_DST_EN = (GDMA_InitStruct->GDMA_Multi_Block_Mode & BIT27) >> 27;
            gdma_0x18.b.LLP_SRC_EN = (GDMA_InitStruct->GDMA_Multi_Block_Mode & BIT28) >> 28;
            GDMA_Channelx->GDMA_CTL_LOWx = gdma_0x18.d32;
        }
        gdma_0x40.b.RELOAD_SRC = (GDMA_InitStruct->GDMA_Multi_Block_Mode & BIT30) >> 30;
        gdma_0x40.b.RELOAD_DST = (GDMA_InitStruct->GDMA_Multi_Block_Mode & BIT31) >> 31;
        GDMA_Channelx->GDMA_CFG_LOWx = gdma_0x40.d32;
    }

    /* ---------------- Set handshake ---------------- */
    /* Configure peripheral parameters and configure source or destination hardware handshaking interface */
    if (GDMA_IsValidHandshake(temp_hs_src) == true)
    {
        gdma_0x44.b.SRC_PER = temp_hs_src & 0x0F;
        gdma_0x44.b.ExtendedSRC_PER1 = (temp_hs_src & 0x10) >> 4;
        gdma_0x44.b.ExtendedSRC_PER2 = (temp_hs_src & 0x20) >> 5;
        gdma_0x44.b.ExtendedSRC_PER3 = (temp_hs_src & 0x40) >> 6;

        gdma_0x44.b.DEST_PER = temp_hs_dst & 0x0F;
        gdma_0x44.b.ExtendedDEST_PER1 = (temp_hs_dst & 0x10) >> 4;
        gdma_0x44.b.ExtendedDEST_PER2 = (temp_hs_dst & 0x20) >> 5;
        gdma_0x44.b.ExtendedDEST_PER3 = (temp_hs_dst & 0x40) >> 6;

        GDMA_Channelx->GDMA_CFG_HIGHx = gdma_0x44.d32;
    }

    /* Set DMA channel priority level */
    gdma_0x40.b.CH_PRIOR = GDMA_InitStruct->GDMA_ChannelPriority;
    GDMA_Channelx->GDMA_CFG_LOWx = gdma_0x40.d32;

    /* Enable FIFO mode and Flow control mode, fixed FIFO mode enable */

#if (GDMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    /* ---------------- Configure scatter and gather ---------------- */
    /* Set for gather */
#if (GDMA_SUPPORT_GATHER_SCATTER_ALL_CHANNEL == 1)
    if (GDMA_InitStruct->GDMA_Gather_En == 1)
#elif (GDMA_SUPPORT_GATHER_SCATTER_CHANNEL_2345 == 1)
    if (GDMA_InitStruct->GDMA_Gather_En == 1 &&
        ((GDMA_Channelx == GDMA_Channel2) || (GDMA_Channelx == GDMA_Channel3) ||
         (GDMA_Channelx == GDMA_Channel4) || (GDMA_Channelx == GDMA_Channel5)))
#else
    if ((GDMA_InitStruct->GDMA_Gather_En == 1) && (GDMAx == GDMA2))
#endif
    {
        gdma_0x18.b.SRC_GATHER_EN = 0x1;
        GDMA_Channelx->GDMA_CTL_LOWx = gdma_0x18.d32;

        GDMA_SGR_LOW_t gdma_0x48 = {.d32 = GDMA_Channelx->GDMA_SGR_LOW};
        gdma_0x48.b.SGI = GDMA_InitStruct->GDMA_GatherInterval & 0xFFFFF;
        gdma_0x48.b.SGC = GDMA_InitStruct->GDMA_GatherCount & 0xFFF;
        GDMA_Channelx->GDMA_SGR_LOW = gdma_0x48.d32;

        GDMA_SGR_HIGH_t gdma_0x4c = {.d32 = GDMA_Channelx->GDMA_SGR_HIGH};
        gdma_0x4c.b.SGSN = GDMA_InitStruct->GDMA_GatherCircularStreamingNum;
        GDMA_Channelx->GDMA_SGR_HIGH = gdma_0x4c.d32;
    }
    /* Set for scatter */
#if (GDMA_SUPPORT_GATHER_SCATTER_ALL_CHANNEL == 1)
    if (GDMA_InitStruct->GDMA_Scatter_En == 1)
#elif (GDMA_SUPPORT_GATHER_SCATTER_CHANNEL_2345 == 1)
    if (GDMA_InitStruct->GDMA_Scatter_En == 1 &&
        ((GDMA_Channelx == GDMA_Channel2) || (GDMA_Channelx == GDMA_Channel3) ||
         (GDMA_Channelx == GDMA_Channel4) || (GDMA_Channelx == GDMA_Channel5)))
#else
    if ((GDMA_InitStruct->GDMA_Scatter_En == 1) && (GDMAx == GDMA2))
#endif
    {
        gdma_0x18.b.DST_SCATTER_EN = 0x1;
        GDMA_Channelx->GDMA_CTL_LOWx = gdma_0x18.d32;

        GDMA_DSR_LOW_t gdma_0x50 = {.d32 = GDMA_Channelx->GDMA_DSR_LOW};
        gdma_0x50.b.DSI = GDMA_InitStruct->GDMA_ScatterInterval & 0xFFFFF;
        gdma_0x50.b.DSC = GDMA_InitStruct->GDMA_ScatterCount & 0xFFF;
        GDMA_Channelx->GDMA_DSR_LOW = gdma_0x50.d32;

        GDMA_DSR_HIGH_t gdma_0x54 = {.d32 = GDMA_Channelx->GDMA_DSR_HIGH};
        gdma_0x54.b.DSSN = GDMA_InitStruct->GDMA_ScatterCircularStreamingNum;
        GDMA_Channelx->GDMA_DSR_HIGH = gdma_0x54.d32;
    }
#endif

    /* Clear pending interrupts of corresponding GDMA channel */
    temp_bit = BIT(channel_num);
    GDMAx->GDMA_ClearTfr |= temp_bit;
    GDMAx->GDMA_ClearBlock |= temp_bit;
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
    GDMAx->GDMA_ClearHalfBlock |= temp_bit;
#endif
    GDMAx->GDMA_ClearErr |= temp_bit;
    GDMAx->GDMA_ClearErrNonSecure |= temp_bit;
}

/**
  * \brief  Fills each GDMA_InitStruct member with its default value.
  * \param  GDMA_InitStruct: pointer to a GDMA_InitTypeDef structure which will
  *         be initialized.
  * \return None.
  */
void GDMA_StructInit(GDMA_InitTypeDef *GDMA_InitStruct)
{
    /*-------------- Reset DMA init structure parameters values ------------------*/
    GDMA_InitStruct->GDMA_ChannelNum            = 0;
    GDMA_InitStruct->GDMA_DIR                   = GDMA_DIR_PeripheralToMemory;
    GDMA_InitStruct->GDMA_BufferSize            = 200;
    GDMA_InitStruct->GDMA_SourceInc             = DMA_SourceInc_Fix;
    GDMA_InitStruct->GDMA_DestinationInc        = DMA_DestinationInc_Inc;
    GDMA_InitStruct->GDMA_SourceDataSize        = GDMA_DataSize_Byte;
    GDMA_InitStruct->GDMA_DestinationDataSize   = GDMA_DataSize_Byte;
    GDMA_InitStruct->GDMA_SourceMsize           = GDMA_Msize_1;
    GDMA_InitStruct->GDMA_DestinationMsize      = GDMA_Msize_1;
    GDMA_InitStruct->GDMA_SourceAddr            = 0;
    GDMA_InitStruct->GDMA_DestinationAddr       = 0;
    GDMA_InitStruct->GDMA_SourceHandshake       = 0;
    GDMA_InitStruct->GDMA_DestHandshake         = 0;
    GDMA_InitStruct->GDMA_ChannelPriority       = 0;

    GDMA_InitStruct->GDMA_Multi_Block_En        = DISABLE;
    GDMA_InitStruct->GDMA_Multi_Block_Mode      = LLI_TRANSFER;
    GDMA_InitStruct->GDMA_Multi_Block_Struct    = 0;

#if (GDMA_SUPPORT_GATHER_SCATTER_FUNCTION == 1)
    GDMA_InitStruct->GDMA_Gather_En             = DISABLE;
    GDMA_InitStruct->GDMA_GatherCount           = 0;
    GDMA_InitStruct->GDMA_GatherInterval        = 0;
    GDMA_InitStruct->GDMA_Scatter_En            = DISABLE;
    GDMA_InitStruct->GDMA_ScatterCount          = 0;
    GDMA_InitStruct->GDMA_ScatterInterval       = 0;
    GDMA_InitStruct->GDMA_GatherCircularStreamingNum = 0;
    GDMA_InitStruct->GDMA_ScatterCircularStreamingNum = 0;
#endif

    GDMA_InitStruct->GDMA_Secure_En             = ENABLE;
}

/**
  * \brief  Enables or disables the specified GDMA Channelx.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  NewState: new state of the DMA Channelx.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void GDMA_Cmd(uint8_t GDMA_ChannelNum, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMA_ChannelNum));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    uint8_t bit_need_set_times = 10;
    uint8_t bit_need_check_times = 50;
    uint8_t timeout = bit_need_check_times ;
    uint8_t bit_set_time = 0;

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);
    GDMA_ChannelTypeDef *GDMA_Channelx = GDMA_GetGDMAChannelx(GDMA_ChannelNum);

    if (NewState == ENABLE)
    {
        /* Enable the selected DMA Channel */
#if (CHIP_GDMA_CHANNEL_NUM == 27)
        if (GDMA_ChannelNum < GDMA2_CH_NUM8)
#else
        if (channel_num < 8)
#endif
        {
            GDMAx->GDMA_ChEnReg |= BIT(channel_num) | BIT(channel_num + 8);
        }
        else
        {
            GDMAx->GDMA_ChEnReg |= BIT(channel_num + 16 - 8) | BIT(channel_num + 24 - 8);
        }
    }
    else if (NewState == DISABLE)
    {
        /* Disable the selected DMA Channel */
#if (CHIP_GDMA_CHANNEL_NUM == 27)
        if (GDMA_ChannelNum < GDMA2_CH_NUM8)
#else
        if (channel_num < 8)
#endif
        {
            /*Gdma transfer not finished */
            if (GDMAx->GDMA_ChEnReg & BIT(channel_num))
            {
                /* suspend gdma channel */
                GDMA_Channelx->GDMA_CFG_LOWx |= GDMA_SUSPEND_TRANSMISSSION;
            }
            /* Polling fifo empty */
            while ((GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET) && --timeout);

            /*cfg bit0 not set */
            if (GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET)
            {
                timeout = bit_need_check_times;
                /* Polling cfg[1:2] 10 times set in 100timer check */
                while (--timeout)
                {
                    if ((GDMA_Channelx->GDMA_CFG_LOWx & BIT1) && (GDMA_Channelx->GDMA_CFG_LOWx & BIT2))
                    {
                        bit_set_time++;
                        if (bit_set_time >= bit_need_set_times)
                        {
                            break;
                        }
                    }
                }
            }
            /* Disable the selected DMAy Channelx */
            GDMAx->GDMA_ChEnReg = BIT(channel_num + 8);
        }
        else
        {
            /*gdma transfor not finished */
            if (GDMAx->GDMA_ChEnReg & BIT(channel_num + 16 - 8))
            {
                /* suspend gdma channel */
                GDMA_Channelx->GDMA_CFG_LOWx |= GDMA_SUSPEND_TRANSMISSSION;
            }
            /* Polling fifo empty */
            while ((GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET) && --timeout);

            /*cfg bit0 not set */
            if (GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET)
            {
                timeout = bit_need_check_times;
                /*polling cfg[1:2] 10 times set in 100timer check */
                while (--timeout)
                {
                    if ((GDMA_Channelx->GDMA_CFG_LOWx & BIT1) && (GDMA_Channelx->GDMA_CFG_LOWx & BIT2))
                    {
                        bit_set_time++;
                        if (bit_set_time >= bit_need_set_times)
                        {
                            break;
                        }
                    }
                }
            }
            /* Disable the selected DMAy Channelx */
            GDMAx->GDMA_ChEnReg = BIT(channel_num + 24 - 8);
        }
        /* unsuspend dma channel */
        GDMA_Channelx->GDMA_CFG_LOWx &= ~(GDMA_SUSPEND_TRANSMISSSION);
    }
}

/**
  * \brief  Enables or disables the specified DMA Channelx interrupts.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  GDMA_IT: specifies the GDMA interrupts sources to be enabled or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg GDMA_INT_Transfer:  Transfer complete interrupt unmask
  *         \arg GDMA_INT_Block:  Block transfer interrupt unmask
  *         \arg GDMA_INT_Error:  Transfer error interrupt unmask
  *         \arg GDMA_INT_Half_Block: Half Block transfer interrupt unmask
  * \param  NewState: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void GDMA_INTConfig(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GDMAx_ChannelNum(GDMA_ChannelNum));
    assert_param(IS_GDMA_CONFIG_IT(GDMA_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);
    uint32_t temp_bit = 0;

    if (NewState == ENABLE)
    {
        /* Enable the selected DMA interrupts */
#if (CHIP_GDMA_CHANNEL_NUM == 27)
        if (GDMA_ChannelNum < GDMA2_CH_NUM8)
#else
        if (GDMA_ChannelNum < 8)
#endif
        {
            temp_bit = BIT(channel_num) | BIT(channel_num + 8);
        }
        else
        {
            temp_bit = BIT(channel_num + 16 - 8) | BIT(channel_num + 24 - 8);
        }

        if (GDMA_IT & GDMA_INT_Transfer)
        {
            GDMAx->GDMA_MaskTfr |= temp_bit;
        }
        if (GDMA_IT & GDMA_INT_Block)
        {
            GDMAx->GDMA_MaskBlock |= temp_bit;
        }
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
        if (GDMA_IT & GDMA_INT_Half_Block && GDMAx == GDMA2)
        {
            GDMAx->GDMA_MaskHalfBlock |= temp_bit;
        }
#endif
        if (GDMA_IT & GDMA_INT_Error)
        {
            GDMAx->GDMA_MaskErr |= temp_bit;
            GDMAx->GDMA_MaskErrNonSecure |= temp_bit;
        }
    }
    else if (NewState == DISABLE)
    {
        /* Disable the selected DMA interrupts */
#if (CHIP_GDMA_CHANNEL_NUM == 27)
        if (GDMA_ChannelNum < GDMA2_CH_NUM8)
#else
        if (GDMA_ChannelNum < 8)
#endif
        {
            temp_bit = BIT(channel_num + 8);
        }
        else
        {
            temp_bit = BIT(channel_num + 24 - 8);
        }

        if (GDMA_IT & GDMA_INT_Transfer)
        {
            GDMAx->GDMA_MaskTfr = temp_bit;
        }
        if (GDMA_IT & GDMA_INT_Block)
        {
            GDMAx->GDMA_MaskBlock = temp_bit;
        }
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
        if (GDMA_IT & GDMA_INT_Half_Block && GDMAx == GDMA2)
        {
            GDMAx->GDMA_MaskHalfBlock = temp_bit;
        }
#endif
        if (GDMA_IT & GDMA_INT_Error)
        {
            GDMAx->GDMA_MaskErr = temp_bit;
            GDMAx->GDMA_MaskErrNonSecure = temp_bit;
        }
    }
}

/**
  * \brief  Check whether GDMA Channel transfer interrupt is set.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \return Transfer interrupt status, SET or RESET.
  */
ITStatus GDMA_GetTransferINTStatus(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMAx_Channel_Num));

    ITStatus bit_status = RESET;
    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);

    if ((GDMAx->GDMA_StatusTfr & BIT(channel_num)) != (uint32_t)RESET)
    {
        bit_status = SET;
    }

    /* Return the transfer interrupt status */
    return  bit_status;
}

/**
  * \brief  Clear the specified DMA Channelx interrupts.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  GDMA_IT: specifies the GDMA interrupts sources to be enabled
  *         or disabled.
  *         This parameter can be any combination of the following values:
  *         \arg GDMA_INT_Transfer:  clear transfer complete interrupt.
  *         \arg GDMA_INT_Block:  clear Block transfer interrupt.
  *         \arg GDMA_INT_Error:  clear Transfer error interrupt.
  *         \arg GDMA_INT_Half_Block:  clear Half Block transfer interrupt.
  * \param  NewState: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void GDMA_ClearINTPendingBit(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT)
{
    /* Check the parameters */
    assert_param(IS_GDMAx_ChannelNum(GDMAx_ChannelNum));
    assert_param(IS_GDMA_CONFIG_IT(GDMA_IT));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);
    uint32_t temp_bit = 0;

    /* clear the selected DMA interrupts */
    temp_bit = BIT(channel_num);

    if (GDMA_IT & GDMA_INT_Transfer)
    {
        GDMAx->GDMA_ClearTfr = temp_bit;
    }
    if (GDMA_IT & GDMA_INT_Block)
    {
        GDMAx->GDMA_ClearBlock = temp_bit;
    }
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
    if (GDMA_IT & GDMA_INT_Half_Block && GDMAx == GDMA2)
    {
        GDMAx->GDMA_ClearHalfBlock = temp_bit;
    }
#endif
    if (GDMA_IT & GDMA_INT_Error)
    {
        GDMAx->GDMA_ClearErr = temp_bit;
        GDMAx->GDMA_ClearErrNonSecure = temp_bit;
    }
}

/**
  * \brief  Clear GDMAx Channelx all type interrupt.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \return None.
  */
void GDMA_ClearAllTypeINT(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_Num(GDMAx));
    assert_param(IS_GDMA_ChannelNum(GDMA_Channel_Num));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);
    uint32_t temp_bit = 0;

    temp_bit = BIT(channel_num);
    GDMAx->GDMA_ClearTfr = temp_bit;
    GDMAx->GDMA_ClearBlock = temp_bit;
#if (GDMA_SUPPORT_INT_HAIF_BLOCK == 1)
    GDMAx->GDMA_ClearHalfBlock = temp_bit;
#endif
    GDMAx->GDMA_ClearErr = temp_bit;
    GDMAx->GDMA_ClearErrNonSecure = temp_bit;
}

/**
  * \brief  Get selected GDMA channel status.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \return GDMA channel status: can be SET or RESET.
  * \return None.
  */
FlagStatus GDMA_GetChannelStatus(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMA_ChannelNum));

    FlagStatus bit_status = RESET;
    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);
    uint8_t channel_num = GDMA_GetGDMAChannelNum(GDMA_ChannelNum);

#if (CHIP_GDMA_CHANNEL_NUM == 27)
    if (GDMA_ChannelNum < GDMA2_CH_NUM8)
#else
    if (GDMA_ChannelNum < 8)
#endif
    {
        if ((GDMAx->GDMA_ChEnReg & BIT(channel_num)) != (uint32_t)RESET)
        {
            bit_status = SET;
        }
    }
    else
    {
        if ((GDMAx->GDMA_ChEnReg & BIT(channel_num + 16 - 8)) != (uint32_t)RESET)
        {
            bit_status = SET;
        }
    }

    /* Return the selected channel status */
    return  bit_status;
}

/**
  * \brief  Enable or disable the specified DMA channel secure functions.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  NewState: Specifies the GDMA channel secure function to be enabled or disabled.
  *         This parameter can be: ENABLE or DISABLE.
  * \return None.
  */
void GDMA_SecureCmd(GDMA_ChannelTypeDef *GDMA_Channelx, FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_CFG_HIGHx_TypeDef gdma_0x44 = {.d32 = GDMA_Channelx->GDMA_CFG_HIGHx};
    gdma_0x44.b.PROTCTL = !NewState;
    GDMA_Channelx->GDMA_CFG_HIGHx = gdma_0x44.d32;
}

/**
  * \brief  Set GDMA OSW.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  osw_count: outstanding write count.
  * \return None.
  */
void GDMA_SetOSW(uint8_t GDMA_ChannelNum, uint8_t osw_count)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);

    GDMA_DmaOsNum_TypeDef gdma_0x3b8 = {.d32 = GDMAx->GDMA_DmaOsNum};
    gdma_0x3b8.b.OSW = osw_count & 0xFF;
    GDMAx->GDMA_DmaOsNum = gdma_0x3b8.d32;
}

/**
  * \brief  Set GDMA OSR.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \param  osr_count: outstanding read count.
  * \return None.
  */
void GDMA_SetOSR(uint8_t GDMA_ChannelNum, uint8_t osr_count)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);

    GDMA_DmaOsNum_TypeDef gdma_0x3b8 = {.d32 = GDMAx->GDMA_DmaOsNum};
    gdma_0x3b8.b.OSR = osr_count & 0xFF;
    GDMAx->GDMA_DmaOsNum = gdma_0x3b8.d32;
}

/**
  * \brief  Get GDMA OSW.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \return osw_count: outstanding write count.
  */
uint8_t GDMA_GetOSWCount(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);

    GDMA_DmaOsNum_TypeDef gdma_0x3b8 = {.d32 = GDMAx->GDMA_DmaOsNum};
    return gdma_0x3b8.b.OSW & 0xFF;
}

/**
  * \brief  Get GDMA OSR.
  * \param  GDMA_ChannelNum: Select the GDMA channel number. \ref GDMA_CHANNEL_NUM
  * \return osr_count: outstanding read count.
  */
uint8_t GDMA_GetOSRCount(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_TypeDef *GDMAx = GDMA_GetGDMAxByCh(GDMA_ChannelNum);

    GDMA_DmaOsNum_TypeDef gdma_0x3b8 = {.d32 = GDMAx->GDMA_DmaOsNum};

    return gdma_0x3b8.b.OSR & 0xFF;
}

/**
  * \brief  Suspend GDMA transmission safe from the source.Please check GDMA FIFO empty to guarnatee without losing data.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
  * \return true: suspend success, false: suspend failed
  */
bool GDMA_SafeSuspend(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    uint8_t bit_set_time = 0;
    uint8_t bit_need_set_times = 10;
    uint8_t bit_need_check_times = 50;
    uint8_t timeout = bit_need_check_times;

    /* Suspend transmission */
    GDMA_Channelx->GDMA_CFG_LOWx |= GDMA_SUSPEND_TRANSMISSSION;

    /* Disable the selected DMAy Channelx */
    /* polling fifo empty */
    while ((GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET) && timeout--);
    if (GDMA_GetSuspendChannelStatus(GDMA_Channelx) != SET)
    {
        timeout = bit_need_check_times;
        /*polling cfg[1:2] 10 times set in 100timer check */
        while (--timeout)
        {
            if ((GDMA_Channelx->GDMA_CFG_LOWx & BIT1) && (GDMA_Channelx->GDMA_CFG_LOWx & BIT2))
            {
                bit_set_time++;
                if (bit_set_time >= bit_need_set_times)
                {
                    break;
                }
            }
        }
        if (timeout == 0)
        {
            /* unsuspend dma channel */
            GDMA_Channelx->GDMA_CFG_LOWx &= ~(GDMA_SUSPEND_TRANSMISSSION);
            return false;
        }
    }

    return true;
}

/**
 * \brief  Set GDMA transmission source address.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  Address: Source address.
 * \return None.
 */
void GDMA_SetSourceAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_Channelx->GDMA_SARx = Address;
}

/**
 * \brief  Set GDMA transmission destination address.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  Address: Destination address.
 * \return None.
 */
void GDMA_SetDestinationAddress(GDMA_ChannelTypeDef *GDMA_Channelx,
                                uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_Channelx->GDMA_DARx = Address;
}

/**
 * \brief  Set GDMA LLP stucture address.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  Address: LLP stucture address.
 * \return None.
 */
void GDMA_SetLLPAddress(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t Address)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_Channelx->GDMA_LLPx = Address & 0xFFFFFFFC;
}

/**
 * \brief  Set GDMA buffer size.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  buffer_size: Set GDMA_BufferSize, max 65535.
 * \return None.
 */
void GDMA_SetBufferSize(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t buffer_size)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    /* Configure high 32 bit of CTL register */
    GDMA_Channelx->GDMA_CTL_HIGHx = buffer_size;
}

/**
 * \brief  Get GDMA source address.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return Source address.
 */
uint32_t GDMA_GetSrcTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    uint32_t address = 0;
    address = GDMA_Channelx->GDMA_SARx;
    return address;
}

/**
 * \brief  Get GDMA destination address.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return Destination address.
 */
uint32_t GDMA_GetDstTransferAddress(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    uint32_t address = 0;
    address = GDMA_Channelx->GDMA_DARx;
    return address;
}

/**
 * \brief  Get GDMA transfer data length.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return GDMA transfer data length.
 */
uint16_t GDMA_GetTransferLen(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    return (uint16_t)(GDMA_Channelx->GDMA_CTL_HIGHx & 0xffffffff);
}

/**
 * \brief  Check GDMA FIFO status.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return GDMA FIFO status.
 */
FlagStatus GDMA_GetFIFOStatus(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    FlagStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    if ((GDMA_Channelx->GDMA_CFG_LOWx & GDMA_FIFO_STATUS) != (uint32_t)RESET)
    {
        bit_status = SET;
    }

    /* Return the selected channel status */
    return  bit_status;
}

/**
 * \brief  Suspend GDMA transmission from the source.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  NewState: New state of the GDMAx Channelx.
 * \return None.
 */
void GDMA_SuspendCmd(GDMA_ChannelTypeDef *GDMA_Channelx,
                     FunctionalState NewState)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState == DISABLE)
    {
        /* Not suspend transmission*/
        GDMA_Channelx->GDMA_CFG_LOWx &= ~(GDMA_SUSPEND_TRANSMISSSION);
    }
    else
    {
        /* Suspend transmission */
        GDMA_Channelx->GDMA_CFG_LOWx |= GDMA_SUSPEND_TRANSMISSSION;
    }
}

/**
 * \brief  Check GDMA suspend command status.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return GDMA suspend command status.
 */
FlagStatus GDMA_GetSuspendCmdStatus(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    FlagStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    if ((GDMA_Channelx->GDMA_CFG_LOWx & GDMA_SUSPEND_CMD_STATUS) == GDMA_SUSPEND_CMD_STATUS)
    {
        bit_status = SET;
    }

    /* Return the selected channel suspend status */
    return  bit_status;
}

/**
 * \brief  Check GDMA suspend channel status.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \return GDMA suspend channel status.
 */
FlagStatus GDMA_GetSuspendChannelStatus(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    FlagStatus bit_status = RESET;

    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    if ((GDMA_Channelx->GDMA_CFG_LOWx & GDMA_SUSPEND_CHANNEL_STATUS) == GDMA_SUSPEND_CHANNEL_STATUS)
    {
        bit_status = SET;
    }

    /* Return the selected channel suspend status */
    return  bit_status;
}

/**
 * \brief  Update GDMA LLP mode in multi-block.
  * \param  GDMA_Channelx: Select the GDMA peripheral. \ref GDMA_Declaration
 * \param  GDMA LLP mode
 * \return None.
 */
void GDMA_SetLLPMode(GDMA_ChannelTypeDef *GDMA_Channelx, uint32_t mode)
{
    GDMA_Channelx->GDMA_CTL_LOWx = ((GDMA_Channelx->GDMA_CTL_LOWx & (~LLI_TRANSFER)) | mode);
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

