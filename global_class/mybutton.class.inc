<?php
require_once 'shared.php';

class mybutton 
{
   var $lstbutton_;
   
   function __construct($lstbutton)
   {
     $this->lstbutton_=$lstbutton;
   }  
   
    function display()
	{
	  $txt = '';
      
	  if(!empty($this->lstbutton_))
	  {
	    $dtform = new html_form;
		foreach($this->lstbutton_ as $button)
		{
		  $txt.= $dtform->addButton($button['type'],$button['id'],$button['txt'],$button['attr_ar']);		
		}
	  
	  } 
	  return $txt;
	}
}

?>