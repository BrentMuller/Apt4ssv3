/* SOLVE3.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : SOLVE3.ORG   *** */

/* Subroutine */ int solve3_(doublereal *a, doublereal *b, doublereal *x, 
	integer *iflag)
{
    static doublereal d__, e;

/*     GIVEN A, B, SOLVES AX=B */


    /* Parameter adjustments */
    --x;
    --b;
    a -= 4;

    /* Function Body */
    d__ = a[4] * (a[8] * a[12] - a[11] * a[9]) - a[7] * (a[5] * a[12] - a[11] 
	    * a[6]) + a[10] * (a[5] * a[9] - a[8] * a[6]);
    if (abs(d__) < 1e-8) {
	*iflag = 1;
	goto L100;
    }

    *iflag = 0;
    d__ = 1. / d__;

    e = b[1] * (a[8] * a[12] - a[11] * a[9]) - a[7] * (b[2] * a[12] - a[11] * 
	    b[3]) + a[10] * (b[2] * a[9] - a[8] * b[3]);
    x[1] = e * d__;

    e = a[4] * (b[2] * a[12] - a[11] * b[3]) - b[1] * (a[5] * a[12] - a[11] * 
	    a[6]) + a[10] * (a[5] * b[3] - b[2] * a[6]);
    x[2] = e * d__;

    e = a[4] * (a[8] * b[3] - b[2] * a[9]) - a[7] * (a[5] * b[3] - b[2] * a[6]
	    ) + b[1] * (a[5] * a[9] - a[8] * a[6]);
    x[3] = e * d__;

L100:

    return 0;
} /* solve3_ */

