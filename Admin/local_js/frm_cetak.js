

function init_tb(tbnm, tg) {

	var kls = new Array();
	kls['R'] = 'Reguler';
	kls['N'] = 'Non Reguler';

	vmydatatable = new mydatatable;
	vmydatatable.id = tbnm;
	vmydatatable.template = 0;
	vmydatatable.title = 0;
	vmydatatable.bPaginate = true;
	vmydatatable.bInfo = true;
	vmydatatable.bFilter = true;
	vmydatatable.aoColumnDefs = [{
		"fnRender" : function (oObj, sVal) {
			return kls[sVal];
		},
		"aTargets" : [tg]
	}
	];
	vmydatatable.settemplate();
	vmydatatable.rowselected();
	vmydatatable.footerfilter();
	return vmydatatable.create();

}

function ctk_excel(vdata) {

	var my_ajax = new myajax;
	my_ajax.url = "../global_class/ctk_excel.php";
	my_ajax.data = vdata;
	my_ajax.success = function success(data) {
		window.open(data, 'Download');
	};
	my_ajax.getdata();

}

function fnGetSelected(oTableLocal) {
	return oTableLocal.$('tr.row_selected');
}


function binding(oTable,idx)
{
	switch (idx) {
	case 1:{
			$("#BAP").click(function () {

				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=4';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});
			$("#CBAP").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=5';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});

			$("#Honor4").click(function () {
				data = 'idx=12';
				ctk_excel(data);
			});

			$("#Honor2").click(function () {
				data = 'idx=20';
				ctk_excel(data);
			});

			$("#DHMD").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=6';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});
			break;
		}
	case 2:{
			$("#Absen_UTS").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=7';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});
			$("#Absen_UAS").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=8';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});

			$("#DPNA").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=9';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});
			$("#BAU").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=10';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});
			$("#label").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "sem=" + anSelected.find("td:eq(0)").text();
					data = data + "&kls=" + anSelected.find("td:eq(1)").text();
					data = data + "&kdkmk=" + anSelected.find("td:eq(2)").text();
					data = data + "&nakmk=" + anSelected.find("td:eq(3)").text();
					data = data + "&kdds=" + anSelected.find("td:eq(4)").text();
					data = data + "&nads=" + anSelected.find("td:eq(5)").text();
					data = data + '&idx=11';
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Matakuliah !!!");
				}

			});

			$("#pakasi").click(function () {
				data = 'idx=13';
				ctk_excel(data);
			});
			break;
		}
	case 3:{
			$("#Kartu_UAS").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "nim=" + anSelected.find("td:eq(1)").text();
					data = data + "&idx=3";
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Mahasiswa !!!");
				}

			});
			$("#Kartu_UTS").click(function () {
				var anSelected = fnGetSelected(oTable);
				if (anSelected.length !== 0) {
					data = "nim=" + anSelected.find("td:eq(1)").text();
					data = data + "&idx=2";
					ctk_excel(data);
				} else {
					alert("Anda belum memilih Mahasiswa !!!");
				}

			});
		}
		break;
	}
}
