function init_table() {
	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_dsn';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.rowselect();
	oTable = vmydatatable.create();
}

function open() {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/chg_conten.php";
	my_ajax.data = "idx=1";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_table();
	};
	myajax.error = function (jqXHR, textStatus, errorThrown) {
		var r = jQuery.parseJSON(jqXHR.responseText);
		var txt = "Message: " + r.Message + "<br>StackTrace: " + r.StackTrace + "<br>ExceptionType: " + r.ExceptionType;
		$("#data").html(txt);
	};
	my_ajax.getdata();
}