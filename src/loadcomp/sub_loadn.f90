! Modified to .f90 from M0006715.F                                    
!********************************************************************                                                                        
!                                                                       
!              FORTRAN SUBROUTINE LOADN                                 
!                                                                       
! LINKAGE       CALL   LOADN                                            
!                                                                       
!          SUBSIDIARIES                  CALLED FROM                    
!          TYPE          ENTRY           TYPE          ENTRY            
!          INTEGER FCT.  NAME            SUBROUTINE    LOADG            
!                                                                       
      SUBROUTINE LOADN 
!                                                                       
      IMPLICIT INTEGER (A-Z) 
!                                                                       
!        1.    NAME TABLE AND TABLE LIMITS                              
!                                                                       
      INCLUDE 'NAMETB.INC' 
!  INAMST:     BEGIN GEOMETRIC DEFINITION ROUTINE NAME SECTION(NAMTBL)  
!  NAMMAX:     NAMTBL INDEX OF END OF THE PART PROGRAM NAME SECTION     
!  IFIXST:     INDEX OF BEGINNING OF FIXED POINT NUMBER SECTION,CNUMTB  
!  NAMBTL:     INTEGER CODE CORRESPONDING TO NAME TABLE ENTRY           
!  CNAMTB:     NAME TABLE OR DICTIONARY                                 
!  CNUMTB:     NUMBER TABLE                                             
!                                                                       
!        6.    SYMBOLIC FILE DEFINITIONS                                
!                                                                       
      COMMON/SYMFIL/SYMFIL 
      DIMENSION SYMFIL(6) 
!  NTFILE:     BLOCK DATA OUTPUT OF NAMTBL AND NAMTBL POINTERS          
      EQUIVALENCE (NTFILE,SYMFIL(2)) 
!  LCDATA:     INPUT FILE NUMBER OF PRODUCTION TABLES SEQUEN. MODE      
      EQUIVALENCE (LCDATA,SYMFIL(5)) 
!  VLFILE:     VERIFICATION LISTING FILE                                
      EQUIVALENCE (VLFILE,SYMFIL(6)) 
!                                                                       
!        7.    RESTRICTION DATA FOR CAPACITY CONTROL                    
!                                                                       
      COMMON/LDXSIZ/LDXSIZ 
      DIMENSION LDXSIZ(28) 
!  QAPTXX:     DIMENSION OF ARRAY APTXXX (OUTPUT)                       
      EQUIVALENCE (QAPTXX,LDXSIZ(20)) 
!  QAPTYY:     DIMENSION OF ARRAY APTYYY (OUTPUT)                       
      EQUIVALENCE (QAPTYY,LDXSIZ(21)) 
!  QSUBNA:     DIMENSION OF ARRAY SUBNAM                                
      EQUIVALENCE (QSUBNA,LDXSIZ(22)) 
!  QHOLER:     DIMENSION OF ARRAY HOLER                                 
      EQUIVALENCE (QHOLER,LDXSIZ(23)) 
!  QINMBR:     DIMENSION OF COMMON/NUMPTR/ DATA                         
      EQUIVALENCE (QINMBR,LDXSIZ(24)) 
!  QISUB:      DIMENSION OF COMMON/SUBLST/ DATA                         
      EQUIVALENCE (QISUB,LDXSIZ(25)) 
!  QIHOL:      DIMENSION OF COMMON/BCDPTR/ DATA                         
      EQUIVALENCE (QIHOL,LDXSIZ(26)) 
!                                                                       
!        8.    CONTROL FLAGS AND POINTERS                               
!                                                                       
      COMMON/LDSCOM/LDSCOM 
      DIMENSION LDSCOM(9) 
!  PRODI:      POINTER TO LAST ENTRY IN PRODN TABLE                     
      EQUIVALENCE (PRODI,LDSCOM(4)) 
!                                                                       
!       13.    SPACE FOR PRODUCTION LISTS                               
!                                                                       
      INCLUDE 'PRODN.INC' 
