**** SOURCE FILE : M0006687.W03   ***
*
C
C              FORTRAN SUBROUTINE SSDEF
C
C LINKAGE      SUBROUTINE SSDEF(ACTNO,BIGCNT)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    RECOG
C          SUBROUTINE    CALLZZ
C          LOGICAL FCT.  IFTMP
C          INTEGER FCT.  NUMB
C          SUBROUTINE    ONEARG
C          SUBROUTINE    OPCODE
C          SUBROUTINE    ARGCVT
C          SUBROUTINE    PUTTMP
C          SUBROUTINE    CONCAT
C          SUBROUTINE    RESRVZ
C          SUBROUTINE    RLSLIN
C          INTEGER FCT.  GETTMP
C          SUBROUTINE    TWOARG
C          SUBROUTINE    BINBCD
C
      SUBROUTINE SSDEF(ACTNO,BIGCNT)
C
      IMPLICIT INTEGER (A-Z)
C
C              FUNCTION DECLARATION
C
      LOGICAL IFTMP
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C NAMMAX:      NAMTBL INDEX OF THE PART PROGRAM NAME SECTION
C
C        2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST
      DIMENSION STKLST(300),STACK(2,99)
C TOP:         POINTER TO LAST STACK ENTRY
      EQUIVALENCE (TOP,STKLST(1))
C STACK:       WORKING STACK
      EQUIVALENCE (STACK(1,1),STKLST(4))
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),NUMBER(2),TEMP(2),PERMID(2),VBL(2),IDENT(2),
     *          COMMA(2)
C COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF 'COMMA '
      EQUIVALENCE (COMMA(1),CODE(1))
C NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER'
      EQUIVALENCE (NUMBER(1),CODE(27))
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C PERMID:      (1)=CODE CLASS 20000,(2)=NAMTBL INDEX OF 'PERMID'
      EQUIVALENCE (PERMID(1),CODE(39))
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT '
      EQUIVALENCE (IDENT(1),CODE(69))
C        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE
      COMMON/TMP/TXXXX
      DIMENSION TXXXX(2,32)
C
C        4.    PRODUCTION TABLE
C
      COMMON/SRCTBL/SRCTBL
      DIMENSION SRCTBL(502),META(50)
C META:        CONTAINS INTERNAL BIT CODES FOR METALINGUISTIC CLASSES
      EQUIVALENCE (META(1),SRCTBL(3))
C
C        8.    NAME TABLE POINTERS TO BCD LITERALS
C
      COMMON/BCDPTR/BCDPTR
      DIMENSION BCDPTR(7)
C DOTTAB:      NAMTBL POINTER TO ALPHAMERIC LITERAL '$$TAB'
      EQUIVALENCE (DOTTAB,BCDPTR(7))
C
C        9.    NAME TABLE POINTERS TO NUMBERS
C
      COMMON/NUMPTR/NUMPTR
      DIMENSION NUMPTR(12)
C ZEROPT:      NAMTBL POINTER TO '0.    '
      EQUIVALENCE (ZEROPT,NUMPTR( 2))
C ONE:PT:      NAMTBL POINTER TO '1     '
      EQUIVALENCE (ONE,NUMPTR( 3))
C TWO:         NAMTBL POINTER TO '2     '
      EQUIVALENCE (TWO,NUMPTR( 5))
C FOUR:        NAMTBL POINTER TO '4     '
      EQUIVALENCE (FOUR,NUMPTR(7))
C
C       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR
C
      INCLUDE 'GMTY.INC'
C GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB
C PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB
C GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE
C
C       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS
C
      COMMON/CFSIZE/CFSIZE
      DIMENSION CFSIZE(1106),MAXSIZ(2),KSC(3,300)
C MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY
      EQUIVALENCE (MAXSIZ(1),CFSIZE(4))
C ISC:         POINTER TO LAST KSC ENTRY
      EQUIVALENCE (ISC,CFSIZE(206))
C KSC:         CONTAINS SYMBOL,SIZE AND NUMBER OF SEQMENTS OF SS-DEFIN.
      EQUIVALENCE (KSC(1,1),CFSIZE(207))
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C REPL:        CONTAINS COMMAND CODE (17) FOR REPL COMMAND
      EQUIVALENCE (REPL,IL(17))
C MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND
      EQUIVALENCE (MOVE,IL(19))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C MATRIX:      MODE CODE (18) FOR MATRIX
      EQUIVALENCE (MATRIX,MODX(18))
