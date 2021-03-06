**** SOURCE FILE : FREAD000.ORG   ***
*
*
*  *  FREAD  *                  18.6.86   E.MCLELLAN
*
*
*  PURPOSE     TO READ A RECORD CONTAINING CHARACTER DATA
*              FROM A SPECIFIED FILE, CONVERT EACH 12 BYTE ITEM
*              INTO A DOUBLE PRECISION FLOATING POINT NUMBER
*
*  CALLING SEQUENCE
*              CALL FREAD (NO,IRECNO,DATA,ISIZE,IRET)
*  ARGUMENTS
*              NO        FILE NUMBER
*              IRECNO    RECORD NO. IF SET TO ZERO RETRIEVES
*                        THE NEXT RECORD. IF SET TO 'N'
*                        RETRIEVES N-TH RECORD DIRECTLY.
*              DATA      DATA ARRAY TO CONTAIN THE RETRIEVED
*                        RECORD (DOUBLE PRECISION)
*              ISIZE     SIZE OF RECORD (IN DOUBLE PRECISION WORDS)
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
*         CDATA     CHARACTER  CHARACTER VARIABLE INTO WHICH RECORD
*                              IS INITIALLY READ
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
      SUBROUTINE FREAD (NO,IRECNO,DATA,ISIZE,IRET)
C
      INCLUDE 'FILTAB.INC'
C
      INTEGER NO,IRECNO,ISIZE,IRET
      DOUBLE PRECISION DATA(ISIZE)
      LOGICAL OD
      CHARACTER*12 CDATA(3000)
      CHARACTER*12 IACC
      CHARACTER*80 DARRAY
      INTEGER POSN,SLEN
      DATA DARRAY/' '/
C
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
        IF (IRECNO.GT.LSTREC(NO)) THEN
          IRET=1
          RETURN
        END IF
        IREC=IRECNO
        IF (ISIZE*12.LE.IRECL) THEN
          READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (CDATA(I),I=1,ISIZE)
          CALL ABCDBN(CDATA,DATA,ISIZE)
        ELSE
          NUM=(ISIZE*12)/IRECL
          DO 20 J=1,NUM
            I2=IRECL/12
            READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (CDATA(I),I=1,I2)
            I1=(J-1)*I2+1
            CALL ABCDBN(CDATA,DATA(I1),I2)
            IREC=IREC+1
   20     CONTINUE
          IF ((ISIZE*12-NUM*IRECL).GT.0) THEN
            I2=ISIZE-NUM*IRECL/12
            READ (ID,REC=IREC,IOSTAT=IRET,ERR=90) (CDATA(I),I=1,I2)
            I1=ISIZE-I2+1
            CALL ABCDBN(CDATA,DATA(I1),I2)
          ELSE
            IREC=IREC-1
          END IF
          IRET=2
        END IF
        NXTREC(NO)=IREC+1
      ELSE
C---- SEQUENTIAL ACCESS FILE
        READ (ID,END=80) (CDATA(I),I=1,ISIZE)
        CALL ABCDBN(CDATA,DATA,ISIZE)
      ENDIF
      RETURN
 80   IRET=1
      RETURN
 90   SLEN=0
      CALL CFORM (' *** ERROR READING BY FREAD FROM FILE :',
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
