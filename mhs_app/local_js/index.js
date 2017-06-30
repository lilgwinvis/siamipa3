function menu(idx) {
		var menus = ["frm_summary.php",
		             "frm_khs.php",
					 "frm_trans.php",
					 "frm_krs.php" ,
					 "frm_mtk.php",
					 "../Admin/frm_sebaran.php?idx=2" ,
					 "../Admin/frm_jdwl_kuliah.php?idx=2",
					 "frm_tran_keu_mhs.php",
					 "frm_tot_tran_keu_mhs.php",
					 "frm_profile.php",
					 "frm_gnt_pass.php",
					 "../global_code/frm_login.php?idx=2&isout=1"
					];
		
		$("#mainFrame").attr("src",menus[idx]);
		return 0;
	}
	