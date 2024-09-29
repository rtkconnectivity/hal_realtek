/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl_gpio.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
uint32_t GPIO_SwapDebPinBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
    uint32_t temp_gpio_bit = GPIO_Pin;

    if (GPIOx == GPIOA)
    {
        /* BIT12 <-> BIT27  BIT20 <-> BIT31 */
        temp_gpio_bit &= ~BIT12;
        temp_gpio_bit |= ((GPIO_Pin & BIT27) >> 27) << 12;

        temp_gpio_bit &= ~BIT27;
        temp_gpio_bit |= ((GPIO_Pin & BIT12) >> 12) << 27;

        temp_gpio_bit &= ~BIT20;
        temp_gpio_bit |= ((GPIO_Pin & BIT31) >> 31) << 20;

        temp_gpio_bit &= ~BIT31;
        temp_gpio_bit |= ((GPIO_Pin & BIT20) >> 20) << 31;
    }
    else
    {
        /* BIT1 <-> BIT8  BIT2 <-> BIT12  BIT3 <-> BIT16 */
        temp_gpio_bit &= ~BIT1;
        temp_gpio_bit |= ((GPIO_Pin & BIT8) >> 8) << 1;

        temp_gpio_bit &= ~BIT8;
        temp_gpio_bit |= ((GPIO_Pin & BIT1) >> 1) << 8;

        temp_gpio_bit &= ~BIT2;
        temp_gpio_bit |= ((GPIO_Pin & BIT12) >> 12) << 2;

        temp_gpio_bit &= ~BIT12;
        temp_gpio_bit |= ((GPIO_Pin & BIT2) >> 2) << 12;

        temp_gpio_bit &= ~BIT3;
        temp_gpio_bit |= ((GPIO_Pin & BIT16) >> 16) << 3;

        temp_gpio_bit &= ~BIT16;
        temp_gpio_bit |= ((GPIO_Pin & BIT3) >> 3) << 16;
    }

    return temp_gpio_bit;
}

/**
  * \brief  Get GPIO GROUP through the given pad.
  * \param  Pin_num: Pin number to be configured. \ref Pin_Number
  * \return GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  */
GPIO_TypeDef *GPIO_GetPort(uint8_t Pin_num)
{
    if (((Pin_num >= P0_0) && (Pin_num <= P3_2)) || ((Pin_num >= MICBIAS) && (Pin_num <= DACN)))
    {
        return GPIOA;
    }
    else if (((Pin_num >= P3_3) && (Pin_num <= P7_4)) || ((Pin_num >= P9_0) && (Pin_num <= P10_2)))
    {
        return GPIOB;
    }
    return 0;
}


/**
  * \brief  Get the GPIO_Pin(GPIO0~GPIO31) through the given PAD num.
  * \param  Pin_num: Pin number to be configured. \ref Pin_Number
  * \return GPIOx(x is 0~31) value.
  */
uint32_t GPIO_GetPinBit(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    if (Pin_num <= P1_7)
    {
        return BIT(Pin_num);
    }
    else if ((Pin_num >= P2_0) && (Pin_num <= P3_2))
    {
        return BIT(Pin_num + 5);
    }
    else if ((Pin_num >= P3_3) && (Pin_num <= P5_7))
    {
        return BIT(Pin_num - 27);
    }
    else if ((Pin_num >= P6_0) && (Pin_num <= P7_4))
    {
        return BIT(Pin_num - 29);
    }
    else if ((Pin_num >= MICBIAS) && (Pin_num <= DACN))
    {
        return BIT(Pin_num - 48);
    }
    else if ((Pin_num >= P9_0) && (Pin_num <= P10_2))
    {
        return BIT(Pin_num - 51);
    }

    return 0xFF;
}


/**
  * \brief  Get GPIO value (GPIOA0 ~ GPIOB31) through the given pad.
  * \param  Pin_num: Pin number to be configured. \ref Pin_Number
  * \return GPIO value (GPIOA0 ~ GPIOB31).
  */
