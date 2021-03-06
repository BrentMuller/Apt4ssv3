**** SOURCE FILE : M0006658.W01   ***
*
C
C              FORTRAN SUBROUTINE NAME
C
C LINKAGE      INTEGER  FUNCTION  NAME  (STR)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    ALARM           SUBROUTINE    COMSTR
C          INTEGER FCT.  BCDF            INTEGER FCT.  GETTMP
C                                        SUBROUTINE    GOLO
C                                        SUBROUTINE    GOPAT
C                                        SUBROUTINE    INPAT
C                                        SUBROUTINE    INPUT
C                                        SUBROUTINE    IPRLOG
C                                        SUBROUTINE    MACLBL
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C                                        SUBROUTINE    RESRVZ
C                                        SUBROUTINE    VCTPRD
C
      INTEGER  FUNCTION  NAME  (STR)
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C NAMEST:      NAMTBL INDEX OF BEGIN OF THE PART PROGRAM NAME SECTION
C NAMMAX:      NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION
C*
C ARGUMENTS    STR     A CHARACTER STRING CONTAINING THE ALPHA
C                      NUMERIC CHARACTERS OF THE SYMBOL.
C
      external alarm
      CHARACTER*6 STR
C**
   10 J=MOD(BCDF(STR),NAMMAX-NAMEST)
      IF (J.LT.0) THEN
        J=J+NAMMAX
      ELSE
        J=J+NAMEST
      ENDIF
      DO 20 I = J,NAMMAX
      IF (NAMTBL(I).EQ.0) GOTO 40
      IF(CNAMTB(I).EQ.STR) GOTO 100
   20 CONTINUE
C
C...       SCAN TABLE FROM BOTTOM UP
C
      DO 30 I = NAMEST,J
      IF (NAMTBL(I).EQ.0) GOTO 40
      IF(CNAMTB(I).EQ.STR) GOTO 100
   30 CONTINUE
C...       TABLE FULL
      CALL ALARM(3001,0,8,'NAME    ')
      RETURN
C
C...       NOT IN TABLE
C
   40 CNAMTB(I)=STR
C...       ENTRY IF NAME FOUND
  100 NAME = I
      IF ((NAMTBL(I) .GE. 0) .OR. (I .GT. NAMMAX))  RETURN
      I = -NAMTBL(I)
      GO TO 100
C
       END
