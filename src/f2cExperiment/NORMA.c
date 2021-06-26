/* NORMA.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : NORMA.ORG   *** */

/* Subroutine */ int norma_(doublereal *x, doublereal *xnorm, doublereal *
	xmod)
{
    static doublereal a;
    static integer k;
    extern /* Subroutine */ int vecmod_(doublereal *, doublereal *);


/*     GIVEN 3-D VECTOR X, CALCULATES NORMALISED (UNIT) VECTOR XNORM */
/*     AND MODULUS OF X AS XMOD */


    /* Parameter adjustments */
    --xnorm;
    --x;

    /* Function Body */
    vecmod_(&x[1], xmod);

    if (*xmod < 1e-10f) {
	a = 0.;
    } else {
	a = 1 / *xmod;
    }

    for (k = 1; k <= 3; ++k) {
	xnorm[k] = a * x[k];
/* L10: */
    }

    return 0;
} /* norma_ */
