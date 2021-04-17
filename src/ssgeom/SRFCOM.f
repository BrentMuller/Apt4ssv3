**** SOURCE FILE : M0002769.W01   ***
*
      SUBROUTINE SRFCOM(ISPRNT,IRR)
      IMPLICIT DOUBLE PRECISION(A-H,O-Z)
C---     ISPRNT  IS INPUT AND CONTROLS PRINT VERIFICATION
C---     IRR IS OUTPUT AND IF NON ZERO INDICATES AN ERROR
C---     PURPOSE IS TO COMBINE A STRING OF SEPARATELY DEFINED SSURFS
C---     INTO A SINGLE NEW SSURF
C---     PART PROGRAM DATA ARRIVES IN BLANK COMMON(LOC 41 ON)
C---     IT IS FIRST TRANSFERRED TO LABELED COMMON.
C---     SURFACES ARE THEN LOADED ONE BY ONE INTO BLANK COMMON
C---     STRIPPED OF THEIR TOPOLOGY TABLES, AND CONSOLIDATED INTO
C---     A SINGLE SURFACE IN BLANK COMMON.  THEN A PROCESS OF
C---     COMPARING EACH PATCH TO EVERY OTHER PATCH IS INVOKED TO
C---     BUILD A NEW TOPOLOGY TABLE FOR THE CONSOLIDATED
C---     SURFACE IN LABELED COMMON.  PRINT VERIFICATION FOLLOWS
C---     IF THE PRINT FLAG HAS BEEN TURNED ON AND AS A FINAL
C---     STEP THIS TOPOLOGY DATA IS CONSOLIDATED WITH THE
C---     NEW SURFACE.
C
      INCLUDE 'DARRAY.INC'
C
      COMMON/MAXLDA/MAXLDA
      INCLUDE 'SSPAD.INC'
      COMMON/IBUGG/IBUG,IPCOLC,IPCOMC
C
      INCLUDE 'BLANKCOM.INC'
C
C     DUMMY ARRAY FOR BLANK-COMMON RESERVATION, MESH-TEST
      DIMENSION FDUMMY(2)
      DIMENSION SCH(4)
C
      CHARACTER*8 WEIGHT,ALIMIT
      CHARACTER*8 TEST
      LOGICAL CKDEF
C
      DIMENSION SPV(32),B(64),IFLAG(4),ITOP(6,4)
C
      DIMENSION U(4),V(4)
C
C---     INTEGER ARRAY KTOP USED FOR QUICK MANIPULATION OF TOPOLOGY DATA
      DIMENSION KTOP(2*ISCN)
      EQUIVALENCE (KTOP(1),SCAN(1))
C
      DIMENSION ICP(2),JCP(2)
C
      DIMENSION IBPT(4,2)
C
      DIMENSION ICURV(4,2)
C
      DIMENSION NP(2)
C
      DATA FDUMMY /2*0.D0/
      DATA WEIGHT,ALIMIT/'WEIGHT  ','LIMIT   '/
      DATA ZERO,ONE,SMAL/0.0D0,1.0D0,1.0D-14/
      DATA U/0.0D0,1.0D0,0.0D0,1.0D0/
      DATA V/0.0D0,0.0D0,1.0D0,1.0D0/
      DATA IBPT/1,1,2,3,2,3,4,4/
      DATA ICURV/3,6,6,3,6,3,3,6/
      DATA SMALP/1.0D-4/
      DATA SMALV/1.0D-5/
C
C---     TRANSFER PART PROGRAM INPUT
      NSIZE=SSCAN(5)
      DO 10 I=1,NSIZE
      SCAN(I)=SSCAN(I)
   10 CONTINUE
C---     NEXT AVAILABLE SLOT IN SCAN
      ISCAN=NSIZE
C---     NPAT IS TOTAL NUMBER OF PATCHES IN NEW SURFACE
C---     NTOT IS TOTAL SIZE OF ALL SURFACES
C---     NUMSUR IS TOTAL NUMBER OF INPUT SURFACES
      NPAT=0
      NTOT=0
      NUMSUR=0
C---     LOAD IN ALL SURFACES TO OBTAIN NPAT,NTOT,NUMSUR
      I=9
  100 CONTINUE
      CALL HOLFRM(SCAN(I+1),TEST,1,8,NWD)
      IF(TEST.NE.WEIGHT.AND.TEST.NE.ALIMIT) GO TO 110
      I=I+2
      GO TO 120
C
  110 CONTINUE
