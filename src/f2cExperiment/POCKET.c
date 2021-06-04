/* POCKET.f -- translated by f2c (version 20100827).
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
    doublereal ccentr[3], cend[3], cenlen, chord, costh, crdius, ctool, alpha,
	     dcentr[3], drdius, dinc, delmot[3], dnmot[3], dif, difout, dsmov,
	     d2[3], el1, el2, fipnt[3], hchord, hafdia, offset, psi, radno, 
	    rone, rzero[3], rzerol, sinth, stvec[3], tanmot[3], theta, zdotc, 
	    zign, zgamma, zpnts;
} dshar5_;

#define dshar5_1 dshar5_

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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c_n1 = -1;
static integer c__3506 = 3506;
static integer c__3501 = 3501;
static integer c__3502 = 3502;
static integer c__3507 = 3507;
static integer c__3504 = 3504;
static integer c__3503 = 3503;
static integer c__3510 = 3510;
static integer c__6 = 6;
static integer c__10 = 10;

/* *** SOURCE FILE : M0002779.V09   *** */



/* .....FORTRAN SUBROUTINE           POCKET        2/69      SR,RL */
/* Subroutine */ int pocket_(doublereal *radf, doublereal *ofsc, doublereal *
	ofsf, doublereal *frone, doublereal *frtwo, doublereal *frthre, 
	doublereal *ovrd, doublereal *ptyp, integer *ncor, doublereal *crr)
{
    /* Initialized data */

    static integer kcldat[10] = { 0,0,1308622848,0,1308622848,2,1308622848,1,
	    0,0 };
    static logical first = TRUE_;
    static doublereal z5em4 = 5e-4;
    static doublereal z5em3 = .005;
    static doublereal z1em4 = 1e-4;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_7[63], equiv_8[60], equiv_9[1], equiv_10[1];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
#define q (equiv_7)
    static doublereal t[3], u[63]	/* was [3][21] */;
#define w (equiv_8)
    static doublereal y[3], x1, xi[66]	/* was [3][22] */, bl[20];
#define qq (equiv_7)
#define ww (equiv_8)
    static doublereal wd[3];
    static integer nc, ir, nr, kt1, kt2;
    static logical sr1, sr2, sr3, sr4, sr5;
#define can ((doublereal *)&_BLNK__1 + 40)
#define srf ((doublereal *)&_BLNK__1)
    static doublereal cor[60]	/* was [3][20] */;
    static integer nwd, num;
    extern integer bcdf_(char *, ftnlen);
    static integer kalc, ktab[20];
    static doublereal rmda;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static integer kone;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer move, init;
    static doublereal dist;
    static integer ktwo;
    static doublereal dcov;
    extern /* Subroutine */ int apt299_();
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int aread_(integer *, integer *, doublereal *, 
	    integer *, integer *), atape_(void);
#define canon ((doublereal *)&_BLNK__1)
    static logical fpflg;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal ctemp[60]	/* was [3][20] */;
#define ifdrt ((integer *)equiv_10)
    static doublereal vprim[60]	/* was [3][20] */, uprim[60]	/* was [3][20]
	     */, ptint[3];
#define hfdrt (equiv_10)
    extern /* Subroutine */ int tapop_(integer *, integer *), error_(integer *
	    );
    static doublereal tempd, addem1;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);
    static doublereal addem2, dummy;
    static integer jsave, inter, itest;
    static doublereal cosva, rtest;
    static integer kover;
    static doublereal sin2va, sphio2;
    static integer nless1, nplus1;
    static doublereal radeff;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal xiprim[63]	/* was [3][21] */, crosto[3], tcrsto[
	    3], ucrsto[3];
#define ipockt ((integer *)equiv_9)
#define hpockt (equiv_9)
    static logical fptflg;
    static doublereal ofsetc, ofsetf, ovride, pttype;
    static integer ncorig;
    static doublereal cutrad, deldst;
    static integer ncutbk, icrsto;
    static doublereal ofcsto, offsto;
    static integer kutbac, kolaps;
    static doublereal phitmp;
    static integer jdummy;
    extern /* Subroutine */ int awrite_(integer *, integer *, doublereal *, 
	    integer *, integer *);
    static integer nwdmax;
    extern /* Subroutine */ int record_(integer *);
    static doublereal feedrt;
    extern /* Subroutine */ int ewrite_(integer *, integer *, integer *, 
	    integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  5.  DSHARE BLOCK 5  *** */





/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/* ...            SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...                SYSTEM I/O FILES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ...  DIMENSION FOR POCKET */
    /* Parameter adjustments */
    crr -= 4;

    /* Function Body */

    tapop_(&symfil_1.pofile, &c_n1);
    radeff = *radf;
    ofsetc = *ofsc;
    ofsetf = *ofsf;
    ovride = *ovrd;
    pttype = *ptyp;
    nc = *ncor;
    if (first) {
	kcldat[0] = bcdf_("CLDA", (ftnlen)4);
	kcldat[1] = bcdf_("TA  ", (ftnlen)4);
	kcldat[8] = bcdf_("GOTO", (ftnlen)4);
	kcldat[9] = bcdf_("    ", (ftnlen)4);
	ipockt[0] = bcdf_("POCK", (ftnlen)4);
	ipockt[1] = bcdf_("ET  ", (ftnlen)4);
	ifdrt[0] = bcdf_("FEDR", (ftnlen)4);
	ifdrt[1] = bcdf_("AT  ", (ftnlen)4);
	first = FALSE_;
    }
/* ...WRITE POCKET HEADER RECORD */
    apt299_(&knumbr_1.k0, hpockt, &knumbr_1.k0, &knumbr_1.k0);
    ncorig = nc;
    cutrad = fxcor_1.cutdat[0];
    sr1 = FALSE_;
    sr2 = FALSE_;
    sr3 = FALSE_;
    sr4 = FALSE_;
    sr5 = FALSE_;
    nwd = 1;
    i__1 = *ncor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ckdef_(&crr[i__ * 3 + 1])) {
	    goto L5;
	}
