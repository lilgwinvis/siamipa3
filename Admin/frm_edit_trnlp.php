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
	     $lht_trnlp = new vw_trnlp;
		 $_SESSION['pg_bfr']="../Admin/frm_edit_trnlp.php?nim=".$nim;
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Nilai Konversi</title>
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
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
							$('#pgload').html("");
							var vmydatatable = new mydatatable;
							vmydatatable.id = 'lst_konversi';
							vmydatatable.template = 1;
							vmydatatable.title = 1;
							vmydatatable.settemplate();
							vmydatatable.create();							
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
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_trnlp_mtk_baru.php?nim=".$nim."'" ?>);			 
					 });					 
					
					 
					 $("#edit").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_trnlp_mtk_edt.php?nim=".$nim."'" ?>);			 
					 });
					 
					 $("#hapus").click( function()
                     {
				     	window.parent.buka_dlg(<?php echo "'"."../global_code/frm_trnlp_mtk_hapus.php?nim=".$nim."'" ?>);		 
					 });
					 $("#export").click( function()
                     {
				     	          $.ajax({
                                     type : "POST",
				                     url : "../global_code/extrnlp_trnlm.php",
				                     cache: false,
				                     //data : $("#inputkrs").serialize(),
									 data : "nim="+"<?php echo $nim ?>"+"&idx=1",
									 success : function(data){
					                            alert(data);															
				                               }
                                  });		 
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
	<div id="dialog" title="Nilai Konversi">	
	   <?php echo $lht_trnlp->lht_trnlp($nim) ?>
	</div>	
   
</body>

</html>
<?php } ?> 