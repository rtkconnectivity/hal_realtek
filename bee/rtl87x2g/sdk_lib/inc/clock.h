/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*============================================================================*
 *               Define to prevent recursive inclusion
 *============================================================================*/
#ifndef __CLOCK_H_
#define __CLOCK_H_


/*============================================================================*
 *                               Header Files
*============================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "flash_nor_device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CLOCK Clock
  * @brief
  * @{
  */

/*============================================================================*
 *                              Variables
*============================================================================*/
/** @defgroup CLOCK_Exported_Variables Clock Exported Variables
  * @{
  */
typedef enum
{
    CLK_NO_PLL,
    CLK_PLL1_SRC,
    CLK_PLL2_SRC,
    CLK_PLL_SRC_MAX,
} PLL_CLK_SRC_TYPE;

/** End of CLOCK_Exported_Variables
  * @}
  */

/*============================================================================*
 *                              Functions
*============================================================================*/
/** @defgroup CLOCK_Exported_Functions Clock Exported Functions
  * @{
  */
/**
 * @brief Config cpu clock freq.
 * @param  require_mhz  require cpu freqency .
 * @param  real_mhz  the freqency of current cpu.
 * @return  Status of Operation.
*/
int32_t pm_cpu_freq_set(uint32_t required_mhz, uint32_t *actual_mhz);

/**
 * @brief Config cpu clock freq.
 * @param  require_mhz  require cpu slow freqency .
 * @return  Status of Operation.
*/
int32_t pm_cpu_slow_freq_set(uint32_t required_mhz);


/**
 * @brief Config SPIC0 clock freq.
 * @param  require_mhz  require SPIC0 freqency .
 * @param  real_mhz  the freqency of current SPIC0.
 * @return  Status of Operation.
*/
bool fmc_flash_nor_clock_switch(FLASH_NOR_IDX_TYPE idx, uint32_t required_mhz,
                                uint32_t *actual_mhz);

/**
 * @brief Config SPIC1 clock freq.
 * @param  require_mhz  require SPIC1 freqency .
 * @param  real_mhz  the freqency of current SPIC1.
 * @return  Status of Operation.
*/
int32_t pm_spic1_freq_set(uint32_t required_mhz, uint32_t *actual_mhz);

/**
 * @brief Config SPIC2 clock freq.
 * @param  require_mhz  require SPIC2 freqency .
 * @param  real_mhz  the freqency of current SPIC2.
 * @return  Status of Operation.
*/
int32_t pm_spic2_freq_set(uint32_t required_mhz, uint32_t *actual_mhz);

/**
 * @brief Config display clock freq.
 * @param  clk_src_type  switch display to PLLx clock .
 * @param  pll_output_mhz  require display freqency .
 * @param  required_mhz  require display freqency .
 * @return  Status of Operation.
*/
int32_t pm_display_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                            uint32_t required_mhz);

/**
 * @brief disable display clock freq.
 * @param  clk_src_type  switch display to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_display_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config sd host controller clock freq.
 * @param  clk_src_type  switch sd host controller to PLLx clock .
 * @param  pll_output_mhz  require sd host controller freqency .
 * @param  required_mhz  require sd host controller freqency .
 * @return  Status of Operation.
*/
int32_t pm_sdhc_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                         uint32_t required_mhz);

/**
 * @brief disable sd host controller clock freq.
 * @param  clk_src_type  switch sd host controller to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_sdhc_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config public key engine clock freq.
 * @param  clk_src_type  switch public key engine to PLLx clock .
 * @param  pll_output_mhz  require public key engine freqency .
 * @param  required_mhz  require public key engine freqency .
 * @return  Status of Operation.
*/
int32_t pm_pke_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                        uint32_t required_mhz);

/**
 * @brief disable public key engine clock freq.
 * @param  clk_src_type  switch public key engine to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_pke_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config ethernet clock freq.
 * @param  clk_src_type  switch ethernet to PLLx clock .
 * @param  pll_output_mhz  require ethernet freqency .
 * @param  required_mhz  require ethernet freqency .
 * @return  Status of Operation.
*/
int32_t pm_ethernet_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                             uint32_t required_mhz);

/**
 * @brief disable ethernet clock freq.
 * @param  clk_src_type  switch ethernet to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_ethernet_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config USB clock freq.
 * @param  clk_src_type  switch USB to PLLx clock .
 * @param  pll_output_mhz  require USB freqency .
 * @param  required_mhz  require USB freqency .
 * @return  Status of Operation.
*/
int32_t pm_usb_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                        uint32_t required_mhz);

/**
 * @brief disable USB clock freq.
 * @param  clk_src_type  switch USB to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_usb_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config hw timer clock freq.
 * @param  clk_src_type  switch hw timer to PLLx clock .
 * @param  pll_output_mhz  require hw timer freqency .
 * @param  required_mhz  require hw timer freqency .
 * @return  Status of Operation.
*/
int32_t pm_timer_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                          uint32_t required_mhz);

/**
 * @brief disable hw timer clock freq.
 * @param  clk_src_type  switch hw timer to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_timer_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);


/**
 * @brief Config enhanced_timer clock freq.
 * @param  clk_src_type  switch enhanced_timer to PLLx clock .
 * @param  pll_output_mhz  require enhanced_timer freqency .
 * @param  required_mhz  require enhanced_timer freqency .
 * @return  Status of Operation.
*/
int32_t pm_enhanced_timer_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                                   uint32_t required_mhz);

/**
 * @brief disable enhanced_timer clock freq.
 * @param  clk_src_type  switch enhanced_timer to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_enhanced_timer_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);

/**
 * @brief Config IR clock freq.
 * @param  clk_src_type  switch IR to PLLx clock .
 * @param  pll_output_mhz  require IR freqency .
 * @param  required_mhz  require IR freqency .
 * @return  Status of Operation.
*/
int32_t pm_ir_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                       uint32_t required_mhz);

/**
 * @brief disable IR clock freq.
 * @param  clk_src_type  switch IR to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_ir_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);

/**
 * @brief Config SPI0 master clock freq.
 * @param  clk_src_type  switch SPI0 master to PLLx clock .
 * @param  pll_output_mhz  require SPI0 master freqency .
 * @param  required_mhz  require SPI0 master freqency .
 * @return  Status of Operation.
*/
int32_t pm_spi0_master_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                                uint32_t required_mhz);

/**
 * @brief disable USB clock freq.
 * @param  clk_src_type  switch SPI0 master to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_spi0_master_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);

/**
 * @brief Config SPI0 slave clock freq.
 * @param  clk_src_type  switch SPI0 slave to PLLx clock .
 * @param  pll_output_mhz  require SPI0 slave freqency .
 * @param  required_mhz  require SPI0 slave freqency .
 * @return  Status of Operation.
*/
int32_t pm_spi0_slave_freq_set(PLL_CLK_SRC_TYPE clk_src_type, uint32_t pll_output_mhz,
                               uint32_t required_mhz);

/**
 * @brief disable SPI0 slave clock freq.
 * @param  clk_src_type  switch SPI0 slave to PLLx clock .
 * @return  Status of Operation.
*/
int32_t pm_spi0_slave_freq_unset(PLL_CLK_SRC_TYPE clk_src_type);

/** End of CLOCK_Exported_Functions
  * @}
  */

/** End of CLOCK
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif
