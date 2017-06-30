<?php
require_once 'shared.php';

$thnmsmshs=$_POST['thnmsmshs'];

$vmhs = new dt_mhs;
$data=$vmhs->getkls($thnmsmshs);

foreach($data as $row)
{

  if($row['shiftmsmhs']=='R'){
     echo"<option value='$row[shiftmsmhs]'>$row[shiftmsmhs] - Reguler</option>";
  }else{ 
     echo"<option value='$row[shiftmsmhs]'>$row[shiftmsmhs] - Non Reguler </option>";
  }
  
 }
?>

