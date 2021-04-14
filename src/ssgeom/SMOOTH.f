**** SOURCE FILE : M0000659.V02   ***
*
C
      SUBROUTINE SMOOTH(Q,RL,A,TV,CB,NIN,IDC)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C----************* SMTH1 *********************************'71/4/23  N.K.
C---- THIS ROUTINE CALCULATES SMOOTHED POINTS AND TANGENT VECTORS AT
C---- THOSE POINTS , AND INPUT IS AN ARRAY OF POINT VECTORS.
C---- INPUT --- N = NUMBER OF POINTS
C----           Q = AN ARRAY OF INPUT POINT VECTORS
C----           RL = AN ARRAY OF RELAXATION FACTORS ASSOCIATED TO EACH
C----                INPUT POINTS   ( RL(I)=0. MEANS NO SMOOTHING
C----                                 TO THE I-TH POINT.)
C----           IDC = BOUNDARY CONDITION IDENTIFIER
C----               =1   CLOSED CURVE
C----                =2   1-ST DERIVATIVE --- 1-ST DERIVATIVE
C----               =3   1-ST DERIVATIVE --- 2-ND DERIVATIVE
C----               =4   2-ND DERIVATIVE --- 1-ST DERIVATIVE
C----               =5   2-ND DERIVATIVE --- 2-ND DERIVATIVE
C----           TV = END CONDITION VECTORS INTERPRETED AS SPECIFIED BY
C----                IDC.
C---- OUTPUT--- A = AN ARRAY OF DISTANCE BETWEEN CONSECUTIVE OUTPUT
C----               POINTS  ( A(J)=DISTANCE BTW. J-TH AND (J-1)-TH PNT.)
C----           CB = AN ARRAY OF 1-ST DERIVATIVES (NORMALIZED)
C----           IDC = ERROR INDICATOR
C----               =0   NO ERROR
C----               =-1   A DISTANCE BTW. TWO CONSECUTIVE INPUT POINTS
C----                     IS VANISHING
C----               = -2   IDC IS NOT SIGNIFICANT.
C----               =-3   ERROR IN SOLVING SIMULTANEOUS EQUATION
C----               =-4   NUMBER OF INPUT POINTS IS LESS THAN 3.
C----               =-5   A DISTANCE BTW. TWO CONSECUTIVE OUTPUT POINTS
C----                     IS VANISHING.
C----               =-6   AN OUTPUT 1-ST DERIVATIVE IS VANISHING.
C----********* SUBSIDIARY --- GELG
C----*******************************************************************
      DIMENSION Q(3,30),RL(30),A(30),TV(3,2),CV(3,30),CT(90),CM(900),
     1  CA(3,30),CB(3,30)
      DATA SMAL1,SMAL2,SMAL3/1.0D-7,1.0D-6,1.0D-14/
      DATA ZERO,ONE/0.0D0,1.0D0/
C------ JG CONTROLS OUTPUT. JO IS OUTPUT FILE NUMBER.
      JG=0
      JO=6
C------ INITIAL EXAMINATION TO DETERMINE IF CURVE IS CLOSED
      N=NIN
      W=DSQRT((Q(1,1)-Q(1,N))**2+(Q(2,1)-Q(2,N))**2+(Q(3,1)-Q(3,N))**2)
      IF(W.GT.SMAL2) GO TO 3
C--- CLOSED CURVE CASE   END POINTS ASSUMED EQUAL
      N=NIN-1
      IDC=1
    3 CONTINUE
C------ CONVERT FROM A PART PROGRAMMER WEIGHT FACTOR(0.0 TO 1.0 WHERE
C------ 1.0 MEANS CERTAINTY FOR A POINT) TO A RELAXATION FACTOR ( INF
C------ TO 0.0 WHERE 0.0 IS CERTITUDE AND INFINITY IS COMPLETE RELAXA)
      DO 1517 I=1,NIN
      AA=RL(I)
      IF(AA.LT.SMAL1)  AA=SMAL1
      IF(AA.GT.ONE) AA=ONE
      RL(I)=ONE/AA-ONE
 1517 CONTINUE
      NN=N*N
      N3=3*N