/* L4: */
    }
    goto L4002;
/*   AN INPUT POINT IS UNDEFINED */
L5:
    error_(&c__3506);
    goto L993;
L4002:
    if (pttype < 1.1f) {
	goto L4003;
    }
    pttype += -2.f;
    i__1 = *ncor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tempd = fxcor_1.ta[0] * srf[0] + fxcor_1.ta[1] * srf[1] + fxcor_1.ta[
		2] * srf[2];
	rmda = srf[3] - (crr[i__ * 3 + 1] * srf[0] + crr[i__ * 3 + 2] * srf[1]
		 + crr[i__ * 3 + 3] * srf[2]);
	if (abs(tempd) < z1em4) {
	    goto L50;
	}
	rmda /= tempd;
	cor[i__ * 3 - 3] = crr[i__ * 3 + 1] + rmda * fxcor_1.ta[0];
	cor[i__ * 3 - 2] = crr[i__ * 3 + 2] + rmda * fxcor_1.ta[1];
	cor[i__ * 3 - 1] = crr[i__ * 3 + 3] + rmda * fxcor_1.ta[2];
/* L4001: */
    }
    goto L6;
L4003:
    i__1 = *ncor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	cor[i__ * 3 - 3] = crr[i__ * 3 + 1];
	cor[i__ * 3 - 2] = crr[i__ * 3 + 2];
/* L4004: */
	cor[i__ * 3 - 1] = crr[i__ * 3 + 3];
    }
L6:
    if (radeff <= 0.) {
	goto L1903;
    } else {
	goto L2903;
    }
L1903:
    radeff = znumbr_1.z5em1 * ofsetc * cutrad;
L2903:
    kalc = knumbr_1.k0;
    move = knumbr_1.k1;
    init = knumbr_1.k1;
    deldst = znumbr_1.z0;
    goto L1904;
L904:
    nc = ncutbk;
    pttype = znumbr_1.z0;
L1904:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L905: */
	    xi[i__ + (j + 1) * 3 - 4] = cor[i__ + j * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	xi[i__ - 1] = cor[i__ + nc * 3 - 4];
/* L906: */
	xi[i__ + (nc + 2) * 3 - 4] = cor[i__ - 1];
    }
    nplus1 = nc + 1;
    nless1 = nc - 1;
    i__1 = nplus1;
    for (j = 1; j <= i__1; ++j) {
	addem1 = znumbr_1.z0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    q[i__ + j * 3 - 4] = xi[i__ + (j + 1) * 3 - 4] - xi[i__ + j * 3 - 
		    4];
/* L907: */
/* Computing 2nd power */
	    d__1 = q[i__ + j * 3 - 4];
	    addem1 = d__1 * d__1 + addem1;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* L908: */
	    u[i__ + j * 3 - 4] = q[i__ + j * 3 - 4] / sqrt(addem1);
	}
    }
    if (init <= 0) {
	goto L9907;
    } else {
	goto L1907;
    }
L1907:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = xi[i__ + j * 3 - 4] - cor[i__ + j * 3 - 4], abs(d__1))
		     - z5em4 <= 0.) {
		goto L1906;
	    } else {
		goto L2906;
	    }
L1906:
	    ;
	}
	aerr_(&c__3501, "POCKET  ", (ftnlen)8);
L2906:
	;
    }
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = u[i__ + (j + 1) * 3 - 4] - u[i__ + j * 3 - 4], abs(
		    d__1)) - z5em4 <= 0.) {
		goto L3906;
	    } else {
		goto L4906;
	    }
L3906:
	    ;
	}
	aerr_(&c__3502, "POCKET  ", (ftnlen)8);
L4906:
	;
    }
    icrsto = knumbr_1.k1;
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	crosto[0] = -u[j * 3 - 3];
	crosto[1] = -u[j * 3 - 2];
	crosto[2] = -u[j * 3 - 1];
	cross_(crosto, &u[(j + 1) * 3 - 3], crosto);
	vnorm_(crosto, ucrsto);
	if (icrsto <= 0) {
	    goto L4907;
	} else {
	    goto L2907;
	}
