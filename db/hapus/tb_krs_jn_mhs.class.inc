<?php
require_once 'default_table.class.inc';
class tb_krs_jn_mhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'thsmskrs,nimhsmsmhs,nmmhsmsmhs,shiftmsmhs,tahunmsmhs';
		$this->tablename       = 'krs INNER JOIN msmhs ON nimhskrs=nimhsmsmhs';
       	$this->fieldlist       = array('thsmskrs','nimhsmsmhs','nmmhsmsmhs','shiftmsmhs','tahunmsmhs');
              
				
    } // end class constructor

} // end class


?>