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
	     
		$vwtottrkeumhs = new vwtottrkeumhs;

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Total Transaksi Keuangan Mahasiswa</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
	<style type="text/css">
	 
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_tot_tran_keu_mhs.js"></script>
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
				init_tb();
			},
			buttons : {
				"Ok" : function () {
					$(this).dialog("close");
				},
				"Cetak" : function () {
					nim = $("#Mhs").val();
					vdata = nim + '&idx=16';
					$.ajax({
						type : "POST",
						url : "../global_class/ctk_excel.php",
						cache : false,
						data : vdata,
						success : function (data) {
							//alert(data);
							//window.open(data,'Download');
						}
					});
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
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			filter(nim);

		});

	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Total Transaksi Keuangan Mahasiswa">
		  <?php 
		     echo $vwtottrkeumhs->filter_mhs();
		   ?>
		</div>
   
</body>

</html>
	 <?php }} ?>