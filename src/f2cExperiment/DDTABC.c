/* DDTABC.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c_b82 = -28801;

/* *** SOURCE FILE : M0002926.W01   *** */

/* .....FORTRAN SUBROUTINE  ....DDTABC         8/68                    RN */
/* .....FORTRAN SUBROUTINE             DDTABC...              3/1/68   GK */
/* Subroutine */ int ddtabc_(doublereal *d__)
{
    /* Initialized data */

    static integer iitbsg[4] = { 0,0,0,0 };
    static integer isqls = 0;
    static integer icount = 0;
    static doublereal zlit1 = .2;
    static doublereal zlit2 = 1e-20;
    static integer klit3 = 14;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *), atan(
	    doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, j, k, l, m, n;
#define x ((doublereal *)&dshar4_1 + 65)
#define a1 ((doublereal *)&fxcor_1 + 38)
#define b1 ((doublereal *)&fxcor_1 + 39)
#define c1 ((doublereal *)&fxcor_1 + 40)
#define g2 ((doublereal *)&fxcor_1 + 36)
#define h2 ((doublereal *)&fxcor_1 + 35)
    static doublereal r0[9];
#define sq ((doublereal *)&fxcor_1 + 37)
#define up ((doublereal *)&fxcor_1 + 41)
#define vp ((doublereal *)&fxcor_1 + 42)
#define un ((doublereal *)&fxcor_1 + 43)
#define vn ((doublereal *)&fxcor_1 + 44)
    static doublereal wp, uq;
#define acf ((doublereal *)&dshar4_1 + 80)
#define bcf ((doublereal *)&dshar4_1 + 81)
#define ccf ((doublereal *)&dshar4_1 + 82)
    static integer iip;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static doublereal savc;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define sinn ((doublereal *)&dshar4_1 + 62)
#define coss ((doublereal *)&dshar4_1 + 63)
    static doublereal aarg1, aarg2;





/* ...  ALL REFERENCES TO ARRAY R, HAVE BEEN CHANGED TO R0, */
/* ...  BECAUSE R OCCURS IN DSHAR4.INC */

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






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */







/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --d__;

    /* Function Body */

/* ...  DEFINITIONS OF ARITHMETIC STATEMENT FUNCTIONS */


/* ...  INITIALIZE DIRECTED DISTANCE */




/* ...  TRANSFORM TOOL POINT AND TOOL NORMAL INTO U-V-W COORD. SYSTEM */

    i__ = 1;
L10:
    r0[i__ - 1] = d__[i__ + 2];
    ++i__;
    if (i__ < 10) {
	goto L10;
    }


    ifxcor_1.ier = 0;
    sv_1.s[ifxcor_1.is - 1] = 1e38;
    *up = r0[0] * sv_1.tp[ifxcor_1.is * 3 - 3] + r0[1] * sv_1.tp[ifxcor_1.is *
	     3 - 2] + r0[2] * sv_1.tp[ifxcor_1.is * 3 - 1];
    *vp = r0[3] * sv_1.tp[ifxcor_1.is * 3 - 3] + r0[4] * sv_1.tp[ifxcor_1.is *
	     3 - 2] + r0[5] * sv_1.tp[ifxcor_1.is * 3 - 1];
    wp = r0[6] * sv_1.tp[ifxcor_1.is * 3 - 3] + r0[7] * sv_1.tp[ifxcor_1.is * 
	    3 - 2] + r0[8] * sv_1.tp[ifxcor_1.is * 3 - 1];
    *un = r0[0] * sv_1.tn[ifxcor_1.is * 3 - 3] + r0[1] * sv_1.tn[ifxcor_1.is *
	     3 - 2] + r0[2] * sv_1.tn[ifxcor_1.is * 3 - 1];
    *vn = r0[3] * sv_1.tn[ifxcor_1.is * 3 - 3] + r0[4] * sv_1.tn[ifxcor_1.is *
	     3 - 2] + r0[5] * sv_1.tn[ifxcor_1.is * 3 - 1];
/* Computing 2nd power */
    d__1 = *un;
/* Computing 2nd power */
    d__2 = *vn;
    uq = sqrt(d__1 * d__1 + d__2 * d__2);
    if (uq == 0.f) {
	goto L1002;
    }
    *un /= uq;
    *vn /= uq;

/* ...  CHECK TO SEE IF TOOL NORMAL IS PARALLEL TO AXIS OF TABCYL */

    if (abs(*un) + abs(*vn) - znumbr_1.z1em6 <= 0.) {
	goto L1002;
    } else {
	goto L600;
    }

/* ...  SET INDEXES AND BEGIN EXAMINING TABCYL SEGMENTS */

L600:
    ifxcor_1.nwds = (integer) (d__[12] * 7.f + 6.f);
    i__ = (integer) d__[13];
    iip = ifxcor_1.is - 1;
    if (isv_1.jent[ifxcor_1.is - 1] == 0 && isqls == ifxcor_1.iseqno) {
	i__ = iitbsg[iip - 1];
    }
/* L602: */
    ifxcor_1.icheck = 0;
    ifxcor_1.nmbseg = (integer) d__[12];
    ifxcor_1.nmbseg -= knumbr_1.k1;
    i__1 = ifxcor_1.nmbseg;
    for (l = 1; l <= i__1; ++l) {

/* ...  STORE CANONICAL INFORMATION FOR SEGMENT IN SEG(K) */

/* L2501: */
	j = i__;
	for (k = 1; k <= 9; ++k) {
	    dshar4_1.seg[k - 1] = d__[j];
/* L500: */
	    j += knumbr_1.k1;
	}
	dshar4_1.seg[5] *= dshar4_1.seg[4];
	dshar4_1.seg[6] *= dshar4_1.seg[4];
	dshar4_1.seg[4] = -dshar4_1.seg[4] * (dshar4_1.seg[2] * dshar4_1.seg[
		4] + dshar4_1.seg[3]);

/* ...  TRANSFORM POINTS AND VECTOR INTO U-V COORD. SYSTEM OF SEGMENT */

	*h2 = dshar4_1.seg[7] - dshar4_1.seg[0];
	*g2 = dshar4_1.seg[8] - dshar4_1.seg[1];
	dshar4_1.sqroot = sqrt(*h2 * *h2 + *g2 * *g2);
	*sinn = *g2 / dshar4_1.sqroot;
	*coss = *h2 / dshar4_1.sqroot;
	*h2 = *up - dshar4_1.seg[0];
	*g2 = *vp - dshar4_1.seg[1];
	dshar4_1.upp = *h2 * *coss + *g2 * *sinn;
	dshar4_1.vpp = -(*h2) * *sinn + *g2 * *coss;
	dshar4_1.unn = *un * *coss + *vn * *sinn;
	dshar4_1.vnn = -(*un) * *sinn + *vn * *coss;

/* ...  TEST FOR INTERSECTION OF DIRECTED LINE WITH RECTANGLE */
/* ...  SURROUNDING TABCYL SEGMENT */

	if (znumbr_1.z1e6 * abs(dshar4_1.unn) - abs(dshar4_1.vnn) <= 0.) {
	    goto L603;
	} else {
	    goto L604;
	}
L603:
	dshar4_1.slope = znumbr_1.z1e6;
	if (dshar4_1.upp - dshar4_1.sqroot <= 0.) {
	    goto L4410;
	} else {
	    goto L1000;
	}
L4410:
	if (dshar4_1.upp >= 0.) {
	    goto L4411;
	} else {
	    goto L1000;
	}
L4411:
	fxcor_1.tem[0] = dshar4_1.upp;
	fxcor_1.tem[1] = dshar4_1.seg[5];
	goto L700;
L604:
	dshar4_1.slope = dshar4_1.vnn / dshar4_1.unn;
	if (abs(dshar4_1.slope) - znumbr_1.z1em6 <= 0.) {
	    goto L605;
	} else {
	    goto L4419;
	}
L605:
	dshar4_1.slope = znumbr_1.z0;
	if ((d__1 = dshar4_1.vpp - dshar4_1.seg[5]) < 0.) {
	    goto L606;
	} else if (d__1 == 0) {
	    goto L4419;
	} else {
	    goto L1000;
	}
L606:
	if (dshar4_1.seg[6] - dshar4_1.vpp <= 0.) {
	    goto L4419;
	} else {
	    goto L1000;
	}

/* ...  U AND V COORDS. OF INTERSECTION WITH RECTANGLE ARE STORED */
/* ...  IN TEM AND TEM(2) */

L4419:
	fxcor_1.tem[0] = 0.f;
	m = knumbr_1.k7;
	if (dshar4_1.upp <= 0.) {
	    goto L4420;
	} else {
	    goto L4429;
	}
L4420:
	fxcor_1.tem[1] = dshar4_1.vpp + dshar4_1.slope * (fxcor_1.tem[0] - 
		dshar4_1.upp);
/* L4421: */
	if ((d__1 = dshar4_1.seg[6] - fxcor_1.tem[1]) < 0.) {
	    goto L4426;
	} else if (d__1 == 0) {
	    goto L4424;
	} else {
	    goto L4432;
	}
L4426:
	if (dshar4_1.seg[5] - fxcor_1.tem[1] >= 0.) {
	    goto L4424;
	} else {
	    goto L4435;
	}
L4435:
	m = knumbr_1.k6;
L4432:
	fxcor_1.tem[0] = (dshar4_1.seg[m - 1] - dshar4_1.vpp) / 
		dshar4_1.slope + dshar4_1.upp;
/* ---  CII UPDATE TO ENABLE INTERSEC AT A TAB PT, NIU-APR/75 */
	if (abs(fxcor_1.tem[0]) < 5e-17) {
	    fxcor_1.tem[0] = znumbr_1.z0;
	}
	if ((d__1 = -fxcor_1.tem[0]) < 0.) {
	    goto L4433;
	} else if (d__1 == 0) {
	    goto L4425;
	} else {
	    goto L1000;
	}
L4433:
	if (fxcor_1.tem[0] - dshar4_1.sqroot <= 0.) {
	    goto L4425;
	} else {
	    goto L1000;
	}
L4425:
	fxcor_1.tem[1] = dshar4_1.seg[m - 1];
L4424:
/* Computing 2nd power */
	d__1 = fxcor_1.tem[0] - dshar4_1.upp;
/* Computing 2nd power */
	d__2 = fxcor_1.tem[1] - dshar4_1.vpp;
	fxcor_1.tem[2] = sqrt(d__1 * d__1 + d__2 * d__2);

/* ...  IF DIRECTED DISTANCE TO RECTANGLE IS LESS THAN DIR. DIST. */
/* ...  TO CUBIC OF LAST SEGMENT,GO AHEAD AND CALC. DIR. DIST. */
/* ...  TO CUBIC FOR THIS SEGMENT */

	if (fxcor_1.tem[2] - (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) >= 
		0.) {
	    goto L1000;
	} else {
	    goto L4436;
	}
L4429:
	if (dshar4_1.upp - dshar4_1.sqroot >= 0.) {
	    goto L4430;
	} else {
	    goto L4431;
	}
L4431:
	if ((d__1 = dshar4_1.seg[6] - dshar4_1.vpp) < 0.) {
	    goto L4434;
	} else if (d__1 == 0) {
	    goto L700;
	} else {
	    goto L4432;
	}
L4434:
	if (dshar4_1.vpp - dshar4_1.seg[5] <= 0.) {
	    goto L700;
	} else {
	    goto L4435;
	}
L4430:
	fxcor_1.tem[0] = dshar4_1.sqroot;
	goto L4420;
L4436:
	if (isv_1.iop[ifxcor_1.is - 1] <= 0) {
	    goto L700;
	} else {
	    goto L4437;
	}
L4437:
	if (dshar4_1.unn * (dshar4_1.upp - fxcor_1.tem[0]) + dshar4_1.vnn * (
		dshar4_1.vpp - fxcor_1.tem[1]) <= 0.) {
	    goto L700;
	} else {
	    goto L1000;
	}

/* ...  CALC. DIRECTED DISTANCE TO CUBIC OF SEGMENT */

/* ...  J IS SET TO KEEP A RECORD OF THE NUMBER OF INTERSECTIONS WITH */
/* ...  THE CUBIC */

L700:
	j = knumbr_1.k1;
	if (znumbr_1.z1e6 - dshar4_1.slope <= 0.) {
	    goto L607;
	} else {
	    goto L609;
	}

/* ...  SOLVE DIRECTLY FOR INTERSECTION WITH VERTICAL LINE */

L607:
	x[0] = dshar4_1.upp;
	goto L48;
L609:
	dshar4_1.vint = dshar4_1.vpp - dshar4_1.slope * dshar4_1.upp;
	if (znumbr_1.z1em6 - abs(dshar4_1.vint) >= 0.) {
	    goto L618;
	} else {
	    goto L612;
	}

/* ...  TEST FOR DEGENERATE CASES OF CUBIC */

L612:
	if (dshar4_1.seg[2] != 0.) {
	    goto L630;
	} else {
	    goto L613;
	}
L613:
	if (dshar4_1.seg[3] != 0.) {
	    goto L616;
	} else {
	    goto L617;
	}

/* ...  DOES DIRECTED LINE CROSS U AXIS WITHIN SEGMENT */

L614:
	if (dshar4_1.vint * dshar4_1.slope >= 0.) {
	    goto L635;
	} else {
	    goto L615;
	}
L615:
	if (dshar4_1.vint / dshar4_1.slope + dshar4_1.sqroot <= 0.) {
	    goto L635;
	} else {
	    goto L5041;
	}

/* ...  DEGENERATE CUBIC ---- QUADRATIC EQUATION */

L616:
	*c1 = -dshar4_1.vint;
	*a1 = dshar4_1.seg[3];
	*b1 = dshar4_1.seg[4] - dshar4_1.slope;
/* L622: */
	j = 0;
	goto L623;

/* ...  DEGENERATE CUBIC ---- LINEAR EQUATION */

L617:
	x[0] = -dshar4_1.vint / dshar4_1.slope;
	goto L48;

/* ...  FACTOR OUT THE ROOT,X=0,AND CREATE THE RESULTING QUADRATIC */

L699:
	if (*b1 == 0.f) {
	    goto L629;
	}
	x[1] = -(*c1) / *b1;
	k = knumbr_1.k2;
	goto L629;
L618:
	x[0] = 0.f;
	k = knumbr_1.k1;
	*c1 = dshar4_1.seg[4] - dshar4_1.slope;
	*b1 = dshar4_1.seg[3];
	if (abs(dshar4_1.seg[2]) < znumbr_1.z1em9) {
	    goto L699;
	}
L643:
	*a1 = dshar4_1.seg[2];

/* ...  SOLVE THE QUADRATIC EQUATION FOR ROOTS */

L623:
/* Computing 2nd power */
	d__1 = *b1;
	*sq = d__1 * d__1 - *a1 * 4.f * *c1;
	if (abs(*sq) - znumbr_1.z1em7 <= 0.) {
	    goto L624;
	} else {
	    goto L625;
	}
L624:
	x[1] = -(*b1) / (znumbr_1.z2 * *a1);

/* ...  K IS SET TO KEEP A RECORD OF THE NUMBER OF ROOTS */
/* ...  OF THE QUADRATIC, 0=0 ROOTS, 2=1 ROOT, 3=2 ROOTS */

	k = knumbr_1.k2;
	goto L629;
L625:
	if (*sq <= 0.) {
	    goto L621;
	} else {
	    goto L627;
	}
L621:
	k = knumbr_1.k0;
	goto L629;
L627:
	d__1 = sqrt(*sq);
	*sq = -(*b1) - d_sign(&d__1, b1);
	x[1] = znumbr_1.z2 * *c1 / *sq;
	x[2] = *sq / (znumbr_1.z2 * *a1);
	k = knumbr_1.k3;
L629:
	if (j >= 0) {
	    goto L631;
	} else {
	    goto L614;
	}

/* ...  REJECT ROOTS NOT IN SEGMENT AND UPDATE RECORDS */

L631:
	n = knumbr_1.k1;
L750:
	n += knumbr_1.k1;
	if (n - k <= 0) {
	    goto L751;
	} else {
	    goto L752;
	}
L751:
	if (x[n - 1] < -1e-5) {
	    goto L750;
	}
	if (x[n - 1] > 1e-5) {
	    goto L633;
	}
	goto L634;
L633:
	if (x[n - 1] - dshar4_1.sqroot > 1e-5) {
	    goto L750;
	}
L634:
	x[j] = x[n - 1];
	j += knumbr_1.k1;
	goto L750;
L752:
	if (j <= 0) {
	    goto L1000;
	} else {
	    goto L48;
	}

/* ...  TRUE CUBIC, PREPARE TO DETERMINE ROOT */

/* ...  DIFFERENTIATE CUBIC AND SOLVE FOR MAX AND MIN POINTS */

L630:
	j = -knumbr_1.k1;
/* L620: */
	*a1 = znumbr_1.z3 * dshar4_1.seg[2];
	*b1 = znumbr_1.z2 * dshar4_1.seg[3];
	*c1 = dshar4_1.seg[4] - dshar4_1.slope;
	goto L623;

/* ...  ELIMINATE MAX AND MIN POINTS NOT IN THE SEGMENT */

L635:
	n = knumbr_1.k1;
L753:
	n += knumbr_1.k1;
	if (n - k <= 0) {
	    goto L754;
	} else {
	    goto L1000;
	}
L754:
	if (x[n - 1] > 1e-5) {
	    goto L637;
	}
	goto L753;
L637:
	if (x[n - 1] - dshar4_1.sqroot > 1e-5) {
	    goto L753;
	}

/* ...  LOOK FOR TANGENCY AND MULTIPLE INTERSECTION CASES */

/* L638: */
	fxcor_1.tem[0] = ((*acf * x[n - 1] + *bcf) * x[n - 1] + (*ccf - 
		dshar4_1.slope)) * x[n - 1] - dshar4_1.vint;
	if (abs(fxcor_1.tem[0]) - znumbr_1.z1em5 >= 0.) {
	    goto L640;
	} else {
	    goto L639;
	}

/* ...  TANGENCY */

L639:
	x[0] = x[n - 1];
	j = knumbr_1.k1;
	goto L48;
L641:
	j = knumbr_1.k1;
L642:
	*b1 = dshar4_1.seg[2] * x[0] + dshar4_1.seg[3];
	*c1 = *b1 * x[0] + dshar4_1.seg[4] - dshar4_1.slope;
	goto L643;

/* ...  IS THERE A POSSIBLE MULTIPLE INTERSECTION */

L640:
	if (dshar4_1.vint * fxcor_1.tem[0] >= 0.) {
	    goto L5041;
	} else {
	    goto L753;
	}

/* ...  CALCULATE VALUE OF X WHICH WILL ASSURE CONVERGENCE TO A ROOT */

L5041:
	if (k - knumbr_1.k2 <= 0) {
	    goto L5090;
	} else {
	    goto L5050;
	}
L5090:
	x[0] = znumbr_1.z5em1 * dshar4_1.sqroot;
	goto L5100;
L5050:
	for (j = 1; j <= 2; ++j) {
/* L5060: */
	    fxcor_1.tem[j - 1] = ((*acf * x[j] + *bcf) * x[j] + (*ccf - 
		    dshar4_1.slope)) * x[j] - dshar4_1.vint;
	}
	if (fxcor_1.tem[0] * fxcor_1.tem[1] >= 0.) {
	    goto L5062;
	} else {
	    goto L5061;
	}
L5061:
	x[0] = (x[1] + x[2]) * znumbr_1.z5em1;
	goto L5100;
L5062:
	if (abs(fxcor_1.tem[0]) - abs(fxcor_1.tem[1]) >= 0.) {
	    goto L5064;
	} else {
	    goto L5063;
	}
L5063:
	x[0] = znumbr_1.z12em1 * x[2] - zlit1 * x[1];
	goto L5100;
L5064:
	x[0] = znumbr_1.z12em1 * x[1] - zlit1 * x[2];

/* ...  ITERATE FOR ROOT OF CUBIC */

L5100:
/* Computing MIN */
	d__1 = max(x[0],znumbr_1.z0);
	x[0] = min(d__1,dshar4_1.sqroot);
	fxcor_1.tem[0] = znumbr_1.z3 * dshar4_1.seg[2];
	fxcor_1.tem[1] = znumbr_1.z2 * dshar4_1.seg[3];
	fxcor_1.tem[2] = dshar4_1.seg[4] - dshar4_1.slope;
	for (m = 1; m <= 100; ++m) {
	    fxcor_1.tem[3] = (fxcor_1.tem[0] * x[0] + fxcor_1.tem[1]) * x[0] 
		    + fxcor_1.tem[2];
	    if (abs(fxcor_1.tem[3]) - zlit2 >= 0.) {
		goto L4009;
	    } else {
		goto L4008;
	    }
L4008:
	    x[0] += znumbr_1.z1em6;
	    goto L5200;
L4009:
	    fxcor_1.tem[3] = (((*acf * x[0] + *bcf) * x[0] + (*ccf - 
		    dshar4_1.slope)) * x[0] - dshar4_1.vint) / fxcor_1.tem[3];

/* ...  ACCEPT ROOT WHEN CORRECTION TERM IS LESS THAN .000001*X */

	    if (abs(fxcor_1.tem[3]) < znumbr_1.z1em6 * abs(x[0])) {
		goto L5300;
	    }
/* L5110: */
	    x[0] -= fxcor_1.tem[3];
L5200:
	    ;
	}
	aerr_(&c_b82, "DDTABC  ", (ftnlen)8);
	goto L1000;

/* ...  IF THE ROOT IS WITHIN THE SEGMENT, */
/* ...  FACTOR OUT THE ROOT X,FOUND BY ITERATION, AND SOLVE */
/* ...  THE RESULTING QUADRATIC */

L5300:
	if (x[0] < 0.) {
	    goto L636;
	} else if (x[0] == 0) {
	    goto L641;
	} else {
	    goto L644;
	}
L636:
	j = 0;
	goto L642;
L644:
	if (x[0] - dshar4_1.sqroot <= 0.) {
	    goto L641;
	} else {
	    goto L636;
	}
L48:
	i__2 = j;
	for (k = 1; k <= i__2; ++k) {

/* ...  USING U COORD. OF INTERSECTION POINT,SOLVE CUBIC FOR V COORD. */

	    dshar4_1.param[2] = ((*acf * x[k - 1] + *bcf) * x[k - 1] + *ccf) *
		     x[k - 1];

/* ...  CALCULATE DIR. DIST. TO CUBIC AND TEST AGAINST PRESENT VALUE */

/* Computing 2nd power */
	    d__1 = x[k - 1] - dshar4_1.upp;
/* Computing 2nd power */
	    d__2 = dshar4_1.param[2] - dshar4_1.vpp;
	    fxcor_1.tem[0] = sqrt(d__1 * d__1 + d__2 * d__2);
	    if (fxcor_1.tem[0] - (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) 
		    >= 0.) {
		goto L51;
	    } else {
		goto L49;
	    }
L49:
	    d__1 = (x[k - 1] - dshar4_1.upp) * dshar4_1.unn + (dshar4_1.param[
		    2] - dshar4_1.vpp) * dshar4_1.vnn;
	    fxcor_1.tem[0] = d_sign(fxcor_1.tem, &d__1);
	    if (isv_1.iop[ifxcor_1.is - 1] <= 0) {
		goto L52;
	    } else {
		goto L50;
	    }
L50:
	    if (fxcor_1.tem[0] >= 0.) {
		goto L52;
	    } else {
		goto L51;
	    }
L52:
	    sv_1.s[ifxcor_1.is - 1] = fxcor_1.tem[0];

/* ...  SAVE SUBSCRIPT OF U COORD. OF FIRST POINT OF SEGMENT */

	    ifxcor_1.iseg = i__;

/* ...  SAVE U COORD. OF SURFACE POINT */

	    dshar4_1.savpar[3] = x[k - 1];

/* ...  SAVE SINN AND COSS FOR SEGMENT AND V COORD. OF SURFACE POINT */

	    for (n = 1; n <= 3; ++n) {
/* L53: */
		dshar4_1.savpar[n - 1] = dshar4_1.param[n - 1];
	    }
	    savc = dshar4_1.seg[4];
L51:
	    ;
	}
	if (ldef_1.subflg) {
	    goto L9000;
	}

/* ...  SET INDEX TO LOOK AT NEXT SEGMENT OR FIRST SEGMENT */

L1000:
	if (ifxcor_1.icheck < 0) {
	    goto L2010;
	} else if (ifxcor_1.icheck == 0) {
	    goto L2020;
	} else {
	    goto L2000;
	}
L2000:
	i__ -= knumbr_1.k7;
	goto L1001;
L2010:
	i__ += knumbr_1.k7;
	goto L1001;
L2020:
	i__ += knumbr_1.k7 * l * (knumbr_1.k2 * (l % knumbr_1.k2) - 
		knumbr_1.k1);
	if (i__ < klit3) {
	    goto L2030;
	}
	if (i__ < ifxcor_1.nwds) {
	    goto L1001;
	}
	ifxcor_1.icheck = 1;
	i__ = i__ - knumbr_1.k7 * l - knumbr_1.k7;
	goto L1001;
L2030:
	ifxcor_1.icheck = -1;
	i__ = i__ + knumbr_1.k7 * l + knumbr_1.k7;
L1001:
	;
    }
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - znumbr_1.z1e38 >= 0.) {
	goto L1002;
    } else {
	goto L9000;
    }

