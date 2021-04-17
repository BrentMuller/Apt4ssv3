**** SOURCE FILE : M0000648.V01   ***
*
      SUBROUTINE PARMPT(PA,PD,PB,B,PC,C,TA,TD,IRR)
C------ A COMPLETELY MODULAR SCULPTURED SURFACE ROUTINE  APRIL 1970 JKH
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION PA(3),PB(3),PC(3),PD(3),DF(3),TA(3),TD(3)
C------ INPUT CONSISTS OF TWO END POINTS PA,PD AND TWO INTERIOR POINTS
C------PB WITH PARAMETER VALUE B AND PC WITH PARAMETER VALUE C THRU
C------WHICH A CUBIC CURVE MUST PASS.
C------OUTPUT CONSISTS OF TWO COONS TANGENT VECTORS TA AND TD WHICH
C-------DEFINE THE DESIRED CURVE.  A CASE OF TROUBLE IS THAT THE
C------PARAMETER VALUES B AND C ARE NEARLY EQUAL
      IDIAG=23000
      BSQ=B*B
      CSQ=C*C
      DISC = B * C * (B - 1) * (C - 1) * (B - C)
      IRR=IDIAG+1
      IF(DABS(DISC).LT.1.0D-12) RETURN
C------SET UP THE LINEAR EQUATION A * TA() + B * TB() = C()
      A1 = B * (1 - B)**2
      A2 = C * (1 - C)**2
      B1 = BSQ*(-1 + B)
      B2 = CSQ*(-1 + C)
      DO 20 I=1,3
   20 DF(I)=PD(I)-PA(I)
C------DETERMINE EACH COMPONENT OF TA() AND TD() BY SOLVING TWO EQUNS
C------IN TWO UNKNOWNS
      DO 10 I=1,3
      C1 = PB(I) - ( PA(I) + DF(I)*BSQ*(3 - 2*B) )
      C2 = PC(I) - ( PA(I) + DF(I)*CSQ*(3 - 2*C) )
      TA(I)=(C1*B2 -C2*B1)/DISC
      TD(I)=(A1*C2 - A2*C1)/DISC
   10 CONTINUE
      IRR=0
      RETURN
      END