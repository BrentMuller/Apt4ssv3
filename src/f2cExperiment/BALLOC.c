/* BALLOC.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001040.V02   *** */

/* Subroutine */ int balloc_(doublereal *b, integer *iflag, integer *itop, 
	doublereal *side, doublereal *tc, doublereal *rad, doublereal *td, 
	doublereal *u, doublereal *v, doublereal *dist, integer *maxrep, 
	integer *ifree, integer *irr)
{
    /* Initialized data */

    static doublereal fac = .999;
    static doublereal big = 1e22;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static doublereal r__[32], u1, v1, da, du, dv, du1, dv1;
    static integer iok, isqr;
    extern /* Subroutine */ int sqrbn_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *), balone_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), chktop_(doublereal *, doublereal *, 
	    integer *, integer *), cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);

    /* Parameter adjustments */
    --td;
    --tc;
    itop -= 7;
    --iflag;
    --b;

    /* Function Body */

/*           /-PURPOSE IS TO FIND QUICK ESTIMATE OF LINEUP FROM */
/*           /-BALL TOOL TO SURFACE. */

    u1 = *u;
    v1 = *v;
    *dist = big;
    if (*ifree == 0) {
	goto L10;
    }
/*            /-IF IFREE=1, INITIAL U,V SHOULD BE IN A VALID SECTOR */
/*            /-U,V SHOULD ALSO REMAIN IN A VALID SECTOR */
    *irr = 1;
    chktop_(&u1, &v1, &itop[7], &iok);
    if (iok != 0) {
	goto L999;
    }

L10:
/*           /-LOOP WITH LINEAR ESTIMATES FOR GOOD APPROXIMATION */
    i__1 = *maxrep;
    for (i__ = 1; i__ <= i__1; ++i__) {
	cnsurf_(&u1, &v1, &b[1], r__, &iflag[1], &c__1);
	balone_(r__, side, &tc[1], rad, &td[1], &du, &dv, &da, irr);
	if (*irr == 0) {
	    goto L30;
	}
/*           /-ON FAILURE ACCEPT THE LAST GOOD U,V */
	if (i__ > 1) {
	    goto L100;
	}
	*irr = 2;
	goto L999;

L30:
	if (*ifree == 0) {
	    goto L40;
	}
/*           /-TRUNCATE U,V IF THEY LEAD TO A NEW SECTOR */
	sqrbn_(&u1, &v1, &du, &dv, &du1, &dv1, &fac, &isqr);
	if (isqr > 0) {
	    du = du1;
	}
	if (isqr > 0) {
	    dv = dv1;
	}
L40:
	u1 += du;
	v1 += dv;
	*dist = da;
/* L20: */
    }

L100:
    *irr = 0;
    *u = u1;
    *v = v1;
L999:
    return 0;
} /* balloc_ */

