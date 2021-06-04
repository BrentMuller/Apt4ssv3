/* CURCAL.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** SOURCE FILE : CURCAL.V01   *** */

/* Subroutine */ int curcal_(doublereal *ru, doublereal *rv, doublereal *ruu, 
	doublereal *ruv, doublereal *rvv, doublereal *rnorm, doublereal *side,
	 doublereal *curve1, doublereal *curve2)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal w[3], a1, a2, a3, z4, d11, d12, d22, g11, g12, g22, 
	    disc;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal zero, denom;


/*     PURPOSE: TO CALCULATE PRINCIPAL CURVATURES CURVE1,CURVE2 */


/* .... WORKSPACE */


/*     CALC. 1ST FUNDAMENTAL MATRIX G */

/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    /* Parameter adjustments */
    --rnorm;
    --rvv;
    --ruv;
    --ruu;
    --rv;
    --ru;

    /* Function Body */
    dotf_(&g11, &ru[1], &ru[1]);
    dotf_(&g22, &rv[1], &rv[1]);
    dotf_(&g12, &ru[1], &rv[1]);

/*     CALC. 2ND FUNDAMENTAL MATRIX D */

/* .... TAKE SURFACE NORMAL POINTING TOWARDS TOOL */

    for (i__ = 1; i__ <= 3; ++i__) {
	w[i__ - 1] = *side * rnorm[i__];
/* L10: */
    }

    dotf_(&d11, w, &ruu[1]);
    dotf_(&d12, w, &ruv[1]);
    dotf_(&d22, w, &rvv[1]);

/*     CALC. COEFFS. FOR QUADRATIC IN CURVATURE */

    a1 = g11 * g22 - g12 * g12;
    a2 = -g11 * d22 - g22 * d11 + g12 * 2. * d12;
    a3 = d11 * d22 - d12 * d12;

/*     SOLVE FOR CURVATURES */

    disc = a2 * a2 - z4 * a1 * a3;
    disc = max(zero,disc);
    disc = sqrt(disc);

    denom = a1 + a1;

    *curve1 = (-a2 + disc) / denom;
    *curve2 = (-a2 - disc) / denom;

    return 0;
} /* curcal_ */