C POINT:       MODE CODE (19) FOR POINT
      EQUIVALENCE (POINT,MODX(19))
C VECTOR:      MODE CODE (20) FOR VECTOR
      EQUIVALENCE (VECTOR,MODX(20))
C REAL:        MODE CODE (21) FOR A SCALAR
      EQUIVALENCE (REAL,MODX(21))
C SSURF:       MODE CODE (29) FOR SCULPTURED SURFACE
      EQUIVALENCE (SSURF,MODX(29))
C SCURV:       MODE CODE (30) FOR SCULPTURED CURVE
      EQUIVALENCE (SCURV,MODX(30))
C
C       22.    MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      DIMENSION MACXX1(71)
C INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING
      EQUIVALENCE (INTMED,MACXX1(22))
C
C       27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION OPMOD(6)
C NOUGHT:      CONTAINS OPERAND TYPE 0
      EQUIVALENCE (NOUGHT,OPMOD(1))
C DLR:         CONTAINS OPERAND TYPE CODE 1
      EQUIVALENCE (DLR,OPMOD(2))
C
C       28.    OPERAND MODIFIERS
C
      COMMON/SUBLST/SUBLST
      DIMENSION SUBLST(135),APTXXX(120)
C APTXXX:      NAMTBL POINTERS FOR XECUTION SUBROUTINE NAMES
      EQUIVALENCE (APTXXX(1),SUBLST(1))
C
C       29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULI
      DIMENSION MODULI(2)
C MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS
      EQUIVALENCE (MODULO,MODULI(1))
C MODHLF:      NORMAL MODE CODE LIMIT 500
      EQUIVALENCE (MODHLF,MODULI(2))
C
C       44.    ERROR POSITION TABLE
C
      COMMON/ERRPOS/ERRPOS
      INTEGER ESTACK,ERRPOS
      DIMENSION ERRPOS(302),ESTACK(100)
C ESTACK:      INPUT STATEMENT ERROR POSITION WHEN DETECTED IN STACK
      EQUIVALENCE (ESTACK(1),ERRPOS(103))
C*
C       TYPE   MODE  SIZE
C       ****************************************************************
C SCURV/CURSEG 140  NPS=2  SEGMS=0                    *
C       SPLINE  30  NOWRDS=24*(NPS+1)                 * =72
C                   NPS=2  SEGMS.GT.0                 *
C       SEG    150  NOWRDS=54*(NPS+1)-18+6*SEGMS      * =144+6*SEGMS
C                           I=N
C       COMBIN 141   NOWRDS=SUMME(NOWRDS(SS )-24) + 24
C                           I=1            I
C       ****************************************************************
C SSURF/SMESH,XYZ,...132   KN=59   NOWRDS=10+KN*(SPL-1)*(NPS-1)
C       GMESH,XYZ,...125   KN=59
C       SMESH,XYPLAN,132   KN=35
C       COMBIN,......141                  I=N
C       RULED,.......143           NOWRDS=SUMME(NOWRDS(SS )-10) + 10
C       TRANSL,......133                  I=1            I
C       SCALE,....... 36
C       XYROT,....... 34
C       REVOLV,......142           NOWRDS=74+222*NOWRDS/24
C       GENCUR,......148           NOWRDS=NOWRDS+10
C       PATCH,PNTSON,131
C       PATCH,PNTVEC,131           NOWRDS=8+65*NPATCH
C       PATCH,POLYGN,131
C       ****************************************************************
      LOGICAL FOULUP,CRSFLG,MINDEF,WTFLAG,NOMTRX
      DIMENSION ITMP(2,3)
      CHARACTER IBUFF*15,IBLANK
      DIMENSION STK(2,30),SAVE(2,27),SPLARY(16)
      DIMENSION TCURV(4),TSURF(11)
C
      EQUIVALENCE(STK(1, 1),    TP),(STK(1, 2),NOMTRX)
      EQUIVALENCE(STK(1, 3),FOULUP),(STK(1, 4),MINDEF)
      EQUIVALENCE(STK(1, 5),CRSFLG),(STK(1, 6),WTFLAG)
      EQUIVALENCE(STK(1, 7), INDEX),(STK(1, 8),  MOUT)
      EQUIVALENCE(STK(1, 9),NOWRDS),(STK(1,10), MMODE)
      EQUIVALENCE(STK(1,11),   SPM),(STK(1,12),   PTM)
      EQUIVALENCE(STK(1,13),   PNT),(STK(1,14),   SPL)
      EQUIVALENCE(STK(1,15),   PMS),(STK(1,16), COUNT)
      EQUIVALENCE(STK(1,17),   CNT),(STK(1,18),   JMP)
      EQUIVALENCE(STK(1,19),   NPS),(STK(1,20),    KN)
      EQUIVALENCE(STK(1,21),  MTOP),(STK(1,22),ITMP(1,1))
      external alarm
