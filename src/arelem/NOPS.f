**** SOURCE FILE : M0000937.V02   ***
*
C.....FORTRAN SUBROUTINE             NOPS....               4/1/68   GK
      SUBROUTINE NOPS
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
      IF(IAERR.NE.0)GO TO 10
C...  NO PS IS TO BE USED FOR THE STARTUP
      INOPS=K1
      IAUTPS = 0
      JENT(IPS) = K1
   10 RETURN
       END
