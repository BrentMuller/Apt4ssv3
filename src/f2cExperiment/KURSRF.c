/* KURSRF.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcomc, ipcolc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n4 = -4;
static integer c__1 = 1;

/* *** SOURCE FILE : M0001074.V02   *** */

/* Subroutine */ int kursrf_(doublereal *r__, doublereal *side, doublereal *
	cx)
{
    /* Initialized data */

    static doublereal dvec[3] = { .13,.23,.33 };
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-19;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__, j, l;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
    static doublereal disc;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static integer lnxt;
    static doublereal denom;
    static integer imiss;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);

/*           /-INPUT */
/*           /-SURFACE POINT, FIRST AND SECOND DERIVATIVES IN R */
/*           /-SIDE(CUTTER SIDE) OF SURFACE =1 OR -1. */
/*           /-OUTPUT */
/*           /-SURFACE CURVATURE ANALYSIS, ALL DATA STORED IN CX */

/*           /-PURPOSE TO COMPUTE PRINCIPAL CURVATURES AND OTHER QUANTITI */
/*           /-RELATED TO SURFACE AT THIS POINT. */

    /* Parameter adjustments */
    --cx;
    --r__;

    /* Function Body */

    for (i__ = 1; i__ <= 24; ++i__) {
/* L5: */
	cx[i__] = zero;
    }

/*           /-COMPUTE G11,G12,G22 */
    dotv_(&cx[13], &r__[5], &r__[5]);
    dotv_(&cx[14], &r__[5], &r__[9]);
    dotv_(&cx[15], &r__[9], &r__[9]);
    cx[16] = one;
/*           /-COMPUTE L11,L12,L22 */
    dotv_(&cx[17], &r__[13], &r__[29]);
    dotv_(&cx[18], &r__[17], &r__[29]);
    dotv_(&cx[19], &r__[21], &r__[29]);
    for (i__ = 17; i__ <= 19; ++i__) {
/* L10: */
	cx[i__] = *side * cx[i__];
    }
    cx[20] = one;
/*           /-COMPUTE COEFFICIENTS OF CURVATURE EQUATION A.KSQ+B.K+C=0 */
/*           /-A=DET(G),B=-(L11*G22-2*L12G12+L22*G11),C=DET(L) */
/* Computing 2nd power */
    d__1 = cx[14];
    cx[21] = cx[13] * cx[15] - d__1 * d__1;
    cx[22] = -(cx[13] * cx[19] - cx[14] * 2.f * cx[18] + cx[15] * cx[17]);
/* Computing 2nd power */
    d__1 = cx[18];
    cx[23] = cx[17] * cx[19] - d__1 * d__1;
    cx[24] = one;
/*           /-SOLVE THIS EQUATION TO OBTAIN TWO PRINCIPAL CURVATURES */
/* Computing 2nd power */
    d__1 = cx[22];
    disc = d__1 * d__1 - cx[21] * 4.f * cx[23];
    disc = max(zero,disc);
    disc = sqrt(disc);
    denom = cx[21] + cx[21];
    cx[1] = (-cx[22] + disc) / denom;
    cx[2] = (-cx[22] - disc) / denom;
    cx[4] = one;
/*           /-FINALLY DETERMINE SPATIAL DIRECTIONS OF THESE CURVATURES */
/*           /- THE DIRECTION OF K IS ACHIEVED BY (-L12+KG12,L11-KG11) */
/*           /- IMISS IS THE COUNT OF THE NUMBER OF MISSES */
    imiss = 0;
    for (i__ = 1; i__ <= 2; ++i__) {
	a = -(cx[18] - cx[i__] * cx[14]);
	b = cx[17] - cx[i__] * cx[13];
	l = i__ << 2;
	if (abs(a) + abs(b) > smal) {
	    goto L50;
	}
/*            /-TRY AGAIN TO OBTAIN A NON ZERO A,B */
	a = -(cx[19] - cx[i__] * cx[15]);
	b = cx[18] - cx[i__] * cx[14];
	if (abs(a) + abs(b) > smal) {
	    goto L50;
	}
	++imiss;
	goto L20;
L50:
	for (j = 1; j <= 3; ++j) {
/* L30: */
	    cx[l + j] = a * r__[j + 4] + b * r__[j + 8];
	}
	vnorm_(&cx[l + 1], &cx[l + 1]);
	cx[l + 4] = one;
	goto L100;
L20:
	;
    }

L100:
    if (imiss == 2) {
	goto L130;
    }
/* -- A GOOD VECTOR WAS OBTAINED, COMPUTE THE OTHER BY CROSS PRODUCT */
    lnxt = l + 4;
    if (l == 8) {
	lnxt = l - 4;
    }
    cross_(&cx[l + 1], &r__[29], &cx[lnxt + 1]);
    vnorm_(&cx[lnxt + 1], &cx[lnxt + 1]);
    cx[lnxt + 4] = one;
    goto L140;
/* -- NO GOOD VECTORS AVAILABLE, GENERATE ANY TWO NORMAL TO R(29) */
L130:
    cross_(dvec, &r__[29], &cx[5]);
    vnorm_(&cx[5], &cx[5]);
    cross_(&cx[5], &r__[29], &cx[9]);
    vnorm_(&cx[9], &cx[9]);
    cx[8] = one;
    cx[12] = one;

L140:

    if (ibugg_1.ibug != 11) {
	goto L60;
    }
    for (i__ = 1; i__ <= 21; i__ += 4) {
	bad_(&c_n4, &c__1, "KRSF", &r__[i__], (ftnlen)4);
/* L70: */
    }
    for (i__ = 1; i__ <= 9; i__ += 4) {
	bad_(&c_n4, &c__1, "CX  ", &cx[i__], (ftnlen)4);
/* L80: */
    }

L60:
    return 0;
} /* kursrf_ */

