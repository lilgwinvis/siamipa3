<?php
require_once 'default_table.class.inc';
class tb_jdwl_klh extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select ='hariklh,jawalklh,jakhirklh,sem,shift,kdkmk,nakmktbkmk,sksmktbkmk,kdds,nama,kdass,rklh,hnr,Hstat';
        $this->sql_from ='vw_jdwlklh';
        $this->sql_orderby='hariklh,jawalklh,sem,shift,kdds,kdkmk';  
        
		$this->fieldlist       = $this->getfieldlist(); 
		
		//$this->fieldlist = array('hariklh','jawalklh','jakhirklh','sem','shift','kdkmk','nakmktbkmk','sksmktbkmk,','nama','rklh','hnr','Hstat');
        
                
				
    } // end class constructor

} // end class


?>