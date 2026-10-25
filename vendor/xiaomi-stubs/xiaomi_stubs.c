// SPDX-License-Identifier: GPL-2.0
/*
 * Pudding Kernel — 闭源符号桩（自动生成）
 *
 * 目的：为小米/高通闭源代码导出的符号提供定义，使 404 个厂商模块可加载。
 *
 * 数据来源（全部从真机提取）：
 *   · /proc/kallsyms 的 __ksymtab_*                       14,734 项
 *   · 404 个厂商 .ko 的 __versions 依赖表
 *   · 404 个 .ko 的 aarch64 反汇编                         30,288 个调用点
 *   · 404 个 .ko 的 .symtab 符号类型（FUNC / OBJECT）
 *
 * 符号总数：677（函数 650，变量 27）
 */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/device.h>
#include <linux/kobject.h>
#include <linux/soc/qcom/qmi.h>

/* ==================== 函数桩 ==================== */

/* ---- adc_* (4) ---- */
int adc_tm_absolute_rthr_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_absolute_rthr_gen3);

int adc_tm_channel_measure_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_channel_measure_gen3);

int adc_tm_disable_chan_meas_gen3(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_disable_chan_meas_gen3);

int adc_tm_scale_therm_voltage_100k_gen3(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(adc_tm_scale_therm_voltage_100k_gen3);

/* ---- add_* (4) ---- */
int add_common_data_to_buf(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(add_common_data_to_buf);

int add_hw_component_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(add_hw_component_info);

int add_hw_monitor_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(add_hw_monitor_info);

int add_input_event_timeline_before_event_time(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(add_input_event_timeline_before_event_time);

/* ---- altmode_* (5) ---- */
int altmode_deregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(altmode_deregister_client);

int altmode_deregister_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(altmode_deregister_notifier);

int altmode_register_client(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(altmode_register_client);

int altmode_register_notifier(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(altmode_register_notifier);

int altmode_send_data(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(altmode_send_data);

/* ---- attach_* (1) ---- */
int attach_mpam_msc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(attach_mpam_msc);

/* ---- bm_* (1) ---- */
int bm_send_nl(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(bm_send_nl);

/* ---- bootprof_* (1) ---- */
int bootprof_lock(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(bootprof_lock);

/* ---- boottime_* (1) ---- */
int boottime_ok(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(boottime_ok);

/* ---- btfm_* (1) ---- */
void * btfm_get_btfmcodec(void)
{
	return NULL;
}
EXPORT_SYMBOL(btfm_get_btfmcodec);

/* ---- btfmcodec_* (2) ---- */
int btfmcodec_register_hw_ep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btfmcodec_register_hw_ep);

int btfmcodec_unregister_hw_ep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btfmcodec_unregister_hw_ep);

/* ---- btpower_* (2) ---- */
void * btpower_get_chipset_version(void)
{
	return NULL;
}
EXPORT_SYMBOL(btpower_get_chipset_version);

int btpower_register_slimdev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(btpower_register_slimdev);

/* ---- build_* (1) ---- */
int build_fingerprint(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(build_fingerprint);

/* ---- camlog_* (1) ---- */
int camlog_send_message(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(camlog_send_message);

/* ---- cdev_* (5) ---- */
int cdev_tevent_add_int(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_add_int);

int cdev_tevent_add_str(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_add_str);

void * cdev_tevent_alloc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(cdev_tevent_alloc);

void cdev_tevent_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(cdev_tevent_destroy);

int cdev_tevent_write(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdev_tevent_write);

/* ---- cdsprm_* (10) ---- */
int cdsprm_compute_core_set_priority(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_compute_core_set_priority);

int cdsprm_compute_vtcm_set_partition_map(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_compute_vtcm_set_partition_map);

int cdsprm_cxlimit_camera_activity_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_camera_activity_notify);

int cdsprm_cxlimit_npu_activity_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_activity_notify);

int cdsprm_cxlimit_npu_corner_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_corner_notify);

int cdsprm_cxlimit_npu_limit_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_limit_deregister);

int cdsprm_cxlimit_npu_limit_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_cxlimit_npu_limit_register);

int cdsprm_register_cdspl3gov(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_register_cdspl3gov);

int cdsprm_sysmon_dcvs_clients_votes(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_sysmon_dcvs_clients_votes);

int cdsprm_unregister_cdspl3gov(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cdsprm_unregister_cdspl3gov);

/* ---- charger_* (30) ---- */
void * charger_partition_alloc(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_alloc);

int charger_partition_dealloc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_dealloc);

void * charger_partition_get_eu_model(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_get_eu_model);

void * charger_partition_get_mishow(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(charger_partition_get_mishow);

int charger_partition_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read);

int charger_partition_read_batt_emerg_sn(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_emerg_sn);

int charger_partition_read_batt_missing_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_missing_count);

int charger_partition_read_batt_missing_time(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_missing_time);

int charger_partition_read_batt_safe_ilim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_safe_ilim);

int charger_partition_read_batt_safe_vlim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_batt_safe_vlim);

int charger_partition_read_cuv_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_cuv_count);

int charger_partition_read_double85(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_double85);

int charger_partition_read_hscd_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_hscd_count);

int charger_partition_read_memory_test(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_memory_test);

int charger_partition_read_ocd_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_ocd_count);

int charger_partition_read_soc_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_read_soc_limit);

int charger_partition_write(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write);

int charger_partition_write_batt_emerg_sn(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_emerg_sn);

int charger_partition_write_batt_missing_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_missing_count);

int charger_partition_write_batt_missing_time(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_missing_time);

int charger_partition_write_batt_safe_ilim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_safe_ilim);

int charger_partition_write_batt_safe_vlim(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_batt_safe_vlim);

int charger_partition_write_cuv_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_cuv_count);

int charger_partition_write_double85(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_double85);

int charger_partition_write_eu_model(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_eu_model);

int charger_partition_write_hcsd_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_hcsd_count);

int charger_partition_write_memory_test(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_memory_test);

int charger_partition_write_ocd_count(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_ocd_count);

int charger_partition_write_remove_temp_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_remove_temp_limit);

