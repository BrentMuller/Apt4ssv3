! Modified to .f90 from M0006713.F                                    
!********************************************************************                                                                       
!                                                                       
!              FORTRAN SUBROUTINE LOADI                                 
!                                                                       
! LINKAGE       CALL   LOADI(SWITCH)                                    
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    INPUT           SUBROUTINE    LOADB            
!          SUBROUTINE    SPILL           SUBROUTINE    LOADG            
!                                        SUBROUTINE    LOADP            
!                                        SUBROUTINE    LOADT            
!                                                                       
      SUBROUTINE LOADI(SWITCH) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMTBL:INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY                
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!                                                                       
!        2.    STACK AND POINTER STORAGE                                
!                                                                       
      COMMON/STKLST/STKLST 
      DIMENSION STKLST(3002),STACK(2,1500) 
!  TOP:        POINTER TO LAST STACK ENTRY                              
      EQUIVALENCE (TOP,STKLST(1)) 
!  MCTOP:      VALUE OF POSTN FOR MBKPNT                                
      EQUIVALENCE (MCTOP,STKLST(2)) 
!  STACK:      WORKING STACK                                            
      EQUIVALENCE (STACK(1,1),STKLST(3)) 
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150),RTERM(2),SLASH(2),DIGIT(2),IDENT(2),CONGEO(2 &
     &          ),CONBIG(2)                                             
!  RTERM:      (1)=CODE CLASS  4000,(2)=NAMTBL INDEX OF 'RTERM '        
      EQUIVALENCE (RTERM(1),CODES(7)) 
!  SLASH:      (1)=CODE CLASS  5000,(2)=NAMTBL INDEX OF '/     '        
      EQUIVALENCE (SLASH(1),CODES(9)) 
