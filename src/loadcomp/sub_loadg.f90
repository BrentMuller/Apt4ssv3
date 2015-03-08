! Modified to .f90 from M0006712.F                                    
!********************************************************************                                                                       
!                                                                       
!              FORTRAN SUBROUTINE LOADG                                 
!                                                                       
! LINKAGE       CALL   LOADG                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          SUBROUTINE    LOADI                         MAIN             
!          SUBROUTINE    LOADN                                          
!          SUBROUTINE    LOADS                                          
!          SUBROUTINE    LOADT                                          
!          INTEGER FCT.  NAME                                           
!          SUBROUTINE    BCDBIN                                         
!          SUBROUTINE    SORT                                           
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADG 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  CHARST:     BEGINNING OF BASIC CHARACTER SECTION OF NAMTBL           
!  CHARND:     END OF BASIC CHARACTER SECTION OF NAMTBL                 
!  INAMST:     BEGIN GEOMETRIC DEFINITION ROUTINE NAME SECTION(NAMTBL)  
!  INAMND:     END OF GEOMETRIC DEFINITION ROUTINE NAME SECTION(NAMTBL) 
!  NAMEST:     NAMTBL INDEX OF BEGIN OF THE PART PROGRAM NAME  SECTION  
!  NAMMAX:     NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION     
!  IFIXST:     INDEX OF BEGINNING OF FIXED POINT NUMBER SECTION,CNUMTB  
!  IFIXND:     INDEX OF START OF FIXED POINT NUMBER SECTION OF CNUMTB   
!  NUMBST:     INDEX OF BEGINNING OF NUMBER SECTION OF CNUMTB           
!  NUMBND:     INDEX OF END OF NUMBER SECTION OF CNUMTB                 
!  NAMTBL:     INTEGER CODES FOR CORRESPONDING NAME TABLE ENTRIES       
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!  CNUMTB:     NUMBER TABLE                                             
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150),DIGIT(2),IDENT(2) 
!  DIGIT:      (1)=CODE CLASS 10000,(2)=NAMTBL INDEX OF 'DIGIT '        
      EQUIVALENCE (DIGIT(1),CODES(19)) 
!  IDENT:      (1)=CODE CLASS 35000,(2)=NAMTBL INDEX OF 'IDENT '        
      EQUIVALENCE (IDENT(1),CODES(69)) 
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
!  NTFILE:     BLOCK DATA OUTPUT OF NAMTBL AND NAMTBL POINTERS          
      EQUIVALENCE (NTFILE,SYMFIL(2)) 
