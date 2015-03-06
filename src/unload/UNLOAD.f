***************************************************************
* NO REDISTRIBUTION TO U.S. EMBARGOED DESTINATIONS OR PERSONS *
* WHICH INCLUDE CUBA, IRAQ, LIBYA, NORTH KOREA, IRAN, SYRIA,  *
* SUDAN, AFGHANISTAN AND ANY OTHER COUNTRY TO WHICH THE U.S.  *
* HAS EMBARGOED GOODS AND SERVICES.                           *
************************************************************************
*            PROGRAM TO UNLOAD THE CONCATENATED FILES                  *
*            CONTAINED ON THE SSV.. AND CASPA.. TAPES                  *
*                     INTO INDIVIDUAL FILES                            *
*                                                                      *
*   CONCATENATED FILE TO BE UNLOADED SHOULD BE ASSIGNED TO UNIT 1      *
*                                                                      *
*   UNLOADING INSTRUCTIONS SHOULD BE ON A FILE ASSIGNED TO UNIT 2      *
*                                                                      *
*   AS FOLLOWS:-                                                       *
*       RECORD 1: MODULE OR FILE                                       *
*                 TO INDICATE WHETHER TO DIVIDE INTO MODULES OR FILES  *
*                 NOTE: MODULES ARE CONCATENATED SETS OF FILES         *
*       RECORD 2: SEQ, NOSEQ OR VB                                     *
*                 TO INDICATE OUTPUT RECORD FORMAT                     *
*                 SEQ   - FIXED LENGTH WITH SEQUENCE NOS (80 BYTES)    *
*                 NOSEQ - VARIABLE LENGTH WITHOUT SEQUENCE NOS.        *
*                 VB    - VARIABLE LENGTH WITH LEADING SEQUENCE NOS.   *
*       RECORD 3: VAX, IBM OR NOINC                                    *
*                 TO INDICATE INCLUDE FILE FORMAT                      *
*                 VAX   - INCLUDE 'NAME.INC'                           *
*                 IBM   - INCLUDE (NAME)                               *
*                 NOINC - TEXT OF INCLUDE FILES WILL BE INSERTED       *
*                         INTO SOURCE CODE DURING UNLOAD PROCEDURE     *
*       RECORD 4: FORT OR LIST                                         *
*                 TO INDICATE IF STANDARD FORTRAN OPEN                 *
*                 OR SPECIAL VAX OPEN (CARRIAGECONTROL='LIST')         *
************************************************************************
C
      CHARACTER RECORD*80,FILNAM*40,F1*2,FORM*5,FORM1*8
      CHARACTER COMAND*6,TYPE*12,SEQNO*8
      INTEGER RLEN,LENGTH
      INTEGER COMIN,INFIL,OUTFIL
      LOGICAL OD,MODULE,SEQ,VB,VAX,IBM,NOINC,LIST,COPY
C
      INFIL=1 
      COMIN=2
      OUTFIL=3
      open(infil,file='FILE02',status='old')
      open(comin,file='FORT.2',status='old')
      open(outfil,file='OUT')
C
C.... READ INSTRUCTIONS FROM COMIN
C
C.... RECORD 1
      READ (COMIN,'(A6)') COMAND
      MODULE=(COMAND.EQ.'MODULE')
C.... RECORD 2
      READ (COMIN,'(A6)') COMAND
      SEQ=(COMAND.EQ.'SEQ')
      VB=(COMAND.EQ.'VB')
C.... RECORD 3
      READ (COMIN,'(A6)') COMAND
      VAX=(COMAND.EQ.'VAX')
      IBM=(COMAND.EQ.'IBM')
      NOINC=(COMAND.EQ.'NOINC')
C.... RECORD 4
      READ (COMIN,'(A6)') COMAND
      LIST=(COMAND.EQ.'LIST')
