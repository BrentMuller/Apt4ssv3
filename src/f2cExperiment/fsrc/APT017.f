**** SOURCE FILE : M0000767.V02   ***
*
C.....FORTRAN SUBROUTINE              APT017               4/17/68
C
C              FORTRAN SUBROUTINE APT017
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED
C              AS PASSING THROUGH A POINT AND HAVING A SPECI-
C              FIED SLOPE OR FORMING A SPECIFIED ANGLE WITH THE
C              X-AXIS BY ONE OF THE FOLLOWING APT STATEMENTS
C              RESULT = LINE/PNT, ATANGL, ALPHA
C              RESULT = LINE/PNT, SLOPE, ALPHA
C
C LINKAGE      CALL APT017 (RESULT, PNT, M, ALPHA)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE
C                      RESULTING LINE
C              PNT     ARRAY CONTAINING THE CANONICAL FORM OF THE
C                      INPUT POINT
C              M       INTEGER EQUIVALENT OF THE MODIFIER
C                      1 = ATANGL 2 = SLOPE
C              ALPHA   REAL VARIABLE CONTAINING THE VALUE OF
C                      THE ANGLE (DEGREES) OR SLOPE.
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          APT022
C              REAL FUNCTION       ATAN
C
      SUBROUTINE APT017 (RESULT,PNT,MN,ALPHA)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
      DIMENSION RESULT(4),PNT(3)
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
C...     IF SLOPE, SOLVE FOR ANGLE
C
      IF (MN.EQ.K1)GO TO 10
      ALPHA=DATAN(ALPHA)/DEGRAD
C
C...     TRANSFORM LOCAL X-AXIS (0,1,0,0) TO BASE SYSTEM
C
   10 CALL APT077 (R(5),KM1)
      CALL APT022 (RESULT,PNT,K1,ALPHA,R)
      RETURN
       END
