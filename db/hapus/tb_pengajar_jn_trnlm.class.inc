<?php
require_once 'default_table.class.inc';
class tb_pengajar_jn_trnlm extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        
        $this->sql_select ='thnsmspengajar,kdkmkpengajar,kddspengajar,shiftpengajar,nimhstrnlm,nlakhtrnlm,bobottrnlm';
        $this->sql_from ='pengajar INNER JOIN trnlm  ON thnsmspengajar=thsmstrnlm AND kdkmkpengajar=kdkmktrnlm AND shifttrnlm=shiftpengajar';
        
		
		
        $this->fieldlist       = array('thnsmspengajar','kdkmkpengajar','kddspengajar','shiftpengajar','nimhstrnlm','nlakhtrnlm','bobottrnlm');
              
				
    } // end class constructor

} // end class


?>