C****    INPUT SURFACE WAS NOT DEFINED OR INCORRECT INPUT
      IRR=01
      IF(CKDEF(SCAN(I))) GO TO 998
      MODE=2
      CALL APT094(MODE,SCAN(I),SSCAN)
      IRR=02
C****    INPUT SURFACE COULD NOT BE FETCHED FROM EXTERNAL STORAGE
      IF(MODE.NE.2) GO TO 998
C---     SURFACE HAS BEEN LOADED, EXTRACT NEEDED INFORMATION.
      NPAT=NPAT+SSCAN(4)
      NTOT=NTOT+SSCAN(8)
      NUMSUR=NUMSUR+1
  120 CONTINUE
      I=I+2
      IF(I.LT.NSIZE) GO TO 100
C
      IF(IBUG.NE.11) GO TO 130
      CALL BAD(1,0,'NPAT',NPAT)
      CALL BAD(1,0,'NTOT',NTOT)
      CALL BAD(-1,0,'NMSR',NUMSUR)
  130 CONTINUE
C****    ERROR IF THIS COMBINATION OF SURFACES IS TOO LARGE
      IRR=03
      IF(NTOT-NUMSUR*10.GT.MAXLDA) GO TO 998
C---      IF ONLY ONE SURFACE IS INPUT, THEN LEAVE IT UNALTERED
      IF(NUMSUR.EQ.1) GO TO 999
C
C---     NOW RE-READ ALL SURFACES AND CONSOLIDATE THEM INTO A
C---     A SINGLE SURFACE AFTER EACH SURFACE LOAD
C---     ALSO, STRIP OUT ALL TOPOLOGY TABLES, AS THEY WILL BE RESET.
C---     FIRST SET POINTER FOR SCANNING THRU PART PROGRAM INPUT
      I=9
C---     CURRENT AVAILABLE SLOT IN PATCH HEADER TABLE
      NHEAD=11
C---     SET CURRENT AVAILABLE SLOT IN VALUE TABLE
      NVAL=11+6*NPAT
C---     SET CURRENT AVAILABLE SLOT TO LOAD THE NEXT  SURFACE.
      NEXSUR=NVAL
C
  200 CONTINUE
      CALL HOLFRM(SCAN(I+1),TEST,1,8,NWD)
      IF(TEST.NE.WEIGHT.AND.TEST.NE.ALIMIT) GO TO 210
      I=I+2
      GO TO 299
C
  210 CONTINUE
C****    INPUT SURFACE NOT CORRECTLY DEFINED
      IRR=04
      IF(CKDEF(SCAN(I))) GO TO 998
      MODE=2
      CALL APT094(MODE,SCAN(I),SSCAN(NEXSUR))
C****    INPUT SURFACE COULD NOT BE FETCHED
      IRR=05
      IF(MODE.NE.2) GO TO 998
C---     NEXT  SURFACE IS NOW AVAILABLE.  CONSOLIDATE IT WITH
C---     THE CONSOLIDATED SURFACE.
C---     PATCH HEADER DATA MUST BE MODIFIED TO REFLECT NEW DISPLACEMENTS
C---      OF VALUE AND TOPOLOGY DATA.
C
C---     NUMBER OF PATCHES IN CURRENT INPUT SURFACE
      KPAT=SSCAN(NEXSUR+3)
C---     LENGTH OF VALUE TABLE FOR CURRENT INPUT SURFACE
      KVAL=SSCAN(NEXSUR+1)
C---     POINTER TO CURRENT PATCH HEADER DATA
      KLOC=NEXSUR+10
C---     COMPUTE NEW DISPLACEMENT FOR HEADER DATA
      DISP=NVAL-SSCAN(KLOC+4)
C---     RULE FOR DISPLACEMENT IS DIFFERENT FOR A GENCUR TYPE
      IF(SSCAN(KLOC).GT.9.0) DISP=NVAL-SSCAN(KLOC)
      IF(IBUG.NE.0) CALL BAD(-1,1,'DISP',DISP)
C
      DO 220 L=1,KPAT
      IF(SSCAN(KLOC).GT.9.0) GO TO 230
C---     CONVENTIONAL COONS BICUBIC PATCH
      SSCAN(KLOC+4)=SSCAN(KLOC+4)+DISP
      GO TO 240
C
  230 CONTINUE
C---     GENCUR TYPE PATCH
      DO 250 LL=1,4
      LK=KLOC+LL-1
      IF(SSCAN(LK).GT.SMAL) SSCAN(LK)=SSCAN(LK)+DISP
  250 CONTINUE
