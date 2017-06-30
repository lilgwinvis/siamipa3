<?php
    
    require_once 'shared.php';
	$vwmhs=new vwmhs;
    echo $vwmhs->detail($_POST['nim']);	
?>