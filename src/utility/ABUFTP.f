**** SOURCE FILE : ABUFTP00.V01   ***
*
      SUBROUTINE ABUFTP(NO,N)
*
*  *  ABUFTP  *  VAX-11 VERSION   08.07.82  E.MCLELLAN
*
*  PURPOSE     TO PROVIDE FILE HANDLING  CAPABILITY
*              COMPATABLE  WITH APT 111 POST PROCESSOR USAGE
*
*  CALLING SEQUENCE
*              CALL ABUFTP(NO,N)
*  ARGUMENTS
*              NO    FILE NUMBER
*                    FOR NC 360 HELD IN SECOND HALF
*                    OF REAL*8 WORD
*              N=1   OPEN FILE IN WRITE MODE
*               =2   OPEN FILE IN READ MODE
*               =3   REWIND FILE
*               =9   CLOSE FILE
*
*  ALTERNATIVE ENTRY
*              CALL BUFFTP(NO,N)
*
      INCLUDE 'FILTAB.INC'
*
      INTEGER NO(2)
      LOGICAL OD
C
      INCLUDE 'DARRAY.INC'
C
*
      ENTRY BUFFTP(NO,N)
C
C
      IFIL=NO(1)
      IF (NO(1).EQ.0) IFIL=NO(2)
C
      IF ((IFIL.LT.1).OR.(IFIL.GT.50)) THEN
         CALL CFORM(' *** FILE NUMBER OUTSIDE RANGE 1-50',DARRAY,2,35)
         CALL CFORM(' REQUESTED IN CALL TO ABUFTP OR BUFFTP ***',DARRAY
     1              ,37,42)
         CALL CPRINT(DARRAY)
         CALL ABNEND
      ELSE
         ID=U(IFIL)
C
        IF (N.EQ.1) THEN
C....    OPEN FILE IN WRITE MODE
C
       INQUIRE (UNIT=ID,OPENED=OD)
       IF (OD) THEN
       RETURN
       ELSE
         CALL FILOPN(IFIL)
       END IF
C
        ELSE IF (N.EQ.2) THEN
C
C.....   OPEN FILE IN READ MODE
C
        INQUIRE (UNIT=ID,OPENED=OD)
        IF (OD) THEN
        RETURN
        ELSE
         CALL FILOPN(IFIL)
        END IF
C
        ELSE IF (N.EQ.3) THEN
C
C.....   REWIND FILE
C
         CALL TAPOP(IFIL,-4)
C
        ELSE IF (N.EQ.9) THEN
C
C.....   CLOSE FILE
C
         CALL TAPOP(IFIL,-3)
C
        ELSE
C
C.....   INVALID ARGUMENT
C
        CALL CFORM(' *** INVALID ARGUMENT IN CALL TO ABUFTP(BUFFTP) ***'
     1              ,DARRAY,2,51)
        CALL CPRINT(DARRAY)
        CALL ABNEND
C
        END IF
      END IF
      RETURN
      END