C
  240 CONTINUE
C---     NOW TRANSFER SIX HEADER LOCATIONS
      DO 260 LL=1,6
      SSCAN(NHEAD)=SSCAN(KLOC)
      NHEAD=NHEAD+1
      KLOC=KLOC+1
  260 CONTINUE
C---      ZERO OUT THE TOPOLOGY TABLE REFERENCE
      SSCAN(NHEAD-1)=ZERO
C
  220 CONTINUE
C
C---     NOW TRANSFER PATCH VALUE DATA IN ONE BLOCK
      KLOC=NEXSUR+9+6*KPAT
      DO 270 LL=1,KVAL
      SSCAN(NVAL)=SSCAN(KLOC+LL)
      NVAL=NVAL+1
  270 CONTINUE
C
  299 CONTINUE
      NEXSUR=NVAL
      I=I+2
      IF(I.LT.NSIZE) GO TO 200
C
C---     SURFACES HAVE ALL BEEN FETCHED AND HEADER AND VALUE DATA
C---     CONSOLIDATED INTO ONE SURFACE.
C
C---     NOW A PORTION OF THE SURFACE HEADER TABLE CAN BE FILLED
      DO 292 L=1,10
  292 SSCAN(L)=ZERO
C---     VALUE TABLE SIZE
      SSCAN(2)=NVAL-11-6*NPAT
C---     NUMBER OF PATCHES
      SSCAN(4)=NPAT
C---     TYPE OF SURFACE - NON-MESH
      SSCAN(5)=ONE
C---     SURFACE TYPE -- ASSEMBLAGE OF ALL TYPES
      SSCAN(6)=7.
C---     SIGN OF SURFACE NORMAL
      SSCAN(7)=ONE
C---     TOTAL SIZE - NOT YET KNOWN BUT SET TO CURRENT SIZE
      SSCAN(8)=NVAL-1
C
      IF(IBUG.NE.11) GO TO 291
      CALL BAD(-10,1,'SSHD',SSCAN)
      NK=NPAT*6
      CALL BAD(-NK,1,'PCHD',SSCAN(11))
      NK1=NVAL-11-NK
      NK=11+NK
      CALL BAD(-NK1,1,'VALD',SSCAN(NK))
  291 CONTINUE
C
C---     FETCH AND STORE ALL VECTORS FOR EACH PATCH CORNER
C---     BASE POINTER FOR THIS STORAGE IS IPT+1
      IPT=ISCAN-1
      ISCAN=IPT
      NLEN=NPAT*60
C****    THERE IS NOT ENOUGH BUFFER SPACE TO HOLD CORNER DATA
      IRR=06
      IF(NLEN+IPT.GT.NSCNMX) GO TO 998
C
C RESERV PRESENT NEW SURFACE
      MODE=5
      FDUMMY(2)=NVAL-1
      CALL APT094(MODE,FDUMMY,SSCAN)
C
      DO 300 ICUR=1,NPAT
C---     FETCH THE ICUR-TH PATCH
      CALL LODPCH(SSCAN,B,IFLAG,ITOP,ICUR,1)
C---     OBTAIN DATA FROM EACH CORNER
      DO 310 J=1,4
      CALL CNSURF(U(J),V(J),B,SPV,IFLAG,1)
      DO 320 K=1,3
C---     SAVE POINT,TANSPL,CRSSPL,TWIST,NORMAL
      SCAN(ISCAN+K)=SPV(K)
      SCAN(ISCAN+3+K)=SPV(K+4)
      SCAN(ISCAN+6+K)=SPV(K+8)
      SCAN(ISCAN+9+K)=SPV(K+16)
      SCAN(ISCAN+12+K)=SPV(K+28)
  320 CONTINUE
      ISCAN=ISCAN+15
  310 CONTINUE
C
  300 CONTINUE
C---     CORNER DATA HAS NOW BEEN LOADED
      IF(IBUG.NE.11) GO TO 340
      CALL BAD(-NLEN,1,'CORN',SCAN(IPT+1))
  340 CONTINUE
C
C---     PREPARE FOR SAVING TOPOLOGY CALCULATIONS
      KLIM=2*NSCNMX
      KSTART=(ISCAN+1)*2
      KNOW=KSTART+4
      DO 399 K=1,4
  399 KTOP(K+KSTART)=0
