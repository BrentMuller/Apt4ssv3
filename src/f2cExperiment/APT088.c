/* APT088.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal b, c__, d__[12], dx1, dx2, sb, tem[3], temp, v[3], x2, y2;
} dshar6_;

#define dshar6_1 dshar6_

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
    integer i__, inc, i1, j, j1, k, l, lim, l1, m, n, nm1;
} ishr17_;

#define ishr17_1 ishr17_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__14 = 14;
static integer c__35 = 35;
static integer c__4 = 4;

/* *** SOURCE FILE : M0002722.V08   *** */

/* .....FORTRAN SUBROUTINE  ....APT088         8/68                 HG,RN */
/* .....FORTRAN SUBROUTINE             APT088...              3/1/68   GK */
/*                      VECTOR USED IN THE XYZ CASE TO GENERATE A */
/*                      CANTED TABCYL PARALLEL TO VV */
/*              JJ      INTEGER TRANSFORMATION INDICATOR */
/*                      1 = TRANSFORMATION MATRIX DESIRED */
/*                      0 = NO TRANSFORMATION */
/*              DD      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      TRANSFORMATION MATRIX */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT040 */
/*              SUBROUTINE          APT087 */
/*              SUBROUTINE          APT094 */
/*              REAL FUNCTION       ATAN */
/*              REAL FUNCTION       ATAN2 */
/*              LOGICAL FUNCTION    CKDEF */
/*              REAL FUNCTION       COS */
/*              SUBROUTINE          DOTF */
/*              SUBROUTINE          ERROR */
/*              REAL FUNCTION       MINO */
/*              REAL FUNCTION       SIN */
/*              REAL FUNCTION       SQRT */
/*              SUBROUTINE          TABTAP */
/*              LOGICAL FUNCTION    ZVECT */

/* Subroutine */ int apt088_(doublereal *a, integer *mm, integer *nn, integer 
	*kk, integer *ll, integer *jj, doublereal *dottab)
{
    /* Initialized data */

    static integer k21 = 21;
    static integer k14 = 14;
    static doublereal zlit1 = .707;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11, d__12, d__13, d__14, d__15, d__16;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), d_sign(doublereal *, doublereal *
	    ), sqrt(doublereal);
    integer pow_ii(integer *, integer *);
    double atan2(doublereal, doublereal), atan(doublereal);

    /* Local variables */
#define r__ ((doublereal *)&dshar6_1 + 17)
#define u ((doublereal *)&dshar6_1 + 20)
#define x ((doublereal *)&dshar6_1 + 24)
#define y ((doublereal *)&dshar6_1 + 25)
#define a1 ((doublereal *)&dshar6_1 + 20)
#define a2 ((doublereal *)&dshar6_1 + 17)
#define b1 ((doublereal *)&dshar6_1 + 18)
#define b2 ((doublereal *)&dshar6_1 + 19)
#define d1 ((doublereal *)&dshar6_1 + 14)
#define s1 ((doublereal *)&dshar6_1 + 18)
#define t1 ((doublereal *)&dshar6_1 + 19)
#define ga ((doublereal *)&dshar6_1 + 20)
#define al ((doublereal *)&dshar6_1 + 17)
#define sq ((doublereal *)&dshar6_1 + 17)
#define ta ((doublereal *)&dshar6_1 + 18)
#define tb ((doublereal *)&dshar6_1 + 19)
    static integer kp;
#define ga1 ((doublereal *)&dshar6_1 + 19)
#define se2 ((doublereal *)&dshar6_1 + 24)
#define dy1 ((doublereal *)&dshar6_1 + 17)
#define dy2 ((doublereal *)&dshar6_1 + 18)
#define can ((doublereal *)&_BLNK__1 + 40)
#define tab ((doublereal *)&_BLNK__1 + 40)
#define phi ((doublereal *)&dshar6_1 + 20)
#define cen1 ((doublereal *)&dshar6_1 + 17)
#define cen2 ((doublereal *)&dshar6_1 + 18)
#define cmin ((doublereal *)&dshar6_1 + 14)
#define cmax ((doublereal *)&dshar6_1 + 25)
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
#define rotm ((doublereal *)&_BLNK__1 + 41)
    extern /* Subroutine */ int apt040_(doublereal *, doublereal *), apt094_(
	    integer *, doublereal *, doublereal *), apt089_(doublereal *);
