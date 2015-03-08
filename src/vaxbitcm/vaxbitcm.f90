!*** SOURCE FILE : M0006723.W02   ***                                   
!                                                                       
!                                                                       
! PURPOSE      TO INITIALIZE THE LABELLED COMMON AREAS                  
!              MODULI , BITCOM AND SYMFIL.                              
!                                                                       
      BLOCK DATA BDBITC 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!          5.      CLASS CODE MODULI                                    
!                                                                       
      COMMON/MODULI/MODULO 
!                                                                       
!          4.    BIT COMBINATION TABLE                                  
!                                                                       
      COMMON/BITCOM/BIT 
      DIMENSION BIT(32) 
      DIMENSION LOBIT(16),HIBIT(16) 
      EQUIVALENCE (LOBIT(1),BIT(1)),(HIBIT(1),BIT(17)) 
!                                                                       
!          6.    SYMBOLIC FILE DEFINITIONS                              
!                                                                       
      COMMON/SYMFIL/ BPFILE,NTFILE,GPFILE,ELFILE,LCDATA,VLFILE 
!                                                                       
!     DATA STATEMENTS                                                   
!                                                                       
!                                                                       
!          5.      CLASS CODE MODULI                                    
!                                                                       
      DATA MODULO/1000/ 
!                                                                       
!          4.    BIT COMBINATION TABLE                                  
!                                                                       
      DATA LOBIT( 1),LOBIT( 2),LOBIT( 3),LOBIT( 4),                     &
     &     LOBIT( 5),LOBIT( 6),LOBIT( 7),LOBIT( 8),                     &
     &     LOBIT( 9),LOBIT(10),LOBIT(11),LOBIT(12),                     &
     &     LOBIT(13),LOBIT(14),LOBIT(15),LOBIT(16)                      &
     &  /-2147483648,1073741824,536870912,268435456,                    &
     &     134217728, 67108864, 33554432, 16777216,                     &
     &       8388608,  4194304,  2097152,  1048576,                     &
     &        524288,   262144,   131072,    65536/                     
!    4    /Z80000000,Z40000000,Z20000000,Z10000000,                     
!    5     Z 8000000,Z 4000000,Z 2000000,Z 1000000,                     
!    6     Z  800000,Z  400000,Z  200000,Z  100000,                     
!    7     Z   80000,Z   40000,Z   20000,Z   10000/                     
      DATA HIBIT( 1),HIBIT( 2),HIBIT( 3),HIBIT( 4),                     &
     &     HIBIT( 5),HIBIT( 6),HIBIT( 7),HIBIT( 8),                     &
     &     HIBIT( 9),HIBIT(10),HIBIT(11),HIBIT(12),                     &
     &     HIBIT(13),HIBIT(14),HIBIT(15),HIBIT(16)                      &
     &    /    32768,    16384,     8192,     4096,                     &
     &          2048,     1024,      512,      256,                     &
     &           128,       64,       32,       16,                     &
     &             8,        4,        2,        1/                     
!    4    /Z    8000,Z    4000,Z    2000,Z    1000,                     
!    5     Z     800,Z     400,Z     200,Z     100,                     
!    6     Z      80,Z      40,Z      20,Z      10,                     
!    7     Z       8,Z       4,Z       2,Z       1/                     
!                                                                       
!          6.    SYMBOLIC FILE DEFINITIONS                              
!                                                                       
      DATA           BPFILE,NTFILE,GPFILE,ELFILE,LCDATA,VLFILE/         &
     &                    1,     2,     3,     4,     5,     6/         
      END                                           
