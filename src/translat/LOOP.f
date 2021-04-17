**** SOURCE FILE : M0006648.V03   ***
*
C
C              FORTRAN SUBROUTINE LOOP
C
C LINKAGE      SUBROUTINE  LOOP
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    INPUT
C          SUBROUTINE    ARGCVT          SUBROUTINE    RECOG
C          SUBROUTINE    MACLBL          SUBROUTINE    PRO026
C          SUBROUTINE    ONEARG
C          SUBROUTINE    OPCODE
C          INTEGER FCT.  GETTMP
C          INTEGER FCT.  MODE
C          SUBROUTINE    REPLAC
C          SUBROUTINE    RLSLIN
C          SUBROUTINE    LABELZ
C          SUBROUTINE    SETCHR
C
      SUBROUTINE  LOOP
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION
C NAMTBL:      NAME TABLE OR DICTIONARY
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
      DIMENSION CODE(150),COMMA(2),NUMBER(2),TEMP(2),LABEL(2),IMPLAB(2)
     *         ,VBL(2),IDENT(2)
C COMMA:       (1)=CODE CLASS  1000,(2)=NAMTBL INDEX OF ',     '
      EQUIVALENCE (COMMA(1),CODE(1))
C NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER'
      EQUIVALENCE (NUMBER(1),CODE(27))
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL '
      EQUIVALENCE (LABEL(1),CODE(43))
C IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB'
      EQUIVALENCE (IMPLAB(1),CODE(45))
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C IDENT:       (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT '
      EQUIVALENCE (IDENT(1),CODE(69))
C
C        4.    PRODUCTION TABLE
C
      COMMON/SRCTBL/SRCTBL
      DIMENSION SRCTBL(501),META(50)
C META:        END OF CHARACTER CONCATENATION AND STRING PRODUCTION
      EQUIVALENCE (META(1),SRCTBL(3))
C
C        9.    NAME TABLE POINTERS TO NUMBERS
C
      COMMON/NUMPTR/NUMPTR
      DIMENSION NUMPTR(12)
C ONEPT:       NAMTBL POINTER TO '1.    '
      EQUIVALENCE (ONEPT,NUMPTR(4))
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C FADD:        CONTAINS COMMAND CODE ( 1) FOR FADD COMMAND
      EQUIVALENCE (FADD,IL(1))
C FSUB:        CONTAINS COMMAND CODE ( 2) FOR FSUB COMMAND
      EQUIVALENCE (FSUB,IL(2))
C FMPY:        CONTAINS COMMAND CODE ( 3) FOR FMPY COMMAND
      EQUIVALENCE (FMPY,IL(3))
C CONJMP:      CONTAINS COMMAND CODE (11) FOR CONJMP COMMAND
      EQUIVALENCE (CONJMP,IL(11))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C REAL:        MODE CODE (21) FOR REAL
      EQUIVALENCE (REAL,MODX(21))
C
C       22.    MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      DIMENSION MACXX1(71)
      LOGICAL FINMAC
C FINMAC:      TRUE DURING FINAL MACRO PROCESSING
      EQUIVALENCE (FINMAC,MACXX1(24))
C WHCHMN:      EQUAL TO NUMBER OF CURRENT MACRO BEING PROCESSED
      EQUIVALENCE (WHCHMN,MACXX1(63))
C
C       29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULI
      DIMENSION MODULI(2)
C MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS
      EQUIVALENCE (MODULO,MODULI(1))
C
C       40.    PARAMETERS REQUIRED BY SUPERVISOR
C
      COMMON/SUPER/SUPER
      LOGICAL FINI
      DIMENSION SUPER(36)
C FINI:        FLAG ON INDICATES A FINI CARD HAS BEEN READ
      EQUIVALENCE (FINI,SUPER(7))
C
C       43.    DO LOOP CONTROL VALUES
C
      COMMON/DOLOOP/DOLOOP
      LOGICAL DOFLAG
      DIMENSION DOLOOP(8)
C ABSDO:       LOOP NUMBER FOR LABEL CREATION
      EQUIVALENCE (ABSDO,DOLOOP(2))
C RELDO:       CURRENTLY NESTED DO LOOPS
      EQUIVALENCE (RELDO,DOLOOP(3))
C DONEST:      CURRENTLY NESTED DO LOOPS
      EQUIVALENCE (DONEST,DOLOOP(4))
C DOMAX:       MAXIMAL NESTING OF LOOPS
      EQUIVALENCE (DOMAX,DOLOOP(5))
C DOJUMP:      VBL FOR COMPUTED GOTO AT LOOP PROCESSING
      EQUIVALENCE (DOJUMP,DOLOOP(6))
C DOFLAG:      FLAG IS ON DURING OPENED LOOP
      EQUIVALENCE (DOFLAG,DOLOOP(7))
C*
C PURPOSE      DISSECTS AND PROCESSES FORTRAN-LIKE PROGRAMMED DO-LOOPS
C              FOR I.L.-OUTPUT BY SETTING THE START-VALUE, ADDING WITH
C              RETURN-POINTER AND IF-SCANNING ON LOOP-END-VALUE WITH
C              RETURN OR BRANCHING OUT OF THE LOOP RESPECTIVELY.
C
C
C INPUT                                DO / LABEL, I1 = I2, I3, I4
C                              LABEL ) CONTIN
C                        OR    LABEL ) APT - STATEMENT
C
C              DOJUMP         1        DO STATEMENT PROGRAMMED
C                             2     LABEL STATEMENT PROGRAMMED
C                             3     PRODUCTION OF THE LOOP-END
C                             4     TERMAC STATEMENT
C                             5     FINI   STATEMENT
C              LABSAV(J,K)          NAMTBL ADDRESS
C                     J       1     I1
C                             2     I2
C                             3     I3
C                             4     I4
C                             5     PROGRAMMED LABEL
C                             6     PRODUCED LABEL
C                             7     VALUE FOR PRODUCING LABEL
C
C
      external alarm
      DIMENSION LABSAV(7,10),ISTCK(5)
      DATA ISTCK/7,5,3,1,9/
