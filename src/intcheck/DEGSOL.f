**** SOURCE FILE : DEGSOL.ORG   ***
*
      SUBROUTINE DEGSOL(V,V1,V2,A,B,IFLAG)
C     SOLVES DEGENERATE EQN. SYSTEM  A.V1 + B.V2 = V
C     WHERE V, V1, V2, 3-D VECTORS AND A,B SCALARS
C     FOR NO SOLUTION, IFLAG SET TO 1, ELSE ZERO
C
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C
      DIMENSION V1(3),V2(3),V(3)
C
      PARAMETER (ETA=1E-10)
C
      IFLAG=0
      A=0
C.... CHOOSE LARGEST ABS(DET)
      DO 10 J=1,2
        DO 10 K=J+1,3
          B=V1(J)*V2(K)-V1(K)*V2(J)
          IF (ABS(B).GT.ABS(A)) THEN
            A=B
            JA=J
            KA=K
          END IF
10    CONTINUE
C
      IF (ABS(A).LT.ETA .OR. JA.EQ.O) THEN
            IFLAG=1
      ELSE
            B=(V1(JA)*V(KA)-V1(KA)*V(JA))/A
            A=(V(JA)*V2(KA)-V(KA)*V2(JA))/A
      END IF
C
      END
