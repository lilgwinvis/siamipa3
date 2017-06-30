<?php require_once 'shared.php';

    
     $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {
       
      
	    $login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{ 
		
	   $vwtrkeumhs = new vwtrkeumhs;  
       
	   $nim = $_SESSION['user'];
	   
	   	   
	  
	   
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Transaksi Keuangan Mahasiswa</title>
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
	<script type="text/javascript">

	<?php echo "var nim='$nim'"; ?>

	$(document).ready(function () {
		// Dialog
		        var oTable;
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");								
												
							oTable=$('#lst_trans').dataTable({
      "aoColumnDefs": [
          { 'bSortable': false, 'aTargets': [ 1 ] },
		  { 'bVisible': false, 'aTargets': [ 0 ] }
       ]
});		
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						},
						"Cetak": function() {
							data="nim="+nim;
				            data=data+'&idx=15';	
                            $.ajax({
                                     type : "POST",
				                     url : "../global_class/ctk_excel.php",
				                     cache: false,
				                     data :data,
									 success : function(data){               
												//alert(data);
												//window.open(data,'Download'); 											
				                               }
                                  }); 
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
		<div id="dialog" title="Transaksi Keuangan Mahasiswa">
		   <?php 
		     echo $vwtrkeumhs->trankeumhs($nim);
		   ?>
		   
		</div>
   
</body>

</html>
	 <?php }} ?>