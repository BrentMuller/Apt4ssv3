/* AMIND.f -- translated by f2c (version 20100827).
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
    doublereal a, b, c__, cendis, cmove[3], com1, com4, dir[3], dp, dpe, 
	    dpcnt, dpi, dpl, dp1, d1, d2a, flipck, fwd[3], ogle[3], p1[3], p2[
	    3], rdrn, refpnt[3], tangl, tes[3], tew[3], uvec[3], u2[3], v[3], 
	    vl, zl, zlnorm[3], zlpnt[3], zl1, param[6], r__[6], savpar[4], 
	    seg[9], slope, sqroot, unn, upp, vint, vnn, vpp;
} dshar4_;

#define dshar4_1 dshar4_

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
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer iamdct, ipdpl, ipt, iws, jckr, jcnt1, jcnt2, jcnt3, jcpr, jcr, 
	    jdr, jfind, jgr, jmin, jminr, jpr, jpxr, jtkf, jtr, j10, j12, j13,
	     j54, mdic;
} ishr18_;

#define ishr18_1 ishr18_

struct {
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

struct {
    integer ichekf;
} chekfl_;

#define chekfl_1 chekfl_

struct {
    doublereal talt[3], svgl, shilf, gflg, tpg[3], spg[3];
} cgoug_;

#define cgoug_1 cgoug_

struct {
    doublereal dist, uvdist, spbond[40];
    integer istart;
} cstart_;

#define cstart_1 cstart_

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__1 = 1;
static integer c__26002 = 26002;
static integer c__7 = 7;

/* *** SOURCE FILE : M0002918.W05   *** */

/* .....FORTRAN SUBROUTINE  ....AMIND          8/68                 PH,HG */
/* Subroutine */ int amind_(void)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal zero = 0.;
    static doublereal zlit1 = .99995;
    static doublereal zlit2 = .995;
    static doublereal zlit5 = .99;
    static doublereal z2 = 2.;
    static doublereal z9em1 = .9;

    /* Format strings */
    static char fmt_7100[] = "(\002*** WARNING *** FLIPAB = \002,d12.5,\002 "
	    "AT 3RD (WEAKER) CONVERGENCE TEST IN AMIND\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;

    /* Local variables */
    static integer i__, k;
    static doublereal w1, te1[3];
#define can ((doublereal *)&_BLNK__1 + 40)
    static char msg[70];
    static integer map;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal ssav;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal smod;
    extern /* Subroutine */ int apt238_(integer *);
    static doublereal oldu1[3], u1sav[3], cfakt;
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal tpsav[3], tnsav[3], spsav[3], snsav[3], smods;
    static integer icbot;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), ccurv_(
	    integer *, doublereal *, doublereal *, doublereal *);
    static doublereal rcsav;
    static integer itsav, islim;
    static doublereal ajent;
    extern /* Subroutine */ int u1comp_(void);
    static integer itlon1;
    static doublereal flipab;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ajundd_(void);
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
#define kdynfl ((integer *)&addcom_1 + 48)
    static integer itnchg;
    static doublereal flipmx, blongd;
    extern /* Subroutine */ int tlnorm_(doublereal *), outmsg_(char *, ftnlen)
	    ;

    /* Fortran I/O blocks */
    static icilist io___43 = { 0, msg, 0, fmt_7100, 70, 1 };




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  4.  DSHARE BLOCK 4  *** */





/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...  21. ADDCOM BLOCK */

/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */







/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/* ---- FLAG INTRODUCED BY VW - USED TO DETERMINE 'CORRECT' SIDE OF CUTTER */









/* ------------AMIND - FIND MINIMUM DISTANCE FROM CUTTER TO SURFACE. */
/*             /-IC IS INDEX TO THE CANON FORM OF IS SURFACE */
    ifxcor_1.ic = isv_1.icanon[(20 + (0 + (ifxcor_1.is - 1 << 2)) - 20) / 4];
/*             /-SPECIAL LOGIC FOR SSURF ONLY.  A FAST LOGIC IS */
/*             /-USED FOR POINT AND BALL CUTTERS AT TIMES ON SSURFS */
/*             /-MSSCHK SET TO 1 FOR SPECIAL LOGIC, 0 FOR NORMAL */
    flipmx = zero;
    flipab = zero;
    ssav = 1e5;
    smods = 1e5;
    modess_1.modess = 0;
    modess_1.msschk = 0;
    cstart_1.istart = 0;
    cstart_1.uvdist = zero;
    cstart_1.dist = zero;
    if (modess_1.mssarl != 1) {
	goto L1101;
    }
    if (isv_1.isfidn[ifxcor_1.is - 1] != 29) {
	goto L1101;
    }
/*             /-JTLFLG IS 1 IF 8 TH CUTTER SEGMENT RQD, 0 OTHERWISE. */
    if (isv_1.jtlflg[ifxcor_1.is - 1] == 1) {
	goto L1101;
    }
    w1 = fxcor_1.cutdat[1] - fxcor_1.cutdat[0];
    if (abs(w1) > 1e-4) {
	goto L1101;
    }
    modess_1.msschk = 1;
L1101:
    icbot = ifxcor_1.ic - 1;