int charger_partition_write_soc_limit(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(charger_partition_write_soc_limit);

/* ---- cld80211_* (1) ---- */
void * cld80211_get_genl_family(void)
{
	return NULL;
}
EXPORT_SYMBOL(cld80211_get_genl_family);

/* ---- cma_* (1) ---- */
int cma_pool_init_shrinker(void)
{
	return 0;
}
EXPORT_SYMBOL(cma_pool_init_shrinker);

/* ---- connector_* (1) ---- */
bool connector_antiburn_is_triggered(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(connector_antiburn_is_triggered);

/* ---- core_* (2) ---- */
int core_ctl_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(core_ctl_notifier_register);

void core_ctl_notifier_unregister(void)
{
	/* no-op */
}
EXPORT_SYMBOL(core_ctl_notifier_unregister);

/* ---- coredump_* (1) ---- */
int coredump_cleanup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(coredump_cleanup);

/* ---- cpu_* (1) ---- */
int cpu_logical_to_phys(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cpu_logical_to_phys);

/* ---- crm_* (5) ---- */
int crm_dump_regs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(crm_dump_regs);

void * crm_get_device(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(crm_get_device);

int crm_read_curr_perf_ol(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(crm_read_curr_perf_ol);

int crm_write_perf_ol(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(crm_write_perf_ol);

int crm_write_pwr_states(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(crm_write_pwr_states);

/* ---- cs35l43_* (2) ---- */
int cs35l43_resume_runtime(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs35l43_resume_runtime);

int cs35l43_suspend_runtime(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(cs35l43_suspend_runtime);

/* ---- cx_* (1) ---- */
void * cx_stats_get_ss_vote_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(cx_stats_get_ss_vote_info);

/* ---- ddr_* (5) ---- */
void * ddr_stats_get_change_his(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_change_his);

void * ddr_stats_get_freq_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_freq_count);

void * ddr_stats_get_residency(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_residency);

void * ddr_stats_get_ss_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_ss_count);

void * ddr_stats_get_ss_vote_info(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(ddr_stats_get_ss_vote_info);

/* ---- debug_* (2) ---- */
int debug_symbol_available(void)
{
	return 0;
}
EXPORT_SYMBOL(debug_symbol_available);

int debug_symbol_lookup_name(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(debug_symbol_lookup_name);

/* ---- deregister_* (1) ---- */
int deregister_cld_cmd_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(deregister_cld_cmd_cb);

/* ---- detach_* (1) ---- */
int detach_mpam_msc(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(detach_mpam_msc);

/* ---- digital_* (3) ---- */
void digital_cdc_rsc_mgr_hw_vote_disable(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_disable);

int digital_cdc_rsc_mgr_hw_vote_enable(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_enable);

void digital_cdc_rsc_mgr_hw_vote_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(digital_cdc_rsc_mgr_hw_vote_reset);

/* ---- disp_* (3) ---- */
int disp_kernel_timer_log_printk(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(disp_kernel_timer_log_printk);

int disp_log_printk(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(disp_log_printk);

int disp_log_printk_utc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(disp_log_printk_utc);

/* ---- dss_* (3) ---- */
void dss_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(dss_reg_dump);

int dss_reg_r(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(dss_reg_r);

int dss_reg_w(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(dss_reg_w);

/* ---- dump_* (3) ---- */
int dump_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(dump_enabled);

int dump_trace_and_send_event(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(dump_trace_and_send_event);

int dump_user_backtrace(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(dump_user_backtrace);

/* ---- etm_* (1) ---- */
void * etm_event_get_path(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(etm_event_get_path);

/* ---- firmware_* (1) ---- */
int firmware_request_from_smcinvoke(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(firmware_request_from_smcinvoke);

/* ---- fsa4480_* (3) ---- */
int fsa4480_reg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_reg_notifier);

int fsa4480_switch_event(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_switch_event);

int fsa4480_unreg_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(fsa4480_unreg_notifier);

/* ---- geni_* (1) ---- */
int geni_gsi_common_request_channel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(geni_gsi_common_request_channel);

/* ---- ghd_* (4) ---- */
void * ghd_rm_get_vmid(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(ghd_rm_get_vmid);

int ghd_rm_mem_lend(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_lend);

int ghd_rm_mem_reclaim(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_reclaim);

int ghd_rm_mem_share(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(ghd_rm_mem_share);

/* ---- gpi_* (2) ---- */
int gpi_dump_for_geni(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(gpi_dump_for_geni);

int gpi_update_multi_desc_flag(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(gpi_update_multi_desc_flag);

/* ---- gsihal_* (2) ---- */
void * gsihal_get_reg_nk_ofst(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(gsihal_get_reg_nk_ofst);

int gsihal_write_reg_nk(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(gsihal_write_reg_nk);

/* ---- has_* (2) ---- */
bool has_subsystem_slept(void)
{
	return false;
}
EXPORT_SYMBOL(has_subsystem_slept);

bool has_system_slept(void *a0)
{
	return false;
}
EXPORT_SYMBOL(has_system_slept);

/* ---- hdcp1_* (8) ---- */
void hdcp1_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hdcp1_deinit);

int hdcp1_feature_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_feature_supported);

int hdcp1_init(void)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_init);

int hdcp1_ops_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_ops_notify);

int hdcp1_set_enc(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_set_enc);

int hdcp1_set_hdcp_key_verify_retries(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_set_hdcp_key_verify_retries);

int hdcp1_start(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hdcp1_start);

void hdcp1_stop(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hdcp1_stop);

/* ---- hdcp2_* (8) ---- */
int hdcp2_app_comm(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_app_comm);

int hdcp2_close_stream(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_close_stream);

void hdcp2_deinit(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hdcp2_deinit);

int hdcp2_feature_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_feature_supported);

int hdcp2_force_encryption(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_force_encryption);

int hdcp2_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_init);

int hdcp2_open_stream(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_open_stream);

int hdcp2_set_hdcp_key_verify_retries(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hdcp2_set_hdcp_key_verify_retries);

/* ---- hw_* (2) ---- */
int hw_monitor_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hw_monitor_notifier_register);

void hw_monitor_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hw_monitor_notifier_unregister);

/* ---- hwmon_* (1) ---- */
int hwmon_device_register_for_thermal(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(hwmon_device_register_for_thermal);

/* ---- hyp_* (1) ---- */
int hyp_assign_table(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(hyp_assign_table);

/* ---- hypsys_* (5) ---- */
int hypsys_event_add_int(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_add_int);

int hypsys_event_add_str(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_add_str);

void * hypsys_event_alloc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(hypsys_event_alloc);

void hypsys_event_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(hypsys_event_destroy);

int hypsys_event_report(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(hypsys_event_report);

/* ---- ieee802_* (1) ---- */
int ieee802_11_parse_elems_full(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ieee802_11_parse_elems_full);

/* ---- init_* (3) ---- */
int init_si_mem_object_sg(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(init_si_mem_object_sg);

int init_si_mem_object_user(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(init_si_mem_object_user);

int init_si_object_user(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(init_si_object_user);

/* ---- ipahal_* (2) ---- */
void * ipahal_get_ep_bit(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(ipahal_get_ep_bit);

void * ipahal_get_ep_reg_idx(void)
{
	return NULL;
}
EXPORT_SYMBOL(ipahal_get_ep_reg_idx);

/* ---- ipc_* (4) ---- */
void * ipc_log_context_create(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(ipc_log_context_create);

void ipc_log_context_destroy(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(ipc_log_context_destroy);

int ipc_log_extract(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(ipc_log_extract);

void ipc_log_string(void *ctxt, const char *fmt, ...)
{
	/* no-op */
}
EXPORT_SYMBOL(ipc_log_string);

/* ---- is_* (5) ---- */
bool is_mem_buf_dma_buf(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_mem_buf_dma_buf);

bool is_mem_object(void)
{
	return false;
}
EXPORT_SYMBOL(is_mem_object);

bool is_mi_dev_support_nova(void)
{
	return false;
}
EXPORT_SYMBOL(is_mi_dev_support_nova);

bool is_nlpid_valid(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_nlpid_valid);

bool is_qos_task(void *a0)
{
	return false;
}
EXPORT_SYMBOL(is_qos_task);

/* ---- kern_* (1) ---- */
int kern_qi_set_qos(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(kern_qi_set_qos);

/* ---- kgsl_* (5) ---- */
int kgsl_add_rcu_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_add_rcu_notifier);

int kgsl_del_rcu_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_del_rcu_notifier);

int kgsl_gpu_frame_count(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_frame_count);

int kgsl_gpu_num_freqs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_num_freqs);

int kgsl_gpu_stat(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(kgsl_gpu_stat);

/* ---- llc_* (1) ---- */
void * llc_stats_get_active_scids(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(llc_stats_get_active_scids);

/* ---- llcc_* (2) ---- */
int llcc_configure_staling_mode(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(llcc_configure_staling_mode);

int llcc_notif_staling_inc_counter(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(llcc_notif_staling_inc_counter);

/* ---- lpd_* (1) ---- */
bool lpd_is_charging_limit(void)
{
	return false;
}
EXPORT_SYMBOL(lpd_is_charging_limit);

/* ---- map_* (1) ---- */
int map_debug_bases(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(map_debug_bases);

/* ---- matt_* (3) ---- */
int matt_register_ulp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(matt_register_ulp);

int matt_trace_msg(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(matt_trace_msg);

int matt_unregister_ulp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(matt_unregister_ulp);

/* ---- mca_* (94) ---- */
int __mca_log_debug(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_debug);

int __mca_log_err(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_err);

int __mca_log_info(const char *fmt, const char *func, int line, ...)
{
	return 0;
}
EXPORT_SYMBOL(__mca_log_info);

int mca_adsp_glink_read_prop(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_read_prop);

int mca_adsp_glink_resister_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_resister_ops);

int mca_adsp_glink_write_prop(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_adsp_glink_write_prop);

int mca_bmd_force_detection(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_bmd_force_detection);

bool mca_bmd_is_batt_missing(void)
{
	return false;
}
EXPORT_SYMBOL(mca_bmd_is_batt_missing);

void mca_cancel_delayed_work(void *dwork)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_cancel_delayed_work);

void mca_cancel_work(void *work)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_cancel_work);

int mca_charge_if_ops_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_if_ops_register);

int mca_charge_mievent_report(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_report);

int mca_charge_mievent_set_state(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_charge_mievent_set_state);

int mca_create_votable(void *dev, const char *name, int type, int *out, void *cb)
{
	return 0;
}
EXPORT_SYMBOL(mca_create_votable);

int mca_debugfs_create_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_debugfs_create_group);

int mca_destroy_votable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_destroy_votable);

int mca_event_block_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify);

int mca_event_block_notify_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_block_notify_register);

void mca_event_block_notify_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_event_block_notify_unregister);

int mca_event_report_multiple_uevent(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_multiple_uevent);

int mca_event_report_uevent(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_event_report_uevent);

void * mca_find_votable(const char *name)
{
	return NULL;
}
EXPORT_SYMBOL(mca_find_votable);

void * mca_get_client_vote(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_client_vote);

void * mca_get_client_vote_locked(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_client_vote_locked);

void * mca_get_effective_client(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_client);

void * mca_get_effective_client_locked(void *votable)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_client_locked);

void * mca_get_effective_result(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_effective_result);

int mca_get_effective_result_locked(void *votable)
{
	return 0;
}
EXPORT_SYMBOL(mca_get_effective_result_locked);

void * mca_get_hwid_info(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_get_hwid_info);

void mca_get_wls_charger_thermal_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_get_wls_charger_thermal_remove);

bool mca_is_client_vote_enabled(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled);

bool mca_is_client_vote_enabled_locked(void *votable, void *client)
{
	return false;
}
EXPORT_SYMBOL(mca_is_client_vote_enabled_locked);

bool mca_is_override_vote_enabled(void *votable)
{
	return false;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled);

bool mca_is_override_vote_enabled_locked(void *votable)
{
	return false;
}
EXPORT_SYMBOL(mca_is_override_vote_enabled_locked);

void mca_lock_votable(void *votable)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_lock_votable);

int mca_log_charge_log_register(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_log_charge_log_register);

void * mca_log_get_charge_boot_mode(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_log_get_charge_boot_mode);

void * mca_log_get_rtc_time(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_log_get_rtc_time);

int mca_mod_delayed_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_mod_delayed_work);

bool mca_panel_get_hbm_state(void)
{
	return false;
}
EXPORT_SYMBOL(mca_panel_get_hbm_state);

int mca_panel_get_screen_state(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_panel_get_screen_state);

int mca_parse_dts_count_strings(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_count_strings);

int mca_parse_dts_s32(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_s32);

int mca_parse_dts_string(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string);

int mca_parse_dts_string_array(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_array);

int mca_parse_dts_string_index(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_string_index);

int mca_parse_dts_u32(void *np, const char *name, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32);

int mca_parse_dts_u32_array(void *np, const char *name, int *out, int n)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_array);

int mca_parse_dts_u32_count(void *np, const char *name, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_count);

int mca_parse_dts_u32_index(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u32_index);

int mca_parse_dts_u8(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8);

int mca_parse_dts_u8_array(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_array);

int mca_parse_dts_u8_count(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_parse_dts_u8_count);

int mca_path_control_enable_gate(void *ctrl, bool en)
{
	return 0;
}
EXPORT_SYMBOL(mca_path_control_enable_gate);

bool mca_qcom_smem_is_zero_speed(void)
{
	return false;
}
EXPORT_SYMBOL(mca_qcom_smem_is_zero_speed);

int mca_queue_delayed_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_delayed_work);

int mca_queue_work(void *wq, void *work)
{
	return 0;
}
EXPORT_SYMBOL(mca_queue_work);

int mca_rerun_election(int id)
{
	return 0;
}
EXPORT_SYMBOL(mca_rerun_election);

void mca_set_wls_charger_thermal_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_set_wls_charger_thermal_remove);

int mca_smartchg_get_board_temp(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_board_temp);

void * mca_smartchg_get_limit_soc(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_smartchg_get_limit_soc);

int mca_smartchg_get_scene(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_get_scene);

int mca_smartchg_if_ops_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_if_ops_register);

bool mca_smartchg_is_extreme_cold_enabled(void)
{
	return false;
}
EXPORT_SYMBOL(mca_smartchg_is_extreme_cold_enabled);

int mca_smartchg_set_batt_emerg_soc_limit(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_batt_emerg_soc_limit);

int mca_smartchg_set_board_temp(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_board_temp);

int mca_smartchg_set_scene(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_smartchg_set_scene);

void * mca_strategy_func_get_status(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(mca_strategy_func_get_status);

int mca_strategy_func_process(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_process);

int mca_strategy_func_set_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_func_set_config);

bool mca_strategy_is_support_pps_100w(void)
{
	return false;
}
EXPORT_SYMBOL(mca_strategy_is_support_pps_100w);

int mca_strategy_ops_register(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mca_strategy_ops_register);

void * mca_subpmic_proxy_get_otg_wls_mutex(void)
{
	return NULL;
}
EXPORT_SYMBOL(mca_subpmic_proxy_get_otg_wls_mutex);

int mca_sysfs_create_files(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_files);

int mca_sysfs_create_group(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_group);

int mca_sysfs_create_link_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_create_link_group);

int mca_sysfs_init_attrs(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_init_attrs);

int mca_sysfs_lookup_attr(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_lookup_attr);

int mca_sysfs_remove_group(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_remove_group);

int mca_sysfs_remove_link_group(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_sysfs_remove_link_group);

void mca_unlock_votable(void *votable)
{
	/* no-op */
}
EXPORT_SYMBOL(mca_unlock_votable);

int mca_vote(void *votable, void *client, int val, int *out)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote);

int mca_vote_override(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(mca_vote_override);

int mca_wireless_rev_enable_reverse_charge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_enable_reverse_charge);

int mca_wireless_rev_get_firmware_state(void)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_get_firmware_state);

void * mca_wireless_rev_get_rev_boost_default(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_rev_boost_default);

void * mca_wireless_rev_get_reverse_chg(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg);

void * mca_wireless_rev_get_reverse_chg_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mca_wireless_rev_get_reverse_chg_state);

bool mca_wireless_rev_get_user_reverse_chg(void)
{
	return false;
}
EXPORT_SYMBOL(mca_wireless_rev_get_user_reverse_chg);

int mca_wireless_rev_set_firmware_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_firmware_state);

int mca_wireless_rev_set_reverse_chg(bool en)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_reverse_chg);

int mca_wireless_rev_set_user_reverse_chg(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_user_reverse_chg);

int mca_wireless_rev_set_wired_chg_ok(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_set_wired_chg_ok);

int mca_wireless_rev_update_fw_version(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mca_wireless_rev_update_fw_version);

/* ---- mem_* (1) ---- */
int mem_object_to_dma_buf(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mem_object_to_dma_buf);

/* ---- memcheck_* (5) ---- */
int memcheck_ashmem_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_ashmem_info_show);

int memcheck_cma_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_cma_info_show);

int memcheck_dmabuf_info_show(void)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_dmabuf_info_show);

int memcheck_slab_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_slab_info_show);

