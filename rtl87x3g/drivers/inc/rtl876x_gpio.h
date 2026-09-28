/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: LicenseRef-Realtek-5-Clause
 */

#ifndef RTL876X_GPIO_H
#define RTL876X_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/*============================================================================*
 *                        Header Files
 *============================================================================*/
#include "rtl876x.h"
#include "rtl876x_gpio_def.h"

/**
 * @brief GPIO Number value.
 */
#ifdef GPIOA
#define GPIOA0   0
#define GPIOA1   1
#define GPIOA2   2
#define GPIOA3   3
#define GPIOA4   4
#define GPIOA5   5
#define GPIOA6   6
#define GPIOA7   7
#define GPIOA8   8
#define GPIOA9   9
#define GPIOA10  10
#define GPIOA11  11
#define GPIOA12  12
#define GPIOA13  13
#define GPIOA14  14
#define GPIOA15  15
#define GPIOA16  16
#define GPIOA17  17
#define GPIOA18  18
#define GPIOA19  19
#define GPIOA20  20
#define GPIOA21  21
#define GPIOA22  22
#define GPIOA23  23
#define GPIOA24  24
#define GPIOA25  25
#define GPIOA26  26
#define GPIOA27  27
#define GPIOA28  28
#define GPIOA29  29
#define GPIOA30  30
#define GPIOA31  31
#endif
#ifdef GPIOB
#define GPIOB0   32
#define GPIOB1   33
#define GPIOB2   34
#define GPIOB3   35
#define GPIOB4   36
#define GPIOB5   37
#define GPIOB6   38
#define GPIOB7   39
#define GPIOB8   40
#define GPIOB9   41
#define GPIOB10  42
#define GPIOB11  43
#define GPIOB12  44
#define GPIOB13  45
#define GPIOB14  46
#define GPIOB15  47
#define GPIOB16  48
#define GPIOB17  49
#define GPIOB18  50
#define GPIOB19  51
#define GPIOB20  52
#define GPIOB21  53
#define GPIOB22  54
#define GPIOB23  55
#define GPIOB24  56
#define GPIOB25  57
#define GPIOB26  58
#define GPIOB27  59
#define GPIOB28  60
#define GPIOB29  61
#define GPIOB30  62
#define GPIOB31  63
#endif
#ifdef GPIOC
#define GPIOC0   64
#define GPIOC1   65
#define GPIOC2   66
#define GPIOC3   67
#define GPIOC4   68
#define GPIOC5   69
#define GPIOC6   70
#define GPIOC7   71
#define GPIOC8   72
#define GPIOC9   73
#define GPIOC10  74
#define GPIOC11  75
#define GPIOC12  76
#define GPIOC13  77
#define GPIOC14  78
#define GPIOC15  79
#define GPIOC16  80
#define GPIOC17  81
#define GPIOC18  82
#define GPIOC19  83
#define GPIOC20  84
#define GPIOC21  85
#define GPIOC22  86
#define GPIOC23  87
#define GPIOC24  88
#define GPIOC25  89
#define GPIOC26  90
#define GPIOC27  91
#define GPIOC28  92
#define GPIOC29  93
#define GPIOC30  94
#define GPIOC31  95
#endif
#ifdef GPIOD
#define GPIOD0   96
#define GPIOD1   97
#define GPIOD2   98
#define GPIOD3   99
#define GPIOD4   100
#define GPIOD5   101
#define GPIOD6   102
#define GPIOD7   103
#define GPIOD8   104
#define GPIOD9   105
#define GPIOD10  106
#define GPIOD11  107
#define GPIOD12  108
#define GPIOD13  109
#define GPIOD14  110
#define GPIOD15  111
#define GPIOD16  112
#define GPIOD17  113
#define GPIOD18  114
#define GPIOD19  115
#define GPIOD20  116
#define GPIOD21  117
#define GPIOD22  118
#define GPIOD23  119
#define GPIOD24  120
#define GPIOD25  121
#define GPIOD26  122
#define GPIOD27  123
#define GPIOD28  124
#define GPIOD29  125
#define GPIOD30  126
#define GPIOD31  127
#endif

/** @
  * @brief Macros to lookup GPIO handler based on gpio number
  */
#define XGPIO_HANDLER(num)     GPIO ## num ## _Handler
#define GPIO_HANDLER(num)      XGPIO_HANDLER(num)

/**
 * @brief Macros to lookup GPIO index based on Pin number.
 */
#define XGPIO_INDEX(pin_num)   PIN ## pin_num ## _GPIO_INDEX
#define GPIO_INDEX(pin_num)    XGPIO_INDEX(pin_num)


/** @
  * @brief GPIO Number to IRQ Lookup Macro
  */
