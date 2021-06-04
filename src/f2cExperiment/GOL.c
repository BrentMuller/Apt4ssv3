/* GOL.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer id[24];
    doublereal obnam1;
    integer jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10], vta[3];
} plgol_;

#define plgol_1 plgol_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
} fxcor_;

#define fxcor_1 fxcor_

struct {
    char modfer[6];
} charct_;

#define charct_1 charct_

struct {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
} glflgs_;

#define glflgs_1 glflgs_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__34 = 34;
static integer c__4 = 4;
static integer c__36 = 36;
static integer c__15 = 15;
static integer c__6 = 6;
static integer c__14 = 14;
static integer c__5 = 5;
static integer c__8 = 8;
static integer c__44 = 44;
static integer c__46 = 46;
static integer c__3 = 3;
static integer c_n1 = -1;
static integer c__22223 = 22223;
static integer c__22222 = 22222;
static integer c__22220 = 22220;
static integer c__2 = 2;

/* *** SOURCE FILE : M0012234.V04   *** */

/* Subroutine */ int gol_(doublereal *adress)
{
    /* Initialized data */

    static char cmodf[8*7] = "PLOTKP  " "PLOTKF  " "PLOTFU  " "PLOTFV  " 
	    "PLOTGR  " "GOFLU   " "GOFLV   ";
    static logical first = TRUE_;
    static struct {
	doublereal e_1[4];
	} equiv_0 = { 2.003e7, 0., 0., 0. };

    static struct {
	integer e_1[18];
	doublereal e_2;
	} equiv_21 = { 0, 0, 1308622848, 0, 1308622848, 6, 1308622848, 1, 0, 
		0, 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0. };

    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_23 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 2, 0, 
		0, 0. };


    /* System generated locals */
    doublereal d__1;
    static doublereal equiv_22[7];

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, n, j11;
    static doublereal ua, va, ue;
#define vl ((doublereal *)&plgol_1 + 4)
#define nu ((integer *)&plgol_1 + 10)
#define nv ((integer *)&plgol_1 + 11)
    static doublereal uv[100]	/* was [4][25] */;
    static integer nr, ir;
    static doublereal ve;
    static integer ic1, ic2;
#define vt1 ((doublereal *)&equiv_0)
#define can ((doublereal *)&_BLNK__1 + 40)
#define iat ((integer *)&plgol_1 + 17)
#define uva ((doublereal *)&plgol_1 + 1)
#define tol ((doublereal *)&plgol_1 + 3)
#define uve ((doublereal *)&plgol_1 + 2)
    static doublereal spv[52], umx, anz;
    extern /* Subroutine */ int gop_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
    extern integer bcdf_(char *, ftnlen);
    static integer mode;
#define modf (equiv_22)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define incr ((integer *)&plgol_1 + 16)
    static integer nseg;
#define leit ((doublereal *)&equiv_21)
#define iart ((integer *)&plgol_1 + 12)
#define cosl ((doublereal *)&tlldat_1 + 16)
    static integer ianz, iret;
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal toli;
#define vtax ((doublereal *)&equiv_0 + 1)
    static doublereal vmax;
    static integer lseg, incr1;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
#define canon ((doublereal *)&_BLNK__1)
#define imodf ((integer *)equiv_22)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define ileit ((integer *)&equiv_21)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define ipenu ((integer *)&equiv_23)
#define penup ((doublereal *)&equiv_23)
#define ithru ((integer *)&plgol_1 + 19)
    extern /* Subroutine */ int iconv_(integer *, char *, integer *, integer *
	    , ftnlen), fconv_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static integer isize, nnseg;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
#define istrt ((integer *)&plgol_1 + 18)
    static integer inver1, ldaflg;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define obname ((doublereal *)&equiv_21 + 6)
#define normal ((integer *)&plgol_1 + 15)
#define invers ((integer *)&plgol_1 + 13)
#define mirror ((integer *)&plgol_1 + 14)
    extern /* Subroutine */ int cprint_(char *, ftnlen);
