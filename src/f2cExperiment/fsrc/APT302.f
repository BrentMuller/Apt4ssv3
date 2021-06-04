**** SOURCE FILE : M0011535.W02   ***
*
C
C......     FORTRAN SUBROUTINE APT302             1/71   R.N.
C  PURPOSE     TO WRITE OUT ON THE VERIFICATION LISTING THE DATA
C              BEING PLACED ON CLFILE AND TO OUTPUT ERROR MESSAGES
C              OR OTHER INFORMATION HELPFUL TO THE PART PROGRAMMER.
C  LINKAGE     CALL APT302
C  ARGUMENTS   NONE - APT302 WRITES ON THE VERIFICATION LISTING
C                     THE INFORMATION STORED IN RECORD.
C  SUBSIDIARIES  APT309,APT331,APT332,FCONV,ICONV,CFORM,CPRINT
C
        SUBROUTINE  APT302
      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION (O-Z)
C
C     CLPRINT PRINTS THE RECORDS RECEIVED FROM EXFILE
C
C     *****   COMMON-EQUIVALENCE BLOCK VARIABLES  *****
C
      COMMON /EDITOR/ EDITOR(1500)
C
      DIMENSION AREA1(1500),AREA2(1000),AREA3(250)
      EQUIVALENCE (EDITOR(1500),AREA1(1500),AREA2(1000),AREA3(250))
C
      DIMENSION RECORD(256),SRECRD(512),JRECRD(512)
      REAL   SRECRD
      EQUIVALENCE (AREA1(1),RECORD(1)),(AREA1(1),JRECRD(1)),
     C            (AREA1(1),SRECRD(1))
      EQUIVALENCE (JRECRD(6),NUMWDS)
      INTEGER BRANCH
      EQUIVALENCE (AREA2(39),BRANCH),(AREA2(94),NUMCLD)
      EQUIVALENCE (AREA2(469),MULTAX)
C
      INCLUDE 'DARRAY.INC'
C
      CHARACTER*8 RTAPNO,ATAPNO
      CHARACTER*12 TAPENO,HCIRC
      CHARACTER*6 CONTR,CUT,HFINI,GODLTA,START,TESTWD,RECTYP,BLANK,PARNT
      CHARACTER*2 JBLK,JSBK
      EQUIVALENCE (RTAPNO,TAPENO)
      LOGICAL GOFLG
C
      DATA GOFLG /.TRUE./
      DATA HCIRC/' = CIRCLE/  '/
      DATA CONTR/'CONT. '/
      DATA IXYZ/0/,KCONT/0/
      DATA CUT/'CUT   '/,BLANK/'      '/,HFINI/'FINI  '/
      DATA GODLTA/'GODLTA'/,START/'START '/,JBLK/'  '/,JSBK/'S '/
      DATA TAPENO/'0     /     '/,ATAPNO/'0     / '/
      DATA PARNT/'(    )'/
C
C.    TAPENO SEQUENCE NO.
C
      RTAPNO=ATAPNO
      I = JRECRD(4)
      I1=I/10000
      IF(I1.NE.0)CALL ICONV(I1,TAPENO,2,5)
      CALL ICONV (I-I1*10000,TAPENO,8,4)
      DARRAY(1:12) = TAPENO
      CALL HOLFRM(RECORD(1),RECTYP,1,6,NWD)
      CALL HOLFRM(RECORD(5),TESTWD,1,6,NWD)
C
C.    BRANCH
C
      IF(BRANCH.GE.22) GO TO 4000
      IF(BRANCH.EQ.2) GO TO 2000
      IF(BRANCH.EQ.6) GO TO 1000
      IF(BRANCH.EQ.3) GO TO 5000
      IF(BRANCH.EQ.5) GO TO 6000
      IF(BRANCH.LE.16) GO TO 4000
      IF(BRANCH.EQ.17) GO TO 7000
      IF(BRANCH.EQ.19) GO TO 1500
      IF(BRANCH.EQ.21) GO TO 3000
      GO TO 4000
