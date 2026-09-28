/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _PATCH_IODRIVER_H_
#define _PATCH_IODRIVER_H_

#include <patch.h>
#include "rtl876x_trng.h"
#include "rtl876x_adc.h"
#include "rtl876x_wdg.h"
#include "rtl876x_pinmux.h"
#include "rtl876x_uart.h"
#include "rtl876x_nvic.h"
#include "rtl876x_gdma.h"
#include "rtl876x_tim.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ======================= Patch of TRNG ======================================== */
void init_true_random_generator_rom(void);
uint32_t get_true_random_number_rom(void);
/* ============================================================================== */

/* ======================= Patch of ADC ========================================= */
extern bool (*patch_ADC_DeInit)(ADC_TypeDef *ADCx);
extern bool (*patch_ADC_Init)(ADC_TypeDef *ADCx, ADC_InitTypeDef *ADC_InitStruct);
extern bool (*patch_ADC_StructInit)(ADC_InitTypeDef *ADC_InitStruct);
extern bool (*patch_ADC_Cmd)(ADC_TypeDef *ADCx, ADCOperationMode_TypeDef AdcMode,
                             FunctionalState NewState);
extern bool (*patch_ADC_INTConfig)(ADC_TypeDef *ADCx, uint32_t ADC_IT, FunctionalState NewState);
extern bool (*patch_ADC_ReadRawData)(ADC_TypeDef *ADCx, uint8_t Index, uint16_t *p_ret);
extern bool (*patch_ADC_ReadAvgRawData)(ADC_TypeDef *ADCx, uint16_t *p_ret);
extern bool (*patch_ADC_ReadFIFO)(ADC_TypeDef *ADCx, uint16_t *p_ret);
extern bool (*patch_ADC_ReadFIFOData)(ADC_TypeDef *ADCx, uint16_t *outBuf, uint16_t Num);
extern bool (*patch_ADC_GetFIFODataLen)(ADC_TypeDef *ADCx, uint8_t *p_ret);
extern bool (*patch_ADC_SchTableConfig)(ADC_TypeDef *ADCx, uint16_t Index, uint8_t AdcMode);
extern bool (*patch_ADC_BitMapConfig)(ADC_TypeDef *ADCx, uint16_t BitMap, FunctionalState NewState);
extern bool (*patch_ADC_WriteFIFOCmd)(ADC_TypeDef *ADCx, FunctionalState NewState);
extern bool (*patch_ADC_BypassCmd)(uint8_t ChannelNum, FunctionalState NewState);
extern bool (*patch_ADC_GetINTStatus)(ADC_TypeDef *ADCx, uint32_t ADC_INT, ITStatus *p_ret);
extern bool (*patch_ADC_ClearINTPendingBit)(ADC_TypeDef *ADCx, uint32_t ADC_INT);
extern bool (*patch_ADC_ClearFIFO)(ADC_TypeDef *ADCx);
extern bool (*patch_ADC_GetAllFlagStatus)(ADC_TypeDef *ADCx, uint8_t *p_ret);
extern bool (*patch_ADC_StopwriteFifoStatusClear)(ADC_TypeDef *ADCx);
extern bool (*patch_ADC_ManualModeConfig)(void);
extern bool (*patch_ADC_PowerAlwaysOnCmd)(ADC_TypeDef *ADCx, FunctionalState NewState);
extern bool (*patch_ADC_GetRes)(uint16_t RawData, uint8_t adcMode, int32_t *p_ret);
extern bool (*patch_ADC_GetHighBypassRes)(uint16_t RawData, uint8_t adcMode, int32_t *p_ret);

/**@brief patch function pointer for NVIC */
extern bool (*patch_NVIC_Init)(NVIC_InitTypeDef *NVIC_InitStruct);

/**@brief patch function pointer for RCC */
extern bool (*patch_RCC_PeriphClockCmd)(uint32_t APBPeriph, uint32_t APBPeriph_Clock,
                                        FunctionalState NewState);
