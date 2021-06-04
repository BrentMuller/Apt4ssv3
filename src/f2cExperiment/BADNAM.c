/* BADNAM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : BADNAM00.V01   *** */


/*  * BADNAM *    FORTRAN 77 SUBROUTINE   15-JUL-1986  E.MCLELLAN */

/*   PURPOSE:  TO RETURN THE BCD EQUIVALENT OF 'BADNAM  ' */

/*   CALLING SEQUENCE: */
/*                    CALL BADNAM(IWORD) */

/*   ARGUMENTS: */
/*         IWORD  INTEGER  ARRAY INTO WHICH 'BADNAM  ' IS TO BE LOADED */

/*   GLOBAL VARIABLES: NONE */

/*   LOCAL VARIABLES: */
/*                   TYPE        DESCRIPTION */
/*         IBDNAM    INTEGER     INTEGER ARRAY TO BUILD UP BCDF */
/*         FIRST     LOGICAL     FLAG INDICATING FIRST CALL */

/*   SUBSIDIARIES:  BCDF */

/* Subroutine */ int badnam_(integer *iword)
{
    /* Initialized data */

    static logical first = TRUE_;

    extern integer bcdf_(char *, ftnlen);
    static integer ibdnam[2];



    /* Parameter adjustments */
    --iword;

    /* Function Body */
    if (first) {
	ibdnam[0] = bcdf_("BADN", (ftnlen)4);
	ibdnam[1] = bcdf_("AM  ", (ftnlen)4);
	first = FALSE_;
    }

    iword[1] = ibdnam[0];
    iword[2] = ibdnam[1];
    return 0;
} /* badnam_ */

