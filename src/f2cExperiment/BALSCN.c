/* BALSCN.f -- translated by f2c (version 20100827).
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

static integer c__3 = 3;

/* *** SOURCE FILE : M0001042.V02   *** */

/* Subroutine */ int balscn_(doublereal *surf, doublereal *side, doublereal *
	tc, doublereal *rad, doublereal *td, doublereal *u, doublereal *v, 
	doublereal *dist, integer *npat, integer *irr)
{
    /* Initialized data */

    static doublereal half = .5;
    static doublereal big = 1e22;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal b[64];
    static integer i__;
    static doublereal u1, v1, da;
    static integer ir, iok, itop[24]	/* was [6][4] */, iflag[6], ifree;
    extern /* Subroutine */ int balloc_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *), lodpch_(doublereal *, doublereal *, integer *, 
	    integer *, integer *, integer *), chktop_(doublereal *, 
	    doublereal *, integer *, integer *);
    static integer maxrep, numpat;

/*           /-PURPOSE IS TO SCAN ALL PATCHES IN SURFACE AND SELECT */
/*           /-BEST CANDIDATE FOR LINEUP WITH TOOL */
/*           /-INPUT */
/*           /-SURF- INPUT SCULPTURED SURFACE LARGE DATA ARRAY */
/*           /-OUTPUT */
/*           /-NPAT PATCH NUMBER OF BEST CANDIDATE */
/*           /-PATCH U,V COORDINATES AT ESTIMATED CONTACT POINT */
/*           /-DIST ESTIMATED DISPLACEMENT FROM CURRENT CUTTER POSN TO SU */

    /* Parameter adjustments */
    --td;
    --tc;
    --surf;

    /* Function Body */

    *u = half;
    *v = half;
    *npat = 1;
    *dist = big;
    ir = 1;
    numpat = (integer) surf[4];

    i__1 = numpat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*           /-LOAD THE ITH PATCH */
	lodpch_(&surf[1], b, iflag, itop, &i__, &c__3);
	maxrep = 5;
	ifree = 0;
	u1 = half;
	v1 = half;
	*irr = 0;
	balloc_(b, iflag, itop, side, &tc[1], rad, &td[1], &u1, &v1, &da, &
		maxrep, &ifree, irr);
	if (*irr != 0) {
	    goto L20;
	}
	chktop_(&u1, &v1, itop, &iok);
	if (iok == 0) {
	    goto L30;
	}
L20:
	if (abs(*dist) < big) {
	    goto L10;
	}
	u1 = half;
	v1 = half;
	maxrep = 1;
	ifree = 1;
	*irr = 0;
	balloc_(b, iflag, itop, side, &tc[1], rad, &td[1], &u1, &v1, &da, &
		maxrep, &ifree, irr);
	if (*irr != 0) {
	    goto L10;
	}
L30:
	if (abs(*dist) < abs(da)) {
	    goto L10;
	}
/*           /-UPDATE BEST PATCH BASED ON SMALLEST DISTANCE */
	*dist = da;
	*u = u1;
	*v = v1;
	*npat = i__;
	ir = 0;
/*           /-UPDATE ERROR FLAG TO INDICATE SUCCESS */
L10:
	;
    }

    *irr = ir;
    return 0;
} /* balscn_ */

