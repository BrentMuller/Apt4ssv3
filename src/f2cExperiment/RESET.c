/* RESET.f -- translated by f2c (version 20100827).
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
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

/* *** SOURCE FILE : RESET.ORG   *** */

/* Subroutine */ int reset_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;


/*     PURPOSE: TO RESET INTERFERENCE TABLE FOR NEXT POINT */




/*    INTERFERENCE TABLE */





    i__1 = interf_1.npintr;
    for (i__ = 1; i__ <= i__1; ++i__) {

	interf_1.ldintr[i__ - 1] = interf_1.dintr[i__ - 1];
	interf_1.lpintr[i__ - 1] = interf_1.pintr[i__ - 1];
	interf_1.luintr[i__ - 1] = interf_1.uintr[i__ - 1];
	interf_1.lvintr[i__ - 1] = interf_1.vintr[i__ - 1];

	interf_1.dintr[i__ - 1] = 0.;
	interf_1.pintr[i__ - 1] = 0;
	interf_1.uintr[i__ - 1] = 0.;
	interf_1.vintr[i__ - 1] = 0.;

	interf_1.iseg[i__ - 1] = 0;
	for (j = 1; j <= 3; ++j) {
	    interf_1.tpintr[j + i__ * 3 - 4] = 0.;
	    interf_1.spintr[j + i__ * 3 - 4] = 0.;
	    interf_1.snintr[j + i__ * 3 - 4] = 0.;
/* L100: */
	}

/* L200: */
    }

    interf_1.lnpint = interf_1.npintr;
    interf_1.npintr = 0;

    return 0;
} /* reset_ */

