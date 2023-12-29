/**
*****************************************************************************************
*     Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
* @file      adc_k_lib.c
* @brief     This file gets adc k values and calculates the sampling voltage.
* @author    echo
* @date      2021-09-10
* @version   v1.1.0
**************************************************************************************
* @attention
* <h2><center>&copy; COPYRIGHT 2021 Realtek Semiconductor Corporation</center></h2>
**************************************************************************************
*/

/*============================================================================*
 *                              Header Files
 *============================================================================*/
#include "adc_lib.h"
#include "ft_patch_efuse_table.h"
#include "nsc_veneer.h"
#include "nsc_veneer_param.h"
#define ADC_DEBUG                   0
#define PRINTF_ADC_K_VALUE          0

#if ((ADC_DEBUG == 1) || (PRINTF_ADC_K_VALUE == 1))
#include "trace.h"
#endif

/* Defines -----------------------------------------------------------------*/
EFUSE_FT_AUXADC auxadc;

#define PARA_A_MAGN     100000000
#define PARA_B_MAGN     10000
#define PARA_C_MAGN     10

/* Globals -----------------------------------------------------------------*/

void efuse_ram_read(uint16_t offset, uint8_t *data, uint16_t len)
{
    NSC_EFUSE_RAM_SECURE_ACCESS_PARAM param;
    param.type = EFUSE_OPERATION_READ;
    param.offset = offset;
    param.data = data;
    param.byte_size = len;
    secure_function_call(EFUSE_RAM_ACCESS, &param);
}

void adc_efuse_data_init(void)
{
    efuse_ram_read(offsetof(EFUSE_TABLE, ft_efuse_table) + offsetof(EFUSE_FT_TABLE, auxadc), \
                   (uint8_t *)&auxadc, EFUSE_FT_AUXADC_SIZE);
}

int32_t ADC_ApplyPara(int32_t RawData, float a, float b, float c)
{
    return (a* RawData / PARA_A_MAGN  * RawData) + (b * RawData / PARA_B_MAGN) + (c / PARA_C_MAGN);
}

int32_t ADC_GetRes(uint16_t RawData, uint8_t adcMode)
{
    int32_t retval = 0;

    EFUSE_FT_AUXADC *ft_auxadc_para = &auxadc;

    switch (adcMode)
    {
    case DIVIDE_SINGLE_MODE: // SE DIVIDE
        {
            if (!(ft_auxadc_para->auxadc_invalid.single_ended_divide))
            {
                retval = ADC_ApplyPara(RawData,
                                       (float)ft_auxadc_para->se_mode.divide_para_a,
                                       (float)ft_auxadc_para->se_mode.divide_para_b,
                                       (float)ft_auxadc_para->se_mode.divide_para_c);
#if PRINTF_ADC_K_VALUE
                DBG_DIRECT("DIVIDE_SINGLE_MODE: a = %d, b = %d, c = %d", ft_auxadc_para->se_mode.divide_para_a,
                           ft_auxadc_para->se_mode.divide_para_b,
                           ft_auxadc_para->se_mode.divide_para_c);
#endif

            }
            else
            {
                retval = (int32_t)(1000 * ((double)RawData + 47) / 900);
            }
        }
        break;
    case DIVIDE_DIFFERENTIAL_MODE: // DIFF DIVIDE
        {
            if (!(ft_auxadc_para->auxadc_invalid.differential_divide))
            {
                int32_t data_shift = RawData - 2048;

                retval = ADC_ApplyPara(data_shift,
                                       (double)ft_auxadc_para->df_mode.divide_para_a,
                                       (double)ft_auxadc_para->df_mode.divide_para_b,
                                       (double)ft_auxadc_para->df_mode.divide_para_c);
#if PRINTF_ADC_K_VALUE
                DBG_DIRECT("DIVIDE_DIFFERENTIAL_MODE: a = %d, b = %d, c = %d",
                           ft_auxadc_para->df_mode.divide_para_a,
                           ft_auxadc_para->df_mode.divide_para_b,
                           ft_auxadc_para->df_mode.divide_para_c);
#endif
            }
            else
            {
                retval = (int32_t)(((98500 * RawData) / 100000) - ((374 * RawData * RawData) / 100000000) - 62.121);
            }
        }
        break;
    }

    return retval;
}

/**
  * @brief  Get ADC Result in high bypass resistor mode.
  * @param  RawData: ADC raw data.
  * @param  adcMode:
  *      this parameter can be one of the following values:
  *     @arg EXT_SINGLE_ENDED(index)
  *     @arg EXT_DIFFERENTIAL(index)
  *     @arg VREF_AT_CHANNEL7(index)
  *     @arg INTERNAL_VBAT_MODE
  * @retval ADC result
  */

