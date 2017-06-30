function ctkxls(nim)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = "nim="+nim+"&idx=16";
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}

function ctkpdf(nim)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_pdf.php";
	my_ajax.data = "nim="+nim+"&idx=1";
	my_ajax.success = function success(data) {		
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}

function init_tb() {
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_krs';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();
}