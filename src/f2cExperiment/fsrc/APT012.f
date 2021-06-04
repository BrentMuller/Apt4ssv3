**** SOURCE FILE : M0000762.V02   ***
*
C.....FORTRAN SUBROUTINE             APT012...              3/1/68   GK
C
C              FORTRAN SUBROUTINE APT012
C
C PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED
C              AS PASSING THROUGH TWO POINTS BY ONE OF THE
C              FOLLOWING APT STATEMENTS
C                  RESULT = LINE/X1, Y1, Z1, X2, Y2, Z2
C              OR  RESULT = LINE/X1, Y1, X2, Y2
C
C LINKAGE      CALL APT012 (RESULT, X1, Y1, X2, Y2)
C
C ARGUMENTS    RESULT  ARRAY TO CONTAIN CANONICAL FORM OF
C                      RESULTING LINE
C              X1      X COORDINATE OF THE FIRST INPUT POINT
C              Y1      Y COORDINATE OF THE FIRST INPUT POINT
C              X2      X COORDINATE OF THE SECOND INPUT POINT
C              Y2      Y COORDINATE OF THE SECOND INPUT POINT
C
C SUBSIDIARIES TYPE                ENTRY
C              SUBROUTINE          APT077
C              SUBROUTINE          DEFEXT
C              SUBROUTINE          VNORM
C              LOGICAL FUNCTION    ZVECT
C
      SUBROUTINE APT012 (RESULT,X1,Y1,X2,Y2)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION RESULT(4)
      LOGICAL ZVECT
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
C
C
C...     SET UP VECTOR
C
      V(1)=Y1-Y2
      V(2)=X2-X1
      V(3)=Z0
C
C...     CHECK POINTS TOO CLOSE (ALL VECTOR COMPONENTS LT .000001)
C
      IF (.NOT.ZVECT(V)) IERROR=K19
C
C...     NORMALIZE VECTOR
C
      CALL VNORM(V,V)
C
C...     COMPUTE RESULT(4) AND TRANSFORM IF NECESSARY  (APT077)
C
      V(4)=V(1)*X1+V(2)*Y1
      CALL APT077 (V,KM1)
   10 CALL DEFEXT (RESULT)
       RETURN
       END
