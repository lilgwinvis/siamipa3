function init_tb() {
	return $("#tb_filter").dataTable({});
}

function cmbkelas_change(thnmsmshs, kelas) {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/ambilnm.php";
	my_ajax.data = "thnmsmshs=" + thnmsmshs + "&kelas=" + kelas;
	my_ajax.success = function success(data) {
		$("#Mhs").html(data);
	};
	my_ajax.getdata();
}

function cmbangk_change(thnmsmshs) {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/ambilkelas.php";
	my_ajax.data = "thnmsmshs=" + thnmsmshs;
	my_ajax.success = function success(data) {
		$("#kls").html(data);
		var kelas = $("#kls").val();
		cmbkelas_change(thnmsmshs, kelas);
	};
	my_ajax.getdata();
}

function filter(nim) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "nim=" + nim + "&idx=48";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		oTable = init_tb();
	};
	my_ajax.getdata();
}

function btn_save(oTable, nim) {
	var my_ajax = new myajax;
	my_ajax.url = "entry.php";
	my_ajax.data = "vnim=" + nim + "&" + $(":input", oTable.fnGetNodes()).serialize();
	my_ajax.success = function success(data) {
		filter(nim);
	};
	my_ajax.getdata();
}