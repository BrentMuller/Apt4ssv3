/* NORML3.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000643.V01   *** */

/* Subroutine */ int norml3_(doublereal *pa, doublereal *pb, doublereal *pc, 
	doublereal *an, integer *irr)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__;
    static doublereal p1[3], p2[3], crit;
    static integer idiag;

/* ------CONSTRUCT A UNIT NORMAL TO THREE POINTS PA,PB,PC AND STORE IN AN */
/* ------IF NO NORMAL EXISTS THEN IRR NE 0. */
    /* Parameter adjustments */
    --an;
    --pc;
    --pb;
    --pa;

    /* Function Body */
    idiag = 4000;
    crit = 1e-10;
    for (i__ = 1; i__ <= 3; ++i__) {
	p1[i__ - 1] = pb[i__] - pa[i__];
/* L10: */
	p2[i__ - 1] = pc[i__] - pa[i__];
    }
    an[1] = p1[1] * p2[2] - p1[2] * p2[1];
    an[2] = p1[2] * p2[0] - p1[0] * p2[2];
    an[3] = p1[0] * p2[1] - p1[1] * p2[0];
    d__ = sqrt(an[1] * an[1] + an[2] * an[2] + an[3] * an[3]);
    *irr = idiag + 1;
    if (d__ < crit) {
	return 0;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	an[i__] /= d__;
    }
    *irr = 0;
    return 0;
} /* norml3_ */

