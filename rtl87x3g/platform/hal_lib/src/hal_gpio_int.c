/**
*********************************************************************************************************
*               Copyright(c) 2025, Realtek Semiconductor Corporation. All rights reserved.
**********************************************************************************************************
* @file     hal_gpio_int.c
* @brief    This file provides all the gpio hal interrupt functions.
* @details
* @author   colin
* @date     2025-03-19
* @version  v1.0
*********************************************************************************************************
*/
#include <stdint.h>
#include "rtl876x.h"
#include "rtl876x_gpio.h"
#include "rtl876x_nvic.h"
#include "rtl876x_pinmux.h"
#include "trace.h"
#include "vector_table.h"
#include "section.h"
#include "hal_gpio.h"
#include "hal_gpio_int.h"
#include "hal_pinmux.h"

#define TOTAL_HAL_GPIO_NUM                          (64)
#define TOTAL_HAL_GPIO_PORT_NUM                     (32)
#define TOTAL_HAL_PIN_NUM                           TOTAL_PIN_NUM

//#define PRINT_GPIO_LOGS
#ifdef PRINT_GPIO_LOGS
#define GPIO_PRINT_INFO(fmt, ...)                   DBG_DIRECT(fmt, __VA_ARGS__)
#else
#define GPIO_PRINT_INFO(...)
#endif

#define IS_GPIO_INVALID(gpio_num)                   ((gpio_num == 0xff) || (gpio_num >= TOTAL_HAL_GPIO_NUM))

extern T_GPIO_TYPE hal_gpio_get_type(uint8_t pin_index);
extern bool gpio_get_isr_by_gpio(uint8_t gpio_num, P_GPIO_CBACK *callback, uint32_t *context);
extern void gpio_int_init(void);
extern void GPIO_DebounceTimeToDivCnt(uint32_t debounce_time, GPIODebounceDiv_TypeDef *div,
                                      uint8_t *cnt);
extern void gpio_update_callback_context(uint8_t gpio_num, uint32_t context);
extern void goio_update_isr_callback(uint8_t gpio_num, P_GPIO_CBACK callback);

static uint32_t gpio_get_vector_number(uint8_t p_gpio_num)
{
    if (p_gpio_num == GPIOA0)
    {
        return  GPIOA0_VECTORn;
    }
    else if (p_gpio_num == GPIOA1)
    {
        return GPIOA1_VECTORn;
    }
    else if (p_gpio_num < GPIOA8)
    {
        return GPIOA2_VECTORn + p_gpio_num - GPIOA2;
    }
    else if (p_gpio_num < GPIOA16)
    {
        return GPIOA8_VECTORn + p_gpio_num - GPIOA8;
    }
    else if (p_gpio_num < GPIOA24)
    {
        return GPIOA16_VECTORn + p_gpio_num - GPIOA16;
    }
    else if (p_gpio_num < GPIOB0)
    {
        return GPIOA24_VECTORn + p_gpio_num - GPIOA24;
    }
    else if (p_gpio_num < GPIOB8)
    {
        return GPIOB0_VECTORn + p_gpio_num - GPIOB0;
    }
    else if (p_gpio_num < GPIOB16)
    {
        return GPIOB8_VECTORn + p_gpio_num - GPIOB8;
    }
    else if (p_gpio_num < GPIOB24)
    {
        return GPIOB16_VECTORn + p_gpio_num - GPIOB16;
    }
    else
    {
        return GPIOB24_VECTORn + p_gpio_num - GPIOB24;
    }
}

static IRQn_Type hal_gpio_get_irq_num(uint8_t p_gpio_num)
{
    if (p_gpio_num == GPIOA0)
    {
        return  GPIO_A0_IRQn;
    }
    else if (p_gpio_num == GPIOA1)
    {
        return GPIO_A1_IRQn;
    }
    else if (p_gpio_num < GPIOA8)
    {
        return GPIO_A2_7_IRQn;
    }
    else if (p_gpio_num < GPIOA16)
    {
        return GPIO_A8_15_IRQn;
    }
    else if (p_gpio_num < GPIOA24)
    {
        return GPIO_A16_23_IRQn;
    }
    else if (p_gpio_num < GPIOB0)
    {
        return GPIO_A24_31_IRQn;
    }
    else if (p_gpio_num < GPIOB8)
    {
        return GPIO_B0_7_IRQn;
    }
    else if (p_gpio_num < GPIOB16)
    {
        return GPIO_B8_15_IRQn;
    }
    else if (p_gpio_num < GPIOB24)
    {
        return GPIO_B16_23_IRQn;
    }
    else
    {
        return GPIO_B24_31_IRQn;
    }
}

