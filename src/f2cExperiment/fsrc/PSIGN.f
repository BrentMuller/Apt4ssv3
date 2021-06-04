**** SOURCE FILE : M0002773.V01   ***
*
C....    FORTRAN FUNCTION SUBPROGRAM      PSIGN      4/1/69     RC
C
c      REAL FUNCTION PSIGN(A,B)
      real*8 function psign(a,b)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C  PURPOSE         TO MULTIPLY THE FIRST ARGUMENT BY THE SIGN OF THE
C                  SECOND ARGUMENT  -AND- IF THE SECOND ARGUMENT
C                  IS EQUAL TO ZERO, TO RETURN THE VALUE ZERO
C
C  LINKAGE         VALUE=PSIGN(A,B)
C
C  ARGUMENTS       A AND B ANY REAL VARIABLES
C
C  CALLED BY       QSD
C
C     ------------------------------------------------------------
C
      IF (B) 10,20,10
C
   10 PSIGN=DSIGN(A,B)
      RETURN
C
   20 PSIGN=0.0
      RETURN
      END
