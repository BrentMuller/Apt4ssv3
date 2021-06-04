**** SOURCE FILE : NNTAIN00.ORG   ***
*
      INTEGER FUNCTION NNTAIN(A,B,C)
*
*  * NNTAIN *  VAX11 FORTRAN 77 VERSION  27.8.82  E.MCLELLAN
*
*  PURPOSE     TO TEST IF A FLOATING POINT NUMBER LIES
*              WITHIN A CLOSED INTERVAL
*
*  CALLING SEQUENCE
*              IF (NNTAIN(A,B,C)) 1,2,3
*  ARGUMENTS
*              A IS ONE LIMIT OF THE CLOSED INTERVAL
*              B IS FLOATING POINT NUMBER TO BE TESTED
*                TO SEE IF IT FALLS IN THE CLOSED INTERVAL
*              C IS THE OTHER LIMIT OF THE CLOSED INTERVAL
*
*              INTEGER RETURNED = 1  IF B LIES IN CLOSED INTERVAL
*                               =-1  IF B DOES NOT LIE IN CLOSED
*                                    INTERVAL
*                               = 0  IF ERROR CONDITION APPLIES
*                                    I.E. A=C
*
      DOUBLE PRECISION A,B,C,LOW,HIGH
C
      IF (A.EQ.C) THEN
C.....ERROR CONDITION A=C
         NNTAIN=0
         RETURN
      ELSE
C.....SET UP UPPER AND LOWER LIMITS TO CLOSED INTERVAL
         IF (A.GT.C) THEN
            LOW=C
            HIGH=A
         ELSE
            LOW=A
            HIGH=C
         END IF
C.....TEST IF B WITHIN CLOSED INTERVAL
         IF ((B.GE.LOW).AND.(B.LE.HIGH)) THEN
C.....YES
            NNTAIN=1
            RETURN
         ELSE
C.....NO
            NNTAIN=-1
            RETURN
         END IF
      END IF
      END
