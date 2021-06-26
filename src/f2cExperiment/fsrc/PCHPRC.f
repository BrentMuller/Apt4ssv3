**** SOURCE FILE : M0004323.W03   ***
*
      SUBROUTINE PCHPRC(SS,B,UST,VST,TP,TN,UA,VA,SP,SN,SLX,
     1 IFLAG,ITOP,IPNUM,MODE,IDEBUG,IRR,LGEOM)
C------ THIS PROGRAM ACCEPTS A CURRENT PATCH B AND U,V VALUES.
C------ IT MUST DETERMINE A LINEUP WITH AN INPUT TOOL POINT AND
C------  TOOL NORMAL .  IF THE LINEUP IS NOT ON THE CURRENT
C------ PATCH THEN THE LOGIC FREELY EXCHANGES PATCHES UNTIL AN ANSWER
C------ IS FOUND.  NO MORE THAN TEN PATCH EXCHANGES ARE ALLOWED.
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
      DIMENSION SS(*),DAF(3),DELT(3)
      DIMENSION B(64),IFLAG(4),ITOP(6,4)
      DIMENSION SLX(3),DIF(3)
      DIMENSION SP(32),SN(3),TP(3),TN(3),SPV(32)
      DIMENSION UCHG(8),VCHG(8)
      LOGICAL LGEOM
      CHARACTER*20 BADMSG
C
      INCLUDE 'CSTART.INC'
C
      DATA ZERO,ONE,HALF/0.0D0,1.0D0,0.5D0/
      DATA FLCK0,FLCK1,FLCK2/0.99998D0,0.999992D0,0.9990D0/
      DATA SMAL,VSMAL/1.0D-10,1.0D-20/,BIG/1.0D10/
      DATA UVCHG/0.0005D0/
      DATA UCHG/0.0D0,3*1.0D0,0.0D0,3*-1.0D0/
      DATA VCHG/2*1.0D0,0.0D0,3*-1.0D0,0.0D0,1.0D0/
C---      NITS IS THE NUMBER OR ITERATIONS ALLOWED ON 1 SURFACE
C---      MEXCHG IS THE NUMBER OF PATCH EXCHANGES ALLOWED
      DATA NITS/30/,MEXCHG/10/
C---      STEPMX IS A MAXIMUM STEP WITHIN THE PARAMETRIC UNIT SQUARE
C---      STEPLN IS THE REDUCTION OF STEP SIZE IF IT IS TOO LARGE.
      DATA STEPMX/0.64D0/,STEPLN/0.7D0/,R125/0.125D0/,R875/0.875D0/
C---
C---
C---
C---
      KRETRY=0
      UA=UST
      VA=VST
      ULAST=HALF
      VLAST=HALF
      DRMAX = 0.0D0
      IPNST=IPNUM
    1 IEXCNT = 0
      KINPAT = 0
C
      DO 1000 K=1,NITS
C
      IF (KRETRY.EQ.5) GO TO 8
      IF(KRETRY.EQ.0)  GO TO 8
      IF(IPNUM.NE.IPMAX) GO TO 8
      IF(DABS(UA-UMAX).GT.0.01D0)  GO TO 8
      IF(DABS(VA-VMAX).GT.0.01D0)  GO TO 8
      GO TO 1400
    8 KINPAT=KINPAT+1
      IF(IDEBUG.EQ.0) GO TO 9
      CALL BAD(-1,0,' ',0)
      BADMSG=' PCHPRC LOOP'
      CALL CPRINT(BADMSG)
      CALL BAD(1,0,'PNUM',IPNUM)
      CALL BAD(1,1,'UA  ',UA)
      CALL BAD(1,1,'VA  ',VA)
      CALL BAD(-1,0,'KNPT',KINPAT)
    9 CONTINUE
C
C------EVALUATE THE SURFACE DIFFERENTIAL ELEMENTS AT UA,VA
C------PLACE THE ELEMENTS IN ARRAY SPV
C
      CALL CNSURF(UA,VA,B,SPV,IFLAG,1)
      IF(IDEBUG.EQ.0) GO TO 10
      CALL BAD(3,1,'SP  ',SPV)
      CALL BAD(-3,1,'SPN ',SPV(29))
      CALL BAD(3,1,'SPU ',SPV(5))
      CALL BAD(-3,1,'SP-V',SPV(9))
      CALL BAD(3,1,'SPUU',SPV(13))
      CALL BAD(-3,1,'SPVV',SPV(21))
      CALL BAD(-3,1,'SPUV',SPV(17))
   10 CONTINUE
