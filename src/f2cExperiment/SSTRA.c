/* SSTRA.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__34 = 34;
static integer c__36 = 36;
static integer c__25 = 25;
static integer c__12 = 12;
static integer c__5 = 5;

/* *** SOURCE FILE : M0008157.V11   *** */

/* Subroutine */ int sstra_(doublereal *xma, doublereal *ana, doublereal *can,
	 integer *isprnt)
{
    /* Initialized data */

    static char blank[8] = "        ";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a[16]	/* was [4][4] */, b[96]	/* was [4][24] */, 
	    c__[96]	/* was [4][24] */, d__;
    static integer i__, j, k, l, m, n;
    static doublereal w[16];
    static integer i1, ia, ib, ic, ka, ih, ii, jj, jk, kk, ll, ml, mm, iq, iu,
	     iv, iw, ix, nr, ia1, ia2, jmd, ijk, isc, nwd, nnn, npt, nst, 
	    ignc, iflg[4], narc, npch;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    static char aname[16], tname[8];
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen), teval_(char *, doublereal *, doublereal *, 
	    ftnlen), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen), cprint_(char *, ftnlen), sspict_(doublereal *,
	     char *, integer *, ftnlen);

/* ----------  THE PURPOSE OF THIS SUBROUTINE IS TO PERFORM GEOMETRY */
/* ----------  TRANSFORMATION FOR THE SCULPTURED SURFACES. */
/* ----------      XMA     TRANSFORMATION MATRIX */
/* ----------      ANA     SURFACE NAME */
/* ----------      CAN     CANON OF THE SURFACE */
/* ----------      ISPRNT  PRINT FLAG */
/* ---------- */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --can;
    --ana;
    --xma;

    /* Function Body */

