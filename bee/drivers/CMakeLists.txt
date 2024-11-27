# Copyright (c) 2024 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0
zephyr_include_directories(.)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_ADC adc)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_UART uart)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_RCC rcc)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_PINMUX pinmux)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_NVIC nvic)

if (CONFIG_REALTEK_BEE_TIM OR CONFIG_REALTEK_BEE_ENHTIM)
add_subdirectory(tim)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_RTC rtc)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_DMA dma)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_GPIO gpio)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_I2C i2c)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_KEYSCAN keyscan)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_AON_QDEC qdec)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_SPI spi)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_USB usb)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_BT bluetooth)

add_subdirectory_ifdef(CONFIG_REALTEK_BEE_PPT ppt)

if (CONFIG_REALTEK_BEE_CORE_WDT OR CONFIG_REALTEK_BEE_AON_WDT)
add_subdirectory(wdt)
endif()

if (CONFIG_REALTEK_BEE_MAC_802154)
add_subdirectory(mac_802154)
endif()
