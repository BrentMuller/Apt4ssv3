**** SOURCE FILE : M0006656.V03   ***
*
C
C              FORTRAN SUBROUTINE MODE
C
C LINKAGE      INTEGER FUNCTION MODE(INDEX)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MATCH
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C                                        SUBROUTINE    TSSMIL
C
      INTEGER FUNCTION MODE(INDEX)
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
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),NUMBER(2),TEMP(2),VBL(2)
C NUMBER:      (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER'
      EQUIVALENCE (NUMBER(1),CODE(27))
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C REAL:        MODE CODE (21) FOR REAL
      EQUIVALENCE (REAL,MODX(21))
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
C ARGUMENTS    INDEX     NAME TABLE (NAMTBL) INDEX OF THE VARIABLE.
C**
C...     IS INDEX THAT OF A NUMBER
C
      IF (INDEX.LE.NAMMAX) GOTO 100
C
C...     YES - MODE = REAL.
C
   10 MODE = REAL
      RETURN
C
C...     SET K TO CLASS OF ITEM.
C
  100 K = MODULO*(NAMTBL(INDEX)/MODULO)
C
C...     IS IT OF CLASS NUMBER
C
      IF (K.EQ.NUMBER(1)) GOTO 10
C
C...     NO. IS IT OF CLASS VBL OR TEMP. IF SO RETURN CORRECT MODE.
C
      IF ((K.NE.VBL(1)).AND.(K.NE.TEMP(1))) GOTO 25
      MODE = NAMTBL(INDEX)-K
C
C...     IS IT A SUBSCRIPT. IF SO RETURN DERIVATIVE MODE.
C
      IF (MODE.GE.MODHLF) MODE = MODE-MODHLF
      RETURN
C
C...     NOT NUMBER, VBL, OR TEMP - SO RETURN ZERO MODE.
C
   25 MODE = 0
      RETURN
       END
