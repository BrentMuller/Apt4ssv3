**** SOURCE FILE : M0004143.V04   ***
*
      SUBROUTINE SSPLIN(S,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION S(4,6,31)
C------ S IS AN INPUT ARRAY CONTAINING ALL POINTS AND CONSTRAINTS
C------ FOR A SPLINE FIT
C------ UPON RETURN S CONTAINS ALL OF THE PROCESSED OUTPUT DATA
C------ IRR IS AN ERROR INDICATOR.  ON  RETURN IRR IS ZERO IF
C------ NO ERRORS OCCURRED DURING PROCESSING WHILE IF AN
C------ ERROR DID OCCUR IRR GIVES THE APPROPRIATE ERROR NUMBER
C------ THE STRUCTURE OF S( IC, IL, IB ) IS AS FOLLOWS
C------ IB IS THE BLOCK OR POINT NUMBER( THE FIRST BLOCK IS A
C------ HEADER)
C------ IL  IS THE LINE NUMBER OF THE BLOCK
C------ IC IS THE COORDINATE NUMBER OF THE LINE
C------ ON INPUT S IS STRUCTURED AS FOLLOWS
C      S(1-3,1,2) = X,Y,Z OF THE INPUT POINT
C      S(1-4,2,2) = I,J,K OF TANSPL CONSTRAINT AND INDICATOR(0 OR 1)
C      S(1-4,3,2) = I,J,K OF CRSSPL CONSTRAINT AND INDICATOR(0 OR 1)
C      S(1-4,4,2) = I,J,K OF NORMAL CONSTRAINT AND INDICATOR(0 OR 1)
C      S(1,5,2) = WEIGHT FACTOR FOR SMOOTHING
C      S(2,5,2) = LIMIT FACTOR TO LIMIT MOVEMENT IN SMOOTHING
C      S(1-4,6,2) ,S(4,1,2) AND S(3-4,5,2) ARE NOT INITIATED INPUT
C------ OUTPUT CONTAINS THE FOLLOWING ADDITIONAL INFORMATION
C      S(1-3,1,2) = X,Y,Z OF THE SMOOTHED INPUT POINT
C      S(4,1,2)   = DISTANCE FROM THIS POINT TO THE NEXT
C      S(1-3,2,2) = I,J,K OF UNIT TANGENT VECTOR GENERATED AT THE PT
C      S(1,5,2) = WEIGHT WHICH GIVES CERTITUDE(1.0)
C      S(2,5,2) = INPUT LIMIT
C      S(3,5,2) = ORIGINAL INPUT WEIGHT
C      S(4,5,2) =  MEASUREMENT OF WILDNESS RELATIVE TO ADJACENT POINTS
C      S(1-3,6,2) = X,Y,Z OF THE ORIGINAL INPUT POINT
C      S(4,6,2)   = DISTANCE OF OUTPUT POINT FROM INPUT
C------ THE HEADER CONTAINS THE FOLLOWING INFORMATION
C      S(2,1,1) = LENGTH OF THE HEADER TABLE IN BLOCKS(=1)
C      S(3,1,1) = ORIGIN OF CALL  SSURF/MESH = 1, SCURV/SPLINE=2
C                 SCURV/CURSEG =3
C      S(4,1,1) = NUMBER OF POINT BLOCKS USED(GE.2)
      DIMENSION P(3,30),W(30),D(30),TV(3,2),V(3,30)
      DIMENSION T(3),TA(3),TB(3)
C------ LOGICAL FLAGS ARE TRUE WHEN NO CONSTRAINT IS PRESENT
C------ ID(1,I) TRUE MEANS THERE IS NO TANSPL CONSTRAINT AT ITH PT
C------ ID(2,I) TRUE MEANS THERE IS NO CRSSPL CONSTRAINT AT ITH PT
C------ ID(3,I) TRUE MEANS THERE IS NO NORMAL CONSTRAINT AT ITH PT
      LOGICAL ITAN,ICRS,INOR,IWGT,ILIM,ID(3,31)
      DATA SMAL1,SMAL2/1.0D-8,1.0D-12/
      NP=S(4,1,1)
      IORG=S(3,1,1)
      NHD=S(2,1,1)
      NTOT=NP+NHD
      NPL=NHD+1
      NPLP=NPL+1
      NPH=NTOT
      NPHM=NPH-1
C------ MOVE INPUT POINTS INTO SIXTH LINE FOR SAVING
      DO 30 I=NPL,NPH
      S(4,6,I)=0.0
      DO 20 L=1,3
   20 S(L,6,I)=S(L,1,I)
   30 CONTINUE
C------ THERE SHOULD BE AT LEAST TWO POINTS IN A SPLINE
      IRR=5901
      IF(NP.LT.2) GO TO 998
C------ CHECK FOR IDENTICAL POINTS
      IF(IORG.EQ.3) GO TO 200
 10   IRR=5902
      DO 100 I=NPL,NPHM
      INX=I+1
      SUM=0.0
      DO 110 L=1,3
      SUM=SUM+(S(L,1,INX)-S(L,1,I))**2
  110 CONTINUE
      IF(SUM.LT.SMAL1) GO TO 998
  100 CONTINUE
      GO TO 300
  200 CONTINUE
C------ CHECK FOR ANY TWO POINTS IDENTICAL IN CURSEG CASE
      IRR=5903
      DO 210 I=NPL,NPHM
      INX=I+1
      DO 210 J=INX,NPH
      SUM=0.0
      DO 220 L=1,3
      SUM=SUM+(S(L,1,J)-S(L,1,I))**2
  220 CONTINUE
      IF(SUM.LT.SMAL1) GO TO 998
  210 CONTINUE
  300 CONTINUE
C------ DETERMINE THE PRESENCE OF CONSTRAINTS OF DIFFERENT TYPES
C1----- IF A FLAG IS TRUE THEN THERE IS NO CONSTRAINT OF THIS TYPE
      INOR=.TRUE.
      ITAN=.TRUE.
      ICRS=.TRUE.
      IWGT=.TRUE.
      ILIM=.TRUE.
      DO 340 I=NPL,NPH
      DO 340 K=1,3
      KK=K+1
      DUM=S(4,KK,I)-1.0
      DUM=DABS(DUM)
      ID(K,I)=.TRUE.
      IF(DUM.GT.SMAL1) GO TO 340
      ID(K,I)=.FALSE.
  340 CONTINUE
      DO 310 I=NPL,NPH
      IF(.NOT.ID(1,I)) ITAN=.FALSE.
      IF(.NOT.ID(2,I)) ICRS=.FALSE.
      IF(.NOT.ID(3,I)) INOR=.FALSE.
C---  CII UPDATE TO INITIALIZE WT AND LIM. NIU-APR/75E
      IF(DABS(S(1,5,I)-1.0).GT.SMAL1) IWGT=.FALSE.
      IF(DABS(S(2,5,I)).GT.SMAL1) ILIM=.FALSE.
  310 CONTINUE
C------ SKIP THE NEXT SECTION IF WEIGHTS ARE NOT EFFECTED
      IF(IWGT) GO TO 500
C------ WEIGHTS ARE PRESENT, MAKE A SMOOTHING PASS TO OBTAIN NEW
C------ POINT POSITIONS
  400 CONTINUE
      DO 420 I=NPL,NPH
      DO 410 L=1,3
      DO 410 J=1,2
  410 TV(L,J)=0.0
      J=I-NHD
      W(J)=S(1,5,I)
      S(3,5,I)=W(J)
      DO 420 L=1,3
  420 P(L,J)=S(L,1,I)
      IDC=5
      CALL SMOOTH(P,W,D,TV,V,NP,IDC)
      IRR=5904
      IF(IDC.LT.0) GO TO 998
C------ RELOAD NEW POINTS INTO THE S ARRAY
      DO 430 I=NPL,NPH
      J=I-NHD
      S(1,5,I)=1.0
      IF(ILIM) GO TO 450
C------ VAL IS THE DISTANCE BETWEEN THE OLD POINT AND NEW POINT
      VAL=DSQRT((P(1,J)-S(1,1,I))**2+(P(2,J)-S(2,1,I))**2
     X          +(P(3,J)-S(3,1,I))**2)
      IF(VAL.LE.DABS(S(2,5,I))) GO TO 450
C------ BRING THE POINT BACK INTO THE LIMITED SPHERE AROUND THE OLD
      VAL=DABS(S(2,5,I))/VAL
      DO 440 L=1,3
  440 P(L,J)=S(L,1,I)+VAL*(P(L,J)-S(L,1,I))
      VAL=DABS(S(2,5,I))
  450 CONTINUE
      DO 460 L=1,3
      S(L,6,I)=S(L,1,I)
      S(L,1,I)=P(L,J)
  460 CONTINUE
      S(4,6,I)=VAL
  430 CONTINUE
C------ NOW RECYCLE THRU PRIOR LOGIC WITH NEW POINTS AND NO WEIGHTS
      GO TO 10
  500 CONTINUE
      IF(INOR.AND.ICRS.AND.ITAN) GO TO 700
C------ CHECK FOR NULL CONSTRAINT VECTORS AND UNITIZE ALL
      IRR=5905
      DO 600 I=NPL,NPH
      DO 630 K=2,4
      IF(ID(K-1,I)) GO TO 630
      SUM=S(1,K,I)**2+S(2,K,I)**2+S(3,K,I)**2
      IF(SUM.LT.SMAL1) GO TO 998
      SUM=DSQRT(SUM)
      DO 620 L=1,3
  620 S(L,K,I)=S(L,K,I)/SUM
  630 CONTINUE
  600 CONTINUE
  700 CONTINUE
C------ REORIENT TANSPL VECTORS BASED ON THE DIRECTION INDICATED BY PTS
      IF(ITAN) GO TO 790
      DO 710 I=NPL,NPH
      IF(ID(1,I)) GO TO 710
      NLO=MAX0(I-1,NPL)
      NHI=MIN0(I+1,NPH)
      SUM=0.0
      DO 720 L=1,3
      T(L)=S(L,1,NHI)-S(L,1,NLO)
      SUM=SUM+T(L)*S(L,2,I)
  720 CONTINUE
      IF(SUM.GE.0.0) GO TO 710
C------ REORIENT THIS TANGENT CONSTRAINT
      DO 730 L=1,3
  730 S(L,2,I)=-S(L,2,I)
  710 CONTINUE
  790 CONTINUE
      IRR=5909
C------ GENERATE A TANSPL CONSTRAINT WHEREEVER A NORMAL IS PRESENT
      IF(INOR) GO TO 980
      DO 910 I=NPL,NPH
C------ IF THERE ALREADY IS A TANSPL CONTRAINT OR NO NORMAL, SKIP
      IF(.NOT.ID(1,I).OR.ID(3,I)) GO TO 910
      NLO=MAX0(I-1,NPL)
      NHI=MIN0(I+1,NPH)
      IF(NHI-NLO.GT.1) GO TO 920
      DO 930 L=1,3
  930 T(L)=S(L,1,NHI)-S(L,1,NLO)
      GO TO 950
  920 CALL PARINT(S(1,1,NLO),S(1,1,I),S(1,1,NHI),T,DUM,2,IRRR)
      IF(IRRR.NE.0) GO TO 998
  950 VAL=T(1)*S(1,4,I)+T(2)*S(2,4,I)+T(3)*S(3,4,I)
      DO 960 L=1,3
  960 T(L)=T(L)-VAL*S(L,4,I)
      CALL SNORM(T,S(1,2,I),IRRR)
      IF(IRRR.NE.0) GO TO 998
      ID(1,I)=.FALSE.
      S(4,2,I)=-1.0
  910 CONTINUE
  980 CONTINUE
      IF(IORG.EQ.3) GO TO 900
C END TANGENTS ARE NOT GENERATED IN CURSEG CASE
C------ GENERATE TANGENTS AT THE ENDS
      IRR=5909
      NDIF=NPH-NPL
      DO 800 I=NPL,NPH,NDIF
      IF(.NOT.ID(1,I)) GO TO 800
      IF(I.EQ.NPL) GO TO 830
      IF(I.EQ.NPH) GO TO 860
  830 IF(NP.EQ.2.AND..NOT.ID(1,I+1)) GO TO 840
      IF(NP.GT.2.AND.S(4,2,I+1).EQ.1.0) GO TO 840
      IF(NP.GT.2) GO TO 836
      DO 835 L=1,3
  835 T(L)=S(L,1,I+1)-S(L,1,I)
      CALL SNORM(T,T,IDUM)
      GO TO 880
  836 CALL PARINT(S(1,1,I),S(1,1,I+1),S(1,1,I+2),T,DUM,1,IRRR)
      GO TO 880
  840 CALL PARINT(S(1,1,I),S(1,2,I+1),S(1,1,I+1),T,DUM,21,IRRR)
      IF(IRRR.NE.0) GO TO 998
      GO TO 880
  860 IF(NP.EQ.2.AND..NOT.ID(1,I-1)) GO TO 870
      IF(NP.GT.2.AND.S(4,2,I-1).EQ.1.0) GO TO 870
      IF(NP.GT.2) GO TO 866
      DO 865 L=1,3
  865 T(L)=S(L,1,I)-S(L,1,I-1)
      CALL SNORM(T,T,IDUM)
      GO TO 880
  866 CALL PARINT(S(1,1,I-2),S(1,1,I-1),S(1,1,I),T,DUM,3,IRRR)
      GO TO 880
  870 CALL PARINT(S(1,1,I-1),S(1,2,I-1),S(1,1,I),T,DUM,13,IRRR)
      IF(IRRR.NE.0) GO TO 998
  880 CONTINUE
      DO 890 L=1,3
  890 S(L,2,I)=T(L)
      S(4,2,I)=-1.0
      ID(1,I)=.FALSE.
  800 CONTINUE
C------ PROJECT ALL TANSPL AND CRRSPL CONSTRAINTS INTO THE PLANE OF THE
C------ NORMAL CONSTRAINT AND UNITIZE THEM
  900 CONTINUE
      IF(INOR) GO TO 1100
      DO 1000 I=NPL,NPH
      IF(ID(3,I)) GO TO 1000
      DO 1010 K=2,3
      IRR=5904+K
      IF(ID(K-1,I)) GO TO 1010
      VAL=S(1,K,I)*S(1,4,I)+S(2,K,I)*S(2,4,I)+S(3,K,I)*S(3,4,I)
      DO 1015 L=1,3
 1015 S(L,K,I)=S(L,K,I)-VAL*S(L,4,I)
      CALL SNORM(S(1,K,I),S(1,K,I),IRRR)
      IF(IRRR.NE.0) GO TO 998
 1010 CONTINUE
 1000 CONTINUE
 1100 CONTINUE
C------ CHECK FOR THE COLLINEARITY OF CONSTRAINTS
      IF(INOR.OR.ICRS) GO TO 1300
      IRR=5908
      DO 1200 I=NPL,NPH
      IF(ID(1,I).OR.ID(2,I).OR.ID(3,I)) GO TO 1200
      CALL CROSS(S(1,2,I),S(1,3,I),T)
      VAL=T(1)*S(1,4,I)+T(2)*S(2,4,I)+T(3)*S(3,4,I)
      IF(DABS(VAL).LT.SMAL2) GO TO 998
 1200 CONTINUE
 1300 CONTINUE
C------ CHECK FOR WILD POINTS
      IF(NP.EQ.2) GO TO 1500
      IRR=5910
      DO 1400 I=NPLP,NPHM
      DO 1410 L=1,3
 1410 T(L)=S(L,1,I+1)-S(L,1,I-1)
      DO 1420 L=1,3
 1420 TA(L)=S(L,1,I)-S(L,1,I-1)
      VAL=T(1)*TA(1)+T(2)*TA(2)+T(3)*TA(3)
      IF(VAL.LE.0.0) GO TO 998
      DO 1430 L=1,3
 1430 TB(L)=S(L,1,I+1)-S(L,1,I)
      VAL=T(1)*TB(1)+T(2)*TB(2)+T(3)*TB(3)
      IF(VAL.LE.0.0) GO TO 998
      CALL CROSS(T,TA,TB)
      VAL=TB(1)*TB(1)+TB(2)*TB(2)+TB(3)*TB(3)
      VALA=T(1)*T(1)+T(2)*T(2)+T(3)*T(3)
C------ WILD POINT MEASURE -- RATIO OF THE HEIGHT TO BASE
      S(4,5,I)=DSQRT(VAL)/VALA
 1400 CONTINUE
 1500 CONTINUE
      S(4,5,NPL)=0
      S(4,5,NPH)=0
C------ BRANCH TO SPLINE OR CURSEG PROCESSING
      GO TO (2000,2000,3000),IORG
C------ COLLECT SUBSPLINES ONE BY ONE AND CONDUCT SMOOTHING
 2000 IBEG=NPL
      ICUR=NPL
 2010 NCUR=1
      IBEG=ICUR
      IF(IBEG.EQ.NTOT) GO TO 2160
      DO 2040 L=1,3
 2040 P(L,NCUR)=S(L,1,ICUR)
      W(NCUR)=1.
 2020 NCUR=NCUR+1
      ICUR=ICUR+1
      IF(.NOT.ID(1,ICUR)) GO TO 2100
      DO 2030 L=1,3
 2030 P(L,NCUR)=S(L,1,ICUR)
      W(NCUR)=1.0
      GO TO 2020
 2100 IF(NCUR.EQ.2) GO TO 2010
      DO 2110 L=1,3
      P(L,NCUR)=S(L,1,ICUR)
      TV(L,1)=S(L,2,IBEG)
 2110 TV(L,2)=S(L,2,ICUR)
      IDC=2
      W(NCUR)=1.0
      NREL=ICUR-IBEG+1
      CALL SMOOTH (P,W,D,TV,V,NREL,IDC)
      IRR=5920+IABS(IDC)
      IF(IDC.LT.0) GO TO 998
      DO 2120 J=IBEG,ICUR
      K=J-IBEG+1
      S(4,2,J)=1.0
      IF((J-IBEG)*(J-ICUR).NE.0) S(4,2,J)=-1.0
      ID(1,ICUR)=.FALSE.
      DO 2130 L=1,3
      S(L,1,J)=P(L,K)
 2130 S(L,2,J)=V(L,K)
      S(4,1,J)=D(K)
 2120 CONTINUE
      IF(ICUR.LT.NTOT) GO TO 2010
 2160 CONTINUE
      DO 2150 I=NPL,NPHM
      J=I+1
      S(4,1,I)=DSQRT((S(1,1,J)-S(1,1,I))**2+(S(2,1,J)-S(2,1,I))**2
     X          +(S(3,1,J)-S(3,1,I))**2)
 2150 CONTINUE
      GO TO 999
C------ CURSEG PROCESSING
 3000 CONTINUE
  999 IRR=0
      RETURN
C------ ERROR RETURN.  IRR IS NOT ZERO.
  998 CONTINUE
      S(1,2,1)=IRR
      RETURN
      END
