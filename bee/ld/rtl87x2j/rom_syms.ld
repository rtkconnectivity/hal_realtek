/* Auto-generated from ROM.sym — do not edit by hand.
 * RTL87x2J ROM symbol addresses for GNU ld PROVIDE() resolution.
 * T entries: address already has Thumb bit (bit 0) set.
 * D entries: plain data address.
 * Include in the final Zephyr link via zephyr_linker_sources(SECTIONS ...).
 */

PROVIDE(RomVectorTable = 0x00000000);
PROVIDE(boot_rom_header = 0x00000040);
PROVIDE(__aeabi_uldivmod = 0x00000061);
PROVIDE(_ll_udiv = 0x00000061);
PROVIDE(memcmp = 0x00000151);
PROVIDE(memcpy = 0x000001a9);
PROVIDE(memset = 0x000001b1);
PROVIDE(__aeabi_memclr4 = 0x000001c7);
PROVIDE(__aeabi_memclr8 = 0x000001c7);
PROVIDE(__rt_memclr_w = 0x000001c7);
PROVIDE(_memset_w = 0x000001cb);
PROVIDE(__aeabi_memcpy = 0x00000215);
PROVIDE(__rt_memcpy = 0x00000215);
PROVIDE(_memcpy_lastbytes = 0x0000027b);
PROVIDE(__aeabi_memclr = 0x0000029f);
PROVIDE(__rt_memclr = 0x0000029f);
PROVIDE(_memset = 0x000002a3);
PROVIDE(__aeabi_memcpy4 = 0x000002e3);
PROVIDE(__aeabi_memcpy8 = 0x000002e3);
PROVIDE(__rt_memcpy_w = 0x000002e3);
PROVIDE(_memcpy_lastbytes_aligned = 0x0000032b);
PROVIDE(Debug_Monitor_Handler = 0x00000347);
PROVIDE(HardFault_Handler = 0x0000036f);
PROVIDE(LogUartTxData = 0x0000038d);
PROVIDE(Pad_Config = 0x00000491);
PROVIDE(Pinmux_Config = 0x0000054d);
PROVIDE(Pinmux_Deinit = 0x0000058d);
PROVIDE(Pinmux_Reset = 0x000005c9);
PROVIDE(RCC_ClockCmd = 0x000005f1);
PROVIDE(UART_ClearINT = 0x00000825);
PROVIDE(UART_ClearRxFIFO = 0x0000083d);
PROVIDE(UART_ClearTxFIFO = 0x0000084f);
PROVIDE(UART_ClockAutoModeCmd = 0x00000861);
PROVIDE(UART_DeInit = 0x000008a9);
PROVIDE(UART_GetFlagStatus = 0x000008d9);
PROVIDE(UART_GetIID = 0x00000911);
PROVIDE(UART_GetLineStatus = 0x00000919);
PROVIDE(UART_GetRxFIFODataLen = 0x0000091f);
PROVIDE(UART_GetTxFIFODataLen = 0x00000927);
PROVIDE(UART_HwClock = 0x00000931);
PROVIDE(UART_INTConfig = 0x000009a5);
PROVIDE(UART_Init = 0x00000a09);
PROVIDE(UART_LoopBackCmd = 0x00000b51);
PROVIDE(UART_MaskINTConfig = 0x00000b65);
PROVIDE(UART_ReceiveByte = 0x00000b91);
PROVIDE(UART_ReceiveData = 0x00000b99);
PROVIDE(UART_RxDmaCmd = 0x00000bc5);
PROVIDE(UART_SendByte = 0x00000bdd);
PROVIDE(UART_SendData = 0x00000be1);
PROVIDE(UART_SetBaudRate = 0x00000c0d);
PROVIDE(UART_SetParams = 0x00000c45);
PROVIDE(UART_StructInit = 0x00000c61);
PROVIDE(UART_TxData = 0x00000c95);
PROVIDE(UART_TxDmaCmd = 0x00000cfd);
PROVIDE(VSnprintf = 0x00000d15);
PROVIDE(VTORInit = 0x00000ec9);
PROVIDE(WDT_ClearINTPendingBit = 0x00000ed9);
PROVIDE(WDT_ClockAutoModeCmd = 0x00000ef5);
PROVIDE(WDT_Disable = 0x00000f05);
PROVIDE(WDT_Enable = 0x00000f25);
PROVIDE(WDT_GetCurrentCount = 0x00000f41);
PROVIDE(WDT_GetMode = 0x00000f4d);
PROVIDE(WDT_GetTimeoutMs = 0x00000f59);
PROVIDE(WDT_ISR = 0x00000f65);
PROVIDE(WDT_IsEnable = 0x00000f8d);
PROVIDE(WDT_Kick = 0x00000f95);
PROVIDE(WDT_Start = 0x00000fb1);
PROVIDE(active_irq_type_get = 0x00001021);
PROVIDE(aon_reg_read_8b = 0x00001035);
PROVIDE(aon_reg_write_8b = 0x00001059);
PROVIDE(atomic_post_inc_return = 0x00001099);
PROVIDE(boot_failed = 0x00001111);
PROVIDE(cal_quotient_remainder = 0x0000117d);
PROVIDE(check_disable_hci_platform_vendor_cmd = 0x000011c7);
PROVIDE(check_header_valid = 0x00001221);
PROVIDE(check_log_permition = 0x000012dd);
PROVIDE(check_power_on_trap = 0x00001325);
PROVIDE(check_zero_count = 0x00001349);
PROVIDE(clk_cnt_diff = 0x0000135b);
PROVIDE(cmd_get_property = 0x00001399);
PROVIDE(cmd_load_ram_patch = 0x000013a9);
PROVIDE(count_zeros = 0x000014bd);
PROVIDE(cpu_register_dump = 0x0000155d);
PROVIDE(cpu_snapshot_dump = 0x000016a1);
PROVIDE(data_cmp = 0x00001725);
PROVIDE(debug_monitor_dump = 0x00001749);
PROVIDE(default_handler = 0x000017a1);
PROVIDE(deinit_true_random_generator = 0x000017c5);
PROVIDE(delay_ms_asm = 0x000017f1);
PROVIDE(delay_us_asm = 0x00001831);
PROVIDE(dump_memory_valid_size_get = 0x000018cd);
PROVIDE(dump_raw_mem = 0x00001905);
PROVIDE(dump_raw_memory_all = 0x000019c9);
PROVIDE(dwt_cyccnt_init = 0x00001a1d);
PROVIDE(eflash_chip_erase_main_redundancy_nvr_sector = 0x00001a41);
PROVIDE(eflash_chip_erase_main_redundancy_sector = 0x00001a71);
PROVIDE(eflash_cmd_rx_rom = 0x00001aa1);
PROVIDE(eflash_cmd_tx_rom = 0x00001aed);
PROVIDE(eflash_erase_main_sector_rom = 0x00001b49);
PROVIDE(eflash_erase_nvr_cfg_rom = 0x00001b79);
PROVIDE(eflash_erase_nvr_sector_rom = 0x00001ba1);
PROVIDE(eflash_erase_redundancy_sector_rom = 0x00001bd1);
PROVIDE(eflash_erase_retry_main_sector_rom = 0x00001bfd);
PROVIDE(eflash_erase_retry_nvr_sector_rom = 0x00001c61);
PROVIDE(eflash_erase_retry_redundancy_sector = 0x00001cc5);
PROVIDE(eflash_fill_cmd_id_addr_and_trig_user_mode = 0x00001d3d);
PROVIDE(eflash_get_addr_offset = 0x00001d5d);
PROVIDE(eflash_get_cmd_err = 0x00001d81);
PROVIDE(eflash_get_cmd_trig = 0x00001d8d);
PROVIDE(eflash_get_nvr_cfg_addr_offset = 0x00001d95);
PROVIDE(eflash_get_nvr_sector_addr_offset = 0x00001db5);
PROVIDE(eflash_get_rdata = 0x00001dd9);
PROVIDE(eflash_get_redundancy_addr_offset = 0x00001de9);
PROVIDE(eflash_init = 0x00001e0d);
PROVIDE(eflash_init_fail_enter_hci_mode = 0x00001e31);
PROVIDE(eflash_lock_read_protection_for_main_memory = 0x00001e4d);
PROVIDE(eflash_lock_read_protection_for_nvr_cfg = 0x00001e69);
PROVIDE(eflash_lock_read_protection_for_nvr_sector = 0x00001e81);
PROVIDE(eflash_lock_rom = 0x00001e9d);
PROVIDE(eflash_lock_write_protection_for_main_memory = 0x00001ed9);
PROVIDE(eflash_lock_write_protection_for_nvr_cfg = 0x00001ef5);
PROVIDE(eflash_lock_write_protection_for_nvr_sector = 0x00001f11);
PROVIDE(eflash_power_on_reqn_efc = 0x00001f31);
PROVIDE(eflash_program_main_sector = 0x00001f59);
PROVIDE(eflash_program_nvr_cfg_rom = 0x00001fa9);
PROVIDE(eflash_program_nvr_sector = 0x00002021);
PROVIDE(eflash_program_redundancy_sector = 0x0000206d);
PROVIDE(eflash_read_data_flow_rom = 0x000020b5);
PROVIDE(eflash_read_main_sector = 0x00002119);
PROVIDE(eflash_read_modify_write_32 = 0x00002141);
PROVIDE(eflash_read_modify_write_8 = 0x0000214b);
PROVIDE(eflash_read_nvr_sector = 0x00002155);
PROVIDE(eflash_recall_read_nvr_cfg_rom = 0x0000217d);
PROVIDE(eflash_set_auto_mode = 0x000021b9);
PROVIDE(eflash_set_cmd_id = 0x000021cd);
PROVIDE(eflash_set_cmd_trig = 0x000021d9);
PROVIDE(eflash_set_config_register = 0x000021ed);
PROVIDE(eflash_set_read_mode_idle = 0x00002205);
PROVIDE(eflash_set_read_protection_for_nvr_cfg = 0x00002219);
PROVIDE(eflash_set_read_protection_range_for_main_memory = 0x0000223d);
PROVIDE(eflash_set_read_protection_range_for_nvr_sector = 0x00002265);
PROVIDE(eflash_set_reqn_by_efc = 0x00002295);
PROVIDE(eflash_set_standby_mode_idle = 0x000022a1);
PROVIDE(eflash_set_user_mode = 0x000022b9);
PROVIDE(eflash_set_user_mode_addr = 0x000022cd);
PROVIDE(eflash_set_wait_eflash_acceptn = 0x000022e1);
PROVIDE(eflash_set_wdata = 0x000022f5);
PROVIDE(eflash_set_write_protection_for_nvr_cfg = 0x00002301);
PROVIDE(eflash_set_write_protection_range_for_main_memory = 0x00002321);
PROVIDE(eflash_set_write_protection_range_for_nvr_sector = 0x0000235d);
PROVIDE(eflash_unlock_rom = 0x00002399);
PROVIDE(eflash_verify_read_main_sector_rom = 0x000023b1);
PROVIDE(eflash_verify_read_nvr_sector_rom = 0x000023d9);
PROVIDE(eflash_verify_read_redundancy_sector_rom = 0x00002401);
PROVIDE(empty_function = 0x00002429);
PROVIDE(flash_cache_flush = 0x0000242d);
PROVIDE(flash_cache_is_enable = 0x00002449);
PROVIDE(flash_cache_reset_counter = 0x00002455);
PROVIDE(flash_cache_setup = 0x00002469);
PROVIDE(flash_cache_staticstic_dump = 0x000024a9);
PROVIDE(flash_cache_way_set = 0x000024dd);
PROVIDE(generic_response = 0x000024e9);
PROVIDE(get_ahb_wait_cnt = 0x000025a9);
PROVIDE(get_airplane_mode = 0x000025b9);
PROVIDE(get_disable_hci_efuse_access = 0x000025bd);
PROVIDE(get_disable_hci_flash_access = 0x000025c9);
PROVIDE(get_disable_hci_ram_patch = 0x000025d5);
PROVIDE(get_disable_hci_read_chip_info = 0x000025e1);
PROVIDE(get_disable_hci_system_access = 0x000025ed);
PROVIDE(get_true_random_number_rom = 0x000025fd);
PROVIDE(hardfault_dump = 0x00002621);
PROVIDE(hci_handle_read_write_efuse_data_cmd = 0x000026bd);
PROVIDE(hci_handle_vendor_download_cmd = 0x00002701);
PROVIDE(hci_handle_vendor_read_write_reg_cmd = 0x00002755);
PROVIDE(hci_mode_enable = 0x0000283d);
PROVIDE(hci_platform_vendor_cmd_rom = 0x00002859);
PROVIDE(hci_platform_vendor_generate_command_complete_event_rom = 0x00002915);
PROVIDE(hci_vendor_cmd_generate_event_rom = 0x00002a09);
PROVIDE(hci_vendor_enter_debug_password_cmd_rom = 0x00002a2d);
PROVIDE(hci_vendor_enter_response_cmd_rom = 0x00002a55);
PROVIDE(hci_vendor_generate_command_complete_event_rom = 0x00002a81);
PROVIDE(hci_vendor_handle_set_fast_reboot_mode_cmd_rom = 0x00002ac9);
PROVIDE(hci_vendor_trigger_wdg_reset_rom = 0x00002af5);
PROVIDE(image_entry = 0x00002db5);
PROVIDE(image_integrity_check_rom = 0x00002df5);
PROVIDE(init_true_random_generator_rom = 0x00002e4d);
PROVIDE(is_assert_enable = 0x00002e85);
PROVIDE(is_in_isr = 0x00002e91);
PROVIDE(is_log_enable = 0x00002e9d);
PROVIDE(is_overlapped = 0x00002ea9);
PROVIDE(log_buffer = 0x00002ec3);
PROVIDE(log_buffer_imp = 0x00002ed9);
PROVIDE(log_direct = 0x00002f39);
PROVIDE(log_direct_imp = 0x00002f59);
PROVIDE(log_enable_get = 0x00002fb1);
PROVIDE(log_enable_set = 0x00002fbd);
PROVIDE(log_output_rom = 0x00002fd1);
PROVIDE(log_timestamp_get = 0x00002fd9);
PROVIDE(log_uart_hw_deinit = 0x00003005);
PROVIDE(log_uart_hw_init = 0x00003011);
PROVIDE(mp_cmd_verify = 0x00003151);
PROVIDE(mp_send_data = 0x00003185);
PROVIDE(otp_access = 0x0000319d);
PROVIDE(otp_operate_rom = 0x000031f9);
PROVIDE(otp_set_read_protect_lock = 0x0000323d);
PROVIDE(otp_set_read_protect_rom = 0x00003251);
PROVIDE(otp_set_write_protect_lock = 0x00003265);
PROVIDE(otp_set_write_protect_rom = 0x0000327d);
PROVIDE(platform_delay_ms = 0x00003291);
PROVIDE(platform_delay_us = 0x000032b1);
PROVIDE(platform_random = 0x000032d1);
PROVIDE(primary_bootloader = 0x000032f5);
PROVIDE(ram_vector_table_init = 0x000033d1);
PROVIDE(ram_vector_table_register = 0x000033f9);
PROVIDE(ram_vector_table_update = 0x00003439);
PROVIDE(ram_vector_table_update_rom = 0x0000346d);
PROVIDE(read_cpu_counter = 0x000034d9);
PROVIDE(reverse_bits_in_word = 0x000034e5);
PROVIDE(rot_check_euid = 0x00003501);
PROVIDE(rot_chk_bit = 0x00003541);
PROVIDE(rot_enter_debug_authentication_data = 0x00003561);
PROVIDE(rot_get_challenge = 0x000035c1);
PROVIDE(rot_parse_logic_map = 0x000035f1);
PROVIDE(rot_set_reg_rom = 0x00003699);
PROVIDE(rot_swd_control = 0x00003785);
PROVIDE(rot_update_parameter = 0x00003821);
PROVIDE(saturate_by_boundary = 0x0000387d);
PROVIDE(secondary_bootloader_entry = 0x0000388d);
PROVIDE(secondary_bootloader_verify = 0x000038c9);
PROVIDE(secure_boot_seq_cnt_check = 0x00003909);
PROVIDE(set_airplane_mode = 0x00003925);
PROVIDE(set_swd_pinmux_rom = 0x00003929);
PROVIDE(swap_buf = 0x00003a71);
PROVIDE(sys_reset_reason_get = 0x00003ad9);
PROVIDE(sys_reset_reason_update = 0x00003af9);
PROVIDE(syscall = 0x00003b3d);
PROVIDE(syscall_bt_controller = 0x00003b4d);
PROVIDE(syscall_bt_host_common = 0x00003b71);
PROVIDE(syscall_bt_host_le = 0x00003b95);
PROVIDE(syscall_platform = 0x00003bb9);
PROVIDE(tick_32000_to_us = 0x00003bdd);
PROVIDE(tick_32768_to_us = 0x00003bff);
PROVIDE(trace_header_build = 0x00003c29);
PROVIDE(true_function = 0x00003c71);
PROVIDE(uart_senddata_continuous_rom = 0x00003c75);
PROVIDE(update_cpu_tick_to_us = 0x00003ca9);
PROVIDE(us_to_tick_32000 = 0x00003cc5);
PROVIDE(us_to_tick_32768 = 0x00003ce7);
PROVIDE(vector_table_ram_init = 0x00003d11);
PROVIDE(void_ptr_function = 0x00003d45);
PROVIDE(wdt_dump = 0x00003d49);
PROVIDE(pad_addr_table = 0x00003db8);
PROVIDE(pinmux_index_table = 0x00003e1c);
PROVIDE(RamVectorTable = 0x20019600);
PROVIDE(hci_vendor_handle_set_fast_reboot_mode_cmd = 0x200197ac);
PROVIDE(hci_vendor_trigger_wdg_reset = 0x200197b0);
PROVIDE(hci_vendor_enter_debug_password_cmd = 0x200197b4);
PROVIDE(hci_vendor_enter_response_cmd = 0x200197b8);
PROVIDE(eflash_erase_retry_max_times = 0x200197bc);
PROVIDE(eflash_cmd_tx = 0x200197c0);
PROVIDE(eflash_verify_read_redundancy_sector = 0x200197c4);
PROVIDE(boot_patch_addr = 0x200197e4);
PROVIDE(boot_rom_cfg = 0x200197e8);
PROVIDE(cpu_tick_per_us = 0x200197ec);
PROVIDE(crypto_ioctrl = 0x200197f0);
PROVIDE(dbg_cfg = 0x200197f4);
PROVIDE(eflash_cmd_rx = 0x2001981c);
PROVIDE(eflash_erase_main_sector = 0x20019820);
PROVIDE(eflash_erase_nvr_cfg = 0x20019824);
PROVIDE(eflash_erase_nvr_sector = 0x20019828);
PROVIDE(eflash_erase_redundancy_sector = 0x2001982c);
PROVIDE(eflash_erase_retry_main_sector = 0x20019830);
PROVIDE(eflash_erase_retry_nvr_sector = 0x20019834);
PROVIDE(eflash_lock = 0x20019838);
PROVIDE(eflash_program_nvr_cfg = 0x2001983c);
PROVIDE(eflash_read_data_flow = 0x20019840);
PROVIDE(eflash_recall_read_nvr_cfg = 0x20019844);
PROVIDE(eflash_unlock = 0x20019848);
PROVIDE(eflash_verify_read_main_sector = 0x2001984c);
PROVIDE(eflash_verify_read_nvr_sector = 0x20019850);
PROVIDE(get_SystemCpuClock = 0x20019854);
PROVIDE(get_btmac_32k_drift_ppm = 0x20019858);
PROVIDE(get_true_random_number = 0x2001985c);
PROVIDE(hci_event_pkt_ptr = 0x20019860);
PROVIDE(hci_platform_vendor_cmd = 0x20019864);
PROVIDE(hci_platform_vendor_generate_command_complete_event = 0x20019868);
PROVIDE(header_size_rom = 0x2001986c);
PROVIDE(image_integrity_check = 0x20019870);
PROVIDE(init_true_random_generator = 0x20019874);
PROVIDE(is_module_clk_32000Hz = 0x20019878);
PROVIDE(kernel_ioctrl = 0x20019884);
PROVIDE(log_output = 0x20019888);
PROVIDE(loop_cycle_count = 0x2001988c);
PROVIDE(occd_base_addr = 0x20019890);
PROVIDE(occd_payload_size = 0x20019894);
PROVIDE(otp_operate = 0x20019898);
PROVIDE(otp_ram = 0x2001989c);
PROVIDE(otp_set_read_protect = 0x200198a0);
PROVIDE(otp_set_write_protect = 0x200198a4);
PROVIDE(patch_log_direct = 0x200198a8);
PROVIDE(rom_ro_base = 0x200198ac);
PROVIDE(rot_set_reg = 0x200198b0);
PROVIDE(set_swd_pinmux = 0x20019900);
PROVIDE(irqMap = 0x20019904);
PROVIDE(gpio_regFunc = 0x20019908);
PROVIDE(regFuncTable = 0x2001990c);
PROVIDE(secure_boot_failed_line = 0x20019910);
PROVIDE(secure_boot_failed_file = 0x20019914);
PROVIDE(secure_boot_image_id = 0x20019918);
PROVIDE(ota_bank_num = 0x2001991c);
PROVIDE(image_check_bitmap = 0x20019920);
PROVIDE(rxi300_dump = 0x20019924);
PROVIDE(is_rxi300_interrupt_ocurred = 0x20019928);
PROVIDE(eflash_disable_irq = 0x20019938);
PROVIDE(eflash_enable_irq = 0x2001993c);
PROVIDE(patch_sys_reset_reason_get = 0x20019940);
PROVIDE(sys_reset_reason = 0x20019944);
PROVIDE(patch_sys_reset = 0x20019948);
PROVIDE(sys_reset_callback = 0x2001994c);
PROVIDE(patch_sys_reset_aon_preserve = 0x20019950);
PROVIDE(rom_code_patch_block_index = 0x20019954);
PROVIDE(rom_code_patch_start_address = 0x20019958);
PROVIDE(cmd_used_info = 0x2001995c);
PROVIDE(buf_output = 0x20019964);
PROVIDE(eflash_recovery_flag = 0x20019968);
PROVIDE(g_hci_vendor_read_data = 0x2001996c);
PROVIDE(g_hci_vendor_read_data_len = 0x20019970);
PROVIDE(is_log_init = 0x20019971);
PROVIDE(log_seq_num = 0x20019978);
PROVIDE(mp_loader_entry = 0x2001997c);
PROVIDE(os_init_done = 0x20019980);
PROVIDE(ota_header_addr_rom = 0x20019984);
PROVIDE(patch_Pad_Config = 0x20019988);
PROVIDE(patch_Pinmux_Config = 0x2001998c);
PROVIDE(patch_Pinmux_Deinit = 0x20019990);
PROVIDE(patch_Pinmux_Reset = 0x20019994);
PROVIDE(patch_RCC_ClockCmd = 0x20019998);
PROVIDE(patch_RCC_ClockIgnoreCmd = 0x2001999c);
PROVIDE(patch_UART_ClockAutoModeCmd = 0x200199a0);
PROVIDE(patch_UART_INTConfig = 0x200199a4);
PROVIDE(patch_UART_Init = 0x200199a8);
PROVIDE(patch_UART_MaskINTConfig = 0x200199ac);
PROVIDE(patch_UART_ReceiveData = 0x200199b0);
PROVIDE(patch_UART_SendData = 0x200199b4);
PROVIDE(patch_UART_TxData = 0x200199b8);
PROVIDE(patch_WDT_ClearINTPendingBit = 0x200199bc);
PROVIDE(patch_WDT_Disable = 0x200199c0);
PROVIDE(patch_WDT_Enable = 0x200199c4);
PROVIDE(patch_WDT_Kick = 0x200199c8);
PROVIDE(patch_WDT_Start = 0x200199cc);
PROVIDE(patch_check_log_permition = 0x200199d0);
PROVIDE(patch_log_buffer = 0x200199d4);
PROVIDE(patch_log_timestamp_get = 0x200199d8);
PROVIDE(patch_log_trace_header_build = 0x200199dc);
PROVIDE(patch_platform_delay_ms = 0x200199e0);
PROVIDE(patch_platform_delay_us = 0x200199e4);
PROVIDE(patch_ram_vector_table_update = 0x200199e8);
PROVIDE(patch_sys_reset_reason_update = 0x200199ec);
PROVIDE(patch_syscall = 0x200199f0);
PROVIDE(patch_syscall_bt_controller = 0x200199f4);
PROVIDE(patch_syscall_bt_host_common = 0x200199f8);
PROVIDE(patch_syscall_bt_host_le = 0x200199fc);
PROVIDE(patch_syscall_platform = 0x20019a00);
PROVIDE(patch_wdt_get_reset_reason = 0x20019a04);
PROVIDE(patch_wdt_get_reset_type = 0x20019a08);
PROVIDE(patch_wdt_regiser_reset_callback = 0x20019a0c);
PROVIDE(patch_wdt_reset = 0x20019a10);
PROVIDE(patch_wdt_reset_with_reason = 0x20019a14);
PROVIDE(patch_wdt_update_reset_reason = 0x20019a18);
