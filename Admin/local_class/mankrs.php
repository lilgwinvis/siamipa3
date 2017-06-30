<?php 
require_once 'shared.php';
$idx=$_POST['idx'];
switch($idx)
{
 case 1 : $dtkrs = new dt_krs;
          $TA = $dtkrs->TA();
	      $tmp=str_split($TA,4);
		  
     	  if($tmp[1] == 1)
		  {
            $semester=($tmp[0]-1)."2";
         }else{
            $semester=$tmp[0]."1"; 
          } 		  
		  //$semester=$TA;
		  $dtkrs->export_record('trnlm',"thsmstrnlm,nimhstrnlm,kdkmktrnlm,kelastrnlm,shifttrnlm,tgl_input,semestrnlm","thsmskrs,nimhskrs,kdkmkkrs,kelaskrs,shiftkrs,tgl_input,semkrs","thsmskrs=".$semester); 
          $dtkrs->export_record('trnlm_trnlp',"thsmstrnlm,nimhstrnlm,kdkmktrnlm,kelastrnlm","thsmskrs,nimhskrs,kdkmkkrs,kelaskrs","(kdkmkkrs not like 'MATP%') and (thsmskrs=".$semester.")"); 
            $vw_krs=new vw_krs;
            echo $vw_krs->lst_mhs();
		  break;
 case 2 : $dtkrs = new dt_krs;
          $TA = $dtkrs->TA();
	      $tmp=str_split($TA,4);		  
     	  if($tmp[1] == 1)
		  {
            $semester=($tmp[0]-1)."2";
          }else{
            $semester=$tmp[0]."1"; 
          } 			  
		  $dtkrs->delAllRecord("thsmskrs=".$semester);
		  $vw_krs=new vw_krs;
          echo $vw_krs->lst_mhs();
          break; 
 case 3 : $dtksdngajar=new dt_ksd_ngajar;
          $dtksdngajar->export_record('pengajar',"kdkmkpengajar,kddspengajar,shiftpengajar,thnsmspengajar,semespengajar,jawalpengajar,jakhirpengajar,haripengajar,hnrpengajar,kdass,kelaspengajar,tgl_input","kdkmk,kdds,shift,thnsms,sem,jawalklh,jakhirklh,hariklh,hnr,kdass,klsklh,tgl_input","");
          $ksd_dosen = new vw_ksd_ngajar;
          echo $ksd_dosen->lst_dsn();		  
          break;
 case 4 : $dtksdngajar=new dt_ksd_ngajar;
          $dtksdngajar->delAllRecord("");
           $ksd_dosen = new vw_ksd_ngajar;
		  echo $ksd_dosen->lst_dsn();		  
          break; 		  
}



?>