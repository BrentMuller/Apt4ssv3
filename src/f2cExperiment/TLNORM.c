/* TLNORM.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer ichekf;
} chekfl_;

#define chekfl_1 chekfl_

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

/* Table of constant values */

static integer c__26601 = 26601;
static integer c_b63 = -26002;
static integer c__26602 = 26602;

/* *** SOURCE FILE : M0002898.W06   *** */

/* .....FORTRAN SUBROUTINE  ....TLNORM         8/68                 PH,HG */
/* ..... FORTRAN SUBROUTINE            TLNORM...              4/8/68   GK */
/* Subroutine */ int tlnorm_(doublereal *u1var)
{
    /* Initialized data */

    static doublereal z5em3 = .005;
    static doublereal z5em4 = 5e-4;
    static doublereal z700 = 700.;
    static doublereal z9999 = .9999;
    static doublereal z995 = .995;
    static doublereal zbig2 = 1e20;
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal zbig = 1e30;
    static doublereal z4 = 4.;
    static doublereal z3em4 = 3e-4;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal w1, w2;
    static integer ll, iw;
    static doublereal w11, am;
    static integer ibb;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nnn;
    static doublereal rrr, wfl1, wfl2;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), dotf_(
	    doublereal *, doublereal *, doublereal *);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer itry;
    extern /* Subroutine */ int ddst_(void);
    static integer jfind;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal tnold[3], tpold[3], snold[3], spold[3];
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), error_(
	    integer *, char *, ftnlen), ccurv_(integer *, doublereal *, 
	    doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ajundd_(void);
    static doublereal tpspdf[3];






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





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/* ---- FLAG INTRODUCED BY VW - USED TO DETERMINE 'CORRECT' SIDE OF CUTTER */





    /* Parameter adjustments */
    --u1var;

    /* Function Body */

/* ----------------------------------------------------------- */
/*             /-JFIND IS -1 WHEN AT LEAST ONE TOOL SEG HAS LINED UP */
/*             /-WITH THE CENTER OF CURVATURE */
/*             /-IBB=-1 FOR 1ST PASS THRU TLNORM, =0 ON SECOND PASS */
    jfind = 1;
    ibb = -1;
L805:
/*              /-IT IS TOOL SEGMENT INDEX  =1 AT TIP,2,3,4 ETC */
/*              /-IT=7 IS LAST SEGMENT, =8 IS DISC. IBEGIN IS FIRST */
/*              /-SIGNIFICANT TOOL SEGMENT. */
    ifxcor_1.it = ifxcor_1.ibegin;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L12: */
	dshar4_1.uvec[i__ - 1] = u1var[i__];
    }

    if (modess_1.msschk == 1) {
	goto L3029;
    }
/* ----------------------------------------------------------- */
/*              /-TEST FOR ROUTE */

/*              /-ITLON IS 0 IF TOOL ON SURF, 1 OTHERWISE */
    if (isv_1.itlon[ifxcor_1.is - 1] == 0) {
	goto L1;
    }
/*              /-IAFL=-1, GENERAL SURF, 0 PLANE PERP TO TA, 1 CYL LL TA */
/*              /-JTLFLG=0 FOR NORMAL CUTTER, =1 FOR DISC TYPE. */

    iw = isv_1.iafl[ifxcor_1.is - 1] + isv_1.jtlflg[ifxcor_1.is - 1];
/*              /-IAFL,JTLFLG = 0,1,  1,1,  OR 1,0 */
    if (iw > 0) {
	goto L401;
    }
/*              /-IAFL,JTLFLG = -1,1, 0,0 */
    if (iw == 0) {
	goto L404;
    }
/*              /-IAFL=-1,JTLFLG=0 */
    if (ifxcor_1.ipt1 != 0) {
	goto L84;
    }
    goto L1;

/*              /-TA LL TO SURFACE ELEMENT */

