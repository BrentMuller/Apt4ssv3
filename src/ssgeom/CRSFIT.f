**** SOURCE FILE : M0000621.V02   ***
*
      SUBROUTINE CRSFIT(SA,SB,SC,SD,IERROR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---     PURPOSE IS TO FILL OUT ALL CROSS SLOPE VECTORS IN
C---     THE CURVES SA,SB GIVEN THAT SA,SB  AND SC,SD FORM
C---     OPPOSITE PAIRS OF A FOUR SIDED PATCH.  ALL CURVES
C---     ARE SINGLE SEGMENT FLOW CURVES.
C---     IF AN ERROR IS ENCOUNTERED, IERROR IS NOT ZERO ON RETURN
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      DIMENSION SA(*),SB(*),SC(*),SD(*)
      DIMENSION VEC(3),VA(3),VB(3),CV(16)
      DATA ZERO,ONE,SMAL/0.0D0,1.0D0,1.0D-10/
C
C---     MAKE TWO PASSES, ONE FOR THE CURVE SA, THE OTHER FOR SB
C
      DATA ICT/0/
C
      IENT=IERROR
      IERROR=0
C
      ICT=ICT+10
      IF(IBUG.EQ.11) CALL SCDUMP(ICT,SA)
      IF(IBUG.EQ.11) CALL SCDUMP(2,SB)
      IF(IBUG.EQ.11) CALL SCDUMP(3,SC)
      IF(IBUG.EQ.11) CALL SCDUMP(4,SD)
      DO 10 IPASS=1,2
      U=IPASS-1
C---     PICK UP CROSS VECTORS AT ENDS FROM SC AND SD
      CALL CURFLO(U,SC,CV,1,1)
      DO 20 L=1,3
   20 VA(L)=CV(L+4)
      CALL CURFLO(U,SD,CV,1,1)
      DO 30 L=1,3
   30 VB(L)=CV(L+4)
C
C---     STORE THESE VECTORS INTO THE ENDS OF CURVE SA OR SB
      IF(IPASS.EQ.2) GO TO 350
C
      N1=16
      N2=(SA(2)+SA(4)-ONE)*24.+16.
      DO 310 L=1,3
      SA(N1+L)=VA(L)
  310 SA(N2+L)=VB(L)
      SA(N1+4)=ONE
      SA(N2+4)=ONE
      GO TO 390
C
  350 CONTINUE
      N1=16
      N2=(SB(2)+SB(4)-ONE)*24.+16.
      DO 320 L=1,3
      SB(N1+L)=VA(L)
  320 SB(N2+L)=VB(L)
      SB(N1+4)=ONE
      SB(N2+4)=ONE
  390 CONTINUE
C
C---      SKIP OTHER CALCULATIONS IF IENT IS -11
      IF(IENT.EQ.-11) GO TO 10
C
C---     DETERMINE N1,N2 THE STARTING AND ENDING ARC JUNCTIONS
      N1=0
      IF(IPASS.EQ.2) GO TO 40
      NARCRW=SA(7)
      NSEGRW=SA(9)
      N2=SA(NSEGRW+1)+N1
      GO TO 50
   40 CONTINUE
      NARCRW=SB(7)
      NSEGRW=SB(9)
      N2=SB(NSEGRW+1)+N1
   50 CONTINUE
C
C---     NLO,NHI REPRESENT JUNCTION PT LIMITS TO BE TESTED AND
C---     IF NECESSARY TO RECEIVE CROSS SLOPE VECTORS
      NLO=N1+1
      NHI=N2-1
      IF(NHI.LT.NLO) GO TO 10
C
      DO 60 K=NLO,NHI
      NROW=NARCRW+K*4
C
C---     DETERMINE FLOW VALUE OF THIS JUNCTION POINT
      IF(IPASS.EQ.2) GO TO 70
      NROW=SA(NROW)
      FLOVAL=SA(NROW)
      GO TO 80
   70 CONTINUE
      NROW=SB(NROW)
      FLOVAL=SB(NROW)
   80 CONTINUE
C---     DETERMINE THE BLEND OF END VECTORS BASED ON FLOVAL
      CALL BLENDF(FLOVAL,CV)
      DO 90 L=1,3
   90 VEC(L)=CV(1)*VA(L)+CV(2)*VB(L)
      WA=DSQRT(VEC(1)*VEC(1)+VEC(2)*VEC(2)+VEC(3)*VEC(3))
C
C---     NOW CHECK THIS JUNCTION FOR CONSTRAINT DATA ALREADY THERE
      J=K*24+16
      IF(IPASS.EQ.1) TEMP=SA(J+4)
      IF(IPASS.EQ.2) TEMP=SB(J+4)
      IF(DABS(TEMP-ONE).GT.SMAL) GO TO 100
C
C---     A CROSS VECTOR IS ALREADY PRESENT, MODIFY ITS LENGTH TO WA
      IF(IPASS.EQ.2) GO TO 110
      WB=DSQRT(SA(J+1)**2+SA(J+2)**2+SA(J+3)**2)
      IF(WB.LT.SMAL) GO TO 140
      WB=WA/WB
      DO 120 L=1,3
  120 SA(J+L)=WB*SA(J+L)
      GO TO 60
  110 CONTINUE
      WB=DSQRT(SB(J+1)**2+SB(J+2)**2+SB(J+3)**2)
      IF(WB.LT.SMAL) GO TO 140
      WB=WA/WB
      DO 130 L=1,3
  130 SB(J+L)=WB*SB(J+L)
      GO TO 60
C
  100 CONTINUE
      IF(IPASS.EQ.1) TEMP=SA(J+8)
      IF(IPASS.EQ.2) TEMP=SB(J+8)
      IF(DABS(TEMP-ONE).GT.SMAL) GO TO 140
C
C---     A SURFACE NORMAL CONSTRAINT IS PRESENT, PROJECT VEC
C---     INTO THE PLANE OF THIS NORMAL AND ASSIGN WA AS LENGTH
      IF(IPASS.EQ.2) GO TO 150
      WB=DSQRT(SA(J+5)**2+SA(J+6)**2+SA(J+7)**2)
      IF(WB.LT.SMAL) GO TO 140
      PROJ=(VEC(1)*SA(J+5)+VEC(2)*SA(J+6)+VEC(3)*SA(J+7))/WB
      SUM=ZERO
      DO 160 L=1,3
      VEC(L)=VEC(L)-PROJ*SA(J+4+L)/WB
  160 SUM=SUM+VEC(L)**2
      SUM=DSQRT(SUM)
      IF(SUM.LT.SMAL) GO TO 140
      WB=WA/SUM
      DO 170 L=1,3
  170 SA(J+L)=WB*VEC(L)
      GO TO 60
C
  150 CONTINUE
      WB=DSQRT(SB(J+5)**2+SB(J+6)**2+SB(J+7)**2)
      IF(WB.LT.SMAL) GO TO 140
      PROJ=(VEC(1)*SB(J+5)+VEC(2)*SB(J+6)+VEC(3)*SB(J+7))/WB
      SUM=ZERO
      DO 180 L=1,3
      VEC(L)=VEC(L)-PROJ*SB(J+4+L)/WB
  180 SUM=SUM+VEC(L)**2
      SUM=DSQRT(SUM)
      IF(SUM.LT.SMAL) GO TO 140
      WB=WA/SUM
      DO 190 L=1,3
  190 SB(J+L)=WB*VEC(L)
      GO TO 60
C
  140 CONTINUE
C---     USE VEC TO DETERMINE THE CROSS CONSTRAINT AT JUNCTION J
      IF(IPASS.EQ.2) GO TO 200
      DO 210 L=1,3
  210 SA(J+L)=VEC(L)
      SA(J+4)=ONE
      GO TO 60
  200 CONTINUE
      DO 220 L=1,3
  220 SB(J+L)=VEC(L)
      SB(J+4)=ONE
C
   60 CONTINUE
C
   10 CONTINUE
C
      IF(IBUG.EQ.11) CALL SCDUMP(5,SA)
      IF(IBUG.EQ.11) CALL SCDUMP(6,SB)
C
      IERROR=0
      RETURN
      END