uint8_t GPIO_GetNum(uint8_t Pin_num)
{
    /* Check the parameters */
    assert_param(IS_PIN_NUM(Pin_num));

    if (Pin_num <= P1_7)
    {
        return (Pin_num);
    }
    else if ((Pin_num >= P2_0) && (Pin_num <= P5_7))
    {
        return (Pin_num + 5);
    }
    else if ((Pin_num >= P6_0) && (Pin_num <= P7_4))
    {
        return (Pin_num + 3);
    }
    else if ((Pin_num >= MICBIAS) && (Pin_num <= DACN))
    {
        return (Pin_num - 48);
    }
    else if ((Pin_num >= P9_0) && (Pin_num <= P10_2))
    {
        return (Pin_num - 19);
    }
    return 0xFF;
}

/**
  * \brief  Enable GPIO external debounce clock.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  NewState: Disable or enable gpio debounce clock.
  * \return None.
  */
void GPIO_ExtDebCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState)
{
    uint32_t GPIO_Pin_Swap = GPIO_SwapDebPinBit(GPIOx, GPIO_Pin);

    /* Configure Debounce register */
    GPIO_Debounce_TypeDef *GPIOx_DEB = GPIOx == GPIOA ? GPIOA_DEB : GPIOB_DEB;

    if (NewState == DISABLE)
    {
        GPIOx_DEB->GPIO_DEB_FUN_CTL &= (~GPIO_Pin_Swap);

        for (uint8_t i = 0; i < 8; i++)
        {
            if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
            {
                GPIO_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2]};
                if (i % 2)
                {
                    gpio_deb.b.GPIO_G_H_DEB_CNT_EN = DISABLE;
                }
                else
                {
                    gpio_deb.b.GPIO_G_L_DEB_CNT_EN = DISABLE;
                }
                GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
            }
        }
    }
    else
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
            {
                GPIOx_DEB->GPIO_DEB_FUN_CTL &= (~((uint32_t)0x0F << i * 4));
                GPIOx_DEB->GPIO_DEB_FUN_CTL |= GPIO_Pin_Swap;

                GPIO_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2]};
                if (i % 2)
                {
                    gpio_deb.b.GPIO_G_H_DEB_CNT_EN = ENABLE;
                }
                else
                {
                    gpio_deb.b.GPIO_G_L_DEB_CNT_EN = ENABLE;
                }
                GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
            }
        }
    }
}

/**
  * \brief  Set GPIO debounce parameters.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_Pin: GPIO_Pin can be 0 to 31.
  * \param  GPIO_DebounceClkSource: select debounce count clk source, can be S11 or 32KHz.
  * \param  GPIO_DebounceClkDiv: divider selection.
  * \param  GPIO_DebounceCntLimit: debounce time can be calculated by count limit.
  * \return None.
  */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebounceSrc_TypeDef GPIO_DebounceClkSource,
                       GPIODebounceDiv_TypeDef GPIO_DebounceClkDiv,
                       uint8_t GPIO_DebounceCntLimit)
{
    uint32_t GPIO_Pin_Swap = GPIO_SwapDebPinBit(GPIOx, GPIO_Pin);

    /* Configure Debounce register */
    GPIO_Debounce_TypeDef *GPIOx_DEB = GPIOx == GPIOA ? GPIOA_DEB : GPIOB_DEB;

    for (uint8_t i = 0; i < 8; i++)
    {
        if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
        {
            GPIOx_DEB->GPIO_DEB_FUN_CTL &= (~((uint32_t)0x0F << i * 4));
            GPIOx_DEB->GPIO_DEB_FUN_CTL |= GPIO_Pin_Swap;
            GPIO_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2]};
            if (i % 2)
            {
                gpio_deb.b.GPIO_G_H_CNT_LIMIT = GPIO_DebounceCntLimit & 0xFF;
                gpio_deb.b.GPIO_G_H_DEB_CLK_SEL = GPIO_DebounceClkSource;
                gpio_deb.b.GPIO_G_H_DEB_CLK_DIV = GPIO_DebounceClkDiv;
                gpio_deb.b.GPIO_G_H_DEB_CNT_EN = ENABLE;
            }
            else
            {
                gpio_deb.b.GPIO_G_L_CNT_LIMIT = GPIO_DebounceCntLimit & 0xFF;
                gpio_deb.b.GPIO_G_L_DEB_CLK_SEL = GPIO_DebounceClkSource;
                gpio_deb.b.GPIO_G_L_DEB_CLK_DIV = GPIO_DebounceClkDiv;
                gpio_deb.b.GPIO_G_L_DEB_CNT_EN = ENABLE;
            }
            GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
        }
    }
}

