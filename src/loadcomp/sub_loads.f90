! Modified to .f90 from M0006717.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADS                                 
!                                                                       
! LINKAGE       CALL   LOADS                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    SPILL           SUBROUTINE    LOADG            
!                                        SUBROUTINE    LOADP            
!                                                                       
      SUBROUTINE LOADS 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        0.    SYSTEM DEPENDENT PARAMETERS                              
!                                                                       
      INCLUDE 'SDP.INC' 
!  NBWRD:      NO OF BITS PER COMPUTER WORD                             
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMTBL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150),DIGIT(2),NUMBER(2),TEMP(2) 
!  DIGIT:      (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
!  NUMBER:     (1)=CODE CLASS 14000,(2)=NAMTBL INDEX OF 'NUMBER'        
      EQUIVALENCE (NUMBER(1),CODES(27)) 
!  TEMP:       (1)=CODE CLASS 17000,(2)=NAMTBL INDEX OF 'TEMP  '        
      EQUIVALENCE (TEMP(1),CODES(33)) 
!                                                                       
!        4.    BIT COMBINATION TABLE                                    
!                                                                       
!  BIT:        CONTAINS THE ELEMENTARY BIT PATTERNS                     
      COMMON/BITCOM/BIT 
      DIMENSION BIT(32) 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QLENGT:     DIMENSION OF ARRAY LENGTH                                
      EQUIVALENCE (QLENGT,LDXSIZ(6)) 
!  QKGRP:      DIMENSION OF ARRAY KGRP                                  
      EQUIVALENCE (QKGRP,LDXSIZ(19)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  NUMEL:      NUMBER OF ELEMENTS IN ASSOC TABLE                        
!  PRODI:      POINTER TO LAST ENTRY IN PRODN TABLE                     
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  NUMGP:      NUMBER OF GROUPS IN PRODUCTION TABLE                     
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
!       12.    BIT OUTPUT PATTERNS                                      
!                                                                       
      COMMON/ELBIT/ELBIT 
      DIMENSION ELBIT(200),LBIT(200) 
!  LBIT:       BIT PATTERNS FOR ELEMENTS OF ASSOC TABLE                 
      EQUIVALENCE (LBIT(1),ELBIT(1)) 
!                                                                       
!       13.    NAMTBL INDEXES OF THE PROD. TABLES                       
!                                                                       
      INCLUDE 'PRODN.INC' 
!  PRODN:      NAMTBL INDEXES OF THE PROD. TABLES IN SEQUENT. MODE      
!*                                                                      
! NOTES        THE INTEGER VARIABLE IBITS IS A COMPUTER DE-             
!              PENDENT WORD.  IT SHOULD CONTAIN THE NUMBER OF           
!              BITS (EXCLUDING THE SIGN BIT) IN A COMPUTER              
!              WORD.  IT IS USED IN ASSIGINING UNIQUE BIT-PATTERNS      
!              TO EACH ITEM IN THE VARIOUS TABLES.                      
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              I                  I            DO LOOP INDEX            
!              IBITS              I            NUMBER OF USEFULL BITS IN
!                                              A COMPUTER WORD          
!              IDGIT              I            NAMTBL INDEX OF DIGIT    
!              IDIGIT             C*6          CONTAINS DIGIT ('DIGIT') 
!              IELT               I            POSITION OF ELEMENT BIT  
!              IEND               I            PRODI+1                  
!              IGRP               I            NUMBER OF ITEMS IN EACH  
!                                              GROUP                    
!              II                 I            GENERAL VARIABLE         
!              INMBR              I            NAMTBL INDEX OF NUMBER   
!              INUMBR             C*6          CONTAINS NUMBER          
!                                              ('NUMBER')               
!              J                  I            GENERAL VARIABLE         
!              JDFCIT             I            DIFFERENCE BETWEEN       
!                                              MAXIMUM POSSIBLE NO. OF  
!                                              COMBINATIONS AND NO. OF  
!                                              ELEMENTS                 
!              JEXCES             I            DIFFERENCES BETWEEN NO.  
!                                              OF GROUPS AND NO. OF BITS
!              JJ                 I            GENERAL VARIABLE         
!              K                  I            DO LOOP INDEX            
!              KERP         75    I            ZONE NUMBER FOR EACH     
!                                              GROUP                    
!              KJ                 I            NEXT ZONE NUMBER         
!              L                  I            NAMTBL INDEX             
!              LENTH3             L            FLAG USED DURING ATTEMPTS
!                                              TO MERGE GROUPS          
!              MAXLTH             I            MAXIMUM NUMBER OF        
!                                              ELEMENTS IN ANY ONE SET  
!              MORE               L            FLAG TO SAY IF MORE ITEMS
!                                              TO COME IN THIS SET OF   
!                                              ALTERNATIVES             
!              NUMZAV             I            IBITS-MAXLTM=NO. BITS    
!                                              AVAILABLE FOR ZONE BITS  
!              TEMP               I            USED FOR TEMPORARY       
!                                              STORAGE OF---            
!                                              1) SUM OF NO. OF ELEMENTS
!                                                IN 2 GROUPS            
!                                              2) NAMTBL INDEX OF NEXT  
!                                                ITEM IN PRODUCTION     
!                                                TABLE                  
!              NEMTBL     3000    I            ARRAY HOLDING BIT        
!                                              PATTERNS                 
!...           ASSOC IS A TWO COLUMN ARRAY OF GROUP ELEMENTS            
!...           THE FIRST COLUMN CONTAINS THE NAME TABLE POINTER         
!...           AND THE SECOND COLUMN HAS THE GROUP NUMBER OF THE        
!...           ELEMENTS (NOTE..THE THIRD COLUMN IS A WORKING AREA)      
!...           ELBIT IS A ONE COLUMN ARRAY WITH THE BIT PATTERNS OF THE 
!...           ELEMENTS IN ASSOC TABLE                                  
!...           LENGTH IS A THREE COLUMN ARRAY OF GROUPS.                
!...           THE FIRST COLUMN IN LENGTH IS THE GROUP NUMBER,          
!...           THE SECOND COLUMN HAS THE NUMBER OF ELEMENTS IN          
!...           THIS GROUP, AND THE THIRD COLUMN HAS THE TOTAL           
!...           NUMBER OF ALL ELEMENTS IF THIS GROUP CONTAINS OTHERS     
!...           OF  THE THIRD COLUMN IS -INDEX OF LENGTH WITH            
!...           WHICH THIS GROUP IS COMBINED.                            
!...           NUMEL IS THE TOTAL NUMBER OF ELEMENTS IN ASSOC           
!...           NUMGP IS THE TOTAL NUMBER OF GROUPS IN THE LENGTH TABLE  
!                                                                       
      DIMENSION KGRP(100),IGRP(100),NEMTBL(3000) 
      CHARACTER*6 INUMBR,IDIGIT 
      LOGICAL LENTH3,LENTH4,MORE 
      DATA INUMBR/'NUMBER'/,                                            &
     &     IDIGIT/'DIGIT'/                                              
      DATA    LENTH3/.TRUE./,LENTH4/.FALSE./ 
