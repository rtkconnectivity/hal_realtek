add_subdirectory_ifdef(CONFIG_RTK_UART uart)
add_subdirectory_ifdef(CONFIG_RTK_GPIO gpio)
add_subdirectory(rcc)
add_subdirectory(pinmux)
