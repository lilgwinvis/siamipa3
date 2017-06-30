
function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_stat';
	vmydatatable.template = 1;
	vmydatatable.title = 2;
	vmydatatable.settemplate();
	vmydatatable.create();

	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_summary';
	vmydatatable.bFilter = true;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.create();
}

function filter(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=21";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	}
	my_ajax.getdata();

}

function cetak(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = "sem=" + thn + "&idx=18";
	my_ajax.success = function success(data) {
		alert(data);
		window.open(data, 'Download');
	}
	my_ajax.getdata();

}