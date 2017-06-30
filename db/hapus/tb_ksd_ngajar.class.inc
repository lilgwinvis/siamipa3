<?php
require_once 'default_table.class.inc';
class tb_ksd_ngajar extends Default_Table
{
    // additional class variables go here
    function __construct()
    {
        $this->sql_select      = 'Kdkmk,kdds,shift,thnsms,sem,jawalklh,jakhirklh,hariklh,klsklh,tgl_input,kdass,disetujui,hnr';
		$this->tablename       = 'ksd_ngajar';
       	$this->orderby         = 'sem'; 
		
		$this->fieldlist       = $this->getfieldlist(); 
		
		// $this->fieldlist       = array('Kdkmk','kdds','shift','thnsms','sem','jawalklh','jakhirklh','hariklh','klsklh','tgl_input','kdass','disetujui','hnr');
        // $this->fieldlist['thnsms'] = array('pkey' => 'y');
        // $this->fieldlist['Kdkmk'] = array('pkey' => 'y');
        // $this->fieldlist['kdds'] = array('pkey' => 'y');
        // $this->fieldlist['shift'] = array('pkey' => 'y');
		// $this->fieldlist['sem'] = array('pkey' => 'y');
		$this->fieldlist['klsklh'] = array('pkey' => 'y');
		
    } // end class constructor

} // end class


?>