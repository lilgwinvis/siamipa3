

function del(oTable, idx, pg_bfr) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_dsn.php";
	my_ajax.data = $(":input", oTable.fnGetNodes()).serialize() + '&idx=' + idx;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	};
	my_ajax.getdata();
}

function save(pg_bfr, idx) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_dsn.php";
	my_ajax.data = $("#entrydsn").serialize() + '&idx=' + idx;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	};
	my_ajax.getdata();
}
function init_tb()
{
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_dsn';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	
	return vmydatatable.create();
	
	
	
}