DELIMITER $$

USE `siafmipa`$$

DROP TRIGGER /*!50032 IF EXISTS */ `upd_nim`$$

CREATE
    /*!50017 DEFINER = 'root'@'localhost' */
    TRIGGER `upd_nim` AFTER UPDATE ON `msmhs` 
    FOR EACH ROW BEGIN
     IF (old.nimhsmsmhs != new.nimhsmsmhs) 
     THEN       
       UPDATE stat_mhs SET nimstat_mhs=new.nimhsmsmhs WHERE nimstat_mhs=old.nimhsmsmhs;
       UPDATE keumhs SET nimkeumhs=new.nimhsmsmhs WHERE nimkeumhs=old.nimhsmsmhs;
       UPDATE krs SET nimhskrs=new.nimhsmsmhs WHERE nimhskrs=old.nimhsmsmhs; 
       UPDATE tbmpoll SET nimhsmpoll=new.nimhsmsmhs WHERE nimhsmpoll=old.nimhsmsmhs;
       UPDATE trkeumhs SET trkeumhsnim=new.nimhsmsmhs WHERE trkeumhsnim=old.nimhsmsmhs;
       UPDATE trnlm SET nimhstrnlm=new.nimhsmsmhs WHERE nimhstrnlm=old.nimhsmsmhs;  
       UPDATE trnlm_trnlp SET nimhstrnlm=new.nimhsmsmhs WHERE nimhstrnlm=old.nimhsmsmhs; 
       UPDATE trnlp SET nimhstrnlp=new.nimhsmsmhs WHERE nimhstrnlp=old.nimhsmsmhs;
     END IF;   
    END;
$$

DELIMITER ;