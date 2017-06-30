<?php require_once 'shared.php';     	 
     
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
	     
		 $_SESSION['pg_bfr_1']="../Admin/frm_konversi.php"; 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Nilai Konversi</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	 <!--<link type="text/css" href="../css/style.css" rel="stylesheet" />
	 <link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />-->
	<style type="text/css">
	        @import "../datatables/media/css/demo_page.css";
			@import "../datatables/media/css/demo_table.css";
			div.giveHeight {
				/* Stop the controls at the bottom bouncing around */
				//min-height: 380px;
			}
      .ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script> 
	<script type="text/javascript" src="../js/siamipa.js"></script>
	 <script type = "text/javascript">

		$(document).ready(function () {
			// Dialog
			$('#dialog').dialog({
				autoOpen : true,
				width : 450,
				autoHeight : true,
				resizable : true,
				open : function () {
					$('#pgload').html("");
					var vmydatatable = new mydatatable;
					vmydatatable.id = 'lst_mhs';
					vmydatatable.template = 1;
					vmydatatable.title = 2;
					vmydatatable.settemplate();
					vmydatatable.create();
				},
				buttons : {
					"Ok" : function () {
						$('#dialog').dialog("close");
					}
				}
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
	<div id="dialog" title="Nilai Konversi">	
	<fieldset> 
	<div>
	 <?php
	    $vwtrnlp=new vw_trnlp;
		echo $vwtrnlp->lst_mhs();
	 ?>
	 </div>
	 </fieldset>
	
	
	</div>	
   
</body>

</html>
<?php }} ?> 