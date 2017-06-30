<?php
require_once 'default_table.class.inc';
class tb_keuangk_jn_acclvl1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='angkkeuangk,shiftkeuangk,noacclvl1keuangk,nmacclvl1,jmlbyrkeuangk';
        $this->sql_from ='keuangk INNER JOIN acclvl1 ON noacclvl1keuangk=noacclvl1';
        $this->sql_orderby='angkkeuangk,shiftkeuangk,noacclvl1keuangk';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('angkkeuangk','shiftkeuangk','noacclvl1keuangk','nmacclvl1','jmlbyrkeuangk');
              
				
    } // end class constructor

} // end class


?>