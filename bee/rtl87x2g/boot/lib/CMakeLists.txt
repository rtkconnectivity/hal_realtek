zephyr_library()
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/liblowerstack.a)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/libROM_NS.a)
zephyr_link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/ROM_CMSE_Lib.o)
