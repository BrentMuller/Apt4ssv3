**** SOURCE FILE : OUTMSG.ORG   ***
*
*
*  * OUTMSG *  FORTRAN 77 SUBROUTINE  1.12.88  E.MCLELLAN
*
*  PURPOSE:  TO PRINT MESSAGE ON THE VLFILE
*
*  CALLING SEQUENCE:
*                   CALL OUTMSG(STR)
*
*  ARGUMENTS:
*                   TYPE       DESCRIPTION
*      STR          CHARACTER  CHARACTER STRING TO BE PRINTED
*                              MAY BE LITERAL OR A STRING VARIABLE
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
      SUBROUTINE OUTMSG(STR)
C
      CHARACTER STR*(*),F1*3,FORM*9
      INTEGER SLEN
C
      INCLUDE 'SYMFIL.INC'
C
      SLEN=LEN(STR)
C
C.... SET UP FORMAT AND PRINT
C
      WRITE (F1,'(I3)') SLEN
      FORM='(1X,A'//F1//')'
      WRITE (VLFILE,FORM) STR
C
      END