!  GPFILE:     BLOCK DATA OUTPUT OF GEOMETRIC PRODUCTIONS               
      EQUIVALENCE (GPFILE,SYMFIL(3)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QPMIDT:     DIMENSION OF ARRAY PMIDTB                                
      EQUIVALENCE (QPMIDT,LDXSIZ(3)) 
!  QGEOML:     DIMENSION OF ARRAY GEOMLC                                
      EQUIVALENCE (QGEOML,LDXSIZ(5)) 
!  QPRODN:     DIMENSION OF ARRAY PRODN                                 
      EQUIVALENCE (QPRODN,LDXSIZ(7)) 
!  QIAGMX:     DIMENSION OF ARRAY IAGMXY                                
      EQUIVALENCE (QIAGMX,LDXSIZ(10)) 
!  QARGMX:     DIMENSION OF ARRAY ARGMXY (OUTPUT)                       
      EQUIVALENCE (QARGMX,LDXSIZ(15)) 
!  QGEOLO:     DIMENSION OF ARRAY GEOLOC                                
      EQUIVALENCE (QGEOLO,LDXSIZ(17)) 
!  QIPRMI:     DIMENSION OF ARRAY IPRMID                                
      EQUIVALENCE (QIPRMI,LDXSIZ(18)) 
!  QNAMTB:     DIMENSION OF ARRAY NAMTBL(OUTPUT)                        
      EQUIVALENCE (QNAMTB,LDXSIZ(27)) 
!  QNUMTB:     DIMENSION OF ARRAY CNUMTB(OUTPUT)                        
      EQUIVALENCE (QNUMTB,LDXSIZ(28)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
! IBKPNT:      NAMTBL INDEX OF BRKPNT                                   
!  NUMEL:      NUMBER OF ELEMENTS IN ASSOC TABLE                        
!  IPROD:      NUMBER OF ITEMS IN PRODUCTION TABLES                     
!  PDERR:      NAMTBL INDEX OF '28' = PROD. NOT FOUND                   
!                                                                       
!        9.    ITEM AND GROUP CONTROL                                   
!                                                                       
      INCLUDE 'ASSOC.INC' 
!                                                                       
!       11.    GEOMETRIC TABLE LOCATIONS                                
!                                                                       
!  GEOMLC:     START POSITION FOR A SRF TYPE IN THE GEOMETRIC TABLE     
      COMMON/GEOMLC/GEOMLC 
      DIMENSION GEOMLC(50) 
!                                                                       
!       12.    BIT OUTPUT PATTERNS                                      
!                                                                       
      COMMON/ELBIT/ELBIT 
      DIMENSION ELBIT(200) 
!                                                                       
!       13.    SPACE FOR PRODUCTION LISTS                               
!                                                                       
      INCLUDE 'PRODN.INC' 
!                                                                       
!       19.    BIT CONSTANTS                                            
!                                                                       
      INCLUDE 'ALLBTS.INC' 
!  Z9999:      SIGNALIZES START OF A SURFACE PRODUCTION SEQUENCE        
!  ZAAAA:      SIGNALIZES JUMP ADDRESSES IN THE PRODUCTION TABLE        
!  ZCCCC:      SIGNALIZES A PRODUCTION NUMBER IN THE TABLE              
!*                                                                      
! PURPOSE      TO CAUSE THE READING OF DATA TO BE LOADED INTO           
!              NAMTBL, AND THE GEOMETRIC PRODUCTION TABLES,             
!              AND TO PRODUCE FORTRAN BLOCK DATA PROGRAMS FOR           
!              VARIOUS PRESET POINTERS TO ITEMS IN NAMTBL,              
!              FOR THE LOADING OF NAMTBL, AND FOR THE LOADING           
!              OF THE GEOMETRIC TABLES.                                 
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              I                  I            GENERAL                  
!              IAGMXY      250    I            FOR STORAGE OF ARGMXY    
!                                              TABLE                    
!              IPRMID     3*35    I            CORRESPONDENCE BETWEEN   
!                                              PERMID'S AND INTEGERS.   
!                                              SEE 7LDG FOR INITIAL     
!                                              VALUE                    
!              I200               C            CONTAINS 200 IN BCD      
!              J                  I            USED FOR PRODUCTION NO.  
!              K                  I            PARAMETER TO LOADI       
!              L                  I            USED IN DO LOOP          
!              L1                 I            USED IN DO LOOP          
!              M                  I            COUNTER FOR DECK NAME    
!                                              NUMBERS                  
!              N                  I            USED FOR NO. OF CHARS.   
!                                              IN CALL TO BCDBIN        
!                                                                       
!    CHARACTER FUNCTION TO CONVERT INTEGER TO HEXADECIMAL STRING        
      CHARACTER*8 HEX 
!                                                                       
      DIMENSION IAGMXY(250) 
      CHARACTER*6 I200,TEMP,BKPNT 
      CHARACTER*6 CPRMID(35) 
      DIMENSION IPRMID(35) 
      DATA I200/'200'/,BKPNT/'BRKPNT'/ 
      DATA CPRMID(1),IPRMID(1)/'XLARGE',1/,                             &
     &     CPRMID(2),IPRMID(2)/'YLARGE',2/,                             &
     &     CPRMID(3),IPRMID(3)/'ZLARGE',3/,                             &
     &     CPRMID(4),IPRMID(4)/'XSMALL',4/,                             &
     &     CPRMID(5),IPRMID(5)/'YSMALL',5/,                             &
     &     CPRMID(6),IPRMID(6)/'ZSMALL',6/,                             &
     &     CPRMID(7),IPRMID(7)/'XYPLAN',1/,                             &
     &     CPRMID(8),IPRMID(8)/'YZPLAN',2/,                             &
     &     CPRMID(9),IPRMID(9)/'ZXPLAN',3/                              
      DATA CPRMID(10),IPRMID(10)/'RIGHT', 1/,                           &
     &     CPRMID(11),IPRMID(11)/'LEFT ', 2/,                           &
     &     CPRMID(12),IPRMID(12)/'ATANGL',1/,                           &
     &     CPRMID(13),IPRMID(13)/'SLOPE', 2/,                           &
     &     CPRMID(14),IPRMID(14)/'LARGE', 1/,                           &
     &     CPRMID(15),IPRMID(15)/'SMALL', 2/,                           &
     &     CPRMID(16),IPRMID(16)/'IN   ', 1/,                           &
     &     CPRMID(17),IPRMID(17)/'OUT  ', 2/,                           &
     &     CPRMID(18),IPRMID(18)/'INTAN', 1/,                           &
     &     CPRMID(19),IPRMID(19)/'OUTAN', 2/                            
      DATA CPRMID(20),IPRMID(20)/'POSX ', 1/,                           &
     &     CPRMID(21),IPRMID(21)/'POSY ', 2/,                           &
     &     CPRMID(22),IPRMID(22)/'POSZ ', 3/,                           &
     &     CPRMID(23),IPRMID(23)/'NEGX ', 4/,                           &
     &     CPRMID(24),IPRMID(24)/'NEGY ', 5/,                           &
     &     CPRMID(25),IPRMID(25)/'NEGZ ', 6/,                           &
     &     CPRMID(26),IPRMID(26)/'XYROT', 1/,                           &
     &     CPRMID(27),IPRMID(27)/'YZROT', 2/,                           &
     &     CPRMID(28),IPRMID(28)/'ZXROT', 3/,                           &
     &     CPRMID(29),IPRMID(29)/'XAXIS', 1/                            
      DATA CPRMID(30),IPRMID(30)/'YAXIS', 2/,                           &
     &     CPRMID(31),IPRMID(31)/'5PT  ', 1/,                           &
     &     CPRMID(32),IPRMID(32)/'4PT1SL',2/,                           &
     &     CPRMID(33),IPRMID(33)/'3PT2SL',3/,                           &
     &     CPRMID(34),IPRMID(34)/'TANTO ',1/,                           &
     &     CPRMID(35),IPRMID(35)/'PERPTO',2/                            
!**                                                                     
!...     CALL LOADN TO READ ITEMS INTO NAMTBL                           
!                                                                       
      CALL LOADN 
      PDERR=NAME(I200) 
      NAMTBL(PDERR)=DIGIT(1) 
      IBKPNT=NAME(BKPNT) 
      NAMTBL(IBKPNT)=99000 
      DO 300 I=1,QGEOML 
  300 GEOMLC(I) = 0 
      K=2 
!                                                                       
!...     CALL LOADI TO READ GEOMETRY TABLES                             
!                                                                       
      CALL LOADI(K) 
      IF(ERROR)RETURN 
      CALL LOADT 
      DO 301 I=1,QIAGMX 
!                                                                       
!...     SET UP IAGMXY AS FOLLOWS - IAGMXY(K) = L                       
!...     WHERE   K = MODE OF GEOMETRIC MODIFIER                         
!...     AND     L = NAMTBL INDEX OF INTEGER ASSOCIATED WITH IT         
!                                                                       
  301 IAGMXY(I)=0 
      DO 22  I=1,QIPRMI 
      K = NAME(CPRMID(I)) 
      IF (NAMTBL(K).EQ.0) GOTO 22 
      K = NAMTBL(K)-IDENT(1) 
      IF (K.GT.QIAGMX) CALL SPILL(10,'LOADG   ') 
      IAGMXY(K) = IFIXST + IPRMID(I) 
   22 END DO 
!                                                                       
!...     PRODUCE LISTING OF NAMTBL LOADING AND BLOCK DATA PROGRAMS      
!...     TO SET UP NAMTBL.                                              
!                                                                       
      L=CHARST 
      L1 = INAMST+100 
!                                                                       
!...     WRITE HEADING FOR BLOCK DATA PROGRAM                           
!                                                                       
      WRITE(NTFILE,401) QNAMTB ,QNAMTB ,QNUMTB 
  401 FORMAT(6X,17HBLOCK DATA BDNAME,57X/                               &
     &35HC     BLOCK DATA PROGRAM FOR NAMETB,45X/                       &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,65HCOMMON /NAMETB/ CHARST,CHARND,INAMST,INAMND,NAMEST,NAMMAX,IF&
     &IXST, 9X/                                                         &
     &5X,29H/ IFIXND,NUMBST,NUMBND,NAMTBL,46X/                          &
     &6X,27HCOMMON/CNAMTB/CNAMTB,CNUMTB ,47X/                           &
     &6X,17HDIMENSION NAMTBL( ,I4,1H) ,52X/                             &
     &6X,19HCHARACTER*6 CNAMTB( ,I4,1H) ,50X/                           &
     &6X,20HCHARACTER*12 CNUMTB( ,I4,1H) ,49X)                          
      WRITE(NTFILE,500) CHARST,CHARND,INAMST,INAMND,NAMEST,NAMMAX,      &
     &             IFIXST,IFIXND,NUMBST,NUMBND,QNAMTB,QNAMTB,QNUMTB     
  500 FORMAT(6X,47HDATA CHARST,CHARND,INAMST,INAMND,NAMEST,NAMMAX/,27X/ &
     &       5X,1H1,5X,  I6,1H, I6,1H, I6,1H, I6,1H, I6,1H, I6,2H/,26X/ &
     &5X,1H2,5X,28HIFIXST,IFIXND,NUMBST,NUMBND/,41X/                    &
     &       5X,1H3,5X,  I6,1H, I6,1H, I6,1H, I6,1H/,41X/               &
     &       6X,12HDATA NAMTBL/,I5,3H*0/,54X/                           &
     &       6X,12HDATA CNAMTB/,I5,5H*' '/,52X/                         &
     &       6X,12HDATA CNUMTB/,I5,5H*' '/,52X)                         
      NAMTBL(IBKPNT)=0 
   23 DO 50 I=L,L1 
!                                                                       
!...     IS THIS CELL FILLED                                            
!                                                                       
      IF ((NAMTBL(I).EQ.0).OR.(NAMTBL(I).EQ.DIGIT(1).AND.I.GT.CHARND    &
     & )) GOTO 50                                                       
!                                                                       
!...     YES. OUTPUT TO LIST AND BLOCK DATA PROGRAM.                    
!                                                                       
!... CHECK FOR QUOTE                                                    
      IF (CNAMTB(I).EQ.'''') THEN 
        TEMP='''''' 
        WRITE(NTFILE,4)CNAMTB(I),I,I,NAMTBL(I),TEMP 
      ELSE 
        WRITE(NTFILE,4)CNAMTB(I),I,I,NAMTBL(I),CNAMTB(I) 
      ENDIF 
    4 FORMAT(28HC          NAMTBL ENTRY FOR ,A6,46X/                    &
     &6X,12HDATA NAMTBL(,I4,12H),   CNAMTB(,I4,1H),41X/                 &
     &5X,10H*        /,I5,10H   ,     ',A6,2H'/,42X)                    
   50 END DO 
!                                                                       
!...     HAVE WE REACHED NAMMAX YET                                     
!                                                                       
      IF (L1.LT.NAMMAX) GOTO 51 
!                                                                       
!...     YES. OUTPUT FIXED POINT AREA OF CNUMTB TO LIST AND B.D.PROGRAM 
!                                                                       
      WRITE(NTFILE,52) 
   52 FORMAT (42HC     CNUMTB ENTRIES FROM IFIXST TO IFIXND,38X) 
      DO 55 I=IFIXST,IFIXND 
      WRITE(NTFILE,54)I,CNUMTB(I) 
   54 FORMAT(6X,12HDATA CNUMTB(,I4,4H) /',A12,2H'/,40X) 
   55 END DO 
   51 CONTINUE 
!                                                                       
!...     END OF THIS PROGRAM. RETURN TO PRODUCE ANOTHER IF ALL OF       
!...     NAMTBL HAS NOT BEEN COVERED                                    
!                                                                       
    6 FORMAT (7X,3HEND,70X) 
      L=L1+1 
      IF(L.GT.NAMMAX)GO TO 60 
      L1=L+99 
      IF(L1.GT.NAMMAX)L1=NAMMAX 
      GO TO 23 
   60 CONTINUE 
      WRITE(NTFILE,6) 
!                                                                       
!...     IF THERE WAS NO ERROR IN THE GEOMETRIC PRODUCTION TABLES       
!...     CALL LOADS TO ASSIGN BIT PATTERNS AND PRODUCE INTERNAL         
!...     GEOMETRIC PRODUCTION TABLES                                    
!                                                                       
      CALL LOADS 
      QGEOMT=(IPROD+QGEOLO)/10*10 
      J=QGEOMT+QGEOLO+QPMIDT+QARGMX 
!                                                                       
!...     PRODUCE BLOCK DATA PROGRAMS TO SET UP GEOMETRY TABLES          
!                                                                       
      WRITE(GPFILE,3000) 
 3000 FORMAT(6X,17HBLOCK DATA BDGMTY,57X/1HC,79X/                       &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,16HCOMMON/GMTY/GMTY,58X)                                       
      WRITE(GPFILE,3001) J,QGEOMT,QGEOLO,QPMIDT,QARGMX 
 3001 FORMAT(6X,15HDIMENSION GMTY(I4, 9H),GEOMTB(,I4, 9H),GEOLOC(,I4,   &
     & 9H),PMIDTB(,I4,2H),,14X/5X,10H1  ARGMXY(,I4,1H),60X)             
      I=QGEOLO+1 
      II=QPMIDT+I 
      JJ=QARGMX+II 
      WRITE(GPFILE,3009)I,II,JJ 
 3009 FORMAT(6X,32HEQUIVALENCE (GEOLOC(1),GMTY(1)),,42X/                &
     &       5X,29H1            (PMIDTB(1),GMTY(I3,3H)),,40X/           &
     &       5X,29H2            (ARGMXY(1),GMTY(I3,3H)),,40X/           &
     &       5X,29H3            (GEOMTB(1),GMTY(I3,3H)) ,40X)           
      WRITE(GPFILE,3010)QIAGMX 
 3010 FORMAT(1HC,79X/6X,12HDATA ARGMXY/,I3,3H*0/,56X) 
!                                                                       
!...     ARGMXY CONTAINS NAMTBL POINTERS TO THE INTEGERS ASSOCIATED     
!...     WITH PERMANENT IDENTIFIERS                                     
!                                                                       
      DO 1 I=1,QIAGMX 
      IF (IAGMXY(I).EQ.0)GOTO 1 
      WRITE(GPFILE,3050)I,IAGMXY(I) 
    1 END DO 
 3050 FORMAT (6X,12HDATA ARGMXY(,I3,2H)/,I4,1H/,52X) 
!                                                                       
!...     PMIDTB CONTAINS THE INTERNAL REPRESENTATION OF IDENTIFIERS     
!...     AND GEOMETRICS. THE I.R. IS STORED IN THE CELL CORRESPONDING   
!...     TO THE MODE OF GEOMETRICS, THE MODE+25 OF IDENTIFIERS          
!...     USE ARRAY IAGMXY TO RECORD ENTRIES MADE IN PMIDTB.             
!                                                                       
      WRITE(GPFILE,3020)QPMIDT,ALLBTS(1) 
 3020 FORMAT(33HC                     /Z7FFFFFFF/,47X/                  &
     &       6X,12HDATA PMIDTB/,I3,1H*,I11,1H/,47X)                     
      DO 2 I=1,NUMEL 
      K=ASSOC(1,I) 
      L = MOD(NAMTBL(K),MODULO) 
      IF ((NAMTBL(K)-L).EQ.IDENT(1)) L=L+50 
      IF(L.GT.QPMIDT) CALL SPILL(3,'LOADG   ') 
    2 WRITE(GPFILE,3002)HEX(ELBIT(I)),L,ELBIT(I) 
 3002 FORMAT(25HC                     / Z,A8,1H/,46X/                   &
     &       6X,12HDATA PMIDTB(,I3,2H)/,I11,1H/,46X)                    
      DO 30 I=1,QGEOLO 
      WRITE(GPFILE,3062) I 
 3062 FORMAT (1HC,10X,12HSURFACE TYPE,I2,55X) 
!                                                                       
!...     GEOLOC CONTAINS FOR EACH SURFACE TYPE THE POSITION IN THE      
!...     GEOMTB TO START SEARCHING                                      
!                                                                       
   30 WRITE(GPFILE,3003)I,GEOMLC(I) 
 3003 FORMAT(6X,12HDATA GEOLOC(,I2,2H)/,I4,1H/,53X) 
!                                                                       
!                                                                       
!...     WRITE DATA STATEMENTS TO PRODUCE GEOMETRIC TABLE               
!                                                                       
      L1=0 
      DO 90 I=1,50 
      IF(GEOMLC(I).EQ.0)GOTO 90 
      L1=L1+1 
      GEOMLC(L1)=GEOMLC(I) 
   90 END DO 
      L1=L1+1 
      GEOMLC(L1)=QPRODN 
      CALL SORT(GEOMLC(1),1,L1,1,1) 
      JJ=0 
      L1=1 
      WRITE(GPFILE,3012) 
 3012 FORMAT(1HC,79X) 
!                                                                       
      DO 100 I=1,IPROD 
      JJ=JJ+1 
!                                                                       
!...     IF NEXT ITEM IS NEGATIVE IT IS THE TERMINATOR OF THIS          
!...     PRODUCTION. IS IT NEGATIVE                                     
!                                                                       
      IF(JJ.LT.GEOMLC(L1))GOTO 502 
      K=4*(JJ-1) 
      WRITE(GPFILE,3008)K,JJ,(Z9999+K) 
 3008 FORMAT(36HC                         /Z9999/ + ,I4,40X/            &
     &       6X,12HDATA GEOMTB(,I6,3H) /I11,1H/,42X)                    
      JJ=JJ+1 
      L1=L1+1 
      IF(JJ.LT.GEOMLC(L1))GOTO 502 
      JJ=JJ-1 
      GO TO 100 
  502 IF(PRODN(I).LT.0)GOTO 98 
!                                                                       
!...     NO. WRITE DATA STATEMENT ASSIGNING BIT PATTERN                 
   97 WRITE(GPFILE,3004)HEX(PRODN(I)),JJ,PRODN(I) 
 3004 FORMAT(29HC                         / Z,A8,1H/,42X/               &
     &       6X,12HDATA GEOMTB(,I6,3H) /I11,1H/,42X)                    
      GO TO 100 
!                                                                       
!...     THIS ITEM IS NEGATIVE, -(NO. OF PRODUCTION).                   
!...     FETCH BCD OF ITS MODULUS FROM THE NAMTBL AND WRITE             
!...     DATA STATEMENT FOR NEGATIVE INTEGER.                           
!                                                                       
   98 J=-PRODN(I) 
      CALL BCDBIN(CNAMTB(J),K,M) 
      IF(K.GE.10000)GOTO 99 
      WRITE(GPFILE,3005)K,JJ,(ZCCCC+K) 
 3005 FORMAT(36HC                         /ZCCCC/ + ,I4,40X/            &
     &       6X,12HDATA GEOMTB(,I6,3H) /I11,1H/,42X)                    
      GOTO 100 
   99 K=K-10000 
      WRITE(GPFILE,3006)K,JJ,(ZAAAA+K) 
 3006 FORMAT(36HC                         /ZAAAA/ + ,I4,40X/            &
     &       6X,12HDATA GEOMTB(,I6,3H) /I11,1H/,42X)                    
  100 END DO 
!                                                                       
!...     BLOCK DATA PROGRAM IS NOW WRITTEN.                             
!...     WRITE END CARD AND RETURN.                                     
!                                                                       
      WRITE(GPFILE,3007) 
 3007 FORMAT(7X,3HEND,70X) 
      RETURN 
      END                                           
