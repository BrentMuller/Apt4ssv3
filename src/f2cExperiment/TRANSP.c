/* TRANSP.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001121.V01   *** */

/* Subroutine */ int transp_(doublereal *a, doublereal *b, integer *n)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, k;
    static doublereal t;

/* ---     TRANSPOSE A NXN MATRIX  CALLED A AND PLACE IN B */
/* ---     NOTE THAT B MAY BE THE SAME AS A */
    /* Parameter adjustments */
    b_dim1 = *n;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    a_dim1 = *n;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = i__;
	i__2 = j;
	for (k = 1; k <= i__2; ++k) {
	    t = a[i__ + k * a_dim1];
	    b[i__ + k * b_dim1] = a[k + i__ * a_dim1];
	    b[k + i__ * b_dim1] = t;
/* L20: */
	}
/* L10: */
    }
    return 0;
} /* transp_ */

