<?php session_start(); 
    
	 $islog = isset($_SESSION['islog']) ? $_SESSION['islog'] : 0;
	 
	 if($islog==0)
	 {
		 header("Location: ../global_code/frm_login.php?idx=2");
		 exit();
	 }
	 else
	 {	 require_once 'shared.php';
		  
		 
		 $nim = $_SESSION['user'];
		 
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Lihat Nilai</title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
	<link type="text/css" href="../css/jquery-ui-1.8.23.custom.css" rel="stylesheet" />
	<!--<link type="text/css" href="../css/style.css" rel="stylesheet" />-->
	<link type="text/css" href="../datatables/media/css/jquery.dataTables.css" rel="stylesheet" />
	<style type="text/css">
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
							$("#box-table-a").dataTable();
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
		<?php
          $ventri_krs = new dt_krs;
		  $thnsms = $ventri_krs->TA();
		  $vbaca_krs = new dt_krs;
		  $data = $vbaca_krs->getMhs($thnsms,$nim);
		 if(!empty($data)){ 	  
          foreach($data as $row)
		  {}
		 } 
        ?>  		
		<div id="dialog" title="<?php echo "Lihat KRS : ".$row['nimhsmsmhs']." - ".$row['nmmhsmsmhs'] ?>" >
		  <table  id="box-table-a" >
				<thead>
					<tr>
					  <th>Semester</th>
					  <th>Kode Mata Kuliah</th>
					  <th>Nama Mata Kuliah</th>
					  <th>SKS</th>
					  <th>Kelas</th>		  
					</tr>
				</thead>
				<tbody>
		<?php	          
			$data = $vbaca_krs->getMtk($thnsms,$nim);
            $tmp="";
			$ctk=0;
			$jmlsks=0;
			if(!empty($data)){ 
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
				
					 
				
             if($row['kelas']=='R'){
					  $tmp1="R - Reguler";
					}else
					{
					  $tmp1="N - Non Reguler";
					}
			if($ctk==1){
		?>		
			
			        <!--<tr>
					  <td colspan='4' align='center'><?php echo "Semester ".$tmp ?></td>
			        </tr>-->
			
			
			<tr>
				 <?php 
                       
					     $ctk=0;
					}
					   if($row['wp']=='p'){
                      ?>
				<td ><?php echo $row['semestbkmk']?></td>
				<td ><font color='red'><i><?php echo $row['kdkmkkrs']?></i></font></td>
				<td ><font color='red'><i><?php echo $row['nakmktbkmk']?></i></font></td>
				<td  align="center" ><font color='red'><i><?php echo $sks ?></i></font></td>
				<td  ><font color='red'><i><?php echo $tmp1 ?></i></font></td>
				<?php	
						}else{
						?>
				<td ><?php echo $row['semestbkmk']?></td>
				<td ><?php echo $row['kdkmkkrs']?></td>
				<td ><?php echo $row['nakmktbkmk'] ?></td>
				<td  align="center" ><?php echo $sks ?></td>
                <td  ><?php echo $tmp1 ?></td>				
				<?php
						}
						?>
             </tr>
			 
			 
			 
        <?php
           }
        ?> 	
             	
			</tbody>
	      </table>
		 <br><p>Jumlah SKS : <?php echo $jmlsks ?></p>
		</div>
        <?php
           }
        ?> 	
</body>

</html>
<?php } ?>