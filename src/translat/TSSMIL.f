**** SOURCE FILE : M0006690.W06   ***
*
C
C              FORTRAN SUBROUTINE TSSMIL
C
C LINKAGE      SUBROUTINE TSSMIL
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    PRO026
C          SUBROUTINE    ARGCVT
C          SUBROUTINE    BINBCD
C          SUBROUTINE    CALLZZ
C          SUBROUTINE    CONCAT
C          INTEGER FCT.  NUMB
C          SUBROUTINE    ONEARG
C          SUBROUTINE    OPCODE
C          SUBROUTINE    RLSLIN
C          INTEGER FCT.  SEARCH
C          SUBROUTINE    TWOARG
C
      SUBROUTINE TSSMIL
C
      IMPLICIT INTEGER (A-Z)
C
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
      DIMENSION STKLST(300),STACK(2,99),ARGSTK(99)
C TOP:         POINTER TO LAST STACK ENTRY
      EQUIVALENCE (TOP,STKLST(1))
C ARGTOP:      POINTER TO LAST ARGSTK ENTRY
      EQUIVALENCE (ARGTOP,STKLST(2))
C STACK:       WORKING STACK
      EQUIVALENCE (STACK(1,1),STKLST(4))
C ARGSTK:      ARGUMENT STACK
      EQUIVALENCE (ARGSTK(1),STKLST(202))
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),NUMBER(2),TEMP(2),PERMID(2),VBL(2),IDENT(2),
     *          CANON(2)
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
C CANON:       (1)=CODE CLASS 42000,(2)=NAMTBL INDEX OF 'CANON '
      EQUIVALENCE (CANON(1),CODE(83))
C
C        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE
      COMMON/TMP/TXXXX
      DIMENSION TXXXX(2,32)
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
      EQUIVALENCE (ZEROPT,NUMPTR(2))
C ONEPT:       NAMTBL POINTER TO '1.    '
      EQUIVALENCE (ONEPT,NUMPTR(4))
C
C       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR
C
      INCLUDE 'GMTY.INC'
C GEOLOC:      GEOMETRIC ,PRODUCTION STARTING INDEX IN GEOMTB
C PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB
C GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE
C
C       12.    LARGE DATA ARRAY STORAGE REQUIREMENTS
C
      COMMON/CFSIZE/CFSIZE
      DIMENSION CFSIZE(205),MAXSIZ(2)
C MAXSIZ:      SIZE OF THE LAST LARGEST LARGE DATA ARRAY
      EQUIVALENCE (MAXSIZ(1),CFSIZE(4))
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
C LINE:        MODE CODE ( 1) FOR LINE
      EQUIVALENCE (LINE,MODX(1))
C PLANE:       MODE CODE ( 2) FOR PLANE
      EQUIVALENCE (PLANE,MODX(2))
C POINT:       MODE CODE (19) FOR POINT
      EQUIVALENCE (POINT,MODX(19))
C REAL:        MODE CODE (21) FOR A SCALAR
      EQUIVALENCE (REAL,MODX(21))
C SSURF:       MODE CODE (29) FOR SCULPTURED SURFACE
      EQUIVALENCE (SSURF,MODX(29))
C
C       27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION OPMOD(6)
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
C*
      CHARACTER*6 DPS(2),SMIL(6)
      CHARACTER IBUFF*15,BLANK*4
      DIMENSION LOC(4),ARG(5)
      DATA DPS,BLANK,OFFSET /'DS  ','PS  ','    ',25/
      DATA SMIL /'SCON  ','SMIL  ','GOMILL','GCLEAR','INTSEC','AVCTRL'/
      external alarm
