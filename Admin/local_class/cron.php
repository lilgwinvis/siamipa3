<?php 
          require_once 'shared.php';
          
		  $dtkrs = new dt_krs;
          $TA = $dtkrs->TA();
	      $tmp=str_split($TA,4);
		  
     	  if($tmp[1] == 1)
		  {
            $semester=($tmp[0]-1)."2";
         }else{
            $semester=$tmp[0]."1"; 
          } 		  
		  
		  $dtkrs->export_record('trnlm',"thsmstrnlm,nimhstrnlm,kdkmktrnlm,kelastrnlm,shifttrnlm,tgl_input,semestrnlm","thsmskrs,nimhskrs,kdkmkkrs,kelaskrs,shiftkrs,tgl_input,semkrs","thsmskrs=".$semester); 
          $dtkrs->export_record('trnlm_trnlp',"thsmstrnlm,nimhstrnlm,kdkmktrnlm,kelastrnlm","thsmskrs,nimhskrs,kdkmkkrs,kelaskrs","(kdkmkkrs not like 'MATP%') and (thsmskrs=".$semester.")"); 
         		  
		  $dtkrs->delAllRecord("thsmskrs=".$semester);
		  
          $dtksdngajar=new dt_ksd_ngajar;
          $dtksdngajar->export_record('pengajar',"kdkmkpengajar,kddspengajar,shiftpengajar,thnsmspengajar,semespengajar,jawalpengajar,jakhirpengajar,haripengajar,hnrpengajar,kdass,kelaspengajar,tgl_input","kdkmk,kdds,shift,thnsms,sem,jawalklh,jakhirklh,hariklh,hnr,kdass,klsklh,tgl_input","");
          $dtksdngajar->delAllRecord("");
		  
		  $dt_stat_mhs = new dt_stat_mhs;
	      $dt_stat_mhs->import($TA);
?>