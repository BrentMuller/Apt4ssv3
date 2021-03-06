**** SOURCE FILE : M0000810.V02   ***
*
C.....FORTRAN SUBROUTINE             APT060...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT060
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A GENERAL CONIC
C              IN THE XY PLANE DEFINED BY THE COEFFICIENTS OF
C              THE TERMS OF THE GENERAL EQUATION AX2 + BXY +
C              CY2 + DX + EY + F = O BY THE APT STATEMENT
C              RESULT = GCONIC/A,B,C,D,E,F
C
C LINKAGE      CALL APT060 (RESULT, AN, BN, CN, DN, EN, FN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING CONIC
C              AN      COEFFICIENT OF THE X2 TERM
C              BN      COEFFICIENT OF THE XY TERM
C              CN      COEFFICIENT OF THE Y2 TERM
C              DN      COEFFICIENT OF THE X TERM
C              EN      COEFFICIENT OF THE Y TERM
C              FN      CONSTANT TERM
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT079
C              SUBROUTINE          DEFEXT
C
      SUBROUTINE APT060(RESULT,AN,BN,CN,DN,EN,FN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      R(1)=AN
      R(2)=CN
      R(4)=FN
      R(6)=Z0
      R(7)=BN/Z2
      R(8)=DN/Z2
      R(9)=EN/Z2
      CALL APT079(R,KM1)
      CALL DEFEXT(RESULT)
      RETURN
       END
