**** SOURCE FILE : M0011539.W03   ***
*
C
C......    FORTRAN SUBROUTINE CNVRT3    11/69    RC
C.....FORTRAN SUBROUTINE                CNVRT3...            8/1/68  AR
C PURPOSE          TO CONVERT EXFILE RECORDS INTOAPTIII FORMAT AND
C                  WRITE THEM ON CLFIL3.
C
C CALLING SEQUENCE CALL CNVRT3(MLTFLG)
C
C ARGUMENTS        MLTFLG     MULTAX FLAG-0,IF OFF
C                                         1,IF ON
C
C CALLED BY        APT301
C
C SUBSIDIARIES     NONE
C
C DIAGNOSTICS      ERROR CODE   COMMENT
C                  ----------   -------
C                               UNIDENTIFIED POSTPROCESSOR COMMAND---
C                               XXXXXX. SEQUENCE NO. NNNNNN.
C
C                               UNIDENTIFIED MODIFIER--- XXXXXX.
C                               SEQUENCE NO. NNNNNN.
C
C METHOD           THE CURRENT EXFILE RECORD IN THE RECORD ARRAY IS
C                  EXAMINED AND THE APPROPRIATE APTIII CLTAPE RECORDS
C                  ARE WRITTEN ON CLFIL3.
C
C*********************************************************************
C
      SUBROUTINE  CNVRT3(MLTFLG)
      IMPLICIT  DOUBLE PRECISION(A-H),DOUBLE PRECISION(O-Z)
C
      COMMON /EDITOR/ EDITOR
      DIMENSION  EDITOR(1500)
      DIMENSION  AREA1(1500), AREA2(1000), AREA3(250)
      EQUIVALENCE  (EDITOR(1500),AREA1(1500),AREA2(1000),AREA3(250))
C
      EQUIVALENCE (AREA2(94),NUMCLD)
      DIMENSION  RECORD(256),IRECRD(256),JRECRD(512)
      EQUIVALENCE  (EDITOR(1),IRECRD(1),RECORD(1),JRECRD(1))
      EQUIVALENCE  (JRECRD(6),NUMWDS)
      DOUBLE PRECISION  IRECRD
C
C...            SYSTEM I/O FILE NAMES
C
      INCLUDE 'SYMFIL.INC'
C
C
      COMMON/I5AXIS/
     1 IVTFLG,IS,IR,IL,IE,JSUBER,IABOVE,NRECEX,NRECCL,NCFLSV
C
C... LOCAL VARIABLES
C
      CHARACTER*6 RECTYP,PPNAME,PMNAME,PARAM,PM0,PM1,
     1            PAR0,PAR1,PAR2,PAR3,SPLWDS
      DIMENSION  IRXXXX(515),RXXXX(256),IR1000(7),R1000(2),RECTYP(10),
     1           PPNAME(22),PMNAME(100),PARAM(200),IJK(2),PM0(50),
     2           PM1(50),PAR0(50),PAR1(50),PAR2(50),PAR3(50),SPLWDS(20)
      CHARACTER*6 PP2(2),PM2(8),PAR4(7)
      INTEGER     IPP2(2),IPM2(8),IPAR4(7)
      CHARACTER*8 BLANK,SCALIN(4),TEST8
      CHARACTER*6 OFF,FROM,GODLTA,SCALWD,TEST,ATEST
      EQUIVALENCE  (IJK(2),IRXXXX(1)),(IRXXXX(4),RXXXX(1)),
     1             (IRXXXX(3),SUBTYP),(IR1000(4),R1000(1)),
     3             (PMNAME(1),PM0(1)),(PMNAME(51),PM1(1)),
     3             (PARAM(1),PAR0(1)),(PARAM(51),PAR1(1)),
     4             (PARAM(101),PAR2(1)),(PARAM(151),PAR3(1))
      INTEGER BCDF
      INTEGER  SUBTYP,SUBCLS
      CHARACTER    RCDCHR*1000,BLK,CHAR*8,BLK2*2,BLK4*4
      EQUIVALENCE  (BLK,BLANK),(BLK2,BLANK),(BLK4,BLANK)
      LOGICAL  MULTAX
C
C...     RECORD TYPES AND POST PROCESSOR SUBCLASS WORDS
C
      DATA  RECTYP /'FINI  ','AERR  ','GERR  ','MULTAX','CLDATA',
     1              'CLPRNT','CLDAT ','      ','      ','      '/
C
      DATA  SPLWDS /'CUT   ','2DCALC','******','INTOL ','OUTTOL',
     1              'CUTTER','******','******','DYNDMP','******',
     2              'DNTCUT','3DCALC','TOLER ','THICK ','MAXDP ',
     3              'NUMPTS','GOUGCK','POCKET','******','******'/