C.... READ RECORD FROM INFIL
  10  READ (INFIL,'(A80)',END=999,ERR=950) RECORD
      SEQNO=' '
      IF (RECORD(1:5).EQ.'**** ') THEN
C.... CHECK IF MODULE NAME, FILENAME OR END OF FILE
        IF (RECORD(1:13).EQ.'**** EOF ****') THEN
            GOTO 999
        ELSE IF (RECORD(1:12).EQ.'**** CREATED') THEN
C.... IGNORE
            GOTO 10
        ELSE
C.... EXTRACT TYPE OF MARKER RECORD
          IFN=INDEX(RECORD,'=')-2
          IF (IFN.GT.0) THEN
            TYPE=RECORD(6:IFN)
          ELSE
            IFN=INDEX(RECORD,':')-2
            IF (IFN.GT.0) THEN
              TYPE=RECORD(6:IFN)
            ELSE
              TYPE=' '
            ENDIF
          ENDIF
        ENDIF
        IF (    ( (TYPE.EQ.'MODULE').AND.MODULE)
     1     .OR. ( (TYPE.EQ.'SOURCE FILE').AND..NOT.MODULE)
     2     .OR. ( (TYPE.EQ.'FILENAME').AND..NOT.MODULE) ) THEN
C.... CANCEL COPY FLAG
          COPY=.FALSE.
C.... EXTRACT FILENAME
          FILNAM=' '
          IST=INDEX(RECORD(IFN+4:),']')+IFN+4
          IFN=INDEX(RECORD(IST:),' ')
          IF (IFN.EQ.0.OR.IFN.GT.40) THEN
            IFN=40
            FILNAM(1:40)=RECORD(IST:IST+IFN-1)
          ELSE IF (IFN.EQ.1) THEN
            IFN=6
            FILNAM(1:IFN)='NONAME'
          ELSE
            IFN=IFN-1
            FILNAM(1:IFN)=RECORD(IST:IST+IFN-1)
          ENDIF
C.... CLOSE CURRENT FILE ATTACHED TO UNIT 3
C.... AND OPEN NEW FILE
          INQUIRE(UNIT=OUTFIL,OPENED=OD)
             IF (OD) THEN
              CLOSE (UNIT=OUTFIL)
             ENDIF
           IF (LIST) THEN
c            OPEN (UNIT=OUTFIL,FILE=FILNAM(1:IFN),STATUS='NEW',
            open (unit=outfil,file=filnam(1:ifn),status='new')
c     +            CARRIAGECONTROL='LIST')
           ELSE
            OPEN (UNIT=OUTFIL,FILE=FILNAM(1:IFN),STATUS='NEW')
           ENDIF
         ELSE IF ( (TYPE.EQ.'MODULE').AND..NOT.MODULE) THEN
C.... IGNORE
          GOTO 10
         ELSE
          GOTO 15
        ENDIF
      ELSE IF (RECORD(1:5).EQ.'*COPY') THEN
        COPY=.TRUE.
C.... INCLUDE FILE TEXT
        IF (IBM) THEN
C.... IS A FILE OPENED ON UNIT 3
          INQUIRE(UNIT=OUTFIL,OPENED=OD)
          IF (.NOT.OD) THEN
C.... OPEN A FILE INCFILES
            OPEN (UNIT=OUTFIL,FILE='INCFIL.COPY',STATUS='NEW')
          ENDIF
          GOTO 15
        ELSE
C.... EXTRACT FILE NAME
          FILNAM=' '
          IST=7
          IFN=INDEX(RECORD(IST:),' ')
          IF (IFN.EQ.0.OR.IFN.GT.36) THEN
            IFN=36
            FILNAM(1:IFN)=RECORD(IST:IST+IFN-1)
          ELSE IF (IFN.EQ.1) THEN
            IFN=6
            FILNAM(1:IFN)='NONAME'
          ELSE
            IFN=IFN-1
            FILNAM(1:IFN)=RECORD(IST:IST+IFN-1)
          ENDIF
          IF (VAX) THEN
            FILNAM(IFN+1:IFN+4)='.INC'
            IFN=IFN+4
          ENDIF
