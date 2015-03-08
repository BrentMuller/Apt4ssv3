! Modified to .f90 from m0000448.F                                    
!********************************************************************   
!                                                                       
! *  BCDBIN  *  FORTRAN 77 SUBROUTINE      E.MCLELLAN  06.85            
!                                                                       
! PURPOSE      TO CONVERT AN INTEGER FROM BCD TO BINARY.                
!                                                                       
! LINKAGE      CALL BCDBIN (WORD, I, COUNT)                             
!                                                                       
! ARGUMENTS    WORD     CONTAINS THE BCD REPRESENTATION OF              
!                       THE NUMBER, LEFT JUSTIFIED.                     
!              I        WILL CONTAIN THE BINARY INTEGER                 
!              COUNT    WILL CONTAIN A COUNT OF THE NUMBER              
!                       OF DIGITS IN THE NUMBER.                        
!                                                                       
!                                                                       
! SUBSIDIARIES TYPE                ENTRY                                
!              SUBROUTINE          HELP                                 
!                                                                       
!                                                                       
      SUBROUTINE BCDBIN(WORD,I,COUNT) 
!                                                                       
      INTEGER I,COUNT 
      CHARACTER WORD*8,W*8,CHAR,PERIOD,BLANK,ZERO 
!                                                                       
      DATA PERIOD/'.'/,BLANK/' '/,ZERO/'0'/ 
!                                                                       
      W=WORD 
      I=0 
      DO 300 J=1,8 
      COUNT=J 
      CHAR=W(J:J) 
      IF( CHAR   .EQ.PERIOD.OR. CHAR   .EQ.BLANK) GOTO 100 
      NUM=ICHAR(CHAR)-ICHAR(ZERO) 
      IF(NUM .GT.9.OR.NUM .LT.0) CALL HELP 
      I=I*10+NUM 
  300 END DO 
  200 RETURN 
  100 COUNT=COUNT-1 
      GOTO 200 
      END                                           
