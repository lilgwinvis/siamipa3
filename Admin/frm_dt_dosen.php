<?php 

     require_once 'shared.php';

     
     $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $_SESSION['pg_bfr']="../Admin/frm_dt_dosen.php";
	 
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
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Data Dosen</title>
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
	<script type="text/javascript" src="local_js/frm_dt_dosen.js"></script>
	<script type="text/javascript">
    var oTable;
	init_table();
	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 700,
					resizable: true,
					autoHeight: true,
					open: function(){
							$("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
							open();
							
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						}
					}
				});
				
				$("#Add").click( function()
                {  
				   window.parent.buka_dlg("frm_dt_dosen_entry.php?idx=1");
				});
				
				$("#Edit").click( function()
                {  
				    var anSelected = fnGetSelected( oTable );
					if ( anSelected.length !== 0 ) {
					    $data="kdds="+anSelected.find("td:eq(0)").text();
						$data=$data+'&idx=2';						
						window.parent.buka_dlg("frm_dt_dosen_entry.php?"+$data);	
					}else{
				       alert("Anda belum memilih Data Dosen !!!");
					}
				});
				
				$("#Del").click( function()
                {  
				   window.parent.buka_dlg("frm_dt_dosen_entry.php?idx=3");
				});
				
				function fnGetSelected( oTableLocal )
					{
						return oTableLocal.$('tr.row_selected');
					}

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <!-- ui-dialog -->
		<div id="dialog" title="Data Dosen">
		  <fieldset>	
			<legend>Aksi</legend>
			<table>
			  <tr>
			    <td><button type='submit' id='Add' <?php echo ($hak==0 ? 'disabled':''); ?>>Add</button></td>
				<td><button type='submit' id='Edit' <?php echo ($hak==0 ? 'disabled':''); ?>>Edit</button></td>
				<td><button type='submit' id='Del' <?php echo ($hak==0 ? 'disabled':''); ?>>Delete</button></td>
			  </tr>	
			</table>
		   </fieldset>	
		  <fieldset>	
			<legend>List Dosen</legend>			
			<div id="data"> 
			  
			 </div> 
		   </fieldset>
		</div>
   
</body>

</html>
	 <?php }} ?>