<?php
require_once 'default_table.class.inc';
class tb_vwnidnbim extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_nidnbim';
        //$this->dbname          = 'siafmipa';
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('nimhssidang','tgllls','tgl','bln','thn','akhbim','nidn_pemb1','nidn_pemb2','nimhstrnlm','sem','awlbim');
               
			
    } // end class constructor

} // end class


?>