**** SOURCE FILE : TAPOP000.ORG   ***
*
*
*  *  TAPOP  *   VAX11 VERSION    11.5.82   E.MCLELLAN
*                MODIFIED         18.07.85  E.MCLELLAN
*
*  PURPOSE     TO PERFORM I/O FILE HANDLING OPERATIONS
*
*  CALLING SEQUENCE
*              CALL TAPOP (NO,N)
*  ARGUMENTS
*              NO        FORTRAN NUMBER
*              N  =-1    REWIND FILE BEFORE WRITING NEW FILE
*                 =-2    REWIND FILE BEFORE READING OLD FILE
*                 =-3    CLOSE FILE
*                 =-4    REWIND FILE
*                 =-5    GET THE NO. OF THE NEXT RECORD
*
*
*  GLOBAL VARIABLES:
*
*---------------------------------------------------
*   VARIABLE        BLOCK     TYPE       DESCRIPTION
*---------------------------------------------------
*   FILNAM          FILTAB    CHARACTER  FILE NAME
*   FILACC          FILTAB    CHARACTER  FILE ACCESS
*                                         (DIRECT OR SEQUENTIAL)
*   FILFMT          FILTAB    CHARACTER  FILE FORMAT
*                                         (FORMATTED OR UNFORMATTED)
*   OPSTAT          FILTAB    CHARACTER  OPEN STATUS
*                                         (UNKNOWN,SCRATCH,NEW,OLD)
*   CLSTAT          FILTAB    CHARACTER  CLOSE STATUS (KEEP,DELETE)
*   U               IFILTB    INTEGER    UNIT NUMBER
*   RL              IFILTB    INTEGER    RECORD LENGTH
*   NXTREC          IFILTB    INTEGER    NUMBER OF NEXT RECORD TO BE
*                                        READ OR WRITTEN (DIRECT ACCESS)
*   LSTREC          IFILTB    INTEGER    NUMBER OF LAST RECORD ON FILE
*                                         (DIERECT ACCESS)
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*        IACC       CHARACTER  FILE ACCESS RETURNED BY INQUIRE
*        DARRAY     CHARACTER  PRINT BUFFER
*        POSN       INTEGER    START POSTION IN PRINT BUFFER
*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN BUFFER
*
*  FILES:  FILE REFERENCED BY FILE NUMBER
*
*  SUBSIDIARIES:
*               FILOPN
*               CFORM
*               CPRINT
*
      SUBROUTINE TAPOP (NO,N)
C
      INCLUDE 'FILTAB.INC'
      CHARACTER*12 IACC
      CHARACTER DARRAY*80
      INTEGER POSN,SLEN
      DATA DARRAY/' '/
      ID=U(NO)
C
      IF (N.EQ.-1) THEN
C---- CLOSE FILE
        CLOSE (UNIT=ID,ERR=91,STATUS=CLSTAT(NO))
C---- OPEN FILE
      CALL FILOPN(NO)
      NXTREC(NO)=1
      LSTREC(NO)=0
C
        ELSE IF (N.EQ.-2) THEN
          INQUIRE (UNIT=ID,ACCESS=IACC)
          IF (IACC.EQ.'DIRECT') THEN
            NXTREC(NO)=1
          ELSE
            REWIND (UNIT=ID)
          END IF
        ELSE IF (N.EQ.-3) THEN
C---- CLOSE FILE
          CLOSE (UNIT=ID,ERR=91,STATUS=CLSTAT(NO))
        ELSE IF (N.EQ.-4) THEN
          INQUIRE (UNIT=ID,ACCESS=IACC)
          IF (IACC.EQ.'DIRECT') THEN
            NXTREC(NO)=1
          ELSE
            REWIND (UNIT=ID)
          END IF
        ELSE IF (N.EQ.-5) THEN
            N=LSTREC(NO)+1
      ENDIF
      RETURN
 90   SLEN=0
      CALL CFORM (' *** ERROR OPENING FILE :',DARRAY,2,SLEN)
      POSN=SLEN+3
      SLEN=0
      CALL CFORM (FILNAM(NO),DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+4
      SLEN=0
      CALL CFORM ('*** FROM ROUTINE: TAPOP',DARRAY,POSN,SLEN)
      CALL CPRINT (DARRAY)
      CALL ABNEND
 91   CALL CFORM (' *** ERROR CLOSING FORTRAN UNIT NO:',DARRAY,2,35)
      CALL ICONV (U(NO),DARRAY,37,2)
      CALL CFORM ('*** FROM ROUTINE: TAPOP',DARRAY,40,23)
      CALL CPRINT (DARRAY)
      RETURN
      END
