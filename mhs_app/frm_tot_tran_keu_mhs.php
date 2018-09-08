<?php 

     session_start();

     
    $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {
        require_once 'shared.php';
        
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{ 
		
		$vwtottrkeumhs = new vwtottrkeumhs;
		$nim = $_SESSION['user'];
	    

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
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
		    
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");								
							$('#lst_trans').dataTable();				
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						}
					}
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
		     echo $vwtottrkeumhs->tottrankeumhs($nim);
		   ?>
		</div>
   
</body>

</html>
	 <?php }} ?>