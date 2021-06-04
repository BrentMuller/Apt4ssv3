/* HOLFRM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : HOLFRM00.W01   *** */


/*  * HOLFRM *  FORTRAN 77 SUBROUTINE  16.7.86  E.MCLELLAN */
/*                MODIFIED                 2-FEB-1988  E.MCLELLAN */

/*  PURPOSE:  TO INSERT SPECIFIED NUMBER OF CHARACTERS IN BCDF FORM */
/*            FROM INTEGER ARRAY INTO CHARACTER VARIABLE */
/*            STARTING FROM SPECIFIED LOCATION - RETURNING THE NUMBER */
/*            OF INTEGER WORDS OCCUPIED */

/*  CALLING SEQUENCE: */
/*                   CALL HOLFRM(IARR,STR,IST,NCHR,NWD) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*       IARR        INTEGER    ARRAY CONTAINING BCDF CHARACTERS */
/*       STR         CHARACTER  STRING INTO WHICH CHARACTERS ARE */
/*                              TO BE LOADED */
/*       IST         INTEGER    START LOCATION IN STR */
/*       NCHR        INTEGER    NUMBER OF CHARACTERS TO BE INSERTED */
/*       NWD         INTEGER    NUMBER OF WORDS OCCUPIED */

/*  GLOBAL VARIABLES: */

/* --------------------------------------------------- */
/*   VARIABLE        BLOCK     TYPE       DESCRIPTION */
/* --------------------------------------------------- */
/*     IWRD          SDP       INTEGER    NO OF BYTES PER WORD */
/*     NBCHAR        SDP       INTEGER    NO OF BITS PER BYTE */

/*  LOCAL VARIABLES: */
/*                   TYPE       DESCRIPTION */
/*     IVAL          INTEGER    VALUE OF INTEGER WORD */
/*     JVAL          INTEGER    INDEX OF CHARACTER IN CONCATINATION */
/*                              SEQUENCE */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */

/* Subroutine */ int holfrm_(integer *iarr, char *str, integer *ist, integer *
	nchr, integer *nwd, ftnlen str_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), lbit_shift(integer, integer);

    /* Local variables */
    static integer i__, j, k, k1, jj, ival, jval, slen;


/* .... SYSTEM DEPENDENT PARAMETERS */





    /* Parameter adjustments */
    --iarr;

    /* Function Body */
    slen = i_len(str, str_len);
    *nwd = *nchr / sdp_1.iwrd;
    if (*nchr > *nwd * sdp_1.iwrd) {
	++(*nwd);
    }
    i__1 = *nwd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ival = iarr[i__];
	k1 = *ist + i__ * sdp_1.iwrd;
	for (j = sdp_1.iwrd; j >= 1; --j) {
	    k = k1 - j;
	    jj = sdp_1.nbchar * (j - 1);
	    jval = lbit_shift(ival, -jj);
	    if (k <= slen) {
		*(unsigned char *)&str[k - 1] = (char) jval;
	    }
	    ival -= lbit_shift(jval, jj);
/* L10: */
	}
/* L20: */
    }

    return 0;
} /* holfrm_ */

