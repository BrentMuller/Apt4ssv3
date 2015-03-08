! Modified to .f90 from M0006724.F                                    
!********************************************************************                                                                       
!                                                                       
!              FORTRAN SUBROUTINE NAME                                  
!                                                                       
! LINKAGE       CALL    NAME  (STR)                                     
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    HELP            SUBROUTINE    LOADG            
!                                        SUBROUTINE    LOADM            
!                                        SUBROUTINE    LOADN            
!                                        SUBROUTINE    LOADP            
!                                        SUBROUTINE    INPUT            
!                                                                       
      INTEGER  FUNCTION  NAME  (STR) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMEST:     NAMTBL INDEX OF BEGIN OF THE PART PROGRAM NAME  SECTION  
!  NAMMAX:     NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION     
!  NAMTBL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!*                                                                      
! PURPOSE      TO FIND THE POSITION IN NAMTBL OF A BCD NAME,            
!              AND TO PUT THE NAME INTO NAMTBL IF IT IS NOT             
!              ALREADY THERE.                                           
! ARGUMENTS    STR     CHARACTER STRING CONTAINING THE                  
!              SYMBOLIC NAME.                                           
! NOTES        THE NAMTBL IS SEARCHED USING A HASH TECHNIQUE.           
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!              STR                C            ARGUMENT OF FUNCTION =   
!                                              SYMBOLIC NAME            
!              BCD                I            BCD OF NAME              
!              I                  I            INDEX OF DO LOOP         
!              J                  I            MASK TABLE SEARCH        
!                                              STARTING POINT           
!              NAME               I            FUNCTION NAME            
!                                                                       
      CHARACTER*6 STR 
!**                                                                     
!**   CALCULATE BCD                                                     
!                                                                       
      BCD=BCDF(STR(1:4)) 
!                                                                       
!...     FIND STARTING PLACE IN TABLE.                                  
!                                                                       
   10 J=MOD(BCD,NAMMAX-NAMEST) 
      IF (J.LT.0) THEN 
        J=J+NAMMAX 
      ELSE 
        J=J+NAMEST 
      ENDIF 
!                                                                       
!...     SEARCH FROM THERE UP TO TOP OF TABLE.                          
!                                                                       
      DO 20 I = J,NAMMAX 
!                                                                       
!...     IS THERE AN ENTRY AT THIS LOCATION                             
!                                                                       
      IF (NAMTBL(I).EQ.0) GOTO 40 
!                                                                       
!...     YES. IS IT THIS NAME                                           
!                                                                       
      IF(CNAMTB(I).EQ.STR)GOTO 100 
!                                                                       
!...     NO. CONTINUE SEARCH.                                           
!                                                                       
   20 END DO 
!                                                                       
!...     NOT IN THAT PART OF TABLE - SEARCH FROM BOTTOM TO STARTING PT. 
!                                                                       
      DO 30 I = NAMEST,J 
!                                                                       
!...     IS THERE AN ENTRY AT THIS LOCATION                             
!                                                                       
      IF (NAMTBL(I).EQ.0) GOTO 40 
!                                                                       
!...     YES. IS IT THIS NAME                                           
!                                                                       
      IF(CNAMTB(I).EQ.STR)GOTO 100 
!                                                                       
!...     NO. CONTINUE SEARCH.                                           
!                                                                       
   30 END DO 
!                                                                       
!...     TABLE FULL - ISSUE DIAGNOSTIC                                  
!                                                                       
      WRITE(VLFILE,999) 
  999 FORMAT (1H ,54HERROR NO. 3001 IN SUBROUTINE NAME. NAME TABLE OVERF&
     &LOW)                                                              
      CALL HELP 
      RETURN 
!                                                                       
!...     NAME IS NOT IN TABLE - PUT IT IN                               
!                                                                       
   40 CNAMTB(I) = STR 
!                                                                       
!...     ENTRY IF NAME FOUND.                                           
!...     IS THIS A SYNONYM                                              
!                                                                       
  100 IF (NAMTBL(I).LT.0) GOTO 110 
!                                                                       
!...     NO. RETURN INDEX.                                              
!                                                                       
      NAME = I 
      RETURN 
!                                                                       
!...     YES. RETURN INDEX OF SYNONYM                                   
!                                                                       
  110 NAME = -NAMTBL(I) 
      RETURN 
      END                                           
