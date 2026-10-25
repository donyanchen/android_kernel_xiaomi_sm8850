// SPDX-License-Identifier: GPL-2.0

/*
 * 小米私有符号桩函数（自动生成）

 * 这些符号由小米闭源代码导出，此处提供空实现以便厂商模块加载。

 * 生成依据：设备 /proc/kallsyms 的 __ksymtab_* 条目 +

 *           模块反汇编的调用点参数推断
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>

/* 推断：5 个参数 */
int __mca_log_debug(const char * a0, unsigned int a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_debug);

/* 推断：5 个参数 */
int __mca_log_err(const char * a0, unsigned int a1, unsigned long a2, unsigned long a3, unsigned long a4)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_err);

/* 推断：3 个参数 */
int __mca_log_info(const char * a0, unsigned int a1, unsigned long a2)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_info);

/* 推断：1 个参数 */
int mca_adsp_glink_read_prop(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_read_prop);

/* 推断：1 个参数 */
int mca_adsp_glink_resister_ops(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_resister_ops);

/* 推断：1 个参数 */
int mca_adsp_glink_write_prop(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_write_prop);

/* 推断：1 个参数 */
int mca_bmd_force_detection(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_bmd_force_detection);

/* 推断：1 个参数 */
bool mca_bmd_is_batt_missing(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_bmd_is_batt_missing);

/* 推断：1 个参数 */
int mca_cancel_delayed_work(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_cancel_delayed_work);

/* 推断：1 个参数 */
int mca_cancel_work(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_cancel_work);

/* 推断：1 个参数 */
int mca_charge_if_ops_register(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_if_ops_register);

/* 推断：1 个参数 */
int mca_charge_mievent_report(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_report);

/* 推断：1 个参数 */
int mca_charge_mievent_set_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_set_state);

/* 推断：1 个参数 */
int mca_create_votable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_create_votable);

/* 推断：1 个参数 */
int mca_debugfs_create_group(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_debugfs_create_group);

/* 推断：1 个参数 */
void mca_destroy_votable(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_destroy_votable);

/* 推断：1 个参数 */
int mca_event_block_notify(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify);

/* 推断：1 个参数 */
int mca_event_block_notify_register(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify_register);

/* 推断：1 个参数 */
void mca_event_block_notify_unregister(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_event_block_notify_unregister);

/* 推断：1 个参数 */
int mca_event_report_multiple_uevent(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_multiple_uevent);

/* 推断：1 个参数 */
int mca_event_report_uevent(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_uevent);

/* 推断：1 个参数 */
int mca_find_votable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_find_votable);

/* 推断：1 个参数 */
int mca_get_client_vote(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_client_vote);

/* 推断：1 个参数 */
int mca_get_client_vote_locked(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_client_vote_locked);

/* 推断：1 个参数 */
int mca_get_effective_client(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_client);

/* 推断：1 个参数 */
int mca_get_effective_client_locked(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_client_locked);

/* 推断：1 个参数 */
int mca_get_effective_result(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_result);

/* 推断：1 个参数 */
int mca_get_effective_result_locked(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_result_locked);

/* 推断：1 个参数 */
int mca_get_hwid_info(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_hwid_info);

/* 推断：1 个参数 */
void mca_get_wls_charger_thermal_remove(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_get_wls_charger_thermal_remove);

/* 推断：1 个参数 */
bool mca_is_client_vote_enabled(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled);

/* 推断：1 个参数 */
bool mca_is_client_vote_enabled_locked(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled_locked);

/* 推断：1 个参数 */
bool mca_is_override_vote_enabled(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled);

/* 推断：1 个参数 */
bool mca_is_override_vote_enabled_locked(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled_locked);

/* 推断：1 个参数 */
int mca_lock_votable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_lock_votable);

/* 推断：3 个参数 */
int mca_log_charge_log_register(const char * a0, unsigned int a1, unsigned long a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_log_charge_log_register);

/* 推断：1 个参数 */
int mca_log_get_charge_boot_mode(const char * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_log_get_charge_boot_mode);

/* 推断：1 个参数 */
int mca_log_get_rtc_time(const char * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_log_get_rtc_time);

/* 推断：1 个参数 */
int mca_mod_delayed_work(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_mod_delayed_work);

/* 推断：1 个参数 */
int mca_panel_get_hbm_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_panel_get_hbm_state);

/* 推断：1 个参数 */
int mca_panel_get_screen_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_panel_get_screen_state);

