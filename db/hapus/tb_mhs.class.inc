<?php
require_once 'default_table.class.inc';
class tb_mhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'msmhs';
        //$this->dbname          = 'siafmipa';
        
		//$this->fieldlist       = array('kdpstmsmhs', 'nimhsmsmhs', 'nmmhsmsmhs', 'shiftmsmhs', 'tplhrmsmhs', 'tglhrmsmhs', 'kdjekmsmhs', 'tahunmsmhs', 'smawlmsmhs','agamamsmhs','smamsmhs','statmsmhs','tlpmsmhs','emailmsmhs','almmsmhs','pass','bpmsmhs','link_forlap');
        
		$this->fieldlist = $this->getfieldlist();
		
		
		//$this->fieldlist['kdpstmsmhs'] = array('pkey' => 'y');
		//$this->fieldlist['nimhsmsmhs'] = array('pkey' => 'y'); 
		
		$this->sql_orderby='tahunmsmhs,nimhsmsmhs';

        	
				
    } // end class constructor

} // end class
?>