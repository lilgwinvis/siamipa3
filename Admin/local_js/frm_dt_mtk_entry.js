function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_mtk';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	return vmydatatable.create();

}

function del(oTable, idx, pg_bfr) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_mtk.php";
	my_ajax.data = $(":input", oTable.fnGetNodes()).serialize() + '&idx=' + idx;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	};
	my_ajax.getdata();

}

function save(idx, pg_bfr, kdmtk) {

	var tmp;

	if (idx == 4) {

		tmp=$("#entrymtk").serialize() + '&idx=' + idx + '&kdkmk=' + kdmtk;

	} else {

		tmp=$("#entrymtk").serialize() + '&idx=' + idx;

	}

	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_mtk.php";
	my_ajax.data = tmp;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	};
	my_ajax.getdata();

}