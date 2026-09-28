# Copyright (c) 2025 Realtek Semiconductor Corp.
# SPDX-License-Identifier: Apache-2.0

set(REALTEK_SUBSYS_LIBS "")

if(CONFIG_REALTEK_SUBSYS_GAP)
    zephyr_include_directories(bluetooth/gap_ext/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/gap_ext/lib/libgap_utils.a)
endif()

if(CONFIG_REALTEK_SUBSYS_UPPERSTACK)
    zephyr_include_directories(bluetooth/bt_host/inc)
    zephyr_include_directories(bluetooth/bt_host/lib)
    if(CONFIG_REALTEK_LIBS_NANDBOOT)
        list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/bt_host/lib/upperstack_nandboot.a)
    else()
        list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/bt_host/lib/upperstack.a)
    endif()
elseif(CONFIG_REALTEK_SUBSYS_UPPERSTACK_HRP)
    zephyr_include_directories(bluetooth/bt_host/inc)
    zephyr_include_directories(bluetooth/bt_host/lib)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/bt_host/lib/upperstack_hrp.a)
endif()

# if CONFIG_REALTEK_SUBSYS_UPPERSTACK_HRP is true,
# then remote lib should link before btm lib
if(CONFIG_REALTEK_SUBSYS_REMOTE)
    zephyr_include_directories(remote/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/remote/lib/libremote.a)
endif()
if(CONFIG_REALTEK_SUBSYS_BTM)
    zephyr_include_directories(btm/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/btm/lib/libbtm.a)
endif()
if(CONFIG_REALTEK_SUBSYS_AUDIO)
    zephyr_include_directories(audio/inc)
    if(CONFIG_REALTEK_LIBS_NANDBOOT)
        list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/audio/lib/libaudio_nandboot.a)
    else()
        list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/audio/lib/libaudio.a)
    endif()
endif()
if(CONFIG_REALTEK_SUBSYS_SYSM)
    zephyr_include_directories(sysm/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/sysm/lib/libsysm.a)
endif()
if(CONFIG_REALTEK_SUBSYS_CONSOLE)
    zephyr_include_directories(console/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/console/lib/libconsole.a)
endif()

if(CONFIG_REALTEK_SUBSYS_BLE_MGR)
    zephyr_include_directories(bluetooth/ble_mgr/inc)
    zephyr_include_directories(bluetooth/ble_mgr/inc/bond)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/ble_mgr/lib/libble_mgr.a)
endif()

if(CONFIG_REALTEK_SUBSYS_BLE_AUDIO)
    zephyr_include_directories(bluetooth/leaudio/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/bluetooth/leaudio/lib/libleaudio.a)
endif()

if(CONFIG_REALTEK_SUBSYS_GFPS)
    zephyr_include_directories(gfps/inc)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/gfps/lib/libgfps.a)
endif()

if(CONFIG_REALTEK_SUBSYS_LWIP)
    zephyr_include_directories(lwip/src/include)
    zephyr_include_directories(lwip/src)
    zephyr_include_directories(lwip/src/arch)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/lwip/lib/liblwip.a)
endif()

if(CONFIG_REALTEK_SUBSYS_MBEDTLS)
    zephyr_include_directories(mbedtls/include)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers/builtin/include)
    zephyr_include_directories(mbedtls/tf-psa-crypto/include)
    zephyr_include_directories(mbedtls/include/library)
    zephyr_include_directories(mbedtls/include/library/tf-psa-crypto)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers/builtin)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers/builtin/include)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers/builtin/mbedtls)
    zephyr_include_directories(mbedtls/tf-psa-crypto/drivers/builtin/src)
    zephyr_include_directories(mbedtls/tf-psa-crypto/core)
    zephyr_include_directories(mbedtls/tf-psa-crypto/include/psa)
    zephyr_include_directories(mbedtls/tf-psa-crypto/include)
    zephyr_include_directories(mbedtls/include/mbedtls)
    zephyr_include_directories(mbedtls/library)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/mbedtls/lib/libmbedtls.a)
endif()

if(CONFIG_REALTEK_SUBSYS_USB)
    zephyr_include_directories(usb/inc)
    zephyr_include_directories(usb/inc/bc12)
    zephyr_include_directories(usb/inc/class)
    zephyr_include_directories(usb/inc/composite)
    zephyr_include_directories(usb/inc/hal)
    zephyr_include_directories(usb/inc/host)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/usb/lib/libusb.a)
    list(APPEND REALTEK_SUBSYS_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/usb/lib/libusb_hal.a)
endif()

add_subdirectory_ifdef(CONFIG_REALTEK_SUBSYS_MAC_802154 mac_802154)

if(REALTEK_SUBSYS_LIBS)
    target_link_libraries(app PRIVATE 
        -Wl,--start-group
        ${REALTEK_SUBSYS_LIBS}
        -Wl,--end-group
    )
endif()






