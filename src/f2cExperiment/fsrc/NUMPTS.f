**** SOURCE FILE : M0000940.V04   ***
*
C.....FORTRAN SUBROUTINE             NUMPTS...              3/1/68   GK
      SUBROUTINE NUMPTS(XNUMBR)
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'IFXCOR.INC'
C
      INTEGER IPPWRD(2),BCDF
      CHARACTER*8 PPWORD
      DATA  PPWORD /'NUMPTS'/
C
C
C
C...  USE THIS AS THE MAXIMUM NUMBER OF CUTTER CENTERS ON ONE
C...  ELEMENTARY CUT SEQUENCE
      IPPWRD(1)=BCDF(PPWORD(1:4))
      IPPWRD(2)=BCDF(PPWORD(5:8))
      CALL APT299(1,IPPWRD,1,XNUMBR)
      NMPNTS=XNUMBR
      RETURN
       END