C
C
C------BEFORE SEEKING A NEW UV PAIR, CHECK THE ACCURACY OF THE
C------PRESENT SURFACE POINT,NORMAL
C------ ERROR COMPUTATIONS DEPEND ON THE VARIABLE MODE
C------ MODE=-1, POSITIVE DDST. =0 SNXP OR CLOSEST POINT. =1
C------ DDST IN EITHER DIRECTION ALONG TOOL RAY.
      DO 20 I=1,3
   20 DIF(I)=TP(I)-SPV(I)
      CALL DOTF(D,DIF,DIF)
      D=DSQRT(D)
C---      IF D IS TOO SMALL, THEN SET IT TO A LARGER VALUE
      D=DMAX1(D,VSMAL)
      DO 25 I=1,3
      DAF(I)=DIF(I)/D
   25 CONTINUE
C
      IF(MODE.NE.0) GO TO 30
C---      COMPUTE ANGLE BETWEEN DIF AND SURFACE NORMAL
      CALL DOTF(DR,DAF,SPV(29))
      GO TO 35
C
   30 CONTINUE
C---      COMPUTE ANGLE BETWEEN DIF AND TOOL RAY
      CALL DOTF(DR,DAF,TN)
C---      NORMALIZE ANGLE BY DIVIDING BY LENGTH OF DIF
   35 CONTINUE
      DR=DABS(DR)
C
      IF(IDEBUG.EQ.0) GO TO 41
      CALL BAD(1,1,'ERR*',DR)
      CALL BAD(1,1,'DIST',D)
      CALL BAD(-3,1,'SPTP',DIF)
   41 CONTINUE
C
C---      IF THE RAY IS AT RIGHT ANGLES TO THE SURFACE, QUIT NOW.
      IF(DR.LT.SMAL.AND.MODE.NE.0) GO TO 9999
C---      ACCEPTANCE CRITERIA, ANGULAR LINEUP BETTER THAN FLIPCK
      IF(MODE.EQ.0.AND.DR.GT.FLCK0) GO TO 2000
      IF(MODE.NE.0.AND.DR.GT.FLCK2) GO TO 2000
      IF(DR.LT.SMAL) GO TO 63
      IF(DR.LT.DRMAX) GO TO 60
      DMAX=D
      DRMAX = DR
      UMAX = UA
      VMAX = VA
      IPMAX = IPNUM
C
C------ ALL INDICATIONS ARE THAT U,V SHOULD BE R MODIFIED
   60 CONTINUE
      CU = ZERO
      CV = ZERO
      DT=ZERO
      ILEV = 3
      IF (KRETRY.LT.5) ILEV=2
      CALL APRIX(CU,CV,DT,SPV,TP,TN,MODE,ILEV,IR,IDEBUG)
C---      IF IR.NE.0, THEN ARBITRARILY ALTER CU,CV SLIGHTLY
  640 IF(IR.EQ.0) GO TO 65
   63 DM=ZERO
      CT=0.025D0
      DO 649 IZ=1,2
      DO 648 J=1,8
      DHU=UA+CT*UCHG(J)
      DHV=VA+CT*UCHG(J)
      CALL CNSURF(DHU,DHV,B,SPV,IFLAG,1)
      DO 641 I=1,3
  641 DIF(I)=TP(I)-SPV(I)
      CALL DOTF(D,DIF,DIF)
      D=DSQRT(D)
      D=DMAX1(D,VSMAL)
      DO 642 I=1,3
  642 DAF(I)=DIF(I)/D
      IF(MODE.NE.0)  GO TO 643
      CALL DOTF(DT,DAF,SPV(29))
      GO TO 644
  643 CALL DOTF(DT,DAF,TN)
  644 DT=DABS(DT)
      IF(DT.LE.DM)  GO TO 648
      JMAX=J
      CTM=CT
      DM=DT
  648 CONTINUE
      CT=0.075D0
  649 CONTINUE
      IF(IDEBUG.NE.0) CALL BAD(1,1,'ERRT',DM)
      IF(IDEBUG.NE.0) THEN
        CALL BAD(-1,0,' ',0)
        BADMSG=' AFTER UV CHANGE'
        CALL CPRINT(BADMSG)
      ENDIF
      IF(1.1D0*DT.LT.DRMAX.OR.DT.LT.SMAL)  GO TO 1400
      CU=UCHG(JMAX)*CTM
      CV=VCHG(JMAX)*CTM
   65 CONTINUE