#define GPIO0_IRQ_NUM GPIO0_IRQn
#define GPIO1_IRQ_NUM GPIO1_IRQn
#define GPIO2_IRQ_NUM GPIO2_IRQn
#define GPIO3_IRQ_NUM GPIO3_IRQn
#define GPIO4_IRQ_NUM GPIO4_IRQn
#define GPIO5_IRQ_NUM GPIO5_IRQn
#define GPIO6_IRQ_NUM GPIO6_IRQn
#define GPIO7_IRQ_NUM GPIO7_IRQn
#define GPIO8_IRQ_NUM GPIO8_IRQn
#define GPIO9_IRQ_NUM GPIO9_IRQn
#define GPIO10_IRQ_NUM GPIO10_IRQn
#define GPIO11_IRQ_NUM GPIO11_IRQn
#define GPIO12_IRQ_NUM GPIO12_IRQn
#define GPIO13_IRQ_NUM GPIO13_IRQn
#define GPIO14_IRQ_NUM GPIO14_IRQn
#define GPIO15_IRQ_NUM GPIO15_IRQn
#define GPIO16_IRQ_NUM GPIO16_IRQn
#define GPIO17_IRQ_NUM GPIO17_IRQn
#define GPIO18_IRQ_NUM GPIO18_IRQn
#define GPIO19_IRQ_NUM GPIO19_IRQn
#define GPIO20_IRQ_NUM GPIO20_IRQn
#define GPIO21_IRQ_NUM GPIO21_IRQn
#define GPIO22_IRQ_NUM GPIO22_IRQn
#define GPIO23_IRQ_NUM GPIO23_IRQn
#define GPIO24_IRQ_NUM GPIO24_IRQn
#define GPIO25_IRQ_NUM GPIO25_IRQn
#define GPIO26_IRQ_NUM GPIO26_IRQn
#define GPIO27_IRQ_NUM GPIO27_IRQn
#define GPIO28_IRQ_NUM GPIO28_IRQn
#define GPIO29_IRQ_NUM GPIO29_IRQn
#define GPIO30_IRQ_NUM GPIO30_IRQn
#define GPIO31_IRQ_NUM GPIO31_IRQn
#define GPIO32_IRQ_NUM GPIOB0_IRQn
#define GPIO33_IRQ_NUM GPIOB1_IRQn
#define GPIO34_IRQ_NUM GPIOB2_IRQn
#define GPIO35_IRQ_NUM GPIOB3_IRQn
#define GPIO36_IRQ_NUM GPIOB4_IRQn
#define GPIO37_IRQ_NUM GPIOB5_IRQn
#define GPIO38_IRQ_NUM GPIOB6_IRQn
#define GPIO39_IRQ_NUM GPIOB7_IRQn
#define GPIO40_IRQ_NUM GPIOB8_IRQn
#define GPIO41_IRQ_NUM GPIOB9_IRQn
#define GPIO42_IRQ_NUM GPIOB10_IRQn
#define GPIO43_IRQ_NUM GPIOB11_IRQn
#define GPIO44_IRQ_NUM GPIOB12_IRQn
#define GPIO45_IRQ_NUM GPIOB13_IRQn
#define GPIO46_IRQ_NUM GPIOB14_IRQn
#define GPIO47_IRQ_NUM GPIOB15_IRQn
#define GPIO48_IRQ_NUM GPIOB16_IRQn
#define GPIO49_IRQ_NUM GPIOB17_IRQn
#define GPIO50_IRQ_NUM GPIOB18_IRQn
#define GPIO51_IRQ_NUM GPIOB19_IRQn
#define GPIO52_IRQ_NUM GPIOB20_IRQn
#define GPIO53_IRQ_NUM GPIOB21_IRQn
#define GPIO54_IRQ_NUM GPIOB22_IRQn
#define GPIO55_IRQ_NUM GPIOB23_IRQn
#define GPIO56_IRQ_NUM GPIOB24_IRQn
#define GPIO57_IRQ_NUM GPIOB25_IRQn
#define GPIO58_IRQ_NUM GPIOB26_IRQn
#define GPIO59_IRQ_NUM GPIOB27_IRQn
#define GPIO60_IRQ_NUM GPIOB28_IRQn
#define GPIO61_IRQ_NUM GPIOB29_IRQn
#define GPIO62_IRQ_NUM GPIOB30_IRQn
#define GPIO63_IRQ_NUM GPIOB31_IRQn

/**
 * @brief Macros to lookup GPIO IRQ number based on GPIO number.
 */
#define XGPIO_IRQ_NUM(gpio_num)   GPIO ## gpio_num ## _IRQ_NUM
#define GPIO_IRQ_NUM(gpio_num)    XGPIO_IRQ_NUM(gpio_num)


/** @addtogroup 87x3g_GPIO GPIO
  * @brief GPIO driver module.
  * @{
  */

