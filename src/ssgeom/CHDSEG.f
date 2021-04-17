**** SOURCE FILE : M0001049.V04   ***
*
      SUBROUTINE CHDSEG(C,FL,TOLR,NUM,NUMAX,IRR,P,D,V)
C---     SUBROUTINE PURPOSE IS TO PARAMETERIZE A RATIONAL CUBIC
C---     ARC IN TERMS OF A PROJECTION IN DIRECTION V UPON AN
C---     ARBITRARY LINE IN SPACE DETERMINED BY A POINT P AND
C---      A DIRECTION VECTOR D
C---     INPUT  C IS A RATIONAL PARAMETRIC CUBIC CURVE C
C---     INPUT  NUMAX IS THE MAXIMUM NUMBER OF ARCS WHICH CAN
C---            BE GENERATED(DUE TO BUFFER SPACE)
C---    INPUT  TOLR THE TOLERANCE TO BE USED IN FITTING(.001 NORMAL)
C---    OUTPUT IRR ERROR FLAG, ZERO IS CORRECT, NONZERO IS ERROR.
C---     OUTPUT IS A SET OF FLOW FUNCTIONS FL(4,NUM) WHERE
C---     FL(1,) IS ACCUMULATED CHORD LENGTH
C---     FL(2,) IS CORRESPONDING COONS PARAMETER
C---     FL(3,) IS RATE OF CHANGE OF PARAMETER
C---     FL(4,) IS SECOND DERIVATIVE.
C---  OUTPUT  NUM IS USUALLY NUMBER OF SEGMENTS, NEGATIVE IS ERROR.
C
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION C(16),FL(4,1),P(3),V(3),D(3)
      DIMENSION T(3),CV(16)
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
      DATA ZERO,ONE,SMAL,VSMAL,HALF/0.0D0,1.0D0,1.0D-6,1.0D-30,0.5D0/
C
C---     METHOD IS TO SPLIT ARC INTO SMALLER AND SMALLER SUBARCS
C---     UNTIL WHOLE ARC HAS BEEN FIT TO ACCEPTABLE ACCURACY.
C---     BEGIN BY DEVELOPING VECTOR CONSTANTS
C
      A=DSQRT(V(1)*V(1)+V(2)*V(2)+V(3)*V(3))
      IRR=2
      IF(A.LT.VSMAL) GO TO 999
      T(1)=V(1)/A
      T(2)=V(2)/A
      T(3)=V(3)/A
C
      IF(IBUG.NE.11) GO TO 2
      CALL BAD(3,1,'P   ',P)
      CALL BAD(3,1,'D   ',D)
      CALL BAD(3,1,'V   ',V)
      CALL BAD(-3,1,'T   ',T)
    2 CONTINUE
C
      IRR=3
      DT=D(1)*T(1)+D(2)*T(2)+D(3)*T(3)
      IF(DABS(DT).LT.VSMAL) GO TO 999
      NOW=1
      CHDLEN=ZERO
      UNOW=ZERO
      CALL CNCURV(UNOW,C,CV,1)
C---     CHECK FOR VALIDITY OF PROJECTION
      TEMP=CV(13)*T(1)+CV(14)*T(2)+CV(15)*T(3)
      IF(TEMP.GT.SMAL) GO TO 5
      IRR=4
      IF(DABS(TEMP).LT.SMAL) GO TO 999
C---     REVERSE THE DIRECTION OF T
      DO 6 I=1,3
    6 T(I)=-T(I)
      DT=-DT
    5 CONTINUE
      IF(DT.GT.ZERO) GO TO 8
      DO 7 I=1,3
    7 D(I)=-D(I)
      DT=-DT
    8 CONTINUE
C
C---     DETERMINE PROJECTION VALUE AND DERIVATIVES
      FL(1,NOW)=(CV(1)-P(1))*T(1)+(CV(2)-P(2))*T(2)+(CV(3)-P(3))*T(3)
      FL(1,NOW)=FL(1,NOW)/DT
      A=(CV(5)*T(1)+CV(6)*T(2)+CV(7)*T(3))/DT+VSMAL
      B=(CV(9)*T(1)+CV(10)*T(2)+CV(11)*T(3))/DT
      FL(2,NOW)=UNOW
      FL(3,NOW)=ONE/A
      FL(4,NOW)=-B/(A**3)
      CNOW=FL(1,NOW)
      UNX=.76
C
   40 CONTINUE
      ICHK=1
   50 CONTINUE
      CALL CNCURV(UNX,C,CV,1)
      NX=NOW+1
C---     CHECK FOR VALIDITY OF PROJECTION
      TEMP=CV(13)*T(1)+CV(14)*T(2)+CV(15)*T(3)
C---     ERROR IF CURVE IS MOVING IN OPPOSITE DIRECTION TO CHORD
      IRR=5
      IF(TEMP.LT.SMAL) GO TO 999
