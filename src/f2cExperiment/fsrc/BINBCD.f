**** SOURCE FILE : M0000502.W01   ***
*
C
C *  BINBCD  *  FORTRAN 77 SUBROUTINE   E.MCLELLAN  06.85
C
      SUBROUTINE BINBCD(JNTGER,SYMBOL,COUNT)
      INTEGER COUNT,INTGER
      CHARACTER SYMBOL*(*),BCD*8,ZERO,BLANK
      DATA BLANK/' '/,ZERO/'0'/
C
      INTGER=JNTGER
      COUNT=0
      BCD=BLANK
      IF(INTGER.LT.0) THEN
        SYMBOL=BCD
      ELSE
        WRITE(BCD,'(I8)') INTGER
        DO 10 I=1,8
          IF (BCD(I:I).NE.BLANK) THEN
            J=I
            GOTO 20
          ENDIF
   10   CONTINUE
C
   20   COUNT=9-J
        SYMBOL=BCD(J:8)//BLANK
      ENDIF
      RETURN
      END