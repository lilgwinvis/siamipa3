<?php  require_once 'shared.php'; 
         
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
	    
		$_SESSION['pg_bfr']="../Admin/frm_hutang.php"; 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Nilai Belum Masuk</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
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
	<script type="text/javascript" src="local_js/frm_hutang.js"></script>
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
    		width : 720,
    		autoHeight : true,
    		resizable : true,
    		open : function () {
    			init();
    		},
    		resize : function () {},
    		buttons : {
    			"Ok" : function () {
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
   
   <!-- ui-dialog -->
        
		<div id="dialog" title="Nilai Belum Masuk">
		     <div id="data1">			  
			 </div> 		        
		</div>
   
</body>

</html>
	 <?php }} ?>