int memcheck_vmalloc_info_show(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(memcheck_vmalloc_info_show);

/* ---- memdup_* (1) ---- */
int memdup_user_trace(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(memdup_user_trace);

/* ---- mi_* (24) ---- */
int mi_dflt_bwmon_update_cur_freq_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_bwmon_update_cur_freq_hook);

int mi_dflt_calculate_dflt_lantancy_hook(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_dflt_lantancy_hook);

int mi_dflt_calculate_mon_sampling_freq_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_calculate_mon_sampling_freq_hook);

void * mi_dflt_get_bwmon_enable(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_enable);

void * mi_dflt_get_bwmon_sample_start(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_bwmon_sample_start);

void * mi_dflt_get_latency_enable(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable);

void * mi_dflt_get_latency_enable_from_user(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_enable_from_user);

void * mi_dflt_get_latency_vote_start(void)
{
	return NULL;
}
EXPORT_SYMBOL(mi_dflt_get_latency_vote_start);

int mi_dflt_process_raw_ctrs_hook(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_process_raw_ctrs_hook);

int mi_dflt_set_bwmon_sample_start(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_bwmon_sample_start);

int mi_dflt_set_latency_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_enable);

int mi_dflt_set_latency_vote_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_set_latency_vote_start);

int mi_dflt_update_memlat_fp_vote_hook(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_dflt_update_memlat_fp_vote_hook);