!  PRODA:      CONTAINS NAMTBL INDICES OF THOSE NAMES                   
!              TO BE PRE-LOADED INTO NAMTBL                             
!  IPRODB:     NAMTBL INDEXES ASSOCIATED WITH PRODB ENTRIES             
!  PRODB:      PRE-LOADED NAMES ALPHABETICALLY SORTED                   
!*                                                                      
! PURPOSE      TO READ ALL THOSE NAMES TO BE PRE-LOADED INTO            
!              NAMTBL, AND TO PRODUCE A BLOCK DATA PROGRAM              
!              FOR VARIOUS POINTERS TO NAMTBL.                          
!                                                                       
! LOCAL                                INITIAL                          
! VARIABLES    NAME   DIMENSION  TYPE  VALUE   DESCRIPTION              
!                                                                       
!              HOL         3      C*6  CONTAINS BCD NAMES FOR PUTTING   
!                                              IN BLOCK DATA            
!              HOLER       4      C*6          CONTAINS SPECIAL NAMES,  
!              IHOLER      4      I            CLASS CODES FOR NAMTBL   
!              I                  I            INDEX OF DO-LOOP         
!              II                 C*6          CONTAINS NAME            
!              I1                 I            SUBSCRIPT IN DO LOOP     
!              J                  I            CLASS/MODE               
!              K                  I            NAMTBL INDEX             
!              K1                 I            NAMTBL INDEX             
!              NAMSUB      5      I            CONTAINS BCD NAMES FOR   
!                                              B.D. ORG.                
!              NUMBRS      14     C*6          CONTAINS BCD NUMBERS FOR 
!                                              NAMTBL                   
!              SUBNAM     109     C*6          CONTAINS SUBROUTINE NAMES
!              ISUBNM     109     I            + ASSOC. CLASS CODES FOR 
!                                              NAMTBL                   
!              SUBPTR       113   I            TO SPECIFY ORDER OF ITEMS
!                                              IN B.D. FOR SUBLST       
!              TEMP               C*6          TEMPORARY STORAGE FOR    
!                                              NAME DURING SORTING      
!              ITEMP              I            TEMPORARY STORAGE FOR    
!                                              NAMTBL INDEX DURING SORT 
!                                                                       
      CHARACTER*6 SUBNAM(109),HOLER(4),NUMBRS(14),HOL(3),II,NAMSUB(5) 
      CHARACTER*6 TEMP 
      DIMENSION  ISUBNM(109),IHOLER(4),SUBPTR(113) 
      DATA SUBNAM(1)/'UNDEF '/,ISUBNM(1)/19100/,                        &
     &     SUBNAM(2)/'APT001'/,ISUBNM(2)/19101/,                        &
     &     SUBNAM(3)/'APT003'/,ISUBNM(3)/19102/,                        &
     &     SUBNAM(4)/'APT004'/,ISUBNM(4)/19103/,                        &
     &     SUBNAM(5)/'APT005'/,ISUBNM(5)/19104/,                        &
     &     SUBNAM(6)/'APT006'/,ISUBNM(6)/19105/,                        &
     &     SUBNAM(7)/'APT007'/,ISUBNM(7)/19106/,                        &
     &     SUBNAM(8)/'APT008'/,ISUBNM(8)/19107/,                        &
     &     SUBNAM(9)/'APT009'/,ISUBNM(9)/19108/                         
      DATA SUBNAM(10)/'APT010'/ISUBNM(10)/19109/,                       &
     &     SUBNAM(11)/'APT011'/,ISUBNM(11)/19110/,                      &
     &     SUBNAM(12)/'APT012'/,ISUBNM(12)/19111/,                      &
     &     SUBNAM(13)/'APT014'/,ISUBNM(13)/19112/,                      &
     &     SUBNAM(14)/'APT015'/,ISUBNM(14)/19113/,                      &
     &     SUBNAM(15)/'APT016'/,ISUBNM(15)/19114/,                      &
     &     SUBNAM(16)/'APT017'/,ISUBNM(16)/19115/,                      &
     &     SUBNAM(17)/'APT018'/,ISUBNM(17)/19116/,                      &
     &     SUBNAM(18)/'APT019'/,ISUBNM(18)/19117/,                      &
     &     SUBNAM(19)/'APT020'/,ISUBNM(19)/19118/                       
      DATA SUBNAM(20)/'APT021'/,ISUBNM(20)/19119/,                      &
     &     SUBNAM(21)/'APT022'/,ISUBNM(21)/19120/,                      &
     &     SUBNAM(22)/'APT023'/,ISUBNM(22)/19121/,                      &
     &     SUBNAM(23)/'APT024'/,ISUBNM(23)/19122/,                      &
     &     SUBNAM(24)/'APT025'/,ISUBNM(24)/19123/,                      &
     &     SUBNAM(25)/'APT026'/,ISUBNM(25)/19124/,                      &
     &     SUBNAM(26)/'APT027'/,ISUBNM(26)/19125/,                      &
     &     SUBNAM(27)/'APT028'/,ISUBNM(27)/19126/,                      &
     &     SUBNAM(28)/'APT029'/,ISUBNM(28)/19127/,                      &
     &     SUBNAM(29)/'APT030'/,ISUBNM(29)/19128/                       
      DATA SUBNAM(30)/'APT031'/,ISUBNM(30)/19129/,                      &
     &     SUBNAM(31)/'APT032'/,ISUBNM(31)/19130/,                      &
     &     SUBNAM(32)/'APT033'/,ISUBNM(32)/19131/,                      &
     &     SUBNAM(33)/'APT035'/,ISUBNM(33)/19132/,                      &
     &     SUBNAM(34)/'APT036'/,ISUBNM(34)/19133/,                      &
     &     SUBNAM(35)/'APT037'/,ISUBNM(35)/19134/,                      &
     &     SUBNAM(36)/'APT038'/,ISUBNM(36)/19135/,                      &
     &     SUBNAM(37)/'APT039'/,ISUBNM(37)/19136/,                      &
     &     SUBNAM(38)/'APT040'/,ISUBNM(38)/19137/,                      &
     &     SUBNAM(39)/'APT044'/,ISUBNM(39)/19138/                       
      DATA SUBNAM(40)/'APT045'/,ISUBNM(40)/19139/,                      &
     &     SUBNAM(41)/'APT046'/,ISUBNM(41)/19140/,                      &
     &     SUBNAM(42)/'APT047'/,ISUBNM(42)/19141/,                      &
     &     SUBNAM(43)/'APT048'/,ISUBNM(43)/19142/,                      &
     &     SUBNAM(44)/'APT049'/,ISUBNM(44)/19143/,                      &
     &     SUBNAM(45)/'APT050'/,ISUBNM(45)/19144/,                      &
     &     SUBNAM(46)/'APT051'/,ISUBNM(46)/19145/,                      &
     &     SUBNAM(47)/'APT052'/,ISUBNM(47)/19146/,                      &
     &     SUBNAM(48)/'APT053'/,ISUBNM(48)/19147/,                      &
     &     SUBNAM(49)/'APT054'/,ISUBNM(49)/19148/                       
      DATA SUBNAM(50)/'APT055'/,ISUBNM(50)/19149/,                      &
     &     SUBNAM(51)/'APT056'/,ISUBNM(51)/19150/,                      &
     &     SUBNAM(52)/'APT057'/,ISUBNM(52)/19151/,                      &
     &     SUBNAM(53)/'APT058'/,ISUBNM(53)/19152/,                      &
     &     SUBNAM(54)/'APT060'/,ISUBNM(54)/19153/,                      &
     &     SUBNAM(55)/'APT061'/,ISUBNM(55)/19154/,                      &
     &     SUBNAM(56)/'APT062'/,ISUBNM(56)/19155/,                      &
     &     SUBNAM(57)/'APT063'/,ISUBNM(57)/19156/,                      &
     &     SUBNAM(58)/'APT064'/,ISUBNM(58)/19157/,                      &
     &     SUBNAM(59)/'APT065'/,ISUBNM(59)/19158/                       
      DATA SUBNAM(60)/'APT066'/,ISUBNM(60)/19159/,                      &
     &     SUBNAM(61)/'APT067'/,ISUBNM(61)/19160/,                      &
     &     SUBNAM(62)/'APT068'/,ISUBNM(62)/19161/,                      &
     &     SUBNAM(63)/'APT073'/,ISUBNM(63)/19162/,                      &
     &     SUBNAM(64)/'APT075'/,ISUBNM(64)/19163/,                      &
     &     SUBNAM(65)/'APT077'/,ISUBNM(65)/19164/,                      &
     &     SUBNAM(66)/'APT078'/,ISUBNM(66)/19165/,                      &
     &     SUBNAM(67)/'APT079'/,ISUBNM(67)/19166/,                      &
     &     SUBNAM(68)/'APT081'/,ISUBNM(68)/19167/,                      &
     &     SUBNAM(69)/'APT083'/,ISUBNM(69)/19168/                       
      DATA SUBNAM(70)/'APT085'/,ISUBNM(70)/19169/,                      &
     &     SUBNAM(71)/'APT087'/,ISUBNM(71)/19170/,                      &
     &     SUBNAM(72)/'APT088'/,ISUBNM(72)/19171/,                      &
     &     SUBNAM(73)/'APT090'/,ISUBNM(73)/19172/,                      &
     &     SUBNAM(74)/'APT092'/,ISUBNM(74)/19173/,                      &
     &     SUBNAM(75)/'APT093'/,ISUBNM(75)/19174/,                      &
     &     SUBNAM(76)/'APT094'/,ISUBNM(76)/19175/,                      &
     &     SUBNAM(77)/'APT100'/,ISUBNM(77)/19176/,                      &
     &     SUBNAM(78)/'APT200'/,ISUBNM(78)/19177/,                      &
     &     SUBNAM(79)/'APT201'/,ISUBNM(79)/19178/                       
      DATA SUBNAM(80)/'APT298'/,ISUBNM(80)/19179/,                      &
     &     SUBNAM(81)/'APT299'/,ISUBNM(81)/19180/,                      &
     &     SUBNAM(82)/'APT041'/,ISUBNM(82)/19193/,                      &
     &     SUBNAM(83)/'APT043'/,ISUBNM(83)/19195/,                      &
     &     SUBNAM(84)/'APT295'/,ISUBNM(84)/19196/,                      &
     &     SUBNAM(85)/'APT042'/,ISUBNM(85)/19194/,                      &
     &     SUBNAM(86)/'APT069'/,ISUBNM(86)/19198/,                      &
     &     SUBNAM(87)/'APT070'/,ISUBNM(87)/19199/,                      &
     &     SUBNAM(88)/'APT071'/,ISUBNM(88)/19200/,                      &
     &     SUBNAM(89)/'APT072'/,ISUBNM(89)/19201/                       
      DATA SUBNAM(90)/'APT074'/,ISUBNM(90)/19203/,                      &
     &     SUBNAM(91)/'APT034'/,ISUBNM(91)/19204/,                      &
     &     SUBNAM(92)/'DEFEXT'/,ISUBNM(92)/19202/,                      &
     &     SUBNAM(93)/'APT101'/,ISUBNM(93)/19207/,                      &
     &     SUBNAM(94)/'NDTEST'/,ISUBNM(94)/19011/,                      &
     &     SUBNAM(95)/'COMP3D'/,ISUBNM(95)/19012/,                      &
     &     SUBNAM(96)/'TLON  '/,ISUBNM(96)/19003/,                      &
     &     SUBNAM(97)/'GOTOPN'/,ISUBNM(97)/19208/,                      &
     &     SUBNAM(98)/'APT105'/,ISUBNM(98)/19209/,                      &
     &     SUBNAM(99)/'APT106'/,ISUBNM(99)/19211/                       
      DATA SUBNAM(100)/'TRANSF'/,ISUBNM(100)/19212/,                    &
     &     SUBNAM(101)/'APT104'/,ISUBNM(101)/19213/,                    &
     &     SUBNAM(102)/'APT102'/,ISUBNM(102)/19214/,                    &
     &     SUBNAM(103)/'APT103'/,ISUBNM(103)/19215/                     &
     &    ,SUBNAM(104)/'APT107'/,ISUBNM(104)/19216/                     &
     &    ,SUBNAM(105)/'APT013'/,ISUBNM(105)/19217/                     &
     &    ,SUBNAM(106)/'APT108'/,ISUBNM(106)/19218/                     &
     &    ,SUBNAM(107)/'APT109'/,ISUBNM(107)/19219/                     &
     &    ,SUBNAM(108)/'APT110'/,ISUBNM(108)/19247/                     &
     &    ,SUBNAM(109)/'LOGIF '/,ISUBNM(109)/19248/                     
      DATA HOLER(1)/'.AC.  '/,IHOLER(1)/31000/,                         &
     &     HOLER(2)/'APTER'/,IHOLER(2)/31000/,                          &
     &     HOLER(3)/'$21T$1'/,IHOLER(3)/31000/,                         &
     &     HOLER(4)/'$$TAB'/,IHOLER(4)/31000/                           
      DATA NUMBRS                                                       &
     & /'0','1','2','3','4','5','6','7','8','9','0.','1.','10.',' '/    