C
C    ***DISTANCE BTW,CONSECUTIVE INPUT POINTS***
C    ***NORMALIZED INCREMENTAL VECTORS***
C    ***SINGULARITY IS CHECKED***
C
      IF(N.LT.3)  GO TO 1300
    1 DO  10   J=2,N
      JJ=J-1
      DO  11   I=1,3
      CV(I,J)=Q(I,J)-Q(I,JJ)
   11 CONTINUE
      A(J)= DSQRT(CV(1,J)**2+CV(2,J)**2+CV(3,J)**2)
      IF(A(J).LT.SMAL1)   GO TO 1000
      DO  12   I=1,3
      CV(I,J)=CV(I,J)/A(J)
   12 CONTINUE
   10 CONTINUE
      DO  13   I=1,3
   13 CV(I,1)=Q(I,1)-Q(I,N)
      A(1)=DSQRT(CV(1,1)**2+CV(2,1)**2+CV(3,1)**2)
      IF(A(1).LT.SMAL1)  GO TO 1000
      DO  14   I=1,3
   14 CV(I,1)=CV(I,1)/A(1)
C
C    ***CONSTANT VECTORS FOR THE EQUATION OF CURVATURE***
C
      L1=N+1
      DO  20   I=1,3
      II=I*N-L1
      DO  21   J=2,N
      CT(II+J)=6.*(CV(I,J)-CV(I,J-1))
   21 CONTINUE
      CT(II+L1)=6.*(CV(I,1)-CV(I,N))
   20 CONTINUE
C
C    ***CLEAR THE MATRIX***
C
      DO  30   I=1,NN
      CM(I)=0.
   30 CONTINUE
C
C    ***MATRIX ELEMENTS***
C
      CA(1,1)=6.*(RL(1)+RL(2))/A(2)**2
      CB(1,1)=6.*(RL(1)/A(2))/A(1)
      DO  31   I=1,N
      II=I+1-(I/N)*N
      J1=I+2-((I+1)/N)*N
      CA(1,II)=6.*(RL(II)+RL(J1))/A(J1)**2
      CB(1,II)=6.*(RL(II)/A(J1))/A(II)
      CB(2,I)=A(II)-(CB(1,II)+CA(1,I)+CB(1,I))
      CB(3,II)=2.*(A(J1)+A(II))+(CA(1,II)+CA(1,I)+2.*CB(1,II))
   31 CONTINUE
C
C    ***SET PRIMARY MATRIX***
C
      L2=N+2
      N2=2*N
      DO  41   IJ=L1,N2
      J=IJ-1-((IJ-2)/N)*N
      JJ=J+1-(J/N)*N
      I=J*L1-N
      IA=I+N-((I+N-1)/NN)*NN
      IB=I+2*N-((I+2*N)/NN)*NN
      IC=I+1-(J/N)*N
      ID=I+2-((J+1)/N)*N
      CM(I)=CB(3,J)+CM(I)
      CM(IA)=CB(2,J)+CM(IA)
      CM(IB)=CB(1,JJ)+CM(IB)
      CM(IC)=CB(2,J)+CM(IC)
      CM(ID)=CB(1,JJ)+CM(ID)
   41 CONTINUE
C
C    ***CLOSED CURVE***
C
      IF(IDC.EQ.1)  GO TO 200
C
C    ***OPEN ENDS***
C
      K1=N-1
      CM(NN-N+1)=0.
      CM(NN-N+2)=0.
      CM(NN-N2+1)=0.
      CM(N)=0.
      CM(N2)=0.
      CM(K1)=0.
      CM(2)=A(2)-CA(1,1)-CB(1,2)
      IF(N.NE.3)  GO TO 60
      CM(8)=A(3)-(CA(1,2)+CB(1,2))
      GO TO 61
   60 CM(NN-1)=A(N)-(CA(1,K1)+CB(1,K1))
C
C    *** FIRST END BY CURVATURE***
C
   61 IF(IDC.LT.4)  GO TO 110
      DO  42   I=1,3
      CT(I*N-K1)=TV(I,1)
   42 CONTINUE
      CM(1)=1.
      CM(L1)=0.
      CM(N2+1)=0.
C
C    ***LAST END BY TANGENT***
C
      IF(IDC.NE.4)  GO TO 120
  130 DO  43   I=1,3
      CT(I*N)=6.*(CV(I,N)-TV(I,2))
   43 CONTINUE
      CM(NN-N)=-A(N)+CB(1,K1)+CA(1,K1)
      CM(NN)=-2.*A(N)-CA(1,K1)
      CM(NN-N2)=-   CB(1,K1)
      GO TO 200
C
C    ***LAST END BY CURVATURE***
C
  120 IF(IDC.NE.5)  GO TO 1100
  140 DO  44   I=1,3
      CT(I*N)=TV(I,2)
   44 CONTINUE
      CM(NN)=1.
      CM(NN-N)=0.
      CM(NN-N2)=0.
      GO TO 200
