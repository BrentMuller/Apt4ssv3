! Modified to .f90 from M0007340.F                                    
!********************************************************************                                                                       
!                                                                       
!              FORTRAN SUBROUTINE INPUT                                 
!                                                                       
! LINKAGE       CALL   INPUT                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          INTEGER FCT.  NAME            SUBROUTINE    LOADI            
!          SUBROUTINE    READ                                           
!          SUBROUTINE    SHIFT                                          
!                                                                       
      SUBROUTINE INPUT 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMTBL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!                                                                       
!        2.    STACK AND POINTER STORAGE                                
!                                                                       
      COMMON/STKLST/STKLST 
      DIMENSION STKLST(3002),STACK(2,1500) 
!  TOP:        POINTER TO LAST STACK ENTRY                              
      EQUIVALENCE (TOP,STKLST(1)) 
!  STACK:      WORKING STACK                                            
      EQUIVALENCE (STACK(1,1),STKLST(3)) 
!                                                                       
!        5.    CLASS CODE MODULI                                        
!                                                                       
!  MODULO:     NAMTBL CLASS AND CODE FACTOR 1000 TO DEVIDE OUT CLASS    
      COMMON/MODULI/MODULO 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!*                                                                      
! PURPOSE      TO PLACE IN THE FIRST COLUMN OF STACK THE INDEX          
!              IN NAMTBL OF THE NEXT ITEM IN THE INPUT STREAM.          
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              BLANK              C        ' ' BLANK WORD               
!              CNT                I            COUNT OF CHARACTERS      
!                                              FETCHED FROM INCHAR      
!              ENDFL              L            FLAG FOR LAST ITEM ON    
!                                              CARD                     
!              EXPIND             I        66  NAMTBL INDEX FOR END OF  
!                                              CARD                     
!              I                  I            MODE OF CHARACTER        
!              II                 I            NAMTBL POINTER FOR NEXT  
!                                              CHARACTER                
!              INCHAR       72    I            FOR READ TO PLACE FIRST  
!                                              72 CHARS ON A CARD IN    
!              J                  I            NAMTBL POINTER           
!              SAVE               L    .FALSE. FLAG IF NEXT ITEM HAS    
!                                              BEEN SAVED.              
!              SEQNO              C*8          FOR READ TO PLACE        
!                                              SEQUENCE NO. IN          
!              SYM                L            FLAG SET WHEN A SYMBOL   
!                                              (NOT A NO.) IS BEING     
!                                              FORMED                   
!              WDFL               L            FLAG SET WHEN            
!                                              CONCATINATION IS IN      
!                                              PROGRESS                 
!              WORD               C*6          TEMPORARY STORAGE OF     
!                                              CHARS. WHILE WORD IS     
!                                              FORMED                   
!              XI                 I            NAMTBL POINTER           
!              PTR                I            NAMBTL POINTER           
!              CLASS              I            CLASS NUMBER             
!                                                                       
      LOGICAL   SAVE,SYM,WDFL,ENDFL,ERRFL 
      DIMENSION INCHAR(73) 
      CHARACTER SEQNO*8,WORD*6,BLANK 
      DATA ENDFL,SAVE/.TRUE.,.FALSE./ 
      DATA INCHAR(73)/1/ 
      DATA EXPIND,BLANK/51,' ' / 
!**                                                                     
!...     IS NEW ITEM REQUIRED                                           
!                                                                       
      IF(SAVE) GO TO 10 
!                                                                       
!...     YES. IS NEW CARD REQUIRED                                      
!                                                                       
      IF(.NOT.ENDFL) GO TO 8 
!                                                                       
!...     YES. SET FLAGS                                                 
!                                                                       
      SAVE = .FALSE. 
      SYM = .FALSE. 
      WDFL = .FALSE. 
      ENDFL = .FALSE. 
!                                                                       
!...     READ NEXT CARD                                                 
!                                                                       
    2 CALL READ(INCHAR,SEQNO) 
      CNT=0 
      ERRFL=.TRUE. 
!                                                                       
!...     HAVE WE REACHED THE END OF THIS CARD                           
!                                                                       
    8 IF(CNT.EQ.72) GO TO 20 
!                                                                       
!...     NO. FETCH NEXT CHARACTER FROM INCHAR                           
!                                                                       
      CNT = CNT + 1 
      II = INCHAR(CNT) 
!                                                                       
!...     IS THIS A VALID CHARACTER                                      
!                                                                       
      IF (NAMTBL(II).NE.0) GOTO 7 
!                                                                       
!...     NO. REJECT CHARACTER AND PRODUCE DIAGNOSTIC                    
!                                                                       
      IF(ERRFL)WRITE(VLFILE,3) SEQNO 
    3 FORMAT(1H ,73HERROR NO. 7001 IN SUBROUTINE INPUT. INVALID CHARACTE&
     &R. CARD SEQUENCE NO.=,A8)                                         
      ERRFL=.FALSE. 
      GO TO 8 
    7 I = NAMTBL(II)/MODULO 
