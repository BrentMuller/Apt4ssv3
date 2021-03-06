**** SOURCE FILE : M0006635.W01   ***
*
C
C              FORTRAN SUBROUTINE GOPAT
C
C LINKAGE      SUBROUTINE GOPAT
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    CALLZZ          SUBROUTINE    PRO026
C          SUBROUTINE    ALARM
C          INTEGER FCT.  NAME
C          SUBROUTINE    OPCODE
C          SUBROUTINE    ARGCVT
C          SUBROUTINE    RESRVZ
C          SUBROUTINE    RLSLIN
C          INTEGER FCT.  SEARCH
C          SUBROUTINE    TWOARG
C
      SUBROUTINE GOPAT
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION
C
C        2.    STACK AND POINTER STORAGE
C
      COMMON/STKLST/STKLST
      DIMENSION STKLST(300),ARGSTK(99)
C ARGTOP:      POINTER TO LAST ARGSTK ENTRY
      EQUIVALENCE (ARGTOP,STKLST(2))
C ARGSTK:      ARGUMENT STACK
      EQUIVALENCE (ARGSTK(1),STKLST(202))
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),NUMBER(2),TEMP(2),PERMID(2),VBL(2),IDENT(2)
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
C
C        9.    NAME TABLE POINTERS TO NUMBERS
C
      COMMON/NUMPTR/NUMPTR
      DIMENSION NUMPTR(12),ZERO(1)
C ZERO:        NAMTBL POINTER TO '0     '
      EQUIVALENCE (ZERO(1),NUMPTR(1))
C ZEROPT:      NAMTBL POINTER TO '0.    '
      EQUIVALENCE (ZEROPT,NUMPTR(2))
C ONE:         NAMTBL POINTER TO '1     '
      EQUIVALENCE (ONE,NUMPTR(3))
C
C       10.    TABLE STORAGE FOR GEOMETRIC FUNCTION PROCESSOR
C
      INCLUDE 'GMTY.INC'
C GEOLOC:      GEOMETRIC PRODUCTION STARTING INDEX IN GEOMTB
C PMIDTB:      INTERNAL BIT REPRESENTATIONS FOR EACH ELEMENT OF GEOMTB
C GEOMTB:      GEOMETRIC FORMAT PRODUCTIONS ARRANGED BY SURFACE TYPE
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C MOVE:        CONTAINS COMMAND CODE (19) FOR MOVE COMMAND
      EQUIVALENCE (MOVE,IL(19))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C REAL:        MODE CODE (24) FOR A SCALAR
      EQUIVALENCE (REAL,MODX(21))
C PATERN:      MODE CODE (26) FOR PATTERN
      EQUIVALENCE (PATERN,MODX(26))
C
C       27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION OPMOD(6)
C QUIDLR:      CONTAINS OPERAND TYPE CODE 5
      EQUIVALENCE (QUIDLR,OPMOD(6))
C
C       28.    OPERAND MODIFIERS
C
      COMMON/SUBLST/SUBLST
      DIMENSION SUBLST(136),APTXXX(120)
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
C PURPOSE      TO VALIDATE GO/PATERN STATEMENTS AND GENERATE
C              APPROPRIATE INTERMEDIATE LANGUAGE.
C
      DIMENSION BIGSTK(10),NUMREC(5),OMTLST(18),AVDLST(18)
      LOGICAL LOMIT,LRETAI
      CHARACTER*6 HDOLSC,HDOLPC
      DATA NUMREC/1,5,4,3,2/
      DATA KOMIT /64/, KRETAI /65/, KINVER /35/, KZIGZA /61/
      DATA HDOLSC,HDOLPC /'$SCRTH','$PCRTH'/
      external alarm
C**
C......             INITIALIZE
C
      IARG1=ZERO(1)
      IARG2=ZERO(1)
      IO=0
      IA=0
      KMOVO=-1
      KMOVA=-1
      KSCRTH=NAME(HDOLSC)
      KPCRTH=NAME(HDOLPC)
      ASSIGN 15 TO IEND
C                             POINTER FOR ARGSTK, 1 BELOW PATERN
      IARG=ARGTOP-1
C                             POINTER FOR BIGSTK
      IBIG=5
C                             FLAGS FOR OMIT AND RETAIN
      LOMIT=.FALSE.
      LRETAI=.FALSE.
C                             NUMBER OF ARGS TO DELETE FROM BIGSTK
      IGET=5
      IF(IARG.EQ.0)GO TO 40
C
C......             SETUP BIGSTK CORRESPONDING TO TOP 5 ARGUMENTS OF
C......             ARGSTK, IN FORMAT TO BE RECOGNIZED BY PATERN
C......             GEOMETRIC PRODUCTIONS
C
      ASSIGN 10 TO ISETUP
      GO TO 1000
C
C......             LOOK FOR PATERN
C
   10 J=GEOLOC(PATERN)
      ERRPT=IBIG
      KSERCH=SEARCH(BIGSTK,10,GEOMTB(J),ERRPT)
