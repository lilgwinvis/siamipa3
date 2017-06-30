<?php
require_once 'default_table.class.inc';
class tb_trnlp_trnlm_jn_mtk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='thsmstrnlm,nimhstrnlm,kdkmktrnlm,nakmktbkmk,sksmktbkmk,nlakhtrnlm,bobottrnlm,wp,semestbkmk';
        //$this->sql_from ='trnlm_trnlp INNER JOIN tbkmk ON kdkmktrnlm=kdkmktbkmk ';
		$this->sql_from ='vw_tbtrnlptrnlmjnmtk';
        $this->sql_orderby='thsmstrnlm,semestbkmk,kdkmktrnlm';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thsmstrnlm','nimhstrnlm','kdkmktrnlm','nakmktbkmk','sksmktbkmk','nlakhtrnlm','bobottrnlm','wp','semestbkmk');
              
				
    } // end class constructor

} // end class
?>