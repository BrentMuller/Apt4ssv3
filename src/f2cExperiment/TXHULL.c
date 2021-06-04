/* TXHULL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : TXHULL.V01   *** */

/* Subroutine */ int txhull_(doublereal *rc, doublereal *rcnorm, doublereal *
	r1, doublereal *r2, doublereal *r3, doublereal *tlen, doublereal *
	toolax, doublereal *tooltp, doublereal *toolce, doublereal *ct, 
	doublereal *hrad, doublereal *hcent)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__;
    static doublereal w1[3], ra, tr, rr1;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), vecmod_(doublereal *, doublereal *);



/* .... HULL CENTRE */


/*     CALCULATE RADIUS OF MINIMUM ENCLOSING SPHERE */
    /* Parameter adjustments */
    --hcent;
    --toolce;
    --tooltp;
    --toolax;
    --rcnorm;
    --rc;

    /* Function Body */
    rr1 = *r1 * *r1;
    for (i__ = 1; i__ <= 3; ++i__) {
	w1[i__ - 1] = toolce[i__] - rc[i__];
/* L10: */
    }
    dotf_(&b, w1, &toolax[1]);
    vecmod_(w1, &c__);
    ra = sqrt(c__ * c__ - b * b);
    if (ra + 1e-6 >= *r1 || ra <= *r3) {
	*hrad = 1e5;
    } else {

/*     CALC RADIUS OF SPHERE ON R AND ON POINT ON TOP OF TOOL OPPOSITE TO */
	a = ra + *r1;
	b = *tlen - *r2 + b;
/* .... HRAD IS RADIUS */
	*hrad = sqrt(a * a + b * b) * .5f;
	if (*hrad > 1e5) {
	    *hrad = 1e5;
	} else {

/*     CALC. MAXIMUM RADIUS OF CURVATURE OF TOOL AT R AS TR */
	    dotf_(&a, &rcnorm[1], &toolax[1]);
	    if (a < 1e-6 || abs(a) - 1. < 1e-6) {
		*hrad = 1e5;
	    } else {
		tr = *r2 + *r3 / sqrt(1 - a * a);
		if (tr > 1e5) {
		    *hrad = 1e5;
		} else {
		    *hrad = max(*hrad,tr);
		}
	    }
	}
    }
/* .... CT IS CURVATURE OF ENCLOSING SPHERE ON R */
    *ct = 1 / *hrad;

    for (i__ = 1; i__ <= 3; ++i__) {
	hcent[i__] = rc[i__] + *hrad * rcnorm[i__];
/* L40: */
    }

    return 0;
} /* txhull_ */

