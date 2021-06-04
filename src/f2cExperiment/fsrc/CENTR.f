**** SOURCE FILE : M0002742.W07   ***
*
C.....FORTRAN SUBROUTINE  ....CENTR          8/68                    HG
C...  FORTRAN SUBROUTINE               CENTR
      SUBROUTINE CENTR
      IMPLICIT DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
C
C
C
      INCLUDE 'TOTAL.INC'
      INCLUDE 'DSHAR4.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'SV.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'ISV.INC'
      INCLUDE 'IFXCOR.INC'
      INCLUDE 'ISHR18.INC'
      INCLUDE 'KNUMBR.INC'
C
C
C...  21. ADDCOM BLOCK
C
      COMMON /ADDCOM/ ADDCOM
      DIMENSION ADDCOM(25)
      EQUIVALENCE (ADDCOM(25),KDYNFL)
C
C
      INCLUDE 'CHANG.INC'
      DIMENSION TEZA(3)
C
      DIMENSION P(3)
      DIMENSION SAVETE(3),SAVETA(3)
C
      LOGICAL LRET
C
C                   ACC       FUDGE TERM FOR DISTANCE MEASUREMENTS, SET
C                             AT 5.E-6
C                  IM       FLAG USED IN ORIENTING TANGENT CS NORMAL
C                           WITH OTHER SURFACE NORMAL.
C                   PTOL      FRACTION OF TOTAL TOLERANCE BAND ABOUT
C                             PLANES WITHIN WHICH TOOL IS CONSTRAINED
C                             TO LIE. INITIALLY .2, ENLARGED TO 1.0 AS
C                             ITERATION COUNT INCREASES.
C                   SAVETA(3) SAVES TOOL AXIS DURING NOTAN STEP.
C                   SAVETE(3) SAVES TOOL END POSITION DURING NOTAN STEP.
C                   SAVES     SAVES DISTANCE TO ALL 3 SURFACES ON ENTRY
C                             TO NOTAN STEP.  USED AS A CRITERION FOR
C                             POSSIBLE RESTART FROM ENTRY TO NOTAN.
C                   SMOVE     MAGNITUDE OF SMALLEST VECTOR WHICH CAN BE
C                             ADDED TO TOOL END WITHIN SINGLE PRECISION.
C                             SET ON ENTRY TO CENTR.   ALL MOVE VECTORS
C                             ARE ENLARGED TO THIS SIZE IF NECESSARY
C                   TANANG    CRITERION FOR ESTABLISHING PSEUDO-TANGENCY
C                             IS DOT(CHECK SURF NORMAL, OTHER SURF
C                             NORMAL) .GT. TANANG.  SET AT 1-.5*TAU.
C
C                   PURPOSE   TO ITERATE CUTTER TO DESIRED POSITION
C                             RELATIVE TO 2 OR 3 SURFACES
C
C-----------------------------------------------------------------------
C
C     MAIN ROUTINE
C...                INITIALIZATIONS
C
      ITINK=0
      ITOLFL=0
      JTKF=0
C
      DO 1 I=1,3
        TEZA(I)=TE(I)
   1  CONTINUE
C                                       TINKR FAILURE COUNTER
      JTRC=10
C                                       PLANE TOLERANCE LIMIT FACTOR
      PTOL=.2
C                                       PARALLEL SURFACE TOLERANCE
      TANANG=1.-.5*TAU(IS)
      IF (TANANG.LT.Z9EM1) TANANG=Z9EM1
C                                       EPSILON FOR DISTANCES
      ACC=5.D-6
C                                       MAGNITUDE OF SMALLEST MOVE WHICH
C                                       CAN BE MADE IN SINGLE PRECISION
      SMOVE=1.D-7*DMAX1(DABS(TE(1)),DABS(TE(2)),DABS(TE(3)))
C                                       CPLAN FLAGS
      CPLFL(IS)=0.
      CPTST(IS)=0.
C
C
C
C
C...                SET ITERATION COUNTERS
C
C                                       5-AXIS RESTART COUNTER
      JCNT3=25
C                                       NOTAN CPLAN COUNTER
  100 JCNT2=25
C                                       BASIC CMOVE ITERATION COUNTER
      JCNT1=25
C
C...                CALL 2 SURF IF 2 SURFACE ITERATION
C
  105 IF (J51(IS)) 200,200,120
C
C...                CALL TANTO FOR TANGENT CS, OTHERWISE 3 SURF
C
  120 IF (ISFTYP(IS)-4) 300,400,300