#define uvcons ((doublereal *)&plgol_1)
    extern /* Subroutine */ int record_(integer *), unpack_(doublereal *, 
	    integer *, integer *, integer *);
    static integer isbsct;
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static doublereal regfls;
    extern /* Subroutine */ int transm_(doublereal *, doublereal *, integer *,
	     integer *, integer *), golpln_(integer *, integer *), ewrite_(
	    integer *, integer *, doublereal *, integer *, integer *);
    static doublereal uhilfs, udummy;
    extern /* Subroutine */ int gochor_(integer *, doublereal *, doublereal *,
	     integer *, integer *);
    static doublereal deltuv;
    extern /* Subroutine */ int numver_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    , goretr_(integer *, doublereal *, doublereal *, doublereal *, 
	    integer *, integer *);


/*  MAIN DISPATCHING ROUTINE FOR GOLOFT/PLOTFT */


/*  CANONICAL FORM OF SS GEOMETRY */

/*  HELP ARRAY FOR VECTOR TRANSFORMATION */

/*   STORAGE FOR REGION SEGMENTS */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/*  GOLOFT COMMON */

/*  VECTOR-COMPONENTS OF THE TOOL-AXIS-VECTOR */


/* UVCONS:    U-, V- CONSTANTS, GIVEN BY "UCONST,U" OR "VCONST,V" */

/* UVA:       STARTPARAMETER GIVEN BY "START,S" */

/* UVE:       ENDPARAMETER GIVEN BY "THRU,T" */

/* TOL:       INCREMENTS BY "INCR,I", ERROR OF CHORD BY "CHORD,C" */

/* VL:        LENGTH-PARAMETER GIVEN BY "LENGTH,L" */

/* NU:        AMOUNT OF INTERMEDIATE LINES IN DIRECTION    UCONST */

/* NV:        AMOUNT OF INTERMEDIATE LINES IN DIRECTION    VCONST */

/* IART:      IART = 1   PLOTFT/SCURV,.........,PARAM,.... */
/*            IART = 2   PLOTFT/SCURV,.........,FLOW ,.... */
/*            IART = 3   PLOTFT/SSURF,UCONST,U,........... */
/*            IART = 4   PLOTFT/SSURF,VCONST,V,........... */
/*            IART = 5   PLOTFT/SSURF,GRID,............... */
/*            IART = 6   GOLOFT/SSURF,UCONST,U,........... */
/*            IART = 7   GOLOFT/SSURF,VCONST,V,........... */

/* INVERS:    INVERSION OF THE POINT-SEQUENCE */

/* MIRROR:    INVERSION OF THE MANUFACTURED SIDE  (DIRECTION OF NORMAL) */

/* NORMAL:   =1, IF  TLAXIS/NORMPS GIVEN; SURFACE-NORMAL = AXIS-DIRECTION */

/* INCR:     =1 IF "INCR,I", =0 IF "CHORD,C" GIVEN */

/* IAT:       IAT   = 0 AT NOT PROGRAMMED */
/*            IAT   = 1 AT   "AT,A",        = 2 AT   "AT,TO,PL1" */
/*            IAT   = 3 AT   "AT,ON,PL1,    = 4 AT   "AT,PAST,PL1 */

/* ISTRT:     ISTRT = 0 START NOT PROGRAMMED */
/*            ISTRT = 1 AT   "START,A",     = 2 AT   "START,TO,PL1" */
/*            ISTRT = 3 AT   "START,ON,PL1, = 4 AT   "START,PAST,PL1 */

/* ITHRU:     ITHRU = 0 THRU NOT PROGRAMMED */
/*            ITHRU = 1 AT   "THRU,A",      = 2 AT   "THRU,TO,PL1" */
/*            ITHRU = 3 AT   "THRU,ON,PL1,  = 4 AT   "THRU,PAST,PL1 */

/*   LOGIC-FUNCTION FOR CHECKING THE GEOMETRY */

/*  BLANK-COMMON */

/*  OUTPUT-ARRAY OF THE HEADER */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*  SYSTEM - INPUT/OUTPUT-NAMES */

/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */


/*  STORAGE OF POINTS */

/* ...                SYSTEM I/O FILES */




