<?php

require_once 'shared.php';

class dt_rekap_trkeumhs 
{

   function __construct(){
   
   }
   
   function getrekaptrkeumhs($where="")
   {
     $tb=new tb_gen('vw_tbrekaptrkeumhs');
	 $data = $tb->getData($where);
     return $data;
   }
   
   function getpendperthn()
   {
     $tb=new tb_gen('trkeumhs');
	 
	 $tb->sql_select="EXTRACT(YEAR FROM trkeumhstgl) AS thn,SUM(trkeumhsbayar) AS jml";
	 $tb->sql_groupby="thn";
	 $tb->sql_orderby="thn";  
	 
	 $data = $tb->getData("");
     return $data;
   }
   function getrekapacclvl0()
   {
     $tb=new tb_gen('rekap_acclvl0');
     $data = $tb->getData("");
     return $data;   
   }
   
   function getdtchart()
   {
      	  
	  $tb = new tb_gen('vw_rekapkeu1');	
	  $data = $tb->getData('');
	  
	  $chartdata=array();	  
	  
	  if($tb->numrows>0){
		  $tmp=array();	
		  
		  $thn_arr=array_unique(array_column($data, 'thn'));
	      asort($thn_arr);  
	  
	      $bln_arr=array_unique(array_column($data, 'bln'));
	      asort($bln_arr);
		  
		  array_walk($thn_arr,function ($thn,$key) use (&$tmp,$bln_arr){	            
			array_walk($bln_arr,function ($bln,$key1) use (&$tmp,$thn){
	            $tmp[$bln][$thn]=0;				
	        });	
	      });
		  		  
		  array_walk($data,function ($row,$key) use (&$tmp){$tmp[$row['bln']][$row['thn']]=$row['tran'];});		  
		  
	      array_walk($tmp,function ($arrrekap,$bln) use (&$chartdata){
			 $nmbln = array(1=>'Jan',2=>'Feb',3=>'Mar',4=>'Apr', 5=>'Mei',6=>'Jun',7=>'Jul',8=>'Agus',9=>'Sept',10=>'Okt',11=>'Nov',12=>'Des');	
			 $dt=array();	   
		     array_walk($arrrekap, function ($rekap,$thn) use (&$dt){			 
				 $dt[]=array('label'=>"$thn",'y'=>intval($rekap)); 
				 });				
				  $tmp_chart=array('type'=>"stackedBar",'showInLegend'=>'true','name'=>"$nmbln[$bln]",'dataPoints'=>$dt);		
				  $chartdata[]=$tmp_chart;			
		  });	
	  }
	  return $chartdata;
   }
   function getdtchart1()
   {
     $tb = new tb_gen('vw_rekapkeu2');	
	 $data = $tb->getData('');
	  
	 $chartdata=array();
	 
	 if($tb->numrows>0){
		 
		  
		  $ang_arr=array_unique(array_column($data, 'tahunmsmhs'));
	      asort($ang_arr);
		  
		  $thn_arr=array_unique(array_column($data, 'thn'));
	      asort($thn_arr);  
	  
	      
		  array_walk($ang_arr,function ($ang,$key) use (&$tmp,$thn_arr){	            
			array_walk($thn_arr,function ($thn,$key1) use (&$tmp,$ang){
	            $tmp[$ang][$thn]=0;				
	        });	
	      });
		 
		 array_walk($data,function ($row,$key) use (&$tmp){$tmp[$row['tahunmsmhs']][$row['thn']]=$row['tran'];});	
		 
		 
		 array_walk($tmp,function ($arrrekap,$ang) use (&$chartdata){
			 
			 $dt=array();	   
		     array_walk($arrrekap, function ($rekap,$thn) use (&$dt){			 
				 $dt[]=array('label'=>"$thn",'y'=>intval($rekap)); 
				 });				
				  $tmp_chart=array('type'=>"stackedBar",'showInLegend'=>'true','name'=>"$ang",'dataPoints'=>$dt);		
				  $chartdata[]=$tmp_chart;			
		  });	 
	 }	 
	 
	 return $chartdata;
   }
   
   function getdtchart2()
   {
     $tb = new tb_gen('vw_rekapkeu3');	
	 $data = $tb->getData('');
	 
	 $chartdata=array();
	 
	 if($tb->numrows>0){
		   		   
		  $thn_arr=array_unique(array_column($data, 'thn'));
	      asort($thn_arr);
		  
		  $aku_arr=array_unique(array_column($data, 'nm'));
	      asort($aku_arr);  
	  
		   
		  array_walk($aku_arr,function ($aku,$key) use (&$tmp,$thn_arr){	            
			array_walk($thn_arr,function ($thn,$key1) use (&$tmp,$aku){
	            $tmp[$aku][$thn]=0;				
	        });	
	      }); 
		   
		  array_walk($data,function ($row,$key) use (&$tmp){$tmp[$row['nm']][$row['thn']]=$row['tran'];}); 
		   
		  array_walk($tmp,function ($arrrekap,$aku) use (&$chartdata){
			 
			 $dt=array();	   
		     array_walk($arrrekap, function ($rekap,$thn) use (&$dt){			 
				 $dt[]=array('label'=>"$thn",'y'=>intval($rekap)); 
				 });				
				  $tmp_chart=array('type'=>"stackedBar",'showInLegend'=>'true','name'=>"$aku",'dataPoints'=>$dt);		
				  $chartdata[]=$tmp_chart;			
		  });        
		  
	 }	 
	 return $chartdata;
   }
}


?>