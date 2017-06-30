function init_tb() {

	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lstmtkdsn';
	vmydatatable.template = 1;
	vmydatatable.title = 1;	
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [0]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [1]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "45%","aTargets" : [2]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "10%","aTargets" : [3]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "10%","aTargets" : [4]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [5]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [6]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [7]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [8]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [9]});
	vmydatatable.footerfilter();
	vmydatatable.create();

}

function filter(thn) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/chg_conten.php";
	my_ajax.data = "thn=" + thn + "&idx=64";
	my_ajax.success = function success(data) {
		$("#data").html(data);
		init_tb();
	}
	my_ajax.getdata();

}