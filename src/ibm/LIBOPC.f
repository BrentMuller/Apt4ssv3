**** SOURCE FILE : LIBOPC00.IBM;2   ***
*
      SUBROUTINE LIBOPC(IND,FLAG)
*
*  * LIBOPC *  VAX-11 FORTRAN VERSION  27.09.82  E.MCLELLAN
*                            MODIFIED  26.09.86
*                MODIFIED                25-FEB-1988  E.MCLELLAN
*
*  PURPOSE     TO CHECK THE EXISTENCE OF SUBDIRECTORY [.APTLIB]
*              OR CLOSE UNIT REFERENCING SUBDIRECTORY
*  CALLING SEQUENCE
*              CALL LIBOPC(IND,FLAG)
*  ARGUMENTS
*              IND   =1 DOES SUBDIRECTORY EXIST
*                    =2 CLOSE UNIT WHICH REFERENCES SUBDIRECTORY
*              FLAG  =0 SUBDIRECTORY EXISTS
*                    =1 SUBDIRECTORY DOES NOT EXIST
*                    =2 NOT USED
*                    =3 ALREADY CLOSED (IND=2)
*                    =4 IND IS NOT 1 OR 2
*
      INTEGER FLAG
      LOGICAL OD,EX
C
      INCLUDE 'FILTAB.INC'
C
C
C
C.....UNIT NUMBER
C
      ID=U(24)
C
      IF (IND.EQ.1) THEN
        FLAG=0
C
      ELSE IF (IND.EQ.2) THEN
c        CALL UCLOSE(ID,2,JRET)
      write(*,*)'TODO: uclose command-LIBOPC.f'
        IF (JRET.EQ.4) THEN
          FLAG=3
        ELSE
          FLAG=0
        ENDIF
C
      ELSE
C
C.....IND NOT 1 OR 2
        FLAG=4
      END IF
      RETURN
      END
