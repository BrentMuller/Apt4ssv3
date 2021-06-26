**** SOURCE FILE : M0006689.V03   ***
*
C
C              FORTRAN SUBROUTINE SUBCOD
C
C LINKAGE      SUBROUTINE SUBCOD (TPX)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          LOGICAL FCT.  IFTMP           SUBROUTINE    RECOG
C          SUBROUTINE    ONEARG
C          SUBROUTINE    OPCODE
C          SUBROUTINE    PUTTMP
C          SUBROUTINE    RLSLIN
C          INTEGER FCT.  GETTMP
C          SUBROUTINE    ALARM
C          INTEGER FCT.  MODE
C          SUBROUTINE    ARGCVT
C
      SUBROUTINE SUBCOD (TPX)
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
C NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION
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
      DIMENSION CODE(150),TEMP(2),VBL(2)
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C
C        6.    GHOST STACK FOR OBJECT TIME TEMPORARY ALLOCATION
C              LENGTH AND CURRENT NUMBER OF ACTIVE TEMPORARY STORAGE
      COMMON/TMP/TXXXX
      DIMENSION TXXXX(2,32)
C
C       15.    ARRAY LIMIT STORAGE
C
      COMMON/SBSCPT/SBSCPT
      DIMENSION SBSCPT(101),RANGE(100)
C RNGPT:       POINTER TO NEXT RANGE ENTRY
      EQUIVALENCE (RNGPT,SBSCPT(1))
C RANGE:       STORAGE FOR APT RESERVE STATEMENT INFORMATION
      EQUIVALENCE (RANGE(1),SBSCPT(2))
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C CVTSUB:      CONTAINS COMMAND CODE (13) FOR CVTSUB COMMAND
      EQUIVALENCE (CVTSUB,IL(13))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C SUBSCR:      MODE CODE (24) FOR SUBSCRIPT
      EQUIVALENCE (SUBSCR,MODX(24))
C
C       22.    MACRO PROCESSING VARIABLES
C
      COMMON/MACXX1/MACXX1
      LOGICAL ILHLT
      DIMENSION MACXX1(71)
C ILHLT:       TRUE IF I.L. SHOULD NOT BE PLACED IN ILFILE
      EQUIVALENCE (ILHLT,MACXX1(14))
C INTMED:      0=NO -,-1=INTERMEDIATE-,+1=FINAL MACRO PROCESSING
      EQUIVALENCE (INTMED,MACXX1(22))
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
C       37.    INCLUSIVE SUBSCRIPT VARIABLES
C
      COMMON/ISSCOM/ISSCOM
      LOGICAL ISSFL
      DIMENSION ISSCOM(9),ISSTRM(2)
C ISSMOD:      MODE OF THE INCLUSIVE SUBSCRIPTED VARIABLE
      EQUIVALENCE (ISSMOD,ISSCOM(5))
C ISSFL:       TRUE DURING INCLUSIVE SUBSCRIPT PROCESSING
      EQUIVALENCE (ISSFL,ISSCOM(6))
C ISSTRM:      SAVES THE STACK TOP ITEMS DURING SUBSCRIPT PROCESSING
      EQUIVALENCE (ISSTRM(1),ISSCOM(8))
C*
C ARGUMENTS    TPX       WORKING STACK (STACK) INDEX WHICH
C                        POINTS TO THE VARIABLE NAME OF A
C**                      SUBSCRIPTED VARIABLE.
C
      external alarm
C     GET RESULT CELL
      RSLT=GETTMP(SUBSCR)
      NAMTBL(RSLT)=TEMP(1)+SUBSCR
C
C     FIND POSITION IN RANGE TABLE
      IF(RNGPT.EQ.1)GO TO 62
      J=RNGPT-2
      N=STACK(1,TPX)
      DO 10 I=1,J,2
      IF(RANGE(I).EQ.N)GO TO 20
   10 CONTINUE
      GO TO 60
C
C     GENERATE CODE
   20 II=STACK(1,TPX+2)
      IF(II.GT.NAMMAX)GO TO 30
      IF(IFTMP(II))CALL PUTTMP(MOD(NAMTBL(II),MODULO))
   30 I=MODE(N)
      IF(I.EQ.0)GO TO 65
      IF(ISSFL)ISSMOD=I
      CALL OPCODE(CVTSUB)
      CALL ARGCVT (RSLT)
      CALL ARGCVT(N)
      CALL ARGCVT (STACK(1,TPX+2))
      CALL ONEARG(TXXXX(1,I))
      CALL RLSLIN
C
C...       MODIFY NAMTBL ENTRY TO MODE + 50
C
      NAMTBL(RSLT) = TEMP(1)+I+MODHLF
C
C     MODIFY STACK
      STACK (1,TPX)=RSLT
   90 RETURN
C
C     ERROR
   60 IF(INTMED)61,62,63
   61 ILHLT=.FALSE.
      CALL ALARM(1013,TPX,8,'SUBCOD  ')
      ILHLT=.TRUE.
      GO TO 72
   63 M=NAMTBL(N)
      J=(M/MODULO)*MODULO
      IF(J.EQ.VBL(1).AND.(M-J).GT.MODHLF)GO TO 20
   62 IERROR=1013
      GO TO 70
   65 IERROR=1014
   70 CALL ALARM(IERROR,TPX,8,'SUBCOD  ')
   72 IF(.NOT.ISSFL) GO TO 90
      STACK(1,TOP)=ISSTRM(1)
      STACK(2,TOP)=ISSTRM(2)
      ISSFL=.FALSE.
      GO TO 90
       END