L2907:
	for (i__ = 1; i__ <= 3; ++i__) {
/* L3907: */
	    tcrsto[i__ - 1] = ucrsto[i__ - 1];
	}
	icrsto = knumbr_1.k0;
	goto L6907;
L4907:
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = ucrsto[i__ - 1] - tcrsto[i__ - 1], abs(d__1)) - z5em4 
		    <= 0.) {
		goto L5907;
	    } else {
		goto L7907;
	    }
L5907:
	    ;
	}
L6907:
	;
    }
/* ...  ADJUST POCKET VERTICES IF POCKET BOTTOM IS CANTED */
/*      WITH RESPECT TO TOOL AXIS AND VERTICIES DESCRIBE ACTUAL */
/*     POCKET BOUNDARIES. */
    x1 = (d__1 = fxcor_1.ta[0] * tcrsto[0] + fxcor_1.ta[1] * tcrsto[1] + 
	    fxcor_1.ta[2] * tcrsto[2], abs(d__1));
    if (x1 - .2 <= 0.) {
	goto L50;
    } else {
	goto L55;
    }
L50:
    aerr_(&c__3507, "POCKET  ", (ftnlen)8);
L55:
    if (x1 - .9999 >= 0.) {
	goto L60;
    } else {
	goto L65;
    }
L60:
    init = -knumbr_1.k1;
L65:
    if (init < 0) {
	goto L9907;
    } else if (init == 0) {
	goto L60;
    } else {
	goto L70;
    }
L70:
    if (pttype < 0.) {
	goto L50;
    } else if (pttype == 0) {
	goto L60;
    } else {
	goto L75;
    }
L75:
    init = knumbr_1.k0;
    pttype = znumbr_1.z0;
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	addem1 = fxcor_1.ta[0] * u[j * 3 - 3] + fxcor_1.ta[1] * u[j * 3 - 2] 
		+ fxcor_1.ta[2] * u[j * 3 - 1];
	addem2 = fxcor_1.ta[0] * u[(j + 1) * 3 - 3] + fxcor_1.ta[1] * u[(j + 
		1) * 3 - 2] + fxcor_1.ta[2] * u[(j + 1) * 3 - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
	    qq[i__ - 1] = u[i__ + j * 3 - 4] - fxcor_1.ta[i__ - 1] * addem1;
/* L100: */
	    ww[i__ - 1] = u[i__ + (j + 1) * 3 - 4] - fxcor_1.ta[i__ - 1] * 
		    addem2;
	}
	vnorm_(qq, qq);
	vnorm_(ww, ww);
	t[0] = ww[0] - qq[0];
	t[1] = ww[1] - qq[1];
	t[2] = ww[2] - qq[2];
	vnorm_(t, t);
/* Computing 2nd power */
	d__1 = cutrad;
/* Computing 2nd power */
	d__2 = t[0] * ww[0] + t[1] * ww[1] + t[2] * ww[2];
	dshar5_1.alpha = sqrt(d__1 * d__1 / (1.f - d__2 * d__2));
	y[0] = dshar5_1.alpha * t[0];
	y[1] = dshar5_1.alpha * t[1];
	y[2] = dshar5_1.alpha * t[2];
	dshar5_1.alpha = y[0] * tcrsto[0] + y[1] * tcrsto[1] + y[2] * tcrsto[
		2];
	for (i__ = 1; i__ <= 3; ++i__) {
/* L200: */
	    cor[i__ + j * 3 - 4] = cor[i__ + j * 3 - 4] + y[i__ - 1] - 
		    dshar5_1.alpha * fxcor_1.ta[i__ - 1] / x1;
	}
    }
    goto L1904;
L7907:
    for (i__ = 1; i__ <= 3; ++i__) {
	if ((d__3 = (d__1 = ucrsto[i__ - 1], abs(d__1)) - (d__2 = tcrsto[i__ 
		- 1], abs(d__2)), abs(d__3)) - z5em4 <= 0.) {
	    goto L5906;
	} else {
	    goto L6906;
	}
L5906:
	;
    }
    aerr_(&c__3504, "POCKET  ", (ftnlen)8);
L6906:
    aerr_(&c__3503, "POCKET  ", (ftnlen)8);
L9907:
    if (ovride != 0.) {
	goto L909;
    } else {
	goto L1908;
    }
L1908:
    sphio2 = znumbr_1.z1;
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	addem1 = znumbr_1.z0;
	for (i__ = 1; i__ <= 3; ++i__) {
/* L2908: */
	    addem1 = -u[i__ + j * 3 - 4] * u[i__ + (j + 1) * 3 - 4] + addem1;
	}
	dummy = sqrt((znumbr_1.z1 - addem1) / znumbr_1.z2);
	if (dummy - sphio2 >= 0.) {
	    goto L4908;
	} else {
	    goto L3908;
	}
L3908:
	sphio2 = dummy;
