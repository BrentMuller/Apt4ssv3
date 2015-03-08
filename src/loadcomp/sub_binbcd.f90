! Modified to .f90 from M0000502.F                                    
!********************************************************************                                                                      
!                                                                       
! *  BINBCD  *  FORTRAN 77 SUBROUTINE   E.MCLELLAN  06.85               
!                                                                       
      SUBROUTINE BINBCD(JNTGER,SYMBOL,COUNT) 
      INTEGER COUNT,INTGER,TEN 
      CHARACTER SYMBOL*8,BCD*8,ZERO,BLANK 
      DATA BLANK/' '/,ZERO/'0'/ 
!                                                                       
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
!                                                                       
   20   COUNT=9-J 
        SYMBOL(1:COUNT)=BCD(J:8) 
      ENDIF 
      RETURN 
      END                                           
