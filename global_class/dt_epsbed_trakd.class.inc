<?php

require_once 'shared.php';

class dt_epsbed_trakd
{
   var $tb;
   var $idx_array;
   
   function __construct(){
     $this->tb = new tb_epsbed_trakd;
	 
	 $this->idx_array= array();
	 $data=$this->getData();
	 
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      foreach($this->tb->fieldname as $fieldnm)
		  {
		    if(!in_array($fieldnm,$this->tb->keyfield)){
			   $this->idx_array[$row['THSMSTRAKD']][$row['NODOSTRAKD']]['mtk'][$row['KDKMKTRAKD']][$row['KELASTRAKD']][$fieldnm]=$row[$fieldnm];
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
			  foreach($v1 as $f2=>$v2)
			  { 
			   $fieldarray[]=array('NODOSTRAKD'=>$f,'KDKMKTRAKD'=>$f1,'KELASTRAKD'=>$f2,'TMRENTRAKD'=>$v2['TMRENTRAKD'],'TMRELTRAKD'=>$v2['TMRELTRAKD']);
			  }
			}			
		 }
	   }
	  }
	  
	  return $fieldarray;   
   }
   
   function delData($thn)
   {
     $this->tb->deleteRecord(array('THSMSTRAKD'=>$thn)); 	 
	 
   }
   
   function siatoepsbed($thn)
   {
     $fieldarray = array(); 	 
	 $data = $this->getData();
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	      if($row['THSMSTRAKD'] != $thn){
	          $fieldarray[] = $row;	    
	      }
	   }	 
	 }
	 
	 $tb_pengajar = new tb_gen('pengajar');
	 $dt_dosen=new dt_dosen;
	
	 $data1 = $tb_pengajar->getData("thnsmspengajar='$thn' and kdkmkpengajar not like 'MATP%'");//and kdkmkpengajar not in ('UBB106','MAT352','MAT353')
	
	 $data=array();
	 
	 /*
	   0404037103  dadang ruhiat
	   0402108204  cecep suwanda
	   0403067801  dini andiani
	   0411057607  deni sopiansyah
       0403057104  adang effendi
	   0403037403  asep maulana
       0413037902  esih sukaesih 	   
	 */
	 
	 
	 $jmlmtk=array('0403057104'=>0,'0411057607'=>0,'0403037403'=>0,'0403067801'=>0,'0402108204'=>0,'0404037103'=>0,'0413037902'=>0);
	 if(!empty($data1))
	 {
	   $tmp=array();
	   foreach($data1 as $row)
	   {
	      $tmp['kdkmkpengajar'] = $row['kdkmkpengajar'];
		  $tmp['nidnpengajar'] = $dt_dosen->getnidnepsbed($row['kddspengajar']);
		 
		 if(!isset($data[$row['kdkmkpengajar']])) {			   
			   if(isset($jmlmtk[$tmp['nidnpengajar']]))
			   {
				 if($jmlmtk[$tmp['nidnpengajar']]<2){
   				   $data[$row['kdkmkpengajar']]=$tmp;
				   $jmlmtk[$tmp['nidnpengajar']]=$jmlmtk[$tmp['nidnpengajar']]+1;
				 }else{
                       $find=0;
					   $bts=3;
					   while($find==0)
					   {     
							
							foreach($jmlmtk as $nidn=>$jml)
                            {
								 if((($find==0) and ($jml<$bts)) and ($tmp['nidnpengajar']!=$nidn)){
								    if(in_array($row['kdkmkpengajar'],array('MAT352','MAT353'))){  
									  $tmp['nidnpengajar']='0402108204';
								    }else{   
									  $tmp['nidnpengajar']=$nidn;
								    }   
									   
								   $data[$row['kdkmkpengajar']]=$tmp;
								   $jmlmtk[$tmp['nidnpengajar']]=$jmlmtk[$tmp['nidnpengajar']]+1;
								   $find=1;						   
								 }
                                 
							}
							$bts=$bts+1;
						}	
					   
					   if($find==0){
					    $data[$row['kdkmkpengajar']]=$tmp;
					   }
				   }				 
			   }else{
			     $data[$row['kdkmkpengajar']]=$tmp;
			   }
		 }	 
	   }  
	 }
	 
	 
	 if(!empty($data))
	 {
	  
	   foreach($data as $row)
	   {	     
	      
		  //if( $thn=='20091' and $row['kdkmkpengajar'] == 'MAT364' )
		  //{
		   //  $kdkmk = 'MAT307';
		  //}else{	 
		     $kdkmk = $row['kdkmkpengajar'];
		  //}
		//if($kdkmk!='MAT314'){  
		  $fieldarray[] = array('THSMSTRAKD'=>$thn,'KDPTITRAKD'=>'041048','KDJENTRAKD'=>'C','KDPSTTRAKD'=>'44201','NODOSTRAKD'=>$row['nidnpengajar'],'KDKMKTRAKD'=>$kdkmk,'KELASTRAKD'=>'01','TMRENTRAKD'=>16,'TMRELTRAKD'=>14);	    
        //}
	   }	 
	 }
	 
	 
	 $this->tb->writedata($fieldarray);
   
   }
   
   function stat($thn)
   {
     $dt_kmk = new dt_epsbed_kmk;
     $fieldarray = array(); 	 
	 
	 if(!empty($this->idx_array))
    {
	
	  if($thn!=0)
	  {
	    if(isset($this->idx_array[$thn]))
		{
		    $jml_tot_kls=0;
			$jml_tot_sks=0;
			$jml_tot_mtk=0;
		   foreach($this->idx_array[$thn] as $f=>$v)
		   {
		      $jml_kls=0;
			  $jml_sks=0;
			  $jml_mtk = count($v['mtk']);
			  foreach($v['mtk'] as $f1=>$v1)
		      { 		   
		        foreach($v1 as $f2=>$v2){
  				  $jml_kls=$jml_kls+1;
                  $jml_tot_kls=$jml_tot_kls+1;				  
				  $jml_sks=$jml_sks+$dt_kmk->getsks($thn,$f1);
				  $jml_tot_sks=$jml_tot_sks+$jml_sks;
				}  
		      } 
              $jml_tot_mtk=$jml_tot_mtk+$jml_mtk;
			  $fieldarray[$f]['jml_mtk']=$jml_mtk;
              $fieldarray[$f]['jml_sks']=$jml_sks;
 			  $fieldarray[$f]['jml_kelas']=$jml_kls;
		   }
		      $fieldarray['Jumlah']['jml_mtk']=$jml_tot_mtk;
              $fieldarray['Jumlah']['jml_sks']=$jml_tot_sks;
 			  $fieldarray['Jumlah']['jml_kelas']=$jml_tot_kls;
		   
		}
	  
	  }else{
	       
		   foreach($this->idx_array as $f=>$v)
		   {
		      $jml_dsn=0;
			  $jml_mtk=0;
			  $jml_kls=0;
			  $jml_min_sks=0;
			  $jml_max_sks=0;
			  
			  foreach($v as $f1=>$v1)
			  {
			    			
				$jml_dsn=$jml_dsn+1;
                $jml_mtk=$jml_mtk+count($v1['mtk']);
                $jml_sks=0;
				foreach($v1['mtk'] as $f2=>$v2)
				{   
				   	foreach($v2 as $f3=>$v3){
                      $jml_kls=$jml_kls+1;					 
					  $jml_sks=$jml_sks+$dt_kmk->getsks($f,$f2);
                     
					}					
				   
				   $jml_max_sks=$jml_max_sks<$jml_sks ? $jml_sks : $jml_max_sks;
				   $jml_min_sks=$jml_min_sks==0 ? $jml_sks : $jml_min_sks;
				   $jml_min_sks=$jml_min_sks>$jml_sks ? $jml_sks : $jml_min_sks;
				}
			  }			  
			  
		      $fieldarray[$f]['jml_dsn']=$jml_dsn;
              $fieldarray[$f]['jml_mtk']=$jml_mtk;
 			  $fieldarray[$f]['jml_kelas']=$jml_kls;
			  $fieldarray[$f]['jml_min_sks']=$jml_min_sks;
			  $fieldarray[$f]['jml_max_sks']=$jml_max_sks;
		   }
	          
	  
	  }	
	}
	 	 	 
	 return  $fieldarray;   
   }
   
   
   
   function getTRAKD()
   {   
     return $this->tb->getTablePath();
   }
   
   
}

?>