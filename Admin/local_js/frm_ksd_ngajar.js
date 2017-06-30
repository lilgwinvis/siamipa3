
function init_tb() {

	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_dsn';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.bSort = true;
	vmydatatable.aaSorting = [[3, 'desc'], [2, 'desc']];
	vmydatatable.settemplate();
	vmydatatable.create();
}

function init() {
	$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

	var my_ajax = new myajax;
	my_ajax.url = "local_class/chg_conten.php";
	my_ajax.data = "idx=4";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.error = function (jqXHR, textStatus, errorThrown) {
		var r = jQuery.parseJSON(jqXHR.responseText);
		var txt = "Message: " + r.Message + "<br>StackTrace: " + r.StackTrace + "<br>ExceptionType: " + r.ExceptionType;
		$("#data").html(txt);
	}
	my_ajax.getdata();

	$('#pgload').html("");
}

function del() {
	$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

	var my_ajax = new myajax;
	my_ajax.url = "local_class/mankrs.php";
	my_ajax.data = "idx=4";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();
}

function mig() {
	$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

	var my_ajax = new myajax;
	my_ajax.url = "local_class/mankrs.php";
	my_ajax.data = "idx=3";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	};
	my_ajax.getdata();

}