C
C...  LOCAL VARIABLES WHICH MUST BE SAVED UNTIL THIS SSURF DEF IS
C      COMPLETELY TRANSLATED.
C
      DATA IBLANK/' '/,JSAVE/0/
C                CURSEG SPLINE COMBIN SEG
      DATA TCURV/   190,    80,   191,   200/
C                PATCH  SMESH  COMBIN GENCUR REVOLV RULED
      DATA TSURF/   181,   182,   191,   198,   192,   193,
C                TRANSL SCALE  XYROT  YZROT  ZXROT
     *               83,    86,    84,    87,    98/
C**
      IRET=1
      IND=1
      IF(BIGCNT.NE.1)GOTO 10
C
      TP=2
    1 MTOP=TOP
      ISS=MOD(NAMTBL(STACK(1,TOP-5)),MODHLF)
      FOULUP=.FALSE.
      MINDEF=.FALSE.
      CRSFLG=.FALSE.
      WTFLAG=.FALSE.
      NOMTRX =.FALSE.
      INDEX=-9
      NOWRDS=0
      NPS=0
      SPM=31
      PTM=31
      PMS=31
      PNT=1
      SEGMS=0
      SPL=0
      COUNT=0
      CNT=0
      SPLARY(1)=0
      DO 5 I=1,3
      ITMP(1,I)=1
    5 ITMP(2,I)=REAL
      STK(2,1)=-1
      KN=35
      JMP=5
      MOUT=1
      FLOWS=-1
      NPATCH=0
      L=STACK(1,TOP-3)
      M=STACK(1,TOP-1)
      ERRPT=TOP-3
      GOTO 200
C
C         STORE INTERNAL BIT REPRESENTATION IN STK
C
   10 IF(ACTNO.GT.102)GOTO 500
      IF(FOULUP)GOTO 140
      IF(TOP.GT.MTOP)GOTO 900
   20 L=STACK(1,TOP-1)
      ERRPT=TOP-1
      IF(L.GT.NAMMAX)GOTO 50
      CLASS=MODULO*(NAMTBL(L)/MODULO)
      MODE=NAMTBL(L)-CLASS
      IF(MODE.GT.MODHLF)MODE=MODE-MODHLF
      IF(CLASS.NE.IDENT(1))GOTO 40
      CLASS=PERMID(1)
      NAMTBL(L)=NAMTBL(L)-IDENT(1)+PERMID(1)
   40 IF(CLASS.EQ.PERMID(1))MODE=MODE+50
      IF(CLASS.EQ.VBL(1).OR.CLASS.EQ.PERMID(1).OR.CLASS.EQ.TEMP(1))
     *                                                      GOTO 60
      IF(CLASS.NE.NUMBER(1))GOTO 80
   50 MODE=REAL
      CLASS=NUMBER(1)
   60 IF(WTFLAG)GOTO 1000
      TP=TP+1
      ERROR=1227
      IF(TP.GT.30)GOTO 100
      STK(2,TP)=PMIDTB(MODE)
      GEOPOS=GEOLOC(ISS)
      TPT2=TP*2
      PROD=SEARCH(STK,TPT2,GEOMTB(GEOPOS),ERRPT)
C
      GOTO(1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,
     1     2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,
     2     3100,3200,3300,3400,3500,3600,3700),PROD
C
C                ERROR OUTPUT
C
   80 ERRPT=TOP-1
   90 ERROR=1007
      IF(CLASS.EQ.PERMID(1))GOTO 100
      J=MOD(MODE-9,10)
      IF(MODE.LT.19.OR.J.GT.2)GOTO 100
      ERROR=1203+MODE
  100 FOULUP=.TRUE.
      MINDEF=.TRUE.
  110 TP=TP-1
      CALL ALARM(ERROR,ERRPT,8,'SSDEF   ')
  140 STACK(1,TOP-2)=STACK(1,TOP)
      STACK(2,TOP-2)=STACK(2,TOP)
      ESTACK( TOP-2)=ESTACK( TOP)
      TOP=TOP-2
  150 RETURN
