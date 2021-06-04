**** SOURCE FILE : M0006638.V03   ***
*
C
C              FORTRAN SUBROUTINE IFTMP
C
C LINKAGE      LOGICAL FUNCTION IFTMP(A)
C
C          SUBSIDIARIES                  CALLED BY
C          NONE                          TYPE          ENTRY
C                                        SUBROUTINE    BOOLIF
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    PRO020
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    REPLAC
C                                        SUBROUTINE    SSDEF
C                                        SUBROUTINE    SUBCOD
C
      LOGICAL FUNCTION IFTMP(A)
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
      DIMENSION CODE(150),TEMP(2)
C TEMP:        (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '
      EQUIVALENCE (TEMP(1),CODE(33))
C
C       29.    CLASS CODE MODULI
C
      COMMON/MODULI/MODULI
      DIMENSION MODULI(2)
C MODULO:      NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS
      EQUIVALENCE (MODULO,MODULI(1))
C MODHLF:      NORMAL MODE CODE LIMIT 500
      EQUIVALENCE (MODHLF,MODULI(2))
C**
C
C...     IS A THE NAMTBL INDEX OF A TEMPORARY LOCATION
C
      IF(A.GT.NAMMAX)GO TO 5
      IF((NAMTBL(A)/MODULO.EQ.TEMP(1)/MODULO).AND.
     /  ((NAMTBL(A)-MODULO*(NAMTBL(A)/MODULO)).LT.MODHLF))GO TO 10
C
C...     NO. RETURN IFTMP AS .FALSE.
C
    5 IFTMP=.FALSE.
      RETURN
C
C...     YES. RETURN IFTMP AS .TRUE.
C
   10 IFTMP=.TRUE.
      RETURN
       END