#define sl1sq ((doublereal *)&dshar6_1 + 19)
#define sl2sq ((doublereal *)&dshar6_1 + 20)
    extern logical ckdef_(doublereal *);
#define delta ((doublereal *)&dshar6_1 + 25)
#define dcmax ((doublereal *)&dshar6_1 + 14)
#define canon ((doublereal *)&_BLNK__1)
    static integer kkkkk;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    extern logical zvect_(doublereal *);
#define curti1 ((doublereal *)&dshar6_1 + 24)
#define curti2 ((doublereal *)&dshar6_1 + 25)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define center ((doublereal *)&dshar6_1 + 18)
#define curvrg ((doublereal *)&dshar6_1 + 19)



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */










/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  6.  DSHARE BLOCK 6  *** */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 17.  ISHARE17 BLOCK  *** */

/*   TABCYL SHARED INTEGER VARIABLES */
/*   SOME OF THESE MAY BE ONLY USED AS LOCAL VARIABLES */







/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/*        ARITHMETIC STATEMENT FUNCTIONS */
    /* Parameter adjustments */
    --dottab;
    --a;

    /* Function Body */
/*        INITIALIZATION AND DIAGNOSTICS */
    ldef_1.unflag = FALSE_;
    ishr17_1.n = *nn;
    ishr17_1.i__ = knumbr_1.k7 * ishr17_1.n + k21;
    i__1 = ishr17_1.i__;
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= i__1; ++ishr17_1.i1) {
/* L99: */
	tab[ishr17_1.i1 - 1] = dottab[ishr17_1.i1];
    }
/*        TEST SLOPE OR NORMAL AT FIRST POINT */
    ishr17_1.k = *kk;
    dshar6_1.b = tab[0];
    if (ishr17_1.k < knumbr_1.k2) {
	goto L100;
    }
    d__1 = (dshar6_1.b - znumbr_1.z90) * znumbr_1.degrad;
    d__2 = cos(d__1);
/* Computing MAX */
    d__4 = abs(d__2);
    d__3 = max(d__4,znumbr_1.z1em9);
    dshar6_1.b = sin(d__1) / d_sign(&d__3, &d__2);
    ishr17_1.k = knumbr_1.k1;
/*        TEST SLOPE OR NORMAL AT SECOND POINT */
L100:
    ishr17_1.l = *ll;
    dshar6_1.c__ = tab[1];
    if (ishr17_1.l < knumbr_1.k2) {
	goto L110;
    }
    d__1 = (dshar6_1.c__ - znumbr_1.z90) * znumbr_1.degrad;
    d__2 = cos(d__1);
/* Computing MAX */
    d__4 = abs(d__2);
    d__3 = max(d__4,znumbr_1.z1em9);
    dshar6_1.c__ = sin(d__1) / d_sign(&d__3, &d__2);
    ishr17_1.l = knumbr_1.k1;
/*        TEST TRANSFORMATION MATRIX */
L110:
    ishr17_1.j = *jj;
    if (ishr17_1.j == knumbr_1.k1) {
	goto L130;
    }
    for (ishr17_1.i1 = 2; ishr17_1.i1 <= 12; ++ishr17_1.i1) {
/* L120: */
	dshar6_1.d__[ishr17_1.i1 - 1] = znumbr_1.z0;
    }
    dshar6_1.d__[0] = znumbr_1.z1;
    dshar6_1.d__[5] = znumbr_1.z1;
    dshar6_1.d__[10] = znumbr_1.z1;
    goto L150;
L130:
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= 12; ++ishr17_1.i1) {
/* L140: */
	dshar6_1.d__[ishr17_1.i1 - 1] = tab[ishr17_1.i1 + 4];
    }
L150:
    if (! ckdef_(dshar6_1.d__)) {
	goto L160;
    }
    ldef_1.unflag = TRUE_;
    error_(&c__14, "APT088  ", (ftnlen)8);
/*        SET NUMBER OF POINT COORDINATES. IF XYZ, TEST AXIS VECTOR AND */
/*        OMISSION OF SLOPES */
L160:
    ishr17_1.m = *mm;
    ishr17_1.inc = knumbr_1.k2;
    if (ishr17_1.m < knumbr_1.k6) {
	goto L180;
    }
    ishr17_1.inc = knumbr_1.k3;
    kkkkk = ishr17_1.i__;
    apt040_(dshar6_1.v, &tab[2]);
    ishr17_1.i__ = kkkkk;
    if (zvect_(dshar6_1.v)) {
	goto L170;
    }
    ldef_1.unflag = TRUE_;
    error_(&knumbr_1.k32, "APT088  ", (ftnlen)8);
