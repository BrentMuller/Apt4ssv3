/* AFORM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : AFORM000.ORG   *** */


/*  * AFORM *  FORTRAN 77 SUBROUTINE  9/9/86  M.D.LIPSCOMBE */

/*  PURPOSE:  TO FORM INDISCRIMINATE VALUES INTO ONE ARRAY */

/*  CALLING SEQUENCE: */
/*                   CALL AFORM(ARR,VALS,L) */


/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */

/*  ARR      DOUBLE PRECISION   ARRAY TO CONTAIN GATHERED INDISCRIMINATE */
/*  VALS     DOUBLE PRECISION   INDISCRIMINATE VALUES (POSSIBLY PACKED) */
/*  L        INTEGER            NUMBER OF CONTIGUOUS 8-BYTE WORDS HOLDING */


/*  GLOBAL VARIABLES:  NONE */

/*  LOCAL VARIABLES:  NONE */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */


/* Subroutine */ int aform_(doublereal *arr, doublereal *vals, integer *l)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;



    /* Parameter adjustments */
    --arr;
    --vals;

    /* Function Body */
    i__1 = *l;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arr[i__] = vals[i__];
/* L20: */
    }

    return 0;
} /* aform_ */

