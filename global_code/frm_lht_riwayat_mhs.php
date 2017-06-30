<?php require_once 'shared.php'; 
     
        
	 $islog = $_SESSION['islog'];
	 $pg_bfr = $_SESSION['pg_bfr'];
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	  
	      $user = $_SESSION['user'];
	      
		  $kdkmktrnlm = $_GET['kdkmktrnlm'];
	      $shifttrnlm = $_GET['shifttrnlm'];
	      $kelastrnlm = $_GET['kelastrnlm'];
	      $semestrnlm = $_GET['semestrnlm'];
		  $thsmstrnlm = $_GET['thsmstrnlm'];
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Mahasiswa</title>
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

	

	$(document).ready(function () {
		// Dialog
				$('#dialog').dialog({
					autoOpen: true,
					width : 450,
					autoHeight:true, 
					resizable: true,
					open: function(){
					    $('#box-table-a').dataTable({
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
						"Ok": function() {
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
          $vbaca_trnlm = new dt_trnlm;
		  $data = $vbaca_trnlm->getmtk($kdkmktrnlm,$shifttrnlm,$kelastrnlm,$semestrnlm,$thsmstrnlm);
		  
		  
		  
          foreach($data as $row)
		  {
		    if($row['shifttrnlm']=='R'){
					  $tmp1="Reguler";
					}else
					{
					  $tmp1="Non Reguler";
					}
		  }
        ?>  		
		<div id="dialog" title="<?php echo "Lihat Mahasiswa : ".$row['kdkmktrnlm']." - ".$row['nakmktbkmk']." (".$tmp1.")" ?>" >
	    <fieldset> 
			<div id="data">	 
     		 <table  id='box-table-a' width='100%'>
				<thead>
					<tr>
					  <th>Angkatan</th>
					  <th>NIM</th>
					  <th>Nama </th>					  		  
					</tr>
				</thead>
				<tbody>
			     <?php
				     $data = $vbaca_trnlm->getmhs($kdkmktrnlm,$shifttrnlm,$kelastrnlm,$semestrnlm,$thsmstrnlm);				     
				    foreach($data as $row){
				 ?> 	   <tr>	
							<td ><?php echo $row['tahunmsmhs']?></td>
							<td ><?php echo $row['nimhsmsmhs']?></td>
							<td ><?php echo $row['nmmhsmsmhs'] ?></td>							
						   </tr>			
					<?php
					}				 
				 ?>
			    </tbody>
	      </table>
		   </div>
			</fieldset>	
		</div>
        
</body>

</html>
<?php } ?>