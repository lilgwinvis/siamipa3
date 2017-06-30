<?php 
     require_once 'shared.php'; 
     
        
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
		  $thnsms = $_GET['thnsms'];
		  
		  $vdt_mhs = new dt_mhs;
		  $sem=array(1=>'Ganjil',2=>'Genap');
		  $tmp = str_split($thnsms, 4);		 
		  $tmp_txt = 'Semester '.$sem[$tmp[1]].' '.$tmp[0].' - '.$vdt_mhs->getnmmhs($nim).' ('.$nim.')';
		  
		  $lht_krs = new vw_riwayat_krs;
		  $vbuild_trnlm = new dt_trnlm;
          $data = $vbuild_trnlm->getData("nimhstrnlm='$nim' and thsmstrnlm=$thnsms");
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
	<script type="text/javascript" src="local_js/frm_riwayat_krs_mtk_hapus.js"></script>	
	<script type="text/javascript">
    var oTable;
	$(document).ready(function () {
	   $('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
					   var vmydatatable = new mydatatable;
					   vmydatatable.id = 'lst_krs';
					   vmydatatable.template = 1;
					   vmydatatable.title = 1;
					   vmydatatable.settemplate();
					   vmydatatable.footerfilter();
					   oTable = vmydatatable.create();
						  },
					buttons: {
					  <?php
					   if(!empty($data)){	
					  ?> 	
						"Save": function() {
						  <?php
							 echo "var thnsms=".$thnsms.";";
							?>
							$('#dialog').dialog("close");
                            save(oTable,<?php echo '"'.$pg_bfr.'"' ?>,thnsms);												
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
	<div id="dialog" title="Riwayat Kartu Rencana Studi &#40KRS&#41 - <?php echo $tmp_txt ?> : Hapus Matakuliah ">	
	   <?php echo $lht_krs->olah_krs($nim,$thnsms,1) ?>
	</div>	 
</body>

</html>	
<?php } ?>