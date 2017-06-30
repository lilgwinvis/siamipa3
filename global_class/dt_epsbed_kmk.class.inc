<?php

require_once 'shared.php';

class dt_epsbed_kmk
{
   var $tb;
   var $idx_array;
   
   function __construct(){
     $this->tb = new tb_epsbed_kmk;
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			 $this->idx_array[$row['THSMSTBKMK']][$row['KDKMKTBKMK']][$fieldnm]=$row[$fieldnm];
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
		   $fieldarray[] = array('SEMESTBKMK'=> $v['SEMESTBKMK'],'KDKMKTBKMK'=>$f,'NAKMKTBKMK'=>$v['NAKMKTBKMK'],'SKSMKTBKMK'=>$v['SKSMKTBKMK'],'SKSTMTBKMK'=>$v['SKSTMTBKMK'],'SKSPRTBKMK'=>$v['SKSPRTBKMK'],'SKSLPTBKMK'=>$v['SKSLPTBKMK'],'NODOSTBKMK'=>$v['NODOSTBKMK'],'STKMKTBKMK'=>$v['STKMKTBKMK']);	
		 }
	   }
	  }
	  
	  return $fieldarray;
   }
   
   function delData($thn)
   {
     $this->tb->deleteRecord(array('THSMSTBKMK'=>$thn));
   }
   
   function siatoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['THSMSTBKMK'] != $thn){
	          $fieldarray[] = $row;	    
	      }
	   }	 
	 }
	 
	 /*$dt_mtk_h = new dt_mtk_h;	
	 $data = $dt_mtk_h->getData("THSMSTBKMK='$thn'");
	
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {	     
	      $fieldarray[] = array('THSMSTBKMK'=>$row['thsmstbkmk'],'KDPTITBKMK'=>$row['kdptitbkmk'],'KDJENTBKMK'=>$row['kdjentbkmk'],'KDPSTTBKMK'=>$row['kdpsttbkmk'],'KDKMKTBKMK'=>$row['kdkmktbkmk'],'NAKMKTBKMK'=>$row['nakmktbkmk'],'SKSMKTBKMK'=>$row['sksmktbkmk'],'SKSTMTBKMK'=>$row['skstmtbkmk'],'SKSPRTBKMK'=>$row['sksprtbkmk'],'SKSLPTBKMK'=>$row['skslptbkmk'],'SEMESTBKMK'=>$row['semestbkmk'],'KDWPLTBKMK'=>$row[ 'kdwpltbkmk'],'KDKURTBKMK'=>$row['kdkurtbkmk'],'KDKELTBKMK'=>$row['kdkeltbkmk'],'NODOSTBKMK'=>$row['nodostbkmk'],'STKMKTBKMK'=>$row['stkmktbkmk'],'SLBUSTBKMK'=>$row['slbustbkmk'],'SAPPPTBKMK'=>$row['sappptbkmk'],'BHNAJTBKMK'=>$row['bhnajtbkmk'],'DIKTTTBKMK'=>$row['diktttbkmk']);	    
       }	 
	 }*/
	 
	 $dt_mtk = new dt_mtk;	
	 $data = $dt_mtk->getData("kdkmktbkmk not like 'MATP%'");
	
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {	     
	      if(in_array($row['kdkmktbkmk'],array('MAT352','MAT353')))
		  {
		    $tmpwp='S';
		  }
		  else{
		    $tmpwp=($row[ 'wp']=='p' ? 'B' : 'A');
		  }
		  $fieldarray[] = array('THSMSTBKMK'=>$thn,'KDPTITBKMK'=>'041048','KDJENTBKMK'=>'C','KDPSTTBKMK'=>'44201','KDKMKTBKMK'=>$row['kdkmktbkmk'],'NAKMKTBKMK'=>$row['nakmktbkmk'],'SKSMKTBKMK'=>$row['sksmktbkmk'],'SKSTMTBKMK'=>$row['skstmtbkmk'],'SKSPRTBKMK'=>$row['sksprtbkmk'],'SKSLPTBKMK'=>$row['skslptbkmk'],'SEMESTBKMK'=>$row['semestbkmk'],'KDWPLTBKMK'=>$tmpwp,'KDKURTBKMK'=>'A','KDKELTBKMK'=>'A','NODOSTBKMK'=>$row['nodostbkmk'],'STKMKTBKMK'=>'A','SLBUSTBKMK'=>'Y','SAPPPTBKMK'=>'Y','BHNAJTBKMK'=>'T','DIKTTTBKMK'=>'T');	    
       }	 
	 }
	 
	 $this->tb->writedata($fieldarray);
   
   }
   
   
   function salin($thn)
   {
   
     $thn_sem = str_split($thn, 4);
	 if($thn_sem[1]==1)
	  {
	    $bts=$thn_sem[0]-1;
		$bts=$bts.'2';
	  }else
	  {
        $bts=$thn_sem[0];
        $bts=$bts.'1';		
	  }
	  
	  $dt_mtk_h = new dt_mtk_h;
      $dt_mtk_h->salin($bts,$thn);
   }
   
   
   function getTBKMK()
   {
   
     return $this->tb->getTablePath();
   }
   
   function getsks($thnkmk,$kdkmk){
     $tmp_sks= isset($this->idx_array[$thnkmk][$kdkmk]) ? $this->idx_array[$thnkmk][$kdkmk]['SKSMKTBKMK']  :0;
	 return $tmp_sks;
   }
   
   
   function getnmmtk($thn,$kd)
   {
    return $this->idx_array[$thn][$kd]['NAKMKTBKMK'];   
   }
   
   
   function stat($thn)   {
     
	 $fieldarray = array();  
	 
	 if(!empty($this->idx_array))
    {	
	  if(($thn!=0))
	  {		
	   if(isset($this->idx_array[$thn]))
       {	   
		$jml_tot_mtk=0;
		$jml_tot_mtk_gnjl=0;
		$jml_tot_mtk_gnp=0;
		$jml_tot_mtk_pp=0;
		$jml_tot_sks=0;
		$jml_tot_sks_gnjl=0;
		$jml_tot_sks_gnp=0;
		$jml_tot_sks_pp=0;
		$sem_gnjl=array('01','03','05','07');
		
		foreach($this->idx_array[$thn] as $f=>$v)
		{
		  $fieldarray[$v['NODOSTBKMK']]['jml_mtk']=isset($fieldarray[$v['NODOSTBKMK']]['jml_mtk']) ? $fieldarray[$v['NODOSTBKMK']]['jml_mtk']+1 : 1;
		  $fieldarray[$v['NODOSTBKMK']]['jml_sks']=isset($fieldarray[$v['NODOSTBKMK']]['jml_sks']) ? $fieldarray[$v['NODOSTBKMK']]['jml_sks']+$v['SKSMKTBKMK']: $v['SKSMKTBKMK'];
		  $jml_tot_mtk=$jml_tot_mtk+1;
		  $jml_tot_sks= $jml_tot_sks+$v['SKSMKTBKMK'];
		  
		  if(in_array($v['SEMESTBKMK'],$sem_gnjl)){
			  $fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnjl']=isset($fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnjl']) ? $fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnjl']+1 : 1;
			  $fieldarray[$v['NODOSTBKMK']]['jml_sks_gnjl']=isset($fieldarray[$v['NODOSTBKMK']]['jml_sks_gnjl']) ? $fieldarray[$v['NODOSTBKMK']]['jml_sks_gnjl']+$v['SKSMKTBKMK']: $v['SKSMKTBKMK'];
			  $jml_tot_mtk_gnjl=$jml_tot_mtk_gnjl+1;
			  $jml_tot_sks_gnjl= $jml_tot_sks_gnjl+$v['SKSMKTBKMK'];
              }		  
		  else{	  
			  if($v['KDWPLTBKMK']!='B'){
				  $fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnp']=isset($fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnp']) ? $fieldarray[$v['NODOSTBKMK']]['jml_mtk_gnp']+1 : 1;		  
				  $fieldarray[$v['NODOSTBKMK']]['jml_sks_gnp']=isset($fieldarray[$v['NODOSTBKMK']]['jml_sks_gnp']) ? $fieldarray[$v['NODOSTBKMK']]['jml_sks_gnp']+$v['SKSMKTBKMK']: $v['SKSMKTBKMK'];
				  $jml_tot_mtk_gnp=$jml_tot_mtk_gnp+1;
				  $jml_tot_sks_gnp= $jml_tot_sks_gnp+$v['SKSMKTBKMK'];
		          }else{
					  $fieldarray[$v['NODOSTBKMK']]['jml_mtk_pp']=isset($fieldarray[$v['NODOSTBKMK']]['jml_mtk_pp']) ? $fieldarray[$v['NODOSTBKMK']]['jml_mtk_pp']+1 : 1;		  
					  $fieldarray[$v['NODOSTBKMK']]['jml_sks_pp']=isset($fieldarray[$v['NODOSTBKMK']]['jml_sks_pp']) ? $fieldarray[$v['NODOSTBKMK']]['jml_sks_pp']+$v['SKSMKTBKMK']: $v['SKSMKTBKMK'];
					  $jml_tot_mtk_pp=$jml_tot_mtk_pp+1;
					  $jml_tot_sks_pp= $jml_tot_sks_pp+$v['SKSMKTBKMK'];
				  }
			  }
		  
		  
		  
		  
		  
		}
		  $fieldarray['Jumlah']['jml_mtk']=$jml_tot_mtk;
		  $fieldarray['Jumlah']['jml_mtk_gnjl']=$jml_tot_mtk_gnjl;
		  $fieldarray['Jumlah']['jml_mtk_gnp']=$jml_tot_mtk_gnp;
		  $fieldarray['Jumlah']['jml_mtk_pp']=$jml_tot_mtk_pp;
		  $fieldarray['Jumlah']['jml_sks']=$jml_tot_sks;
          $fieldarray['Jumlah']['jml_sks_gnjl']=$jml_tot_sks_gnjl;
          $fieldarray['Jumlah']['jml_sks_gnp']=$jml_tot_sks_gnp;
          $fieldarray['Jumlah']['jml_sks_pp']=$jml_tot_sks_pp; 		  
		}
	  }else
	  {	      
	     foreach($this->idx_array as $f=>$v)
		{ 
		  $jml_sks=0;
		  $jml_mtk_wjb=0;
		  $jml_sks_wjb=0;
		  $dsn=array();
		  foreach($v as $f1=>$v2)
		  {
		   $jml_sks = $jml_sks + $v2['SKSMKTBKMK'];
		   
		   if($v2['KDWPLTBKMK']!='B')
		   {
		     $jml_mtk_wjb= $jml_mtk_wjb + 1;
			 $jml_sks_wjb= $jml_sks_wjb + $v2['SKSMKTBKMK'];
		   }
		   
		   if(!in_array($v2['NODOSTBKMK'],$dsn))
		   {
		     $dsn[]=$v2['NODOSTBKMK'];
		   }
		  }
		  		  
		  $fieldarray[$f]['jml_mtk']=count($v);
		  $fieldarray[$f]['jml_sks']=$jml_sks;
		  $fieldarray[$f]['jml_mtk_wjb']=$jml_mtk_wjb;
		  $fieldarray[$f]['jml_sks_wjb']=$jml_sks_wjb;
		  $fieldarray[$f]['jml_dsn']=count($dsn);
		}  
	  }
	  
	  
	}  
	 
	 
	 return  $fieldarray;   
   }
   
}

?>