L170:
    if (ishr17_1.k + ishr17_1.l == 0) {
	goto L180;
    }
    ldef_1.unflag = TRUE_;
    error_(&c__35, "APT088  ", (ftnlen)8);
/*        TEST WHETHER POINTS DEFINED */
L180:
    ishr17_1.lim = ishr17_1.n * ishr17_1.inc;
    i__1 = ishr17_1.lim;
    i__2 = ishr17_1.inc;
    for (ishr17_1.i1 = 1; i__2 < 0 ? ishr17_1.i1 >= i__1 : ishr17_1.i1 <= 
	    i__1; ishr17_1.i1 += i__2) {
	if (ckdef_(&tab[ishr17_1.i1 + 16])) {
	    goto L200;
	}
/* L190: */
    }
    goto L210;
L200:
    ldef_1.unflag = TRUE_;
    error_(&knumbr_1.k33, "APT088  ", (ftnlen)8);
/*        TEST FOR IDENTICAL CONSECUTIVE POINTS */
L210:
    ishr17_1.nm1 = ishr17_1.inc + 1;
    i__2 = ishr17_1.lim;
    i__1 = ishr17_1.inc;
    for (ishr17_1.i1 = ishr17_1.nm1; i__1 < 0 ? ishr17_1.i1 >= i__2 : 
	    ishr17_1.i1 <= i__2; ishr17_1.i1 += i__1) {
	kp = ishr17_1.i1 + ishr17_1.inc - knumbr_1.k1;
	i__3 = kp;
	for (ishr17_1.j1 = ishr17_1.i1; ishr17_1.j1 <= i__3; ++ishr17_1.j1) {
	    ishr17_1.l1 = ishr17_1.j1 - ishr17_1.inc + 17;
	    if (tab[ishr17_1.j1 + 16] != tab[ishr17_1.l1 - 1]) {
		goto L230;
	    }
/* L220: */
	}
	error_(&knumbr_1.k34, "APT088  ", (ftnlen)8);
	goto L240;
L230:
	;
    }
    if (! ldef_1.unflag) {
	goto L250;
    }
L240:
    apt094_(&c__4, &a[1], tab);
    return 0;
/*        MOVE POINTS AND INITIALIZE FIRST PORTION OF CANONICAL FORM */
L250:
    i__1 = ishr17_1.lim;
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= i__1; ++ishr17_1.i1) {
	ishr17_1.j1 = ishr17_1.lim + knumbr_1.k18 - ishr17_1.i1;
	kp = ishr17_1.i__ + knumbr_1.k1 - ishr17_1.i1;
/* L260: */
	tab[kp - 1] = tab[ishr17_1.j1 - 1];
    }
    tab[0] = (doublereal) ishr17_1.i__;
    tab[10] = (doublereal) (ishr17_1.n + knumbr_1.k2);
    tab[11] = (doublereal) k14;
/*        DEFINE ROTATION MATRIX */
    if (ishr17_1.m < knumbr_1.k6) {
	goto L280;
    }
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= 3; ++ishr17_1.i1) {
/* L270: */
	dotf_(&rotm[ishr17_1.i1 + 5], dshar6_1.v, &dshar6_1.d__[(ishr17_1.i1 
		<< 2) - 4]);
    }
    ishr17_1.i__ = kkkkk;
    goto L300;
L280:
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= 3; ++ishr17_1.i1) {
/* L290: */
	rotm[ishr17_1.i1 + 5] = znumbr_1.z0;
    }
    kp = min(ishr17_1.m,knumbr_1.k3);
    rotm[kp + 5] = znumbr_1.z1;
L300:
    kp = knumbr_1.k0;
    *d1 = znumbr_1.zm1;
    if (abs(rotm[8]) <= zlit1) {
	goto L310;
    }
    kp = knumbr_1.km1;
    *d1 = znumbr_1.z1;
