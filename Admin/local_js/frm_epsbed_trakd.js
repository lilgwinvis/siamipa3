
function init_tb(idx = 0) {

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_epsbedtrakd';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'stat2_epsbedtrnlm';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();

	if (idx > 0) {
		var vmydatatable = new mydatatable;
		vmydatatable.id = 'stat1_epsbedtrnlm';
		vmydatatable.template = 0;
		vmydatatable.title = 0;
		vmydatatable.bPaginate = true;
		vmydatatable.bFilter = true;
		vmydatatable.settemplate();
		vmydatatable.create();
	}

}

function update_stat() {
	$("#stat").html("<fieldset><font size='1' color='red'>Memroses Data ....</font> <img src='../img/ajax-loader.gif' /></fieldset>");

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "idx=55";
	my_ajax.success = function success(data) {
		$("#stat").html(data);
		init_tb(1);
	};
    my_ajax.getdata();
}

function filter_click(thn) {
    
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=23";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();

}

function add_click(thn) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=24";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		update_stat();
	};
    my_ajax.getdata();
}

function del_click(thn) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=25";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		update_stat();
	};
    my_ajax.getdata();
}

function down_click(thn) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=26";
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	};
	my_ajax.getdata();
}