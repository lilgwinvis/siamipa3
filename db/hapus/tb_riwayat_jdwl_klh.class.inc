<?php
require_once 'default_table.class.inc';
include_once 'query_string.class.inc';

class tb_riwayat_jdwl_klh extends Default_Table
{
    // additional class variables go here
    function __construct()
    {   $qstr = new query_string;
	
        $this->sql_select ='haripengajar,jawalpengajar,jakhirpengajar,semestrnlm,shifttrnlm,kdkmktrnlm,nakmktbkmk,kddspengajar,nama,kdass,ruangpengajar,hnrpengajar,Hstat,sksmktbkmk';
        
		$fieldsubquery='thsmstrnlm,kdkmktrnlm,semestrnlm,shifttrnlm,kelastrnlm';
		$subquery='('.$qstr->select('trnlm',array('field'=>$fieldsubquery,'groupby'=>$fieldsubquery)).')';
				
		
		$jointb=array('pengajar',"$subquery a",'tbdos','tbkmk');
		$jointype=array('RIGHT','LEFT','LEFT');
		
		$ands = $qstr->and(array('thnsmspengajar=thsmstrnlm','kdkmktrnlm=kdkmkpengajar','semestrnlm=semespengajar','shifttrnlm=shiftpengajar','kelastrnlm=kelaspengajar'));
		
		$onquery =array($ands,
		                'Kode=kddspengajar',
						'kdkmktrnlm=kdkmktbkmk');
		
		$this->sql_from =$qstr->join($jointb,$jointype,$onquery);
        $this->sql_orderby='haripengajar,jawalpengajar,semestrnlm,shifttrnlm,kdkmktrnlm,kddspengajar';  
        
		$this->fieldlist = array('haripengajar','jawalpengajar','jakhirpengajar','semestrnlm','shifttrnlm','kdkmktrnlm','nakmktbkmk','kddspengajar','nama','kdass','ruangpengajar','hnrpengajar','Hstat','sksmktbkmk');
        
                
				
    } // end class constructor

} // end class


?>