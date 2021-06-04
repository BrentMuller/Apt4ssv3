/* CNSURH.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0001056.V02   *** */

/* Subroutine */ int cnsurh_(doublereal *u, doublereal *v, doublereal *b, 
	doublereal *spv, integer *iflag, integer *mmode)
{
    /* Initialized data */

    static doublereal one = 1.;
    static integer iflx[4] = { 4,4,4,1 };
    static doublereal zero = 0.;

    /* System generated locals */
    static doublereal equiv_5[64];

    /* Local variables */
    static integer i__, j, k, l;
#define r__ (equiv_5)
    static doublereal u1, v1;
    static integer ia, ib, ii;
    static doublereal va, vb;
    static integer in;
    static doublereal fv[12];
#define rk (equiv_5)
#define rt (equiv_5 + 32)
    static doublereal ut;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer loc;
    static doublereal spw[32];
    static integer mode, kinc, jlev;
#define canon ((doublereal *)&_BLNK__1)
    static doublereal bsave;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int blendf_(doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int curflo_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), cnsurg_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);

/* ------  INTERPOLATION FORMULAS FOR VARIOUS TYPES OF GENCUR */
/* ------  PATCHES ARE HERE. */
/* ---     BLANK COMMON INCLUDED TO PROVIDE ACCESS TO SURFACE */
/* ---     FOR THE SPECIAL CASE OF A SURFACE THRU GENERAL CURVES */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --iflag;
    --spv;
    --b;

    /* Function Body */
/* --- INPUT CONSISTS OF PARAMETRIC U,V COORDINATES.  THE UNIT SQUARE */
/* --- DIVIDES THE PLANE INTO 9 SECTORS.  THIS ROUTINE DETERMINES THE */
/* --- CORRECT SECTOR FOR U,V AND THEN COMPUTES SURFACE DIFFERENTIAL */
/* --- QUANTITIES FOR THE NATURAL PATCH OR ELSE FOR ITS RULED EXTENSIONS */


    u1 = *u;
    v1 = *v;
    mode = *mmode;

/* ---     SPECIAL PATH FOR HANDLING A PATCH THRU GENERAL CURVES. */
/* ---     FIRST DECOMPOSE THE PATCH FLAG INTO COMPONENTS FOR */
/* ---     INTERPOLATING BOUNDARIES 1 AND 2 AND BOUNDARIES 3 AND 4 */

/* L100: */
    ii = (integer) abs(b[1]);
    ia = ii % 10;
    ib = ii / 10;
    ib %= 10;
/* ---     LEVEL OF INTERPOLATION IS DIFFERENT FOR RULED INTERPOLATION */
/* ---     AND HIGHER LEVEL OF INTERPOLATION */
    if (ia < 2) {
	jlev = 1;
    }
    if (ia > 1) {
	jlev = 2;
    }

/* ---     OBTAIN DERIVATIVES AT CORRESPONDING EDGES OF BOUNDARIES */
/* ---     NUMBERED 1 AND 2 */
    for (i__ = 1; i__ <= 2; ++i__) {
	loc = iflag[i__];
	curflo_(u, &canon[loc - 1], &rk[(i__ << 5) - 32], &jlev, &c__1);
/* L110: */
    }
/* ---      BRANCH TO NON RULED TYPE OF INTERPOLATION */
    if (ia > 1) {
	goto L200;
    }
/* ---     RULED TYPE OF INTERPOLATION FOLLOWS */
    va = one - v1;
    vb = v1;
    for (i__ = 1; i__ <= 3; ++i__) {
	spv[i__] = rk[i__ - 1] * va + rk[i__ + 31] * vb;
	if (mode == 0) {
	    goto L120;
	}
	spv[i__ + 4] = rk[i__ + 3] * va + rk[i__ + 35] * vb;
	spv[i__ + 12] = rk[i__ + 7] * va + rk[i__ + 39] * vb;
	spv[i__ + 8] = rk[i__ + 31] - rk[i__ - 1];
	spv[i__ + 20] = zero;
	spv[i__ + 16] = rk[i__ + 35] - rk[i__ + 3];
L120:
	;
    }

L140:

    goto L999;

/* ---     THE CASE OF NON-RULED INTERPOLATION */
L200:
    blendf_(v, fv);
    for (i__ = 1; i__ <= 3; ++i__) {
	spv[i__] = fv[0] * rk[i__ - 1] + fv[1] * rk[i__ + 31] + fv[2] * rk[
		i__ + 15] + fv[3] * rk[i__ + 47];
	if (mode == 0) {
	    goto L210;
	}
	spv[i__ + 4] = fv[0] * rk[i__ + 3] + fv[1] * rk[i__ + 35] + fv[2] * 
		rk[i__ + 19] + fv[3] * rk[i__ + 51];
	spv[i__ + 8] = fv[4] * rk[i__ - 1] + fv[5] * rk[i__ + 31] + fv[6] * 
		rk[i__ + 15] + fv[7] * rk[i__ + 47];
	spv[i__ + 12] = fv[0] * rk[i__ + 7] + fv[1] * rk[i__ + 39] + fv[2] * 
		rk[i__ + 23] + fv[3] * rk[i__ + 55];
	spv[i__ + 16] = fv[4] * rk[i__ + 3] + fv[5] * rk[i__ + 35] + fv[6] * 
		rk[i__ + 19] + fv[7] * rk[i__ + 51];
	spv[i__ + 20] = fv[8] * rk[i__ - 1] + fv[9] * rk[i__ + 31] + fv[10] * 
		rk[i__ + 15] + fv[11] * rk[i__ + 47];
L210:
	;
    }

    if (ib < 2) {
	goto L140;
    }

