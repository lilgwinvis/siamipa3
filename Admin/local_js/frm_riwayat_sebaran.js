function init_tb() {

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'box-table-a';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();

}

function filter(thn) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=14";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	}
	my_ajax.getdata();

}