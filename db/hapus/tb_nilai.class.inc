<?php
require_once 'default_table.class.inc';
class tb_nilai extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
       //$this->sql_select ='thsmstrnlm,kdkmktrnlm,nakmktbkmk,semestrnlm,kelastrnlm,sum(bobottrnlm) as jml';
		//$this->sql_from  = 'trnlm INNER JOIN tbkmk ON kdkmktrnlm=kdkmktbkmk';
       // $this->sql_where  = "thsmstrnlm>=20111 AND kdkmktrnlm NOT LIKE 'MATP%' AND kdkmktrnlm NOT IN ('MAT352','MAT353')";
 	    //$this->sql_groupby  = 'thsmstrnlm,semestrnlm,kelastrnlm,kdkmktrnlm,nakmktbkmk';
		
		//$this->fieldlist  = array('thsmstrnlm','kdkmktrnlm','nakmktbkmk','semestrnlm','kelastrnlm');
        
		$this->sql_select ='thsmstrnlm,kdkmktrnlm,nakmktbkmk,nama,shifttrnlm,semestrnlm,kelastrnlm,jml';
		//$this->sql_from  = "(SELECT thsmstrnlm,kdkmktrnlm,nakmktbkmk,shifttrnlm,semestrnlm,kelastrnlm,SUM(bobottrnlm) AS jml FROM trnlm INNER JOIN tbkmk ON kdkmktrnlm=kdkmktbkmk WHERE thsmstrnlm>=20111 AND kdkmktrnlm NOT LIKE 'MATP%' AND kdkmktrnlm NOT IN ('MAT352','MAT353') GROUP BY thsmstrnlm,semestrnlm,kelastrnlm,shifttrnlm,kdkmktrnlm,nakmktbkmk) a INNER JOIN (SELECT thnsmspengajar,kddspengajar,nama,kdkmkpengajar,shiftpengajar,semespengajar,kelaspengajar FROM pengajar INNER JOIN tbdos ON kddspengajar=kode WHERE thnsmspengajar>=20111 ORDER BY thnsmspengajar) b ON thsmstrnlm=thnsmspengajar AND kdkmktrnlm=kdkmkpengajar AND shifttrnlm=shiftpengajar AND semestrnlm=semespengajar AND kelaspengajar=kelastrnlm";
        $this->sql_from  = "vw_tbnilai";
 	    $this->sql_orderby  = 'thsmstrnlm desc,semestrnlm,kelastrnlm,kdkmktrnlm,nama,shifttrnlm';
		
		$this->fieldlist  = array('thsmstrnlm','kdkmktrnlm','nakmktbkmk','semestrnlm','kelastrnlm');
		
				
    } // end class constructor

} // end class