int mi_display_gesture_callback_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_gesture_callback_register);

int mi_display_pwrkey_callback_set(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_display_pwrkey_callback_set);

int mi_dsi_panel_lockdown_info_read(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read);

int mi_dsi_panel_lockdown_info_read_p8(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_p8);

int mi_dsi_panel_lockdown_info_read_q81(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_dsi_panel_lockdown_info_read_q81);

int mi_scsi_execute_cmd(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(mi_scsi_execute_cmd);

int mi_smart_refill_dynamic_page_pool_refill(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_dynamic_page_pool_refill);

void mi_smart_refill_exit(void)
{
	/* no-op */
}
EXPORT_SYMBOL(mi_smart_refill_exit);

int mi_smart_refill_init(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_init);

int mi_smart_refill_pools_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_pools_init);

int mi_smart_refill_update(void)
{
	return 0;
}
EXPORT_SYMBOL(mi_smart_refill_update);

/* ---- mist_* (1) ---- */
int mist_ddr_vote_enable(void)
{
	return 0;
}
EXPORT_SYMBOL(mist_ddr_vote_enable);

/* ---- mitee_* (3) ---- */
int mitee_smc_notify_connect(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_connect);

int mitee_smc_notify_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_data);

int mitee_smc_notify_signal(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mitee_smc_notify_signal);

/* ---- miui_* (1) ---- */
int miui_cluster_packing_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(miui_cluster_packing_callback);

/* ---- mmrm_* (7) ---- */
bool mmrm_client_check_scaling_supported(void *a0, void *a1)
{
	return false;
}
EXPORT_SYMBOL(mmrm_client_check_scaling_supported);

int mmrm_client_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_deregister);

void * mmrm_client_get_clk_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mmrm_client_get_clk_count);

void * mmrm_client_get_value(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(mmrm_client_get_value);

int mmrm_client_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_register);

int mmrm_client_set_value(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_set_value);

int mmrm_client_set_value_in_range(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(mmrm_client_set_value_in_range);

/* ---- msc_* (12) ---- */
void * msc_system_get_device_capability(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_device_capability);

void * msc_system_get_mpam_version(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_mpam_version);

void * msc_system_get_partition(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(msc_system_get_partition);

int msc_system_mon_alloc_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_alloc_info);

int msc_system_mon_be_bw_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_be_bw_info);

int msc_system_mon_config(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_config);

int msc_system_mon_fe_bw_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_fe_bw_info);

int msc_system_mon_read_all(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_read_all);

int msc_system_mon_read_miss_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_read_miss_info);

int msc_system_mon_stats_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_mon_stats_read);

int msc_system_reset_partition(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_reset_partition);

int msc_system_set_partition(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(msc_system_set_partition);

/* ---- ncm_* (6) ---- */
int ncm_ipa_cleanup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_cleanup);

int ncm_ipa_cleanup_module(void)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_cleanup_module);

int ncm_ipa_init(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_init);

int ncm_ipa_init_module(void)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_init_module);

int ncm_ipa_pipe_connect_notify(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_pipe_connect_notify);

