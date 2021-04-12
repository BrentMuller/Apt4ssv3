**** SOURCE FILE : M0008176.V01   ***
*
      SUBROUTINE KRUMM(SPV,E,F,G,XL,XM,XN,HKR,RK1,RK2)
C
C SUBROUTINE FOR THE OUTPUT OF THE CURVING OF PATCHES
C
C  SPV :   SURFACE POINTS AND DERIVATIVES
C  E   :   COEFFICIENTS OF FIRST AND SECOND GAUSSIAN FUNDAMENTAL FORM
C  F   :
C  G   :
C  XL  :
C  XM  :
C  XN  :
C  HKR :   MAIN CURVATURE DIRECTION
C  RK1 :   1.CURVATURE
C  RK2 :   2.CURVATURE
C
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
      DOUBLE PRECISION SPV(4,8),HKR(3)
C  HELP STORAGE
      DOUBLE PRECISION VT(3),VT2(3)
C
C  COMPUTATION OF THE FUNDAMENTAL COEFFICIENTS
      E=0.D0
      F=0.D0
      G=0.D0
      XL=0.D0
      XN=0.D0
      XM=0.D0
      DO 7002 I=1,3
      SUPI=SPV(I,2)
      SVPI=SPV(I,3)
      E=SUPI*SUPI+E
      F=SUPI*SVPI+F
      G=SVPI*SVPI+G
      XNORM=SPV(I,8)
      XL=SPV(I,4)*XNORM+XL
      XM=SPV(I,5)*XNORM+XM
      XN=SPV(I,6)*XNORM+XN
 7002 CONTINUE
C   THE LENGTH OF THE NORMAL
      XNL=DSQRT(E*G-F*F)+1.D-12
C   COMPUTATION OF ONE MAIN CURVATURE DIRECTION
C   A=G*M-F*N
      A=G*XM-F*XN
C   B=G*L-E*N
      B=G*XL-E*XN
C   C=F*L-E*M
      C=F*XL-E*XM
      T1=B*B-4.D0*A*C
      T2=DSQRT(T1)
      T3=E*B-2.D0*F*C
      IF(T3.LT.0.D0)T2=-T2
      T4=DSQRT(2.D0*E*E*T1+2.D0*E*T3*T2)
      IF(DABS(T4).GT.0.D-20) GOTO 7060
C   NO MAIN DIRECTION GIVEN
      SINALF=0.D0
      COSALF=1.D0
      GOTO 7070
 7060 SINALF=(T3+E*T2)/T4
      COSALF=(2.D0*C*XNL)/T4
 7070 WE=DSQRT(E)
      DO 7300 I=1,3
C  U-TANGENT
 7300 VT(I)=SPV(I,2)/WE
C  VECTOR, PERPENTICULAR TO U-TANGENT
      CALL KREUZ(SPV(1,8),VT,VT2)
C   DIRECTION OF 1. MAIN CURVATURE
      DO 7310 I=1,3
 7310 HKR(I)=COSALF*VT(I)+SINALF*VT2(I)
C  COMPUTATION OF 1.CURVATURE:
      DV=E*SINALF
      DU= XNL*COSALF-F*SINALF
      RK1=(XL*DU*DU+2.D0*XM*DU*DV+XN*DV*DV)/
     *        (E*DU*DU+2.D0*F*DU*DV+G*DV*DV)
C  COMPUTATION OF 2.CURVATURE:
      DV=E*COSALF
      DU=-XNL*SINALF-F*COSALF
      RK2=(XL*DU*DU+2.D0*XM*DU*DV+XN*DV*DV)/
     *        (E*DU*DU+2.D0*F*DU*DV+G*DV*DV)
C
      RETURN
      END