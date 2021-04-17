**** SOURCE FILE : AWRITE00.V01   ***
*
*
*  *  AWRITE  *   VAX11 VERSION    11.05.82   E.MCLELLAN
*                 MODIFIED         16.7.85
*
*  PURPOSE     TO WRITE ONE RECORD ON A SPECIFIED FILE
*
*  CALLING SEQUENCE
*              CALL AWRITE (NO,IRECNO,DATA,ISIZE,IRET)
*  ARGUMENTS
*              NO        FILE NUMBER
*              IRECNO    RECORD NO. IF SET TO ZERO WILL WRITE
*                        NEXT RECORD. CONTAINS ACTUAL RECORD
*                        NUMBER ON RETURNING
*              DATA      DATA ARRAY CONTAINING RECORD TO
*                        BE WRITTEN ON THE FILE
*              ISIZE     SIZE OF RECORD (IN 4 BYTE WORDS)
*              IRET      RETURN FLAG =0  NO ERROR
*                                    =1  ERROR
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
*                                         (DIRECT ACCESS)
*
*  LOCAL VARIABLES:
*                   TYPE       DESCRIPTION
*        OD         LOGICAL    FLAG TO INDICATE IF FILE IS OPENED
*        IACC       CHARACTER  FILE ACCESS TYPE RETURNED BY INQUIRE
*        DARRAY     CHARACTER  PRINT BUFFER
*        DUM        REAL       DUMMY ARRAY FOR FILLING OUT A PHYSICAL
*                              RECORD
*        NUM        INTEGER    NUMBER OF FULL PHYSICAL RECORDS TO
*                              WRITTEN FOR LOGICAL RECORD
*        POSN       INTEGER    START POSITION IN PRINT BUFFER
*        SLEN       INTEGER    LENGTH OF STRING ENTERED IN PRINT BUFFER
*
*  FILES:  FILE REFERENCED BY FILE NUMBER
*
*  SUBSIDIARIES:
*               FILOPN
*               CFORM
*               ICONV
*               CPRINT
*
      SUBROUTINE AWRITE (NO,IRECNO,DATA,ISIZE,IRET)
C
      INCLUDE 'FILTAB.INC'
      LOGICAL OD
      CHARACTER*12 IACC
      DIMENSION DATA(*)
      CHARACTER*80 DARRAY
      INTEGER POSN,SLEN
      REAL DUM(256)
      DATA DARRAY/' '/
      DATA DUM/256*0.0/
      ID=U(NO)
C
C---- IS FILE OPENED, IF NOT OPEN
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
          IRECNO=LSTREC(NO)+1
        END IF
        IREC=IRECNO
        IF (ISIZE.LE.IRECL) THEN
          WRITE (ID,REC=IREC,IOSTAT=IRET,ERR=90) (DATA(I),I=1,ISIZE)
        ELSE
        NUM=ISIZE/IRECL
          DO 20 J=1,NUM
          I1=(J-1)*IRECL+1
          I2=J*IRECL
          WRITE (ID,REC=IREC,IOSTAT=IRET,ERR=90) (DATA(I),I=I1,I2)
   20     IREC=IREC+1
          IF ((ISIZE-NUM*IRECL).GT.0) THEN
            I1=NUM*IRECL+1
            I2=(NUM+1)*IRECL-ISIZE
            WRITE (ID,REC=IREC,IOSTAT=IRET,ERR=90)
     1            (DATA(I),I=I1,ISIZE),(DUM(I),I=1,I2)
          ELSE
            IREC=IREC-1
          END IF
        END IF
        IF (IREC.GT.LSTREC(NO)) THEN
          LSTREC(NO)=IREC
        END IF
        NXTREC(NO)=IREC+1
        ELSE
C---- SEQUENTIAL ACCESS FILE
        WRITE (ID) (DATA(I),I=1,ISIZE)
        END IF
      RETURN
   90 SLEN=0
      CALL CFORM(' *** ERROR WRITING BY AWRITE ON FILE :',
     1            DARRAY,2,SLEN)
      POSN=SLEN+3
      SLEN=0
      CALL CFORM (FILNAM(NO),DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+2
      SLEN=0
      CALL CFORM ('RECNO :',DARRAY,POSN,SLEN)
      POSN=POSN+SLEN+1
      SLEN=6
      CALL ICONV (IRECNO,DARRAY,POSN,SLEN)
      CALL CPRINT (DARRAY)
      IRET=1
      RETURN
      END