!        1   2   3   4   5   6   7   8   9  10   11   12   13   14      
!                                                                       
      DATA HOL(1)/'FEDRAT'/,                                            &
     &     HOL(2)/'TO'/,                                                &
     &     HOL(3)/'DS'/                                                 
!                                                                       
      DATA SUBPTR( 1)/ 2/,SUBPTR( 2)/ 5/,SUBPTR( 3)/ 6/,SUBPTR( 4)/ 8/, &
     &     SUBPTR( 5)/11/,SUBPTR( 6)/10/,SUBPTR( 7)/12/,SUBPTR( 8)/16/, &
     &     SUBPTR( 9)/17/,SUBPTR(10)/19/,SUBPTR(11)/20/,SUBPTR(12)/43/, &
     &     SUBPTR(13)/23/,SUBPTR(14)/24/,SUBPTR(15)/25/,SUBPTR(16)/32/, &
     &     SUBPTR(17)/21/,SUBPTR(18)/22/,SUBPTR(19)/34/,SUBPTR(20)/35/, &
     &     SUBPTR(21)/32/,SUBPTR(22)/36/,SUBPTR(23)/37/,SUBPTR(24)/38/, &
     &     SUBPTR(25)/39/,SUBPTR(26)/40/,SUBPTR(27)/97/,SUBPTR(28)/42/, &
     &     SUBPTR(29)/44/,SUBPTR(30)/45/,SUBPTR(31)/46/,SUBPTR(32)/47/, &
     &     SUBPTR(33)/48/,SUBPTR(34)/49/,SUBPTR(35)/50/,SUBPTR(36)/51/, &
     &     SUBPTR(37)/52/,SUBPTR(38)/53/,SUBPTR(39)/55/,SUBPTR(40)/56/  
      DATA SUBPTR(41)/59/,SUBPTR(42)/60/,SUBPTR(43)/61/,SUBPTR(44)/-1/, &
     &     SUBPTR(45)/98/,SUBPTR(46)/ 4/,SUBPTR(47)/ 7/,SUBPTR(48)/ 9/, &
     &     SUBPTR(49)/ 1/,SUBPTR(50)/13/,SUBPTR(51)/14/,SUBPTR(52)/15/, &
     &     SUBPTR(53)/18/,SUBPTR(54)/26/,SUBPTR(55)/27/,SUBPTR(56)/28/, &
     &     SUBPTR(57)/29/,SUBPTR(58)/30/,SUBPTR(59)/31/,SUBPTR(60)/33/, &
     &     SUBPTR(61)/ 9/,SUBPTR(62)/41/,SUBPTR(63)/57/,SUBPTR(64)/58/, &
     &     SUBPTR(65)/ 3/,SUBPTR(66)/33/,SUBPTR(67)/71/,SUBPTR(68)/75/, &
     &     SUBPTR(69)/54/,SUBPTR(70)/11/,SUBPTR(71)/54/,SUBPTR(72)/70/, &
     &     SUBPTR(73)/76/,SUBPTR(74)/ 0/,SUBPTR(75)/81/,SUBPTR(76)/82/, &
     &     SUBPTR(77)/84/,SUBPTR(78)/85/,SUBPTR(79)/86/,SUBPTR(80)/87/  
      DATA SUBPTR(81)/88/,SUBPTR(82)/91/,SUBPTR(83)/89/,SUBPTR(84)/90/, &
     &     SUBPTR(85)/67/,SUBPTR(86)/68/,SUBPTR(87)/65/,SUBPTR(88)/64/, &
     &     SUBPTR(89)/66/,SUBPTR(90)/69/,SUBPTR(91)/77/,SUBPTR(92)/78/, &
     &     SUBPTR(93)/83/,SUBPTR(94)/79/,SUBPTR(95)/80/,SUBPTR(96)/92/, &
     &     SUBPTR(97)/93/,SUBPTR(98)/94/,SUBPTR(99)/95/,                &
     &     SUBPTR(100)/96/,SUBPTR(101)/72/,SUBPTR(102)/97/,             &
     &     SUBPTR(103)/98/,SUBPTR(104)/99/,SUBPTR(105)/100/,            &
     &     SUBPTR(106)/101/,SUBPTR(107)/102/,SUBPTR(108)/103/           &
     &    ,SUBPTR(109)/104/,SUBPTR(110)/105/,SUBPTR(111)/106/           &
     &    ,SUBPTR(112)/107/,SUBPTR(113)/108/                            
      DATA NAMSUB(1)/'ZSURF'/,                                          &
     &     NAMSUB(2)/'ERROR'/,                                          &
     &     NAMSUB(3)/'PSIS'/,                                           &
     &     NAMSUB(4)/'REFSYS'/,                                         &
     &     NAMSUB(5)/'TLAXIS'/                                          
