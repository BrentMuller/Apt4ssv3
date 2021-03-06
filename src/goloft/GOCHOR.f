**** SOURCE FILE : M0012232.V01   ***
*
      SUBROUTINE GOCHOR(MODC,U1,U2,J11,IRET)
C
C
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C
      COMMON/PLGOL/ID(24)
      DOUBLE PRECISION UVCONS,TOL,VL
      EQUIVALENCE (ID(1),UVCONS)
      EQUIVALENCE (ID(7),TOL)
      EQUIVALENCE (ID(9),VL)
C
C  POINT STORAGE AND CURVATURE
      DOUBLE PRECISION SPV(52,3),K1
C
C AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
C
      TOL2=TOL*TOL
      UI=U1
      UJ=U1
C
C  TANGENT IN SPV (-1)
      IT=4
      IF(MODC.EQ.2.OR.MODC.EQ.3) IT=8
C
C  DIFFERENT KINDS OF CALCULATION
    1 GOTO( 10, 20, 30, 40, 50),MODC
C
C  CURVE
   10 CALL GOP(3,UI,UDUMMY,SPV(1,1),J11,IRET)
C
C  CURVATURE OF A CURVE
      SPSP=0.D0
      SPPSPP=0.D0
      SPSPP=0.D0
      DO 11 I=1,3
      SPI=SPV(4+I,1)
      SPPI=SPV(8+I,1)
      SPSP=SPI*SPI+SPSP
      SPPSPP=SPPI*SPPI+SPPSPP
   11 SPSPP=SPI*SPPI+SPSPP
C
C  OFFSET OF RADIUS
      ZR=0.D0
      IF(DABS(SPSP).LT.1.D-12) GOTO 12
C
C  LENGTH OF THE TANGENT
      TL=DSQRT(SPSP)
      K1=DSQRT((DABS(SPSP*SPPSPP-SPSPP*SPSPP)/SPSP/SPSP/SPSP))
      GOTO 60
   12 K1=1.D18
      GOTO 60
C
C  CURVATURE AT VARIABLE V
   20 CONTINUE
   30 CALL GOP(3,UVCONS,UI,SPV(1,1),J11,IRET)
C
C  K=N/G
      K1=SPV(51,1)/SPV(47,1)
C
C  LENGTH OF TANGENT
      TL=DSQRT(SPV(47,1))
C
C  OFFSET OF RADIUS
      ZR=SPV(52,1)
      GOTO 60
C
C  CURVATURE AT VARIABLE  U
   40 CONTINUE
   50 CALL GOP(3,UI,UVCONS,SPV(1,1),J11,IRET)
C
C  K=L/E
      K1=SPV(49,1)/SPV(45,1)
C
C  LENGTH OF THE TANGENT
      TL=DSQRT(SPV(45,1))
C
C  OFFSET OF RADIUS
      ZR=SPV(52,1)
      GOTO 60
C
C  CACULATION OF THE STEP OUT U-DISTANCE
   60 IF(K1.LT.0.D0)ZR=-ZR
      K1=DABS(K1)
      R1=1.D0/(K1+1.D-12)
      IF(R1.LT.TOL) GOTO 61
      IF(ZR.EQ.0.D0) GOTO 63
      R1=R1+ZR
      IF(R1.LE.0.D0)GOTO 61
      TL=TL/(R1-ZR)*R1
   63 DU=2.D0*DSQRT(TOL*(R1+R1-TOL))/TL
      GOTO 62
   61 DU=TOL
C  R1 LESS THAN THE TOLERANCE
      CALL AERR(-22221,'GOCHOR  ')
   62 CONTINUE
C
C  LENGTH COMPUTING OF THE CUT
      IF(DU*TL.LT.VL) GOTO 64
      DU=DU*VL*.99D0/TL
   64 CONTINUE
      GOTO(110,120,130,140,150),MODC
C
C  U2 IS BIGGER THAN   U1
  110 CONTINUE
  120 CONTINUE
  140 IANZ=(U2-UI)/DU
      ANZ=IANZ+1
      DU=(U2-UI)/ANZ
      UJ=UI+DU+.0000001D0
      IF(UJ.GT.U2) UJ=U2
      GOTO 160
C
C  U1 IS BIGGER THAN  U2
  130 CONTINUE
  150 IANZ=(UI-U2)/DU
      ANZ=IANZ+1
      DU=(UI-U2)/ANZ
      UJ=UI-DU-.0000001D0
      IF(UJ.LT.U2) UJ=U2
      GOTO 160
C
C  COMPUTATION OF THE NEW ENDPOINT AND CONTROL OF THE CHORD
  160 GOTO(210,220,230,240,250),MODC
  210 CONTINUE
  240 CONTINUE
  250 CALL GOP(1,UJ          ,UVCONS,SPV(1,2),J11,IRET)
      CALL GOP(1,(UJ+UI)/2.D0,UVCONS,SPV(1,3),J11,IRET)
      GOTO 260
  220 CONTINUE
  230 CALL GOP(1,UVCONS,          UJ,SPV(1,2),J11,IRET)
      CALL GOP(1,UVCONS,(UJ+UI)/2.D0,SPV(1,3),J11,IRET)
      GOTO 260
C
C  DISTANCE VALUES :
  260 AB=QABPST(SPV(1,1),SPV(1,2),SPV(1,3))
      IF(AB.LE.TOL2) GOTO 270
      UJ=(UI+UJ)/2.D0
      GOTO 160
C
C  CONTROL OF THE LENGTH OF A CUT
  270 VL1=DSQRT((SPV(1,2)-SPV(1,1))**2
     *         +(SPV(2,2)-SPV(2,1))**2
     *         +(SPV(3,2)-SPV(3,1))**2)
C
      IF(VL1.LE.VL) GOTO 280
      DU=DU*VL*.9D0/VL1
      GOTO 64
C
C  CONTROL OF THE TURNING POINT
  280 IF((SPV(IT+2,1)*SPV(IT+3,3)-SPV(IT+3,1)*SPV(IT+2,3))
     *  *(SPV(IT+2,3)*SPV(IT+3,2)-SPV(IT+3,3)*SPV(IT+2,2))
     *  +(SPV(IT+3,1)*SPV(IT+1,3)-SPV(IT+1,1)*SPV(IT+3,3))
     *  *(SPV(IT+3,3)*SPV(IT+1,2)-SPV(IT+1,3)*SPV(IT+3,2))
     *  +(SPV(IT+1,1)*SPV(IT+2,3)-SPV(IT+2,1)*SPV(IT+1,3))
     *  *(SPV(IT+1,3)*SPV(IT+2,2)-SPV(IT+2,3)*SPV(IT+1,2)))
     * 285,290,290
  285 UJ=(UI+UJ)/2.D0
      GOTO 160
  290 UI=UJ
C
C  FINISHED ?
      IF(UJ.NE.U2) GOTO 1
C
C  THE LAST POINT WILL BE OUTPUT IN THE CALLING PROGRAM
      RETURN
      END