/*  CONTROL OF TEST-OUTPUT */



    /* Parameter adjustments */
    --adress;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/*     INITIALISE CHARACTER ITEMS FOR OUTPUT TO EXFILE */

    if (first) {
	for (i__ = 1; i__ <= 7; ++i__) {
	    imodf[(i__ << 1) - 2] = bcdf_(cmodf + (i__ - 1 << 3), (ftnlen)4);
	    imodf[(i__ << 1) - 1] = bcdf_(cmodf + ((i__ - 1 << 3) + 4), (
		    ftnlen)4);
/* L5: */
	}
	ileit[0] = bcdf_("CLDA", (ftnlen)4);
	ileit[1] = bcdf_("TA  ", (ftnlen)4);
	ipenu[0] = bcdf_("PENU", (ftnlen)4);
	ipenu[1] = bcdf_("P   ", (ftnlen)4);
	ipenu[8] = bcdf_("    ", (ftnlen)4);
	ipenu[9] = ipenu[8];
	first = FALSE_;
    }
    if (! ssprt_1.sstest) {
	goto L22;
    }
    cform_("1 GOLOFT/PLOTFT-CALLED WITH IART=  ", darray_1.darray, &c__1, &
	    c__34, (ftnlen)35, (ftnlen)120);
    iconv_(iart, darray_1.darray, &c__34, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("  PART PROGRAM-SEQUENCE-N0. (ISN): ", darray_1.darray, &c__1, &
	    c__34, (ftnlen)35, (ftnlen)120);
    record_(&i__);
    iconv_(&i__, darray_1.darray, &c__34, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("0  -U-, V- CONSTANTS         UVCONS=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(uvcons, darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -START PARAMETER             UVA=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(uva, darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -END PARAMETER               UVE=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(uve, darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -TOLERANCE                   TOL=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    if (*incr == 1) {
	cform_("   -INCREMENT ", darray_1.darray, &c__1, &c__14, (ftnlen)14, (
		ftnlen)120);
    }
    fconv_(tol, darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -MAX.CUT-VECTOR               VL=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(vl, darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -NO. INTERMEDIATE LINES-U     NU=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(nu, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -NO. INTERMEDIATE LINES-V     NV=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(nv, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -INTERPOLATION-MODE         IART=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(iart, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -POINT SEQ. INVERSION     INVERS=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(invers, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -SPIMANUF. SIDE INVERSION    MIRROR=", darray_1.darray, &c__1, 
	    &c__36, (ftnlen)39, (ftnlen)120);
    iconv_(mirror, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -NORMALS REQUIRED         NORMAL=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(normal, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    ic1 = ifxcor_1.ics;
    ic2 = ifxcor_1.ics + ifxcor_1.lsv1;
    cform_("   -AT    CONDITION              AT=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(iat, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (*iat < 2 || *iat > 4) {
	goto L7;
    }
    cform_("   -THICK FOR CHECKSURFACE 1     TH=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.th[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -OUTTOL                     TAU1=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau1[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -INTOL                      TAU2=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau2[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L7:
    cform_("   -START CONDITION           START=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(istrt, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (*istrt < 2 || *istrt > 4) {
	goto L8;
    }
    cform_("   -THICK FOR CHECKSURFACE 1     TH=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.th[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -OUTTOL                     TAU1=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau1[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -INTOL                      TAU2=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau2[ic1 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L8:
    cform_("   -THRU  CONDITION            THRU=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    iconv_(ithru, darray_1.darray, &c__36, &c__5, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (*ithru < 2 || *ithru > 4) {
	goto L9;
    }
    cform_("   -THICK FOR CHECKSURFACE 2     TH=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.th[ic2 - 1], darray_1.darray, &c__36, &c__15, &c__6, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -OUTTOL                     TAU1=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau1[ic2 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("   -INTOL                      TAU2=", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    fconv_(&sv_1.tau2[ic2 - 1], darray_1.darray, &c__36, &c__15, &c__6, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L9:
    cform_("   -SURFACE NAME                   :", darray_1.darray, &c__1, &
	    c__36, (ftnlen)36, (ftnlen)120);
    unpack_(&adress[1], &mode, &isize, &isbsct);
    holfrm_(&adress[3], darray_1.darray, &c__36, &c__8, &n, (ftnlen)120);
    if (isbsct < 1) {
	goto L10;
    }
    holfrm_(&adress[isbsct * 3], darray_1.darray, &c__36, &c__8, &n, (ftnlen)
	    120);
    cform_(" (....) ", darray_1.darray, &c__44, &c__8, (ftnlen)8, (ftnlen)120)
	    ;
    iconv_(&isbsct, darray_1.darray, &c__46, &c__4, (ftnlen)120);
L10:
    cprint_(darray_1.darray, (ftnlen)120);

/*  COMMON START OF ROUTINE */

/*  NAME OF THE SURFACE */
L22:
    unpack_(&adress[1], &mode, &isize, &isbsct);
    *obname = adress[isize + 1];
    if (isbsct > 1) {
	*obname = adress[isbsct * isize + isbsct];
    }
    plgol_1.obnam1 = *obname;

/*   SAVE REGION FLAG ANS SWITCH OFF GLOBAL REGION FLAG TO PREVENT */
/*                        REGION PROCESSING IF PROGRAMMED IN ATAPE */
    regfls = (doublereal) glflgs_1.regflg;
    glflgs_1.regflg = 0;

/*  FETCHING THE SURFACE */
    ldaflg = 3;
    apt094_(&ldaflg, &adress[1], &j11);
    j11 += -41;

/*  TAKE OLD TLAXIS FOR 5-AXIS DIRECTION DECISION */
    if (ifxcor_1.mantax != 2 || *normal == 1) {
	goto L200;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L210: */
	vtax[i__ - 1] = fxcor_1.ta[i__ - 1];
    }
    transm_(plgol_1.vta, vtax, &c__3, &c__3, &c_n1);
L200:

/* PREPARATION FOR PLANE LIMITS */
    iret = 0;
    incr1 = *incr;
    *incr = 1;
    golpln_(&j11, &iret);
    *incr = incr1;

/*  WRONG TOOL AXIS INFORMATION. */
    if (iret == 1) {
	aerr_(&c__22223, "GOL     ", (ftnlen)8);
    }

/*  TOOL-AXIS CAN NOT BE COMPUTED. */
    if (iret == 2) {
	aerr_(&c__22222, "GOL     ", (ftnlen)8);
    }

/*  POINT IS OUTSIDE OF THE U/V PARAMETERS OF THE PATCH. */
    if (iret == 3) {
	aerr_(&c__22220, "GOL     ", (ftnlen)8);
    }
    if (iret != 0) {
	goto L998;
    }

/*  TAKE OLD TLAXIS FOR 5-AXIS DIRECTION DECISION */
    if (ifxcor_1.mantax != 2 || *normal == 1) {
	goto L300;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L310: */
	vtax[i__ - 1] = fxcor_1.ta[i__ - 1];
    }
    transm_(plgol_1.vta, vtax, &c__3, &c__3, &c_n1);
L300:

/*  OUTPUT OF    PENUP, IF  PLOTFT/GRID WANTED */
    if (*iart != 5) {
	goto L30;
    }
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ipenu[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, penup, &j, &ir);

/*  OUTPUT OF THE HEADER ONLY FOR >PLOTFT/SCURV,...< */
L30:
    if (*iart > 2) {
	goto L35;
    }
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[*iart - 1];
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = 2;
    if (*uva == *uve) {
	ifxcor_1.icl = 3;
    }

/*  DISPATCHING OF IART */
L35:
    if (*uva == -1e30) {
	*uva = 0.;
    }
    switch (*iart) {
	case 1:  goto L1200;
	case 2:  goto L1100;
	case 3:  goto L1300;
	case 4:  goto L1400;
	case 5:  goto L1500;
	case 6:  goto L1600;
	case 7:  goto L1700;
    }
    s_stop("", (ftnlen)0);

/*  PLOTFT/CURVE,FLOW,... */
L1100:
    umx = sscan[j11 + 7];

/*  IF NEEDED OUTPUT WITH 'PARAM' */
    if (umx == 0.) {
	umx = sscan[j11 + 3];
    }

/*  KEEP THE 'FLOW'-SEGMENT-ACCOUNT */
    uhilfs = sscan[j11 + 7];
    goto L1210;

/*  PLOTFT/CURVE,PARAM,... */
L1200:
    umx = sscan[j11 + 3];

/*  KEEP THE 'FLOW'-SEGMENT-ACCOUNT */
    uhilfs = sscan[j11 + 7];

/*  'FLOW'-SEGMENT-ACCOUNT =0 FOR A SHORT TIME */
    sscan[j11 + 7] = 0.;
L1210:
    ua = max(0.,*uva);
    if (*uve == 1e30) {
	*uve = umx;
    }
    ue = min(*uve,umx);
    ianz = (integer) ((ue - ua) / *tol);
    anz = (doublereal) ianz;
    if (ianz == 0) {
	anz = 1.;
    }
    anz += -1e-4f;
    toli = (ue - ua) / anz;
    if (ua >= ue) {
	goto L1205;
    }
    if (*uva >= 0.) {
	goto L1220;
    }
L1205:
    gop_(&c__2, uva, &udummy, spv, &j11, &iret);
    if (ua >= ue) {
	goto L1240;
    }
L1220:
    if (*incr == 1) {
	goto L1221;
    }

/*  OUTPUT OF POINTS UNDER CHORD-CONTROL */
    gochor_(&c__1, &ua, &ue, &j11, &iret);
    goto L1222;

/*  MOVEMENT WITH 'INCR' */
L1221:
    gop_(&c__2, &ua, &udummy, spv, &j11, &iret);
    ua += toli;
    if (ua < ue) {
	goto L1221;
    }
L1222:
    if (ue == *uve) {
	ifxcor_1.icl = 3;
    }
    gop_(&c__2, &ue, &udummy, spv, &j11, &iret);
    if (ue == *uve) {
	goto L1260;
    }
L1240:
    if (ifxcor_1.icl == 3) {
	goto L1260;
    }
    ifxcor_1.icl = 3;
    gop_(&c__2, uve, &udummy, spv, &j11, &iret);
L1260:
    sscan[j11 + 7] = uhilfs;
    goto L999;

/*  PLOTTING OF THE GRID */
L1500:
    *invers = 0;
    inver1 = 1;
    if (*nu < 0) {
	goto L1510;
    }
    *uvcons = 0.;
    *uva = 0.;
    *uve = sscan[j11 + 8] - 1.;
    deltuv = 1. / (*nu + 1);
    umx = sscan[j11 + 9] - 1.;
    goto L1300;
L1510:
    if (*nv < 0) {
	goto L999;
    }
    *uvcons = 0.;
    *uva = 0.;
    *uve = sscan[j11 + 9] - 1.;
    deltuv = 1. / (*nv + 1);
    vmax = sscan[j11 + 8] - 1.;
    goto L1400;

/*  PLOTTING OR MANUFACTURING WITH    UCONST */
L1300:
L1600:
    vmax = sscan[j11 + 8] - 1.;
    if (*uve == 1e30) {
	*uve = vmax;
    }

/*  PRESET >NSEG< AND >LSEG< TO ZERO FOR REGION/OFF CASE */
    nseg = 0;
    lseg = 0;
/*  COMPUTE THE SEGMENTS */
    if (regfls == 0.) {
	goto L1604;
    }
    numver_(uvcons, uva, uvcons, uve, &adress[1], uv, &nseg);
    ldaflg = 3;
    apt094_(&ldaflg, &adress[1], &j11);
    j11 += -41;
    if (nseg == 0) {
	goto L1552;
    }
    if (*invers == 1) {
	goto L1602;
    }

/*  PREPARATION OF REGION SEGMENT CUTS */
    ifxcor_1.iseg = 1;
L1601:
    *uvcons = uv[(ifxcor_1.iseg << 2) - 4];
    *uva = uv[(ifxcor_1.iseg << 2) - 3];
    *uve = uv[(ifxcor_1.iseg << 2) - 1];
    lseg = 3;
    if (ifxcor_1.iseg == 1) {
	lseg = 1;
    }
    ++ifxcor_1.iseg;
    --nseg;
    goto L1604;

/*  PREPARATION OF INVERS REGION SEGMENT CUTS */
L1602:
    ifxcor_1.iseg = nseg;
    nnseg = nseg;
L1603:
    *uvcons = uv[(ifxcor_1.iseg << 2) - 4];
    *uva = uv[(ifxcor_1.iseg << 2) - 3];
    *uve = uv[(ifxcor_1.iseg << 2) - 1];
    lseg = 2;
    if (ifxcor_1.iseg == nnseg) {
	lseg = 4;
    }
    --ifxcor_1.iseg;
    --nseg;
L1604:
    va = max(0.,*uva);
    ve = min(*uve,vmax);

/*  COMPUTING OF A CUT-NUMBER WITHOUT REST */
    ianz = (integer) ((ve - va) / *tol);
    anz = (doublereal) ianz;
    if (ianz == 0) {
	anz = 1.;
    }
    anz += -1e-4f;
    toli = (ve - va) / anz;

/*  INVERS ? */
    if (*invers == 1) {
	goto L1650;
    }

/*  CUTTER PATH INTRODUCTION */
    if (lseg == 0) {
	lseg = 1;
    }
    ifxcor_1.icl = 2;
    if (*uva == *uve) {
	ifxcor_1.icl = 3;
    }
    goretr_(&lseg, uvcons, uva, spv, &j11, &iret);

/*  NOT   INVERS */
    if (va >= ve) {
	goto L1605;
    }
    if (*uva >= 0.) {
	goto L1620;
    }
L1605:
    gop_(&c__2, uvcons, uva, spv, &j11, &iret);
    if (va >= ve) {
	goto L1640;
    }
L1620:
    if (*incr == 1) {
	goto L1621;
    }

/*  OUTPUT OF POINTS UNDER CONTROL OF CHORD */
    gochor_(&c__2, &va, &ve, &j11, &iret);
    goto L1622;

/*  MOVEMENTS WITH 'INCR' */
L1621:
    gop_(&c__2, uvcons, &va, spv, &j11, &iret);
    va += toli;
    if (va < ve) {
	goto L1621;
    }
L1622:
    if (ve == *uve) {
	ifxcor_1.icl = 3;
    }
    gop_(&c__2, uvcons, &ve, spv, &j11, &iret);
    if (ve == *uve) {
	goto L1550;
    }
L1640:
    if (ifxcor_1.icl == 3) {
	goto L1550;
    }
    ifxcor_1.icl = 3;
    gop_(&c__2, uvcons, uve, spv, &j11, &iret);
    goto L1550;

/*  INVERS */

/*  CUTTER PATH INTRODUCTION */
L1650:
    if (lseg == 0) {
	lseg = 4;
    }
    ifxcor_1.icl = 2;
    if (*uva == *uve) {
	ifxcor_1.icl = 3;
    }
    goretr_(&lseg, uvcons, uve, spv, &j11, &iret);
    if (va >= ve) {
	goto L1655;
    }
    if (*uve <= vmax) {
	goto L1670;
    }
L1655:
    gop_(&c__2, uvcons, uve, spv, &j11, &iret);
    if (va >= ve) {
	goto L1690;
    }
L1670:
    if (*incr == 1) {
	goto L1671;
    }

/*  OUTPUT OF POINTS UNDER CONTROL OF CHORD */
    gochor_(&c__3, &ve, &va, &j11, &iret);
    goto L1672;

/*  MOVEMENT WITH 'INCR' */
L1671:
    gop_(&c__2, uvcons, &ve, spv, &j11, &iret);
    ve -= toli;
    if (va < ve) {
	goto L1671;
    }
L1672:
    if (va == *uva) {
	ifxcor_1.icl = 3;
    }
    gop_(&c__2, uvcons, &va, spv, &j11, &iret);
    if (va == *uva) {
	goto L1550;
    }
L1690:
    if (ifxcor_1.icl == 3) {
	goto L1550;
    }
    ifxcor_1.icl = 3;
    gop_(&c__2, uvcons, uva, spv, &j11, &iret);

/*  RETRACT AT END OF SEGMENT */
L1550:
    if (*invers == 1) {
	goto L1551;
    }
    lseg = 2;
    if (nseg == 0) {
	lseg = 4;
    }
    goretr_(&lseg, uvcons, uve, spv, &j11, &iret);
    if (nseg != 0) {
	goto L1601;
    }
    goto L1552;
L1551:
    lseg = 3;
    if (nseg == 0) {
	lseg = 1;
    }
    goretr_(&lseg, uvcons, uva, spv, &j11, &iret);
    if (nseg != 0) {
	goto L1603;
    }
L1552:
    if (*iart != 5) {
	goto L999;
    }
    *invers += inver1;
    inver1 = -inver1;
    *uvcons += deltuv;
    if (*uvcons <= umx) {
	goto L1300;
    }
    *nu = -1;
    goto L1500;

/*  PLOTTING OR MANUFACTURING WITH VCONST */
L1400:
L1700:
    umx = sscan[j11 + 9] - 1.;
    if (*uve == 1e30) {
	*uve = umx;
    }

/*  PRESET >NSEG< AND >LSEG< TO ZERO FOR REGION/OFF CASE */
    nseg = 0;
    lseg = 0;
/*  COMPUTE THE SEGMENTS */
    if (regfls == 0.) {
	goto L1704;
    }
    numver_(uva, uvcons, uve, uvcons, &adress[1], uv, &nseg);
    ldaflg = 3;
    apt094_(&ldaflg, &adress[1], &j11);
    j11 += -41;
    if (nseg == 0) {
	goto L1562;
    }
    if (*invers == 1) {
	goto L1702;
    }

/*  PREPARATION OF REGION SEGMENT CUTS */
    ifxcor_1.iseg = 1;
L1701:
    *uvcons = uv[(ifxcor_1.iseg << 2) - 3];
    *uva = uv[(ifxcor_1.iseg << 2) - 4];
    *uve = uv[(ifxcor_1.iseg << 2) - 2];
    lseg = 3;
    if (ifxcor_1.iseg == 1) {
	lseg = 1;
    }
    ++ifxcor_1.iseg;
    --nseg;
    goto L1704;

/*  PREPARATION OF INVERS REGION SEGMENT CUTS */
L1702:
    ifxcor_1.iseg = nseg;
    nnseg = nseg;
L1703:
    *uvcons = uv[(ifxcor_1.iseg << 2) - 3];
    *uva = uv[(ifxcor_1.iseg << 2) - 4];
    *uve = uv[(ifxcor_1.iseg << 2) - 2];
    lseg = 2;
    if (ifxcor_1.iseg == nnseg) {
	lseg = 4;
    }
    --ifxcor_1.iseg;
    --nseg;
L1704:
    ua = max(0.,*uva);
    ue = min(*uve,umx);

/*  COMPUTATION OF THE CUT-NUMBER WITHOUT REST */
    ianz = (integer) ((ue - ua) / *tol);
    anz = (doublereal) ianz;
    if (ianz == 0) {
	anz = 1.;
    }
    anz += -1e-4f;
    toli = (ue - ua) / anz;

/*  INVERS ? */
    if (*invers == 1) {
	goto L1750;
    }

/*  CUTTER PATH INTRODUCTION */
    if (lseg == 0) {
	lseg = 1;
    }
    ifxcor_1.icl = 2;
    if (*uva == *uve) {
	ifxcor_1.icl = 3;
    }
    goretr_(&lseg, uva, uvcons, spv, &j11, &iret);

/*  NOT  INVERS */
    if (ua >= ue) {
	goto L1705;
    }
    if (*uva >= 0.) {
	goto L1720;
    }
L1705:
    gop_(&c__2, uva, uvcons, spv, &j11, &iret);
    if (ua >= ue) {
	goto L1740;
    }
L1720:
    if (*incr == 1) {
	goto L1721;
    }

/*  OUTPUT OF POINTS UNDER CONTROL OF CHORD */
    gochor_(&c__4, &ua, &ue, &j11, &iret);
    goto L1722;

/*  MOVEMENT WITH 'INCR' */
L1721:
    gop_(&c__2, &ua, uvcons, spv, &j11, &iret);
    ua += toli;
    if (ua < ue) {
	goto L1721;
    }
L1722:
    if (ue == *uve) {
	ifxcor_1.icl = 3;
    }
    gop_(&c__2, &ue, uvcons, spv, &j11, &iret);
    if (ue == *uve) {
	goto L1560;
    }
L1740:
    if (ifxcor_1.icl == 3) {
	goto L1560;
    }
    ifxcor_1.icl = 3;
    gop_(&c__2, uve, uvcons, spv, &j11, &iret);
    goto L1560;

/*  INVERS */

/*  CUTTER PATH INTRODUCTION */
L1750:
    if (lseg == 0) {
	lseg = 4;
    }
    ifxcor_1.icl = 2;
    if (*uva == *uve) {
	ifxcor_1.icl = 3;
    }
    goretr_(&lseg, uve, uvcons, spv, &j11, &iret);
    if (ua >= ue) {
	goto L1755;
    }
    if (*uve <= umx) {
	goto L1770;
    }
L1755:
    gop_(&c__2, uve, uvcons, spv, &j11, &iret);
    if (ua >= ue) {
	goto L1790;
    }
L1770:
    if (*incr == 1) {
	goto L1771;
    }

/*  OUTPUT OF POINTS UNDER CONTROL OF CHORD */
    gochor_(&c__5, &ue, &ua, &j11, &iret);
    goto L1772;

/*  MOVEMENT WITH 'INCR' */
L1771:
    gop_(&c__2, &ue, uvcons, spv, &j11, &iret);
    ue -= toli;
    if (ua < ue) {
	goto L1771;
    }
L1772:
    if (ua == *uva) {
	ifxcor_1.icl = 3;
    }
    gop_(&c__2, &ua, uvcons, spv, &j11, &iret);
    if (ua == *uva) {
	goto L1560;
    }
L1790:
    if (ifxcor_1.icl == 3) {
	goto L1560;
    }
    ifxcor_1.icl = 3;
    gop_(&c__2, uva, uvcons, spv, &j11, &iret);

/*  RETRACT AT END OF SEGMENT */
L1560:
    if (*invers == 1) {
	goto L1561;
    }
    lseg = 2;
    if (nseg == 0) {
	lseg = 4;
    }
    goretr_(&lseg, uve, uvcons, spv, &j11, &iret);
    if (nseg != 0) {
	goto L1701;
    }
    goto L1562;
L1561:
    lseg = 3;
    if (nseg == 0) {
	lseg = 1;
    }
    goretr_(&lseg, uva, uvcons, spv, &j11, &iret);
    if (nseg != 0) {
	goto L1703;
    }
L1562:
    if (*iart != 5) {
	goto L999;
    }
    *invers += inver1;
    inver1 = -inver1;
    *uvcons += deltuv;
    if (*uvcons <= vmax) {
	goto L1400;
    }
    *nv = -1;
    goto L999;

/*  DIRECTION OF MOVEMENT */
L999:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2000: */
	fxcor_1.temp[i__ - 1] = fxcor_1.te[i__ - 1] - fxcor_1.tek[i__ - 1];
    }
    vnorm_(fxcor_1.temp, fxcor_1.ti);
    ifxcor_1.igoto = 0;
    if (ifxcor_1.ier > 0) {
	goto L998;
    }
    if ((d__1 = fxcor_1.ti[0] * fxcor_1.ta[0] + fxcor_1.ti[1] * fxcor_1.ta[1] 
	    + fxcor_1.ti[2] * fxcor_1.ta[2], abs(d__1)) > .997) {
	goto L998;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2010: */
	fxcor_1.pmove[i__ - 1] = fxcor_1.ti[i__ - 1];
    }


/*  POINT IS OUTSIDE OF THE U/V PARAMETERS OF THE PATCH. */
    if (iret == 2) {
	aerr_(&c__22220, "GOL     ", (ftnlen)8);
    }

/*   RESTURE GLOBAL REGION FLAG */
L998:
    glflgs_1.regflg = (integer) regfls;
    return 0;
} /* gol_ */

#undef uvcons
#undef mirror
#undef invers
#undef normal
#undef obname
#undef bcanon
#undef istrt
#undef ithru
#undef penup
#undef ipenu
#undef ileit
#undef sscan
#undef imodf
#undef canon
#undef vtax
#undef sinl
#undef cosl
#undef iart
#undef leit
#undef incr
#undef modf
#undef uve
#undef tol
#undef uva
#undef iat
#undef can
#undef vt1
#undef nv
#undef nu
#undef vl


