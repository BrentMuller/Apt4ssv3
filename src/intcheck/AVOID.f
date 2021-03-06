**** SOURCE FILE : AVOID.V01   ***
*
      SUBROUTINE AVOID(PSURF,IPSIZE,PSIDE,PTHICK,PTOLI,PTOLO,TOLCOM,FWD,
     +                 TUL,TE,TA,R,NPAT,UP,VP,INTLOC,LRET)
C
C     PURPOSE:   TO CARRY OUT AVOIDANCE STRATEGIES WHEN INTERFERENCE
C                HAS BEEN DETECTED
C
C     ARGUMENTS:
C
C     PSURF   -  CANONICAL FORM OF PART SURFACE
C     IPSIZE  -  SIZE OF PS CANONICAL FORM
C     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV)
C     PTHICK  -  THICKNESS OFFSET FROM SURFACE
C     PTOLI, PTOLO - PS TOLERANCE
C     TOLCOM  -  TOLERANCE BAND COMPENSATION
C     FWD     -  DS FORWARD DIRECTION
C     TUL     -  TOOL GEOMETRY
C     TE      -  TOOL END COORDINATES
C     TA      -  TOOL AXIS VECTOR
C     R       -  SURFACE CONTACT POINT AND DERIVATIVES
C     NPAT    -  PATCH NUMBER FOR CONTACT POINT
C     UP,VP   -  U,V PARAMETERS OF CONTACT POINT
C     INTLOC  -  LOCATION INTERFERENCE TABLE OF WORST PENETRATION
C     LRET    -  RETURN FLAG
C                .TRUE.  IF INTERFERENCE AVOIDED
C                .FALSE. IF THERE IS STILL INTERFERENCE
C
      DOUBLE PRECISION PSURF,PTHICK,PTOLI,PTOLO,FWD,TUL,TE,TA,R,UP,VP
      DOUBLE PRECISION PSIDE
      INTEGER IPSIZE,NPAT,INTLOC
      LOGICAL LRET
C
      DIMENSION PSURF(IPSIZE),FWD(3),TUL(7),TE(3),TA(3),R(32)
C
C     GLOBAL VARIABLES
C
      INCLUDE 'AVCPRM.INC'
      INCLUDE 'INTERF.INC'
      INCLUDE 'ZNUMBR.INC'
C
C     LOCAL VARIABLES
C
C     B      - COMPUTED TILT ANGLE TO CLEAR INTERFERENCE
C     UL     - LOCAL AXIS IN FWD DIRECTION PERPTO TA
C     S      - SIGN OF TILT ANGLE  (+VE IN FWD DIRECTION)
C     TCCENT - CENTRE OF TOOL CONTACT SPHERE
C     TCRAD  - RADIUS OF TOOL CONTACT SPHERE
C     CX     - PRINCIPLE CURVATURES, DIRECTIONS AND COEFFICIENTS
C     RCMIN  - MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT
C     NPS    - PART SURFACE NORMAL AT POINT OF CONTACT
C     VL     - LIFT OFF DIRECTION
C     D1,TEMP- LOCAL WORK VARIABLES
C     D      - LIFT OFF DISTANCE
C     E      - CURVATURE COMPENSATION
C     MSG    - PRINT BUFFER
C     MSG1,MSG2 - MESSAGES
C     IPOS   - LOCATION IN PRINT BUFFER
C     IRET   - INTCHK RETURN FLAG - .TRUE. IF INTERFERENCE DETECTED
C     JRET   - CALMXB RETURN FLAG - .TRUE. IF BETA CALC. OK
C     BDEG   - B IN DEGREES
C     TYPE   - TYPE OF TILT (ROLL OR PITCH)
C     OLDTE  - ORIGINAL TE
C     OLDTA  - ORIGINAL TA
C     MAXK   - MAXIMUM CURVATURE
C
      DOUBLE PRECISION B,UL,S,TCCENT,TCRAD,CX,RCMIN,NPS,V,VL,D1,D,E,TEMP
      DOUBLE PRECISION BDEG,OLDTE,OLDTA,MAXK
      DIMENSION UL(3),TCCENT(3),CX(24),NPS(3),VL(3),OLDTE(3),OLDTA(3)
      CHARACTER*5 TYPE
      CHARACTER*120 MSG,MSG1*52,MSG2*64
      INTEGER IPOS
      LOGICAL IRET,JRET
C
      DATA MSG1/'UNABLE TO AVOID INTERFERENCE WITH CURRENT PARAMETERS'/
      DATA MSG2/
     +'INTERFERENCE DIRECTION PERPENDICULAR TO SELECTED LIFT OFF VECTOR'
     +/
C
      LRET=.FALSE.
      B=Z0
      D=Z0
      MSG=' '
C
C.... DETERMINE SURFACE NORMAL POINTING TOWARDS TOOL AT CONTACT POINT
C
      CALL VSCALE(PSIDE,R(29),NPS)
C
C.... COMPUTE PRINCIPLE CURVATURES OF SURFACE AT POINT OF CONTACT
C
      CALL KURSRF(R,PSIDE,CX)
