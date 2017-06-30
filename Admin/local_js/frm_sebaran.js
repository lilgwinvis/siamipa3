function init_tb()
{
	
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'box-table-a';
	vmydatatable.template = 1;
	vmydatatable.title = 1;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.footerfilter();
	vmydatatable.create();
	
}