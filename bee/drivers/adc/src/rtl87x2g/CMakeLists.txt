zephyr_library()

zephyr_library_sources_ifdef(CONFIG_REALTEK_ADC_ADC rtl87x2g_adc.c)
