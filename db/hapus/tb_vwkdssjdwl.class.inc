<?php
require_once 'default_table.class.inc';
class tb_vwkdssjdwl extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'kdds,hariklh';
		$this->tablename       = 'vw_kdssjdwl';
       	$this->fieldlist       = array('kdds','hariklh','bentrok');
		$this->sql_orderby         = 'kdds,hariklh';	
    } // end class constructor

} // end class


?>