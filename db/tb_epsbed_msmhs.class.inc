<?php
require_once 'epsbed_table.class.inc';
class tb_epsbed_msmhs extends epsbed_table
{
    // additional class variables go here
    function __construct()
    {
        $this->tablename       = 'epsbed/MSMHS.DBF';
        $this->dbname        = 'siafmipa';
        $this->fieldname     = array('KDPTIMSMHS','KDJENMSMHS','KDPSTMSMHS','NIMHSMSMHS','NMMHSMSMHS','SHIFTMSMHS','TPLHRMSMHS','TGLHRMSMHS','KDJEKMSMHS','TAHUNMSMHS','SMAWLMSMHS','BTSTUMSMHS','ASSMAMSMHS','TGMSKMSMHS','TGLLSMSMHS','STMHSMSMHS','STPIDMSMHS','SKSDIMSMHS','ASNIMMSMHS','ASPTIMSMHS','ASJENMSMHS','ASPSTMSMHS','BISTUMSMHS','PEKSBMSMHS','NMPEKMSMHS','PTPEKMSMHS','PSPEKMSMHS','NOPRMMSMHS','NOKP1MSMHS','NOKP2MSMHS','NOKP3MSMHS','NOKP4MSMHS');
        
        $this->keyfield = array('KDPTIMSMHS','KDJENMSMHS','KDPSTMSMHS','NIMHSMSMHS');  		
		
		$this->fieldlist = array(
		array("KDPTIMSMHS" , DBFFIELD_TYPE_CHAR, 6),	
		array("KDJENMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("KDPSTMSMHS" , DBFFIELD_TYPE_CHAR, 5),	
		array("NIMHSMSMHS" , DBFFIELD_TYPE_CHAR, 15),	
		array("NMMHSMSMHS" , DBFFIELD_TYPE_CHAR, 30),	
		array("SHIFTMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("TPLHRMSMHS" , DBFFIELD_TYPE_CHAR, 20),
		array("TGLHRMSMHS" , DBFFIELD_TYPE_DATE, 8),	
		array("KDJEKMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("TAHUNMSMHS" , DBFFIELD_TYPE_CHAR, 4),	
		array("SMAWLMSMHS" , DBFFIELD_TYPE_CHAR, 5),	
		array("BTSTUMSMHS" , DBFFIELD_TYPE_CHAR, 5),	
		array("ASSMAMSMHS" , DBFFIELD_TYPE_CHAR, 2),	
		array("TGMSKMSMHS" , DBFFIELD_TYPE_DATE, 8),	
		array("TGLLSMSMHS" , DBFFIELD_TYPE_DATE, 8),
		array("STMHSMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("STPIDMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("SKSDIMSMHS" , DBFFIELD_TYPE_NUMERIC, 11),	
		array("ASNIMMSMHS" , DBFFIELD_TYPE_CHAR, 15),	
		array("ASPTIMSMHS" , DBFFIELD_TYPE_CHAR, 6),
		array("ASJENMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("ASPSTMSMHS" , DBFFIELD_TYPE_CHAR, 5),
		array("BISTUMSMHS" , DBFFIELD_TYPE_CHAR, 1),	
		array("PEKSBMSMHS" , DBFFIELD_TYPE_CHAR, 1),
		array("NMPEKMSMHS" , DBFFIELD_TYPE_CHAR, 40),	
		array("PTPEKMSMHS" , DBFFIELD_TYPE_CHAR, 6),
		array("PSPEKMSMHS" , DBFFIELD_TYPE_CHAR, 5),	
		array("NOPRMMSMHS" , DBFFIELD_TYPE_CHAR, 10),
		array("NOKP1MSMHS" , DBFFIELD_TYPE_CHAR, 10),	
		array("NOKP2MSMHS" , DBFFIELD_TYPE_CHAR, 10),
		array("NOKP3MSMHS" , DBFFIELD_TYPE_CHAR, 10),	
		array("NOKP4MSMHS" , DBFFIELD_TYPE_CHAR, 10)
		
       ); 
		

		
		$server = dirname(dirname(__FILE__));
   	   	$this->base_path1 = $server .'/db/';
				
    } // end class constructor

} // end class
?>

         