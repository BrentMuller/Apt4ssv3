**** SOURCE FILE : LIBSCH00.V01   ***
*
      SUBROUTINE LIBSCH(MEMBER,FLAG)
*
*  * LIBSCH *  VAX-11 FORTRAN 77 VERSION  27.09.82  E.MCLELLAN
*                               MODIFIED  30.10.86  E.MCLELLAN
*
*  PURPOSE     TO SEARCH APTLIB FOR A GIVEN
*              MEMBER FILE AND TO OPEN SAID FILE
*  CALLING SEQUENCE
*              CALL LIBSCH(MEMBER,FLAG)
*  ARGUMENTS
*              MEMBER    CHARACTER STRING CONTAINING THE
*                        MEMBER NAME (BCD LEFT JUSTIFIED)
*              FLAG      0 = MEMBER FOUND
*                        1 = MEMBER NOT FOUND IN APTLIB
*                        2 = ERROR OPENING FILE
*                        3 = APTLIB DOES NOT EXIST
*                        4 = LIBSCH IS CALLED BEFORE COMPLETING THE
*                            PROCESSING OF PREVIOUS MEMBER
*
      CHARACTER*(*) MEMBER
      INTEGER FLAG
C
      INCLUDE 'FILTAB.INC'
C
      INCLUDE 'LIBCOM.INC'
C
      LOGICAL OD,EX
C
C
C..... DOES APTLIB EXIST
      ID=U(24)
      INQUIRE(FILE=APTLIB//'INDEX',EXIST=EX)
      IF (EX) THEN
C
C.....YES - HAS PROCESSING OF PREVIOUS MEMBER BEEN COMPLETED
         IF (IEOF.EQ.0) THEN
C.....NO
             FLAG=4
             RETURN
C.....YES - SET UP FILE NAME FOR MEMBER
         ELSE
            J=INDEX(MEMBER(1:),' ')
            IF (J.EQ.0) THEN
              FILENM=APTLIB//MEMBER//'.TXT'
            ELSE
              FILENM=APTLIB//MEMBER(1:J-1)//'.TXT'
            ENDIF
C
C.....STORE MEMBER NAME AND RESET EOF FLAG
            MEMNAM=MEMBER
            IEOF=0
C.....DOES FILE EXIST
            INQUIRE(FILE=FILENM,EXIST=EX)
               IF (EX) THEN
C.....YES
               OPEN(UNIT=ID,FILE=FILENM,ERR=90,STATUS='OLD',
     1              ACCESS=FILACC(24),FORM=FILFMT(24))
               FLAG=0
               RETURN
   90          FLAG=2
               RETURN
               ELSE
C.....NO
               FLAG=1
               RETURN
               END IF
C
        END IF
C
      ELSE
C.....APTLIB DOES NOT EXIST
        FLAG=3
      END IF
      RETURN
      END
