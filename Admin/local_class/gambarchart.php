<?php
require_once 'shared.php';

$idx=$_POST['idx'];

switch($idx){
	case 1 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs());
				 break;
	case 2 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs1());
				 break;
    case 3 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs2());
				 break;	
    case 4 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs3());
				 break;
	case 5 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs4());
				 break;
    case 6 :
				 $vw = new vw_mychart;
				 echo json_encode($vw->vwchartmhs5());
				 break;				 
 }	 
?>