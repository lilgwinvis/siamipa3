function save(oTable,pg_bfr,thnsms)
{
	var $data = $('input[type=hidden]').serialize()+"&"+$('input:text').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize();
	var my_ajax = new myajax;
	my_ajax.url = "local_class/isiriwayatkrs.php";
	my_ajax.data =  $data+"&thnsms="+thnsms;
	my_ajax.success = function success(data) {
		alert(data);
		window.parent.pg_bfr(pg_bfr);
	}
	my_ajax.getdata();
}