/*============================================================================*
 *                         Constants
 *============================================================================*/
/** @defgroup 87x3g_GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup 87x3g_GPIO_pins_define GPIO Pins Define
  * @{
  */
#define GPIO_Pin_0                 (BIT0)   /*!< Pin 0 selected.    */
#define GPIO_Pin_1                 (BIT1)   /*!< Pin 1 selected.    */
#define GPIO_Pin_2                 (BIT2)   /*!< Pin 2 selected.    */
#define GPIO_Pin_3                 (BIT3)   /*!< Pin 3 selected.    */
#define GPIO_Pin_4                 (BIT4)   /*!< Pin 4 selected.    */
#define GPIO_Pin_5                 (BIT5)   /*!< Pin 5 selected.    */
#define GPIO_Pin_6                 (BIT6)   /*!< Pin 6 selected.    */
#define GPIO_Pin_7                 (BIT7)   /*!< Pin 7 selected.    */
#define GPIO_Pin_8                 (BIT8)   /*!< Pin 8 selected.    */
#define GPIO_Pin_9                 (BIT9)   /*!< Pin 9 selected.    */
#define GPIO_Pin_10                (BIT10)  /*!< Pin 10 selected.   */
#define GPIO_Pin_11                (BIT11)  /*!< Pin 11 selected.   */
#define GPIO_Pin_12                (BIT12)  /*!< Pin 12 selected.   */
#define GPIO_Pin_13                (BIT13)  /*!< Pin 13 selected.   */
#define GPIO_Pin_14                (BIT14)  /*!< Pin 14 selected.   */
#define GPIO_Pin_15                (BIT15)  /*!< Pin 15 selected.   */
#define GPIO_Pin_16                (BIT16)  /*!< Pin 16 selected.   */
#define GPIO_Pin_17                (BIT17)  /*!< Pin 17 selected.   */
#define GPIO_Pin_18                (BIT18)  /*!< Pin 18 selected.   */
#define GPIO_Pin_19                (BIT19)  /*!< Pin 19 selected.   */
#define GPIO_Pin_20                (BIT20)  /*!< Pin 20 selected.   */
#define GPIO_Pin_21                (BIT21)  /*!< Pin 21 selected.   */
#define GPIO_Pin_22                (BIT22)  /*!< Pin 22 selected.   */
#define GPIO_Pin_23                (BIT23)  /*!< Pin 23 selected.   */
#define GPIO_Pin_24                (BIT24)  /*!< Pin 24 selected.   */
#define GPIO_Pin_25                (BIT25)  /*!< Pin 25 selected.   */
#define GPIO_Pin_26                (BIT26)  /*!< Pin 26 selected.   */
#define GPIO_Pin_27                (BIT27)  /*!< Pin 27 selected.   */
#define GPIO_Pin_28                (BIT28)  /*!< Pin 28 selected.   */
#define GPIO_Pin_29                (BIT29)  /*!< Pin 29 selected.   */
#define GPIO_Pin_30                (BIT30)  /*!< Pin 30 selected.   */
#define GPIO_Pin_31                (BIT31)  /*!< Pin 31 selected.   */
#define GPIO_Pin_All               ((uint32_t)0xFFFFFFFF)  /*!< All pins selected. */

#define IS_GET_GPIO_PIN(PIN)       (((PIN) == GPIO_Pin_0) || \
                                    ((PIN) == GPIO_Pin_1) || \
                                    ((PIN) == GPIO_Pin_2) || \
                                    ((PIN) == GPIO_Pin_3) || \
                                    ((PIN) == GPIO_Pin_4) || \
                                    ((PIN) == GPIO_Pin_5) || \
                                    ((PIN) == GPIO_Pin_6) || \
                                    ((PIN) == GPIO_Pin_7) || \
                                    ((PIN) == GPIO_Pin_8) || \
                                    ((PIN) == GPIO_Pin_9) || \
                                    ((PIN) == GPIO_Pin_10) || \
                                    ((PIN) == GPIO_Pin_11) || \
                                    ((PIN) == GPIO_Pin_12) || \
                                    ((PIN) == GPIO_Pin_13) || \
                                    ((PIN) == GPIO_Pin_14) || \
                                    ((PIN) == GPIO_Pin_15) || \
                                    ((PIN) == GPIO_Pin_16) || \
                                    ((PIN) == GPIO_Pin_17) || \
                                    ((PIN) == GPIO_Pin_18) || \
                                    ((PIN) == GPIO_Pin_19) || \
                                    ((PIN) == GPIO_Pin_20) || \
                                    ((PIN) == GPIO_Pin_21) || \
                                    ((PIN) == GPIO_Pin_22) || \
                                    ((PIN) == GPIO_Pin_23) || \
                                    ((PIN) == GPIO_Pin_24) || \
                                    ((PIN) == GPIO_Pin_25) || \
                                    ((PIN) == GPIO_Pin_26) || \
                                    ((PIN) == GPIO_Pin_27) || \
                                    ((PIN) == GPIO_Pin_28) || \
                                    ((PIN) == GPIO_Pin_29) || \
                                    ((PIN) == GPIO_Pin_30) || \
                                    ((PIN) == GPIO_Pin_31) || \
                                    ((PIN) == GPIO_Pin_All)) //!< Check if the input parameter is valid.

