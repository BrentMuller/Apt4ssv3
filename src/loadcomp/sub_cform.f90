! Modified to .f90 from CFORM000.F                                   
!********************************************************************   
!                                                                       
!  * CFORM *  FORTRAN 77 SUBROUTINE  26.10.84  E.MCLELLAN               
!                                                                       
!  PURPOSE:  TO INSERT A CHARACTER STRING IN A CHARACTER BUFFER         
!            AT LOCATION POSN.                                          
!            THE LENGTH OF THE STRING IS RETURNED IF THE ARGUMENT       
!            LENGTH IS ZERO ON INPUT.                                   
!                                                                       
!  CALLING SEQUENCE:                                                    
!                   CALL CFORM(STRING,BUFFER,POSN,LENGTH)               
!                                                                       
!  ARGUMENTS:                                                           
!                   TYPE       DESCRIPTION                              
!       STRING      CHARACTER  CHARACTER STRING TO BE INSERTED          
!       BUFFER      CHARACTER  CHARACTER BUFFER INTO WHICH              
!                              STRING IS TO BE INSERTED                 
!       POSN        INTEGER    LOCATION IN CHARACTER BUFFER             
!                              AT WHICH STRING IS TO BE INSERTED        
!       LENGTH      INTEGER    LENGTH OF STRING                         
!                              IF = 0 ON INPUT, ACTUAL LENGTH           
!                              IS RETURNED TO CALLING ROUTINE           
!                                                                       
!  GLOBAL VARIABLES:  NONE                                              
!                                                                       
!  LOCAL VARIABLES:  NONE                                               
!                                                                       
!  FILES:  NONE                                                         
!                                                                       
!  SUBSIDIARIES:  NONE                                                  
!                                                                       
      SUBROUTINE CFORM(STRING,BUFFER,POSN,LENGTH) 
!                                                                       
      CHARACTER STRING*(*),BUFFER*(*) 
      INTEGER POSN,LENGTH 
!                                                                       
!.....IF LENGTH IS ZERO ON INPUT RETURN ACTUAL LENGTH OF STRING         
!                                                                       
      IF (LENGTH.EQ.0) THEN 
         LENGTH=LEN(STRING) 
      ENDIF 
!                                                                       
!.....INSERT CHARACTER STRING IN PRINT BUFFER                           
!                                                                       
      BUFFER(POSN:POSN+LENGTH-1)=STRING(1:LENGTH) 
!                                                                       
      RETURN 
      END                                           