! Modified to .f90 from M0007343.F                                    
!********************************************************************                                                                        
!                                                                       
! PURPOSE      TO INITIALIZE THE LABELLED COMMON AREA NAMETB, LDXCOM    
!                                                                       
      BLOCK DATA 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!...      0.SYSTEMS DEPENDENT PARAMETERS                                
!                                                                       
      INCLUDE 'SDP.INC' 
!                                                                       
!...       1.      NAME TABLE AND TABLE LIMITS                          
!                                                                       
      INCLUDE 'NAMETB.INC' 
      DIMENSION ALPHA(68) 
      CHARACTER*6 CALPHA(68) 
      EQUIVALENCE (ALPHA(1),NAMTBL(1)) 
      EQUIVALENCE (CALPHA(1),CNAMTB(1)) 
!                                                                       
!          2.    STACK AND POINTER STORAGE                              
!                                                                       
      COMMON/STKLST/STKLST 
      DIMENSION STKLST(3002) 
!                                                                       
!          3.    METALINGUISTIC VARIABLE CLASS CODES                    
!                                                                       
      COMMON/CODES/CODES 
      DIMENSION CODES(150) 
!                                                                       
!          7.    RESTRICTION DATA FOR CAPACITY CONTROL                  
!                                                                       
      COMMON/LDXSIZ/QCODE ,QMETA ,QPMIDT,QASSOC,QGEOML,QLENGT,QPRODN,   &
     &              QPROCD,QWORK ,QIAGMX,QPROD2,QSTACK,QLEVPO,QCLSWD,   &
     &              QARGMX,QKDENT,QGEOLO,QIPRMI,QKGRP ,QAPTXX,QAPTYY,   &
     &              QSUBNA,QHOLER,QINMBR,QISUB ,QIHOL ,QNAMTB,QNUMTB    
!                                                                       
!          8.    CONTROL FLAGS AND POINTERS                             
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!                                                                       
!          9.    ITEM AND GROUP CONTROL                                 
!                                                                       
      INCLUDE 'ASSOC.INC' 
!                                                                       
!         10.    ITEM AND GROUP CONTROL                                 
!                                                                       
      COMMON/LENGTH/LENGTH 
      DIMENSION LENGTH(3,100) 
!                                                                       
!         11.    GEOMETRIC TABLE LOCATIONS                              
!                                                                       
      COMMON/GEOMLC/GEOMLC 
      DIMENSION GEOMLC(50) 
!                                                                       
!         12.    BIT OUTPUT PATTERS                                     
!                                                                       
      COMMON/ELBIT/ELBIT 
      DIMENSION ELBIT(200) 
!                                                                       
!         13.    SPACE FOR PRODUCTION LISTS                             
!                                                                       
      INCLUDE 'PRODN.INC' 
!                                                                       
!         14.    LEVEL START OF THE PRODUCTIONS IN PRODR                
!                                                                       
      COMMON/LEVPOS/LEVPOS 
      DIMENSION LEVPOS(12,250) 
!                                                                       
!         15.    INTEGER CODE AND LEVPOS COLUMN OF A PRODUCTION         
!                                                                       
      COMMON/PROCOD/PROCOD 
      DIMENSION PROCOD(2,1500) 
!                                                                       
!         16.    RELATION OF ORDINAL NUMBERS TO NAMTBL INDEXES          
!                                                                       
      COMMON/CLSWRD/CLSWRD 
      DIMENSION CLSWRD(100) 
!                                                                       
!         17.    OUTPUT SPACE FOR TRANSFORMED PRODUCTION LIST           
!                                                                       
      COMMON/OUTARY/OUTARY 
      CHARACTER*80 OUTARY 
!                                                                       
!         18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION          
!                                                                       
      COMMON/BRANCH/BRANCH,LEVPRD 
      DIMENSION BRANCH(15),LEVPRD(2,250) 
