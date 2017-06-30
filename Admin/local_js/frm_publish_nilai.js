function init_tb(namatb) {

	var vmydatatable = new mydatatable;
	vmydatatable.id = namatb;
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();

}

function init() {
	init_tb('tbl1');
	init_tb('tbl2');
	init_tb('tbl3');
	
	var vmyaccordion = new myaccordion;
	vmyaccordion.id='accordion'; 
	vmyaccordion.create();
	
}