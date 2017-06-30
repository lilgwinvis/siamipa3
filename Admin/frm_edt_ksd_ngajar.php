<?php require_once 'shared.php'; 
  $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	      
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {   
	     $kode = $_GET['kdds'];
	    
		 $pg_bfr_1 = $_SESSION['pg_bfr_1'];
		 $ksd_mtk = new vw_ksd_ngajar;
		 $_SESSION['pg_bfr']="../Admin/frm_edt_ksd_ngajar.php?kdds=".$kode;
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Kesediaan Mengajar</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
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
	<script type="text/javascript" src="local_js/frm_edt_ksd_ngajar.js"></script>
	<script type="text/javascript">
	  $(document).ready(function () {
	     $('#dialog').dialog({
					autoOpen: true,
					width: 950,
					autoHeight:true, 
					resizable: false,
					open: function(){
							$('#pgload').html("");
							init_tb();
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr_1.'"' ?>);
						}
					}
				});
				
				     $("#baru").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_ksd_mtk_baru.php?kdds=".$kode."'" ?>);			 
					 });
					 
					 $("#lama").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_ksd_mtk_ulang.php?kdds=".$kode."'" ?>);				 
					 });
					 
					 $("#edit").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_ksd_mtk_edt.php?kdds=".$kode."'" ?>);			 
					 });
					 
					 $("#hapus").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_ksd_mtk_hapus.php?kdds=".$kode."'" ?>);		 
					 });
					  $("#acc").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_ksd_mtk_acc.php?kdds=".$kode."'" ?>);		 
					 });
	  
	  });
	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Kesediaan Mengajar">
		<?php echo $ksd_mtk->lst_mtk($kode,1) ?>
		</div>   
</body>
</html>
<?php
      }
?>