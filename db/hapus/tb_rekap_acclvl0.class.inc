<?php
require_once 'default_table.class.inc';
require_once 'query_string.class.inc';
class tb_rekap_acclvl0 extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        //$this->tablename       = 'msmhs';
        $this->sql_select ='noacclvl0,nmacclvl0,kewajiban,jml';
        
		$qstr = new query_string;
		
		$jointb=array('keumhs','msmhs','keuangk','acclvl1');
		$jointype=array('INNER','LEFT','INNER');
		$ands = $qstr->and(array('angkkeuangk=tahunmsmhs','shiftkeuangk=shiftmsmhs','acclvl1keumhs=noacclvl1keuangk'));
		$onquery =array('nimhsmsmhs=nimkeumhs',
		                $ands,
						'noacclvl1=noacclvl1keuangk');
		$firstjoin = $qstr->join($jointb,$jointype,$onquery);
		
		$subquery1 = '('.$qstr->select($firstjoin,array('field'=>'noacclvl0,SUM(pengalikeumhs*jmlbyrkeuangk) AS kewajiban',
		                                            'groupby'=>'noacclvl0' 
												   )).')'; 
		
		
		$jointb=array('trkeumhs','acclvl1','acclvl0');
		$jointype=array('INNER','INNER');		
		$onquery =array('trkeumhsacclvl1=noacclvl1',		                
						'acclvl1.noacclvl0=acclvl0.noacclvl0');
		$secondjoin = $qstr->join($jointb,$jointype,$onquery);
		
		$subquery2 = '('.$qstr->select($secondjoin,array('field'=>'acclvl1.noacclvl0,nmacclvl0,SUM(trkeumhsbayar) AS jml',
		                                            'groupby'=>'noacclvl0' 
												   )).')';				  
		
		
		$jointb=array("$subquery2 a","$subquery1 b");
		$jointype=array('INNER');		
		$onquery =array('a.noacclvl0=b.noacclvl0');
		
		$thirdjoin = $qstr->join($jointb,$jointype,$onquery);
		
		$this->sql_from ='('.$qstr->select($thirdjoin,array('field'=>'a.noacclvl0,nmacclvl0,kewajiban,jml')).') c';
		//$this->dbname          = 'siafmipa';
        $this->fieldlist       = array('noacclvl0','nmacclvl0','kewajiban','jml');
              
				
    } // end class constructor

} // end class


?>