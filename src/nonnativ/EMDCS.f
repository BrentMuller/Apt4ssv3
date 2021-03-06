**** SOURCE FILE : M0008175.V05   ***
*
      SUBROUTINE EMDCS (U,V,DATA,SPV,MODE)
      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
C  EVALUATION ROUTINE FOR
C   "MASTER DIMENSION CONTOUR SURFACE" - MCDS
C
C   PATCH DATA
      DIMENSION DATA(120)
C   OUTPUT: EVALUATION VECTOR
      DIMENSION SPV(4,12)
C  FUNCTIOS IN V, FV(I,2): 1.DERIVATIVE; FV(I,3): 2.DERIVATIVE;
C                                        FV(I,4): 3.DERIVATIVE
      DIMENSION FV(3,4)
C  8 CONICS WITH DERIVATIVES (1.,2.,AND 3.)
      DIMENSION YZ(8,4),YZ1(2,4,4)
      EQUIVALENCE (YZ(1,1),YZ1(1,1,1))
C  6 CONIC DELTAS AND DERIVATIVE ((Y1,Y4,Y3),(Z1,Z4,Z3))
      DIMENSION YZS(3,2,4)
C  3 WEIGHT FUNCTIONS UND DERIVATIVES (W1,W4,W3)
      DIMENSION WS(3,4)
      INTEGER IW(4)
C  AUXILIARY ARRAY
      DIMENSION HI(3)
                     
      DATA FV(1,3),FV(2,3),FV(3,3) /2.D0,-2.D0,2.D0/
      DATA FV(1,4),FV(2,4),FV(3,4) /3*0.D0/
      DATA IW/2,3,1,2/
C
C    SET OF INTERNAL MODE, IF NECESSARY
      GOTO (1,2,3),MODE
C    POINT ONLY
      IMODE=1
      NRES=1
      GOTO 4
C    POINT AND TANGENTS
    1 IMODE=2
      NRES=3
      GOTO 4
C    POINT, TANGENTS AND 2. DERIVATIVE
    2 IMODE=3
      NRES=8
      GOTO 4
C    POINT, TANGENTS, 2. AND 3. DERIVATIVE
    3 IMODE=4
      NRES=12
      GOTO 4
C  ZERO SPV
    4 DO 5 I=1,4
      DO 5 J=1,NRES
    5 SPV(I,J)=0.D0
C  X(U) = XMIN+EXT*U
      SPV(1,1)=DATA(31)+DATA(32)*U
C  DX/DU = EXT
      SPV(1,2)=DATA(32)
C  FUNCTIONS IN V:  FV(1-3,1) = (1-V)**2, V*(1-V), V**2
   10 FV(3,1)=V*V
      FV(2,1)=V-FV(3,1)
      FV(1,1)=1.D0-V-FV(2,1)
      IF(IMODE.EQ.1) GOTO 20
C  DERIVATIVES IN V:  FV(1-3,2) = 2V-2, 1-2V, 2V
      FV(3,2)=V+V
      FV(2,2)= 1.D0-FV(3,2)
      FV(1,2)=-1.D0-FV(2,2)
C  2. DERIVATIVES OF V-FUNCTIONS  FV(1-3,3) = 2,-2, 2 (CONSTANT)
C  3. DERIVATIVES OF V-FUNCTIONS  FV(1-3,4) = 0, 0, 0  (CONSTANT)
C
C  8 CONIC FUNCTIONS
   20 XHX=SPV(1,1)*SPV(1,1)
      IRN=0
      DO 30 I=1,8
      IRN1=DATA(I)
      IF(IRN1.LE.IRN) GOTO 25
C  COMPUTE CONIC (1. TIME)
      IRN=IRN1
      ID=DATA(IRN+9)
      IF(DATA(ID).NE.1.D0) GOTO 23
C  LINE CONIC: Y = YMIN+YEXT*U
      YZ(I,1)=DATA(ID+1)+DATA(ID+2)*U
      YZ(I,2)=DATA(ID+2)
      YZ(I,3)=0.D0
      YZ(I,4)=0.D0
      GOTO 30
