zephyr_library()

if(CONFIG_REALTEK_TIM)
zephyr_library_sources(rtl876x_tim.c)
endif()

if(CONFIG_REALTEK_ENHTIM)
zephyr_library_sources(rtl876x_enh_tim.c)
endif()
