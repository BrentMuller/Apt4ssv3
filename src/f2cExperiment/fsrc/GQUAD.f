**** SOURCE FILE : M0000919.V01   ***
*
C...  FORTRAN SUBROUTINE GQUAD                   7/70      RW
C        CANONICAL FORM OF QUADRATIC
C        1. COEFFICIENT OF X**2 (A)
C        2. COEFFICIENT OF Y**2 (B)
C        3. COEFFICIENT OF Z**2 (C)
C        4. CONSTANT TERM       (D)
C        5. COEFFICIENT OF 2YZ  (F)
C        6. COEFFICIENT OF 2XZ  (G)
C        7. COEFFICIENT OF 2XY  (H)
C        8. COEFFICIENT OF 2X   (P)
C        9. COEFFICIENT OF 2Y   (Q)
C       10. COEFFICIENT OF 2Z   (R)
C
C        EQUATION
C
C        A*X**2+B*Y**2+C*Z**2+2*F*Y*Z+
C        2*G*X*Z+2*H*X*Y+2*P*X+2*Q*Y+
C        2*R*Z+D=0
C
C     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
C
      SUBROUTINE GQUAD(CANON,QUADBF)
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION (O-Z)
      DIMENSION CANON(10),QUADBF(10)
C
      DO 2 I=1,3
 2    QUADBF(I)=CANON(I)
      DO 5 I=4,9
 5    QUADBF(I)=CANON(I+1) * 2.0
      QUADBF(10)=CANON(4)
C
      RETURN
      END
