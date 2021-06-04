/* CNSURG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000617.V02   *** */

/* Subroutine */ int cnsurg_(doublereal *u, doublereal *v, doublereal *b, 
	doublereal *spv, integer *iflag, integer *mode)
{
    /* Initialized data */

    static integer nt[6] = { 1,5,1,9,5,1 };
    static integer ng[6] = { 1,1,5,1,5,9 };
    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static doublereal f[12], g[12];
    static integer i__, k, l, m, n;
    static doublereal t[12];
    static integer lg, lv, klim;
    static logical imode;
    extern /* Subroutine */ int blendf_(doublereal *, doublereal *);

/* --  MODULAR.  PURPOSE IS TO GENERATE SURFACE POINT AND DIFFERENTIAL */
/* --  ELEMENTS ON A COONS PATCH (B) FROM INPUT COORDINATES U,V. */
/* --  U,V = INPUT SURFACE COORDINATES */
/* --  B   = INPUT COONS PATCH COEFFICIENTS */
/* --  IFLAG = INPUT ARRAY WHICH RECORDS THE TYPE OF EACH 16-COMPONENT */
/* --           MATRIX IN THE ARRAY B( 1=CONSTANT,2=LINEAR,3,4=FULL) */
/* --  MODE  = INPUT.  MODE=0 MEANS ONLY SURFACE POINT REQD. */
/* --               OTHERWISE FIRST AND SECOND ORDER DIFFERENTIAL ELEMENTS */
/* --                ARE ALSO REQUIRED */
/* --  SPV   = OUTPUT  SPV(1-4)= PROJECTIVE COORDINATES OF SURFACE POINT */
/* --               SPV(5-8) = P.C. OF FIRST DERIV WRT U */
/* --                SPV(9-12)=  P.C. OF FIRST DERIV WRT V */
/* --                SPV(13-16)= P.C. OF SECOND DERIV WRT U */
/* --                SPV(17-20) = P.C. OF MIXED PARTIAL WRT U,V */
/* --                SPV(21-24) = P.C. OF SECOND DERIV WRT TO V */
/* ---     POINTERS FOR RAPID EVALUATION OF SPV THRU PRODUCTS OF T AND G. */
    /* Parameter adjustments */
    --iflag;
    --spv;
    --b;

    /* Function Body */



    imode = FALSE_;
    if (*mode == 0) {
	imode = TRUE_;
    }
/* ------ EVALUATE COONS BLEND FUNCTIONS AND THEIR DERIVATIVES */
/* ------ FOR PARAMETER VALUES U AND V */
    blendf_(u, f);
    blendf_(v, g);
/* ------ EVALUATE THE PROJECTIVE SURFACE POINT AND PARTIAL DERIVATIVE */
/* ------ COORDINATES.  EACH COORDINATE SET(X,Y,Z,W) IS EVALUATED */
/* ------ ON SUCCESSIVE PASSES THRU THE 10 LOOP AND SPECIAL SPEED */
/* ------ ROUTES ARE TAKEN FOR A LINEAR OR CONSTANT COORDINATE */
/* ------ MATRIX */
    for (i__ = 1; i__ <= 4; ++i__) {
	k = iflag[i__];
	switch (k) {
	    case 1:  goto L100;
	    case 2:  goto L200;
	    case 3:  goto L300;
	    case 4:  goto L300;
	}
L300:
	n = (i__ << 4) - 16;
	klim = 9;
	if (imode) {
	    klim = 1;
	}
	i__1 = klim;
	for (l = 1; l <= i__1; l += 4) {
	    t[l - 1] = f[l - 1] * b[n + 1] + f[l] * b[n + 2] + f[l + 1] * b[n 
		    + 3] + f[l + 2] * b[n + 4];
	    t[l] = f[l - 1] * b[n + 5] + f[l] * b[n + 6] + f[l + 1] * b[n + 7]
		     + f[l + 2] * b[n + 8];
	    t[l + 1] = f[l - 1] * b[n + 9] + f[l] * b[n + 10] + f[l + 1] * b[
		    n + 11] + f[l + 2] * b[n + 12];
	    t[l + 2] = f[l - 1] * b[n + 13] + f[l] * b[n + 14] + f[l + 1] * b[
		    n + 15] + f[l + 2] * b[n + 16];
/* L310: */
	}
	spv[i__] = t[0] * g[0] + t[1] * g[1] + t[2] * g[2] + t[3] * g[3];
	if (imode) {
	    goto L10;
	}

	lv = 0;
	for (l = 1; l <= 5; ++l) {
	    lv += 4;
	    m = nt[l];
	    lg = ng[l];
	    spv[i__ + lv] = t[m - 1] * g[lg - 1] + t[m] * g[lg] + t[m + 1] * 
		    g[lg + 1] + t[m + 2] * g[lg + 2];
/* L320: */
	}
	goto L10;

L100:
	spv[i__] = b[(i__ << 4) - 15];
	if (imode) {
	    goto L10;
	}
	for (l = 4; l <= 20; l += 4) {
/* L110: */
	    spv[i__ + l] = zero;
	}
	goto L10;

L200:
	n = (i__ << 4) - 15;
	t[0] = b[n];
	t[1] = b[n + 1] - b[n];
	t[2] = b[n + 4] - b[n];
	t[3] = b[n + 5] - b[n + 4] - t[1];
	spv[i__] = t[0] + t[1] * *u + (t[2] + t[3] * *u) * *v;
	if (imode) {
	    goto L10;
	}
	spv[i__ + 4] = t[1] + t[3] * *v;
	spv[i__ + 8] = t[2] + t[3] * *u;
	spv[i__ + 12] = zero;
	spv[i__ + 16] = t[3];
	spv[i__ + 20] = zero;
L10:
	;
    }

    if (iflag[4] == 1) {
	goto L400;
    }

/* --  INTERPOLATE EUCLIDEAN QUANTITIES FROM PROJECTIVE QUANTITIES */
/* ---     PATCH IS OF RATIONAL FORM SO COMPUTE DERIVATIVES BY RATIOS. */
/* ---     FIRST EVALUATE FIXED W DERIVATIVES AND RATIOS. */
    if (imode) {
	goto L360;
    }
/* ---     T(1)=WSQ, 2=WU, 3=WV, 4=TWU, 5=TWV, 6=WUU, 7=WUV, 8=WVV */
/* Computing 2nd power */
    d__1 = spv[4];
    t[0] = d__1 * d__1;
    t[1] = spv[8] / t[0];
    t[2] = spv[12] / t[0];
    t[3] = (spv[8] + spv[8]) / spv[4];
    t[4] = (spv[12] + spv[12]) / spv[4];
    t[5] = spv[16] / t[0];
    t[6] = spv[20] / t[0];
    t[7] = spv[24] / t[0];
/* ---     LOOP TO EVALUATE RATIONAL DERIVATIVES FOR X,Y,Z COMPONENTS */
    for (l = 1; l <= 3; ++l) {
/* ---     PARTIAL OF F WITH RESPECT TO U =FU. */
	spv[l + 4] = spv[l + 4] / spv[4] - spv[l] * t[1];
/* ---     PARTIAL OF F WITH RESPECT TO V */
	spv[l + 8] = spv[l + 8] / spv[4] - spv[l] * t[2];
/* ---     SECOND PARTIAL OF F WITH RESPECT TO U. */
	spv[l + 12] = -t[3] * spv[l + 4] + spv[l + 12] / spv[4] - spv[l] * t[
		5];
/* ---     SECOND PARTIAL OF F WITH RESPECT TO V. */
	spv[l + 20] = -t[4] * spv[l + 8] + spv[l + 20] / spv[4] - spv[l] * t[
		7];
/* ---     MIXED SECOND PARTIAL OF F WITH RESPECT TO U AND V. */
	spv[l + 16] = -(t[4] * spv[l + 4] + t[3] * spv[l + 8]) / 2.f + spv[l 
		+ 16] / spv[4] - spv[l] * t[6];
/* ---     NOTE THAT THE ORDER OF THE ABOVE CALCULATIONS IS SENSITIVE */
/* L350: */
    }

L360:
    for (l = 1; l <= 3; ++l) {
	spv[l] /= spv[4];
/* L370: */
    }

L400:
/* ---     SET INDICATOR VALUES FOR QUANTITIES COMPUTED */
    if (imode) {
	goto L501;
    }
    for (i__ = 8; i__ <= 24; i__ += 4) {
/* L500: */
	spv[i__] = one;
    }
L501:
    spv[4] = one;

    return 0;
} /* cnsurg_ */

