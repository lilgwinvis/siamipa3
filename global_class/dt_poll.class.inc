<?php
 require_once 'shared.php';

class dt_poll 
{  
   var $numrows;
      
   function __construct()
   {
      	  	  
   }
   
   function cek_poll($thn,$nim)
   {
      $data=$this->getDataMpoll('nimhsmpoll="'.$nim.'" AND thsmsmpoll<='.$thn.' AND isimpoll=0');
      return ($this->numrows>0 ? 1 :0);	  
   }
   
   function alreadypoll($thn,$kdkmk,$nim)
   {
      $data=$this->getDataMpoll('nimhsmpoll="'.$nim.'" AND kdkmkmpoll="'.$kdkmk.'" AND thsmsmpoll='.$thn.' AND isimpoll=1');
      return ($this->numrows>0);	  
   }
   
   function getDataVMpoll($where)
   {
      $vtbvmpoll = new tb_gen('vw_poll');  
	  $data = $vtbvmpoll->getData($where); 
	 
	  $this->numrows=$vtbvmpoll->numrows;
      	 
	  return $data;		   
   
   }
   
   function getDataVMpoll1($where)
   {
      $vtbvmpoll1 = new tb_gen('vw_poll1');  
	  $data = $vtbvmpoll1->getData($where); 
	 
	  $this->numrows=$vtbvmpoll1->numrows;
      	 
	  return $data;		   
   
   }
   
    function getDataadminVDpoll($thn,$sem,$shift,$kelas,$kdkmk)
    {  
      $data = $this->getDataDpoll("thsmsdpoll=".$thn." and semdpoll='".$sem."' and shiftdpoll='".$shift."' and kelasdpoll='".$kelas."' and kdkmkdpoll='".$kdkmk."'");
	  $temp_data=array();
	  
	  if(!empty($data)){
	    
	   foreach($data as $row)
	   {
	     if(!isset($temp_data[$row['nopolldpoll']][$row['jwbdpoll']])) {  
		  $temp_data[$row['nopolldpoll']][$row['jwbdpoll']]=1;
		 }else{
           $temp_data[$row['nopolldpoll']][$row['jwbdpoll']]+=1;
         }		 
	   
	   }
	  
	  }
	  
	  return $temp_data;
	} 
   function getDataadminVMpoll()
   {
     $data = $this->getDataVMpoll('');
	 
	 $temp_data=array();
	 $jml=array();
	 $jmlisi=array();
	 
	 if(!empty($data))
	 {
	   $idx_new='';
	   $idx_old=$idx_new;
	   foreach($data as $row)
	   {
        $idx_new=$row['thsmsmpoll'].$row['semmpoll'].$row['shiftmpoll'].$row['kdkmkmpoll'].$row['kddspengajar'];  	    
        
		if(!isset($temp_data[$idx_new])){
		     $link="frm_hsl_kuosioner.php?thn=".$row['thsmsmpoll']."&sem=".$row['semmpoll']."&shift=".$row['shiftmpoll']."&kelas=".$row['kelasmpoll']."&kdkmk=".$row['kdkmkmpoll']."&nmkmk=".$row['nakmktbkmk']."&kdds=".$row['kddspengajar']."&nmds=".$row['nama'];
		     $temp_data[$idx_new] = array(array($row['thsmsmpoll'],array()),
								  array($row['semmpoll'],array()),
								  array($row['shiftmpoll']=='R' ? 'Reguler' : 'Non Reguler',array()),
								  array($row['kdkmkmpoll'],array()),
								  array($row['nakmktbkmk'],array()),
								  array($row['kddspengajar'],array()),
								  array($row['nama'],array()),
								  array(0,array('align'=>'right')),
								  array(0,array('align'=>'right')),
								  array("<a href='$link'>View</a>",array('align'=>'center')));
            $jml[$idx_new]=1;
			$jml_isi[$idx_new]=$row['isimpoll']==1 ? 1 : 0 ;
			
          if(isset($temp_data[$idx_old])){  
			$temp_data[$idx_old][7][0] = $jml[$idx_old];
			$temp_data[$idx_old][8][0] = $jml_isi[$idx_old];			
			}
			$idx_old=$idx_new;			
        }else{
          $jml[$idx_old]=$jml[$idx_old]+1;
		  $jml_isi[$idx_old]=$row['isimpoll']==1 ? $jml_isi[$idx_old]+1 : $jml_isi[$idx_old] ;
		}   
		
	   }
         if(isset($temp_data[$idx_old])){  
			$temp_data[$idx_old][7][0] = $jml[$idx_old];
            $temp_data[$idx_old][8][0] = $jml_isi[$idx_old];			
			}	   
	   
	 }
	
     return $temp_data;
   }
   function getDataadminVMpoll1()
   {
     $data = $this->getDataVMpoll1('');
	 
	 $temp_data=array();
	 $jml=array();
	 $jmlisi=array();
	 
	 if(!empty($data))
	 {
	   $idx_new='';
	   $idx_old=$idx_new;
	   foreach($data as $row)
	   {
        $idx_new=$row['thsmsmpoll'].$row['semmpoll'].$row['shiftmpoll'].$row['kdkmkmpoll'].$row['kdds'];  	    
        
		if(!isset($temp_data[$idx_new])){
		     $link="frm_hsl_kuosioner.php?thn=".$row['thsmsmpoll']."&sem=".$row['semmpoll']."&shift=".$row['shiftmpoll']."&kelas=".$row['kelasmpoll']."&kdkmk=".$row['kdkmkmpoll']."&nmkmk=".$row['nakmktbkmk']."&kdds=".$row['kdds']."&nmds=".$row['nama'];
		     $temp_data[$idx_new] = array(array($row['thsmsmpoll'],array()),
								  array($row['semmpoll'],array()),
								  array($row['shiftmpoll']=='R' ? 'Reguler' : 'Non Reguler',array()),
								  array($row['kdkmkmpoll'],array()),
								  array($row['nakmktbkmk'],array()),
								  array($row['kdds'],array()),
								  array($row['nama'],array()),
								  array(0,array('align'=>'right')),
								  array(0,array('align'=>'right')),
								  array("<a href='$link'>View</a>",array('align'=>'center')));
            $jml[$idx_new]=1;
			$jml_isi[$idx_new]=$row['isimpoll']==1 ? 1 : 0 ;
			
          if(isset($temp_data[$idx_old])){  
			$temp_data[$idx_old][7][0] = $jml[$idx_old];
			$temp_data[$idx_old][8][0] = $jml_isi[$idx_old];
			
			}
			$idx_old=$idx_new;			
        }else{
          $jml[$idx_old]=$jml[$idx_old]+1;
		  $jml_isi[$idx_old]=$row['isimpoll']==1 ? $jml_isi[$idx_old]+1 : $jml_isi[$idx_old] ;
		}   
		
	   }
         if(isset($temp_data[$idx_old])){  
			$temp_data[$idx_old][7][0] = $jml[$idx_old];
            $temp_data[$idx_old][8][0] = $jml_isi[$idx_old];			
			}	   
	   
	 }
     return $temp_data;
   }
   