#define IS_GPIO_PIN(PIN)          ((PIN) != (uint32_t)0x00) //!< Check if the input parameter is valid.

/** End of group 87x3g_GPIO_pins_define
  * @}
  */

/**
 * \defgroup    87x3g_GPIO_Bit_Action GPIO Bit Action
 * \{
 */
typedef enum
{
    Bit_RESET = 0, //!< Reset the GPIO bit.
    Bit_SET //!< Set the GPIO bit.
} BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET)) //!< Check if the input parameter is valid.
/** End of group 87x3g_GPIO_Bit_Action
  * @}
  */

/**
 * \defgroup    87x3g_GPIO_Direction GPIO Direction
 * \{
 */
typedef enum
{
    GPIO_Mode_IN   = 0x0, /**< GPIO input direction. */
    GPIO_Mode_OUT  = 0x1, /**< GPIO output direction. */
} GPIODir_TypeDef;

#define IS_GPIO_DIR(DIR) (((DIR) == GPIO_Mode_IN) || ((DIR) == GPIO_Mode_OUT))

/** End of 87x3g_GPIO_Direction
  * \}
  */

/**
 * \defgroup    87x3g_GPIO_Output_Mode GPIO Output Mode
 * \{
 */
typedef enum
{
    GPIO_OUTPUT_PUSHPULL  = 0x0, /**< GPIO output push-pull mode. */
    GPIO_OUTPUT_OPENDRAIN = 0x1, /**< GPIO output opendrain mode. */
} GPIOOutputMode_TypeDef;

#define IS_GPIO_OUTPUT_MODE(MODE) (((MODE) == GPIO_OUTPUT_PUSHPULL)|| ((MODE) == GPIO_OUTPUT_OPENDRAIN)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Output_Mode
  * \}
  */

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
/**
 * \defgroup    87x3g_GPIO_Control_Mode GPIO Control Mode
 * \{
 */
typedef enum
{
    GPIO_SOFTWARE_MODE = 0x0, /**< GPIO software mode(default). */
    GPIO_HARDWARE_MODE  = 0x1, /**< GPIO hardware control mode.  */
} GPIOControlMode_Typedef;

#define IS_GPIOIT_MODDE(TYPE) (((TYPE) == GPIO_SOFTWARE_MODE)\
                               || ((TYPE) == GPIO_HARDWARE_MODE)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Control_Mode
  * \}
  */
#endif

/**
 * \defgroup    87x3g_GPIO_Interrupt_Trigger GPIO Interrupt Trigger
 * \{
 */
typedef enum
{
    GPIO_INT_TRIGGER_LEVEL = 0x0,     /**< This interrupt is level trigger. */
    GPIO_INT_TRIGGER_EDGE  = 0x1,     /**< This interrupt is edge trigger. */
#if GPIO_SUPPORT_INT_BOTHEDGE
    GPIO_INT_TRIGGER_BOTH_EDGE = 0x2, /**< This interrupt is both edge trigger. */
#endif
} GPIOITTrigger_TypeDef;

#define IS_GPIOIT_TRIGGER_TYPE(TYPE) (((TYPE) == GPIO_INT_TRIGGER_LEVEL) || \
                                      ((TYPE) == GPIO_INT_TRIGGER_EDGE)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Interrupt_Trigger
  * \}
  */

/**
 * \defgroup    87x3g_GPIO_Interrupt_Polarity GPIO Interrupt Polarity
 * \{
 */
typedef enum
{
    GPIO_INT_POLARITY_ACTIVE_LOW  = 0x0, /**< Set interrupt polarity to low active. */
    GPIO_INT_POLARITY_ACTIVE_HIGH = 0x1, /**< Set interrupt polarity to high active. */
} GPIOITPolarity_TypeDef;

#define IS_GPIOIT_POLARITY_TYPE(TYPE) (((TYPE) == GPIO_INT_POLARITY_ACTIVE_LOW) || \
                                       ((TYPE) == GPIO_INT_POLARITY_ACTIVE_HIGH)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Interrupt_Polarity
  * \}
  */

/**
 * \defgroup    87x3g_GPIO_Interrupt_Debounce GPIO Interrupt Debounce
 * \{
 */