C......             ERROR IF NO MATCH ON CORRECT TYPE
C
      IF(KSERCH.LE.12 .OR. KSERCH.GE.18)GO TO 1258
C
C......             DETERMINE NUMBER OF ELEMENTS RECOGNIZED
C
      I=KSERCH-12
      IGET=NUMREC(I)
C
      NAMX=BIGSTK(9)
      IF(NAMX.GT.NAMMAX)GO TO 12
      KMODE=MOD(NAMTBL(NAMX),MODULO)
C
C                   BRANCH TO PROCESS RECOGNIZED ELEMENTS
C
   12 GO TO(100,210,300,200,300),I
C
C                   INVERS OR ZIGZAG
C
  100 IF(KMODE.EQ.KINVER)IARG1=ONE
      IF(KMODE.EQ.KZIGZA)IARG2=ONE
      GO TO 15
C
C                   AVOID
C
  200 AVDSAV=BIGSTK(7)
  210 AVDLST(IA+1)=BIGSTK(7)
      AVDLST(IA+2)=BIGSTK(5)
      IF(KSERCH.NE.14)GO TO 215
      AVDLST(IA+3)=BIGSTK(1)
      GO TO 220
  215 AVDLST(IA+3)=ZEROPT
  220 IA=IA+3
      IF(IA.LT.18)GO TO 15
C                   IF NOT ALREADY DONE,DECLARE ARRAY OF SCRATCH
C                   STORAGE IN PART PROGRAM.  MOVE AVOID INFORMATION
C                   INTO LOCATIONS 1 THRU 102 OF THIS ARRAY.
  250 IF(NAMTBL(KSCRTH).NE.0)GO TO 255
      NAMTBL(KSCRTH)=VBL(1)
      CALL RESRVZ(KSCRTH,0,102,1)
  255 IF((KMOVA-IA).LT.(-102))GO TO 2010
      CALL OPCODE(MOVE)
      CALL TWOARG(KMOVA,KSCRTH)
      DO 260 I=1,IA
  260 CALL ARGCVT(AVDLST(I))
      CALL RLSLIN
      KMOVA=KMOVA-IA
      IA=0
      GO TO IEND,(15,35,40)
C
C                   OMIT OR RETAIN
C
  300 LOMIT=KMODE.EQ.KOMIT. OR. LOMIT
      LRETAI=KMODE.EQ.KRETAI. OR. LRETAI
      IF(LOMIT.AND.LRETAI)GO TO 2000
      OMTLST(IO+1)=BIGSTK(7)
      IF(KSERCH.NE.15)GO TO 315
      OMTLST(IO+2)=BIGSTK(3)
      GO TO 320
  315 OMTLST(IO+2)=OMTLST(IO+1)
  320 IO=IO+2
      IF(IO.LT.18)GO TO 15
C                   IF NOT ALREADY DONE, DECLARE ARRAY OF SCRATCH
C                   STORAGE IN PART PROGRAM.  MOVE OMIT OR RETAIN
C                   INFORMATION INTO LOCATIONS 1 THRU 98 OF THIS ARRAY.
  350 IF(NAMTBL(KPCRTH).NE.0)GO TO 355
      NAMTBL(KPCRTH)=VBL(1)
      CALL RESRVZ(KPCRTH,0,98,1)
  355 IF((KMOVO-IO).LT.(-98))GO TO 2010
      CALL OPCODE(MOVE)
      CALL TWOARG(KMOVO,KPCRTH)
      DO 360 I=1,IO
  360 CALL ARGCVT(OMTLST(I))
      CALL RLSLIN
      KMOVO=KMOVO-IO
      IO=0
      GO TO IEND,(15,35,40)
C
C                   BRANCH IF ARGSTK ALL EXAMINED
C
   15 IF(IARG+IBIG-IGET.EQ.0)GO TO 30
C
C                   RESET BIGSTK
C
      ASSIGN 20 TO ISETUP
      GO TO 1000
C
C                   LOOP IF REAL LIST CANNOT FOLLOW
C
   20 IF(KSERCH.LE.15)GO TO 10
C
C                   PROCESS ELEMENT OF REAL LIST IF PRESENT
C
      NAMX=BIGSTK(9)
      IGET=1
      IF(NAMX.GT.NAMMAX)GO TO 17
      KCLASS=NAMTBL(NAMX)/MODULO
      IF(KCLASS.EQ.NUMBER(1))GO TO 17
      KMODE=MOD(NAMTBL(NAMX),MODHLF)
      IF(KMODE.NE.REAL)GO TO 10
   17 IF(KSERCH.EQ.17)GO TO 18
C                   ELEMENT OF AVOID LIST
      AVDLST(IA+1)=AVDSAV
      AVDLST(IA+2)=BIGSTK(9)
      GO TO 215
C                   ELEMENT OF OMIT OR RETAIN LIST
   18 OMTLST(IO+1)=BIGSTK(9)
      GO TO 315
