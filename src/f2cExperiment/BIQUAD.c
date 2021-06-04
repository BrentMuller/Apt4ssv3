/* BIQUAD.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000601.V01   *** */

/* Subroutine */ int biquad_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *d__, doublereal *e, doublereal *rts, integer *nz)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal smal = 1e-14;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal p, q, r__, s, a1, b1, c1, d1, e1, dd, ak, al, am, tr, 
	    res, disc, trcb;
    static integer ntem;
    static doublereal temp[3], trsq;
    extern /* Subroutine */ int gcubic_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);

/* ------THIS PROGRAM SOLVES FOR THE REAL ROOTS OF A BIQUADRATIC */
/* ------A*X**4+B*X**3+C*X**2+D*X+E=0.  THE ROOTS ARE THEN LOADED */
/* ------INTO THE ARRAY RTS.  NZ GIVES THE TOTAL NUMBER OF ROOTS. */
    /* Parameter adjustments */
    --rts;

    /* Function Body */
    rts[1] = 9999.f;
    rts[2] = 9999.f;
    rts[3] = 9999.f;
    rts[4] = 9999.f;
    if (abs(*a) < smal) {
	goto L100;
    }
/* ------ TRANSFORM THE POLYNOM BY THE EQUATION X=Y-B/4A TO ELIM- */
/* ------ INATE THE CUBIC TERM.  THEN UNITIZE THE COEFFICIENT */
/* ------ OF THE RESULTING QUARTIC EQUATION */
    tr = *b / (*a * 4.f);
    trsq = tr * tr;
    trcb = tr * trsq;
    a1 = 1.f;
    b1 = 0.f;
    c1 = trsq * 6.f + (*b * -3.f * tr + *c__) / *a;
    d1 = trcb * -4.f + (*b * 3.f * trsq - *c__ * 2.f * tr + *d__) / *a;
    e1 = trsq * trsq + (-(*b) * trcb + *c__ * trsq - *d__ * tr + *e) / *a;
/* ------ SETUP AND SOLVE THE RESOLVENT CUBIC(HALL KNIGHT,SEC 583) */
    p = 1.f;
    q = c1 + c1;
    r__ = c1 * c1 - e1 * 4.f;
    s = -d1 * d1;
    gcubic_(&p, &q, &r__, &s, temp, &ntem);
    res = -1.f;
    i__1 = ntem;
    for (i__ = 1; i__ <= i__1; ++i__) {
	res = temp[i__ - 1];
	if (res > zero) {
	    goto L30;
	}
/* L20: */
    }
    *nz = 0;
    return 0;
L30:
    ak = sqrt(res);
    am = (res + c1 + d1 / ak) * .5f;
    al = (res + c1 - d1 / ak) * .5f;
/* ------ NOW THE BIQUADRATIC RESOLVES INTO TWO QUADRATICS */
/* ------THE FIRST QUADRATIC IS Y**2+AK*Y+AL=0  OTHER IS Y**2-AK*Y+AM=0 */
    disc = ak * ak - al * 4.f;
    *nz = 0;
    if (disc < zero) {
	goto L40;
    }
    *nz = 2;
    dd = sqrt(disc);
    rts[1] = (-ak + dd) / 2.f - tr;
    rts[2] = (-ak - dd) / 2.f - tr;
L40:
    disc = ak * ak - am * 4.f;
    if (disc < zero) {
	goto L50;
    }
    dd = sqrt(disc);
    rts[*nz + 1] = (ak + dd) / 2.f - tr;
    rts[*nz + 2] = (ak - dd) / 2.f - tr;
    *nz += 2;
L50:
    return 0;
L100:
    gcubic_(b, c__, d__, e, &rts[1], nz);
    return 0;
} /* biquad_ */

