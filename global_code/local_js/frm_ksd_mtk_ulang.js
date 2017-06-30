function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'sebaran';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	return vmydatatable.create();

}

function save(oTable, pg_bfr) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/save_ksd_ngajar.php";
	my_ajax.data = $('input[type=hidden]').serialize() + "&" + $('input:text').serialize() + "&" + $(":input", oTable.fnGetNodes()).serialize();
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	};
	my_ajax.getdata();

}