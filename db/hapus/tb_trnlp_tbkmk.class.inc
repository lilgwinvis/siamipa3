<?php
require_once 'default_table.class.inc';
class tb_trnlp_tbkmk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select = 'semestbkmk,kdkmktrnlp,nakmktbkmk,sksmktbkmk,nlakhtrnlp,bobottrnlp,kelastrnlp';
		$this->tablename  = 'trnlp INNER JOIN tbkmk ON kdkmktbkmk=kdkmktrnlp';
        $this->sql_orderby = 'semestbkmk,kdkmktrnlp';
		//$this->dbname          = 'siafmipa';
        $this->fieldlist  = array('semestbkmk','kdkmktrnlp','nakmktbkmk','sksmktbkmk','nlakhtrnlp','bobottrnlp','kelastrnlp');
				
    } // end class constructor

} // end class
?>