!**                                                                     
      WRITE(VLFILE,110) 
  110 FORMAT (1H1,5X,32HEXTERNAL NAME TABLE LOADING DATA/4X,4HNAME,10X, &
     &5HCLASS,10X,4HNAME,7X,6HNAMTBL)                                   
!                                                                       
!...     CLEAR NAMTBL                                                   
!                                                                       
      DO 10 I=INAMST,NAMMAX 
   10 NAMTBL(I) = 0 
      L=0 
!                                                                       
!...     READ NEXT CARD,II = NAME, J = ITS CLASS AND MODE               
!                                                                       
   20 READ(LCDATA,30)II,J 
   30 FORMAT(A6,7X,I6) 
!                                                                       
!...     THIS SET OF CARDS IS TERMINATED BY A NEGATIVE NUMBER           
!...     IN THE CLASS FIELD. IS J NEGATIVE                              
!                                                                       
      IF (J.LT.0) GOTO 40 
!                                                                       
!...     NO. PUT NAME AND ITS CLASS IN NAMTBL,                          
!...     THEN RETURN FOR NEXT CARD.                                     
!                                                                       
      K=NAME(II) 
      NAMTBL(K) = J 
      L=L+1 
      PRODA(L)=K 
      IPRODB(L)=K 
      PRODB(L)=CNAMTB(K) 
      GOTO 20 