/**
  * \brief  Configure Debounce enable register for GPIO_Init.
  * \param  GPIOx: Select the GPIO peripheral. \ref GPIO_Declaration
  * \param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that
  *         contains the configuration information for the specified GPIO peripheral.
  * \return None.
  */
void GPIO_ExtDebInInit(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t GPIO_Pin_Swap = GPIO_SwapDebPinBit(GPIOx, GPIO_InitStruct->GPIO_Pin);

    /* Configure Debounce enable register */
    GPIO_Debounce_TypeDef *GPIOx_DEB = GPIOx == GPIOA ? GPIOA_DEB : GPIOB_DEB;

    if (GPIO_InitStruct->GPIO_ITDebounce == GPIO_INT_DEBOUNCE_DISABLE)
    {
        GPIOx_DEB->GPIO_DEB_FUN_CTL &= (~GPIO_Pin_Swap);
        for (uint8_t i = 0; i < 8; i++)
        {
            if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
            {
                GPIO_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2]};
                if (i % 2)
                {
                    gpio_deb.b.GPIO_G_H_DEB_CNT_EN = DISABLE;
                }
                else
                {
                    gpio_deb.b.GPIO_G_L_DEB_CNT_EN = DISABLE;
                }
                GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
            }
        }
    }
    else
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            if ((GPIO_Pin_Swap & ((uint32_t)0x0F << i * 4)) != 0)
            {
                GPIOx_DEB->GPIO_DEB_FUN_CTL &= (~((uint32_t)0x0F << i * 4));
                GPIOx_DEB->GPIO_DEB_FUN_CTL |= GPIO_Pin_Swap;

                GPIO_DEB_CLK_CTL_TypeDef gpio_deb = {.d32 = GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2]};
                if (i % 2)
                {
                    gpio_deb.b.GPIO_G_H_CNT_LIMIT = GPIO_InitStruct->GPIO_DebounceCntLimit & 0xFF;
                    gpio_deb.b.GPIO_G_H_DEB_CLK_SEL = GPIO_InitStruct->GPIO_DebounceClkSource;
                    gpio_deb.b.GPIO_G_H_DEB_CLK_DIV = GPIO_InitStruct->GPIO_DebounceClkDiv;
                    gpio_deb.b.GPIO_G_H_DEB_CNT_EN = ENABLE;
                }
                else
                {
                    gpio_deb.b.GPIO_G_L_CNT_LIMIT = GPIO_InitStruct->GPIO_DebounceCntLimit & 0xFF;
                    gpio_deb.b.GPIO_G_L_DEB_CLK_SEL = GPIO_InitStruct->GPIO_DebounceClkSource;
                    gpio_deb.b.GPIO_G_L_DEB_CLK_DIV = GPIO_InitStruct->GPIO_DebounceClkDiv;
                    gpio_deb.b.GPIO_G_L_DEB_CNT_EN = ENABLE;
                }
                GPIOx_DEB->GPIO_DEB_CLK_CTL[i / 2] = gpio_deb.d32;
            }
        }
    }
}

/**
  * \brief  Store GPIO register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Store buffer to store GPIO register data.
  * \return None.
  */
