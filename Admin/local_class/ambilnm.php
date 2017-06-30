<?php
require_once 'shared.php';

$thnmsmshs=$_POST['thnmsmshs'];
$kelas=$_POST['kelas'];

$vmhs = new dt_mhs;
$data=$vmhs->getmhs($thnmsmshs,$kelas);

foreach($data as $row)
{
    echo "<option value='$row[nimhsmsmhs]'>$row[nimhsmsmhs] - $row[nmmhsmsmhs]</option>";
 }
?>

