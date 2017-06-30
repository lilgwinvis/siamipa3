var oTable;

function init_tb() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_stat';
	vmydatatable.template = 1;
	vmydatatable.title = 2;
	vmydatatable.settemplate();
	oTable = vmydatatable.create();
}

function del(pg_bfr,idx,thn){
	
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_stat_mhs.php";
	my_ajax.data = $(":input",oTable.fnGetNodes()).serialize()+'&idx='+idx+'&thn='+thn;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr+'?thn='+thn);
	}
	my_ajax.getdata();
}

function save(pg_bfr,idx,thn){
	
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/entry_dt_stat_mhs.php";
	my_ajax.data =$(":input",oTable.fnGetNodes()).serialize()+'&idx='+idx+'&thn='+thn;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr+'?thn='+thn);
	}
	my_ajax.getdata();
}