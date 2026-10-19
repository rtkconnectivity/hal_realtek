/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
*============================================================================*/
#include "rtl_lpwdt.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Constants
 *============================================================================*/
#define LPWDT_CLOCK_FREQUENCY        (32000)
#define LPWDT_MAX_TIMEOUT_MS         (((1 << 28) - 1) / (LPWDT_CLOCK_FREQUENCY / 1000))
#define LPWDT_VPON_ADDR              0x400003E0

/*============================================================================*
*                           Private Functions
*============================================================================*/
static bool LPWDT_CalculateConfig(uint32_t timeout_ms, uint32_t *cnt_limit)
{
    if (timeout_ms > LPWDT_MAX_TIMEOUT_MS)
    {
        return false;
    }

    *cnt_limit = timeout_ms * (LPWDT_CLOCK_FREQUENCY / 1000);

    return true;
}

static void LPWDT_Config(uint32_t cnt_limit, WDTMode_TypeDef wdt_mode)
{
    /* LPWDT function enable*/
    RCC_ClockCmd(LPWDT_CLOCK, ENABLE);

    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDT->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_mode = wdt_mode;
    lpwdt_reg0.b.lpwdt_cnt_limit = cnt_limit;

    /* counter will go on and counter value is reload from active when enter low power mode*/
    lpwdt_reg0.b.lpwdt_cnt_ctl = 1;
    lpwdt_reg0.b.lpwdt_cnt_reload = 1;
    LPWDT->WDT_REG0X = lpwdt_reg0.d32;
}

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * @brief  Start LPWDT. This function will enable LPWDT clock, set and start LPWDT.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  * @param  TimeMs  LPWDT Timeout Time. Unit: ms.
  * @param  Mode    Refer to @ref WDTMode_TypeDef. If the Reset LPWDT operation is not performed within the Timeout period,
  *                 the configured mode operation will be executed.
  * @return LPWDT operating status.
  * @retval true   LPWDT started successfully.
  * @retval false  LPWDT start failed.
  */
bool LPWDT_Start(LPWDT_TypeDef *LPWDTx, uint32_t TimeMs, WDTMode_TypeDef Mode)
{
    uint32_t cnt_limit;
    if (LPWDT_CalculateConfig(TimeMs, &cnt_limit))
    {
        LPWDT_Config(cnt_limit, Mode);
        LPWDT_Kick(LPWDTx);
        LPWDT_Enable(LPWDTx);
        return true;
    }
    return false;
}

/**
  * @brief  Enable LPWDT.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  */
void LPWDT_Enable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_enable = 1;
    LPWDTx->WDT_REG0X = lpwdt_reg0.d32;
}

/**
  * @brief  Disable LPWDT.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  */
void LPWDT_Disable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};
    lpwdt_reg0.b.lpwdt_enable = 0;
    LPWDTx->WDT_REG0X = lpwdt_reg0.d32;
}

/**
  * @brief  Kick Watchdog to restart LPWDT.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  */
void LPWDT_Kick(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG1X_TypeDef lpwdt_reg1 = {.d32 = LPWDTx->WDT_REG1X};
    lpwdt_reg1.b.lpwdt_cnt_reset = 0x5A5A;
    LPWDTx->WDT_REG1X = lpwdt_reg1.d32;
}

/**
  * @brief  Check if the LPWDT is working.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  * @return LPWDT operating status.
  * @retval true   LPWDT is enabled.
  * @retval false  LPWDT is not enabled.
  */
bool LPWDT_IsEnable(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};

    return (lpwdt_reg0.b.lpwdt_enable == 1);
}

/**
  * @brief  Get the current LPWDT timeout value in milliseconds.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  * @return LPWDT timeout duration in milliseconds.
  */
uint32_t LPWDT_GetTimeoutMs(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDTx->WDT_REG0X};

    uint32_t timeout_ms = (lpwdt_reg0.b.lpwdt_cnt_limit / (LPWDT_CLOCK_FREQUENCY / 1000));

    return timeout_ms;
}

/**
  * @brief  Get LPWDT mode.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  * @return LPWDT mode.
  * @retval RESET_ALL               Reset all.
  * @retval RESET_ALL_EXCEPT_AON    Reset all except RTC and some AON register.
  * @retval INTERRUPT_CPU           Interrupt CPU.
  * @retval WDT_MODE_NUM            The maximum selectable value for WDT mode.
  */
WDTMode_TypeDef LPWDT_GetMode(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG0X_TypeDef lpwdt_reg0 = {.d32 = LPWDT->WDT_REG0X};

    return (WDTMode_TypeDef)(lpwdt_reg0.b.lpwdt_mode);
}

/**
  * @brief  Get LPWDT current Count.
  * @param  LPWDTx  Refer to @ref LPWDT_Declaration
  * @return Current count.
  */
uint32_t LPWDT_GetCurrentCount(LPWDT_TypeDef *LPWDTx)
{
    WDT_REG19X_TypeDef lpwdt_reg19 = {.d32 = LPWDT->WDT_REG19X};

    return (uint32_t)lpwdt_reg19.b.lpwdt_current;
}
