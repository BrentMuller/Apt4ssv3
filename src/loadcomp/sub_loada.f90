! Modified to .f90 from M0006710.F                                    
!********************************************************************                                                                      
!                                                                       
!              FORTRAN SUBROUTINE LOADA                                 
!                                                                       
! LINKAGE       CALL   LOADA                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    BINBCD          SUBROUTINE    LOADB            
!          SUBROUTINE    CFORM           SUBROUTINE    LOADT            
!                                                                       
      SUBROUTINE LOADA 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  NAMBTL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
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
!  ELFILE:     I/O FILE NUMBER OF TRANSFORMED PRODUCTION TABLE          
      EQUIVALENCE (ELFILE,SYMFIL(4)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  BREAK:      VALUE OF POSTN FOR BRKPNT                                
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
!  MAXCLS:     NUMBER OF DEFINITIONS IN A TRANSFORMATION SECTIION       
      EQUIVALENCE (MAXCLS,BRANCH(6)) 
!*                                                                      
! PURPOSE      TO OUTPUT THE BASIC PRODUCTION TABLE AND THE             
!              GEOMETRIC PRODUCTION TABLE ON A TEMPORARY FILE           
!**                                                                     
      IF(BREAK.EQ.0)GOTO 165 
      DO 160 I=1,BREAK 
      OUTARY(1:72)=' ' 
      L=TENMIL+4*I 
      CALL BINBCD(L,OUTARY(73:80),N) 
      J1=PROD2(1,I) 
      J2=PROD2(2,I) 
      IF(J1.EQ.0)GOTO 140 
      IF(J2.GT.MAXCLS)GOTO 110 
!                                                                       
!     OUTPUT OF A PARTICULAR CLASS WORD                                 
!                                                                       
      J2=CLSWRD(J2) 
      CALL CFORM(CNAMTB(J2),OUTARY,8,6) 
      GOTO 160 
!                                                                       
!     OUTPUT OF A GROUP OF CLASS WORDS                                  
!                                                                       
  110 J2=J2-TENMIL+1 
      J1=IABS(JASSOC(J2-1)) 
      K=0 
      DO 130 J=J2,J1 
      K=K+1 
      LL=JASSOC(J) 
      LL=CLSWRD(LL) 
      CALL CFORM(CNAMTB(LL),OUTARY,8*K,6) 
      IF(J.EQ.J1)GOTO 160 
      CALL CFORM(',',OUTARY,8*K+7,1) 
      IF(K.LT.7)GOTO 130 
      CALL CFORM(',$',OUTARY,62,2) 
      WRITE(ELFILE,999)OUTARY 
      OUTARY(1:72)=' ' 
      K=0 
  130 END DO 
      GOTO 160 
!                                                                       
  140 IF(J2.GT.TENMIL)GOTO 150 
!                                                                       
!     OUTPUT OF A PRODUCTION NUMBER OR BRKPNT                           
!                                                                       
      CALL CFORM(CNAMTB(-J2),OUTARY,8,6) 
      GOTO 160 
!                                                                       
!     OUTPUT OF A GOTO ADDRESS                                          
!                                                                       
  150 CALL BINBCD(J2,OUTARY(9:16),N) 
  160 WRITE(ELFILE,999)OUTARY 
!                                                                       
!     OUTPUT OF THE PARTICULAR PRODUCTION SECTION                       
!                                                                       
  165 BREAK=BREAK+1 
      IF(BREAK.GE.IPROD)GOTO 250 
      DO 230 I=BREAK,IPROD 
      OUTARY(1:72)=' ' 
      L=TENMIL+4*I 
      CALL BINBCD(L,OUTARY(73:80),N) 
      J1=PROD2(1,I) 
      J2=PROD2(2,I) 
      IF(J2.GE.0)GOTO 180 
!                                                                       
!     OUTPUT OF THE PRODUCTION NUMBER                                   
!                                                                       
      CALL CFORM(CNAMTB(-J2),OUTARY,8,6) 
      GOTO 230 
!                                                                       
!     OUTPUT OF A GROUP OF CLASS WORDS                                  
!                                                                       
  180 K=0 
      DO 200 J=J1,J2 
      K=K+1 
      LL=IABS(PRODR(J)) 
      LL=CLSWRD(LL) 
      CALL CFORM(CNAMTB(LL),OUTARY,8*K,6) 
      IF(J.EQ.J2)GOTO 230 
      CALL CFORM(',',OUTARY,8*K+7,1) 
      IF(K.LT.7)GOTO 200 
      CALL CFORM(',$',OUTARY,62,2) 
      WRITE(ELFILE,999)OUTARY 
      OUTARY(1:72)=' ' 
      K=0 
  200 END DO 
  230 WRITE(ELFILE,999)OUTARY 
!                                                                       
  250 RETURN 
  999 FORMAT(A80) 
      END                                           
