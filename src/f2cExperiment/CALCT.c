/* CALCT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : CALCT.V01   *** */

/* Subroutine */ int calct_(doublereal *tul, doublereal *toolce, doublereal *
	toolax, doublereal *r__, doublereal *rn, doublereal *pside, 
	doublereal *t, logical *lbase)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal a, b, c__, d__;
    static integer i__;
    static doublereal a1, v1[3], v2[3], sn[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), norma_(doublereal *, doublereal *, doublereal *), vnorm_(
	    doublereal *, doublereal *), vecmod_(doublereal *, doublereal *);
    static doublereal tcylen;


/*     PURPOSE: TO CALCULATE T, POINT ON TOOL WITH SAME NORMAL AS */
/*              SURFACE AT POINT R, RN */

/*     ARGUMENTS: */
/*         TUL     - TOOL GEOMETRY */
/*         TOOLCE  - TOOL CENTER POINT */
/*         TOOLAX  - TOOLAXIS VECTOR */
/*         R       - SURFACE POINT */
/*         RN      - SURFACE NORMAL */
/*         PSIDE   - TOOL SIDE OF SURFACE */
/*         T       - POINT ON TOOL WITH SAME NORMAL */
/*         LBASE   - FLAG INDICATING THAT T IS ON BASE FLAT OF CUTTER */


/*     LOCAL VARIABLES: */


    /* Parameter adjustments */
    --t;
    --rn;
    --r__;
    --toolax;
    --toolce;
    --tul;

    /* Function Body */
    *lbase = FALSE_;

/* .... COMPUTE LENGTH OF TOOL CYLINDER */

    tcylen = tul[7] - tul[4] + tul[1];

/* .... ADJUST DIRECTION OF SURFACE NORMAL */

    for (i__ = 1; i__ <= 3; ++i__) {
	sn[i__ - 1] = *pside * rn[i__];
/* L10: */
    }

/* .... DIRECTION OF SURFACE NORMAL WRT TO TOOLAXIS */

    dotf_(&a1, sn, &toolax[1]);

    if (a1 < 0. && abs(a1) > 1e-6) {
/* .... TAKE T AT TOP OF UPPER LINE SEGMENT */
	for (i__ = 1; i__ <= 3; ++i__) {
	    v1[i__ - 1] = r__[i__] - toolce[i__];
/* L100: */
	}
	dotf_(&a, v1, &toolax[1]);
	for (i__ = 1; i__ <= 3; ++i__) {
	    v2[i__ - 1] = v1[i__ - 1] - a * toolax[i__];
/* L102: */
	}
	vnorm_(v2, v2);
	for (i__ = 1; i__ <= 3; ++i__) {
	    t[i__] = toolce[i__] + tul[2] * v2[i__ - 1] + tcylen * toolax[i__]
		    ;
/* L104: */
	}
    } else {

/* .... COMPUTATION DEPENDENT ON TYPE OF TOOL */


	if ((d__1 = tul[1] - tul[2], abs(d__1)) <= 1e-6) {
/* .... BALL-ENDED CUTTER */
	    for (i__ = 1; i__ <= 3; ++i__) {
		v1[i__ - 1] = r__[i__] - toolce[i__];
		t[i__] = toolce[i__] - tul[1] * sn[i__ - 1];
/* L110: */
	    }
	    dotf_(&a, v1, &toolax[1]);
/* .... LIMIT A TO VALID RANGE FOR TOOL CYLINDER */
	    if (a < 0.) {
		a = 0.;
	    }
	    if (a > tcylen) {
		a = tcylen;
	    }

	    if (abs(a1) < 1e-6) {
/* .... ON CYLINDER */
		for (i__ = 1; i__ <= 3; ++i__) {
		    t[i__] += a * toolax[i__];
/* L120: */
		}
	    }
	} else {

/*     CORNER RADIUS CUTTER */
/*     FIND TOOL POINT T WITH SAME NORMAL */

	    if (abs(a1) < 1e-6) {

/* .... CYLINDER CASE */

		for (i__ = 1; i__ <= 3; ++i__) {
		    v1[i__ - 1] = r__[i__] - toolce[i__];
/* L130: */
		}
		dotf_(&a, v1, &toolax[1]);
/* .... LIMIT A TO VALID RANGE FOR TOOL CYLINDER */
		if (a < 0.) {
		    a = 0.;
		}
		if (a > tcylen) {
		    a = tcylen;
		}
/* .... NOTE IN THIS CASE SN IS PERP. TO TA SO T WILL LIE ON CYLINDER */
		for (i__ = 1; i__ <= 3; ++i__) {
		    t[i__] = toolce[i__] + a * toolax[i__] - tul[2] * sn[i__ 
			    - 1];
/* L140: */
		}
	    } else if (1. - a1 < 1e-6) {

/* .... BOTTOM FLAT CASE */

		for (i__ = 1; i__ <= 3; ++i__) {
		    v1[i__ - 1] = toolce[i__] - r__[i__];
/* L150: */
		}
		dotf_(&b, v1, &toolax[1]);
		for (i__ = 1; i__ <= 3; ++i__) {
		    v1[i__ - 1] -= b * toolax[i__];
/* L155: */
		}
		norma_(v1, v2, &d__);
		if (d__ > tul[3]) {
		    d__ = tul[3];
		}
		c__ = tul[4] + tul[2];
		for (i__ = 1; i__ <= 3; ++i__) {
		    t[i__] = toolce[i__] - c__ * toolax[i__] - d__ * v2[i__ - 
			    1];
/* L160: */
		}
/* .... INDICATE T IS ON FLAT BASE OF CUTTER */
		*lbase = TRUE_;
	    } else {
/* .... CORNER RADIUS CASE */
		for (i__ = 1; i__ <= 3; ++i__) {
		    v1[i__ - 1] = sn[i__ - 1] - a1 * toolax[i__];
/* L170: */
		}
		vecmod_(v1, &a);
		c__ = tul[3] / a;
		for (i__ = 1; i__ <= 3; ++i__) {
		    t[i__] = toolce[i__] - c__ * v1[i__ - 1] - tul[1] * sn[
			    i__ - 1];
/* L180: */
		}

	    }

	}

    }

    return 0;
} /* calct_ */

