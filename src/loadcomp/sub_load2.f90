! Modified to .f90 from M0006722.F                                    
!********************************************************************                                                                      
!                                                                       
!              FORTRAN SUBROUTINE LOAD2                                 
!                                                                       
! LINKAGE       CALL   LOAD2(FROM)                                      
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    SORT            SUBROUTINE    LOADU            
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOAD2(FROM) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QASSOC:     DIMENSION OF ARRAY ASSOC                                 
      EQUIVALENCE (QASSOC,LDXSIZ(4)) 
!  QPROD2:     DIMENSION OF ARRAY PROD2                                 
      EQUIVALENCE (QPROD2,LDXSIZ(11)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!  KNT:        NAMTBL INDEX OF ALL                                      
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!  JASSOC:     STORAGE OF CLASS WORD COLLECTION. TABLE COMPRESSION      
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
!  IASC:       POINTER TO THE LAST JASSOC ENTRY                         
      EQUIVALENCE (IASC,BRANCH(10)) 
!  IRET:       ALL LEVELS ARE PROCESSED                                 
      EQUIVALENCE (IRET,BRANCH(11)) 
!  STRTPR:     FIRST PRODCTION COLUMN IN ARRAY LEVPOS                   
      EQUIVALENCE (STRTPR,BRANCH(12)) 
!  ENDPRD:     LAST PRODCTION COLUMN IN ARRAY LEVPOS                    
      EQUIVALENCE (ENDPRD,BRANCH(13)) 
!  LGT:        POINTER TO LAST ENTRY IN LENGTH                          
      EQUIVALENCE (LGT,BRANCH(14)) 
!  LEVPRD:     CONTAINS THE PRODUCTION NUMBERS FOR A FAILED SEARCH      
      EQUIVALENCE (LEVPRD(1,1),BRANCH(16)) 
!*                                                                      
      DIMENSION LVL(2,400) 
!                                                                       
! PURPOSE      TO LOAD PRODUCTION LEVELS TWO,THREE, FOUR AND FIVE       
!              INTO THE PRODUCTION TABLES (PROD2).                      
!**                                                                     
      DIVIS=BRANCH(LEVEL-1) 
      IF(LEVEL.GT.5)DIVIS=BRANCH(LEVEL-5) 
!                                                                       
!     SEARCH FOR PARTICULAR AND ENDING PRODUCTIONS.                     
!                                                                       
      IRET=1 
      LPROD=IPROD 
      I1=0 
      PP=-PDERR 
      DO 90 I=ID1,ID2 
      J1=PROCOD(1,I)/DIVIS 
      IF(I1.EQ.J1)GOTO 80 
      I1=J1 
      IPROD=IPROD+2 
      IF(IPROD.GE.QPROD2)CALL SPILL(11,'LOAD2   ') 
      PROD2(1,IPROD-1)=IADRES 
      PROD2(2,IPROD-1)=I1 
      PROD2(1,IPROD)=I 
   80 PROD2(2,IPROD)=I 
      L=PROCOD(2,I) 
      IF(PP.EQ.-PDERR)PP=-IABS(LEVPOS(11,L)) 
      IF(LEVPRD(2,L).LT.LEVEL)PP=-LEVPRD(1,L) 
   90 END DO 
!                                                                       
!         FADE OUT ENDING OR PARTICULAR PRODUCTIONS                     
!                                                                       
      KK=LPROD+2 
      DO 110 I=KK,IPROD,2 
      ID1=PROD2(1,I) 
      ID2=PROD2(2,I) 
      IF(ID2.GT.ID1)GOTO 110 
      PROD2(2,I)=PROCOD(2,ID2) 
      IF(LEVPOS(10,PROD2(2,I)).GT.LEVEL)GOTO 100 
      PROD2(1,I)=0 
      GOTO 110 
  100 PROD2(1,I)=-LEVEL-1 
  110 END DO 
!                                                                       
!         COLLECT CLASS WORDS WITH SAME FINAL PRODUCTIONS               
!               WHICH REMAINING IN THE LEVEL SECTION                    
!                                                                       
      KPROD=IPROD 
      IPROD=LPROD 
      DO 210 I=KK,KPROD,2 
      IF(PROD2(1,I-1).EQ.PROD2(2,I-1))GOTO 210 
      K1=PROD2(1,I) 
      IF(K1.LE.0)GOTO 200 
      K2=PROD2(2,I) 
      IF(I.EQ.KPROD)GOTO 160 
      LL=I+2 
      ASC=IASC+2 
      JASC=IASC 
      NN=IASC+1 
      JASSOC(ASC)=PROD2(2,I-1) 
      DO 130 L=LL,KPROD,2 
      L1=PROD2(1,L) 
      IF(L1.LE.0)GOTO 130 
      L2=PROD2(2,L) 
      IF((K2-K1).NE.(L2-L1))GOTO 130 
      K=K2-K1+1 
      DO 120 J=1,K 
      IF(PROCOD(2,K1-1+J).NE.PROCOD(2,L1-1+J))GOTO 130 
  120 END DO 
      ASC=ASC+1 
      IF(ASC.GT.4*QASSOC)CALL SPILL(4,'LOAD2   ') 
      JASSOC(NN)=-ASC 
      JASSOC(ASC)=PROD2(2,L-1) 
      IASC=ASC 
      PROD2(2,L-1)=PROD2(1,L-1) 
      PROD2(2,I-1)=TENMIL+NN 
  130 END DO 
      IF(NN.GT.IASC.OR.JASC.EQ.0)GOTO 160 
      K=IASC-NN 
      DO 150 J=1,JASC 
      IF(JASSOC(J).GE.0)GOTO 150 
      IF(K.NE.(-JASSOC(J)-J))GOTO 150 
      DO 140 L=1,K 
      IF(JASSOC(J+L).NE.JASSOC(NN+L))GOTO 150 
  140 END DO 
      IASC=JASC 
      PROD2(2,I-1)=TENMIL+J 
      GOTO 160 
  150 END DO 
      JASC=IASC 
  160 LL=PROCOD(2,K1) 
      K1=K1+1 
      DO 170 J=K1,K2 
      IF(PROCOD(2,J).NE.LL)GOTO 200 
  170 END DO 
      IF(LEVPOS(10,LL).GT.LEVEL)GOTO 190 
      PROD2(1,I)=0 
      PROD2(2,I)=-LEVPOS(12,LL) 
      GOTO 200 
  190 PROD2(1,I)=-LEVEL-1 
      PROD2(2,I)=LL 
  200 IPROD=IPROD+2 
      PROD2(1,IPROD-1)=PROD2(1,I-1) 
      PROD2(2,IPROD-1)=PROD2(2,I-1) 
      PROD2(1,IPROD)=PROD2(1,I) 
      PROD2(2,IPROD)=PROD2(2,I) 
  210 END DO 
!                                                                       
!     COMPRESS ARRAY PROCOD AND SEARCH FOR ALTERNATIV PROD. NUMBER      
!                                                                       
      KPROD=IPROD 
      DO 300 I=KK,KPROD,2 
      IF(PROD2(1,I).LE.0)GOTO 300 
      ID1=PROD2(1,I) 
      ID2=PROD2(2,I) 
      IF(LEVEL.NE.5)GOTO 230 
!                                                                       
      DO 220 J=ID1,ID2 
      IF(LEVPOS(10,PROCOD(2,J)).EQ.5)GOTO 221 
  220 END DO 
      GOTO 260 
  221 LL=PROCOD(2,J) 
      DO 223 L=ID1,ID2 
      IF(LL.NE.PROCOD(2,L))GOTO 222 
      PROCOD(1,L)=0 
      GOTO 223 
  222 LEVPRD(1,PROCOD(2,L))=LEVPOS(12,LL) 
      LEVPRD(2,PROCOD(2,L))=LEVEL 
  223 END DO 
      GOTO 260 
!                                                                       
  230 DO 250 J=ID1,ID2 
      K1=PROCOD(1,J) 
      IF(MOD(K1,DIVIS).NE.0)GOTO 250 
      LL=J+1 
      IF(LL.GT.ID2)GOTO 250 
      K1=K1/DIVIS 
      L1=PROCOD(2,J) 
      DO 240 L=LL,ID2 
      K2=PROCOD(1,L)/DIVIS 
      IF(K2.GT.K1)GOTO 250 
      L2=PROCOD(2,L) 
      LEVPRD(1,L2)=LEVPOS(12,L1) 
      LEVPRD(2,L2)=LEVEL 
      PROCOD(1,J)=0 
  240 END DO 
  250 PROCOD(1,J)=MOD(PROCOD(1,J),DIVIS) 
  260 LL=ID2 
      ID2=ID1-1 
      I1=0 
      DO 270 J=ID1,LL 
      IF(PROCOD(1,J).LE.0)GOTO 270 
      ID2=ID2+1 
      IF(ID1.EQ.ID2)NN=PROCOD(2,J) 
      IF(PROCOD(2,J).NE.NN)I1=I1+1 
      PROCOD(1,ID2)=PROCOD(1,J) 
      PROCOD(2,ID2)=PROCOD(2,J) 
  270 END DO 
      IF(ID2.LE.ID1.OR.I1.LE.0)GOTO 280 
      PROD2(1,I)=ID1 
      PROD2(2,I)=ID2 
      IRET=0 
      GOTO 300 
  280 IF(LEVPOS(10,PROCOD(2,ID1)).EQ.LEVEL)GOTO 290 
      PROD2(1,I)=-LEVEL-1 
      PROD2(2,I)=PROCOD(2,ID1) 
      GOTO 300 
  290 PROD2(1,I)=0 
      PROD2(2,I)=-LEVPOS(12,PROCOD(2,ID1)) 
  300 END DO 
!                                                                       
!         SEARCH FOR UNIFORM PARTICULAR PRODUCTION                      
!                                                                       
      DO 340 I=KK,KPROD,2 
      IF(PROD2(1,I).GE.0)GOTO 340 
      L2=PROD2(2,I) 
      L1=-PROD2(1,I) 
      DO 320 K2=STRTPR,ENDPRD 
      IF(LEVPOS(L1,K2).NE.LEVPOS(L1,L2))GOTO 320 
      IF(LEVPOS(11,K2).GT.0.OR.L2.EQ.K2)GOTO 320 
      IF(IABS(LEVPOS(11,K2)).NE.IABS(LEVPOS(11,L2)))GOTO 320 
      IF(LEVPRD(1,K2).NE.LEVPRD(1,L2))GOTO 320 
      PROD2(2,I)=K2 
      GOTO 340 
  320 END DO 
      IF(LEVPOS(11,L2).GT.0)LEVPOS(11,L2)=-LEVPOS(11,L2) 
  340 END DO 
!                                                                       
!         COLLECT CLASS WORDS WITH SAME FINAL PRODUCTIONS               
!                   OF THE PARTICULAR PRODUCTIONS                       
!                                                                       
  350 IPROD=LPROD 
      DO 460 I=KK,KPROD,2 
      IF(PROD2(1,I-1).EQ.PROD2(2,I-1))GOTO 460 
      IF(PROD2(1,I).GT.0)GOTO 450 
      LL=I+2 
      IF(LL.GT.KPROD)GOTO 440 
      ASC=IASC+2 
      JASC=IASC 
      NN=IASC+1 
      I1=0 
      JASSOC(ASC)=PROD2(2,I-1) 
      IF(JASSOC(ASC).GT.TENMIL)I1=1 
      DO 360 L=LL,KPROD,2 
      IF(PROD2(1,L).NE.PROD2(1,I))GOTO 360 
      IF(PROD2(2,L).NE.PROD2(2,I))GOTO 360 
      ASC=ASC+1 
      IF(ASC.GT.4*QASSOC)CALL SPILL(4,'LOAD2   ') 
      JASSOC(NN)=-ASC 
      JASSOC(ASC)=PROD2(2,L-1) 
      IF(JASSOC(ASC).GT.TENMIL)I1=1 
      IASC=ASC 
      PROD2(2,L-1)=PROD2(1,L-1) 
      PROD2(2,I-1)=TENMIL+NN 
  360 END DO 
      IF(NN.GT.IASC.OR.JASC.EQ.0)GOTO 440 
      IF(I1.EQ.0)GOTO 410 
      L1=NN+1 
      L2=-JASSOC(NN) 
      LL=L2 
      DO 390 J=L1,L2 
      IF(JASSOC(J).GT.TENMIL)GOTO 370 
      LL=LL+1 
      JASSOC(LL)=JASSOC(J) 
      GOTO 390 
  370 K=JASSOC(J)-TENMIL+1 
      L=-JASSOC(K-1) 
      DO 380 I1=K,L 
      LL=LL+1 
  380 JASSOC(LL)=JASSOC(I1) 
  390 END DO 
      CALL SORT(JASSOC(L2+1),1,LL-L2,1,1) 
      IASC=NN+1 
      L2=L2+2 
      JASSOC(IASC)=JASSOC(L2-1) 
      DO 400 I1=L2,LL 
      IF(JASSOC(I1).LE.JASSOC(I1-1))GOTO 400 
      IASC=IASC+1 
      JASSOC(IASC)=JASSOC(I1) 
  400 END DO 
      JASSOC(NN)=-IASC 
  410 K=IASC-NN 
      DO 430 J=1,JASC 
      IF(JASSOC(J).GE.0)GOTO 430 
      IF(K.NE.(-JASSOC(J)-J))GOTO 430 
      DO 420 L=1,K 
      IF(JASSOC(J+L).NE.JASSOC(NN+L))GOTO 430 
  420 END DO 
      IASC=JASC 
      PROD2(2,I-1)=TENMIL+J 
      GOTO 440 
  430 END DO 
      JASC=IASC 
  440 IF(PROD2(1,I).LT.0)GOTO 450 
      PROD2(2,I)=-LEVPOS(12,PROD2(2,I)) 
  450 IPROD=IPROD+2 
      PROD2(1,IPROD-1)=PROD2(1,I-1) 
      PROD2(2,IPROD-1)=PROD2(2,I-1) 
      PROD2(1,IPROD)=PROD2(1,I) 
      PROD2(2,IPROD)=PROD2(2,I) 
  460 END DO 
!                                                                       
!     SORT SO THAT PARTICULAR PRODUCTIONS STAND AT THE END OF THE COLUMN
!                                                                       
      L2=IPROD 
      DO 462 I=KK,IPROD,2 
      IF(PROD2(1,I).GE.0)GOTO 462 
      L2=L2+2 
      IF(L2.GE.QPROD2)CALL SPILL(11,'LOAD2   ') 
      PROD2(2,L2-1)=PROD2(2,I-1) 
      PROD2(1,L2)=PROD2(1,I) 
      PROD2(2,L2)=PROD2(2,I) 
  462 END DO 
      IF(L2.EQ.IPROD)GOTO 469 
      LL=LPROD 
      DO 464 I=KK,IPROD,2 
      IF(PROD2(1,I).LT.0)GOTO 464 
      LL=LL+2 
      PROD2(2,LL-1)=PROD2(2,I-1) 
      PROD2(1,LL)=PROD2(1,I) 
      PROD2(2,LL)=PROD2(2,I) 
  464 END DO 
      L1=IPROD+2 
      K2=L1 
      IF(L2.EQ.L1)GOTO 467 
  465 K1=0 
      DO 466 I=L1,L2,2 
      IF(PROD2(2,I).LE.K1)GOTO 466 
      K1=PROD2(2,I) 
      K2=I 
  466 END DO 
  467 LL=LL+2 
      PROD2(2,LL-1)=PROD2(2,K2-1) 
      PROD2(1,LL  )=PROD2(1,K2  ) 
      PROD2(2,LL  )=PROD2(2,K2  ) 
      PROD2(2,K2)=0 
      IF(LL.LT.IPROD)GOTO 465 
!                                                                       
!     END OF THE LEVEL                                                  
!                                                                       
  469 J=PROD2(2,IPROD-1) 
      IF(J.LT.1.OR.J.GT.MAXCLS)GOTO 470 
      IF(CLSWRD(J).EQ.KNT)GOTO 480 
  470 IPROD=IPROD+1 
      IF(IPROD.GE.QPROD2)CALL SPILL(11,'LOAD2   ') 
      PROD2(1,IPROD)=0 
      PROD2(2,IPROD)=PP 
!                                                                       
  480 IF(STRTPR.EQ.1)GOTO 560 
!                                                                       
!     COMPRESS LEVEL SECTION IF BASIC PRODUCTIONS                       
!                                                                       
      IF(LGT.EQ.0)GOTO 550 
      K=0 
      L=0 
  490 K=K+1 
      IF(K.GT.LGT)GOTO 530 
      IF(LVL(2,K).NE.LEVEL)GOTO 490 
      I=LVL(1,K)+1 
      J=IPROD+1 
  500 I=I-1 
      J=J-1 
      IF(J.LE.LPROD)GOTO 540 
      IF(PROD2(1,J).GT.TENMIL)GOTO 510 
      IF(PROD2(1,J).GT.0)GOTO 520 
      IF(PROD2(1,J).NE.PROD2(1,I))GOTO 520 
  510 IF(PROD2(2,J).NE.PROD2(2,I))GOTO 520 
      GOTO 500 
  520 N=IPROD-J 
      IF(N.LT.3.OR.N.LE.L)GOTO 490 
      L=N 
      M=LVL(1,K)-L+1 
      GOTO 490 
  530 IF(L.EQ.0)GOTO 550 
      IPROD=IPROD-L+1 
      IF(PROD2(1,IPROD).GT.TENMIL)GOTO 535 
      IPROD=IPROD+1 
      M=M+1 
  535 PROD2(1,IPROD)=0 
      PROD2(2,IPROD)=TENMIL+4*M 
      GOTO 560 
!                                                                       
  540 PROD2(1,FROM+1)=0 
      PROD2(2,FROM+1)=TENMIL+4*(I+1) 
      IPROD=LPROD 
      IRET=1 
      GOTO 560 
!                                                                       
  550 IF(LGT.GE.400)GOTO 560 
      LGT=LGT+1 
      LVL(1,LGT)=IPROD 
      LVL(2,LGT)=LEVEL 
!                                                                       
  560 RETURN 
      END                                           
