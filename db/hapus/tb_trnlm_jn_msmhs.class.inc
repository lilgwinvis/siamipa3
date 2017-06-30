<?php
require_once 'default_table.class.inc';
class tb_trnlm_jn_msmhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='thsmstrnlm,semestrnlm,kdkmktrnlm,shifttrnlm,kelastrnlm,nimhstrnlm,nmmhsmsmhs,tahunmsmhs,trim(nlakhtrnlm) as nlakhtrnlm';
        $this->sql_from ='trnlm INNER JOIN msmhs ON nimhstrnlm=nimhsmsmhs';
        $this->sql_orderby='thsmstrnlm,shifttrnlm,kdkmktrnlm,tahunmsmhs';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('thsmstrnlm','semestrnlm','kdkmktrnlm','shifttrnlm','kelastrnlm','nimhstrnlm','nmmhsmsmhs','tahunmsmhs','nlakhtrnlm');
              
				
    } // end class constructor

} // end class