**** SOURCE FILE : M0000773.V03   ***
*
C
C.....FORTRAN SUBROUTINE             APT023...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT023
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED
C              AS THE INTERSECTION OF TWO PLANES BY THE FOLLOWING
C              APT STATEMENT
C              RESULT = LINE/INTOF, PL1, PL2
C
C LINKAGE      CALL APT023 (RESULT, PL1, PL2)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING LINE
C              PL1     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE FIRST INPUT PLANE
C              PL2     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE SECOND INPUT PLANE
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          DEFEXT
C              REAL FUNCTION       SQRT
C
      SUBROUTINE APT023 (RESULT,PL1,PL2)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4),PL1(4),PL2(4)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'IDEF.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
      EQUIVALENCE (S1,SC(1)),(S2,SC(2)),(S3,SC(3)),(S4,SC(4))
C
C...     TRANSFORM PL1,PL2,CHECK VALIDITY
C
      CALL APT077(PL1,0)
      DO 10 I= 1,4
   10 SC(I+4) =L(I)
      CALL APT077(PL2,0)
C
C...     SOLVE FOR VERTICAL PLANE AT INTERSECTION OF PL1,PL2
C
      S1 =  SC(5)*L(3)-L(1)*SC(7)
      S2 =  SC(6)*L(3)-L(2)*SC(7)
      S3 =  SC(8)*L(3)-L(4)*SC(7)
      S4 = DSQRT(S1*S1+S2*S2)
C
C...     TEST FOR PARALLEL PLANES - LINE UNDEFINED
C
      IF (S4  .LT.Z1EM5) GO TO 30
      R(1)= S1/S4
      R(2)= S2/S4
      R(4)= S3/S4
      CALL APT077 (R,KM1)
   20 CALL DEFEXT (RESULT)
      RETURN
   30 IERROR =K27
      GO TO 20
       END