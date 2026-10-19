/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *                           Header Files
 *============================================================================*/
#include "rtl_lpqdec.h"
#include "rtl_pinmux.h"
#include "rtl_rcc.h"

/*============================================================================*
 *                           Private Defines
 *============================================================================*/

/*============================================================================*
 *                           Public Functions
 *============================================================================*/
/**
  * \brief  Get LPQDEC X-Axis direction.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \param  LPQDEC_AXIS: Specifies the LPQDEC axis.
  *         This parameter parameter can be one of the following values:
  *         \arg  LPQDEC_AXIS_X: The LPQDEC X axis.
  * \return The direction of the axis. This parameter parameter can be one of the following values:
  *         \retval LPQDEC_AXIS_DIR_UP: The axis is rolling up.
  *         \retval LPQDEC_AXIS_DIR_DOWN: The axis is rolling down.
  */
bool LPQDEC_GetAxisDirection(LPQDEC_TypeDef *LPQDECx, uint32_t LPQDEC_AXIS)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));
    assert_param(IS_LPQDEC_AXIS(LPQDEC_AXIS));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr1x = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    return lpqdec_sr1x.b.cnt_dir;
}

/**
  * \brief  Get current state of phase.
  * \param  LPQDECx: Select the LPQDEC peripheral. \ref LPQDEC_Declaration.
  * \return The current state of phase. \ref LPQDECPhase_TypeDef
  */
LPQDECPhase_TypeDef LPQDEC_GetPhaseState(LPQDEC_TypeDef *LPQDECx)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    LPQDEC_SR_1_X_TypeDef lpqdec_sr_1 = {.d32 = LPQDECx->LPQDEC_SR_1_X};
    LPQDECPhase_TypeDef phase = LPQDEC_PHASE_MODE0;

    /* PHA is the high bit and PHB the low bit, same encoding as x_initial_phase. */
    phase = (lpqdec_sr_1.b.pha_sta << 1) | lpqdec_sr_1.b.phb_sta;

    return phase;
}

/**
 * \brief  Get the NVIC IRQ number for an LPQDEC peripheral instance.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \return CMSIS IRQn_Type value, or 0 if unknown.
 */
int32_t LPQDEC_GetIRQx(LPQDEC_TypeDef *LPQDECx)
{
    /* Check the parameters */
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (LPQDECx == LPQDEC) { return LPQDEC_IRQn; }
    return 0;
}

/**
 * \brief  Get the LPQDEC peripheral pointer for a given IRQ number.
 *
 * \param  irqn  CMSIS IRQ number.
 * \return LPQDEC peripheral pointer, or NULL if not found.
 */
LPQDEC_TypeDef *LPQDEC_GetLPQDECByIRQx(int32_t irqn)
{
    if (irqn == LPQDEC_IRQn) { return LPQDEC; }
    return NULL;
}

/**
 * \brief  Configure PHA / PHB GPIO pads for an LPQDEC peripheral instance.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  pha_pin  PHA GPIO pin number. Out-of-range values skip the pad config.
 * \param  phb_pin  PHB GPIO pin number. Out-of-range values skip the pad config.
 */
void LPQDEC_PadConfig(LPQDEC_TypeDef *LPQDECx, uint8_t pha_pin, uint8_t phb_pin)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (IS_PIN_NUMBER(pha_pin))
    {
        Pad_Config(pha_pin, PAD_PON_MODE, PAD_IS_PWRON, PAD_PULL_NONE,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
        Pad_FunctionConfig(pha_pin, LPQDEC_PHA_SEL);
    }
    if (IS_PIN_NUMBER(phb_pin))
    {
        Pad_Config(phb_pin, PAD_PON_MODE, PAD_IS_PWRON, PAD_PULL_NONE,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
        Pad_FunctionConfig(phb_pin, LPQDEC_PHB_SEL);
    }
}

/**
 * \brief  Release the PHA / PHB GPIO pads of an LPQDEC peripheral instance.
 *
 * LPQDEC is routed through the AON pad function registers rather than PINMUX,
 * so the pads are released by disabling the pad function itself: passing an
 * out-of-range pin number to Pad_FunctionConfig() clears the enable bit of the
 * given function. The pad is then handed back to software control and pulled
 * down, so the (input-only) pin does not float once the peripheral is gone.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  pha_pin  PHA GPIO pin number. Out-of-range values skip the pad config.
 * \param  phb_pin  PHB GPIO pin number. Out-of-range values skip the pad config.
 */
void LPQDEC_PadRelease(LPQDEC_TypeDef *LPQDECx, uint8_t pha_pin, uint8_t phb_pin)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (IS_PIN_NUMBER(pha_pin))
    {
        Pad_FunctionConfig(TOTAL_PIN_NUM, LPQDEC_PHA_SEL);
        Pad_Config(pha_pin, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_DOWN,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
    }
    if (IS_PIN_NUMBER(phb_pin))
    {
        Pad_FunctionConfig(TOTAL_PIN_NUM, LPQDEC_PHB_SEL);
        Pad_Config(phb_pin, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_DOWN,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
    }
}

#if (LPQDEC_SUPPORT_LED_FUNCTION == 1)
/**
 * \brief  Configure the optical-encoder LED output pad of an LPQDEC instance.
 *
 * The LED is an output driven by the LED_CTRL block, so unlike PHA / PHB the
 * pad is configured for output with a pull-up.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  led_pin  LED GPIO pin number. Out-of-range values skip the pad config.
 */
void LPQDEC_LedPadConfig(LPQDEC_TypeDef *LPQDECx, uint8_t led_pin)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (IS_PIN_NUMBER(led_pin))
    {
        Pad_Config(led_pin, PAD_PON_MODE, PAD_IS_PWRON, PAD_PULL_UP,
                   PAD_OUT_ENABLE, PAD_OUT_HIGH);
        Pad_FunctionConfig(led_pin, LPQDEC_LED_SEL);
    }
}

/**
 * \brief  Release the optical-encoder LED output pad of an LPQDEC instance.
 *
 * Releases by function, the same way as LPQDEC_PadRelease(). The pad is left
 * in software mode with its output disabled so the LED stops being driven.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  led_pin  LED GPIO pin number. Out-of-range values skip the pad config.
 */
void LPQDEC_LedPadRelease(LPQDEC_TypeDef *LPQDECx, uint8_t led_pin)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (IS_PIN_NUMBER(led_pin))
    {
        Pad_FunctionConfig(TOTAL_PIN_NUM, LPQDEC_LED_SEL);
        Pad_Config(led_pin, PAD_SW_MODE, PAD_IS_PWRON, PAD_PULL_DOWN,
                   PAD_OUT_DISABLE, PAD_OUT_LOW);
    }
}
#endif /* LPQDEC_SUPPORT_LED_FUNCTION */

/**
 * \brief  Enable or disable the LPQDEC peripheral clock.
 *
 * \param  LPQDECx  LPQDEC peripheral pointer.
 * \param  state    ENABLE or DISABLE.
 */
void LPQDEC_RccConfig(LPQDEC_TypeDef *LPQDECx, FunctionalState state)
{
    assert_param(IS_LPQDEC_PERIPH(LPQDECx));

    if (LPQDECx == LPQDEC)
    {
        RCC_ClockCmd(LPQDEC_CLOCK, state);
    }
}