C  CONICS: Y1,Z1,Y2,Z2,Y3,Z3,Y4,Z4
   23 YZ(I,1)=(DSQRT(DATA(ID+7)*XHX+DATA(ID+8)*SPV(1,1)
     *              +DATA(ID+9))*DATA(ID+10)
     *              -DATA(ID+2)*SPV(1,1)-DATA(ID+5))/DATA(ID+3)
      IF(IMODE.EQ.1) GOTO 30
C  CONIC DERIVATIVES TO U:YS= -(A*X+B*Y+D)/(B*X+C*Y+E)*L
      QQ=       DATA(ID+2)*SPV(1,1)+DATA(ID+3)*YZ(I,1)+DATA(ID+5)
      YZ(I,2)=-(DATA(ID+1)*SPV(1,1)+DATA(ID+2)*YZ(I,1)+DATA(ID+4))
     *        /QQ*SPV(1,2)
      IF(IMODE.EQ.2) GOTO 30
C  2. DERIVATIVES:YSS= -(A*L**2+2*B*L*YS+C*YS**2)/(B*X+C*Y+E)
      YZ(I,3)=-(SPV(1,2)*(DATA(ID+1)*SPV(1,2)
     *        +2.D0*DATA(ID+2)*YZ(I,2))
     *        +DATA(ID+3)*YZ(I,2)*YZ(I,2))/QQ
      IF(IMODE.EQ.3) GOTO 30
C  3. DERIVATIVES:YSSS= -3*YSS*(B*L+C*YS)/(B*X+C*Y+E)
      YZ(I,4)=-3.D0*YZ(I,3)*(DATA(ID+2)*SPV(1,2)+
     *                       DATA(ID+3)*YZ(I,2))/QQ
      GOTO 30
C  CONIC ALREADY COMPUTED
   25 DO 27 I1=1,I
      IRN2=DATA(I1)
      IF(IRN2.NE.IRN1) GOTO 27
      YZ(I,1)=YZ(I1,1)
      YZ(I,2)=YZ(I1,2)
      YZ(I,3)=YZ(I1,3)
      YZ(I,4)=YZ(I1,4)
      GOTO 30
   27 CONTINUE
   30 CONTINUE
C  CONIC DIFFERENCES
      DO 40 I=1,IMODE
C  Y1S = Y1 - Y2
      YZS(1,1,I)=YZ(1,I)-YZ(3,I)
C  Y4S = Y4 - Y2
      YZS(2,1,I)=YZ(7,I)-YZ(3,I)
C  Y3S = Y3 - Y2
      YZS(3,1,I)=YZ(5,I)-YZ(3,I)
C  Z1S = Z1 - Z2
      YZS(1,2,I)=YZ(2,I)-YZ(4,I)
C  Z4S = Z4 - Z2
      YZS(2,2,I)=YZ(8,I)-YZ(4,I)
C  Z3S = Z3 - Z2
      YZS(3,2,I)=YZ(6,I)-YZ(4,I)
C  MOVE Y4, Z4 TO Y2, Z2
      YZ(3,I)=YZ(7,I)
      YZ(4,I)=YZ(8,I)
   40 CONTINUE
C  COEFFICIENTS OF WEIGHT FUNCTIONS
      DO 50 I=1,3
      I1=IW(I)
      I2=IW(I+1)
      WS(I,1)=YZS(I1,1,1)*YZS(I2,2,1)-YZS(I1,2,1)*YZS(I2,1,1)
      IF(IMODE.EQ.1) GOTO 50
C  1. DERIVATIVE
      WS(I,2)=YZS(I1,1,2)*YZS(I2,2,1)-YZS(I1,2,2)*YZS(I2,1,1)
     *       +YZS(I1,1,1)*YZS(I2,2,2)-YZS(I1,2,1)*YZS(I2,1,2)
      IF(IMODE.EQ.2) GOTO 50
C  2. DERIVATIVE
      WS(I,3)=YZS(I1,1,3)*YZS(I2,2,1)-YZS(I1,2,3)*YZS(I2,1,1)
     * +2.D0*(YZS(I1,1,2)*YZS(I2,2,2)-YZS(I1,2,2)*YZS(I2,1,2))
     *       +YZS(I1,1,1)*YZS(I2,2,3)-YZS(I1,2,1)*YZS(I2,1,3)
      IF(IMODE.EQ.3) GOTO 50
