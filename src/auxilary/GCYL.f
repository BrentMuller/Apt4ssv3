**** SOURCE FILE : M0000909.V01   ***
*
C...  FORTRAN SUBROUTINE GCYL                    6/70      RW
C
C        CANONICAL FORM OF CYLINDER
C        1. X-COORDINATE OF POINT ON AXIS         (XO)
C        2. Y-COORDINATE OF POINT ON AXIS         (YO)
C        3. Z-COORDINATE OF POINT ON AXIS         (ZO)
C        4. X-COMPONENT OF NORMALIZED AXIS VECTOR (A)
C        5. Y-COMPONENT OF NORMALIZED AXIS VECTOR (B)
C        6. Z-COMPONENT OF NORMALIZED AXIS VECTOR (C)
C        7. RADIUS OF CYLINDER                    (R)
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
      SUBROUTINE GCYL(CANON,QUADBF)
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      DIMENSION CANON(10),QUADBF(10)
C
C        INITALIZATION
C
      XO=CANON(1)
      YO=CANON(2)
      ZO=CANON(3)
      A=CANON(4)
      B=CANON(5)
      C=CANON(6)
      R=CANON(7)
      DI=1.-C**2
C
C
C       DEFAULT CASE
C
      IF(A.NE.B)GO TO 10
      IF(A.NE.0)GO TO 10
C
      DO 2 J=1,2
    2 QUADBF(J)=1.0
C
      DO 3 J=3,6
    3 QUADBF(J)=0.0
C
      QUADBF(7)=-2.0*XO
      QUADBF(8)=-2.0*YO
      QUADBF(9)=0.0
      QUADBF(10)=XO**2+YO**2-R**2
C
      GO TO 50
C
C
C
   10 QUADBF(1)=(A**2*C**2+B**2)/DI
C
      QUADBF(2)=(B**2*C**2+A**2)/DI
C
      QUADBF(3)=DI
C
      QUADBF(4)=-2.0*B*C
C
      QUADBF(5)=-2.0*A*C
C
      QUADBF(6)=2.0*((A*B*C**2-A*B)/DI)
C
      QUADBF(7)=2.0*((-XO*A**2*C**2-YO*A*B*C**2-XO*B**2+YO*A*B)/DI+ZO*A*
     1C)
C
      QUADBF(8)=2.0*((-YO*B**2*C**2-XO*A*B*C**2+XO*A*B-YO*A**2)/DI+ZO*B*
     1C)
C
      QUADBF(9)=2.0*(-ZO*DI+A*C*XO+YO*B*C)
C
      QUADBF(10)=(XO**2*A**2*C**2+YO**2*B**2*C**2+2.0*XO*YO*A*B*C**2+XO*
     1*2*B**2-2.0*XO*YO*A*B+YO**2*A**2)/DI+ZO**2*DI-2.0*XO*ZO*A*C-2.0*YO
     2*ZO*B*C-R**2
C
 50    CONTINUE
C       RETURN TO CALLING PROGRAM
      RETURN
      END
