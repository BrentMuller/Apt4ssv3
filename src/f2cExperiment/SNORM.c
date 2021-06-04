/* SNORM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000660.V02   *** */

/* Subroutine */ int snorm_(doublereal *a, doublereal *b, integer *irr)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal w;

    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    *irr = 1;
    w = sqrt(a[1] * a[1] + a[2] * a[2] + a[3] * a[3]);
    if (w < 1e-15) {
	return 0;
    }
    *irr = 0;
    b[1] = a[1] / w;
    b[2] = a[2] / w;
    b[3] = a[3] / w;
    return 0;
} /* snorm_ */