C
C                                       GO TO EXIT
  130 GO TO 1100
C
C
C
C
C
C-----------------------------------------------------------------------
C     2 SURF - ITERATE TOOL INTO PART AND DRIVE ONLY
C
C
C
C...                CALL 2 SURF ITERAT
C
  200 ASSIGN 210 TO J2SURF
      GO TO 600
C
C...                SET FLAG, 2 SURFACE ITERATION SUCCESSFUL
C
  210 JCR=0
C
C...                RETURN TO MAIN PROGRAM
C
      GO TO 130
C
C
C
C
C
C-----------------------------------------------------------------------
C     3 SURF - ITERATE TOOL TO PART, DRIVE, AND CHECK SURFACES
C
C
C
C...                FIND PART AND DRIVE SURFACES
C
  300 ASSIGN 1000 TO JFPD
C
C...                FIND CHECK SURFACE
C
      ASSIGN  302 TO JFNDCK
      GO TO 800
C
C...                FETCH CHECK DATA
C
C                                       NORMAL
  302 DO  305 I=1,3
      PLNV(I,IS)=TN(I,IS)
  305 CONTINUE
C                                       DISTANCE
      PLND(IS)=S(IS)
C
C...                TEST PART AND DRIVE SURFACES
C
      ASSIGN 310 TO JTSTPD
      GO TO 900
  310 IF (JTOL) 330,330,315
C
C...                BOTH WITHIN LIMIT, CALL TEST CHECK SURF
C
  315 ASSIGN 320 TO JTSTCK
      GO TO 1300
  320 IF (JTOL) 330,330,380
C
C...                TEST IF PSEUDO-TANGENCY ALREADY HANDLED
C
  330 IF (NOTAN(IS)) 365,340,340
C
C...                TEST IF PSEUDO-TANGENCY HAS DEVELOPED
C
C                                       TEST CHECK SURF BEYOND STEP
  340 IF (DABS(S(IS))-DP)  350,350,365
C                                       TEST SURFACE TANGENCY
  350 DO 360 I= IPS,IDS,LSV
      IF (TANANG-DABS( SN(1,IS)*SN(1,I)
     1                +SN(2,IS)*SN(2,I)
     2                +SN(3,IS)*SN(3,I))) 370,360,360
  360 CONTINUE
C                                       NO PSEUDO-TAN
C
C...                CALL CMOVE AND LOOP
C
  365 ASSIGN 300 TO JCMOVE
      GO TO 700
C
C...                PSEUDO TANGENCY CASE
C
C                                       SET FLAG FOR TANGENT SURF
  370 IFL4(IS)=(IDS-I)/LSV
C                                       CALL NOTAN AND LOOP
      GO TO 500
C
C...                SET FLAG, SUCCESSFUL 3-SURF ITERATION
C
  380 JCR=1
      GO TO 1100
C
C
C
C
C-----------------------------------------------------------------------
C     TANTO -  3 SURFACE ITERATION IN TANTO OR PSTAN CASE
C
C
C
C...                CALL FIND PART AND DRIVE
C
  400 CONTINUE
      IF(IFL4(IS).EQ.0.AND.
     X   (ISFIDN(IDS).GT.2.OR.ISFIDN(ICS).GT.2)) GO TO 402
      IF(IFL4(IS).EQ.1.AND.
     X   (ISFIDN(IPS).GT.2.OR.ISFIDN(ICS).GT.2)) GO TO 402
      IF(ISFIDN(IPS).LE.2) CALL AERR(25009,'CENTR   ')
  402 IM=-1
      ASSIGN 410 TO JFPD
      GO TO 800
C
C...                CALL FIND CHECK
C
  410 ASSIGN 1400 TO JFNDCK
C
C...                CALL CPLAN SURF
C
      ASSIGN 420 TO JCPLAN
      GO TO 1000
C
C...                TEST WHETHER NORMALS HAVE SAME ORIENTATION
C
  420 IF (PLNCS(IS)) 430,460,460
C
C...                OPPOSITE, TEST WHETHER TOOL NORMAL ALREADY REVERSED
C
  430 IF (IM) 440,450,450
C
C...                NOT REVERSED, REVERSE AND SET FLAG
C
  440 DO 445 I=1,3
      TN(I,IS)=-TN(I,IS)
  445 CONTINUE
      IM=0
      GO TO 410