/*             /-JMIN SWITCH=1 FOR ERR IN AMIND, =0 OTHERWISE */
/*             /-IAMDCT IS COUNT OF NUMBER OF ITERATIONS WITHIN AMIND */
    ishr18_1.jmin = 0;
    ishr18_1.iamdct = 0;

/*             /-SAVE TN ONLY FOR CHECK SURFACES */
    if (ifxcor_1.is < ifxcor_1.ics) {
	goto L1102;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv1_1.tnl[i__ + ifxcor_1.is * 3 - 4] = sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4];
/* L1105: */
    }
L1102:
    if (*kdynfl != 0) {
	apt238_(&c__3);
    }
/*              /-DYNDMP(103) --------. */
/*             /-REPLACE TOOL BY POINT TOOL AT TP(IT) IF TANGENT */
/*             /-CS IS BEING REFERENCED. */
/*             /-IOP=1 FOR SMALLEST POSITIVE DIRECTED DISTANCE */
/*             /-IOP=0 FOR SMALLEST ABSOLUTE DIRECTED DISTANCE */
    isv_1.iop[ifxcor_1.is - 1] = 0;
/*             /-ITLON=0 FOR TOOL ON THIS SURF, =1 OTHERWISE */
    itlon1 = isv_1.itlon[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1103: */
	te1[i__ - 1] = fxcor_1.te[i__ - 1];
    }
/*             /-ITLON -2 MEANS FIND DIST FROM DS CONTACT PT TO SURF */
/*             /-ITLON=-3 MEANS FIND DIST FROM PS CONTACT PT TO SURF */
/*             /-THESE CASES ARE FORCED BY CHANGING TE TO TP AND TOOL ON. */
    if (isv_1.itlon[ifxcor_1.is - 1] < 2) {
	goto L1104;
    }
    if (isv_1.itlon[ifxcor_1.is - 1] == 2) {
	k = ifxcor_1.ids;
    }
    if (isv_1.itlon[ifxcor_1.is - 1] == 3) {
	k = ifxcor_1.ips;
    }
    isv_1.itlon[ifxcor_1.is - 1] = 0;
/*             /-TE IS THE CURRENT TOOL END AND VT IS THE VECTOR FROM THE */
/*             /-TO THE CONTACT POINT ON THE CUTTER WITH THE SURFACE. */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] = sv_1.tp[i__ + k * 3 - 4] - sv_1.th[k - 1] * 
		sv_1.tn[i__ + k * 3 - 4];
	sv_1.vt[i__ + ifxcor_1.is * 3 - 4] = zero;
/* L1107: */
    }

/*             /-FOR INITIAL ENTRY FOR A GIVEN SURFACE,JENT=1. THEN */
/*             /-FOLLOW INITIAL ENTRY ROUTES. START WITH TP = TM. */
L1104:

/*     SPECIAL HANDLING WHEN GFLG=1 */

    if (cgoug_1.gflg > zero) {
	cfakt = one;
	cgoug_1.gflg = -one;
L77008:
	for (i__ = 1; i__ <= 3; ++i__) {
	    sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + cfakt *
		     fxcor_1.cutdat[0] * fxcor_1.ti[i__ - 1];
/* .... SAVE TN */
	    tnsav[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L7008: */
	}
	isv_1.itseg[ifxcor_1.is - 1] = ifxcor_1.ibegin;
	modess_1.modess = 11;
	ajundd_();
	modess_1.modess = 0;

/* .... TN,SN TROUBLE ? (ITNCHG=1) */

	if (itnchg == 0) {
	    goto L252;
	} else {
	    for (i__ = 1; i__ <= 3; ++i__) {
		sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = tnsav[i__ - 1];
/* L77011: */
	    }
	    if (cfakt < .3) {
		goto L252;
	    } else {
		cfakt += -.1;
		goto L77008;
	    }
	}
    }
/* ----------------------------------------------- */
/*             /-JENT =1 FOR FIRST ENTRY TO AMIND, 0 OTHERWISE. */
    if (isv_1.jent[ifxcor_1.is - 1] == 0) {
	goto L2012;
    }
/*             /-INITIAL ENTRY - CONSTRUCT FIRST TP IN MIDDLE OF CUTTER */
    w1 = fxcor_1.cutdat[6] / 2.f;
    if (modess_1.msschk == 1) {
	w1 = fxcor_1.cutdat[1];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.tm[i__ - 1];
/* L1108: */
    }

    blongd = w1 * 2.;
    if (blongd < 15.) {
	blongd = 1e5;
    }

/*             /-Z ADJUSTS SURFACE NORMAL TO POINT TO CUTTER SIDE */
/*             /-RC IS THE RADIUS OF CURVATURE AT THE SURFACE POINT. */
/*             /-RC1 INITIALLY 4500 INCHES(ENGLISH UNITS) */
    sv_1.rc[ifxcor_1.is - 1] = fxcor_1.rc1;
    sv_1.z__[ifxcor_1.is - 1] = one;

/*             /-IAFL = 0 IF PS PLANE PERPTO TA,OR DS,CS PLANE LL TA. */
/*             /-IAFL = 1 IF SURF LINE ELEMENT LL TA */
/*             /-IAFL = -1 OTHERWISE */
/*             /-FOLLOW SPECIAL ANALYTIC ROUTE FOR IAFL = 0 */
    if (isv_1.iafl[ifxcor_1.is - 1] == 0) {
	goto L202;
    }
    if (isv_1.iafl[ifxcor_1.is - 1] > 0) {
	goto L1109;
    }
/*             /-SINCE IAFL IS LT 0, SET TOOL SEG TO FIRST SEG. */
    isv_1.itseg[ifxcor_1.is - 1] = ifxcor_1.ibegin;
    goto L251;
L1109:
/*             /-IAFL(IS) IS GT 0, SO SET TP TO TOP OF TOOL */
/*             /-TOOLHT ARE TOOL TOP COORDS(HT*TA)- RELATED TO SURFACE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1111: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		sv_1.toolht[i__ + ifxcor_1.is * 3 - 4];
    }

L251:
/*             /-INITIAL ENTRY ROUTE,NORMAL CASE. PROBLEM IS TO SET */
/*             /-SIGN OF SN(IS) AND HENCE Z(IS) CORRECTLY. */
/*             /-BRANCH TO SURFACE DISTANCE CALCULATION FROM HERE. */
/*             /-USE TP,TN TO FIND SP,SN,S SO THAT TP+S*TN=SP */
    modess_1.modess = 11;
    ajundd_();
    modess_1.modess = 0;

L252:
    ishr18_1.iamdct = 1;
/* ***       BRANCH TO 2999 ON FATAL ERROR */
    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
/*             /-JTN FLAG IS 1 FOR TN CONTROL OF SURFACE(LIKE CS) */
/*             /-JTN FLAG IS SET TO 0 FOR SN CONTROL(LIKE PS,DS) */
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L1110;
    }
