<?php session_start(); 
     
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	
	     require_once 'shared.php';
	    
		$login = new login;
		if($login->logintime()){		  
		  header("Location: ../global_code/frm_login.php?idx=2&isout=1");
		  exit();	
		}else{ 

		 $vsummary = new vw_summary;
		 $nim = $_SESSION['user'];
	     
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Summary</title>
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

	function init_tb(namatb,bgroup,idx)
	{
	                            
		if(bgroup==1)
        {	
								$("#"+namatb).dataTable({
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
											  switch(idx)
                                              {											  
											  case 0 :return  sem_txt(sVal);break;
											  case 1 :return  "Semester "+sVal;break;
											  }	
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
								
	    }else{
		
		                       $("#"+namatb).dataTable({
									"bFilter": false,
									"bSort": false,
									"bPaginate": false,
									"bInfo": false
								});
		
		}							
	
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

	$(document).ready(function () {
		// Dialog
				
				
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,					
					autoHeight:true, 
					resizable: true,
					open: function(){
							
							$("#tabs").tabs();
							$('#pgload').html("");							
							    $('#pgload').html("");
								init_tb("tb_sks_sem",0,1);							
								init_tb("jml_sks",0,0);
								init_tb("hit_ipk",0,0);
								init_tb("rstat",0,0);
								init_tb("mstud",0,0);
								init_tb("poskeu",0,0);
							
								init_tb("blm_amb",1,1);
								init_tb("cobaE",1,0);
								init_tb("cobaD",1,0);
								init_tb("cobaT",1,0);

                                init_tb("coba1E",1,0);
								init_tb("coba1D",1,0);
								init_tb("coba1T",1,0);								
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
   <div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div>
   
   
   
   <!-- ui-dialog -->
		<div id="dialog" title="Summary">
		  <?php
           
			echo $vsummary->summarymhs($nim);
          ?>
	    		
		</div>
   
</body>

</html>
<?php
	 }}
?>