int ncm_ipa_pipe_disconnect_notify(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(ncm_ipa_pipe_disconnect_notify);

/* ---- nfc_* (1) ---- */
int nfc_to_touch_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(nfc_to_touch_event);

/* ---- notify_* (1) ---- */
int notify_raw_data_update(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(notify_raw_data_update);

/* ---- nvt_* (1) ---- */
void * nvt_get_lcm_id_notify(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(nvt_get_lcm_id_notify);

/* ---- oem_* (1) ---- */
int oem_corectl_cpu_busy(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(oem_corectl_cpu_busy);

/* ---- panel_* (3) ---- */
int panel_event_notification_trigger(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(panel_event_notification_trigger);

int panel_event_notifier_register(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(panel_event_notifier_register);

void panel_event_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(panel_event_notifier_unregister);

/* ---- pcie_* (1) ---- */
int pcie_pdc_cfg_irq(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(pcie_pdc_cfg_irq);

/* ---- pen_* (2) ---- */
int pen_charge_state_notifier_register_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pen_charge_state_notifier_register_client);

int pen_charge_state_notifier_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pen_charge_state_notifier_unregister_client);

/* ---- phy_* (4) ---- */
void phy_core_exit(void)
{
	/* no-op */
}
EXPORT_SYMBOL(phy_core_exit);

void * phy_get_num_lanes(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(phy_get_num_lanes);

int phy_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(phy_read);

int phy_write(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(phy_write);

/* ---- ping_* (2) ---- */
int ping_subsystem(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ping_subsystem);

int ping_subsystem_init(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(ping_subsystem_init);

/* ---- pmic_* (3) ---- */
int pmic_glink_register_client(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_register_client);

int pmic_glink_unregister_client(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_unregister_client);

int pmic_glink_write(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(pmic_glink_write);

/* ---- powerinsight_* (10) ---- */
int powerinsight_gpu_close_opp_cost(void)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_close_opp_cost);

void * powerinsight_gpu_get_opp_cnt(void)
{
	return NULL;
}
EXPORT_SYMBOL(powerinsight_gpu_get_opp_cnt);

int powerinsight_gpu_init_opp_cost(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_init_opp_cost);

int powerinsight_gpu_query_opp_cost(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_query_opp_cost);

int powerinsight_gpu_update_opp_cost(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_gpu_update_opp_cost);

int powerinsight_register_module_ops(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_register_module_ops);

int powerinsight_unregister_module_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_unregister_module_ops);

int powerinsight_wifi_wake_data(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_data);

int powerinsight_wifi_wake_interrupt(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_interrupt);

int powerinsight_wifi_wake_reason(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(powerinsight_wifi_wake_reason);

/* ---- product_* (1) ---- */
int product_name_get(void)
{
	return 0;
}
EXPORT_SYMBOL(product_name_get);

/* ---- provide_* (1) ---- */
int provide_qseecom_kernel_fun_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(provide_qseecom_kernel_fun_ops);

/* ---- put_* (1) ---- */
int put_si_object(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(put_si_object);

/* ---- qcom_* (105) ---- */
int qcom_alloc_io_pgtable_ops(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_alloc_io_pgtable_ops);

int qcom_arm_lpae_map_sg(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qcom_arm_lpae_map_sg);

int qcom_arm_lpae_unmap_pages(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_arm_lpae_unmap_pages);

int qcom_cc_sync_state(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_cc_sync_state);

int qcom_clk_crm_set_rate(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_crm_set_rate);

int qcom_clk_crmb_set_rate(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_crmb_set_rate);

void qcom_clk_dump(void *a0, void *a1, void *a2)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_clk_dump);

void * qcom_clk_get_voltage(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_clk_get_voltage);

int qcom_clk_set_flags(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_clk_set_flags);

int qcom_create_ramdump_device(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_create_ramdump_device);

void * qcom_dcvs_get_ddr_child_node(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_dcvs_get_ddr_child_node);

int qcom_dcvs_hw_minmax_get(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_hw_minmax_get);

int qcom_dcvs_kobject_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_kobject_get);

int qcom_dcvs_register_voter(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_register_voter);

int qcom_dcvs_unregister_voter(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_unregister_voter);

int qcom_dcvs_update_votes(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_dcvs_update_votes);

int qcom_destroy_ramdump_device(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_destroy_ramdump_device);

void qcom_dump(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_dump);

void qcom_elf_dump(void *a0, void *a1, void *a2)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_elf_dump);

void * qcom_flash_led_get_max_avail_current(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_flash_led_get_max_avail_current);

int qcom_free_io_pgtable_ops(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_free_io_pgtable_ops);

void qcom_fw_elf_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_fw_elf_dump);

void * qcom_get_cpucp_id(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_get_cpucp_id);

int qcom_glink_early_ssr_notify(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_early_ssr_notify);

void * qcom_glink_get_signals(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_glink_get_signals);

bool qcom_glink_is_wakeup(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_glink_is_wakeup);

void qcom_glink_mem_entry_free(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_glink_mem_entry_free);

int qcom_glink_mem_entry_init(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_mem_entry_init);

int qcom_glink_native_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_native_start);

int qcom_glink_prepare_da_for_cpu(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_prepare_da_for_cpu);

int qcom_glink_register_signals_cb(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_register_signals_cb);

int qcom_glink_rx_done(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_rx_done);

int qcom_glink_rx_done_supported(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_rx_done_supported);

int qcom_glink_set_signals(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_set_signals);

int qcom_glink_smem_early_ssr_notify(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_smem_early_ssr_notify);

int qcom_glink_smem_start(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_smem_start);

int qcom_glink_spss_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_glink_spss_register);

void qcom_glink_spss_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_glink_spss_unregister);

bool qcom_haptics_vi_sense_is_enabled(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_haptics_vi_sense_is_enabled);

int qcom_iommu_enable_s1_translation(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_enable_s1_translation);

void * qcom_iommu_get_asid_nr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_asid_nr);

void * qcom_iommu_get_context_bank_nr(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_context_bank_nr);

void * qcom_iommu_get_fault_ids(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_fault_ids);

void * qcom_iommu_get_mappings_configuration(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_iommu_get_mappings_configuration);

int qcom_iommu_set_fault_model(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_set_fault_model);

int qcom_iommu_set_secure_vmid(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_set_secure_vmid);

int qcom_iommu_sid_switch(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_iommu_sid_switch);

bool qcom_is_dma_buf_file(void *a0)
{
	return false;
}
EXPORT_SYMBOL(qcom_is_dma_buf_file);

int qcom_mpam_config_monitor(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_config_monitor);

void * qcom_mpam_get_bw_limit(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_bw_limit);

void * qcom_mpam_get_bw_limit_rpmsg(void)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_bw_limit_rpmsg);

void * qcom_mpam_get_cache_partition(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_cache_partition);

void * qcom_mpam_get_platform_bw_ctrl(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_platform_bw_ctrl);

void * qcom_mpam_get_version(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_mpam_get_version);

int qcom_mpam_set_bw_limit_rpmsg(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_bw_limit_rpmsg);

int qcom_mpam_set_cache_partition(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_cache_partition);

int qcom_mpam_set_platform_bw_ctrl(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_platform_bw_ctrl);

int qcom_mpam_set_platform_bw_monitor(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_mpam_set_platform_bw_monitor);

int qcom_msc_lookup(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_msc_lookup);

int qcom_notify_early_ssr_clients(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_notify_early_ssr_clients);

int qcom_notify_ssr_clients(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_notify_ssr_clients);

int qcom_pil_timeouts_disabled(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pil_timeouts_disabled);

int qcom_pmu_event_supported(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_event_supported);

int qcom_pmu_idle_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_idle_register);

int qcom_pmu_read(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_read);

int qcom_pmu_read_all_local(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_pmu_read_all_local);

int qcom_q6v5_register_glink_subdev(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_q6v5_register_glink_subdev);

int qcom_q6v5_register_ssr_subdev(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_q6v5_register_ssr_subdev);

int qcom_register_early_ssr_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_register_early_ssr_notifier);

int qcom_rproc_update_recovery_status(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_rproc_update_recovery_status);

int qcom_scm_dcvs_ca_available(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_ca_available);

int qcom_scm_dcvs_core_available(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_core_available);

int qcom_scm_dcvs_init_ca_v2(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_init_ca_v2);

int qcom_scm_dcvs_init_v2(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_init_v2);

void qcom_scm_dcvs_reset(void)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_scm_dcvs_reset);

int qcom_scm_dcvs_update(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update);

int qcom_scm_dcvs_update_ca_v2(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update_ca_v2);

int qcom_scm_dcvs_update_v2(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_dcvs_update_v2);

void * qcom_scm_get_sec_dump_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_sec_dump_state);

void * qcom_scm_get_tz_feat_id_version(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_tz_feat_id_version);

void * qcom_scm_get_tz_log_feat_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_scm_get_tz_log_feat_id);

void qcom_scm_io_reset(void)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_scm_io_reset);

int qcom_scm_kgsl_dcvs_tuning(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_dcvs_tuning);

int qcom_scm_kgsl_init_regs(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_init_regs);