C
C.... DETERMINE MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT
C
      MAXK=MAX(CX(1),CX(2))
      IF (ABS(MAXK).GT.Z1EM6) THEN
        RCMIN=Z1/MAXK
      ELSE
        RCMIN=Z1E6
      ENDIF
C
      IF (LATYP1) THEN
C
C.... FIRST TRY AVOIDING INTERFERENCE BY TILTING TOOL
C     IN THE MOST APPROPRIATE DIRECTION INDICATED BY TYPE AND UL
C
        CALL CALCB(TA,FWD,R,INTLOC,B,TYPE,UL)
C
C.... ADD CONSTANT TECHNOLOGICAL ANGLE (TO CLEAR SURFACE)
C
        S=SIGN(Z1,B)
        B=B+S*CTANG
C
C.... IS B WITHIN PERMITTED RANGE
C
        IF (B.LT.BMIN) THEN
          B=BMIN
        ELSE IF (B.GT.BMAX) THEN
          B=BMAX
        ENDIF
C
C.... COMPUTE NEW TA TILTED THROUGH B IN UL DIRECTION
C     SAVE OLD TE AND TA
C
        DO 10 I=1,3
          OLDTE(I)=TE(I)
          OLDTA(I)=TA(I)
          TA(I)=COS(B)*TA(I)+SIN(B)*UL(I)
   10   CONTINUE
C
C.... COMPUTE NEW TE
C
        CALL TECALC(R,TA,FWD,PSIDE,PTHICK,TOLCOM,TUL,TE)
C
C.... COMPUTE CENTRE AND RADIUS OF TOOL CONTACT SPHERE
C
        CALL TCSPHR(TE,TA,TUL,R,PSIDE,PTHICK,TCCENT,TCRAD)
C
C.... IS THERE LOCAL INTERFERENCE
C
        IF (TCRAD.GT.RCMIN) THEN
C.... YES
          IF ( (ABS(TCRAD-TUL(1)).GT.Z1EM6).AND.
     +         ((TUL(1)+TUL(3)).LT.RCMIN) ) THEN
C.... COMPUTE MAXIMUM TILT ANGLE TO FIT SURFACE
            CALL CALMXB(RCMIN,TUL,OLDTA,UL,NPS,B,JRET)
C.... HAS ANGLE BEEN COMPUTED SATISFACTORILY
C     AND IS ANGLE WITHIN PERMITTED RANGE
            IF ( JRET.AND.(B.GE.BMIN).AND.(B.LE.BMAX) ) THEN
C
C.... YES - COMPUTE NEW TA TILTED THROUGH B IN FWD (UL) DIRECTION
C
              DO 20 I=1,3
                TA(I)=COS(B)*OLDTA(I)+SIN(B)*UL(I)
   20         CONTINUE
C
C.... COMPUTE NEW TE
C
              CALL TECALC(R,TA,PSIDE,PTHICK,PTOLI,PTOLO,TUL,TE)
C
            ELSE
C
C.... NO - LIFTOFF
C
              B=Z0
C
              IF (AVLIST) THEN
                CALL CFORM('UNABLE TO FIND TOOL AXIS ORIENTATION',
     +                      MSG,2,36)
                CALL CFORM('WITHIN SELECTED RANGE',MSG,39,21)
                CALL CPRINT(MSG)
                CALL CFORM('WHERE TOOL CAN BE POSITIONED IN',MSG,2,31)
                CALL CFORM('NON-INTERFERING CONTACT WITH SURFACE',
     +                      MSG,36,36)
                CALL CPRINT(MSG)
                CALL BAD(3,1,'R   ',R(1))
                CALL BAD(1,0,'NPAT',NPAT)
                CALL BAD(1,1,'U   ',UP)
                CALL BAD(-1,1,'V   ',VP)
              ENDIF
C
C.... RESTORE OLD TE AND TA
C
              DO 25 I=1,3
                TE(I)=OLDTE(I)
                TA(I)=OLDTA(I)
   25         CONTINUE
C
              GOTO 100
            ENDIF
          ELSE
C
C.... RADIUS OF TOOL CONTACT SPHERE = TOOL CORNER RADIUS - LIFT OFF
C
            B=Z0
            IF (AVLIST) THEN
               MSG='TOOL RADIUS GT RADIUS OF CURVATURE AT'
              CALL CPRINT(MSG)
              CALL BAD(3,1,'R   ',R(1))
              CALL BAD(1,0,'NPAT',NPAT)
              CALL BAD(1,1,'U   ',UP)
              CALL BAD(-1,1,'V   ',VP)
            ENDIF
C
C.... RESTORE OLD TE AND TA
C
            DO 26 I=1,3
              TE(I)=OLDTE(I)
              TA(I)=OLDTA(I)
   26       CONTINUE
C
            GOTO 100
          ENDIF
        ENDIF
C
C.... CHECK NEW POSTION (TE,TA) FOR INTERFERENCE
C
C.... SAVE ORIGINAL INTERFERENCE DATA TO USE FOR START POINTS
C
        CALL RESET
        CALL INTCHK(PSURF,IPSIZE,PSIDE,PTHICK,PTOLI,TUL,
     +              TE,TA,R,NPAT,UP,VP,IRET,INTLOC)
