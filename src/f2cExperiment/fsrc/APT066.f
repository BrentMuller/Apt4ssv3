**** SOURCE FILE : M0000816.V02   ***
*
C...  FORTRAN SUBROUTINE               APT066
C
C              FORTRAN SUBROUTINE APT066
C
C PURPOSE      TO GENERATE A MATRIX DEFINED AS THE PRODUCT OF
C              TWO MATRICES BY THE FOLLOWING APT STATEMENT
C              RESULT = MATRIX/M1, M2
C
C LINKAGE      CALL APT066(RESULT,M1,M2,MN)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING MATRIX
C              M1      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE FIRST INPUT MATRIX
C              M2      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE SECOND INPUT MATRIX
C              MN      INTEGER SET TO ONE IF APT III ORDER OF
C                      MULTIPLICATION FOR THIS CASE IS OPPOSITE TO
C                      APT IV ORDER
C
      SUBROUTINE APT066(RESULT,M1,M2,MN)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(12),M1(12),M2(12)
      DOUBLE PRECISION M1
      DOUBLE PRECISION M2
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'LDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      LOGICAL SWITCH
C
C        CHECK FOR APT III ORDER OF MATRIX MULTIPLICATION
C
      SWITCH=.FALSE.
      IF(ALTMLT .AND. (MN.EQ.1))SWITCH=.TRUE.
C
C...     MAKE MATRIX SQUARE,TRANSFER
C
      DO 10 I=1,3
C
      L11=4*(I-1)
      DO 10 J=1,4
      J11=L11+J
      IF(SWITCH)GO TO 5
      RESULT(J11)=M2(L11+1)*M1(J)+M2(L11+2)*M1(J+4)+M2(L11+3)*M1(J+8)
      IF(J.EQ.4) RESULT(J11)=RESULT(J11)+M2(L11+4)
      GO TO 10
    5 RESULT(J11)=M1(L11+1)*M2(J)+M1(L11+2)*M2(J+4)+M1(L11+3)*M2(J+8)
      IF(J.EQ.4)RESULT(J11)=RESULT(J11)+M1(L11+4)
   10 CONTINUE
      RETURN
       END
