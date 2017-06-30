<?php

 require_once 'shared.php';
 

class dt_stat_mhs 
{

   var $numrows;
   var $rows_per_page=0;
   var $pageno=0;
   
   
   
   function __construct(){
   }
   
   function getData($where)
   {
     $tb = new tb_gen('stat_mhs');
	 
	 $tb->pageno = $this->pageno;
	 $tb->rows_per_page = $this->rows_per_page;
	 
	 $data = $tb->getData($where);
     
	 $this->numrows = $tb->numrows;
	 
	 return $data;	 
   }
   
   function getnumrows()
   {
	   return $this->numrows;
   }
   
   function setpageno($pageno)
   {
	   $this->pageno = $pageno;
   }
   
   function setrows_per_page($rows_per_page)
   {
	   $this->rows_per_page = $rows_per_page;
   }
   
   function stattostr($kd)
   {
     switch($kd)
      {
      case 0 : return "Non Status";break;
	  case 1 : return "Aktif";break;
      case 2 : return "Cuti";break;
      case 3 : return "DO";break;
      case 4 : return "Keluar";break;
      case 5 : return "Lulus";break;
      case 6 : return "Non Aktif";break;
      }
   
   }
   
   function stattocd($kd)
   {
   
             switch($kd)
			  {
			  case 0 : return -1;break;
			  case 1 : return "A";break;
			  case 2 : return "C";break;
			  case 3 : return "D";break;
			  case 4 : return "K";break;
			  case 5 : return "L";break;
			  case 6 : return "N";break;
			  }
   
   }
   
   function getstatmhs($thn,$nim,$idx=0){
     
	   $tb = new tb_gen('stat_mhs');
	   $data = $tb->getData("thnsmsstat_mhs='$thn' and nimstat_mhs='$nim'");
	 
		 $stat = 0;
		 if(!empty($data)){
		   foreach($data as $row){
			$stat = $row['statstat_mhs'];
		   }
		 }
	 
	 if($idx==0)
	 {
	  return $this->stattostr($stat);
     }else{
	 	if($idx==1)
		{
		   return $this->stattocd($stat);  
		}else{
			return $stat;
        }		
	 }	 
   
   }
   
   
   function hmstd($data)
   {
        $vmythnsem = new mythnsem;
		$txtsemawal='';
		$semawal=0;
		$thnawal=2008;		
		$jmlcuti=0;
		$jmltolcuti=0;
		$jmlnoncuti=0;
		
		$hsl=array();
		
		if(!empty($data))
		{
		  $i=1;
		  foreach($data as $f=>$v)
		  {
		     			  
			  if($i==1){
			            $txtsemawal=$vmythnsem->gettxtthnsem($f);
				        $semawal=$f; 
                        $thnawal=$vmythnsem->getthn($f); 
				       }	
					   
			  if($v['kdstat']=='C')
			  {
			     if($i<=8){  
				   $jmlcuti=$jmlcuti+1;				   				   
				 } 
				
				if(($i<=14) and ($thnawal<=2010)){  
				   $jmltolcuti=$jmltolcuti+1;                    					 
				 } else {
				    if(($i<=10) and ($thnawal>2010) ){  
				        $jmltolcuti=$jmltolcuti+1;				       
					}
				}
				 
			  }else{
                 if(strpos("A N",$v['kdstat'])!==false)
			     {
				   $jmlnoncuti=$jmlnoncuti+1;
				 }
              } 	
			  $i=$i+1;		  
		  }
		
		}	
	 	
				
		$semakhir = $vmythnsem->gettxtthnsem($vmythnsem->addthnsem($semawal,7+$jmlcuti));		
		$tolsemakhir =  $vmythnsem->gettxtthnsem($vmythnsem->addthnsem($semawal,($thnawal<=2010 ? 13 : 9)+$jmltolcuti));
		
		$sembts = $vmythnsem->getsem($vmythnsem->addthnsem($semawal,7+$jmlcuti));
		$thnbts = $vmythnsem->getthn($vmythnsem->addthnsem($semawal,7+$jmlcuti));
        $tolsembts = $vmythnsem->getsem($vmythnsem->addthnsem($semawal,($thnawal<=2010 ? 13 : 9)+$jmltolcuti));		
		$tolthnbts = $vmythnsem->getthn($vmythnsem->addthnsem($semawal,($thnawal<=2010 ? 13 : 9)+$jmltolcuti));
		
		  $hsl['sawal']=$txtsemawal;
	      $hsl['sakhir']=$semakhir;	
		  $hsl['bstd']=(($sembts==2) ? 'Agustus '.($thnbts+1):'Februari '.($thnbts+1));
		  $hsl['tsakhir']=$tolsemakhir;
		  $hsl['tbstd']=(($tolsembts==2) ? 'Agustus '.($tolthnbts+1):'Februari '.($tolthnbts+1));
   
        return $hsl;
        
   }
   
   
   
