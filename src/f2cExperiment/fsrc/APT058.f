**** SOURCE FILE : M0000808.V02   ***
*
C.....FORTRAN SUBROUTINE             APT058...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT058
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A HYPERBOLA
C              DEFINED AS HAVING A GIVEN CENTER POINT, GIVEN
C              LENGTHS OF SEMI-TRANSVERSE AND SEMI-CONJUGATE
C              AXIS, AND A GIVEN ANGLE BETWEEN THE TRANSVERSE
C              AXIS AND THE X AXIS BY THE FOLLOWING APT STATEMENT
C              RESULT = HYPERB/CENTER, PN, STA, SCA, BETA
C
C LINKAGE      CALL APT058 (RESULT, PN, STA, SCA, BETA)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF
C                      THE RESULTING HYPERBOLA
C              PN      ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT POINT
C              STA     REAL VARIABLE CONTAINING THE LENGTH
C                      OF SEMI-TRANSVERSE AXIS
C              SCA     REAL VARIABLE CONTAINING THE LENGTH OF
C                      THE SEMI-CONJUGATE AXIS
C              BETA    REAL VARIABLE CONTAINING THE ANGLE
C                      BETWEEN THE TRANSVERSE AXIS AND THE
C                      X AXIS (DEGREES)
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT059
C
      SUBROUTINE APT058 (RESULT,PN,STA,SCA,BETA)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(10),PN(3)
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'ZNUMBR.INC'
C
C
C
      CALL APT059(RESULT,PN,STA,SCA,BETA,ZM1)
      RETURN
       END
