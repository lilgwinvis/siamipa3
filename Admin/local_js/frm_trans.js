function init_tb() {
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'tb_trans';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();

}

function update_kelas(thnmsmshs) {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/ambilkelas.php";
	my_ajax.data = "thnmsmshs=" + thnmsmshs;
	my_ajax.success = function success(data) {
		$("#kls").html(data);
		var kelas = $("#kls").val();
		update_cmb_mhs(thnmsmshs, kelas);
	}
	my_ajax.getdata();
}

function update_cmb_mhs(thnmsmshs, kelas) {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/ambilnm.php";
	my_ajax.data = "thnmsmshs=" + thnmsmshs + "&kelas=" + kelas;
	my_ajax.success = function success(data) {
		$("#Mhs").html(data);
	}
	my_ajax.getdata();
}

function filter(nim) {
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "nim=" + nim + "&idx=3";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	}
	my_ajax.getdata();
}

function ctkxls(nim)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = "nim="+nim+"&idx=1";
	my_ajax.success = function success(data) {
		alert(data);
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}

function ctkpdf(nim)
{
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_pdf.php";
	my_ajax.data = "nim="+nim+"&idx=3";
	my_ajax.success = function success(data) {
		alert(data);
		window.open(data, 'Download');
	}
	my_ajax.getdata();
}

