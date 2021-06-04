**** SOURCE FILE : SPRINT00.V02   ***
*
*
*  * SPRINT *  FORTRAN 77 SUBROUTINE  3.12.85  E.MCLELLAN
*
*  PURPOSE:  PRINT CHARACTER STRING ON (VLFILE) SYSTEM OUTPUT DEVICE
*
*  CALLING SEQUENCE:
*                   CALL SPRINT(BUFFER)
*
*  ARGUMENTS:
*                   TYPE       DESCRIPTION
*      BUFFER       CHARACTER  CHARACTER STRING TO BE PRINTED
*
*  GLOBAL VARIABLES:
*           BLOCK   TYPE       DESCRIPTION
*   VLFILE  SYMFIL  INTEGER    UNIT NUMBER FOR SYSTEM OUTPUT DEVICE
*
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*        SLEN       INTEGER    LENGTH OF STRING TO BE PRINTED
*        F1         CHARACTER  INTERNAL FILE FOR INTEGER TO CHARACTER
*                              CONVERSION
*        FORM       CHARACTER  OUTPUT FORMAT
*
*  FILES:
*        VLFILE     SYSTEM OUTPUT DEVICE
*
*  SUBSIDIARIES:  NONE
*
      SUBROUTINE SPRINT(BUFFER)
C
      CHARACTER BUFFER*(*),F1*3,FORM*6
      INTEGER SLEN
C
      INCLUDE 'SYMFIL.INC'
C
      SLEN=LEN(BUFFER)
C.....OMIT TRAILING BLANKS
      DO 10 I=SLEN,1,-1
        IF (BUFFER(I:I).NE.' ') THEN
          SLEN=I
          GOTO 20
        ENDIF
  10  CONTINUE
        SLEN=1
  20  CONTINUE
      IF (BUFFER(1:1).EQ.'C') THEN
         CLOSE (VLFILE,STATUS='KEEP')
      ELSE
         WRITE (F1,'(I3)') SLEN
         FORM='(A'//F1//')'
         WRITE (VLFILE,FORM) BUFFER
      ENDIF
C
      BUFFER=' '
C
      RETURN
      END
