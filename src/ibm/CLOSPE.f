**** SOURCE FILE : CLOSPE00.IBM;1   ***
*
*                MODIFIED                23-FEB-1988  E.MCLELLAN
      SUBROUTINE CLOSPE(ID,IRET)
C
      INTEGER ID,IRET,JCODE,JRET
C
      JCODE=2
      CALL UCLOSE(ID,JCODE,JRET)
      IF (JRET.EQ.0) THEN
       IRET=0
      ELSE
       IRET=1
      ENDIF
      RETURN
      END