C
C                I.L.  OUTPUT
C
C           SPECIAL CONTROL AND OUTPUT OF THE SUBTYPE
C
  200 ASSIGN 1110 TO TSEG
      MODE=MOD(NAMTBL(L),MODHLF)
      CLASS=NAMTBL(L)-MODE
      IF(CLASS.NE.IDENT(1))GOTO 201
      CLASS=PERMID(1)
      NAMTBL(L)=NAMTBL(L)-IDENT(1)+PERMID(1)
  201 IF(CLASS.NE.PERMID(1))GOTO 202
      ITMP(1,1)=L
      MODE=MODE+50
  202 MMODE=MODE
      STK(2,TP)=PMIDTB(MMODE)
      HMODE=MOD(NAMTBL(M),MODHLF)
      TYP=NAMTBL(M)-HMODE
      IF(TYP.NE.PERMID(1).AND.TYP.NE.IDENT(1))GOTO 204
      HMODE=HMODE+50
      IF(HMODE.NE.188.AND.HMODE.NE.189)ITMP(1,3)=M
  204 IF(ISS.EQ.29)GOTO 215
C
      DO 210 TYP=1,4
      IF(TCURV(TYP).EQ.MMODE)GOTO 225
  210 CONTINUE
      GOTO 90
C
  215 DO 216 TYP=1,11
      IF(TSURF(TYP).EQ.MMODE)GOTO 217
  216 CONTINUE
      GOTO 90
  217 TYP=TYP+4
C
  225 IRET=2
      TOP=TOP-2
      GOTO(230,232,234,236,
     *     244,270,246,270,320,248,320,320,320,320,320),TYP
C            CURSEG
  230 NPS=1
      PTM=6
C            SPLINE
  232 SPL=1
      NPS=NPS+1
      JMP=6
      GOTO 320
C            COMBIN
  234 NPS=1
      JMP=7
      GOTO 270
C            SEG
  236 SPL=1
      NPS=2
      PNT=2
      JMP=6
      ASSIGN 1910 TO TSEG
      GOTO 270
C            PATCH
  244 MOUT=2
      JMP=2
      GOTO 270
C            SSURF/COMBIN
  246 JMP=3
      GOTO 270
C            SSURF/RULED
  248 SPL=1
      GOTO 320
C
  270 IRET=1
      TOP=TOP+2
      GOTO 20
C
  280 JJ=ISS-28
      IF(CLASS.EQ.TEMP(1))GOTO 290
      DO 285 JJ=4,ISC
      IF(L.EQ.KSC(1,JJ))GOTO 290
  285 CONTINUE
      ERRPT=TOP-1
      ERROR=1235
      GOTO 100
  290 K=24
      IF(MODE.NE.SCURV)K=10
      NOWRDS=NOWRDS+KSC(2,JJ)-K
      IF(JMP.EQ.5)NOWRDS=NOWRDS+KSC(2,JJ)+24*KSC(3,JJ)
      GOTO 330
C
C                MOVE COUPLER TO LINE
C
  300 GOTO(310,330),MOUT
  310 IF(CLASS.EQ.PERMID(1))MODE=MODE-50
      IBUFF(8:15)=IBLANK
      CALL BINBCD(MODE,IBUFF(4:),NCH)
      WRITE (IBUFF(1:3),'(I3)') NCH
      CALL CONCAT(IBUFF,'.')
      JN=NUMB(IBUFF(4:15))+NAMMAX
      CALL OPCODE(MOVE)
      CALL TWOARG(INDEX,DOTTAB)
      CALL TWOARG(DLR,JN)
      CALL RLSLIN
      INDEX=INDEX-1
      IF(IND.GT.1)GOTO 330
C
  320 CALL OPCODE(MOVE)
      GOTO 340
  330 CALL OPCODE(REPL)
      CALL ONEARG(IND)
  340 CALL TWOARG(INDEX,DOTTAB)
      CALL ARGCVT(STACK(1,TOP-1))
      CALL RLSLIN
      INDEX=INDEX-IND
      GOTO(140,270),IRET
