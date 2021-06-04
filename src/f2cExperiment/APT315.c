/* APT315.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000431.V02   *** */


/* .....FORTRAN SUBROUTINE              APT315                12/67 */
/* PURPOSE      TO NORMALIZE A GIVEN VECTOR. */
/* LINKAGE      CALL APT315 (B,C) */
/* ARGUMENTS    B    ARRAY TO CONTAIN THE NORMALIZED VECTOR */
/*              C    ARRAY CONTAINING THE VECTOR TO BE NORMALIZED */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt315_(doublereal *b, doublereal *c__)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a[3];
    static integer i__;
    static doublereal s;


/*      NORM NORMALIZES A VECTOR V---NORM= VX/V + VY/V + VZ/V */
    /* Parameter adjustments */
    --c__;
    --b;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	a[i__ - 1] = c__[i__];
    }
    s = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    if (s < 1e-6) {
	s = 1.f;
    }

    for (i__ = 1; i__ <= 3; ++i__) {
	b[i__] = a[i__ - 1] / s;
	if ((d__1 = b[i__], abs(d__1)) - 1e-6 <= 0.) {
	    goto L1;
	} else {
	    goto L2;
	}
L1:
	b[i__] = 0.f;
L2:
	;
    }
    return 0;
} /* apt315_ */