/* 推断：1 个参数 */
int mca_parse_dts_count_strings(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_count_strings);

/* 推断：1 个参数 */
int mca_parse_dts_s32(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_s32);

/* 推断：1 个参数 */
int mca_parse_dts_string(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string);

/* 推断：1 个参数 */
int mca_parse_dts_string_array(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_array);

/* 推断：1 个参数 */
int mca_parse_dts_string_index(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_index);

/* 推断：4 个参数 */
int mca_parse_dts_u32(void * a0, void * a1, void * a2, void * a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32);

/* 推断：4 个参数 */
int mca_parse_dts_u32_array(void * a0, void * a1, void * a2, void * a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_array);

/* 推断：4 个参数 */
int mca_parse_dts_u32_count(void * a0, void * a1, void * a2, void * a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_count);

/* 推断：1 个参数 */
int mca_parse_dts_u32_index(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_index);

/* 推断：1 个参数 */
int mca_parse_dts_u8(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8);

/* 推断：1 个参数 */
int mca_parse_dts_u8_array(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_array);

/* 推断：1 个参数 */
int mca_parse_dts_u8_count(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_count);

/* 推断：1 个参数 */
int mca_path_control_enable_gate(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_path_control_enable_gate);

/* 推断：0 个参数 */
bool mca_qcom_smem_is_zero_speed(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_qcom_smem_is_zero_speed);

/* 推断：1 个参数 */
int mca_queue_delayed_work(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_delayed_work);

/* 推断：1 个参数 */
int mca_queue_work(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_work);

/* 推断：1 个参数 */
int mca_rerun_election(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_rerun_election);

/* 推断：1 个参数 */
void mca_set_wls_charger_thermal_remove(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_set_wls_charger_thermal_remove);

/* 推断：1 个参数 */
int mca_smartchg_get_board_temp(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_board_temp);

/* 推断：1 个参数 */
int mca_smartchg_get_limit_soc(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_limit_soc);

/* 推断：1 个参数 */
int mca_smartchg_get_scene(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_scene);

/* 推断：1 个参数 */
int mca_smartchg_if_ops_register(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_if_ops_register);

/* 推断：1 个参数 */
bool mca_smartchg_is_extreme_cold_enabled(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_is_extreme_cold_enabled);

/* 推断：1 个参数 */
int mca_smartchg_set_batt_emerg_soc_limit(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_batt_emerg_soc_limit);

/* 推断：1 个参数 */
int mca_smartchg_set_board_temp(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_board_temp);

/* 推断：1 个参数 */
int mca_smartchg_set_scene(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_scene);

/* 推断：3 个参数 */
int mca_strategy_func_get_status(void * a0, void * a1, void * a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_get_status);

/* 推断：3 个参数 */
int mca_strategy_func_process(void * a0, void * a1, void * a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_process);

/* 推断：1 个参数 */
int mca_strategy_func_set_config(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_set_config);

/* 推断：1 个参数 */
bool mca_strategy_is_support_pps_100w(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_is_support_pps_100w);

/* 推断：5 个参数 */
int mca_strategy_ops_register(void * a0, void * a1, void * a2, void * a3, void * a4)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_ops_register);

/* 推断：1 个参数 */
int mca_subpmic_proxy_get_otg_wls_mutex(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_subpmic_proxy_get_otg_wls_mutex);

/* 推断：1 个参数 */
int mca_sysfs_create_files(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_files);

/* 推断：1 个参数 */
int mca_sysfs_create_group(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_group);

/* 推断：4 个参数 */
int mca_sysfs_create_link_group(void * a0, void * a1, void * a2, void * a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_link_group);

/* 推断：3 个参数 */
int mca_sysfs_init_attrs(void * a0, void * a1, void * a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_init_attrs);

/* 推断：3 个参数 */
int mca_sysfs_lookup_attr(void * a0, void * a1, void * a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_lookup_attr);

/* 推断：1 个参数 */
void mca_sysfs_remove_group(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_sysfs_remove_group);

/* 推断：4 个参数 */
void mca_sysfs_remove_link_group(void * a0, void * a1, void * a2, void * a3)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_sysfs_remove_link_group);

/* 推断：1 个参数 */
int mca_unlock_votable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_unlock_votable);

/* 推断：4 个参数 */
int mca_vote(void * a0, void * a1, void * a2, void * a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote);

/* 推断：1 个参数 */
int mca_vote_override(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote_override);

/* 推断：1 个参数 */
int mca_wireless_rev_enable_reverse_charge(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_enable_reverse_charge);

