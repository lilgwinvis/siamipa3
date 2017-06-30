function init_tb(namatb) {
	var vmydatatable = new mydatatable;
	vmydatatable.id = namatb;
	vmydatatable.template = 1;
	vmydatatable.title = 2;
	vmydatatable.settemplate();
	vmydatatable.create();
}
function formatdata() {
	init_tb("tb_krs");
	init_tb("tb_krs1");
	init_tb("tb_krs2");
	init_tb("tb_krs3");
	var vmyaccordion = new myaccordion; 
	vmyaccordion.id = 'accordion';
	vmyaccordion.create();
}

function del() {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/mankrs.php";
	my_ajax.data = "idx=2";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		formatdata();
	}
	my_ajax.getdata();
}

function mig() {
	var my_ajax = new myajax;
	my_ajax.url = "local_class/mankrs.php";
	my_ajax.data = "idx=1";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		formatdata();
	}
	my_ajax.getdata();
}