C
C    ***FIRST END BY TANGENT***
C
  110 DO  45   I=1,3
      CT(I*N-K1)=6.*(CV(I,2)-TV(I,1))
   45 CONTINUE
      CM(1)=2.*A(2)+   CA(1,1)
      CM(L1)=A(2)-   (CA(1,1)+CB(1,2))
      CM(N2+1)=CB(1,2)
      IF(IDC.EQ.2)   GO TO 130
      GO TO 140
C
C    *** CALCULATION OF CURVATURE***
C
  200 EPS=SMAL3
      NR=3
      CALL GELG(CT,CM,EPS,N,NR,IER)
      IF(IER.NE.0)   GO TO 1200
      DO  50   I=1,3
      II=I*N-N
      DO  51   J=1,N
      CV(I,J)=CT(II+J)
   51 CONTINUE
   50 CONTINUE
C    ***CALCULATION OF CURVE SEGMENT COEFFICIENTS***
C
      DO  55   I=1,3
      DO  56   J=2,N
      CA(I,J)=(CV(I,J)-CV(I,J-1))/A(J)
   56 CONTINUE
      CA(I,1)=(CV(I,1)-CV(I,N))/A(1)
      K1=N-1
      DO  57   J=2,K1
      Q(I,J)=Q(I,J)-RL(J)*(CA(I,J+1)-CA(I,J))
   57 CONTINUE
      IF(IDC.EQ.1)  GO TO 250
      Q(I,1)=Q(I,1)-RL(1)*(CV(I,2)-CV(I,1))/A(2)
      Q(I,N)=Q(I,N)+RL(N)*(CV(I,N)-CV(I,N-1))/A(N)
      GO TO 55
  250 Q(I,1)=Q(I,1)-RL(1)*(CA(I,2)-CA(I,1))
      Q(I,N)=Q(I,N)-RL(N)*(CA(I,1)-CA(I,N))
   55 CONTINUE
      IDXX=0
      DO  400   J=1,N
      IF(RL(J).GT.SMAL2)   IDXX=IDXX+1
      IF(RL(J).GT.SMAL2)   RL(J)=0.
  400 CONTINUE
      IF(IDXX.EQ.0)   GO TO 590
      GOTO 500
  590 DO  510   J=2,N
      DO  510   I=1,3
      CA(I,J)=Q(I,J)-Q(I,J-1)
  510 CONTINUE
      IF(IDC.NE.1)   GO TO 260
      DO  520   I=1,3
  520 CA(I,1)=Q(I,1)-Q(I,N)
  260 DO  91   J=1,N
      J1=J+1-(J/N)*N
      DO  93   I=1,3
      CB(I,J)=CA(I,J1)/A(J1)-A(J1)*(2.*CV(I,J)+CV(I,J1))/6.
   93 CONTINUE
      A(J1)=0.
      DO  92   I=1,3
      A(J1)=CA(I,J1)**2+A(J1)
   92 CONTINUE
      A(J1)=DSQRT(A(J1))
      IF(A(J1).GE.SMAL3)  GO TO 91
      IF(J.NE.N)  GO TO 1400
      IF(IDC.EQ.1)  GO TO 1400
      A(1)=99999.
   91 CONTINUE
      IF(IDC.EQ.1)   GO TO 511
      DO  94   I=1,3
   94 CB(I,N)=CA(I,N)/A(N)+A(N)*(CV(I,N-1)+2.*CV(I,N))/6.
  511 CONTINUE
      DO  300 J=1,N
      TL=DSQRT(CB(1,J)*CB(1,J)+CB(2,J)*CB(2,J)+CB(3,J)*CB(3,J))
      IF(TL.LE.SMAL2)   GO TO 1500
      DO  310   I=1,3
  310 CB(I,J)=CB(I,J)/TL
  300 CONTINUE
      GO TO 500
 1000 IDC=-1
      GO TO 500
 1100 IDC=-2
      GO TO 500
 1200 IDC=-3
      GO TO 500
 1300 IDC=-4
      GO TO 500
 1400 IDC=-5
      GO TO 500
 1500 IDC=-6
  500 CONTINUE
      IF(IDC.NE.1) RETURN
C------ FINAL ADJUSTMENT FOR CLOSED CURVE
      DO 502 I=1,3
      Q(I,NIN)=Q(I,1)
      CB(I,NIN)=CB(I,1)
  502 CONTINUE
      A(NIN)=A(1)
      IDC=2
      RETURN
      END