C.... CLOSE CURRENT FILE ATTACHED TO UNIT 3
C.... AND OPEN NEW FILE
          INQUIRE(UNIT=OUTFIL,OPENED=OD)
             IF (OD) THEN
              CLOSE (UNIT=OUTFIL)
             ENDIF
          IF (LIST) THEN
c            OPEN (UNIT=OUTFIL,FILE=FILNAM(1:IFN),STATUS='NEW',
            open (unit=outfil,file=filnam(1:ifn),status='new')
c     +            CARRIAGECONTROL='LIST')
          ELSE
            OPEN (UNIT=OUTFIL,FILE=FILNAM(1:IFN),STATUS='NEW')
          ENDIF
        ENDIF
      ELSE
C.... ASCERTAIN INPUT RECORD LENGTH
  15    RLEN=LENGTH(RECORD)
C.... IF SEQUENCE NOS. EXIST BUT ARE TO BE OMITTED FIND NEW OUTPUT
C     RECORD LENGTH
        IF (.NOT.SEQ.AND.(RLEN.EQ.80)) THEN
          RLEN=LENGTH(RECORD(:72))
          IF (VB) THEN
            SEQNO=RECORD(73:80)
          ENDIF
        ENDIF
C.... CHECK IF RECORD IS AN INCLUDE STATEMENT AND TAKE APPROP. ACTION
        IF (IBM) THEN
C.... REPLACE INCLUDE 'NAME.INC' BY INCLUDE(NAME)
          CALL IBMINC(RECORD,RLEN)
        ELSE IF (NOINC) THEN
C.... INSERT INCLUDE FILE
          CALL INCLUD(RECORD,RLEN,VB,SEQ,OUTFIL)
          GOTO 10
        ELSE
          CONTINUE
        ENDIF
C.... WRITE CURRENT RECORD TO CURRENT FILE
        IF (VB.AND.(SEQNO.EQ.' ').AND.(RECORD(1:5).EQ.'**** ')) THEN
          CONTINUE
        ELSE
          WRITE (F1,'(I2)') RLEN
          IF (VB.AND..NOT.COPY) THEN
            FORM1='(A8,A'//F1//')'
            WRITE (OUTFIL,FORM1) SEQNO,RECORD(1:RLEN)
          ELSE
            FORM='(A'//F1//')'
            WRITE (OUTFIL,FORM) RECORD(1:RLEN)
          ENDIF
        ENDIF
      ENDIF
C
      GOTO 10
C
C
  950 PRINT *,' ERROR READING FROM INPUT FILE '
      STOP ' ABNORMAL END'
C
  999 STOP ' FILE UNLOADED SUCCESSFULLY'
      END
******************************************
*   ROUTINE TO CHANGE INCLUDE STATEMENT  *
*   TO IBM FORMAT                        *
******************************************
      SUBROUTINE IBMINC(REC,RLEN)
      CHARACTER*80 REC
      CHARACTER F1*2,QUOTE,FORM*5
C
      INTEGER RLEN,LENGTH