L4908:
	;
    }
    dummy = radeff / cutrad * (znumbr_1.z1 + sphio2);
    if (ofsetc - dummy <= 0.) {
	goto L6908;
    } else {
	goto L5908;
    }
L5908:
    ofsetc = dummy;
L6908:
    if (ofsetf - dummy <= 0.) {
	goto L8908;
    } else {
	goto L7908;
    }
L7908:
    ofsetf = dummy;
L8908:
    if (! sr5) {
	goto L909;
    }
    sr5 = FALSE_;
/* L9908: */
    ofcsto = ofsetc;
    offsto = ofsetf;
    dummy = znumbr_1.z2 * radeff / cutrad * sphio2;
    if (ofsetc - dummy <= 0.) {
	goto L4909;
    } else {
	goto L2909;
    }
L2909:
    ofsetc = dummy;
    if (ofsetf - dummy <= 0.) {
	goto L4909;
    } else {
	goto L3909;
    }
L3909:
    ofsetf = dummy;
L4909:
    sr5 = TRUE_;
L909:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L1909: */
	    w[i__ + j * 3 - 4] = u[i__ + (j + 1) * 3 - 4] - u[i__ + j * 3 - 4]
		    ;
	}
	addem1 = znumbr_1.z0;
	addem2 = znumbr_1.z0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    addem1 = w[i__ + j * 3 - 4] * u[i__ + (j + 1) * 3 - 4] + addem1;
/* L910: */
	    addem2 = w[i__ + j * 3 - 4] * w[i__ + j * 3 - 4] + addem2;
	}
/* L911: */
/* Computing 2nd power */
	d__1 = addem1;
	bl[j - 1] = sqrt(addem2 - d__1 * d__1);
    }
    dist = pttype * cutrad;
    goto L4915;
L912:
    move = knumbr_1.k2;
    goto L1913;
L913:
    move = knumbr_1.k3;
L1913:
    deldst = znumbr_1.z5em1 * ofsetf * cutrad;
    goto L2914;
L914:
    move = knumbr_1.k4;
L1914:
    deldst = znumbr_1.z5em1 * ofsetc * cutrad;
L2914:
    dist += deldst;
/* L915: */
    if (kalc <= 0) {
	goto L1915;
    } else {
	goto L2915;
    }
L1915:
    kalc = knumbr_1.k1;
    goto L3915;
L2915:
    kalc = knumbr_1.k0;
/*     EXIT IF ZERO DIAM. CUTTER */
L3915:
    if (cutrad <= 0.) {
	goto L987;
    } else {
	goto L3916;
    }
L3916:
    if (! sr5) {
	goto L4915;
    }
/* L5915: */
    ofsetc = ofcsto;
    ofsetf = offsto;
L4915:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L916: */
	    xiprim[i__ + j * 3 - 4] = cor[i__ + j * 3 - 4] + dist / bl[j - 1] 
		    * w[i__ + j * 3 - 4];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L917: */
	xiprim[i__ + (nc + 1) * 3 - 4] = xiprim[i__ - 1];
    }
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	addem1 = znumbr_1.z0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    vprim[i__ + j * 3 - 4] = xiprim[i__ + (j + 1) * 3 - 4] - xiprim[
		    i__ + j * 3 - 4];
/* L918: */
/* Computing 2nd power */
	    d__1 = vprim[i__ + j * 3 - 4];
	    addem1 = d__1 * d__1 + addem1;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* L919: */
	    uprim[i__ + j * 3 - 4] = vprim[i__ + j * 3 - 4] / sqrt(addem1);
	}
    }
/*     COLLAPSE TESTS */
/* L920: */
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	ktab[j - 1] = knumbr_1.k0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    if ((d__1 = u[i__ + (j + 1) * 3 - 4] - uprim[i__ + j * 3 - 4], 
		    abs(d__1)) - z5em3 <= 0.) {
		goto L7260;
	    } else {
		goto L7250;
	    }
L7250:
	    ktab[j - 1] = knumbr_1.k1;
L7260:
	    ;
	}
    }
L7270:
    ncutbk = nc;
    kutbac = knumbr_1.k0;
    kolaps = knumbr_1.k0;
    phitmp = znumbr_1.z1;
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	if (ktab[j - 1] <= 0) {
	    goto L921;
	} else {
	    goto L934;
	}
L921:
	if (! sr2) {
	    goto L927;
	}
	sr2 = FALSE_;
/* L922: */
	if (kutbac - j + 1 != 0) {
	    goto L924;
	} else {
	    goto L923;
	}
L923:
	jsave = j;
	kolaps = knumbr_1.k0;
	goto L942;
L924:
	inter = knumbr_1.k1;
	kone = j - kolaps - 1;
	ktwo = j;
	goto L1940;
L925:
	for (i__ = 1; i__ <= 3; ++i__) {
	    jdummy = j - kutbac;
/* L926: */
	    ctemp[i__ + jdummy * 3 - 4] = ptint[i__ - 1];
	}
	kolaps = knumbr_1.k0;
	goto L929;
