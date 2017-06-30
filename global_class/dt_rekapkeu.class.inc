<?php
require_once 'shared.php';
class dt_rekapkeu {
	
	function __construct() {
		// Type your code here
	}
	
	function getrekapkeutotal() {

	 $tb = new tb_gen('vw_rekapkeutotal');
	 $data = $tb->getData('');
	 
	 $table['isitable']=array();
	 $table['footer']='';
	 $tot_danamasuk=0;
	 $tot_ajuan=0;
	 $tot_kurang=0;
	 $tot_lebih=0;
	 if(!empty($data))
	 {
		 foreach($data as $row)
		 {
			 $table['isitable'][]=array(array($row['thn'],array()),array(number_format($row['danamasuk'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['jmlajuan'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['surflus'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['defisit'], 2, ',', '.'),array('align'=>'right')));
			 $tot_danamasuk+=$row['danamasuk'];
	         $tot_ajuan+=$row['jmlajuan'];
	         $tot_kurang+=$row['surflus'];
	         $tot_lebih+=$row['defisit'];
		 }
	 }	 
     
	                $txt = '';
					$txt = $txt."<tr>";												
						$txt = $txt."<th>Total</th>";
						$txt = $txt."<th align='right'>".number_format($tot_danamasuk, 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($tot_ajuan, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($tot_kurang, 2, ',', '.')."</th>";
                        $txt = $txt."<th align='right'>".number_format($tot_lebih, 2, ',', '.')."</th>";						
					$txt = $txt."</tr>";
	 $table['footer']=$txt;
	 
	 return $table;
    }
	function getrekapkeuoperasional() {

	 $tb = new tb_gen('vw_rekapkeuoperasional');
	 $data = $tb->getData('');
	 
	 $table['isitable']=array();
	 $table['footer']='';
	 $tot_danaoprasional=0;
	 $tot_ajuan=0;
	 $tot_kurang=0;
	 $tot_lebih=0;
	 if(!empty($data))
	 {
		 foreach($data as $row)
		 {
			 $table['isitable'][]=array(array($row['thn'],array()),array(number_format($row['danaoprasional'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['jmlajuan'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['surflus'], 2, ',', '.'),array('align'=>'right')),array(number_format($row['defisit'], 2, ',', '.'),array('align'=>'right')));
			 $tot_danaoprasional+=$row['danaoprasional'];
	         $tot_ajuan+=$row['jmlajuan'];
	         $tot_kurang+=$row['surflus'];
	         $tot_lebih+=$row['defisit'];
		 }
	 }	 
     
	                $txt = '';
					$txt = $txt."<tr>";												
						$txt = $txt."<th>Total</th>";
						$txt = $txt."<th align='right'>".number_format($tot_danaoprasional, 2, ',', '.')."</th>";											
						$txt = $txt."<th align='right'>".number_format($tot_ajuan, 2, ',', '.')."</th>";
						$txt = $txt."<th align='right'>".number_format($tot_kurang, 2, ',', '.')."</th>";
                        $txt = $txt."<th align='right'>".number_format($tot_lebih, 2, ',', '.')."</th>";						
					$txt = $txt."</tr>";
	 $table['footer']=$txt;
	 
	 return $table;
    }
}
?>