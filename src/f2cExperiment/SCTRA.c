/* SCTRA.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__34 = 34;
static integer c__36 = 36;
static integer c__25 = 25;
static integer c__12 = 12;
static integer c__5 = 5;

/* *** SOURCE FILE : M0001090.V07   *** */

/* Subroutine */ int sctra_(doublereal *xma, doublereal *ana, doublereal *can,
	 integer *isprnt)
{
    /* Initialized data */

    static char blank[8] = "        ";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a[16]	/* was [4][4] */, b[96]	/* was [4][24] */, 
	    c__[96]	/* was [4][24] */, d__;
    static integer i__, j, k, m, n, ia, ib, ic, ka, ii, jj, kk, ll, ml, iv, 
	    ia1, ia2, nwd, npt, ignc, narc;
    static char aname[16];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen);
    static char darray[120];
    extern /* Subroutine */ int scpict_(doublereal *, char *, integer *, 
	    ftnlen), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen), cprint_(char *, ftnlen);

/* ----------  THE PURPOSE OF THIS SUBROUTINE IS TO PERFORM GEOMETRY */
/* ----------  TRANSFORMATION FOR THE SYNTHETIC CURVESS. */
/* ----------      XMA     TRANSFORMATION MATRIX */
/* ----------      ANA     CURVE NAME */
/* ----------      CAN     CANON OF THE CURVE */
/* ----------      ISPRNT  PRINT FLAG */
/* ---------- */
    /* Parameter adjustments */
    --can;
    --ana;
    --xma;

    /* Function Body */
    ignc = 0;
    holfrm_(&ana[3], aname, &c__1, &c__8, &nwd, (ftnlen)16);
    s_copy(aname + 8, blank, (ftnlen)8, (ftnlen)8);
    s_copy(darray, blank, (ftnlen)120, (ftnlen)8);
    cform_("1THE FOLLOWING SSURF OR SCURV WAS ", darray, &c__1, &c__34, (
	    ftnlen)34, (ftnlen)120);
    cform_("TRANSFORMED BY THE MATRIX", darray, &c__36, &c__25, (ftnlen)25, (
	    ftnlen)120);
    cprint_(darray, (ftnlen)120);
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprint_(darray, (ftnlen)120);
/* ***  INPUT MATRIX */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    ll = (i__ - 1 << 2) + j;
	    a[i__ + (j << 2) - 5] = xma[ll];
/* L7: */
	}
    }
    a[3] = 0.f;
    a[7] = 0.f;
    a[11] = 0.f;
    a[15] = 1.f;
/* ***  ************ */
    for (i__ = 1; i__ <= 4; ++i__) {
	k = 2;
	for (j = 1; j <= 4; ++j) {
	    fconv_(&a[i__ + (j << 2) - 5], darray, &k, &c__12, &c__5, (ftnlen)
		    120);
	    k += 12;
/* L11: */
	}
	cprint_(darray, (ftnlen)120);
/* L12: */
    }
    cform_("0", darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprint_(darray, (ftnlen)120);
    narc = (integer) can[4];
    npt = narc + 1;
    iv = (integer) can[5];
    ia = iv;
    i__1 = narc;
    for (n = 1; n <= i__1; ++n) {
	ib = ia;
	for (m = 1; m <= 4; ++m) {
	    b[(m << 2) - 4] = can[ib];
	    b[(m << 2) - 3] = can[ib + 4];
	    b[(m << 2) - 2] = can[ib + 8];
	    b[(m << 2) - 1] = can[ib + 12];
	    ++ib;
/* L2100: */
	}
	ib = ia;
/* ----------  CRSSPL  OR  NORMAL */
	for (k = 1; k <= 2; ++k) {
	    kk = k + 4;
	    ic = ib - (3 - k << 2);
	    b[(kk << 2) - 4] = can[ic];
	    b[(kk << 2) - 3] = can[ic + 1];
	    b[(kk << 2) - 2] = can[ic + 2];
	    b[(kk << 2) - 1] = 0.f;
/* L2300: */
	}
	ml = 6;
	if (n != narc) {
	    goto L2500;
	}
	ia1 = ia + 19;
	ia2 = ia + 23;
	if (can[ia1] == 0. && can[ia2] == 0.) {
	    goto L2500;
	}
	for (k = 1; k <= 2; ++k) {
	    kk = k + 6;
	    ic = ib + 16 + (k - 1 << 2);
	    b[(kk << 2) - 4] = can[ic];
	    b[(kk << 2) - 3] = can[ic + 1];
	    b[(kk << 2) - 2] = can[ic + 2];
	    b[(kk << 2) - 1] = 0.f;
/* L2310: */
	}
	ml = 8;
L2500:
	i__2 = ml;
	for (ka = 1; ka <= i__2; ++ka) {
	    for (ii = 1; ii <= 4; ++ii) {
		d__ = 0.f;
		for (jj = 1; jj <= 4; ++jj) {
		    c__[ii + (ka << 2) - 5] = a[ii + (jj << 2) - 5] * b[jj + (
			    ka << 2) - 5] + d__;
/* L220: */
		    d__ = c__[ii + (ka << 2) - 5];
		}
/* L230: */
	    }
/* L240: */
	}
	ib = ia;
	for (m = 1; m <= 4; ++m) {
	    can[ib] = c__[(m << 2) - 4];
	    can[ib + 4] = c__[(m << 2) - 3];
	    can[ib + 8] = c__[(m << 2) - 2];
	    can[ib + 12] = c__[(m << 2) - 1];
	    ++ib;
/* L2600: */
	}
	ib = ia;
	for (k = 1; k <= 2; ++k) {
	    kk = k + 4;
	    ic = ib - (3 - k << 2);
	    can[ic] = c__[(kk << 2) - 4];
	    can[ic + 1] = c__[(kk << 2) - 3];
	    can[ic + 2] = c__[(kk << 2) - 2];
/* L2700: */
	}
	if (ml == 6) {
	    goto L2800;
	}
	for (k = 1; k <= 2; ++k) {
	    kk = k + 6;
	    ic = ib + 16 + (k - 1 << 2);
	    can[ic] = c__[(kk << 2) - 4];
	    can[ic + 1] = c__[(kk << 2) - 3];
	    can[ic + 2] = c__[(kk << 2) - 2];
/* L2710: */
	}
L2800:
	ia += 24;
/* L2200: */
    }
    scpict_(&can[1], aname, isprnt, (ftnlen)16);
/* L999: */
    return 0;
} /* sctra_ */

