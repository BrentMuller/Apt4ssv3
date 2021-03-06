**** SOURCE FILE : AVCTRL.ORG   ***
*
      SUBROUTINE AVCTRL(DONOFF,DAVTP1,G,BMN,BMX,DAVTP2,DMX)
C
C     PURPOSE: TO PROCESS THE AVCTRL STATEMENT
C              SET FLAGS AND STORE PARAMETERS
C
C     ARGUMENTS:
C               DONOFF   D.P.   ON OR OFF
C                               INVOKES OR CANCELS AVOIDANCE CONTROL
C               DAVTP1   D.P.   TYPE1 AVOIDANCE CONTROL
C                               (MODIFICATION OF TOOL AXIS)
C                                 CUTANG - MODIFY PITCH ANGLE
C                                 NULL   - NO MODIFICATION OF TOOL AXIS
C               G        D.P.   CONSTANT TECHNOLOGICAL ANGLE (DEGREES)
C               BMN      D.P.   MINIMUM PITCH ANGLE (DEGREES)
C               BMX      D.P.   MAXIMUM PITCH ANGLE (DEGREES)
C               DAVTP2   D.P.   TYPE2 AVOIDANCE CONTROL (LIFT OFF)
C                                 NORMPS - LIFT OFF NORMAL TO PS
C                                 AXIS   - LIFT OFF PARLLEL TO TOOL AXIS
C                                 NULL   - NONE SPECIFIED (AXIS ASSUMED)
C               DMX      D.P.   MAXIMUM LIFT OFF DISTANCE
C
C     LOCAL VARIABLES:
C
C               ONOFF    C*6    CHARACTER VERSION OF DONOFF
C               AVTYP1   C*6        "        "    "  DAVTP1
C               AVTYP2   C*6        "        "    "  DAVTP2
C               NWD      I      NO OF INTEGER WORDS OCCUPIED BY
C                               ENCODED CHARACTER STRING
C               MSG      C*30   DEBUG PRINT MESSAGE
C
      DOUBLE PRECISION DONOFF,DAVTP1,DAVTP2,G,BMN,BMX,DMX
      CHARACTER*6       ONOFF,AVTYP1,AVTYP2
      INTEGER NWD
      CHARACTER*30 MSG
C
      INCLUDE 'RMFLGS.INC'
      INCLUDE 'AVCPRM.INC'
      INCLUDE 'ZNUMBR.INC'
      INCLUDE 'FXCOR.INC'
      INCLUDE 'IBUGG.INC'
C
      CALL HOLFRM(DONOFF,ONOFF,1,6,NWD)
      CALL HOLFRM(DAVTP1,AVTYP1,1,6,NWD)
      CALL HOLFRM(DAVTP2,AVTYP2,1,6,NWD)
C
C.... SET AVOIDANCE CONTROL FLAG
C
      IF (ONOFF.EQ.'ON') THEN
        LAVCTL=.TRUE.
      ELSE
        LAVCTL=.FALSE.
      ENDIF
C
C.... STORE PARAMETERS
C
      IF (AVTYP1.EQ.'NULL'.AND.AVTYP2.EQ.'NULL') THEN
C
C.... DO NOT ALTER PARAMETERS SINCE AVCTRL/ON OR AVCTRL/OFF
C
        CONTINUE
      ELSE
C
C.... TYPE 1 AVOIDANCE CONTROL
C
        IF (AVTYP1.EQ.'CUTANG') THEN
          LATYP1=.TRUE.
C.... CONVERT ANGLES TO RADIANS BEFORE STORING
          CTANG=G*DEGRAD
          BMIN=BMN*DEGRAD
          BMAX=BMX*DEGRAD
        ELSE
          LATYP1=.FALSE.
          CTANG=Z0
          BMIN=Z0
          BMAX=Z0
        ENDIF
C
C.... TYPE 2 AVOIDANCE CONTROL
C
        IF (AVTYP2.EQ.'NORMPS') THEN
          LANPS=.TRUE.
        ELSE
          LANPS=.FALSE.
        ENDIF
C
C.... LIFT OFF LIMIT
C
        IF (ABS(DMX-Z0).LT.Z1EM6) THEN
C.... NO LIMIT SPECIFIED - TAKE DPMAX AS DEFAULT
          DMAX=DPMAX
        ELSE
          DMAX=DMX
        ENDIF
      ENDIF
C
C.... DEBUG PRINT
C
      IF (IBUG.EQ.11) THEN
        CALL BAD(-1,0,' ',0)
        MSG='0 AVOIDANCE CONTROL PARAMETERS'
        CALL CPRINT(MSG)
        CALL BAD(1,1,'CANG',CTANG)
        CALL BAD(1,1,'BMIN',BMIN)
        CALL BAD(1,1,'BMAX',BMAX)
        CALL BAD(-1,1,'DMAX',DMAX)
        CALL BAD(1,0,'LTYP',LATYP1)
        CALL BAD(1,0,'LNPS',LANPS)
        CALL BAD(-1,0,'ALST',AVLIST)
      ENDIF
C
      END
