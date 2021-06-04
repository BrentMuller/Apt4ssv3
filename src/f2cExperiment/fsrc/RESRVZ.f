**** SOURCE FILE : M0006679.W01   ***
*
C
C              FORTRAN SUBROUTINE RESRVZ
C
C LINKAGE      SUBROUTINE RESRVZ(INDEX,MODE,ISIZE,NNNBER)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          INTEGER FCT.  NAME            INTEGER FCT.  GETTMP
C          SUBROUTINE    OPCODE          SUBROUTINE    GOPAT
C          SUBROUTINE    RLSLIN          SUBROUTINE    INPAT
C          SUBROUTINE    TWOARG          SUBROUTINE    LARGES
C                                        SUBROUTINE    LCANON
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    RESRED
C                                        SUBROUTINE    SSDEF
C
      SUBROUTINE RESRVZ(INDEX,MODE,ISIZE,NNNBER)
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C
C        3.    METALINGUISTIC VARIABLE CLASS CODES
C
      COMMON/CODE/CODE
      DIMENSION CODE(150),VBL(2)
C VBL:         (1)=CODE CLASS 31000,(2)=NAMTBL INDEX OF 'VBL   '
      EQUIVALENCE (VBL(1),CODE(61))
C
C       16.    LITERALS FOR I. L. OPERATION CODES
C
      COMMON/IL/IL
      DIMENSION IL(21)
C RESRV:       CONTAINS COMMAND CODE (12) FOR RESRV COMMAND
      EQUIVALENCE (RESRV,IL(12))
C
C       17.    MODE CODES
C
      COMMON/MODX/MODX
      DIMENSION MODX(32)
C REAL:        MODE CODE (21) FOR A SCALAR
      EQUIVALENCE (REAL,MODX(21))
C BOOL:        MODE CODE (23) FOR BOOLEAN TYPE
      EQUIVALENCE (BOOL,MODX(23))
C
C       30.    NAMTBL POINTERS TO FIRST CANONICAL FORMS IN EACH BLOCK
C
      COMMON/BLKCFS/FIRST
      DIMENSION FIRST(2,3)
C*
C ARGUMENT     INDEX     NAME TABLE (NAMTBL) INDEX OF
C                        VARIABLE FOR WHICH OBJECT TIME
C                        CANONICAL FORM SPACE IS BEING ALLOCATED.
C              MODE      MODE OF VARIABLE.
C              ISIZE     NUMBER OF ELEMENTS IN CANONICAL FORM
C                        EXCLUDING SUBSCRIPT AND BCD NAME.
C              NNNBER    UPPER SUBSCRIPT LIMIT (1 IF NON-
C                        SUBSCRIPTED VARIABLE).
C
      CHARACTER*6  DLRBLK(3)
      DATA  DLRBLK /'      ','$$BLK2','$$BLK3'/
C**
C... DETERMINE WHICH BLOCK THE VARIABLE BELONGS IN
C
      BLOCK = 4
      MD = MODE
      IF(MD.EQ.BOOL)MD=REAL
      IF (MD .EQ. REAL   .AND. NNNBER .EQ. 1)  BLOCK = 1
      IF (MD .EQ. REAL   .AND. NNNBER .GT. 1)  BLOCK = 2
      IF ((MD .LT. REAL  .AND.  MD .GT. 0) .OR. (MD .GE. 24)
     1  ) BLOCK = 3
C
      IF(BLOCK.NE.2 .OR. FIRST(2,2).NE.0)GO TO 5
C... PUT FIRST ITEM IN CANONICAL FORM BLOCK 2.
      I=NAME(DLRBLK(2))
      NAMTBL(I)=VBL(1)+MODE
      CALL OPCODE(RESRV)
      CALL TWOARG(I,MODE)
      CALL TWOARG(1,2)
      CALL RLSLIN
      FIRST(1,2)=I
      FIRST(2,2)=1
C
    5 CALL OPCODE(RESRV)
      CALL TWOARG(INDEX,MODE)
      CALL TWOARG(ISIZE,NNNBER)
      CALL RLSLIN
      IF(BLOCK.EQ.4)GO TO 20
C... IF FIRST CANONICAL FORM FOR THIS BLOCK, SAVE NAMTBL INDEX.
      IF(FIRST(2,BLOCK).NE.0)GO TO 10
      FIRST(1,BLOCK)=INDEX
C... INCREMENT COUNT OF NUMBER OF FORMS IN THIS BLOCK
C
   10 FIRST(2,BLOCK) = FIRST(2,BLOCK) + NNNBER
   20 RETURN
      END
