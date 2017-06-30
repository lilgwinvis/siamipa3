<?php
require_once 'default_table.class.inc';
class tb_vwsemjdwl extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'sem,hariklh';
		$this->tablename       = 'vw_semjdwl';
       	$this->fieldlist       = array('sem','hariklh','bentrok');
		$this->sql_orderby         = 'sem,hariklh';	
    } // end class constructor

} // end class


?>