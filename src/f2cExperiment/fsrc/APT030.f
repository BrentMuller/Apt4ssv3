**** SOURCE FILE : M0000780.V03   ***
*
C
C.....FORTRAN SUBROUTINE             APT030...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT030
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED
C              AS TANGENT TO EACH OF TWO GIVEN LINES AND HAVING
C              A GIVEN RADIUS BY THE FOLLOWING APT STATEMENT
C              RESULT = CIRCLE/****, LI, ****, L2, RADIUS, RAD
C                **** = XLARGE, YLARGE, XSMALL, YSMALL
C
C LINKAGE      CALL APT030 (RESULT, M1, L1, M2, L2, RAD)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING CIRCLE
C              M1      INTEGER EQUIVALENT OF THE FIRST MODIFIER
C                             1 = XLARGE       2 = YLARGE
C                             4 = XSMALL       5 = YSMALL
C              L1      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE FIRST INPUT LINE
C              M2      INTEGER EQUIVALENT OF THE SECOND MODIFIER
C                             1 = XLARGE       2 = YLARGE
C                             4 = XSMALL       5 = YSMALL
C              L2      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE SECOND INPUT LINE
C              RAD     REAL VARIABLE CONTAINING THE VALUE OF THE
C                      DESIRED RADIUS
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT003
C              SUBROUTINE          APT020
C              SUBROUTINE          APT078
C
      SUBROUTINE APT030 (RESULT,M1,L1,M2,L2,RAD)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
      DIMENSION RESULT(7),L1(4),L2(4)
      DOUBLE PRECISION L1,L2
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
C
C
C
C...     DEFINE C1 WITH AXIS OF DESIRED CYLINDER
C
      CALL APT078 (R(4),KM1)
      DO 10 I=1,3
      C1(I+1)=R(I)
   10 R(I)=Z0
      C1(5)=RAD
C...     DEFINE LINES PARALLEL TO L1,L2 AT DISTANCE RAD
C
      CALL APT020 (LN1(2),L1,M1,C1(5))
      DO 30 I=2,5
   30 SC(I+11)=LN1(I)
      CALL APT020 (LN1(2),L2,M2,C1(5))
C
C...     SOLVE FOR INTERSECTION OF LN1 AND SC(13) -GIVES CIRCLE CENTER
C
      DO 50 I=4,7
   50 R(I)=C1(I-2)
      CALL APT003 (RESULT,SC(13),LN1(2))
      DO 20 I=4,7
   20 RESULT(I)=C1(I-2)
      RETURN
       END
