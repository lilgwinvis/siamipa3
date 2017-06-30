function menu(idx) {
		var menus = ["frm_riwayat.php",
		             "frm_hutang.php",
					 "frm_ksd_ngajar.php",
					 "../Admin/frm_sebaran.php?idx=3",
					 "../Admin/frm_jdwl_kuliah.php?idx=3",
					 "frm_profile.php",
					 "frm_gnt_pass.php",
					 "../global_code/frm_login.php?idx=3&isout=1"
					];
		
		$("#mainFrame").attr("src",menus[idx]);
		return 0;
	}