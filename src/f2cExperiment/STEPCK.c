/* STEPCK.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001113.W01   *** */

/* Subroutine */ int stepck_(doublereal *side, doublereal *r__, doublereal *
	rx, doublereal *rk, doublereal *rl, doublereal *rxl, doublereal *rkl, 
	doublereal *efrad, doublereal *tol, doublereal *srmin, doublereal *
	tlmin)
{
    /* Initialized data */

    static doublereal smal = 1e-38;
    static doublereal big = 1e10;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal w;
    extern /* Subroutine */ int bad_();
    static doublereal rsq, rdif[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal smin, tmin;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen), srftol_(doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *);

    /* Parameter adjustments */
    --rxl;
    --rl;
    --rx;
    --r__;

    /* Function Body */
/* --PURPOSE IS TO COMPUTE MINIMUM SURFACE (SRMIN) AND TOOL STEPS */
/* --(TLMIN) BASED ON CURRENT AND LAST CONTACT POINTS */

    *srmin = big;
    *tlmin = big;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	rdif[i__ - 1] = r__[i__] - rl[i__];
    }
    dotf_(&rsq, rdif, rdif);

    srftol_(rk, efrad, tol, &smin, &tmin);
    *srmin = min(*srmin,smin);
    *tlmin = min(*tlmin,tmin);

    srftol_(rkl, efrad, tol, &smin, &tmin);
    *srmin = min(*srmin,smin);
    *tlmin = min(*tlmin,tmin);

    if (rsq < smal) {
	goto L999;
    }
    dotf_(&w, &r__[29], rdif);
    w = w * -2.f * *side / rsq;
    srftol_(&w, efrad, tol, &smin, &tmin);
    *srmin = min(*srmin,smin);
    *tlmin = min(*tlmin,tmin);

    dotf_(&w, &rl[29], rdif);
    w = w * 2.f * *side / rsq;
    srftol_(&w, efrad, tol, &smin, &tmin);
    *srmin = min(*srmin,smin);
    *tlmin = min(*tlmin,tmin);

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER STEPCK", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "SIDE", side, (ftnlen)4);
    bad_(&c__1, &c__1, "RK  ", rk, (ftnlen)4);
    bad_(&c__1, &c__1, "RKL ", rkl, (ftnlen)4);
    bad_(&c__1, &c__1, "ERAD", efrad, (ftnlen)4);
    bad_(&c_n1, &c__1, "TOL ", tol, (ftnlen)4);
    bad_(&c__1, &c__1, "SRMN", srmin, (ftnlen)4);
    bad_(&c_n1, &c__1, "TLMN", tlmin, (ftnlen)4);
L1999:
    return 0;
} /* stepck_ */