typedef enum
{
    GPIO_INT_DEBOUNCE_DISABLE = 0x0, /**< Disable interrupt debounce. */
    GPIO_INT_DEBOUNCE_ENABLE  = 0x1, /**< Enable interrupt debounce.  */
} GPIODebounce_TypeDef;

#define IS_GPIOIT_DEBOUNCE_TYPE(TYPE) (((TYPE) == GPIO_INT_DEBOUNCE_DISABLE) || \
                                       ((TYPE) == GPIO_INT_DEBOUNCE_ENABLE)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Interrupt_Debounce
  * \}
  */

/**
 * \defgroup    87x3g_GPIO_Debounce_Source GPIO Debounce Source
 * \{
 */
typedef enum
{
    GPIO_DEBOUNCE_32K = 0x0, /**< GPIO debounce source is 32KHz. */
} GPIODebounceSrc_TypeDef;

#define IS_GPIO_DEBOUNCE_SRC_TYPE(TYPE) (((TYPE) == GPIO_DEBOUNCE_32K)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Debounce_Source
  * \}
  */

/**
 * \defgroup    87x3g_GPIO_Debounce_Divide GPIO Debounce Divide
 * \{
 */
typedef enum
{
    GPIO_DEBOUNCE_DIVIDER_1  = 0x0, /**< GPIO debounce divider value is 1. */
    GPIO_DEBOUNCE_DIVIDER_2  = 0x1, /**< GPIO debounce divider value is 2. */
    GPIO_DEBOUNCE_DIVIDER_4  = 0x2, /**< GPIO debounce divider value is 4. */
    GPIO_DEBOUNCE_DIVIDER_8  = 0x3, /**< GPIO debounce divider value is 8. */
    GPIO_DEBOUNCE_DIVIDER_16 = 0x4, /**< GPIO debounce divider value is 16. */
    GPIO_DEBOUNCE_DIVIDER_32 = 0x5, /**< GPIO debounce divider value is 32. */
    GPIO_DEBOUNCE_DIVIDER_64 = 0x6, /**< GPIO debounce divider value is 64. */
} GPIODebounceDiv_TypeDef;

#define IS_GPIO_DEBOUNCE_DIV_TYPE(TYPE) (((TYPE) == GPIO_DEBOUNCE_DIVIDER_1) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_2) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_4) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_8) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_16) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_32) || \
                                         ((TYPE) == GPIO_DEBOUNCE_DIVIDER_64)) //!< Check if the input parameter is valid.

/** End of 87x3g_GPIO_Debounce_Divide
  * \}
  */

/** End of group 87x3g_GPIO_Exported_Constants
  * @}
  */

/*============================================================================*
 *                         Types
 *============================================================================*/
/** @defgroup 87x3g_GPIO_Exported_Types GPIO Exported Types
  * @{
  */

/**
 * \brief       GPIO init structure definition.
 */
typedef struct
{

    uint32_t                GPIO_PinBit;           /**< Specifies the GPIO pins to be configured.
                                                     This parameter can be a value of \ref x3g_GPIO_pins_define. */

    GPIODir_TypeDef         GPIO_Mode;           /**< Specifies the GPIO direction.
                                                     This parameter can be a value of \ref x3g_GPIO_Direction. */

    GPIOOutputMode_TypeDef  GPIO_OutPutMode;    /**< Specifies the GPIO output mode.
                                                     This parameter can be a value of \ref x3g_GPIO_Output_Mode. */

#if (GPIO_SUPPORT_SET_CONTROL_MODE == 1)
    GPIOControlMode_Typedef GPIO_ControlMode;   /**< Specifies the GPIO control mode.
                                                             This parameter can be a value of \ref x3g_GPIO_Control_Mode. */
#endif

    FunctionalState         GPIO_ITCmd;         /**< Enable or disable GPIO interrupt.
                                                             This parameter can be a value of DISABLE or ENABLE. */

    GPIOITTrigger_TypeDef   GPIO_ITTrigger;     /**< Specifies the GPIO interrupt trigger type.
                                                             This parameter can be a value of \ref x3g_GPIO_Interrupt_Trigger. */

    GPIOITPolarity_TypeDef  GPIO_ITPolarity;    /**< Specifies the GPIO interrupt polarity.
                                                             This parameter can be a value of \ref x3g_GPIO_Interrupt_Polarity. */

    GPIODebounce_TypeDef    GPIO_ITDebounce;    /**< Enable or disable debounce for interrupt.
                                                     This parameter can be a value of \ref x3g_GPIO_Interrupt_Debounce. */

    GPIODebounceSrc_TypeDef GPIO_DebounceClkSource; /**< Specifies the GPIO debounce clock source.
                                                     This parameter can be a value of \ref x3g_GPIO_Debounce_Source. */

    GPIODebounceDiv_TypeDef GPIO_DebounceClkDiv;    /**< Specifies the GPIO debounce divider value.
                                                     This parameter can be a value of \ref x3g_GPIO_Debounce_Divide. */

    uint8_t                 GPIO_DebounceCntLimit;  /**< Specifies the GPIO debounce count limit.
                                                         Debounce_time = (CntLimit + 1) * DEB_CLK. */
} GPIO_InitTypeDef;