C
C
      DATA  PPNAME /'END   ','STOP  ','OPSTOP','ISTOP ','RAPID ',
     1              'SWITCH','RETRCT','DRESS ','PICKUP','UNLOAD',
     2              'PENUP ','PENDWN','ZERO  ','CODEL ','RESET ',
     3              'GOCLER','DRAWLI','PROBY ','PROBX ','ULOCKX',
     4              'LOCKX ','FACEML'/
      DATA PP2/'GOHOME','BREAK '/
      DATA IPP2/   14,    17  /
      DATA  PM0    /'PLUNGE','HEAD  ','MODE  ','CLEARP','TMARK ',
     1              'REWIND','CUTCOM','REVERS','FEDRAT','DELAY ',
     2              'AIR   ','OPSKIP','LEADER','PPLOT ','MACHIN',
     3              'MCHTOL','PIVOTZ','MCHFIN','SEQNO ','INTCOD',
     4              'DISPLY','AUXFUN','CHECK ','POSTN ','TOOLNO',
     5              'ROTABL','ORIGIN','SAFETY','ARCSLP','COOLNT',
     6              'SPINDL','IFRO  ','TURRET','*1034*','ROTHED',
     7              'THREAD','TRANS ','TRACUT','INDEX ','COPY  ',
     8              'PLOT  ','OVPLOT','LETTER','PPRINT','PARTNO',
     9              'INSERT','CAMERA','PREFUN','COUPLE','PITCH '/
      DATA  PM1      /'MDWRIT','MDEND ','ASLOPE','CYCLE ','LOADTL',
     1              'SELCTL','CLRSRF','DWELL ','DRAFT ','CLAMP ',
     2              'PLABEL','MAXDPM','SLOWDN','MAXVEL','LPRINT',
     3              'MOVETO','CORNFD','PBS   ','REGBRK','VTLAXS',
     4              'WCORN ','MAGTAP','*1073*','*1074*','*1075*',
     5              '*1076*','*1077*','*1078*','*1079*','*1080*',
     6              '*1081*','*1082*','*1083*','*1084*','*1085*',
     7  15*'      '/
      DATA PM2/'DELETE','PPLOT','WRTMDI','ENDMDI','POSMAP',
     1              'DEBUGG','LINTOL','******'/
      DATA IPM2/ 1012,  1014  ,  1051  ,  1052  ,   1068 ,
     1                 1032,  1067  ,     0  /
      DATA PAR0    /'ATANGL','CENTER','CROSS ','FUNOFY','INTOF ',
     1              'INVERS','LARGE ','LEFT  ','LENGTH','MINUS ',
     2              'NEGX  ','NEGY  ','NEGZ  ','NOX   ','NOY   ',
     3              'NOZ   ','PARLEL','PERPTO','PLUS  ','POSX  ',
     4              'POSY  ','POSZ  ','RADIUS','RIGHT ','SCALE ',
     5              'SMALL ','TANTO ','TIMES ','TRANSL','UNIT  ',
     6              'XLARGE','XSMALL','XYPLAN','XYROT ','YLARGE',
     7              'YSMALL','YZPLAN','YZROT ','ZLARGE','ZSMALL',
     8              'ZXPLAN','ZXROT ','3PT2SL','4PT1SL','5PT   ',
     9              'INTERC','SLOPE ','IN    ','OUT   ','OPEN  '/
      DATA  PAR1     /'ALL   ','LAST  ','NOMORE','SAME  ','MODIFY',
     1              'MIRROR','START ','ENDARC','CCLW  ','CLW   ',
     2              'MEDIUM','HIGH  ','LOW   ','CONST ','DECR  ',
     3              'INCR  ','GRID  ','ROTREF','TO    ','PAST  ',
     4              'ON    ','OFF   ','IPM   ','IPR   ','CIRCUL',
     5              'LINEAR','PARAB ','RPM   ','MAXRPM','TURN  ',
     6              'FACE  ','BORE  ','BOTH  ','XAXIS ','YAXIS ',
     7              'ZAXIS ','NORMDS','AUTO  ','FLOOD ','MIST  ',
     8              'TAPKUL','STEP  ','MAIN  ','SIDE  ','LINCIR',
     9              'MAXIPM','REV   ','TYPE  ','NIXIE ','LIGHT '/
      DATA PAR2    /'FOURPT','TWOPT ','PTSLOP','PTNORM','SPLINE',
     1              'RTHETA','THETAR','XYZ   ','TANON ','TRFORM',
     2              'NORMAL','UP    ','DOWN  ','LOCK  ','SFM   ',
     3              'XCOORD','YCOORD','ZCOORD','MULTRD','XYVIEW',
     4              'YZVIEW','ZXVIEW','SOLID ','DASH  ','DOTTED',
     5              'CTRLIN','DITTO ','PEN   ','SCRIBE','BLACK ',
     6              'RED   ','GREEN ','BLUE  ','INTENS','LITE  ',
     7              'MED   ','DARK  ','CHUCK ','COLLET','AAXIS ',
     8              'BAXIS ','CAXIS ','TPI   ','OPTION','RANGE ',
     9              'PSTAN ','RANDOM','FRONT ','REAR  ','SADDLE'/
      DATA PAR3      /'MILL  ','THRU  ','DEEP  ','TRAV  ','SETOOL',
     1              'SETANG','HOLDER','MANUAL','ADJUST','CUTANG',
     2              'NOW   ','NEXT  ','DRILL ','BINARY','BCD   ',
     3              'PART  ','REAM  ','TAP   ','CAM   ','NOCLRP',
     4              'REGTOL','TRAVED','MAXWD ','MAXLNG','SPIRAL',
     5              'ANTSPI','ZIGZAG','NOBND ','MAXPTS','GAPLES',
     6              '**181*','ARC   ',' *183*','RETAIN','ZIGZAG',
     7              'OMIT  ','AVOID ',' *188*','AT    ',' *190*',
     8              ' *191*',' *192*',' *193*',' *194*',' *195$',
     9              ' *196*',' *197*',' *198*',' *199*',' *200*'/
      DATA PAR4/'PITCH','RAIL','FULL','SAVMDI','SAVTDI','MMPM','MMPR'/
      DATA IPAR4/ 67   ,  93  , 147  ,   398  ,   396  ,   171,  172/
      DATA IR1000(2)/1000/
      DATA IRCOLD/-1/
      DATA  BLANK,OFF,MULTAX,FROM,GODLTA /'        ','OFF   ',.FALSE.,
     1 'FROM  ','GODLTA'/
      DATA  NNN/0/
      DATA SCALIN /'MM      ','CM      ','INCHES  ','FEET    '/
      DATA SCALWD /'UNITS '/
      DATA I3000/0/
