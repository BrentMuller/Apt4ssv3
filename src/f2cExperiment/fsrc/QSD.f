**** SOURCE FILE : M0002772.V02   ***
*
C
C....    FORTRAN SUBROUTINE            QSD            4/1/69     RC
C
      SUBROUTINE  QSD(CANFRM,IQ,COEFF,TRANS)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
      DIMENSION  CANFRM(10), COEFF(10), QL(4,4), TRANS(3,4)
C
C  PURPOSE         TO IDENTIFY QUADRIC, LCONIC, AND GCONIC SURFACES
C
C  CALLING SEQNCE  CALL  QSD(CANFRM,IQ,COEFF,TRANS)
C
C  ARGUMENTS       CANFRM....ARRAY CONTAINING ORIGINAL CANONICAL FORM
C                  IQ .......FLAG SET TO INDICATE TYPE OF QUADRIC
C                            SURFACE FOUND BY THIS ROUTINE
C                  COEFF.....ARRAY CONTAINING NEW VALUES CALCULATED
C                            FOR THE QUADRIC EQUATION
C                  TRANS.....TRANSFORMATION MATRIX FROM THE ORIGINAL
C                            TO THE LOCAL COORDINATE SYSTEM
C
C  CALLED BY       AERR
C
C  SUBSIDIARIES    REAL FUNCTION SUBPROGRAM - PSIGN
C
C  DIAGNOSTICS     NONE
C
C     -----------------------------------------------------------
C
C              ** INITIALIZE **
C
      ONE=1.0
      DO 20 I=1,4
      DO 20 J=1,4
20    QL(I,J)=0
      DO 30 I=1,3
      DO 30 J=1,4
30    TRANS(I,J)=0
      DO 40 I=1,3
40    TRANS(I,I)=1
C
C        ** SET UP INITIAL CANONICAL VALUES
C
      QL(1,1)=CANFRM(1)
      QL(2,2)=CANFRM(2)
      QL(3,3)=CANFRM(3)
      QL(4,4)=CANFRM(4)
      QL(2,3)=CANFRM(5)
      QL(3,2)=CANFRM(5)
      QL(1,3)=CANFRM(6)
      QL(3,1)=CANFRM(6)
      QL(1,2)=CANFRM(7)
      QL(2,1)=CANFRM(7)
      P=CANFRM(8)
      Q=CANFRM(9)
      R=CANFRM(10)
C
C               * FIND ROTATION MATRIX AND LOCAL QL
C
100   AMAX=0
      AMIN=DABS(QL(3,3))
      DO 120 I=1,2
      IF (DABS(QL(I,I))-AMIN) 102,103,103
102   AMIN=DABS(QL(I,I))
103   I1=I+1
      DO 120 J=I1,3
      IF (DABS(QL(I,J))-AMAX) 120,120,110
110   AMAX=DABS(QL(I,J))
      K=I
      L=J
120   CONTINUE
C               * SET SMALL TERMS TO ZERO
C
      IF (AMIN) 130,140,130
130   IF (AMAX/AMIN-1.E-15) 160,140,140
140   IF (AMAX-1.E-25) 160,200,200
160   DO 170 I=1,2
      I1=I+1
      DO 170 J=I1,3
      QL(I,J)=0
      QL(J,I)=0
170   CONTINUE
      GOTO 250
C
C               * JACOBI CALCULATION
200   AKK=QL(K,K)
      AKL=QL(K,L)
      ALL=QL(L,L)
      IF (ALL-AKK) 205,208,205
205   S=AKL/(ALL-AKK)
      GOTO 210
208   S=PSIGN(ONE,AKL)
210   IF (DABS(S)-.5)214,212,212
212   S=PSIGN(.5*ONE,S)
214   SS=S*S
      CC=1-SS
      C=DSQRT(CC)
      SC=S*C
      QL(K,K)=CC*AKK-2*SC*AKL+SS*ALL
      QL(L,L)=SS*AKK+2*SC*AKL+CC*ALL
      QL(L,K)=(CC-SS)*AKL+SC*(AKK-ALL)
      QL(K,L)=QL(L,K)
      J=6-K-L
      AKK=QL(J,K)
      ALL=QL(J,L)
      QL(J,K)=C*AKK-S*ALL
      QL(K,J)=QL(J,K)
      QL(J,L)=S*AKK+C*ALL
      QL(L,J)=QL(J,L)
      DO 230 I=1,3
      AKK=TRANS(K,I)
      ALL=TRANS(L,I)
      TRANS(K,I)=C*AKK-S*ALL
      TRANS(L,I)=S*AKK+C*ALL
230   CONTINUE
      GOTO 100
C
C               * ROTATION COMPLETE
250   ALL=0
      DO 280 I=1,3
      QL(I,4)=.5*P*TRANS(I,1)+.5*Q*TRANS(I,2)+.5*R*TRANS(I,3)
      QL(4,I)=QL(I,4)
