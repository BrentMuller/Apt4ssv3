! Modified to .f90 from M0006720.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOAD0                                 
!                                                                       
! LINKAGE       CALL   LOAD0(IPRO,KPRO)                                 
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    SORT            SUBROUTINE    LOADB            
!                                        SUBROUTINE    LOADT            
!                                                                       
      SUBROUTINE LOAD0(IPRO,KPRO) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
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
!       14.    LEVEL START OF THE PRODUCTIONS IN PRODR                  
!                                                                       
      COMMON/LEVPOS/LEVPOS 
      DIMENSION LEVPOS(12,250) 
!                                                                       
!       18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION            
!                                                                       
      COMMON/BRANCH/BRANCH 
      DIMENSION BRANCH(515) 
!  IASC:       POINTER TO THE LAST JASSOC ENTRY                         
      EQUIVALENCE (IASC,BRANCH(10)) 
!  STRTPR:     FIRST PRODCTION COLUMN IN ARRAY LEVPOS                   
      EQUIVALENCE (STRTPR,BRANCH(12)) 
!*                                                                      
! PURPOSE      TO GATHER THE PRODUCTIONS POSSESSING THE SAME PRODUCTION 
!              NUMBERS                                                  
!**                                                                     
!     SORT THE LEVPOS TABLE ASCENDING IN FIRST AND SECOND COLUMN        
!                                                                       
      JPRO=IPRO 
      IF(IPRO.EQ.1)GOTO 30 
      CALL SORT(LEVPOS(1,1),12,KPRO,2,1) 
      DO 10 I=1,KPRO 
      IF(LEVPOS(12,I).GT.0)GOTO 20 
   10 END DO 
   20 JPRO=I 
      IPRO=I-1 
      CALL SORT(LEVPOS(1,1),12,IPRO,1,2) 
!                                                                       
   30 KK=KPRO+1-JPRO 
      CALL SORT(LEVPOS(1,JPRO),12,KK,1,2) 
      II=JPRO 
      JJ=LEVPOS(1,JPRO) 
      KK=LEVPOS(1,KPRO) 
      IF(STRTPR.EQ.1)GOTO 36 
!                                                                       
!     DELETE FOLLOWING LONGER PRODUCTIONS OF THE SAME START STRUCTURE   
!                                                                       
      DO 35 I=JPRO,KPRO 
      IF(LEVPOS(10,I).NE.1)GOTO 35 
      L=I+1 
      DO 34 J=L,KPRO 
      IF(LEVPOS(1,J).EQ.LEVPOS(1,I))LEVPOS(1,J)=0 
   34 END DO 
   35 END DO 
!                                                                       
!     GATHER THE PRODUCTIONS                                            
!                                                                       
   36 DO 70 I=JJ,KK 
      LENGTH(1,I)=0 
      LENGTH(2,I)=II 
      DO 50 J=II,KPRO 
      IF(LEVPOS(1,J)-I)50,40,60 
   40 LENGTH(1,I)=LENGTH(1,I)+1 
   50 END DO 
   60 II=J 
   70 END DO 
!                                                                       
      IASC=0 
      II=KK-1 
      DO 100 I=JJ,II 
      IF(LENGTH(1,I).LE.0)GOTO 100 
      K=I+1 
      N=IASC+1 
      ASC=IASC+2 
      JASSOC(ASC)=LEVPOS(1,LENGTH(2,I)) 
      L=LENGTH(1,I) 
      DO 90 J=K,KK 
      IF(LENGTH(1,J).NE.L)GOTO 90 
      DO 80 M=1,L 
      IF(LEVPOS(2,LENGTH(2,I)-1+M).NE.LEVPOS(2,LENGTH(2,J)-1+M))GOTO 90 
   80 END DO 
      ASC=ASC+1 
      JASSOC(ASC)=LEVPOS(1,LENGTH(2,J)) 
      JASSOC(N)=-ASC 
      IASC=ASC 
      LENGTH(1,I)=-N 
      LENGTH(1,J)=0 
      DO 85 M=1,L 
   85 LEVPOS(1,LENGTH(2,J)-1+M)=0 
   90 END DO 
  100 END DO 
!                                                                       
!     ZERO ALL PRODUCTIONS BUT ONE WHICH ARE BELONGING TO A GROUP       
!     OF SAME PRODUCTION PATTERNS                                       
!                                                                       
      KK=JPRO-1 
      DO 120 L=JPRO,KPRO 
      IF(LEVPOS(1,L).EQ.0)GOTO 120 
      KK=KK+1 
      IF(LEVPOS(10,L).EQ.1)LENGTH(2,LEVPOS(1,L))=-LEVPOS(2,L) 
      DO 110 J=1,12 
  110 LEVPOS(J,KK)=LEVPOS(J,L) 
  120 END DO 
      KPRO=KK 
!                                                                       
      RETURN 
      END                                           
