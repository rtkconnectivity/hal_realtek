# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(rtl876x_adc.c)

zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libadc.a)

if (CONFIG_PM_DEVICE)
if(CONFIG_REALTEK_ADC)
zephyr_library_sources(rtl8752h_adc.c)
if (CONFIG_REALTEK_DRIVER_DLPS_CALLBACK_ON_RAM)
zephyr_code_relocate(FILES rtl8752h_adc.c LOCATION RAM)
endif()
endif()
endif()