/** End of group 87x3g_GPIO_Exported_Types
  * @}
  */

/*============================================================================*
 *                         Functions
 *============================================================================*/
/** @defgroup 87x3g_GPIO_Exported_Functions GPIO Exported Functions
  * @{
  */

/**
 * \brief   Deinitializes the GPIO peripheral registers to their default reset values (turn off clock).
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     GPIO_DeInit(GPIOA);
 * }
 * \endcode
 */
void GPIO_DeInit(GPIO_TypeDef *GPIOx);

/**
 * \brief  Initializes the GPIO peripheral according to the specified
 *         parameters in the GPIO_InitStruct.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_InitStruct: Pointer to a \ref GPIO_InitTypeDef structure that
 *            contains the configuration information for the specified GPIO peripheral.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd       = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger   = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity  = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = GPIOA0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);

 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIOx_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * \brief    Fills each GPIO_InitStruct member with its default value.
 *
 * \note   The default settings for the GPIO_InitStruct member are shown in the following table:
 *         | GPIO_InitStruct Member | Default Value                     |
 *         |:----------------------:|:---------------------------------:|
 *         | GPIO_Pin               | \ref GPIO_Pin_All                 |
 *         | GPIO_Dir               | \ref GPIO_DIR_IN                  |
 *         | GPIO_ITCmd             | DISABLE                           |
 *         | GPIO_ITTrigger         | \ref GPIO_INT_TRIGGER_LEVEL       |
 *         | GPIO_ITPolarity        | \ref GPIO_INT_POLARITY_ACTIVE_LOW |
 *         | GPIO_ITDebounce        | \ref GPIO_INT_DEBOUNCE_DISABLE    |
 *         | GPIO_ControlMode       | \ref GPIO_SOFTWARE_MODE           |
 *         | GPIO_DebounceClkSource | \ref GPIO_DEBOUNCE_32K            |
 *         | GPIO_DebounceClkDiv    | \ref GPIO_DEBOUNCE_DIVIDER_1      |
 *         | GPIO_DebounceCntLimit  | 32                                |
 *
 * \param[in]  GPIO_InitStruct: Pointer to a \ref GPIO_InitTypeDef structure which will
 *             be initialized.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin        = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir        = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd      = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger  = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 * }
 * \endcode
 */
void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

/**
 * \brief   Enable the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] NewState: Enable or disable the specified GPIO pin interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable the specified GPIO pin interrupt.
 *            - DISABLE: Disable the specified GPIO pin interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void driver_gpio_init(void)
 * {
 *     RCC_PeriphClockCmd(APBPeriph_GPIOA, APBPeriph_GPIOA_CLOCK, ENABLE);
 *
 *     GPIO_InitTypeDef GPIO_InitStruct;
 *     GPIO_StructInit(&GPIO_InitStruct);
 *     GPIO_InitStruct.GPIO_Pin         = GPIO_GetPinBit(P0_0);
 *     GPIO_InitStruct.GPIO_Dir         = GPIO_DIR_IN;
 *     GPIO_InitStruct.GPIO_OutPutMode  = GPIO_OUTPUT_PUSHPULL;
 *     GPIO_InitStruct.GPIO_ITCmd       = ENABLE;
 *     GPIO_InitStruct.GPIO_ITTrigger   = GPIO_INT_TRIGGER_EDGE;
 *     GPIO_InitStruct.GPIO_ITPolarity  = GPIO_INT_POLARITY_ACTIVE_LOW;
 *     GPIO_InitStruct.GPIO_ITDebounce  = GPIO_INT_DEBOUNCE_ENABLE;
 *     GPIO_InitStruct.GPIO_DebounceClkSource = GPIO_DEBOUNCE_32K;
 *     GPIO_InitStruct.GPIO_DebounceClkDiv    = GPIO_DEBOUNCE_DIVIDER_1;
 *     GPIO_InitStruct.GPIO_DebounceCntLimit  = 20;
 *     GPIO_Init(GPIOA, &GPIO_InitStruct);
 *
 *     NVIC_InitTypeDef NVIC_InitStruct;
 *     NVIC_InitStruct.NVIC_IRQChannel = GPIOA0_IRQn;
 *     NVIC_InitStruct.NVIC_IRQChannelPriority = 3;
 *     NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
 *     NVIC_Init(&NVIC_InitStruct);

 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_INTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief   Clear the specified GPIO pin interrupt pending bit.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     driver_gpio_init();
 * }
 *
 * void GPIOA0_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *     //Add user code here.
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
}
 * \endcode
 */
