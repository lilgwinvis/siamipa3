	function init_tb(namatb, bgroup, idx) {
		vmydatatable = new mydatatable;
		vmydatatable.id = namatb;
		vmydatatable.template = ((bgroup > 0) ? 1 : 0);
		vmydatatable.title = ((bgroup == 2) ? bgroup : idx);

		if (bgroup < 2) {
			vmydatatable.bProcessing = false;
			vmydatatable.bServerSide = false;
			vmydatatable.sAjaxSource = null;
			vmydatatable.sServerMethod = null;
			vmydatatable.fnServerParams = null;
		} else {
						
			vmydatatable.bProcessing = true;
			vmydatatable.bServerSide = true;
			vmydatatable.sAjaxSource = "local_class/chg_conten.php";
			vmydatatable.sServerMethod = 'POST';

			vmydatatable.fnServerParams = function (aoData) {
				
				aoData.push({
					"name" : "idx",
					"value" : "6"
				},{
					"name" : "namatb",
					"value" : namatb
				}
				);
				
				
				
			};
		}

		vmydatatable.settemplate();
		vmydatatable.create();
	}
	
	function init() {
		$("#tabs").tabs();
		$("#tabs1").tabs();
		$('#pgload').html("");
		init_tab_sum();
		init_tab_per_mhs();
		var vmyaccordion = new myaccordion;
		vmyaccordion.id = 'accordion';
		vmyaccordion.create();		
	}
	
	function init_tab_per_mhs()
	{
		init_tb("tb_sks_sem", 0, 1);
		init_tb("jml_sks", 0, 0);
		init_tb("hit_ipk", 0, 0);
		init_tb("rstat", 0, 0);
		init_tb("mstud", 0, 0);
		init_tb("poskeu", 0, 0);

		init_tb("blm_amb", 1, 1);
		init_tb("cobaE", 1, 0);
		init_tb("cobaD", 1, 0);
		init_tb("cobaT", 1, 0);

		init_tb("coba1E", 1, 0);
		init_tb("coba1D", 1, 0);
		init_tb("coba1T", 1, 0);
	}
	
	function init_tab_sum()
    {
		init_tb("sumaktif1", 2, 0);
		init_tb("sumaktif2", 2, 0);
		init_tb("sumnonaktif", 2, 0);
		init_tb("sumcuti", 2, 0);
		init_tb("sumlulus", 2, 0);
		init_tb("sumkeluar", 2, 0);
	}	
	
	
	function update_kelas(thnmsmshs)
	{
		var my_ajax = new myajax;
		my_ajax.url = "local_class/ambilkelas.php";
		my_ajax.data = "thnmsmshs=" + thnmsmshs;
		my_ajax.success = function success(data) {
			$("#kls").html(data);
			var kelas = $("#kls").val();
			update_cmb_mhs(thnmsmshs, kelas);
		}
		my_ajax.getdata();
	}
	
	function update_cmb_mhs(thnmsmshs,kelas)
	{
		var my_ajax = new myajax;
		my_ajax.url = "local_class/ambilnm.php";
		my_ajax.data = "thnmsmshs=" + thnmsmshs + "&kelas=" + kelas;
		my_ajax.success = function success(data) {
			$("#Mhs").html(data);
		}
		my_ajax.getdata();
	}
	
	function filter(nim)
	{
		var my_ajax = new myajax;
		my_ajax.url = "../global_class/chg_conten.php";
		my_ajax.data = "nim=" + nim + "&idx=1";
		my_ajax.success = function success(data) {
			$("#data").html(data);
			$("#tabs").tabs();
			init_tab_per_mhs();
		}
		my_ajax.getdata();
	}
	
