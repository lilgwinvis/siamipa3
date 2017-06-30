<?php require_once 'shared.php';
     
        
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	  
	      $kode =$_GET['kdds'];
	      $thn =$_GET['thn'];
		  
		  $ksd_ngajar = new vw_ksd_ngajar;
		  $dtksd_ngajar = new dt_ksd_ngajar;
		  $data = $dtksd_ngajar->getDataRiwayatMtk($kode,$thn);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Riwayat Kesediaan Mengajar : Hapus Riwayat Kesediaan</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
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
	<script type="text/javascript" src="local_js/frm_riwayat_ksd_mtk_hapus.js"></script>	
	<script type="text/javascript">
    var oTable;
	$(document).ready(function () {
	   $('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
					    oTable= init_tb();
						  },
					buttons: {
					  <?php
					   if(!empty($data)){	
					  ?> 	
						"Save": function() {
							$('#dialog').dialog("close");
                           save(oTable,<?php echo '"'.$pg_bfr.'"' ?>);							
						},
					 <?php 
					   }	
					  ?>
						"Cancel": function() {
							$('#dialog').dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
						}
					}
					});
	});

	</script>
</head>

<body>
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>	
   <!-- ui-dialog -->
	<div id="dialog" title="Riwayat Kesediaan Mengajar : Hapus Riwayat Kesediaan ">	
	   <?php echo $ksd_ngajar->edt_riwayat_jadwal($kode,0,$thn) ?>
	</div>	 
</body>

</html>	
<?php } ?>