/*             /-TN CONTROL CASE, SET TN TO CURRENT SURF NORMAL , GO ON */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1115: */
    }
    goto L2009;

L1110:
/*             /-SN CONTROL, SET Z SO Z*SN POINTS TO CUTTER SIDE OF SURF */
    dotf_(&sv_1.z__[ifxcor_1.is - 1], &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.sn[
	    ifxcor_1.is * 3 - 3]);
    if ((d__1 = sv_1.z__[ifxcor_1.is - 1], abs(d__1)) > 1e-6f) {
	goto L1112;
    }
/*             /-INNER PRODUCT SMALL, TN AND SN PERPENDICULAR. TRY NEW TN */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4] + sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L1113: */
    }
    vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
/*             /-RESORE Z */
    sv_1.z__[ifxcor_1.is - 1] = one;
/*             /-CALL SURFACE DISTANCE CALC AGAIN */
    goto L251;

L1112:
/*             /-SET Z SO THAT Z*SN AND TP-SP ARE IN SAME DIRECTION */
    if (sv_1.s[ifxcor_1.is - 1] != zero) {
	sv_1.z__[ifxcor_1.is - 1] = sv_1.s[ifxcor_1.is - 1] * sv_1.z__[
		ifxcor_1.is - 1];
    }
    d__1 = sv_1.past[ifxcor_1.is - 1] * sv_1.z__[ifxcor_1.is - 1];
    sv_1.z__[ifxcor_1.is - 1] = -d_sign(&one, &d__1);
/*             /-PAST IS -1 IF ISFTYP=2 (PAST CASE ), 1 OTHERWISE */
/*             /-ADJUST SN BY Z AND SET TN TO -SN */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = sv_1.z__[ifxcor_1.is - 1] * 
		sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1114: */
    }
    goto L2009;

/* ------------------------------------------------------- */
/*             /-NORMAL ENTRY ROUTE. SET FIRST TRIAL TP USING VT. */
/*             /-SWITCH TO SPECIAL ANALYTIC IAFL = 0 ROUTES IF NEEDED */
/*             /-ALSO USE SPECIAL ROUTE IF CYLINDER LL TA. */
L2012:
/*             /-PLACE TOOL POINT ON THICK ENVELOPE IN DIRECTION OF TN */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = sv_1.vt[i__ + ifxcor_1.is * 3 - 
		4] + sv_1.th[ifxcor_1.is - 1] * sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4] + fxcor_1.te[i__ - 1];
/* L1122: */
    }
/*             /-IAFL -1, GENERAL SURF PATH */
    if (isv_1.iafl[ifxcor_1.is - 1] < 0) {
	goto L2009;
    }
/*             /-IAFL =0, PLANE SURF PERPEN, OR PLANE DRIVE SURF PARLLEL */
    if (isv_1.iafl[ifxcor_1.is - 1] == 0) {
	goto L212;
    }
/*             /-IAFL +1, SURF ELEMENT PARALLEL TO TA */
/*             /-IF SURFACE TYPE LT 5,(IE PLANE,LINE,CYLIN) GO TO 4000 */
    if (isv_1.isfidn[ifxcor_1.is - 1] >= 5) {
	goto L2009;
    }

/* ------------------------------------------------------- */
/*             /-SPECIAL U1COMP ROUTE FOR TA LL CYLINDER AXIS. */
/*             /-USEFUL IF CUTTER RADIUS NEARLY CYLINDER RADIUS */
/*             /-BRANCH TO SURFACE DISTANCE CALCULATION FROM HERE. */

    modess_1.modess = 12;
    ajundd_();
    modess_1.modess = 0;

    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spl[ifxcor_1.is 
	    * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ + 2] = sv_1.cc[i__ + ifxcor_1.is * 3 - 4];
