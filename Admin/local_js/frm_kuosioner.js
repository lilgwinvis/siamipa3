function init_tb(namatb) {
	vmydatatable = new mydatatable;
	vmydatatable.id = namatb;
	vmydatatable.template = 1;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();
}