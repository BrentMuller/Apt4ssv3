**** SOURCE FILE : M0000950.V03   ***
*
C.....FORTRAN SUBROUTINE             PSIS.....              3/1/68   GK
      SUBROUTINE PSIS   (HMOD,ADRESS)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      DIMENSION ADRESS(*)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C
C...  ESTABLISHES PART SURFACE PARAMETERS
      IPSDEF=0
      IS=IPS
      CALL APT234(HMOD,ADRESS)
      RETURN
       END