!                                                                       
!...  **********************************************************        
!...  *                                                        *        
!...  *  IBITS IS COMPUTER DEPENDENT.                          *        
!...  *  IT IS SET EQUAL TO THE NUMBER OF BITS (EXCLUDING THE  *        
!...  *  SIGN BIT) IN A COMPUTER WORD.                         *        
!...  *                                                        *        
!...  **********************************************************        
!**                                                                     
      IBITS = NBWRD-1 
!                                                                       
!...     CLEAR KGRP,IGRP, AND 3RD COLUMN OF LENGTH.                     
!                                                                       
      DO 2 I=1,QKGRP 
      KGRP(I) = 0 
    2 IGRP(I) = 0 
      IF (NUMGP.GT.QLENGT) CALL SPILL(6,'LOADS   ') 
      DO  3 I=1,NUMGP 
    3 LENGTH(3,I) = 0 
      MAXLTH = LENGTH(2,1) 
      NUMZAV = IBITS - MAXLTH 
!                                                                       
!...     ARE THERE ENOUGH ZONE BITS TO ASSIGN A UNIQUE ONE              
!...     TO EACH SET OF ELEMENTS                                        
!                                                                       
      IF(NUMZAV.GE.NUMGP) GO TO 100 
!                                                                       
!...     NO. TRY TO COMBINE SETS SO AS TO ELIMINATE EXCESS SETS.        
!...     JEXCES = NO. OF EXCESS SETS TO BE ELIMINATED,                  
!...     JDFCIT = (MAX. NO. OF BITS AVAILABLE FOR ZONE BITS)*(MAX. NO.  
!...               OF BITS REQUIRED FOR ELEMENT BITS) - TOTAL NO.       
!...               OF ELEMENTS.                                         
!...     IF JDFCIT IS LESS THAN ZERO THE EXCESS CANNOT BE ELIMINATED.   
!                                                                       
      JEXCES = NUMGP - NUMZAV 
      JDFCIT = NUMZAV*MAXLTH- NUMEL 
      IF(JDFCIT.GE.0) GO TO 1 
