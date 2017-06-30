<?php
require_once 'default_table.class.inc';
class tb_rekap_trkeumhs extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='tahunmsmhs,shiftmsmhs,nimhsmsmhs,nmmhsmsmhs,kewajiban,tran';
        //$this->sql_from ='msmhs LEFT JOIN (SELECT trkeumhsnim,SUM(trkeumhsbayar) AS tran FROM trkeumhs GROUP BY trkeumhsnim) a ON trkeumhsnim=nimhsmsmhs 
        //                  LEFT JOIN (SELECT nimkeumhs,SUM(pengalikeumhs*jmlbyrkeuangk) AS kewajiban 
        //                  FROM keumhs INNER JOIN msmhs ON nimhsmsmhs=nimkeumhs LEFT JOIN keuangk ON angkkeuangk=tahunmsmhs AND shiftkeuangk=shiftmsmhs AND acclvl1keumhs=noacclvl1keuangk
        //                  GROUP BY nimkeumhs) b ON nimhsmsmhs=nimkeumhs';
        $this->sql_from ='vw_tbrekaptrkeumhs';
		$this->sql_orderby='tahunmsmhs,nimhsmsmhs';  
		
		//$this->dbname          = 'siafmipa';
		$this->fieldlist       = $this->getfieldlist(); 
        //$this->fieldlist       = array('tahunmsmhs','shiftmsmhs','nimhsmsmhs','nmmhsmsmhs','kewajiban','tran');
              
				
    } // end class constructor

} // end class


?>