**** SOURCE FILE : M0002848.V02   ***
*
C.....FORTRAN SUBROUTINE             LNTHF....              3/1/68   GK
C
C              FORTRAN SUBROUTINE LNTHF
C
C PURPOSE      TO COMPUTE THE LENGTH OF A VECTOR.
C
C LINKAGE      CALL LNTHF (RES, ARG)
C
C ARGUMENTS    RES     REAL VARIABLE TO CONTAIN THE RESULT
C              ARG     ARRAY CONTAINING THE CANONICAL FORM OF
C                      THE INPUT VECTOR
C
C SUBSIDIARIES TYPE                ENTRY
C              LOGICAL FUNCTION    CKDEF
C              SUBROUTINE          ERROR
C              REAL FUNCTION       SQRT
      SUBROUTINE LNTHF (RES,ARG)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION ARG(3)
      LOGICAL CKDEF
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C
C...     CHECK DEFINITION OF INPUT VECTOR
C
      IF (CKDEF(ARG)) GO TO 20
C
C...     COMPUTE LENGTH OF VECTOR
C
      RES=DSQRT(ARG(1)**2+ARG(2)**2+ARG(3)**2)
      GO TO 9
C
C...     DIAGNOSE UNDEFINED INPUT
C
   20 CALL ERROR( 56,'LNTHF   ')
      RES= Z0
    9 RETURN
       END
