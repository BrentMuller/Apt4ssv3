**** SOURCE FILE : M0000907.V01   ***
*
C...  FORTRAN SUBROUTINE GCONE                   7/70      RW
C
C        CANONICAL FORM OF CONE
C        1. X-COORDINATE OF VERTEX                (XO)
C        2. Y-COORDINATE OF VERTEX                (YO)
C        3. Z-COORDINATE OF VERTEX                (ZO)
C        4. X-COMPONENT OF NORMALIZED AXIS VECTOR (A)
C        5. Y-COMPONENT OF NORMALIZED AXIS VECTOR (B)
C        6. Z-COMPONENT OF NORMALIZED AXIS VECTOR (C)
C        7. COSINE OF VERTEX HALF-ANGLE           (V)
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
C
      SUBROUTINE GCONE(CANON,QUADBF)
C
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      DIMENSION CANON(10),QUADBF(10)
C        INITIALIZATION
C
      XO=CANON(1)
      YO=CANON(2)
      ZO=CANON(3)
      A=CANON(4)
      B=CANON(5)
      C=CANON(6)
      V=CANON(7)
      DI=1.-C**2
      FR=V**2/(1.-V**2)
C
C     CHECK FOR DEFAULT CASE
C
      IF(A.NE.B) GO TO 10
      IF(A.NE.0) GO TO 10
C
      DO 2 J=1,2
    2 QUADBF(J)=FR
C
      QUADBF(3)= -1.0
C
      DO 3 J=4,6
    3 QUADBF(J)=0.0
C
      QUADBF(7)=-2.0*XO*FR
      QUADBF(8)=-2.0*YO*FR
      QUADBF(9)= 2.0*ZO
      QUADBF(10)=FR*XO**2+FR*YO**2-ZO**2
C
      GO TO 100
C
C     ALL OTHER CASES
C
   10 QUADBF(1)=FR*((C**2*A**2+B**2)/DI)-A**2
      QUADBF(2)=FR*((C**2*B**2+A**2)/DI)-B**2
      QUADBF(3)=FR*DI-C**2
      QUADBF(4)=-2.0*(B*C*FR+B*C)
      QUADBF(5)=-2.0*(A*C*FR+A*C)
      QUADBF(6)=2.0*(FR*((A*B*C**2-A*B)/DI)-A*B)
      QUADBF(7)=2.0*(FR*((-XO*A**2*C**2-YO*A*B*C**2-XO*B**2+YO*A*B)/DI+Z
     1O*A*C)+XO*A**2+YO*A*B+ZO*A*C)
      QUADBF(8)=2.0*(FR*((-YO*B**2*C**2-XO*A*B*C**2-YO*A**2+XO*A*B)/DI+Z
     1O*B*C)+YO*B**2+XO*A*B+ZO*B*C)
      QUADBF(9)=2.0*(FR*(-DI*ZO+XO*A*C+YO*B*C)+ZO*C**2+XO*A*C+YO*B*C)
      QUADBF(10)=FR*((XO**2*A**2*C**2+YO**2*B**2*C**2+2.0*XO*YO*A*B*C**2
     1+XO**2*B**2+YO**2*A**2-2.0*XO*YO*A*B)/DI+DI*ZO**2-2.0*XO*ZO*A*C-2.
     20*YO*ZO*B*C)-XO**2*A**2-YO**2*B**2-ZO**2*C**2-2.0*XO*YO*A*B-2.0*XO
     3*ZO*A*C-2.0*YO*ZO*B*C
C
C     ONLY ONE OF THE THREE SQUARED-TERM COEFFICIENTS SHOULD BE NEGATIVE
C     IF TWO ARE NEGATIVE, MULTIPLY THE EQUATION BY MINUS ONE.
C
      IT = 0
      IF (QUADBF(1) .LT. 0.0) IT=IT+1
      IF (QUADBF(2) .LT. 0.0) IT=IT+1
      IF (QUADBF(3) .LT. 0.0) IT=IT+1
      IF (IT .LE. 1) GO TO 100
      DO 60 I=1,10
 60   QUADBF(I) = -QUADBF(I)
 100  RETURN
      END
