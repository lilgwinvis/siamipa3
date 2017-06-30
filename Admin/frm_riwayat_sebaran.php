<?php 
     require_once 'shared.php';

     
	 $idx = $_GET['idx'];
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 $_SESSION['pg_bfr']="../Admin/frm_riwayat_sebaran.php?idx=".$idx; 
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=$idx");
		 exit();
	 }
	 else
	 {
       $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=$idx&isout=1");
		  exit();	
		}else{ 
	    
        
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Riwayat Sebaran Matakuliah</title>
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
	<script type="text/javascript" src="local_js/frm_riwayat_sebaran.js"></script>
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
			width : 900,
			resizable : true,
			autoHeight : true,
			open : function () {
				$('#pgload').html("");
				init_tb();
			},
			buttons : {
				"Ok" : function () {
					$(this).dialog("close");
				}
			}
		});
		$("#filter").click(function () {
			var thn = $("#semester").val();
			var tmp = $('#semester').find('option:selected').text();
			$("#hsl_filter").html("Sebaran Matakuliah : " + tmp);
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			filter(thn);
		});

	});
	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Riwayat Sebaran Matakuliah">
		  
		  <?php 
		   $vwsebaran = new vwsebaran;
		   echo $vwsebaran->sem_filter(); 
		  ?> 
		  
        
		</div>
   
</body>

</html>
	 <?php }} ?>