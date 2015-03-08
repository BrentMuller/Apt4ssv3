! Modified to .f90 from SHIFT000.F                                    
!********************************************************************                                                                       
      SUBROUTINE SHIFT(WORD,JCHAR) 
!                                                                       
!  *  SHIFT  *  VAX11 VERSION   4.10.85    E.MCLELLAN                   
!                                                                       
!  PURPOSE     TO APPEND A SINGLE CHARACTER 'JCHAR' TO THE CHARACTER    
!              STRING BEING SET UP IN 'WORD' TO FORM A LEFT-JUSTIFIED   
!              'NAME' IN 'WORD'                                         
!                                                                       
!  CALLING SEQUENCE                                                     
!              CALL SHIFT(WORD,JCHAR)                                   
!  ARGUMENTS   WORD   CHARACTER STRING IN WHICH A 'NAME'                
!                     IS BEING BUILT UP                                 
!              JCHAR  CONTAINS THE NEXT CHARACTER (LEFT JUSTIFIED)      
!                     TO BE PLACED IN WORD                              
!                                                                       
      CHARACTER*6 WORD,JCHAR,TEMP 
!                                                                       
      J=INDEX(WORD(1:),' ') 
      IF(J.NE.0) THEN 
       WORD(J:J)=JCHAR(1:1) 
      ELSE 
!  LEFT SHIFT CONTENTS OF WORD AND APPEND CHARACTER                     
       TEMP=WORD(2:6)//JCHAR(1:1) 
       WORD=TEMP 
      ENDIF 
      RETURN 
      END                                           
