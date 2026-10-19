/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
*============================================================================*/
#include "rtl_wdt.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Constants
 *============================================================================*/
#define WDT_CLOCK_FREQUENCY        (32000)
#define WDT_MAX_TIMEOUT_MS         (((1 << 28) - 1) / (WDT_CLOCK_FREQUENCY / 1000))

#define WDT_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC       (0x00)
#define WDT_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN       (0x03)//Force off 0x02

/*============================================================================*
*                           Private Functions
*============================================================================*/
static void WDT_ClockEnable(void)
{
    RCC_ClockCmd(WDT_CLOCK, ENABLE);
}

static bool WDT_CalculateConfig(uint32_t timeout_ms, uint32_t *cnt_limit)
{
    if (timeout_ms > WDT_MAX_TIMEOUT_MS)
    {
        return false;
    }

    *cnt_limit = timeout_ms * (WDT_CLOCK_FREQUENCY / 1000);

    return true;
}

static void WDT_Config(uint32_t cnt_limit, WDTMode_TypeDef wdt_mode)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_cnt_limit = cnt_limit;
    wdt_ctl.b.wdt_mode = wdt_mode;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * @brief  Start WDT. This function will enable WDT clock, set and start WDT.
  * @param  TimeMs  WDT Timeout Time. Unit: ms.
  * @param  Mode    Refer to @ref WDTMode_TypeDef. If the Reset WDT operation is not performed within the Timeout period,
  *                 the configured mode operation will be executed.
  * @return WDT operating status.
  * @retval true   WDT mode set successfully, enabling the function.
  * @retval false  WDT setting failed.
  */
bool WDT_Start(uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    uint32_t cnt_limit;
    if (WDT_CalculateConfig(TimeMs, &cnt_limit))
    {
        WDT_ClockEnable();
        WDT_Config(cnt_limit, Mode);
        WDT_Kick();
        WDT_Enable();
        return true;
    }
    return false;
}

/**
  * @brief  Enable WDT.
  */
void WDT_Enable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_en = 1;
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * @brief  Disable WDT.
  */
void WDT_Disable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_en = 0;
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * @brief  Kick Watchdog to restart WDT.
  */
void WDT_Kick(void)
{
    WDT->WDT_KICK = 0x5A5A;
}

/**
  * @brief  Clear WDT interrupt pending bit.
  */
void WDT_ClearINTPendingBit(void)
{

    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};
    wdt_ctl.b.wdt_to = 1;
    WDT->WDT_CTL = wdt_ctl.d32;
}

/**
  * @brief  Check if the WDT is working.
  * @return WDT operating status.
  * @retval true   WDT is enabled.
  * @retval false  WDT is not enabled.
  */
bool WDT_IsEnable(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    return (wdt_ctl.b.wdt_en == 1);
}

/**
  * @brief  Get the current WDT timeout value in milliseconds.
  * @return WDT timeout duration in milliseconds.
  */
uint32_t WDT_GetTimeoutMs(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    uint32_t timeout_ms = (wdt_ctl.b.wdt_cnt_limit / (WDT_CLOCK_FREQUENCY / 1000));

    return timeout_ms;
}

/**
  * @brief  Get WDT current count.
  * @return Current count.
  */
uint32_t WDT_GetCurrentCount(void)
{
    return WDT->WDT_CURRENT;
}

/**
  * @brief  Get WDT mode.
  * @return WDT mode.
  * @retval RESET_ALL               Reset all.
  * @retval RESET_ALL_EXCEPT_AON    Reset all except RTC and some AON register.
  * @retval INTERRUPT_CPU           Interrupt CPU.
  * @retval WDT_MODE_NUM            The maximum selectable value for WDT mode.
  */
WDTMode_TypeDef WDT_GetMode(void)
{
    WDT_CTL_TypeDef wdt_ctl = {.d32 = WDT->WDT_CTL};

    return (WDTMode_TypeDef)(wdt_ctl.b.wdt_mode);
}

/**
  * @brief  Enable or disable WDT clock auto mode.
  * @param  Newstate  Enable or disable WDT clock auto mode.
  */
void WDT_ClockAutoModeCmd(FunctionalState Newstate)
{
    if (Newstate == ENABLE)
    {
        WDT->WDT_CLK_QACTIVE_CTL = WDT_CLOCK_AUTO_MODE_CONFIG_AUTOMATIC;
    }
    else
    {
        WDT->WDT_CLK_QACTIVE_CTL = WDT_CLOCK_AUTO_MODE_CONFIG_ALWAYSRUN;
    }

    return;
}