C**
C     PREPARE MODES AND PERMANENT IDENTIFIERS OF THE ARGSTK ARGUMENTS
C          AND MOVE THEM TO STACK(2,TOP+1) AND HIGHER ADDR.
C
      IF(ARGTOP.LT.1)GOTO 4000
      TP=TOP+1
      STACK(2,TP)=-1
      DO 40 ERRPT=1,ARGTOP
      NN=0
      J=ARGSTK(ERRPT)
      IF(J.GT.NAMMAX)GOTO 20
      CLASS=NAMTBL(J)/MODULO*MODULO
      MM=NAMTBL(J)-CLASS
      IF(MM.GT.MODHLF)MM=MM-MODHLF
      IF(CLASS.NE.PERMID(1).AND.CLASS.NE.CANON(1))GOTO 10
      NN=50
      MM=MM+NN
      GOTO 30
   10 IF(CLASS.EQ.VBL(1).OR.CLASS.EQ.TEMP(1).OR.MM.EQ.OFFSET)GOTO 30
      IF(CLASS.NE.NUMBER(1))GOTO 4030
   20 MM=REAL
   30 TP=TP+1
      STACK(1,TP)=MM-NN
   40 STACK(2,TP)=PMIDTB(MM)
C
C
C     BRANCH IF INTSEC STATEMENT OR DEFINE START OF SEARCHING
C
      SNAME=STACK(1,TOP-1)
      DO 50 TYP=1,6
        IF(CNAMTB(STACK(1,TOP-1)).NE.SMIL(TYP))GOTO 50
        GOTO(  60,  60,  70,  65,2000,  72),TYP
   50 CONTINUE
      ERRPT=1-TOP
      GOTO 4060
C
C                   START OF SCON/, SMIL/ PRODUCTIONS
   60 GL=GEOLOC(50)
      GOTO 75
C                   START OF GCLEAR/ PRODUCTIONS
   65 GL=GEOLOC(46)
      LPROD=1
      DO 66 I=1,4
      ARG(I)=1
   66 LOC(I)=0
      ARG(5)=1
      GOTO 76
C                  START OF GOMILL/ PRODUCTIONS
   70 GL=GEOLOC(47)
      GOTO 75
C                  START OF AVCTRL/ PRODUCTIONS
   72 GL=GEOLOC(45)
C
C     SEARCH FOR THE PRODUCTION NUMBER AND BRANCH
C
   75 LPROD=0
   76 KK=ARGTOP
      IEND=0
   80 ERRPT=KK
      TPT2=TP*2
      PROD=SEARCH(STACK,TPT2,GEOMTB(GL),ERRPT)
      IF(PROD.EQ.200)GOTO 4050
      IF(LPROD.GT.0)GOTO 90
      J=PROD/5+1
      IF(CNAMTB(STACK(1,TOP-1)).NE.SMIL(J))GOTO 4020
C                   PRODUCTION NUMBERS
C             1    2    3    4    5    6    7    8    9   10
   90 GOTO( 100, 200, 300,3000, 500, 600, 600,4050,4050,1000,
C            11   12   13   14   15   16   17   18   19   20
     *     1000,1200,1300,1400,1600,1600,1600,1600,1600,1700,
C            21   22   23   24   25   26   27   28   29   30
     *     1700,1700,1700,1650,1800,3000,2700,2800,2900,2950),PROD
      GOTO 4050
C
C     CONTROL OF SCON/INIT,DS,PS,FEED,....
C     NO CONTROL OF MULTIPLE DEFINITIONS
C
  100 IF(KK.EQ.2)GOTO 3000
      TP=TP-1
      KK=KK-1
      STACK(2,TP)=STACK(2,TP+1)
      GOTO 80
C
C     CONTROL OF OPTIONAL 'OFFSET' IN SCON/DS,......
C
  200 MM=ARGTOP
      NN=1
      IF(ERRPT.LE.0)GOTO 610
      IF(STACK(1,TOP+1+ERRPT).NE.OFFSET)GOTO 4030
      ERRPT=ERRPT-1
      GOTO 610
C
C     CONTROL SCON/PS,....
C
  300 MM=ARGTOP
      NN=2
      IF(ERRPT.LE.0)GOTO 610
      GOTO 510
