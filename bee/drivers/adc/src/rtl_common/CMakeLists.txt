zephyr_library()

zephyr_library_sources_ifdef(CONFIG_REALTEK_ADC rtl_adc.c)