**** SOURCE FILE : LIBSCH00.IBM;2   ***
*
      SUBROUTINE LIBSCH(MEMBER,FLAG)
*
*  * LIBSCH *  VAX-11 FORTRAN 77 VERSION  27.09.82  E.MCLELLAN
*                               MODIFIED  30.10.86  E.MCLELLAN
*                MODIFIED                25-FEB-1988  E.MCLELLAN
*
*  PURPOSE     TO SEARCH SUBDIRECTORY [.APTLIB] FOR A GIVEN
*              MEMBER FILE AND TO OPEN SAID FILE
*  CALLING SEQUENCE
*              CALL LIBSCH(MEMBER,FLAG)
*  ARGUMENTS
*              MEMBER    CHARACTER STRING CONTAINING THE
*                        MEMBER NAME (BCD LEFT JUSTIFIED)
*              FLAG      0 = MEMBER FOUND
*                        1 = MEMBER NOT FOUND IN SUBDIRECTORY
*                        2 = ERROR OPENING FILE
*                        3 = SUBDIRECTORY [.APTLIB] DOES NOT EXIST
*                        4 = LIBSCH IS CALLED BEFORE COMPLETING THE
*                            PROCESSING OF PREVIOUS MEMBER
*
      CHARACTER*(*) MEMBER
      INTEGER FLAG
C
      INCLUDE (FILTAB)
C
      CHARACTER*8 MEMNAM
      COMMON/CLIBCM/MEMNAM
      COMMON/LIBCOM/IEOF
C
      CHARACTER FLNAME*20,TYPE*4,MODE*2
      INTEGER NLEN,JRET
      LOGICAL OD,EX
C
      DATA TYPE/' TXT'/,MODE/' A'/
C
C
      ID=U(24)
C
C.....HAS PROCESSING OF PREVIOUS MEMBER BEEN COMPLETED
         IF (IEOF.EQ.0) THEN
C.....NO
             FLAG=4
             RETURN
C.....YES - SET UP FILE NAME FOR MEMBER
         ELSE
            NLEN=LEN(MEMBER)
            K=INDEX(MEMBER,' ')
            IF (K.NE.0) NLEN=K-1
            FLNAME=MEMBER(:NLEN)//TYPE//MODE
            NLEN=NLEN+6
C
C.....STORE MEMBER NAME AND RESET EOF FLAG
            MEMNAM=MEMBER
            IEOF=0
C.....DOES FILE EXIST
            CALL UOPEN(ID,FLNAME(:NLEN),1,4,80,0,'FB',0,JRET)
               IF (JRET.EQ.0) THEN
C.....YES
                 CALL UOPEN(ID,FLNAME(:NLEN),1,1,80,0,'FB',0,JRET)
                 IF (JRET.EQ.0) THEN
                   FLAG=0
                 ELSE
                   FLAG=2
                 ENDIF
               ELSE
C.....NO
                 FLAG=1
               END IF
C
        END IF
      RETURN
      END