C
      U1=UA+CU
      V1=VA+CV
C
      IF(IDEBUG.EQ.0) GO TO 42
      CALL BAD(1,1,'UNXT',U1)
      CALL BAD(1,1,'VNXT',V1)
      CALL BAD(1,1,'UCHG',CU)
      CALL BAD(-1,1,'VCHG',CV)
   42 CONTINUE
C
C------ SQRCUT DETERMINES IF A BOUNDARY IS BEING CROSSED.  IF IT IS,
C------ IT WILL THEN DETERMINE IF AN EXCHANGE SHOULD BE CONSIDERED
C------ ON THE BOUNDARY ICKBN.
C
      CALL SQRCUT(UA,VA,U1,V1,U,V,ICKBN)
C---      SAVE THE NUMBER OF THE CURRENT PATCH
      IPSAVE=IPNUM
      IF(IDEBUG.EQ.0) GO TO 43
      CALL BAD(1,1,'UCUT',U)
      CALL BAD(1,1,'VCUT',V)
      CALL BAD(1,0,'ICKB',ICKBN)
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER SQRCUT'
      CALL CPRINT(BADMSG)
   43 CONTINUE
C---      RESTRICT A PARAMETER CHANGE WITHIN THE UNIT SQUARE
      IF(KINPAT.LE.1) GO TO 130
      IF(DABS(ULAST-HALF).GT.HALF) GO TO 130
      IF(DABS(VLAST-HALF).GT.HALF) GO TO 130
      IF(DABS(U-HALF).GT.HALF) GO TO 130
      IF(DABS(V-HALF).GT.HALF) GO TO 130
C---      BOTH POINTS ARE WITHIN THE UNIT SQUARE, SO CHECK FOR LENGTH
      STEP=(U-ULAST)**2+(V-VLAST)**2
      IF(STEP.LT.STEPMX) GO TO 130
C---      MODIFY STEP LENGTH TO AVOID TRAVERSING COMPLETE PATCH
      U=ULAST+STEPLN*(U-ULAST)
      V=VLAST+STEPLN*(V-VLAST)
      ICKBN=0
      IF(IDEBUG.EQ.0) GO TO 130
      CALL BAD(1,1,'ULIM',U)
      CALL BAD(-1,1,'VLIM',V)
  130 CONTINUE
C
C------ BONCHK WILL SEARCH BOUNDARY ICKBN AND IF ANOTHER PATCH IS
C------ FOUND, WILL EXCHANGE THE CURRENT PATCH VALUES.
C
      IF(ICKBN.EQ.0) GO TO 110
C---
      CALL BONCHK(SS,B,U,V,IFLAG,ITOP,IPNUM,ICKBN,IDEBUG)
      IF(IPSAVE.NE.IPNUM) GO TO 1300
      GO TO 110
C---      A PATCH EXCHANGE OCCURRED SO INCREMENT THE EXCHANGE COUNT
 1300 IEXCNT=IEXCNT+1
C---      RESET COUNTER FOR ITERATIONS ON THIS PATCH TO ZERO
      KINPAT=0
C
      IF(IDEBUG.EQ.0) GO TO 120
      CALL BAD(1,1,'UNEW',U)
      CALL BAD(1,1,'VNEW',V)
      CALL BAD(1,0,'PNUM',IPNUM)
      CALL BAD(1,0,'EXCT',IEXCNT)
      CALL BAD(-1,0,' ',0)
      BADMSG=' AFTER BONCHK'
      CALL CPRINT(BADMSG)
  120 CONTINUE
C
      UA=U
      VA=V
  110 CONTINUE
      IF(IEXCNT.GT.MEXCHG) GO TO 1400
C
 1100 ULAST=UA
      VLAST=VA
      UA=U
      VA=V
 1000 CONTINUE
