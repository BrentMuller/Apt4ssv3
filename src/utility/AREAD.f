**** SOURCE FILE : AREAD000.ORG   ***
*
*
*  *  AREAD  *   VAX11 VERSION   11.5.82   E.MCLELLAN
*                MODIFIED        16.7.85   E.MCLELLAN
*
*
*  PURPOSE     TO READ ONE RECORD FROM A SPECIFIED FILE
*
*  CALLING SEQUENCE
*              CALL AREAD (NO,IRECNO,DATA,ISIZE,IRET)
*  ARGUMENTS
*              NO        FILE NUMBER
*              IRECNO    RECORD NO. IF SET TO ZERO RETRIEVES
*                        THE NEXT RECORD. IF SET TO 'N'
*                        RETRIEVES N-TH RECORD DIRECTLY.
*              DATA      DATA ARRAY TO CONTAIN THE RETRIEVED
*                        RECORD
*              ISIZE     SIZE OF RECORD (IN 4 BYTE WORDS)
*              IRET      RETURN FLAG =0  NO ERROR
*                                    =1  E.O.F ENCOUNTERED
*                                    =2  ISIZE IS BIGGER THAN ACTUAL
*                                        RECORD SIZE. DATA ASSUMED TO
*                                        SPAN MORE THAN ONE RECORD
*                                        DATA TRANSFERRED TO ARRAY
*                                    =3  UNRECOVERABLE ERROR
*
*
*  GLOBAL VARIABLES:  NONE
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
*                                         (DIRECT ACCESS)
*
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*         OD        LOGICAL    FLAG TO INDICATE IF FILE IS OPEN
*         IACC      CHARACTER  ACCESS TYPE RETURN BY INQUIRE
*         DARRAY    CHARACTER  PRINT BUFFER
*         IRECL     INTEGER    RECORD LENGTH
*         NUM       INTEGER    NUMBER OF COMPLETE PHYSICAL RECORDS
*                              SPANNED BY LOGICAL RECORD BEING READ
*         POSN      INTEGER    START POSITION IN PRINT BUFFER
*         SLEN      INTEGER    LENGTH OF STRING ENTERED IN PRINT BUFFER
*
*  FILES:  FILE REFERENCED BY FILE NUMBER
*
*  SUBSIDIARIES:
*               FILOPN
*               CFORM
*               ICONV
*               CPRINT
*
      SUBROUTINE AREAD (NO,IRECNO,DATA,ISIZE,IRET)
C
      INCLUDE 'FILTAB.INC'
C
      LOGICAL OD
      DIMENSION DATA(*)
      CHARACTER*12 IACC
      CHARACTER*80 DARRAY
      INTEGER POSN,SLEN
      DATA DARRAY/' '/
      ID=U(NO)
C
C---- IS UNIT OPENED, IF NOT OPEN
      INQUIRE (UNIT=ID,OPENED=OD)
      IF (OD) GOTO 10
C---- OPEN UNIT
      CALL FILOPN(NO)
C---- CHECK FILE ACCESS
   10 INQUIRE (UNIT=ID,ACCESS=IACC)
      IF (IACC.EQ.'DIRECT') THEN
C---- DIRECT ACCESS FILE
        IRECL=RL(NO)
        IF (IRECNO.EQ.0) THEN
          IRECNO=NXTREC(NO)
        END IF
C.... IF LSTREC(NO).EQ.0 THEN READING AN EXTERNALLY WRITTEN
C     DIRECT ACCESS FILE FOR WHICH LENGTH IS NOT KNOWN
        IF ((LSTREC(NO).NE.0).AND.(IRECNO.GT.LSTREC(NO))) THEN
          IRET=1
          RETURN
        END IF
        IREC=IRECNO
        IF (ISIZE.LE.IRECL) THEN
          READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (DATA(I),I=1,ISIZE)
        ELSE
          NUM=ISIZE/IRECL
          DO 20 J=1,NUM
          I1=(J-1)*IRECL+1
          I2=J*IRECL
          READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (DATA(I),I=I1,I2)
   20     IREC=IREC+1
          IF ((ISIZE-NUM*IRECL).GT.0) THEN
            I1=NUM*IRECL+1
            READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (DATA(I),I=I1,ISIZE)
          ELSE
            IREC=IREC-1
          END IF
          IRET=2
        END IF
        NXTREC(NO)=IREC+1
        ELSE
C---- SEQUENTIAL ACCESS FILE
          READ (ID,END=80) (DATA(I),I=1,ISIZE)
        END IF
      RETURN
 80   IRET=1
      RETURN
 90   SLEN=0
      CALL CFORM (' *** ERROR READING BY AREAD FROM FILE :',
     1            DARRAY,2,SLEN)
      POSN=SLEN+3
      SLEN=0
      CALL CFORM (FILNAM(NO),DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+2
      SLEN=0
      CALL CFORM ('RECNO:',DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+1
      SLEN=6
      CALL ICONV (IRECNO,DARRAY,POSN,SLEN)
      CALL CPRINT (DARRAY)
      IRET=3
      RETURN
      END