C     --------------------------------------------------------
C
      KKIX=0
      IF (NNN .NE. 0) GO TO 3
      DO 1 I=4,7
        IR1000(I)=BCDF(BLK4)
    1 CONTINUE
C...     STORE SEQUENCE NUMBER AND INITIALIZE
    3 ISEQ=JRECRD(4)
      IR1000(3)=ISEQ-(ISEQ/10000)*10000
      IRXXXX(1)=ISEQ/10000
      IRXXXX(3)=0
      DO 10  I = 1,5
   10 RXXXX(I) = 0.D0
      IX = 0
C
C...     BRANCH ON RECORD TYPE
      CALL HOLFRM(RECORD(1),TEST,1,6,NWD)
      DO 100  IT=1,10
      IF (TEST .NE. RECTYP(IT)) GO TO 100
      GO TO (300,350,400,500,1000, 450,9999,9999,9999,9999), IT
  100 CONTINUE
C
C...     CHECK FOR SPECIAL WORDS--SPECIAL PROCESSING NEEDED
      DO 105 KK=1,20
      IF (TEST .EQ. SPLWDS(KK)) GO TO 600
  105 CONTINUE
C
C...     *** POSTPROCESSOR TYPE COMMANDS***
      IF(TEST.EQ.SCALWD) GO TO 605
      IRXXXX(2) = 2000
      CALL HOLFRM(RECORD(5),TEST8,1,8,NWD)
      IF ((JRECRD(6) .NE. 2) .OR. (TEST8 .NE. BLANK))  GO TO 140
      DO 110 SUBTYP = 1,22
      IF (TEST .EQ. PPNAME(SUBTYP))  GO TO 9000
  110 CONTINUE
      DO 111 I = 1,2
      SUBTYP=IPP2(I)
      IF(TEST.EQ.PP2(I))GOTO 9000
  111 CONTINUE
C
  140 DO 150  SUBTYP = 1001,1100
      IF (TEST .EQ. PMNAME(SUBTYP-1000))  GO TO 160
  150 CONTINUE
      DO 151 I=1,8
      SUBTYP=IPM2(I)
      IF(TEST.EQ.PM2(I))GOTO 160
  151 CONTINUE
C
C...     UNIDENTIFIED POSTPROCESSOR COMMAND--ISSUE ERROR MESSAGE
      CALL APT336(30030,'CNVRT3  ')
      GO TO 9999
