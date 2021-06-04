/* QABPST.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : QABPST.ORG   *** */

doublereal qabpst_(doublereal *p1, doublereal *p2, doublereal *p3)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, d__, h__[3];
    static integer i__;
    static doublereal v2[3], v3[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );


/*  PURPOSE: TO COMPUTE THE DISTANCE OF A POINT FROM A SPACE LINE */

/*  ARGUMENTS: */
/*            P1    D.P.  1ST POINT OF SPACE LINE */
/*            P2    D.P.  2ND POINT OF SPACE LINE */
/*            P3    D.P.  POINT */



    /* Parameter adjustments */
    --p3;
    --p2;
    --p1;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	v2[i__ - 1] = p2[i__] - p1[i__];
	v3[i__ - 1] = p3[i__] - p1[i__];
/* L10: */
    }

    dotf_(&a, v3, v2);
    dotf_(&b, v2, v2);

    if (b > 1e-10) {
	a /= b;
    } else {
/* .... IF LINE PIS VERY SHORT ASSUME PERPENDICULAR MEETS LINE AT MIDPOIN */
	a = .5f;
    }

    for (i__ = 1; i__ <= 3; ++i__) {
	h__[i__ - 1] = v3[i__ - 1] - a * v2[i__ - 1];
/* L20: */
    }

    dotf_(&d__, h__, h__);

    ret_val = sqrt(d__);

    return ret_val;
} /* qabpst_ */

