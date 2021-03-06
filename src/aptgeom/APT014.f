**** SOURCE FILE : M0000764.V02   ***
*
C.....FORTRAN SUBROUTINE             APT014...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT014
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE
C              DEFINED AS PASSING THROUGH TWO SYMBOLIC POINTS
C              BY THE FOLLOWING APT STATEMENT
C                   RESULT = LINE/P1, P2
C
C LINKAGE      CALL APT014 (RESULT, P1, P2)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN CANONICAL FORM OF THE
C                      RESULTING LINE
C              P1      ARRAY CONTAINING CANONICAL FORM OF THE
C                      FIRST INPUT POINT
C              P2      ARRAY CONTAINING CANONICAL FORM OF THE
C                      SECOND INPUT POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT081
C              SUBROUTINE          APT012
C
      SUBROUTINE APT014 (RESULT,P1,P2)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4),P1(3),P2(3)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ISHR16.INC'
C
C
C
C...     CHECK INPUT VALIDITY AND TRANSFORM CANONICAL FORMS
C
      CALL APT081 (P1,0)
      SC(1) = P(1)
      SC(2) = P(2)
      CALL APT081 (P2,0)
C
C...     LINE THRU TWO POINTS FROM APT012
C
      CALL APT012(RESULT,SC(1),SC(2),P(1),P(2))
       RETURN
       END
