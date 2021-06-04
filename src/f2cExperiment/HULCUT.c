/* HULCUT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : HULCUT.V01   *** */

/* Subroutine */ int hulcut_(doublereal *te, doublereal *ta, doublereal *tul, 
	doublereal *sphr, integer *iseg)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static real d__;
    static integer i__;
    static doublereal p, v[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), vecmod_(doublereal *, doublereal *);


/*     CALCS. PENETRATION OF CORNER RADIUS CUTTER INTO SPHERICAL CONVEX H */
/*     OF RADIUS RAD AND CENTRE CENT */
/*     IF NO PENETRATION OCCURS, THEN ISEG = -1, ELSE */
/*     ISEG   = 0      BOTTOM FLAT */
/*              1      CORNER RADIUS */
/*              2      CYLINDER */
/*     P IS PENETRATION, -VE FOR MISS */

/*     ARGUMENTS: */

/*     TE      - TOOL END */
/*     TA      - TOOL AXIS */
/*     TUL     - TOOL GEOMETRY */
/*     SPHR    - CENTRE AND RADIUS OF TEST SPHERE */


/* .... LOCAL VARIABLES */


    /* Parameter adjustments */
    --sphr;
    --tul;
    --ta;
    --te;

    /* Function Body */
    *iseg = -1;
    for (i__ = 1; i__ <= 3; ++i__) {
	v[i__ - 1] = te[i__] + (tul[4] + tul[1]) * ta[i__] - sphr[i__];
/* L10: */
    }
    vecmod_(v, &b);
    dotf_(&a, v, &ta[1]);
    c__ = sqrt(b * b - a * a);

    if (a > 0.) {
/* .... CYLINDER CASE */
	p = sphr[4] + tul[2] - c__;
/* .... P -VE FOR MISS */
	if (p > 0.) {
	    *iseg = 2;
	}

    } else if (c__ <= tul[3]) {
/* .... BOTTOM FLAT CASE */
	p = tul[1] + tul[4] + sphr[4] - a;
/* .... P -VE FOR MISS */
	if (p > 0.) {
	    *iseg = 0;
	}

    } else {
/* .... CORNER RADIUS CASE */
	d__ = c__ - tul[3];
	p = tul[1] + sphr[4] - sqrt(d__ * d__ + a * a);
/* .... P -VE FOR MISS */
	if (p > 0.) {
	    *iseg = 1;
	}
    }

    return 0;
} /* hulcut_ */