C**
      GOTO(5,170,100,250,300),DOJUMP
      GOTO 999
C
C     START OF DO-LOOP; INPUT STATEMENT DO / LAB , I1 = I2 , I3 (, I4)
C
C     ERROR-CONTROL
C
    5 IF(ARGTOP.GT.0)GOTO 835
      IF(TOP.EQ.DOMAX)GOTO 10
      TOP=DOMAX
      STACK(1,TOP)=STACK(1,TOP-2)
      STACK(2,TOP)=STACK(2,TOP-2)
      CALL SETCHR(TOP-2,COMMA)
      STACK(1,TOP-1)=ONEPT
      L=NUMBER(1)/MODULO
      STACK(2,TOP-1)=META(L)
C
C     PROVIDING AN ADDRESS ON TEMPORARY INPUT
C
   10 LL=TOP
      ABSDO=ABSDO+1
      DO 29 J=2,4
      M=LL-ISTCK(J)
      IF (STACK(1,M).GT.NAMMAX) GOTO 29
      KK=MODULO*(NAMTBL(STACK(1,M))/MODULO)
      IF(KK.NE.TEMP(1))GOTO 29
      K=STACK(1,M)
      KK=20000+998*ABSDO-J
      L=WHCHMN
      IF(L.EQ.0)L=51
      CALL MACLBL(KK,-L,K)
      NAMTBL(K)=IDENT(1)
      KK=STACK(1,M-2)
      MM=STACK(2,M-2)
      TOP=M+1
      STACK(1,M-2)=K
      CALL REPLAC
      STACK(1,M)=STACK(1,M-2)
      STACK(2,M)=META(NAMTBL(STACK(1,M))/MODULO)
      STACK(1,M-2)=KK
      STACK(2,M-2)=MM
   29 CONTINUE
      TOP=LL
C
C     STORING THE DO-VALUES IN LABSAV; CONTROL ON MULTIPLY DEFINED
C     VARIABLES IN INTERLEAVINGS.
C
      RELDO=RELDO+1
      IF(RELDO.GT.DONEST)GOTO 820
      DO 20 K=1,5
   20 LABSAV(K,RELDO)=STACK(1,(TOP-ISTCK(K)))
C
      IF(RELDO.LE.1)GOTO 23
      KK=RELDO-1
      DO 22 K=1,KK
      IF(LABSAV(1,K).EQ.LABSAV(1,RELDO))GOTO 830
   22 CONTINUE
C
C     WORKING UP OF I1=I2-I4
C
   23 DO 25 K=2,4
   25 IF(MODE(LABSAV(K,RELDO)).NE.REAL) CALL ALARM(1008,TOP-9+2*K,8,
     /'LOOP    ')
      RSLT=GETTMP(REAL)
      CALL OPCODE(FSUB)
      CALL ARGCVT(RSLT)
      CALL ARGCVT(LABSAV(2,RELDO))
      CALL ARGCVT(LABSAV(4,RELDO))
      CALL RLSLIN
      STACK(1,TOP-3)=LABSAV(1,RELDO)
      STACK(1,TOP-1)=RSLT
      CALL REPLAC
C
C     WORKING UP OF LABEL)
C
      KK=20000+998*ABSDO
      LABSAV(7,RELDO)=KK+1
      L=WHCHMN
      IF(L.EQ.0)L=51
      CALL MACLBL(KK,-L,K)
      LABSAV(6,RELDO)=K
      IF((.NOT.FINMAC).AND.(WHCHMN.NE.0))GOTO 40
      NAMTBL(K)=LABEL(1)+WHCHMN
   30 CALL LABELZ(K)
      GOTO 50
   40 NAMTBL(K)=IMPLAB(1)+WHCHMN
      GOTO 30