   function getDataMpoll($where)
    {	  
	  $vtbmpoll = new tb_gen('tbmpoll');  
	  $data = $vtbmpoll->getData($where); 
	 
	  $this->numrows=$vtbmpoll->numrows;
      	 
	  return $data;		 
	  	  
	}   
	
	 function getDataDpoll($where)
    {	  
	  $vtbdpoll = new tb_gen('tbdpoll');  
	  $data = $vtbdpoll->getData($where); 
	 
	  $this->numrows=$vtbdpoll->numrows;
      	 
	  return $data;		 
	  	  
	} 

    function updateDataMpoll($thn,$kdkmk,$nim)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'isimpoll'=>1);
	  $vtbmpoll->updateRecord($data);
	
	  return 0;
	}
	
	function gantikelasMpoll($thn,$kdkmk,$nim,$kelas)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $today = date("Y-m-d H:i:s");
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'shiftmpoll'=>$kelas,'tgl_input'=>$today);
	  $vtbmpoll->updateRecord($data);
	
	  return 0;
	}
	
	function gantikelasmhsMpoll($thn,$kdkmk,$nim,$kelas)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $today = date("Y-m-d H:i:s");
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'kelasmpoll'=>$kelas,'tgl_input'=>$today);
	  $vtbmpoll->updateRecord($data);
	
	  return 0;
	}
	
	function gantisemmhsMpoll($thn,$kdkmk,$nim,$sem)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $today = date("Y-m-d H:i:s");
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'semmpoll'=>$sem,'tgl_input'=>$today);
	  $vtbmpoll->updateRecord($data);
	
	  return 0;
	}	
	
	function deleteDataMpoll($thn,$kdkmk,$nim)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'isimpoll'=>1);
	  $vtbmpoll->deleteRecord($data);
	
	  return 0;
	}
	
	function insertDataMpoll($thn,$nim,$sem,$shift,$kelas,$kdkmk)
	{
	  $vtbmpoll = new tb_gen('tbmpoll');
	  $today = date("Y-m-d H:i:s");
	  $data=array('thsmsmpoll'=>$thn,'kdkmkmpoll'=>$kdkmk,'nimhsmpoll'=>$nim,'isimpoll'=>0,'semmpoll'=>$sem,'kelasmpoll'=>$kelas,'shiftmpoll'=>$shift,'tgl_input'=>$today);
	  $vtbmpoll->insertRecord($data);    
	 
	  return 0; 
	}
	
    function insertDataDpoll($thn,$sem,$shift,$kelas,$kdkmk,$poll)
	{
	  $vtbdpoll = new tb_gen('tbdpoll');
	  
	  $iddpoll = date("YmdHis");
	  
      foreach($poll as $no=>$v){	  
		  $today = date("Y-m-d H:i:s");
		  $data=array('iddpoll'=>$iddpoll,'thsmsdpoll'=>$thn,'kdkmkdpoll'=>$kdkmk,'shiftdpoll'=>$shift,'kelasdpoll'=>$kelas,'semdpoll'=>$sem,'nopolldpoll'=>$no,'jwbdpoll'=>$v,'tgl_input'=>$today);
	      $vtbdpoll->insertRecord($data);
      }	  
	  return 0;
	}
	
	
	
}


?>