C
C                PROCESS END OF DEFINITION
C
  500 IF(MINDEF.AND.FLOWS.NE.0)GOTO 510
      CALL ALARM(1204,TOP,8,'SSDEF   ')
      FOULUP=.TRUE.
      GOTO 520
  510 IF(MMODE.EQ.182.AND.PNT.NE.NPS)CALL ALARM(1225,0,8,'SSDEF   ')
  520 ISS=MOD(NAMTBL(STACK(1,TOP-3)),MODHLF)
      IF(ACTNO.NE.105)GOTO 530
      RESULT=GETTMP(ISS)
      GOTO 560
  530 RESULT=STACK(1,TOP-5)
      CLASS=MODULO*(NAMTBL(RESULT)/MODULO)
      MODE=MOD(NAMTBL(RESULT),MODHLF)
      IF(CLASS.EQ.VBL(1).OR.CLASS.EQ.TEMP(1))GOTO 540
      NAMTBL(RESULT)=VBL(1)+ISS
      CALL RESRVZ(RESULT,ISS,TXXXX(1,ISS),1)
      MODE=MOD(NAMTBL(RESULT),MODHLF)
  540 IF(MODE.NE.ISS)GOTO 800
      IF(CLASS.EQ.VBL(1).AND.INTMED.EQ.0)
     *                      CALL ALARM(52,TOP-5,4,'SSDEF   ')
  560 IF(FOULUP)GOTO 810
      IF(.NOT.WTFLAG)GOTO 570
      CALL ALARM(1200+WTMODE,TOP,8,'SSDEF   ')
  570 DO 590 I=3,5
      J=-I
      IF(I-4)573,574,575
  573 NMU=SPL
      GOTO 580
  574 NMU=NPS
      GOTO 580
  575 NMU=-INDEX
  580 IBUFF(8:15)=IBLANK
      CALL BINBCD(NMU,IBUFF(4:),NCH)
      WRITE (IBUFF(1:3),'(I3)') NCH
      CALL CONCAT(IBUFF,'.')
      JN=NUMB(IBUFF(4:))+NAMMAX
      CALL OPCODE(MOVE)
      CALL TWOARG(J,DOTTAB)
      CALL TWOARG(DLR,JN)
  590 CALL RLSLIN
      IF(ISS.EQ.30)GOTO 585
      CALL CALLZZ(APTXXX(88))
      GOTO 595
  585 I=90
      IF(MMODE.EQ.200)I=86
      CALL CALLZZ(APTXXX(I))
  595 CALL ARGCVT(RESULT)
      DO 600 I=1,3
  600 CALL ARGCVT(ITMP(1,I))
      CALL RLSLIN
C
C                STORAGE OF THE SIZE
C
      GOTO(610,620,630,640,650,660,670),JMP
C**** SSURF/                   SMESH
  610 IF(SPL.EQ.2.OR.NPS.EQ.2)KN=47
      NOWRDS=10+KN*(SPL-1)*(NPS-1)
      GOTO 700
C**** SSURF/                   PATCH
  620 NOWRDS=8+65*NPATCH
      GOTO 700
C**** SSURF/                   COMBIN
  630 NOWRDS=NOWRDS+10
      GOTO 700
C**** SSURF/                   REVOLV
  640 NOWRDS=10+222*NOWRDS/24
      GOTO 700
C**** SSURF/                   GENCUR,RULED
C****                          TRANSL,SCALE,XYROT,YZROT,ZXROT
  650 NOWRDS=10+NOWRDS
      GOTO 700
  660 IF(NOWRDS.GT.0)GOTO 670
C**** SCURV/                   CURSEG,SPLINE,SEG
      NOWRDS=72
      IF(SEGMS.GT.0)NOWRDS=144+6*SEGMS
      GOTO 700
C**** SCURV/                   COMBIN
  670 NOWRDS=NOWRDS+24
C
  700 IF(CLASS.NE.TEMP(1))GOTO 720
      J=ISS-28
      IF(NOWRDS.GT.KSC(2,J))KSC(2,J)=NOWRDS
      IF(SEGMS.GT.KSC(3,J))KSC(3,J)=SEGMS
      GOTO 760
  720 ISC=ISC+1
      IF(ISC.LE.300)GOTO 740
      CALL ALARM(34,TOP-5,8,'SSDEF   ')
      GOTO 810
  740 KSC(1,ISC)=RESULT
      KSC(2,ISC)=NOWRDS
      KSC(3,ISC)=SEGMS
  760 IF(NOWRDS.LE.MAXSIZ(2)) GOTO 820
      IF(NOWRDS.GE.MAXSIZ(1)) GOTO 780
      MAXSIZ(2)=NOWRDS
      GOTO 820
  780 MAXSIZ(2)=MAXSIZ(1)
      MAXSIZ(1)=NOWRDS
      GOTO 820
