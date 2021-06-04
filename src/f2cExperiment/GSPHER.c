/* GSPHER.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000920.V01   *** */

/* ...  FORTRAN SUBROUTINE GSPHER                  7/70      RW */

/*  PURPOSE */
/*        THIS SUBROUTINE TRANSLATES THE CANONICAL FORMS */
/*        OF THE APT GEOMETRY (SPHERE) INTO THE COEFFICIENTS */
/*        OF THE QUADRATIC. COEFFICIENTS ARE STORED IN */
/*        "QUADBF" AND THE QUADRATIC OUTPUT */
/*        SUBROUTINE IS CALLED. */


/*        CANONICAL FORM OF SPHERE */
/*        1. X-COORDINATE OF CENTER OF SPHERE     (XC) */
/*        2. Y-COORDINATE OF CENTER OF SPHERE     (YC) */
/*        3. Z-COORDINATE OF CENTER OF SPHERE     (ZC) */
/*        4. RADIUS OF SPHERE                     (R) */

/*        EQUATION */
/*        X**2 + Y**2 + Z**2 - 2XC*X - 2YC*Y - 2ZC*Z + */
/*                            (XC**2 + YC**2 + ZC**2 - R**2) */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gspher_(doublereal *canon, doublereal *quadbf)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer j, kr, kx, ky, kz;



    /* Parameter adjustments */
    --quadbf;
    --canon;

    /* Function Body */
    for (j = 1; j <= 3; ++j) {
/* L2: */
	quadbf[j] = 1.f;
    }

    for (j = 4; j <= 6; ++j) {
/* L3: */
	quadbf[j] = 0.f;
    }

/*        COMPUTE C*X TERM */

    kx = 1;
    ky = 2;
    kz = 3;
    kr = 4;
    quadbf[7] = canon[kx] * -2.f;

/*        COMPUTE C*Y TERM */

    quadbf[8] = canon[ky] * -2.f;

/*        COMPUTE C*Z TERM */

    quadbf[9] = canon[kz] * -2.f;

/*        COMPUTE CONSTANT TERM */

/* Computing 2nd power */
    d__1 = canon[kx];
/* Computing 2nd power */
    d__2 = canon[ky];
/* Computing 2nd power */
    d__3 = canon[kz];
    quadbf[10] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* Computing 2nd power */
    d__1 = canon[kr];
    quadbf[10] -= d__1 * d__1;

/*        RETURN TO CALLING PROGRAM */

    return 0;
} /* gspher_ */