L927:
	for (i__ = 1; i__ <= 3; ++i__) {
	    jdummy = j - kutbac;
/* L928: */
	    ctemp[i__ + jdummy * 3 - 4] = xiprim[i__ + j * 3 - 4];
	}
L929:
	if (j - nc >= 0) {
	    goto L930;
	} else {
	    goto L942;
	}
L930:
	if (! sr3) {
	    goto L942;
	}
	sr3 = FALSE_;
/* L931: */
	inter = knumbr_1.k2;
	kone = j;
	ktwo = jsave;
	goto L1940;
L932:
	for (i__ = 1; i__ <= 3; ++i__) {
/* L933: */
	    ctemp[i__ - 1] = ptint[i__ - 1];
	}
	goto L942;
L934:
	--ncutbk;
	++kutbac;
	++kolaps;
	sr2 = TRUE_;
	if (j - 1 <= 0) {
	    goto L935;
	} else {
	    goto L936;
	}
L935:
	sr3 = TRUE_;
	goto L942;
L936:
	if (j - nc >= 0) {
	    goto L1936;
	} else {
	    goto L942;
	}
L1936:
	if (move == 1 && ncutbk <= 2) {
	    aerr_(&c__3510, "POCKET  ", (ftnlen)8);
	}
	if (ncutbk - 2 <= 0) {
	    goto L2936;
	} else {
	    goto L937;
	}
L2936:
	move = knumbr_1.k5;
	if (kalc <= 0) {
	    goto L3936;
	} else {
	    goto L982;
	}
L937:
	if (! sr3) {
	    goto L940;
	}
	sr3 = FALSE_;
/* L938: */
	ktwo = jsave;
L939:
	inter = knumbr_1.k2;
	kone = j - kolaps;
	goto L1940;
L940:
	ktwo = knumbr_1.k1;
	goto L939;
/* ...  CALCULATE INTERSECTION OF NON-COLLAPSING SIDES */
L1940:
	itest = knumbr_1.k1;
	kt1 = kone;
	kt2 = ktwo;
L2040:
	cosva = uprim[kt1 * 3 - 3] * uprim[kt2 * 3 - 3] + uprim[kt1 * 3 - 2] *
		 uprim[kt2 * 3 - 2] + uprim[kt1 * 3 - 1] * uprim[kt2 * 3 - 1];
	addem2 = sqrt((d__1 = (znumbr_1.z1 + cosva) / znumbr_1.z2, abs(d__1)))
		;
	if (addem2 - phitmp >= 0.) {
	    goto L2080;
	} else {
	    goto L2060;
	}
L2060:
	phitmp = addem2;
L2080:
/* Computing 2nd power */
	d__1 = cosva;
	sin2va = znumbr_1.z1 - d__1 * d__1;
	if (sin2va - z1em4 <= 0.) {
	    goto L2140;
	} else {
	    goto L2340;
	}
/* ...  SIDES ARE NEARLY PARALLEL - TAKE AVERAGE OF TWO VERTICES */
L2140:
	for (l = 1; l <= 3; ++l) {
/* L2240: */
	    ptint[l - 1] = (xiprim[l + (kone + 1) * 3 - 4] + xiprim[l + ktwo *
		     3 - 4]) / znumbr_1.z2;
	}
	goto L8941;
/* ...  SIDES INTERSECT - COMPUTE INTERSECTION */
L2340:
	dshar5_1.alpha = znumbr_1.z0;
	for (l = 1; l <= 3; ++l) {
/* L2440: */
	    dshar5_1.alpha += (xiprim[l + kt2 * 3 - 4] - xiprim[l + kt1 * 3 - 
		    4]) * (uprim[l + kt1 * 3 - 4] - uprim[l + kt2 * 3 - 4] * 
		    cosva);
	}
	dshar5_1.alpha /= sin2va;
	addem1 = znumbr_1.z0;
	for (l = 1; l <= 3; ++l) {
/* L2540: */
/* Computing 2nd power */
	    d__1 = xiprim[l + (kt1 + 1) * 3 - 4] - xiprim[l + kt1 * 3 - 4];
	    addem1 += d__1 * d__1;
	}
	addem1 = sqrt(addem1);
	switch (itest) {
	    case 1:  goto L2640;
	    case 2:  goto L2740;
	    case 3:  goto L3040;
	    case 4:  goto L3340;
	    case 5:  goto L3540;
	    case 6:  goto L3840;
	}
L2640:
	if (dshar5_1.alpha < 0.) {
	    goto L2650;
	} else if (dshar5_1.alpha == 0) {
	    goto L2140;
	} else {
	    goto L3140;
	}
L2650:
	kt1 -= knumbr_1.k1;
	if (kt1 <= 0) {
	    goto L2680;
	} else {
	    goto L2660;
	}
L2660:
	if (ktab[kt1 - 1] <= 0) {
	    goto L2670;
	} else {
	    goto L2650;
	}
L2670:
	itest = knumbr_1.k2;
	goto L2040;
L2680:
	kt1 = nc;