int qcom_scm_kgsl_set_smmu_aperture(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_aperture);

int qcom_scm_kgsl_set_smmu_lpac_aperture(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_kgsl_set_smmu_lpac_aperture);

int qcom_scm_mem_protect_region_id(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_mem_protect_region_id);

int qcom_scm_mem_protect_sd_ctrl(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_mem_protect_sd_ctrl);

int qcom_scm_pas_shutdown_retry(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_pas_shutdown_retry);

int qcom_scm_query_encrypted_log_feature(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_encrypted_log_feature);

int qcom_scm_query_log_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_log_status);

int qcom_scm_query_tz_time(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_query_tz_time);

int qcom_scm_register_qsee_log_buf(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_register_qsee_log_buf);

int qcom_scm_request_encrypted_log(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_request_encrypted_log);

int qcom_scm_smmu_notify_secure_lut(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_scm_smmu_notify_secure_lut);

int qcom_skip_tlb_management(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_skip_tlb_management);

int qcom_spss_set_fw_name(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_spss_set_fw_name);

void * qcom_ssr_get_subsys(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_ssr_get_subsys);

int qcom_stats_ddr_freqsync_msg(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_stats_ddr_freqsync_msg);

void * qcom_sysmon_get_txn_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qcom_sysmon_get_txn_id);

int qcom_unregister_early_ssr_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_unregister_early_ssr_notifier);

int qcom_va_md_add_region(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_add_region);

int qcom_va_md_enabled(void)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_enabled);

int qcom_va_md_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qcom_va_md_register);

void qcom_va_md_unregister(void *a0, void *a1)
{
	/* no-op */
}
EXPORT_SYMBOL(qcom_va_md_unregister);

/* ---- qlpmm_* (1) ---- */
void * qlpmm_get_subsystem_lpm_data(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qlpmm_get_subsystem_lpm_data);

/* ---- qmap_* (1) ---- */
int qmap_encapsulate_skb(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qmap_encapsulate_skb);

/* ---- qptm_* (11) ---- */
int qptm_available_node_count(void)
{
	return 0;
}
EXPORT_SYMBOL(qptm_available_node_count);

int qptm_channel_register(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(qptm_channel_register);

void qptm_channel_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qptm_channel_unregister);

int qptm_data_update_notifier_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qptm_data_update_notifier_register);

void qptm_data_update_notifier_unregister(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(qptm_data_update_notifier_unregister);

int qptm_for_each_node(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qptm_for_each_node);

void * qptm_get_energy_in_uj(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_energy_in_uj);

void * qptm_get_node_id(void)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_node_id);

void * qptm_get_node_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_node_name);

void * qptm_get_power_in_uw(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qptm_get_power_in_uw);

int qptm_power_data_update(void)
{
	return 0;
}
EXPORT_SYMBOL(qptm_power_data_update);

/* ---- qrtr_* (2) ---- */
int qrtr_peek_pkt_size(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qrtr_peek_pkt_size);

int qrtr_print_wakeup_reason(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qrtr_print_wakeup_reason);

/* ---- qseecom_* (3) ---- */
int qseecom_send_command(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(qseecom_send_command);

int qseecom_shutdown_app(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qseecom_shutdown_app);

int qseecom_start_app(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qseecom_start_app);

/* ---- qtee_* (5) ---- */
int qtee_shmbridge_allocate_shm(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_allocate_shm);

int qtee_shmbridge_deregister(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_deregister);

int qtee_shmbridge_free_shm(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_free_shm);

bool qtee_shmbridge_is_enabled(void)
{
	return false;
}
EXPORT_SYMBOL(qtee_shmbridge_is_enabled);

int qtee_shmbridge_register(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6)
{
	return 0;
}
EXPORT_SYMBOL(qtee_shmbridge_register);

/* ---- qti_* (2) ---- */
void * qti_battery_charger_get_prop(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(qti_battery_charger_get_prop);

int qti_smmu_proxy_register_callbacks(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(qti_smmu_proxy_register_callbacks);

/* ---- qts_* (3) ---- */
int qts_client_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qts_client_register);

int qts_ts_resume(void)
{
	return 0;
}
EXPORT_SYMBOL(qts_ts_resume);

int qts_ts_suspend(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qts_ts_suspend);

/* ---- qvadj_* (2) ---- */
void * qvadj_get_cur_voltage_overrides(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(qvadj_get_cur_voltage_overrides);

int qvadj_set_next_voltage_overrides(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(qvadj_set_next_voltage_overrides);

/* ---- regulator_* (1) ---- */
int regulator_proxy_consumer_sync_state(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(regulator_proxy_consumer_sync_state);

/* ---- rpmh_* (4) ---- */
int rpmh_drv_start(void)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_drv_start);

void rpmh_drv_stop(void)
{
	/* no-op */
}
EXPORT_SYMBOL(rpmh_drv_stop);

void * rpmh_get_device(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(rpmh_get_device);

int rpmh_write_sleep_and_wake_no_child(void)
{
	return 0;
}
EXPORT_SYMBOL(rpmh_write_sleep_and_wake_no_child);

/* ---- sched_* (4) ---- */
int sched_entity_freq_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sched_entity_freq_enable);

void * sched_entity_freq_get_runq_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sched_entity_freq_get_runq_count);

bool sched_entity_freq_is_power_save_mode(void *a0)
{
	return false;
}
EXPORT_SYMBOL(sched_entity_freq_is_power_save_mode);

int sched_lpm_disallowed_time(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sched_lpm_disallowed_time);

/* ---- schedule_* (1) ---- */
int schedule_resume_suspend_work(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(schedule_resume_suspend_work);

/* ---- sdca_* (2) ---- */
void * sdca_devices_debugfs_dentry_create(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(sdca_devices_debugfs_dentry_create);

void sdca_devices_debugfs_dentry_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sdca_devices_debugfs_dentry_remove);

/* ---- sde_* (2) ---- */
int sde_i2c_byte_read(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sde_i2c_byte_read);

int sde_i2c_byte_write(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sde_i2c_byte_write);

/* ---- should_* (1) ---- */
int should_boost_bus_dcvs(void)
{
	return 0;
}
EXPORT_SYMBOL(should_boost_bus_dcvs);

/* ---- si_* (3) ---- */
int si_core_client_env_open(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(si_core_client_env_open);

void * si_core_get_client_env(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(si_core_get_client_env);

int si_object_do_invoke(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(si_object_do_invoke);

/* ---- sipa_* (8) ---- */
void * sipa_get_channels(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(sipa_get_channels);

int sipa_i2c_probe(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_i2c_probe);

void sipa_i2c_remove(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_i2c_remove);

void sipa_i2c_shutdown(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_i2c_shutdown);

int sipa_multi_channel_load_fw(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_multi_channel_load_fw);

void sipa_multi_channel_power_off(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_multi_channel_power_off);

int sipa_multi_channel_power_on_and_set_scene(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sipa_multi_channel_power_on_and_set_scene);

void sipa_multi_channel_reg_dump(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(sipa_multi_channel_reg_dump);

/* ---- smmu_* (2) ---- */
void * smmu_proxy_get_csf_version(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(smmu_proxy_get_csf_version);

int smmu_proxy_switch_sid(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(smmu_proxy_switch_sid);

/* ---- socinfo_* (9) ---- */
void * socinfo_get_feature_code(void)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_feature_code);

void * socinfo_get_part_count(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_part_count);

void * socinfo_get_part_info(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_part_info);

void * socinfo_get_partinfo_chip_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_chip_id);

void * socinfo_get_partinfo_part_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_part_name);

void * socinfo_get_partinfo_vulkan_id(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_partinfo_vulkan_id);

void * socinfo_get_pcode(void)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_pcode);

void * socinfo_get_serial_number(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_serial_number);

void * socinfo_get_subpart_info(void *a0, void *a1, void *a2)
{
	return NULL;
}
EXPORT_SYMBOL(socinfo_get_subpart_info);

/* ---- spec_* (1) ---- */
int spec_sync_wait_bind_array(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(spec_sync_wait_bind_array);

/* ---- spf_* (2) ---- */
int spf_core_apm_close_all(void)
{
	return 0;
}
EXPORT_SYMBOL(spf_core_apm_close_all);

bool spf_core_is_apm_ready(void *a0)
{
	return false;
}
EXPORT_SYMBOL(spf_core_is_apm_ready);

/* ---- spmi_* (1) ---- */
int spmi_pmic_arb_map_address(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(spmi_pmic_arb_map_address);

/* ---- strategy_* (38) ---- */
bool strategy_class_fg_dual_is_chip_ok(void *a0)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_dual_is_chip_ok);

bool strategy_class_fg_get_authentic(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_get_authentic);

void * strategy_class_fg_get_comp_fcc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_comp_fcc);

void * strategy_class_fg_get_comp_rm(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_comp_rm);

void * strategy_class_fg_get_dc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_dc);

void * strategy_class_fg_get_fastcharge(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_fastcharge);

int strategy_class_fg_get_fcc(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_fcc);

void * strategy_class_fg_get_first_termination(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_first_termination);

void * strategy_class_fg_get_health(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_health);

bool strategy_class_fg_get_is_support_fast_mode(void *a0)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_get_is_support_fast_mode);

void * strategy_class_fg_get_model_name(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_model_name);

int strategy_class_fg_get_pack_vendor_id(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_pack_vendor_id);

int strategy_class_fg_get_rm(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_rm);

void * strategy_class_fg_get_soh(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_soh);

void * strategy_class_fg_get_vacc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_get_vacc);

int strategy_class_fg_get_voltage_mean(void)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_get_voltage_mean);

bool strategy_class_fg_is_chip_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_is_chip_ok);

void * strategy_class_fg_ops_get_charging_done(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_charging_done);

void * strategy_class_fg_ops_get_current(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_current);

void * strategy_class_fg_ops_get_cyclecount(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_cyclecount);

void * strategy_class_fg_ops_get_real_soc_decimal(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_real_soc_decimal);

void * strategy_class_fg_ops_get_rsoc(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_rsoc);

void * strategy_class_fg_ops_get_soc(void)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_soc);

void * strategy_class_fg_ops_get_soc_decimal(void *a0, void *a1)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_soc_decimal);

