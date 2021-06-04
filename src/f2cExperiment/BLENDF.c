/* BLENDF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001046.V02   *** */

/* Subroutine */ int blendf_(doublereal *u, doublereal *fu)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal three = 3.;
    static doublereal four = 4.;
    static doublereal six = 6.;

    static integer i__;
    static doublereal u2, u3, dif;

    /* Parameter adjustments */
    --fu;

    /* Function Body */
/* ------ INPUT IS A SCALAR U */
/* ------ OUTPUT ARE VALUES OF COONS CUBIC BLEND FUNCTIONS */
/* ------ (FU(I),I=1,4), THEIR FIRST AND SECOND */
    if (*u < zero || *u > one) {
	goto L100;
    }
/* ------ DERIVATIVES (FU(I),I=5,12) */
    u2 = *u * *u;
    u3 = u2 * *u;
    dif = u3 - u2;
    fu[1] = dif + dif - u2 + one;
    fu[2] = -fu[1] + one;
    fu[3] = dif - u2 + *u;
    fu[4] = dif;
    dif = three * (u2 - *u);
    fu[5] = dif + dif;
    fu[6] = -fu[5];
    fu[7] = dif - *u + one;
    fu[8] = dif + *u;
    dif = six * *u;
    fu[9] = dif + dif - six;
    fu[10] = -fu[9];
    fu[11] = dif - four;
    fu[12] = dif - two;
    return 0;
L100:
    for (i__ = 1; i__ <= 12; ++i__) {
/* L110: */
	fu[i__] = zero;
    }
    if (*u > one) {
	goto L200;
    }
/* ---  U IS LESS THAN ZERO */
    fu[1] = one;
    fu[3] = *u;
    fu[7] = one;
    return 0;
L200:
    fu[2] = one;
    fu[4] = *u - one;
    fu[8] = one;
    return 0;
} /* blendf_ */

