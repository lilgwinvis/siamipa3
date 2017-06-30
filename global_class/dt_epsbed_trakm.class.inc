<?php

require_once 'shared.php';

class dt_epsbed_trakm
{
   var $tb;
   var $idx_array;
   var $dt_epsbed_trnlm;
   
   function __construct(){
     $this->tb = new tb_epsbed_trakm;
	 $this->dt_epsbed_trnlm =new dt_epsbed_trnlm;
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			   $this->idx_array[$row['THSMSTRAKM']][$row['NIMHSTRAKM']][$fieldnm]=$row[$fieldnm];
		    }
		  } 
	   }
	 }  
	 
	 
   }
   
   function getData()
   {      
	  $data = $this->tb->getData();
	  return $data;   
   }
   
   function getviewdata($thnsms)
   {      
	  $fieldarray = array();
	  
	  if(!empty($this->idx_array))
      {
	    if(isset($this->idx_array[$thnsms]))
	   {
	     foreach($this->idx_array[$thnsms] as $f=>$v)
		 {
		     $fieldarray[]=array('NIMHSTRAKM'=>$f,'NLIPSTRAKM'=>$v['NLIPSTRAKM'],'SKSEMTRAKM'=>$v['SKSEMTRAKM'],'NLIPKTRAKM'=>$v['NLIPKTRAKM'],'SKSTTTRAKM'=>$v['SKSTTTRAKM']);
						
		 }
	   }
	  }
	  
	  return $fieldarray;   
   }
   
   
   
   function delData($thn)
   {
     $this->tb->deleteRecord(array('THSMSTRAKM'=>$thn));
   }
   
   function siatoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['THSMSTRAKM'] != $thn){
	          $fieldarray[] = $row;	    
	      }
	   }	 
	 }
	
	
     set_time_limit(60);	 
	 $stat_mhs = new dt_stat_mhs;
	 
	 $dt_mhs = new dt_mhs;
	 $data = $dt_mhs->getAllData("smawlmsmhs<=$thn");
	 if(!empty($data))
	 {
	   
	   foreach($data as $row)
	   {	     
		  if($stat_mhs->getstatmhs($thn,$row['nimhsmsmhs'],1)=='A'){	
			// $sksem=$this->hit_skssem($thn,$row['nimhsmsmhs']);
			  
			  $this->dt_epsbed_trnlm->hit_sksbobotsem($thn,$row['nimhsmsmhs']);
			  $this->dt_epsbed_trnlm->hit_sksbobottot($thn,$row['nimhsmsmhs'],$row['bpmsmhs']);
			  
			  $sksem=$this->dt_epsbed_trnlm->jml_skssem;
			  $skstot=$this->dt_epsbed_trnlm->jml_skstot;
			  $bobotsem=$this->dt_epsbed_trnlm->jml_bobotsem;
			  $bobottot=$this->dt_epsbed_trnlm->jml_bobottot;;
			  
			  $ips = $sksem!=0 ? $bobotsem/$sksem : 0;
			  $ipk = $skstot!=0 ? $bobottot/$skstot : 0;		 
			  
			  if($sksem!=0){
				$fieldarray[] = array('THSMSTRAKM'=>$thn,'KDPTITRAKM'=>'041048','KDJENTRAKM'=>'C','KDPSTTRAKM'=>'44201','NIMHSTRAKM'=>$row['nimhsmsmhs'],'SKSEMTRAKM'=>$sksem,'NLIPSTRAKM'=>$ips,'SKSTTTRAKM'=>$skstot,'NLIPKTRAKM'=>$ipk);  
			  }
		  }
	   }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
     
   }
   
   function getTRAKM()
   {
     return $this->tb->getTablePath();
   }
   
   
   
   
   
   
   function hit_ips($thn,$nim)
   {
     
	 $dt_epsbed_trnlm =new dt_epsbed_trnlm;
	 $data = $dt_epsbed_trnlm->getData();
	  
	 $jml_sks=0;
	 $jml_sks_bbt=0;
	 if(!empty($data))
	 {	  
	   
	   foreach($data as $row)
	   {
	      if(($row['NIMHSTRNLM'] == $nim) AND ($row['THSMSTRNLM'] == $thn)){
	          $idx = $row['KDKMKTRNLM'];
			  $bbt = $row['BOBOTTRNLM'];
			  $jml_sks+=$this->dt_sks[$idx];
			  $jml_sks_bbt+=$this->dt_sks[$idx]*$bbt;
	      }
	     
		
	   } 	   
	 }   
   
     return  $jml_sks==0 ? 0 : $jml_sks_bbt/$jml_sks; 
	 
   }
   
   function hit_ipk($thn,$nim,$p)
   {
     $dt_epsbed_trnlm =new dt_epsbed_trnlm;
	 $data = $dt_epsbed_trnlm->getData();
	  
	 $dt_nilai = array();
	 
	 if(!empty($data))
	 {	  
	   
	   foreach($data as $row)
	   {
	      if(($row['NIMHSTRNLM'] == $nim) AND ($row['THSMSTRNLM'] <= $thn)){
	          
			 if( $thn!='20091' and $row['KDKMKTRNLM'] == 'MAT307' )
		     { 
			   $idx = 'MAT364';
			 }
			 else{
			   $idx = $row['KDKMKTRNLM'];
			 }
			 
			 if(isset($dt_mtk[$idx]))
			 {  if($dt_mtk[$idx]<=$row['BOBOTTRNLM'])
				{
				  $dt_mtk[$idx]=$row['BOBOTTRNLM'];
				}
			 }else{
                $dt_mtk[$idx]=$row['BOBOTTRNLM'];
			 }
			  
	      }
	     
		
	   } 	   
	 }   
   
      if($p==1)
	  {
	     $dt_epsbed_trnlp =new dt_epsbed_trnlp;
	     $data = $dt_epsbed_trnlp->getData();
	  
	 
	     if(!empty($data))
	     {	  
	   
	      foreach($data as $row)
	      {
	       if($row['NIMHSTRNLP'] == $nim){
	          
			 if( $row['KDKMKTRNLP'] == 'MAT307' )
		     { 
			   $idx = 'MAT364';
			 }
			 else{
			   $idx = $row['KDKMKTRNLP'];
			 }
			 
			   if(isset($dt_mtk[$idx]))
			 {  if($dt_mtk[$idx]<=$row['BOBOTTRNLP'])
				{
				  $dt_mtk[$idx]=$row['BOBOTTRNLP'];
				}
			 }else{
                $dt_mtk[$idx]=$row['BOBOTTRNLP'];
			 }
	      }
	     
		
	   } 	   
	   }	  
	  }
	  
	  
	  $jml_sks=0;
	  $jml_sks_bbt=0;
	  if(!empty($dt_mtk))
	  {
	    foreach($dt_mtk as $kmk=>$bbt)
		{
		   $jml_sks+=$this->dt_sks[$kmk];
		   $jml_sks_bbt+=$this->dt_sks[$kmk]*$bbt;
		}
            	  
	  }
   
     return $jml_sks==0 ? 0 : $jml_sks_bbt/$jml_sks;
   }
   
   function stat($thn)
   {
     $dt_msmhs = new dt_epsbed_msmhs;
	 $dt_kmk = new dt_epsbed_kmk;
	 
	 $fieldarray = array(); 	 
	 
	 if(!empty($this->idx_array))
     {	
	   foreach($this->idx_array as $f=>$v)
       {    
	        $min_ips=0;
			$max_ips=0;
			$max_sks_sem=0;
			$min_sks_sem=0;
			$min_ipk=0;
			$max_ipk=0;
			$min_sks_tot=0;
			$max_sks_tot=0;
            foreach($v as $f1=>$v1)
           {
              $max_ips = $max_ips<$v1['NLIPSTRAKM'] ? $v1['NLIPSTRAKM'] : $max_ips;
              $min_ips = $min_ips==0 ? $max_ips : $min_ips>$v1['NLIPSTRAKM'] ? $v1['NLIPSTRAKM'] : $min_ips;
			  $max_sks_sem = $max_sks_sem<$v1['SKSEMTRAKM'] ? $v1['SKSEMTRAKM'] : $max_sks_sem;
              $min_sks_sem = $min_sks_sem==0 ? $max_sks_sem : $min_sks_sem>$v1['SKSEMTRAKM'] ? $v1['SKSEMTRAKM'] : $min_sks_sem;
              $max_ipk = $max_ipk<$v1['NLIPKTRAKM'] ? $v1['NLIPKTRAKM'] : $max_ipk;
              $min_ipk = $min_ipk==0 ? $max_ipk : $min_ipk>$v1['NLIPKTRAKM'] ? $v1['NLIPKTRAKM'] : $min_ipk;
			  $max_sks_tot = $max_sks_tot<$v1['SKSTTTRAKM'] ? $v1['SKSTTTRAKM'] : $max_sks_tot;
              $min_sks_tot = $min_sks_tot==0 ? $max_sks_tot : $min_sks_tot>$v1['SKSTTTRAKM'] ? $v1['SKSTTTRAKM'] : $min_sks_tot;
		   }
       
	       $fieldarray[$f]['jml_mhs']=count($v);
		   $fieldarray[$f]['min_ips']=$min_ips;
		   $fieldarray[$f]['max_ips']=$max_ips;
		   $fieldarray[$f]['min_sks_sem']=$min_sks_sem;
		   $fieldarray[$f]['max_sks_sem']=$max_sks_sem;
		   $fieldarray[$f]['min_ipk']=$min_ipk;
		   $fieldarray[$f]['max_ipk']=$max_ipk;
		   $fieldarray[$f]['min_sks_tot']=$min_sks_tot;
		   $fieldarray[$f]['max_sks_tot']=$max_sks_tot;
		   
		   
	   }	   
		
	 	   
	 }
	  
	 return  $fieldarray;
   
   }
}

?>