**** SOURCE FILE : DNONAM00.V01   ***
*
*
*  * DNONAM *    FORTRAN 77 SUBROUTINE   15-JUL-1986  E.MCLELLAN
*
*   PURPOSE:  TO RETURN THE BCD EQUIVALENT OF 'DNONAM  '
*             IN THE FIRST 8 BYTES OF THE ARGUMENT
*             (NOTE: THIS SHOULD GIVE A NONE VALID D.P. NUMBER
*                    ON MOST SYSTEMS)
*
*   CALLING SEQUENCE:
*                    CALL DNONAM(IWORD)
*
*   ARGUMENTS:
*         IWORD  INTEGER  ARRAY INTO WHICH 'DNONAM  ' IS TO BE LOADED
*
*   GLOBAL VARIABLES:
*
*----------------------------------------------------
*   VARIABLE    BLOCK    TYPE        DESCRIPTION
*----------------------------------------------------
*   IFAC        SDP      INTEGER     BYTE LEFT SHIFT
*                                    MULTIPLICATION FACTOR
*
*   LOCAL VARIABLES:
*                   TYPE        DESCRIPTION
*         IBDNAM    INTEGER     INTEGER ARRAY TO BUILD UP BCDF
*         FIRST     LOGICAL     FLAG INDICATING FIRST CALL
*
*   SUBSIDIARIES:  NONE
*
      SUBROUTINE DNONAM(IWORD)
C
      INTEGER IDNONM(2),IWORD(2)
      INTEGER BCDF
      LOGICAL FIRST
      SAVE IDNONM,FIRST
      DATA FIRST/.TRUE./
                        
      IF (FIRST) THEN
        IDNONM(1) = BCDF('DNON')
        IDNONM(2) = BCDF('AM  ')
        FIRST=.FALSE.
      ENDIF
C
      IWORD(1)=IDNONM(1)
      IWORD(2)=IDNONM(2)
      RETURN
      END