C
C...                NORMAL REVERSED, TEST WHETHER NORMALS NEAR ORTHOG
C
  450 IF (DABS(PLNCS(IS))-.01) 455,452,452
C
C...                NEAR ORTHOGONAL, ERROR EXIT
C
 452  CALL AERR(25008,'CENTR   ')
C
C...                RESET TOOL NORM REVERSAL FLAG
C
  455 IM=-1
C
C...                TEST WHETHER WITHIN 2*TAU OF CPLAN
C
  460 IF(DABS (PLND(IS))-EPS4(IS) ) 462,462,464
C
C...                WITHIN 2*TAU, TEST WHETHER NORMALS PARALLEL
C
  4620IF( TANANG-DABS(SN(1,IS)*SN(1,IT)
     1               +SN(2,IS)*SN(2,IT)
     2               +SN(3,IS)*SN(3,IT))) 480,480,464
C
C...                CALL CMOVE, USING CPLAN DATA
C
  464 ASSIGN 471 TO JCMOVE
      GO TO 700
C
C...                CALL 2 SURFACE ITERATION AND LOOP
C
 471  IM = -1
      IF(KDYNFL.NE.K0) CALL APT238(K31)
      ASSIGN 410 TO J2SURF
      GO TO 600
C
C...                NORMALS PARALLEL, CALL TEST CHECK SURF
C                                       RETURN TO MAIN IF IN TOL
  480 ASSIGN 482 TO JTSTCK
      GO TO 1300
  482 IF (JTOL) 486,486,483
  483 JCR=1
      GO TO 130
C
C...                NOT WITHIN TOL, TEST WHETHER WITHIN 8*TAU
C
  486 IF (8.*TAU(IS)-DABS(S(IS))) 488,488,464
C
C...                NOT WITHIN 8*TAU, FALSE TANGENCY EXIT
C
  488 JCR=2
      GO TO 1100
C
C
C
C
C-----------------------------------------------------------------------
C     NOTAN - PSEUDO-TANGENCY CALCULATION
C
C
C                                       FLAG- PSEUDO TANGENCY DONE
  500 NOTAN(IS)=-1
C                                       SAVE CUTTER POSITION FOR
C                                       RESET IF NECESSARY
      DO 502 I=1,3
      SAVETE(I)=TE(I)
      SAVETA(I)=TA(I)
  502 CONTINUE
C                                       CURRENT DISTANCE FROM SURFACES
      SAVES=DABS(S(IS))+DABS(S(IDS))+DABS(S(IPS))
C
C...                CALL FIND PART AND DRIVE
C
      ASSIGN 510 TO JFPD
      GO TO 800
C
C...                CALL FIND CHECK
C
  510 ASSIGN 1400 TO JFNDCK
C
C...                CALL CPLAN SURF
C
      ASSIGN 520 TO JCPLAN
      GO TO 1000
C
C...                TEST WHETHER WITHIN 2*TAU OF CPLAN
C
  520 IF (DABS(PLND(IS))-EPS4(IS))  540,540,530
C
C...                                    CALL CMOVE
C
  530 ASSIGN 600 TO JCMOVE
C
C...                                    CALL 2 SURF ITERAT
C
      ASSIGN 531 TO J2SURF
      GO TO 700
C
C...                CALL FIND CHECK
C
  531 ASSIGN 532 TO JFNDCK
      GO TO 1000
C
C...                RESTORE IF MOVED AWAY FROM SURFACES
C
  532 IF (DABS(S(IS))-2.0*SAVES) 510,510,535
  535 DO 537 I=1,3
      TE(I)=SAVETE(I)
      TA(I)=SAVETA(I)
  537 CONTINUE
C                                       RETURN TO 3 SURF
      GO TO 300
C
C...                TEST WHETHER CHECK SURF WITHIN TOL
C
  540 ASSIGN 550 TO JTSTCK
      GO TO 1300
  550 IF (JTOL)  555,555,565
C
C...                TEST WHETHER CHECK SURF WITHIN 8*TAU
C                                       RETURN TO 3 SURF IF SO
 555  IF(8*TAU(IS)-DABS(S(IS)))560,560,535
C
C...                SET FALSE TANGENCY FLAG AND EXIT
C
  560 JCR=2
      GO TO 1100
C
C...                CALL TEST PART AND DRIVE
C
  565 ASSIGN 570 TO JTSTPD
      GO TO 900
C
C...                RETURN TO 3-SURF IF BOTH WITHIN TOL,
C...                FALSE TANGENCY IF NOT
C
  570 IF (JTOL) 560,560,300
