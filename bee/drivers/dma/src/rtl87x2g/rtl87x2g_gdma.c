/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "dma/inc/rtl_gdma.h"
#include "rcc/inc/rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
GDMA_TypeDef *GDMA_GetGDMAx(GDMA_ChannelTypeDef *GDMA_Channelx)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    GDMA_TypeDef *GDMAx = GDMA0;

    return GDMAx;
}

GDMA_TypeDef *GDMA_GetGDMAxByCh(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMA_ChannelNum));

    GDMA_TypeDef *GDMAx = GDMA0;

    return GDMAx;
}

uint8_t GDMA_GetGDMAChannelNum(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMA_ChannelNum));

    return GDMA_ChannelNum;
}

uint8_t GDMA_GetHandshakeNum(GDMA_ChannelTypeDef *GDMA_Channelx, uint8_t handshake)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ALL_PERIPH(GDMA_Channelx));

    return handshake;
}

GDMA_ChannelTypeDef *GDMA_GetGDMAChannelx(uint8_t GDMA_ChannelNum)
{
    /* Check the parameters */
    assert_param(IS_GDMA_ChannelNum(GDMA_ChannelNum));

    GDMA_ChannelTypeDef *GDMA_Channelx = (GDMA_ChannelTypeDef *)(GDMA0_CHANNEL_REG_BASE +
                                                                 GDMA_ChannelNum * 0x0058);;
    if (GDMA_ChannelNum < 8)
    {
        GDMA_Channelx = (GDMA_ChannelTypeDef *)(GDMA0_CHANNEL_REG_BASE + GDMA_ChannelNum * 0x0058);
    }
    else
    {
        GDMA_Channelx = (GDMA_ChannelTypeDef *)(GDMA0_CHANNEL_REG_BASE + 0x0400 +
                                                (GDMA_ChannelNum - 8) * 0x0058);
    }

    return GDMA_Channelx;
}

bool GDMA_IsValidHandshake(uint8_t handshake)
{
    return true;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