/* L1142: */
	sv_1.cc[i__ + ifxcor_1.is * 3 - 4] = canon[icbot + i__ - 1];
    }
    u1comp_();
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1143: */
	sv_1.cc[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.temp[i__ + 2];
    }
    goto L2038;

/* -------------------------* CALL SURFACE FOR DIRECTED DISTANCE *-------- */
/*             /-OTHERWISE, GO THE GENERAL SURFACE PATH */
/*             /-2ND PHASE OF INITIAL ENTRY TO AMIND(JENT=1) */
/*             /-WITH CURRENT TP,TN CALL SURFACE ROUTINE FOR SP,SPL,SN */
/*             /-THEN USE CCURV TO FIND RC,CC.  USE CENTER OF CURVATURE C */
/*             /-TO FIND THE CORRECT SIDE OF THE CUTTER. */
/*             /-BRANCH TO SURFACE DISTANCE CALCULATION FROM HERE. */
L2009:
    if (modess_1.msschk == 1) {
	goto L2038;
    }
    modess_1.modess = 13;
    ajundd_();
    modess_1.modess = 0;

/* ***        TERMINATE FOR FATAL ERROR */
    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
/*             /-FIND ISIGCR, RC AND CC.  CENTER OF CURV= SP-RC*SN. */
    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spl[ifxcor_1.is 
	    * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
/*             /-ISIGCR -1 FOR PLANE, 0 NORMAL CASE, 1 IF PREV RC USED */
    if (isv_1.isigcr[ifxcor_1.is - 1] >= 0) {
	goto L1116;
    }
/*             /-SPECIAL CALC OF CC IN PLANE CASE */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.cc[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4] - sv_1.rc[ifxcor_1.is - 1] * sv_1.sn[i__ + ifxcor_1.is * 3 
		- 4];
/* L1117: */
    }
L1116:
/*             /-IF TOOL IS ON THIS SURF, SKIP U1(TOOL SIDE) CALCULATION */
    if (isv_1.itlon[ifxcor_1.is - 1] == 0) {
	goto L338;
    }
/*             /-DETERMINE THE SIDE OF THE CUTTER TO CONTACT SURFACE */
    u1comp_();

    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
    if (isv_1.jent[ifxcor_1.is - 1] <= 0) {
	goto L1118;
    }
/*             /-FURTHER ADJUSTMENT NEEDED FOR FIRST AMIND ENTRY */
    if (isv_1.jtn[ifxcor_1.is - 1] != 0) {
	goto L1118;
    }
/*             /-SURFACE NORMAL CONTROL, JTN=0 */
    if (sv_1.rc[ifxcor_1.is - 1] >= zero) {
	goto L1118;
    }
/*             /-RC NEGATIVE  ADJUST U1 IF CC-TE.U1 IS POSITIVE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1119: */
	fxcor_1.temp[i__ - 1] = sv_1.cc[i__ + ifxcor_1.is * 3 - 4] - 
		fxcor_1.te[i__ - 1];
    }
    dotf_(fxcor_1.tem, &sv_1.u1[ifxcor_1.is * 3 - 3], fxcor_1.temp);
    if (fxcor_1.tem[0] <= zero) {
	goto L1118;
    }
/*             /-SET U1 TO OTHER SIDE OF CUTTER */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
/* L1120: */
    }
L1118:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1121: */
	oldu1[i__ - 1] = sv_1.u1[i__ + ifxcor_1.is * 3 - 4];
    }

/* ------------------------------------------------------- */
L338:
    if (*kdynfl != 0) {
	apt238_(&c__4);
    }
/*              /-DYNDMP(104) --------. */
/*             /-***** START ITERATIVE LOOP. CALL TLNORM FOR TP,TN ** */
/*             /-***** CALL AJUNDD FOR SP,SN,S. COMPUTE FLIPCK=TN.SN */
L2038:
/*             /-MAP IS A RESTART FLAG, =0 REVERSE U1 AND TRY AGAIN */
/*             /-MAP=1 MEANS RESTART EFFECTIVE, ERROR IS FATAL NOW. */
    map = 0;

/*             /-TLNORM CALL GETS LINEUP FROM SURF TO TOOL IN U1 DIREC. */
L2712:

/* .... VW MODIFICATION FOR SITUATION WHEN DISTANCE BETWEEN TOOL */
/*     AND SURFACE IS LARGE - ONLY APPLIES TO DS AND PS */

    if (ifxcor_1.is < ifxcor_1.ics) {
	if (isv_1.jent[ifxcor_1.is - 1] != 0) {
	    if (cstart_1.uvdist < .4 || cstart_1.dist < blongd) {
		cstart_1.istart = 0;
	    } else {
		cstart_1.istart = 1;
		for (i__ = 1; i__ <= 3; ++i__) {
		    sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = cstart_1.spbond[i__ 
			    - 1] - sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
		    sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = cstart_1.spbond[i__ 
			    - 1];
/* L27121: */
		}
		vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 
			3 - 3]);
		for (i__ = 1; i__ <= 3; ++i__) {
		    sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + 
			    ifxcor_1.is * 3 - 4];
/* L27123: */
		}
		if (sv_1.s[ifxcor_1.is - 1] > blongd) {
		    sv_1.s[ifxcor_1.is - 1] = blongd;
		}
		goto L711;
	    }
	}
    }