C
C
C
C
C-----------------------------------------------------------------------
C     2 SURF ITERATE - ITERATE TOOL INTO PART AND DRIVE SURFACES
C
C
C
C...                FIND PART AND DRIVE SURFACES
C
  600 ASSIGN 900 TO JFPD
C
C...                TEST PART AND DRIVE SURFACES
C
      ASSIGN 605 TO JTSTPD
      GO TO 800
C
C...                RETURN IF BOTH WITHIN TOL
C
  605 IF (JTOL) 615,615,610
C                                       RETURN
  610 GO TO J2SURF, (210,410,510,531)
C
C...                CREATE PSEUDO CHECK SURFACE NORMAL TO
C...                PART AND DRIVE
C
  615 CALL CROSS(  TN(1,IPS),  TN(1,IDS),PLNV(1,IS))
      CALL VNORM(PLNV(1,IS),PLNV(1,IS))
      PLND(IS)=0.0
C
C...                CALL CMOVE AND LOOP
C
      ASSIGN 600 TO JCMOVE
      GO TO 700
C
C
C
C
C-----------------------------------------------------------------------
C     CMOVE - COMPUTE AND APPLY MOVE VECTOR
C
C
C
C...                IN CASE OF PLANE PART AND DRIVE SURFACES, MODIFY
C...                DISTANCES TO DIRECT TOOL TOWARD CENTER OF TOLERANCE
C...                BAND AS ITERATION COUNT INCREASES
C
  700 DO 701 I=IPS,IDS,LSV
C                                       SKIP IF SURF NOT A PLANE
      IF (IPL(I)) 705,701,705
C                                       ADAUST DIST TOWARD CENTER
  705 S(I)=S(I) - (TAU1(I)+TAU2(I))/2.0 * (PTOL-.2)/.8
C
  701 CONTINUE
C.... SPECIAL TREATMENT FOR 2 SURFACE APPROACH WHEN DIST TO
C     ONE SURFACE IS ZERO
      IF (J51(IS).EQ.0) THEN
        IF (S(IDS).NE.Z0) THEN
          CONTINUE
        ELSE
          DO 702 III=1,3
            CMOVE(III)=Z9EM1*TN(III,IPS)*S(IPS)
  702     CONTINUE
          GOTO 720
        ENDIF
      ENDIF
C
C...                COMPUTE MOVE VECTOR
C
     0CALL GAUSS(  TN(1,IPS),   S(IPS),
     1             TN(1,IDS),   S(IDS),
     2           PLNV(1,IS),PLND( IS),CMOVE,JPXR)
C
C....  DETERMINE MAXIMUM DIST TO SURFACES
C
      SIMAX=MAX(ABS(S(IPS)),ABS(S(IDS)),ABS(PLND(IS)))
C
      IF (JPXR.NE.0) THEN
C.... GAUSS FAILED - COMPUTE CMOVE BY ALTERNATIVE METHODS
        CALL ALTCMV(JPXR,TN,S,IPS,IDS,PLND(IS),PLNV(1,IS),EPS1(IS),
     +              CMOVE,LRET)
        JPXR=1
C.... IS TOOL IN TOLERANCE OD CS WHEN PS PARALLEL TO CS
        IF (LRET) GOTO 380
      ENDIF
C
C...                TEST FOR ITERATION 10, 5, OR 3 OF 3 SURF
C
  720 IF ( (JCNT1-18)*(JCNT1-9)*(JCNT1-3)+(JCNT1-22) ) 735,725,735
C
C...                IF SO, WIDEN TOLERANCE LIMIT AND HALVE MOVE
C
  725 EPS8(IPS)=1.709976*EPS8(IPS)
      EPS8(IDS)=1.709976*EPS8(IDS)
      EPS8(IS )=1.709976*EPS8(IS )
      PTOL     =1.709976*PTOL
      DO 730 I=1,3
      CMOVE(I)=.5*CMOVE(I)
  730 CONTINUE
C
C.... ENSURE CMOVE IS LESS THAN LARGEST ACTUAL DISTANCE TO SURFACES
      BCMOV=SQRT(CMOVE(1)*CMOVE(1)+CMOVE(2)*CMOVE(2)
     +          +CMOVE(3)*CMOVE(3))
      IF (BCMOV.GT.SIMAX) THEN
        DO 731 IK=1,3
          CMOVE(IK)=SIMAX/BCMOV*CMOVE(IK)
  731   CONTINUE
      ENDIF