L2690:
	if (ktab[kt1 - 1] <= 0) {
	    goto L2670;
	} else {
	    goto L2700;
	}
L2700:
	kt1 -= knumbr_1.k1;
	if (kt1 - kt2 <= 0) {
	    goto L2140;
	} else {
	    goto L2690;
	}
L2740:
	if (dshar5_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L2840;
	}
L2840:
	if (dshar5_1.alpha - addem1 <= 0.) {
	    goto L2940;
	} else {
	    goto L2140;
	}
L2940:
	kt2 = kt1;
	kt1 = ktwo;
	itest = knumbr_1.k3;
	goto L2340;
L3040:
	if (dshar5_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3050;
	}
L3050:
	if (dshar5_1.alpha - addem1 <= 0.) {
	    goto L3060;
	} else {
	    goto L2140;
	}
/* ...  SIDE OUTSIDE POLYGON-PLACE SIDE IN COLLAPSE CONDITION */
L3060:
	ktab[kone - 1] = knumbr_1.k1;
	goto L3870;
L3140:
	if (dshar5_1.alpha - addem1 >= 0.) {
	    goto L2140;
	} else {
	    goto L3240;
	}
L3240:
	kt1 = ktwo;
	kt2 = kone;
	itest = knumbr_1.k4;
	goto L2340;
L3340:
	if (dshar5_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3350;
	}
L3350:
	if (dshar5_1.alpha - addem1 <= 0.) {
	    goto L5940;
	} else {
	    goto L3440;
	}
L3440:
	kt1 = kt2;
	kt2 = ktwo;
L3450:
	kt2 += knumbr_1.k1;
	if (kt2 - nc <= 0) {
	    goto L3460;
	} else {
	    goto L3480;
	}
L3460:
	if (ktab[kt2 - 1] <= 0) {
	    goto L3470;
	} else {
	    goto L3450;
	}
L3470:
	itest = knumbr_1.k5;
	goto L2040;
L3480:
	kt2 = knumbr_1.k1;
L3490:
	if (ktab[kt2 - 1] <= 0) {
	    goto L3470;
	} else {
	    goto L3510;
	}
L3510:
	kt2 += knumbr_1.k1;
	if (kt2 - kt1 - knumbr_1.k1 >= 0) {
	    goto L2140;
	} else {
	    goto L3490;
	}
L3540:
	if (dshar5_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3640;
	}
L3640:
	if (dshar5_1.alpha - addem1 <= 0.) {
	    goto L3740;
	} else {
	    goto L2140;
	}
L3740:
	kt1 = kt2;
	kt2 = kone;
	itest = knumbr_1.k6;
	goto L2340;
L3840:
	if (dshar5_1.alpha <= 0.) {
	    goto L2140;
	} else {
	    goto L3850;
	}
L3850:
	if (dshar5_1.alpha - addem1 <= 0.) {
	    goto L3860;
	} else {
	    goto L2140;
	}
/* ...  SIDE OUTSIDE POLYGON-PLACE SIDE IN COLLAPSE CONDITION */
L3860:
	ktab[ktwo - 1] = knumbr_1.k1;
L3870:
	sr2 = FALSE_;
/* L3880: */
	sr3 = FALSE_;
	goto L7270;
L5940:
	for (l = 1; l <= 3; ++l) {
/* L6040: */
	    ptint[l - 1] = xiprim[l + kt1 * 3 - 4] + dshar5_1.alpha * uprim[l 
		    + kt1 * 3 - 4];
	}
L8941:
	switch (inter) {
	    case 1:  goto L925;
	    case 2:  goto L932;
	}
L942:
	;
    }
    if (nc - ncutbk <= 0) {
	goto L944;
    } else {
	goto L1942;
    }
L1942:
    if (kalc != 0) {
	goto L8942;
    } else {
	goto L2942;
    }
L2942:
    if (ovride != 0.) {
	goto L3942;
    } else {
	goto L5942;
    }
L8942:
    if (ovride != 0.) {
	goto L3942;
    } else {
	goto L9941;
    }
L9941:
    sr5 = TRUE_;
L3942:
    i__1 = ncutbk;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L4942: */
	    cor[i__ + j * 3 - 4] = ctemp[i__ + j * 3 - 4];
	}
    }
    goto L904;
L5942:
    if (! sr5) {
	goto L6942;
    }
    sr5 = FALSE_;
/* L943: */
    if (! sr4) {
	goto L6942;
    }
    sr4 = FALSE_;
    goto L3942;
L6942:
    if (phitmp - sphio2 >= 0.) {
	goto L3942;
    } else {
	goto L7942;
    }
L7942:
    sphio2 = phitmp;
    dummy = radeff / cutrad * (znumbr_1.z1 + sphio2);
    if (ofsetc - dummy <= 0.) {
	goto L2943;
    } else {
	goto L9942;
    }
L9942:
    ofcsto = dummy;
    if (ofsetf - dummy <= 0.) {
	goto L3943;
    } else {
	goto L1943;
    }
