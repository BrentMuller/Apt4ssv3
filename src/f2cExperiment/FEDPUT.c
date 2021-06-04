/* FEDPUT.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0001068.V05   *** */

/* Subroutine */ int fedput_(doublereal *feed)
{
    /* System generated locals */
    static doublereal equiv_0[1];

    /* Local variables */
    extern /* Subroutine */ int bad_();
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, doublereal *, integer *, 
	    doublereal *);
#define itemp ((integer *)equiv_0)
#define fedrat (equiv_0)



    itemp[0] = bcdf_("FEDR", (ftnlen)4);
    itemp[1] = bcdf_("AT  ", (ftnlen)4);
    apt299_(&c__1, fedrat, &c__1, feed);
    if (ibugg_1.ibug != 11) {
	goto L999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c_n1, &c__1, "FEED", feed, (ftnlen)4);
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
L999:
    return 0;
} /* fedput_ */

#undef fedrat
#undef itemp