C
        IF (.NOT.IRET) THEN
C.... AVOIDANCE SUCCESSFUL - RESTORE ORIGINAL INTERFERENCE DATA
          CALL RESTOR
          IF (AVLIST) CALL AVMSG(TE,TA,LANPS,B,TYPE,Z0)
          LRET=.TRUE.
          GOTO 999
        ENDIF
      ENDIF
C
C.... IF TILTING UNSUCCESSFUL OR LIFT OFF ONLY SELECTED
C
C.... TRY AVOIDING INTERFERENCE BY LIFTING THE TOOL OFF THE SURFACE
C     IN THE SPECIFIED DIRECTION
C
  100 CONTINUE
C
C.... COMPUTE LIFT OFF DISTANCE
C
C     VL - LIFT OFF DIRECTION
C
      DO 30 I=1,3
        IF (LANPS) THEN
          VL(I)=NPS(I)
        ELSE
          VL(I)=TA(I)
        ENDIF
   30 CONTINUE
C
      CALL VNORM(VL,VL)
C
      CALL DOTV(D1,SNINTR(1,INTLOC),VL)
      IF (ABS(D1).LT.Z1EM6) THEN
        IF (AVLIST) THEN
          CALL OUTMSG(MSG1)
          CALL OUTMSG(MSG2)
        ENDIF
      ELSE
C
C.... LIFT OFF IN DIRECTION VL
C
        D=DINTR(INTLOC)/D1
C
C.... COMPUTE CURVATURE COMPENSATION FOR CONCAVE SURFACE
C
        IF (RCMIN.GT.Z0) THEN
          TEMP=RCMIN*RCMIN - DINTR(I)*DINTR(I) + D*D
          IF (TEMP.GT.Z0) THEN
            E=SQRT(TEMP)-RCMIN
          ELSE
            E=Z0
          ENDIF
        ELSE
          E=Z0
        ENDIF
C
C.... LIFT OFF - COMPENSATED FOR CURVATURE, AND INCREASED BY OUTTOL
C
        D = D + E + PTOLO
C
        IF (ABS(D).LE.DMAX) THEN
C
C.... LIFTOFF WITHIN SPECIFIED LIMIT - COMPUTE NEW TE (TA UNCHANGED)
C
          DO 40 I=1,3
            TE(I)=TE(I)+D*VL(I)
   40     CONTINUE
C
          IF (LANPS) THEN
C.... IF LIFT OFF NORMAL TO PS CHECK FOR INTERFERENCE
            CALL RESET
            CALL INTCHK(PSURF,IPSIZE,PSIDE,PTHICK,PTOLI,TUL,
     +                  TE,TA,R,NPAT,UP,VP,IRET,INTLOC)
            IF (IRET) THEN
C... STILL INTERFERENCE
              IF (AVLIST) THEN
                CALL OUTMSG(MSG1)
                CALL INTMSG(TE,TA,INTLOC)
                CALL CFORM('ACTION ATTEMPTED -',MSG,1,18)
                IPOS=21
                IF (ABS(B-Z0).GT.Z1EM6) THEN
                  CALL CFORM(TYPE,MSG,IPOS,5)
                  IPOS=IPOS+6
                  CALL CFORM('THROUGH',MSG,IPOS,7)
                  IPOS=IPOS+8
                  BDEG=B/DEGRAD
                  CALL FCONV(BDEG,MSG,IPOS,6,2)
                  IPOS=IPOS+7
                  CALL CFORM('DEGREES AND',MSG,IPOS,11)
                  IPOS=IPOS+12
                ENDIF
                CALL CFORM('LIFTED OFF BY',MSG,IPOS,13)
                IPOS=IPOS+14
                CALL FCONV(D,MSG,IPOS,10,4)
                IPOS=IPOS+11
                CALL CFORM('NORMAL TO PS',MSG,IPOS,12)
                CALL CPRINT(MSG)
              ENDIF
              GOTO 999
            ENDIF
C
C.... RESTORE INTEFERENCE DATA FOR USE AS NEXT START VALUES
C
            CALL RESTOR
          ENDIF
C
C.... AVOIDANCE SUCCESSFUL
C
          IF (AVLIST) CALL AVMSG(TE,TA,LANPS,B,TYPE,D)
          LRET=.TRUE.
C
        ELSE
C
C.... COMPUTED LIFT OFF GREATER THAN LIMIT
C
          IF (AVLIST) THEN
            CALL OUTMSG(MSG1)
            CALL CFORM('LIFT OFF',MSG,2,8)
            CALL FCONV(D,MSG,11,10,4)
            IF (LANPS) THEN
              CALL CFORM('NORMAL TO PS',MSG,22,12)
            ELSE
              CALL CFORM('PARALLEL TO TA',MSG,22,14)
            ENDIF
            CALL CPRINT(MSG)
          ENDIF
C
        ENDIF
C
      ENDIF
C
  999 CONTINUE
C
      END
