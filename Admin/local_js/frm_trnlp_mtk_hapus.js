function entry_data(pg_bfr) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/isitrnlp.php";
	my_ajax.data = "idx=2&"+$('input[type=hidden]').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize();
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	}
	my_ajax.getdata();
}