static void hal_gpio_enable_nvic(uint8_t gpio_num, uint8_t proirity)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = hal_gpio_get_irq_num(gpio_num);
    NVIC_InitStruct.NVIC_IRQChannelPriority = proirity;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

bool hal_gpio_update_pin_table(void)
{
    return true;
}

static bool hal_gpio_register_isr_by_gpio(uint8_t gpio_num, P_GPIO_CBACK callback, uint32_t context)
{
    if (IS_GPIO_INVALID(gpio_num))
    {
        return false;
    }

    if ((gpio_num == GPIOA0) || (gpio_num == GPIOA1))
    {
        goio_update_isr_callback(gpio_num, callback);
    }
    else
    {
        RamVectorTableUpdate(gpio_get_vector_number(gpio_num), (IRQ_Fun)callback);
    }

    gpio_update_callback_context(gpio_num, context);

    hal_gpio_enable_nvic(gpio_num, 4);

    return true;
}

bool hal_gpio_register_isr_callback(uint8_t pin_index, P_GPIO_CBACK callback, uint32_t context)
{
    if (hal_gpio_get_type(pin_index) == GPIO_TYPE_AUTO)
    {
        hal_pad_register_pin_wake_callback(pin_index, (P_PIN_WAKEUP_CALLBACK)callback, context);
    }

    return hal_gpio_register_isr_by_gpio(GPIO_GetNum(pin_index), callback, context);
}

bool hal_gpio_get_isr_callback(uint8_t pin_index, P_GPIO_CBACK *callback, uint32_t *context)
{
    return gpio_get_isr_by_gpio(GPIO_GetNum(pin_index), callback, context);
}

static void hal_gpio_set_aon_debounce(uint8_t pin_index, uint32_t debounce_time)
{
    /* Config aon debounce */
    if (System_WakeUpDebounceEnable(pin_index))
    {
        System_WakeUpDebounceTime(pin_index, debounce_time);
        System_WakeupDebounceClear(pin_index);
        System_WakeUpDebounceCmd(pin_index, PAD_WAKEUP_ENABLE);
    }
}

T_GPIO_STATUS hal_gpio_set_pin_debounce_time(uint8_t pin_index, uint8_t ms)
{
    uint32_t gpio_pin = GPIO_GetPin(pin_index);
    GPIO_TypeDef *GPIOx = GPIO_GetPort(pin_index);
    GPIODebounceDiv_TypeDef div = 0;
    uint8_t cnt_limit = 0;

    GPIO_DebounceTimeToDivCnt(ms, &div, &cnt_limit);

    GPIO_ExtDebUpdate(GPIOx, gpio_pin, GPIO_DEBOUNCE_32K, div, cnt_limit);

    hal_gpio_set_aon_debounce(pin_index, ms);

    return GPIO_STATUS_OK;
}

void hal_gpio_convert_debounce_time(uint8_t pin_index, GPIO_InitTypeDef *GPIO_InitStruct,
                                    uint32_t debounce_time)
{
    if (GPIO_InitStruct->GPIO_ITDebounce == GPIO_INT_DEBOUNCE_ENABLE)
    {
        GPIO_DebounceTimeToDivCnt(debounce_time, &(GPIO_InitStruct->GPIO_DebounceClkDiv),
                                  &(GPIO_InitStruct->GPIO_DebounceCntLimit));

        hal_gpio_set_aon_debounce(pin_index, debounce_time);
    }
    else
    {
        System_WakeUpDebounceCmd(pin_index, PAD_WAKEUP_DISABLE);
        System_WakeUpDebounceDisable(pin_index);
    }
}

void hal_gpio_int_deinit(void)
{

}

void hal_gpio_int_init(void)
{

}
