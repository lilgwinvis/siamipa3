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
		 
		 $vmythnsem = new mythnsem;
		 
		 
		 $_SESSION['pg_bfr_1']="../Admin/frm_ksd_ngajar.php";
         		 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kesediaan Mengajar</title>
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
	<script type="text/javascript" src="local_js/frm_ksd_ngajar.js"></script>
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
			autoHeight : true,
			resizable : false,
			open : function () {
				init();
			},
			buttons : {
				"Ok" : function () {
					$(this).dialog("close");
				}
			}
		});

		$("#Del").click(function () {
			del();
		});
		$("#Mig").click(function () {
			mig();
		});

	});
	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Kesediaan Mengajar">
		  <fieldset>
		      <table>
			  <tr>
			    <td><button type='submit' id='Mig' <?php echo ($hak==0 ? 'disabled':''); ?> >Arsipkan <?php echo $vmythnsem->gettxtthnsem(); ?></button></td>
				<td><button type='submit' id='Del' <?php echo ($hak==0 ? 'disabled':''); ?> >Delete <?php echo $vmythnsem->gettxtthnsem(); ?></button></td>							
			  </tr>	
			</table>
		  </fieldset>
		  <fieldset>
		   <legend><?php echo  $vmythnsem->gettxtthnsem();  ?></legend>
			<div id="data">			
            </div>
		 </fieldset>			
		</div>
   
</body>

</html>
	 <?php }} ?>