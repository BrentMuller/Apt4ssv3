/* APT306.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000423.V01   *** */

/* .....FORTRAN SUBROUTINE              APT306                12/67 */
/* PURPOSE      TO GENERATE THE PRODUCT MATRIX OF TWO GIVEN */
/*              3X4 MATRICES. */
/* LINKAGE      CALL APT306 (RESULT, M1, M2) */
/* ARGUMENTS    RESULT    ARRAY TO CONTAIN THE ELEMENTS OF THE */
/*                        PRODUCT MATRIX */
/*              M1        ARRAY CONTAINING THE ELEMENTS OF THE */
/*                        PREMULTIPLIER MATRIX */
/*              M2        ARRAY CONTAINING THE ELEMENTS OF THE */
/*                        POSTMULTIPLIER MATRIX */
/* SUBSIDIARIES NONE */
/* Subroutine */ int apt306_(doublereal *result, doublereal *m1, doublereal *
	m2)
{
    static integer i__, j, k;
    static doublereal gm1[16]	/* was [4][4] */, gm2[16]	/* was [4][4] 
	    */, gm3[16]	/* was [4][4] */;

/*     THIS ROUTINE MULTIPLIES TWO MATRICES OF THREE ROWS AND FOUR */
/*     COLUMNS */
    /* Parameter adjustments */
    m2 -= 4;
    m1 -= 4;
    result -= 4;

    /* Function Body */
    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    gm1[i__ + (j << 2) - 5] = m1[i__ + j * 3];
	    gm2[i__ + (j << 2) - 5] = m2[i__ + j * 3];
/* L50: */
	}
    }
    i__ = 4;
    for (j = 1; j <= 3; ++j) {
	gm1[i__ + (j << 2) - 5] = 0.;
	gm2[i__ + (j << 2) - 5] = 0.;
/* L100: */
    }
    gm1[15] = 1.;
    gm2[15] = 1.;
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    gm3[i__ + (j << 2) - 5] = 0.;
	    for (k = 1; k <= 4; ++k) {
		gm3[i__ + (j << 2) - 5] += gm1[i__ + (k << 2) - 5] * gm2[k + (
			j << 2) - 5];
/* L190: */
	    }
	}
    }
    for (j = 1; j <= 4; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    result[i__ + j * 3] = gm3[i__ + (j << 2) - 5];
/* L230: */
	}
    }
    return 0;
} /* apt306_ */