void GPIO_DLPSEnter(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIO_Debounce_TypeDef *GPIOx_DEB = GPIOx == GPIOA ? GPIOA_DEB : GPIOB_DEB;
    GPIOStoreReg_Typedef *store_buf = (GPIOStoreReg_Typedef *)StoreBuf;

    if (GPIOx == GPIOA)
    {
        RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_PeriphClockCmd(APBPeriph_GPIOB, APBPeriph_GPIOB_CLOCK, ENABLE);
    }

    store_buf->gpio_reg[0] = GPIOx->GPIO_DR;
    store_buf->gpio_reg[1] = GPIOx->GPIO_DDR;
    store_buf->gpio_reg[3] = GPIOx->GPIO_INT_EN;
    store_buf->gpio_reg[4] = GPIOx->GPIO_INT_MASK;
    store_buf->gpio_reg[5] = GPIOx->GPIO_INT_LV;
    store_buf->gpio_reg[6] = GPIOx->GPIO_LS_SYNC;
    store_buf->gpio_reg[7] = GPIOx->GPIO_OUT_MODE;
    store_buf->gpio_reg[8] = GPIOx->GPIO_EXT_DEB_POL_CTL;

    store_buf->gpio_reg[10] = GPIOx_DEB->GPIO_DEB_CLK_CTL[0];
    store_buf->gpio_reg[11] = GPIOx_DEB->GPIO_DEB_CLK_CTL[1];
    store_buf->gpio_reg[12] = GPIOx_DEB->GPIO_DEB_CLK_CTL[2];
    store_buf->gpio_reg[13] = GPIOx_DEB->GPIO_DEB_CLK_CTL[3];
    store_buf->gpio_reg[14] = GPIOx_DEB->GPIO_DEB_FUN_CTL;

    return;
}

/**
  * \brief  Restore GPIO register values when system enter DLPS.
  * \param  PeriReg: Specifies to select the GPIO peripheral.
  * \param  StoreBuf: Restore buffer to restore GPIO register data.
  * \return None
  */
void GPIO_DLPSExit(void *PeriReg, void *StoreBuf)
{
    GPIO_TypeDef *GPIOx = (GPIO_TypeDef *)PeriReg;
    GPIO_Debounce_TypeDef *GPIOx_DEB = GPIOx == GPIOA ? GPIOA_DEB : GPIOB_DEB;
    GPIOStoreReg_Typedef *store_buf = (GPIOStoreReg_Typedef *)StoreBuf;

    if (GPIOx == GPIOA)
    {
        RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
    }
    else if (GPIOx == GPIOB)
    {
        RCC_PeriphClockCmd(APBPeriph_GPIOB, APBPeriph_GPIOB_CLOCK, ENABLE);
    }

    GPIOx->GPIO_DDR               = store_buf->gpio_reg[1];
    GPIOx->GPIO_OUT_MODE          = store_buf->gpio_reg[7];
    GPIOx->GPIO_DR                = store_buf->gpio_reg[0];

    GPIOx->GPIO_INT_MASK          = 0xFFFFFFFF;
    GPIOx->GPIO_INT_LV            = store_buf->gpio_reg[5];
    GPIOx->GPIO_LS_SYNC           = store_buf->gpio_reg[6];
    GPIOx->GPIO_EXT_DEB_POL_CTL   = store_buf->gpio_reg[8];

    GPIOx_DEB->GPIO_DEB_CLK_CTL[0] = store_buf->gpio_reg[10];
    GPIOx_DEB->GPIO_DEB_CLK_CTL[1] = store_buf->gpio_reg[11];
    GPIOx_DEB->GPIO_DEB_CLK_CTL[2] = store_buf->gpio_reg[12];
    GPIOx_DEB->GPIO_DEB_CLK_CTL[3] = store_buf->gpio_reg[13];
    GPIOx_DEB->GPIO_DEB_FUN_CTL   = store_buf->gpio_reg[14];

    GPIOx->GPIO_INT_EN            = store_buf->gpio_reg[3];
    GPIOx->GPIO_INT_CLR           = ~(store_buf->gpio_reg[1]);
    GPIOx->GPIO_INT_MASK          = store_buf->gpio_reg[4];

    return;
}

/******************* (C) COPYRIGHT 2023 Realtek Semiconductor Corporation *****END OF FILE****/

