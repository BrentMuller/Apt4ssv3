/* VSCALE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : VSCALE.ORG   *** */

/* Subroutine */ int vscale_(doublereal *s, doublereal *v1, doublereal *v2)
{
    static integer i__;


/*    PURPOSE: TO APPLY A SCALE FACTOR TO A VECTOR  ( V2=S*V1 ) */


    /* Parameter adjustments */
    --v2;
    --v1;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	v2[i__] = *s * v1[i__];
/* L10: */
    }

    return 0;
} /* vscale_ */

