! Modified to .f90 from M0006721.F                                    
!********************************************************************                                                                     
!                                                                       
!              FORTRAN SUBROUTINE LOAD1                                 
!                                                                       
! LINKAGE       CALL   LOAD1                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    SORT            SUBROUTINE    LOADU            
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOAD1 
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
!  VLFILE      VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QPROCD:     DIMENSION OF ARRAY PROCOD                                
      EQUIVALENCE (QPROCD,LDXSIZ(8)) 
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
!       18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION            
!                                                                       
      COMMON/BRANCH/BRANCH 
      DIMENSION BRANCH(515) 
!  MILION:     CONTAINS DIVISOR 1000000                                 
      EQUIVALENCE (MILION,BRANCH(1)) 
!  TENMIL:     CONTAINS DIVISOR 10000                                   
      EQUIVALENCE (TENMIL,BRANCH(2)) 
!  CENT:       CONTAINS DIVISOR 100                                     
      EQUIVALENCE (CENT,BRANCH(3)) 
!  LEVEL:      ACTUALLY PROCESSED PRODUCTION LEVEL                      
      EQUIVALENCE (LEVEL,BRANCH(5)) 
!  ID1:        BEGIN OF A REGION IN ARRAY PROCOD TO BE PROCESSED        
      EQUIVALENCE (ID1,BRANCH(8)) 
!  ID2:        END OF A REGION IN ARRAY PROCOD TO BE PROCESSED          
      EQUIVALENCE (ID2,BRANCH(9)) 
!*                                                                      
! PURPOSE      TO LOAD INTEGER CODE OF LEVELS TWO,THREE, FOUR AND FIVE  
!              INTO THE ARRAY PROCOD.                                   
!                                                                       
      DIMENSION JD(8),SAVE(50) 
      EQUIVALENCE(JD(1),J1),(JD(2),J2),(JD(3),J3),(JD(4),J4),(JD(5),J5),&
     &          (JD(6),J6),(JD(7),J7),(JD(8),J8)                        
!**                                                                     
!     FIND ALL POSSIBLE VARIATIONS OF A STARTING CLASS WORD             
!                                                                       
      LVA=LEVEL 
      LVE=LEVEL+3 
      PSTRT=0 
      IF(LEVEL.NE.6)GOTO 50 
      IF((ID2-ID1).LT.50)GOTO 20 
      WRITE(VLFILE,10) 
   10 FORMAT('   ERROR: ARRAY SAVE IN SUBROUTINE LOAD1 EXCEEDED. REDEFIN&
     &E ARRAY SAVE')                                                    
      STOP 
   20 PSTRT=PEND 
      N=0 
      DO 30 I=ID1,ID2 
      N=N+1 
   30 SAVE(N)=PROCOD(2,I) 
      CALL SORT(SAVE(1),1,N,1,1) 
      II=1 
      DO 40 I=2,N 
      IF(SAVE(I).EQ.SAVE(I-1))GOTO 40 
      II=II+1 
      SAVE(II)=SAVE(I) 
   40 END DO 
      ID2=ID1+II-1 
   50 NN=PSTRT 
      II=0 
      DO 80 N=ID1,ID2 
      II=II+1 
      I=N 
      IF(LEVEL.EQ.6)I=SAVE(II) 
      LVL=LEVPOS(10,I) 
      IF(LVL.LT.LVA)GOTO 80 
      DO 60 MM=LVA,LVE 
      JD(MM-LVA+1)=LEVPOS(MM,I) 
      JD(MM-LVA+5)=LEVPOS(MM+1,I)-1 
      IF(JD(MM-LVA+1).LT.1)JD(MM-LVA+1)=1 
      IF(JD(MM-LVA+5).LT.JD(MM-LVA+1))JD(MM-LVA+5)=JD(MM-LVA+1) 
   60 END DO 
      IF(LVE.EQ.9)J8=J4 
      DO 70 J=J1,J5 
      JJ=IABS(PRODR(J))*MILION 
      DO 70 K=J2,J6 
      KK=JJ 
      IF(LVL.GT.LVA)KK=KK+IABS(PRODR(K))*TENMIL 
      DO 70 L=J3,J7 
      LL=KK 
      IF(LVL.GT.LVA+1)LL=LL+IABS(PRODR(L))*CENT 
      DO 70 M=J4,J8 
      MM=LL 
      IF(LVL.GT.LVA+2.AND.LVE.LT.9)MM=MM+IABS(PRODR(M)) 
      IF(MM.EQ.0)GOTO 70 
      IF(NN.EQ.QPROCD)CALL SPILL(8,'LOAD1   ') 
      NN=NN+1 
      PROCOD(1,NN)=MM 
      PROCOD(2,NN)=I 
   70 CONTINUE 
   80 END DO 
      ID1=PSTRT+1 
      CALL SORT(PROCOD(1,ID1),2,NN-PSTRT,1,2) 
!                                                                       
!     DELETE A FOLLOWING PRODUCTION OF THE SAME FORMAT                  
!                                                                       
      ID2=PSTRT 
      MM=-1 
      LL=6 
      DO 100 I=ID1,NN 
      IF(MM.NE.PROCOD(1,I))GOTO 90 
      J2=PROCOD(2,I) 
      IF(LEVPOS(10,J2).LT.6.AND.LEVPOS(10,LL).LT.6)GOTO 100 
      IF(LEVPOS(10,J2).EQ.LEVPOS(10,LL).AND.                            &
     &   LEVPOS(12,J2).EQ.LEVPOS(12,LL))GOTO 100                        
   90 ID2=ID2+1 
      MM=PROCOD(1,I) 
      LL=PROCOD(2,I) 
      PROCOD(1,ID2)=MM 
      PROCOD(2,ID2)=LL 
  100 END DO 
      IF(LEVEL.EQ.2)PEND=NN 
!                                                                       
      RETURN 
      END                                           
