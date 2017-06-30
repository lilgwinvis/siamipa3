var oTable;

function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_trans';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.bSort = true;
	vmydatatable.aoColumnDefs = [{
			'bSortable' : false,
			'aTargets' : [1]
		}, {
			'bVisible' : false,
			'aTargets' : [0]
		}
	];
	vmydatatable.settemplate();
	vmydatatable.rowselected();
	return vmydatatable.create();
}

function filter(nim) {	
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "nim=" + nim + "&idx=17";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		oTable = init_tb();
	};
	my_ajax.getdata();
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

function hitung(nim)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_trkeumhs.php";
	my_ajax.data = "idx=4&nim=" + nim;
	my_ajax.success = function success(data) {
		alert(data);
		filter(nim);
	};
	my_ajax.getdata();
}

function ctk_excel() {

	data = "nim=" + $("#Mhs").val();
	data = data + '&idx=14';

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = data;
	my_ajax.success = function success(data) {
		alert(data);
		window.open(data, 'Download');
	};
	my_ajax.getdata();

}