/* ...  CALCULATE SURFACE NORMAL IN U-V-W COORD. SYSTEM */

L9000:
    aarg1 = (znumbr_1.z3 * d__[ifxcor_1.iseg + 2] * dshar4_1.savpar[3] + 
	    znumbr_1.z2 * d__[ifxcor_1.iseg + 3]) * dshar4_1.savpar[3] + savc;
    aarg2 = atan(aarg1);
    fxcor_1.tem[2] = znumbr_1.z0 - sin(aarg2);
    fxcor_1.tem[4] = cos(aarg2);
    fxcor_1.tem[3] = fxcor_1.tem[2] * dshar4_1.savpar[1] - fxcor_1.tem[4] * 
	    dshar4_1.savpar[0];
    fxcor_1.tem[4] = fxcor_1.tem[2] * dshar4_1.savpar[0] + fxcor_1.tem[4] * 
	    dshar4_1.savpar[1];

/* ...  TRANSFORM SURFACE POINT INTO U-V-W COORD. SYSTEM */

    dshar4_1.param[0] = dshar4_1.savpar[3] * dshar4_1.savpar[1] - 
	    dshar4_1.savpar[2] * dshar4_1.savpar[0] + d__[ifxcor_1.iseg];
    dshar4_1.param[1] = dshar4_1.savpar[3] * dshar4_1.savpar[0] + 
	    dshar4_1.savpar[2] * dshar4_1.savpar[1] + d__[ifxcor_1.iseg + 1];

