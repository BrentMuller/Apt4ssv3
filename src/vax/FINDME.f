**** SOURCE FILE : FINDME00.V01   ***
*
      SUBROUTINE FINDME(ID,MEMBER,IRET)
C
      INTEGER ID,IRET
      CHARACTER*(*) MEMBER
C
      LOGICAL EX
C
      INCLUDE 'LIBCOM.INC'
C
C.... SET UP FILENAME
C
C
      J=INDEX(MEMBER(1:),' ')
      IF (J.EQ.0) THEN
        FILENM=APTLIB//MEMBER//'.LDA'
      ELSE
        FILENM=APTLIB//MEMBER(1:J-1)//'.LDA'
      ENDIF
C
C.... INQUIRE IF FILE EXISTS
C
      INQUIRE(FILE=FILENM,EXIST=EX)
      IF (EX) THEN
C.... FILE EXISTS - OPEN ATTACHED TO ID
        OPEN(UNIT=ID,FILE=FILENM,ERR=20,STATUS='OLD',
     +       ACCESS='SEQUENTIAL',FORM='UNFORMATTED')
        IRET=0
      ELSE
        IRET=6
      ENDIF
      RETURN
C.... ERROR OPENING FILE
  20  IRET=5
      RETURN
      END
