function init_tb()
{
	
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lstbapdhmd';
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	//vmydatatable.settemplate();
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [0]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [1]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "80%","aTargets" : [2]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [3]});
	vmydatatable.aoColumnDefs.push({"sWidth" : "5%","aTargets" : [4]});
	vmydatatable.create();
	
}