!                                                                       
!...     TERMINATING CARD READ. PUT SUBROUTINE NAMES AND CLASSES        
!...     INTO NAMTBL FROM INAMST UPWARDS.                               
!                                                                       
   40 PRODI=J 
      DO 50 I=1,QSUBNA 
      J = INAMST+I-1 
      NAMTBL(J) = ISUBNM(I) 
      CNAMTB(J)=SUBNAM(I) 
   50 END DO 
!                                                                       
!...  PUT .AC.,APTER,$21T$1,AND, ..TAB INTO NAMTBL IMMEDIATELY          
!...     ABOVE THE SUBROUTINE NAMES.                                    
!                                                                       
      DO 60 I=1,QHOLER 
      J = J+1 
      NAMTBL(J) = IHOLER(I) 
      CNAMTB(J)=HOLER(I) 
   60 END DO 
!                                                                       
!...     PUT 0-9,0.,1.,10. INTO NUMBER TABLE, CNUMTB, STARTING AT IFIXST
!                                                                       
      DO 70 I=1,13 
      J = IFIXST+I-1 
      CNUMTB(J)=NUMBRS(I) 
   70 END DO 
!                                                                       
!...     WRITE CARDS BEING SORTED TO LISTING                            
!                                                                       
!... SORT PRE-LOADED NAMES ALPHABETICALLY                               
      LM1=L-1 
      DO 71 I=1,LM1 
        IP1=I+1 
        IK=I 
        DO 72 J=IP1,L 
          IF (LGT(PRODB(IK),PRODB(J))) THEN 
            IK=J 
          ENDIF 
   72   CONTINUE 
        IF (IK.NE.I) THEN 
          TEMP=PRODB(IK) 
          ITEMP=IPRODB(IK) 
          PRODB(IK)=PRODB(I) 
          IPRODB(IK)=IPRODB(I) 
          PRODB(I)=TEMP 
          IPRODB(I)=ITEMP 
        ENDIF 
   71 END DO 