/* ...  TRANSFORM SURFACE POINT AND NORMAL INTO X-Y-Z COORD. SYSTEM */

    j = ifxcor_1.is;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.spl[i__ + j * 3 - 4] = sv_1.sp[j * 3 - 3];
	sv_1.snl[i__ + j * 3 - 4] = sv_1.sn[j * 3 - 3];
	sv_1.sp[i__ + j * 3 - 4] = r0[i__ - 1] * dshar4_1.param[0] + r0[i__ + 
		2] * dshar4_1.param[1] + r0[i__ + 5] * wp;
	fxcor_1.tem[i__ + 6] = r0[i__ - 1] * fxcor_1.tem[3] + r0[i__ + 2] * 
		fxcor_1.tem[4];
	sv_1.sn[i__ + j * 3 - 4] = fxcor_1.tem[i__ + 6];
/* L9001: */
    }

/* ...  SAVE SEGMENT INDEX */

    d__[13] = (doublereal) ifxcor_1.iseg;
    isqls = ifxcor_1.iseqno;
    iitbsg[iip - 1] = ifxcor_1.iseg;

/* ...  CALCULATE 3D DIRECTED DISTANCE */

/* Computing 2nd power */
    d__2 = sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.tp[ifxcor_1.is * 3 - 3];
/* Computing 2nd power */
    d__3 = sv_1.sp[ifxcor_1.is * 3 - 2] - sv_1.tp[ifxcor_1.is * 3 - 2];
/* Computing 2nd power */
    d__4 = sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.tp[ifxcor_1.is * 3 - 1];
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 + d__4 * d__4);
    sv_1.s[ifxcor_1.is - 1] = d_sign(&d__1, &sv_1.s[ifxcor_1.is - 1]);
    ++icount;
L29:
    return 0;

/* ...  UNABLE TO FIND DIRECTED DISTANCE */

L1002:
    ifxcor_1.ier = knumbr_1.k1;
    goto L29;
} /* ddtabc_ */

#undef coss
#undef sinn
#undef sinl
#undef cosl
#undef ccf
#undef bcf
#undef acf
#undef vn
#undef un
#undef vp
#undef up
#undef sq
#undef h2
#undef g2
#undef c1
#undef b1
#undef a1
#undef x


