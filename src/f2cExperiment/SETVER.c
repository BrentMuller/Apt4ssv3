/* SETVER.f -- translated by f2c (version 20100827).
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
    doublereal umin1, umax1, vmin1, vmax1, w1[4];
} vercom_;

#define vercom_1 vercom_

/* *** SOURCE FILE : M0012335.V02   *** */

/* Subroutine */ int setver_(doublereal *w)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__;


/* ROUTINE SETVER SETS THE STARTING VALUES FOR INTERSECTION */

/* STORES ARRAY W IN ARRAY W1 IN COMMON/VERCOM FOR USE BY GETVER */

/*       W1     : I: DEFINITION OF 1ST LINE: START POINT (U1,V1) */
/*                                           END   POINT (U2,V2) */
/*                    W1(1) = U1 */
/*                    W1(2) = V1 */
/*                    W1(3) = U2-U1 */
/*                    W1(4) = V2-V1 */




    /* Parameter adjustments */
    --w;

    /* Function Body */
    for (i__ = 1; i__ <= 4; ++i__) {
	vercom_1.w1[i__ - 1] = w[i__];
/* L10: */
    }

/* Computing MIN */
    d__1 = vercom_1.w1[0], d__2 = vercom_1.w1[0] + vercom_1.w1[2];
    vercom_1.umin1 = min(d__1,d__2);
/* Computing MAX */
    d__1 = vercom_1.w1[0], d__2 = vercom_1.w1[0] + vercom_1.w1[2];
    vercom_1.umax1 = max(d__1,d__2);
/* Computing MIN */
    d__1 = vercom_1.w1[1], d__2 = vercom_1.w1[1] + vercom_1.w1[3];
    vercom_1.vmin1 = min(d__1,d__2);
/* Computing MAX */
    d__1 = vercom_1.w1[1], d__2 = vercom_1.w1[1] + vercom_1.w1[3];
    vercom_1.vmax1 = max(d__1,d__2);
    return 0;
} /* setver_ */


/* Subroutine */ int getver_(doublereal *w2, doublereal *result, integer *
	ires)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal d__, a1, a2, a3, b1, b2, b3;


/* ROUTINE   GETVER COMPUTES THE INTERSECTION */
/*       W2     : I: DEFINITION OF 2ND LINE: START POINT (U3,V3) */
/*                                           END   POINT (U4,V4) */
/*                    W2(1) = U3 */
/*                    W2(2) = V3 */
/*                    W2(3) = U4-U3 */
/*                    W2(4) = V4-V3 */
/*       RESULT : O: RESULTING VALUES, POINT OF INTERSECTION */
/*       IRES   : O: =0: NO INTERSECTION */
/*                   =1: INTERSECTION, RESULT IN RESULT */
/*                   =2: INTERSECTION, PARALLEL LINES, */
/*                        UPON EACH OTHER */




    /* Parameter adjustments */
    --result;
    --w2;

    /* Function Body */
    *ires = 0;

/* Computing MAX */
    d__1 = w2[1], d__2 = w2[1] + w2[3];
    if (vercom_1.umin1 > max(d__1,d__2)) {
	return 0;
    }
/* Computing MIN */
    d__1 = w2[1], d__2 = w2[1] + w2[3];
    if (vercom_1.umax1 < min(d__1,d__2)) {
	return 0;
    }
/* Computing MAX */
    d__1 = w2[2], d__2 = w2[2] + w2[4];
    if (vercom_1.vmin1 > max(d__1,d__2)) {
	return 0;
    }
/* Computing MIN */
    d__1 = w2[2], d__2 = w2[2] + w2[4];
    if (vercom_1.vmax1 < min(d__1,d__2)) {
	return 0;
    }

    if (((w2[1] - vercom_1.w1[0]) * vercom_1.w1[3] - (w2[2] - vercom_1.w1[1]) 
	    * vercom_1.w1[2]) * ((w2[1] + w2[3] - vercom_1.w1[0]) * 
	    vercom_1.w1[3] - (w2[2] + w2[4] - vercom_1.w1[1]) * vercom_1.w1[2]
	    ) > 0.) {
	return 0;
    }

    if (((vercom_1.w1[0] - w2[1]) * w2[4] - (vercom_1.w1[1] - w2[2]) * w2[3]) 
	    * ((vercom_1.w1[0] + vercom_1.w1[2] - w2[1]) * w2[4] - (
	    vercom_1.w1[1] + vercom_1.w1[3] - w2[2]) * w2[3]) > 0.) {
	return 0;
    }

/* INTERSECT THE 1ST AND 2ND LINE */
    a1 = vercom_1.w1[3];
    a2 = -vercom_1.w1[2];
    a3 = vercom_1.w1[3] * vercom_1.w1[0] - vercom_1.w1[2] * vercom_1.w1[1];
    b1 = w2[4];
    b2 = -w2[3];
    b3 = w2[4] * w2[1] - w2[3] * w2[2];

/*  CHECK FOR PARALLEL */
    d__ = a2 * b1 - a1 * b2;
    if (abs(d__) < 1e-10) {
	goto L50;
    }
    result[1] = -(a3 * b2 - a2 * b3) / d__;
    result[2] = (a3 * b1 - a1 * b3) / d__;
    *ires = 1;
    goto L60;
L50:
    *ires = 2;
L60:
/* CCCC WRITE(6,100)IRES,W1,W2,RESULT */
/* C100 FORMAT(' IRES,W1,W2,RESULT:'/I3/1X,4F20.5/1X,4F20.5/1X,2F20.5) */

    return 0;
} /* getver_ */

