/* APT201.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* *** SOURCE FILE : M0002726.W02   *** */
/* moved this function to an external function to remove compile error */



/* .....FORTRAN INTEGER FUNCTION  ...APT211    8/68              HG,DE,PH */

/* .....MODIFIED FOR VAX 11 IMPLEMENTATION   02.06.82   E.MCLELLAN */

/* .....MODIFICATION TO PERMIT RESTART PROCEDURE USING */
/*     VAX CONDITION HANDLING FACILITIES */


/*      INTEGER FUNCTION APT211(ADRESS,HDRECT,IAEEE) */
/* C */
/*      IMPLICIT DOUBLE PRECISION (A-H),DOUBLE PRECISION(O-Z) */
/*      DIMENSION ADRESS(*) */
/* C */
/*      INCLUDE 'TOTAL.INC' */
/*      INCLUDE 'DSHAR4.INC' */
/*      INCLUDE 'FXCOR.INC' */
/*      INCLUDE 'HOLRTH.INC' */
/*      INCLUDE 'SV.INC' */
/*      INCLUDE 'ZNUMBR.INC' */
/*      INCLUDE 'LDEF.INC' */
/*      INCLUDE 'ISV.INC' */
/*      INCLUDE 'IFXCOR.INC' */
/*      INCLUDE 'KNUMBR.INC' */
/* C */
/* C...            SYSTEM I/O FILE NAMES */
/* C */
/*      INCLUDE 'SYMFIL.INC' */
/* C */
/*      CHARACTER*8 TEST,HNOCS */
/*      INTEGER BCDF,TDS(2) */
/*      LOGICAL FIRST */
/*      SAVE FIRST,HOLDPP,TDS */
/*      CHARACTER*8 HOLRTH(6) */
/*      EQUIVALENCE (HOLRTH(1),HLFT) */
/* C */
/*      INTEGER Z4E */
/*      PARAMETER (Z4E=1308622848) */
/*      INTEGER HOLDPP */
/*      DIMENSION HOLDPP(8) */
/* C */
/*      COMMON /HOLD/ JHLDFG,ITHCNT,ITABH(100) */
/*      COMMON /HSAVE/ SAVEH(50) */
/*      COMMON/SQNC/ LSEQNO */
/* C */
/* C++++ FLAG TO ALLOW A SECOND TRY WITHOUT CHECKING TA TO OVERCOME */
/* C++++ ERROR 20106 */
/*      INTEGER I20106 */
/* C */
/* C */
/*      LOGICAL KCS */
/* C */
/*      INCLUDE 'BLANKCOM.INC' */
/* C */
/*      DIMENSION MODTYP(3,6) */
/*      DIMENSION CSSAVE(10) */
/* C */
/*      DATA HOLDPP/0,0,Z4E,1,Z4E,1,Z4E,1/ */
/*      DATA HNOCS/'NOCS    '/ */
/*      DATA MODTYP/1,2,3,2,1,3,6*4,1,2,3,2,1,3/ */
/*      DATA ZLIT2/.0349D0/ */
/*      DATA FIRST/.TRUE./ */
/* C */
/*      IF (FIRST)THEN */
/*        HOLDPP(1) = BCDF('HOLD') */
/*        HOLDPP(2) = BCDF('PP  ') */
/*        TDS(1) = BCDF(HDS(1:4)) */
/*        TDS(2) = BCDF(HDS(5:8)) */
/*        FIRST=.FALSE. */
/*      ENDIF */
/* C */
/*      CALL HOLFRM(HDRECT,TEST,1,8,NWD) */
/*      IF (IAEEE .EQ. 1) GO TO 8010 */
/*      IF(IAERR.EQ.1) GO TO 1000 */
/*      IF(TEST.EQ.HNOCS) GO TO 8000 */
/*      IF(IGOTO+ICTDEF)1,1,3000 */
/*    1 DO 4001 I=1,6 */
/*      IF(TEST.EQ.HOLRTH(I)) GO TO 4002 */
/* 4001 CONTINUE */
/*      CALL AERR(20104,'APT211  ') */
/*      GO TO 1000 */
/* 4002 ISAV=I */
/*      IF(.NOT.JDS)GO TO 4000 */
/*      KSEQNO = LSEQNO */
/*      LSEQNO = JSEQNO */
/*      KCSCNT=ICSCNT */
/*      KCS=JCS */
/*      LSAV=ISFTYP(IDS) */
/*      ISFTYP(IDS)=MSAV */
/*      ICSCNT=0 */
/*      KIPL=IPL(ICS) */
/*      KLMFL=LIMFL(ICS) */
/*      KUNFL=IUNFL(ICS) */
/*      KFIDN=ISFIDN(ICS) */
/*      KSTYP=ISFTYP(ICS) */
/*      KTLON=ITLON(ICS) */
/*      SPAST=PAST(ICS) */
/*      KCAN=ICANON(ICS) */
/*      KFL4=IFL4(ICS) */
/*      KFAR=IFAR(ICS) */
/*      DO 1530 IIT = 1,10 */
/* 1530 CSSAVE(IIT) = CANON(IIT+20) */
/*      CALL APT200(TDS,ADRESS,Z1) */
/*      IF(IAERR.NE.0)GO TO 1000 */
/*      IF(MOTMOD.EQ.0)GO TO 4004 */
/*      ISFTYP(ICS)=MODTYP(MOTMOD,ISAV) */
/*      IF(ISFTYP(ICS).EQ.2) PAST(ICS)=-K1 */
/*      IS=IDS */
/*      GO TO 9200 */
/* 4000 MODFER=TEST */
/*      IGO=ISAV */
/*      MSAV=ISFTYP(IDS) */
/*      IS=IDS */
/*      CALL APT234(TDS,ADRESS) */
/*      IF(IAERR.NE.0)GO TO 1000 */
/*      IF(JCS)GO TO 9200 */
/*      JSEQNO = LSEQNO */
/*      JDS=.TRUE. */
/* C     INTEG.ON EXFILE DP. 1ST WD UNNORM POWER,2ND INTEG VALUE */
/*      NR=0 */
/*      CALL EWRITE(EXFILE,NR,HOLDPP,8,IR) */
/*      JHLDFG=1 */
/*      GO TO 9999 */
/* 4004 CALL AERR(20109,'APT211  ') */
/*      GO TO 1000 */
/* 9200 CALL APT235 */
/*      IF(IAERR)6000,6000,1000 */
/* 6000 CALL APT240 (NUMDIM) */
/*   14 ICL = K2 */
/*      NW = 0 */
/*   19 IF (CUTDAT(6).EQ.0.)GO TO 32 */
/*      NUMDIM = K1 */
/*      GO TO 32 */
/*   72 CALL APT236 */
/*      IF(IAERR.NE.0)GO TO 4006 */
/*      IF(JDS)GO TO 4005 */
/* 4006 CONTINUE */
/*      JHLDFG=0 */
/*      ITHCNT=1 */
/*      JCS=.FALSE. */
/*      JDS=.FALSE. */
/*      GO TO 9999 */
/* 4005 JCS=KCS */
/*      JHLDFG=0 */
/*      GO TO 9500 */
/* 9600 CONTINUE */
/*      NR=0 */
/*      HOLDPP(8)=K2 */
/*      CALL EWRITE(EXFILE,NR,HOLDPP,8,IR) */
/*      HOLDPP(8)=K1 */
/*      ISFTYP(IDS)=LSAV */
/*      LSEQNO = KSEQNO */
/*      IF(.NOT.JCS)GO TO 4000 */
/*      IPL(ICS)=KIPL */
/*      LIMFL(ICS)=KLMFL */
/*      ISFIDN(ICS)=KFIDN */
/*      ISFTYP(ICS)=KSTYP */
/*      ITLON(ICS)=KTLON */
/*      PAST(ICS)=SPAST */
/*      ICANON(ICS)=KCAN */
/*      IFL4(ICS)=KFL4 */
/*      IFAR(ICS)=KFAR */
/*      ICSCNT=KCSCNT */
/*      JDS=.FALSE. */
/*      DO 1531 IIT = 1,10 */
/* 1531 CANON(IIT+20) = CSSAVE(IIT) */
/*      GO TO 4000 */
/*   32 J6 = 0 */
/*      IS=IPS */
/* C  INITIALIZE VARIABLES FOR AMIND */
/*   33 IF (JENT(IS)) 301,302,301 */
/*  301 JTN(IS) = K0 */
/*      IOPSET(IS)=0 */
/*      JU1(IS)=0 */
/*      JIOPS(IS)=0 */
/*  302 JAP = K1 */
/*  201 CALL AMIND */
/*      IF(IAERR)1000,2000,1000 */
/* 2000 IF(IPL(IS))141,140,141 */
/*  141 IF(S(IS))142,39,143 */
/*  142 IF (S(IS)-TAU2(IS)+1.D-4) 36,39,39 */
/*  143 IF (S(IS)-TAU1(IS)-1.D-4) 39,39,36 */
/*  140 IF(RC(IS)*S(IS))34,39,35 */
/*   34 IF(DABS(S(IS))-Z9EM1*TAU(IS)-1.D-4) 39,39,36 */
/*   35 IF(DABS(S(IS))-EPS1(IS)-1.D-2) 39,39,36 */
/*   36 GO TO(505,508,504,204),JAP */
/*  505 IF (IPL(IS)) 506,202,506 */
/*  202 IF (ISFTYP(IS)-K3) 504,507,504 */
/*  504 RC(IS)=-RC(IS) */
/*      JAP = JAP + K1 */
/*      GO TO 201 */
/*  506 IF (TH(IS)) 510,510,204 */
/*  507 JAP = K4 */
/*  203 Z(IS)=-Z(IS) */
/*      GO TO 201 */
/*  510 IF (IAFL(IS)) 507,511,507 */
/*  511 JENT(IS)= -K1 */
/*      JAP = K4 */
/*      GO TO 201 */
/*  508 IF (TH(IS)) 509,204,204 */
/*  509 JAP = JAP + K1 */
/*      GO TO 203 */
/*  204 IF(J6)38,37,38 */
/* C  CUTTER NOT WITHIN TOLERANCE OF DRIVE SURFACE AT START OF CUT SEQUENCE */
/*   38 CALL AERR (20102,'APT211  ') */
/*      GO TO 1000 */
/* C  CUTTER NOT WITHIN TOLERANCE OF PART SURFACE AT START OF CUT SEQUENCE */
/*   37 CALL AERR (20103,'APT211  ') */
/*      GO TO 1000 */
/*   40 J6=K1 */
/*      IS=IDS */
/*      GO TO 33 */
/*   39 IF (JAP-K1) 480,481,480 */
/*  480 TPK(1,IS)=TP(1,IS) */
/*      TPK(2,IS)=TP(2,IS) */
/*      TPK(3,IS)=TP(3,IS) */
/*      SNK(1,IS)=SN(1,IS) */
/*      SNK(2,IS)=SN(2,IS) */
/*      SNK(3,IS)=SN(3,IS) */
/*      SK(1,IS) = S(IS) */
/*  481 IF(J6)41,40,41 */
/* C  DETERMINE GENERAL DIRECTION OF FIRST CUT VECTOR AND STORE IN FWD */
/*   41 DO 42 K=1,3 */
/*   42 FWD(K)=TE(K)-TEK(K) */
/* 2001 CALL VNORM(FWD,FWD) */
/* C  IGO =1 IF LFT, =2 IF RGT, =3 IF FWD, =4 IF BACK, =5 IF UP, =6 IF DOWN */
/* C  RELATIVE TO LAST COMMAND */
/*      IF(K4-IGO)43,45,45 */
/*   43 DO 44 K=1,3 */
/*   44 FWD(K)=TA(K) */
/*      GO TO 50 */
/*   45 CALL CROSS(FWD,TA,FWD) */
/*      CALL VNORM(FWD,FWD) */
/*      IF (VTEM.GT.Z1EM6)GO TO 48 */
/*   46 CALL CROSS(PMOVE,TA,FWD) */
/*      CALL VNORM(FWD,FWD) */
/*      IF(IER)47,48,47 */
/* C  FWD DIRECTION CANNOT BE DETERMINED */
/*   47 CALL AERR (20105,'APT211  ') */
/*      GO TO 1000 */
/*   48 IF(K3-IGO)49,49,50 */
/*   49 CALL CROSS(TA,FWD,FWD) */
/*      CALL VNORM(FWD,FWD) */
/*      IF(IER)147,50,147 */
/*  147 GO TO 47 */
/*   50 GO TO (52,54,54,52,54,52),IGO */
/*   52 DO 53 K=1,3 */
/*   53 FWD(K)=-FWD(K) */
/* C  CALCULATE TI VECTOR PERPENDICULAR TO BOTH PART AND DRIVE SURFACE */
/* C  NORMALS */
/*   54 CALL CROSS(SN(1,IPS),SN(1,IDS),TI) */
/*      CALL VNORM(TI,TI) */
/*      IF(IER)58,60,58 */
/*   58 DO 59 K=1,3 */
/*   59 TI(K)=FWD(K) */
/*      GO TO 67 */
/* C  TI VECTOR AND FWD VECTOR SHOULD NOT BE ORTHOGONAL. IF SO CALL AERR */
/*   60 TEM(1)= TI(1)*FWD(1) +TI(2)*FWD(2)+TI(3)*FWD(3) */
/*      IF(DABS(TEM(1)) - ZLIT2) 64,64,63 */
/*   64 IF (I20106.EQ.0) THEN */
/* C++++ HAVE SECOND TRY WITHOUT CHECKING TA TO AVOID ERROR 20106 */
/*        I20106=1 */
/*        CALL OUTMSG('*** WARNING: ERROR 20106 IN APT201 ***') */
/*        CALL OUTMSG('*** TRY WITHOUT CHECKING TA        ***') */
/*        DO 641 K=1,3 */
/*          FWD(K)=TE(K)-TEK(K) */
/*  641   CONTINUE */
/*        CALL VNORM(FWD,FWD) */
/*        GOTO 50 */
/*      ELSE */
/*        CALL AERR (20106,'APT211  ') */
/*        GO TO 1000 */
/*      ENDIF */
/*   63 IF(TEM(1)) 65,65,67 */
/*   65 DO 66 K=1,3 */
/*   66 TI(K)=-TI(K) */
/*   67 IF(NUMDIM)68,68,73 */
/* C  ICSCNT = NUMBER OF CHECK SURFACES. IF MORE THAN ONE CHECK SURFACE 3D */
/* C  ROUTES USED */
/* 68   CONTINUE */
/*  168 IF(I3DFLG-K1)130,73,130 */
/*  130 IF(ICSCNT-K2)69,73,73 */
/* C  IF THICKNESS OF PART, DRIVE, AND CHECK SURFACE NOT ZERO 3D ROUTES */
/* C  FOLLOWED */
/*   69 IF(TH(IPS))173,70,173 */
/*  173 GO TO 73 */
/*   70 IF(TH(IDS))174,71,174 */
/*  174 GO TO 73 */
/*   71 IF(TH(ICS))73,76,73 */
/*   73 CONTINUE */
/* C  ENTRY FOR 3D CALCULATIONS */
/*  732 CALL ARLM3 */
/*      APT211=TEMP(1)+0.5 */
/*  101 IF(IAERR)1000,72,1000 */
/*   76 IS=ICS */
/*      IF(ISFIDN(IDS)-K3)80,86,86 */
/*   80 IF(ISFIDN(ICS)-K3)82,81,81 */
/* C  LINE TO LINE CASE */
/*   82 JBR=K3 */
/*      GO TO 83 */
/* C  CIRCLE TO LINE OR CIRCLE TO CIRCLE CASE */
/*   86 JBR=K1 */
/* C  ENTRY FOR 2D CALCULATIONS */
/*   83 CALL ARLM2 */
/*      APT211=Z1 */
/*      GO TO 101 */
/* C  LINE TO CIRCLE CASE */
/*   81 JBR=K2 */
/*      GOTO83 */
/* 6001 IF(IGOTO)3001,3001,3002 */
/* 3001 CALL AERR (20107,'APT211  ') */
/*      GO TO 1000 */
/* 3002 CALL AERR (20108,'APT211  ') */
/* 1000 CONTINUE */
/* 6002 APT211=Z1 */
/*      GO TO 72 */
/* 3000 IF(ISRCH)6001,6001,6002 */
/* 9999 CONTINUE */
/*      RETURN */
/* 9500 JJ=0 */
/* 9510 JJ=JJ+1 */
/*      IF(JJ.EQ.ITHCNT) GO TO 9590 */
/*      KK=ITABH(JJ) */
/*      GO TO (9510,9510,9510,9504,9505,9506,9507,9508,9509, */
/*     C 9550,9511,9512,9513),KK */
/* 9504 CALL TOLERH */
/*      GO TO 9510 */
/* 9505 CALL CUTTEH */
/*      GO TO 9510 */
/* 9506 CALL CUTH */
/*      GO TO 9510 */
/* 9507 CALL DNTCUH */
/*      GO TO 9510 */
/* 9508 CALL INTOLH */
/*      GO TO 9510 */
/* 9509 CALL OUTTOH */
/*      GO TO 9510 */
/* 9550 CALL MAXDPH */
/*      GO TO 9510 */
/* 9511 CALL INDRVH */
/*      GO TO 9510 */
/* 9512 CALL INDRPH */
/*      GO TO 9510 */
/* 9513 CALL THICKH */
/*      GO TO 9510 */
/* 9590 ITHCNT=1 */
/*      IF(IAEEE.EQ.1) GO TO 8020 */
/*      GO TO 9600 */
/* 8000 KSEQNO = LSEQNO */
/*      LSEQNO = JSEQNO */
/*      CALL APT235 */
/*      IAEEE = 1 */
/*      CALL AERR(20110,'APT211  ') */
/* 8010 IAERR = 0 */
/*      GO TO 9500 */
/* 8020 IAERR = 1 */
/*      NR = 0 */
/*      HOLDPP(8) = K2 */
/*      CALL EWRITE(EXFILE,NR,HOLDPP,8,IR) */
/*      HOLDPP(8) = K1 */
/*      LSEQNO = KSEQNO */
/* C....   RETURN TO CALLER */
/*      GO TO 1000 */
/*      END */


/* .....FORTRAN INTEGER FUNCTION  ...APT201 */

/* .....NEW SUBROUTINE FOR VAX 11 IMPLEMENTATION   02.06.82   E.MCLELLAN */

/* .....MODIFICATION TO PERMIT RESTART PROCEDURE USING */
/*     VAX CONDITION HANDLING FACILITIES */


integer apt201_(doublereal *adress, doublereal *hdrect)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    extern /* Subroutine */ int libsrevert_(void);
    extern integer apt211_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int apt241_(void);
    static integer iaeee;




    /* Parameter adjustments */
    --adress;

    /* Function Body */
    iaeee = 0;
/* ...ESTABLISH CONDITION HANDLER FOR AERR ERROR */
L1:
    apt241_();
    ret_val = apt211_(&adress[1], hdrect, &iaeee);
    if (iaeee == 1) {
	goto L1;
    }
/* ...REVERT TO DEFAULT CONDITION HANDLER */
/*      CALL LIB$REVERT */
    libsrevert_();
    return ret_val;
} /* apt201_ */

