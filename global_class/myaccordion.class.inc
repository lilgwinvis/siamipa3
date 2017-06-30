<?php

  require_once 'shared.php';

class myaccordion
{
    var $id_;
    var $header_;
    var $content_;	
	 
	 function __construct($id,$header,$content)
	 {
	  	$this->id_=$id;
        $this->header_=$header;
        $this->content_=$content;	  
	 }

     function display($idx=0)
     {
        $html_txt = '<div role="tablist" class="ui-accordion ui-widget ui-helper-reset ui-accordion-icons" id="'.$this->id_.'">';
             $i=0;
			 foreach($this->header_ as $row)
             {			 
		        $html_txt.='<div>';
				
				$html_txt.='<h3 tabindex="$i" aria-selected='.($i>0 ? "false" : "true").' aria-expanded="true" role="tab" class="ui-accordion-header ui-helper-reset ui-state-default'.( $i>0 ? "":"ui-state-active ui-corner-top").'">'.($idx==0 ? '<span class="ui-icon ui-icon-triangle-1-s">':"").'</span><a tabindex="$i" href="#"> '.$row.' </a></h3>';
				$html_txt.='<div role="tabpanel"'.($idx==0 ?'style="height:120px;"':'') .' class="ui-accordion-content ui-helper-reset ui-widget-content ui-corner-bottom '.($i>0 ? "":"ui-accordion-content-active").'">';
		        
				$html_txt.= $this->content_[$i];
				$html_txt.='</div>';
			    $html_txt.='</div>';
				$i=$i+1;
		     }
        $html_txt .='</div>';

        return $html_txt;		
     }	 
}


?>