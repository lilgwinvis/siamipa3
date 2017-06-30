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
	    		
		
		$user = $_SESSION['user'];
	    
	 
		$idx = $_GET['idx'];
		$pg_bfr = $_SESSION['pg_bfr'];
		$id = isset($_GET['id']) ? $_GET['id']:"";
		$thn = isset($_GET['thn']) ? $_GET['thn']:"";
		$nim = isset($_GET['nim']) ? $_GET['nim']:"";
		$idbimbingan = isset($_GET['idbimbingan']) ? $_GET['idbimbingan']:"";
		
		$vw_ta = new vw_ta;  
		
		switch($idx)
		{
		  case 1 : $title='Add Data Sidang';break;
		  case 2 : $title='Edit Data Sidang';break;		  		 
		}
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title><?php echo $title  ?></title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	
	<style type="text/css">	 
	/* Style the CKEditor element to look like a textfield */
		.cke_textarea_inline
		{
			
			overflow: auto;

			border: 1px solid gray;
			-webkit-appearance: textfield;
		}
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>	
	<script src="../ckeditor/ckeditor.js"></script>
	
	<script type="text/javascript">

	

	$(document).ready(function () {
		// Dialog
		var oTable;
		var editortxt;
		var editortxt1;
		var editortxt2;
		      CKEDITOR.inline( 'judultxt', {
					extraPlugins: 'mathjax',
					mathJaxLib: 'http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML', 
					on: {
                          blur: function( event ) {
                                editortxt = event.editor.getData();
                                // Do sth with your data...
					            }
						}
				});
				CKEDITOR.inline( 'absindotxt', {
					extraPlugins: 'mathjax',
					mathJaxLib: 'http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML', 
					on: {
                          blur: function( event ) {
                                editortxt1 = event.editor.getData();
                                // Do sth with your data...
					            }
						}
				});
				CKEDITOR.inline( 'absingtxt', {
					extraPlugins: 'mathjax',
					mathJaxLib: 'http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML', 
					on: {
                          blur: function( event ) {
                                editortxt2 = event.editor.getData();
                                // Do sth with your data...
					            }
						}
				});
			    $( "#tgllls" ).datepicker({
					  dateFormat: "yy-mm-dd"				  
					});	
			    $( "#tglsid" ).datepicker({
					  dateFormat: "yy-mm-dd"				  
					});	
				$( "#tglsk" ).datepicker({
					  dateFormat: "yy-mm-dd"				  
					});	
				$('#dialog').dialog({
					autoOpen: true,
					width: 800,					
					resizable: true,
					autoHeight: true,
					open: function(){
							$('#pgload').html("");
												
						  },
					buttons: {
					  
						"Save": function() {	
							for (instance in CKEDITOR.instances){
                               CKEDITOR.instances[instance].updateElement();
							   switch (instance) {
									case "judultxt":
										editortxt = CKEDITOR.instances[instance].getData();
										break;
									case "absindo":
										editortxt1 = CKEDITOR.instances[instance].getData();
										break;
                                    case "absingtxt":
										editortxt2 = CKEDITOR.instances[instance].getData();
										break;										
								} 
						       
							}
							
							
							$.ajax({
                                     type : "POST",
				                     url : "../global_code/entry_dt_sidang.php",
				                     cache: false,
				                     data : $("#frmsidang").serialize()+'&idx=<?php echo $idx ?>&idbimbingan=<?php echo $idbimbingan ?>&judul='+encodeURIComponent(editortxt)+'&absindo='+encodeURIComponent(editortxt1)+'&absing='+encodeURIComponent(editortxt2),
									 success : function(data){					                            
												alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);			
				                               }
                                  });
							
							$(this).dialog("close");
						},						
						"Cancel": function() {
							$(this).dialog("close");
							window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);
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
		<div id="dialog" title="<?php echo $title  ?>">
         <div id="data">		 
		 <?php
		   switch($idx)
		   {
		   case 1 : echo $vw_ta->addsidang($thn,$nim,$idbimbingan);break;
		   case 2 : echo $vw_ta->editsidang($id);break;		   		   
		   }

		  ?> 
		 </div>  
		   
		</div>
   
</body>

</html>


<?php } ?>