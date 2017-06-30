<?php require_once 'shared.php';
     
     
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
	    
		$_SESSION['pg_bfr']="../Admin/frm_ajuan_keu.php";
	    
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Ajuan Keuangan</title>
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

	 var otable;
	 function init_tb(namatb)
	{
		                    otable= $("#"+namatb).dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#'+namatb+' tbody tr');
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
											  										  
											  return  sVal;
											  
											},
											"aTargets": [ 0 ]
										}
									],
									"aaSortingFixed": [[ 0, 'desc' ]],
									//"aaSorting": [[ 1, 'asc' ]],
									"sDom": 'lfr<"giveHeight"t>ip',
									 "oLanguage": {
                                     "sSearch": "Search all columns:"
                                    }
								
								});
	}	

	$(document).ready(function () {
		// Dialog
				                    $("#lst_ajuan tbody tr").click( function( e ) {
							            if ( $(this).hasClass('row_selected') ) {
								             $(this).removeClass('row_selected');
							           }
							           else {
								             otable.$('tr.row_selected').removeClass('row_selected');
								             $(this).addClass('row_selected');
							           }
				                    });
				
				
				$('#dialog').dialog({
					autoOpen: true,
					width: 850,
					open: function(){
							$('#pgload').html("");
							init_tb('lst_ajuan');
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						}
					}
				});
				
				$("#Add").click( function()
                {  
				   window.parent.buka_dlg("frm_dt_ajuankeu_entry.php?idx=1");
				});
				
				$("#Edit").click( function()
                {  
				    var anSelected = fnGetSelected( otable );
					if ( anSelected.length !== 0 ) {
					    $data="idajuan="+anSelected.find("td:eq(0)").text();
						$data=$data+'&idx=2';						
						window.parent.buka_dlg("frm_dt_ajuankeu_entry.php?"+$data);	
					}else{
				       alert("Anda belum memilih Data Ajuan !!!");
					}
				});
				
				$("#Del").click( function()
                {  
				   window.parent.buka_dlg("frm_dt_ajuankeu_entry.php?idx=3");
				});
				
				function fnGetSelected( oTableLocal )
					{
						return oTableLocal.$('tr.row_selected');
					}
				

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   <!-- ui-dialog -->
		<div id="dialog" title="Ajuan Keuangan">
			<?php 
		      $vwajuankeu = new vw_ajuankeu;
		      echo $vwajuankeu->view_ajuan(); 
		    ?> 
		</div>
   
</body>

</html>
	 <?php }} ?>