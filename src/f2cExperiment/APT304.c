/* APT304.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000421.V01   *** */

/* .....FORTRAN SUBROUTINE              APT304                12/67 */
/* PURPOSE      TO TRANSFORM A GIVEN VECTOR BY A GIVEN MATRIX. */
/* LINKAGE      CALL APT304 (RESULT, MATRX, VCTR) */
/* ARGUMENTS    RESULT    ARRAY TO CONTAIN THE CANONICAL FROM OF */
/*                        THE TRANSFORMED VECTOR */
/*              MATRX     ARRAY CONTAINING THE GIVEN TRANSFORMA- */
/*                        TION MATRIX (3 X 4) */
/*              VCTR      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                        THE VECTOR TO BE TRANSFORMED */
/* Subroutine */ int apt304_(doublereal *result, doublereal *matrx, 
	doublereal *vctr)
{
    static integer i__, j;
    static doublereal vec[3];

/*     THIS ROUTINE TRANSFORMS THE CANONICAL FORM OF A VECTOR */
/*     BY A GIVEN MATRIX */
    /* Parameter adjustments */
    --vctr;
    matrx -= 4;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	vec[i__ - 1] = vctr[i__];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__] = 0.;
	for (j = 1; j <= 3; ++j) {
	    result[i__] += vec[j - 1] * matrx[i__ + j * 3];
/* L70: */
	}
    }
    return 0;
} /* apt304_ */

