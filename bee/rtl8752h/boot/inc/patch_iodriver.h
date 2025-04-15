/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_IODRIVER_H_
#define _PATCH_IODRIVER_H_

#include <patch.h>

#ifdef __cplusplus
extern "C" {
#endif

/* uart patch function pointer */
//extern BOOL_PATCH_FUNC patch_HCI_UART_Pin_Config;

/* cp patch function pointer */
#if 0
extern BOOL_PATCH_FUNC patch_cp_burst_read;
extern BOOL_PATCH_FUNC patch_cp_signal_read;
extern BOOL_PATCH_FUNC patch_cp_write;
extern BOOL_PATCH_FUNC patch_cp_reset;
extern BOOL_PATCH_FUNC patch_cp_hw_init;
#endif

/**@brief patch function pointer for gdma */
extern BOOL_PATCH_FUNC patch_GDMA_Init;
extern BOOL_PATCH_FUNC patch_GDMA_Cmd;
extern BOOL_PATCH_FUNC patch_GDMA_INTConfig;
extern BOOL_PATCH_FUNC patch_GDMA_ClearINTPendingBit;

/**@brief patch function pointer for high speed uart */
extern BOOL_PATCH_FUNC patch_UART_Init;
extern BOOL_PATCH_FUNC patch_UART_INTConfig;
extern BOOL_PATCH_FUNC patch_UART_ReceiveData;
extern BOOL_PATCH_FUNC patch_UART_SendData;

/**@brief patch function pointer for gpio */
//extern BOOL_PATCH_FUNC patch_GPIO_Init;
//extern BOOL_PATCH_FUNC patch_GPIO_INTConfig;
//extern BOOL_PATCH_FUNC patch_GPIO_ClearINTPendingBit;
//extern BOOL_PATCH_FUNC patch_GPIO_MaskINTConfig;
//extern BOOL_PATCH_FUNC patch_GPIO_GetPin;
//extern BOOL_PATCH_FUNC patch_GPIO_GetNum;

/**@brief patch function pointer for rcc */
extern BOOL_PATCH_FUNC patch_RCC_PeriphClockCmd;
extern BOOL_PATCH_FUNC patch_RCC_SPIClkDivConfig;
//extern BOOL_PATCH_FUNC patch_RCC_I2CClkDivConfig;
//extern BOOL_PATCH_FUNC patch_RCC_UARTClkDivConfig;
//extern BOOL_PATCH_FUNC patch_RCC_PeriClockConfig;
//extern BOOL_PATCH_FUNC patch_RCC_PeriFunctionConfig;
//extern BOOL_PATCH_FUNC patch_RCC_IRClockConfig;
//extern BOOL_PATCH_FUNC patch_RCC_SPIClockConfig;
//extern BOOL_PATCH_FUNC patch_RCC_TimerClockConfig;
/**@brief patch function pointer for i2c */
//extern BOOL_PATCH_FUNC patch_I2C_Init;

/**@brief patch function pointer for keyscan */

/**@brief patch function pointer for tim and pwm */
extern BOOL_PATCH_FUNC patch_TIM_TimeBaseInit;
extern BOOL_PATCH_FUNC patch_TIM_StructInit;
extern BOOL_PATCH_FUNC patch_TIM_Cmd;
extern BOOL_PATCH_FUNC patch_TIM_PWMChangeFreqAndDuty;
extern BOOL_PATCH_FUNC patch_TIM_PWMDeadzone_bypass;
extern BOOL_PATCH_FUNC patch_TIM_PWMChange_clock;
/**@brief patch function pointer for hw_aes */
/**@brief patch function pointer for nvic */

/**@brief patch function pointer for pinmux */
extern BOOL_PATCH_FUNC patch_Pinmux_Config;
extern BOOL_PATCH_FUNC patch_Pad_Config;
//extern BOOL_PATCH_FUNC patch_Pad_ConfigExt;
//extern BOOL_PATCH_FUNC patch_Pad_AllConfigDefault;
extern BOOL_PATCH_FUNC patch_System_WakeUpPinEnable;
extern BOOL_PATCH_FUNC patch_System_WakeUpPinDisable;
extern BOOL_PATCH_FUNC patch_System_WakeUpInterruptValue;

/**@brief patch function pointer for rtc */
extern BOOL_PATCH_FUNC patch_RTC_Register_Write;
//extern BOOL_PATCH_FUNC patch_RTC_WriteReg_Safe;
//extern BOOL_PATCH_FUNC patch_RTC_Reset;
//extern BOOL_PATCH_FUNC patch_RTC_NvIntEn;
//extern BOOL_PATCH_FUNC patch_RTC_CLKInSel;
//extern BOOL_PATCH_FUNC patch_BackupRegWrite;
/**@brief patch function pointer for wdg */
extern BOOL_PATCH_FUNC patch_WDG_Config;
extern BOOL_PATCH_FUNC patch_WDG_SystemReset;

#if 0
/**@brief patch function pointer for spi */
extern BOOL_PATCH_FUNC patch_SPI_Init;
extern BOOL_PATCH_FUNC patch_SPI_StructInit;
extern BOOL_PATCH_FUNC patch_SPI_ClearINTPendingBit;
#endif

#if 0
/**@brief patch function pointer for adc */
extern BOOL_PATCH_FUNC patch_ADC_Init;
extern BOOL_PATCH_FUNC patch_ADC_INTConfig;
extern BOOL_PATCH_FUNC patch_ADC_Read;
extern BOOL_PATCH_FUNC patch_ADC_Cmd;
extern BOOL_PATCH_FUNC patch_ADC_SchTableConfig;
extern BOOL_PATCH_FUNC patch_ADC_GetFifoData;
extern BOOL_PATCH_FUNC patch_ADC_HighBypassCmd;
extern BOOL_PATCH_FUNC patch_ADC_GetRes_rom;
extern BOOL_PATCH_FUNC patch_ADC_GetHighBypassRes_rom;
#endif

#ifdef __cplusplus
}
#endif

#endif /* _PATCH_IODRIVER_H_ */
