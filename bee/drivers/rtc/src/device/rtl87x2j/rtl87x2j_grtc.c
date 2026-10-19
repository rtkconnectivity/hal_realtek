/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_grtc.h"
#include "rtl_nvic.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/
#define GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x0F) // Force off 0x0A

/* GRTC rides on the free running GTC; on RTL87X2J the AON 32K source is fixed
 * at 32000Hz for every module except USER RTC. */
#define GRTC_CLK_SOURCE                             (32000)

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
void GRTC_ClockAutoModeCmd(FunctionalState Newstate)
{
    if (Newstate == ENABLE)
    {
        GRTC->GRTC_QACTIVE_CTRL &= ~GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }
    else
    {
        GRTC->GRTC_QACTIVE_CTRL |= GRTC_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}

uint32_t GRTC_PeriodMsToCnt(uint32_t period_ms)
{
    return (GRTC_CLK_SOURCE * period_ms / 1000);
}

uint32_t GRTC_CntToPeriodMs(uint32_t cnt)
{
    return (cnt * 1000 / GRTC_CLK_SOURCE);
}

bool GRTC_GetCompIRQx(GRTCCompIndex_TypeDef Index, IRQn_Type *IRQ, uint8_t *is_first_irq)
{
    if (!IS_GRTC_COMP(Index))
    {
        return false;
    }

    /* RTL87X2J gives every comparator its own first level vector:
     * GRTC_CH0_IRQn ~ GRTC_CH7_IRQn. No shared vector, so no sub ISR dispatch. */
    *IRQ = (IRQn_Type)(GRTC_CH0_IRQn + Index);
    *is_first_irq = true;

    return true;
}

FlagStatus GRTC_GetInterruptEnableStatus(GRTCCompIndex_TypeDef Index)
{
    if ((GRTC->GRTC_INTR_CTRL & BIT(Index)) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

FlagStatus GRTC_GetAutoReloadEnableStatus(GRTCCompIndex_TypeDef Index)
{
    if ((GRTC->GRTC_RELOAD_CTRL & BIT(Index)) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}

#if (GRTC_SUPPORT_RAP_FUNCTION == 1)
bool GRTC_IsSupportRAPComp(GRTCCompIndex_TypeDef Index)
{
    /* All RTL87X2J comparators own a rap_mode bit in GRTC_TASK_CTRL */
    return IS_GRTC_COMP(Index);
}

FlagStatus GRTC_GetRAPEnableStatus(GRTCCompIndex_TypeDef Index)
{
    if (!GRTC_IsSupportRAPComp(Index))
    {
        return RESET;
    }
    if ((GRTC->GRTC_TASK_CTRL & BIT(Index)) != (uint32_t)RESET)
    {
        return SET;
    }
    return RESET;
}
#endif