L310:
/* Computing 2nd power */
    d__1 = rotm[kp + 8];
    rotm[kp + 5] = *d1 * sqrt(znumbr_1.z1 - d__1 * d__1);
    kkkkk = 1;
    dshar6_1.temp = rotm[kp + 8] / rotm[kp + 5];
    kkkkk = 2;
    rotm[3] = -dshar6_1.temp * rotm[6];
    rotm[kp + 2] = znumbr_1.z0;
    dshar6_1.tem[0] = *d1 / rotm[kp + 5];
    kp = -kp;
/* ---    CORRECTION TO ROTATION MATRIX FOR SOME TABCYLS */
    rotm[kp + 4] = *d1 * dshar6_1.temp * rotm[kp + 7] * pow_ii(&knumbr_1.km1, 
	    &kp);
    rotm[kp + 1] = -rotm[6] * dshar6_1.tem[0];
    rotm[0] = rotm[kp + 7] * dshar6_1.tem[0];
/*        MOVE POINTS TO PROPER PLACE IN CANONICAL FORM */
    kp = ishr17_1.i__ + knumbr_1.k1 - ishr17_1.lim;
    ishr17_1.l1 = knumbr_1.k19;
    i__1 = ishr17_1.n;
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= i__1; ++ishr17_1.i1) {
	i__2 = ishr17_1.inc;
	for (ishr17_1.j1 = 1; ishr17_1.j1 <= i__2; ++ishr17_1.j1) {
	    ishr17_1.l1 += knumbr_1.k1;
	    tab[ishr17_1.l1 - 1] = tab[kp - 1];
/* L320: */
	    kp += knumbr_1.k1;
	}
	for (ishr17_1.j1 = ishr17_1.inc; ishr17_1.j1 <= 6; ++ishr17_1.j1) {
	    ishr17_1.l1 += knumbr_1.k1;
/* L330: */
	    tab[ishr17_1.l1 - 1] = znumbr_1.z0;
	}
    }
/*        ZERO BALANCE OF CANONICAL FORM */
    for (ishr17_1.i1 = 13; ishr17_1.i1 <= 19; ++ishr17_1.i1) {
/* L340: */
	tab[ishr17_1.i1 - 1] = znumbr_1.z0;
    }
    tab[ishr17_1.i__ - 2] = znumbr_1.z0;
    tab[ishr17_1.i__ - 1] = znumbr_1.z0;
/*        TRANSFORM AND ROTATE POINTS, USING D MATRIX */
    ishr17_1.i1 = 0;
L350:
    ishr17_1.i1 += knumbr_1.k7;
    switch (ishr17_1.m) {
	case 1:  goto L390;
	case 2:  goto L390;
	case 3:  goto L390;
	case 4:  goto L380;
	case 5:  goto L375;
	case 6:  goto L360;
    }
/*        XYZ CASE */
L360:
    for (ishr17_1.j1 = 1; ishr17_1.j1 <= 3; ++ishr17_1.j1) {
	dotf_(&dshar6_1.tem[ishr17_1.j1 - 1], &dshar6_1.d__[(ishr17_1.j1 << 2)
		 - 4], &tab[ishr17_1.i1 + 12]);
/* L370: */
	dshar6_1.tem[ishr17_1.j1 - 1] += dshar6_1.d__[(ishr17_1.j1 << 2) - 1];
    }
    dotf_(&tab[ishr17_1.i1 + 12], rotm, dshar6_1.tem);
    dotf_(&tab[ishr17_1.i1 + 13], &rotm[3], dshar6_1.tem);
    tab[ishr17_1.i1 + 14] = znumbr_1.z0;
    goto L410;
/*        RTHETA AND THETAR CASES-FIRST TRANSFORM TO RECTANGULAR */
/*        THETAR CASE */
L375:
    dshar6_1.tem[2] = tab[ishr17_1.i1 + 13];
    tab[ishr17_1.i1 + 13] = tab[ishr17_1.i1 + 12];
    tab[ishr17_1.i1 + 12] = dshar6_1.tem[2];
L380:
    dshar6_1.tem[0] = tab[ishr17_1.i1 + 12];
    dshar6_1.tem[1] = tab[ishr17_1.i1 + 13] * znumbr_1.degrad;
    tab[ishr17_1.i1 + 12] = dshar6_1.tem[0] * cos(dshar6_1.tem[1]);
    tab[ishr17_1.i1 + 13] = dshar6_1.tem[0] * sin(dshar6_1.tem[1]);
