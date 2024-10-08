if(NOT DEFINED CONFIG_REALTEK_USING_RTL876X_DRIVER)
    zephyr_include_directories(inc)
endif()

add_subdirectory(src)
