SECTIONS
{
    PROVIDE(bt_clk_offset = 0x0013ded8);
    PROVIDE(mac_FIFO_BaseAddr_rom = 0x000251e9);
    PROVIDE(modem_set_zb_cca_combination = 0x0013d774);
    PROVIDE(set_zigbee_priority = 0x00043719);
    PROVIDE(mac_adapter = 0x0003359c);
    PROVIDE(pzbpm_adapter = 0x0013dee4);
    PROVIDE(pmac_driver = 0x0013dec0);
    PROVIDE(platform_rtc_get_counter = 0x0013d908);
    PROVIDE(get_valid_txgain_index_from_tx_power = 0x0013d568);
    PROVIDE(zbmac_pm_init = 0x0013deec);
    PROVIDE(zbmac_pm_check = 0x0013def0);
    PROVIDE(zbmac_pm_store = 0x0013def4);
    PROVIDE(zbmac_pm_restore = 0x0013def8);
    PROVIDE(zbmac_pm_enter = 0x0013defc);
    PROVIDE(zbmac_pm_exit = 0x0013df00);
    PROVIDE(mac_GetTxGainIndex = 0x0002548d);
    PROVIDE(zbmac_pm_check_rom = 0x0001d5f9);
    PROVIDE(le_read_register = 0x00051139);
    PROVIDE(power_manager_interface_get_unit_status = 0x0002aac9);
    PROVIDE(power_manager_interface_check_unit_active = 0x0002aa7d);
    PROVIDE(mac_retention_reg16b_list = 0x000337bc);
    PROVIDE(mac_retention_reg32b_list = 0x000337cc);
    PROVIDE(mac_retention_reg8b_list = 0x00033850);
    PROVIDE(patch_SystemCall_Zigbee_Stack = 0x0013e3d4);
    PROVIDE(MAC_EADR_BASE_ADDR = 0x0001e72d);
    PROVIDE(modem_set_zb_cca_energy_detect_threshold_rom = 0x00027335);
}