C
  160 IR = 4
      LR=NUMWDS+3
      IF (JRECRD(8) .EQ. 3 .AND. JRECRD(12) .EQ. 0)  IX=1
  170 IX = IX + 1
      IT=JRECRD(IR*2)
      GO TO (180,190,230,225), IT
C...     ***  TYPE 1 --- FLOATING POINT DATA ITEM PAIR
  180 RXXXX(IX) = RECORD(IR+1)
      GO TO 250
C...     ***  TYPE 2 --- ALPHANUMERIC DATA ITEM PAIR
  190 CALL HOLFRM(RECORD(IR+1),ATEST,1,6,NWD)
      DO 200  I = 1,200
      IF (ATEST .EQ. PARAM(I))  GO TO 220
  200 CONTINUE
      DO 201 J=1,7
      I=IPAR4(J)
      IF(ATEST.EQ.PAR4(J))GOTO 220
  201 CONTINUE
      CALL HOLFRM(RECORD(IR+1),RCDCHR,1,8,NWD)
      CHAR=BLANK
      N=6
      DO 210  I = 6,1,-1
      IF (RCDCHR(I:I) .EQ. BLK) GO TO 210
      CHAR(N:N) = RCDCHR(I:I)
      N = N - 1
  210 CONTINUE
      IRXXXX(2*IX+2) = BCDF(CHAR(1:4))
      IRXXXX(2*IX+3) = BCDF(CHAR(5:8))
      GO TO 250
  220 MM=2*IX+2
      IRXXXX(MM) = 0
      IRXXXX(MM+1) = I
      GO TO 250
C...     ***  TYPE 4 --- GEOMETRIC VARIABLE
  225 M=JRECRD((IR+1)*2)
      DO 227  I=1,M
      J=IX+I-1
      RXXXX(J)=RECORD(IR+I+1)
  227 CONTINUE
      IX=J
      IR=IR+M
      GO TO 250
C...     ***  TYPE 3 --- ALPHANUMERIC LITERAL STRING
  230 M = JRECRD((IR+2)*2)
      RCDCHR=BLANK
      CALL HOLFRM(RECORD(IR+3),RCDCHR,1,M,NWD)
      N=M/6
      IF (M.GT.N*6) N=N+1
      I=1
      DO 232  KIX=1,N
      CHAR=RCDCHR(I:I+5)//BLK2
      IRXXXX(2*IX+2) = BCDF(CHAR(1:4))
      IRXXXX(2*IX+3) = BCDF(CHAR(5:8))
      IX=IX+1
      I=I+6
  232 CONTINUE
      DO 240  KIX = IX,12
      IRXXXX(2*IX+2) = BCDF(BLANK)
      IRXXXX(2*IX+3) = BCDF(BLANK)
      IF (SUBTYP.GE.1044.AND.SUBTYP.LE.1046)KKIX=11
  240 CONTINUE
      IR = IR + JRECRD((IR+1)*2)
  250 IR = IR + 2
  260 IF (IR.LT.LR)  GOTO 170
      GOTO 9000
               
C...     FINI RECORD...
  300 IRXXXX(2) = 14000
      IF (NNN.EQ.0)RETURN
      GO TO 9000
C
C...     AERR RECORD -- STORE PREVIOUS SEQUENCE NUMBER
  350 IF (JRECRD(4) .NE. 1) GO TO 9999
      IR1000(3)=ISVSEQ-(ISVSEQ/10000)*10000
      IRXXXX(1)=ISVSEQ/10000
C...     GERR RECORD
  400 IRXXXX(2)=13000
      IRXXXX(3) = 3
      IRXXXX(5) = JRECRD(8)
  410 IX=1
      IRXXXX(4)=0
      GO TO 9000
C...     CLPRNT RECORD.....SET ON OR OFF
  450 IRXXXX(2)=13000
      IRXXXX(3)=4
      IRXXXX(5)=1
      CALL HOLFRM(RECORD(5),TEST,1,6,NWD)
      IF (TEST .EQ. OFF) IRXXXX(5)=0
      GO TO 410
C...     MULTAX RECORD -- SET MULTAX FLAG
  500 IRXXXX(2) = 9000
      IRXXXX(3) = 2
      IRXXXX(4)=0
      IRXXXX(5) = 1
      CALL HOLFRM(RECORD(5),TEST,1,6,NWD)
      IF(TEST.EQ.OFF)IRXXXX(5)=0
      MULTAX = .FALSE.
      IF (IRXXXX(5) .EQ. 1)  MULTAX = .TRUE.
      GO TO 410
  605 IRXXXX(2)=9000
      IRXXXX(3)=9
      CALL HOLFRM(RECORD(5),TEST8,1,8,NWD)
      DO 601 I=1,4
      IF(TEST8.EQ.SCALIN(I)) GO TO 603
  601 CONTINUE