C
C                ERROR PROCESSING GENERATE CALL TO APT094
C
  800 CALL ALARM(1001,TOP-5,8,'SSDEF   ')
  810 CALL CALLZZ(APTXXX(68))
      CALL TWOARG(DLR,FOUR)
      CALL ARGCVT(RESULT)
      CALL TWOARG(NOUGHT,DOTTAB)
      CALL RLSLIN
C
C                IF NESTED DEFINITION LOAD SAVED DATA
C
  820 IF(ACTNO-104)150,830,840
  830 TOP=TOP-6
      GOTO 860
  840 TOP=TOP-4
  860 STACK(1,TOP)=RESULT
      CLASS=NAMTBL(RESULT)/MODULO
      STACK(2,TOP)=META(CLASS)
      IF(JSAVE.EQ.0)GOTO 890
      IF(TOP.GT.SAVE(JSAVE,21))GOTO 890
      DO 880 I=1,27
  880 STK(1,I)=SAVE(JSAVE,I)
      JSAVE=JSAVE-1
      GOTO 150
  890 BIGCNT=0
      GOTO 150
C
C                NESTED DEFINITION, SAVE DATA
C
  900 IF(JSAVE.LT.2)GOTO 910
      CALL ALARM(1228,TOP-5,8,'SSDEF   ')
      FOULUP=.TRUE.
      MINDEF=.TRUE.
      GOTO 140
  910 JSAVE=JSAVE+1
      DO 920 I=1,27
  920 SAVE(JSAVE,I)=STK(1,I)
      TP=TP+1
      GOTO 1
C
C       ****  POINT,VECTOR,SCALAR OR SURFACES EXPECTED ****
C
 1000 COUNT=COUNT+1
      IF(COUNT.EQ.MAXCNT)WTFLAG=.FALSE.
      IF(MAXCNT-10)1030,1005,1020
 1005 IF(MMODE.NE.193)GOTO 1010
      IF(MODE.EQ.POINT)GOTO 1025
      WTMODE=VECTOR
      WTFLAG=.FALSE.
      GOTO 1025
 1010 IF(COUNT.EQ.9)GOTO 1030
      IF(MODE.EQ.WTMODE)GOTO 1025
      WTMODE=VECTOR
      IF(MMODE.NE.192)WTMODE=SSURF
      GOTO 1025
 1020 WTMODE=SPLARY(COUNT)
 1025 IF(.NOT.WTFLAG)MAXCNT=1
 1030 ERROR=1200+WTMODE
      IF(MODE.NE.WTMODE)CALL ALARM(ERROR,TOP-1,8,'SSDEF   ')
      IF(MODE.NE.MATRIX)GOTO 1040
      IF(NOMTRX)CALL ALARM(1216,TOP-1,4,'SSDEF   ')
      IND=12
      IF(STACK(1,TOP).NE.COMMA(2))GOTO 330
      FOULUP=.TRUE.
      CALL ALARM(1217,TOP,8,'SSDEF   ')
      GOTO 330
 1040 GOTO TSEG,(1100,1910)
C
C       ****  SCURV/CURSEG-SPLINE  ****
C
 1080 COUNT=0
      WTFLAG=.TRUE.
 1090 TP=TP-1
      GOTO 1110
C
 1100 CNT=0
      SPLARY(1)=0
 1110 IND=1
      IF(CLASS.NE.PERMID(1))IND=TXXXX(1,MODE)
      IF(IND.EQ.2)GOTO 280
      GOTO 300
C
 1200 IF(.NOT.CRSFLG.OR.PNT.LT.2)GOTO 1210
      ESTACK(TOP-1)=ERRPOS(102)
      CALL ALARM(1211,TOP-1,4,'SSDEF   ')
 1210 CRSFLG=.FALSE.
      GOTO 1310
C
 1300 NPS=NPS+1
 1310 MINDEF=.TRUE.
 1320 PNT=PNT+1
      IF(PNT.EQ.PTM)CALL ALARM(1201,TOP-1,4,'SSDEF   ')
      CNT=0
      SPLARY(1)=0
      GOTO 1090
C
 1400 WTMODE=VECTOR
      ERROR=1210
      IF(MODE.NE.187)GOTO 1510
      ERRPOS(102)=ESTACK(TOP-1)
      CRSFLG=.TRUE.
      GOTO 1510