C
C     CONTROL SMIL/PATH,..  SMIL/ZIGZAG,... SMIL/PICKFD,....
C
  500 MM=ARGTOP-1
      NN=1
      IF(ERRPT.LE.0)GOTO 610
C
C     CONTROL OF OPTIONAL 'REAL'
C
  510 IF(STACK(1,TOP+1+ERRPT).NE.REAL)GOTO 4030
      ERRPT=ERRPT-1
      GOTO 610
C
C     CONTROL SMIL/POSN,..
C
  600 MM=ARGTOP-1
      NN=1
C
C     CONTROL OF 'PS' RSP. 'DS' ,BECAUSE BOTH ARE OF SAME MODE AND CLASS
C
  610 IF(CNAMTB(ARGSTK(MM)).NE.DPS(NN))GOTO 4040
      GOTO 3000
C
C     A P T  COMPATIBLE REGIONAL MILLING
C
C     FIRST (STANDARD) PART OF MULTI-CUT SEQUENCE COMMAND
C           PRODUCTION 13 MAY, 14 MUST FOLLOW
C                        - OR -
C     START UP RESP. SINGLE CUT SEQUENCE COMMAND
C           PRODUCTION 12 SHOULD , 13 MAY FOLLOW
 1000 IF(LPROD.NE.0)GOTO 4070
      IF(ERRPT.EQ.0)GOTO 3000
 1010 TP=ERRPT+4
      KK=ERRPT
      LPROD=PROD
      GOTO 80
C
C     START UP COMMAND COMPLETE
 1200 IF(LPROD.NE.11)GOTO 4070
 1210 IF(MOD(ARGTOP,2).EQ.0)GOTO 4050
      GOTO 3000
C
C     PARAMETERS FOR FOR SINGLE OR MULTI CUT SEQUENCE MILLING
 1300 IF(LPROD.EQ.11)GOTO 3000
      IF(LPROD.NE.10)GOTO 4070
      GOTO 1010
C
C     MULTI CUT SEQUENCE COMMAND COMPLETE
 1400 IF(LPROD.EQ.0)GOTO 3000
      IF(LPROD.NE.10.AND.LPROD.NE.13)GOTO 4070
      GOTO 3000
C
C     REGIONAL MILLING GCLEAR COMMAND
C
 1600 IEND=KK
      IF(KK.NE.ARGTOP)GOTO 3010
 1610 IEND=0
      DO 1620 I=1,5
 1620 ARG(I)=0
      ARG(PROD-14)=1
      J=3
      GOTO 1850
C
 1650 SNAME=ARGSTK(KK-1)
 1700 NN=PROD-19
      IF(ARG(NN).NE.0)GOTO 4070
      ARG(NN)=1
      J=2
      GOTO 1860
C
 1800 IEND=KK
      IF(KK.NE.ARGTOP)GOTO 3010
 1810 IEND=0
      DO 1820 I=1,5
 1820 ARG(I)=1
      J=2
C   K FOR START=3 , FOR THRU=6 , FOR AWAY=11 , FOR BACK=12
 1850 K=MOD(STACK(1,TP),10)+3
      K=K/3
      IF(LOC(K).NE.0)GOTO 4070
      LOC(K)=1
 1860 IF(ERRPT.EQ.0)GOTO 3010
      TP=TP-J
      KK=KK-J
      GOTO 80
C
C     INTERSECTION OF PLANE AND SCULPTURED SURFACE
C
 2000 K=1
      J=ARGSTK(K)
      IF(NAMTBL(J).EQ.CANON(1).OR.STACK(1,TOP+2).EQ.72)K=2
      ERRPT=1
      IF(STACK(1,TP).EQ.LINE.OR.STACK(1,TP).EQ.PLANE)GOTO 2500
      IF(ARGTOP.LE.K)GOTO 4060
      J=TOP+K+1
      L=J+20
      ERRPT=K-1
      DO 2010 I=J,L
      ERRPT=ERRPT+1
      IF(STACK(1,I).NE.SSURF)GOTO 2020
 2010 CONTINUE
      GOTO 4010
 2020 IF(STACK(1,I).NE.73)GOTO 4030
      J=I+1
      L=TP
      IF(L.LT.J)GOTO 4060
      GOTO 2520
