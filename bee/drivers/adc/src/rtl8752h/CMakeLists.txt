# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(rtl876x_adc.c)

zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libadc.a)

zephyr_library_sources_ifdef(CONFIG_REALTEK_ADC rtl8752h_adc.c)
