<?php  require_once 'shared.php'; 
     
	 $islog = $_SESSION['islog'];
	 
	 if($islog==0)
	 {
		 include("frm_login.php");
	 }
	 else
	 {	
     
     $kdkmkkrs = $_GET['kdkmkkrs'];
	 $shiftkrs = $_GET['shiftkrs'];
	 $kelaskrs = $_GET['kelaskrs'];
	 $semkrs = $_GET['semkrs'];
     	 
     $user = $_SESSION['user'];
	 
	 $pg_bfr = $_SESSION['pg_bfr'];
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Mahasiswa</title>
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

	

	$(document).ready(function () {
		// Dialog
		        var oTable;
				$('#dialog').dialog({
					autoOpen: true,
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){
							$('#pgload').html("");
					         oTable=$('#box-table-a').dataTable({
									"fnDrawCallback": function ( oSettings ) {
										if ( oSettings.aiDisplay.length == 0 )
										{
											return;
										}
										 
										var nTrs = $('#box-table-a tbody tr');
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
												return  'Angkatan '+sVal;
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
						"Save": function() {
							$(this).dialog("close");
							$.ajax({
                                     type : "POST",
				                     url : "ubahkls.php",
				                     cache: false,
				                     data : $('input[type=hidden]').serialize()+"&"+$('input:text').serialize()+"&"+$(":input",oTable.fnGetNodes()).serialize()+"&idx=1",
									 success : function(data){
					                            alert(data);
												window.parent.pg_bfr(<?php echo '"'.$pg_bfr.'"' ?>);		
				                               }
                                  });
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
   <?php echo "<link rel=\"icon\" href=\"../img/unibba.ico\" type=\"image/x-icon\">"; ?>
   <!-- ui-dialog -->
		<?php
          $vbaca_krs = new dt_krs;
		  $data = $vbaca_krs->getMtk1($kdkmkkrs,$shiftkrs,$kelaskrs,$semkrs);
		  
		  
		  
          foreach($data as $row)
		  {
		    if($row['shiftkrs']=='R'){
					  $tmp1="Reguler";
					}else
					{
					  $tmp1="Non Reguler";
					}
		  }
        ?>  		
		<div id="dialog" title="<?php echo "Ubah Kelas : ".$row['kdkmkkrs']." - ".$row['nakmktbkmk']." (".$tmp1.")" ?>" >
		<fieldset> 
			  <div id="data">
		<form name="ubahkls" id="ubahkls" method="post" action="ubahkls.php">  
		     <input type="hidden" name="kdmtk" value="<?php echo $row['kdkmkkrs'] ?>">
		     <table  id="box-table-a" width="100%" >
				<thead>
					<tr>
					  <th>Angkatan</th>
					  <th>NIM</th>
					  <th>Nama </th>					  
					  <th>Ubah</th>
					  <th>Kls. Mhs.</th>
					  <th>Sem. Mhs.</th>
					</tr>
				</thead>
				<tbody>
			     <?php
				     $data = $vbaca_krs->getMhs1($kdkmkkrs,$shiftkrs,$kelaskrs,$semkrs);
				     $tmp="";
					 $ctk=0;
					 $i=1;
				    foreach($data as $row){
					?>
						   <tr>	
							<td ><?php echo $row['tahunmsmhs']?></td>
							<td ><?php echo $row['nimhsmsmhs']?></td>
							<td ><?php echo $row['nmmhsmsmhs'] ?></td>
							
							<td ><input type="checkbox" name="nim[]" value="<?php echo $row['nimhsmsmhs'] ?>" id="nim<?php echo $i ?>" ></td>
							<td ><input type="text" name="klsmhs[<?php echo trim($row['nimhsmsmhs']) ?>]" value="<?php echo $row['kelaskrs'] ?>" id="klsmhs<?php echo $i ?>" ></td>
							<td ><input type="text" name="semmhs[<?php echo trim($row['nimhsmsmhs']) ?>]" value="<?php echo $row['semkrs'] ?>" id="semmhs<?php echo $i ?>" ></td>
						   </tr>			
					<?php
					     $i++;
					}				 
				 ?>
			    </tbody>
	      </table>
		</form>  
		</div>
			</fieldset>	
		</div>
        
</body>

</html>
<?php } ?>