L401:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		sv_1.toolwd[ifxcor_1.is - 1] * dshar4_1.uvec[i__ - 1] + 
		sv_1.toolht[i__ + ifxcor_1.is * 3 - 4];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = dshar4_1.uvec[i__ - 1];
/* L402: */
    }
/*              /-TP,TN FOUND, RETURN TO CALLING PROGRAM */
    goto L9999;
/*              /-CASE OF POINT CUTTER */
L1:
/*              /-TEMP(1) IS +OR-1 TO SELECT CUTTER SIDE */
/*              /-TEMP(2) IS 0 OR 1 */
    fxcor_1.temp[1] = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L21: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1];
    }
    isv_1.itseg[ifxcor_1.is - 1] = 1;
    goto L408;

/* ----------------------------------------------------------- */

/*              /-TLON, POINT TOOL, 5-AXIS RING ROUTES */
L404:
    if (tlldat_1.ri[7] == zero) {
	goto L406;
    }
    fxcor_1.temp[0] = -one;
    fxcor_1.temp[1] = one;
    goto L407;
L406:
    fxcor_1.temp[1] = zero;
L407:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L405: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		tlldat_1.tlhite[7] * fxcor_1.ta[i__ - 1] + fxcor_1.temp[0] * 
		tlldat_1.ri[7] * dshar4_1.uvec[i__ - 1];
    }
    isv_1.itseg[ifxcor_1.is - 1] = 8;
L408:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = sv_1.cc[i__ + ifxcor_1.is * 3 - 
		4] - sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
/* L2: */
    }
/*              /-LL MAY BE 3,4 OR 5 */
    ll = (integer) (fxcor_1.temp[0] * fxcor_1.temp[1] + z4);
    vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.ier == 0) {
	goto L8;
    }
/* **** ERROR EXIT, TN CANNOT BE FOUND */
L3:
    if (fxcor_1.temp[1] > zero) {
	goto L410;
    }
    aerr_(&c__26601, "TLNORM  ", (ftnlen)8);
    goto L9999;

L410:
    fxcor_1.temp[ll - 1] = -one;

L417:
    if (fxcor_1.temp[0] >= zero) {
	goto L418;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ + 4] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L503: */
	fxcor_1.temp[i__ + 7] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
    }
    fxcor_1.temp[0] = one;
    goto L407;

L418:
    if (fxcor_1.temp[4] >= fxcor_1.temp[2]) {
	goto L505;
    }
/*              /-TEMP(5) IS LT TEMP(3) */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.temp[i__ + 4];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.temp[i__ + 7];
/* L506: */
    }
L505:
/*              /-JTLFLG NE 1 MEANS IGNORE DISC CUTTER */
    if (isv_1.jtlflg[ifxcor_1.is - 1] != 1) {
	goto L9999;
    }
    if (isv_1.ipl[ifxcor_1.is - 1] != 1) {
	goto L9999;
    }
/*              /-PLANAR SURFACE CASE */
    dotf_(&w1, fxcor_1.ta, &sv_1.sn[ifxcor_1.is * 3 - 3]);
    if (abs(w1) < z995) {
	goto L9999;
    }
/*              /-SN AND TA ARE CLOSE, LOOK FURTHER */
    if (isv_1.jtn[ifxcor_1.is - 1] > 0) {
	goto L9999;
    }
/*              /-SURFACE IS DS OR PS, CONTINUE */
    goto L413;

L8:
    if (fxcor_1.temp[1] > zero) {
	goto L412;
    }
/*              /-TEMP(2) IS LE ZERO */
    if (isv_1.jtn[ifxcor_1.is - 1] > 0) {
	goto L414;
    }
L413:
/*              /-JTN(IS) IS ZERO, NORMAL PS OR DS SURFACE */
    dotf_(&w1, &sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
/*              /- WHEN TN AND SN ARE OPPOSED, FINISH */
    if (w1 <= zero) {
	goto L9999;
    }
/*              /-ELSE CHECK FURTHER */
    goto L340;
L414:
/*              /-JTN NOT ZERO, CHECK SURFACE, TN CONTROL */
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv1_1.tnl[ifxcor_1.is * 3 - 3])
	    ;
