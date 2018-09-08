<?php session_start(); 
     
     
     
     	 
     
	 $islog = $_SESSION['islog'];
	 $_SESSION['pg_bfr']="../dosen_app/frm_hutang.php";
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=3");
		 exit();
	 }
	 else
	 {	 require_once 'shared.php';
	     
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=3&isout=1");
		  exit();	
		}else{  
		 $kode = $_SESSION['user'];
	     
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Nilai Belum Masuk</title>
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
	<script type="text/javascript">

	var asInitVals = new Array();
    var oTable;
	
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

	function ctk_excel(idx,sem,kls,kdkmk,nakmk,kdds,thnsms)
	{
	
	                        $.ajax({
                                     type : "POST",
				                     url : "../global_class/ctk_excel.php",
				                     cache: false,
				                     data :"idx="+idx+"&sem="+sem+"&kls="+kls+"&kdkmk="+kdkmk+"&nakmk="+nakmk+"&kdds="+kdds+"&thnsms="+thnsms,
									 success : function(data){ 
												window.open(data,'Download'); 											
				                               }
                                  });
	
	}
	
	
	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){
							
							oTable=$("#tb_hutang").dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#tb_hutang tbody tr');
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
									"aaSorting": [[ 1, 'asc' ]],
									"sDom": 'lfr<"giveHeight"t>ip',
									 "oLanguage": {
                                     "sSearch": "Search all columns:"
                                    }
								});
						  },
					resize: function(){ 
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
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <!-- ui-dialog -->
        
		<div id="dialog" title="Nilai Belum Masuk">
			 
			<!--<div id="accordion">-->
			  <fieldset>
			  <div id="data"> 
				  <?php
				    $vwhutang=new vwhutang;
					echo $vwhutang->buildhutang($kode);
				  ?>
		      </div> 
		      </fieldset>
			<!--</div>-->
		</div>
   
</body>

</html>
	 <?php }} ?>