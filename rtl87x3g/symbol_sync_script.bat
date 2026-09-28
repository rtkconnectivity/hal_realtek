1>NUL copy       ..\..\..\..\..\bb2ultra-dev\sdk\bin\ROM.a                      platform\rom_symbol\ROM.a
1>NUL copy       ..\..\..\..\..\bb2ultra-dev\keil_proj\inc\rom_uuid.h                   platform\inc\
1>NUL copy       ..\..\..\..\..\bb2ultra-dev\rom\include\bb2ultra_rom_defines.h         ..\..\..\..\..\release-crb-3.14.0\hal\inc\bb2ultra\bb2ultra_rom_defines.h

:: Upperstack_compile_stamp.h  right now place in realtek-app\subsys\bluetooth\bt_host\lib\
:: The mismatch of stamp would not affect upperstack functions. 
:: So when upperstack is settled down to .bin, then we update this file.
:: 1>NUL copy       ..\..\..\..\..\..\bb2ultra-dev\keil_proj\upperstack\upperstack_compile_stamp.h                   bluetooth\bt_host\inc\


@echo %TIME%
start python    ..\..\..\..\..\bb2ultra-dev\sdk\tool\gcc_tool\arcclib_to_gcclib.py ..\..\..\..\..\bb2ultra-dev\keil_proj\lib\lowerstack.lib    platform\rom_symbol\lowerstack.a
start python    ..\..\..\..\..\bb2ultra-dev\sdk\tool\gcc_tool\arcclib_to_gcclib.py ..\..\..\..\..\bb2ultra-dev\keil_proj\lib\upperstack.lib    ..\..\..\..\realtek-app\subsys\bluetooth\bt_host\lib\upperstack.a

set INPUT_FILE=platform\rom_symbol\ROM.a
powershell -Command "(Get-Content -path %INPUT_FILE%) -replace 'chip_reset =','chip_reset_patch =' | Set-Content -path %INPUT_FILE%"
powershell -Command "(Get-Content -path %INPUT_FILE%) -replace 'sd_init =','sd_init_rom =' | Set-Content -path %INPUT_FILE%"
powershell -Command "(Get-Content -path %INPUT_FILE%) -replace 'os_timer_handle_get =','os_timer_handle_get_deprecated =' | Set-Content -path %INPUT_FILE%"