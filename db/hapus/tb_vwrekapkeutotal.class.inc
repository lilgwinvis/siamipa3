<?php
require_once 'default_table.class.inc';
class tb_vwrekapkeutotal extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        
        $this->sql_select ='thn,danamasuk,jmlajuan,surflus,defisit';        
        $this->sql_from ='vw_rekapkeutotal';
		$this->sql_orderby='thn';		
        $this->fieldlist       = $this->getfieldlist(); 
		//$this->fieldlist       = array('thn','danamasuk','jmlajuan','surflus','defisit');
              
				
    } // end class constructor

} // end class


?>