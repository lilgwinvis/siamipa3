<?php

require_once 'shared.php';


class dt_epsbed_trnlm
{
   var $tb;
   var $dt_kmk;
   var $idx_array;
   
   var $jml_skssem;
   var $jml_skstot;
   var $jml_bobotsem;
   var $jml_bobottot;
   
   
   function __construct(){
     $this->tb = new tb_epsbed_trnlm;
     $this->dt_kmk = new dt_epsbed_kmk;     
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			   $this->idx_array[$row['THSMSTRNLM']][$row['NIMHSTRNLM']]['mtk'][$row['KDKMKTRNLM']][$fieldnm]=$row[$fieldnm];
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
		    foreach($v['mtk'] as $f1=>$v1)
			{
			   $fieldarray[]=array('NIMHSTRNLM'=>$f,'KDKMKTRNLM'=>$f1,'NLAKHTRNLM'=>$v1['NLAKHTRNLM'],'BOBOTTRNLM'=>$v1['BOBOTTRNLM']);
			}			
		 }
	   }
	  }
	  
	  return $fieldarray;   
   }
   
   function delData($thn)
   {
     $this->tb->deleteRecord(array('THSMSTRNLM'=>$thn));
   }
   
   function siatoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $dataunik=array();
	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['THSMSTRNLM'] != $thn){
		     if(!isset($dataunik[$row['THSMSTRNLM'].$row['NIMHSTRNLM'].$row['KDKMKTRNLM']]))
             {
			    $fieldarray[] = $row;
                $dataunik[$row['THSMSTRNLM'].$row['NIMHSTRNLM'].$row['KDKMKTRNLM']]=0;				
		     }
		  }
	   }	 
	 }
	 
	 $tb_trnlm = new tb_gen('trnlm');
	 $data = $tb_trnlm->getData("thsmstrnlm='$thn' and kdkmktrnlm not like 'MATP%'");
	
	 if(!empty($data))
	 {
	   
	   foreach($data as $row)
	   {	     
	      
		 //if( $thn=='20091' and $row['kdkmktrnlm'] == 'MAT364' )
		  //{
		    // $kdkmk = 'MAT307';
		  //}else{	 
		     $kdkmk = $row['kdkmktrnlm'];
		  //} 
		  
		 if(($kdkmk!='MAT307') and ($kdkmk!='MAT314')){
   		     
			if(!isset($dataunik[$thn.$row['nimhstrnlm'].$kdkmk]))
            { 
			 $fieldarray[] = array('THSMSTRNLM'=>$thn,'KDPTITRNLM'=>'041048','KDJENTRNLM'=>'C','KDPSTTRNLM'=>'44201','NIMHSTRNLM'=>strtoupper($row['nimhstrnlm']),'KDKMKTRNLM'=>strtoupper($kdkmk),'NLAKHTRNLM'=>($row['nlakhtrnlm']=='K' ? 'E' : ($row['nlakhtrnlm']=='T' ? 'C' : $row['nlakhtrnlm'])),'BOBOTTRNLM'=>( $row['nlakhtrnlm']=='K' ? '0.00' : ( $row['nlakhtrnlm']=='T' ? '2.00' : $row['bobottrnlm'])),'KELASTRNLM'=>'01');	    
             $dataunik[$thn.$row['nimhstrnlm'].$kdkmk]=0; 
			}
		 
		 }
	   }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
   
   }
   
   function siakrstoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $dataunik=array();
	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['THSMSTRNLM'] != $thn){
	         if(!isset($dataunik[$row['THSMSTRNLM'].$row['NIMHSTRNLM'].$row['KDKMKTRNLM']]))
             {  
			  $fieldarray[] = $row;
			  $dataunik[$row['THSMSTRNLM'].$row['NIMHSTRNLM'].$row['KDKMKTRNLM']]=0;
             }			  
	      }
	   }	 
	 }
	 
	 $tb_trnlm = new tb_gen('trnlm');
	
	
	 $data = $tb_trnlm->getData("thsmstrnlm='$thn' and kdkmktrnlm not like 'MATP%'");
	
	 if(!empty($data))
	 {			
	   
	   foreach($data as $row)
	   {	     
	      
		 //if( $thn=='20091' and $row['kdkmktrnlm'] == 'MAT364' )
		 // {
		//     $kdkmk = 'MAT307';
		//  }else{	 
		     $kdkmk = $row['kdkmktrnlm'];
		//  } 
		  
		 //if($kdkmk!='MAT314'){
		    if(!isset($dataunik[$thn.$row['nimhstrnlm'].$kdkmk]))
             {
   		      $fieldarray[] = array('THSMSTRNLM'=>$thn,'KDPTITRNLM'=>'041048','KDJENTRNLM'=>'C','KDPSTTRNLM'=>'44201','NIMHSTRNLM'=>strtoupper($row['nimhstrnlm']),'KDKMKTRNLM'=>strtoupper($kdkmk),'NLAKHTRNLM'=>'','BOBOTTRNLM'=>0,'KELASTRNLM'=>$row['kelastrnlm']);	    
              $dataunik[$thn.$row['nimhstrnlm'].$kdkmk]=0; 
		     } 
		 //}
	   }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
   
   }
   
   
   function stat($thn)
   {
     $dt_msmhs = new dt_epsbed_msmhs;
	 
	 
	 $fieldarray = array(); 	 
	 
	 
	 
	if(!empty($this->idx_array))
    {	
	  if(($thn!=0) && isset($this->idx_array[$thn]))
	  {
	    
		foreach($this->idx_array[$thn] as $f=>$v)
		{
		  $fieldarray[$thn][$dt_msmhs->get_tahunmsmhs($f)][$f]['jml_mtk'] = count($v['mtk']); 
		  $jml_sks=0;
		  $jml_mtk_t=0;
		  foreach($v['mtk'] as $f1=>$v1)
		  {
		    $jml_sks=$jml_sks+$this->dt_kmk->getsks($thn,$f1);
			if($v1['NLAKHTRNLM']=='T')
			{
			$jml_mtk_t=$jml_mtk_t+1;
			}
			 
			
		  }
		  $fieldarray[$thn][$dt_msmhs->get_tahunmsmhs($f)][$f]['jml_sks'] = $jml_sks;
		  $fieldarray[$thn][$dt_msmhs->get_tahunmsmhs($f)][$f]['jml_mtk_t'] = $jml_mtk_t;
		}
	 
	   }else
	   {
	     foreach($this->idx_array as $f=>$v)
		 {
		   $tmp_txt='';
		   $lst_ang=array();
		   $lst_mtk=array();
		   $lst_mtk_t=array();
		   $min_sks=0;
		   $max_sks=0;
		   foreach($v as $f1=>$v1)
		   {
	          	$jml_sks=0;
				foreach($v1['mtk'] as $f2=>$v2)
				{
				  if(!in_array($f2,$lst_mtk))
				 { 
		           $lst_mtk[]=$f2;                    			   
                 }	
				 
				 if(!in_array($f2,$lst_mtk_t) && ($v2['NLAKHTRNLM']=='T'))
				 { 
		           $lst_mtk_t[]=$f2;                    			   
                 }	
				 
                  $jml_sks=$jml_sks+$this->dt_kmk->getsks($f,$f2); 				 
				}
				
				if($jml_sks>$max_sks)
				{
				  $max_sks=$jml_sks;				
				  $min_sks= $min_sks == 0 ? $max_sks : $min_sks;
				}else{
				 if($jml_sks<$min_sks)
				 {
				  $min_sks=$jml_sks;				
				 }
				
				}

				
				
				$ang = $dt_msmhs->get_tahunmsmhs($f1);
				if(!in_array($ang,$lst_ang))
				{ 
		           $lst_ang[]=$ang;
				   $tmp_txt.=$ang.','; 
                 }				
		   }
		   
		    $fieldarray[$f]['jml_ang']=count($lst_ang);
	        $fieldarray[$f]['nm_ang']='('.chop($tmp_txt,',').')';
	        $fieldarray[$f]['jml_mhs']=count($v);
	        $fieldarray[$f]['jml_mtk']=count($lst_mtk);
			$fieldarray[$f]['max_sks']=$max_sks;
		    $fieldarray[$f]['min_sks']=$min_sks;
			$fieldarray[$f]['jml_mtk_t']=count($lst_mtk_t);
		 }
	 
	   }
	 }
	 
	 
	 
	 
	 return  $fieldarray;
   
   }
   
   function hit_sksbobotsem($thn,$nim)
   {
   
	$jml_sks=0;
	$jml_bbt=0;
	if(!empty($this->idx_array))
    {
	   if(isset($this->idx_array[$thn][$nim]['mtk']))
       {
	     foreach($this->idx_array[$thn][$nim]['mtk'] as $f=>$v){
		   $jml_sks = $jml_sks+$this->dt_kmk->getsks($thn,$f);
           $jml_bbt = $jml_bbt+($this->dt_kmk->getsks($thn,$f)*$v['BOBOTTRNLM']);		   
		 }
	   }
	  
	}
	
     $this->jml_skssem=$jml_sks;
	 $this->jml_bobotsem=$jml_bbt;
   }
   
   function hit_sksbobottot($thn,$nim,$p)
   {
       $dt_mtk=array();
	   	   
	   $jml_sks=0;
	   $jml_bbt=0;
	   
	 if(!empty($this->idx_array)){  	   
	   foreach($this->idx_array as $f=>$v)
	   {
	      if( ($f <= $thn) AND isset($v[$nim]) ){
	          
			  foreach($v[$nim]['mtk'] as $f1=>$v1){
						 
						 if( $thn!='20091' and $f1 == 'MAT307' )
						 { 
						   $idx = 'MAT364';
						 }
						 else{
						   $idx = $f1;
						 }
						 
						 if(!isset($dt_mtk[$idx]))
						 {
							$dt_mtk[$idx]=$v1['BOBOTTRNLM'];
							$jml_bbt+=($this->dt_kmk->getsks($thn,$idx)*$v1['BOBOTTRNLM']);
							$jml_sks+=$this->dt_kmk->getsks($thn,$idx);
						 }else{
						   if($dt_mtk[$idx]<$v1['BOBOTTRNLM'])
						   {
						     $jml_bbt-=($this->dt_kmk->getsks($thn,$idx)*$dt_mtk[$idx]);
						     $jml_bbt+=($this->dt_kmk->getsks($thn,$idx)*$v1['BOBOTTRNLM']);
							 $dt_mtk[$idx]=$v1['BOBOTTRNLM'];
						   }
						 
						 }
			            } 
	      }
	     
		
	   } 	   
	 }   
   
      if($p==1)
	  {
	     $dt_epsbed_trnlp =new dt_epsbed_trnlp;
	     $dt_epsbed_trnlp->hit_sksbobottot($nim,$thn,$dt_mtk); 
	     $jml_sks+=	$dt_epsbed_trnlp->jml_sks;
		 $jml_bbt+=	$dt_epsbed_trnlp->jml_bbt;
	   }
	  
	  $this->jml_skstot=$jml_sks;
	  $this->jml_bobottot=$jml_bbt;

   }
   
   
   function getTRNLM()
   {
   
     return $this->tb->getTablePath();
   }
   
   
}

?>