int32_t ADC_GetHighBypassRes(uint16_t RawData, uint8_t adcMode)
{
    int32_t retval = 0;

    EFUSE_FT_AUXADC *ft_auxadc_para = &auxadc;

    switch (adcMode)
    {
    case BYPASS_SINGLE_MODE: // single ended
        {
            if (!(ft_auxadc_para->auxadc_invalid.single_ended_bypass))
            {
                retval = ADC_ApplyPara(RawData,
                                       (double)ft_auxadc_para->se_mode.bypass_para_a,
                                       (double)ft_auxadc_para->se_mode.bypass_para_b,
                                       (double)ft_auxadc_para->se_mode.bypass_para_c);
#if PRINTF_ADC_K_VALUE
                DBG_DIRECT("BYPASS_SINGLE_MODE: a = %d, b = %d, c = %d", ft_auxadc_para->se_mode.bypass_para_a,
                           ft_auxadc_para->se_mode.bypass_para_b,
                           ft_auxadc_para->se_mode.bypass_para_c);
#endif
            }
            else
            {
                retval = (int32_t)(((22651 * RawData) / 100000) - ((169 * RawData * RawData) / 100000000) + 4);
            }
        }
        break;

    case BYPASS_DIFFERENTIAL_MODE: // differential
        {
            if (!(ft_auxadc_para->auxadc_invalid.differential_bypass))
            {
                int32_t data_shift = RawData - 2048;

                retval = ADC_ApplyPara(data_shift,
                                       (double)ft_auxadc_para->df_mode.bypass_para_a,
                                       (double)ft_auxadc_para->df_mode.bypass_para_b,
                                       (double)ft_auxadc_para->df_mode.bypass_para_c);
#if PRINTF_ADC_K_VALUE
                DBG_DIRECT("BYPASS_SINGLE_MODE: a = %d, b = %d, c = %d", ft_auxadc_para->df_mode.bypass_para_a,
                           ft_auxadc_para->df_mode.bypass_para_b,
                           ft_auxadc_para->df_mode.bypass_para_c);
#endif
            }
            else
            {
                retval = (int32_t)(((26621 * RawData) / 100000) - ((200 * RawData * RawData) / 100000000) - 27.86);
            }
        }
        break;
    }

    return retval;
}

/**
  * @brief  Get ADC efuse k value.
  * @param  No parameter.
  * @return true of false
  */
bool ADC_CalibrationInit(void)
{
    bool ret = false;

    adc_efuse_data_init();

    EFUSE_FT_AUXADC *ft_auxadc_para = &auxadc;
    if (!(ft_auxadc_para->auxadc_invalid.single_ended_divide &&
          ft_auxadc_para->auxadc_invalid.differential_divide
          && ft_auxadc_para->auxadc_invalid.single_ended_bypass &&
          ft_auxadc_para->auxadc_invalid.differential_bypass))
    {
        ret = true;
    }

    return ret;
}

int32_t ADC_GetVoltage(const ADC_SampleMode vSampleMode, int32_t vSampleData,
                     ADC_ErrorStatus *pErrorStatus)
{
    int32_t adc_sample_voltage = 0;
    if ((vSampleMode < 1) || (vSampleMode > 4) || (vSampleData < 0) || (vSampleData > 4095))
    {
        *pErrorStatus = PARAMETER_ERROR;
        return adc_sample_voltage;
    }
    switch ((uint8_t)vSampleMode)
    {
    case DIVIDE_SINGLE_MODE:
        adc_sample_voltage = ADC_GetRes(vSampleData, DIVIDE_SINGLE_MODE);
        break;
    case DIVIDE_DIFFERENTIAL_MODE:
        adc_sample_voltage = ADC_GetRes(vSampleData, DIVIDE_DIFFERENTIAL_MODE);
        break;
    case BYPASS_SINGLE_MODE:
        adc_sample_voltage = ADC_GetHighBypassRes(vSampleData, BYPASS_SINGLE_MODE);
        break;
    case BYPASS_DIFFERENTIAL_MODE:
        adc_sample_voltage = ADC_GetHighBypassRes(vSampleData, BYPASS_DIFFERENTIAL_MODE);
        break;
    default:
        *pErrorStatus = PARAMETER_ERROR;
        return adc_sample_voltage;
    }
    return adc_sample_voltage;
}



uint16_t ADC_GetResistance(void)
{
    EFUSE_FT_AUXADC *ft_auxadc_para = &auxadc;
    return ((double)ft_auxadc_para->divide_resistance_value);
}
