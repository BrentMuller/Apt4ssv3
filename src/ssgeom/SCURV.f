**** SOURCE FILE : M0004151.V04   ***
*
      SUBROUTINE SCURV(S,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C------ INPUT IS A STREAM OF POINTS TOGETHER WITH VARIOUS
C------ TANSPL,CRSSPL,NORMAL,WEIGHT,LIMIT CONSTRAINTS
C------ ALL OF THIS INPUT IS STRUCTURED INTO THE S ARRAY
C------ THE OBJECTIVE OF THIS ROUTINE IS TO CREATE EITHER
C------ A CONIC ARC(S(3,1,1)=3.) OR A SPLINE CURVE(S(3,1,1)=2.)
C------ THE FINAL PROCESSED CURVE IS PACKED INTO THE S ARRAY
C------ REVISED VERSION, CRANFIELD 1981, R.J.G./M.J.P.
C
      COMMON/IBUGG/IBUG,IPCOLC,IPCOLM
C
      DIMENSION S(4,6,31)
      DIMENSION X(5),Y(5),XT(5),YT(5)
      DIMENSION VA(3),VB(3),VN(3),DIF(3)
      DIMENSION C(4,4),A(3,3),CL(4,4),R(4,4)
      CHARACTER*20 BADMSG
      DATA SMAL1,SMAL2,VSMAL/.000000001D0,.00001D0,1.0D-30/
      DATA ZERO,ONE,TWO,THREE/0.0D0,1.0D0,2.0D0,3.0D0/
      IRRR=0
      IRR=0
C
C-------  FIRST CHECK FOR PRESENCE OF NULL ARC
      NHD=S(2,1,1)
      NPL=NHD+1
      NP=S(4,1,1)
      NPH=NHD+NP
      NPLP=NPL+1
      NPHM=NPH-1
C
      IF(IBUG.NE.11) GO TO 7
      CALL BAD(-1,0,' ',0)
      BADMSG=' ENTRY TO SCURV'
      CALL CPRINT(BADMSG)
      JLIM=S(4,1,1)+ONE
      DO 8 J=1,JLIM
      DO 8 I=1,6
      CALL BAD(-4,1,'SC  ',S(1,I,J))
    8 CONTINUE
    7 CONTINUE
C
      IF(NP.NE.2) GO TO 1
      DO 2 I=1,3
    2 DIF(I)=S(I,1,NPH)-S(I,1,NPL)
      CALL DOTF(W,DIF,DIF)
      IF(W.GT.VSMAL) GO TO 1
C-------  NULL ARC INPUT CONFIRMED, PROCESS CURVE DEFINITION HERE
C
C-------  SET UP COONS CANON FORM FOR NULL CURVE
      DO 3 I=1,3
      C(1,I)=S(I,1,NPL)
      C(2,I)=S(I,1,NPH)
      C(3,I)=ZERO
      C(4,I)=ZERO
    3 CONTINUE
      C(1,4)=ONE
      C(2,4)=ONE
      C(3,4)=ZERO
      C(4,4)=ZERO
C-------  NOW MOVE ALL VECTOR CONSTRAINTS
      DO 4 I=1,4
      S(I,5,NPL-1)=S(I,3,NPL)
      S(I,6,NPL-1)=S(I,4,NPL)
      S(I,5,NPL)=S(I,3,NPH)
      S(I,6,NPL)=S(I,4,NPH)
      DO 5 J=1,4
      S(I,J,NPL)=C(I,J)
    5 CONTINUE
    4 CONTINUE
C
C-------  REDUCE POINT BLOCK COUNT BY 1 AND QUIT
      S(4,1,1)=S(4,1,1)-ONE
      GO TO 1000
C
    1 CONTINUE
C------ ELIMINATE ALL SMALL CONSTRAINT VECTORS BEFORE SSPLIN
      DO 12 I=NPL,NPH
      IF(S(4,3,I).LT.SMAL2) GO TO 12
      CALL DOTF(W,S(1,3,I),S(1,3,I))
      IF(W.GT.VSMAL) GO TO 12
C------ CONSTRAINT VECTOR IS SMALL, SO ELIMINATE IT
      DO 13 L=1,4
   13 S(L,3,I)=ZERO
   12 CONTINUE
C
C------ CALL SSPLIN FOR SMOOTHING AND GENERATION OF TANGENTS,
C------ DISCRIMINATION OF INPUT ERRORS AND GENERATION OF TANGENT
C------ DIRECTIONS AT EACH POINT IN THE CASE OF A SPLINE DEFINITION
C
      CALL SSPLIN(S,IRR)
      IF(IRR.NE.0) GO TO 998
C------ JUMP TO LABEL 700 FOR SPLINE PROCESSING
C
C------ THE CASE OF A CURSEG DEFINITION
C------ TEST FOR COPLANARITY OF THE NUMERICAL INPUT
C------ BEGIN BY CONSTRUCTING THE FIRST CHORD VECTOR
      NHD=S(2,1,1)
      NPL=NHD+1
      NP=S(4,1,1)
      NPH=NHD+NP
      NPLP=NPL+1
      NPHM=NPH-1
      IF (S(3,1,1) .NE. THREE) GO TO 700
      DO 10 L=1,3
   10 VA(L)=S(L,1,NPLP)-S(L,1,NPL)
      CALL SNORM(VA,VA,IRRR)
      IF (NP .EQ. 2) GO TO 25
C------ CONSTRUCT A SECOND NON PARALLEL CHORD VECTOR
      DO 20 I=NPLP,NPHM
      DO 30 L=1,3
      VB(L)=S(L,1,I+1)-S(L,1,NPL)
   30 CONTINUE
      CALL CROSS(VB,VA,VN)
      D=DSQRT(VN(1)**2+VN(2)**2+VN(3)**2)
      IF(D.GT.SMAL1) GO TO 50
   20 CONTINUE
C------ THE POINTS ARE COLINEAR SO FIND A NONPARALLEL TANGENT
   25 CONTINUE
      DO 40 I=NPL,NPH
      KK=0
      IF(S(4,4,I).NE.ZERO) KK=4
      IF(S(4,2,I).NE.ZERO) KK=2
      IF(KK.EQ.0) GO TO 40
      IF(I.EQ.NPH)GO TO 42
      CALL CROSS(VA,S(1,KK,I),VN)
      GO TO 45
   42 CALL CROSS(S(1,KK,I),VA,VN)
   45 D=DSQRT(VN(1)**2+VN(2)**2+VN(3)**2)
      IF(D.GT.SMAL1) GO TO 50
   40 CONTINUE
C------ THERE IS NO UNIQUE NORMAL, CONDITIONS INDICATE A STRAIGHT LINE
      GO TO 200
C
C------ VN IS THE POTENTIAL NORMAL TO THE BASE PLANE
   50 CALL SNORM(VN,VN,IRRR)
C------ NOW CHECK ALL INPUT POINTS AND VECTORS TO SEE IF THEY
C------ DO LIE IN THE BASE PLANE
      DO 100 I=NPLP,NPH
      DO 110 L=1,3
  110 DIF(L)=S(L,1,I)-S(L,1,NPL)
      CALL SNORM(DIF,DIF,IRRR)
      DOT=DIF(1)*VN(1)+DIF(2)*VN(2)+DIF(3)*VN(3)
C------ NON COPLANAR POINTS
      IRR=5751
      IF(DABS(DOT).GT.SMAL2) GO TO 998
  100 CONTINUE
C------ NOW CHECK FOR NON COPLANAR TANGENTS
C------ NT GIVES TOTAL NUMBER OF TANGENT CONSTRAINTS
      IRR=5752
      NT=0
      DO 120 I=NPL,NPH
      IF(S(4,2,I).EQ.ZERO) GO TO 120
      NT=NT+1
      DOT=VN(1)*S(1,2,I)+VN(2)*S(2,2,I)+VN(3)*S(3,2,I)
      IF(DABS(DOT).GT.SMAL2) GO TO 998
  120 CONTINUE
      IRR=5753
      IF(NP+NT.GT.5) GO TO 998
C------ ERROR IF MORE THAN 5 IMPOSED CONSTRAINTS
      GO TO 300
C------ INPUT DOES LIE IN A PLANE
C
C------ LINEAR CASE
  200 CONTINUE
      DO 210 K=1,2
      I=NPL
      IF(K.EQ.2) I=NPH
      DO 210 L=1,3
      C(K,L)=S(L,1,I)
  210 C(K+2,L)=S(L,1,NPH)-S(L,1,NPL)
      C(1,4)=ONE
      C(2,4)=ONE
      C(3,4)=ZERO
      C(4,4)=ZERO
      GO TO 604
C
C------ NON-LINEAR CASES; CONSTRUCT NEW COORDINATE SYSTEM
  300 CONTINUE
      DO 305 I=1,3
  305 VA(I)=DIF(I)
      CALL CROSS(VN,VA,VB)
      CALL SNORM(VB,VB,IRR)
C------ VA,VB,VN ARE NEW AXES CENTRED AT FIRST POINT
C------ R IS RATIONAL TRANSFORMATION MATRIX
      DO 310 I=1,3
  310 R(I,4)=0.0
      R(4,4)=1.0
      DO 320 J=1,3
      R(1,J)=VA(J)
      R(2,J)=VB(J)
      R(3,J)=VN(J)
  320 R(4,J)=S(J,1,NPL)
C------ NEW COORDINATES STORED IN ARRAYS X,Y,TANGENTS IN XT,YT
      NPN1=NP-1
      DO 340 I=1,NPN1
      SUMX=0.0
      SUMY=0.0
      DO 330 J=1,3
      SUMX=SUMX+(S(J,1,NPL+I)-S(J,1,NPL))*VA(J)
  330 SUMY=SUMY+(S(J,1,NPL+I)-S(J,1,NPL))*VB(J)
      X(I+1)=SUMX
  340 Y(I+1)=SUMY
      DO 350 I=1,NP
      J=NPL+I-1
      IF(S(4,2,J).EQ.ZERO) GO TO 350
      XT(I)=S(1,2,J)*VA(1)+S(2,2,J)*VA(2)+S(3,2,J)*VA(3)
      YT(I)=S(1,2,J)*VB(1)+S(2,2,J)*VB(2)+S(3,2,J)*VB(3)
  350 CONTINUE
      X(1)=0.0
      Y(1)=0.0
C
C------ CHECK CONVEXITY OF POINTS AND CONDITIONS DEFINED
      IRR=5770
      IF(NP.EQ.2) GO TO 361
      NPN1=NP-1
      DO 360 I=2,NPN1
      D=(Y(I)-Y(I-1))*(X(I+1)-X(I-1))-(X(I)-X(I-1))*(Y(I+1)-Y(I-1))
      IF(D.LE.SMAL1) GO TO 998
  360 CONTINUE
  361 CONTINUE
C
      IF(NT.EQ.0) GO TO 372
      DO 371 I=1,NP
      IF(S(4,2,NPL+I-1).EQ.ZERO) GO TO 371
      DO 370 J=1,NP
      IF(J.EQ.I) GO TO 370
      DT=(X(J)-X(I))*YT(I)-(Y(J)-Y(I))*XT(I)
      IF(DT.LE.SMAL1) GO TO 998
  370 CONTINUE
  371 CONTINUE
  372 CONTINUE
C
C------ FIT CONIC X*X+B*Y*Y+C0*X*Y+D*X+E*Y=0 TO DATA
      D=-X(NP)
      IRR=5772
      IF(NP+NT.EQ.4) GO TO 400
      IF(NP+NT.EQ.5) GO TO 500
C------ 3 CONDITIONS DEFINE UNIQUE CIRCULAR ARC
      IF(NT.EQ.0) GO TO 381
      DO 380 I=1,NP
      IF(S(4,2,NPL+I-1).EQ.ZERO) GO TO 380
      E=-(2.0*X(I)*XT(I)+2.0*Y(I)*YT(I)+D*XT(I))/YT(I)
  380 CONTINUE
  381 CONTINUE
      IF(NP.NE.3) GO TO 390
      E=-(X(2)*X(2)+Y(2)*Y(2)+D*X(2))/Y(2)
  390 CONTINUE
C
C------ GENERATE CANONICAL FORM MATRIX CL
      A0=(DSQRT(D*D+E*E)-E)/DABS(D)
      A2=A0*A0
      DO 391 I=1,4
      DO 391 J=1,4
  391 CL(I,J)=0.0
      CL(1,4)=A2+1.0
      CL(2,1)=-D*(A2+1.0)
      CL(2,4)=A2+1.0
      CL(3,1)=-D*(1.0-A2)
      CL(3,2)=-2.0*A0*D
      CL(3,4)=-4.0*A2
      CL(4,1)=-D*(1.0+3.0*A2)
      CL(4,2)=2.0*A0*D
      CL(4,4)=4.0*A2
      GO TO 600
C------ FOUR CONDITIONS,CURVE IS ELLIPSE OR PARABOLA
  400 CONTINUE
      IF(NT.NE.2) GO TO 410
      E=-D*XT(1)/YT(1)
      C0=-(XT(2)/YT(2)+XT(1)/YT(1))
C------ MINIMUM ECCENTRICITY ELLIPSE HAS B=C0*C0/2+1, PARABOLA B=C0*C0/4
      B=1.0+C0*C0/2.0
      GO TO 550
  410 IF(NT.NE.1) GO TO 425
      DO 420 I=1,NP
      IF(S(4,2,NPL+I-1).EQ.ZERO) GO TO 420
C------ FORM QUADRATIC A2*C0*C0+A1*C0+A0=0 FOR C,TRY B=1+C0*C0/2 FIRST
      A2=Y(2)*YT(I)*(Y(I)-0.5*Y(2))
      A1=Y(2)*(X(I)*YT(I)+Y(I)*XT(I)-X(2)*YT(I))
      A0=XT(I)*Y(2)*(2.0*X(I)+D)-X(2)*YT(I)*(X(2)+D)+2.0*A2
  420 CONTINUE
      GO TO 430
  425 A2=Y(2)*Y(3)*(Y(2)-Y(3))/2.0
C------ CASE OF 4 DEFINED POINTS
      A1=Y(2)*Y(3)*(X(2)-X(3))
      A0=X(2)*Y(3)*(X(2)+D)-X(3)*Y(2)*(X(3)+D)+2.0*A2
  430 IF(DABS(A2).LE.SMAL1) GO TO 450
      DISC=A1*A1-4.0*A2*A0
      IF(DISC.LT.ZERO) GO TO 460
      IF(DISC.GT.SMAL1) GO TO 435
      C0=-A1/(2.0*A2)
      GO TO 455
  435 DO 440 K=1,3,2
      C0=(-A1+(K-2)*DSQRT(DISC))/(2.0*A2)
      B=1.0+C0*C0/2.0
      E=(X(2)*X(2)+B*Y(2)*Y(2)+C0*X(2)*Y(2)+D*X(2))/(-Y(2))
      IF(D*E.LT.ZERO.AND.D*(E-C0*D).LT.ZERO) GO TO 550
  440 CONTINUE
      GO TO 460
  450 C0=-A0/A1
C------ EQUAL ROOTS OR LINEAR EQUATION FOR C
  455 B=1.0+C0*C0/2.0
      E=(X(2)*X(2)+B*Y(2)*Y(2)+C0*X(2)*Y(2)+D*X(2))/(-Y(2))
      IF(D*E.LT.ZERO.AND.D*(E-C0*D).LT.ZERO) GO TO 550
  460 A2=A2/2.0
C------ PARABOLIC CASE
      A0=A0-4.0*A2
      IF(DABS(A2).LE.SMAL1) GO TO 480
      DISC=A1*A1-4.0*A0*A2
      IF(DISC.LT.0.0) GO TO 998
      IF(DISC.GT.SMAL1) GO TO 465
      C0=-A1/(2.0*A2)
      GO TO 485
  465 DO 470 K=1,3,2
      C0=(-A1+(K-2)*DSQRT(DISC))/(2.0*A2)
      B=C0*C0/4.0
      E=(X(2)*X(2)+B*Y(2)*Y(2)+C0*X(2)*Y(2)+D*X(2))/(-Y(2))
      IF(D*E.LT.ZERO.AND.D*(E-C0*D).LT.ZERO) GO TO 550
  470 CONTINUE
      GO TO 998
C------ NO SATISFACTORY CONIC FOUND
  480 C0=-A0/A1
C------ EQUAL ROOTS OR LINEAR EQUATIONS FOR C
  485 B=C0*C0/4.0
      E=(X(2)*X(2)+B*Y(2)*Y(2)+C0*X(2)*Y(2)+D*X(2))/(-Y(2))
      IF(D*E.LT.ZERO.AND.D*(E-C0*D).LT.ZERO) GO TO 550
      GO TO 998
  500 CONTINUE
C
C------ UNIQUE CONIC DEFINED BY 5 CONDITIONS;
C------ SET UP EQUATIONS FOR COEFFICIENTS
      NPN2=NP-2
      DO 510 I=1,NPN2
      J=I+1
      A(I,1)=Y(J)*Y(J)
      A(I,2)=X(J)*Y(J)
      A(I,3)=Y(J)
  510 VA(I)=-(X(J)+D)*X(J)
      IF(NT.EQ.0) GO TO 530
      I=NP-2
      DO 520 J=1,NP
      IF(S(4,2,NPL+J-1).EQ.ZERO) GO TO 520
      I=I+1
      A(I,1)=2.0*Y(J)*YT(J)
      A(I,2)=Y(J)*XT(J)+X(J)*YT(J)
      A(I,3)=YT(J)
      VA(I)=-(2.0*X(J)+D)*XT(J)
  520 CONTINUE
C------ SOLVE LINEAR EQUATIONS
  530 CALL GELG(VA,A,SMAL1,3,1,IRR)
      IF(IRR.EQ.0) GO TO 540
      IRR=5772
      GO TO 998
  540 B=VA(1)
      C0=VA(2)
      E=VA(3)
C
C------ COEFFICIENTS OF CONIC HAVE BEEN DETERMINED,FIND MID POINT OF
C------ ARC (XM,YM) AND TANGENT INTERSECTION (XI,YI)
  550 IRR=5760
      XM=-0.5*D
      IF(DABS(B).GT.SMAL2) GO TO 560
      IF(C0.LT.SMAL2) GO TO 555
      IF(DABS(0.5+E/C0).LT.0.5) GO TO 998
C------ DISCONTINUOUS HYPERBOLIC CASES REJECTED
  555 YM=XM*XM/(E-C0*XM)
      GO TO 570
  560 BB=E-0.5*C0*D
      DISC=BB*BB+B*D*D
      IF(DISC.LT.0.0) GO TO 998
      YM=(-BB+DSQRT(DISC))/(2.0*B)
  570 DENOM=2.0*E-C0*D
      IF(DABS(DENOM).LE.SMAL1) GO TO 998
C------ PARALLEL TANGENTS
      XI=-D*E/DENOM
      YI=D*D/DENOM
      IF(YI*YM.LT.ZERO) GO TO 998
C------ POINTS ON OPPOSITE SIDES OF CHORD
      CALL RATCON(-D,XM,YM,XI,YI,CL)
C
C------ NOW REVERSE THE COORDINATE TRANSFORMATION
  600 CNORM=0.0
      DO 602 I=1,4
      DO 602 J=1,4
      SUM=0.0
      DO 601 K=1,4
  601 SUM=SUM+CL(I,K)*R(K,J)
      IF(DABS(SUM).GT.CNORM) CNORM=SUM
  602 C(I,J)=SUM
C------ NORMALISE THE C MATRIX
      DO 603 I=1,4
      DO 603 J=1,4
  603 C(I,J)=C(I,J)*10.0/CNORM
C------ BUILD THE NEW DATA BASE CONSISTING OF A SINGLE RATIONAL
C------ CUBIC CURVE WITH POSSIBLE CRRSPL AND NORMAL CONSTRAINTS
C------ AT CURVE ENDS
C------ SHIFT THE FIRST AND LAST CONSTRAINT VECTORS INTO APPROPRIATE
C------ PARTS OF THE FINAL ARRAY
  604 NDIFF=NPH-NPL
      DO 610 I=NPL,NPH,NDIFF
      K=NHD
      IF(I.EQ.NPH) K=NHD+1
      DO 610 J=3,4
      JJ=J+2
      DO 620 L=1,4
  620 S(L,JJ,K)=S(L,J,I)
  610 CONTINUE
C------ NOW LOAD THE RATIONAL PARAMETRIC CUBIC CANON FORM
C------ INTO THE DATA BASE
      DO 630 K=1,4
      DO 630 L=1,4
  630 S(L,K,NPL)=C(L,K)
C------ ZERO OUT THE REST OF THE ARRAY
      DO 640 I=NPLP,NPH
      DO 640 K=1,6
      DO 640 L=1,4
  640 S(L,K,I)=ZERO
      S(4,1,1)=ONE
      GO TO 1000
C------ THE INPUT HERE IS A PARTIALLY COMPLETED SPLINE DATA BASE
C------ IN THIS SECTION FINAL LENGTHS ARE ASSIGNED TO TANGENT VECTORS
C------ COONS MATRICES ARE CONSTRUCTED FOR EACH SEGMENT, AND THE
C------ COMPLETE DATA BASE IS CONSTRUCTED
C
  700 CONTINUE
C------ FIRST SHIFT THE LOCATION OF ALL CROSS SPLINE AND NORMAL
C------ CONSTRAINTS
      DO 710 I=NPL,NPH
      DO 710 K=3,4
      DO 710 L=1,4
      S(L,K+2,I-1)=S(L,K,I)
  710 CONTINUE
C------ NOW GENERATE LENGTHS FOR VECTORS AND THEN COONS MATRICES
C
      DO 720 I=NPL,NPHM
C-------  THREE LOGIC LEVELS FOR TANGENT VECTOR LENGTHS ARE AVAILABLE
C-------  ILEVEL=2, DEFAULT, MINIMIZES DDR(0)**2+DDR(1)**2
      ILEVEL=2
C-------  ILEVEL=1 USE CHORD LENGTH FOR TANGENT VECTORS
C-------  ILEVEL=3 USED LENGTHS WHICH MINIMIZE TENSION
      IF(IBUG.EQ.9) ILEVEL=1
      IF(IBUG.EQ.10) ILEVEL=3
C-------  CTOLR SETS THE TOLERANCE LEVEL FOR TERMINATING THE
C-------  ITERATIVE PROCESS OF ADJUSTING TANGENT LENGTHS FOR
C-------  THE PURPOSE OF REDUCING CURVE TENSION.
      CTOLR=0.005
C-------  NUMINT IS THE NUMBER OF INTERVALS USED FOR APPROXIMATING
C-------  TENSION.  VALUE 5 IS ECONOMIC BUT MORE MAY PRODUCE
C-------  MORE ACCURATE RESULTS, BUT WITH GREATER RUN TIMES
      NUMINT=5
C-------  MXCT IS AN UPPER LIMIT ON THE NUMBER OF ITERATIONS
C-------  THIS IS TO LIMIT TOTAL CPU TIME FOR SPLINING.
      MXCT=10
C-------  ALPH AND BETA ARE THE DESIRED LENGTHS OF TANGENT VECTORS
C
      CALL CRVLEN(S(1,1,I),S(1,1,I+1),S(1,2,I),S(1,2,I+1),
     X            ALPH,BETA,NUMINT,MXCT,CTOLR,ILEVEL)
C
C------ THIS ASSIGNMENT OF LENGTHS IS BASED ON A MINIMUM VALUE
C------ FOR THE INTEGRAL OF THE SECOND DERIVATIVE SQUARED
      DO 750 L=1,3
      C(1,L)=S(L,1,I)
      C(2,L)=S(L,1,I+1)
      C(3,L)=ALPH*S(L,2,I)
      C(4,L)=BETA*S(L,2,I+1)
  750 CONTINUE
      C(1,4)=ONE
      C(2,4)=ONE
      C(3,4)=ZERO
      C(4,4)=ZERO
C------ NOW LOAD THE COONS MATRIX INTO THE S ARRAY
      DO 760 K=1,4
      DO 760 L=1,4
  760 S(L,K,I)=C(L,K)
  720 CONTINUE
C
C------ ZERO OUT THE LAST BLOCK AND RESET THE POINT BLOCK NUMBER
      S(4,1,1)=NP-1
      DO 770 K=1,6
      DO 770 L=1,4
  770 S(L,K,NPH)=ZERO
      GO TO 1000
 1000 CONTINUE
      IRR=0
  998 CONTINUE
C
      IF(IBUG.NE.11) GO TO 917
      CALL BAD(-1,0,' ',0)
      BADMSG=' EXIT FROM SCURV'
      CALL CPRINT(BADMSG)
      JLIM=S(4,1,1)+ONE
      DO 918 J=1,JLIM
      DO 918 I=1,6
      CALL BAD(-4,1,'SC  ',S(1,I,J))
  918 CONTINUE
  917 CONTINUE
C
      RETURN
      END
