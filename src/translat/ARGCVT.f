**** SOURCE FILE : M0006616.V03   ***
*
C
C              FORTRAN SUBROUTINE ARGCVT
C
C LINKAGE      SUBROUTINE ARGCVT(INDEX)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    TWOARG          SUBROUTINE    ARGGEN
C                                        SUBROUTINE    ASNADZ
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    GOPAT
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    ISSCOD
C                                        SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO021
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REFGEN
C                                        SUBROUTINE    REFREF
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C                                        SUBROUTINE    TSSMIL
C
      SUBROUTINE ARGCVT(INDEX)
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
      DIMENSION CODE(150),TEMP(2),LABEL(2),IMPLAB(2),VBL(2)
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C LABEL:       (1)=CODE CLASS 22000,(2)=NAMTBL INDEX OF 'LABEL '
      EQUIVALENCE (LABEL(1),CODE(43))
C IMPLAB:      (1)=CODE CLASS 23000,(2)=NAMTBL INDEX OF 'IMPLAB'
      EQUIVALENCE (IMPLAB(1),CODE(45))
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C
C       27.    OPERAND MODIFIERS
C
      COMMON/OPMOD/OPMOD
      DIMENSION OPMOD(6)
C NOUGHT:      CONTAINS OPERAND TYPE 0
      EQUIVALENCE (NOUGHT,OPMOD(1))
C DLR:         CONTAINS OPERAND TYPE CODE 1
      EQUIVALENCE (DLR,OPMOD(2))
C DBLDLR:      CONTAINS OPERAND TYPE CODE 2
      EQUIVALENCE (DBLDLR,OPMOD(3))
C TRPDLR:      CONTAINS OPERAND TYPE CODE 3
      EQUIVALENCE (TRPDLR,OPMOD(4))
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
C PURPOSE      TO DETERMINE THE LITERAL DESIGNATION OF AN
C              ARGUMENT AND OUTPUT THE APPROPRIATE ARGUMENT-
C              PAIR TO THE I.L. INTERNAL RECORD IMAGE
C              (ILFILE)
C
C ARGUMENTS    INDEX    NAME TABLE (NAMTBL) INDEX OF ARGUMENT.
C**
C...     IS INDEX A POINTER TO A NUMBER
C
      IF(INDEX.GT.NAMMAX) GOTO 20
C
C...     NO. CALCULATE CLASS OF THIS ITEM.
C
      L = MODULO*(NAMTBL(INDEX)/MODULO)
C
C...     IS MODE OF ITEM GREATER THAN MODHLF
C...     I.E. IS IT AN INDIRECT ADDRESS
C
      IF((NAMTBL(INDEX)-L).LT.MODHLF) GO TO 10
C
C...     YES. CALL TWOARG WITH MODIFIER OF 3 ($$$)
C
      CALL TWOARG(TRPDLR,INDEX)
      GO TO 100
C
C...     NOT AN INDIRECT ADDRESS.
C...     IS IT OF CLASS VBL, TEMP, LABEL, OR IMPLAB.
C
   10 IF ((L.NE.VBL(1)).AND.(L.NE.TEMP(1)).AND.(L.NE.LABEL(1))
     / .AND.(L.NE.IMPLAB(1))) GOTO 30
C
C...     YES. CALL TWOARG WITH MODIFIER OF 0
C
      CALL TWOARG(NOUGHT,INDEX)
      GO TO 100
C
C...     NUMBER. CALL TWOARG WITH MODIFIER OF 1 ($)
C
   20 CALL TWOARG(DLR,INDEX)
      GO TO 100
C
C...     BCD CHARACTER INDEX. CALL TWOARG WITH MODIFIER OF 2 ($$)
C
   30 CALL TWOARG(DBLDLR,INDEX)
  100 RETURN
       END