/*        NOX, NOY, NOZ, RTHETA,AND THETAR CASES- TRANSFORM COORDINATES */
L390:
    dshar6_1.x2 = tab[ishr17_1.i1 + 12];
    dshar6_1.y2 = tab[ishr17_1.i1 + 13];
    *d1 = znumbr_1.z1;
    goto L460;
/*        STORE ONLY DESIRED COORDINATES */
L400:
    tab[ishr17_1.i1 + 12] = dshar6_1.tem[0];
    tab[ishr17_1.i1 + 13] = -dshar6_1.tem[2];
L410:
    if (ishr17_1.i1 < ishr17_1.n * 7) {
	goto L350;
    }
/*        TRANSFORM AND ROTATE SLOPES- CONSIDER AS POINTS. */
    if (ishr17_1.k == 0) {
	goto L450;
    }
    ishr17_1.i1 = 0;
/* L420: */
    dshar6_1.y2 = dshar6_1.b;
L430:
    *d1 = znumbr_1.z0;
    dshar6_1.x2 = znumbr_1.z1;
    goto L460;
L440:
/* Computing MAX */
    d__2 = abs(dshar6_1.tem[0]);
    d__1 = max(d__2,znumbr_1.z1em9);
    dshar6_1.b = -dshar6_1.tem[2] / d_sign(&d__1, dshar6_1.tem);
L450:
    if (ishr17_1.l == 0) {
	goto L490;
    }
    ishr17_1.i1 = knumbr_1.k1;
    dshar6_1.y2 = dshar6_1.c__;
    goto L430;
/*        POINT ROTATION ROUTINE */
L460:
    kp = min(ishr17_1.m,knumbr_1.k3);
    ishr17_1.l1 = kp % knumbr_1.k3;
    kp = (kp + 1) % knumbr_1.k3;
    for (ishr17_1.j1 = 1; ishr17_1.j1 <= 3; ++ishr17_1.j1) {
	dshar6_1.tem[ishr17_1.j1 - 1] = dshar6_1.x2 * dshar6_1.d__[
		ishr17_1.l1] + dshar6_1.y2 * dshar6_1.d__[kp] + *d1 * 
		dshar6_1.d__[(ishr17_1.j1 << 2) - 1];
	kp += knumbr_1.k4;
/* L470: */
	ishr17_1.l1 += knumbr_1.k4;
    }
/*        SAVE ONLY DESIRED COORDINATES */
    if (ishr17_1.m == knumbr_1.k1) {
	dshar6_1.tem[0] = -dshar6_1.tem[1];
    }
    if (ishr17_1.m > knumbr_1.k2) {
	dshar6_1.tem[2] = -dshar6_1.tem[1];
    }
    if ((i__1 = ishr17_1.i1 - knumbr_1.k1) < 0) {
	goto L440;
    } else if (i__1 == 0) {
	goto L480;
    } else {
	goto L400;
    }
/*        ROTATE SECOND SLOPE */
L480:
/* Computing MAX */
    d__2 = abs(dshar6_1.tem[0]);
    d__1 = max(d__2,znumbr_1.z1em9);
    dshar6_1.c__ = -dshar6_1.tem[2] / d_sign(&d__1, dshar6_1.tem);
/*        COMPUTE SEGMENT LENGTHS, SLOPES, AND SLOPE OF AVERAGE */
L490:
    ishr17_1.nm1 = knumbr_1.k7 * (ishr17_1.n - knumbr_1.k1);
    i__1 = ishr17_1.nm1;
    for (ishr17_1.i1 = 7; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	dshar6_1.dx2 = tab[ishr17_1.i1 + 19] - tab[ishr17_1.i1 + 12];
	*dy2 = tab[ishr17_1.i1 + 20] - tab[ishr17_1.i1 + 13];
/* Computing 2nd power */
	d__1 = dshar6_1.dx2;
/* Computing 2nd power */
	d__2 = *dy2;
	*sl2sq = d__1 * d__1 + d__2 * d__2;
	tab[ishr17_1.i1 + 16] = sqrt(*sl2sq);
	tab[ishr17_1.i1 + 15] = atan2(*dy2, dshar6_1.dx2);
/*        CALCULATE SLOPE OF CIRCLE THRU P(N-1),P(N),P(N+1) */
	if (ishr17_1.i1 != knumbr_1.k7) {
	    d__1 = *sl1sq * dshar6_1.dx2 + *sl2sq * dshar6_1.dx1;
/* Computing MAX */
	    d__3 = abs(d__1);
	    d__2 = max(d__3,znumbr_1.z1em9);
	    tab[ishr17_1.i1 + 14] = atan((*sl1sq * *dy2 + *sl2sq * *dy1) / 
		    d_sign(&d__2, &d__1));
	}
	dshar6_1.dx1 = dshar6_1.dx2;
	*dy1 = *dy2;
/* L500: */
	*sl1sq = *sl2sq;
    }
