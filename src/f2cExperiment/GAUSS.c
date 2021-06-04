/* GAUSS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000905.W01   *** */

/* .....FORTRAN SUBROUTINE             GAUSS...               4/1/68   GK */
/* Subroutine */ int gauss_(doublereal *vec1, doublereal *d1, doublereal *
	vec2, doublereal *d2, doublereal *vec3, doublereal *d3, doublereal *
	pt, integer *ir)
{
    /* Initialized data */

    static doublereal eps = .9999;
    static doublereal zero = 0.;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    integer pow_ii(integer *, integer *);

    /* Local variables */
    static doublereal a[12], c__[3];
    static integer i__, j, k, m;
    static doublereal q, coe5, erg1, erg2, erg3, coe9, coe10, asav[4];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer jmax;

    /* Parameter adjustments */
    --pt;
    --d3;
    --vec3;
    --d2;
    --vec2;
    --d1;
    --vec1;

    /* Function Body */
/* .... CHECK FOR ANY TWO INPUT VECTORS BEING PARALLEL */

    dotf_(&erg1, &vec1[1], &vec2[1]);
    dotf_(&erg2, &vec1[1], &vec3[1]);
    dotf_(&erg3, &vec2[1], &vec3[1]);
    if (abs(erg1) > eps) {
	*ir = 12;
	if (erg1 < zero) {
	    *ir = -12;
	}
    } else if (abs(erg2) > eps) {
	*ir = 13;
	if (erg2 < zero) {
	    *ir = -13;
	}
    } else if (abs(erg3) > eps) {
	*ir = 23;
	if (erg3 < zero) {
	    *ir = -23;
	}
    } else {
	for (i__ = 1; i__ <= 3; ++i__) {
	    a[i__ - 1] = vec1[i__];
	    a[i__ + 3] = vec2[i__];
/* L7: */
	    a[i__ + 7] = vec3[i__];
	}
	a[3] = d1[1];
	a[7] = d2[1];
	a[11] = d3[1];
	q = 0.f;
	for (i__ = 1; i__ <= 3; ++i__) {
	    c__[i__ - 1] = (d__1 = a[(i__ << 2) - 4], abs(d__1));
	    q += c__[i__ - 1];
/* L2: */
	}
	if (q <= 0.) {
	    goto L2000;
	} else {
	    goto L3;
	}
L3:
	if (c__[1] - c__[0] <= 0.) {
	    goto L30;
	} else {
	    goto L40;
	}
L30:
	if (c__[2] - c__[0] <= 0.) {
	    goto L70;
	} else {
	    goto L50;
	}
L40:
	if (c__[2] - c__[1] <= 0.) {
	    goto L60;
	} else {
	    goto L50;
	}
L50:
	jmax = 3;
	goto L65;
L60:
	jmax = 2;
L65:
	k = pow_ii(&c__2, &jmax);
	for (i__ = 1; i__ <= 4; ++i__) {
	    m = i__ + k;
	    asav[i__ - 1] = a[i__ - 1];
	    a[i__ - 1] = a[m - 1];
	    a[m - 1] = asav[i__ - 1];
/* L66: */
	}
L70:
	coe5 = a[4] / a[0];
	coe9 = a[8] / a[0];
	for (j = 2; j <= 4; ++j) {
	    a[j + 3] -= coe5 * a[j - 1];
	    a[j + 7] -= coe9 * a[j - 1];
/* L75: */
	}
	c__[1] = abs(a[5]);
	c__[2] = abs(a[9]);
	if (c__[1] + c__[2] <= 0.) {
	    goto L2000;
	} else {
	    goto L80;
	}
L80:
	if (c__[1] - c__[2] >= 0.) {
	    goto L100;
	} else {
	    goto L90;
	}
L90:
	for (j = 1; j <= 4; ++j) {
	    asav[j - 1] = a[j + 3];
	    a[j + 3] = a[j + 7];
	    a[j + 7] = asav[j - 1];
/* L95: */
	}
L100:
	coe10 = a[9] / a[5];
	for (j = 3; j <= 4; ++j) {
/* L105: */
	    a[j + 7] -= a[j + 3] * coe10;
	}
	if (a[10] != 0.) {
	    goto L1050;
	} else {
	    goto L2000;
	}
L1050:
	pt[3] = a[11] / a[10];
	pt[2] = (a[7] - a[6] * pt[3]) / a[5];
	pt[1] = (a[3] - a[2] * pt[3] - a[1] * pt[2]) / a[0];
	goto L2010;
L2000:
	*ir = 1;
	goto L2020;
L2010:
	*ir = 0;
    }
L2020:
    return 0;
} /* gauss_ */