/*              /-LAST TWO TNS ALIGNED, THEN QUIT */
    if (w1 > zero) {
	goto L9999;
    }
    if (w1 < zero) {
	goto L340;
    }
/*              /-CHECK FURTHER IF TN PERPEN TO TNL */
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    if (w1 >= zero) {
	goto L9999;
    }
L340:
/*              /-REVERSE TN AND THEN TERMINATE */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L341: */
    }
    goto L9999;

L412:
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], dshar4_1.uvec);
    if (fxcor_1.temp[0] * w1 >= zero) {
	goto L502;
    }
/*              /-REVERSE TN */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L501: */
    }
L502:
    if (isv_1.jtn[ifxcor_1.is - 1] <= 0) {
	dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 
		3]);
    }
    if (isv_1.jtn[ifxcor_1.is - 1] <= 0) {
	fxcor_1.temp[ll - 1] = -w1;
    }
    if (isv_1.jtn[ifxcor_1.is - 1] > 0) {
	dotf_(&fxcor_1.temp[ll - 1], &sv_1.tn[ifxcor_1.is * 3 - 3], &
		sv1_1.tnl[ifxcor_1.is * 3 - 3]);
    }
    goto L417;
/* ----------------------------------------------------------- */

/*              /-START NORMAL ROUTE. SPECIAL PATH FOR END TOOL */

L84:
    tlldat_1.tcont[8] = -one;
    nnn = 1;
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	ifxcor_1.it = isv_1.itseg[ifxcor_1.is - 1];
    }
/* .... CONSIDER PRECEDING AS WELL AS CURRENT AND FOLLOWING TOOL SEGMENTS */
    if (ifxcor_1.it >= 4) {
	ifxcor_1.it += -2;
    }
    dshar4_1.cendis = zbig;
    wfl1 = zero;
    ifxcor_1.it -= nnn;

/*              /-INCREMENT TOOL SEGMENT, TRY AGAIN */
L2000:
    ifxcor_1.it += nnn;
/*              /-TCONT=0 MEANS SEGMENT INSIGNIFICANT */
    if (tlldat_1.tcont[ifxcor_1.it] == zero) {
	goto L2000;
    }
/*              /-TCONT=-1 MEANS ALL SEGS OF TOOL DONE, SELECT TN. */
    if (tlldat_1.tcont[ifxcor_1.it] >= zero) {
	goto L700;
    }

/*              /-END OF TOOL.  ONLY ONE POSSIBLE TN. */

    if (jfind <= 0) {
	goto L9999;
    }
    fxcor_1.temp[0] = (doublereal) ((isv_1.jtn[ifxcor_1.is - 1] << 1) - 1);
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.temp[0] * sv_1.sn[i__ + 
		ifxcor_1.is * 3 - 4];
/* L8223: */
    }
    dotf_(&dshar4_1.com1, fxcor_1.ta, &sv_1.tn[ifxcor_1.is * 3 - 3]);
    dshar4_1.com1 = -dshar4_1.com1;
/* Computing 2nd power */
    d__1 = dshar4_1.com1;
    dshar4_1.com4 = sqrt(one - d__1 * d__1);
    if (dshar4_1.com4 <= znumbr_1.z1em3 && dshar4_1.com1 >= zero) {
	goto L605;
    }
    if (dshar4_1.com4 < znumbr_1.z1em3 && dshar4_1.com1 < zero) {
	goto L604;
    }
    dshar4_1.tangl = dshar4_1.com1 / dshar4_1.com4;
    ifxcor_1.it = ifxcor_1.ibegin;
L704:
/*              /-TCONT LT ZERO MEANS THIS IS LAST TOOL SEGMENT */
    if (tlldat_1.tcont[ifxcor_1.it] < zero) {
	goto L3;
    }
