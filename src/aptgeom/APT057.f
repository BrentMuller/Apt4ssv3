**** SOURCE FILE : M0000807.V02   ***
*
C.....FORTRAN SUBROUTINE             APT057...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT057
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF AN ELLIPSE DE-
C              FINED AS HAVING A GIVEN CENTER POINT, GIVEN LENGTHS
C              OF SEMI-MAJOR AND SEMI-MINOR AXES, AND A GIVEN
C              ANGLE BETWEEN THE MAJOR AXIS AND THE X AXIS BY
C              THE FOLLOWING APT STATEMENT
C              RESULT = ELLIPS/CENTER, PN, MA, MI, BETA
C
C LINKAGE      CALL APT057 (RESULT, PN, MA, MI, BETA)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING ELLIPSE
C              PN      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT POINT
C              MA      REAL VARIABLE CONTAINING THE LENGTH OF
C                      THE SEMI-MAJOR AXIS
C              MI      REAL VARIABLE CONTAINING THE LENGTH OF
C                      THE SEMI-MINOR AXIS
C              BETA    REAL VARIABLE CONTAINING THE VALUE OF
C                      THE ANGLE BETWEEN THE MAJOR AXIS AND
C                      THE X AXIS (DEGREES)
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT059
C
      SUBROUTINE APT057 (RESULT,PN,MA,MI,BETA)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10),PN(3)
      DOUBLE PRECISION MA,MI
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'ZNUMBR.INC'
C
C
C
      CALL APT059(RESULT,PN,MA,MI,BETA,Z1)
      RETURN
       END