!                                                                       
!...     NOT ENOUGH BITS AVAILABLE.                                     
!...     SET LENTH3 .FALSE. AND OUTPUT DIAGNOSTIC.                      
!                                                                       
      JDFCIT = 0 
      LENTH3 = .FALSE. 
      GO TO 13 
!                                                                       
!...     MERGING OF GROUPS MAY BE POSSIBLE. TRY TO ELIMINATE EXCESS SETS
!                                                                       
    1 II = NUMGP-1 
!                                                                       
!...     THIS LOOP ATTEMPTS TO COMBINE GROUPS                           
!                                                                       
      DO 12 I = 2,II 
!                                                                       
!...     IF THIS SET HAS BEEN PROCESSED, 3RD COL. OF LENGTH WILL        
!...     BE NON-ZERO. TEST THIS                                         
!                                                                       
      IF(LENGTH(3,I).NE.0) GO TO 12 
!                                                                       
!...     STORE NO. OF ELEMENTS IN THIS GROUP IN 3RD COL. OF LENGTH.     
!                                                                       
      LENGTH(3,I) = LENGTH(2,I) 
      J = I+1 
!                                                                       
!...     SEARCH REST OF GROUPS FOR ONE THAT CAN BE COMBINED WITH THIS.  
!                                                                       
      DO 10 JJ = J,NUMGP 
!                                                                       
!...     HAS THIS GROUP ALREADY BEEN PROCESSED.                         
!                                                                       
      IF(LENGTH(3,JJ).NE.0) GO TO 10 
!                                                                       
!...     NO. PUT TOTAL NO. OF ELEMENTS IN THIS GROUP AND THE ONE WE ARE 
!...     ATTEMPTING TO COMBINE IT WITH IN TEMP AND TEST IF TOTAL IS     
!...     GREATER THAN MAX. NO ALLOWED (= LENGTH(2,1))                   
!                                                                       
      TEMP(1)=LENGTH(3,I)+LENGTH(2,JJ) 
      IF (TEMP(1).GT.MAXLTH) GO TO 10 
!                                                                       
!...     NO. SO PUT NEW TOTAL LENGTH IN 3RD COL. OF ORIGINAL GROUP,     
!...     AND NEGATIVE POINTER TO THAT GROUP IN 3RD COL. OF MERGED GROUP.
!...     ALSE SET LENTH3 .FALSE. IF WE CANNOT MERGE ANY MORE GROUPS     
!...     WITH THIS ONE.                                                 
!                                                                       
      IF ((TEMP(1)+JDFCIT).LT.MAXLTH) LENTH3 = .FALSE. 
      LENGTH(3,I) = TEMP(1) 
      LENGTH(3,JJ) = -I 
!                                                                       
!...     REDUCE EXCESS BY ONE AND SEE IF ALL NECCESSARY ELIMINATION     
!...     HAS BEEN DONE YET.                                             
!                                                                       
      JEXCES = JEXCES - 1 
      IF(JEXCES.EQ.0) GO TO 100 
!                                                                       
!...     NO. IF LENTH3 IS .TRUE. TRY TO MERGE ANOTHER GROUP WITH THIS.  
!                                                                       
      IF(.NOT.LENTH3) GO TO 11 
   10 END DO 
!                                                                       
!...     RESET IDFCIT AND TRY TO PERFORM A FURTHER MERGE.               
!                                                                       
   11 JDFCIT = JDFCIT + LENGTH(3,I)-MAXLTH 
      LENTH3 = .TRUE. 
   12 END DO 
!                                                                       
!...     CANNOT REDUCE EXCESS SETS TO ZERO. OUTPUT DIAGNOSTIC           
!                                                                       
   13 WRITE(VLFILE,14) 
   14 FORMAT (1H ,61HERROR NO. 7031 IN SUBROUTINE LOADS. UNABLE TO COMBI&
     &NE GROUPS.)                                                       