C
C     WORKING UP OF I1 = I1 + I4
C
   50 CALL OPCODE(FADD)
      CALL ARGCVT(LABSAV(1,RELDO))
      CALL ARGCVT(LABSAV(1,RELDO))
      CALL ARGCVT(LABSAV(4,RELDO))
      CALL RLSLIN
      GOTO 999
C
C     END OF A DO-LOOPS;  INPUT: LABEL)CONTIN  RESP. STATEMENT
C
  100 IF(.NOT.DOFLAG)GOTO 999
      DOFLAG=.FALSE.
C
C     WORKING UP OF TEMP = I3+I1
C
      RSLT=GETTMP(REAL)
      DO 160 J=1,III
      CALL OPCODE(FSUB)
      CALL ARGCVT(RSLT)
      CALL ARGCVT(LABSAV(3,RELDO))
      CALL ARGCVT(LABSAV(1,RELDO))
      CALL RLSLIN
C
C     WORKING UP OF TEMP = TEMP -I4
C
      CALL OPCODE(FSUB)
      CALL ARGCVT(RSLT)
      CALL ARGCVT(RSLT)
      CALL ARGCVT(LABSAV(4,RELDO))
      CALL RLSLIN
C
C     WORKING UP OF TEMP = I4 * TEMP
C
      CALL OPCODE(FMPY)
      CALL ARGCVT(RSLT)
      CALL ARGCVT(LABSAV(4,RELDO))
      CALL ARGCVT(RSLT)
      CALL RLSLIN
C
C     WORKING UP OF IF(TEMP) LAB1,LAB2,LAB2
C
      CALL OPCODE(CONJMP)
      CALL ARGCVT(RSLT)
      KK=LABSAV(7,RELDO)
      L=WHCHMN
      IF(L.EQ.0)L=51
      CALL MACLBL(KK,-L,K)
      IF((.NOT.FINMAC).AND.(WHCHMN.NE.0))GOTO 140
      NAMTBL(K)=LABEL(1)+WHCHMN
      GOTO 150
C
C     WORKING UP OF IF-LABELS
C
  140 NAMTBL(K)=IMPLAB(1)+WHCHMN
  150 CALL ONEARG(K)
      CALL ONEARG(LABSAV(6,RELDO))
      CALL ONEARG(LABSAV(6,RELDO))
      CALL RLSLIN
      CALL LABELZ(K)
  160 RELDO=RELDO-1
      GOTO 999
C
C     CHECK IF LABEL BELONGS TO A DO-LOOP
C
  170 IF(RELDO.LE.0) GOTO 999
  171 III=0
      DO 172 L=1,RELDO
      K=RELDO+1-L
      IF(LABSAV(5,K).EQ.STACK(1,TOP-1))III=III+1
  172 CONTINUE
      IF(III.EQ.0)GOTO 999
      DO 175 L=1,III
      K=RELDO+1-L
      IF(LABSAV(5,K).NE.STACK(1,TOP-1))GOTO 805
  175 CONTINUE
  177 DOFLAG=.TRUE.
      GOTO 999
C
C     MACRO HAS BEEN COMPLETED
C
  250 IF(.NOT.FINI)GOTO 999
      ABSDO=0
      GOTO 310
C
C     FINI HAS BEEN READ IN
  300 ABSDO=0
  310 IF(RELDO.GT.0)GOTO 810
C
  999 RETURN
C
C     ERROR-MESSAGES
C
C     ERROR 1037   ON FINI OR TERMAC OPEN LOOP
  810 CALL ALARM(1037,0,8,'LOOP    ')
      RELDO=0
      GOTO 999
C     ERROR 1038   TOO MANY DO'S NESTED (MORE THAN 10)
  820 CALL ALARM(1038,2,8,'LOOP    ')
  825 RELDO=RELDO-1
      GOTO 999
C     ERROR 1039   WRONGLY NESTED DO
  805 CALL ALARM(1039,TOP-1,8,'LOOP    ')
      GOTO 177
C     ERROR 1040   DO-VARIABLE IDENTICAL
  830 CALL ALARM(1040,TOP-7,8,'LOOP    ')
      GOTO 825
C     ERROR 1036   DO-ARGUMENT WITHOUT VALUE-ASSIGNEMENT
  835 IF(TOP.EQ.DOMAX)GOTO 840
      CALL ALARM(1036,-ARGTOP,8,'LOOP    ')
      GOTO 999
C     ERROR 2052   TOO MANY DO-ARGUMENTS
  840 CALL ALARM(2052,-ARGTOP,8,'LOOP    ')
      GOTO 10
C
      END