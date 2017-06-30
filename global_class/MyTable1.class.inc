<?php

 require_once 'shared.php';
 
 class MyTable
 {
    var $tbstat_;
	var $header_;
	var $data_;
	var $footer_;
    
	function __construct($tbstat,$header,$data,$footer)
	{
       $this->tbstat_=$tbstat;
	   $this->header_=$header;
	   $this->data_=$data;
	   $this->footer_=$footer;
	}
	
	function display()
	{
	  
	    $tbl = new HTML_Table(null, 'display', 0, 0, 0,$this->tbstat_);
		
		$tbl->addRow();
		foreach($this->header_ as $data)
		{		  
	      $tbl->addCell($data, null, 'header');
	    }
		
		if(!empty($this->data_))
		{		
		  foreach($this->data_ as $row)
		  {
		    $tbl->addRow();
	        foreach($row as $v){ 
			   $tbl->addCell($v[0], null, 'data',$v[1]);
	        }
		  }		
		}
		
		
		
	  if($this->footer_!=""){	
	    return $tbl->display($this->footer_);
      }else{
        return $tbl->display();
      }	  
	}
	
 
 }
 ?>