!                                                                       
!...     IF WE HAVE NOT YET ATTEMPTED A MERGE, DO SO, OTHERWISE START   
!...     FORMING INTERNAL REPRESENTATIONS.                              
!                                                                       
      IF(LENTH3) GO TO 100 
      LENTH3 = .TRUE. 
      GO TO 1 
!                                                                       
!...     THE FOLLOWING LOOPS SET UP ELBIT WITH THE INTERNAL             
!...     REPRESENTATIONS OF THE ELEMENTS IN ASSOC.                      
!                                                                       
  100 KJ = 1 
!                                                                       
!...     THIS LOOP EXAMINES EACH ITEM IN ASSOC, ONE AT A TIME.          
!                                                                       
      DO  107 I=1,NUMEL 
!                                                                       
!...     THIS LOOP EXAMINES THE CORRESPONDING ITEM IN LENGTH.           
!                                                                       
      DO 103 K = 1,NUMGP 
      J = K 
!                                                                       
!...     FIND ITEM IN LENGTH CORRESPONDING TO SET NO. OF THIS ELEMENT.  
!                                                                       
      IF(ASSOC(2,I).NE.LENGTH(1,J)) GO TO 103 
!                                                                       
!...     TEST IF 3RD COL. IS A POINTER TO ANOTHER GROUP.                
!                                                                       
      IF(LENGTH(3,J)) 101,102,102 
!                                                                       
!...     YES. SET J TO POINT TO THAT GROUP - I.E. TO GROUP WHICH NOW    
!...     CONTAINS THE ELEMENT IN ASSOC.                                 
!                                                                       
  101 J = -LENGTH(3,J) 
!                                                                       
!...     INCREASE CORRESPONDING ITEM OF IGRP - CONTAINS NO. OF ELEMENTS 
!...     IN THIS GROUP - AND SET IELT TO POSITION FOR ELEMENT BIT.      
!                                                                       
  102 IGRP(J) = IGRP(J)+1 
      IELT = NUMZAV+1+IGRP(J) 
!                                                                       
!...     ARE THERE MORE THAN MAX. ALLOWABLE NO. OF ELEMENTS IN GROUP    
!                                                                       
      IF (IGRP(J).GT.MAXLTH)        GO TO 105 
!                                                                       
!...     IS THIS FIRST ELEMENT ENCOUNTERED IN THIS GROUP                
!                                                                       
      IF (KGRP(J).NE.0) GO TO 108 
!                                                                       
!...     YES. HAVE WE HAD MAX. NO. OF GROUPS YET                        
!                                                                       
      IF(KJ.GT.NUMZAV) GO TO 110 
!                                                                       
!...     NO. INCREASE KJ BY 1 - KJ = ZONE NO. OF THIS GROUP             
!...     STORE ZONE NO. IN KGRP                                         
!                                                                       
      KJ = KJ+1 
      KGRP(J) = KJ 
!                                                                       
!...     FORM INTERNAL REPRESENTATION IN LBIT                           
!                                                                       
  108 J = KGRP(J) 
      LBIT(I) = ORF(BIT(J),BIT(IELT)) 
      GO TO 107 
!                                                                       
!...     MORE THAN MAX. NO. OF GROUPS - ISSUE DIAGNOSTIC                
!                                                                       
  110 WRITE(VLFILE,111)KJ 
  111 FORMAT (1H ,54HERROR NO. 7032 IN SUBROUTINE LOADS. TOO MANY GROUPS&
     &...,I5)                                                           
!                                                                       
!...     END OF LOOP                                                    
!                                                                       
  103 END DO 
!                                                                       
!...     THIS ELEMENT HAS NO ENTRY IN LENGTH TABLE - ISSUE DIAGNOSTIC   
!                                                                       
      L = ASSOC(1,I) 
      WRITE(VLFILE,104) CNAMTB(L) 
  104 FORMAT(1H ,46HERROR NO. 7033 IN SUBROUTINE LOADS.  ELEMENT  ,A6,  &
     & 24H HAS NO GROUP ASSIGNMENT)                                     
      GO TO 107 
!                                                                       
!...     MORE THAN MAX. NO. OF ELEMENTS ALLOWABLE IN ONE GROUP -        
!...     ISSUE DIAGNOSTIC                                               
!                                                                       
  105 WRITE(VLFILE,106) J 
  106 FORMAT (1H ,64HERROR NO. 7034 IN SUBROUTINE LOADS.  TOO MANY ELEME&
     &NTS IN GROUP ,I5)                                                 
      IGRP(J) = 0 
