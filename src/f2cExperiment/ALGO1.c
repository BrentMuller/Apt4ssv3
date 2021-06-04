/* ALGO1.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ALGO1.ORG   *** */

/* Subroutine */ int algo1_(doublereal *t, doublereal *r__, doublereal *rn, 
	doublereal *ru, doublereal *rv, doublereal *du, doublereal *dv)
{
    static doublereal a;
    static integer i__;
    static doublereal s, v4[3];
    static integer isf;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), vecmod_(doublereal *, doublereal *), degsol_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    static doublereal uvstep[3];


/*     PURPOSE: CALCULATE DU,DV USING ALGORITHM 1 */

/*              GIVEN A SURFACE POINT R AND SURFACE NORMAL RN */
/*              AND A POINT ON THE TOOL T WITH SAME NORMAL */
/*              CALCULATE POINT B WHERE THIS TOOL NORMAL INTERSECTS */
/*              THE TANGENT PLANE AT R. */
/*              THE INDUCED PARAMETERIZATION OF THE TANGENT PLANE */
/*              IS USED TO DETERINE DU AND DV */


/*     CALC. UVSTEP AS STEP ON TANGENT PLANE AT POINT R */


    /* Parameter adjustments */
    --rv;
    --ru;
    --rn;
    --r__;
    --t;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	v4[i__ - 1] = t[i__] - r__[i__];
/* L100: */
    }
    dotf_(&a, v4, &rn[1]);
    for (i__ = 1; i__ <= 3; ++i__) {
	uvstep[i__ - 1] = v4[i__ - 1] - a * rn[i__];
/* L200: */
    }

/* .... S IS STEP LENGTH */

    vecmod_(uvstep, &s);

/* .... COMPUTE DU,DV FROM INDUCED PARAMETERIZATION OF TANGENT PLANE */

    degsol_(uvstep, &ru[1], &rv[1], du, dv, &isf);

    return 0;
} /* algo1_ */