/*              /-TCONT GT ZERO MEANS THIS IS ORDINARY TOOL SEGMENT */
    if (tlldat_1.tcont[ifxcor_1.it] > zero) {
	goto L706;
    }
/*              /-TCONT EQ ZERO MEANS INSIGNIFICANT TOOL SEGMENT */
L705:
    ++ifxcor_1.it;
    goto L704;
L706:
    if (tlldat_1.tlinc[ifxcor_1.it] != zero) {
	goto L705;
    }
    if (dshar4_1.tangl < tlldat_1.tanhi[ifxcor_1.it - 1]) {
	goto L705;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L709: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		tlldat_1.tlhite[ifxcor_1.it - 1] * fxcor_1.ta[i__ - 1] + 
		tlldat_1.ri[ifxcor_1.it - 1] * dshar4_1.uvec[i__ - 1] + 
		tlldat_1.corrad[ifxcor_1.it - 1] * sv_1.tn[i__ + ifxcor_1.is *
		 3 - 4];
    }
    goto L9999;

L700:
/*              /-CONTINUE SEARCH */
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.refpnt[i__ - 1] = fxcor_1.te[i__ - 1] + tlldat_1.ri[
		ifxcor_1.it - 1] * dshar4_1.uvec[i__ - 1] + tlldat_1.tlhite[
		ifxcor_1.it - 1] * fxcor_1.ta[i__ - 1];
	dshar4_1.ogle[i__ - 1] = sv_1.cc[i__ + ifxcor_1.is * 3 - 4] - 
		dshar4_1.refpnt[i__ - 1];
/* L15: */
    }
    vnorm_(dshar4_1.ogle, dshar4_1.u2);
/*              /-IF OGLE, CANDIDATE TN, IS SMALL, TRY NXT SEG */
    if (ifxcor_1.ier > 0) {
	goto L2000;
    }
/*              /-IF SURFACE IS PLANAR, USE NORMAL RATHER THAN CC */
    if (isv_1.ipl[ifxcor_1.is - 1] < 1) {
	goto L155;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.ogle[i__ - 1] = -sv_1.rc[ifxcor_1.is - 1] * sv_1.sn[i__ + 
		ifxcor_1.is * 3 - 4];
	dshar4_1.u2[i__ - 1] = -d_sign(&one, &sv_1.rc[ifxcor_1.is - 1]) * 
		sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
/* L153: */
    }

L155:
    if (tlldat_1.tlinc[ifxcor_1.it] == zero) {
	goto L16;
    }
    tlldat_1.corrad[ifxcor_1.it - 1] = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.u2[i__ - 1] = cosl[ifxcor_1.it - 1] * dshar4_1.uvec[i__ - 1] 
		+ sinl[ifxcor_1.it - 1] * fxcor_1.ta[i__ - 1];
/* L41: */
	tlldat_1.corrad[ifxcor_1.it - 1] += dshar4_1.ogle[i__ - 1] * 
		dshar4_1.u2[i__ - 1];
    }
/*              /-IF CORNER RADIUS IS SMALL, GO TO NEXT SEG */
    if (tlldat_1.corrad[ifxcor_1.it - 1] < -z3em4) {
	goto L2000;
    }
/*              /-OTHERWISE, GO TO PLANE CALC */
/*              /-IF SURF IS A PLANE, TN MUST BE LL TO TOOL SEG */
/* L43: */
    if (isv_1.ipl[ifxcor_1.is - 1] <= 0) {
	goto L643;
    }
    if (tlldat_1.corrad[ifxcor_1.it - 1] >= z5em3) {
	goto L2000;
    }
    tlldat_1.corrad[ifxcor_1.it - 1] = zero;
    goto L44;
L643:
    if (tlldat_1.corrad[ifxcor_1.it - 1] >= tlldat_1.umax[ifxcor_1.it - 1] + 
	    z5em4) {
	goto L2000;
    }
