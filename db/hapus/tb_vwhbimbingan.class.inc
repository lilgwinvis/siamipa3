<?php
require_once 'default_table.class.inc';
class tb_vwhbimbingan extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_hbimbingan';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thsmstrnlm','nimhstrnlm','nmmhsmsmhs','idbimbingan','thsmsbimbingan','nimhsbimbingan','temabimbingan','tglsrttgs','tglsk','nosrttgs','nosk','tgl_input');
               
			
    } // end class constructor

} // end class


?>