   function getRStatMhs($nim,$thn=0)
   {
     $vmythnsem = new mythnsem;
	 $tb = new tb_gen('stat_mhs');
	 $tb->sql_orderby='nimstat_mhs,thnsmsstat_mhs';
       
	 if($nim!=""){	   
	      $data = $tb->getData("nimstat_mhs='".$nim."'");     
	 }else{
	   
	     $data = $tb->getData(""); 
	 }
	 
	 
	    $hsl = array(); 
	 			
		if(!empty($data))
		{	  
		  
             
          $obj = $this;
		  array_walk($data,function ($row,$key) use (&$hsl,$obj) {
			  $vmythnsem = new mythnsem;
			  $hsl[$row['nimstat_mhs']]['rstat'][$row['thnsmsstat_mhs']]['txt']=$vmythnsem->gettxtthnsem($row['thnsmsstat_mhs']);
			  $hsl[$row['nimstat_mhs']]['rstat'][$row['thnsmsstat_mhs']]['kdstat']=$obj->stattocd($row['statstat_mhs']);
			  $hsl[$row['nimstat_mhs']]['rstat'][$row['thnsmsstat_mhs']]['txtstat']=$obj->stattostr($row['statstat_mhs']);
			});
		  
	      	
			array_walk($hsl,function ($row,$f) use (&$hsl,$obj) {			
			  
			  $tmp=$obj->hmstd($row['rstat']);
			  
			  $hsl[$f]['sawal']=$tmp['sawal'];	         
			  $hsl[$f]['sakhir']=$tmp['sakhir'];	
		      $hsl[$f]['bstd']=$tmp['bstd'];
		      $hsl[$f]['tsakhir']=$tmp['tsakhir'];
		      $hsl[$f]['tbstd']=$tmp['tbstd'];
			
			});
		 
		
		}  
		
	 
	 return $hsl;
   }
   
   function getjmlaktif($nim)
   {
	  $tb = new tb_gen('stat_mhs'); 
	  $data = $tb->getData("nimstat_mhs='".$nim."' and statstat_mhs=1");
	  
	  $jml=0;
	  if(!empty($data))
	  {
		 foreach($data as $row) 
		 {
			 $jml++;
		 }
	  }
	  
	  return $jml;
   }
   
   function getAngkatan($thn)
   {
     $tb = new tb_gen('stat_mhs');
	 
	 $tb->sql_select="tahunmsmhs";
     $tb->sql_from="stat_mhs INNER JOIN msmhs ON nimstat_mhs=nimhsmsmhs";
	 $tb->sql_groupby="tahunmsmhs";
	 
	 $data = $tb->getData("thnsmsstat_mhs in ($thn)");
     return $data;
   }
   
   function getjmlmhs_jmlstat($thnsms,$thn,$kls)
   {
     
	 
	 $hitung=function ($stat) use ($thnsms,$thn,$kls)
			 {
				 $tb = new tb_gen('stat_mhs');
			 
				 $tb->sql_select="thnsmsstat_mhs,tahunmsmhs,shiftmsmhs,count(statstat_mhs) as jml";
				 $tb->sql_from="stat_mhs INNER JOIN msmhs ON nimstat_mhs=nimhsmsmhs";
				 $tb->sql_groupby="thnsmsstat_mhs,tahunmsmhs,shiftmsmhs";
				 
				 $txt_where = "thnsmsstat_mhs='$thnsms' and tahunmsmhs='$thn' and shiftmsmhs='$kls'";
				 $txt_where .=($stat!='T') ? "and statstat_mhs=$stat":''; 				 
				 
				 $data = $tb->getData($txt_where);
				 
				 return (!empty($data)) ? $data[0]['jml'] : 0;
				 
				 
			 }; 
	 
	 $jml = array();     
	 $jml['T']=$hitung('T');	   
	 $jml['1']=$hitung(1);
	 $jml['2']=$hitung(2);
	 $jml['3']=$hitung(3);
	 $jml['4']=$hitung(4);
	 $jml['5']=$hitung(5);
	 $jml['6']=$hitung(6);
	 	 
	 return $jml;
   }
   
   
   function tambah($thn,$stat)
   {
      $tb_stat_mhs = new tb_gen('stat_mhs'); 
	  
	  if(!empty($stat))
	  {
	    foreach($stat as $f=>$v)
		{
		 $tb_stat_mhs->insertRecord(array('thnsmsstat_mhs'=>$thn,'nimstat_mhs'=>$f,'statstat_mhs'=>$v));
		}
	  }
	  return 1;
   
   }
   function edit($thn,$stat)
   {
      $tb_stat_mhs = new tb_gen('stat_mhs'); 
	  
	  if(!empty($stat))
	  {
	    foreach($stat as $f=>$v)
		{
		 $tb_stat_mhs->updateRecord(array('thnsmsstat_mhs'=>$thn,'nimstat_mhs'=>$f,'statstat_mhs'=>$v));
		}
	  }
	  return 1;
   }
   function hapus($thn,$plh)
   {
      $tb_stat_mhs = new tb_gen('stat_mhs'); 
	  
	  if(!empty($plh))
	  {
	    foreach($plh as $f)
		{
		 $tb_stat_mhs->deleteRecord(array('thnsmsstat_mhs'=>$thn,'nimstat_mhs'=>$f));
		}
	  }
	  return 1;
   
   }
   