!                                                                       
!         19.    BIT CONSTANTS                                          
!                                                                       
      INCLUDE 'ALLBTS.INC' 
!                                                                       
!     DATA STATEMENTS                                                   
!                                                                       
!                                                                       
!          0. SDP FOR A 32 BIT WORD COMPUTER                            
!                                                                       
!     NBYTE:  NO. OF BITS PER BYTE                                      
      DATA NBCHAR/8/ 
!     NBWRD:  NO. OF BITS PER WORD                                      
      DATA NBWRD/32/ 
!     IWRD:  NO. OF BYTES PER WORD                                      
      DATA IWRD/4/ 
!     IFAC: BYTE LEFT SHIFT MULTIPLICATION FACTOR                       
      DATA IFAC/256/ 
!                                                                       
!...       1.      NAME TABLE AND TABLE LIMITS                          
!                                                                       
      DATA   CHARST /  1/,  CHARND / 56/ ,                              &
     &       INAMST / 57/,  INAMND /169/,                               &
     &       NAMEST /170/,  NAMMAX /3000/,                              &
     &       IFIXST/ 1/,  IFIXND /13/,                                  &
     &       NUMBST/14/,  NUMBND /3000/                                 
      DATA ALPHA(1),CALPHA(1)/    0,' '/,                               &
     &     ALPHA(2),CALPHA(2)/10000,'0'/,                               &
     &     ALPHA(3),CALPHA(3)/10000,'1'/,                               &
     &     ALPHA(4),CALPHA(4)/10000,'2'/,                               &
     &     ALPHA(5),CALPHA(5)/10000,'3'/,                               &
     &     ALPHA(6),CALPHA(6)/10000,'4'/,                               &
     &     ALPHA(7),CALPHA(7)/10000,'5'/,                               &
     &     ALPHA(8),CALPHA(8)/10000,'6'/,                               &
     &     ALPHA(9),CALPHA(9)/10000,'7'/,                               &
     &     ALPHA(10),CALPHA(10)/10000,'8'/                              
      DATA ALPHA(11),CALPHA(11)/10000,'9'/,                             &
     &     ALPHA(12),CALPHA(12)/ 8000,'='/,                             &
     &     ALPHA(13),CALPHA(13)/12000,''''/,                            &
     &     ALPHA(14),CALPHA(14)/ 7000,'+'/,                             &
     &     ALPHA(15),CALPHA(15)/11000,'A'/,                             &
     &     ALPHA(16),CALPHA(16)/11000,'B'/,                             &
     &     ALPHA(17),CALPHA(17)/11000,'C'/,                             &
     &     ALPHA(18),CALPHA(18)/11000,'D'/,                             &
     &     ALPHA(19),CALPHA(19)/11000,'E'/,                             &
     &     ALPHA(20),CALPHA(20)/11000,'F'/                              
      DATA ALPHA(21),CALPHA(21)/11000,'G'/,                             &
     &     ALPHA(22),CALPHA(22)/11000,'H'/,                             &
     &     ALPHA(23),CALPHA(23)/11000,'I'/,                             &
     &     ALPHA(24),CALPHA(24)/21000,'.'/,                             &
     &     ALPHA(25),CALPHA(25)/ 3000,')'/,                             &
     &     ALPHA(26),CALPHA(26)/ 6000,'-'/,                             &
     &     ALPHA(27),CALPHA(27)/11000,'J'/,                             &
     &     ALPHA(28),CALPHA(28)/11000,'K'/,                             &
     &     ALPHA(29),CALPHA(29)/11000,'L'/,                             &
     &     ALPHA(30),CALPHA(30)/11000,'M'/                              
      DATA ALPHA(31),CALPHA(31)/11000,'N'/,                             &
     &     ALPHA(32),CALPHA(32)/11000,'O'/,                             &
     &     ALPHA(33),CALPHA(33)/11000,'P'/,                             &
     &     ALPHA(34),CALPHA(34)/11000,'Q'/,                             &
     &     ALPHA(35),CALPHA(35)/11000,'R'/,                             &
     &     ALPHA(36),CALPHA(36)/15000,'$'/,                             &
     &     ALPHA(37),CALPHA(37)/ 9000,'*'/,                             &
     &     ALPHA(38),CALPHA(38)/13000,' '/,                             &
     &     ALPHA(39),CALPHA(39)/ 5000,'/'/,                             &
     &     ALPHA(40),CALPHA(40)/11000,'S'/                              
      DATA ALPHA(41),CALPHA(41)/11000,'T'/,                             &
     &     ALPHA(42),CALPHA(42)/11000,'U'/,                             &
     &     ALPHA(43),CALPHA(43)/11000,'V'/,                             &
     &     ALPHA(44),CALPHA(44)/11000,'W'/,                             &
     &     ALPHA(45),CALPHA(45)/11000,'X'/,                             &
     &     ALPHA(46),CALPHA(46)/11000,'Y'/,                             &
     &     ALPHA(47),CALPHA(47)/11000,'Z'/,                             &
     &     ALPHA(48),CALPHA(48)/ 1000,','/,                             &
     &     ALPHA(49),CALPHA(49)/ 2000,'('/,                             &
     &     ALPHA(50),CALPHA(50)/24000,'LTERM'/                          
      DATA ALPHA(51),CALPHA(51)/ 4000,'RTERM'/,                         &
     &     ALPHA(52),CALPHA(52)/38000,'MCLTRM'/,                        &
     &     ALPHA(53),CALPHA(53)/32000,'DBLAST'/,                        &
     &     ALPHA(54),CALPHA(54)/25000,'DOT'/,                           &
     &     ALPHA(55),CALPHA(55)/26000,'KREUZ'/,                         &
     &     ALPHA(56),CALPHA(56)/45000,'CONAST'/                         
!                                                                       
!          7.    RESTRICTION DATA FOR CAPACITY CONTROL                  
!                                                                       
      DATA     QCODE / 150/, QMETA /  50/, QPMIDT/ 250/, QASSOC/ 200/ 
      DATA     QGEOML/  50/, QLENGT/ 100/, QPRODN/6000/, QPROCD/1500/ 
      DATA     QWORK / 100/, QIAGMX/ 250/, QPROD2/3000/, QSTACK/1500/ 
      DATA     QLEVPO/ 250/, QCLSWD/ 100/, QARGMX/ 250/, QKDENT/ 200/ 
      DATA     QGEOLO/  50/, QIPRMI/  35/, QKGRP / 100/, QAPTXX/ 120/ 
      DATA     QAPTYY/   5/, QSUBNA/ 109/, QHOLER/   4/, QINMBR/  13/ 
      DATA     QISUB /  10/, QIHOL /   7/, QNAMTB/3000/, QNUMTB/3000/ 
!                                                                       
!     NOTE - THE FOLLOWING SETS OF ARRAY SIZES SHOULD BE KEPT IDENTICAL 
!                                                                       
!          1) GEOLOC (QGEOLO) AND GEOMLC (QGEOML).                      
!          2) ELBIT (QELBIT) AND ASSOC (QASSOC).                        
!          3) LENGTH (QLENGT) AND KGRP (QKGRP).                         
!                                                                       
!         18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION          
!                                                                       
      DATA   BRANCH/1000000,10000,100,1,10*0,1/ 
!                                                                       
!         19.    BIT CONSTANTS                                          
!                                                                       
!     DATA   ALLBTS/Z7FFFFFFF,ZFFFFFFFF,Z9999,ZAAAA,ZCCCC/              
      DATA   ALLBTS/2147483647,-1/ 
      DATA   Z9999/-1718026240/ 
      DATA   ZAAAA/-1431699456/ 
      DATA   ZCCCC/-859045888/ 
!                                                                       
      END                                           