/* ---     THE FULL CROSS CURVE CASE, TWO MORE LEVELS OF INTERPOLATION */
/* ---     ARE NOW REQUIRED. */

/* ---     FIRST LOAD THE TWO CROSS CURVES AND INTERPOLATE THEM */
    for (i__ = 3; i__ <= 4; ++i__) {
	loc = iflag[i__];
	ii = i__ - 2;
	curflo_(v, &canon[loc - 1], &rk[(ii << 5) - 32], &jlev, &c__1);
/* L410: */
    }
    bsave = b[1];
    blendf_(u, fv);
    for (i__ = 1; i__ <= 3; ++i__) {
	spw[i__ - 1] = spv[i__] + fv[0] * rk[i__ - 1] + fv[1] * rk[i__ + 31] 
		+ fv[2] * rk[i__ + 15] + fv[3] * rk[i__ + 47];
	if (mode == 0) {
	    goto L420;
	}
	spw[i__ + 3] = spv[i__ + 8] + fv[0] * rk[i__ + 3] + fv[1] * rk[i__ + 
		35] + fv[2] * rk[i__ + 19] + fv[3] * rk[i__ + 51];
	spw[i__ + 7] = spv[i__ + 4] + fv[4] * rk[i__ - 1] + fv[5] * rk[i__ + 
		31] + fv[6] * rk[i__ + 15] + fv[7] * rk[i__ + 47];
	spw[i__ + 11] = spv[i__ + 20] + fv[0] * rk[i__ + 7] + fv[1] * rk[i__ 
		+ 39] + fv[2] * rk[i__ + 23] + fv[3] * rk[i__ + 55];
	spw[i__ + 15] = spv[i__ + 16] + fv[4] * rk[i__ + 3] + fv[5] * rk[i__ 
		+ 35] + fv[6] * rk[i__ + 19] + fv[7] * rk[i__ + 51];
	spw[i__ + 19] = spv[i__ + 12] + fv[8] * rk[i__ - 1] + fv[9] * rk[i__ 
		+ 31] + fv[10] * rk[i__ + 15] + fv[11] * rk[i__ + 47];
L420:
	;
    }
/* ---     FINALLY SET UP MATRIX FOR CONVENTIONAL COONS INTERPOLATION */

    for (i__ = 1; i__ <= 2; ++i__) {

	loc = iflag[i__];
	for (j = 1; j <= 2; ++j) {
	    ut = (doublereal) (j - 1);
	    curflo_(&ut, &canon[loc - 1], r__, &c__2, &c__1);
	    in = j + (i__ - 1 << 2) - 1;
	    kinc = 0;
	    for (k = 1; k <= 33; k += 16) {
		++kinc;
		b[in + k] = r__[kinc - 1];
		b[in + k + 2] = r__[kinc + 3];
		b[in + k + 8] = r__[kinc + 15];
		b[in + k + 10] = r__[kinc + 19];
/* L430: */
	    }
/* ---     SET THE W MATRIX */
	    for (l = 51; l <= 64; ++l) {
		b[l] = zero;
/* L435: */
	    }
	    b[49] = one;
	    b[50] = one;
	    b[53] = one;
	    b[54] = one;

/* L470: */
	}
    }

/* ---     NOW EVALUATE COONS INTERPOLATION OF SURFACE POINT */

    cnsurg_(u, v, &b[1], &spv[1], iflx, &mode);

/* ---     NOWSUBTRACT THIS POINT AND DERIVATIVES FROM SPW */
/* ---     TO OBTAIN THE CONSTRAINED INTERPOLATION. */

    for (i__ = 1; i__ <= 3; ++i__) {
	spv[i__] = spw[i__ - 1] - spv[i__];
	if (mode < 1) {
	    goto L450;
	}
	spv[i__ + 4] = spw[i__ + 7] - spv[i__ + 4];
	spv[i__ + 8] = spw[i__ + 3] - spv[i__ + 8];
	spv[i__ + 12] = spw[i__ + 19] - spv[i__ + 12];
	spv[i__ + 16] = spw[i__ + 15] - spv[i__ + 16];
	spv[i__ + 20] = spw[i__ + 11] - spv[i__ + 20];
L450:
	;
    }
/* ---     NOW RESTORE THE B MATRIX */
    for (i__ = 2; i__ <= 64; ++i__) {
/* L480: */
	b[i__] = zero;
    }
    b[49] = one;
    b[50] = one;
    b[53] = one;
    b[54] = one;
    b[1] = bsave;

L999:
    return 0;
} /* cnsurh_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef rt
#undef rk
#undef r__


