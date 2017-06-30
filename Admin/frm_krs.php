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
		
		 $user = $_SESSION['user'];	     
		 
		 $dtuser = new dt_user;
         $hak = $dtuser->gethak($user); 	
		 
		 $_SESSION['pg_bfr_1']="../Admin/frm_krs.php"; 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Rencana Studi (KRS)</title>
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
	  #accordion .ui-accordion-header a {
        font-size: 9px;        
      }  
     </style>
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script> 
	<script type="text/javascript" src="../js/siamipa.js"></script>
	 <script type="text/javascript" src="local_js/frm_krs.js"></script>
	<script type="text/javascript">

	$(document).ready(function () {
		// Dialog
		$('#dialog').dialog({
			autoOpen : true,
			width : 700,
			autoHeight : true,
			resizable : true,
			open : function () {
				$('#pgload').html("");
				formatdata();
			},
			buttons : {
				"Ok" : function () {
					$('#dialog').dialog("close");
				}
			}
		});

		$("#Del").click(function () {
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			del();
		});
		$("#Mig").click(function () {
			$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
			mig();
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
	<div id="dialog" title="Kartu Rencana Studi &#40KRS&#41">	
	<fieldset>
	<legend>Alat Migrasi</legend>
	  <table>
			  <tr>
			    <td><button type='submit' id='Mig' <?php echo ($hak==0 ? 'disabled':''); ?> >KRS - (TRNLM,TRNLM_TRNLP)</button></td>
				<td><button type='submit' id='Del' <?php echo ($hak==0 ? 'disabled':''); ?> >DELETE KRS (TA-1)</button></td>							
			  </tr>	
			</table>
	</fieldset>
	 
	<div id="data">
	 <?php
	    $vw_krs=new vw_krs;
		echo $vw_krs->lst_mhs();
	 ?>
	 </div>
	 	 
	</div>	
   
</body>

</html>
	 <?php }} ?> 