extern bool (*patch_RCC_PeriClockConfig)(uint32_t APBPeriph_Clock, FunctionalState NewState);
extern bool (*patch_RCC_PeriFunctionConfig)(uint32_t APBPeriph, FunctionalState NewState);

/**@brief patch function pointer for wdg */
extern bool (*patch_WDG_Calculate_Config)(uint32_t timeout_ms, uint16_t *div_factor,
                                          uint8_t *cnt_limit, bool *retval);
extern bool (*patch_WDG_Config)(uint16_t div_factor, uint8_t  cnt_limit, T_WDG_MODE  wdg_mode);
extern bool (*patch_WDG_Set_Core)(T_WDG_TYPE type);
extern bool (*patch_WDG_Start_Core)(uint32_t ms, T_WDG_MODE wdg_mode, bool *retval);

/**@brief patch function pointer for timer */
extern bool (*patch_TIM_ClkConfig)(TIM_TypeDef *TIMx, uint16_t ClockSrc, uint16_t ClockDiv);
extern bool (*patch_TIM_TimeBaseInit)(TIM_TypeDef *TIMx,
                                      TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);
extern bool (*patch_TIM_StructInit)(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);
extern bool (*patch_TIM_Cmd)(TIM_TypeDef *TIMx, FunctionalState NewState);
extern bool (*patch_TIM_ChangePeriod)(TIM_TypeDef *TIMx, uint32_t period);
extern bool (*patch_TIM_InterruptConfig)(TIM_TypeDef *TIMx, uint8_t TIM_INT,
                                         FunctionalState NewState);
extern bool (*patch_TIM_GetCurrentValue)(TIM_TypeDef *TIMx, uint32_t *p_ret);
extern bool (*patch_TIM_GetInterruptStatus)(TIM_TypeDef *TIMx, uint8_t TIM_INT, ITStatus *p_ret);
extern bool (*patch_TIM_ClearInterrupt)(TIM_TypeDef *TIMx, uint8_t TIM_INT);
extern bool (*patch_TIM_GetTimerID)(TIM_TypeDef *TIMx, uint32_t *p_ret);
extern bool (*patch_TIM_GetTimerCase)(TIM_TypeDef *TIMx, TIMCASE_TypeDef *p_ret);
extern bool (*patch_TIM_GetTimerShareBase)(TIM_TypeDef *TIMx, TIM_ShareTypeDef **p_ret);
extern bool (*patch_TIM_PWMDZClockConfig)(TIM_TypeDef *TIMx, uint16_t ClockSrc, uint16_t ClockDiv);
extern bool (*patch_TIM_LatchTrigDebClkConfig)(TIMClockDiv_TypeDef ClockDiv,
                                               FunctionalState Newstate);
extern bool (*patch_TIM_LatchTrigDebConfig)(uint16_t LatchTrigDebSize, FunctionalState Newstate);
extern bool (*patch_TIM_LatchTrigPad)(uint16_t LatchTrigPad);

/**@brief patch function pointer for gdma */
extern bool (*patch_GDMA_Init)(GDMA_ChannelTypeDef *GDMA_Channelx,
                               GDMA_InitTypeDef *GDMA_InitStruct);
extern bool (*patch_GDMA_Cmd)(uint8_t GDMA_ChannelNum, FunctionalState NewState, uint8_t *retval);
extern bool (*patch_GDMA_INTConfig)(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT,
                                    FunctionalState NewState);
extern bool (*patch_GDMA_ClearINTPendingBit)(uint8_t GDMA_ChannelNum, uint32_t GDMA_IT);
extern bool (*patch_GDMA_SafeSuspend)(GDMA_ChannelTypeDef *GDMA_Channelx, bool *retval);
extern bool (*patch_GDMA_SuspendCmd)(GDMA_ChannelTypeDef *GDMA_Channelx, FunctionalState NewState);
extern bool (*patch_GDMA_GetSuspendCmdStatus)(GDMA_ChannelTypeDef *GDMA_Channelx,
                                              FlagStatus *retval);
extern bool (*patch_GDMA_GetSuspendChannelStatus)(GDMA_ChannelTypeDef *GDMA_Channelx,
                                                  FlagStatus *retval);

