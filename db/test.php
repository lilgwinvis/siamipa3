<?php
 include_once 'query_string.class.inc';

 $qstr = new query_string;
 
        $fieldsubquery='thsmstrnlm,kdkmktrnlm,semestrnlm,shifttrnlm,kelastrnlm';
		$subquery='('.$qstr->select('trnlm',array('field'=>$fieldsubquery,'groupby'=>$fieldsubquery)).')';
				
		
		$jointb=array('pengajar',"$subquery a",'tbdos','tbkmk');
		$jointype=array('RIGHT','LEFT','LEFT');
		
		$ands = $qstr->and(array('thnsmspengajar=thsmstrnlm','kdkmktrnlm=kdkmkpengajar','semestrnlm=semespengajar','shifttrnlm=shiftpengajar','kelastrnlm=kelaspengajar'));
		
		$onquery =array($ands,
		                'Kode=kddspengajar',
						'kdkmktrnlm=kdkmktbkmk');
		
		echo $qstr->join($jointb,$jointype,$onquery);
       
 
?>