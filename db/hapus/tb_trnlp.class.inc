<?php
require_once 'default_table.class.inc';
class tb_trnlp extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'trnlp';
        //$this->dbname          = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thsmstrnlp', 'nimhstrnlp', 'kdkmktrnlp', 'nlakhtrnlp', 'bobottrnlp', 'kelastrnlp');
        $this->fieldlist['thsmstrnlp'] = array('pkey' => 'y');
		$this->fieldlist['nimhstrnlp'] = array('pkey' => 'y');
		$this->fieldlist['kdkmktrnlp'] = array('pkey' => 'y');
		
		
				
    } // end class constructor

} // end class
?>