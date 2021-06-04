/* BALTOL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001044.V02   *** */

/* Subroutine */ int baltol_(doublereal *r__, doublereal *side, doublereal *
	tc, doublereal *rad, doublereal *td, doublereal *dist, doublereal *
	tol, integer *iok)
{
    /* Initialized data */

    static doublereal smal = 1e-22;
    static doublereal flipck = .99995;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal st[3], fac, ang;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal stlen;

/*           /-PURPOSE IS TO VERIFY THAT CUTTER IS WITHIN TOLERANCE OF */
/*           /-SURFACE AT THIS POINT */
/*           /-IOK=0 IF IT IS AND SET TO NON-ZERO VALUE OTHERWISE */

    /* Parameter adjustments */
    --td;
    --tc;
    --r__;

    /* Function Body */

    fac = *side * *rad;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	st[i__ - 1] = tc[i__] + *dist * td[i__] - r__[i__] - fac * r__[i__ + 
		28];
    }
    dotv_(&stlen, st, st);
    *iok = 0;
/*            /-IF STLEN IS VERY SMALL, ACCEPT THIS RESULT */
    if (stlen < smal) {
	goto L999;
    }
    stlen = sqrt(stlen);
    *iok = 1;
/*            /-IF STLEN EXCEEDS TOLERANCE, DO NOT ACCEPT */
    if (stlen > *tol) {
	goto L999;
    }
/*            /-MEASURE ANGLE FROM NORMAL TO ST */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	st[i__ - 1] = tc[i__] + *dist * td[i__] - r__[i__];
    }
    dotv_(&stlen, st, st);
    if (stlen < smal) {
	goto L999;
    }
    dotv_(&ang, st, &r__[29]);
    ang = ang / sqrt(stlen) * *side;
    *iok = 2;
/*            /-VECTOR LINEUP IS REQUIRED ONLY FOR NON ZERO RADIUS */
    if (*rad > smal && ang < flipck) {
	goto L999;
    }
    *iok = 0;
L999:
    return 0;
} /* baltol_ */