C
 1500 WTMODE=REAL
      ERROR=1209
 1510 DO 1520 I=1,CNT
      IF(SPLARY(I).NE.MODE)GOTO 1520
      CALL ALARM(ERROR,TOP-1,4,'SSDEF   ')
      GOTO 1530
 1520 CONTINUE
      CNT=CNT+1
      SPLARY(CNT)=MODE
 1530 MAXCNT=1
      GOTO 1080
C
C                   **** SCURV-SSURF/COMBIN  ****
C
 1600 MINDEF=.TRUE.
      GOTO 1110
C
 1700 IF(ISS.EQ.SSURF)GOTO 1090
      NPS=NPS+1
      PNT=NPS+1
      IF(NPS.EQ.PTM)CALL ALARM(1213,TOP-1,4,'SSDEF   ')
      GOTO 1090
C
C                   ****  SCURV/SEG  ****
C
 1800 CNT=CNT+1
      ERROR=1212
      ERRPT=TOP-1
      GOTO(1810,1820,1830,110),CNT
 1810 CALL CALLZZ(APTXXX(86))
      CALL ARGCVT(STACK(1,TOP-7))
      CALL ARGCVT(STACK(1,TOP-1))
      CALL ARGCVT(ZEROPT)
      CALL ARGCVT(ONE)
      CALL RLSLIN
 1820 II=STACK(1,TOP-1)
      GOTO 140
 1830 MINDEF=.TRUE.
      IF(COUNT.GT.0)GOTO 1820
      COUNT=COUNT+1
 1840 COUNT=COUNT+1
 1850 CALL CALLZZ(APTXXX(86))
      CALL ARGCVT(STACK(1,TOP-7))
      CALL ARGCVT(II)
      CALL ARGCVT(STACK(1,TOP-1))
      CALL ARGCVT(TWO)
      CALL RLSLIN
      II=-II
      GOTO 140
C
 1900 TP=TP-2
      IF(COUNT.GE.2)GOTO 1820
      GOTO 1840
 1910 IF(II.LT.0)GOTO 1820
      GOTO 1850
C
C                   ****  FLOW AND SEG SECTION ****
C
 2000 FLOWS=0
 2010 IF(MINDEF)GOTO 2020
      FOULUP=.TRUE.
      CALL ALARM(1204,TOP-1,8,'SSDEF   ')
 2020 GOTO TSEG,(1080,1100,1910)
C
 2100 FLWARG=2
      IF(MODE.EQ.117)FLWARG=3
      GOTO 2210
C
 2200 FLWARG=5
      IF(MODE.EQ.204)FLWARG=6
      IF(JMP.EQ.5)CALL ALARM(1206,TOP-1,8,'SSDEF   ')
      JMP=FLWARG
 2210 FLOWS=FLOWS+1
      IF(FLOWS.EQ.PNT)CALL ALARM(1205,TOP-1,4,'SSDEF   ')
 2220 COUNT=0
      MAXCNT=2
 2240 WTMODE=REAL
 2250 WTFLAG=.TRUE.
      GOTO 2640
C
 2300 IF(COUNT.NE.2.OR.FLWARG.LT.3)CALL ALARM(1206,TOP-1,8,'SSDEF   ')
      COUNT=2
      MAXCNT=3
      WTMODE=REAL
      GOTO 2410
C
 2400 IF(COUNT.GT.3.OR.FLWARG.LT.5)CALL ALARM(1206,TOP-1,8,'SSDEF   ')
      IF((FLWARG+MODE).EQ.223)CALL ALARM(1206,TOP-1,8,'SSDEF   ')
      JMP=0
      WTMODE=POINT
      COUNT=3
      MAXCNT=COUNT+MODE/110
 2410 WTFLAG=.TRUE.
      TP=TP-1
      GOTO 140
C
 2500 IF(FLWARG.LT.5.OR.FLWARG.LE.COUNT)CALL ALARM(1206,TOP-1,8,
     *                                  'SSDEF   ')
      WTMODE=VECTOR
      MAXCNT=FLWARG
      COUNT=MAXCNT-1
      GOTO 2410
