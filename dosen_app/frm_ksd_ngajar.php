<?php require_once 'shared.php';
$islog = $_SESSION['islog']; 

if($islog==0)
{
	header("Location: ../global_code/frm_login.php?idx=3");
	exit();
}
else
{  
	
	$login = new login;
	if($login->logintime()){		  
		header("Location: ../global_code/frm_login.php?idx=3&isout=1");
		exit();	
	}else{   
		$kode = $_SESSION['user'];
		
		$ksd_mtk = new vw_ksd_ngajar;
		$_SESSION['pg_bfr']="../dosen_app/frm_ksd_ngajar.php";
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
	
	<script type="text/javascript">
	  $(document).ready(function () {
	     $('#dialog').dialog({
					autoOpen: true,
					width: 950,
					autoHeight:true, 
					resizable: false,
					open: function(){
							$('#pgload').html("");
							$("#lst_mtk").dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#lst_mtk tbody tr');
										var iColspan = nTrs[0].getElementsByTagName('td').length;
										var sLastGroup = "";
										for ( var i=0 ; i<nTrs.length ; i++ )
										{
											var iDisplayIndex = oSettings._iDisplayStart + i;
											var sGroup = oSettings.aoData[ oSettings.aiDisplay[iDisplayIndex] ]._aData[0];
											if ( sGroup != sLastGroup )
											{
												var nGroup = document.createElement( 'tr' );
												var nCell = document.createElement( 'td' );
												nCell.colSpan = iColspan;
												nCell.className = "group";
												nCell.innerHTML = sGroup;
												nGroup.appendChild( nCell );
												nTrs[i].parentNode.insertBefore( nGroup, nTrs[i] );
												sLastGroup = sGroup;
											}
										}
									},
									"aoColumnDefs": [
										{ "bVisible": false, "aTargets": [ 0 ] },
										{
											"fnRender": function ( oObj, sVal ) {
												return  'Semester '+sVal;
											},
											"aTargets": [ 0 ]
										}
									],
									"aaSortingFixed": [[ 0, 'asc' ]],
									"aaSorting": [[ 1, 'asc' ]],
									"sDom": 'lfr<"giveHeight"t>ip',
									 "oLanguage": {
                                     "sSearch": "Search all columns:"
                                    }
								});
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						},
						"Cancel": function() {
							$(this).dialog("close");
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
	  
	  });
	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Kesediaan Mengajar">
		<?php echo $ksd_mtk->lst_mtk($kode) ?>
		</div>   
</body>
</html>
<?php
	 }}
?>