/* 推断：1 个参数 */
int mca_wireless_rev_get_firmware_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_firmware_state);

/* 推断：1 个参数 */
int mca_wireless_rev_get_rev_boost_default(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_rev_boost_default);

/* 推断：1 个参数 */
int mca_wireless_rev_get_reverse_chg(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg);

/* 推断：1 个参数 */
int mca_wireless_rev_get_reverse_chg_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg_state);

/* 推断：1 个参数 */
int mca_wireless_rev_get_user_reverse_chg(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_user_reverse_chg);

/* 推断：1 个参数 */
int mca_wireless_rev_set_firmware_state(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_firmware_state);

/* 推断：1 个参数 */
int mca_wireless_rev_set_reverse_chg(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_reverse_chg);

/* 推断：1 个参数 */
int mca_wireless_rev_set_user_reverse_chg(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_user_reverse_chg);

/* 推断：1 个参数 */
int mca_wireless_rev_set_wired_chg_ok(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_wired_chg_ok);

/* 推断：1 个参数 */
int mca_wireless_rev_update_fw_version(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_update_fw_version);

/* 推断：1 个参数 */
int mi_dflt_bwmon_update_cur_freq_hook(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_bwmon_update_cur_freq_hook);

/* 推断：1 个参数 */
int mi_dflt_calculate_dflt_lantancy_hook(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_dflt_lantancy_hook);

/* 推断：1 个参数 */
int mi_dflt_calculate_mon_sampling_freq_hook(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_mon_sampling_freq_hook);

/* 推断：1 个参数 */
int mi_dflt_get_bwmon_enable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_enable);

/* 推断：1 个参数 */
int mi_dflt_get_bwmon_sample_start(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_sample_start);

/* 推断：1 个参数 */
int mi_dflt_get_latency_enable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable);

/* 推断：1 个参数 */
int mi_dflt_get_latency_enable_from_user(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable_from_user);

/* 推断：1 个参数 */
int mi_dflt_get_latency_vote_start(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_get_latency_vote_start);

/* 推断：1 个参数 */
int mi_dflt_process_raw_ctrs_hook(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_process_raw_ctrs_hook);

/* 推断：1 个参数 */
int mi_dflt_set_bwmon_sample_start(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_bwmon_sample_start);

/* 推断：1 个参数 */
int mi_dflt_set_latency_enable(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_enable);

/* 推断：1 个参数 */
int mi_dflt_set_latency_vote_start(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_vote_start);

/* 推断：1 个参数 */
int mi_dflt_update_memlat_fp_vote_hook(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_update_memlat_fp_vote_hook);

/* 推断：1 个参数 */
int mi_display_gesture_callback_register(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_gesture_callback_register);

/* 推断：1 个参数 */
int mi_display_pwrkey_callback_set(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_pwrkey_callback_set);

/* 推断：1 个参数 */
int mi_dsi_panel_lockdown_info_read(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read);

/* 推断：1 个参数 */
int mi_dsi_panel_lockdown_info_read_p8(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_p8);

/* 推断：1 个参数 */
int mi_dsi_panel_lockdown_info_read_q81(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_q81);

/* 推断：1 个参数 */
int mi_scsi_execute_cmd(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_scsi_execute_cmd);

/* 推断：1 个参数 */
int mi_smart_refill_dynamic_page_pool_refill(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_dynamic_page_pool_refill);

/* 推断：1 个参数 */
void mi_smart_refill_exit(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mi_smart_refill_exit);

/* 推断：1 个参数 */
int mi_smart_refill_init(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_init);

/* 推断：1 个参数 */
int mi_smart_refill_pools(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_pools);

/* 推断：1 个参数 */
int mi_smart_refill_pools_init(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_pools_init);

/* 推断：1 个参数 */
int mi_smart_refill_update(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_update);

/* 推断：1 个参数 */
int xiaomi_get_gesture_type(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_get_gesture_type);

/* 推断：1 个参数 */
int xiaomi_register_panel_notifier(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_register_panel_notifier);

/* 推断：1 个参数 */
int xiaomi_touch_mievent_report_int(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_int);

/* 推断：1 个参数 */
int xiaomi_touch_mievent_report_str(void * a0)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_str);

/* 推断：1 个参数 */
void xiaomi_unregister_panel_notifier(void * a0)
{
	/* no-op */
}
EXPORT_SYMBOL(xiaomi_unregister_panel_notifier);