C---     FIND TOPOLOGICAL RELATIONS BY COMPARING ALL BOUNDARIES
C---     IBN OF THE  ICUR-TH PATCH TO ALL BOUNDARIES JBN OF THE
C---     PATCHES JCUR=ICUR+1,ICUR+2,... NPAT
C
      IF(NPAT.LE.1) GO TO 600
      NLIM1=NPAT-1
      DO 400 ICUR=1,NLIM1
C
      NLIM2=ICUR+1
C---     POINTER TO STORAGE OF CORNER DATA FOR PATCH ICUR.
      ICORN=(ICUR-1)*60+IPT
C---     DEVELOP DATA FOR EACH BOUNDARY OF THE ICUR TH PATCH.
      DO 410 IBN=1,4
C---      INSERT INDICES TO CORNERS OF IBN-TH BOUNDARY
      ICP(1)=IBPT(IBN,1)
      ICP(2)=IBPT(IBN,2)
      DO 420 JCUR=NLIM2,NPAT
      JCORN=(JCUR-1)*60+IPT
C---     COMPARE EACH BOUNDARY OF THIS PATCH TO OTHERS
      DO 430 JBN=1,4
      JCP(1)=IBPT(JBN,1)
      JCP(2)=IBPT(JBN,2)
C---     FIRST CHECK FOR IDENTICAL CORNER POINTS
      NP(1)=1
      NP(2)=2
C---      NOCOMP=0 IF A BOUNDARY MATCH EXISTS, 1 IF IT DOES NOT.
      NOCOMP=0
C
      K=1
  438 CONTINUE
      IF(K.GT.2) GO TO 443
C
      II=ICORN+(ICP(K)-1)*15
  439 CONTINUE
      KK=NP(K)
      JJ=JCORN+(JCP(KK)-1)*15
      W=ZERO
      DO 441 L=1,3
  441 W=W+DABS(SCAN(II+L)-SCAN(JJ+L))
      IF(W.LT.SMALP) GO TO 440
C---      MATCH FAILED, SWITCH POINTS AND RETRY
      IF(NP(1).EQ.1) GO TO 442
C---      MATCH FAILED BETWEEN POINTS BOTH WAYS - NO BOUNDARY MATCH
      NOCOMP=1
      GO TO 443
C
  442 CONTINUE
C---      SWITCH POINTS AND COMPARE AGAIN
      K=1
      NP(1)=2
      NP(2)=1
      GO TO 438
C
  440 CONTINUE
      K=K+1
      GO TO 438
C
  443 CONTINUE
C
C---      IF CORNER POINTS DO NOT MATCH, TERMINATE SEARCH BETWEEN
C---      THESE TWO BOUNDARIES, ASSUME NO RELATION.
      IF(NOCOMP.NE.0) GO TO 430
C
      IF(IBUG.NE.11) GO TO 446
      CALL BAD(1,0,'ICUR',ICUR)
      CALL BAD(1,0,'JCUR',JCUR)
      CALL BAD(1,0,'IBN ',IBN)
      CALL BAD(-1,0,'JBN ',JBN)
      CALL BAD(2,0,'NP  ',NP)
      CALL BAD(2,0,'ICP ',ICP)
      CALL BAD(-2,0,'JCP ',JCP)
  446 CONTINUE
      ACOMP=ONE
      IF(NP(1).NE.1) ACOMP=-ONE
C---     NEXT CHECK FOR IDENTICAL BOUNDARIES
      NOCOMP=0
      DO 450 K=1,2
      II=ICORN+(ICP(K)-1)*15+ICURV(IBN,1)
      KK=NP(K)
      JJ=JCORN+(JCP(KK)-1)*15+ICURV(JBN,1)
      DO 451 L=1,3
      W=SCAN(II+L)-ACOMP*SCAN(JJ+L)
      IF(DABS(W).GT.SMALV) NOCOMP=1
  451 CONTINUE
  450 CONTINUE
      IF(NOCOMP.NE.0) GO TO 430
C
C---     ALL CONDITIONS FOR A CONNECTION HAVE BEEN MET
C---     STORE THE RESULTS
      KTOP(KNOW)=ICUR
      KTOP(KNOW+1)=IBN
      KTOP(KNOW+2)=JCUR
      KTOP(KNOW+3)=JBN
      KNOW=KNOW+4
C****    NOT ENOUGH SPACE TO STORE TOPOLOGY RESULTS
      IRR=07
      IF(KNOW.GT.KLIM) GO TO 998
C
  430 CONTINUE
C
  420 CONTINUE
C
  410 CONTINUE
C
  400 CONTINUE
