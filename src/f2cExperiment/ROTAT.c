/* ROTAT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000960.V01   *** */

/* ...  FORTRAN SUBROUTINE               ROTAT */
/* Subroutine */ int rotat_(doublereal *array, doublereal *xmatrx)
{
    static integer i__, j, k;
    static doublereal tmp[3];

/*                  SUBROUTINE USED TO ROTATE THE AXIS SYSTEM IN ARLM2 */
/*                  SO THAT THE TOOL AXIS POINTS IN THE Z-DIRECTION */
    /* Parameter adjustments */
    xmatrx -= 4;
    --array;

    /* Function Body */
    for (k = 1; k <= 3; ++k) {
	tmp[k - 1] = 0.f;
	for (j = 1; j <= 3; ++j) {
	    tmp[k - 1] += xmatrx[j + k * 3] * array[j];
/* L2: */
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4: */
	array[i__] = tmp[i__ - 1];
    }
    return 0;
} /* rotat_ */