!                                                                       
      DO 75 I=1,L 
      J=PRODA(I) 
      K=IPRODB(I) 
   75 WRITE(VLFILE,120)CNAMTB(J),NAMTBL(J),                             &
     &                 CNAMTB(K),K                                      
  120 FORMAT(4X,A6,7X,I6,10X,A6,7X,I4) 
      WRITE(VLFILE,130)PRODI 
  130 FORMAT(17X,I6) 
!                                                                       
!...     NAMTBL IS NOW LOADED. GENERATE BLOCK DATA PROGRAMS CONTAINING  
!...     POINTERS TO SUBROUTINE NAMES, CONTENTS OF IFIXST-IFIXND, AND   
!...     CERTAIN SPECIAL NAMES THAT CAN BE USED IN I.L. WITHOUT         
!...     APPEARING EXPLICITLY IN THE PART PROGRAM.                      
!...     FIRST WRITE HEADING FOR BCDPTR BLOCK DATA PROGRAM.             
!                                                                       
      WRITE(NTFILE,1) QIHOL 
    1 FORMAT(6X,17HBLOCK DATA BDBCDP,57X/                               &
     &,35HC     BLOCK DATA PROGRAM FOR BCDPTR,45X/                      &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,20HCOMMON/BCDPTR/BCDPTR,54X/                                   &
     &6X,17HDIMENSION BCDPTR(I4,1H),52X/                                &
     &6X,48HEQUIVALENCE(DOTAC ,BCDPTR(1)),(FEDRAT,BCDPTR(2)),26X/       &
     &6X,48HEQUIVALENCE(TO    ,BCDPTR(3)),(DS    ,BCDPTR(4)),26X/       &
     &6X,48HEQUIVALENCE(ERASB ,BCDPTR(5)),(ITDOT1,BCDPTR(6)),26X/       &
     &6X,29HEQUIVALENCE(DOTTAB,BCDPTR(7)),45X)                          
      K=INAMST+QSUBNA 
      I = 1 