C
 2500 IF(STACK(1,TP-1).NE.73)GOTO 2510
      ARGSTK(ARGTOP-1)=ARGSTK(ARGTOP)
      ARGTOP=ARGTOP-1
      STACK(1,TP-1)=STACK(1,TP)
      TP=TP-1
 2510 IF(ARGTOP.LE.K)GOTO 4060
      ERRPT=ARGTOP-41
      IF(ARGTOP.GT.(K+40))GOTO 4010
      J=TOP+K+1
      ERRPT=K-1
      L=TP-1
 2520 DO 2530 I=J,L
      ERRPT=ERRPT+1
      IF(STACK(1,I).NE.SSURF)GOTO 4030
 2530 CONTINUE
      ERRPT=0
      GOTO 3010
C
C.... AVOIDANCE CONTROL LANGUAGE
C
C.... AVCTRL/ON
C            OFF
 2700 SUB=STACK(1,TOP-1)
      ERRPT=1-ARGTOP
      IF (ARGTOP.GT.1) GOTO 4060
      CALL CALLZZ(SUB)
      CALL ARGCVT(ARGSTK(ARGTOP))
      JNULL=NAME('NULL  ')
      CALL ARGCVT(JNULL)
      CALL ARGCVT(ZEROPT)
      CALL ARGCVT(ZEROPT)
      CALL ARGCVT(ZEROPT)
      CALL ARGCVT(JNULL)
      CALL ARGCVT(ZEROPT)
      GOTO 3200
C
C.... AVCTRL/CUTANG,CONST,GAMMA,RANGE,BLOW,BHIGH
C
 2800 IF (LPROD.NE.0) GOTO 4070
      SUB=STACK(1,TOP-1)
      JNULL=NAME('NULL  ')
      CALL CALLZZ(SUB)
      J=NAME('ON    ')
      CALL ARGCVT(J)
      CALL ARGCVT(ARGSTK(ARGTOP))
      CALL ARGCVT(ARGSTK(ARGTOP-2))
      CALL ARGCVT(ARGSTK(ARGTOP-4))
      CALL ARGCVT(ARGSTK(ARGTOP-5))
      IF (ERRPT.EQ.0) THEN
        CALL ARGCVT(JNULL)
        CALL ARGCVT(ZEROPT)
        GOTO 3200
      ELSE
        TP=ERRPT+4
        KK=ERRPT
        LPROD=PROD
        GOTO 80
      ENDIF
C
C.... AVCTRL/[CUTANG,....,] NORMPS
C                           AXIS
 2900 IF (LPROD.EQ.0) THEN
        SUB=STACK(1,TOP-1)
        JNULL=NAME('NULL  ')
        CALL CALLZZ(SUB)
        J=NAME('ON    ')
        CALL ARGCVT(J)
        CALL ARGCVT(JNULL)
        CALL ARGCVT(ZEROPT)
        CALL ARGCVT(ZEROPT)
        CALL ARGCVT(ZEROPT)
        CALL ARGCVT(ARGSTK(ARGTOP))
      ELSE IF (LPROD.EQ.28) THEN
        CALL ARGCVT(ARGSTK(KK))
      ELSE
        GOTO 4070
      ENDIF
      IF (ERRPT.EQ.0) THEN
        CALL ARGCVT(ZEROPT)
        GOTO 3200
      ELSE
        TP=ERRPT+4
        KK=ERRPT
        LPROD=PROD
        GOTO 80
      ENDIF
