! Modified to .f90 from M000727.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE SPILL                                 
!                                                                       
! LINKAGE       CALL   SPILL(INDEX,SUBNAM)                              
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          NONE                          TYPE          ENTRY            
!                                        SUBROUTINE    LOADB            
!                                        SUBROUTINE    LOADG            
!                                        SUBROUTINE    LOADI            
!                                        SUBROUTINE    LOADM            
!                                        SUBROUTINE    LOADP            
!                                        SUBROUTINE    LOADS            
!                                        SUBROUTINE    LOADT            
!                                        SUBROUTINE    LOADU            
!                                        SUBROUTINE    LOAD1            
!                                        SUBROUTINE    LOAD2            
!                                                                       
      SUBROUTINE SPILL(INDEX,SUBNAM) 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
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
!  QCODE       DIMENSION OF ARRAY CODE                                  
      EQUIVALENCE (QCODE,LDXSIZ(1)) 
!  QMETA       DIMENSION OF ARRAY META (OUTPUT)                         
      EQUIVALENCE (QMETA,LDXSIZ(2)) 
!  QPMIDT      DIMENSION OF ARRAY PMIDTB                                
      EQUIVALENCE (QPMIDT,LDXSIZ(3)) 
!  QASSOC      DIMENSION OF ARRAY ASSOC                                 
      EQUIVALENCE (QASSOC,LDXSIZ(4)) 
!  QGEOML      DIMENSION OF ARRAY GEOMLC                                
      EQUIVALENCE (QGEOML,LDXSIZ(5)) 
!  QLENGT      DIMENSION OF ARRAY LENGTH                                
      EQUIVALENCE (QLENGT,LDXSIZ(6)) 
!  QPRODN      DIMENSION OF ARRAY PRODN                                 
      EQUIVALENCE (QPRODN,LDXSIZ(7)) 
!  QPROCD      DIMENSION OF ARRAY PROCOD                                
      EQUIVALENCE (QPROCD,LDXSIZ(8)) 
!  QWORK       DIMENSION OF ARRAY WORK                                  
      EQUIVALENCE (QWORK,LDXSIZ(9)) 
!  QIAGMX      DIMENSION OF ARRAY IAGMXY                                
      EQUIVALENCE (QIAGMX,LDXSIZ(10)) 
!  QPROD2      DIMENSION OF ARRAY PROD2                                 
      EQUIVALENCE (QPROD2,LDXSIZ(11)) 
!  QSTACK      DIMENSION OF ARRAY STKLST                                
      EQUIVALENCE (QSTACK,LDXSIZ(12)) 
!  QLEVPO      DIMENSION OF ARRAY LEVPOS                                
      EQUIVALENCE (QLEVPO,LDXSIZ(13)) 
!  QCLSWD      DIMENSION OF ARRAY CLSWRD                                
      EQUIVALENCE (QCLSWD,LDXSIZ(14)) 
!*                                                                      
!     PURPOSE       TO PRINT DIAGNOSTICS CONCERNING ARRAY CAPACITY      
!                   OVERFLOW                                            
!...  ARGUMENTS     INDEX     POINTER TO THE LOCATION IN THE COMMON     
!...                          BLOCK LDXSIZ CONTAINING THE DIMENSION     
!...                          REPRESENTING THE CAPACITY OF THE          
!...                          OVERFLOWED ARRAY.                         
      CHARACTER*6 SUBNAM 
      CHARACTER*6 ARRAY(14),WHERE(14)*16 
!                                                                       
      DATA ARRAY(1)/'CODES'/,WHERE(1)/'COMMON/CODES/'/ 
      DATA ARRAY(2)/'META'/,WHERE(2)/'COMMON/SCRTBL/'/ 
      DATA ARRAY(3)/'PMIDTB'/,WHERE(3)/'COMMON/GMTY/'/ 
      DATA ARRAY(4)/'ASSOC'/,WHERE(4)/'COMMON/ASSOC/'/ 
      DATA ARRAY(5)/'GEOMLC'/,WHERE(5)/'COMMON/GEOMLC/'/ 
      DATA ARRAY(6)/'LENGTH'/,WHERE(6)/'COMMON/LENGTH/'/ 
      DATA ARRAY(7)/'PRODN'/,WHERE(7)/'COMMON/PRODN/'/ 
      DATA ARRAY(8)/'PROCOD'/,WHERE(8)/'COMMON/PROCOD/'/ 
      DATA ARRAY(9)/'WORK'/,WHERE(9)/'COMMON/LEVPOS/'/ 
      DATA ARRAY(10)/'IAGMXY'/,WHERE(10)/'SUBRTN. LOADG'/ 
      DATA ARRAY(11)/'PROD2'/,WHERE(11)/'COMMON/PRODN/'/ 
      DATA ARRAY(12)/'PRODR'/,WHERE(12)/'COMMON/STKLST/'/ 
      DATA ARRAY(13)/'LEVPOS'/,WHERE(13)/'COMMON/LEVPOS/'/ 
      DATA ARRAY(14)/'CLSWRD'/,WHERE(14)/'COMMON/CLSWRD/'/ 
!**                                                                     
      WRITE (VLFILE,1000) SUBNAM,ARRAY(INDEX),WHERE(INDEX),LDXSIZ(INDEX) 
 1000 FORMAT(1H ,30HERROR NO. 7036  IN SUBROUTINE ,A6,1H./1H ,          &
     &22HTHE CAPACITY OF ARRAY ,A6,4H IN ,A6,   9H, SET AT ,I4,         &
     & 54H HAS BEEN EXCEEDED. REVISE INPUT OR REDIMENSION ARRAY.)       
      STOP 
      END                                           
