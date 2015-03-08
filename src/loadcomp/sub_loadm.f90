! Modified to .f90 from M0006714.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADM                                 
!                                                                       
! LINKAGE       CALL   LOADM                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          INTEGER FCT.  NAME                          MAIN             
!          SUBROUTINE    SPILL                                          
!                                                                       
      SUBROUTINE LOADM 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  CHARST:     BEGINNING OF BASIC CHARACTER SECTION OF NAMTBL           
!  CHARND:     END OF BASIC CHARACTER SECTION OF NAMTBL                 
!  NAMEST:     NAMTBL INDEX OF BEGIN OF THE PART PROGRAM NAME  SECTION  
!  NAMMAX:     NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION     
!  NAMTBL:     NAME TABLE OR DICTIONARY                                 
!                                                                       
!        3.    METALINGUISTIC VARIABLE CLASS CODES                      
!                                                                       
      COMMON/CODES/CODES 
!  CODES:      SPACE FOR ALL CLASS CODES                                
      DIMENSION CODES(150) 
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  BPFILE:     BLOCK DATA OUTPUT OF CODE TABLE AND BASIC PRODUCTIONS    
      EQUIVALENCE (BPFILE,SYMFIL(1)) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QCODE:      DIMENSION OF ARRAY CODE                                  
      EQUIVALENCE (QCODE,LDXSIZ(1)) 
!  QCLSWD:     DIMENSION OF ARRAY CLSWRD                                
      EQUIVALENCE (QCLSWD,LDXSIZ(14)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      INCLUDE 'LDSCOM.INC' 
!  ERROR:      FLAG SET IF ERROR IN PRODUCTION TABLE                    
!                                                                       
!       16.    RELATION OF ORDINAL NUMBERS TO NAMTBL INDEXES            
!                                                                       
      COMMON/CLSWRD/CLSWRD 
      DIMENSION CLSWRD(100) 
!                                                                       
!       18.    CONTROL FLAGS AND POINTERS FOR TRANSFORMATION            
!                                                                       
      COMMON/BRANCH/BRANCH 
      DIMENSION BRANCH(515) 
!  MAXCLS:     NUMBER OF DEFINITIONS IN A TRANSFORMATION SECTIION       
      EQUIVALENCE (MAXCLS,BRANCH(6)) 
!*                                                                      
! PURPOSE      TO READ THE META-LINQUISTIC CLASSES AND TO               
!              PRODUCE A BLOCK DATA PROGRAM FOR THEM.                   
      CHARACTER*6 I 
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              I                  C            META-NAME                
!              J                  I            CLASS                    
!              JJ                 I            CODE SUBSCRIPT           
!              JJJ                I            CODE SUBSCRIP (JJ+1)     
!              K                  I            NAMTBL POINTER           
!              L                  I            NAMTBL INDEX OF J        
!**                                                                     
!                                                                       
!...     WRITE HEADING FOR BLOCK DATA PROGRAM                           
!                                                                       
      WRITE(VLFILE,17) 
   17 FORMAT(1H1,5X,35HCODES TABLE LOADING OF META CLASSES/4X,5HENTRY,5X&
     &,4HCODE)                                                          
      WRITE(BPFILE,1) QCODE 
    1 FORMAT(6X,17HBLOCK DATA BDCODE,57X/                               &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,16HCOMMON/CODE/CODE,58X/                                       &
     &6X,15HDIMENSION CODE(I4, 1H),54X)                                 
!                                                                       
!...     INITIALIZE SUBSCRIPTS FOR BLOCK DATA                           
!                                                                       
      JJ = 1 
      JJJ = 2 
!                                                                       
!...     CLEAR NAMTBL                                                   
!                                                                       
      DO 7 K = NAMEST,NAMMAX 
    7 NAMTBL(K) = 0 
      II=0 
      DO 27 K=1,QCLSWD 
   27 CLSWRD(K)=0 
!                                                                       
!...     READ NEXT CARD - I = META-NAME                                 
!...                      J = ITS CLASS                                 
!                                                                       
    2 READ(LCDATA,3)I,J,IPRIOR 
    3 FORMAT(A6,7X,I6,5X,I3) 
!                                                                       
!...     LIST IT                                                        
!                                                                       
      WRITE(VLFILE,13)I,J,IPRIOR 
   13 FORMAT(1X,A6,7X,I6,5X,I3) 
!                                                                       
!...     THIS SET OF CARDS IS TERMINATED BY A NEGATIVE NUMBER IN        
!...     THE CLASS FIELD. IS J NEGATIVE                                 
!                                                                       
      IF (J.LT.0) GO TO 5 
!                                                                       
!...     NO. PUT META-NAME IN NAMTBL WITH CORRECT CLASS,                
!...     AND PUT CLASS INTO ARRAY CODE.                                 
!                                                                       
      K = NAME(I) 
      NAMTBL(K) = J 
      IF (JJ.GT.QCODE) CALL SPILL(1,'LOADM   ') 
   12 CODES(JJ) = J 
!                                                                       
!...     IS THERE A CHARACTER IN CHARACTER PART OF NAMTBL WITH THIS     
!...     CLASS. IF THERE IS, STORE THE INDEX OF THE FIRST SUCH          
!...     CHARACTER IN CODE, IF NOT STORE INDEX OF LAST ITEM IN THE      
!...     CHARACTER PORTION.                                             
!                                                                       
      DO 8 L=CHARST,CHARND 
      IF (NAMTBL(L).EQ.J) GOTO 9 
    8 END DO 
      L = CHARND 
    9 CODES(JJJ) = L 
!                                                                       
!...     OUTPUT NEXT LINE OF BLOCK DATA PROGRAM TOGETHER WITH COMMENT   
!                                                                       
      WRITE(BPFILE,4)I,JJ,JJJ,J,L 
    4 FORMAT(29HC   META LINGUISTIC CLASS    ,A6,45X/6X,10HDATA CODE(   &
     &,I3,7H),CODE(,I3,2H)/,I5,1H,I6,1H/,36X)                           
!                                                                       
      IF(IPRIOR.GE.QCLSWD)CALL SPILL(14,'LOADM   ') 
      IF(IPRIOR)20,10,22 
   22 IF(CLSWRD(IPRIOR).EQ.0)GOTO 23 
   20 WRITE(VLFILE,21) 
   21 FORMAT(1H ,74HERROR NO. 7025 IN SUBROUTINE LOADM.  INVALID OR MULT&
     &IPLE DEFINED PRIORITY.)                                           
      ERROR=.TRUE. 
      GOTO 10 
   23 CLSWRD(IPRIOR)=K 
      IF(L.GT.49.OR.L.EQ.2.OR.L.EQ.15.OR.L.EQ.36)GOTO 10 
      CLSWRD(IPRIOR)=L 
!                                                                       
!...     UPDATE CODE SUBSCRIPTS AND RETURN FOR NEXT CARD                
!                                                                       
   10 JJ = JJ+2 
      JJJ = JJJ+2 
      GO TO 2 
!                                                                       
!...     TERMINATING CARD READ. OUTPUT END CARD AND RETURN              
!                                                                       
    5 WRITE(BPFILE,6) 
    6 FORMAT (7X,3HEND,70X) 
      K=0 
      DO 25 L=1,QCLSWD 
      IF(CLSWRD(L).EQ.0)GOTO 25 
      K=K+1 
      CLSWRD(K)=CLSWRD(L) 
   25 END DO 
      MAXCLS=K+1 
      RETURN 
      END                                           
