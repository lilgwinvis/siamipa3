<?php 
     require_once 'shared.php';
     
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
	    
	    $_SESSION['pg_bfr']="../Admin/frm_sidang.php";
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Sidang</title>
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
	<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML"></script>
	<script type="text/javascript">
	
	function init_tb(namatb)
	{
		                         $("#"+namatb).dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#'+namatb+' tbody #mainrow');
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
											  										  
											  return  sem_txt(sVal);
											  
											},
											"aTargets": [ 0 ]
										}
									],
									"aaSortingFixed": [[ 0, 'asc' ]],
									//"aaSorting": [[ 1, 'asc' ]],
									"sDom": 'lfr<"giveHeight"t>ip',
									 "oLanguage": {
                                     "sSearch": "Search all columns:"
                                    }
								
								});
	}	

	function sem_txt(thn_sms){
	 var txt="";
     
	 if(thn_sms.substr(4,1)==1){
	     txt = "Semester Ganjil";
	 }else{
	     txt = "Semester Genap";
	 }
		
	txt = txt +" "+thn_sms.substr(0,4);
	 return txt;
	}
    function hapus(id){
		                        $("#data").html("<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>");
								$.ajax({
                                     type : "POST",
				                     url : "../global_code/entry_dt_sidang.php",
				                     cache: false,
				                     data : 'idx=3&id='+id,
									 success : function(data){					                            
												$("#data").html(data);
                                                init_tb("poll1");
							                    init_tb("poll2");
							                    $("#tabs").tabs(); 												
				                               }
                                  });
	}
	$(document).ready(function () {
		// Dialog
				            init_tb("poll1");
							init_tb("poll2");
							$("#tabs").tabs();
				$('#dialog').dialog({
					autoOpen: true,
					width: 930,
					open: function(){
							$('#pgload').html("");
							
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
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
		<div id="dialog" title="Sidang">
			<div id="data">
			<?php
			  $vwta = new vw_ta;
			  echo $vwta->view_sidang();
			?>
			</div>
		</div>
   
</body>

</html>
	 <?php }} ?>