L44:
/*              /-COSL IS HORIZONTAL AND SINL VERTICAL COMP OF LINEAR SEG */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L45: */
	dshar4_1.zlnorm[i__ - 1] = sinl[ifxcor_1.it - 1] * dshar4_1.uvec[i__ 
		- 1] - cosl[ifxcor_1.it - 1] * fxcor_1.ta[i__ - 1];
    }
    goto L31;

L16:
    dotf_(&dshar4_1.com1, dshar4_1.ogle, fxcor_1.ta);
    dotf_(&dshar4_1.com4, dshar4_1.ogle, dshar4_1.ogle);
/* Computing 2nd power */
    d__1 = dshar4_1.com1;
    dshar4_1.com4 -= d__1 * d__1;
    fxcor_1.temp[0] = one;
    if (ifxcor_1.it == 7) {
	fxcor_1.temp[0] = -one;
    }
    dshar4_1.tangl = fxcor_1.temp[0] * zbig;
    if (dshar4_1.com4 > zero) {
	goto L19;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L50: */
	dshar4_1.u2[i__ - 1] = -fxcor_1.temp[0] * fxcor_1.ta[i__ - 1];
    }
    itry = 1;
    goto L25;

L19:
    dshar4_1.com4 = sqrt(dshar4_1.com4);
    dshar4_1.tangl = -zbig;
    if (dshar4_1.com1 < z700 * dshar4_1.com4) {
	dshar4_1.tangl = -dshar4_1.com1 / dshar4_1.com4;
    }
    dotf_(&w1, dshar4_1.uvec, dshar4_1.ogle);
    itry = 0;
L1900:
    if (w1 >= zero) {
	goto L25;
    }
/*              /-REVERSE SIDE OF CUTTER */
    dshar4_1.tangl = -dshar4_1.tangl;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L24: */
	dshar4_1.u2[i__ - 1] = -dshar4_1.u2[i__ - 1];
    }
/* ----------------------------------------------------------- */
/*              /-RESUME NORMAL PATH. COMPUTE ZLPNT,ZLNORM */

L25:
/*              /- TANHI.LT.TANGL.LT.TANLO IS CRITERIA FOR VALID TN */
    if (tlldat_1.tanlo[ifxcor_1.it - 1] >= dshar4_1.tangl && tlldat_1.tanhi[
	    ifxcor_1.it - 1] <= dshar4_1.tangl) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    dshar4_1.zlnorm[i__ - 1] = dshar4_1.u2[i__ - 1];
/* L30: */
	}
    } else {
	if (tlldat_1.tanlo[ifxcor_1.it - 1] < dshar4_1.tangl) {
/*              /-TN CONTROL, SEARCH BACKWARDS ON TOOL */
	    if (isv_1.jtn[ifxcor_1.is - 1] != 0) {
		nnn = -1;
	    }
	}

	if (itry == 1) {
	    goto L2000;
	}
	if (chekfl_1.ichekf != 1 && abs(w1) > .05) {
	    goto L2000;
	}
	if (abs(w1) > 10.) {
	    goto L2000;
	}
	itry = 1;
	w1 = -w1;
	goto L1900;
    }

L31:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L32: */
	dshar4_1.zlpnt[i__ - 1] = dshar4_1.refpnt[i__ - 1] + tlldat_1.corrad[
		ifxcor_1.it - 1] * dshar4_1.u2[i__ - 1];
    }
    if (isv_1.jtn[ifxcor_1.is - 1] <= 0) {
	goto L237;
    }


/*              /-NORMAL PATH. TN CONTROL */

    dotf_(&w1, &sv1_1.tnl[ifxcor_1.is * 3 - 3], dshar4_1.zlnorm);