C
      DATA QUOTE/''''/
C
      IF (RLEN.GT.0) THEN
C
C.....CHECK FOR STRING 'INCLUDE'
C
        K=INDEX(REC(:RLEN),'INCLUDE')
        IF ((K.NE.0).AND.(K+7.LT.RLEN)) THEN
C....SCAN REMAINDER OF RECORD FOR FILENAME, ENCLOSED IN QUOTES
          K=K+7
          I=INDEX(REC(K:RLEN),QUOTE)
          J=INDEX(REC(K+I:RLEN),QUOTE)
          IF ((I.NE.0).AND.(J.GT.1)) THEN
C.... REPLACE INCLUDE 'FILENAME' BY INCLUDE (MEMBER)
            L=INDEX(REC(K+I:K+I+J-2),'.')
            REC(K+I-1:K+I-1)='('
            REC(K+I+L-1:K+I+J-1)=')'
          ENDIF
        ENDIF
      ENDIF
C
      END
**************************************
*                                    *
*   ROUTINE TO INSERT INCLUDE FILES  *
*       INTO FORTRAN SOURCE          *
*                                    *
*   EACH INCLUDE FILE IS ASSIGNED    *
*   TO UNIT 9 AS REQUIRED            *
*                                    *
**************************************
      SUBROUTINE INCLUD(REC,RLEN,VB,SEQ,ID)
C
      CHARACTER*40 INCFL
      CHARACTER*80 REC,INCREC
      CHARACTER F1*2,QUOTE,FORM*20
C
      INTEGER RLEN,LENGTH,ID,IDINC
C
      LOGICAL VB,SEQ
C
      integer uinc 
      DATA UINC/4/,QUOTE/''''/
C
      IF (RLEN.GT.0) THEN
C
C.....CHECK FOR STRING 'INCLUDE'
C
        K=INDEX(REC(:RLEN),'INCLUDE')
        IF ((K.NE.0).AND.(K+7.LT.RLEN)) THEN
C....SCAN REMAINDER OF RECORD FOR FILENAME, ENCLOSED IN QUOTES
          K=K+7
          I=INDEX(REC(K:RLEN),QUOTE)
          J=INDEX(REC(K+I:RLEN),QUOTE)
          IF ((I.NE.0).AND.(J.GT.1)) THEN
            INCFL=REC(K+I:K+I+J-2)
C....INSERT INCLUDE FILE INTO FORTRAN SOURCE
            OPEN(UNIT=UINC,FILE=INCFL,ACCESS='SEQUENTIAL',
     +           FORM='FORMATTED',STATUS='OLD')
C
            ISEQ=0
  20        READ(UINC,'(A80)',END=80,ERR=95) INCREC
            RLEN=LENGTH(INCREC)
            IF (RLEN.EQ.0) GOTO 20
            WRITE (F1,'(I2)') RLEN
            ISEQ=ISEQ+1
C.... WHAT OUTPUT RECORD FORMAT IS REQUIRED
            IF (SEQ) THEN
C.... SEQUENCE NUMBERS REQUIRED
              IF (VB) THEN
                FORM='(A4,I4,A'//F1//')'
                WRITE (ID,FORM) INCFL(1:4),ISEQ,INCREC(:RLEN)
              ELSE
                FORM='(A'//F1//',A4,I4)'
                WRITE (ID,FORM) INCREC(:RLEN),INCFL(1:4),ISEQ
              ENDIF
            ELSE
              FORM='(A'//F1//')'
              WRITE (ID,FORM) INCREC(:RLEN)
            ENDIF
            GOTO 20
C
  80        CLOSE(UINC)
          ELSE
            WRITE (F1,'(I2)') RLEN
            FORM='(A'//F1//')'
            WRITE (ID,FORM) REC(:RLEN)
          ENDIF
        ELSE
          WRITE (F1,'(I2)') RLEN
          FORM='(A'//F1//')'
          WRITE (ID,FORM) REC(:RLEN)
        ENDIF
      ENDIF
C
      GOTO 999
C
   95 PRINT *,' ERROR READING FROM INCLUDE FILE: ',INCFL
      STOP ' ABNORMAL END'
C
  999 RETURN
      END
      INTEGER FUNCTION LENGTH(REC)
C
      CHARACTER*(*) REC
      INTEGER MAX,I
C
      MAX=LEN(REC)
      DO 10 I=MAX,1,-1
       IF (REC(I:I).NE.' ') THEN
         LENGTH=I
         GOTO 20
       ENDIF
  10  CONTINUE
C
  20  RETURN
      END