L1943:
    offsto = dummy;
    goto L4943;
L2943:
    ofcsto = ofsetc;
L3943:
    offsto = ofsetf;
L4943:
    dummy = znumbr_1.z2 * radeff / cutrad * sphio2;
    if (ofsetc - dummy <= 0.) {
	goto L3942;
    } else {
	goto L5943;
    }
L5943:
    ofsetc = dummy;
    if (ofsetf - dummy <= 0.) {
	goto L7943;
    } else {
	goto L6943;
    }
L6943:
    ofsetf = dummy;
L7943:
    sr5 = TRUE_;
    sr4 = TRUE_;
    dist -= deldst;
    kalc = knumbr_1.k1;
    switch (move) {
	case 1:  goto L2915;
	case 2:  goto L1913;
	case 3:  goto L1913;
	case 4:  goto L1914;
	case 5:  goto L1914;
    }
L944:
    if (kalc != 0) {
	goto L946;
    } else {
	goto L945;
    }
L945:
    sr1 = FALSE_;
    sr2 = FALSE_;
    sr3 = FALSE_;
    sr4 = FALSE_;
    sr5 = FALSE_;
/*     COVERAGE TESTS */
L946:
    rtest = znumbr_1.z2 * radeff;
    kover = knumbr_1.k2;
    goto L949;
L947:
    rtest = radeff;
    kover = knumbr_1.k1;
L949:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = nless1;
	for (l = 2; l <= i__2; ++l) {
	    k = j + l;
	    if (k - nc <= 0) {
		goto L951;
	    } else {
		goto L950;
	    }
L950:
	    k -= nc;
L951:
	    switch (kover) {
		case 1:  goto L952;
		case 2:  goto L954;
	    }
L952:
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L953: */
		y[i__ - 1] = xiprim[i__ + k * 3 - 4] - xiprim[i__ + (j + 1) * 
			3 - 4];
	    }
L954:
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L955: */
		t[i__ - 1] = xiprim[i__ + k * 3 - 4] - xiprim[i__ + j * 3 - 4]
			;
	    }
	    addem1 = znumbr_1.z0;
	    addem2 = znumbr_1.z0;
	    for (i__ = 1; i__ <= 3; ++i__) {
		addem1 = t[i__ - 1] * uprim[i__ + j * 3 - 4] + addem1;
/* L956: */
		addem2 = t[i__ - 1] * t[i__ - 1] + addem2;
	    }
/* Computing 2nd power */
	    d__1 = addem1;
	    dcov = sqrt(addem2 - d__1 * d__1);
	    if (dcov - rtest <= 0.) {
		goto L957;
	    } else {
		goto L968;
	    }
L957:
	    switch (kover) {
		case 1:  goto L958;
		case 2:  goto L965;
	    }
L958:
	    addem1 = znumbr_1.z0;
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L959: */
		addem1 = y[i__ - 1] * (-uprim[i__ + j * 3 - 4]) + addem1;
	    }
	    if (addem1 < 0.) {
		goto L960;
	    } else if (addem1 == 0) {
		goto L965;
	    } else {
		goto L962;
	    }
L960:
	    addem1 = znumbr_1.z0;
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L961: */
		addem1 = y[i__ - 1] * y[i__ - 1] + addem1;
	    }
	    addem2 = sqrt(addem1);
	    if (addem2 - rtest <= 0.) {
		goto L965;
	    } else {
		goto L968;
	    }
L962:
	    addem1 = znumbr_1.z0;
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L963: */
		addem1 = t[i__ - 1] * uprim[i__ + j * 3 - 4] + addem1;
	    }
	    if (addem1 >= 0.) {
		goto L965;
	    } else {
		goto L964;
	    }
L964:
	    addem1 = sqrt(addem2);
	    if (addem1 - rtest <= 0.) {
		goto L965;
	    } else {
		goto L968;
	    }
L965:
	    ;
	}
	move = knumbr_1.k5;
	switch (kover) {
	    case 1:  goto L969;
	    case 2:  goto L967;
	}
L967:
	if (kalc <= 0) {
	    goto L980;
	} else {
	    goto L947;
	}
L968:
	;
    }
    switch (kover) {
	case 1:  goto L980;
	case 2:  goto L1968;
    }
L1968:
    if (kalc <= 0) {
	goto L980;
    } else {
	goto L982;
    }
L969:
    addem1 = znumbr_1.z0;
    addem2 = znumbr_1.z0;
    for (i__ = 1; i__ <= 3; ++i__) {
/* Computing 2nd power */
	d__1 = xiprim[i__ + j * 3 - 4] - xiprim[i__ - 1];
	addem1 = d__1 * d__1 + addem1;
/* L970: */
/* Computing 2nd power */
	d__1 = xiprim[i__ + (j + 1) * 3 - 4] - xiprim[i__ - 1];
	addem2 = d__1 * d__1 + addem2;
    }
    if (sqrt((abs(addem1))) - sqrt((abs(addem2))) <= 0.) {
	goto L971;
    } else {
	goto L974;
    }
