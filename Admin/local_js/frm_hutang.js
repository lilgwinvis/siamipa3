


function init_tb(nm,is_ss) {

	vmydatatable = new mydatatable;
	vmydatatable.id = nm;
	vmydatatable.template = 1;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	
	if (is_ss == 1) {		
		vmydatatable.bProcessing = true;
		vmydatatable.bServerSide = true;
		vmydatatable.sAjaxSource = "local_class/chg_conten.php";
		vmydatatable.sServerMethod = 'POST';
        vmydatatable.fnServerParams = function ( aoData ) {
            aoData.push( { "name": "idx", "value": "5" } );
        };		
	}else{		
		vmydatatable.bProcessing = false;
		vmydatatable.bServerSide = false;
		vmydatatable.sAjaxSource =null;
		vmydatatable.sServerMethod = null;
        vmydatatable.fnServerParams = null;		
	}
	
	
	vmydatatable.settemplate();
	vmydatatable.create();

}

function ctk_excel(idx, sem, kls, kdkmk, nakmk, kdds, thnsms) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = "idx=" + idx + "&sem=" + sem + "&kls=" + kls + "&kdkmk=" + kdkmk + "&nakmk=" + nakmk + "&kdds=" + kdds + "&thnsms=" + thnsms;
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	};
	my_ajax.getdata();

}

function filter() {
	var kode = $("#Kode").val();
	var tmp = $('#Kode').find('option:selected').text();
	$("#hsl_filter").html("Hasil Filter : " + tmp);
	$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "nim=" + kode + "&idx=11&tg=1";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb('tb_hutang',0)
	};
	my_ajax.getdata();

}

function init() {
	$("#data1").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

	var my_ajax = new myajax;
	my_ajax.url = "local_class/chg_conten.php";
	my_ajax.data = "idx=3";
	my_ajax.success = function success(data) {
		$("#data1").html(data);		
		init_tb('tb_hutang',0);
		init_tb('lst_mtk',1);
		$("#tabs").tabs();
		$("#filter").click(function () {
			filter();
		});
	};
	my_ajax.error = function (jqXHR, textStatus, errorThrown) {
		var r = jQuery.parseJSON(jqXHR.responseText);
		var txt = "Message: " + r.Message + "<br>StackTrace: " + r.StackTrace + "<br>ExceptionType: " + r.ExceptionType;
		$("#data1").html(txt);
	}
	my_ajax.getdata();
}