<?php
require_once 'default_table.class.inc';
class tb_vwrekapstatmhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'vw_rekapstatmhs';
        //$this->dbname        = 'siafmipa';
        $this->sql_orderby     ='tahunmsmhs asc,thnsmsstat_mhs desc';
		
		$this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thnsmsstat_mhs', 'tahunmsmhs', 'statstat_mhs','rekapstat');
        
				
    } // end class constructor

} // end class
?>