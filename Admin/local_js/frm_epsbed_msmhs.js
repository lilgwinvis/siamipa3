

function init_tb() {

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_epsbedmsmhs';
	vmydatatable.template = 1;
	vmydatatable.title = 2;
	vmydatatable.idxdetail = 1;
	vmydatatable.settemplate();
	vmydatatable.aoColumnDefs[0].aTargets = [0, 9, 10, 11, 12, 13];
	vmydatatable.togle();
	vmydatatable.create();

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'stat_epsbedmsmhs';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();

}

function add_click(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=50";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();
}

function del_click(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=51";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();
}

function down_click(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=52";
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	};
	my_ajax.getdata();
}

function update_click(thn) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=53";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();
}