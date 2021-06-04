/* EVALSS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : EVALSS.ORG   *** */

/* Subroutine */ int evalss_(integer *npatch, doublereal *u, doublereal *v, 
	integer *isize, doublereal *geo, integer *mode, doublereal *r__, 
	doublereal *ru, doublereal *rv, doublereal *ruu, doublereal *ruv, 
	doublereal *rvv, doublereal *rnorm, integer *normok)
{
    /* Initialized data */

    static integer icpat = 0;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static doublereal b[64];
    static integer i__, mm;
    static doublereal spv[32];
    static integer itop[24], iflag[4];
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), cnsurf_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);


/* .... EVALUATE SURFACE */




    /* Parameter adjustments */
    --geo;
    --r__;
    --ru;
    --rv;
    --ruu;
    --ruv;
    --rvv;
    --rnorm;

    /* Function Body */

/* .... HAS PATCH ALREADY BEEN LOADED */

    if (*npatch != icpat) {

/* .... LOAD CURRENT PATCH DATA */

	lodpch_(&geo[1], b, iflag, itop, npatch, &c__1);

	icpat = *npatch;

    }

/* .... EVALUATE POINT AND DERIVATIVES */

    mm = 1;
    cnsurf_(u, v, b, spv, iflag, &mm);

    for (i__ = 1; i__ <= 3; ++i__) {
	r__[i__] = spv[i__ - 1];
	ru[i__] = spv[i__ + 3];
	rv[i__] = spv[i__ + 7];
	ruu[i__] = spv[i__ + 11];
	ruv[i__] = spv[i__ + 15];
	rvv[i__] = spv[i__ + 19];
	rnorm[i__] = spv[i__ + 27];
/* L10: */
    }

    *normok = i_dnnt(&spv[31]);

    return 0;
} /* evalss_ */

