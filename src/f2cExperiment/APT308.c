/* APT308.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000424.V01   *** */

/* .....FORTRAN SUBROUTINE              APT308                12/67 */
/* PURPOSE      TO MOVE A 3 X 4 MATRIX FROM ONE ARRAY TO ANOTHER. */
/* LINKAGE      CALL APT308 (RESULT, MATRX1). */
/* ARGUMENTS    RESULT    ARRAY TO CONTAIN THE MATRIX */
/*              MATRX1    ARRAY CONTAINING THE MATRIX WHICH IS */
/*                        TO BE MOVED */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt308_(doublereal *result, doublereal *matrx1)
{
    static integer i__, j;

/*      THIS ROUTINE MOVES A 3X4 MATRIX FROM ONE ARRAY IN CORE TO ANOTHER */
    /* Parameter adjustments */
    matrx1 -= 4;
    result -= 4;

    /* Function Body */
    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    result[i__ + j * 3] = matrx1[i__ + j * 3];
/* L40: */
	}
    }
    return 0;
} /* apt308_ */

