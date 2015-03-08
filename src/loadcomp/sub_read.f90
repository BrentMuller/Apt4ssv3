! Modified to .f90 from M0006725.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE READ                                  
!                                                                       
! LINKAGE       CALL   READ(INCHAR,SEQNO)                               
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    HELP            SUBROUTINE    INPUT            
!                                                                       
      SUBROUTINE READ(INCHAR,SEQNO) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!*                                                                      
! PURPOSE      TO READ AND LIST A CARD IMAGE, AND PLACE IN A 72 WORD    
!              ARRAY THE INDEX TO THE NAMTBL OF THE CHARACTERS          
!              CONTAINED IN THE RECORD, ONE INDEX PER CHARACTER.        
!                                                                       
! ARGUMENTS    ARRAY     A 72 WORD ARRAY INTO WHICH IS PLACED INDICES   
!                        TO THE NAMTBL OF THE FIRST 72 CHARACTERS       
!                        OF THE RECORD.                                 
!              SEQNO     A DOUBLE WORD INTO WHICH IS PLACED THE         
!                        SEQUENCE NUMBER OF THE RECORD.                 
!                                                                       
!     VARIABLES                    INITIAL                              
!         NAME  DIMENSION TYPE     VALUE  EQUIV  DESCRIPTION            
!                                                                       
!         I               I                      DO LOOP INDEX          
!                                                                       
!         II              I        0             POINTER TO LOCATION    
!                                                OF CHARACTER IN LIST   
!                                                OF VALID CHARACTERS    
!                                                                       
!         VALIDC          C*NVLD                 LIST OF VALID          
!                                                CHARACTERS             
!                                                                       
!         CONV   NVLD     I        DATA          INDEX OF VALID         
!                                  DEF           CHARACTERS IN NAMTBL   
!                                                                       
!         RDCHAR          C*80                   READ AREA              
!                                                                       
!         INCHAR 72       I                      INDEX TO NAMTBL FOR    
!                                                EACH CHARACTER READ    
!                                                                       
!         SEQNO           C*8                    SEQUENCE NUMBER        
!                                                OF RECORD              
!                                                                       
      DIMENSION INCHAR(76) 
      PARAMETER (NVLD=53) 
      CHARACTER RDCHAR*80,SEQNO*8,VALIDC*(NVLD) 
      DIMENSION CONV(NVLD) 
!                                                                       
      DATA          II/0/ 
!                                                                       
!    LIST OF VALID NUMBERS                                              
!                                                                       
      DATA VALIDC( 1:10)/'0123456789'/ 
      DATA VALIDC(11:36)/'ABCDEFGHIJKLMNOPQRSTUVWXYZ'/ 
      DATA VALIDC(37:48)/' +-*/=.,''()$'/ 
!  ASCII/EBCDIC REPRESENTATION OF BCDIC CHARACTERS ()+='                
      DATA VALIDC(49:53)/'%<&#@'/ 
!                                                                       
!                   CONV TABLE                                          
!                                                                       
!                 0   1   2   3   4   5   6   7   8   9                 
      DATA CONV/  2,  3,  4,  5,  6,  7,  8,  9, 10, 11,                &
     &           15, 16, 17, 18, 19, 20, 21, 22, 23,                    &
     &           27, 28, 29, 30, 31, 32, 33, 34, 35,                    &
     &           40, 41, 42, 43, 44, 45, 46, 47,                        &
     &           38, 14, 26, 37, 39, 12, 24, 48, 13, 49, 25, 36,        &
     &           49, 25, 26, 12, 13/                                    
!                 A   B   C   D   E   F   G   H   I                     
!                 J   K   L   M   N   O   P   Q   R                     
!                 S   T   U   V   W   X   Y   Z                         
!                SP   +   -   *   /   =   .   ,   '   (   )   $         
!                 %   <   &   #   @                                     
!                                                                       
!**                                                                     
!                   READ CARD IMAGE                                     
      READ(LCDATA,20,END=50) RDCHAR 
   20 FORMAT (A80) 
      WRITE(VLFILE,30) RDCHAR 
   30 FORMAT (1H ,4X,A80) 
!                                                                       
!...                SET UP INDEX TO CHAR PORTION OF NAMTBL              
!                                                                       
      DO 40 I=1,72 
!                    ONE CHARACTER                                      
      II=INDEX(VALIDC,RDCHAR(I:I)) 
!                    LOC OF CHARACTER IN NAMTBL                         
      IF (II.EQ.O) THEN 
         INCHAR(I)=0 
      ELSE 
         INCHAR(I)=CONV(II) 
      ENDIF 
   40 END DO 
!                                                                       
      SEQNO=RDCHAR(73:80) 
!                                                                       
      RETURN 
!        ......... MODIFY FOR THE REAL WORLD...........                 
   50 CALL HELP 
      RETURN 
      END                                           
