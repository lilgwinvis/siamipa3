<?php
require_once 'default_table.class.inc';
require_once 'query_string.class.inc';
class tb_publish_nilai extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $qstr = new query_string;
		$jointb=array('trnlm_trnlp a',"trnlm b",'tbkmk','msmhs');
		$jointype=array('','INNER','INNER');
		$ands = $qstr->and(array('a.thsmstrnlm=b.thsmstrnlm','a.nimhstrnlm=b.nimhstrnlm','a.kdkmktrnlm=b.kdkmktrnlm','a.kelastrnlm=b.kelastrnlm'));
		$onquery =array($ands,
		                'b.kdkmktrnlm=kdkmktbkmk',
						'b.nimhstrnlm=nimhsmsmhs');
		
		$this->tablename  = $qstr->join($jointb,$jointype,$onquery);
        $this->sql_select = 'b.thsmstrnlm,b.nimhstrnlm,nmmhsmsmhs,b.kdkmktrnlm,nakmktbkmk,b.kelastrnlm,b.nlakhtrnlm nilaitrnlm,a.nlakhtrnlm nilaitrnlm_trnlp,b.bobottrnlm bobottrnlm,a.bobottrnlm bobottrnlm_trnlp';
		$this->sql_where  = 'b.nlakhtrnlm<>a.nlakhtrnlm';
		$this->sql_orderby = 'b.thsmstrnlm desc,b.kdkmktrnlm,b.kelastrnlm,b.nimhstrnlm';		
    } // end class constructor

} // end class
?>