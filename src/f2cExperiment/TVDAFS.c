/* TVDAFS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : TVDAFS.ORG   *** */

/* Subroutine */ int tvdafs_(doublereal *trm, doublereal *geo)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal a[3];
    static integer i__, j, n, ix, mu, mv, iy, iz;

/* TRANSFORMATOR ROUTINE FOR VDAFS SURFACE PATCH USING */
/* APT TRANSFORMATION MATRIX TRM */
    /* Parameter adjustments */
    --geo;
    trm -= 5;

    /* Function Body */
    mu = (integer) geo[1];
    mv = (integer) geo[2];
    n = mu * mv;
/* 1ST 2 LOCATIONS OF GEO CONTAIN DIMENSIONS OF ARRAYS AX,AY,AZ OF COEFFI */
/* THESE COEFFICIENT MATRICES FOLLOW IN CONSECUTIVE LOCATIONS IN GEO. */
/* ALL COEFFICIENT VECTORS MUST BE ROTATED. */
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ix = i__ + 2;
	iy = ix + n;
	iz = iy + n;
	for (j = 1; j <= 3; ++j) {
/* L5: */
	    a[j - 1] = trm[(j << 2) + 1] * geo[ix] + trm[(j << 2) + 2] * geo[
		    iy] + trm[(j << 2) + 3] * geo[iz];
	}
	geo[ix] = a[0];
	geo[iy] = a[1];
	geo[iz] = a[2];
/* L10: */
    }
/* (0,0) COEFFICIENT IN EACH ARRAY IS ALSO TRANSLATED */
    geo[3] += trm[8];
    geo[n + 3] += trm[12];
    geo[(n << 1) + 3] += trm[16];
    return 0;
} /* tvdafs_ */

