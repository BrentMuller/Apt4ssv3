/* POLMTN.f -- translated by f2c (version 20100827).
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
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0012387.V01   *** */

/* Subroutine */ int polmtn_(integer *ns, doublereal *poed, integer *m, 
	integer *n)
{
    /* System generated locals */
    integer poed_dim2, poed_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;
    static doublereal u, v;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);


/*  TO COMPUTE A M*N POLYEDRON TO SEARCH FOR ROUGH INTERSECTION */


/* SS - ARELEM - COMMON */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

    /* Parameter adjustments */
    poed_dim2 = *m;
    poed_offset = 1 + 3 * (1 + poed_dim2);
    poed -= poed_offset;

    /* Function Body */
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	v = (doublereal) (j - 1);
	v /= 4.;
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    u = (doublereal) (i__ - 1);
	    u /= 4.;
	    cnsurf_(&u, &v, &ssarlm_1.bb[(*ns << 6) - 64], &poed[(i__ + j * 
		    poed_dim2) * 3 + 1], &ssarlm_1.iiflag[(*ns << 2) - 4], &
		    c__0);
/* L1: */
	}
    }

    return 0;
} /* polmtn_ */

