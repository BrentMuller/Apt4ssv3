**** SOURCE FILE : M0004285.V01   ***
*
C
      SUBROUTINE COMPTW(BCN,P,U,V,IRR)
        IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C------THIS SUBROUTINE ACCEPTS AS INPUT A PARTIALLY DEFINED COONS
C------MATRIX ( TWIST VECTORS ARE STILL UNKNOWN ) AND FOUR SPACE
C------POINTS P(4,) EACH WITH ASSOCIATED U,V VALUES.
C------AFTER EXECUTION THE ROUTINE RETURNS WITH FOUR TWIST VECTORS
C------WHICH ARE LOADED INTO APPROPRIATE POSITIONS OF THE BCN MATRIX
C------ THE COONS MATRIX PASSES THRU THE FOUR INPUT POINTS
C------AT THE INPUT U,V PARAMETER VALUES
      DIMENSION BCN(3,4,4),P(4,3),U(4),V(4)
      DIMENSION RH(4,3), AM(4,4)
      IDIAG=5395
C------SET UP A 4 X 4 SYSTEM OF EQUATIONS AND SOLVE BY CALL TO GELG
      DO 100 I=1,4
C------EVALUATE COONS BLENDING FUNCTIONS FOR U(I) AND V(I)
      A2 = U(I)**2
      A3 = A2*U(I)
      D  = A3 - A2
      A  = D + D - A2 + 1
      B  = -A + 1
      C  = D - A2 + U(I)
      A2 = V(I)**2
      A3 = A2*V(I)
      H  = A3 - A2
      E  = H + H - A2 + 1
      F  = -E + 1
      G  = H - A2 + V(I)
C------NOW GENERATE THE I TH COEFFICIENT ROW
      AM(I,1) = C*G
      AM(I,2) = C*H
      AM(I,3) = D*G
      AM(I,4) = D*H
C------NOW GENERATE THE VECTOR COMPONENTS OF THE RIGHT HAND SIDE
      DO 100 L = 1, 3
      WA = ( BCN(L,1,1)*E + BCN(L,1,2)*F + BCN(L,1,3)*G
     1     + BCN(L,1,4)*H )*A
      WB = ( BCN(L,2,1)*E + BCN(L,2,2)*F + BCN(L,2,3)*G
     1     + BCN(L,2,4)*H )*B
      WC = ( BCN(L,3,1)*E + BCN(L,3,2)*F )*C
      WD = ( BCN(L,4,1)*E + BCN(L,4,2)*F )*D
C------RH IS THE DESIRED COEEFICIENT
      RH(I,L) = P(I,L) - WA - WB - WC - WD
  100 CONTINUE
      EPS=1.0D-13
      CALL GELG(RH,AM,EPS,4,3,IER)
      IRR = IDIAG + 1
      IF (IER .NE. 0) RETURN
C------RH NOW CONTAINS THE VECTOR SOLUTION SET (TWIST VECTORS)
C------FINALLY LOAD THESE INTO BCN MATRIX
      DO 200 I = 1, 4
      IR = 3
      IC = 3
      IF ( MOD(I,2) .EQ. 0 ) IC = 4
      IF ( I .GT. 2 ) IR = 4
      DO 200 L = 1, 3
      BCN(L,IR,IC) = RH(I,L)
  200 CONTINUE
      IRR = 0
      RETURN
      END