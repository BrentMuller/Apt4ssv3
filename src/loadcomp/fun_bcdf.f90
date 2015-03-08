! Modified to .f90 from BCDF0000.F                                   
!*******************************************************************    
!                                                                       
!  * BCDF *  FORTRAN 77 INTEGER FUNCTION  19-DEC-1985  E.MCLELLAN       
!            MODIFIED                      2-FEB-1988  E.MCLELLAN       
!                                                                       
!  PURPOSE:  CONVERT A STRING OF CHARACTERS WHICH OCCUPY THE SAME       
!            NUMBER OF BYTES AS AN INTEGER WORD INTO AN EQUIVALENT      
!            INTEGER VALUE                                              
!                                                                       
!  CALLING SEQUENCE:                                                    
!                   VALUE=BCDF(STR)                                     
!                                                                       
!  ARGUMENTS:                                                           
!                   TYPE       DESCRIPTION                              
!       STR         CHARACTER  STRING TO BE CONVERTED                   
!                                                                       
!  GLOBAL VARIABLES:                                                    
!                                                                       
!---------------------------------------------------                    
!   VARIABLE        BLOCK     TYPE       DESCRIPTION                    
!---------------------------------------------------                    
!   IWRD            SDP       INTEGER    NO. OF BYTES PER WORD          
!   NBCHAR          SDP       INTEGER    NO. OF BITS PER BYTE           
!                                                                       
!  LOCAL VARIABLES:                                                     
!                   TYPE       DESCRIPTION                              
!        I          INTEGER    LOOP COUNT                               
!        BCD        INTEGER    VARIABLE FOR BUILDING UP BCD VALUE       
!        TSTR       CHARACTER  TEMPORARY STORAGE FOR STRING             
!                                                                       
!  FILES:  NONE                                                         
!                                                                       
!  SUBSIDIARIES:  NONE                                                  
!********************************************************************   
      INTEGER FUNCTION BCDF(STR) 
!                                                                       
      INCLUDE 'SDP.INC' 
!                                                                       
      INTEGER  BCD 
      CHARACTER*(*) STR,TSTR*10 
!                                                                       
      BCD=0 
      TSTR=STR//' ' 
      DO 10 I=1,IWRD 
      BCD=ISHFT(BCD,NBCHAR)+ICHAR(TSTR(I:I)) 
   10 END DO 
!                                                                       
      BCDF=BCD 
!                                                                       
      RETURN 
      END                                           
