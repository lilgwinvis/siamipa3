<?php session_start(); 
     
    
     	 
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 
	 if($islog==0)
	 {
		  header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	     require_once 'shared.php';
			
			$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{ 
             $nim = $_SESSION['user'];
			 
               			 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Transkrip Nilai</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />-->
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

	var asInitVals = new Array();
    var oTable;
	
	function init_tb()
	{
	                             oTable=$('#tb_trans').dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#tb_trans tbody tr');
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
								$("tfoot input").keyup( function () {
										/* Filter on the column (the index) of this element */
										oTable.fnFilter( this.value, $("tfoot input").index(this) );
									} );
																		 
									/*
									 * Support functions to provide a little bit of 'user friendlyness' to the textboxes in
									 * the footer
									 */
									$("tfoot input").each( function (i) {
										asInitVals[i] = this.value;
									} );
									 
									$("tfoot input").focus( function () {
										if ( this.className == "search_init" )
										{
											this.className = "";
											this.value = "";
										}
									} );
									 
									$("tfoot input").blur( function (i) {
										if ( this.value == "" )
										{
											this.className = "search_init";
											this.value = asInitVals[$("tfoot input").index(this)];
										}
									} );
	
	}
	
	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 650,
					resizable: true,
					autoHeight : true,
					open: function(){
							$('#pgload').html("");
							init_tb();
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						},
						"Cetak": function() {
							<?php 
							   echo 'var nim = "'.$nim.'";';
							   if($nim == '')
							    {
								  $tmp="'../Admin/cetak/transkrip/Transkrip Nilai - ".$nim." ttd.pdf'";
								  
								  echo "alert($tmp);";
								  echo "window.open($tmp,'Download');";
								}
								else
								{
							?>
								$.ajax({
										 type : "POST",
										 url : "../global_class/ctk_pdf.php",
										 cache: false,
										 data :"nim="+nim+"&idx=3",
										 success : function(data){               
													alert(data);
													window.open(data,'Download'); 											
												   }
									  });
							<?PHP } ?>		  
						}
						}
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
		<div id="dialog" title="Transkrip Nilai">
	       	 <fieldset> 
			  <div id="data">
			     <?php
				    $vvwtrans = new vwtrans;
					echo $vvwtrans->buildtrans($nim);
				 ?>
		      </div>
			 </fieldset>
		</div>
   
</body>

</html>
	 <?php }} ?>