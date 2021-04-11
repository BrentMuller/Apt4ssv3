**** SOURCE FILE : M0012104.V05   ***
*
C
C              FORTRAN SUBROUTINE GOLOFT
C
C LINKAGE      SUBROUTINE GOLOFT
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
      SUBROUTINE GOLOFT
C
      IMPLICIT INTEGER (A-Z)
C
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMMAX:      NAMTBL INDEX OF THE PART PROGRAM NAME SECTION
C CNAMTB:      NAME TABLE OR DICTIONARY
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
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
C REAL:        MODE CODE (21) FOR A SCALAR
      EQUIVALENCE (REAL,MODX(21))
C SCURV:       MODE CODE (30) FOR SCULPTURED CURVE
      EQUIVALENCE (SCURV,MODX(30))
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
      DIMENSION LENGTH(42)
      CHARACTER IBUFF*15,BLANK*8
      CHARACTER*6 PLFT,UC,VC,FLW
      DATA PLFT,UC,VC,FLW/'PLOTFT','UCONST','VCONST','FLOW  '/
      DATA BLANK/'        '/
      DATA LENGTH/3,7,6,6,5,3,4,7,5,6,3,5,4,2,3,2,8,6,6,6,4,
     *            4,4,1,7,5,5,5,3,8,6,7,5,7,5,6,4,6,4,5,3,2/
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
      IF(CLASS.NE.PERMID(1))GOTO 10
      NN=50
      MM=MM+NN
      GOTO 30
   10 IF(CLASS.EQ.VBL(1).OR.CLASS.EQ.TEMP(1))GOTO 30
      IF(CLASS.NE.NUMBER(1))GOTO 4030
   20 MM=REAL
   30 TP=TP+1
      STACK(1,TP)=MM-NN
   40 STACK(2,TP)=PMIDTB(MM)
C
C
C     SEARCH FOR THE PRODUCTION NUMBER AND BRANCH
C
      KK=ARGTOP
      LPROD=0
      FMT=1
      NN=GEOLOC(48)
   50 ERRPT=KK
      TP2=TP*2
      PROD=SEARCH(STACK,TP2,GEOMTB(NN),ERRPT)
C
      IF(PROD.EQ.200)GOTO 4050
      IF((KK-ERRPT).NE.LENGTH(PROD))GOTO 4090
C
C                   PRODUCTION NUMBERS
C             1    2    3    4    5    6    7    8    9   10   11   12
      GOTO( 100, 200, 200, 200, 200, 200, 200, 300, 300, 300, 300, 300,
C            13   14   15   16   17   18   19   20   21   22   23   24
     *      300, 300, 300, 400, 500, 400, 500, 500, 400, 400, 500, 600,
C            25   26   27   28   29   30   31   32   33   34   35   36
     *      600, 600, 600, 600, 600, 700, 700, 800, 800, 700, 700, 800,
C            37   38   39   40   41   42
     *      800, 900, 900, 900, 900, 900),PROD
C
C     GOLOFT/SSURF,UCONST,U,.............
C
  100 FMT=6
      IF(CNAMTB(STACK(1,TOP-1)).NE.PLFT)GOTO 110
      FMT=3
      STACK(2,TP)=PMIDTB(SCURV)
  110 IF(CNAMTB(ARGSTK(ARGTOP-1)).EQ.VC)FMT=FMT+1
      LPROD=1
      GOTO 2900
C
  200 IF(FMT.LT.6)GOTO 4100
      IF(LPROD.EQ.0.OR.LPROD.GE.PROD)GOTO 4070
      LPROD=7
      GOTO 2900
C
  300 IF(FMT.LT.6)GOTO 4100
      IF(LPROD.EQ.0.OR.LPROD.GE.PROD)GOTO 4070
      GOTO 3000
C                                  FLOW
C     PLOTFT/SCURV,START,S,.......,PARAM,.....
C
  400 JJ=1
      GOTO 510
C
  500 JJ=3
  510 IF(CNAMTB(STACK(1,TOP-1)).NE.PLFT)GOTO 4100
      IF(CNAMTB(ARGSTK(JJ)).EQ.FLW)FMT=2
      GOTO 3000
C
C     PLOTFT/SSURF,UCONST,U,START,S,.......
C     PLOTFT/SCURV,START,S,................
C
  600 GOTO 3000
C
C     PLOTFT/SSURF,GRID,...................
C
  700 JJ=4
      GOTO 810
  800 JJ=3
  810 KK=ARGTOP-2
      IF(CNAMTB(ARGSTK(KK)).NE.UC)GOTO 4080
      KK=ARGTOP-JJ
      IF(CNAMTB(ARGSTK(KK)).NE.VC)GOTO 4080
  900 FMT=5
      IF(CNAMTB(STACK(1,TOP-1)).NE.PLFT)GOTO 4100
      GOTO 3000
C
C     REDUCE STACK BY I
C
 2900 IF(ERRPT.EQ.0)GOTO 3010
      JJ=LENGTH(PROD)-1
      STACK(2,TP-JJ)=STACK(2,TP)
      TP=TP-JJ
      KK=KK-JJ
      GOTO 50
C
C     GENERATE I.L. OUTPUT
C
 3000 IF(ERRPT.GT.0)GOTO 4010
 3010 TP=ARGTOP+TOP+1
      INDEX=-3
      JJ=ARGSTK(ARGTOP)
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
      IF(NAMTBL(NN)/MODULO*MODULO.NE.PERMID(1))I=TXXXX(1,MM)
      ENDIF
      IF(I.EQ.12)I=1
      IF(I.GT.1)GOTO 3030
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
      IF(ARGTOP.GT.0) GOTO 3020
      DO 3050 KK=1,2
      IBUFF(8:15)=BLANK
      CALL BINBCD(FMT,IBUFF(4:),NCH)
      WRITE (IBUFF(1:3),'(I3)') NCH
      CALL CONCAT(IBUFF,'.')
      J=NUMB(IBUFF(4:15))+NAMMAX
      CALL OPCODE(MOVE)
      CALL TWOARG(-KK,DOTTAB)
      CALL TWOARG(DLR,J)
      CALL RLSLIN
 3050 FMT=-INDEX
      CALL CALLZZ(APTXXX(92))
      CALL ARGCVT(STACK(1,TOP-1))
      CALL ARGCVT(JJ)
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
 3100 RETURN
C
 4000 ERRPT=1-TOP
 4010 CALL ALARM(2052,-ERRPT,8,'GOLOFT  ')
      GOTO 3100
 4030 CALL ALARM(2021,-ERRPT,8,'GOLOFT  ')
      GOTO 3100
 4050 IF(ERRPT.LE.0)ERRPT=1
 4060 CALL ALARM(2001,-ERRPT,8,'GOLOFT  ')
      GOTO 3100
 4070 ERRPT=KK-1
      GOTO 4060
 4080 ERRPT=KK
      GOTO 4060
 4090 ERRPT=ERRPT+1
      GOTO 4010
 4100 ERRPT=1-TOP
      GOTO 4060
C
      END