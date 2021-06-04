/* TRASH.f -- translated by f2c (version 20100827).
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
    integer nbchar, nbwrd, iwrd, ifac;
} sdp_;

#define sdp_1 sdp_

/* *** SOURCE FILE : TRASH000.V01   *** */


/*  * TRASH *    FORTRAN 77 SUBROUTINE   15-JUL-1986  E.MCLELLAN */
/*                MODIFIED                 3-FEB-1988  E.MCLELLAN */

/*   PURPOSE:  TO RETURN THE BCD EQUIVALENT OF '$',NULL,'TRASH',NULL */
/*             IN THE FIRST 8 BYTES OF THE ARGUMENT */
/*             (NOTE: THIS SHOULD GIVE A NONE VALID D.P. NUMBER */
/*                    ON MOST SYSTEMS) */

/*   CALLING SEQUENCE: */
/*                    CALL TRASH(IWORD) */

/*   ARGUMENTS: */
/*         IWORD  INTEGER  ARRAY INTO WHICH '$ TRASH ' IS TO BE LOADED */

/*   GLOBAL VARIABLES: */

/* ---------------------------------------------------- */
/*   VARIABLE    BLOCK    TYPE        DESCRIPTION */
/* ---------------------------------------------------- */
/*   NBCHAR      SDP      INTEGER     NO OF BITS PER BYTE */

/*   LOCAL VARIABLES: */
/*                   TYPE        DESCRIPTION */
/*         ITRASH    INTEGER     INTEGER ARRAY TO BUILD UP BCDF */
/*         FIRST     LOGICAL     FLAG INDICATING FIRST CALL */

/*   SUBSIDIARIES:  NONE */

/* Subroutine */ int trash_(integer *iword)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* Builtin functions */
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i2, i3, itrash[2];




    /* Parameter adjustments */
    --iword;

    /* Function Body */
    if (first) {
	i3 = sdp_1.nbchar * 3;
	i2 = sdp_1.nbchar << 1;
	itrash[0] = lbit_shift('$', i3) + lbit_shift('T', sdp_1.nbchar) + 'R';
	itrash[1] = lbit_shift('A', i3) + lbit_shift('S', i2) + lbit_shift(
		'H', sdp_1.nbchar);
	first = FALSE_;
    }

    iword[1] = itrash[0];
    iword[2] = itrash[1];
    return 0;
} /* trash_ */

