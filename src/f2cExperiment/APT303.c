/* APT303.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000420.V01   *** */

/* .....FORTRAN SUBROUTINE              APT303                12/67 */
/* PURPOSE      TO TRANSFORM THE CANONICAL FORM OF A POINT BY */
/*              A GIVEN MATRIX. */
/* LINKAGE      CALL APT303 (RESULT, MATRX, PN) */
/* ARGUMENTS    RESULT    ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                        THE RESULTANT POINT */
/*              MATRX     ARRAY CONTAINING THE INPUT TRANSFORMATION */
/*                        MATRIX */
/*              PN        ARRAY CONTAINING THE CANONICAL FORM OF */
/*                        THE INPUT POINT */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt303_(doublereal *result, doublereal *matrx, 
	doublereal *pn)
{
    static integer i__, j;
    static doublereal p[3];

/*     THIS ROUTINE TRANSFORMS THE CANONICAL FORM OF A POINT */
/*     BY A GIVEN MATRIX */
    /* Parameter adjustments */
    --pn;
    matrx -= 4;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	p[i__ - 1] = pn[i__];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__] = matrx[i__ + 12];
	for (j = 1; j <= 3; ++j) {
	    result[i__] += p[j - 1] * matrx[i__ + j * 3];
/* L70: */
	}
    }
    return 0;
} /* apt303_ */

