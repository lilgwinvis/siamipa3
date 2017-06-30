<?php
require_once 'default_table.class.inc';
class tb_trkeumhs_jn_acclvl1 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='trkeumhsnim,trkeumhstgl,trkeumhsacclvl1,nmacclvl1,trkeumhsbayar,trkeumhsket';
        $this->sql_from ='trkeumhs INNER JOIN acclvl1 ON trkeumhsacclvl1=noacclvl1';
        $this->sql_orderby='trkeumhstgl,trkeumhsnim,trkeumhsacclvl1';  
		
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('trkeumhsnim','trkeumhstgl','trkeumhsacclvl1','nmacclvl1','trkeumhsbayar','trkeumhsket');
              
				
    } // end class constructor

} // end class


?>