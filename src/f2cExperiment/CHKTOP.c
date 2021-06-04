/* CHKTOP.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001051.V01   *** */

/* Subroutine */ int chktop_(doublereal *u, doublereal *v, integer *itop, 
	integer *iok)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static integer icomp[18]	/* was [2][3][3] */ = { 1,2,1,0,1,3,2,0,0,0,3,
	    0,2,4,4,0,4,3 };

    static integer j, k, iu, iv;

    /* Parameter adjustments */
    itop -= 7;

    /* Function Body */
/*      DIMENSION ICOMP(2,3,3) */
/*           /-PURPOSE IS TO SEE IF U,V, VALUES OF PATCH WITH TOPOLOGY */
/*           /-TABLE ITOP ARE IN A VALID SECTOR FOR THIS SURFACE */
/*           /-IOK=0 MEANS SECTOR IS OKAY. OTHERWISE IOK POINTS TO INVALI */
/*           /-SECTOR */
/*           /-NOTE THAT UNIT SQUARE DIVIDES SPACE INTO 9 SECTORS */

/*           /-FIRST DETERMINE THE SECTOR OF U,V */
    iu = 2;
    if (*u < zero) {
	iu = 1;
    }
    if (*u > one) {
	iu = 3;
    }
    iv = 2;
    if (*v < zero) {
	iv = 1;
    }
    if (*v > one) {
	iv = 3;
    }
/*           /-NOW COMPARE THIS SECTOR FOR FREE BOUNDARIES */
    *iok = 0;
    for (j = 1; j <= 2; ++j) {
	k = icomp[j + (iu + iv * 3 << 1) - 9];
	if (k == 0) {
	    goto L10;
	}
	if (itop[k * 6 + 2] != 0) {
	    *iok = itop[k * 6 + 2];
	}
L10:
	;
    }
    return 0;
} /* chktop_ */

