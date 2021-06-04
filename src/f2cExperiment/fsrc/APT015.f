**** SOURCE FILE : M0000765.V02   ***
*
C.....FORTRAN SUBROUTINE             APT015...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT015
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED
C              AS TANGENT TO A CIRCLE AND PASSING THROUGH A
C              GIVEN POINT BY THE FOLLOWING APT STATEMENT
C              RESULT = LINE/POINT1, ****, TANTO, CIRC1,
C                       **** = RIGHT OR LEFT
C
C LINKAGE      CALL APT015 (RESULT, PNT, N, CIRC1)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM
C                      OF THE RESULTING LINE
C              PNT     ARRAY CONTAINING THE CANONICAL FORM
C                      OF THE INPUT POINT
C              N       INTEGER EQUIVALENT OF THE MODIFIER
C                      1 = RIGHT     2 = LEFT
C              CIRC1   ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT CIRCLE
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT016
C              SUBROUTINE          APT081
C              SUBROUTINE          APT083
C
      SUBROUTINE APT015 (RESULT, PNT, MN, CIRC1)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4), PNT(3), CIRC1(7)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C...       TRANSFORM CANONICAL FORM TO LOCAL COORDINATE SYSTEM
C
      CALL APT081 (PNT,0)
C
C
C...       MAKE THE POINT A ZERO RADIUS VERTICAL CYLINDER
C
      DO 10 I=3,7
   10 P(I) = R(I)
C
C
C...       TRANSFORM TO BASE SYSTEM AND CALL APT016 TO GET LINE
C
      CALL APT083 (P,KM1)
      CALL APT016 (RESULT, MN, R, MN, CIRC1)
       RETURN
       END
