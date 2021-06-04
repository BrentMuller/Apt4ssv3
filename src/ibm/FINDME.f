**** SOURCE FILE : FINDME00.IBM;1   ***
*
      SUBROUTINE FINDME(ID,MEMBER,IRET)
C
      INTEGER ID,IRET
      CHARACTER*(*) MEMBER
C
      LOGICAL EX
C
      CHARACTER FLNAME*20,TYPE*4,MODE*2
      INTEGER NLEN,JRET
C
      DATA TYPE/' LDA'/,MODE/' A'/
C
C.... SET UP FILENAME
C
      NLEN=LEN(MEMBER)
      K=INDEX(MEMBER,' ')
      IF (K.NE.0) NLEN=K-1
      FLNAME=MEMBER(:NLEN)//TYPE//MODE
      NLEN=NLEN+6
C
C.... INQUIRE IF FILE EXISTS
C
c      CALL UOPEN(ID,FLNAME(:NLEN),1,4,80,0,'U',0,JRET)
      jret=1
      write(*,*)'TODO: uopen command, FINDME.f'
      IF (JRET.EQ.0) THEN
C.... FILE EXISTS - OPEN ATTACHED TO ID
c        CALL UOPEN(ID,FLNAME(:NLEN),1,1,80,0,'U',0,JRET)
      write(*,*)'TODO: uopen command, FINDME.f'
        IF (JRET.NE.0) GOTO 20
        IRET=0
      ELSE
        IRET=6
      ENDIF
      RETURN
C.... ERROR OPENING FILE
  20  IRET=5
      RETURN
      END
