! Modified to .f90 from M0006719.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADU                                 
!                                                                       
! LINKAGE       CALL   LOADU(LL,KK)                                     
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    LOAD1           SUBROUTINE    LOADB            
!          SUBROUTINE    LOAD2           SUBROUTINE    LOADT            
!          SUBROUTINE    SORT                                           
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADU(LL,KK) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        2.    STACK AND POINTER STORAGE                                
!                                                                       
      COMMON/STKLST/STKLST 
      DIMENSION STKLST(3002),PRODR(3000) 
!  PRODR:      ORDINAL NUMBERS OF THE PRD. TABLES IN SEQUENT. MODE      
      EQUIVALENCE (PRODR(1),STKLST(3)) 
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
!  QPRODN:     DIMENSION OF ARRAY PRODN                                 
      EQUIVALENCE (QPRODN,LDXSIZ(7)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  BREAK:      VALUE OF POSTN FOR BRKPNT                                
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!  KNT:        NAMTBL INDEX OF ALL                                      
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!  JASSOC:     STORAGE OF CLASS WORD COLLECTION. TABLE COMPRESSION      
!                                                                       
!       10.    ITEM AND GROUP CONTROL                                   
!                                                                       
      COMMON/LENGTH/LENGTH 
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
!       18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION            
!                                                                       
      COMMON/BRANCH/BRANCH 
      DIMENSION BRANCH(515),LEVPRD(2,250) 
!  TENMIL:     CONTAINS DIVISOR 10000                                   
      EQUIVALENCE (TENMIL,BRANCH(2)) 
!  LEVEL:      ACTUALLY PROCESSED PRODUCTION LEVEL                      
      EQUIVALENCE (LEVEL,BRANCH(5)) 
!  MAXCLS:     NUMBER OF DEFINITIONS IN A TRANSFORMATION SECTIION       
      EQUIVALENCE (MAXCLS,BRANCH(6)) 
!  IADRES:     CODE DESCRIBES LEVEL NUMBER AND LEADING CLASS WORD       
      EQUIVALENCE (IADRES,BRANCH(7)) 
!  ID1:        BEGIN OF A REGION IN ARRAY PROCOD TO BE PROCESSED        
      EQUIVALENCE (ID1,BRANCH(8)) 
!  ID2:        END OF A REGION IN ARRAY PROCOD TO BE PROCESSED          
      EQUIVALENCE (ID2,BRANCH(9)) 
!  IRET:       ALL LEVELS ARE PROCESSED                                 
      EQUIVALENCE (IRET,BRANCH(11)) 
!  STRTPR:     FIRST PRODCTION COLUMN IN ARRAY LEVPOS                   
      EQUIVALENCE (STRTPR,BRANCH(12)) 
!  ENDPRD:     LAST PRODCTION COLUMN IN ARRAY LEVPOS                    
      EQUIVALENCE (ENDPRD,BRANCH(13)) 
!  LGT:        POINTER TO LAST ENTRY IN LENGTH                          
      EQUIVALENCE (LGT,BRANCH(14)) 
!  CONCAT:     =1 IF TRANSFORMATION OF THE CONCATENATING PRODUCTIONS    
      EQUIVALENCE (CONCAT,BRANCH(15)) 
!  LEVPRD:     CONTAINS THE PRODUCTION NUMBERS FOR A FAILED SEARCH      
      EQUIVALENCE (LEVPRD(1,1),BRANCH(16)) 
!*                                                                      
! PURPOSE    TO CONTROL THE LEVEL GENERATION AND CONNECTION             
!            TO HANDLE THE PARTICULAR PRODUCTIONS                       
!                                                                       
!     HANDLING OF THE FIRST LEVEL, SEARCH FOR PARTICULAR PRODUCTIONS    
!                                                                       
!     PROD2(1,X)   PROD2(2,X)                                           
!     N*TENMIL+I1  IN              I1  =CLASS WORD ORDINAL NUMBER       
!                                  IN  =CLASS WORD ORDINAL NUMBER OF    
!                                       LEVEL N , N =LEVEL NUMBER       
!     TENMIL +I1   TENMIL+A        A   =ADDRESS OF JASSOC FOR A COLLEC- 
!                                       TED GROUP OF CLASS WORDS        
!     0            -LEVPOS(10,Y)   PRODUCTION NUMBER.END OF PRODUCTION  
!     GT.0         GT.PROD2(1,X)   POSITIONS OF HIGHER LEVELLED CLASS   
!                                  WORDS IN ARRAY PROCOD                
!     LT.0         GT.0            PARTICULAR HIGHER LEVELLED PRODUCTION
!                                  STARTING ON AT PRODR(-PROD2(1,X),    
!**                                                      PROD2(2,X))    
      IF(KK.LT.2)GOTO 580 
      CALL SORT(LEVPOS(1,LL),12,KK+1-LL,1,2) 
      LGT=0 
      STRTPR=LL 
      ENDPRD=KK 
      II=IPROD 
      III=IPROD+1 
      I1=0 
      M=0 
      DO 120 I=LL,KK 
      IF(LEVPOS(11,I).EQ.0)LEVPOS(11,I)=PDERR 
      LEVPRD(1,I)=0 
      LEVPRD(2,I)=PDERR 
      IF(I1.EQ.LEVPOS(1,I))GOTO 110 
      I1=LEVPOS(1,I) 
      J1=I 
      IPROD=IPROD+2 
      IF(IPROD.GT.QPRODN/2)CALL SPILL(7,'LOADU   ') 
      PROD2(1,IPROD-1)=TENMIL+I1 
      PROD2(2,IPROD-1)=I1 
      IF(CONCAT.EQ.1)GOTO 100 
      IF(LENGTH(1,I1).LT.0)PROD2(2,IPROD-1)=TENMIL-LENGTH(1,I1) 
  100 IF(LEVPOS(10,I).GT.1)GOTO 110 
      PROD2(1,IPROD)=0 
      PROD2(2,IPROD)=-LEVPOS(12,I) 
      GOTO 120 
  110 PROD2(1,IPROD)=J1 
      PROD2(2,IPROD)=I 
  120 END DO 
      IF(CLSWRD(I1).EQ.KNT)GOTO 130 
      IPROD=IPROD+1 
      IF(IPROD.GT.QPRODN/2)CALL SPILL(7,'LOADU   ') 
      PROD2(1,IPROD)=0 
      PROD2(2,IPROD)=-PDERR 
!                                                                       
!     FIND ALL POSSIBLE VARIATIONS OF A STARTING CLASS WORD             
!                                                                       
  130 LPROD=IPROD 
  140 II=II+1 
      IF(II.GT.LPROD)GOTO 240 
      IF(PROD2(1,II).LT.TENMIL)GOTO 140 
      IF(PROD2(1,II+1).LT.1)GOTO 140 
      I1=PROD2(2,II) 
      IF(I1.GT.TENMIL)I1=JASSOC(I1+1-TENMIL) 
      ID1=PROD2(1,II+1) 
      ID2=PROD2(2,II+1) 
      IF(ID2.GT.ID1)GOTO 150 
      PROD2(1,II+1)=-2 
      LEVPOS(11,ID1)=-LEVPOS(11,ID1) 
      GOTO 140 
!                                                                       
!         SECOND LEVEL PROCESSING                                       
!         PREPARE PRODUCTION CODE OF LEVEL 2 TO 5                       
!                                                                       
  150 LEVEL=2 
      CALL LOAD1 
      J1=IPROD 
      IADRES=LEVEL*TENMIL+I1 
      CALL LOAD2(II) 
      J2=IPROD 
      IF(IRET.EQ.1)GOTO 140 
!                                                                       
  160 J1=J1+1 
      IF(J1.GT.J2)GOTO 140 
      IF(PROD2(1,J1).LT.TENMIL)GOTO 160 
      IF(PROD2(1,J1+1).LT.1)GOTO 160 
!                                                                       
!         THIRD LEVEL PROCESSING                                        
!                                                                       
      ID1=PROD2(1,J1+1) 
      ID2=PROD2(2,J1+1) 
      LEVEL=3 
      IADRES=LEVEL*TENMIL+I1 
      J3=IPROD 
      CALL LOAD2(J1) 
      J4=IPROD 
      IF(IRET.EQ.1)GOTO 160 
!                                                                       
  170 J3=J3+1 
      IF(J3.GT.J4)GOTO 160 
      IF(PROD2(1,J3).LT.TENMIL)GOTO 170 
      IF(PROD2(1,J3+1).LT.1)GOTO 170 
!                                                                       
!         FORTH LEVEL PROCESSING                                        
!                                                                       
      ID1=PROD2(1,J3+1) 
      ID2=PROD2(2,J3+1) 
      LEVEL=4 
      IADRES=LEVEL*TENMIL+I1 
      J5=IPROD 
      CALL LOAD2(J3) 
      J6=IPROD 
      IF(IRET.EQ.1)GOTO 170 
!                                                                       
  180 J5=J5+1 
      IF(J5.GT.J6)GOTO 170 
      IF(PROD2(1,J5).LT.TENMIL)GOTO 180 
      IF(PROD2(1,J5+1).LT.1)GOTO 180 
!                                                                       
!         FIFTH LEVEL PROCESSING                                        
!                                                                       
      ID1=PROD2(1,J5+1) 
      ID2=PROD2(2,J5+1) 
      LEVEL=5 
      IADRES=LEVEL*TENMIL+I1 
      J7=IPROD 
      CALL LOAD2(J5) 
      J8=IPROD 
      IF(IRET.EQ.1)GOTO 180 
!                                                                       
!         PREPARE PRODUCTION CODE OF LEVEL 6 TO 9                       
!                                                                       
  190 J7=J7+1 
      IF(J7.GT.J8)GOTO 180 
      IF(PROD2(1,J7).LT.TENMIL)GOTO 190 
      IF(PROD2(1,J7+1).LT.1)GOTO 190 
      LEVEL=6 
      ID1=PROD2(1,J7+1) 
      ID2=PROD2(2,J7+1) 
      CALL LOAD1 
!                                                                       
!         SIXTH LEVEL PROCESSING                                        
!                                                                       
      J9=IPROD 
      IADRES=LEVEL*TENMIL+I1 
      CALL LOAD2(J7) 
      J10=IPROD 
      IF(IRET.EQ.1)GOTO 190 
!                                                                       
  200 J9=J9+1 
      IF(J9.GT.J10)GOTO 190 
      IF(PROD2(1,J9).LT.TENMIL)GOTO 200 
      IF(PROD2(1,J9+1).LT.1)GOTO 200 
!                                                                       
!         SEVENTH LEVEL PROCESSING                                      
!                                                                       
      ID1=PROD2(1,J9+1) 
      ID2=PROD2(2,J9+1) 
      LEVEL=7 
      IADRES=LEVEL*TENMIL+I1 
      J11=IPROD 
      CALL LOAD2(J9) 
      J12=IPROD 
      IF(IRET.EQ.1)GOTO 200 
!                                                                       
  210 J11=J11+1 
      IF(J11.GT.J12)GOTO 200 
      IF(PROD2(1,J11).LT.TENMIL)GOTO 210 
      IF(PROD2(1,J11+1).LT.1)GOTO 210 
!                                                                       
!         8TH LEVEL PROCESSING                                          
!                                                                       
      ID1=PROD2(1,J11+1) 
      ID2=PROD2(2,J11+1) 
      LEVEL=8 
      IADRES=LEVEL*TENMIL+I1 
      CALL LOAD2(J11) 
      IF(IRET.EQ.1)GOTO 210 
!                                                                       
      WRITE(VLFILE,230) 
  230 FORMAT(1H ,99HERROR NO. 7049 IN SUBROUTINE LOADU. THE SUBROUTINE M&
     &UST BE EXTENDED TO DISSOLVE LONGER PRODUCTIONS.)                  
      ERROR=.TRUE. 
      GOTO 570 
!                                                                       
!     CONNECT THE LEVELS BY INSERTING THE ADDRESSES (GOTO)              
!                                                                       
  240 DO 280 I=III,IPROD 
      J1=PROD2(1,I) 
      IF(J1.LE.TENMIL)GOTO 280 
      PROD2(1,I)=TENMIL 
      IF(PROD2(1,I+1).LT.1)GOTO 280 
      J1=J1+TENMIL 
      J=I+2 
      DO 250 M=J,IPROD 
      IF(J1.EQ.PROD2(1,M).AND.PROD2(2,M+1).NE.0)GOTO 260 
  250 END DO 
      GOTO 280 
  260 PROD2(1,I+1)=0 
      PROD2(2,I+1)=TENMIL+4*M 
  270 IF(PROD2(1,M+1).GT.0)PROD2(2,M+1)=0 
      IF(PROD2(1,M+1).LT.1)PROD2(1,M)=TENMIL 
      M=M+2 
      IF(J1.NE.PROD2(1,M))GOTO 280 
      GOTO 270 
  280 END DO 
!                                                                       
!     SEARCH FOR UNIFORM END SECTIONS OF THE PRODUCTIONS                
!                                                                       
      J1=IPROD+1 
      J3=STRTPR-1 
  290 J2=J1 
  300 J3=J3+1 
      IF(J3.GE.ENDPRD)GOTO 450 
      IF(LEVPOS(11,J3).GT.0)GOTO 300 
      LEVPOS(11,J3)=IABS(LEVPOS(11,J3)) 
      PROD2(1,J2)=J3 
      J4=J3+1 
      DO 310 I=J4,ENDPRD 
      IF(LEVPOS(11,I).GT.0)GOTO 310 
      IF(LEVPOS(12,I).NE.LEVPOS(12,J3))GOTO 310 
      IF(IABS(LEVPOS(11,I)).NE.IABS(LEVPOS(11,J3)))GOTO 310 
      IF(LEVPRD(1,I).NE.LEVPRD(1,J3))GOTO 310 
      LEVPOS(11,I)=IABS(LEVPOS(11,I)) 
      J2=J2+1 
      PROD2(1,J2)=I 
  310 END DO 
      IF(J1.EQ.J2)GOTO 300 
      J4=0 
      DO 340 I=1,IPROD 
      IF(PROD2(1,I).GE.0)GOTO 340 
      DO 320 J=J1,J2 
      IF(PROD2(2,I).EQ.PROD2(1,J))GOTO 330 
  320 END DO 
      GOTO 340 
  330 IF(J4.GE.QLENGT)GOTO 340 
      J4=J4+1 
      LENGTH(1,J4)=-PROD2(1,I) 
      LENGTH(2,J4)=PROD2(2,I) 
      LENGTH(3,J4)=I 
  340 END DO 
  350 J5=-1 
      J6=0 
      DO 360 I=1,J4 
      IF(LENGTH(2,I).LT.0)GOTO 360 
      J7=LEVPOS(10,LENGTH(2,I))-LENGTH(1,I) 
      IF(J5-J7)355,354,360 
  354 IF(LEVPOS(10,LENGTH(2,I)).LE.J6)GOTO 360 
  355 J5=J7 
      J6=LEVPOS(10,LENGTH(2,I)) 
      J11=I 
  360 END DO 
      IF(J5.LT.0)GOTO 290 
      J7=LENGTH(2,J11) 
      J8=LEVPOS(10,J7)+1 
      IF(J8.LT.10)GOTO 380 
      J8=LEVPOS(9,J7) 
  370 J8=J8+1 
      K=IABS(PRODR(J8)) 
      IF(K.GT.MAXCLS)GOTO 390 
      GOTO 370 
  380 J8=LEVPOS(J8,J7) 
  390 DO 440 I=1,J4 
      J9=LENGTH(2,I) 
      IF(J7.EQ.J9.OR.J9.LT.0)GOTO 440 
      J6=LEVPOS(10,J9)+1 
      IF(J6.LT.10)GOTO 410 
      J6=LEVPOS(9,J9) 
  400 J6=J6+1 
      K=IABS(PRODR(J6)) 
      IF(K.GT.MAXCLS)GOTO 420 
      GOTO 400 
  410 J6=LEVPOS(J6,J9) 
  420 J2=LEVPOS(LENGTH(1,I),J9) 
      J10=J8 
  430 J10=J10-1 
      J6 =J6 -1 
      IF(PRODR(J6).NE.PRODR(J10))GOTO 440 
      IF(J6.GT.J2)GOTO 430 
      J=LENGTH(3,I) 
      PROD2(1,J)=PROD2(1,J)+LEVPOS(10,J9)-LEVPOS(10,J7) 
      PROD2(2,J)=J7 
      LENGTH(2,I)=-1 
  440 END DO 
!                                                                       
      LENGTH(2,J11)=-1 
      GOTO 350 
  450 LEVPOS(11,ENDPRD)=IABS(LEVPOS(11,ENDPRD)) 
      BREAK=IPROD 
      IF(CONCAT.EQ.1)GOTO 570 
!                                                                       
!     COLLECT THE FINAL PART OF ALL PARTICULAR PRODUCTIONS IN 'LENGTH'  
!                                                                       
      J10=BREAK-1 
      DO 560 I=III,J10 
      IF(PROD2(1,I).GE.0)GOTO 560 
      J1=1 
      J2=PROD2(2,I) 
      J3=I+1 
      J4=-PROD2(1,I) 
      J5=LEVPOS(10,J2) 
      LENGTH(1,J1)=I 
      LENGTH(2,J1)=J4 
!                                                                       
      DO 490 K=J3,BREAK 
      IF(PROD2(1,K).GE.0)GOTO 490 
      IF(PROD2(2,K).NE.J2)GOTO 490 
      J1=J1+1 
      LENGTH(1,J1)=K 
      LENGTH(2,J1)=-PROD2(1,K) 
      J4=MIN(LENGTH(2,J1),J4) 
  490 END DO 
!                                                                       
      DO 500 K=1,J1 
      J3=LENGTH(1,K) 
      PROD2(1,J3)=0 
  500 PROD2(2,J3)=TENMIL+4*(IPROD+LENGTH(2,K)-J4+1) 
!                                                                       
      J6=MIN(8,J5) 
      DO 510 K=J4,J6 
      IPROD=IPROD+1 
      PROD2(1,IPROD)=LEVPOS(K,J2) 
  510 PROD2(2,IPROD)=LEVPOS(K+1,J2)-1 
      IF(J5.LT.9)GOTO 550 
      J6=LEVPOS(9,J2)-1 
  520 J6=J6+1 
      IF(IABS(PRODR(J6)).GT.MAXCLS)GOTO 550 
      J7=J6 
      IF(PRODR(J7).LT.0)GOTO 540 
  530 J7=J7+1 
      IF(PRODR(J7).GT.0)GOTO 530 
  540 IPROD=IPROD+1 
      PROD2(1,IPROD)=J6 
      PROD2(2,IPROD)=J7 
      J6=J7 
      GOTO 520 
!                                                                       
  550 IPROD=IPROD+2 
      PROD2(1,IPROD)=0 
      PROD2(1,IPROD-1)=0 
      PROD2(2,IPROD)=-IABS(LEVPOS(11,J2)) 
      IF(LEVPRD(2,J2).LT.PDERR)PROD2(2,IPROD)=-LEVPRD(1,J2) 
      PROD2(2,IPROD-1)=-LEVPOS(12,J2) 
  560 END DO 
!                                                                       
  570 RETURN 
!                                                                       
  580 BREAK=0 
      IF(MAXCLS.EQ.0)GOTO 620 
      J6=LEVPOS(10,1) 
      J5=MIN(8,J6) 
      DO 590 I=1,J5 
      IPROD=IPROD+1 
      PROD2(1,IPROD)=LEVPOS(IPROD, 1) 
  590 PROD2(2,IPROD)=LEVPOS(IPROD+1,1)-1 
      IF(J6.LT.9)GOTO 620 
      J5=PROD2(2,IPROD) 
      DO 610 I=9,J6 
      IPROD=IPROD+1 
      J5=J5+1 
      PROD2(1,IPROD)=J5 
  600 IF(PRODR(J5).LT.0)GOTO 610 
      J5=J5+1 
      GOTO 600 
  610 PROD2(2,IPROD)=J5 
  620 IPROD=IPROD+2 
      PROD2(1,IPROD)=0 
      PROD2(1,IPROD-1)=0 
      PROD2(2,IPROD)=-PDERR 
      PROD2(2,IPROD-1)=-LEVPOS(12,1) 
      GOTO 570 
!                                                                       
      END                                           