!                                                                       
!...     IS CHARACTER $                                                 
!                                                                       
      IF(I.EQ.15) GO TO 400 
!                                                                       
!...     IS CHARACTER .                                                 
!                                                                       
      IF(I.EQ.21)GO TO 1500 
!                                                                       
!...     TAKE APPROPRIATE ACTION FOR EACH TYPE OF CHARACTER             
!                                                                       
      GO TO (100,200,300,400,500,600,700,800,900,1000,1100,1200,1300),I 
      WRITE(VLFILE,4) CNT,SEQNO 
    4 FORMAT(1H ,46HERROR 7037 IN SUBROUTINE INPUT. CHARACTER NO. ,I3,  &
     & 37HILLEGAL, IGNORED.  CARD SEQUENCE NO.=,A8)                     
      GOTO 8 
!                                                                       
!...     PUT NAMTBL INDEX OF ITEM IN PTR                                
!                                                                       
   10 PTR = II 
      SAVE = .FALSE. 
      GO TO 2000 
!                                                                       
!...     END OF CARD REACHED                                            
!                                                                       
   20 II=EXPIND 
      ENDFL=.TRUE. 
      GO TO 1500 
!                                                                       
!...     ,                                                              
!                                                                       
  100  GO TO 1500 
!                                                                       
!...     (                                                              
!                                                                       
  200  GO TO 1500 
!                                                                       
!...     )                                                              
!                                                                       
  300  GO TO 1500 
!                                                                       
!...     $  FETCH NEXT CHARACTER                                        
!                                                                       
  400 J = INCHAR(CNT+1) 
!                                                                       
!...     IF $ THIS IS END OF CARD                                       
!                                                                       
      IF (NAMTBL(J).EQ.15000) GOTO 20 
!                                                                       
!...     NOT $ - THEREFORE CONTINUED ON NEXT CARD                       
!                                                                       
      GO TO 2 
!                                                                       
!...     /                                                              
!                                                                       
  500  GO TO 1500 
!                                                                       
!...     -                                                              
!                                                                       
  600  GO TO 1500 
!                                                                       
!...     +                                                              
!                                                                       
  700  GO TO 1500 
!                                                                       
!...     =                                                              
!                                                                       
  800  GO TO 1500 
!                                                                       
!...     *                                                              
!                                                                       
  900 GO TO 1500 
!                                                                       
!...     NUMERIC DIGIT                                                  
!                                                                       
 1000 GO TO 1600 
!                                                                       
!...     LETTER - SET SYMBOL FLAG                                       
!                                                                       
 1100 SYM = .TRUE. 
      GO TO 1600 
!                                                                       
!...     '                                                              
!                                                                       
 1200 GO TO 1500 
!                                                                       
!...     BLANK                                                          
!                                                                       
 1300 GO TO 8 
!                                                                       
!...     IS AN ITEM PARTIALLY FORMED                                    
!                                                                       
 1500 IF(.NOT.WDFL) GO TO 10 
!                                                                       
!...     YES. SET SAVE MARKER. THEN SET WORD(3) TO CLASS NUMBER IF      
!...     THIS IS NOT A SYMBOL, TO CLASS IDENT IF IT IS.                 
!                                                                       
      SAVE = .TRUE. 
      IF (.NOT.SYM) CLASS=10000 
      IF (SYM)      CLASS=35000 
!                                                                       
!...     CLEAR SYMBOL AND WORDFILL FLAGS, AND FIND NAMTBL INDEX OF      
!...     THIS ITEM. SET COLUMN 1 OF NAMTBL IF THIS IS THE FIRST         
!...     OCCURRENCE OF THIS ITEM.                                       
!...     STORE NAMTBL INDEX OF ITEM IN PTR                              
!                                                                       
      SYM = .FALSE. 
      WDFL = .FALSE. 
      XI = NAME(WORD) 
      IF (NAMTBL(XI).EQ.0) NAMTBL(XI)=CLASS 
      PTR = XI 
      GO TO 2000 
!                                                                       
!...     ITEM NAME IS TO BE FORMED BY CONCATINATION.                    
!...     HAS THIS STARTED YET                                           
!                                                                       
 1600 IF(WDFL) GO TO 1610 
!                                                                       
!...     NO. CLEAR WORD AND SET WORDFILL FLAG                           
!                                                                       
      WORD = BLANK 
      WDFL = .TRUE. 
!                                                                       
!...     PUT CHARACTER IN NEXT VACANT POSITION                          
!                                                                       
 1610 CALL SHIFT(WORD,CNAMTB(II)) 
      GO TO 8 
!                                                                       
!...     PUT NAMTBL POINTER TO ITEM IN STACK AND RETURN                 
!                                                                       
 2000 TOP = TOP+1 
      STACK(1,TOP) = PTR 
      RETURN 
      END                                           