C
C.    PRINT LIST
C
  100 CALL CPRINT(DARRAY)
  200 RETURN
C
C.    FINI
C
 1000 DARRAY(14:19) = HFINI
      GO TO 100
C
C.    ARLEM
C
 1500 DARRAY(14:19) = RECTYP
      GO TO 100
C
C
C.    CLDATA RECORDS
C
 2000 IF(JRECRD(8).GE.2) GO TO 2500
      IF (TESTWD.NE.GODLTA) GO TO 2020
      CALL CFORM('   $$',DARRAY,7,5)
      GOFLG=.FALSE.
 2020 DARRAY(14:19) = TESTWD
      IF(JRECRD(6) .EQ. 2) GO TO 100
      CALL CFORM('/',DARRAY,20,1)
      CALL HOLFRM(RECORD(7),DARRAY,22,8,NWD)
      CALL CFORM (PARNT,DARRAY,28,6)
      CALL ICONV(JRECRD(16),DARRAY,29,4)
      IF(JRECRD(6).LE.6) GO TO 100
      DARRAY(34:45) = HCIRC
      K = 44
      DO 2010 I=10,16
      CALL FCONV (RECORD(I),DARRAY,K,11,4)
 2010 K=K+11
      GO TO 100
C
 2500 IF(IXYZ.EQ.0) GO TO 2600
      CALL CFORM(' ',DARRAY,1,1)
 2510 IF(KCONT.EQ.0) GO TO 2550
      DARRAY(14:19) = CONTR
      CALL CPRINT (DARRAY)
 2550 IF(NUMCLD.GT.0.AND.GOFLG) GO TO 2800
      GOFLG=.TRUE.
      IF(MULTAX.NE.1) GO TO 2560
      NPLUS = NUMWDS
      NADD = 5
      INCR = 7
      GO TO 2570
 2560 NPLUS = NUMWDS+3
      NADD = 2
      INCR = 4
 2570 DO 2580 I=5,NPLUS,INCR
      K=I+NADD
      L=15
      DO 2574 J=I,K
      IF(DABS(RECORD(J)).LT.100.0) GO TO 2572
      CALL FCONV(RECORD(J),DARRAY,L,17,7)
      GO TO 2573
 2572 N=L+6
      CALL FCONV(RECORD(J),DARRAY,N,11,7)
 2573 L=L+17
 2574 CONTINUE
      CALL CPRINT(DARRAY)
 2580 CONTINUE
      L=6
 2590 KCONT = 1
      IF(JRECRD(2*NPLUS-L).EQ.3) KCONT = 0
      GO TO 200
C
C     FIRST TIME
 2600 CALL CFORM('X',DARRAY,24,1)
      CALL CFORM('Y',DARRAY,41,1)
      CALL CFORM('Z',DARRAY,58,1)
      IF(MULTAX.NE.1) GO TO 2650
      CALL CFORM('I',DARRAY,75,1)
      CALL CFORM('J',DARRAY,92,1)
      CALL CFORM('K',DARRAY,109,1)
 2650 CALL CPRINT (DARRAY)
      IXYZ = 1
      GO TO 2510
C
C     CLDAT EXTENDED OUTPUT
 2800 NPLUS=NUMWDS
      INCR=4*NUMCLD+1
      DO 2840 I=3,NPLUS,INCR
      M=6
      DO 2830 J=2,INCR,4
      M=M+3
      CALL HOLFRM(RECORD(I+J),DARRAY,M,8,NWD)
      M=M+5
      DO 2820 K=1,3
      L=I+J+K
      IF(DABS(RECORD(L)).LT.100.0) GO TO 2810
      CALL FCONV(RECORD(L),DARRAY,M,16,6)
      GO TO 2820
 2810 N=M+5
      CALL FCONV(RECORD(L),DARRAY,N,11,6)
 2820 M=M+16
      IF(M.LT.100)GOTO 2830
      CALL CPRINT(DARRAY)
      M=6
 2830 CONTINUE
      IF(M.NE.6)CALL CPRINT(DARRAY)
 2840 CONTINUE
      L=2*(NPLUS+4-INCR)
      GO TO 2590