C
  600 CONTINUE
C
C---     TOPOLOGY RELATIONS HAVE ALL BEEN DETERMINED, NOW CONSOLIDATE
C---     THESE INTO THE SURFACE CANON FORM
      IF(IBUG.NE.11) GO TO 499
      IK=KSTART
  498 CONTINUE
      CALL BAD(-4,0,'TOPO',KTOP(IK))
      IK=IK+4
      IF(IK.LT.KNOW) GO TO 498
  499 CONTINUE
C---      SET END OF LIST OF TOPOLOGY TABLE POINTERS
      KEND=KNOW-4
C
C---      SAVE CURRENT NVAL FOR TOPOLOGY SIZE CALCULATION
      NVALSV=NVAL
C
      DO 500 ICUR=1,NPAT
C---      LCON IS NUMBER OF SIDES OF PATCH CONNECTED TO SURFACE
      LCON=0
C---     TOPOLOGY POINTER LOCATION IN CURRENT PATCH HEADER
      IHTOP=10+6*ICUR
      SSCAN(IHTOP)=NVAL
C---      SEARCH EACH BOUNDARY IPN OF THE ICUR-TH PATCH
      DO 510 IPN=1,4
      LCONSV=LCON
      SSCAN(NVAL)=ZERO
C---      SEARCH THROUGH THE ENTIRE TOPOLOGY TABLE FOR A MATCH
      DO 520 K=KSTART,KEND,4
      IF(KTOP(K).NE.ICUR.OR.KTOP(K+1).NE.IPN) GO TO 525
      SSCAN(NVAL)=-KTOP(K+2)
      LCON=LCON+1
      NVAL=NVAL+1
      GO TO 520
  525 CONTINUE
      IF(KTOP(K+2).NE.ICUR.OR.KTOP(K+3).NE.IPN) GO TO 520
      SSCAN(NVAL)=-KTOP(K)
      LCON=LCON+1
      NVAL=NVAL+1
  520 CONTINUE
      IF(LCONSV.EQ.LCON) NVAL=NVAL+1
      SSCAN(NVAL-1)=-SSCAN(NVAL-1)
  510 CONTINUE
C
      IF(LCON.GT.0) GO TO 501
      CALL CFORM(' WARNING. PATCH NOT CONNECTED TO SURFACE',
     X  DARRAY,1,40)
      CALL ICONV(ICUR,DARRAY,43,6)
      CALL CPRINT(DARRAY)
      IRR=-09
  501 CONTINUE
  500 CONTINUE
C
C---      UPDATE SURFACE SIZE AND SIZE OF TOPOLOGY TABLE
      SSCAN(8)=NVAL-1
      SSCAN(3)=NVAL-NVALSV
      GO TO 999
C
  999 CONTINUE
      IRR=0
C
C MESH TEST, 1. TOPOLOGY-POINTER
      N1TT=SSCAN(16)
C LOWER LEFT CORNER AT 1. PATCH ?
      IF(SSCAN(N1TT).NE.0.D0.OR.SSCAN(N1TT+1).NE.0.D0) GOTO 997
      IF(SSCAN(N1TT+2).EQ.0.D0.AND.
     *   SSCAN(N1TT+3).EQ.0.D0) GOTO 997
C SPLINE AND CROSS-SPLINE NUMBER
      NU=SSCAN(N1TT+3)
      IF(NU.EQ.0)NU=2
      NU1=NU-1
      NV1=SSCAN(4)/NU1
      NV=NV1+1
      SNU2=NU1-1
      ICH=1-NU1
C TEST LOOP
      DO 1000 I=1,NV1
      DO 1000 J=1,NU1
      SCH(1)=ICH
      SCH(2)=SCH(1)+SNU2
      SCH(3)=SCH(2)+2.D0
      SCH(4)=SCH(3)+SNU2
      ICH=ICH+1
      DO 1000 K=1,4
      IF(I.NE.1.AND.I.NE.NV1.AND.J.NE.1.AND.J.NE.NU1) GOTO 996
      IF(SSCAN(N1TT).EQ.0.D0) GOTO 1000
      GOTO 997
  996 IF(SSCAN(N1TT).NE.SCH(K)) GOTO 997
 1000 N1TT=N1TT+1
      SSCAN( 5)=2.D0
      SSCAN( 9)=NV
      SSCAN(10)=NU
C
      GO TO 997
C
  998 CONTINUE
      CALL BAD(-1,1,'ERR ',IRR)
C
  997 CONTINUE
      RETURN
      END