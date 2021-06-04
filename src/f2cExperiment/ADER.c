/* ADER.f -- translated by f2c (version 20100827).
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

static integer c__2 = 2;

/* *** SOURCE FILE : M0001030.V01   *** */

/* Subroutine */ int ader_(doublereal *dif, doublereal *ta, doublereal *tb, 
	doublereal *a, doublereal *b, doublereal *u, integer *mode, 
	doublereal *area)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal big = 1e8;
    static doublereal smal = 1e-8;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal x, y;
    static integer i1;
    static doublereal ca[3], cb[3], qa, qb, cv[16], xa, xb, ya, yb, xg, xh, 
	    xk, fac, tab[3], tad[3], tbd[3], xaa, xab, xbb, yaa, ybb, yab, 
	    rarb;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal rpra, rprb, rasq, rbsq, drsq, curv[16], recip;
    extern doublereal vdotf_(doublereal *, doublereal *);
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), cncurv_(doublereal *, doublereal *, doublereal *, integer *);

/* ---      PURPOSE IS TO COMPUTE TENSION AND FIRST AND SECOND */
/* ---      PARTIAL DERIVATIVES OF TENSION WITH RESPECT TO A AND B */
/* ---      INPUT CONSISTS OF THE FOLLOWING */
/* ---      CHORD VECTOR DIF OF PARAMETRIC CUBIC */
/* ---      FIRST TANGENT A*TA AND LAST TANGENT VECTOR B*TB */
/* ---      U=PARAMETRIC VALUE AT WHICH TO EVALUATE TENSION */
/* ---      MODE=1 ON FIRST ENTRY -- SETUP SOME INVARIANT VALUES */
/* ---      MODE=0 ON SUBSEQUENT ENTRIES. */
/* ---      OUTPUT IS PLACED IN AREA (1 - 6) AS FOLLOWS. */
/* ---      AREA(1) = K*K*DS WHERE K=CURVATURE AND DS=RATE OF CHANGE */
/* ---      OF ARC LENGTH WITH RESPECT TO COONS PARAMETER U. */
/* ---      AREA(2)= PARTIAL WRT A OF AREA(1) */
/* ---      AREA(3)= PARTIAL WRT B OF AREA(1) */
/* ---      AREA(4)= PARTIAL WRT TO A TWICE OF AREA(1) */
/* ---      AREA(5)= PARTIAL WRT TO A AND B OF AREA(1) */
/* ---      AREA(6)= PARTIAL WRT TO B TWICE OF AREA(1) */


    /* Parameter adjustments */
    --area;
    --tb;
    --ta;
    --dif;

    /* Function Body */

    if (*mode == 0) {
	goto L100;
    }
/* ---IF MODE IS 1 THIS IS FIRST PASS THRU ADER */
/* ---COMPUTE INVARIANT DATA FOR THIS AND SUBSEQUENT CALLS */
/* ---SET UP COONS CANNON FORM OF CURV */
    for (i__ = 1; i__ <= 3; ++i__) {
	i1 = (i__ - 1 << 2) + 1;
	curv[i1 - 1] = zero;
	curv[i1] = dif[i__];
	curv[i1 + 1] = *a * ta[i__];
	curv[i1 + 2] = *b * tb[i__];
/* L10: */
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	curv[i__ + 11] = one;
/* L20: */
	curv[i__ + 13] = zero;
    }
    cross_(&ta[1], &tb[1], tab);
    cross_(&ta[1], &dif[1], tad);
    cross_(&tb[1], &dif[1], tbd);

L100:
/* ---COMPUTE COEFFICIENTS OF DR X DDR WHERE DR X DDR= */
/* ---  XG*A*B*TAB + XH * A * TAD + XK * B * TBD */
/* Computing 2nd power */
    d__1 = *u;
    xg = *u * 6.f - 2.f - d__1 * d__1 * 6.f;
/* Computing 2nd power */
    d__1 = one - *u;
    xh = d__1 * d__1 * 6.f;
/* Computing 2nd power */
    d__1 = *u;
    xk = d__1 * d__1 * -6.f;
/* ---COMPUTE CURVE COEFFICIENTS */
    cncurv_(u, curv, cv, &c__2);

    cross_(&cv[4], &cv[8], &cv[12]);
/* ---COMPUTE DERIVATIVE FRAGMENTS OF DR X DDR */
    for (i__ = 1; i__ <= 3; ++i__) {
	ca[i__ - 1] = *b * tb[i__] * xg + dif[i__] * xh;
	cb[i__ - 1] = -(*a) * ta[i__] * xg + dif[i__] * xk;
/* L120: */
    }
    cross_(&ta[1], ca, ca);
    cross_(&tb[1], cb, cb);
/* ---COMPUTE ALL PARTIAL DERIVATIVES OF (DR X DDR )**2 WRT A NND B */
    x = vdotf_(&cv[12], &cv[12]);
    xa = vdotf_(&cv[12], ca) * 2.f;
    xb = vdotf_(&cv[12], cb) * 2.f;
    xaa = vdotf_(ca, ca) * 2.f;
    xab = (vdotf_(ca, cb) + vdotf_(&cv[12], tab) * xg) * 2.f;
    xbb = vdotf_(cb, cb) * 2.f;

/* ---NEXT COMPUTE ALL PARTIAL DERIVATIVES OF (DR**2)**(-5/2) */
    drsq = vdotf_(&cv[4], &cv[4]);
    drsq = min(big,drsq);
    drsq = max(smal,drsq);
    recip = 1.f / sqrt(drsq);
/* Computing 5th power */
    d__1 = recip, d__2 = d__1, d__1 *= d__1;
    y = d__2 * (d__1 * d__1);
/* Computing 7th power */
    d__1 = recip, d__2 = d__1, d__1 *= d__1, d__2 *= d__1;
    fac = d__2 * (d__1 * d__1) * 5.f;
/* Computing 2nd power */
    d__1 = *u;
    qa = 1.f - *u * 4.f + d__1 * d__1 * 3.f;
/* Computing 2nd power */
    d__1 = *u;
    qb = *u * -2.f + d__1 * d__1 * 3.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	ca[i__ - 1] = ta[i__] * qa;
	cb[i__ - 1] = tb[i__] * qb;
/* L130: */
    }
/* ---COMPUTE INPUT DOT PRODUCTS */
    dotf_(&rpra, &cv[4], ca);
    dotf_(&rprb, &cv[4], cb);
    dotf_(&rarb, ca, cb);
    dotf_(&rasq, ca, ca);
    dotf_(&rbsq, cb, cb);
    ya = -fac * rpra;
    yb = -fac * rprb;
/* ---COMPUTE SECOND ORDER PARTIALS OF Y WRT A AND B */
/* Computing 2nd power */
    d__1 = rpra;
    yaa = fac * (d__1 * d__1 * 7.f / drsq - rasq);
/* Computing 2nd power */
    d__1 = rprb;
    ybb = fac * (d__1 * d__1 * 7.f / drsq - rbsq);
    yab = fac * (rpra * 7.f * rprb / drsq - rarb);

/* ---COMPUTE PARTIALS OF X*Y WRT TO A AND B AND RETURN */
    area[1] = x * y;
    area[2] = xa * y + x * ya;
    area[3] = xb * y + x * yb;
    area[4] = xaa * y + xa * 2.f * ya + x * 2.f * yaa;
    area[6] = xbb * y + xb * 2.f * yb + x * 2.f * ybb;
    area[5] = xab * y + xa * yb + xb * ya + x * yab;

    return 0;
} /* ader_ */