/* ---      BUDD CHANGE TO TEST TABPRT FLAG FOR PRINT OUTPUT. */
    ignc = 0;
    holfrm_(&ana[3], aname, &c__1, &c__8, &nwd, (ftnlen)16);
    s_copy(aname + 8, blank, (ftnlen)8, (ftnlen)8);
    if (*isprnt == 0) {
	goto L2;
    }
    for (i__ = 1; i__ <= 15; ++i__) {
	i1 = i__ << 3;
/* L1: */
	i__1 = i1 - 8;
	s_copy(darray_1.darray + i__1, blank, i1 - i__1, (ftnlen)8);
    }
    cform_("1THE FOLLOWING SSURF OR SCURV WAS ", darray_1.darray, &c__1, &
	    c__34, (ftnlen)34, (ftnlen)120);
    cform_("TRANSFORMED BY THE MATRIX", darray_1.darray, &c__36, &c__25, (
	    ftnlen)25, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
/* ***  INPUT MATRIX */
L2:
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
    if (*isprnt == 0) {
	goto L3;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	k = 2;
	for (j = 1; j <= 4; ++j) {
	    fconv_(&a[i__ + (j << 2) - 5], darray_1.darray, &k, &c__12, &c__5,
		     (ftnlen)120);
	    k += 12;
/* L11: */
	}
	cprint_(darray_1.darray, (ftnlen)120);
/* L12: */
    }
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
/* ***  ************ */
L3:
    npch = (integer) can[4];
    nnn = (integer) can[5];
    for (i__ = 1; i__ <= 16; ++i__) {
/* L15: */
	w[i__ - 1] = 0.f;
    }
    w[0] = 1.f;
    w[1] = w[0];
    w[4] = w[0];
    w[5] = w[0];
    i__1 = npch;
    for (n = 1; n <= i__1; ++n) {
	i__ = (n - 1) * 6 + 11;
	iflg[0] = (integer) can[i__];
	iflg[1] = (integer) can[i__ + 1];
	iflg[2] = (integer) can[i__ + 2];
	iflg[3] = (integer) can[i__ + 3];
	if (iflg[1] != 0) {
	    goto L8;
	}
/* NON NATIVE PATCH TRANSFORMATION */
	ignc = 1;
	holfrm_(&can[i__ + 4], tname, &c__1, &c__8, &nwd, (ftnlen)8);
	teval_(tname, &xma[1], &can[iflg[0]], (ftnlen)8);
	goto L500;
L8:
	iv = (integer) can[i__ + 4];
	if (iv < 0) {
	    goto L1000;
	}
/* ----------  GENERAL CURVE TYPE BRANCH TO 1000 */
/* ----------  COONS BICUBIC PATCH FOLLOWS */
	if (iflg[3] != 4) {
	    goto L19;
	}
	iu = iv + 47;
	for (iw = 1; iw <= 16; ++iw) {
	    ix = iu + iw;
/* L17: */
	    w[iw - 1] = can[ix];
	}
L19:
/* ----------  NON TWIST CONSTANT */
	mm = 12;
	nst = 3;
	ih = 1;
	if (iflg[0] == 3) {
	    goto L50;
	}
/* ----------  TWIST CONSTANT */
	mm = 16;
	nst = 4;
L50:
	if (iflg[0] < 3) {
	    goto L900;
	}
	i__2 = nst;
	for (ijk = 1; ijk <= i__2; ++ijk) {
	    ia = iv;
	    ib = iv + mm;
	    ic = iv + mm + mm;
	    b[0] = can[ia];
	    b[1] = can[ib];
	    b[2] = can[ic];
	    b[3] = w[ih - 1];
	    b[4] = can[ia + 1];
	    b[5] = can[ib + 1];
	    b[6] = can[ic + 1];
	    b[7] = w[ih];
	    l = 4;
	    if (ijk == 3 && nst == 3) {
		l = 2;
	    }
	    b[8] = can[ia + l];
	    b[9] = can[ib + l];
	    b[10] = can[ic + l];
	    b[11] = w[ih + l - 1];
	    b[12] = can[ia + l + 1];
	    b[13] = can[ib + l + 1];
	    b[14] = can[ic + l + 1];
	    b[15] = w[ih + l];
	    for (ka = 1; ka <= 4; ++ka) {
		for (ii = 1; ii <= 4; ++ii) {
		    d__ = 0.f;
		    for (jj = 1; jj <= 4; ++jj) {
			c__[ii + (ka << 2) - 5] = a[ii + (jj << 2) - 5] * b[
				jj + (ka << 2) - 5] + d__;
/* L20: */
			d__ = c__[ii + (ka << 2) - 5];
		    }
/* L30: */
		}
/* L40: */
	    }
	    ia = iv;
	    ib = iv + mm;
	    ic = iv + mm + mm;
	    can[ia] = c__[0];
	    can[ib] = c__[1];
	    can[ic] = c__[2];
	    can[ia + 1] = c__[4];
	    can[ib + 1] = c__[5];
	    can[ic + 1] = c__[6];
	    can[ia + l] = c__[8];
	    can[ib + l] = c__[9];
	    can[ic + l] = c__[10];
	    can[ia + l + 1] = c__[12];
	    can[ib + l + 1] = c__[13];
	    can[ic + l + 1] = c__[14];
	    iv += 2;
	    if (ijk == 2) {
		iv += 4;
	    }
	    ih += 2;
	    if (ijk == 2) {
		ih += 4;
	    }
/* L400: */
	}
	goto L500;
/* ----------  GENCUR  SURFACE */
L1000:
	ignc = 1;
	for (jk = 1; jk <= 4; ++jk) {
	    isc = iflg[jk - 1];
	    if (isc == 0) {
		goto L1900;
	    }
	    narc = (integer) can[isc + 3];
	    npt = narc + 1;
	    iq = (integer) (can[isc + 4] + isc - 1);
	    ia = iq;
	    i__2 = narc;
	    for (nr = 1; nr <= i__2; ++nr) {
		ib = ia;
		for (m = 1; m <= 4; ++m) {
		    b[(m << 2) - 4] = can[ib];
		    b[(m << 2) - 3] = can[ib + 4];
		    b[(m << 2) - 2] = can[ib + 8];
		    b[(m << 2) - 1] = can[ib + 12];
		    ++ib;
/* L1100: */
		}
		ib = ia;
/* ----------  CRSSPL  AND  NANDMAL */
		for (k = 1; k <= 2; ++k) {
		    kk = k + 4;
		    ic = ib - (3 - k << 2);
		    b[(kk << 2) - 4] = can[ic];
		    b[(kk << 2) - 3] = can[ic + 1];
		    b[(kk << 2) - 2] = can[ic + 2];
		    b[(kk << 2) - 1] = 0.f;
/* L1300: */
		}
		ml = 6;
		if (nr != narc) {
		    goto L1500;
		}
		ia1 = ia + 19;
		ia2 = ia + 23;
		if (can[ia1] == 0. && can[ia2] == 0.) {
		    goto L1500;
		}
		for (k = 1; k <= 2; ++k) {
		    kk = k + 6;
		    ic = ib + 16 + (k - 1 << 2);
		    b[(kk << 2) - 4] = can[ic];
		    b[(kk << 2) - 3] = can[ic + 1];
		    b[(kk << 2) - 2] = can[ic + 2];
		    b[(kk << 2) - 1] = 0.f;
/* L1310: */
		}
		ml = 8;
L1500:
		i__3 = ml;
		for (ka = 1; ka <= i__3; ++ka) {
		    for (ii = 1; ii <= 4; ++ii) {
			d__ = 0.f;
			for (jj = 1; jj <= 4; ++jj) {
			    c__[ii + (ka << 2) - 5] = a[ii + (jj << 2) - 5] * 
				    b[jj + (ka << 2) - 5] + d__;
/* L120: */
			    d__ = c__[ii + (ka << 2) - 5];
			}
/* L130: */
		    }
/* L140: */
		}
		ib = ia;
		for (m = 1; m <= 4; ++m) {
		    can[ib] = c__[(m << 2) - 4];
		    can[ib + 4] = c__[(m << 2) - 3];
		    can[ib + 8] = c__[(m << 2) - 2];
		    can[ib + 12] = c__[(m << 2) - 1];
		    ++ib;
/* L1600: */
		}
		ib = ia;
		for (k = 1; k <= 2; ++k) {
		    kk = k + 4;
		    ic = ib - (3 - k << 2);
		    can[ic] = c__[(kk << 2) - 4];
		    can[ic + 1] = c__[(kk << 2) - 3];
		    can[ic + 2] = c__[(kk << 2) - 2];
/* L1700: */
		}
		if (ml == 6) {
		    goto L1800;
		}
		for (k = 1; k <= 2; ++k) {
		    kk = k + 6;
		    ic = ib + 16 + (k - 1 << 2);
		    can[ic] = c__[(kk << 2) - 4];
		    can[ic + 1] = c__[(kk << 2) - 3];
		    can[ic + 2] = c__[(kk << 2) - 2];
/* L1710: */
		}
L1800:
		ia += 24;
/* L1200: */
	    }
L1900:
	    ;
	}
L500:
	;
    }
    if (ignc != 1) {
	goto L550;
    }
    jmd = 1;
    apt094_(&jmd, &ana[1], &can[1]);
L550:
    if (*isprnt == 0) {
	goto L999;
    }
    sspict_(&can[1], aname, isprnt, (ftnlen)16);
    goto L999;
/* ----------  LINEAR OR CONSTANT MATRIX, WILL NOT TRANSFORM */
L900:
L999:
    return 0;
} /* sstra_ */