!                                                                       
!...     WRITE POINTER TO .AC.                                          
!                                                                       
      WRITE(NTFILE,2) HOLER(1),I,K 
    2 FORMAT (23HC   NAMTBL POINTER FOR , A6,51X/                       &
     &6X,12HDATA BCDPTR(,I1,2H)/,I4,1H/,54X)                            
!                                                                       
!...     WRITE POINTERS TO FEDRAT, TO, DS                               
!                                                                       
      DO 80 I=2,4 
      K1=NAME(HOL(I-1)) 
   80 WRITE(NTFILE,2) HOL(I-1),I,K1 
!                                                                       
!...     WRITE POINTERS TO APTER,$21T$1, $$TAB                          
!                                                                       
      DO 90 I=5,7 
      K = K+1 
   90 WRITE(NTFILE,2) HOLER(I-3),I,K 
!                                                                       
!...     TERMINATE BLOCK DATA PROGRAM                                   
      WRITE(NTFILE,9) 
!                                                                       
!...     WRITE BLOCK DATA PROGRAM FOR NUMPTR                            
!                                                                       
      WRITE(NTFILE,3) QINMBR 
    3 FORMAT (6X,17HBLOCK DATA BDNUMP,57X/                              &
     &35HC     BLOCK DATA PROGRAM FOR NUMPTR,45X/                       &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,20HCOMMON/NUMPTR/NUMPTR,54X/                                   &
     &6X,17HDIMENSION NUMPTR(,I4,1H),52X/                               &
     &6X,50HEQUIVALENCE(ZERO  ,NUMPTR( 1)),(ZEROPT,NUMPTR( 2)),24X/     &
     &6X,50HEQUIVALENCE(ONE   ,NUMPTR( 3)),(ONEPT ,NUMPTR( 4)),24X/     &
     &6X,50HEQUIVALENCE(TWO   ,NUMPTR( 5)),(THREE ,NUMPTR( 6)),24X/     &
     &6X,50HEQUIVALENCE(FOUR  ,NUMPTR( 7)),(FIVE  ,NUMPTR( 8)),24X/     &
     &6X,50HEQUIVALENCE(SIX   ,NUMPTR( 9)),(SEVEN ,NUMPTR(10)),24X/     &
     &6X,50HEQUIVALENCE(EIGHT ,NUMPTR(11)),(NINE  ,NUMPTR(12)),24X/     &
     &6X,50HEQUIVALENCE(TENPT ,NUMPTR(13))                    ,24X/     &
     &1HC,79X)                                                          
!                                                                       
!...     WRITE POINTERS TO 0, 0., 1, 1.                                 
!                                                                       
      DO 200 I=1,2 
      K = NAMMAX+IFIXST+I-1 
      J = 2*I - 1 
      WRITE(NTFILE,4) NUMBRS(I),J,K 
    4 FORMAT (23HC   NAMTBL POINTER FOR ,A3,54X/                        &
     &6X,12HDATA NUMPTR(,I2,2H)/,I4,1H/,53X)                            
      I1 = I+10 
      K = K+10 
      J = J+1 
  200 WRITE(NTFILE,4) NUMBRS(I1),J,K 
!                                                                       
!...     WRITE POINTERS TO 2-9                                          
!                                                                       
      DO 210 I=5,12 
      K = NAMMAX+IFIXST+I-3 
  210 WRITE(NTFILE,4) NUMBRS(I-2),I,K 
!                                                                       
!...     WRITE POINTER FOR 10.                                          
!                                                                       
      K=NAMMAX+IFIXST+12 
      I=13 
      WRITE(NTFILE,4) NUMBRS(I),I,K 
!                                                                       
!...     TERMINATE BLOCK DATA PROGRAM                                   
      WRITE(NTFILE,9) 