C
C     CLDAT/START,INDEX  ; CLDAT/NOMORE,INDEX
 3000 NUMCLD=0
C.    IS EXTENDED CLDATA FORMAT GIVEN ?
      IF (TESTWD.EQ.START )NUMCLD=(NUMWDS-4)/2
      IF(TESTWD(5:6).EQ.JBLK.OR.TESTWD(5:6).EQ.JSBK)NUMCLD=NUMWDS/2
C.    POST PROCESSOR COMMAND
 4000 DARRAY(14:19) = RECTYP
      IF(JRECRD(6).EQ.2.AND.TESTWD.EQ.BLANK) GO TO 100
      CALL CFORM('/',DARRAY,20,1)
      J=4
      LSAVE=0
 4010 K=21
 4020 L = JRECRD(2*J)
      GO TO (4100,4200,4300,4400,4500),L
C
C.    FLOATING POINT DATA ITEM
C
 4100 IF(K.GT.109) GO TO 4600
      M=4
      IF (RECORD(J+1).GT.9999.9) M=1
      CALL FCONV (RECORD(J+1),DARRAY,K,10,M)
      K=K+10
      J=J+2
      GO TO 4700
C
C.    ALPHA NUMERIC DATA ITEM
 4200 IF(K.GT.111) GO TO 4600
      CALL HOLFRM (RECORD(J+1),DARRAY,K+1,6,NWD)
      K=K+8
      J=J+2
      GO TO 4700
C
C.    ALPHA NUMERIC DATA ITEM STRING
C
 4300 L=(JRECRD(2*J+2)-1)*8
      IF(JRECRD(2*J+2).LE.1) GO TO 4303
      IF(K+L.GT.119) GO TO 4600
      CALL HOLFRM (RECORD(J+3),DARRAY,K+1,L,NWD)
 4303 K=K+L+2
      J=J+JRECRD(2*J+2)+2
      IF(BRANCH.EQ.8.OR.BRANCH.EQ.12.OR.BRANCH.EQ.14.OR.
     C RECTYP.EQ.CUT)  DARRAY(20:20)=' '
      GO TO 4700
C
C.    GEOMETRIC DATA ITEM STRING
C
 4400 L = JRECRD(2*J+2)
 4404 IF(K+11*L.GT.119) GO TO 4650
 4405 J=J+2
      DO 4410 N=1,L
      CALL FCONV (RECORD(J),DARRAY,K,10,4)
      K=K+10
      J=J+1
      IF(N.EQ.L) GO TO 4700
      CALL CFORM (',',DARRAY,K,1)
 4410 K=K+1
      GO TO 4700
C
C.    ERROR
C
 4500 CALL APT336(30027,'APT302  ')
      GO TO 100
C
 4600 CALL CPRINT (DARRAY)
      GO TO 4010
 4650 IF(K.EQ.21) GO TO 4660
      CALL CPRINT (DARRAY)
      GO TO 4010
 4660 LSAVE = L - 9
      L = 9
      GO TO 4405
 4700 IF(J-3.GE.NUMWDS) GO TO 100
      CALL CFORM (',',DARRAY,K,1)
      K=K+1
      IF(LSAVE.GT.0) GO TO 4720
      GO TO 4020
 4720 CALL CPRINT(DARRAY)
      K=21
      L=LSAVE
      LSAVE=0
      J=J-2
      GO TO 4404
C.    AERR
C
 5000 CALL APT331
      GO TO 200
C
C.    DYNDMP
C
 6000 CALL APT332
      GO TO 200
C
C.    GERR
C
 7000 CALL APT309
      GO TO 200
      END
