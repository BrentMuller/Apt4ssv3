**** SOURCE FILE : CLOSPE00.IBM;1   ***
*
*                MODIFIED                23-FEB-1988  E.MCLELLAN
      SUBROUTINE CLOSPE(ID,IRET)
C
c      INTEGER ID,IRET,JCODE,JRET
      integer id,iret
C
c      JCODE=2
c      CALL UCLOSE(ID,JCODE,JRET)
c      IF (JRET.EQ.0) THEN
c       IRET=0
c      ELSE
c       IRET=1
c      ENDIF
      close(unit=id,err=10 ,status='keep')
      iret = 0
      return
   10 iret = 1
      RETURN
      END
