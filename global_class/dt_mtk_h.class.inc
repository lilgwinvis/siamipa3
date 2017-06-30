<?php

require_once 'shared.php';


class dt_mtk_h 
{
  var $vmtk; 
  
  function __construct(){
     $this->vmtk=new tb_mtk_h;	 
   }
  
  function getData($where)
   {
     $data = $this->vmtk->getData($where);
     return $data;  
   }
   
   function salin($thn1,$thn2)
   {   
      $this->vmtk->export_record('tbkmk_h','THSMSTBKMK,KDPTITBKMK,KDJENTBKMK,KDPSTTBKMK,KDKMKTBKMK,NAKMKTBKMK,SKSMKTBKMK,SKSTMTBKMK,SKSPRTBKMK,SKSLPTBKMK,SEMESTBKMK,KDWPLTBKMK,KDKURTBKMK,KDKELTBKMK,NODOSTBKMK,STKMKTBKMK,SLBUSTBKMK,SAPPPTBKMK,BHNAJTBKMK,DIKTTTBKMK',$thn2.',KDPTITBKMK,KDJENTBKMK,KDPSTTBKMK,KDKMKTBKMK,NAKMKTBKMK,SKSMKTBKMK,SKSTMTBKMK,SKSPRTBKMK,SKSLPTBKMK,SEMESTBKMK,KDWPLTBKMK,KDKURTBKMK,KDKELTBKMK,NODOSTBKMK,STKMKTBKMK,SLBUSTBKMK,SAPPPTBKMK,BHNAJTBKMK,DIKTTTBKMK','thsmstbkmk='.$thn1);
   }
   
}

?>