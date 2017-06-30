<?php require_once 'shared.php'; 
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	 
	     
	    
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{  
		
		 $nim = $_SESSION['user'];
	     
		 $lht_krs = new vw_krs;		 
		 $_SESSION['pg_bfr']="../mhs_app/frm_krs.php";
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
	<script type="text/javascript">

	function init_tb1()
	{
		$("#lst_kuosioner").dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#lst_kuosioner tbody tr');
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
		
		
	}	
	
	function sem_txt(thn_sms){
	 var txt="";
     
	 if(thn_sms!="00000"){
	 if(thn_sms.substr(4,1)==1){
	     txt = "Semester Ganjil";
	 }else{
	     txt = "Semester Genap";
	 }
		
	txt = txt +" "+thn_sms.substr(0,4);
	}else{txt = "Nilai Konversi"}
	 return txt;
	}

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 650,
					open: function(){
							$('#pgload').html("");
							$("#lst_krs").dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#lst_krs tbody tr');
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
												return  "Semester "+sVal;
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
							init_tb1();	
						  },
					buttons: {
						"Ok": function() {
							$('#dialog').dialog("close");							
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
					 
					 $("#ctkpdf").click( function()
                     {
                         vdata="idx=1&nim="+<?php echo "'$nim'"?>;
                 				 $.ajax({
                                     type : "POST",
				                     url : "../global_class/ctk_pdf.php",
				                     cache: false,
				                     data :vdata,
									 success : function(data){ 
												window.parent.buka_dlg( "../global_code/frm_show_pdf.php?pdf_path="+data);												
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
	<div id="dialog" title="Kartu Rencana Studi &#40KRS&#41">	
	   <?php echo $lht_krs->lht_krs($nim,0) ?>
	  
	</div>	
   
</body>

</html>
	 <?php }} ?> 