L971:
    for (i__ = 1; i__ <= 3; ++i__) {
	wd[i__ - 1] = xiprim[i__ + j * 3 - 4];
/* L972: */
	xiprim[i__ - 1] = xiprim[i__ + (j + 1) * 3 - 4];
    }
L973:
    j = knumbr_1.k2;
    num = knumbr_1.k2;
    goto L985;
L974:
    for (i__ = 1; i__ <= 3; ++i__) {
	wd[i__ - 1] = xiprim[i__ + (j + 1) * 3 - 4];
/* L975: */
	xiprim[i__ - 1] = xiprim[i__ + j * 3 - 4];
    }
    goto L973;
L3936:
    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* L4936: */
	    xiprim[i__ + j * 3 - 4] = ctemp[i__ + j * 3 - 4];
	}
/* L4937: */
    }
L980:
    num = nplus1;
    j = knumbr_1.k1;
    goto L983;
L981:
    j = num - 1;
    num = j;
    if (j <= 0) {
	goto L982;
    } else {
	goto L983;
    }
L982:
    switch (move) {
	case 1:  goto L912;
	case 2:  goto L913;
	case 3:  goto L914;
	case 4:  goto L1914;
	case 5:  goto L987;
    }
L983:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L984: */
	wd[i__ - 1] = xiprim[i__ + j * 3 - 4];
    }
L985:
    nwd = 0;
    awrite_(&symfil_1.pofile, &nwd, wd, &c__6, &ir);
/* L2986: */
    ++nwd;
    nwdmax = nwd;
    goto L981;
/* ........INVERT ORDER OF POINTS ON FILE AND OUTPUT TO EXFILE */
/*       INSERTING PROPER FEEDRATES */


/* ...POCKET MUST GENERATE AT LEAST 3 POINTS */
L987:
    if (nwd < knumbr_1.k3) {
	aerr_(&c__3510, "POCKET  ", (ftnlen)8);
    }
    record_(&ifxcor_1.iseqno);
/* ...SET FINAL POINT INDICATOR FOR CLDATA RECORD WRITER */
    ifxcor_1.icl = knumbr_1.k3;
/* ...SET PLUNGE FEEDRATE */
    feedrt = *frone;
/* ...SET FIRST POINT FLAG TRUE */
    fptflg = TRUE_;

    fpflg = FALSE_;
    if (nwdmax == ncorig + knumbr_1.k2) {
	fpflg = TRUE_;
    }
/* ...  WRITE A FEEDRATE RECORD ON EXFILE */
L992:
    apt299_(&knumbr_1.k1, hfdrt, &knumbr_1.k1, &feedrt);
    kcldat[3] = ifxcor_1.iseqno;
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, kcldat, &c__10, &ir);

/* ...WAS LAST POINT PROCESSED.... */
L993:
    if (nwd <= knumbr_1.k1) {
	goto L9999;
    }
/* .... NO */
/* ...WILL FINISH PASS BE COMPLETED WITH NEXT POINT... */
    if (nwd == knumbr_1.k2) {
	goto L996;
    }
/* .... NO */
/* ...SKIP NEXT TEST IF FINISH PASS STARTED */
    if (fpflg) {
	goto L998;
    }
/* ...IS IT TIME FOR FINISH PASS... */
    if (nwd == ncorig + knumbr_1.k2) {
	goto L995;
    }
/* .... NO */
/* ...WILLCLEANOUT PASS BE COMPLETED WITH NEXT POINT... */
L998:
    if (nwd == ncorig + knumbr_1.k3) {
	goto L996;
    }
/* .... NO */
/* ...PRODUCE NEXT POINT */
L994:
    if (nwd == nwdmax) {
	goto L997;
    }

L997:
    --nwd;
    aread_(&symfil_1.pofile, &nwd, fxcor_1.te, &c__6, &ir);
    atape_();

/* ...SET INTERMEDIATE POINT INDICATOR FOR ATAPE (CLDATA RECORD WRITER) */
    ifxcor_1.icl = knumbr_1.k2;
/* ...CHECK FIRST POINT FLAG */
    if (! fptflg) {
	goto L993;
    }
/* ...FLAG TRUE ...SET FALSE , AND PREPARE FOR POCKET CLEANOUT */
    fptflg = FALSE_;
    feedrt = *frtwo;
    if (nwd <= knumbr_1.k2) {
	goto L995;
    }
    if (nwd > ncorig + knumbr_1.k1) {
	goto L992;
    }
/* ...SET FINAL FEEDRATE */
L995:
    feedrt = *frthre;
    fpflg = TRUE_;
    goto L992;
/* ...SET FINAL POINT INDICATOR FOR ATAPE */
L996:
    ifxcor_1.icl = knumbr_1.k3;
    goto L994;
L9999:
    return 0;
} /* pocket_ */

#undef hpockt
#undef ipockt
#undef bcanon
#undef hfdrt
#undef ifdrt
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef srf
#undef can
#undef ww
#undef qq
#undef w
#undef q


