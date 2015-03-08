! Modified to .f90 from M0007328.F                                    
!********************************************************************                                                                       
      INTEGER FUNCTION  ORF(A,B) 
!                                                                       
!. THIS ROUTINE IS COMPILER DEPENDENT.                                  
!                                                                       
!  THREE POSSIBLE VERSIONS ARE OUTLINED HERE                            
!                                                                       
!-IBM-VERSION                                                           
!                                                                       
!   THE TRICK USED HERE WILL WORK ON                                    
!   FORTRAN(G) AND (H), IT MAY NOT WORK ON OTHER COMPILERS.             
!      LOGICAL  AL,BL,ORL                                               
!      INTEGER AI,BI,ORI                                                
!      EQUIVALENCE (AL,AI),(BL,BI),(ORI,ORL)                            
!      AI=A                                                             
!      BI=B                                                             
!      ORL=AL.OR.BL                                                     
!      ORF=ORI                                                          
!                                                                       
!-VAX-VERSION                                                           
!                                                                       
      INTEGER A,B 
      ORF=IOR(A,B) 
!                                                                       
!                                                                       
!-PRIME-VERSION                                                         
!                                                                       
!      INTEGER A,B                                                      
!      ORF=OR(A,B)                                                      
!                                                                       
      RETURN 
      END                                           