C---     DETERMINE PROJECTION VALUE AND DERIVATIVES
      FL(1,NX)=((CV(1)-P(1))*T(1)+(CV(2)-P(2))*T(2)+(CV(3)-P(3))*T(3))
      FL(1,NX)=FL(1,NX)/DT
      A=(CV(5)*T(1)+CV(6)*T(2)+CV(7)*T(3))/DT+VSMAL
      B=(CV(9)*T(1)+CV(10)*T(2)+CV(11)*T(3))/DT
      FL(2,NX)=UNX
      FL(3,NX)=ONE/A
      FL(4,NX)=-B/(A**3)
C---     FIRST CHECK ACCURACY OF SPLINE REPRESENTATION
      DEL1=FL(1,NX)-CNOW
      DEL2=3.*(FL(2,NX)-FL(2,NOW))*(FL(4,NX)+FL(4,NOW))
      DV=FL(4,NX)*(2.*FL(3,NOW)+FL(3,NX))+FL(4,NOW)*(FL(3,NOW)+2.*
     X   FL(3,NX))
      IF(DABS(DV).LT.VSMAL) GO TO 59
      DEL2=DEL2/DV
C---     IF SECOND DERIVATIVES VANISH, ANOTHER FORMULA IS NEEDED
      GO TO 60
   59 CONTINUE
      DEL2=ZERO
      IF(DABS(FL(3,NOW)).GT.VSMAL*SMAL) DEL2=ONE/FL(3,NOW)
      IF(DABS(FL(3,NX)).GT.VSMAL*SMAL) DEL2=DEL2+ONE/FL(3,NX)
      IRR=4
      IF(DEL2.EQ.ZERO) GO TO 999
   60 CONTINUE
C
C---     COMPARE ACCURACY OF ACTUAL AND ESTIMATED CHORD LENGTH.
C
      DIF=(DEL2-DEL1)/DEL1
      IF(IBUG.NE.11) GO TO 22
      CALL BAD(-4,1,'FLNW',FL(1,NOW))
      CALL BAD(-4,1,'FLNX',FL(1,NX))
      CALL BAD(1,1,'DEL1',DEL1)
      CALL BAD(1,1,'DEL2',DEL2)
      CALL BAD(-1,1,'DIF ',DIF)
   22 CONTINUE
      IF(DABS(DIF).GT.TOLR) GO TO 100
C---     ACCURACY IS ACCEPTABLE, IS SPLINE ALSO INCREASING THO.
      IF(FL(2,NX).LE.FL(2,NOW)) GO TO 100
      IF(FL(3,NOW).LT.ZERO) GO TO 100
      IF(FL(3,NX).LT.ZERO) GO TO 100
C---     NOW CHECK FOR A MAX OR MIN WITHIN THE INTERVAL
      A=FL(3,NOW)*DEL1
      B=FL(3,NX)*DEL1
      AA=3.*(B+A-2.*(FL(2,NX)-FL(2,NOW)))+VSMAL
      BB=2.*(3.*(FL(2,NX)-FL(2,NOW))-2.*A-B)
      CC=A
      DISC=BB*BB-4.*AA*CC
      IF(IBUG.NE.11) GO TO 33
      CALL BAD(-1,0,' ',0)
      CALL BAD(1,1,'AA  ',AA)
      CALL BAD(1,1,'BB  ',BB)
      CALL BAD(1,1,'CC  ',CC)
      CALL BAD(-1,1,'DISC',DISC)
   33 CONTINUE
      IF(DISC.LT.ZERO) GO TO 90
      DISC=DSQRT(DISC)
      R=(-BB-DISC)/(2.*AA)
      IF(DABS(R-HALF).LT.HALF) GO TO 100
      R=(-BB+DISC)/(2.*AA)
      IF(DABS(R-HALF).LT.HALF) GO TO 100
   90 CONTINUE
C---     FUNCTION MEETS ALL CRITERIA, SO GO AFTER THE NXT ARC
      NOW=NOW+1
      CNOW=FL(1,NOW)
      FL(1,NOW)=DEL2+CHDLEN
      CHDLEN=CHDLEN+DEL2
      UDEL=UNX-UNOW
      UNOW=UNX
      UNX=UNOW+4.0*UDEL
      UNX=DMIN1(ONE,UNX)
      IF(UNOW.GT.ONE-SMAL) GO TO 500
      IRR=6
      IF(NOW.GT.NUMAX-2) GO TO 999
      GO TO 40
C
C---     DECREASE UNX AND TRY AGAIN
  100 CONTINUE
      UNX=(UNOW+UNX)*HALF
      ICHK=ICHK+1
      IRR=7
      IF(ICHK.GT.10) GO TO 999
      GO TO 50
C
  500 CONTINUE
      IRR=0
      FL(2,NOW)=ONE
C---     TRANSLATE FLOW RATES TO ORIGIN
      FL(1,1)=ZERO
  999 CONTINUE
      NUM=NOW
      RETURN
      END