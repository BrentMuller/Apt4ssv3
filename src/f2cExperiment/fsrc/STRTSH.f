**** SOURCE FILE : STRTSH00.V01   ***
*
*
*  * STRTSH *    FORTRAN 77 SUBROUTINE   15-JUL-1986  E.MCLELLAN
*                MODIFIED                 3-FEB-1988  E.MCLELLAN
*
*   PURPOSE:  TO RETURN THE BCD EQUIVALENT OF '*',NULL,'TRASH',NULL
*             IN THE FIRST 8 BYTES OF THE ARGUMENT
*             (NOTE: THIS SHOULD GIVE A NONE VALID D.P. NUMBER
*                    ON MOST SYSTEMS)
*
*   CALLING SEQUENCE:
*                    CALL STRTSH(IWORD)
*
*   ARGUMENTS:
*         IWORD  INTEGER  ARRAY INTO WHICH '* TRASH ' IS TO BE LOADED
*
*   GLOBAL VARIABLES:
*
*----------------------------------------------------
*   VARIABLE    BLOCK    TYPE        DESCRIPTION
*----------------------------------------------------
*   NBCHAR      SDP      INTEGER     NO OF BITS PER BYTE
*
*   LOCAL VARIABLES:
*                   TYPE        DESCRIPTION
*         ITRASH    INTEGER     INTEGER ARRAY TO BUILD UP BCDF
*         FIRST     LOGICAL     FLAG INDICATING FIRST CALL
*
*   SUBSIDIARIES:  NONE
*
      SUBROUTINE STRTSH(IWORD)
C
      INCLUDE 'SDP.INC'
C
      INTEGER ITRASH(2),IWORD(2)
      LOGICAL FIRST
      SAVE ITRASH,FIRST
      DATA FIRST/.TRUE./
      IF (FIRST) THEN
        I3=3*NBCHAR
        I2=2*NBCHAR
        ITRASH(1) = ISHFT(ICHAR('*'),I3)
     +            + ISHFT(ICHAR('T'),NBCHAR)
     +            + ICHAR('R')
        ITRASH(2) = ISHFT(ICHAR('A'),I3)
     +            + ISHFT(ICHAR('S'),I2)
     +            + ISHFT(ICHAR('H'),NBCHAR)
        FIRST=.FALSE.
      ENDIF
C
      IWORD(1)=ITRASH(1)
      IWORD(2)=ITRASH(2)
      RETURN
      END
