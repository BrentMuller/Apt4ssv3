**** SOURCE FILE : M0000607.V02   ***
*
C
C
C.....  FORTRAN SUBROUTINE  APT330
C  PURPOSE     TO PRINT DYNDMP INFORMATION
C  LINKAGE     CALL APT330 (J,N(1),N(2),N(3),N(4))
C
C  ARGUMENTS   J     INDEX TO POINT SUBROUTINE NAME AND DYNDMP NUMBER.
C                    IF J IS -1, IT INDICATES CONTINUATION CALL.
C              N(K)  INDEX TO POINT PARAMETER NAME AND ITS VALUE.
C
      SUBROUTINE APT330 (J,N1,N2,N3,N4)
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z)
      COMMON /EDITOR/ EDITOR
      DIMENSION EDITOR(1500),ED(1500),IED(3000),AREA3(250)
      EQUIVALENCE (EDITOR(1500),AREA3(250))
      EQUIVALENCE (EDITOR(1),ED(1),IED(1))
      DIMENSION NN(4)
      CHARACTER*4 NMB(50)
      CHARACTER*8 NAME(131),SUBNAM(50),HDYND
C
      INCLUDE 'DARRAY.INC'
C
      DATA HDYND/'DYNDMP  '/
      DATA NAME(  2)/'NUMBER= '/
      DATA NAME(  4)/'DP=     '/
      DATA NAME(  5)/'DPI=    '/
      DATA NAME(  6)/'FLIPCK= '/
      DATA NAME(  7)/'IAMDCT= '/
      DATA NAME(  8)/'IAUTPS= '/
      DATA NAME(  9)/'INOPS=  '/
      DATA NAME( 10)/'IS=     '/
      DATA NAME( 11)/'IT=     '/
      DATA NAME( 12)/'IWS=    '/
      DATA NAME( 13)/'JCKR=   '/
      DATA NAME( 14)/'JCR=    '/
      DATA NAME( 15)/'JDR=    '/
      DATA NAME( 16)/'JPR=    '/
      DATA NAME( 17)/'JPXR=   '/
      DATA NAME( 18)/'NUMPT1= '/
      DATA NAME( 19)/'NUMSUR= '/
      DATA NAME( 20)/'VL=     '/
      DATA NAME( 21)/'TA(1)=  '/
      DATA NAME( 22)/'TA(2)=  '/
      DATA NAME( 23)/'TA(3)=  '/
      DATA NAME( 24)/'TAK(1)= '/
      DATA NAME( 25)/'TAK(2)= '/
      DATA NAME( 26)/'TAK(3)= '/
      DATA NAME( 27)/'TAL(1)= '/
      DATA NAME( 28)/'TAL(2)= '/
      DATA NAME( 29)/'TAL(3)= '/
      DATA NAME( 30)/'TE(1)=  '/
      DATA NAME( 31)/'TE(2)=  '/
      DATA NAME( 32)/'TE(3)=  '/
      DATA NAME( 33)/'TEK(1)= '/
      DATA NAME( 34)/'TEK(2)= '/
      DATA NAME( 35)/'TEK(3)= '/
      DATA NAME( 36)/'TEL(1)= '/
      DATA NAME( 37)/'TEL(2)= '/
      DATA NAME( 38)/'TEL(3)= '/
      DATA NAME( 39)/'TI(1)=  '/
      DATA NAME( 40)/'TI(2)=  '/
      DATA NAME( 41)/'TI(3)=  '/
      DATA NAME( 42)/'TIK(1)= '/
      DATA NAME( 43)/'TIK(2)= '/
      DATA NAME( 44)/'TIK(3)= '/
      DATA NAME( 45)/'CPLFL=  '/
      DATA NAME( 46)/'CPTST=  '/
      DATA NAME( 47)/'CSD=    '/
      DATA NAME( 48)/'IFAR=   '/
      DATA NAME( 49)/'INDIR=  '/
      DATA NAME( 50)/'IOPSET= '/
      DATA NAME( 51)/'ISFTYP= '/
      DATA NAME( 52)/'ISIGCR= '/
      DATA NAME( 53)/'ISVFL=  '/
      DATA NAME( 54)/'J23=    '/
      DATA NAME( 55)/'JENT=   '/
      DATA NAME( 56)/'JTN=    '/
      DATA NAME( 57)/'JU1=    '/
      DATA NAME( 58)/'PLND=   '/
      DATA NAME( 59)/'PLND1=  '/
      DATA NAME( 60)/'PLTST=  '/
      DATA NAME( 61)/'RC=     '/
      DATA NAME( 62)/'S=      '/
      DATA NAME( 63)/'STCK=   '/
      DATA NAME( 64)/'STCK1=  '/
      DATA NAME( 65)/'STCK2=  '/
      DATA NAME( 66)/'STCKN=  '/
      DATA NAME( 67)/'TAU1=   '/
      DATA NAME( 68)/'TAU2=   '/
      DATA NAME( 69)/'TH=     '/
      DATA NAME( 70)/'Z=      '/
      DATA NAME( 71)/'CC(1)=  '/
      DATA NAME( 72)/'CC(2)=  '/
      DATA NAME( 73)/'CC(3)=  '/
      DATA NAME( 74)/'PLNV(1)='/
      DATA NAME( 75)/'PLNV(2)='/
      DATA NAME( 76)/'PLNV(3)='/
      DATA NAME( 77)/'SN(1)=  '/
      DATA NAME( 78)/'SN(2)=  '/
      DATA NAME( 79)/'SN(3)=  '/
      DATA NAME( 80)/'SP(1)=  '/
      DATA NAME( 81)/'SP(2)=  '/
      DATA NAME( 82)/'SP(3)=  '/
      DATA NAME( 83)/'SPL(1)= '/
      DATA NAME( 84)/'SPL(2)= '/
      DATA NAME( 85)/'SPL(3)= '/
      DATA NAME( 86)/'TEE(1)= '/
      DATA NAME( 87)/'TEE(2)= '/
      DATA NAME( 88)/'TEE(3)= '/
      DATA NAME( 89)/'TN(1)=  '/
      DATA NAME( 90)/'TN(2)=  '/
      DATA NAME( 91)/'TN(3)=  '/
      DATA NAME( 92)/'TP(1)=  '/
      DATA NAME( 93)/'TP(2)=  '/
      DATA NAME( 94)/'TP(3)=  '/
      DATA NAME( 95)/'VNDIR(1)'/
      DATA NAME( 96)/'VNDIR(2)'/
      DATA NAME( 97)/'VNDIR(3)'/
      DATA NAME( 98)/'VT(1)=  '/
      DATA NAME( 99)/'VT(2)=  '/
      DATA NAME(100)/'VT(3)=  '/
      DATA NAME(101)/'ISGCRT= '/
      DATA NAME(102)/'RCT=    '/
      DATA NAME(103)/'ST=     '/
      DATA NAME(104)/'ZT=     '/
      DATA NAME(105)/'CCT(1)= '/
      DATA NAME(106)/'CCT(2)= '/
      DATA NAME(107)/'CCT(3)= '/
      DATA NAME(108)/'SNT(1)= '/
      DATA NAME(109)/'SNT(2)= '/
      DATA NAME(110)/'SNT(3)= '/
      DATA NAME(111)/'SPT(1)= '/
      DATA NAME(112)/'SPT(2)= '/
      DATA NAME(113)/'SPT(3)= '/
      DATA NAME(114)/'SPLT(1)='/
      DATA NAME(115)/'SPLT(2)='/
      DATA NAME(116)/'SPLT(3)='/
      DATA NAME(117)/'SPKIPS 1'/
      DATA NAME(118)/'SPKIPS 2'/
      DATA NAME(119)/'SPKIPS 3'/
      DATA NAME(120)/'TPKIPS 1'/
      DATA NAME(121)/'TPKIPS 2'/
      DATA NAME(122)/'TPKIPS 3'/
      DATA NAME(123)/'SPKIDS 1'/
      DATA NAME(124)/'SPKIDS 2'/
      DATA NAME(125)/'SPKIDS 3'/
      DATA NAME(126)/'TPKIDS 1'/
      DATA NAME(127)/'TPKIDS 2'/
      DATA NAME(128)/'TPKIDS 3'/
      DATA NAME(129)/'CMOVE(1)'/
      DATA NAME(130)/'CMOVE(2)'/
      DATA NAME(131)/'CMOVE(3)'/
      DATA  SUBNAM(1 )/'AJUNDD( '/ , NMB(1 ) /'101)'/
      DATA  SUBNAM(2 )/'AJUNDD( '/ , NMB(2 ) /'102)'/
      DATA  SUBNAM(3 )/'AMIND ( '/ , NMB(3 ) /'103)'/
      DATA  SUBNAM(4 )/'AMIND ( '/ , NMB(4 ) /'104)'/
      DATA  SUBNAM(5 )/'AMIND ( '/ , NMB(5 ) /'105)'/
      DATA  SUBNAM(6 )/'AMIND ( '/ , NMB(6 ) /'106)'/
      DATA  SUBNAM(7 )/'AMIND ( '/ , NMB(7 ) /'107)'/
      DATA  SUBNAM(11)/'ARLM3 ( '/ , NMB(11) /'201)'/
      DATA  SUBNAM(12)/'ARLM3 ( '/ , NMB(12) /'202)'/
      DATA  SUBNAM(13)/'ARLM3 ( '/ , NMB(13) /'203)'/
      DATA  SUBNAM(14)/'ARLM3 ( '/ , NMB(14) /'204)'/
      DATA  SUBNAM(15)/'ARLM3 ( '/ , NMB(15) /'205)'/
      DATA  SUBNAM(16)/'ARLM3 ( '/ , NMB(16) /'206)'/
      DATA  SUBNAM(17)/'ARLM3 ( '/ , NMB(17) /'207)'/
      DATA  SUBNAM(18)/'ARLM3 ( '/ , NMB(18) /'208)'/
      DATA  SUBNAM(19)/'ARLM3 ( '/ , NMB(19) /'209)'/
      DATA  SUBNAM(20)/'ARLM3 ( '/ , NMB(20) /'210)'/
      DATA  SUBNAM(21)/'ARLM3 ( '/ , NMB(21) /'211)'/
      DATA  SUBNAM(22)/'ARLM3 ( '/ , NMB(22) /'212)'/
      DATA  SUBNAM(23)/'ARLM3 ( '/ , NMB(23) /'213)'/
      DATA  SUBNAM(24)/'ARLM3 ( '/ , NMB(24) /'214)'/
      DATA  SUBNAM(25)/'ARLM3 ( '/ , NMB(25) /'215)'/
      DATA  SUBNAM(26)/'ARLM3 ( '/ , NMB(26) /'216)'/
      DATA  SUBNAM(27)/'ARLM3 ( '/ , NMB(27) /'217)'/
      DATA  SUBNAM(31)/'CENTR ( '/ , NMB(31) /'401)'/
      DATA  SUBNAM(32)/'CENTR ( '/ , NMB(32) /'402)'/
      DATA  SUBNAM(33)/'CENTR ( '/ , NMB(33) /'403)'/
      DATA  SUBNAM(34)/'CPLAN ( '/ , NMB(34) /'404)'/
      DATA  SUBNAM(41)/'GO    ( '/ , NMB(41) /'501)'/
      DATA  SUBNAM(42)/'GO    ( '/ , NMB(42) /'502)'/
      DATA  SUBNAM(43)/'GO    ( '/ , NMB(43) /'503)'/
      DATA  SUBNAM(44)/'GO    ( '/ , NMB(44) /'504)'/
      DATA  SUBNAM(45)/'GO    ( '/ , NMB(45) /'505)'/
      DATA  SUBNAM(50)/'BRKPNT( '/ , NMB(50) /'999)'/
      IF(J.EQ.-1) GO TO 10
      CALL CFORM(HDYND,DARRAY,1,7)
      CALL CFORM(SUBNAM(J),DARRAY,8,7)
      CALL CFORM(NMB(J),DARRAY,15,4)
      M=4
   10 L=21
      NN(1)=N1
      NN(2)=N2
      NN(3)=N3
      NN(4)=N4
      DO 100 I=1,4
      L=L+2
      K=NN(I)
      IF(K.EQ.0) GO TO 200
      II = IABS(K)
      CALL CFORM(NAME(II),DARRAY,L,8)
      L=L+8
      IF(K.LT.0) GO TO 50
      CALL FCONV(ED(M),DARRAY,L,13,6)
      L=L+13
      GO TO 100
   50 L=L+2
      KK=2*M-1
      CALL ICONV(IED(KK),DARRAY,L,8)
      L=L+11
  100 M=M+1
  200 CALL CPRINT (DARRAY)
      RETURN
      END
