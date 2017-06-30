<?php
 require_once 'shared.php';
   
class dt_cetak 
{     
    
  function __construct()
  {
   
  }

  function get_dt_jdwl_klh()
  {
   $tb_jdwl_klh = new tb_gen('vw_jdwlklh'); 
   $where = "disetujui=1"; 
   $data = $tb_jdwl_klh->getData($where); 
   return $data;
  }
  
  function get_dt_kartu()
  {
      $vkrs_mhs = new tb_gen('vw_krs_jn_mhs');
      $vkrs_mhs->sql_select  = 'distinct thsmskrs,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs,semkrs,kelaskrs';
	  $vkrs_mhs->sql_groupby = 'thsmskrs,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs';
      $vkrs_mhs->sql_orderby = 'tahunmsmhs,nimhskrs';
	  $where = "kdkmkkrs not in ('UBB106','MAT352','MAT353') ";
	  $data = $vkrs_mhs->getData($where);
	  
      return $data;
  }
  
  
}

?>  