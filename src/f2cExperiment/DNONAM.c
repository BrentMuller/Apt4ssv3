/* DNONAM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : DNONAM00.V01   *** */


/*  * DNONAM *    FORTRAN 77 SUBROUTINE   15-JUL-1986  E.MCLELLAN */

/*   PURPOSE:  TO RETURN THE BCD EQUIVALENT OF 'DNONAM  ' */
/*             IN THE FIRST 8 BYTES OF THE ARGUMENT */
/*             (NOTE: THIS SHOULD GIVE A NONE VALID D.P. NUMBER */
/*                    ON MOST SYSTEMS) */

/*   CALLING SEQUENCE: */
/*                    CALL DNONAM(IWORD) */

/*   ARGUMENTS: */
/*         IWORD  INTEGER  ARRAY INTO WHICH 'DNONAM  ' IS TO BE LOADED */

/*   GLOBAL VARIABLES: */

/* ---------------------------------------------------- */
/*   VARIABLE    BLOCK    TYPE        DESCRIPTION */
/* ---------------------------------------------------- */
/*   IFAC        SDP      INTEGER     BYTE LEFT SHIFT */
/*                                    MULTIPLICATION FACTOR */

/*   LOCAL VARIABLES: */
/*                   TYPE        DESCRIPTION */
/*         IBDNAM    INTEGER     INTEGER ARRAY TO BUILD UP BCDF */
/*         FIRST     LOGICAL     FLAG INDICATING FIRST CALL */

/*   SUBSIDIARIES:  NONE */

/* Subroutine */ int dnonam_(integer *iword)
{
    /* Initialized data */

    static logical first = TRUE_;

    extern integer bcdf_(char *, ftnlen);
    static integer idnonm[2];


    /* Parameter adjustments */
    --iword;

    /* Function Body */
    if (first) {
	idnonm[0] = bcdf_("DNON", (ftnlen)4);
	idnonm[1] = bcdf_("AM  ", (ftnlen)4);
	first = FALSE_;
    }

    iword[1] = idnonm[0];
    iword[2] = idnonm[1];
    return 0;
} /* dnonam_ */

