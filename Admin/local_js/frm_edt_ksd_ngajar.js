function init_tb() {

	vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_mtk';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();

}