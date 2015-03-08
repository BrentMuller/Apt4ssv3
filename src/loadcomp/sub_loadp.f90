! Modified to .f90 from M0006716.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADP                                 
!                                                                       
! LINKAGE       CALL   LOADP                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    LOADB                         MAIN             
!          SUBROUTINE    LOADI                                          
!          SUBROUTINE    LOADS                                          
!          INTEGER FCT.  NAME                                           
!          SUBROUTINE    BCDBIN                                         
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADP 
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
      DIMENSION STKLST(3002) 
!  MCTOP:      VALUE OF POSTN FOR MBKPNT                                
      EQUIVALENCE (MCTOP,STKLST(2)) 
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150),DIGIT(2) 
!  DIGIT       (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
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
!  BPFILE:     BLOCK DATA OUTPUT OF CODE TABLE AND BASIC PRODUCTIONS    
      EQUIVALENCE (BPFILE,SYMFIL(1)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QMETA:      DIMENSION OF ARRAY META (OUTPUT)                         
      EQUIVALENCE (QMETA,LDXSIZ(2)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
!  NUMEL:      NUMBER OF ELEMENTS IN ASSOC TABLE                        
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  BREAK:      VALUE OF POSTN FOR BRKPNT                                
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!                                                                       
!       12.    BIT OUTPUT PATTERNS                                      
!                                                                       
      COMMON/ELBIT/ELBIT 
      DIMENSION ELBIT(200) 
!                                                                       
!       13.    NAMTBL INDEXES OF THE PROD. TABLES                       
!                                                                       
      INCLUDE 'PRODN.INC' 
!                                                                       
!       19.    BIT CONSTANTS                                            
!                                                                       
      INCLUDE 'ALLBTS.INC' 
!  Z9999       SIGNALIZES START OF A SURFACE PRODUCTION SEQUENCE        
!  ZAAAA       SIGNALIZES JUMP ADDRESSES IN THE PRODUCTION TABLE        
!  ZCCCC       SIGNALIZES A PRODUCTION NUMBER IN THE TABLE              
!*                                                                      
! PURPOSE      TO CAUSE THE READING OF THE META CLASSES AND             
!              THE BASIC PRODUCTION TABLES, AND TO PRODUCE              
!              FORTRAN BLOCK DATA PROGRAMS FOR THE META CLASSES,        
!              AND FOR THE LOADING OF THE PRODUCTION TABLE.             
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              I                  I            COUNTER FOR DO LOOPS     
!              IANY               C*6          CONTAINS ALL ('ALL')     
!              I28                C*6          CONTAINS ('28')          
!              J                  I            NAMTBL INDEX OF PROD. NO.
!              K                  I            GENERAL VARIABLE         
!              L                  I            NAMTBL INDEX             
!              M                  I            NUMBER OF CHARACTERS IN 3
!                                                                       
!   CHARACTER FUNCTION TO CONVERT INTEGER TO HEXADECIMAL STRING         
      CHARACTER*8 HEX 
                                                                        
      CHARACTER*6 IANY,I28 
      DATA I28/'28'/,IANY/'ALL'/ 
!**                                                                     
!...     PUT ALL, 28 INTO NAMTBL                                        
!                                                                       
      K = NAME (IANY) 
      NAMTBL(K) = 9999000 
      PDERR=NAME(I28) 
      NAMTBL(PDERR) = DIGIT(1) 
      K=1 
      WRITE(VLFILE,4001) 
 4001 FORMAT (1H1,5X,27HBASIC PRODUCTION PROCESSING) 
!                                                                       
!...     CALL LOADI TO READ PRODUCTION TABLES                           
!                                                                       
      CALL LOADI(K) 
!                                                                       
!...     IF THERE WAS A FORMATTING ERROR IN THE PRODUCTION TABLES       
!...     RETURN, OTHERWISE CALL LOADS TO ASSIGN BIT-PATTERNS            
!...     AND TO PRODUCE THE INTERNAL PRODUCTION TABLES.                 
!                                                                       
      IF(ERROR)RETURN 
      CALL LOADB 
      CALL LOADS 
      QPRODT=(IPROD+12)/10*10 
      I=QMETA+3 
      J=QPRODT+QMETA+2 
!                                                                       
!...     WRITE HEADING FOR BLOCK DATA PROGRAM                           
!                                                                       
      WRITE(BPFILE,3000) 
 3000 FORMAT(6X,17HBLOCK DATA BDSCRT,57X/                               &
     &1HC,79X/                                                          &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,20HCOMMON/SRCTBL/SRCTBL,54X)                                   
      WRITE(BPFILE,3001) J,QPRODT,QMETA,I 
 3001 FORMAT(6X,17HDIMENSION SRCTBL(,I4,9H),PRODTB(,I4,7H),META(,I2,1H) &
     &,30X/                                                             &
     &6X,31HEQUIVALENCE (BRKPNT,SRCTBL(1)),,43X/                        &
     &5X,32H1            (MBKPNT,SRCTBL(2)),,43X/                       &
     &5X,33H2            (META(1),SRCTBL(3)),,42X/                      &
     &5X,31H3            (PRODTB(1),SRCTBL(,I2,3H)) ,39X)               
!                                                                       
!...     WRITE DATA STATEMENTS TO ASSIGN BIT-PATTERS TO EACH ITEM       
!...     THAT OCCURRED IN THE PRODUCTION TABLES, I.E. THE META-CLASSES. 
!                                                                       
      DO 2 I=1,NUMEL 
      K=ASSOC(1,I) 
      L = NAMTBL(K)/MODULO 
      IF (L.GT.QMETA) CALL SPILL(2,'LOADP   ') 
    2 WRITE(BPFILE,3002)CNAMTB(K),NAMTBL(K),HEX(ELBIT(I)),L,ELBIT(I) 
 3002 FORMAT(20HC    META ENTRY FOR ,A6,7H CLASS ,I5,5H  / Z,A8,1H/,    &
     & 28X/6X,10HDATA META(,I3,22H)                    /,I11,1H/,28X)   
!                                                                       
!...     WRITE BREAKPOINT DATA STATEMENT                                
!                                                                       
      BREAK=BREAK+1 
      MCTOP=MCTOP+2 
      WRITE(BPFILE,3003)MCTOP,BREAK 
 3003 FORMAT(6X,19HDATA BRKPNT,MBKPNT/,I2,1H,,I2,1H/,49X) 
!                                                                       
!...     WRITE DATA STATEMENTS TO PRODUCE PRODUCTION TABLE              
!                                                                       
      K=0 
      JJ=1 
      WRITE(BPFILE,3008)K,JJ,(Z9999+K) 
      DO 100 I=1,IPROD 
      JJ=JJ+1 
!                                                                       
!...     IF NEXT ITEM IS NEGATIVE IT IS THE TERMINATOR OF THIS          
!...     PRODUCTION. IS IT NEGATIVE                                     
!                                                                       
      IF(PRODN(I).LT.0)GOTO 98 
      IF (PRODN(I).EQ.0) PRODN(I)=ALLBTS(1) 
      IF(JJ.NE.BREAK.AND.JJ.NE.MCTOP) GOTO 97 
      K=4*I 
      WRITE(BPFILE,3008)K,JJ,(Z9999+K) 
 3008 FORMAT(36HC                         /Z9999/ + ,I4,40X/            &
     &       6X,12HDATA PRODTB(,I6,3H) /I11,1H/,42X)                    
      JJ=JJ+1 
!                                                                       
!...     NO. WRITE DATA STATEMENT WITH OCTAL VALUE.                     
   97 WRITE(BPFILE,3004)HEX(PRODN(I)),JJ,PRODN(I) 
 3004 FORMAT(29HC                         / Z,A8,1H/,42X/               &
     &       6X,12HDATA PRODTB(,I6,3H) /I11,1H/,42X)                    
      GO TO 100 
!                                                                       
!...     THIS ITEM IS NEGATIVE, -(NO. OF PRODUCTION).                   
!...     FETCH BCD OF ITS MODULUS FROM THE NAMTBL AND WRITE             
!...     DATA STATEMENT FOR NEGATIVE INTEGER.                           
!                                                                       
   98 J=-PRODN(I) 
      CALL BCDBIN(CNAMTB(J),K,M) 
      IF(K.GE.10000)GOTO 99 
      WRITE(BPFILE,3005)K,JJ,(ZCCCC+K) 
 3005 FORMAT(36HC                         /ZCCCC/ + ,I4,40X/            &
     &       6X,12HDATA PRODTB(,I6,3H) /I11,1H/,42X)                    
      GOTO 100 
   99 K=K-10000 
      WRITE(BPFILE,3006)K,JJ,(ZAAAA+K) 
 3006 FORMAT(36HC                         /ZAAAA/ + ,I4,40X/            &
     &       6X,12HDATA PRODTB(,I6,3H) /I11,1H/,42X)                    
  100 END DO 
!                                                                       
!...     BLOCK DATA PROGRAM IS NOW WRITTEN.                             
!...     WRITE END CARD AND RETURN.                                     
!                                                                       
      WRITE(BPFILE,3007) 
 3007 FORMAT(7X,3HEND,70X) 
      RETURN 
      END                                           
