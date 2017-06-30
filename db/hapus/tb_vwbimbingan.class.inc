<?php
require_once 'default_table.class.inc';
class tb_vwbimbingan extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_bimbingan';
        //$this->dbname          = 'siafmipa';
        //$this->fieldlist       = array('thsmskrs','nimhskrs','nmmhsmsmhs','idbimbingan','thsmsbimbingan','nimhsbimbingan','temabimbingan','tglsrttgs','tglsk','nosrttgs','nosk','tgl_input');
         $this->fieldlist       = $this->getfieldlist();       
			
    } // end class constructor

} // end class


?>