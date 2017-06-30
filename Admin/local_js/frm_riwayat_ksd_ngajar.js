function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_dsn';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.bSort = true;
	vmydatatable.aaSorting = [[2, 'desc']];
	vmydatatable.settemplate();
	vmydatatable.create();
}

function filter(thn) {	
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=16";
	my_ajax.success = function success(data) {
		$("#data1").html(data);
			init_tb();
	};
	my_ajax.getdata();
	
}