/*             /-GENERATE TP ON TOOL SURFACE CLOSE TO CC. */
    tlnorm_(&sv_1.u1[ifxcor_1.is * 3 - 3]);
/* -------------------------* TLNORM CALLS SURF FOR DIRECTED DIST *--- */
/*             /-PLACE TP OUT ON THICK ENVELOPE OFF TOOL SURF */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += sv_1.th[ifxcor_1.is - 1] * 
		sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L1163: */
    }
/* ***        TERMINATE ON FATAL ERROR */
    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
    if (*kdynfl != 0) {
	apt238_(&c__5);
    }
/*              /-DYNDMP(105) --------. */

/*             /-BRANCH TO SURFACE DISTANCE CALCULATION FROM HERE. */
    modess_1.modess = 14;
    if (modess_1.msschk == 0) {
	ajundd_();
    }
    modess_1.modess = 0;

/* ***        TERMINATE ON FATAL ERROR */
    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
    if (cstart_1.istart == 1) {
	goto L711;
    }
/*             /-CHECK LINEUP BETWEEN TN AND SN. */
    dotf_(&dshar4_1.flipck, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.sn[
	    ifxcor_1.is * 3 - 3]);
/*             /-SPECIAL ROUTE. IF FLIPCK WRONG SIGN AFTER 10 */
/*             /-ITERATIONS,REVERSE SIGN OF U1 */
    if (ishr18_1.iamdct <= 10) {
	goto L1123;
    }
    fxcor_1.tem[6] = isv_1.jtn[ifxcor_1.is - 1] - .5f;
    if (fxcor_1.tem[6] * dshar4_1.flipck < zero && map == 0) {
	goto L710;
    }
L1123:
    if (*kdynfl != 0) {
	apt238_(&c__6);
    }
/*              /-DYNDMP(106) --------. */
/*             /-FLIPCK TEST. IF TN.SN WELL ALIGNED EXIT FROM LOOP */
/*             /-FLIPCK SHOULD BE VERY NEAR 1 FOR CONVERGENCE */
    if (abs(dshar4_1.flipck) > zlit1) {
	goto L2041;
    }

/* --- WEAKER CONVERGENCE-TEST */

    if (abs(dshar4_1.flipck) <= zlit2 || abs(dshar4_1.flipck) <= flipab) {
	goto L29;
    }
    if (ishr18_1.mdic <= 0 && (isv_1.jtn[ifxcor_1.is - 1] - .5f) * 
	    dshar4_1.flipck < zero) {
	goto L29;
    }
    if (isv_1.ipl[ifxcor_1.is - 1] <= 0) {
	fxcor_1.temp[0] = sv_1.tau[ifxcor_1.is - 1] - sv_1.eps8[ifxcor_1.is - 
		1];
	if (sv_1.rc[ifxcor_1.is - 1] > zero && isv_1.jtn[ifxcor_1.is - 1] != 
		0) {
	    fxcor_1.temp[0] = sv_1.eps8[ifxcor_1.is - 1];
	}
	if (sv_1.rc[ifxcor_1.is - 1] <= zero && isv_1.jtn[ifxcor_1.is - 1] == 
		0) {
	    fxcor_1.temp[0] = sv_1.eps8[ifxcor_1.is - 1];
	}
	smod = sv_1.s[ifxcor_1.is - 1] - sv_1.tau2[ifxcor_1.is - 1] - 
		fxcor_1.temp[0];
    }
    if (flipab > zlit2 && abs(smod) > abs(smods)) {
	goto L29;
    }

