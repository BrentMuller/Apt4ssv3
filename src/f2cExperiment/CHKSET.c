/* CHKSET.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001050.W01   *** */

/* Subroutine */ int chkset_(integer *idtype, doublereal *pdir, doublereal *
	par, integer *ifin)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal smal = 1e-14;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int bad_();
    static doublereal plim[4];
    static integer ityp, index;
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen);

    /* Parameter adjustments */
    --par;

    /* Function Body */
/* ---PURPOSE IS TO CHECK WHETHER PARAMETER PAIR PAR(1-2) IS */
/* --- WITHIN LEGITIMATE BOUNDS.  THESE BOUNDS ARE SET WHEN */
/* --- IFIN=-121 ON INPUT.  OTHERWISE IFIN NON ZERO ON OUTPUT */
/* --- MEANS THAT P IS OUT OF BOUNDS.  P WILL ALSO BE TRUNCATED */
/* --- TO LIE WITHIN BOUNDS. */

    if (*ifin != -121) {
	goto L15;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L10: */
	plim[i__ - 1] = par[i__];
    }
    goto L999;

L15:
    *ifin = 0;
    ityp = 2;
    if (*idtype < 2) {
	ityp = 1;
    }
    i__ = ityp;
    index = (i__ << 1) - 1;
    if (par[i__] > plim[index - 1] + smal) {
	goto L20;
    }
    par[i__] = plim[index - 1];
    if (*pdir > zero) {
	goto L20;
    }
    *ifin = 1;
L20:
    index = i__ << 1;
    if (par[i__] < plim[index - 1] - smal) {
	goto L40;
    }
    par[i__] = plim[index - 1];
    if (*pdir < zero) {
	goto L40;
    }
    *ifin = 1;
L40:

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER CHKSET", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "PDIR", pdir, (ftnlen)4);
    bad_(&c__1, &c__0, "IFIN", ifin, (ftnlen)4);
    bad_(&c_n2, &c__1, "PAR ", &par[1], (ftnlen)4);
L1999:
    return 0;
} /* chkset_ */