void * strategy_class_fg_ops_get_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_temperature);

void * strategy_class_fg_ops_get_thermal_temperature(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_thermal_temperature);

void * strategy_class_fg_ops_get_voltage(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_fg_ops_get_voltage);

bool strategy_class_fg_ops_is_init_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_init_ok);

bool strategy_class_fg_ops_is_vacc2_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_vacc2_ok);

bool strategy_class_fg_ops_is_vacc_ok(void)
{
	return false;
}
EXPORT_SYMBOL(strategy_class_fg_ops_is_vacc_ok);

int strategy_class_fg_ops_register(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_ops_register);

int strategy_class_fg_ops_set_charging_done(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_ops_set_charging_done);

int strategy_class_fg_set_fastcharge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_fg_set_fastcharge);

void * strategy_class_wireless_op_get_rx_iout_limit(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_op_get_rx_iout_limit);

void * strategy_class_wireless_ops_get_adapter_charger_mode(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_adapter_charger_mode);

void * strategy_class_wireless_ops_get_adapter_power(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_adapter_power);

void * strategy_class_wireless_ops_get_wls_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_get_wls_type);

int strategy_class_wireless_ops_set_parallel_charge(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(strategy_class_wireless_ops_set_parallel_charge);

/* ---- stream_* (3) ---- */
int stream_agg_add_channel(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_add_channel);

int stream_agg_prepare_channel(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_prepare_channel);

int stream_agg_remove_channel(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(stream_agg_remove_channel);

/* ---- subsystem_* (3) ---- */
int subsystem_sleep_debug_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(subsystem_sleep_debug_enable);

int subsystem_sleep_stats_dbg_register(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(subsystem_sleep_stats_dbg_register);

void subsystem_sleep_stats_dbg_unregister(void)
{
	/* no-op */
}
EXPORT_SYMBOL(subsystem_sleep_stats_dbg_unregister);

/* ---- swrm_* (1) ---- */
int swrm_wcd_notify(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(swrm_wcd_notify);

/* ---- sysmon_* (7) ---- */
int sysmon_stats_query_ddr_residency(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_ddr_residency);

int sysmon_stats_query_hmx_utlization(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_hmx_utlization);

int sysmon_stats_query_hvx_utlization(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_hvx_utlization);

int sysmon_stats_query_power_residency(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_power_residency);

int sysmon_stats_query_q6_load(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_q6_load);

int sysmon_stats_query_q6_votes(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_q6_votes);

int sysmon_stats_query_sleep(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysmon_stats_query_sleep);

/* ---- sysstats_* (4) ---- */
int sysstats_register_iterate_kgsl_process_privates(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_iterate_kgsl_process_privates);

int sysstats_register_kgsl_memstat_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_kgsl_memstat_cb);

int sysstats_register_kgsl_stats_cb(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_register_kgsl_stats_cb);

int sysstats_unregister_kgsl_stats_cb(void)
{
	return 0;
}
EXPORT_SYMBOL(sysstats_unregister_kgsl_stats_cb);

/* ---- system_* (1) ---- */
int system_heap_allocate_async_read(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(system_heap_allocate_async_read);

/* ---- tas25xx_* (8) ---- */
bool tas25xx_check_if_algo_ctrl_bypassed(void *a0)
{
	return false;
}
EXPORT_SYMBOL(tas25xx_check_if_algo_ctrl_bypassed);

int tas25xx_deregister_misc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_deregister_misc);

void * tas25xx_get_drv_channel_opmode(void)
{
	return NULL;
}
EXPORT_SYMBOL(tas25xx_get_drv_channel_opmode);

void * tas25xx_get_state(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(tas25xx_get_state);

int tas25xx_prep_dev_for_calib(void)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_prep_dev_for_calib);

int tas25xx_register_amp_error_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_amp_error_callback);

int tas25xx_register_i2c_error_callback(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_i2c_error_callback);

int tas25xx_register_misc(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(tas25xx_register_misc);

/* ---- tmecom_* (1) ---- */
int tmecom_process_request(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(tmecom_process_request);

/* ---- tmelog_* (1) ---- */
int tmelog_process_request(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(tmelog_process_request);

/* ---- trigger_* (2) ---- */
void trigger_dump_disable(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(trigger_dump_disable);

int trigger_dump_enable(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(trigger_dump_enable);

/* ---- ufs_* (3) ---- */
int ufs_ffu_reboot_reason_reboot(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(ufs_ffu_reboot_reason_reboot);

int ufs_scsi_read_partition(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ufs_scsi_read_partition);

int ufs_scsi_write_partition(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(ufs_scsi_write_partition);

/* ---- unregister_* (9) ---- */
int unregister_cam_freq_hook(void)
{
	return 0;
}
EXPORT_SYMBOL(unregister_cam_freq_hook);

int unregister_hboost_event_notifier(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hboost_event_notifier);

int unregister_hw_component_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hw_component_info);

int unregister_hw_monitor_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_hw_monitor_info);

int unregister_micam_cpu_cycles_calibration_hook(void)
{
	return 0;
}
EXPORT_SYMBOL(unregister_micam_cpu_cycles_calibration_hook);

int unregister_phy_device(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(unregister_phy_device);

int unregister_touch_panel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_touch_panel);

int unregister_xiaomi_input_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_xiaomi_input_dev);

int unregister_xiaomi_stylus_input_dev(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(unregister_xiaomi_stylus_input_dev);

/* ---- update_* (8) ---- */
int update_abnormal_event(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_abnormal_event);

int update_ch_per_substream(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(update_ch_per_substream);

int update_fod_press_status(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_fod_press_status);

int update_hw_monitor_info(void *a0, void *a1, void *a2)
{
	return 0;
}
EXPORT_SYMBOL(update_hw_monitor_info);

int update_palm_sensor_value(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_palm_sensor_value);

int update_palm_sensor_value_second_panel(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_palm_sensor_value_second_panel);

int update_phy_device_nr_lanes(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(update_phy_device_nr_lanes);

int update_weak_doubletap_value(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(update_weak_doubletap_value);

/* ---- wakeup_* (1) ---- */
int wakeup_xswapds(void)
{
	return 0;
}
EXPORT_SYMBOL(wakeup_xswapds);

/* ---- walt_* (3) ---- */
void * walt_get_cpus_in_state1(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_cpus_in_state1);

void * walt_get_cpus_taken(void)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_cpus_taken);

void * walt_get_halted_cpus(void)
{
	return NULL;
}
EXPORT_SYMBOL(walt_get_halted_cpus);

/* ---- waltgov_* (1) ---- */
int waltgov_cam_cpu(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(waltgov_cam_cpu);

/* ---- wcnss_* (5) ---- */
bool wcnss_check_pool_lists(void)
{
	return false;
}
EXPORT_SYMBOL(wcnss_check_pool_lists);

void wcnss_pre_alloc_reset(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcnss_pre_alloc_reset);

bool wcnss_prealloc_check_memory_leak(void *a0)
{
	return false;
}
EXPORT_SYMBOL(wcnss_prealloc_check_memory_leak);

int wcnss_prealloc_get(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(wcnss_prealloc_get);

void wcnss_prealloc_put(void *a0)
{
	/* no-op */
}
EXPORT_SYMBOL(wcnss_prealloc_put);

/* ---- wled_* (1) ---- */
int wled_flash_led_prepare(void)
{
	return 0;
}
EXPORT_SYMBOL(wled_flash_led_prepare);

/* ---- wsa883x_* (3) ---- */
void * wsa883x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wsa883x_codec_get_dev_num);

int wsa883x_codec_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wsa883x_codec_info_create_codec_entry);

int wsa883x_set_channel_map(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(wsa883x_set_channel_map);

/* ---- wsa884x_* (3) ---- */
void * wsa884x_codec_get_dev_num(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(wsa884x_codec_get_dev_num);

int wsa884x_codec_info_create_codec_entry(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(wsa884x_codec_info_create_codec_entry);

int wsa884x_set_channel_map(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
	return 0;
}
EXPORT_SYMBOL(wsa884x_set_channel_map);

/* ---- xiaomi_* (5) ---- */
void * xiaomi_get_gesture_type(void *a0)
{
	return NULL;
}
EXPORT_SYMBOL(xiaomi_get_gesture_type);

int xiaomi_register_panel_notifier(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_register_panel_notifier);

int xiaomi_touch_mievent_report_int(void *a0, void *a1, void *a2, void *a3, void *a4)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_int);

int xiaomi_touch_mievent_report_str(void *a0, void *a1, void *a2, void *a3)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_touch_mievent_report_str);

int xiaomi_unregister_panel_notifier(void *a0, void *a1)
{
	return 0;
}
EXPORT_SYMBOL(xiaomi_unregister_panel_notifier);

/* ---- zs_* (1) ---- */
int zs_map_object_straddle_info(void *a0)
{
	return 0;
}
EXPORT_SYMBOL(zs_map_object_straddle_info);


/* ==================== 变量定义 ==================== */

int current_log_level;
EXPORT_SYMBOL(current_log_level);

struct qmi_elem_info data_ep_id_type_v01_ei[1];
EXPORT_SYMBOL(data_ep_id_type_v01_ei);

struct qmi_elem_info dhms_mem_alloc_addr_info_type_v01_ei[1];
EXPORT_SYMBOL(dhms_mem_alloc_addr_info_type_v01_ei);

struct qmi_elem_info dms_get_mac_address_req_msg_v01_ei[1];
EXPORT_SYMBOL(dms_get_mac_address_req_msg_v01_ei);

struct qmi_elem_info dms_get_mac_address_resp_msg_v01_ei[1];
EXPORT_SYMBOL(dms_get_mac_address_resp_msg_v01_ei);

void *gprbus;
EXPORT_SYMBOL(gprbus);

struct qmi_elem_info ims_private_service_mt_invite_ind_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_mt_invite_ind_msg_v01_ei);

struct qmi_elem_info ims_private_service_subscribe_ind_req_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_subscribe_ind_req_msg_v01_ei);

struct qmi_elem_info ims_private_service_subscribe_ind_rsp_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_subscribe_ind_rsp_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_status_ind_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_status_ind_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_twt_config_req_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_twt_config_req_msg_v01_ei);

struct qmi_elem_info ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei[1];
EXPORT_SYMBOL(ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei);

struct kobject low_lat_mem_kobject;
EXPORT_SYMBOL(low_lat_mem_kobject);

struct qmi_elem_info mem_alloc_generic_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_alloc_generic_req_msg_data_v01_ei);

struct qmi_elem_info mem_alloc_generic_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_alloc_generic_resp_msg_data_v01_ei);

struct qmi_elem_info mem_free_generic_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_free_generic_req_msg_data_v01_ei);

struct qmi_elem_info mem_free_generic_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_free_generic_resp_msg_data_v01_ei);

struct qmi_elem_info mem_query_size_req_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_query_size_req_msg_data_v01_ei);

struct qmi_elem_info mem_query_size_resp_msg_data_v01_ei[1];
EXPORT_SYMBOL(mem_query_size_resp_msg_data_v01_ei);

void *memcheck_kgsl_memstat;
EXPORT_SYMBOL(memcheck_kgsl_memstat);

void *memcheck_walk_process_privates;
EXPORT_SYMBOL(memcheck_walk_process_privates);

void *mi_smart_refill_pools;
EXPORT_SYMBOL(mi_smart_refill_pools);

void *micam_amu_data;
EXPORT_SYMBOL(micam_amu_data);

void *miui_power_enhance;
EXPORT_SYMBOL(miui_power_enhance);

unsigned long pwrkey_irq_notifier_list;
EXPORT_SYMBOL(pwrkey_irq_notifier_list);

void *qcom_device_shutdown_in_progress;
EXPORT_SYMBOL(qcom_device_shutdown_in_progress);

struct bus_type soundwire_type;
EXPORT_SYMBOL(soundwire_type);
