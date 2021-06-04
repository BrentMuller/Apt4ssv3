/* LINEAR.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002770.V02   *** */

/* Subroutine */ int linear_(doublereal *scan, doublereal *spl, doublereal *
	pnts, integer *ilin)
{
    /* Initialized data */

    static integer iu[3] = { 1,2,3 };
    static integer iv[3] = { 2,3,1 };
    static doublereal azero = 1e-7;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, m, n;
    static doublereal x[200], y[200];
    static integer ia, ib, ic, id, ja, mn, nm, nu, nv, i1n, in1;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal slop[200];
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal aslop, bslop, cslop, dslop;
    static integer idebug;
#define bcanon ((doublereal *)&_BLNK__1 + 40)




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --scan;

    /* Function Body */
    idebug = 0;
    id = (integer) sscan[5];
    ia = (integer) (*spl);
    ib = (integer) (*pnts);
    nu = iu[id - 1];
    nv = iv[id - 1];
    i__1 = ia;
    for (j = 1; j <= i__1; ++j) {
	i__2 = ib;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ic = (j - 1) * ib * 3 + (i__ - 1) * 3;
	    x[i__ + j * ib - ib - 1] = scan[ic + nu];
	    y[i__ + j * ib - ib - 1] = scan[ic + nv];
/* L150: */
	}
    }
    i__ = ia;
    j = ib;
    i__2 = i__;
    for (n = 1; n <= i__2; ++n) {
	ja = j - 1;
	i__1 = ja;
	for (m = 1; m <= i__1; ++m) {
	    mn = m + ib * n - ib;
	    if ((d__1 = x[mn] - x[mn - 1], abs(d__1)) <= azero) {
		goto L101;
	    }
	    slop[mn - 1] = (y[mn] - y[mn - 1]) / (x[mn] - x[mn - 1]);
	    if ((d__1 = slop[mn - 1], abs(d__1)) <= azero) {
		slop[mn - 1] = 0.f;
	    }
	    goto L100;
L101:
	    slop[mn - 1] = 9999.f;
L100:
	    ;
	}
    }
    cslop = slop[0] * 1.001f;
    dslop = slop[0] * .999f;
    i__1 = i__;
    for (n = 1; n <= i__1; ++n) {
	i1n = (n - 1) * ib + 1;
	aslop = slop[i1n - 1] * 1.001f;
	bslop = slop[i1n - 1] * .999f;
	i__2 = ja;
	for (m = 1; m <= i__2; ++m) {
	    mn = m + (n - 1) * ib;
	    if (slop[mn - 1] <= aslop && slop[mn - 1] >= bslop) {
		goto L110;
	    }
	    goto L130;
L110:
	    ;
	}
	if (slop[i1n - 1] <= cslop && slop[i1n - 1] >= dslop) {
	    goto L120;
	}
	goto L130;
L120:
	;
    }
    goto L1500;
L130:
    *ilin = 0;
    goto L300;
L1500:
    i__1 = j;
    for (n = 1; n <= i__1; ++n) {
	ia = i__ - 1;
	i__2 = ia;
	for (m = 1; m <= i__2; ++m) {
	    nm = n + (m - 1) * ib;
	    if ((d__1 = x[nm + ib - 1] - x[nm - 1], abs(d__1)) <= azero) {
		goto L201;
	    }
	    slop[nm - 1] = (y[nm + ib - 1] - y[nm - 1]) / (x[nm + ib - 1] - x[
		    nm - 1]);
	    if ((d__1 = slop[nm - 1], abs(d__1)) <= azero) {
		slop[nm - 1] = 0.f;
	    }
	    goto L200;
L201:
	    slop[nm - 1] = 9999.f;
L200:
	    ;
	}
    }
    cslop = slop[0] * 1.001f;
    dslop = slop[0] * .999f;
    i__2 = j;
    for (n = 1; n <= i__2; ++n) {
	in1 = n;
	aslop = slop[in1 - 1] * 1.001f;
	bslop = slop[in1 - 1] * .999f;
	i__1 = ia;
	for (m = 1; m <= i__1; ++m) {
	    nm = n + (m - 1) * ib;
	    if (slop[nm - 1] <= aslop && slop[nm - 1] >= bslop) {
		goto L210;
	    }
	    goto L130;
L210:
	    ;
	}
	if (slop[in1 - 1] <= cslop && slop[in1 - 1] >= dslop) {
	    goto L220;
	}
	goto L130;
L220:
	;
    }
    *ilin = 1;
L300:
    return 0;
} /* linear_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


