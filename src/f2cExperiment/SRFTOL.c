/* SRFTOL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001098.W02   *** */

/* Subroutine */ int srftol_(doublereal *skrv, doublereal *trad, doublereal *
	tol, doublereal *sstep, doublereal *tstep)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal smal = 1e-9;
    static doublereal big = 1e9;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal w;
    extern /* Subroutine */ int bad_();
    static doublereal chaf, shaf, srad;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

/* --PURPOSE IS TO COMPUTE SURFACE STEP DISTANCE SSTEP AND */
/* --TOOL STEP DISTANCE TSTEP ALONG SURFACE BASED ON CURVATURE */
/* --SKRV AND TOOL RADIUS TRAD AND TOLERANCE BAND TOL */


    *sstep = big;
    *tstep = *sstep;
    if (abs(*skrv) < smal) {
	goto L999;
    }
    srad = 1 / *skrv;
    w = (d__1 = srad - *trad, abs(d__1));
    if (w < smal) {
	goto L999;
    }
/* --COSINE OF HALF ANGLE OF MOVEMENT */
    chaf = one - *tol / w;
/* Computing 2nd power */
    d__1 = chaf;
    shaf = one - d__1 * d__1;
    shaf = max(smal,shaf);
    shaf = sqrt(shaf);
    *sstep = abs(srad) * 2.f * shaf;
    *tstep = w * 2.f * shaf;

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER SRFTOL", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "SKRV", skrv, (ftnlen)4);
    bad_(&c__1, &c__1, "TRAD", trad, (ftnlen)4);
    bad_(&c__1, &c__1, "TOL ", tol, (ftnlen)4);
    bad_(&c__1, &c__1, "SSTP", sstep, (ftnlen)4);
    bad_(&c_n1, &c__1, "TSTP", tstep, (ftnlen)4);
L1999:
    return 0;
} /* srftol_ */

