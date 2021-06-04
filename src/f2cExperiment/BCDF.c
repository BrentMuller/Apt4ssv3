/* BCDF.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : BCDF0000.W01   *** */


/*  * BCDF *  FORTRAN 77 INTEGER FUNCTION  19-DEC-1985  E.MCLELLAN */
/*            MODIFIED                      2-FEB-1988  E.MCLELLAN */

/*  PURPOSE:  CONVERT A STRING OF CHARACTERS WHICH OCCUPY THE SAME */
/*            NUMBER OF BYTES AS AN INTEGER WORD INTO AN EQUIVALENT */
/*            INTEGER VALUE */

/*  CALLING SEQUENCE: */
/*                   VALUE=BCDF(STR) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*       STR         CHARACTER  STRING TO BE CONVERTED */

/*  GLOBAL VARIABLES: */

/* --------------------------------------------------- */
/*   VARIABLE        BLOCK     TYPE       DESCRIPTION */
/* --------------------------------------------------- */
/*   IWRD            SDP       INTEGER    NO. OF BYTES PER WORD */
/*   NBCHAR          SDP       INTEGER    NO. OF BITS PER BYTE */

/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*        I          INTEGER    LOOP COUNT */
/*        BCD        INTEGER    VARIABLE FOR BUILDING UP BCD VALUE */
/*        TSTR       CHARACTER  TEMPORARY STORAGE FOR STRING */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */

integer bcdf_(char *str, ftnlen str_len)
{
    /* System generated locals */
    address a__1[2];
    integer ret_val, i__1[2], i__2;

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, bcd;
    static char tstr[10];





    bcd = 0;
/* Writing concatenation */
    i__1[0] = str_len, a__1[0] = str;
    i__1[1] = 1, a__1[1] = " ";
    s_cat(tstr, a__1, i__1, &c__2, (ftnlen)10);
    i__2 = sdp_1.iwrd;
    for (i__ = 1; i__ <= i__2; ++i__) {
	bcd = lbit_shift(bcd, sdp_1.nbchar) + *(unsigned char *)&tstr[i__ - 1]
		;
/* L10: */
    }

    ret_val = bcd;

    return ret_val;
} /* bcdf_ */