!                                                                       
!...     END OF LOOP TO SET UP ELBIT                                    
!                                                                       
  107 END DO 
!                                                                       
!...                                                                    
!                                                                       
      INMBR = 0 
      IDGIT = 0 
!                                                                       
!...     THIS LOOP PUTS BCD OF EACH ELEMENT IN ASSOC IN CASSOC, AND     
!...     PUTS THE INTERNAL REPRESENTATION IN NEMTBL LOCATION CORRES.    
!...     TO ENTRY IN NAMTBL, AND SETS IDGIT AND INMBR TO THE NAMTBL     
!...     POINTERS OF DIGIT AND NUMBER RESPECTIVELY.                     
!                                                                       
      DO 140 I= 1,NUMEL 
      L = ASSOC(1,I) 
      CASSOC(I) = CNAMTB(L) 
      IF(CNAMTB(L).EQ.IDIGIT)IDGIT=L 
      IF(CNAMTB(L).EQ.INUMBR)INMBR=L 
      NEMTBL(L) = ELBIT(I) 
  140 END DO 
!...                                                                    
      MORE = .TRUE. 
      TEMP(1) = PRODN(1) 
      PRODN(1) = 0 
      IPROD = 1 
      JEND = PRODI+1 
!                                                                       
!...     THIS LOOP FORMS THE INTERNAL PRODUCTION TABLES IN PRODN.       
!...     TEMP CONTAINS NEXT ITEM, IPROD CONTAINS NEXT VACANT POSITION.  
!                                                                       
      DO 154 I = 2,JEND 
!                                                                       
!...     IS NEXT ITEM NEGATIVE - I.E. THE LAST ELEMENT FOR THIS         
!...     SET OF ALTERNATIVES, OR THE PRODUCTION NUMBER.                 
!                                                                       
      IF (TEMP(1) .GT. 0) GO TO 152 
      TEMP(1) = -TEMP(1) 
!                                                                       
!...     IS IT POINTER TO PRODUCTION NUMBER                             
!                                                                       
      IF (((NAMTBL(TEMP(1)).NE.DIGIT(1))                                &
     &   .OR. (IDGIT.EQ.TEMP(1)))                                       &
     &   .AND.                                                          &
     &   ((NAMTBL(TEMP(1)).NE.NUMBER(1))                                &
     &   .OR. (INMBR.EQ.TEMP(1))))        GO TO 151                     
!                                                                       
!...     YES. IF LAST GROUP OF ALTERNATIVES HAS NOT BEEN TERMINATED,    
!...     ISSUE DIAGNOSTIC                                               
!                                                                       
      IF(PRODN(IPROD).NE.0) WRITE(VLFILE,150) 
  150 FORMAT (1H ,61HERROR NO. 7035 IN SUBROUTINE LOADS.  INCOMPLETE GRO&
     &UP IGNORED)                                                       
!                                                                       
!...     STORE NEGATIVE NAMTBL POINTER IN PRODN(IPROD), AND NEXT        
!...     ITEM IN TEMP.                                                  
!                                                                       
      PRODN(IPROD) = -TEMP(1) 
      TEMP(1) = PRODN(I) 
      GO TO 153 
!                                                                       
!...     END OF GROUP OF ALTERNATIVES. SET FLAG FOR NO MORE, OR THIS    
!...     ITEM INTO CURRENT WORD AND FETCH NEXT ITEM INTO TEMP.          
!                                                                       
  151 MORE = .FALSE. 
  152 PRODN(IPROD) = ORF(PRODN(IPROD),NEMTBL(TEMP(1))) 
      TEMP(1) =PRODN(I) 
!                                                                       
!...     ARE THERE MORE ALTERNATIVES IN THIS GROUP                      
!                                                                       
      IF(MORE) GO TO 154 
!                                                                       
!...     NO. UPDATE POINTER TO NEXT VACANT POSITION, AND CLEAR THAT     
!...     WORD. SET FLAG FOR MORE ITEMS.                                 
!                                                                       
  153 IPROD = IPROD+1 
      PRODN(IPROD) = 0 
      MORE = .TRUE. 
!                                                                       
!...     END OF LOOP                                                    
!                                                                       
  154   CONTINUE 
!                                                                       
!...     SET IPROD TO NO. OF WORDS IN PRODUCTION TABLE,                 
!...     AND RETURN.                                                    
!                                                                       
      IPROD = IPROD-1 
      RETURN 
      END                                           
