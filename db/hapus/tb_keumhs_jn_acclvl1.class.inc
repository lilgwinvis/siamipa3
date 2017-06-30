<?php
require_once 'default_table.class.inc';
class tb_keumhs_jn_acclvl1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='nimkeumhs,acclvl1keumhs,nmacclvl1,pengalikeumhs';
        $this->sql_from ='keumhs INNER JOIN acclvl1 ON acclvl1keumhs=noacclvl1';
        $this->sql_orderby='nimkeumhs,nmacclvl1';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('nimkeumhs','acclvl1keumhs','nmacclvl1','pengalikeumhs');
              
				
    } // end class constructor

} // end class
