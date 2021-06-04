/* RADAR.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__26803 = 26803;
static integer c__26802 = 26802;

/* *** SOURCE FILE : M0002894.V04   *** */

/* .....FORTRAN SUBROUTINE           RADAR           AR       5/1/68 */
/* Subroutine */ int radar_(void)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal zlit1 = .8;
    static doublereal radang[5] = { .5255,.1309,1.0472,1.5707,.7854 };
    static integer kn = 9;
    static doublereal zero = 0.;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal w1;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal crdr[3];
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal axis1[3], axis2[3], axis3[3];
    static integer jmdic;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), cross_(
	    doublereal *, doublereal *, doublereal *);
    static integer iswiv;
    static doublereal aswiv;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddplan_(doublereal *), ddquad_(doublereal *), 
	    ddcyln_(doublereal *);
    static integer ilayer, istsav;



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





/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/* C                 30 DEGS   7.5       60       90         45 DEGS */


/*              /-PURPOSE OF RADAR IS TO MAKE ADDITIONAL TP,TN TO PIERCE */
/*              /-SURFACE AFTER ONE CANDIDATE TP,TN FAILED. */
L100:
/*              /-MDIC IS THE COUNT OF RADAR TRIES WITHOUT SUCCESS */
    ++ishr18_1.mdic;
    if (ishr18_1.mdic == kn) {
	goto L130;
    }
    if (ishr18_1.mdic > kn) {
	goto L200;
    }
/*             /-MDIC IS LES THAN KN, PRELIMINARY RESTART ATTEMPTS. */
/*              /-FIRST ATTEMPT IS TO MOVE TP TOWARD LAST GOOD SP */
/*              /-IF JENT IS 1 AND IAMDCT 0 NO SP IS AVAILABLE */
    if (ishr18_1.iamdct < isv_1.jent[ifxcor_1.is - 1]) {
	goto L130;
    }
/*              /-TP LIES ONE HALF OF THE WAY BETWEEN TP AND SP */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += (sv_1.sp[i__ + ifxcor_1.is * 3 
		- 4] - sv_1.tp[i__ + ifxcor_1.is * 3 - 4]) * .6f;
/* L125: */
    }
    goto L999;

/*              /-CONSTRUCT SURFACE NORMAL THRU EXT TP POINT AND USE THIS */
/*              /-NORMAL FOR A NEW TN IF POSSIBLE */
L130:
    ishr18_1.mdic = kn;
    if (isv_1.iunfl[ifxcor_1.is - 1] <= 0) {
	goto L100;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4];
/* L134: */
    }
/*              /-CALL DIRECTED DISTANCE ROUTINE FOR SURF WITH UNIT NORMA */
/*              /- THRU EXTERIOR POINT CAPABILITY */
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.is - 1];
    ifxcor_1.jsw = isv_1.isfidn[ifxcor_1.is - 1];
    istsav = ifxcor_1.istrup;
/*             /-SET ISTRUP TO 5 FOR SPECIAL CALCULATION IN DD ROUTINES */
    ifxcor_1.istrup = 5;
    switch (ifxcor_1.jsw) {
	case 1:  goto L1;
	case 2:  goto L1;
	case 3:  goto L3;
	case 4:  goto L3;
	case 5:  goto L6;
	case 6:  goto L6;
	case 7:  goto L6;
	case 8:  goto L6;
	case 9:  goto L6;
	case 10:  goto L6;
	case 11:  goto L139;
	case 12:  goto L139;
	case 13:  goto L139;
	case 14:  goto L6;
	case 15:  goto L139;
    }

L139:
    ifxcor_1.istrup = istsav;
    if (ifxcor_1.ier > 0) {
	goto L100;
    }
/*              /-USE SN FOR NEW TN */
    w1 = one;
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	w1 = -one;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = w1 * sv_1.sn[i__ + ifxcor_1.is * 
		3 - 4];
/* L140: */
    }
    goto L999;

L1:
    ddplan_(&canon[ifxcor_1.ic - 1]);
    goto L139;
L3:
    ddcyln_(&canon[ifxcor_1.ic - 1]);
    goto L139;
L6:
    ddquad_(&canon[ifxcor_1.ic - 1]);
    goto L139;

/*              /-SEARCH PATTERN - SEND TOOL RAYS IN CONICAL LAYERS */
/*              /-AROUND LAST GOOD TN. */
L200:
    if (ishr18_1.mdic <= kn + 28) {
	goto L210;
    }
/*              /-RADAR FAILED IN KN+28 TRIES SO TERMINATE */
    aerr_(&c__26803, "RADAR   ", (ftnlen)8);
    goto L999;

L210:
    jmdic = ishr18_1.mdic - kn;
    if (jmdic != 1) {
	goto L220;
    }
/*              /-SET UP BASE SYSTEM OF ORTHONORMAL VECTORS */
/*              /-FIRST DETERMINE IF TN CAN BE USED */
    vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.ier <= 0) {
	goto L230;
    }
/*              /-NO GOOD TOOL NORMAL, RADAR TERMINATES */
    aerr_(&c__26802, "RADAR   ", (ftnlen)8);
    goto L999;

L230:
/*              /-CONSTRUCT COORDINATE SYSTEM AROUND TN */
    for (i__ = 1; i__ <= 3; ++i__) {
	axis1[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L231: */
	axis2[i__ - 1] = zero;
    }
    w1 = abs(axis1[0]);
    if (w1 < zlit1) {
	axis2[0] = one;
    }
    if (w1 >= zlit1) {
	axis2[1] = one;
    }
    cross_(axis1, axis2, axis2);
    vnorm_(axis2, axis2);
    cross_(axis1, axis2, axis3);

L220:
/*              /-INDEX TO CONICAL ANGLE AROUND TN */
    ilayer = (jmdic - 1) / 8 + 1;
/*              /-DETERMINE MULTIPLE OF SWIVEL ANGLE WITHIN THIS CONE */
    iswiv = jmdic - (ilayer - 1 << 3) - 1;
    aswiv = iswiv * radang[4];
    crdr[0] = cos(radang[ilayer - 1]);
    w1 = sin(radang[ilayer - 1]);
    crdr[1] = cos(aswiv) * w1;
    crdr[2] = sin(aswiv) * w1;
/*              /-DETERMINE TN WITHIN CONICAL LAYER */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = crdr[0] * axis1[i__ - 1] + crdr[
		1] * axis2[i__ - 1] + crdr[2] * axis3[i__ - 1];
/* L240: */
    }

    vnorm_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.ier > 0) {
	goto L100;
    }

L999:
    return 0;
} /* radar_ */

#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


