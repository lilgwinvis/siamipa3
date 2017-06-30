<?php require_once 'shared.php';
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 $pg_bfr = $_SESSION['pg_bfr_1'];
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {	 
	     
	     $nim = $_GET['nim'];
	     $lht_krs = new vw_krs;
		 $_SESSION['pg_bfr']="../Admin/frm_edit_krs.php?nim=".$nim;
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kartu Rencana Studi (KRS)</title>
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
	<script type="text/javascript" src="local_js/frm_edit_krs.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
							$('#pgload').html("");
							init_tb();												
						  },
					buttons: {
						"Ok": function() {
							$('#dialog').dialog("close");
                            window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);    							
						}
						
					}
					});
					
					$("#ambil").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_krs_mtk_baru.php?nim=".$nim."'" ?>);			 
					 });
					 
					 $("#ulang").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_krs_mtk_ulang.php?nim=".$nim."'" ?>);				 
					 });
					 
					 $("#edit").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_krs_mtk_edt.php?nim=".$nim."'" ?>);			 
					 });
					 
					 $("#hapus").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_krs_mtk_hapus.php?nim=".$nim."'" ?>);		 
					 });
					 
					 $("#ctkexcel").click(function () {
					 	ctkxls( <?php echo "'$nim'"?> );
					 });
                     
                     $("#ctkpdf").click( function()
                     {
                 		 ctkpdf(<?php echo "'$nim'"?>);
                     });   					 

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
     <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
	<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>  
   <!-- ui-dialog -->
	<div id="dialog" title="Kartu Rencana Studi &#40KRS&#41">	
	   <?php echo $lht_krs->lht_krs($nim) ?>
	</div>	
   
</body>

</html>
<?php } ?> 