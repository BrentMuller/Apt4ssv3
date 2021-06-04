**** SOURCE FILE : M0006650.V04   ***
*
C
C              FORTRAN SUBROUTINE  MACLBL
C
C LINKAGE      SUBROUTINE  MACLBL(LABEL1,LABEL2,LABEL3)
C
C          SUBSIDIARIES                  CALLED BY
C          TYPE          ENTRY           TYPE          ENTRY
C          SUBROUTINE    SHIFT           SUBROUTINE    BOOLIF
C          INTEGER FCT.  NAME            SUBROUTINE    COMSTR
C          SUBROUTINE    HELP            SUBROUTINE    INPUT
C          SUBROUTINE    ALARM           SUBROUTINE    LOOP
C                                        SUBROUTINE    MACREC
C                                        SUBROUTINE    MATCH
C                                        SUBROUTINE    MNPROC
C                                        SUBROUTINE    MOTION
C                                        SUBROUTINE    PATH
C                                        SUBROUTINE    PRO026
C                                        SUBROUTINE    PRO027
C                                        SUBROUTINE    RECOG
C                                        SUBROUTINE    RECOGN
C
      SUBROUTINE MACLBL(LABEL1, LABEL2, LABEL3)
C
      IMPLICIT INTEGER (A-Z)
C
C        1.    NAME TABLE AND TABLE LIMITS
C
      INCLUDE 'NAMETB.INC'
C NAMTBL:      INTEGER CORRESPONDING TO NAME TABLE ENTRY
C CNAMTB:      NAME TABLE OR DICTIONARY
C*
C PURPOSE      TO CONSTRUCT A UNIQUE LABEL NAME CORRESPONDING
C              TO AN ORDERED PAIR OF NUMBERS.
C ARGUMENTS    LABEL1    IS THE FIRST NUMBER OF THE PAIR
C              LABEL2    IS THE SECOND NUMBER OF THE PAIR
C              LABEL3    WILL CONTAIN THE NAME TABLE (NAMTBL)
C                        INDEX OF THE GENERATED LABEL.
C...  COUNT IS THE TOTAL NUMBER OF GENERATED LABELS.
C...  TABL IS AN ARRAY CONTAINING EACH UNIQUE PAIR OF ARGUMENTS
C...    RECEIVED AND THE CORRESPONDING NAMTBL INDEX FOR THE
C...    GENERATED LABEL.
C**
      DIMENSION TABL(3,600)
C...
      CHARACTER BLK,CHARAC(12),FIND*8
      external alarm
      DATA BLK/' '/
      DATA CHARAC/ '0','1','2','3','4','5','6','7','8','9','Z','$'/
      DATA COUNT /0/
      DATA TABL/1800*0/
C...      INITIALIZE FIND WITH BLANKS
      FIND=BLK
C...      IF ARGUMENT PAIR ISIIN TABLE THEN BRANCH - RETURN NAMTBL INDEX
      DO 100 I=1,COUNT
      IF (TABL(1,I).NE.LABEL1) GO TO 100
      IF (TABL(2,I).EQ.LABEL2) GO TO 200
  100 CONTINUE
C...      OTHERWISE PUT ARGUMENTS IN TABLE- GENERATE LABEL
      COUNT=COUNT+1
      IF(COUNT.LE.600) GOTO 105
C TABL LENGTH EXCEEDED.  TERMINATE PROGRAM
      CALL ALARM(15,0,8,'MACLBL  ')
      CALL  HELP
  105 TABL(1,COUNT)=LABEL1
      TABL(2,COUNT)=LABEL2
C...      SHIFT Z$ INTO 1ST TWO POSITIONS OF LABEL BEING GENERATED
      DO 110 I=1,2
      CALL SHIFT(FIND,CHARAC(I+10))
  110 CONTINUE
C...      SHIFT CHARACTER EQUIVALENT OF TABLE INDEX INTO LABEL
      INTGER=COUNT
      DECR=1000
      DO 120 I=1,4
      SYMBOL=INTGER/DECR
      CALL SHIFT(FIND,CHARAC(SYMBOL+1))
      INTGER=INTGER-DECR*SYMBOL
      DECR=DECR/10
  120 CONTINUE
C...      PUT NAMTBL INDEX CORRESPONDING TO GENERATED LABEL IN TABLE
      TABL(3,COUNT)=NAME(FIND)
      I=COUNT
C...      ASSIGN NAMTBL INDEX OF GENERATED LABEL TO RETURN PARAMETER
  200 LABEL3=TABL(3,I)
      RETURN
      END
