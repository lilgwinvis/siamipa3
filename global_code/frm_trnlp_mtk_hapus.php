<?php require_once 'shared.php'; 
     
        
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	  
	      $user = $_SESSION['user'];
	      
		  $nim = $_GET['nim'];
		  $lht_trnlp = new vw_trnlp;
		  $vbuild_trnlp = new dt_trnlp;
          $data = $vbuild_trnlp->getData("nimhstrnlp='$nim'");
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Rencana Studi (KRS): Hapus Matakuliah</title>
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
    <script type="text/javascript" src="../Admin/local_js/frm_trnlp_mtk_hapus.js"></script>	
	<script type="text/javascript">
    var oTable;
	$(document).ready(function () {
	   $('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
						    var vmydatatable = new mydatatable;
							vmydatatable.id = 'lst_mtk';
							vmydatatable.template = 1;
							vmydatatable.title = 1;
							vmydatatable.settemplate();
						    oTable=vmydatatable.create();					    
						  },
					buttons: {
					  <?php
					   if(!empty($data)){	
					  ?> 	
						"Save": function() {
							$('#dialog').dialog("close");
                           entry_data(<?php echo '"'.$pg_bfr.'"' ?>);					
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
	<div id="dialog" title="Kartu Rencana Studi &#40KRS&#41 : Hapus Matakuliah ">	
	   <?php echo $lht_trnlp->build_trnlp($nim,3) ?>
	</div>	 
</body>

</html>	
<?php } ?>