/* --- STORE DATA, IF WEAKER CONVERGENCE-TEST IS OK */

    flipmx = dshar4_1.flipck;
    flipab = abs(dshar4_1.flipck);
    rcsav = sv_1.rc[ifxcor_1.is - 1];
    ssav = sv_1.s[ifxcor_1.is - 1];
    smods = smod;
    itsav = isv_1.itseg[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	tpsav[i__ - 1] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
	tnsav[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
	spsav[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
	snsav[i__ - 1] = sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
	u1sav[i__ - 1] = sv_1.u1[i__ + ifxcor_1.is * 3 - 4];
/* L2900: */
    }
/*             /-INCREMENT AMIND COUNT AND TRY AGAIN TO IMPROVE LINEUP */

L29:
    ++ishr18_1.iamdct;
    if (ishr18_1.iamdct < 25) {
	goto L32;
    }
    if (ishr18_1.iamdct > 25) {
	goto L1124;
    }
/*             /-IAMDCT IS 25, ONE LAST TRY WITH WEAKER CONVERGENCE TEST */
    if (flipab == zero) {
	goto L1124;
    }

    if (flipab > zlit5) {
    } else if (flipab > zlit2) {
/* ... PRINT WARNING */
	s_wsfi(&io___43);
	do_fio(&c__1, (char *)&flipab, (ftnlen)sizeof(doublereal));
	e_wsfi();
	outmsg_(msg, (ftnlen)70);
    } else {
	goto L1124;
    }

/* --- RESTORE DATA OF WEAKER CONVERGENCE-TEST */

    sv_1.rc[ifxcor_1.is - 1] = rcsav;
    sv_1.s[ifxcor_1.is - 1] = ssav;
    isv_1.itseg[ifxcor_1.is - 1] = itsav;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = tpsav[i__ - 1];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = tnsav[i__ - 1];
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = spsav[i__ - 1];
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = snsav[i__ - 1];
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = u1sav[i__ - 1];
/* L2910: */
    }
    goto L2041;
L1124:
/*             /-JMINR IS SET TO 1 IF NO AERR CALL SHOULD BE MADE, 0 OTHE */
/* ***        AMIND ITERATIONS FAILED TO CONVERGE AFTER ALL TRIES. */
    if (ishr18_1.jminr != 1) {
	aerr_(&c__26002, "AMIND   ", (ftnlen)8);
    }
/*             /-JMIN SET TO 1 FOR AMIND FAILURE, 0 OTHERWISE */
    ishr18_1.jmin = 1;
    goto L2999;
/* ------------------------------------------------------- */
/*             /-FLIPCK TEST FAILS. CALL CCURV, U1COMP, AND NEW */
/*             /-ITERATION. FUDGE ROUTE IF TA LL SURF LINE ELEMENT */
/*             /-AND IAFL NOT EQUAL TO 1 */
L32:
    if (ishr18_1.iamdct < 10) {
	goto L1126;
    }
/*             /-RC1 USED FOR PROPER UNITS/ IMPLEMENTATION */
    if ((d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) != fxcor_1.rc1 / 100.) {
	goto L1126;
    }
    dotf_(&w1, fxcor_1.ta, &sv_1.tn[ifxcor_1.is * 3 - 3]);
    dotf_(&fxcor_1.tem[6], fxcor_1.ta, &sv1_1.tnl[ifxcor_1.is * 3 - 3]);
    if (d_sign(&one, &w1) != d_sign(&one, &fxcor_1.tem[6])) {
	goto L1126;
    }
    d__1 = fxcor_1.rc1 * 1e5 / 4500.;
    fxcor_1.tem[6] = d_sign(&d__1, &sv_1.rc[ifxcor_1.is - 1]);
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.cc[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4] - fxcor_1.tem[6] * sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
/* L1127: */
    }
/*             /-RETURN TO TLNORM WITH NEW CC AIMING POINT. */
    goto L2038;

L1126:
    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spl[ifxcor_1.is 
	    * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    if (isv_1.itlon[ifxcor_1.is - 1] == 0) {
	goto L2038;
    }
    u1comp_();
/* ***        TERMINATE ON FATAL ERROR */
    if (ifxcor_1.iaerr != 0) {
	goto L2999;
    }
/*             /-JU1 LOGIC. USE IF U1.OLDU1 .LT. ZERO */
/*             /-JU1 SET TO 1 MEANS U1 SHOULD BE CHKED WITH OLDU1 */
    if (isv_1.ju1[ifxcor_1.is - 1] != 0) {
	goto L2038;
    }
    dotf_(fxcor_1.tem, oldu1, &sv_1.u1[ifxcor_1.is * 3 - 3]);
    if (fxcor_1.tem[0] >= zero) {
	goto L2038;
    }
/*             /-U1 AND OLDU1 CHANGED CUTTER SIDES */
    dotf_(fxcor_1.tem, &sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.snl[ifxcor_1.is * 
	    3 - 3]);
    if (fxcor_1.tem[0] >= z9em1) {
	goto L2038;
    }
    if (fxcor_1.tem[0] == zero) {
	goto L2038;
    }
/*             /-SURFACE NORMALS CHANGED SIGNIFICANTLY */
    if (chekfl_1.ichekf == 1) {
	goto L2038;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	oldu1[i__ - 1] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 4];
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += z2 * sv_1.th[ifxcor_1.is - 1] * 
		sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L1128: */
    }
/*             /-IOP SET TO 1 TO FIND SMALLEST POSITIVE DIRECTED DISTANCE */
    isv_1.iop[ifxcor_1.is - 1] = 1;
/*             /-BRANCH TO SURFACE DISTANCE CALCULATION FROM HERE. */
    modess_1.modess = 15;
    if (modess_1.msschk == 0) {
	ajundd_();
    }
    modess_1.modess = 0;

/*             /-RESET IOP TO FIND SMALLEST ABSOLUTE DISTANCE */
    isv_1.iop[ifxcor_1.is - 1] = 0;
    i__1 = islim;
    for (i__ = ifxcor_1.is; i__ <= i__1; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1129: */
    }
    sv_1.s[ifxcor_1.is - 1] = -sv_1.s[ifxcor_1.is - 1];
    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spl[ifxcor_1.is 
	    * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    goto L2038;

/*             /-IF RADAR USED,DO ANOTHER ITERATION (TE MAY BE OUT) */
L2041:
/*             /-MDIC, COUNT OF NUM OF RADAR TRIALS */
    if (ishr18_1.mdic <= 0) {
	goto L1130;
    }
/*             /-IF CUTTER NOT ON AND NOT A POINT, GO TO 29 */
    if (isv_1.itlon[ifxcor_1.is - 1] * ifxcor_1.ipt1 != 0) {
	goto L29;
    }
/*             /-TOOL-ON OR POINT TOOL CASE */
/*             /-EPS1 IS .1*TAU(INITIALLY .00005) */
    w1 = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1133: */
	w1 += (d__1 = sv_1.tp[i__ + ifxcor_1.is * 3 - 4] - fxcor_1.te[i__ - 1]
		, abs(d__1));
    }
    if (w1 > sv_1.eps1[ifxcor_1.is - 1]) {
	goto L29;
    }
