zephyr_include_directories(inc)

FILE(GLOB ota_sources src/*.c)

zephyr_sources_ifdef(
    CONFIG_RTK_OTA
    ${ota_sources}
	# src/ota_service.c
    # src/silent_ota_application.c
    # src/ota_task.c
    # src/dfu_service.c
    # src/dfu_application.c
    # src/dfu_task.c
    # src/dfu_main.c
    # src/dfu_flash.c
    # src/ota_service.c
)