C
C.... AVCTRL/[CUTANG,...,] NORMPS,LIMIT,DMAX
C                          AXIS
 2950 IF (LPROD.NE.29) GOTO 4070
      IF (ERRPT.GT.0) GOTO 4010
      CALL ARGCVT(ARGSTK(1))
      GOTO 3200
C
C     GENERATE I.L. OUTPUT
C
 3000 IF(ERRPT.GT.0)GOTO 4010
 3010 TP=ARGTOP+TOP+1
      INDEX=-3
 3020 MM=STACK(1,TP)
      NN=ARGSTK(ARGTOP)
      I=1
      IBUFF(8:15)=BLANK
      CALL BINBCD(MM,IBUFF(4:),NCH)
      WRITE (IBUFF(1:3),'(I3)') NCH
      CALL CONCAT(IBUFF,'.')
      J=NUMB(IBUFF(4:15))+NAMMAX
      CALL OPCODE(MOVE)
      CALL TWOARG(INDEX,DOTTAB)
      CALL TWOARG(DLR,J)
      CALL RLSLIN
      INDEX=INDEX-1
      IF (NN.GT.NAMMAX) THEN
        I=TXXXX(1,MM)
      ELSE
        CLASS=NAMTBL(NN)/MODULO*MODULO
        IF(CLASS.NE.PERMID(1).AND.CLASS.NE.CANON(1))I=TXXXX(1,MM)
      ENDIF
      IF(I.EQ.12)I=1
      IF(I.GT.1)GOTO 3030
      I=1
      CALL OPCODE(MOVE)
      GOTO 3040
 3030 CALL OPCODE(REPL)
      CALL ONEARG(I)
 3040 CALL TWOARG(INDEX,DOTTAB)
      CALL ARGCVT(NN)
      CALL RLSLIN
      INDEX=INDEX-I
      ARGTOP=ARGTOP-1
      TP=TP-1
      IF(ARGTOP.GT.IEND) GOTO 3020
      IBUFF(8:15)=BLANK
      CALL BINBCD(-INDEX,IBUFF(4:),NCH)
      WRITE(IBUFF(1:3),'(I3)') NCH
      CALL CONCAT(IBUFF,'.')
      J=NUMB(IBUFF(4:15))+NAMMAX
      CALL OPCODE(MOVE)
      CALL TWOARG(-2,DOTTAB)
      CALL TWOARG(DLR,J)
      CALL RLSLIN
      CALL CALLZZ(APTXXX(92))
      CALL ARGCVT(STACK(1,TOP-1))
      CALL ARGCVT(SNAME)
C
      NOWRDS=40+INDEX
      IF(NOWRDS .LE.MAXSIZ(2)) GOTO 3100
      IF(NOWRDS .GE.MAXSIZ(1)) GO TO 3090
C
C     REPLACE MAXSIZ(2)
C
      MAXSIZ(2)=NOWRDS
      GOTO 3100
C
C     ADJUST BOTH MAXSIZ(1) AND (2)
C
 3090 MAXSIZ(2)=MAXSIZ(1)
      MAXSIZ(1)=NOWRDS
C
 3100 IF(IEND.EQ.0) GOTO 3200
      CALL RLSLIN
      ARGTOP=KK
      TP=ARGTOP+TOP+1
      IF (PROD.EQ.25) GOTO 1810
      GOTO 1610
 3200 RETURN
C
 4000 ERRPT=1-TOP
 4010 CALL ALARM(2052,-ERRPT,8,'TSSMIL  ')
      GOTO 3100
 4020 ERRPT=1-TOP
 4030 CALL ALARM(2021,-ERRPT,8,'TSSMIL  ')
      GOTO 3100
 4040 ERRPT=MM
      GOTO 4060
 4050 IF(ERRPT.LE.0)ERRPT=1
 4060 CALL ALARM(2001,-ERRPT,8,'TSSMIL  ')
      GOTO 3100
 4070 ERRPT=KK
      GOTO 4060
C
      END
