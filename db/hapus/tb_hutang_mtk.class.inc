<?php
require_once 'default_table.class.inc';
class tb_hutang_mtk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        
        $this->sql_select ='thnsmspengajar,kddspengajar,kdkmkpengajar,nakmktbkmk,shiftpengajar,semespengajar,kelaspengajar,wp';
        //$this->sql_from ="(pengajar INNER JOIN (SELECT thsmstrnlm,kdkmktrnlm,shifttrnlm,semestrnlm,kelastrnlm FROM trnlm WHERE nlakhtrnlm='T' GROUP BY thsmstrnlm,kdkmktrnlm,shifttrnlm,semestrnlm,kelastrnlm) a ON thnsmspengajar=thsmstrnlm AND kdkmkpengajar=kdkmktrnlm AND shiftpengajar=shifttrnlm AND semespengajar=semestrnlm and kelaspengajar=kelastrnlm) INNER JOIN tbkmk ON kdkmktbkmk=kdkmkpengajar";
        $this->sql_from ="vw_tbhutangmtk";
		$this->sql_orderby='thnsmspengajar,kddspengajar,kdkmkpengajar';  
		
		$this->fieldlist       = $this->getfieldlist(); 
		
        //$this->fieldlist       = array('thnsmspengajar','kddspengajar','kdkmkpengajar','nakmktbkmk','shiftpengajar','semespengajar','wp');
              
				
    } // end class constructor

} // end class


?>