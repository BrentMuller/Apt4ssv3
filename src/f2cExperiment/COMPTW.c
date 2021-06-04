/* COMPTW.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__4 = 4;
static integer c__3 = 3;

/* *** SOURCE FILE : M0004285.V01   *** */


/* Subroutine */ int comptw_(doublereal *bcn, doublereal *p, doublereal *u, 
	doublereal *v, integer *irr)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal a, b, c__, d__, e, f, g, h__;
    static integer i__, l;
    static doublereal a2, a3;
    static integer ic;
    static doublereal am[16]	/* was [4][4] */, wa, wb, rh[12]	/* 
	    was [4][3] */, wc, wd;
    static integer ir, ier;
    static doublereal eps;
    extern /* Subroutine */ int gelg_(doublereal *, doublereal *, doublereal *
	    , integer *, integer *, integer *);
    static integer idiag;

/* ------THIS SUBROUTINE ACCEPTS AS INPUT A PARTIALLY DEFINED COONS */
/* ------MATRIX ( TWIST VECTORS ARE STILL UNKNOWN ) AND FOUR SPACE */
/* ------POINTS P(4,) EACH WITH ASSOCIATED U,V VALUES. */
/* ------AFTER EXECUTION THE ROUTINE RETURNS WITH FOUR TWIST VECTORS */
/* ------WHICH ARE LOADED INTO APPROPRIATE POSITIONS OF THE BCN MATRIX */
/* ------ THE COONS MATRIX PASSES THRU THE FOUR INPUT POINTS */
/* ------AT THE INPUT U,V PARAMETER VALUES */
    /* Parameter adjustments */
    --v;
    --u;
    p -= 5;
    bcn -= 16;

    /* Function Body */
    idiag = 5395;
/* ------SET UP A 4 X 4 SYSTEM OF EQUATIONS AND SOLVE BY CALL TO GELG */
    for (i__ = 1; i__ <= 4; ++i__) {
/* ------EVALUATE COONS BLENDING FUNCTIONS FOR U(I) AND V(I) */
/* Computing 2nd power */
	d__1 = u[i__];
	a2 = d__1 * d__1;
	a3 = a2 * u[i__];
	d__ = a3 - a2;
	a = d__ + d__ - a2 + 1;
	b = -a + 1;
	c__ = d__ - a2 + u[i__];
/* Computing 2nd power */
	d__1 = v[i__];
	a2 = d__1 * d__1;
	a3 = a2 * v[i__];
	h__ = a3 - a2;
	e = h__ + h__ - a2 + 1;
	f = -e + 1;
	g = h__ - a2 + v[i__];
/* ------NOW GENERATE THE I TH COEFFICIENT ROW */
	am[i__ - 1] = c__ * g;
	am[i__ + 3] = c__ * h__;
	am[i__ + 7] = d__ * g;
	am[i__ + 11] = d__ * h__;
/* ------NOW GENERATE THE VECTOR COMPONENTS OF THE RIGHT HAND SIDE */
	for (l = 1; l <= 3; ++l) {
	    wa = (bcn[l + 15] * e + bcn[l + 27] * f + bcn[l + 39] * g + bcn[l 
		    + 51] * h__) * a;
	    wb = (bcn[l + 18] * e + bcn[l + 30] * f + bcn[l + 42] * g + bcn[l 
		    + 54] * h__) * b;
	    wc = (bcn[l + 21] * e + bcn[l + 33] * f) * c__;
	    wd = (bcn[l + 24] * e + bcn[l + 36] * f) * d__;
/* ------RH IS THE DESIRED COEEFICIENT */
	    rh[i__ + (l << 2) - 5] = p[i__ + (l << 2)] - wa - wb - wc - wd;
/* L100: */
	}
    }
    eps = 1e-13;
    gelg_(rh, am, &eps, &c__4, &c__3, &ier);
    *irr = idiag + 1;
    if (ier != 0) {
	return 0;
    }
/* ------RH NOW CONTAINS THE VECTOR SOLUTION SET (TWIST VECTORS) */
/* ------FINALLY LOAD THESE INTO BCN MATRIX */
    for (i__ = 1; i__ <= 4; ++i__) {
	ir = 3;
	ic = 3;
	if (i__ % 2 == 0) {
	    ic = 4;
	}
	if (i__ > 2) {
	    ir = 4;
	}
	for (l = 1; l <= 3; ++l) {
	    bcn[l + (ir + (ic << 2)) * 3] = rh[i__ + (l << 2) - 5];
/* L200: */
	}
    }
    *irr = 0;
    return 0;
} /* comptw_ */

