<?php

require_once 'shared.php';

class dt_trkeumhs 
{

   function __construct(){
   
   }
   
   function gettrkeumhs($nim)
   {
     $tb=new tb_gen('vw_trkeumhs_jn_acclvl1');
	 $where = "trkeumhsnim='$nim'";
	 $data = $tb->getData($where);
     return $data;
   }
   
   function getnoacclvl1($nim)
   {
    	 
	 $tb_keumhs=new tb_gen('vw_keumhs_jn_acclvl1'); 
	 $where ="nimkeumhs='$nim'";
	 
	 $data = $tb_keumhs->getData($where);
     return $data;
   
   }
   
   function getbyr($nim,$tgl,$kd)
   {
     $tb_trkeumhs=new tb_gen('trkeumhs'); 
	 $where ="trkeumhsnim='$nim' and trkeumhstgl='$tgl' and trkeumhsacclvl1=$kd";
	 
	 $data = $tb_trkeumhs->getData($where);
	 
	 $byr=0.00;
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	     $byr=$row['trkeumhsbayar'];
	   }
	 }
	 
     return $byr;
   
   }
   
   
   function getket($nim,$tgl,$kd)
   {
     $tb_trkeumhs=new tb_gen('trkeumhs'); 
	 $where ="trkeumhsnim='$nim' and trkeumhstgl='$tgl' and trkeumhsacclvl1=$kd";
	 
	 $data = $tb_trkeumhs->getData($where);
	 
	 $ket="";
	 if(!empty($data))
	 {
	   foreach($data as $row)
	   {
	     $ket=$row['trkeumhsket'];
	   }
	 }
	 
     return $ket;
   
   }
   
   function tambah($nim,$datepicker,$acc,$bayar,$ket)
   {
      
	   $tb_trkeumhs = new tb_gen('trkeumhs'); 
	   $tb_trkeumhs->insertRecord(array('trkeumhsnim'=>$nim,'trkeumhstgl'=>$datepicker,'trkeumhsacclvl1'=>$acc,'trkeumhsbayar'=>$bayar,'trkeumhsket'=>$ket));
	   return 1;
   }
   
   function edit($nim,$tgl,$acc,$bayar,$ket,$id)
   {
       $tb_trkeumhs = new tb_gen('trkeumhs'); 
	   $tb_trkeumhs->updateRecord(array('ID'=>$id,'trkeumhsnim'=>$nim,'trkeumhstgl'=>$tgl,'trkeumhsacclvl1'=>$acc,'trkeumhsbayar'=>$bayar,'trkeumhsket'=>$ket));
	   return 1;
   }
   
   function hapus($plh,$nim)
   {
     $tb_trkeumhs = new tb_gen('trkeumhs');
      
      if(!empty($plh))
      {
	     foreach($plh as $idx)
		 {
		  $tb_trkeumhs->deleteRecord(array('trkeumhsnim'=>$nim,'ID'=>$idx));
		 }
	  }	  
       	  
	  return 1;
   }


	function hitung($nim)
	{
		$txt='Masuk Hitung'; 
        
        $dt = new dt_tot_trkeumhs;   		
	    $dt_tot = $dt->gettottrkeumhs($nim);
	      		
	    $dt_tran = $this->gettrkeumhs($nim);
        
        $lebih=array();
        $kurang=array();
        $tot_byr = 0;
        if(!empty($dt_tot))
        {
        	foreach ($dt_tot as $row) {
        	  if($row['acclvl1keumhs']>1){	
        		if(($row['wajibByr']>0) and ($row['wajibByr']<$row['jmlbyr']))
        		{
                  $lebih[$row['acclvl1keumhs']]= array('wajibByr'=>$row['wajibByr'],'jmlbyr'=>$row['jmlbyr'],'lebih'=>($row['jmlbyr']-$row['wajibByr']));
        		}elseif(($row['wajibByr']>$row['jmlbyr']) and ($row['wajibByr']>0)){
                  $kurang[$row['acclvl1keumhs']]= array('nm'=>$row['nmacclvl1'],'wajibByr'=>$row['wajibByr'],'jmlbyr'=>$row['jmlbyr'],'kurang'=>($row['wajibByr']-$row['jmlbyr']));
        		}
              }
        		$tot_byr=$tot_byr+$row['jmlbyr'];
        	}
        }

       
        
        if(!empty($lebih) and !empty($dt_tran))
        {
          $jml=array();
          foreach ($dt_tran as $row) {
          	if(isset($lebih[$row['trkeumhsacclvl1']]))
          	{
              $jml[$row['trkeumhsacclvl1']] = isset($jml[$row['trkeumhsacclvl1']]) ? $jml[$row['trkeumhsacclvl1']]+$row['trkeumhsbayar']: $row['trkeumhsbayar'];
              

              if($lebih[$row['trkeumhsacclvl1']]['wajibByr']<$jml[$row['trkeumhsacclvl1']])
              {
                 
                 $selisih =0;
                 
                 if ($row['trkeumhsbayar']>($lebih[$row['trkeumhsacclvl1']]['wajibByr']-($jml[$row['trkeumhsacclvl1']]-$row['trkeumhsbayar']))) {
                   
                   $jml_byr=$lebih[$row['trkeumhsacclvl1']]['wajibByr']-($jml[$row['trkeumhsacclvl1']]-$row['trkeumhsbayar']);
                   $selisih=$row['trkeumhsbayar']-($lebih[$row['trkeumhsacclvl1']]['wajibByr']-($jml[$row['trkeumhsacclvl1']]-$row['trkeumhsbayar']));     
                 }                  
                  
                 

                   if(!empty($kurang))
                   {
                   	 foreach ($kurang as $key => $value) {
                   	   if(($value['kurang']>0) and ($selisih>0)){
	                   	   $jml_byr1=0;
	                   	   if($selisih<=$value['kurang']){
	                         $jml_byr1=$selisih;
	                         $kurang[$key]['kurang']=$kurang[$key]['kurang']-$selisih; 
	                         $selisih=0;     
	                   	   }elseif ($selisih>$value['kurang']) {
	                   	   	 $jml_byr1=$value['kurang'];
	                         $kurang[$key]['kurang']=0; 
	                         $selisih=$selisih-$value['kurang'];
	                   	   }
                          
                          if($jml_byr1>0){ 
                            
                            $this->edit($nim,$row['trkeumhstgl'],$row['trkeumhsacclvl1'],$jml_byr,$row['trkeumhsket'].' perbaikan trans.',$row['ID']);
	                        $this->tambah($nim,$row['trkeumhstgl'],$key,$jml_byr1,$value['nm'].' perbaikan trans.');
	                      }       
                      }
                   	 }

                   	 if($selisih>0){
                   	 	
                   	    $this->edit($nim,$row['trkeumhstgl'],$row['trkeumhsacclvl1'],($jml_byr+$selisih),$row['trkeumhsket'].' perbaikan trans.',$row['ID']);
                      }
                   
                   }

                   

              }
              
          	}
          }
        }
         
	    return $txt;
	}	
}


?>