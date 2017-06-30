function save(oTable,pg_bfr)
{
	var $data = "idx=2&"+$('input[type=hidden]').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize();
	var my_ajax = new myajax;
	my_ajax.url = "../global_code/isikrs.php";
	my_ajax.data = $data;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	}
	my_ajax.getdata();
}