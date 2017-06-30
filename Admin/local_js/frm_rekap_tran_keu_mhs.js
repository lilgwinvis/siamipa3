function init_tb() {
	var vmydatatable = new mydatatable;
	vmydatatable.id = 'lst_rekap';
	vmydatatable.template = 1;
	vmydatatable.title = 2;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.settemplate();
	vmydatatable.create();
	
	var vmydatatable1 = new mydatatable;
	vmydatatable1.id = 'lst_rekap_kewajiban';
	vmydatatable1.template = 0;
	vmydatatable1.title = 0;
	vmydatatable1.bPaginate = true;
	vmydatatable1.bInfo = true;
	vmydatatable1.bFilter = true;
	vmydatatable1.aoColumnDefs = [{
			'bSortable' : false,
			'aTargets' : [0, 1]
		}
	];
	vmydatatable1.settemplate();
	vmydatatable1.create();
	
	lst_rekap_kewajiban
	
	var vmydatatable2 = new mydatatable;
	vmydatatable2.id = 'lst_rekap_thn';
	vmydatatable2.create();
	
	lst_rekap_thn
	var vmydatatable3 = new mydatatable;
	vmydatatable3.id = 'lst_summary';
	vmydatatable3.create();
	
	
	
	
	
}