/*             /-IFL1PCK WRONG SIGN, REVERSE U1. SET MAP=1. */
L1130:
    fxcor_1.tem[6] = isv_1.jtn[ifxcor_1.is - 1] - .5f;
    if (fxcor_1.tem[6] * dshar4_1.flipck >= zero) {
	goto L711;
    }
/* ***          ERROR IN AMIND - SET JMIN AND RETURN. */
    if (map > 0) {
	ishr18_1.jmin = 1;
    }
    if (map > 0) {
	goto L2999;
    }
L710:
    map = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
/* L1131: */
    }
/*             /-GO BACK AND FIND TOOL TO SURF RELATIONSHIP */
    goto L2712;

/*             /-MINIMUM DISTANCE S(IS)O.K.. ADJUST TO CORRECT PART */
/*             /-TOLERANCE BAND */
L711:
    ishr18_1.jmin = 0;
/*             /-IPL=1 FOR PLANE, 0 OTHERWISE */
    if (isv_1.ipl[ifxcor_1.is - 1] > 0) {
	goto L1132;
    }
/*             /-TAU = TOTAL TOLERANCE TAU1-TAU2 */
/*             /-EPS8 =EPS1 OR 2*EPS1 WHERE EPS1=.1*TAU */
/*             /-PLACE CUTTER WITHIN 10PC OF TOLERANCE BAND OF LEAST CURV */
    fxcor_1.temp[0] = sv_1.tau[ifxcor_1.is - 1] - sv_1.eps8[ifxcor_1.is - 1];
    if (sv_1.rc[ifxcor_1.is - 1] > zero && isv_1.jtn[ifxcor_1.is - 1] != 0) {
	fxcor_1.temp[0] = sv_1.eps8[ifxcor_1.is - 1];
    }
    if (sv_1.rc[ifxcor_1.is - 1] <= zero && isv_1.jtn[ifxcor_1.is - 1] == 0) {
	fxcor_1.temp[0] = sv_1.eps8[ifxcor_1.is - 1];
    }
/*             /-TAU2 IS NEGATIVE AND IS INNER TOLERANCE(AWAY FROM CUTTER */
    sv_1.s[ifxcor_1.is - 1] = sv_1.s[ifxcor_1.is - 1] - sv_1.tau2[ifxcor_1.is 
	    - 1] - fxcor_1.temp[0];

/*             /-UPDATE SPK,TPK,SNK ETC. JENT = 0. COMPUTE VT */
/*             /-********* EXIT  ROUTE **********. */
L1132:
    if (isv_1.jent[ifxcor_1.is - 1] == 0) {
	goto L2046;
    }

/*             /-FOR FIRST ENTRY SAVE LAST GOOD VALUES */
L2044:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tpk[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.spk[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.u1k[i__ + ifxcor_1.is * 3 - 4] = sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.snk[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1134: */
    }
    if (cstart_1.istart == 0) {
	isv_1.jent[ifxcor_1.is - 1] = 0;
    }
/*             /-SET ENTRY FLAG TO ZERO, INITIAL ENTRY FINISHED */
    isv_1.jent[ifxcor_1.is - 1] = 0;
/*             /-SAVE INDEX TO PERTINENT TOOL SEGMENT */
    isv_1.itsegk[ifxcor_1.is - 1] = isv_1.itseg[ifxcor_1.is - 1];

L2046:
    modess_1.msschk = 0;
/*             /-SAVE DISPLACEMENT VECTOR FROM TE TO CONTACT PT */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.vt[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4] - sv_1.th[ifxcor_1.is - 1] * sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4] - fxcor_1.te[i__ - 1];
/* L1135: */
    }
    if (*kdynfl != 0) {
	apt238_(&c__7);
    }
/*              /-DYNDMP(107) --------. */
/* ***       ERROR EXIT PATH AND END OF NORMAL EXIT */
L2999:
    isv_1.itlon[ifxcor_1.is - 1] = itlon1;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1136: */
	fxcor_1.te[i__ - 1] = te1[i__ - 1];
    }
    return 0;


/*     -------------------------------------------------* */
/*             /-IAFL(IS)=0 SPECIAL ANALYTIC ROUTE. INITIAL ENTRY. */
/*             /-SURF IS PLANE PERPEN TO TA OR PLANE PARL TO DS,CS */
/*             /-CANON(IC+0,+1,+2)=I,J,K NORMAL, AND CN(IC+3)=ORIGIN DIST */
L202:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1150: */
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = canon[icbot + i__ - 1];
    }
    ajent = (doublereal) isv_1.jent[ifxcor_1.is - 1];
    dotf_(fxcor_1.tem, &sv_1.tp[ifxcor_1.is * 3 - 3], &canon[ifxcor_1.ic - 1])
	    ;
    sv_1.save[ifxcor_1.is - 1] = one;
    if (isv_1.jent[ifxcor_1.is - 1] == 0) {
	goto L204;
    }
