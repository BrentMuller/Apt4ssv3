/* GCUBIC.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000630.V01   *** */


/* Subroutine */ int gcubic_(doublereal *p, doublereal *q, doublereal *r__, 
	doublereal *s, doublereal *z__, integer *nz)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal thd = .333333333333333;
    static doublereal smal = 1e-10;
    static doublereal pi = 3.1415926536;
    static doublereal tpio3 = 2.0943951024;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *), pow_dd(
	    doublereal *, doublereal *), cos(doublereal);

    /* Local variables */
    static doublereal a, b, d__, e, f, s1, t1, t2, s2, w1, bh, ds, tr;
    extern doublereal darcos_(doublereal *);

/* ------ MODULAR SCULPTURED SURFACE ROUTINE ALSO SHARED BY PARAMETRIC */
/* ------ SURFACES. GENERAL SOLUTION OF CUBIC EQN. */
/* ------ INPUT ARE COEFFICIENTS OF CUBIC EQN' P*X**3+Q*X**2+R*X+S=0. */
/* ------ OUTPUT IS SET OF REAL ROOTS Z(I), WHERE I=1 TO NZ */
/* ------ NZ IS THE TOTAL NUMBER OF REAL ROOTS. */
/* ------ PROGRAM HANDLES QUADRATICS AND LINEAR EQNS AS SPECIAL CASES */
    /* Parameter adjustments */
    --z__;

    /* Function Body */
    *nz = 0;
    z__[1] = 9999.;
    z__[2] = 9999.;
    z__[3] = 9999.;
    if (abs(*p) < smal) {
	goto L200;
    }
    tr = *q / (*p * 3.f);
    a = (*r__ - *q * tr) / *p;
    b = ((thd * 2 * *q * tr - *r__) * tr + *s) / *p;
    d__ = b * b / 4.f + a * a * a / 27.f;
    bh = -b / 2.f;
    if (d__ >= 0.) {
	goto L10;
    } else {
	goto L20;
    }
L10:
    ds = sqrt(d__);
    t1 = bh + ds;
    t2 = bh - ds;
    s1 = d_sign(&one, &t1);
    s2 = d_sign(&one, &t2);
    d__1 = s1 * t1;
    d__2 = s2 * t2;
    e = s1 * pow_dd(&d__1, &thd) + s2 * pow_dd(&d__2, &thd);
    f = a + e * e;
    d__ = e * e - f * 4.f;
    *nz = 1;
    z__[1] = e - tr;
    if (d__ >= 0.) {
	goto L30;
    } else {
	goto L999;
    }
L30:
    d__ = sqrt(d__);
    z__[2] = (-e + d__) / 2.f - tr;
    z__[3] = (-e - d__) / 2.f - tr;
    *nz = 3;
L999:
    return 0;
L20:
    s2 = sqrt(-d__);
    s1 = bh;
    t1 = sqrt(s1 * s1 + s2 * s2);
    d__1 = s1 / t1;
    t2 = darcos_(&d__1);
    if (s2 < 0.f) {
	t2 += pi;
    }
    bh = pow_dd(&t1, &thd) * 2.f;
    w1 = t2 / 3.f;
    z__[1] = bh * cos(w1) - tr;
    z__[2] = bh * cos(w1 - tpio3) - tr;
    z__[3] = bh * cos(w1 - tpio3 - tpio3) - tr;
    *nz = 3;
    return 0;
L200:
    if (abs(*q) < smal) {
	goto L300;
    }
    d__ = *r__ * *r__ - *q * 4.f * *s;
    if (d__ < 0.f) {
	return 0;
    }
    d__ = sqrt(d__);
    w1 = *q + *q;
    z__[1] = (-(*r__) + d__) / w1;
    z__[2] = (-(*r__) - d__) / w1;
    *nz = 2;
    return 0;
L300:
    if (abs(*r__) < smal) {
	return 0;
    }
    z__[1] = -(*s) / *r__;
    *nz = 1;
    return 0;
} /* gcubic_ */

