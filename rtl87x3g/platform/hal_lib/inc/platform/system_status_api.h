/*
 * Copyright (c) 2026, Realtek Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __SYSTEM_STATUS_API_H_
#define __SYSTEM_STATUS_API_H_


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>


#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup HAL_SYSTEM_STATUS_API System Status API
  * @{
  */
/*============================================================================*
 *                              Variables
*============================================================================*/
/** @defgroup HAL_SYSTEM_STATUS_API_EXPORTED_VARIABLES HAL System Status Exported Variables
  * @{
  */

typedef enum
{
    CUT_VERSION_C_AND_D_CUT,
    CUT_VERSION_E_CUT,
    CUT_VERSION_F_CUT,// to do
    CUT_VERSION_A_CUT_RTL87x3G,
    CUT_VERSION_B_CUT_RTL87x3G,
    CUT_VERSION_MAX_NUM
} T_CUT_VERSION;

typedef enum
{
    SHARE_DSP_RAM_48K, //Share 48K ram from DSP to MCU. bank14~bank16 0x20070000~0x20078000
    SHARE_DSP_RAM_80K, //Share 80K ram from DSP to MCU. bank22~bank26 0x20048000~0x2005c000
    SHARE_DSP_RAM_128K, //Share 128K ram from DSP to MCU. bank14~bank21 0x2005c000~0x20078000
    SHARE_DSP_RAM_160K, //Share 160K ram from DSP to MCU. bank17~bank26 0x20048000~0x20070000
    SHARE_DSP_RAM_208K, //Share 208K ram from DSP to MCU. bank14~bank26 0x20048000~0x2007c000
    SHARE_DSP_RAM_448K //Share 448K ram from DSP to MCU. bank0~bank27 0x20048000~0x200b8000
} T_DSP_SHARE_MODE;

/** @} */ /* End of group HAL_SYSTEM_STATUS_API_EXPORTED_VARIABLES */

/** @defgroup HAL_SYSTEM_STATUS_API_EXPORTED_FUNCTIONS System Status API
  * @{
  */
/*============================================================================*
 *                              Functions
*============================================================================*/

/**
    * @brief  Get the reset status to tell apart whether the mcu reboot from software reset or hardware reset.
    * @return Whether reboot from software reset.
    * @retval  true   Reboot from software reset.
    * @retval  false  Reboot from hardware reset.
    */
bool sys_hall_get_reset_status(void);

/**
    * @brief  Print wake up reason after mcu power down.
    */
void sys_hall_get_power_down_info(void);

/**
    * @brief  Get adpater level
    * @return The result to get adpater level.
    * @retval true  Fail to get adpater level.
    * @retval false Success to get adpater level.
    */
bool sys_hall_adp_read_adp_level(void);

/**
    * @brief  Share 80k ram from dsp to mcu.
    * @param is_off_ram  Whether the memory shared from dsp is off ram or not.
    */
void sys_hall_set_dsp_share_memory_80k(bool is_off_ram);

/**
    * @brief  Share all ram from dsp to mcu.
    */
void sys_hall_set_dsp_share_memory_all(void);

/**
    * @brief  Share ram from dsp to mcu.
    * @param share_mode T_DSP_SHARE_MODE.
    */
void sys_hall_set_dsp_share_memory(T_DSP_SHARE_MODE share_mode);

/**
    * @brief  Read register value of aon register safely.
    * @param  input_info Offerset of aon register.
    * @param  output_info The read value to aon register.
    */
void sys_hall_btaon_fast_read_safe(uint16_t *input_info, uint16_t *output_info);

/**
    * @brief  Store register value of aon register safely.
    * @param  offset Offerset of aon register.
    * @param  input_info The value store to aon register.
    */
void sys_hall_btaon_fast_write_safe(uint16_t offset, uint16_t *input_info);

/**
    * @brief  Get package id of IC.
    * @return Chip id of IC.
    */
uint8_t sys_hall_read_package_id(void);

/**
    * @brief  Get chip id of IC.
    * @return Chip id of IC
    */
uint8_t sys_hall_read_chip_id(void);

/**
    * @brief  Get rom version of IC.
    * @return Rom version of IC.
    */
uint8_t sys_hall_read_rom_version(void);

/**
    * @brief  Get 14 bytes euid of IC.
    * @return Euid of IC.
    */
uint8_t *sys_hall_get_ic_euid(void);

/**
    * @brief  Get RTL87X3D/RTL87X3G cut version.
    * @warning This API is only supported in RTL87x3D and RTL87X3G.
    *          It is NOT supported in RTL87x3E.
    * @retval CUT_VERSION_C_AND_D_CUT   Cut C and D of RTL87X3D.
    * @retval CUT_VERSION_E_CUT         Cut E of RTL87X3D.
    * @retval CUT_VERSION_F_CUT         Cut F of RTL87X3D.
    * @retval CUT_VERSION_A_CUT_X3G     Cut A of RTL87X3G.
    * @retval CUT_VERSION_B_CUT_X3G     Cut B of RTL87X3G.
    * @retval CUT_VERSION_MAX_NUM       Cut version is unavailable.
    */
T_CUT_VERSION sys_hall_get_cut_version(void);

/**
    * @brief  Init upperstack
    * @note   Temporarily unavailable.
    * @param  upperstack_compile_stamp  The time compile upperstack.
    */
void sys_hall_upperstack_ini(uint8_t *upperstack_compile_stamp);

/**
    * @brief  Set vp src image addr
    * @note   Temporarily unavailable.
    * @param  image_addr The image address of vp source.
    */
void sys_hall_vp_src(uint32_t *image_addr);

/**
    * @brief  Enable or disable auto sleep in idle task
    * @note   Temporarily unavailable.
    * @param  flag  Specify the flag as true or false to enable or disable auto sleep in idle.
    */
void sys_hall_auto_sleep_in_idle(bool flag);

/**
    * @brief  Read efuse data on ram.
    * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Added API"
    * @note   Prepare enough data space to read the efuse on ram, and the reading space should be valid in the efuse space.
    * @param  offset  Specify the efuse offset to read.
    * @param  length  Specify the length to read.
    * @param  data    Specify the data buffer to store the efuse data.
    * @return The result to read efuse.
    * @retval  true  Read efuse successfully, refer the efuse data by the data parameter.
    * @retval  false Check the parameter fail before reading efuse data.
    */
bool  read_efuse_on_ram(uint16_t offset, uint16_t length, uint8_t *data);

/**
    * @brief  Get IC secure state.
    * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Added API"
    * @return Whether secure is enabled.
    * @retval true  Secure is enabled.
    * @retval false Secure is disabled.
    */
bool sys_hall_get_secure_state(void);

/**
 * \brief   Get RHA key valid result.
 * \xrefitem Experimental_Added_API_2_14_0_0 "Experimental Added Since 2.14.0.0" "Added API"
 * @warning This API is only supported in RTL87x3D.
 * \return  The RHA key valid check result.
 */
bool check_rha_key_valid(void);

/** @} */ /* End of group HAL_SYSTEM_STATUS_API_Exported_Functions */
/** End of HAL_SYSTEM_STATUS_API
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif
