<?php
require_once 'default_table.class.inc';
class tb_bimbingan extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'tbbimbingan';
        //$this->dbname        = 'siafmipa';
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist     = array('idbimbingan','thsmsbimbingan','nimhsbimbingan','temabimbingan','tglsrttgs','tglsk','nosrttgs','nosk','tglinput');
        //$this->fieldlist['idbimbingan'] = array('pkey' => 'y');
		    
			
    } // end class constructor

} // end class


?>