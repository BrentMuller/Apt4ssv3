/* SCDUMP.f -- translated by f2c (version 20100827).
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

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n4 = -4;

/* *** SOURCE FILE : M0000656.V04   *** */

/* Subroutine */ int scdump_(integer *in, doublereal *scan)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer l, ik;
    extern /* Subroutine */ int bad_();
    static integer ntot;

    /* Parameter adjustments */
    --scan;

    /* Function Body */
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c_n1, &c__0, "CHK=", in, (ftnlen)4);
    ntot = (integer) scan[12];
    if (ntot == 0) {
	ntot = (integer) ((scan[2] + scan[4]) * 24.f);
    }
    ik = -3;
    i__1 = ntot;
    for (l = 1; l <= i__1; l += 4) {
	if (l % 24 == 1) {
	    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	}
	ik += 4;
	bad_(&c__1, &c__0, "KCT ", &ik, (ftnlen)4);
	bad_(&c_n4, &c__1, "SCAN", &scan[l], (ftnlen)4);
/* L10: */
    }
    return 0;
} /* scdump_ */

