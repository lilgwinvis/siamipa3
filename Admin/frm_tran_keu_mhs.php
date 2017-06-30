<?php 
	require_once 'shared.php';     
	
	$islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	
	
	if($islog==0)
	{
		header("Location: ../global_code/frm_login.php?idx=1");
		exit();
	}
	else
	{
		
		
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=1&isout=1");
		  exit();	
		}else{ 
		
		
		$vwtrkeumhs = new vwtrkeumhs;  
		$_SESSION['pg_bfr']="../Admin/frm_tran_keu_mhs.php";        
		
		$thn = isset($_GET['thn']) ? $_GET['thn']: 2008;
		$kls = isset($_GET['kls']) ? $_GET['kls']: "R";
		$nim = isset($_GET['nim']) ? $_GET['nim']: "F1A080001";
           
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta name="generator" content="HTML Tidy for HTML5 (experimental) for Windows https://github.com/w3c/tidy-html5/tree/c63cc39" />

  <title>Transaksi Keuangan Mahasiswa</title>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
  <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
  <style type="text/css">
/*<![CDATA[*/
                @import "../datatables/media/css/demo_page.css";
                        @import "../datatables/media/css/demo_table.css";
        .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
  /*]]>*/
  </style>
  <script type="text/javascript" src="../js/jquery-1.8.0.min.js">
</script>
  <script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js">
</script>
  <script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js">
</script>
  <script type="text/javascript" src="../js/siamipa.js">
</script>
  <script type="text/javascript" src="local_js/frm_tran_keu_mhs.js">
</script>
  <script type="text/javascript">
//<![CDATA[



$(document).ready(function () {
	// Dialog
	$.ajaxSetup({
		type : 'POST',
		headers : {
			"cache-control" : "no-cache"
		}
	});

	
	$('#dialog').dialog({
		autoOpen : true,
		width : 600,
		resizable : true,
		autoHeight : true,
		open : function () {
			$('#pgload').html("");
			oTable = init_tb();
		},
		buttons : {
			"Ok" : function () {
				$(this).dialog("close");
			}
		}
	});

	$("#Angkatan").change(function () {
		var thnmsmshs = $("#Angkatan").val();
		cmbangk_change(thnmsmshs);

	});

	$("#kls").change(function () {
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		cmbkelas_change(thnmsmshs, kelas);

	});

	$("#filter").click(function () {
		var nim = $("#Mhs").val();		
		var tmp = $('#Mhs').find('option:selected').text();
		$("#hsl_filter").html("Daftar Transaksi Keuangan : " + tmp);
		$("#data").html("<fieldset><div id='pgload'><font size='1' color='red'>Mengontak Server ....<\/font> <img src='../img/ajax-loader.gif' /><\/div><\/fieldset>");
		filter(nim);
	});

	$("#Add").click(function () {
		var nim = $("#Mhs").val();
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		window.parent.buka_dlg("frm_trans_keu_mhs_entry.php?idx=1&nim=" + nim + "&thn=" + thnmsmshs + "&kls=" + kelas);
	});

	$("#Edit").click(function () {
		var anSelected = fnGetSelected(oTable);
		if (anSelected.length !== 0) {
			var nim = $("#Mhs").val();
			var thnmsmshs = $("#Angkatan").val();
			var kelas = $("#kls").val();
			$data = "nim=" + nim;
			$data = $data + "&thn=" + thnmsmshs;
			$data = $data + "&kls=" + kelas;
			$data = $data + "&id=" + anSelected.find("td:eq(0)").text();
			$data = $data + "&tgl=" + anSelected.find("td:eq(1)").text();
			$data = $data + "&kd=" + anSelected.find("td:eq(2)").text();
			$data = $data + '&idx=2';
			window.parent.buka_dlg("frm_trans_keu_mhs_entry.php?" + $data);
		} else {
			alert("Anda belum memilih Data !!!");
		}
	});

	$("#Del").click(function () {
		var nim = $("#Mhs").val();
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		window.parent.buka_dlg("frm_trans_keu_mhs_entry.php?idx=3&nim=" + nim + "&thn=" + thnmsmshs + "&kls=" + kelas);
	});

	$("#Cetak").click(function () {
		ctk_excel();
		//window.parent.buka_dlg("frm_trans_keu_mhs_entry.php?idx=3&nim="+nim+"&thn="+thnmsmshs+"&kls="+kelas);
	});

	$("#Trans").click(function () {
		var nim = $("#Mhs").val();		
		hitung(nim);
	});

	function fnGetSelected(oTableLocal) {
		return oTableLocal.$('tr.row_selected');
	}

});

  //]]>
  </script>
  <style type="text/css">
</style>
</head>

<body>
  <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
  <!-- ui-dialog -->

  <div id="dialog" title="Transaksi Keuangan Mahasiswa">
	<?php 
	echo $vwtrkeumhs->filter_mhs($thn,$kls,$nim);
	?>
  </div>
</body>
</html>
	<?php }} ?>