/*             /-CHANGE SIGN OF PLANE NORMAL IF TP IS ON OPPOSITE SIDE */
    if (sv_1.past[ifxcor_1.is - 1] * (canon[ifxcor_1.ic + 2] - fxcor_1.tem[0])
	     >= zero) {
	goto L204;
    }
    sv_1.save[ifxcor_1.is - 1] = -one;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1154: */
    }
L204:
    if (isv_1.itlon[ifxcor_1.is - 1] != 0) {
	goto L327;
    }
/*             /-USE TE FOR TP IF TOOL IS ON SURF */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1151: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1];
    }
    goto L305;
L327:
/*             /-COMPUTE A NEW TOOL POINT */
    if (ifxcor_1.is != ifxcor_1.ips) {
	goto L303;
    }
    w1 = fxcor_1.cutdat[6] / 2.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += w1 * sv_1.tn[i__ + ifxcor_1.is *
		 3 - 4];
/* L1152: */
    }
    goto L305;
L303:
/*             /-SET TP AT TOP PERIPHERY OF TOOL FOR DS,CS */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		sv_1.toolht[i__ + ifxcor_1.is * 3 - 4] + sv_1.toolwd[
		ifxcor_1.is - 1] * sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L1153: */
    }
/*             /-FIND SIGNED NORMAL DISTANCE OF TP FROM PLANE USING SAVE. */
L305:
    dotf_(fxcor_1.tem, &sv_1.tp[ifxcor_1.is * 3 - 3], &canon[ifxcor_1.ic - 1])
	    ;
    sv_1.s[ifxcor_1.is - 1] = sv_1.save[ifxcor_1.is - 1] * (canon[ifxcor_1.ic 
	    + 2] - fxcor_1.tem[0]);
/*             /-COMPUTE SN,S AND MAYBE U1 */
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L208;
    }
    sv_1.z__[ifxcor_1.is - 1] = sv_1.save[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1155: */
    }
    goto L209;
L208:
    sv_1.z__[ifxcor_1.is - 1] = -sv_1.save[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1156: */
    }
L209:
    sv_1.rc[ifxcor_1.is - 1] = fxcor_1.rc1;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.snl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L1157: */
    }
    isv_1.isigcr[ifxcor_1.is - 1] = -1;
/*             /-COMPENSATE DISTANCE S BY THICK PARAMETER */
    sv_1.s[ifxcor_1.is - 1] -= sv_1.th[ifxcor_1.is - 1];
/*             /-TOOL POINT IS PLACED OUT ON THICK ENVELOPE ARND TOOL */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += sv_1.th[ifxcor_1.is - 1] * 
		sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L1158: */
    }

L213:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4];
	sv_1.cc[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4] - sv_1.rc[ifxcor_1.is - 1] * sv_1.sn[i__ + ifxcor_1.is * 3 
		- 4];
/* L1161: */
    }
/*             /-RETURN WITH MINOR HOUSEKEEPING */
    if (isv_1.jent[ifxcor_1.is - 1] == 0) {
	goto L2046;
    }
/*             /-SAVE SPL FOR THE INTITIAL ENTRY ONLY */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4];
/* L1159: */
    }
/*             /-RETURN WITH HOUSEKEEPING - SAVE LAST VALUES(SPK,TPK,..) */
    goto L2044;

/* ------------------------------------------------------- */
/*             /-IAFL(IS)=0 SPECIAL ANALYTIC ROUTE. NORMAL ENTRY. */
L212:
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L307;
    }
/*             /-TOOL NORMAL CONTROL, GENERATE TP,TN. */
    dotf_(fxcor_1.tem, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.u1[ifxcor_1.is * 
	    3 - 3]);
    if (fxcor_1.tem[0] < zero) {
	goto L309;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + sv_1.vt[
		i__ + ifxcor_1.is * 3 - 4] + sv_1.th[ifxcor_1.is - 1] * 
		sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L310: */
    }
    goto L307;

L309:
    sv_1.z__[ifxcor_1.is - 1] = -sv_1.z__[ifxcor_1.is - 1];
    sv_1.save[ifxcor_1.is - 1] = -sv_1.save[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.snl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		sv_1.toolht[i__ + ifxcor_1.is * 3 - 4] + (sv_1.th[ifxcor_1.is 
		- 1] + sv_1.toolwd[ifxcor_1.is - 1]) * sv_1.tn[i__ + 
		ifxcor_1.is * 3 - 4];
/* L311: */
    }

L307:
    dotf_(fxcor_1.tem, &sv_1.tp[ifxcor_1.is * 3 - 3], &canon[ifxcor_1.ic - 1])
	    ;
    sv_1.s[ifxcor_1.is - 1] = sv_1.save[ifxcor_1.is - 1] * (canon[ifxcor_1.ic 
	    + 2] - fxcor_1.tem[0]);
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4];
/* L312: */
    }
/*             /-FINISH UP WITH SP,CC AND RETURN WITH HOUSEKEEPING */
    goto L213;

} /* amind_ */

#undef kdynfl
#undef clngth
#undef ibtflg
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef sinl
#undef cosl
#undef jlin
#undef can


