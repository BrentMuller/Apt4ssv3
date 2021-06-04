/* BEZIER.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000600.V02   *** */


/* Subroutine */ int bezier_(doublereal *bin, doublereal *out, integer *irr)
{
    /* Initialized data */

    static doublereal smal = 1e-10;
    static doublereal zero = 0.;

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static doublereal d__;
    static integer i__, j, k;
    static doublereal w;
    static integer ia, ib, ja, jb, in;
    static doublereal bout[48]	/* was [3][4][4] */;
    static integer icase;

    /* Parameter adjustments */
    --out;
    bin -= 16;

    /* Function Body */
    *irr = 0;
    icase = 1;
/* ------ BEZIER INPUT IS FOUR PARALLEL STRINGS OF FOUR POINTS EACH */
/* -----EACH OF THESE FOUR POINT STRING DEFINES A CHARACTERISTIC POLYGON */
/* ------ UNDER CERTAIN CONDITIONS, THIS INPUT WILL DEFAULT TO A ZERO */
/* ------ TWIST PATCH (ICASE=2) OR A RULED PATCH(ICASE=3) */
    icase = 1;
/* ------ FIRST CHECK INPUT TO DETECT A ZERO TWIST DEFAULT */
    for (ia = 2; ia <= 3; ++ia) {
	for (ib = 2; ib <= 3; ++ib) {
	    for (ja = 2; ja <= 3; ++ja) {
		for (jb = 2; jb <= 3; ++jb) {
		    d__ = 0.f;
		    for (k = 1; k <= 3; ++k) {
/* L20: */
/* Computing 2nd power */
			d__1 = bin[k + (ia + (ib << 2)) * 3] - bin[k + (ja + (
				jb << 2)) * 3];
			d__ += d__1 * d__1;
		    }
/* ------ IF THE FOUR INTERIOR POINTS ARE IDENTICAL, SETUP ZERO TWISTS */
		    if (d__ > smal) {
			goto L100;
		    }
/* L10: */
		}
	    }
	}
    }
    icase = 2;
/* ------CHECK FURTHER FOR A RULED CONDITION */
    for (ia = 1; ia <= 4; ia += 3) {
	for (ib = 2; ib <= 3; ++ib) {
	    for (ja = 1; ja <= 4; ja += 3) {
		for (jb = 2; jb <= 3; ++jb) {
		    d__ = 0.f;
		    for (k = 1; k <= 3; ++k) {
/* L40: */
/* Computing 2nd power */
			d__1 = bin[k + (ia + (ib << 2)) * 3] - bin[k + (ja + (
				jb << 2)) * 3];
			d__ += d__1 * d__1;
		    }
		    if (d__ > smal) {
			goto L100;
		    }
/* L30: */
		}
	    }
	}
    }
/* ------ 5TH THRY 12TH POINTS ARE IDENTICAL HENCE PATCG IS RULED */
    icase = 3;
L100:
/* ------ NOW CREATE COONS CANONICAL FORM FOR PATCH */
    for (i__ = 1; i__ <= 3; ++i__) {
/* ------ FIRST LOAD CORNER POINTS INTO COONS MATRIX (BOUT) */
	bout[i__ - 1] = bin[i__ + 15];
	bout[i__ + 2] = bin[i__ + 24];
	bout[i__ + 11] = bin[i__ + 51];
	bout[i__ + 14] = bin[i__ + 60];
/* ------ NOW LOAD FIRST DIRECTION (FD) TANGENTS INTO BOUT */
	bout[i__ + 5] = (bin[i__ + 18] - bin[i__ + 15]) * 3.f;
	bout[i__ + 8] = (bin[i__ + 24] - bin[i__ + 21]) * 3.f;
	bout[i__ + 17] = (bin[i__ + 54] - bin[i__ + 51]) * 3.f;
	bout[i__ + 20] = (bin[i__ + 60] - bin[i__ + 57]) * 3.f;
	if (icase == 3) {
	    goto L200;
	}
/* ------ SETUP SECOND DIRECTION TANGENTS (SD) INTO COONS MATRIX(BOUT) */
	bout[i__ + 23] = (bin[i__ + 27] - bin[i__ + 15]) * 3.f;
	bout[i__ + 26] = (bin[i__ + 36] - bin[i__ + 24]) * 3.f;
	bout[i__ + 35] = (bin[i__ + 51] - bin[i__ + 39]) * 3.f;
	bout[i__ + 38] = (bin[i__ + 60] - bin[i__ + 48]) * 3.f;
	if (icase == 2) {
	    goto L130;
	}
/* ------ FINALLY LOAD TWIST VECTORS */
	bout[i__ + 29] = (bin[i__ + 30] - bin[i__ + 27] - bin[i__ + 18] + bin[
		i__ + 15]) * 9.f;
	bout[i__ + 32] = (bin[i__ + 36] - bin[i__ + 33] - bin[i__ + 24] + bin[
		i__ + 21]) * 9.f;
	bout[i__ + 41] = (bin[i__ + 54] - bin[i__ + 51] - bin[i__ + 42] + bin[
		i__ + 39]) * 9.f;
	bout[i__ + 44] = (bin[i__ + 60] - bin[i__ + 57] - bin[i__ + 48] + bin[
		i__ + 45]) * 9.f;
	goto L120;
/* ------ THE CASE OF ZERO TWISTS */
L130:
	for (j = 3; j <= 4; ++j) {
	    for (k = 3; k <= 4; ++k) {
/* L140: */
		bout[i__ + (j + (k << 2)) * 3 - 16] = 0.f;
	    }
	}
	goto L120;
L200:
	bout[i__ + 23] = bin[i__ + 51] - bin[i__ + 15];
	bout[i__ + 35] = bout[i__ + 23];
	bout[i__ + 26] = bin[i__ + 60] - bin[i__ + 24];
	bout[i__ + 38] = bout[i__ + 26];
	bout[i__ + 29] = bout[i__ + 17] - bout[i__ + 5];
	bout[i__ + 41] = bout[i__ + 29];
	bout[i__ + 32] = bout[i__ + 20] - bout[i__ + 8];
	bout[i__ + 44] = bout[i__ + 32];
L120:
	;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (k = 1; k <= 4; ++k) {
	    for (j = 1; j <= 4; ++j) {
		in = (i__ - 1 << 4) + (k - 1 << 2) + j;
		out[in] = bout[i__ + (j + (k << 2)) * 3 - 16];
		w = out[in];
		w = abs(w);
		if (w < smal) {
		    out[in] = zero;
		}
/* L220: */
	    }
	}
    }
    return 0;
} /* bezier_ */

