<?php
require_once 'default_table.class.inc';
class tb_ksd_ngajar_jn_tbkmk extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        
        $this->sql_select ='Kdkmk,nakmktbkmk,sksmktbkmk,sksprtbkmk,semestbkmk,kdds,shift,thnsms,sem,jawalklh,jakhirklh,hariklh,klsklh,kdass,tgl_input,disetujui,hnr';
        $this->sql_from ='ksd_ngajar INNER JOIN tbkmk ON kdkmk=kdkmktbkmk';
        $this->sql_orderby='kdds,semestbkmk,kdkmk';  
		
		
        $this->fieldlist       = array('Kdkmk','nakmktbkmk','sksmktbkmk','sksprtbkmk','semestbkmk','kdds','shift','thnsms','sem','jawalklh','jakhirklh','hariklh','klsklh','tgl_input','disetujui');
              
				
    } // end class constructor

} // end class


?>