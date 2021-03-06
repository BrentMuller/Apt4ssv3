**** SOURCE FILE : M0000916.V01   ***
*
C
C.....FORTRAN SUBROUTINE ...GOUGE          SUPPLIED BY VW  6/88
C
C                         MODIFIED FOR SSV..  E.MCLELLAN
C
      SUBROUTINE GOUGE
C     VERSION K1 VOM 8.6.86
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DSHAR4.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
C
      DIMENSION TPSAV(3),TNSAV(3),SPSAV(3),SNSAV(3),U1SAV(3),VTSAV(3)
      DIMENSION HILF(3)
C
      INCLUDE 'CGOUG.INC'
C
      COMMON /MODESS/MODESS,MSSCHK,MSSARL
C
      DATA ZERO /0.D0/
C
C
C++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C+++
C+++  KORR  6-GOUGE -2
C+++
      DURCH = RI(6)
C     INITIALISIERUNG
      JGR = 0
      IFLG = GFLG
C     IF (IABS(IFLG) .GT. 1) STOP ' BETRAG VON GFLG GROESSER 1 '
      IF (IFLG.GE.0) THEN
C
      GFLG = ZERO
      IS = IPS
C
C     WRITE(6,1006) (TE(I), I=1,3)
C     WRITE(6,1007) (TP(I,IS), I=1,3)
C
C      PRINT *, 'GOUGE1:STORE DATA(FLIPMX,RCSAV,TPSAV,....'
C+++
C+++  KORR  6-GOUGE -2 ENDE
C+++
C++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C
      FLIPMX = FLIPCK
      FLIPAB = DABS(FLIPCK)
      RCSAV = RC(IS)
      SSAV = S(IS)
      ITSAV = ITSEG(IS)
      DO 2900 I=1,3
      TPSAV(I) = TP(I,IS)
      TNSAV(I) = TN(I,IS)
      SPSAV(I) = SP(I,IS)
      SNSAV(I) = SN(I,IS)
      U1SAV(I) = U1(I,IS)
      VTSAV(I) = VT(I,IS)
 2900 CONTINUE
C
C++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C+++
C+++  KORR  6-GOUGE -3
C+++
CKEINE PRUEFUNG WENN DP SCHON KLEIN
C---  IF (DP .LT. 0.5D0)  GOTO 106
      IF (DP .LT. 2.0D0)  GOTO 106
C
C
      CALL DOTF(ZAHL, TI, TALT)
C--T--WRITE(6,1003) ZAHL
C      PRINT *, 'GOUGE1 AUFRUF AJUNDD'
      DO 100 I=1,3
      TP(I,IS) = TE(I) + DURCH           * TI(I)
  100 CONTINUE
C--T--WRITE(6,1008) (TP(I,IS), I=1,3)
      MODESS = 11
      CALL AJUNDD
      MODESS = 0
C     VERLETZUNG DER OBERFLAECHE
      DO 101 I=1,3
      HILF(I) = SP(I,IS) - TP(I,IS)
  101 CONTINUE
      CALL DOTF(SHILF, HILF, HILF)
      SHILF = DSQRT(SHILF)
      CALL DOTF(HILF1, HILF, SN(1,IS))
      IF (HILF1 .GT. 0) SHILF = -SHILF
      IF (SHILF .GT. 0) GOTO 103
C---  IF (DABS(SHILF) .LT. 2.0D0*TAU(IS) ) GOTO 106
C   WARNUNG AUSGEBEN
      IF (DABS(SHILF) .LT.10.0D0*TAU(IS) ) GOTO 106
C--T--WRITE(6,7015)(TE(I),I=1,3)
 7015 FORMAT(' *** WARNUNG : TE = ', 3(D12.5, 2X),' TOOL SCHNEIDET '
     1,'FLAECHE')
      GOTO 106
C
C --- RESTORE DATA
C
  103 CONTINUE
C     KEIN LOOK AHEAD, WENN DP NICHT GROSS GENUG
      IF (DABS(SHILF) .GT. 2.0*TAU(IS)) GOTO 106
      IF (DP .LT. 2.0D0)  GOTO 106
C      PRINT *, 'GOUGE1 AUFRUF AJUNDD MIT LOOK AHEAD'
      DO 104 I=1,3
      TP(I,IS) = TE(I) +( DP+DURCH) * TI(I)
  104 CONTINUE
C--T--WRITE(6,1008) (TP(I,IS), I=1,3)
      MODESS = 11
      CALL AJUNDD
      MODESS = 0
C     VERLETZUNG DER OBERFLAECHE
      DO 105 I=1,3
      HILF(I) = SP(I,IS) - TP(I,IS)
  105 CONTINUE
      CALL DOTF(SHILF, HILF, HILF)
      SHILF = DSQRT(SHILF)
      CALL DOTF(HILF1, HILF, SN(1,IS))
      IF (HILF1 .GT. 0) SHILF = -SHILF
      IF (SHILF .GT. 0) GOTO 106
      IF (DABS(SHILF) .LT. 1.5D1*TAU(IS) ) GOTO 106
C--   IF (DABS(SHILF) .LT. 2.5D1*TAU(IS) ) GOTO 106
C ZUSAETZLICHES KRITERIUM
      GFLG  = 1.D0
      JGR = -1
C+++
C+++  KORR  6-GOUGE -3 ENDE
C+++
C++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C
  106 CONTINUE
C      PRINT *, 'GOUGE1 RESTORE DATA , GFLG = ', GFLG
      RC(IS) = RCSAV
      S(IS) = SSAV
      ITSEG(IS) = ITSAV
      DO 2910 I=1,3
      TP(I,IS) = TPSAV(I)
      TN(I,IS) = TNSAV(I)
      SP(I,IS) = SPSAV(I)
      SN(I,IS) = SNSAV(I)
      U1(I,IS) = U1SAV(I)
      VT(I,IS) = VTSAV(I)
 2910 CONTINUE
C
      ELSE
        GFLG = ZERO
      ENDIF
C
 1000 FORMAT(' GOUGE1 : IGOUG = ', I1)
 1001 FORMAT(' GOUGE1 : IS = ',I3, ' IPS = ', I3, ' IDS = ',I3
     1      ,' RC(IPS) = ', D12.5, ' RC(IDS) = ', D12.5 )
 1002 FORMAT(' GOUGE1 : TI  = ', 3(D12.5),/
     1       ' GOUGE1: TIK = ', 3(D12.5),/
     2       ' GOUGE1: GFLG= ',   D12.5)
 1003 FORMAT(' GOUGE1: TI . TIK =', D12.5)
 1004 FORMAT(' GOUGE1: HALBER C.DURCHMESSER:TLLDAT,CUTDAT)',2(D12.5),2X)
 1006 FORMAT(' GOUGE1: TE =', 3(D12.5,2X))
 1007 FORMAT(' GOUGE1: TP =', 3(D12.5,2X))
 1008 FORMAT(' GOUGE1: TPNEU =', 3(D12.5,2X))
      END