/*             /-TN.TNL POSITIVE, ACCEPT CURRENT TP,TN - RETURN */
    if (w1 >= zero) {
	goto L9998;
    }
    if (ibb < 0) {
	w11 = w1;
    } else {
	if (w11 > w1) {
	    goto L8021;
	} else {
	    if (w1 > -.08) {
		error_(&c_b63, "TLNORM", (ftnlen)6);
		goto L9998;
	    }
	}
    }
    dotf_(&am, dshar4_1.zlnorm, fxcor_1.ta);
    if (abs(am) <= z9999) {
	goto L802;
    }
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L603;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L601: */
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -dshar4_1.zlnorm[i__ - 1];
    }
    if (am > zero) {
	goto L605;
    }
/*              /-AM IS LE ZERO */
    goto L604;

L802:
/*             /-IBB =0 MEANS 2ND TIME THRU TLNORM, SO FAIL HERE. */
    if (ibb >= 0) {
	goto L804;
    }
/*             /-RESTART MODE, SWITCH TO OTHER SIDE CUTTER, THEN RESTART */
L8021:
    ibb = 0;
    isv_1.itseg[ifxcor_1.is - 1] = ifxcor_1.ibegin;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L803: */
	u1var[i__] = -u1var[i__];
    }
/*             /-BRANCH BACK TO START OF TLNORM, BEGIN AGAIN */
    goto L805;
L804:
/* ***** */
    aerr_(&c__26602, "TLNORM  ", (ftnlen)8);
L603:
/*             /-SET REFERENCE TP AT TOP OF TOOL */
    if (ifxcor_1.it == 7) {
	goto L605;
    }
L604:
    ifxcor_1.it = 7;
    isv_1.itseg[ifxcor_1.is - 1] = 7;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L3604: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + 
		tlldat_1.tlhite[ifxcor_1.it - 1] * fxcor_1.ta[i__ - 1] + 
		tlldat_1.ri[ifxcor_1.it - 1] * sv_1.u1[i__ + ifxcor_1.is * 3 
		- 4];
    }
    goto L9999;

L605:
    isv_1.itseg[ifxcor_1.is - 1] = ifxcor_1.ibegin;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L3603: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1];
    }
    goto L9999;
/*              /-SELECT CORRECT TN FROM MULTIPLE TN'S. */
/*              /-TEMPORARILY REPLACE TP,TN WITH NEW TP,TN CANDIDATE */
L237:
    for (i__ = 1; i__ <= 3; ++i__) {
	snold[i__ - 1] = sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
	spold[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
	tnold[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
	tpold[i__ - 1] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = dshar4_1.zlnorm[i__ - 1];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = dshar4_1.zlpnt[i__ - 1];
/* L34: */
    }
    if (ifxcor_1.is == 1) {
	goto L7003;
    }
    if (isv_1.isfidn[ifxcor_1.is - 1] == 29 || isv_1.isfidn[ifxcor_1.is - 1] 
	    == 30) {
	goto L7003;
    }
/*              /- */
    ddst_();
/*              /- */
    if (ifxcor_1.ier == 0) {
	goto L7004;
    }
L7003:
    sv_1.s[ifxcor_1.is - 1] = zbig2;
L7004:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = snold[i__ - 1];
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = spold[i__ - 1];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = tnold[i__ - 1];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = tpold[i__ - 1];
/* L4029: */
    }
    sv_1.s[ifxcor_1.is - 1] = (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1));

    if (dshar4_1.cendis < sv_1.s[ifxcor_1.is - 1]) {
	goto L2000;
    }
/* .... SELECT TN WHOS DIRECTION COINCIDES BEST WITH LAST SN */
/* .... IE. WHOSE ABS VALUE OF TN.SN IS MAXIMAL */
    dotf_(&wfl2, &sv_1.sn[ifxcor_1.is * 3 - 3], dshar4_1.zlnorm);
    if (abs(wfl2) <= abs(wfl1)) {
	goto L2000;
    }
    wfl1 = wfl2;
/*              /-NEW DISTANCE TO SURFACE LESS, SET JFIND TO SEARCH TOOL */
/*             /-SET JFIND TO -1 TO SHOW A VALID DIST HAS BEEN FOUND */
    jfind = -1;
    dshar4_1.cendis = sv_1.s[ifxcor_1.is - 1];

