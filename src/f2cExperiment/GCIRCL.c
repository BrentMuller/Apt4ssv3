/* GCIRCL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000906.V01   *** */

/* ...  FORTRAN SUBROUTINE GCIRCL                  7/70      RW */

/*  PURPOSE */
/*        THIS SUBROUTINE TRANSLATES THE CANONICAL FORMS */
/*        OF THE APT GEOMETRY (CIRCLE) INTO THE COEFFICIENTS */
/*        OF THE QUADRATIC. COEFFICIENTS ARE STORED */
/*        IN "QUADBF" AND THE QUADRATIC OUTPUT */
/*        SUBROUTINE IS CALLED. */

/*        CANONICAL FORM OF CIRCLE */
/*        1. X-COORD OF CENTER          (XC) */
/*        2. Y-COORD OF CENTER          (YC) */
/*        3. Z-COORD OF CENTER */
/*        4. X-COMPONENT OF AXIS VECTOR = 0 */
/*        5. Y-COMPONENT OF AXIS VECTOR = 0 */
/*        6. Z-COMPONENT OF AXIS VECTOR = 1 */
/*        7. RADIUS OF CIRCLE           (R) */

/*        EQUATION */
/*        X**2 + Y**2 - 2XC*X - 2YC*Y + (XC**2+YC**2-R**2) = 0. */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gcircl_(doublereal *canon, doublereal *quadbf)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static integer j, kr, kx, ky;



    /* Parameter adjustments */
    --quadbf;
    --canon;

    /* Function Body */
    for (j = 1; j <= 2; ++j) {
/* L2: */
	quadbf[j] = 1.f;
    }

    for (j = 3; j <= 6; ++j) {
/* L3: */
	quadbf[j] = 0.f;
    }

    kx = 1;
    ky = 2;
/*        COMPUTE C*X TERM */

    quadbf[7] = canon[kx] * -2.f;

/*        COMPUTE C*Y TERM */

    quadbf[8] = canon[ky] * -2.f;

/*        C*Z TERM EQUAL ZERO */

    quadbf[9] = 0.f;

/*        COMPUTE CONSTANT TERM */

    kr = 7;
/* Computing 2nd power */
    d__1 = canon[kx];
/* Computing 2nd power */
    d__2 = canon[ky];
    quadbf[10] = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = canon[kr];
    quadbf[10] -= d__1 * d__1;

/*        RETURN TO CALLING PROGRAM */

    return 0;
} /* gcircl_ */

