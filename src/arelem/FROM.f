**** SOURCE FILE : M0000904.V04   ***
*
C.....FORTRAN SUBROUTINE  ....FROM           8/68                 AR,PH
C
      SUBROUTINE FROM(POINT)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C
C...  THE PRESENT TOOL POSITION IS (POINT)
      DIMENSION POINT(3)
      CHARACTER*4 HFROM
      DATA HFROM/'FROM'/
      IAERR=0
      IGOTO=0
      CALL TRANSM(TEK,POINT,2,3,0)
      DO 10 J = 1,3
   10 TE(J)=TEK(J)
      CALL APT202(POINT,2)
C...  SET RECORD TYPE CODE FOR CLTAPE WRITER
      MODFER=HFROM
      CALL APT233
      RETURN
       END
