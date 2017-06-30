<?php require_once 'shared.php'; 
     
     
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=1");
		 exit();
	 }
	 else
	 {	 
	    $user = $_SESSION['user'];
	   
	    $pg_bfr = $_SESSION['pg_bfr1'];
		
		
		 $thn = $_GET['thn'];
		 $sem = $_GET['sem'];
		 $rn=$_GET['rn'];
		 $kelas=$_GET['kelas'];		 
		 $kdkmk=$_GET['kdkmk'];
		 $ke=$_GET['ke'];
		 $idbapdhmd= $thn.$kdkmk.$sem.$kelas.$rn.$ke;
		 $idx =$_GET['idx'];
		
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Ganti Password</title>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<style type="text/css">
	 @import "../datatables/media/css/demo_page.css";
	 @import "../datatables/media/css/demo_table.css";
	.ui-widget { font-family: Trebuchet MS, Tahoma, Verdana, Arial, sans-serif; font-size: 9px; }
	/* Style the CKEditor element to look like a textfield */
		.cke_textarea_inline
		{
			
			overflow: auto;

			border: 1px solid gray;
			-webkit-appearance: textfield;
		}
    </style>
	
	<script type="text/javascript" src="../js/jquery-1.8.0.min.js"></script>
	<script type="text/javascript" src="../js/jquery-ui-1.8.23.custom.min.js"></script>
	<script type="text/javascript" src="../datatables/media/js/jquery.dataTables.js"></script>
	<script type="text/javascript" src="../js/siamipa.js"></script>
	<script type="text/javascript" src="local_js/frm_add_bap_dhmd.js"></script>
	<script src="../ckeditor/ckeditor.js"></script>
	<script type="text/javascript">

	

	$(document).ready(function () {
		          $( "#tgl" ).datepicker({
					  dateFormat: "yy-mm-dd"				  
					});
		
		
		  var editormateri1;
		      CKEDITOR.inline( 'm1', {
					extraPlugins: 'mathjax',
					mathJaxLib: 'http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML', 
					on: {
                          blur: function( event ) {
                                editomateri1 = event.editor.getData();
                                // Do sth with your data...
					            }
						}
				});
		 var editormateri2;
		      CKEDITOR.inline( 'm2', {
					extraPlugins: 'mathjax',
					mathJaxLib: 'http://cdn.mathjax.org/mathjax/2.2-latest/MathJax.js?config=TeX-AMS_HTML', 
					on: {
                          blur: function( event ) {
                                editomateri2 = event.editor.getData();
                                // Do sth with your data...
					            }
						}
				});
		
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width: 600,
					open: function(){
							$('#pgload').html("");
							init_tb();
						  },
					buttons: {
						"Save": function() {
							for (instance in CKEDITOR.instances){
                               CKEDITOR.instances[instance].updateElement();
							   switch (instance) {
									case "materi1":
										editormateri1 = CKEDITOR.instances[instance].getData();
										break;
									case "materi2":
										editormateri2 = CKEDITOR.instances[instance].getData();
										break;
                                    										
								} 
						       
							}
							
							$.ajax({
                                     type : "POST",
				                     url : "local_class/entry_bap_dhmd.php",
				                     cache: false,
				                     data : $("#frmbapdhmd").serialize()+'&idx=<?php echo $idx ?>&idbapdhmd=<?php echo $idbapdhmd ?>&materi1='+encodeURIComponent(editormateri1)+'&materi2='+encodeURIComponent(editormateri2),
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
		<div id="dialog" title="<?php echo ($idx==1 ? 'Add' : 'Edit'); ?> BAP dan DHMD">
			<?php 
		      $vwentrybapdhmd = new vwentrybapdhmd;
		      echo $vwentrybapdhmd->addbapdhmd($thn,$kdkmk,$sem,$kelas,$rn,$ke,$idx); 
		    ?> 
		</div>
   
</body>

</html>
<?php } ?>