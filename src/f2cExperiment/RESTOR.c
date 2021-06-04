/* RESTOR.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : RESTOR.ORG   *** */

/* Subroutine */ int restor_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;


/*     PURPOSE: TO RESTORE INTERFERENCE TABLE FOR USE AS START VALUES */
/*              FOR NEXT INTEFERENCE CHECK AFTER AVOIDING INTERFERENCE */




/*    INTERFERENCE TABLE */





    i__1 = interf_1.lnpint;
    for (i__ = 1; i__ <= i__1; ++i__) {

	interf_1.dintr[i__ - 1] = interf_1.ldintr[i__ - 1];
	interf_1.pintr[i__ - 1] = interf_1.lpintr[i__ - 1];
	interf_1.uintr[i__ - 1] = interf_1.luintr[i__ - 1];
	interf_1.vintr[i__ - 1] = interf_1.lvintr[i__ - 1];

/* L200: */
    }

    interf_1.npintr = interf_1.lnpint;

    return 0;
} /* restor_ */

