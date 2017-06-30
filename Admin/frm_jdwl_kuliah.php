<?php require_once 'shared.php';
     
	 
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $idx = $_GET['idx'];	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=".$idx);
		 exit();
	 }
	 else
	 {	
		
		
       $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=$idx&isout=1");
		  exit();	
		}else{ 
	    
		
		$_SESSION['pg_bfr']="../Admin/frm_jdwl_kuliah.php?idx=".$idx;     
          		
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Jadwal Kuliah</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
	<style type="text/css">
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
	</style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script> 
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_jdwl_kuliah.js"></script>
	<script type="text/javascript">
    	
	$(document).ready(function () {
		// Dialog
        <?php echo "var idx=$idx"; ?>		
		var setting = {
			autoOpen : true,
			autoWidth : true,
			autoHeight : true,
			minWidth : 950,
			open : function () {
				$('#pgload').html("");
				tb();
			},
			buttons : {}
		};

		setting.buttons = {
			"Cetak to PDF" : function () {
				ctk_pdf();
			},
			"Ok" : function () {
				$(this).dialog("close");
			}
		};

		if (idx == 1) {

			setting.buttons = {

				"Hitung Jam Akhir" : function () {
					$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
					hit_jam();
				},

				"Cetak to PDF" : function () {
					ctk_pdf();
				},

				"Cetak to Excel" : function () {
					ctk_excel();
				},
				"Ok" : function () {
					$(this).dialog("close");
				}
			};
		}

		$('#dialog').dialog(setting);

	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <!-- ui-dialog -->
		<div id="dialog" title="Jadwal Kuliah">			
			<?php
				$vwjdwlklh = new vwjdwlklh;
				echo $vwjdwlklh->build();
			?>			
		</div>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
</body>

</html>
	 <?php }} ?>