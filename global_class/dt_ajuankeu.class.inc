<?php
require_once 'shared.php';
class dt_ajuankeu {
    
	var $numrows;
	
	function __construct() {
		
	}
	function getData($where)
   {
     $tb = new tb_gen('tbajuankeu');	 
	 $data = $tb->getData($where);
	 $this->numrows=$tb->numrows;
     return $data;	 
   }
   
   function getvwdtajuankeu($where)
   {
     $tb = new tb_gen('vw_ajuankeu');	 
	 $data = $tb->getData($where);
	 $this->numrows=$tb->numrows;
     return $data;	 
   }
   
   function getidajuan($thn)
   {
	  $tb = new tb_gen('vw_idterakhir');
      $data = $tb->getData("thn=$thn");	  
	  
	  if($tb->numrows>0)
	  {
		foreach($data as $row)
        {
		  $idajuan=$row['id'];	
		}
          $idajuan=$idajuan+1;		
	  }else{
		 $idajuan=$thn.'001'; 
	  }	  
	  
	  
      return $idajuan;	  
   }
   
   
   function tambah($tglajuan,$noajuan,$perihalajuan,$jmlajuan,$tglcair,$jmlcair,$tgllpj,$dilpjkan,$dibagikan,$accoutlvl1)
   {
        $tb = new tb_gen('tbajuankeu');
		
		$new_data = array();
		if(!empty($tglajuan)){
		 $new_data['tglajuan']=$tglajuan;
		}
		if(!empty($tglcair)){
		 $new_data['tglcair']=$tglcair;
		}
		if(!empty($tgllpj)){
		 $new_data['tgllpj']=$tgllpj;
		}
		
		$thn=str_split($tglajuan, 4);				
		$new_data['idajuan']=$this->getidajuan($thn[0]);
		$new_data['noajuan']=$noajuan;
		$new_data['perihalajuan']=$perihalajuan;
		$new_data['jmlajuan']=$jmlajuan;
		$new_data['jmlcair']=$jmlcair;
		$new_data['dilpjkan']=$dilpjkan;
		$new_data['dibagikan']=$dibagikan;
		$new_data['accoutlvl1']=$accoutlvl1;
		
		$today = date("Y-m-d");
		$new_data['tgl_input']=$today;
		
		
		
		$tb->insertRecord($new_data);
	    return 1;
	  
   }
   
   function edit($idajuan,$tglajuan,$noajuan,$perihalajuan,$jmlajuan,$tglcair,$jmlcair,$tgllpj,$dilpjkan,$dibagikan,$accoutlvl1)
   {
     $tb = new tb_gen('tbajuankeu');
		
		$new_data = array();
		if(!empty($tglajuan)){
		 $new_data['tglajuan']=$tglajuan;
		}
		if(!empty($tglcair)){
		 $new_data['tglcair']=$tglcair;
		}
		if(!empty($tgllpj)){
		 $new_data['tgllpj']=$tgllpj;
		}
		$new_data['idajuan']=$idajuan;
		$new_data['noajuan']=$noajuan;
		$new_data['perihalajuan']=$perihalajuan;
		$new_data['jmlajuan']=$jmlajuan;
		$new_data['jmlcair']=$jmlcair;
		$new_data['dilpjkan']=$dilpjkan;
		$new_data['dibagikan']=$dibagikan;
		$new_data['accoutlvl1']=$accoutlvl1;
		
		$today = date("Y-m-d");
		$new_data['tgl_input']=$today;
		
		$tb->updateRecord($new_data);
	    return 1;
   
   }
   
   function getaccoutlvl1()
   {
      $tb = new tb_gen('accoutlvl1');
	  $data = $tb->getData('');
	  $tmp_data = array();
	  
      if(!empty($data))
      {
		  foreach($data as $row)
		  {
		     $tmp_data[$row['noaccoutlvl1']]=$row['nmaccoutlvl1'];	  
		  }
		  
	  }	  
      return $tmp_data;
   }
   
   function hapus($plh)
   {
   
   
   }
   
}
?>