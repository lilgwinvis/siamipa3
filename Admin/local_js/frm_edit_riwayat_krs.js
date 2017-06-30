function init_tb() {
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_krs';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();
}

function ctkxls(nim,thnsms)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = "idx=19&nim="+nim+"&thnsms="+thnsms;
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}

function ctkpdf(nim,thnsms)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_pdf.php";
	my_ajax.data = "idx=4&nim="+nim+"&thnsms="+thnsms;
	my_ajax.success = function success(data) {		
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}