!                                                                       
!...     WRITE BLOCK DATA PROGRAM FOR SUBLST.                           
!...     IN THIS BLOCK SUBROUTINES ARE NOT LISTED IN NUMERICAL ORDER,   
!...     BUT IN THE ORDER DETERMINED BY APTXXX IN PRO026.               
!                                                                       
      QSBLST=QAPTXX+QAPTYY+QISUB+1 
      WRITE(NTFILE,5) QSBLST,QAPTXX,QAPTYY,QISUB 
    5 FORMAT(6X,17HBLOCK DATA BDSUBL,57X/                               &
     &35HC     BLOCK DATA PROGRAM FOR SUBLST,45X/                       &
     &6X,22HIMPLICIT INTEGER (A-Z),52X/                                 &
     &6X,20HCOMMON/SUBLST/SUBLST,54X/                                   &
     &6X,17HDIMENSION SUBLST(I4,9H),APTXXX(I4,9H),APTYYY(I4,7H),ISUB(I4,&
     &1H),15X/,1HC,79X/                                                 &
     &6X,34HEQUIVALENCE(SUBLST(  1),APTXXX(1)),40X/                     &
     &6X,34HEQUIVALENCE(SUBLST(121),APTYYY(1)),40X/                     &
     &6X,32HEQUIVALENCE(SUBLST(126),ISUB(1)),42X/                       &
     &6X,29HEQUIVALENCE (APT085,ISUB( 1)),45X/                          &
     &6X,29HEQUIVALENCE (APT200,ISUB( 2)),45X/                          &
     &6X,29HEQUIVALENCE (APT201,ISUB( 3)),45X/                          &
     &6X,29HEQUIVALENCE (APT298,ISUB( 5)),45X/                          &
     &6X,29HEQUIVALENCE (APT299,ISUB( 6)),45X/                          &
     &6X,29HEQUIVALENCE (ERROR ,ISUB( 7)),45X/                          &
     &6X,29HEQUIVALENCE (PSIS  ,ISUB( 8)),45X/                          &
     &6X,29HEQUIVALENCE (REFSYS,ISUB( 9)),45X/                          &
     &6X,29HEQUIVALENCE (TLAXIS,ISUB(10)),45X)                          
!                                                                       
!...     WRITE POINTERS TO SUBROUTINES IN APTXXX                        
!                                                                       
      DO 220 I=1,43 
      J = SUBPTR(I) 
      K = INAMST+J 
  220 WRITE(NTFILE,6)SUBNAM(J+1),I,K 
    6 FORMAT (23HC   NAMTBL POINTER FOR ,A6,51X/                        &
     &6X,12HDATA APTXXX(,I3,2H)/,I4,1H/,52X)                            
!                                                                       
!...     INSERT POINTER TO ZSURF AT THIS POINT                          
!                                                                       
      I = 44 
      K=NAME(NAMSUB(1)) 
      WRITE(NTFILE,6) NAMSUB(1),I,K 
!                                                                       
!...     WRITE POINTERS TO REMAINING SUBROUTINES IN APTXXX              
!                                                                       
      DO 225 I = 45,84 
      J = SUBPTR(I) 
      K = INAMST+J 
  225 WRITE(NTFILE,6) SUBNAM(J+1),I,K 
      DO 230 I=85,92 
      J=SUBPTR(I+20) 
      K=INAMST+J 
  230 WRITE(NTFILE,6) SUBNAM(J+1),I,K 
      DO 231 I=95,103 
      J=SUBPTR(I+1) 
      K = INAMST+J 
  231 WRITE(NTFILE,6) SUBNAM(J+1),I,K 
!                                                                       
!...     INSERT POINTER TO LOGIF AT THIS POINT                          
!                                                                       
      I = 104 
      J = SUBPTR(113) 
      K= INAMST+J 
      WRITE(NTFILE,6) SUBNAM(J+1),I,K 
!                                                                       
!...     WRITE POINTERS TO SUBROUTINES IN APTYYY                        
!                                                                       
      DO 240 I=1,QAPTYY 
      J=SUBPTR(I+84) 
      K = INAMST+J 
  240 WRITE(NTFILE,7) SUBNAM(J+1),I,K 
    7 FORMAT (23HC   NAMTBL POINTER FOR ,A6,51X/                        &
     &6X,12HDATA APTYYY(,I1,2H)/,I4,1H/,54X)                            
!                                                                       
!...     WRITE POINTERS TO APT085,APT200,APT201,APT295,APT298,APT299    
!                                                                       
      DO 250 I=1,6 
      J=SUBPTR(I+89) 
      K = INAMST+J 
  250 WRITE(NTFILE,8) SUBNAM(J+1),I,K 
    8 FORMAT (23HC   NAMTBL POINTER FOR ,A6,51X/                        &
     &6X,10HDATA ISUB(,I2,2H)/,I4,1H/,55X)                              
!                                                                       
!...     WRITE POINTERS TO ERROR,PSIS,REFSYS,TLAXIS                     
!                                                                       
      DO 260 I=7,QISUB 
      K=NAME(NAMSUB(I-5)) 
  260 WRITE(NTFILE,8) NAMSUB(I-5),I,K 
!                                                                       
!...     BLOCK DATA PROGRAM IS NOW COMPLETE.                            
!...     WRITE END CARD AND RETURN                                      
!                                                                       
      WRITE(NTFILE,9) 
    9 FORMAT (7X,3HEND,70X) 
      RETURN 
      END                                           
