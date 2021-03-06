**** SOURCE FILE : M0000776.V02   ***
*
C.....FORTRAN SUBROUTINE             APT026...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT026
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED
C              AS HAVING ITS CENTER AT A GIVEN POINT AND PASSING
C              THROUGH A GIVEN POINT BY THE FOLLOWING APT STATEMENT
C              RESULT = CIRCLE/CENTER, PNT1, PNT2
C
C LINKAGE      CALL APT026 (RESULT, PNT1, PNT2)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING CIRCLE
C              PNT1    ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE FIRST INPUT POINT (CENTER)
C              PNT2    ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE SECOND INPUT POINT (ON CIRCUMFERENCE)
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT081
C              SUBROUTINE          APT083
C              SUBROUTINE          DEFEXT
C              REAL FUNCTION       SQRT
C
      SUBROUTINE APT026(RESULT,PNT1,PNT2)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(7),PNT1(3),PNT2(3)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DEF.INC'
      INCLUDE 'DSHAR3.INC'
      INCLUDE 'ISHR16.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C...     TRANSFORM COORDINATES, CHECK VALIDITY
C
      CALL APT081(PNT1,0)
      R(1) = P(1)
      R(2) = P(2)
      CALL APT081(PNT2,0)
C
C...     RADIUS,R(7),OF CIRCLE IS DISTANCE BETWEEN PNT1 AND PNT2
C
      R(7) = DSQRT((R(1)-P(1))**2+(R(2)-P(2))**2)
      CALL APT083 (R,KM1)
      CALL DEFEXT (RESULT)
      RETURN
       END