/**@brief patch function pointer for pinmux */
extern bool (*patch_Pad_TableConfig)(AON_FAST_PAD_BIT_POS_TYPE pad_bit_set, uint8_t Pin_Num,
                                     uint8_t value);
extern bool (*patch_Pinmux_Config)(uint8_t Pin_index, uint8_t Pin_Func);
extern bool (*patch_Pinmux_Deinit)(uint8_t Pin_index);
extern bool (*patch_Pad_Config)(uint8_t Pin_Num, PAD_Mode AON_PAD_Mode, PAD_PWR_Mode AON_PAD_PwrOn,
                                PAD_Pull_Mode AON_PAD_Pull, PAD_OUTPUT_ENABLE_Mode AON_PAD_E, PAD_OUTPUT_VAL AON_PAD_O);
extern bool (*patch_Pad_ConfigExt)(uint8_t Pin_Num,
                                   PAD_Mode AON_PAD_Mode,
                                   PAD_PWR_Mode AON_PAD_PwrOn,
                                   PAD_Pull_Mode AON_PAD_Pull,
                                   PAD_OUTPUT_ENABLE_Mode AON_PAD_E,
                                   PAD_OUTPUT_VAL AON_PAD_O,
                                   PAD_PULL_VAL AON_PAD_P);
extern bool (*patch_Pad_AllConfigDefault)(void);
extern bool (*patch_System_WakeUpPinEnable)(uint8_t Pin_Num, uint8_t Polarity);
extern bool (*patch_System_WakeUpPinDisable)(uint8_t Pin_Num);
extern bool (*patch_Pad_ClearAllWakeupINT)(void);
extern bool (*patch_Pad_GetModeConfig)(AON_FAST_PAD_BIT_POS_TYPE mode, uint8_t Pin_Num,
                                       uint8_t *retval);
extern bool (*patch_Pad_WakeUpCmd)(WAKEUP_EN_MODE mode, WAKEUP_POL pol, FunctionalState NewState,
                                   uint8_t *retval);
extern bool (*patch_Pad_HighSpeedMuxSel)(uint8_t Pin_Num, PAD_HS_MUX_SEL_TYPE Pad_Hs_Mux,
                                         bool *retval);
extern bool (*patch_Pad_HighSpeedFuncSel)(uint8_t Pin_Num, PAD_HS_FUNC_SEL_TYPE Pad_HS_Func_Sel,
                                          bool *retval);
extern bool (*patch_Pad_AnalogMode)(uint8_t Pin_Num, ANA_MODE mode);

/**@brief patch function pointer for uart */
extern bool (*patch_UART_Init)(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct);
extern bool (*patch_UART_ReceiveData)(UART_TypeDef *UARTx, uint8_t *outBuf, uint16_t count);
extern bool (*patch_UART_SendData)(UART_TypeDef *UARTx, const uint8_t *inBuf, uint16_t count);
extern bool (*patch_UART_INTConfig)(UART_TypeDef *UARTx, uint32_t UART_IT,
                                    FunctionalState newState);


extern bool (*patch_UART_SetBaudRate)(UART_TypeDef *UARTx, UartBaudRate_TypeDef baud_rate,
                                      uint8_t *retval);


extern bool (*patch_UART_MaskINTConfig)(UART_TypeDef *UARTx, uint32_t UART_INT_MASK,
                                        FunctionalState NewState);
extern bool (*patch_UART_TxData)(UART_TypeDef *UARTx, uint8_t *data, uint32_t len);
extern bool (*patch_UART_ConvUartBaudRate)(uint32_t baudrate, UartBaudRate_TypeDef *retval);
extern bool (*patch_UART_ComputeDiv)(uint16_t *div, uint16_t *ovsr, uint16_t *ovsr_adj,
                                     UartBaudRate_TypeDef rate, bool *retval);

/* ============================================================================== */
#ifdef __cplusplus
}
#endif

#endif /* _PATCH_IODRIVER_H_ */