C---      ACCEPT A LESSER TOLERANCE, IF NECESSARY.
 1400 IF(DRMAX.GT.FLCK2) GO TO 1500
      IF(DR.GT.FLCK2) GO TO 2000
 1410 KRETRY=KRETRY+1
      IF (KRETRY.GT.4) THEN
        IF (KRETRY.GT.5) GOTO 9999
        UA=UMAX
        VA=VMAX
        IPNUM=IPMAX
        CALL LODPCH(SS,B,IFLAG,ITOP,IPNUM,3)
      ELSE
        UA=UST
        VA=VST
        IF(KRETRY.EQ.1)  VA=-HALF
        IF(KRETRY.EQ.2)  UA=-HALF
        IF(KRETRY.EQ.3)  UA=1.5D0
        IF(KRETRY.EQ.4)  VA=1.5D0
        IPNUM=IPNST
        CALL LODPCH(SS,B,IFLAG,ITOP,IPNUM,3)
        CALL SQRCUT(UST,VST,UA,VA,U,V,ICKBN)
        IF(ICKBN.EQ.0) GO TO 1410
        CALL BONCHK(SS,B,U,V,IFLAG,ITOP,IPNUM,ICKBN,IDEBUG)
        UA=U
        VA=V
        IF(KRETRY.EQ.1)  VA=VA-HALF
        IF(KRETRY.EQ.2)  UA=UA-HALF
        IF(KRETRY.EQ.3)  UA=UA+HALF
        IF(KRETRY.EQ.4)  VA=VA+HALF
      ENDIF
      IF(IDEBUG.EQ.0)  GO TO 1
      CALL BAD(1,1,'UA  ',UA)
      CALL BAD(1,1,'VA  ',VA)
      CALL BAD(1,0,'PNUM',IPNUM)
      CALL BAD(-1,0,'RETY',KRETRY)
      GO TO 1
C---      ERROR, ROUTINE FAILED TO DETERMINE SURFACE PT WITHIN TOLERANCE
 9999 CONTINUE
C.... FOR MODE=0 (CALC. SP WITH MINIMUM DISTANCE TO TE)
C.... AND (DMAX.GT.10) AND (DRMAX.GT.0.8) TAKE BEST SOLUTION
      IF (((MODE.EQ.0).AND.(DMAX.GT.10.D0)).AND.(DRMAX.GT.0.8D0))
     +   GO TO 1500
      IRR=7001
      GO TO 3000
C
C --- THE BEST LINE-UP IS ACCEPTED WITH A LESSER TOLERANCE
C
 1500 IPNUM = IPMAX
      CALL LODPCH(SS,B,IFLAG,ITOP,IPNUM,3)
      UA = UMAX
      VA = VMAX
      CALL CNSURF(UA,VA,B,SPV,IFLAG,1)
C
 2000 IRR=0
      IF(NITS.NE.20) GO TO 2003
      NITS = 30
      GO TO 1
 2003 CONTINUE
C
      IF (UA.LT.ZERO) THEN
        UDIST=-UA
        UBOND=ZERO
      ELSE
        IF (UA.LE.ONE) THEN
          UDIST=ZERO
          UBOND=UA
        ELSE
          UDIST=UA-ONE
          UBOND=ONE
        ENDIF
      ENDIF
C
      IF (VA.LT.ZERO) THEN
        VDIST=-VA
        VBOND=ZERO
      ELSE
        IF (VA.LE.ONE) THEN
          VDIST=ZERO
          VBOND=VA
        ELSE
          VDIST=VA-ONE
          VBOND=ONE
        ENDIF
      ENDIF
C
      UVDIST=UDIST + VDIST
C
      DIST=D
C
      IF (UVDIST.GE.0.1D0) THEN
        CALL LODPCH(SS,B,IFLAG,ITOP,IPNUM,3)
        CALL CNSURF(UBOND,VBOND,B,SPBOND,IFLAG,1)
      ENDIF
C
      DO 2005 I=1,3
      SP(I)=SPV(I)
      SN(I)=SPV(I+28)
 2005 CONTINUE
C
C---  LGEOM=.TRUE. SIGNIFIES A SPECIAL CALL FOR GEOMETRIC CONSTRUCTION
      IF (LGEOM) THEN
        DO 2001 II=4,32
        SP(II)=SPV(II)
 2001   CONTINUE
      END IF
C---      SLX VECTOR IS SET IN THE DIRECTION OF THE CRSSPL VECTOR
C---      THIS IS FOR SPECIAL ARELEM TOOL AXIS PRORATING.
      CALL VNORM(SPV(9),SLX)
C
C
 3000 CONTINUE
      RETURN
      END