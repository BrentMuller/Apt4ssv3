      Program loadcomp  
! Modified to .f90 from M0007342.F                                    
!********************************************************************                                                                      
!                                                                       
!          LOAD COMPLEX MAIN PROGRAM                                    
!                                                                       
!          SUBSIDIARIES                                                 
!          TYPE          ENTRY                                          
!          SUBROUTINE    LOADG                                          
!          SUBROUTINE    LOADM                                          
!          SUBROUTINE    LOADP                                          
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NUMBST:     INDEX OF BEGINNING OF NUMBER SECTION OF CNUMTB           
!  NUMBND:     INDEX OF END OF NUMBER SECTION OF CNUMTB                 
!  NAMTBL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!  CNUMTB:     NUMBER TABLE                                             
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  IBKPNT:     NAMTBL INDEX OF BRKPNT                                   
!*                                                                      
!     PURPOSE      TO READ A CONTROL CARD AND DECIDE WHICH BLOCK        
!                  DATA PROGRAMS IT IS TO GENERATE.                     
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!              IG                 C            READ OFF DATA CARD       
!              IG1                C    'GEOM'  CHECK DATA CARD          
!              IP                 C            READ OFF DATA CARD       
!              IP1                C    'PROC'  CHECK DATA CARD          
!                                                                       
!     NOTES        IF THE CONTROL CARD HAS PROC PUNCHED IN COLUMNS      
!                  1-4 THE PROGRAM WILL CAUSE THE READING OF DATA       
!                  WHICH WILL ENABLE BLOCK DATA PROGRAMS FOR THE        
!                  META CLASSES AND BASIC PRODUCTIONS TO BE PRODUCED.   
!                  IF THE CONTROL CARD HAS GEOM PUNCHED IN COLUMNS      
!                  11-14 IT WILL CAUSE THE READING OF DATA WHICH WILL   
!                  ENABLE BLOCK DATA PROGRAMS FOR THE NAME TABLE,       
!                  POINTERS TO THE NAME TABLE, AND GEOMETRIC            
!                  PRODUCTIONS TO BE PRODUCED.                          
!                                                                       
      CHARACTER*6 BKPNT 
      CHARACTER*4 IG,IG1,IP,IP1 
      DATA  IP1,IG1/'PROC','GEOM'/,BKPNT/'BRKPNT'/ 
!**                                                                     
!...     CLEAR NUMBER TABLE                                             
!                                                                       
      DO 1 I=NUMBST,NUMBND 
        CNUMTB(I)=' ' 
    1 END DO
!                                                                       
!...     READ CONTROL CARD.                                             
!                                                                       
      READ(LCDATA,2) IP,IG 
  2   FORMAT (1A4,6X,1A4) 
!                                                                       
!...     CALL LOADM TO READ META-CLASSES.                               
!                                                                       
      IF ((IP .NE. IP1) .AND. (IG .NE. IG1))  GO TO 5 
      CALL LOADM 
!                                                                       
      IBKPNT = NAME(BKPNT) 
      NAMTBL(IBKPNT) = 99000 
!                                                                       
!...     IS BASIC PRODUCTION TABLE PROCESSING REQUIRED                  
!                                                                       
  3   IF(IP.EQ.IP1)CALL LOADP 
!                                                                       
!...     IS GEOMETRIC PRODUCTION TABLE PROCESSING REQUIRED              
!                                                                       
  4   IF(IG.EQ.IG1)CALL LOADG 
!                                                                       
      STOP 
!                                                                       
!...  CONTROL CARD ERROR                                                
!                                                                       
  5   WRITE (VLFILE,6) 
    6 FORMAT (1H ,90HERROR 7002 IN MAIN.  FIRST INPUT CARD DOES NOT CONT
     *AIN GEOM OR PROC.  NO OUTPUT GENERATED.)
      STOP 
      End Program loadcomp