C...     ERROR 30038 -- ERRONEOUS UNITS COMMAND
      CALL APT336(30038,'CNVRT3  ')
      GO TO 9999
  603 IRXXXX(5)=I
      GO TO 410
C
C...     ********* CLDATA RECORDS *********
 1000 IF(JRECRD(8)-2) 1010,1030,1030
 1010 SUBCLS = 5
      CALL HOLFRM(RECORD(5),ATEST,1,6,NWD)
      IF (ATEST .EQ.FROM)  SUBCLS = 3
      SAVNAM = RECORD(7)
      SAVSUB = RECORD(8) + .0
      IF(JRECRD(6).LE.6) GO TO 9997
      IX =12
C...     SAVE CIRCLE CANONICAL FORM
      IRXXXX(2) = 3000
      IRXXXX(3) = 2
      IRXXXX(7) = 4
      IRXXXX(9)=9
      RXXXX(4) = RECORD(7)
      RXXXX(5) = RECORD(8)
      DO 1020 I=6,12
1020  RXXXX(I)=RECORD(I+4)
      GO TO 9000
C
C...     SAVE CUTTER LOCATION POINTS
 1030 IRXXXX(2) = 5000
      IRXXXX(3) = SUBCLS
      NSAVE=NNN
      SBCLSV=SUBCLS
      SUBCLS = 6
      RXXXX(1) = SAVNAM
      RXXXX(2) = SAVSUB
      I = 3
      MM=4
      IF (MULTAX) MM=7
      DO 1070  J = 1,NUMWDS
      IF (( (J+1) - ((J-1)/MM * MM) )/3 - 1) 1070,1050,1050
 1050 RXXXX(I) = RECORD(J+3)
      I = I + 1
 1070 CONTINUE
      IX =I - 1
      IF (IRXXXX(3) - 5)  9010,9010,9100
 9000 IF (KKIX .GE. 11)  IX=KKIX
 9010 IF(I3000.EQ.1) GO TO 9050
      IF(IR1000(3).EQ.IRCOLD) GO TO 9100
      NNN=NNN+1
      IRCOLD=IR1000(3)
      IR1000(1) = NNN
      CALL ATAPWT(CLFIL3,IRET,2,IR1000,3,R1000,2)
 9050 I3000=0
 9100 NNN = NNN + 1
      IRXXXX(1) = NNN
C...     CALCULATE CLFIL3 RECORD NUMBER TO LIST ON VLFILE
      ISEQ=IR1000(3)+NNN*10000
      JRECRD(4)=ISEQ
      IF (IX .EQ. 0) GO TO 9200
      IF(IRXXXX(2).EQ.3000) I3000=1
      CALL ATAPWT(CLFIL3,IRET,2,IRXXXX,3,RXXXX,IX)
      GO TO 9998
 9200 CALL ATAPWT(CLFIL3,IRET,1,IRXXXX,3,DUM,1)
 9998 IF (IRXXXX(2) .NE. 14000) GO TO 9999
      CALL ATAPOP(CLFIL3,2,IRET)
      CALL ATAPOP(CLFIL3,1,IRET)
      GO TO 9999
C
C...     ***** SPECIAL POSTPROCESSOR TYPE RECORDS *****
  600 IF (KK .GT. 11) GO TO 9999
      IRXXXX(2)=6000
      GO TO (610,9999,9999,620,620, 620,9999,9999,9999,9999, 610),KK
C
C...     ARELEM FLAGS-CUT,DNTCUT
  610 IRXXXX(3)=KK-KK/10*10
      IRXXXX(5)=0
      IF (KK .GT. 10) IRXXXX(5)=1
      IX=1
      GO TO 410
C
C...     ARELEM DATA ITEMS-CUTTER,INTOL,OUTTOL
  620 IRXXXX(3)=KK
      LR=NUMWDS+3
      DO 625  I=5,LR,2
      IX=I/2-1
      RXXXX(IX)=RECORD(I)
  625 CONTINUE
      GO TO 9000
C
C...     SAVE SEQUENCE NUMBER IF NOT AERR TYPE RECORD
 9997 I=NNN+2
      IF (IR1000(3).EQ.IRCOLD)I=I-1
      JRECRD(4)=IR1000(3)+10000*I
 9999 IF (TEST .NE. RECTYP(2)) ISVSEQ=JRECRD(4)
      RETURN
      END
