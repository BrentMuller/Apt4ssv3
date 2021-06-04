**** SOURCE FILE : M0002734.V07   ***
*
C.....FORTRAN SUBROUTINE  ....APT240         8/68                 RN,PH
C.....FORTRAN SUBROUTINE             APT240...              4/16/68  GK
C
C              FORTRAN SUBROUTINE APT240 (NUMDIM)
C
C PURPOSE      TO SET THE IAFL FLAG FOR AMIND AND THE NUMDIM FLAG FOR
C              APT201. THIS ROUTINE CALLED BY APT201 AND GO.
C                FLAG SETTINGS
C                 IAFL = -1  NORMAL CASE
C                 IAFL = 0   TOOL PERP. TO PS PLANE OR PARL. TO DS OR CS
C                 IAFL = 1   TA PARLEL SURF. LINE ELEMENT
C                 NUMDIM = 0  USE 2D ROURES
C                 NUMDIM = 1  USE 3D ROUTES
C
      SUBROUTINE APT240 (NUMDIM)
      IMPLICIT DOUBLE PRECISION (A-H), DOUBLE PRECISION(O-Z)
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C    ALIGN J11 ON DOUBLE WORD BOUNDRY.
      EQUIVALENCE  (J11,REAL8)
C
      INCLUDE 'BLANKCOM.INC'
C
      NUMDIM = K0
      IF (K2- MANTAX) 22,22,3
   22 NUMDIM = K1
      GO TO 14
    3 L = LSV
      M = ICS + LSV1*(ICSCNT - K1)
      N = IPS
      IF (ISFIDN(IPS).GT.K2) GO TO 7
      IC = ICANON(IPS)
      CALL DOTF (TEMP,TA,CANON(IC))
      IF(DABS(TEMP(1)).LT..9999999) GO TO 10
      IAFL(N) = 0
      ITSEG(N) = 1
   23 IT = ITSEG(N)
      TOOLHT(1,N) = TLHITE(IT)*TA(1)
      TOOLHT(2,N) = TLHITE(IT)*TA(2)
      TOOLHT(3,N) = TLHITE(IT)*TA(3)
      TOOLWD(N) = CORRAD(IT)+RI(IT)
      GO TO 10
    7 NUMDIM = K1
   10 IF (N.GE.M) GO TO 14
      N = N+ L
      IF (N.EQ.ICS) L = LSV1
      IC = ICANON(N)
      JSW = ISFIDN(N)
      IF(JSW.EQ.29.OR.JSW.EQ.30) GO TO 115
      IF((JSW.LE.0).OR.(JSW.GT.15)) GO TO 8010
      GO TO (110,110,111,111,115,112,112,112,115,112,113,115,115,115,
     +       115), JSW
  110 CALL DOTF (TEMP,TA,CANON(IC))
      IF(DABS(TEMP(1)).GT..0000001) GO TO 115
      IAFL(N) = 0
      GO TO 117
  111 CALL DOTF (TEMP,TA,CANON(IC+3))
      IF (DABS(TEMP(1)).LT..9999999) GO TO 115
  116 IAFL(N) = K1
      GO TO 117
  115 NUMDIM = K1
      GO TO 10
  112 NUMDIM = K1
      IF(DABS(TA(3)).EQ.Z1) GO TO 116
      GO TO 10
  113 CALL APT094(3,CANON(IC),J11)
      J11=J11-1
      CALL DOTF(TEMP,TA,CANON(J11+8) )
      IF (DABS(TEMP(1)).LT..9999999) GO TO 115
      NUMDIM = K1
      GO TO 116
  117 IF (ITLON(N).EQ.0) GO TO 120
      IF(COSL(7)) 200,300,119
  200 IAFL(N)=KM1
      GO TO 115
  300 CONTINUE
      IF (TCONT(5).NE.0.)GO TO 122
      ITSEG(N) = 4
      GO TO 23
  120 ITSEG(N) = 1
      GO TO 23
  119 ITSEG(N) = 7
      GO TO 23
  122 ITSEG(N) = 5
      GO TO 23
 8010 CALL AERR (20101,'APT240  ')
   14 RETURN
      END