C
C...                ADD MOVE TO TOOL END
C
C                                       FACTOR TO ENLARGE MOVE TO MINIM-
C                                       AL SIZE IF NECESSARY
  735 TEMP(1) = DMAX1(Z1,SMOVE/DMAX1(DABS(CMOVE(1)),
     1                         DABS (CMOVE(2)),
     2                         DABS (CMOVE(3)) ) )
C                                       ADD MOVE
      DO 740 I=1,3
      TE(I)=TE(I)+TEMP(1)*CMOVE(I)
  740 CONTINUE
C
C...                 STEP COUNTER, AND RETURN
C
      IF (JCNT1) 750,750,745
  745 JCNT1=JCNT1-1
C                                       RETURN
      GO TO JCMOVE ,(300,600,471)
C
C
C...                IF COUNTER EXHAUSTED, ISSUE WARNING
C
C                                       BRANCH TO ERROR
  750 GO TO 1600
C
C
C
C-----------------------------------------------------------------------
C     FIND PART DRIVE - DETERMINE NORMALS AND DISTANCES FOR PART
C                       AND DRIVE SURFACES
C
C
C                                       SAVE INDEX
  800 ISSTO=IS
C                                       CALL FOR PART SURFACE
      IS=IPS
      JMINR=1
      CALL AMIND
      IS=ISSTO
      IF(JMIN.EQ.1) GO TO 1600
C                                       CALL FOR DRIVE SURFACE
C
      IS=IDS
      JMINR=1
      CALL AMIND
      IS=ISSTO
      IF(JMIN.EQ. 1) GO TO 1600
C                                       RESTORE INDEX
C
C                                       RETURN
      GO TO JFPD,(1000,410,510,900,922)
C
C
C
C
C-----------------------------------------------------------------------
C     TEST PART DRIVE - SET JTOL +1 IF BOTH PART AND DRIVE SURFACE
C                       DISTANCES ARE ACCEPTABLE
C
C
C...                CALL TINKR FOR 5-AXIS CASE
C
  900 IF (MANTAX-2) 925,910,910
  910 IF (ITINK.LE.0) GOTO 925
      CALL TINKR
C                                       TEST IF TA MOVED
      IF (JTR)915,921,925
  915 JTRC=JTRC-1
      IF (JTRC) 920,925,925
C                                       ERROR IF COUNTER EXHAUSTED
 920  CALL AERR(25007,'CENTR   ')
C                                       IF SO,REESTABLISH
C                                       FIND PART AND DRIVE
  921 ASSIGN 922 TO JFPD
      GO TO 800
C                                       RE-ADJUST AXIS
  922 IF (ITINK.LE.0) GOTO 925
      CALL TINKR
C
C
C...                TEST PART AND DRIVE SURFACES
C
  925 DO  950  I=IPS,IDS,LSV
C                                       TEST WHETHER SURFACE A PLANE
      IF (IPL(I)) 930,930,935
C                                       NON-PLANAR
  930 IF (DABS(S(I))-EPS8(I)) 950,950,965
C                                       PLANE, TEST WHICH SIDE
  935 IF (S(I)) 940,950,945
  940 IF (S(I)-PTOL*TAU2(I)+1.E-6) 965,950,950
  945 IF (S(I)-PTOL*TAU1(I)-1.E-6) 950,950,965
  950 CONTINUE
C
C...                BOTH WITHIN TOLERANCE
C
  960 JTOL=1
      GO TO 970
C
C...                NOT BOTH WITHIN TOL
C
  965 JTOL=-1
C
C...                RETURN
C
  970 GO TO JTSTPD, (310,570,605)
C
C
C
C
C-----------------------------------------------------------------------
C     FIND CHECK - DETERMINE NORMAL AND DISTANCE TO CHECK SURFACE
C
C
C
C...                CALL AMIND FOR CHECK SURFACE
C
C                                       RETURN IF AMIND ERROR
 1000 JMINR=1
      CALL AMIND
C                                       RESET RETURN FLAG
      JMINR=0
C                                       BRANCH IF ERROR
      IF (JMIN) 1010,1010,1600
C                                       RETURN
 1010 GO TO JFNDCK, (1400,302,532)
C
C
C
C
C-----------------------------------------------------------------------
C     EXIT - RESET QUANTITIES AND RETURN
C
C
C...                IF 5-AXIS CASE, VERIFY TOOL AXIS SATISFACTORY
C
 1100 IF(2-MANTAX) 1102,1102,1108