C
C                   MOVE ANY ELEMENTS REMAINING IN OMTLST OR
C                   AVDLST TO $SCRTH
C
   30 IF(IO.EQ.0)GO TO 35
      ASSIGN 35 TO IEND
      GO TO 350
   35 IF(IA.EQ.0)GO TO 40
      ASSIGN 40 TO IEND
      GO TO 250
C                   DETERMINE NUMBER OF TWO-ELEMENT ENTRIES IN
C                   OMIT/RETAIN TABLE, OMTLST.
C                   IF RETAIN, SET NUMBER NEGATIVE.
   40 IARG3=-(KMOVO+1)/2
      IF(LRETAI)IARG3=IARG3+1000
C                   DETERMINE NUMBER OF THREE-ELEMENT ENTRIES
C                   IN AVOID TABLE, AVDLST.
      IARG4=-(KMOVA+1)/3
C                   GENERATE CALL TO XECUTION SUBROUTINE GOTOPN
   50 CALL CALLZZ(APTXXX(99))
      CALL ARGCVT(ARGSTK(ARGTOP))
      CALL ARGCVT(IARG1)
      CALL ARGCVT(IARG2)
      CALL TWOARG(QUIDLR,IARG3)
      CALL TWOARG(QUIDLR,IARG4)
      IF(NAMTBL(KPCRTH).EQ.0)GO TO 52
      CALL TWOARG(0,KPCRTH)
      GO TO 53
   52 CALL ARGCVT(ZEROPT)
   53 IF(NAMTBL(KSCRTH).EQ.0)GO TO 54
      CALL TWOARG(0,KSCRTH)
      GO TO 60
   54 CALL ARGCVT(ZEROPT)
   60 CALL RLSLIN
C
      RETURN
C-----------------------------------------------------------------------
C
C     PURPOSE       TO MOVE INTERNAL BIT CONFIGURATIONS CORRESPONDING TO
C                   ELEMENTS OF ARGSTK INTO BIGSTK, FOR RECOGNITION BY
C                   PATERN GEOMETRIC PRODUCTIONS
C
C     ARGUMENTS     IARG      INDEX OF NEXT ELEMENT OF ARGSTK.
C                   IGET      NUMBER OF RECOGNIZED ELEMENTS TO BE POPPED
C                             FROM BIGSTK.
C                   ISETUP    RETURN INDEX.
C
C                             POP RECOGNIZED ELEMENTS
 1000 IIN=10
      IIOUT=10-2*IGET
      IBIG=IBIG-IGET
 1005 IF (IIOUT.EQ.0) GO TO 1010
      BIGSTK(IIN)=BIGSTK(IIOUT)
      BIGSTK(IIN-1)=BIGSTK(IIOUT-1)
      IIN=IIN-2
      IIOUT=IIOUT-2
      GO TO 1005
C                             CONVERT STACK ELEMENTS
 1010 DO 1250 I=1,IGET
      IF(IARG.NE.0)GO TO 1200
      J=10-2*IBIG
      BIGSTK(J)=-1
      GO TO 1255
 1200 NAMX=ARGSTK(IARG)
      ERRPT=IARG
      IF(NAMX.GT.NAMMAX)GO TO 1205
      KCLASS=MODULO*(NAMTBL(NAMX)/MODULO)
      KMODE =NAMTBL(NAMX)-KCLASS
      IF(KMODE.GE.MODHLF) KMODE=KMODE-MODHLF
      IF(KMODE.EQ.0)GOTO 1260
      IF (KCLASS.EQ.VBL(1) .OR. KCLASS.EQ.TEMP(1)) GO TO 1220
     0IF (KCLASS.EQ.IDENT(1)) NAMTBL(NAMX)=NAMTBL(NAMX)-IDENT(1)
     1                                      +PERMID(1)
      IF (KCLASS.EQ.IDENT(1).OR.KCLASS.EQ.PERMID(1)) GO TO 1210
      IF (KCLASS.NE.NUMBER(1)) GO TO 1260
 1205 KMODE=REAL
      GO TO 1220
 1210 KMODE=KMODE+50
 1220 J=10-2*IBIG
      BIGSTK(J)=PMIDTB(KMODE)
      BIGSTK(J-1)=NAMX
      IARG=IARG-1
      IBIG=IBIG+1
 1250 CONTINUE
C                             RETURN
 1255 GO TO ISETUP,(10,20)
C                             IMPROPER ARGUMENT IN GOTO/PATERN STATEMENT
 1258 ERRPT=MAX(IARG+1,IARG+ERRPT)
 1260 IERROR=2036
      GO TO 3000
C                             BOTH OMIT AND RETAIN SPECIFIED IN GOTO/
C                             PATERN STATEMENT
 2000 IERROR=2037
      ERRPT=IARG+IBIG
      GO TO 3000
C                   TOO MANY OMIT, RETAIN OR AVOID POINTS IN GOTO/
C                             PATERN STATEMENT
 2010 IERROR=2038
      ERRPT=IARG+1
 3000 CALL ALARM(IERROR,-ERRPT,8,'GOPAT   ')
      RETURN
C
C
      END
