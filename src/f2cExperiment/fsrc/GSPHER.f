**** SOURCE FILE : M0000920.V01   ***
*
C...  FORTRAN SUBROUTINE GSPHER                  7/70      RW
C
C  PURPOSE
C        THIS SUBROUTINE TRANSLATES THE CANONICAL FORMS
C        OF THE APT GEOMETRY (SPHERE) INTO THE COEFFICIENTS
C        OF THE QUADRATIC. COEFFICIENTS ARE STORED IN
C        "QUADBF" AND THE QUADRATIC OUTPUT
C        SUBROUTINE IS CALLED.
C
C
C        CANONICAL FORM OF SPHERE
C        1. X-COORDINATE OF CENTER OF SPHERE     (XC)
C        2. Y-COORDINATE OF CENTER OF SPHERE     (YC)
C        3. Z-COORDINATE OF CENTER OF SPHERE     (ZC)
C        4. RADIUS OF SPHERE                     (R)
C
C        EQUATION
C        X**2 + Y**2 + Z**2 - 2XC*X - 2YC*Y - 2ZC*Z +
C                            (XC**2 + YC**2 + ZC**2 - R**2)
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
C
      SUBROUTINE GSPHER(CANON,QUADBF)
C
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      DIMENSION CANON(10),QUADBF(10)
C
      DO 2 J=1,3
 2    QUADBF(J)=1.0
C
      DO 3 J=4,6
 3    QUADBF(J)=0.0
C
C        COMPUTE C*X TERM
C
      KX=1
      KY=2
      KZ=3
      KR=4
      QUADBF(7)=CANON(KX)*(-2.0)
C
C        COMPUTE C*Y TERM
C
      QUADBF(8)=CANON(KY)*(-2.0)
C
C        COMPUTE C*Z TERM
C
      QUADBF(9)=CANON(KZ)*(-2.0)
C
C        COMPUTE CONSTANT TERM
C
      QUADBF(10)=(CANON(KX)**2)+(CANON(KY)**2)+(CANON(KZ)**2)
      QUADBF(10)=QUADBF(10)-(CANON(KR)**2)
C
C        RETURN TO CALLING PROGRAM
C
      RETURN
      END
