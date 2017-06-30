<?php require_once 'shared.php';
     
	 $islog = $_SESSION['islog'];
	 
	 if($islog==0)
	 {
		 include("../global_code/frm_login.php");
	 }
	 else
	 {	 
	     
     
         $thnsms = $_GET['thsmskrs'];
	     $nim = $_GET['nim'];
	      	 
         $user = $_SESSION['user'];
	     
		 $pg_bfr = $_SESSION['pg_bfr'];
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Nilai</title>
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
					width : 700,
					autoHeight:true, 
					resizable: true,
					open: function(){
							$("#box-table-a").dataTable({
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
												return  "Semester " + sVal;
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
          $vbaca_krs = new dt_krs;
		  $data = $vbaca_krs->getMhs($thnsms,$nim);
		  
		  
		  
          foreach($data as $row)
		  {}
        ?>  		
		<div id="dialog" title="<?php echo "Lihat KRS : ".$row['nimhsmsmhs']." - ".$row['nmmhsmsmhs'] ?>" >
		  <fieldset>
		  <div>
		  <table  id="box-table-a" width="100%">
				<thead>
					<tr>
					  <th>Semester</th>
					  <th>Kode Mata Kuliah</th>
					  <th>Nama Mata Kuliah</th>
					  <th>SKS</th>
					  		  
					</tr>
				</thead>
				<tbody>
		<?php	          
			$data = $vbaca_krs->getMtk($thnsms,$nim);
            $tmp="";
			$ctk=0;
			$jmlsks=0;
			foreach($data as $row){	
                
				if(empty($tmp)){
					    $tmp=$row['semestbkmk'];
                        $ctk=1;					   
					 }else{
					    if($tmp!=$row['semestbkmk']){
						  $tmp=$row['semestbkmk'];
                          $ctk=1;
						}
					 }
					 
				if($row['sksprtbkmk']>0){
                   $sks=number_format($row['sksmktbkmk']-1, 2, '.', '');
                   $jmlsks+=$row['sksmktbkmk']-1;
				}else{
				   $sks=$row['sksmktbkmk'];
                   $jmlsks+=$row['sksmktbkmk'];				   
				}
				
					 
				
            
			if($ctk==1){
		?>		
			
			        <!--<tr>
					  <td colspan='3' align='center'><?php echo "Semester ".$tmp ?></td>
			        </tr>-->
			
			
			<tr>
				 <?php 
                       
					     $ctk=0;
					}
					  
					  if($row['wp']=='p'){
                 ?>
				<td ><?php echo $row['semestbkmk']?></td>
				<td ><?php echo $row['kdkmkkrs']?></td>
				<td ><font color='red'><i><?php echo $row['nakmktbkmk']?></i></font></td>
				<td  align="center" ><font color='red'><i><?php echo $sks ?></i></font></td>
				
				<?php	
						}else{
						?>
				<td ><?php echo $row['semestbkmk']?></td>
				<td ><?php echo $row['kdkmkkrs']?></td>
				<td ><?php echo $row['nakmktbkmk'] ?></td>
				<td  align="center" ><?php echo $sks ?></td>
                
				<?php
						}
						?>
             </tr>
			 
			 
			 
        <?php
           }
        ?> 	
             	
			</tbody>
	      </table>
		  </div>
		  <br><p>Jumlah SKS : <?php echo $jmlsks ?></p>
		  </fieldset>		 
		</div>
        
</body>

</html>
<?php } ?>