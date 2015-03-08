! Modified to .f90 from M0006711.F                                    
!********************************************************************                                                                       
!                                                                       
!              FORTRAN SUBROUTINE LOADB                                 
!                                                                       
! LINKAGE       CALL   LOADB                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    BINBCD          SUBROUTINE    LOADP            
!          SUBROUTINE    LOADA                                          
!          SUBROUTINE    LOADI                                          
!          SUBROUTINE    LOADU                                          
!          SUBROUTINE    LOAD0                                          
!          SUBROUTINE    CFORM                                          
!          SUBROUTINE    SORT                                           
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADB 
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
      DIMENSION STKLST(3002),PRODR(3000) 
!  PRODR:      ORDINAL NUMBERS OF THE PRD. TABLES IN SEQUENT. MODE      
      EQUIVALENCE (PRODR(1),STKLST(3)) 
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150),DIGIT(2) 
!  DIGIT:      (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  ELFILE:     I/O FILE NUMBER OF TRANSFORMED PRODUCTION TABLE          
      EQUIVALENCE (ELFILE,SYMFIL(4)) 
!  LCDATA      INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QLENGT:     DIMENSION OF ARRAY LENGTH                                
      EQUIVALENCE (QLENGT,LDXSIZ(6)) 
!  QSTACK:     DIMENSION OF ARRAY PRODR                                 
      EQUIVALENCE (QSTACK,LDXSIZ(12)) 
!  QLEVPO:     DIMENSION OF ARRAY LEVPOS                                
      EQUIVALENCE (QLEVPO,LDXSIZ(13)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
!  IBKPNT:     NAMTBL INDEX OF BRKPNT                                   
!  PRODI:      POINTER TO LAST ENTRY IN PRODN TABLE                     
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  BREAK:      VALUE OF POSTN FOR BRKPNT                                
!  KNT:        NAMTBL INDEX OF ALL                                      
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!                                                                       
!       10.    ITEM AND GROUP CONTROL                                   
!                                                                       
      COMMON/LENGTH/LENGTH 
!  LENGTH:     TABLE OF GROUPS AND NUMBER OF CONTAINED ELEMENTS         
      DIMENSION LENGTH(3,100) 
!                                                                       
!       13.    SPACE FOR PRODUCTION LISTS                               
!                                                                       
      INCLUDE 'PRODN.INC' 
!  PROD2:      CONTAINS PRODUCTION TABLES IN JUMP MODE                  
!                                                                       
!       14.    LEVEL START OF THE PRODUCTIONS IN PRODR                  
!                                                                       
      COMMON/LEVPOS/LEVPOS 
      DIMENSION LEVPOS(12,250) 
!                                                                       
!       16.    RELATION OF ORDINAL NUMBERS TO NAMTBL INDEXES            
!                                                                       
      COMMON/CLSWRD/CLSWRD 
      DIMENSION CLSWRD(100) 
!                                                                       
!       17.    OUTPUT SPACE FOR TRANSFORMED PRODUCTION LIST             
!                                                                       
      COMMON/OUTARY/OUTARY 
      CHARACTER*80 OUTARY 
!                                                                       
!       18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION            
!                                                                       
      COMMON/BRANCH/BRANCH 
      DIMENSION BRANCH(515) 
!  TENMIL:     CONTAINS DIVISOR 10000                                   
      EQUIVALENCE (TENMIL,BRANCH(2)) 
!  LEVEL:      ACTUALLY PROCESSED PRODUCTION LEVEL                      
      EQUIVALENCE (LEVEL,BRANCH(5)) 
!  MAXCLS:     NUMBER OF DEFINITIONS IN A TRANSFORMATION SECTIION       
      EQUIVALENCE (MAXCLS,BRANCH(6)) 
!  CONCAT:     =1 IF TRANSFORMATION OF THE CONCATENATING PRODUCTIONS    
      EQUIVALENCE (CONCAT,BRANCH(15)) 
!*                                                                      
! PURPOSE      TO CHANGE THE BASIC PRODUCTION TABLE FROM                
!              SEQUENTIAL READ FORMAT TO A JUMP MODE TABLE.             
!                                                                       
      CHARACTER*6 JALL,IDIGIT 
      LOGICAL ERRPRT 
      DATA IDIGIT/'DIGIT'/,ERRPRT/.FALSE./,JALL/'ALL'/ 
      CHARACTER*6  MACPRD(25) 
      DATA   MACPRD           /'RTERM'   ,'10028'   ,'MCLTRM'  ,        &
     &  '10060'    ,'ALL'     ,'10080'   ,'MCLTRM'  ,'56'      ,        &
     &  'TERMAC'   ,'10048'   ,'10088'   ,'MCLTRM'  ,'54'      ,        &
     &  '10104'    ,'MCLTRM'  ,'58'      ,'ALL'     ,'10096'   ,        &
     &  'MACVBL'   ,'MCLTRM'  ,'60'      ,'ALL'     ,'10096'   ,        &
     &  'MCLTRM'   ,'55'      /                                         
!**                                                                     
      QPRODR=QSTACK*2 
      CNAMTB(KNT)=JALL 
!                                                                       
      CLSWRD(MAXCLS)=KNT 
!                                                                       
!     SAVE CONTENT OF PRODN IN PRODR AFTER HAVING REPLACED THE NAMTBL-  
!     ADDRESSES OF THE CLASS WORDS BY THE PRIORITY NUMBER.              
!     FILL THE ARRAY LEVPOS (LEVEL POSITION). IT IS                     
!     LEVPOS( 1,X)   PRIORITY NUMBER                                    
!     LEVPOS( 2,X)   START ADDRESS (IN PRODR) OF THE 2ND LEVEL          
!     LEVPOS( 3,X)   START ADDRESS (IN PRODR) OF THE 3RD LEVEL          
!     LEVPOS( 4,X)   START ADDRESS (IN PRODR) OF THE 4TH LEVEL          
!     LEVPOS( 5,X)   START ADDRESS (IN PRODR) OF THE 5TH LEVEL          
!     LEVPOS( 6,X)   START ADDRESS (IN PRODR) OF THE 6TH LEVEL          
!     LEVPOS( 7,X)   START ADDRESS (IN PRODR) OF THE 7TH LEVEL          
!     LEVPOS( 8,X)   START ADDRESS (IN PRODR) OF THE 8TH LEVEL          
!     LEVPOS( 9,X)   START ADDRESS (IN PRODR) OF THE 9TH LEVEL          
!     LEVPOS(10,X)   NUMBER OF LEVELS OF THE PRODUCTION                 
!     LEVPOS(11,X)   PRODUCTION NUMBER (NAMTBL ADDR.) AT FAILING SEARCH 
!     LEVPOS(12,X)   PRODUCTION NUMBER (NAMTBL ADDR.)                   
!                                                                       
      DO 11 J=1,QLEVPO 
      DO 10 I=1,11 
   10 LEVPOS(I,J)=0 
   11 END DO 
      DO 15 J=1,QLENGT 
   15 LENGTH(1,J)=0 
!                                                                       
      M=1 
      IPRO=0 
      NSIGN=-1 
      LEVPOS(1,1)=1 
      DO 60 I=1,PRODI 
      J=PRODN(I) 
      K=IABS(J) 
      IF(I.GE.IPROD)NSIGN=1 
      IF(NAMTBL(K).EQ.DIGIT(1).AND.CNAMTB(K).NE.IDIGIT)GOTO 50 
      DO 20 L=1,MAXCLS 
      IF(K.EQ.CLSWRD(L))GOTO 30 
   20 END DO 
      ERROR=.TRUE. 
      ERRPRT=.TRUE. 
      CASSOC(1)=CNAMTB(K) 
      GOTO 60 
   30 IPRO=IPRO+1 
      IF(IPRO.GT.QPRODR)CALL SPILL(12,'LOADB   ') 
      PRODR(IPRO)=L*ISIGN(1,J) 
      IF(J.NE.K)LEVEL=LEVEL+1 
      IF(LEVEL.GT.8.OR.LEVEL.LT.1)GOTO 60 
      IF(LEVPOS(LEVEL+1,M).EQ.0)LEVPOS(LEVEL+1,M)=IPRO+1 
      GOTO 60 
   50 IF(ERRPRT)WRITE(VLFILE,98)CNAMTB(K),CASSOC(1) 
   98 FORMAT(36H ERROR NO. 7045  IN SUBROUTINE LOADB/1H ,14HIN PRODUCTIO&
     &N ,   A6/1H ,   A6,67H  IS AN INVALID CLASS WORD OR A CLASS WORD W&
     &ITHOUT A PRIORITY VALUE)                                          
      ERRPRT=.FALSE. 
      IPRO=IPRO+1 
      IF(IPRO.GT.QPRODR)CALL SPILL(12,'LOADB   ') 
      PRODR(IPRO)=J 
      LEVPOS(10,M)=LEVEL 
      LEVPOS(12,M)=K*NSIGN 
      IF(LEVEL.EQ.0)M=M-1 
      LEVEL=0 
      M=M+1 
      IF(M.GT.QLEVPO)CALL SPILL(13,'LOADB   ') 
      LEVPOS(1,M)=IPRO+1 
   60 END DO 
      M=M-1 
!                                                                       
!                                                                       
!     EXTEND LEVPOS ARRAY IN A WAY, THAT ONLY ONE PRIORITY NUMBER (CLASS
!     WORD) IS LEADING A TOTAL LINE OF LEVPOS                           
!                                                                       
      KPRO=M 
      DO 90 I=1,M 
      KK=LEVPOS(1,I) 
      LL=LEVPOS(2,I)-1 
      LEVPOS(1,I)=IABS(PRODR(KK)) 
      IF(KK.EQ.LL)GOTO 90 
      KK=KK+1 
      DO 80 J=KK,LL 
      IF(KPRO.GE.QLEVPO)CALL SPILL(13,'LOADB   ') 
      KPRO=KPRO+1 
      DO 70 L=2,12 
   70 LEVPOS(L,KPRO)=LEVPOS(L,I) 
   80 LEVPOS(1,KPRO)=IABS(PRODR(J)) 
   90 END DO 
!                                                                       
      CALL LOAD0(IPRO,KPRO) 
!                                                                       
!     START POSITION AND NUMBER OF 'ALL' PRODUCTIONS                    
!                                                                       
      JPRO=IPRO+1 
      DO 100 KK=1,KPRO 
      NN=KPRO+1-KK 
      IF(LEVPOS(1,NN).NE.MAXCLS)GOTO 110 
  100 END DO 
  110 LL=NN+1 
      JJ=KPRO 
!                                                                       
!     'ALL' IS INCLUDING THE OTHER CLASS WORDS, IF THE CLASS WORDS      
!     DO NOT END IN A PRODUCTION NUMBER AHEAD OF 'ALL'                  
!                                                                       
      L=LEVPOS(1,JPRO) 
      N=LEVPOS(1,NN) 
      DO 130 J=L,N 
      IF(LENGTH(1,J).EQ.0)GOTO 130 
      BREAK=PRODI 
      IF(LENGTH(2,J).LT.0)BREAK=-LENGTH(2,J) 
      DO 120 I=LL,JJ 
      IF(LEVPOS(2,I).GT.BREAK)GOTO 130 
      KPRO=KPRO+1 
      IF(KPRO.GT.QLEVPO)CALL SPILL(13,'LOADB   ') 
      DO 115 K=2,12 
  115 LEVPOS(K,KPRO)=LEVPOS(K,I) 
      LEVPOS(1,KPRO)=J 
  120 END DO 
  130 END DO 
!                                                                       
      CALL SORT(LEVPOS(1,JPRO),12,KPRO-IPRO,1,2) 
!                                                                       
!     LOAD ONE LEVEL PRODUCTION NUMBER FOR SECOND PRODUCTION NUMBER     
!     DELETE ONE LEVEL PRODUCTIONS NOT STANDING ALLONE                  
!                                                                       
      KPRO=KPRO+NN-JJ 
      N=2 
      J=1 
  131 DO 140 I=N,IPRO 
      IF(LEVPOS(10,I).NE.1)GOTO 140 
      LL=LEVPOS(1,I) 
      NN=I-1 
      DO 135 L=J,NN 
      IF(LEVPOS(1,L).NE.LL)GOTO 135 
      LEVPOS(1,I)=0 
      LEVPOS(11,L)=IABS(LEVPOS(12,I)) 
  135 END DO 
  140 END DO 
      IF(J.NE.1)GOTO 150 
      N=JPRO+1 
      J=JPRO 
      IPRO=KPRO 
      GOTO 131 
!                                                                       
!     COMPRESS LEVPOS TABLE                                             
!                                                                       
  150 N=KPRO 
      KPRO=0 
      IPRO=0 
      DO 170 I=1,N 
      IF(LEVPOS(1,I).EQ.0)GOTO 170 
      IF(LEVPOS(12,I).LT.0)IPRO=IPRO+1 
      KPRO=KPRO+1 
      DO 160 K=1,11 
  160 LEVPOS(K,KPRO)=LEVPOS(K,I) 
      LEVPOS(12,KPRO)=IABS(LEVPOS(12,I)) 
  170 END DO 
!                                                                       
!         START DATA FOR CONCATENATING PRODUCTIONS                      
!                                                                       
      IPROD=0 
      LL=1 
      CONCAT=1 
      CALL LOADU(LL,IPRO) 
!                                                                       
!         END OF THE CONCATENATING PRODUCTIONS                          
!                                                                       
      PROD2(1,IPROD)=0 
      PROD2(2,IPROD)=-IBKPNT 
      CALL LOADA 
!                                                                       
!     OUTPUT OF THE MACRO TEXT TRANSFER PRODUCTIONS                     
!                                                                       
      DO 350 J=1,25 
      OUTARY(1:72)=' ' 
      L=TENMIL+4*J 
      CALL BINBCD(L,OUTARY(73:80),N) 
      CALL CFORM(MACPRD(J),OUTARY,8,6) 
  350 WRITE(ELFILE,999)OUTARY 
      CALL CFORM('BRKPNT  ',OUTARY,8,8) 
      CALL CFORM('        ',OUTARY,73,8) 
      WRITE(ELFILE,999)OUTARY 
!                                                                       
!         START FOR THE BASIC PRODUCTIONS                               
!                                                                       
      LL=IPRO+1 
      IPROD=0 
      CONCAT=0 
      CALL LOADU(LL,KPRO) 
!                                                                       
!     OUTPUT OF THE BASIC PRODUCTIONS                                   
!                                                                       
      CALL LOADA 
!                                                                       
!                                                                       
      OUTARY=' ' 
      CALL CFORM('FINI',OUTARY,8,4) 
      WRITE(ELFILE,999)OUTARY 
      REWIND ELFILE 
      KK=1 
      LL=LCDATA 
      LCDATA=ELFILE 
      CALL LOADI(KK) 
      LCDATA=LL 
!                                                                       
      RETURN 
  999 FORMAT(A80) 
      END                                           
