/* SRFDIR.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n2 = -2;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001097.W01   *** */

/* Subroutine */ int srfdir_(doublereal *dr, doublereal *r__, doublereal *
	side, doublereal *pdir, doublereal *sx, doublereal *svec, doublereal *
	sk, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal smal = 1e-38;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int bad_();
    static doublereal fac;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal xcos, xsin;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen), kursrf_(doublereal *,
	     doublereal *, doublereal *);

/* ---PURPOSE IS TO COMPUTE SURFACE CURVATURE SK AND DIRECTION SVEC */
/* --IN DIRECTION OF MOVEMENT INDICATED BY DRIVE GEOMETRY ARRAY */
/* --DR. */
    /* Parameter adjustments */
    --svec;
    --sx;
    --r__;
    --dr;

    /* Function Body */

    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	svec[i__] = zero;
    }
    *sk = zero;

    kursrf_(&r__[1], side, &sx[1]);
/* --PROJECT DRIVE TANGENT VECTOR INTO SURFACE TANGENT PLANE */
    dotf_(&fac, &r__[29], &dr[13]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	svec[i__] = dr[i__ + 12] - fac * r__[i__ + 28];
    }
    dotf_(&fac, &svec[1], &svec[1]);
    if (fac < smal) {
	goto L999;
    }
    fac = sqrt(fac) * *pdir;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	svec[i__] = fac * svec[i__];
    }
/* --NOW COMPUTE THE CURVATURE OF THE SURFACE IN THE SVEC DIRECTION */
    dotf_(&xcos, &svec[1], &sx[5]);
    dotf_(&xsin, &svec[1], &sx[9]);
/* Computing 2nd power */
    d__1 = xcos;
/* Computing 2nd power */
    d__2 = xsin;
    *sk = sx[1] * (d__1 * d__1) + sx[2] * (d__2 * d__2);

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER SRFDIR", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__0, "IRR ", irr, (ftnlen)4);
    bad_(&c__1, &c__1, "SK  ", sk, (ftnlen)4);
    bad_(&c_n2, &c__1, "SX  ", &sx[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "SVEC", &svec[1], (ftnlen)4);
L1999:
    return 0;
} /* srfdir_ */