C  2. DERIVATIVE
      WS(I,4)=YZS(I1,1,4)*YZS(I2,2,1)-YZS(I1,2,4)*YZS(I2,1,1)
     * +3.D0*(YZS(I1,1,3)*YZS(I2,2,2)-YZS(I1,2,3)*YZS(I2,1,2))
     * +3.D0*(YZS(I1,1,2)*YZS(I2,2,3)-YZS(I1,2,2)*YZS(I2,1,3))
     *       +YZS(I1,1,1)*YZS(I2,2,4)-YZS(I1,2,1)*YZS(I2,1,4)
   50 CONTINUE
C  WEIGHTED COORDINATES
      DO 60 I=1,2
      DO 60 J=1,3
      QQ1=WS(J,1)*YZ1(I,J,1)
      SPV(I+1,1)=SPV(I+1,1)+QQ1*FV(J,1)
      IF(IMODE.EQ.1) GOTO 60
C
      QQ2=WS(J,2)*YZ1(I,J,1)+WS(J,1)*YZ1(I,J,2)
      SPV(I+1,2)=SPV(I+1,2)+QQ2*FV(J,1)
      SPV(I+1,3)=SPV(I+1,3)+QQ1*FV(J,2)
      IF(IMODE.EQ.2) GOTO 60
C
      QQ3=WS(J,3)*YZ1(I,J,1)+WS(J,2)*YZ1(I,J,2)*2.D0
     *                      +WS(J,1)*YZ1(I,J,3)
      SPV(I+1,4)=SPV(I+1,4)+QQ3*FV(J,1)
      SPV(I+1,5)=SPV(I+1,5)+QQ2*FV(J,2)
      SPV(I+1,6)=SPV(I+1,6)+QQ1*FV(J,3)
      IF(IMODE.EQ.3) GOTO 60
      QQ4=WS(J,4)*YZ1(I,J,1)+WS(J,3)*YZ1(I,J,2)*3.D0
     *                      +WS(J,2)*YZ1(I,J,3)*3.D0
     *                      +WS(J,1)*YZ1(I,J,4)
      SPV(I+1, 9)=SPV(I+1, 9)+QQ4*FV(J,1)
      SPV(I+1,10)=SPV(I+1,10)+QQ3*FV(J,2)
      SPV(I+1,11)=SPV(I+1,11)+QQ2*FV(J,3)
      SPV(I+1,12)=SPV(I+1,12)+QQ1*FV(J,4)
   60 CONTINUE
C  WEIGHT FUNCTION
      DO 65 J=1,3
      SPV(4,1)=SPV(4,1)+WS(J,1)*FV(J,1)
      IF(IMODE.EQ.1) GOTO 65
C
      SPV(4,2)=SPV(4,2)+WS(J,2)*FV(J,1)
      SPV(4,3)=SPV(4,3)+WS(J,1)*FV(J,2)
      IF(IMODE.EQ.2) GOTO 65
C
      SPV(4,4)=SPV(4,4)+WS(J,3)*FV(J,1)
      SPV(4,5)=SPV(4,5)+WS(J,2)*FV(J,2)
      SPV(4,6)=SPV(4,6)+WS(J,1)*FV(J,3)
      IF(IMODE.EQ.3) GOTO 65
C
      SPV(4, 9)=SPV(4, 9)+WS(J,4)*FV(J,1)
      SPV(4,10)=SPV(4,10)+WS(J,3)*FV(J,2)
      SPV(4,11)=SPV(4,11)+WS(J,2)*FV(J,3)
      SPV(4,12)=SPV(4,12)+WS(J,1)*FV(J,4)
   65 CONTINUE