/*              /-UPDATE TP,TN AND EXIT IF JFIND =1. */
L9998:
    isv_1.itseg[ifxcor_1.is - 1] = ifxcor_1.it;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = dshar4_1.zlpnt[i__ - 1];
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = dshar4_1.zlnorm[i__ - 1];
/* L9222: */
    }
/*             /-JFIND -1, SO CONTINUE SEARCHING FOR BETTER TOOL SEG */
    if (jfind < 0) {
	goto L2000;
    }
/* **** */
L9999:
    return 0;
/* ************************************************************ */
/* ----------------------------------------------------------- */

L3029:
/* --------  SPECIAL TREATMENT OF A BALL CUTTER BY SSURF */
/*              /-RADIUS OF BALL EQUALS HALF DIAMETER OF TOOL */
    rrr = fxcor_1.cutdat[1];
/*              /-TOOL ON OR POINT TOOL MEANS RRR IS ZERO */
    if (isv_1.itlon[ifxcor_1.is - 1] * ifxcor_1.ipt1 == 0) {
	rrr = zero;
    }
/*              /-ISFTYP 1=TO, 2=PAST, 3=ON, 4=TANTO 8=PSTAN */
    if (isv_1.isftyp[ifxcor_1.is - 1] == 3) {
	rrr = zero;
    }
/*              /-GENERATE POINT AT CENTER OF BALL OR TIP OF TOOL */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + rrr * 
		fxcor_1.ta[i__ - 1];
/* L3030: */
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4];
    }
/*             /-BRANCH TO DD ROUTINE TO ESTABLISH TOOL/SURF RELATION */
    modess_1.modess = 21;
    ajundd_();
    modess_1.modess = 0;

/*             /-COMPUTE RELEVANT POINT ON TOOL SURFACE */
    w1 = one;
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	w1 = -w1;
    }
/*             /-MODIFY TN FOR TN CONTROL SO THAT TN.TI IS POSITIVE */
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L3032;
    }
/*             /-MEASURE THE ANGLE BETWEEN TN AND TI */
    dotf_(&w2, &sv_1.sn[ifxcor_1.is * 3 - 3], fxcor_1.ti);
    w2 = w2 * w1 * sv_1.past[ifxcor_1.is - 1];
    if (w2 >= zero) {
	goto L3032;
    }
/*             /-ALTER THE SIGN OF Z AND SN TO MAKE TN.TI.PAST POSITIVE */
    sv_1.z__[ifxcor_1.is - 1] = -sv_1.z__[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L3034: */
    }
L3032:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = w1 * sv_1.sn[i__ + ifxcor_1.is * 
		3 - 4];
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += rrr * sv_1.tn[i__ + ifxcor_1.is 
		* 3 - 4];
	tpspdf[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - (sv_1.tp[i__ + 
		ifxcor_1.is * 3 - 4] + sv_1.th[ifxcor_1.is - 1] * sv_1.tn[i__ 
		+ ifxcor_1.is * 3 - 4]);
/* L3033: */
    }
/*             /-DISTANCE MEASURED FROM RELEVANT TP TO SP IN TN DIRECTION */
    dotf_(&sv_1.s[ifxcor_1.is - 1], tpspdf, &sv_1.tn[ifxcor_1.is * 3 - 3]);
    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spl[ifxcor_1.is 
	    * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    isv_1.itseg[ifxcor_1.is - 1] = 4;
    if (abs(rrr) < z5em4) {
	isv_1.itseg[ifxcor_1.is - 1] = 1;
    }
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], fxcor_1.ta);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L3035: */
	u1var[i__] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4] - w1 * fxcor_1.ta[i__ 
		- 1];
    }
    vnorm_(&u1var[1], &u1var[1]);
    ifxcor_1.ier = 0;
    return 0;
} /* tlnorm_ */

#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


