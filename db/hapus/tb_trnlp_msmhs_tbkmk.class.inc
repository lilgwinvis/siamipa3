<?php
require_once 'default_table.class.inc';
class tb_trnlp_msmhs_tbkmk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        
		$this->sql_select = 'tahunmsmhs,nimhsmsmhs,nmmhsmsmhs,SUM(sksmktbkmk) AS jml_sks';
		$this->tablename  = '(trnlp RIGHT JOIN msmhs ON nimhstrnlp=nimhsmsmhs) LEFT JOIN tbkmk ON kdkmktbkmk=kdkmktrnlp';
        $this->sql_where  = 'bpmsmhs=1';
		$this->sql_groupby = 'tahunmsmhs,nimhsmsmhs,nmmhsmsmhs';
		//$this->dbname          = 'siafmipa';
        $this->fieldlist  = array('tahunmsmhs','nimhsmsmhs','nmmhsmsmhs','jml_sks');
		
				
    } // end class constructor

} // end class
?>