   function import($thnsms)
   {
      $tb = new tb_gen('stat_mhs');      
	  $tb->deleteAllRecord('thnsmsstat_mhs='.$thnsms);
	  $tmp = str_split($thnsms,4);
	  
      $ta = $tmp[1]==1 ? ($tmp[0]-1)."2" : $tmp[0]."1";	  
	  
	  $tb->export_record("stat_mhs","thnsmsstat_mhs,nimstat_mhs,statstat_mhs", $thnsms.",nimstat_mhs,statstat_mhs","thnsmsstat_mhs=".$ta);
   }
   
   function getdtchart()
   {
    $mythnsem = new mythnsem;
    $tb = new tb_gen('vw_rekapstatmhs');
	
	$data = $tb->getData('thnsmsstat_mhs="'.$mythnsem->getthnsem().'" and statstat_mhs=1');
	$tmparr=($tb->numrows>0) ? array_map(function ($row){ return array('label'=>$row['tahunmsmhs'],'y'=>intval($row['rekapstat']));},$data) : array();
	$chartdata[] = array('type'=>"column",'dataPoints'=>$tmparr);
	
	return $chartdata;	
   }
   
   function getdtchart1()
   {
    $mythnsem = new mythnsem;
    $tb = new tb_gen('vw_rekapstatmhs');
	
	$data = $tb->getData('statstat_mhs=1');
	$chartdata=array();
	$tmp=array();	
	$thnarr=array();
	$chartdata=array();
	if($tb->numrows>0){
	  
	  $thn_arr=array_unique(array_column($data, 'tahunmsmhs'));
	  asort($thn_arr);  
	  
	  $thn_stat_arr=array_unique(array_column($data, 'thnsmsstat_mhs'));
	  arsort($thn_stat_arr);
	  
	  array_walk($thn_arr,function ($angkatan,$key) use (&$tmp,$thn_stat_arr){	            
			array_walk($thn_stat_arr,function ($thn,$key1) use (&$tmp,$angkatan){
	            $tmp[$angkatan][$thn]=0;				
	        });	
	  });
	  	  
	  array_walk($data,function ($row,$key) use (&$tmp){$tmp[$row['tahunmsmhs']][$row['thnsmsstat_mhs']]=$row['rekapstat'];});
	        		  
	  array_walk($tmp,function ($arrrekap,$angkatan) use (&$chartdata){
	  	   
		   $angk=array();		   
		   array_walk($arrrekap, function ($rekap,$semester) use (&$angk){			 
				 $angk[]=array('label'=>"$semester",'y'=>intval($rekap)); 
				 });		 	
			
		      $tmp_chart=array('type'=>"stackedBar",'showInLegend'=>'true','name'=>"$angkatan",'dataPoints'=>$angk);		
		      $chartdata[]=$tmp_chart;			
	  });	
	}
       
	   return $chartdata;	
   }
   
   function getdtchart2()
   {
    $mythnsem = new mythnsem;
    $tb = new tb_gen('vw_rekapstatmhs');
	
	$data = $tb->getData('');
	$chartdata=array();
	$tmp=array();	
	$thnarr=array();
	if($tb->numrows>0){
	  	  
	  $stat_arr=array_unique(array_column($data, 'statstat_mhs'));
	  asort($stat_arr);  
	  
	  $thn_stat_arr=array_unique(array_column($data, 'thnsmsstat_mhs'));
	  arsort($thn_stat_arr);
	  
	  
	  array_walk($stat_arr,function ($stat,$key) use (&$tmp,$thn_stat_arr){	            
			array_walk($thn_stat_arr,function ($thn,$key1) use (&$tmp,$stat){
	            $tmp[$stat][$thn]=0;				
	        });	
	  });
	  
	  array_walk($data,function ($row,$key) use (&$tmp){$tmp[$row['statstat_mhs']][$row['thnsmsstat_mhs']]+=$row['rekapstat'];});
	  
	   array_walk($tmp,function ($arrrekap,$stat) use (&$chartdata){
	       $angk=array();		   
		   array_walk($arrrekap, function ($rekap,$semester) use (&$angk){			 
				 $angk[]=array('label'=>"$semester",'y'=>intval($rekap)); 
				 });
			
		      $tmp_chart=array('type'=>"stackedBar",'showInLegend'=>'true','name'=>"'".$this->stattostr($stat)."'",'dataPoints'=>$angk);		
		      $chartdata[]=$tmp_chart;			
	  });	
	}
       
	   return $chartdata;	
   }
   

}


?>