/* MINMAX.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* *** SOURCE FILE : MINF0000.ORG   *** */

/* Subroutine */ int minf_(integer *ptable)
{
    /* Initialized data */

    static integer term = -999;

    /* Local variables */
    static integer i__;
#define can ((doublereal *)&_BLNK__1 + 40)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal result;


/*  * MINF *   VAX11 FORTRAN VERSION  29.8.86  E.MCLELLAN */

/*  PURPOSE    TO FIND THE MINIMUM VALUE OF ITEMS IN UNLABELLED */
/*             COMMON REFERENCED BY THE PARAMETER LIST */
/*  CALLING SEQUENCE */
/*             CALL MINF(PTABLE) */
/*  ARGUMENTS */
/*             PTABLE    PARAMETER LIST */

/*      UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --ptable;

    /* Function Body */


    result = _BLNK__1.com[(0 + (0 + (ptable[3] - 1 << 3))) / 8];
    i__ = 4;
L10:
    if (_BLNK__1.com[ptable[i__] - 1] < result) {
	result = _BLNK__1.com[ptable[i__] - 1];
    }
    ++i__;
    if (ptable[i__] != term) {
	goto L10;
    }
    _BLNK__1.com[ptable[2] - 1] = result;
    return 0;
} /* minf_ */

#undef bcanon
#undef sscan
#undef canon
#undef can





/* Subroutine */ int maxf_(integer *ptable)
{
    /* Initialized data */

    static integer term = -999;

    /* Local variables */
    static integer i__;
#define can ((doublereal *)&_BLNK__1 + 40)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal result;


/*  * MAXF *   VAX11 FORTRAN VERSION  29.8.86  E.MCLELLAN */

/*  PURPOSE    TO FIND THE MAXIMUM VALUE OF ITEMS IN UNLABELLED */
/*             COMMON REFERENCED BY THE PARAMETER LIST */
/*  CALLING SEQUENCE */
/*             CALL MAXF(PTABLE) */
/*  ARGUMENTS */
/*             PTABLE    PARAMETER LIST */

/*      UNLABELED COMMON */



/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --ptable;

    /* Function Body */


    result = _BLNK__1.com[(0 + (0 + (ptable[3] - 1 << 3))) / 8];
    i__ = 4;
L20:
    if (_BLNK__1.com[ptable[i__] - 1] > result) {
	result = _BLNK__1.com[ptable[i__] - 1];
    }
    ++i__;
    if (ptable[i__] != term) {
	goto L20;
    }
    _BLNK__1.com[ptable[2] - 1] = result;
    return 0;
} /* maxf_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