280   ALL=ALL+DABS(QL(I,I))
      ALL=ALL/3.E10
C
C               * COMPUTE TRANSLATION
      DO 300 K=1,3
      AKK=QL(K,K)
      IF (DABS(AKK)-ALL) 290,290,285
285   TRANS(K,4)=QL(K,4)/AKK
      AKL=TRANS(K,4)
      QL(4,4)=QL(4,4)-AKL*QL(K,4)
      QL(K,4)=0
      QL(4,K)=0
      GOTO 300
290   QL(K,K)=0
300   CONTINUE
      IF (DABS(QL(4,4))-ALL) 305,305,310
305   QL(4,4)=0
310   AKK=0
      DO 320 J=1,4
      IF (DABS(QL(J,J))-AKK)320,320,315
315   AKK=DABS(QL(J,J))
320   CONTINUE
      IF (AKK) 325,330,325
325   DO 328 I=1,4
      DO 328 J=1,4
328   QL(I,J)=QL(I,J)/AKK
330   CONTINUE
C
C               * CLASSIFY SURFACE TYPE
C
      I=0
      J=0
      L=0
      N=0
      DO 400 K=1,3
      KK=PSIGN(ONE,QL(K,K))
340   I=I+PSIGN(ONE,DABS(QL(K,K)))
      J=J+KK
      L=L+PSIGN(ONE,DABS(QL(K,4)))
400   N=N+PSIGN(ONE,QL(K,K))
      K=DABS(J+PSIGN(ONE,QL(4,4)))
      J=IABS(J)
C
C        ** SURFACE TYPE MARKER IS IIT **
      IIT=10*I+J+K+3*L+1
C
      IF (N) 404,402,410
402   IF (QL(4,4)) 404,410,410
404   DO 408 IL=1,4
      DO 408 LL=1,4
408   QL(IL,LL)=-QL(IL,LL)
C
C        SET IQ TO 1 - NO RECOGNIZABLE SURFACE - AND BRANCH
C                  IF SURFACE TYPE SHOULD BE RESET ACCORDING
C                  TO SURFACE TYPE MARKER (IIT)
410   IQ=1
C
      GO TO (1000,1000,1000,520,520,  1000,520,520,1000,520,
     +       520,530,530,530,540,     540,540,540,540,1000,
     +       550,560,1000,570,550,    580,590,590,590,1000,
     +       1000,610,620,630,1000,   640,650,660),  IIT
C
C        PLANE SURFACE
520   IQ=2
      CC=DSQRT(QL(1,4)**2+QL(2,4)**2+QL(3,4)**2)
      DO 525 IL=1,4
      QL(IL,4)=QL(IL,4)/CC
      QL(4,IL)=QL(IL,4)
525   CONTINUE
      GOTO 1000
C
C        TWO PARALLEL OR COINCIDENT PLANES
530   IQ=3
      GOTO 1000
C
C        PARABOLIC CYLINDER
540   IQ=4
      GOTO 1000
C
550   IF (L-1)552,600,552
C
C        TWO INTERSECTING PLANES
552   IQ=5
      GOTO 1000
C
C        HYPERBOLIC CYLINDER
560   IQ=6
      GOTO 1000
C
570   IF (L-1) 572,600,572
C
C        ELLIPTIC CYLINDER
572   IQ=7
      GOTO 1000
C
C        IMAGINARY ELLIPTIC CYLINDER
580   IQ=9
      GOTO 1000
C
C        ELLIPTIC PARABOLOID
590   IQ=10
      GOTO 1000
C
C        HYPERBOLIC PARABOLOID
600   IQ=8
      GOTO 1000
C
C        HYPERBOLOID OF ONE SHEET
610   IQ=11
      GOTO 1000
C
C        CONE
620   IQ=12
      GOTO 1000
C
C        HYPERBOLOID OF TWO SHEETS
630   IQ=13
      GOTO 1000
C
C        ELLIPSOID
640   IQ=14
      GOTO 1000
C
C        POINT ELLIPSOID
650   IQ=15
      GOTO 1000
C
C        IMAGINARY ELLIPSOID
660   IQ=16
C
C            ** RESET COEFFICIENTS INTO PROPER ORDER **
C
1000  COEFF(1)=QL(1,1)
      COEFF(2)=QL(2,2)
      COEFF(3)=QL(3,3)
      COEFF(4)=QL(4,4)
      COEFF(5)=QL(2,3)
      COEFF(6)=QL(1,3)
      COEFF(7)=QL(1,2)
      COEFF(8)=QL(1,4)
      COEFF(9)=QL(2,4)
      COEFF(10)=QL(3,4)
C
      RETURN
      END