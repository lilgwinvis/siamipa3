var oTable;
function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_trans';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.rowselected();
	return vmydatatable.create();
}

function filter(thnmsmshs, kelas) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thnmsmshs + "&kls=" + kelas + "&idx=20";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		oTable = init_tb();
	};
	my_ajax.getdata();
}

function cmbangk_change(thnmsmshs) {

	var my_ajax = new myajax;
	my_ajax.url = "local_class/ambilkelas.php";
	my_ajax.data = "thnmsmshs=" + thnmsmshs;
	my_ajax.success = function success(data) {
		$("#kls").html(data);
	};
	my_ajax.getdata();

}

function hitung(thn,kls)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_keuangk.php";
	my_ajax.data = "idx=4&thn=" + thn + '&kls='+kls;
	my_ajax.success = function success(data) {
		alert(data);
		filter(thn,kls);
	};
	my_ajax.getdata();
}