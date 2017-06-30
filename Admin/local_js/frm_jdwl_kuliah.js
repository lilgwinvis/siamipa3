function tb() {

	var hari = new Array();
	hari['1'] = 'Senin';
	hari['2'] = 'Selasa';
	hari['3'] = 'Rabu';
	hari['4'] = 'Kamis';
	hari['5'] = 'Jumat';
	hari['6'] = 'Sabtu';
	hari['7'] = 'Minggu';

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'box-table-a';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.bSort = true;
	vmydatatable.settemplate();
	vmydatatable.aoColumnDefs = [{
			"fnRender" : function (oObj, sVal) {
				return hari[sVal];
			},
			"aTargets" : [0]
		}
	];
	vmydatatable.footerfilter();
	vmydatatable.create();

}

function ctk_pdf() {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_pdf.php";
	my_ajax.data = 'idx=2';
	my_ajax.success = function success(data) {
		window.parent.buka_dlg("../global_code/frm_show_pdf.php?pdf_path=" + data);
	}
	my_ajax.getdata();

}

function ctk_excel() {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = 'idx=17';
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	}
	my_ajax.getdata();

}

function hit_jam() {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = 'idx=60';
	my_ajax.success = function success(data) {
		$("#data").html(data);
		tb();
	}
	my_ajax.getdata();

}