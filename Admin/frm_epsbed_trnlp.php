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
	  
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Nilai Mahasiswa</title>
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

	var asInitVals = new Array();
    var oTable;	
	function init_tb()
	{
	  oTable=$("#lst_epsbedtrakd").dataTable();
	}
	
	function update_stat()
	{
	  $("#stat").html("<fieldset><font size='1' color='red'>Memroses Data ....</font> <img src='../img/ajax-loader.gif' /></fieldset>");
	  $.ajax({
                                     type : "POST",
				                     url : "../global_class/chg_conten.php",
				                     cache: false,
				                     data :"idx=58",
									 success : function(data){
					                            $("#stat").html(data);
												 init_tb();
												 $("#stat1_epsbedtrnlm").dataTable({"aaSorting": []});
												}
                                  });
	}

	$(document).ready(function () {
		// Dialog
		    
				$('#dialog').dialog({
					autoOpen: true,
					width: 700,
					resizable: true,
					autoHeight: true,
					open: function(){
							//$('#pgload').html("");								
							init_tb();
							$("#stat1_epsbedtrnlm").dataTable({"aaSorting": []});
						  },
					buttons: {
						"Ok": function() {
							$(this).dialog("close");
						}
					}
				});
				
				$("#filter").click( function()
                  {
                    var nim = $("#nim").val();	
                    var tmp = $('#nim').find('option:selected').text();
					$("#hsl_filter").html("Hasil Filter : "+tmp);
					$("#data").html("<fieldset><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></fieldset>");
		            $.ajax({
                                     type : "POST",
				                     url : "../global_class/chg_conten.php",
				                     cache: false,
				                     data :"nim="+nim+"&idx=31",
									 success : function(data){
					                            $("#data").html(data);
												 init_tb();
												 
												}
                                  });
				  });
				  
				 $("#Add").click( function()
                  {
                    var nim = $("#nim").val();	
                    var tmp = $('#nim').find('option:selected').text();
					$("#hsl_filter").html("Hasil Filter : "+tmp);
                    $("#data").html("<fieldset><font size='1' color='red'>Memroses Data ....</font> <img src='../img/ajax-loader.gif' /></fieldset>");					
		            $.ajax({
                                     type : "POST",
				                     url : "../global_class/chg_conten.php",
				                     cache: false,
				                     data :"nim="+nim+"&idx=32",
									 success : function(data){
					                            $("#data").html(data);
												 init_tb();
												 update_stat();
												}
                                  });
				  });
                  
                  $("#Del").click( function()
                  {
                    var nim = $("#nim").val();	
                    var tmp = $('#nim').find('option:selected').text();
					$("#hsl_filter").html("Hasil Filter : "+tmp);
					$("#data").html("<fieldset><font size='1' color='red'>Memroses Data ....</font> <img src='../img/ajax-loader.gif' /></fieldset>");
		            $.ajax({
                                     type : "POST",
				                     url : "../global_class/chg_conten.php",
				                     cache: false,
				                     data :"nim="+nim+"&idx=33",
									 success : function(data){
					                            $("#data").html(data);
												 init_tb();
												 update_stat();
												}
                                  });
				  });				  
				  
				  $("#Down").click( function()
                  {
                    var nim = $("#nim").val();	
                    var tmp = $('#nim').find('option:selected').text();
					$("#hsl_filter").html("Hasil Filter : "+tmp);					
		            $.ajax({
                                     type : "POST",
				                     url : "../global_class/chg_conten.php",
				                     cache: false,
				                     data :"nim="+nim+"&idx=34",
									 success : function(data){
												window.open(data,'Download'); 
												}
                                  });
				  });		
				

 	});

	</script>
	
  <style type="text/css">
     
  </style>
</head>

<body>
   <!--<div id='pgload'><font size='1' color='red'>Mengontak Server ....</font> <img src='../img/ajax-loader.gif' /></div> -->
   <!-- ui-dialog -->
		<div id="dialog" title="Nilai Mahasiswa">
		  <?php 
		   $vwepsbedtrnlp = new vw_epsbed_trnlp;
		   echo $vwepsbedtrnlp->mhs_filter(); 
		  ?> 
		</div>
   
</body>

</html>
	 <?php }} ?>