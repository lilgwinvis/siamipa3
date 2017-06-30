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
	     
		 
		 $vwkeuangk = new vwkeuangk;
		 $_SESSION['pg_bfr']="../Admin/frm_keu_angkatan.php";

		 $thn = isset($_GET['thn']) ? $_GET['thn']: 2008;
		 $kls = isset($_GET['kls']) ? $_GET['kls']: "R";
		 
		 

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kewajiban Perangkatan</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	
	<style type="text/css">
	        @import "../datatables/media/css/demo_page.css";
			@import "../datatables/media/css/demo_table.css";
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_keu_angkatan.js"></script>
	<script type="text/javascript">



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

	$("#filter").click(function () {
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		var tmp1 = $('#kls').find('option:selected').text();
		var tmp2 = tmp1.split("-");
		var tmp = thnmsmshs + tmp2[1];
		$("#hsl_filter").html("Daftar Kewajiban : " + tmp);
		$("#data").html("<fieldset><div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div></fieldset>");
		filter(thnmsmshs,kelas);

	});

	$("#Add").click(function () {
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		window.parent.buka_dlg("frm_keu_angkatan_entry.php?idx=1&thn=" + thnmsmshs + "&kls=" + kelas);
	});

	$("#Edit").click(function () {

		var anSelected = fnGetSelected(oTable);
		if (anSelected.length !== 0) {
			var thnmsmshs = $("#Angkatan").val();
			var kelas = $("#kls").val();
			$data = "kls=" + kelas;
			$data = $data + "&thn=" + thnmsmshs;
			$data = $data + "&kd=" + anSelected.find("td:eq(0)").text();
			$data = $data + '&idx=2';
			window.parent.buka_dlg("frm_keu_angkatan_entry.php?" + $data);
		} else {
			alert("Anda belum memilih Data !!!");
		}
	});

	$("#Del").click(function () {
		var thnmsmshs = $("#Angkatan").val();
		var kelas = $("#kls").val();
		window.parent.buka_dlg("frm_keu_angkatan_entry.php?idx=3&thn=" + thnmsmshs + "&kls=" + kelas);
	});
    
	    $("#Hit").click(function () {
			var thnmsmshs = $("#Angkatan").val();
		    var kelas = $("#kls").val();
			hitung(thnmsmshs,kelas);		
		});
	
	
	function fnGetSelected(oTableLocal) {
		return oTableLocal.$('tr.row_selected');
	}

});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Kewajiban Perangkatan">
		  <?php 
		     echo $vwkeuangk->filter_mhs($thn,$kls);
		   ?>
		</div>
   
</body>

</html>
	 <?php }} ?>