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
	   
		$_SESSION['pg_bfr_1']="../Admin/frm_riwayat_krs.php";		
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Riwayat Kartu Rencana Studi (KRS)</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	
	<style type="text/css">
	        @import "../datatables/media/css/demo_page.css";
			@import "../datatables/media/css/demo_table.css";
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
	#accordion .ui-accordion-header a {
        font-size: 9px;        
      }  
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_riwayat_krs.js"></script>
	<script type="text/javascript">


	$(document).ready(function () {
		// Dialog
		                 $.ajaxSetup({
				              type : 'POST',
							  headers : {"cache-control" :"no-cache"}
				            });
				 
				$('#dialog').dialog({
					autoOpen: true,
					width: 700,
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");
                            init();
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
					$("#hsl_filter").html("Riwayat Kartu Rencana Studi (KRS) : "+tmp);					
		            $("#data").html("<fieldset><div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div></fieldset>");
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
		<div id="dialog" title="Riwayat Kartu Rencana Studi &#40KRS&#41">
		  <?php 
		   $vwriwayatkrs = new vw_riwayat_krs;
		   echo $vwriwayatkrs->sem_filter(); 
		  ?> 
		</div>
   
</body>

</html>
	 <?php }} ?>