**** SOURCE FILE : M0002819.V04   ***
*
C.....FORTRAN SUBROUTINE  ....APT200         8/68                    PH
C.....FORTRAN SUBROUTINE             APT200...              3/1/68   GK
      SUBROUTINE APT200 (HMOD,ADRESS,XNTSCT)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DIMENSION ADRESS(*)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C     25. COMMON FOR AERR INFORMATION
C
      COMMON /AERCOM/ IAERFG,NPCTPT,PCTPTS,PCTPLN,ERRPTS
      DIMENSION PCTPTS(3,20),PCTPLN(4),ERRPTS(3,3)
C
C
C...  ESTABLISHES CHECK SURFACE PARAMETERS FOR EACH CHECK SURFACE
C...  ADVANCE THE CHECK SURFACE COUNTER
      IF(IAERR.EQ.1) GO TO 1000
      ICSCNT=ICSCNT+K1
      IF(NUMSFS.GE.(ICSCNT+K2)) GO TO 1
      IAERFG=1
      CALL AERR(20001,'APT200  ')
      GO TO 1000
    1 IS=ICS+(ICSCNT-K1)*LSV1
      CALL APT234(HMOD,ADRESS)
      IF(IAERR)5,5,1000
C...  SET IFL4=1 IF PSTAN,0 IF TANTO
    5 IF(ISFTYP(IS)-K4)30,10,20
   10 IFL4(IS)=0
      GO TO 30
   20 IFL4(IS)=K1
C...  SET CS INTERSECTION COUNTER
   30 IFAR(IS) = XNTSCT
      JCS=.TRUE.
 1000 CONTINUE
      RETURN
       END
