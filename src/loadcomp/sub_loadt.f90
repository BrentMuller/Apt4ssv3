! Modified to .f90 from M0006718.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADT                                 
!                                                                       
! LINKAGE       CALL   LOADT                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    CFORM           SUBROUTINE    LOADG            
!          SUBROUTINE    LOADA                                          
!          SUBROUTINE    LOADI                                          
!          SUBROUTINE    LOADU                                          
!          SUBROUTINE    LOAD0                                          
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADT 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMTBL:     INTEGER CORRESPONDING TO NAME TABLE ENTRY                
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
      DIMENSION CODES(150),DIGIT(2),CONGEO(2) 
!  DIGIT:      (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
!  CONGEO:     (1)=CODE CLASS 39000,(2)=NAMTBL INDEX OF 'CONGEO'        
      EQUIVALENCE (CONGEO(1),CODES(77)) 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  ELFILE:     I/O FILE NUMBER OF TRANSFORMED PRODUCTION TABLE          
      EQUIVALENCE (ELFILE,SYMFIL(4)) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QSTACK:     DIMENSION OF ARRAY PRODR                                 
      EQUIVALENCE (QSTACK,LDXSIZ(12)) 
!  QLEVPO:     DIMENSION OF ARRAY LEVPOS                                
      EQUIVALENCE (QLEVPO,LDXSIZ(13)) 
!  QCLSWD:     DIMENSION OF ARRAY LENGTH                                
      EQUIVALENCE (QCLSWD,LDXSIZ(14)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  IBKPNT:     NAMTBL INDEX OF BRKPNT                                   
!  PRODI:      POINTER TO LAST ENTRY IN PRODN TABLE                     
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!                                                                       
!       11.    GEOMETRIC TABLE LOCATIONS                                
!                                                                       
!  GEOMLC:     START POSITION FOR A SRF TYPE IN THE GEOMETRIC TABLE     
      COMMON/GEOMLC/GEOMLC 
      DIMENSION GEOMLC(50) 
!                                                                       
!       13.    SPACE FOR PRODUCTION LISTS                               
!                                                                       
      INCLUDE 'PRODN.INC' 
!                                                                       
!       14.    LEVEL START OF THE PRODUCTIONS IN PRODR                  
!                                                                       
      COMMON/LEVPOS/LEVPOS 
      DIMENSION LEVPOS(12,250) 
!                                                                       
!       15.    INTEGER CODE AND LEVPOS COLUMN OF A PRODUCTION           
!                                                                       
      COMMON/PROCOD/PROCOD 
      DIMENSION PROCOD(2,1500) 
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
!  LEVEL:      ACTUALLY PROCESSED PRODUCTION LEVEL                      
      EQUIVALENCE (LEVEL,BRANCH(5)) 
!  MAXCLS:     NUMBER OF DEFINITIONS IN A TRANSFORMATION SECTIION       
      EQUIVALENCE (MAXCLS,BRANCH(6)) 
!*                                                                      
! PURPOSE      TO CHANGE THE GEOMETRIC PRODUCTION TABLE FROM            
!              SEQUENTIAL READ FORMAT TO A BRANCHING MODE TABLE.        
!                                                                       
      CHARACTER*6 IDIGIT 
      DATA IDIGIT/'DIGI'/ 
!**                                                                     
      QPRODR=QSTACK*2 
      NAMTBL(IBKPNT)=CONGEO(1) 
      KK=0 
!                                                                       
!     SAVE CONTENT OF PRODN IN PRODR                                    
!                                                                       
      MM=PRODI-1 
!                                                                       
      DO 1 I=1,MM 
      IF(I.GT.QPRODR)CALL SPILL(12,'LOADT   ') 
    1 PRODR(I)=PRODN(I) 
!                                                                       
!     ORDINAL NUMBERS REPLACE THE NAMTBL ADDRESSES OF THE CLASS WORDS   
!                                                                       
      REWIND ELFILE 
      M=1 
   10 MAXCLS=0 
      CLSWRD(1)=0 
      DO 60 IPRO=M,MM 
      J=PRODR(IPRO) 
      IF(J.EQ.-PDERR)GOTO 70 
      K=IABS(J) 
      IF(NAMTBL(K).EQ.DIGIT(1).AND.CNAMTB(K).NE.IDIGIT)GOTO 60 
      DO 20 L=1,MAXCLS 
      IF(K.EQ.CLSWRD(L))GOTO 30 
   20 END DO 
      MAXCLS=MAXCLS+1 
      IF(MAXCLS.GT.QCLSWD)CALL SPILL(14,'LOADT   ') 
      CLSWRD(MAXCLS)=K 
      L=MAXCLS 
   30 PRODR(IPRO)=L*ISIGN(1,J) 
   60 END DO 
      PRODR(IPRO)=-PDERR 
   70 IPRO=IPRO-1 
!                                                                       
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
      DO 81 J=1,QLEVPO 
      DO 80 I=1,11 
   80 LEVPOS(I,J)=0 
   81 END DO 
      DO 85 I=14,15 
   85 BRANCH(I)=0 
      LEVEL=0 
!                                                                       
      KPRO=1 
      LEVPOS(1,1)=M 
      DO 100 I=M,IPRO 
      J=PRODR(I) 
      K=IABS(J) 
      IF(K.GT.MAXCLS)GOTO 90 
      IF(J.NE.K)LEVEL=LEVEL+1 
      IF(LEVEL.GT.8.OR.LEVEL.LT.1)GOTO 100 
      IF(LEVPOS(LEVEL+1,KPRO).EQ.0)LEVPOS(LEVEL+1,KPRO)=I+1 
      GOTO 100 
   90 LEVPOS(10,KPRO)=LEVEL 
      LEVPOS(12,KPRO)=K 
      IF(LEVEL.EQ.0)KPRO=KPRO-1 
      LEVEL=0 
      KPRO=KPRO+1 
      IF(KPRO.GT.QLEVPO)CALL SPILL(13,'LOADT   ') 
      LEVPOS(1,KPRO)=I+1 
  100 END DO 
      KPRO=KPRO-1 
      IF(KPRO.LT.2)GOTO 390 
!                                                                       
!     EXTEND LEVPOS ARRAY IN A WAY, THAT ONLY ONE PRIORITY NUMBER (CLASS
!     WORD) IS LEADING A TOTAL LINE OF LEVPOS                           
!                                                                       
      K=KPRO 
      DO 140 I=1,K 
      L=LEVPOS(1,I) 
      N=LEVPOS(2,I)-1 
      LEVPOS(1,I)=IABS(PRODR(L)) 
      IF(L.EQ.N)GOTO 140 
      L=L+1 
      DO 130 J=L,N 
      IF(KPRO.GT.QLEVPO)CALL SPILL(13,'LOADT   ') 
      KPRO=KPRO+1 
      DO 120 LL=2,12 
  120 LEVPOS(LL,KPRO)=LEVPOS(LL,I) 
  130 LEVPOS(1,KPRO)=IABS(PRODR(J)) 
  140 END DO 
!                                                                       
      LL=1 
      CALL LOAD0(LL,KPRO) 
!                                                                       
!                                                                       
!     LOAD ONE LEVEL PRODUCTION NUMBER FOR SECOND PRODUCTION NUMBER     
!                                                                       
      DO 155 I=2,KPRO 
      IF(LEVPOS(10,I).NE.1)GOTO 155 
      J=LEVPOS(1,I) 
      N=I-1 
      DO 150 L=1,N 
      IF(LEVPOS(1,L).NE.J)GOTO 150 
      LEVPOS(1,I)=0 
      LEVPOS(11,L)=LEVPOS(12,I) 
  150 END DO 
  155 END DO 
!                                                                       
!         DELETE  SINGLE LEVEL PRODUCTIONS                              
!                                                                       
      K=KPRO 
      KPRO=0 
      DO 170 I=1,K 
      IF(LEVPOS(1,I).EQ.0)GOTO 170 
      KPRO=KPRO+1 
      DO 160 L=1,12 
  160 LEVPOS(L,KPRO)=LEVPOS(L,I) 
  170 END DO 
!                                                                       
  390 KK=KK+1 
      LL=GEOMLC(KK) 
      GEOMLC(KK)=0 
      OUTARY=' ' 
      CALL CFORM(CNAMTB(LL),OUTARY,8,6) 
      CALL CFORM('/$$',OUTARY,14,3) 
      WRITE(ELFILE,999)OUTARY 
      LL=1 
      IPROD=0 
      CALL LOADU(LL,KPRO) 
!                                                                       
!         OUTPUT OF A GEOMETRIC PRODUCTION GROUP                        
!                                                                       
      CALL LOADA 
      M=IPRO+2 
      OUTARY=' ' 
      IF(M.LT.MM)GOTO 10 
!                                                                       
      CALL CFORM('FINI',OUTARY,8,4) 
      WRITE(ELFILE,999)OUTARY 
      REWIND ELFILE 
      KK=2 
      LL=LCDATA 
      LCDATA=ELFILE 
      CALL LOADI(KK) 
      LCDATA=LL 
!                                                                       
      RETURN 
  999 FORMAT(A80) 
      END                                           
