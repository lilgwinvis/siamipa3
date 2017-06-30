<?php
require_once 'shared.php';

class dt_jdwl_klh 
{     
  var $tb_jdwl_klh;
  
  function __construct(){
    $this->tb_jdwl_klh = new tb_gen('vw_jdwlklh');
	$this->tb_riwayat_jdwl_klh = new tb_gen('riwayat_jdwl_klh');
  }
   
   
   function buildjdwlklh()
    {	  
	  $where = "disetujui=1"; 
      $data = $this->tb_jdwl_klh->getData($where); 
	  return $data;
	}	
	
	
	function timetosec($time)
	{
		$parsed = date_parse($time);
        $seconds = $parsed['hour'] * 3600 + $parsed['minute'] * 60 + $parsed['second'];
		return $seconds;
	}
	
	function selisih($awal,$akhir)
	{
		$selisih = ($this->timetosec($akhir)-$this->timetosec($awal))/60;
		return $selisih;
	}
	
	
	function cekbentrokdosen($kdds,$hariklh)
	{	  
	   $bentrok=false;
	   $data = $this->tb_jdwl_klh->getData("kdds='$kdds' AND hariklh=$hariklh and disetujui=1");
	   if(!empty($data))		  
	   {
			  $jawal_0=null;  
			  $selisih_0=null;
			  
			  foreach($data as $row)
			  {
				  
				  
				  if(!is_null($jawal_0))
				  {
					$selisih = $this->selisih($jawal_0,$row['jawalklh']);
					if($selisih<$selisih_0){
					  $bentrok=true;	
					}  
				  }
				  $selisih_0 = $this->selisih($row['jawalklh'],$row['jakhirklh']);
				  $jawal_0=$row['jawalklh'];
			  }
       } 		  
	   return $bentrok;
	}
	
	function cekbentroksem($sem,$hariklh)
	{
	   $bentrok=false;
	   $data = $this->tb_jdwl_klh->getData("sem='$sem' AND hariklh=$hariklh and disetujui=1");
       if(!empty($data))		  
	   {  
              $jawal_0=null;  
			  $selisih_0=null;
			  
			  foreach($data as $row)
			  {
				  
				  
				  if(!is_null($jawal_0))
				  {
					$selisih = $this->selisih($jawal_0,$row['jawalklh']);					
					if($selisih<$selisih_0){
						$bentrok=true;
					}  
				  }
				  $selisih_0 = $this->selisih($row['jawalklh'],$row['jakhirklh']);
				  $jawal_0=$row['jawalklh'];
			  }
       } 	
       return $bentrok;	   
	}
	
	
	function cekbentrok()
	{
	  $tb=new tb_gen('vw_kdssjdwl'); 
	  $data = $tb->getData('');
	  $temp = array();
	  
	  if(!empty($data))		  
	  {
		foreach($data as $row)
        {
		  if($this->cekbentrokdosen($row['kdds'],$row['hariklh']))
		  {
			$temp[$row['kdds']][$row['hariklh']]='p';  
		  }
 			  
		}		
	  }
	  
	  $tb=new tb_gen('vw_semjdwl');
	  $data = $tb->getData('');
	  
	  if(!empty($data))		  
	  {
		foreach($data as $row)
        {
		  if($this->cekbentroksem($row['sem'],$row['hariklh']))
          {
			$temp[$row['sem']][$row['hariklh']]='p';  
		  }		  
		}		
	  }
	  
	  
      return $temp;	  
	}
	
	
	function hitung_akhir()
    {
	  $dt = new dt_ksd_ngajar;
	  $data = $this->buildjdwlklh();
      if(!empty($data)){
        foreach($data as $row)
		{
		   $jawalklh=$row['jawalklh'];
		   $sksmktbkmk=$row['sksmktbkmk'];
		   $time = new DateTime($jawalklh);
		   $add_minute=($sksmktbkmk*50);
		   $time->modify('+'.$add_minute.'minutes');
		   $dt->update_jam_akhir($row['kdkmk'],$row['kdds'],$row['shift'],$row['sem'],$time->format('H:i:s'));
		}
      }	  
	}
	
	function buildriwayatjdwlklh($thsms)
    {	  
	  $where = "thsmstrnlm='$thsms'"; 
	  $data = $this->tb_riwayat_jdwl_klh->getData($where); 
	  return $data;
	}
	
	function buildhonor($stat,$per=4)
    {	  
	  if ($per==4){  
		$where = "disetujui=1 and Hstat in ($stat) and kdkmk not in ('MAT352','MAT353')"; 
	  }else
       {
	     $where = "disetujui=1 and Hstat in ($stat) and kdkmk not in ('MAT352','MAT353') and hnr='R'"; 
	   } 	  
	  $this->tb_jdwl_klh->sql_orderby='kdds,sem,hnr,kdkmk';
      $data = $this->tb_jdwl_klh->getData($where); 
	  return $data;
	}
	
	function buildpakasi($stat)
    {	  
	  $where = "disetujui=1 and shift='$stat' and kdkmk not in ('MAT352','MAT353')"; 
	  $this->tb_jdwl_klh->sql_orderby='kdds,sem,hnr,kdkmk';
      $data = $this->tb_jdwl_klh->getData($where); 
	  return $data;
	}
    
	function getTglterlama()
	{
	   $tb = new tb_gen('vw_jdwlklh');
	   $tb->sql_select = "MIN(tgl_input) AS tgllama";
	   $tb->sql_where = "disetujui=1";
	   $data=$tb->getData("");
	   
	   return $data;
	}
	function getTglterbaru()
	{
	   $tb = new tb_gen('vw_jdwlklh');
	   $tb->sql_select = "MAX(tgl_input) AS tglbaru";
	   $tb->sql_where = "disetujui=1";
	   $data=$tb->getData("");
	   
	   return $data;
	}
	
	function getRiwayatTglterlama()
	{
	   $tb = new tb_gen('riwayat_jdwl_klh');
	   $tb->sql_select = "MIN(tgl_input) AS tgllama";
	   $data=$tb->getData("");
	   
	   return $data;
	}
	function getRiwayatTglterbaru()
	{
	   $tb = new tb_gen('riwayat_jdwl_klh');
	   $tb->sql_select = "MAX(tgl_input) AS tglbaru";
	   $data=$tb->getData("");
	   
	   return $data;
	}
}

?>