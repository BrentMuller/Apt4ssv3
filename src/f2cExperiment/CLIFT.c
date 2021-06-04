/* CLIFT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001052.V02   *** */

/* Subroutine */ int clift_(doublereal *te, doublereal *clrpln, doublereal *
	tx)
{
    /* Initialized data */

    static doublereal zero = 0.;

    static integer i__;
    static doublereal sum;

/* ---PURPOSE IS TO LIFT TOOL END TE TO POSITION TX ON CLEARANCE */
/* ---PLANE CLRPLN.  MOVE IS IN DIRECTION OF PLANE NORMAL. */

    /* Parameter adjustments */
    --tx;
    --clrpln;
    --te;

    /* Function Body */

    sum = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	sum = (te[i__] - clrpln[4] * clrpln[i__]) * clrpln[i__] + sum;
/* L10: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	tx[i__] = te[i__] - sum * clrpln[i__];
    }
    return 0;
} /* clift_ */

