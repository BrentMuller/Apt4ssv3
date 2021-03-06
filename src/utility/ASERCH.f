**** SOURCE FILE : ASERCH00.V01   ***
*
      SUBROUTINE ASERCH(NO,IRECNO,IRET)
*
*  * ASERCH *  VAX-11 FORTRAN 77 VERSION   13.10.82  E.MCLELLAN
*
*  PURPOSE     TO POSITION A FILE TO START OF REQUIRED RECORD
*
*  CALLING SEQUENCE
*              CALL ASERCH(NO,IRECNO,IRET)
*  ARGUMENTS
*              NO         FILE NUMBER
*              IRECNO     REQUIRED RECORD
*              IRET.LT.0  NORMAL RETURN
*                  .EQ.0  ZERO OR NEGATIVE RECORD NUMBER
*                  .EQ.2  ABNORMAL CONDITION RETURNED BY ATAPRD
*                  .EQ.3  ERROR BACKSPACING FILE
*                  .EQ.4  ERROR REWINDING FILE
*
*  ALTERNATE ENTRY    ****    COMMENTED OUTT   ****
*              CALL SEARCH(NO,IRECNO,IRET)
*
      INTEGER NO(2)
C
      DOUBLE PRECISION REC(256)
      DIMENSION IREC(3)
C
C      ENTRY SEARCH(NO,IRECNO,IRET)
C
C.....CHECK VALUE IN IRECNO - MUST BE GT ZERO
      IF (IRECNO.LE.0) THEN
         IRET=0
         RETURN
      ELSE
         IREW=0
C
C.....READ NEXT RECORD FROM FILE
   10 CALL ATAPRD(NO,IRET,NWDS,2,IREC,3,REC,0)
           IF (IRET.LT.0) THEN
C.....IS THIS THE RECORD BEFORE THE REQUIRED RECORD
              IF (IREC(1).EQ.IRECNO-1) THEN
C.....YES SO NEXT RECORD WILL BE THE REQUIRED RECORD
                 RETURN
C.....NO IS NEXT RECORD LT REQUIRED RECORD - READ NEXT RECORD
              ELSE IF (IREC(1)+1.LT.IRECNO) THEN
C.....YES
                 GO TO 10
C.....N0  IS REQUIRED RECORD NEARER START OF FILE OR CURRENT RECORD
              ELSE IF (IRECNO.GT.IREC(1)/2) THEN
C.....NEARER CURRENT RECORD - BACKSPACE N TIMES BY CALLING ATAPOP
                 N=IREC(1)-IRECNO+1
                 DO 20 I=1,N
                 CALL ATAPOP(NO,3,IRET)
                      IF (IRET.GT.0) THEN
                         IRET=3
                         RETURN
                      END IF
   20            CONTINUE
                 RETURN
C.....NEARER START - REWIND AND SEARCH
              ELSE
                 CALL ATAPOP(NO,1,IRET)
                      IF (IRET.GT.0) THEN
                         IRET=4
                         RETURN
                      ELSE
                         GO TO 10
                      END IF
              END IF
C.....NON NORMAL RETURN FROM ATAPRD
         ELSE IF (IRET.EQ.0) THEN
C.....EOF ENCOUNTERED
             IF (IREW.EQ.1) THEN
                IRET=0
                RETURN
             ELSE
C.....REWIND FILE
            CALL ATAPOP(NO,1,IRET)
                 IF (IRET.GT.0) THEN
                    IRET=4
                    RETURN
                 ELSE
                    IREW=1
                    GO TO 10
                 END IF
             END IF
         ELSE
C.....ABNORMAL CONDITION RETURNED BY ATAPRD
            IRET=2
            RETURN
         END IF
      END IF
      RETURN
      END