C
 1102 IF (ITINK.EQ.0) THEN
        ITINK=1
        GOTO 105
      ELSE IF (ITINK.EQ.-1) THEN
        GOTO 1108
      ELSE
C                                       RESET AXIS IF NECESSARY
        CALL TINKR
      ENDIF
C                                       TEST WHETHER AXIS MOVED
      IF (JTR) 1103,1104,1108
C                                       TINKR ERROR
 1103 CALL AERR(25004,'CENTR   ')
C                                       AXIS MOVED, INDEX COUNTER
C                                       AND RESTART
 1104 IF(JCNT3) 1105,1106,1106
C                                       COUNTER EXHAUSTED
 1105 CALL AERR(25003,'CENTR   ')
C
 1106 JCNT3=JCNT3-1
      GO TO 100
C
C...                RESET   3-SURFACE FLAGS AND TOLERANCE BAND LIMITS
C
 1108 IF (J51(IS)) 1120,1120,1110
 1110 J50(IS)=0
      J51(IS)=0
      EPS8(IPS)=EPS1(IPS)
      EPS8(IDS)=EPS1(IDS)
      EPS8(IS)=EPS1(IS)
      NOTAN(IS)=0
C
C...                RETURN TO CALLING PROGRAM
C
 1120 CONTINUE
C... HAS TE CHANGED
      IF ( (TEZA(1).NE.TE(1)) .OR. (TEZA(2).NE.TE(2)) .OR.
     +     (TEZA(3).NE.TE(3)) ) THEN
        JTENEU=1
      ELSE
        JTENEU=0
      ENDIF
      RETURN
C
C
C
C
C-----------------------------------------------------------------------
C     TEST CHECK SURFACE
C
C
C
C                                       BRANCH IF SURF A PLANE
 1300 IF (IPL(IS)) 1310,1310,1330
C                                       TEST FOR INNER OR OUTER SIDE
 1310 IF (DFLOAT(2*JTN(IS)-1)*RC(IS)*S(IS)) 1315,1350,1320
C                                       INNER SIDE
 1315 IF (DABS(S(IS))-EPS8(IS)-5.D-6) 1350,1350,1360
C                                       OUTER SIDE
 1320 IF (DABS(S(IS))-(TAU(IS)-EPS8(IS)+Z5EM6)) 1350,1350,1360
C                                       PLANE SURFACE
C                                       TEST INNER OR OUTER
 1330 IF (S(IS)) 1340,1340,1335
C                                       INNER
 1335 IF (S(IS)-ACC-TAU1(IS)) 1350,1350,1360
C                                       OUTER
 1340 IF (S(IS)+ACC-TAU2(IS)) 1360,1350,1350
C
C...                WITHIN TOLERANCE BAND
C
 1350 JTOL=1
      GO TO 1370
C
C...                NOT WITHIN TOLERANCE BAND
C
 1360 JTOL=-1
C                                       RETURN
 1370 GO TO JTSTCK, (320,482,550)
C
C
C
C
C-----------------------------------------------------------------------
C     CPLAN SURF - OBTAIN PSEUDO CHECK SURFACE DATA FROM CPLAN
C                  ROUTINE
C
C
C
C
 1400 CALL CPLAN
      IT=IT
C
C...                BRANCH IF CPLAN FAILURE
C
      IF (JCPR) 1420,1410,1420
C
C...                RETURN
C
 1410 GO TO JCPLAN, (420,520)
C
C...                CPLAN ERROR
C
 1420 CALL AERR(25005,'CENTR   ')
C
C
C
C
C-----------------------------------------------------------------------
C     ERROR -                REDUCE STEPSIZE IF POSSIBLE, AND SET
C                            FLAG FOR RESTART
C
C
C
C                                       BRANCH IF 3 SURFACE CALL
 1600 IF (J51(IS)) 1610,1610,1630
C                                       REDUCE STEPSIZE
 1610 DP=.6*DP
C                                       ERROR IF STEPSIZE .LT. TOLERANCE
      IF (DP-DABS(TAU(IS))) 1620,1620,1630
C                                       ERROR ROUTINE
 1620 CALL AERR(25002,'CENTR   ')
C                                       SET FLAG FOR RESTART
 1630 JCR=-1
C                                       BRANCH TO EXIT
      GO TO 1100
C
C
C
C
C
       END
