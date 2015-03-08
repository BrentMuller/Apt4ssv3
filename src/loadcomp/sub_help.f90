! Modified to .f90 from M0000449.F                                    
!******************************************************************** 
!                                                                       
!.....COMPUTER DEPENDENT ROUTINE      HELP.......HL GRAY    12/67  *CD* 
!                                                                       
! PURPOSE      TO PROVIDE A TRACE-BACK IN THE CASE OF A                 
!              CASTASTROPHIC FAILURE.                                   
!                                                                       
! LINKAGE      CALL HELP                                                
!                                                                       
! ARGUMENTS    NONE                                                     
!                                                                       
! NOTES        THE METHOD USED TO OBTAIN THE TRACE-BACK                 
!              MIGHT NEED TO BE CHANGED ON SOME COMPUTERS.              
!                                                                       
! SUBSIDIARIES NONE                                                     
!                                                                       
      SUBROUTINE HELP 
!                                                                       
!...     CATASTROPHIC FAILURE                                           
!...     PRODUCE EXECUTION FAILURE SO AS TO OBTAIN AUTOMATIC TRACE-BACK 
!                                                                       
      DIMENSION Y(1) 
      DO 10 I=100000,1000000,10 
      X=Y(I) 
   10 Y(I)=X 
    1 RETURN 
      END                                           