C
 2600 IF(MODE-VECTOR)2610,2620,2630
 2610 COUNT=COUNT+1
      IF(COUNT.LT.4)COUNT=4
      JMP=0
      IF(COUNT.GT.(FLWARG-1))CALL ALARM(1207,TOP-1,4,'SSDEF   ')
      GOTO 2640
 2620 IF(FLWARG.LT.5)CALL ALARM(1207,TOP-1,4,'SSDEF   ')
      IF(FLWARG.EQ.6.AND.COUNT.EQ.4)CALL ALARM(1207,TOP-1,4,'SSDEF   ')
      COUNT=COUNT+1
      IF(COUNT.LT.FLWARG)COUNT=FLWARG
      IF(COUNT.GT.FLWARG)CALL ALARM(1207,TOP-1,4,'SSDEF   ')
      GOTO 2640
 2630 IF(COUNT.GT.2.OR.FLWARG.LT.3)CALL ALARM(1207,TOP-1,4,'SSDEF   ')
      COUNT=3
 2640 TP=TP-1
      GOTO TSEG,(1100,1910)
C
 2700 SEGMS=0
      MINDEF=.FALSE.
      IF(MODE.EQ.MMODE)GOTO 140
      GOTO 1110
C
 2800 SEGMS=SEGMS+1
      MINDEF=.TRUE.
      IF(SEGMS.EQ.PNT)CALL ALARM(1208,TOP-1,4,'SSDEF   ')
      GOTO 2220
C
C                   ****  TRFORM,MATRIX  ****
C
 2900 WTMODE=MATRIX
      ITMP(1,2)=L
      MAXCNT=1
      MOUT=1
      ASSIGN 1080 TO TSEG
      GOTO 2010
C
C                   ****  SSURF/SMESH  ****
C
 3000 IF(MMODE.EQ.181)GOTO 140
      IF(MODE.EQ.193)SPM=3
      IF(HMODE.GT.83.AND.HMODE.LT.99)NOMTRX=.TRUE.
      JMP=1
      GOTO 140
C
 3100 MINDEF=.FALSE.
      SPL=SPL+1
      CNT=0
      SPLARY(1)=0
      IF(SPL-2)320,3110,3120
 3110 NPS=PNT
      IF(NPS.LT.2)CALL ALARM(1225,TOP-1,8,'SSDEF   ')
      GOTO 3130
 3120 IF(SPL.EQ.SPM)CALL ALARM(1203,TOP-1,4,'SSDEF   ')
      IF(PNT.NE.NPS)CALL ALARM(1225,TOP-1,8,'SSDEF   ')
 3130 PNT=1
      TP=TP-2
      GOTO 320
C
 3200 IF((PNT+1).EQ.NPS)GOTO 1310
      GOTO 1320
C
C                   ****  SSURF/PATCH  ****
C
 3300 NPATCH=NPATCH+1
      MINDEF=.TRUE.
      DO 3310 I=1,16
 3310 SPLARY(I)=POINT
      IF(HMODE-184)3320,3360,3350
 3320 SPLARY(3)=VECTOR
      SPLARY(4)=VECTOR
      DO 3340 I=7,16
 3340 SPLARY(I)=VECTOR
      GOTO 3360
 3350 IF(NPATCH.EQ.2)CALL ALARM(1215,TOP-1,4,'SSDEF   ')
 3360 MAXCNT=16
      COUNT=0
      WTFLAG=.TRUE.
      TP=TP-1
      SPL=NPATCH
      GOTO 320
C
C                   ****  SSURF/REVOLV-RULED  ****
C
 3400 IF(MMODE.EQ.192)GOTO 3430
      SPL=0
      MINDEF=.TRUE.
      GOTO 3440
 3430 JMP=4
      STK(2,TP-1)=STK(2,TP)
 3440 TP=TP-1
      WTMODE=POINT
      COUNT=8
      MAXCNT=10
      WTFLAG=.TRUE.
      GOTO 1110
C
 3500 WTMODE=REAL
      MAXCNT=2
      MINDEF=.TRUE.
      CNT=0
      GOTO 1080
C
C                   ****  SSURF/GENCUR  ****
C
 3600 IF(CLASS.EQ.PERMID(1))GOTO 3610
      PNT=PNT+1
      IF(PNT.EQ.PTM.AND.MMODE.EQ.205)CALL ALARM(1201,TOP-1,4,'SSDEF   ')
      TP=TP-1
      GOTO 1600
 3610 MINDEF=.FALSE.
      IF(CNT.EQ.TP)CALL ALARM(1212,TOP-1,4,'SSDEF   ')
      CNT=TP
      GOTO 1090
C
C               ****  SSURF/TRANSL,SCALE,XYTRANS,YZTRANS,ZXTRANS ***
C
 3700 WTMODE=SCURV
      MINDEF=.TRUE.
      MAXCNT=1
      GOTO 1080
C
      END