void GPIO_ClearINTPendingBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Config whether mask the specified GPIO pin interrupt.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] NewState: Enable or disable mask the specified GPIO pin interrupt.
 *            This parameter can be one of the following values:
 *            - ENABLE: Enable mask the specified GPIO pin interrupt.
 *            - DISABLE: Disable mask the specified GPIO pin interrupt.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *     driver_gpio_init();
 * }
 *
 * void GPIOA0_Handler(void)
 * {
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 *
 *     //Add user code here.
 *
 *     GPIO_ClearINTPendingBit(GPIOA, GPIO_GetPinBit(P0_0));
 *     GPIO_MaskINTConfig(GPIOA, GPIO_GetPinBit(P0_0), DISABLE);
 *     GPIO_INTConfig(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_MaskINTConfig(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief   Get GPIO group through the given pin number.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return  GPIOx: GPIO peripheral \ref x3g_GPIO_Declaration.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 *
 * void gpio_demo(void)
 * {
 *      GPIO_TypeDef gpio_port = GPIO_GetPort(P0_0);
 *      //result: gpio_port is GPIOA
 * }
 *
 * \endcode
 */
GPIO_TypeDef *GPIO_GetPort(uint8_t Pin_num);

/**
 * \brief   Get the GPIO_Pin through the given Pin_num.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return  GPIO_Pin_x, where x can be 0 ~ 31 \ref x3g_GPIO_pins_define.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t gpio_pin = GPIO_GetPinBit(P0_0);
 *     //result: gpio_pin is GPIO_Pin_0
 * }
 * \endcode
 */
uint32_t GPIO_GetPinBit(uint8_t Pin_num);

/**
 * \brief   Get GPIO number value through the given pin number.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return  GPIO number value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t gpio_num = GPIO_GetNum(P0_0);
 *     //result: gpio_num = 0, i.e. GPIOA0.
 *     GPIOx = gpio_num <= GPIOA31 ? GPIOA : GPIOB;
 * }
 * \endcode
 */
uint8_t GPIO_GetNum(uint8_t Pin_num);

/**
 * \brief   Enable GPIO debounce clock.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] NewState: Disable or enable debounce clock.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_DBClkCmd(GPIOA, GPIO_GetPinBit(P0_0), ENABLE);
 * }
 * \endcode
 */
void GPIO_ExtDebCmd(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, FunctionalState NewState);

/**
 * \brief  Set GPIO debounce parameters.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in]  GPIO_DebounceClkSource: Debounce clock source \ref x3g_GPIO_Debounce_Source.
 * \param[in]  GPIO_DebounceClkDiv: Debounce divider selection \ref x3g_GPIO_Debounce_Divide.
 * \param[in]  GPIO_DebounceCntLimit: Debounce count limit, debounce time = (CntLimit + 1) * DEB_CLK.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ExtDebUpdate(GPIOA, GPIO_GetPinBit(P0_0), GPIO_DEBOUNCE_32K, GPIO_DEBOUNCE_DIVIDER_1, 20);
 * }
 * \endcode
 */
void GPIO_ExtDebUpdate(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                       GPIODebounceSrc_TypeDef GPIO_DebounceClkSource,
                       GPIODebounceDiv_TypeDef GPIO_DebounceClkDiv, uint8_t GPIO_DebounceCntLimit);

/**
 * \brief   Read the specified input port pin.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * \return  The input port pin value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t input_bit = GPIO_ReadInputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Read value of all GPIO input data port.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 *
 * \return GPIO input data port value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t input_data = GPIO_ReadInputData(GPIOA);
 * }
 * \endcode
 */
uint32_t GPIO_ReadInputData(GPIO_TypeDef *GPIOx);

/**
 * \brief   Read the specified output port pin.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * \return The output port pin value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint8_t output_bit = GPIO_ReadOutputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Read value of all GPIO output data port.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 *
 * \return  GPIO output data port value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     uint32_t output_data = GPIO_ReadOutputData(GPIOA);
 * }
 * \endcode
 */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef *GPIOx);

/**
 * \brief   Sets the selected data port bit.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Reset the selected data port bit.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ResetBits(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Set or clear the selected data port bit.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] BitVal: Specifies the value to be written to the selected bit \ref x3g_GPIO_Bit_Action.
 *            This parameter can be one of the BitAction enum values:
 *            - Bit_RESET: To clear the port pin.
 *            - Bit_SET: To set the port pin.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_WriteBit(GPIOA, GPIO_GetPinBit(P0_0), Bit_SET);
 * }
 * \endcode
 */
void GPIO_WriteBit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, BitAction BitVal);

/**
 * \brief  Set or clear the selected data port.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] PortVal: Specifies the value to be written to the selected port. This parameter must range from 0x0 to 0xFFFFFFFF.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_Write(GPIOA, 0xFFFFFFFF);
 * }
 * \endcode
 */
void GPIO_Write(GPIO_TypeDef *GPIOx, uint32_t PortVal);

/**
 * \brief  Check whether the GPIO interrupt of the specified pin has occurred or not.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * \return The new state of GPIO interrupt.
 * \retval SET: The interrupt of the specified GPIO pin has occurred.
 * \retval RESET: The interrupt of the specified GPIO pin has not occurred.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     ITStatus int_status = GPIO_GetINTStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
ITStatus GPIO_GetINTStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief  Specifies the direction for the selected pins.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_PinBit: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] GPIO_Dir: Set the GPIO direction \ref x3g_GPIO_Direction.
 *            This parameter can be one of the following values:
 *            \arg GPIO_DIR_IN: The direction is input.
 *            \arg GPIO_DIR_OUT: The direction is output.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetDirection(GPIOA, GPIO_GetPinBit(P3_0), GPIO_DIR_IN);
 * }
 * \endcode
 */
void GPIO_SetDirection(GPIO_TypeDef *GPIOx, uint32_t GPIO_PinBit,
                       GPIODir_TypeDef GPIO_Dir);

/**
 * \brief  Set GPIO output mode.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] GPIO_OutputMode: Specifies the output mode to be set \ref x3g_GPIO_Output_Mode.
 *            This parameter can be one of the GPIOOutputMode_TypeDef enum values:
 *            \arg GPIO_OUTPUT_OPENDRAIN: Set output push-pull mode.
 *            \arg GPIO_OUTPUT_PUSHPULL: Set output open-drain mode.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SetOutputMode(GPIOA, GPIO_GetPinBit(P0_0), GPIO_OUTPUT_OPENDRAIN);
 * }
 * \endcode
 */
void GPIO_SetOutputMode(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                        GPIOOutputMode_TypeDef GPIO_OutputMode);

/**
 * \brief  Get GPIO pad status.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 *
 * \return The new state of GPIO_Pad (SET or RESET).
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     FlagStatus pad_status = GPIO_GetPadStatus(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
FlagStatus GPIO_GetPadStatus(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);

/**
 * \brief   Set the polarity that triggers the GPIO interrupt.
 *
 * \param[in] GPIOx: Where x can be A or B to select the GPIO peripheral \ref x3g_GPIO_Declaration.
 * \param[in] GPIO_Pin: Specifies the GPIO pins to be configured, please refer to \ref x3g_GPIO_pins_define.
 *            This parameter can be one of the following values:
 *            - GPIO_Pin_x, where x can be 0 ~ 31.
 * \param[in] int_type: Specifies the polarity type to be set.
 *            This parameter can be one of the GPIOITPolarity_TypeDef enum values:
 *            - GPIO_INT_POLARITY_ACTIVE_LOW: Set interrupt to low active.
 *            - GPIO_INT_POLARITY_ACTIVE_HIGH: Set interrupt to high active.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void GPIO_Init(void)
 * {
 *     GPIO_SetPolarity(GPIOx, GPIO_GetPinBit(P0_0), GPIO_INT_POLARITY_ACTIVE_LOW);
 * }
 * \endcode
 */
void GPIO_SetPolarity(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin,
                      GPIOITPolarity_TypeDef int_type);

#if (GPIO_SUPPORT_REMAPPING_FUNCTION == 1)
/**
 * \brief   Choose which pin to connect to the input of GPIO.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_SelectRemappingPAD(P0_0);
 *     GPIO_ReadInputDataBit(GPIOA, GPIO_GetPinBit(P0_0));
 * }
 * \endcode
 */
void GPIO_SelectRemappingPAD(uint8_t Pin_num);

/**
 * \brief   Read the specified input port pin by pin number.
 *
 * \param[in] Pin_num: Pin number to be configured, please refer to \ref x3g_Pin_Number.
 *
 * \return  The input port pin value.
 *
 * <b>Example usage</b>
 * \code{.c}
 *
 * void gpio_demo(void)
 * {
 *     GPIO_ReadInputDataBitByPinNum(P0_0);
 * }
 * \endcode
 */
uint8_t GPIO_ReadInputDataBitByPinNum(uint8_t Pin_num);
#endif

/** @} */ /* End of group 87x3g_GPIO_Exported_Functions */
/** @} */ /* End of group 87x3g_GPIO */

#ifdef __cplusplus
}
#endif

#endif /* RTL876X_GPIO_H */


