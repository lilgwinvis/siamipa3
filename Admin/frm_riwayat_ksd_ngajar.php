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
	 
	 $_SESSION['pg_bfr_1']="../Admin/frm_riwayat_ksd_ngajar.php";
     
	 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Riwayat Kesediaan Mengajar</title>
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
	<script type="text/javascript" src="local_js/frm_riwayat_ksd_ngajar.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
		                    $.ajaxSetup({
				              type : 'POST',
							  headers : {"cache-control" :"no-cache"}
				            });
				
		    var oTable;
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");								
							init_tb();		
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						}
					}
				});
				
				$("#filter").click( function()
                  {
                    var thn = $("#semester").val();
					var tmp = $('#semester').find('option:selected').text();
					$("#hsl_filter").html('Kesediaan Mengajar : '+tmp);
					$("#data1").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
		            filter(thn);
				  });
				

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Riwayat Kesediaan Mengajar">
		   <fieldset>
	       <legend>Filter</legend>
		  <?php 
		   $vwksdngajar = new vw_ksd_ngajar;
		   echo $vwksdngajar->sem_filter(); 
		  ?> 
		  </fieldset>
         <fieldset>
         <legend> <div id="hsl_filter">Kesediaan Mengajar : Semester Ganjil 2008</div></legend>
         <div id="data1">		 
		  <?php
		    echo $vwksdngajar->lst_riwayat_dsn(20081);		   
		   ?>
		 </div>  
		 </fieldset>  
		</div>
   
</body>

</html>
	 <?php }} ?>