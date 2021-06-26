**** SOURCE FILE : M0000918.V01   ***
*
C...  FORTRAN SUBROUTINE GPLANE                  6/70      RW
C
C  PURPOSE
C        THIS SUBROUTINE TRANSLATES THE CANONICAL FORMS
C        OF THE APT GEOMETRY (PLANE) INTO THE COEFFICIENTS OF
C        THE QUADRATIC. COEFFICIENTS ARE STORED
C        IN "QUADBF".
C        SUBROUTINE IS CALLED.
C
C        THE CANONICAL FORM OF PLANE IS C*X + C*Y + C*Z + D = 0
C        QUADRATIC EQUATION IS C*X + C*Y + C*Z - D = 0
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
C
      SUBROUTINE GPLANE(CANON,QUADBF)
C
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      DIMENSION CANON(10),QUADBF(10)
C
C        ZERO COEFFICIENTS
C
      DO 5 J=1,6
 5    QUADBF(J)=0.0
C
C        TEST FOR NEGATIVE COEFFICIENTS
C
      M = 0
      DO 6 J = 1,3
      IF (CANON(J).LT. 0.0) M = M - 1
      IF (CANON(J).GT. 0.0) M = M + 1
 6    CONTINUE
C
C        IF A MAJORITY OF COEFFICIENTS ARE NEGATIVE, MULTIPLY BY -1
      S = 1.0
      IF (M.LT.0) S = -1.0
      QUADBF(7) = S * CANON(1)
      QUADBF(8) = S * CANON(2)
      QUADBF(9) = S * CANON(3)
      QUADBF(10)=-S * CANON(4)
C
C
C     RETURN TO CALLING PROGRAM
C
 8    RETURN
      END