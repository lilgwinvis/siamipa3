
function init_tb(namatb) {
	var vmydatatable = new mydatatable;
	vmydatatable.id = namatb;
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	oTable = vmydatatable.create();
}

function init() {
	init_tb('lst_riwayatkrs');
	init_tb('lst_riwayatkrs1');
	init_tb('lst_riwayatkrs2');
	init_tb('lst_riwayatkrs3');
	var vmyaccordion = new myaccordion;
	vmyaccordion.id='accordion';
	vmyaccordion.create();
}
function filter(thn){
	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn="+thn+"&idx=22";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init();
	}
	my_ajax.getdata();
}