!  DIGIT:      (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
!  IDENT:      (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT '        
      EQUIVALENCE (IDENT(1),CODES(69)) 
!  CONGEO:     (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO'        
      EQUIVALENCE (CONGEO(1),CODES(77)) 
!  CONBIG:     (1)=CODE CLASS 43000,(2)=NAMTBL INDEX OF 'CONBIG'        
      EQUIVALENCE (CONBIG(1),CODES(85)) 
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
!  ELFILE:     I/O FILE NUMBER OF TRANSFORMED PRODUCTION TABLE          
      EQUIVALENCE (ELFILE,SYMFIL(4)) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QASSOC:     DIMENSION OF ARRAY ASSOC                                 
      EQUIVALENCE (QASSOC,LDXSIZ(4)) 
!  QGEOML:     DIMENSION OF ARRAY GEOMLC                                
      EQUIVALENCE (QGEOML,LDXSIZ(5)) 
!  QLENGT:     DIMENSION OF ARRAY LENGTH                                
      EQUIVALENCE (QLENGT,LDXSIZ(6)) 
!  QPRODN:     DIMENSION OF ARRAY PRODN                                 
      EQUIVALENCE (QPRODN,LDXSIZ(7)) 
!  QWORK:      DIMENSION OF ARRAY WORK AND LEVPOS                       
      EQUIVALENCE (QWORK,LDXSIZ(9)) 
!  QKDENT:     DIMENSION OF ARRAY KDENT                                 
      EQUIVALENCE (QKDENT,LDXSIZ(16)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
!  IBKPNT:     NAMTBL INDEX OF BRKPNT                                   
!  NUMEL:      NUMBER OF ELEMENTS IN ASSOC TABLE                        
!  PRODI:      POINTER TO LAST ENTRY IN PRODN TABLE                     
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  BREAK:      VALUE OF POSTN FOR BRKPNT                                
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!  NUMGP:      NUMBER OF GROUPS IN PRODUCTION TABLE                     
!  KNT:        NAMTBL INDEX OF ALL                                      
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!                                                                       
!       10.    TABLE OF GROUPS AND NUMBER OF CONTAINED ELEMENTS         
!                                                                       
      COMMON/LENGTH/LENGTH 
      DIMENSION LENGTH(3,100) 
!                                                                       
!       11.    GEOMETRIC TABLE LOCATIONS                                
!                                                                       
!  GEOMLC:     START POSITION FOR A SRF TYPE IN THE GEOMETRIC TABLE     
      COMMON/GEOMLC/GEOMLC 
      DIMENSION GEOMLC(50) 
!                                                                       
!       13.    NAMTBL INDEXES OF THE PROD. TABLES IN SEQUENT. MODE      
!                                                                       
      INCLUDE 'PRODN.INC' 
!                                                                       
!       14.    LEVEL START OF THE PRODUCTIONS IN PRODR                  
!                                                                       
      COMMON/LEVPOS/LEVPOS 
      DIMENSION LEVPOS(12,250),WORK(2,100) 
!  WORK        WORKING AREA FOR STORAGE OF ELEMENT IN ONE SET           
      EQUIVALENCE (WORK(1,1),LEVPOS(1,1)) 
!                                                                       
!       17.    OUTPUT SPACE FOR TRANSFORMED PRODUCTION LIST             
!                                                                       
      COMMON/OUTARY/OUTARY 
      CHARACTER*80 OUTARY 
!                                                                       
!       19.    BIT CONSTANTS                                            
!                                                                       
      INCLUDE 'ALLBTS.INC' 
!*                                                                      
! PURPOSE      TO READ A LIST OF EITHER BASIC OR GEOMETRIC              
!              PRODUCTIONS, PERFORM SOME FORMAT CHECKING                
!              AND ASSIGN GROUP NUMBERS.                                
!                                                                       
! ARGUMENTS    SWITCH = 1 IF BASIC PRODUCTION LIST                      
!                     = 2 IF GEOMETRIC PRODUCTION LIST                  
!                                                                       
! NOTES        LOGICAL VARIABLE ERROR IS SET.TRUE. IF AN ERROR          
!              IN FORMATTING HAS BEEN DETECTED.                         
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              FINI               C            CONTAINS FINI ('FINI')   
!              ICOD               I            CLASS OR MODE OF THIS    
!                                              ITEM                     
!              IDIGIT             C            CONTAINS DIGIT ('DIGIT') 
!              I                  I            FOR USE IN DO LOOPS      
!              INTCNT             I            GROUP NO. COUNT          
!              ITMP               I            NAMTBL INDEX OF THIS ITEM
!              J                  I            CLASS OF ITEM/GROUP NO.  
!              K                  I            MODE OF ITEM/GROUP NO.   
!              KDENT       200    I         0  NAMTBL POINTER FOR EACH  
!                                              MODE OF IDENT.           
!              L                  I            FOR USE IN DO LOOPS      
!              M                  I            NAMTBL INDEX OF NEXT     
!                                              (TERMINATING) CHARACTER  
!              M1                 I            TEMPORARY STORAGE OF     
!                                              ELEMENT IN LENGTH        
!              M2                 I            TEMPORARY STORAGE OF     
!                                              ELEMENT IN LENGTH        
!              N                  I            FOR USE IN DO LOOPS      
!              NUMBR              I            NO. OF ITEMS IN THIS SET 
!              POSTN              I            POSITION IN PRODUCTION   
!                                              TABLES                   
!              SWITCH             I            ARGUMENT OF LOADI =1     
!                                              IF BASIC, =2 IF GEOM.    
!                                              PRODUCTION               
!                                                                       
      DIMENSION KDENT(200) 
      CHARACTER*6 IDIGIT,FINI,IBK*8 
      DATA IDIGIT/'DIGIT'/ 
      DATA FINI/'FINI'/,IBK/' '/ 
!**                                                                     
      DO 100 I=1,QKDENT 
  100 KDENT(I)=0 
      ERROR=.FALSE. 
      OUTARY(1:8)=IBK 
      NUMEL=0 
      KNT = 0 
      LL = 0 
    1 INTCNT=0 
      POSTN=0 
      PRODI=0 
!                                                                       
!...     UPDATE GROUP NUMBER COUNT                                      
!                                                                       
    2 INTCNT=INTCNT+1 
!                                                                       
!...     UPDATE POSITION-IN-TABLE COUNT                                 
!                                                                       
    3 POSTN=POSTN+1 
!                                                                       
!...     ZERO TOP AND NUMBR READY FOR NEW CARD                          
!                                                                       
    4 TOP=0 
      NUMBR=0 
!                                                                       
!...     FETCH NEXT ITEM AND ITS TERMINATOR                             
!                                                                       
    5 CALL INPUT 
      CALL INPUT 
      ITMP=STACK(1,TOP-1) 
!                                                                       
!...     IS IT FINI. IF SO THIS IS THE END OF THIS SET OF TABLES        
!                                                                       
      IF(CNAMTB(ITMP).EQ.FINI)GOTO 30 
  105 ICOD = NAMTBL(ITMP) 
      M=STACK(1,TOP) 
      IF(CNAMTB(M).NE.FINI)GOTO 106 
!                                                                       
      WRITE(VLFILE,2055)CNAMTB(M) 
 2055 FORMAT(1H ,36HERROR NO. 7040 IN SUBROUTINE LOADI. ,A6   ,48H IS IN&
     & A WRONG POSITION. SEARCH FOR DOUPLE COMMA)                       
      GOTO 7 
!                                                                       
!...     BRANCH ON SWITCH - TO 6 IF THESE ARE BASIC PRODUCTIONS,        
!...                        TO 9 IF THEY ARE GEOMETRIC ONES.            
!                                                                       
  106 GO TO(6,9),SWITCH 
!                                                                       
!...     IF CLASS AND MODE ARE BOTH ZERO, THIS CANNOT BE A META-CLASS,  
!...     SO SET ERROR FLAG AND GIVE DIAGNOSTIC                          
!                                                                       
    6 IF(ICOD.NE.0)GO TO 8 
      WRITE(VLFILE,2001)CNAMTB(M) 
 2001 FORMAT(1H ,36HERROR NO. 7011 IN SUBROUTINE LOADI. ,A6   ,46H IS NO&
     &T A META-LINGUISTIC CLASS, CARD IGNORED.)                         
    7 ERROR=.TRUE. 
      IF(SWITCH.EQ.2)GOTO 37 
      GO TO 4 
!                                                                       
!...     ITEM IS AN IDENTIFIER. SHOULD HAVE NON-ZERO MODE - OTHERWISE   
!...     ISSUE DIAGNOSTIC                                               
!                                                                       
  201 K=ICOD-J 
      IF (K.GT.QKDENT) GOTO 209 
      IF(K.EQ.0)GO TO 5004 
!                                                                       
!...     HAS AN IDENTIFIER OF THIS MODE APPEARED PREVIOUSLY             
!                                                                       
      IF(KDENT(K).NE.0)GO TO 5001 
!                                                                       
!...     NO. STORE ITS NAMTBL POINTER IN KDENT, AND CONTINUE PROCESSING 
!                                                                       
      GOTO 220 
  209 WRITE (VLFILE,210) CNAMTB(M), ICOD 
  210 FORMAT(74H0ERROR NO. 7038 THE SIZE OF THE KDENT ARRAY IN LOADI MUS&
     &T BE EXPANDED. ***/101H KDENT CONTAINS POINTERS TO THE NAMTBL ENTR&
     &IES OF IDENTIFIERS USED IN BASIC OR GEOMETRIC PRODUCTIONS./57H THE&
     & IDENTIFIER THAT CAUSED THE LIMITS TO BE EXCEEDED IS , A6,20H WHOS&
     &E CLASS-MODE = ,I5)                                               
      STOP 
  220 KDENT(K) = ITMP 
      GO TO 12 
!                                                                       
!...     YES. SET ITMP TO CONTENTS OF KDENT AND EXAMINE WORK TO SEE     
!...     IF AN IDENTIFIER OF THIS MODE HAS ALREADY APPEARED IN THIS SET 
!...     IF ONE HAS, SKIP EXAMINATION OF ASSOC AND CONTINUE PROCESSING. 
!                                                                       
 5001 ITMP=KDENT(K) 
      IF(NUMBR.EQ.0)GO TO 12 
      DO 5002 L=1,NUMBR 
      IF(WORK(1,L).EQ.ITMP)GO TO 5003 
 5002 END DO 
      GO TO 12 
!                                                                       
!...     IS ITEM BRKPNT                                                 
!                                                                       
    8 IF(IBKPNT.EQ.ITMP)GO TO 25 
!                                                                       
!...     NO. IS IT ALL                                                  
!                                                                       
      IF (NAMTBL(ITMP).NE.9999000) GOTO 11 
!                                                                       
!...     YES. IS THERE ANYTHING ELSE ON THE CARD                        
!                                                                       
      IF (NUMBR.EQ.0) GO TO 202 
!                                                                       
!...     YES. OUTPUT DIAGNOSTIC.                                        
!                                                                       
      WRITE(VLFILE,3001) 
 3001 FORMAT (1H ,63HERROR NO. 7013 IN SUBROUTINE LOADI.  ALL DOES NOT A&
     &PPEAR ALONE.)                                                     
       GO TO 7 
!                                                                       
!...     CARD CONTAINS ALL                                              
!                                                                       
  202 KNT  = ITMP 
      GO TO 18 
!                                                                       
!...     GEOMETRIC PROCESSING                                           
!                                                                       
    9 J = MODULO*(ICOD/MODULO) 
!                                                                       
!...     IS ITEM AN IDENTIFIER                                          
!                                                                       
      IF (J.EQ.IDENT(1)) GO TO 201 
!                                                                       
!...     NO. IS IT A CONDITIONAL GEOMETRIC OR LARGE GEOMETRIC           
!                                                                       
      IF (J .NE. CONGEO(1) .AND. J .NE. CONBIG(1))  GO TO 10 
!                                                                       
!...     YES. IS NEXT ITEM /                                            
!                                                                       
      IF (NAMTBL(M).EQ.SLASH(1)) GOTO 26 
!                                                                       
!...     NO.                                                            
!                                                                       
      GO TO 12 
!                                                                       
!...     IS ITEM A NUMBER                                               
!                                                                       
   10 IF(J.EQ.DIGIT(1))GO TO 24 
!                                                                       
!...     NO. IT IS NEITHER IDENT,NOR CONGEO,NOR CONBIG,NOR NUMBER.      
!...     OUTPUT DIAGNOSTIC                                              
!                                                                       
 5004 WRITE(VLFILE,2002) CNAMTB(ITMP),NAMTBL(ITMP) 
 2002 FORMAT(1H ,36HERROR NO. 7012 IN SUBROUTINE LOADI. ,A6,   10H OF CL&
     &ASS ,I6,48H IS NOT A VALID GEOM. FORMAT NAME. CARD IGNORED.)      
      GO TO 7 
!                                                                       
!...     ITEM IS NOT BRKPNT OR ALL. IS IT A NUMBER.                     
!                                                                       
   11 IF((ICOD.EQ.DIGIT(1)).AND.(CNAMTB(ITMP).NE.IDIGIT))GOTO 24 
!                                                                       
!...     UPDATE NO. OF ITEMS ON CARD AND TEST IF THIS EXCEEDS LIMIT     
!                                                                       
   12 NUMBR=NUMBR+1 
      IF (NUMBR.GT.QWORK) CALL SPILL(9,'LOADI   ') 
      GO TO 14 
!                                                                       
!...     TOO MANY ITEMS FOR TABLE - OUTPUT DIAGNOSTIC                   
!                                                                       
   13 WRITE(VLFILE,2003) 
 2003 FORMAT(1H ,66HERROR NO. 7014 IN SUBROUTINE LOADI. LOAD TABLE FULL.&
     & CARD IGNORED.)                                                   
      GO TO 7 
!                                                                       
!...     STORE NAMTBL POINTER TO ITEM IN FIRST COLUMN OF WORK           
!                                                                       
   14 WORK(1,NUMBR)=ITMP 
!                                                                       
!...     IF THIS IS NOT THE FIRST ITEM, SEARCH ASSOC TO SEE IF THIS     
!...     ITEM HAS BEEN USED PREVIOUSLY.                                 
!                                                                       
      IF(NUMEL.EQ.0)GO TO 16 
      DO 15 I=1,NUMEL 
      IF(ITMP.EQ.ASSOC(1,I))GO TO 17 
   15 END DO 
!                                                                       
!...     THIS IS ITS FIRST APPEARENCE. STORE NAMTBL POINTER AND INTCNT  
!...     IN ASSOC, AND INTCNT IN SECOND COLUMN OF WORK                  
!                                                                       
   16 NUMEL=NUMEL+1 
!                                                                       
!...     IS TABLE FULL                                                  
!                                                                       
      IF (NUMEL.GT.QASSOC) CALL SPILL(4,'LOADI   ') 
!                                                                       
!...     NO.                                                            
!                                                                       
      ASSOC(1,NUMEL)=ITMP 
      ASSOC(2,NUMEL)=INTCNT 
      ASSOC(3,NUMEL)=ITMP 
      WORK(2,NUMBR)=INTCNT 
      L=MOD(NAMTBL(ITMP),MODULO) 
      IF((NAMTBL(ITMP)-L).EQ.IDENT(1))L=L+50 
      GO TO 18 
!                                                                       
!...     ITEM HAS BEEN USED BEFORE - STORE VALUE ALREADY ASSIGNED IN    
!...     ASSOC IN SECOND COLUMN OF WORK                                 
!                                                                       
   17 WORK(2,NUMBR)=ASSOC(2,I) 
      IF(NUMBR.GT.1)ASSOC(3,I)=0 
!                                                                       
!...     UPDATE PRODUCTION TABLE POINTER AND CHECK IF IT EXCEEDS LIMIT  
!                                                                       
   18 PRODI=PRODI+1 
      IF (PRODI.GT.QPRODN) CALL SPILL(7,'LOADI   ') 
!                                                                       
!...     NO. STORE NAMTBL POINTER IN NEXT CELL OF PRODN                 
!                                                                       
      PRODN(PRODI)=ITMP 
!                                                                       
!...     IF TERMINATING CHARACTER IS NOT RTERM, RETURN FOR NEXT ITEM    
!                                                                       
 5003 IF (NAMTBL(M).NE.RTERM(1)) GOTO 5 
!                                                                       
!...     THIS WAS LAST ITEM OF SET - PUT IT IN PRODN NEGATIVELY         
!                                                                       
      PRODN(PRODI)=-PRODN(PRODI) 
!                                                                       
!...     IF THIS WAS ONLY ITEM IN SET GO BACK FOR NEXT CARD             
!                                                                       
      IF(NUMBR.EQ.0)GO TO 3 
      K=INTCNT 
      J=INTCNT 
!                                                                       
!...     THIS LOOP SETS THE SECOND COLUMN OF ASSOC TO THE SAME VALUE    
!...     FOR ALL ALTERNATIVES IN THIS SET, AND FOR ALL ITEMS WHICH ARE  
!...     ALTERNATIVES IN ANY OTHER SET TO AN ITEM IN THIS SET.          
!                                                                       
      DO 23 L=1,NUMBR 
      IF(WORK(2,L)-K)19,23,20 
!                                                                       
!...     J IS THE GROUP NO. OF THIS ITEM IF IT IS LESS THAN K           
!                                                                       
   19 J=WORK(2,L) 
      GO TO 21 
!                                                                       
!...     K IS THE MAXIMUM GROUP NO. SO FAR ENCOUNTERED IN THIS SET      
!                                                                       
   20 K=WORK(2,L) 
   21 DO 22 N=1,NUMEL 
!                                                                       
!...     TEST FOR ANY ITEMS IN ASSOC WITH GROUP NO. EQUAL TO MAX. SO    
!...     FAR IN THIS SET, AND CHANGE THEM TO MINIMUM SO FAR IN THIS SET 
!                                                                       
      IF(ASSOC(2,N).EQ.K)ASSOC(2,N)=J 
   22 END DO 
!                                                                       
!...     SET K TO THE MINIMUM GROUP NO. IN THIS SET                     
!                                                                       
   23 K=J 
!                                                                       
!...     ON EXIT ALL ITEMS HAVE GROUP NO. K, THE LOWEST POSSIBLE.       
!...     IF THIS IS GREATER THAN THE CURRENT MAX. VALUE - DIAGNOSTIC,   
!...     IF IT IS EQUAL TO THE CURRENT MAXIMUM - UPDATE MAXIMUM AND     
!...     FETCH NEXT CARD,                                               
!...     IF IT IS LESS THAN CURRENT MAXIMUM - FETCH NEXT CARD.          
!                                                                       
      IF(K-INTCNT) 3,2,13 
!                                                                       
!...     NUMBER - SHOULD BE ONLY ITEM ON CARD                           
!                                                                       
   24 IF ((NUMBR.EQ.0).AND.(NAMTBL(M).EQ.RTERM(1))) GOTO 18 
!                                                                       
!...     IT IS NOT - SO DIAGNOSTIC                                      
!                                                                       
      WRITE(VLFILE,2004) CNAMTB(ITMP) 
 2004 FORMAT(1H ,36HERROR NO. 7015 IN SUBROUTINE LOADI. ,A6   ,37H APPEA&
     &RS INCORRECTLY IN A PRODUCTION.)                                  
      GO TO 7 
!                                                                       
!...     BREAK-POINT. STORE ITS POSITION. SHOULD BE ONLY ITEM ON CARD.  
!                                                                       
   25 BREAK=MCTOP 
      MCTOP=POSTN 
      IPROD=PRODI+1 
      IF ((NUMBR.EQ.0).AND.(NAMTBL(M).EQ.RTERM(1))) GOTO 4 
      WRITE(VLFILE,2005) 
 2005 FORMAT(1H ,79HERROR NO. 7016 IN SUBROUTINE LOADI. BREAKPOINT INDIC&
     &ATOR DOES NOT APPEAR ALONE.)                                      
      GO TO 7 
!                                                                       
!...     CONGEO OR CONBIG FOLLOWED BY /. SHOULD BE FIRST AND ONLY       
!...     APPEARANCE FOR THIS MODE. TEST GEOMLC TO FIND OUT.             
!                                                                       
   26 L=ICOD-J 
      IF (L.GT.QGEOML) CALL SPILL(5,'LOADI   ') 
      IF(LL.GT.0)GO TO 27 
      IF(GEOMLC(L).EQ.0)GO TO 27 
!                                                                       
!...     GEOMLC(MODE) IS NON-ZERO - I.E. THIS SURFACE TYPE HAS ALREADY  
!...     BEEN USED. ISSUE DIAGNOSTIC.                                   
!                                                                       
      WRITE(VLFILE,2006) CNAMTB(ITMP) 
 2006 FORMAT (1H ,60HERROR NO. 7017 IN SUBROUTINE LOADI. TWO SETS OF FOR&
     &MATS FOR ,A6)                                                     
      GO TO 7 
!                                                                       
!...     CONGEO OR CONBIG SHOULD BE ALONE.3CHECK IT.                    
!                                                                       
   27 IF( NUMBR.EQ.0)GO TO 28 
!                                                                       
!...     NO.                                                            
!                                                                       
      WRITE(VLFILE,2007) CNAMTB(ITMP) 
 2007 FORMAT(1H ,36HERROR NO. 7018 IN SUBROUTINE LOADI. ,A6   ,41H FORMA&
     &T IDENTIFIER DOES NOT APPEAR ALONE.)                              
      GO TO 7 
!                                                                       
!...     SKIP ITEMS UNTIL RTERM IS REACHED                              
!                                                                       
   28 CALL INPUT 
      K=STACK(1,TOP) 
      IF (NAMTBL(K).NE.RTERM(1)) GOTO 28 
!                                                                       
!...     IS THIS FIRST PRODUCTION                                       
!                                                                       
      IF(PRODI.EQ.0)GO TO 29 
!                                                                       
!...     NO. UPDATE PRODUCTION TABLE POINTER, STORE MARER IN PRODUCTION 
!...     TABLE, AND POSITION IN GEOMLC. THEN RETURN FOR NEXT CARD.      
!                                                                       
      IF(ELFILE.EQ.LCDATA)GOTO 39 
      PRODI=PRODI+1 
      PRODN(PRODI)=-PDERR 
   39 IF(NAMTBL(IBKPNT).NE.CONGEO(1))GOTO 38 
      GEOMLC(L)=POSTN+1 
      GO TO 3 
   38 LL=LL+1 
      GEOMLC(LL)=ITMP 
      IF(LL.EQ.1)GOTO 4 
      GO TO 3 
!                                                                       
!...     FIRST PRODUCTION. SET GEOMLC(1).                               
!                                                                       
   29 IF(NAMTBL(IBKPNT).NE.CONGEO(1))GOTO 38 
      GEOMLC(L)=1 
      GO TO 4 
!                                                                       
!...     FINI REACHED. SHOULD BE ALONE - IF NOT ISSUE DIAGNOSTIC        
!...     BUT ACCEPT FINI AS VALID                                       
!                                                                       
   30 IF ((NUMBR.EQ.0).AND.(NAMTBL(M).EQ.RTERM(1))) GOTO 31 
      WRITE(VLFILE,2008) 
 2008 FORMAT(1H ,89HERROR NO. 7019 IN SUBROUTINE LOADI. PRODUCTION LIST &
     & TERMINATOR INCORRECT. ERROR IGNORED.)                            
!                                                                       
!...     SET MARKER IN PRODN AND DECREASE GROUP NO. BY ONE              
!                                                                       
   31 IF(ELFILE.EQ.LCDATA)GOTO 40 
      PRODI=PRODI+1 
      PRODN(PRODI)=-PDERR 
   40 INTCNT=INTCNT-1 
!                                                                       
!...     CLEAR LENGTH                                                   
!                                                                       
      DO 36 I=1,QLENGT 
      LENGTH(1,I) = 0 
   36 LENGTH(2,I) = 0 
      NUMGP=0 
!                                                                       
!...     THIS LOOP SETS UP THE ARRAY LENGTH SO THAT COL.1 CONTAINS THE  
!...     SET NUMBERS, COL.2 THE NO. OF ITEMS IN THAT SET.               
!...     IT IS ARRANGED IN DESCENDING  ORDER OF MAGNITUDE IN COL.2      
!                                                                       
      DO 35 I=1,INTCNT 
      I1=I 
!                                                                       
!...     COUNT NO. OF ITEMS IN ASSOC WITH GROUP NO. I                   
!                                                                       
      K=0 
      DO 32 L=1,NUMEL 
      IF(ASSOC(2,L).EQ.I)K=K+1 
   32 END DO 
      IF(K.EQ.0)GO TO 35 
      NUMGP=NUMGP+1 
!                                                                       
!...     TEST VALID NO. OF GROUPS. IF TOO LARGE ISSUE DIAGNOSTIC.       
!                                                                       
      IF(NUMGP.GT.QLENGT)GO TO 13 
!                                                                       
!...     SET L TO THE POSITION IN LENGTH WHERE THE FIRST GROUP WITH     
!...     LESS MEMBERS THAN THIS ONE OCCURS.                             
!                                                                       
      DO 33 L=1,NUMGP 
      IF(K.GT.LENGTH(2,L))GO TO 34 
   33 END DO 
      L=NUMGP 
!                                                                       
!...     STORE GROUP NO. AND NUMBER OF ELENTS IN GROUP AT THIS POINT    
!...     IN LENGTH, AND MOVE DOWN SUBSEQUENT ENTRIES.                   
!                                                                       
   34 M1=LENGTH(1,L) 
      M2=LENGTH(2,L) 
      LENGTH(1,L)=I1 
      LENGTH(2,L)=K 
      IF(L.EQ.NUMGP)GO TO 35 
      I1=M1 
      K=M2 
      L=L+1 
      GO TO 34 
   35 END DO 
!                                                                       
!...     IF BASIC PRODUCTION PROCESSING AND ALL APPEARED AT LEAST       
!...     ONCE - SET SECOND COL. OF NAMTBL ENTRY FOR ALL TO ALL BITS SET 
!     ***************************************************************** 
      IF((SWITCH.NE.1).OR.(KNT.EQ.0))GOTO 37 
      CNAMTB(KNT)='******' 
   37 RETURN 
      END                                           
