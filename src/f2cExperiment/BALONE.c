/* BALONE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001041.V01   *** */

/* Subroutine */ int balone_(doublereal *r__, doublereal *side, doublereal *
	tc, doublereal *rad, doublereal *td, doublereal *du, doublereal *dv, 
	doublereal *dist, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal smal = 1e-18;

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal del[3], suu, suv, svv, delu, delv;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal rmod[3], tdsn, discr, factor;

/*           /-PURPOSE TO USE LINEAR ESTIMATE OF SURFACE(STORED IN R ) TO */
/*           /-CALCULATE DISTANCE TO MOVE BALL CUTTER CENTERED AT TC */
/*           /-IN DIRECTION TD TOWARD SURFACE */
/*           /-INPUT FOLLOWS */
/*           /-R(1-32) CONTAINS SURFACE COORDS,FIRST AND SECOND DERIVATIV */
/*           /-TC,TD DENOTE TOOL CENTER AND TOOL DIRECTION TO SURFACE */
/*           /-RAD DENOTES THE RADIUS OF THE BALL TOOL */
/*           /-SIDE DENOTES NON MATERIAL SIDE OF SURFACE(+1 FOR U X V ) */
/*           /-OUTPUT */
/*           /-DIST DISTANCE TOOL CENTER SHOULD BE MOVED TO CONTACT PLANE */
/*           /-DU,DV SURFACE COORDINATE CHANGES FOR TOOL CONTACT PT. */
/*           /-IRR IS NON ZERO ON OUTPUT IF AN ERROR OCCURRED HERE. */

    /* Parameter adjustments */
    --td;
    --tc;
    --r__;

    /* Function Body */

/*           /-COMPUTE MODIFIED SURFACE POINT FOR INTERSECTION PLANE */
    factor = *side * *rad;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	rmod[i__ - 1] = r__[i__] + factor * r__[i__ + 28];
    }
/*           /-COMPUTE DISTANCE OF TC ALONG TD TO THIS PLANE */
/*           /- DIST SATISFIES EQN, (TC+DIST*TD-RMOD,SN)=0 */
    dotf_(&tdsn, &td[1], &r__[29]);
    *irr = 1;
    if (abs(tdsn) < smal) {
	goto L999;
    }
    *dist = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	*dist += (rmod[i__ - 1] - tc[i__]) * r__[i__ + 28];
    }
    *dist /= tdsn;
/*           /-COMPUTE INCREMENTAL VECTOR FROM RMOD TO TC , TD PIERCE POI */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	del[i__ - 1] = tc[i__] + *dist * td[i__] - rmod[i__ - 1];
    }
/*           /-COMPUTE CHANGE IN U,V TO REACH DEL */
    dotf_(&suu, &r__[5], &r__[5]);
    dotf_(&suv, &r__[5], &r__[9]);
    dotf_(&svv, &r__[9], &r__[9]);
    dotf_(&delu, del, &r__[5]);
    dotf_(&delv, del, &r__[9]);
/* Computing 2nd power */
    d__1 = suv;
    discr = suu * svv - d__1 * d__1;
    *irr = 2;
    if (abs(discr) < smal) {
	goto L999;
    }
    *du = (delu * svv - delv * suv) / discr;
    *dv = (suu * delv - suv * delu) / discr;
    *irr = 0;
L999:
    return 0;
} /* balone_ */

