	function init_tb() {
		vmydatatable = new mydatatable;
		vmydatatable.id = 'tb_riwayat';
		vmydatatable.template = 1;
		vmydatatable.title = 0;
		vmydatatable.bPaginate = true;
		vmydatatable.bInfo = true;
		vmydatatable.bFilter = true;
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
		my_ajax.data = "nim=" + kode + "&idx=4&tg=1";
		my_ajax.success = function success(data) {
			$("#data").html(data);
			init_tb();
		};
		my_ajax.getdata();

	}

	function init() {
		$("#data1").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");

		var my_ajax = new myajax;
		my_ajax.url = "local_class/chg_conten.php";
		my_ajax.data = "idx=2";
		my_ajax.success = function success(data) {
			$("#data1").html(data);
			init_tb();

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