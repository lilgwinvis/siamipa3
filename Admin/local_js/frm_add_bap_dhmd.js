function init_tb()
{
	
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lstdhmd';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.bAutoWidth = false;
	vmydatatable.settemplate();
	
	vmydatatable.create();
	
}

