/* PCHG.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001082.W01   *** */

/* Subroutine */ int pchg_(doublereal *pcur, doublereal *pdir, doublereal *
	pdel)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal half = .5;
    static doublereal smal = 1e-14;
    static doublereal smal1 = 1e-10;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a;
    static integer i__;
    static doublereal xx;
    extern /* Subroutine */ int bad_();
    static doublereal pin, pmax, phalf, ptarg;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

/* --PURPOSE IS TO MODIFY THE PARAMETRIC CHANGE PDEL SO AS */
/* --TO HIT OR APPROACH A JUNCTION POINT SMOOTHLY. */

    pin = *pdel;
    a = zero;
    xx = *pcur;
    i__ = (integer) xx;
    a = (doublereal) i__;
    if ((d__1 = a - *pcur, abs(d__1)) > smal) {
	goto L10;
    }
    *pdel = min(half,*pdel);
    goto L999;

L10:
    ptarg = zero;
    xx = *pdir + *pcur;
    i__ = (integer) xx;
    ptarg = (doublereal) i__;
    pmax = (d__1 = ptarg - *pcur, abs(d__1));
    *pdel = min(pmax,*pdel);
    phalf = half * pmax;
    if (*pdel < pmax && *pdel > phalf) {
	*pdel = phalf;
    }

L999:
    *pdel += smal1;
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER PCHG", (ftnlen)20, (ftnlen)11);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "PCUR", pcur, (ftnlen)4);
    bad_(&c__1, &c__1, "PDIR", pdir, (ftnlen)4);
    bad_(&c__1, &c__1, "PDEL", pdel, (ftnlen)4);
    bad_(&c_n1, &c__1, "PIN ", &pin, (ftnlen)4);
L1999:
    return 0;
} /* pchg_ */