C  COMPUTATION OF (X,Y,Z)-COORDINATES
      IF(IMODE.EQ.1) GOTO 71
      DO 70 I=2,NRES
   70 SPV(4,I)=SPV(4,I)/SPV(4,1)
   71 DO 72 I=2,3
      SPV(I,1)=SPV(I,1)/SPV(4,1)
      IF(IMODE.EQ.1) GOTO 72
      SPV(I,2)=SPV(I,2)/SPV(4,1)-SPV(I,1)*SPV(4,2)
      SPV(I,3)=SPV(I,3)/SPV(4,1)-SPV(I,1)*SPV(4,3)
      IF(IMODE.EQ.2) GOTO 72
      SPV(I,4)=SPV(I,4)/SPV(4,1)-2.D0*SPV(I,2)*SPV(4,2)
     *                               -SPV(I,1)*SPV(4,4)
      SPV(I,5)=SPV(I,5)/SPV(4,1)-SPV(I,2)*SPV(4,3)
     *                          -SPV(I,3)*SPV(4,2)
     *                          -SPV(I,1)*SPV(4,5)
      SPV(I,6)=SPV(I,6)/SPV(4,1)-2.D0*SPV(I,3)*SPV(4,3)
     *                               -SPV(I,1)*SPV(4,6)
      IF(IMODE.EQ.3) GOTO 72
      SPV(I, 9)=SPV(I, 9)/SPV(4,1)-3.D0*SPV(I, 4)*SPV(4, 2)
     *                            -3.D0*SPV(I, 2)*SPV(4, 4)
     *                                 -SPV(I, 1)*SPV(4, 9)
      SPV(I,10)=SPV(I,10)/SPV(4,1)-2.D0*SPV(I, 5)*SPV(4, 2)
     *                                 -SPV(I, 4)*SPV(4, 3)
     *                                 -SPV(I, 3)*SPV(4, 4)
     *                            -2.D0*SPV(I, 2)*SPV(4, 5)
     *                                 -SPV(I, 1)*SPV(4,10)
      SPV(I,11)=SPV(I,11)/SPV(4,1)     -SPV(I, 6)*SPV(4, 2)
     *                            -2.D0*SPV(I, 5)*SPV(4, 3)
     *                            -2.D0*SPV(I, 3)*SPV(4, 5)
     *                                 -SPV(I, 2)*SPV(4, 6)
     *                                 -SPV(I, 1)*SPV(4,11)
      SPV(I,12)=SPV(I,12)/SPV(4,1)-3.D0*SPV(I, 6)*SPV(4, 3)
     *                            -3.D0*SPV(I, 3)*SPV(4, 6)
     *                                 -SPV(I, 1)*SPV(4,12)
   72 CONTINUE
C
C  TRANSFORMATION NECESSARY ?
      IF(DATA(18).EQ.0.D0) GOTO 80
      DO 76 I=1,NRES
      IF(I.EQ.7)GOTO 76
      IF(I.EQ.8)GOTO 76
      DO 74 J=1,3
   74 HI(J)=SPV(J,I)
      DO 75 J=1,3
   75 SPV(J,I)=DATA(4*J+15)*HI(1)+DATA(4*J+16)*HI(2)+DATA(4*J+17)*HI(3)
   76 CONTINUE
C
C  TRANSLATION OF SURFACE POINT COORDINATES
   77 DO 78 I=1,3
   78 SPV(I,1)=SPV(I,1)+DATA(4*I+18)
C
C  SURFACE NORMAL NECESSARY ?
   80 IF(IMODE.LT.2) GOTO 89
C
C  SURFACE NORMAL
      SPV(1,7)=SPV(2,2)*SPV(3,3)-SPV(3,2)*SPV(2,3)
      SPV(2,7)=SPV(3,2)*SPV(1,3)-SPV(1,2)*SPV(3,3)
      SPV(3,7)=SPV(1,2)*SPV(2,3)-SPV(2,2)*SPV(1,3)
C
C  NORMALIZING OF SURFACE NORMAL
      QQ=DSQRT(SPV(1,7)*SPV(1,7)+SPV(2,7)*SPV(2,7)+SPV(3,7)*SPV(3,7))
      IF(QQ.LT.1.D-12)GOTO 89
      SPV(1,8)=SPV(1,7)/QQ
      SPV(2,8)=SPV(2,7)/QQ
      SPV(3,8)=SPV(3,7)/QQ
      SPV(4,7)=1.D0
      SPV(4,8)=1.D0
C
C  SET THE COMPUTATION SIGNAL
   89 DO 90 I=1,NRES
      IF(I.EQ.7)GOTO 90
      IF(I.EQ.8)GOTO 90
      SPV(4,I)=1.D0
   90 CONTINUE
      RETURN
      END
