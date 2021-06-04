/* INTFA2.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0012399.V01   *** */

/* Subroutine */ int intfa2_(doublereal *face, doublereal *pl, doublereal *p1,
	 doublereal *p2, integer *irc1)
{
    static integer i__;
    static doublereal pi[3], dist, dist1;
    extern /* Subroutine */ int intfa1_(doublereal *, doublereal *, 
	    doublereal *, integer *);



    /* Parameter adjustments */
    --p2;
    --p1;
    --pl;
    face -= 7;

    /* Function Body */
    dist1 = -pl[4];
    dist = 0.;

    for (i__ = 1; i__ <= 3; ++i__) {
	dist1 += pl[i__] * p1[i__];
/* L10: */
	dist += (p2[i__] - p1[i__]) * pl[i__];
    }

    dist = dist1 / dist;

    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	pi[i__ - 1] = p1[i__] + (p2[i__] - p1[i__]) * dist;
    }

    intfa1_(&face[7], &pl[1], pi, irc1);

    return 0;
} /* intfa2_ */