/*        CALCULATION OF ANGLES AND CURVATURE DIFFERENCES */
    *b1 = tab[28] - tab[22];
    if (ishr17_1.k == 0) {
	goto L510;
    }
    tab[21] = atan(dshar6_1.b);
    *a1 = tab[21] - tab[22];
    goto L520;
L510:
    *a1 = znumbr_1.pi - *b1;
    tab[21] = tab[22] - *b1;
    if (ishr17_1.nm1 < 21) {
	goto L531;
    }
L520:
    i__1 = ishr17_1.nm1;
    for (ishr17_1.i1 = 21; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	*a2 = tab[ishr17_1.i1 + 7] - tab[ishr17_1.i1 + 8];
	*b2 = tab[ishr17_1.i1 + 14] - tab[ishr17_1.i1 + 8];
	d__1 = cos(*a2);
	d__2 = cos(*b2);
	d__4 = cos(*b1);
	d__5 = cos(*a1);
/* Computing MAX */
	d__8 = abs(d__1);
	d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
	d__10 = abs(d__2);
	d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
	d__11 = (d__3 = cos(*a2), abs(d__3));
/* Computing MAX */
	d__13 = abs(d__4);
	d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
	d__15 = abs(d__5);
	d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
	d__16 = (d__6 = cos(*b1), abs(d__6));
	tab[ishr17_1.i1 + 10] = -(4.f * (sin(*a2) / d_sign(&d__7, &d__1)) + 
		2.f * (sin(*b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * 
		d__11)) / tab[ishr17_1.i1 + 9] + -(4.f * (sin(*b1) / d_sign(&
		d__12, &d__4)) + 2.f * (sin(*a1) / d_sign(&d__14, &d__5))) * (
		d__16 * (d__16 * d__16)) / tab[ishr17_1.i1 + 2];
	*a1 = *a2;
/* L530: */
	*b1 = *b2;
    }
/*        CALCULATE TERMINAL SLOPE AND EXTERIOR ANGLE */
L531:
    *a2 = tab[ishr17_1.i__ - 14] - tab[ishr17_1.i__ - 13];
    if (ishr17_1.l == 0) {
	goto L540;
    }
    tab[ishr17_1.i__ - 7] = atan(dshar6_1.c__);
    *b2 = tab[ishr17_1.i__ - 7] - tab[ishr17_1.i__ - 13];
    goto L550;
L540:
    *b2 = znumbr_1.pi - *a2;
    tab[ishr17_1.i__ - 7] = tab[ishr17_1.i__ - 13] + *b2;
L550:
    d__1 = cos(*a2);
    d__2 = cos(*b2);
    d__4 = cos(*b1);
    d__5 = cos(*a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(*a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(*b1), abs(d__6));
    tab[ishr17_1.i__ - 11] = -(4.f * (sin(*a2) / d_sign(&d__7, &d__1)) + 2.f *
	     (sin(*b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / 
	    tab[ishr17_1.i__ - 12] + -(4.f * (sin(*b1) / d_sign(&d__12, &d__4)
	    ) + 2.f * (sin(*a1) / d_sign(&d__14, &d__5))) * (d__16 * (d__16 * 
	    d__16)) / tab[ishr17_1.i__ - 19];
    apt089_(&a[1]);
    return 0;
} /* apt088_ */

#undef curvrg
#undef center
#undef bcanon
#undef curti2
#undef curti1
#undef sscan
#undef canon
#undef dcmax
#undef delta
#undef sl2sq
#undef sl1sq
#undef rotm
#undef cmax
#undef cmin
#undef cen2
#undef cen1
#undef phi
#undef tab
#undef can
#undef dy2
#undef dy1
#undef se2
#undef ga1
#undef tb
#undef ta
#undef sq
#undef al
#undef ga
#undef t1
#undef s1
#undef d1
#undef b2
#undef b1
#undef a2
#undef a1
#undef y
#undef x
#undef u
#undef r__


