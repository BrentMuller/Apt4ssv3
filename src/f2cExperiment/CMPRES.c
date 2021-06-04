/* CMPRES.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : CMPRES00.ORG   *** */


/*  * CMPRES *  FORTRAN 77 SUBROUTINE  9-DEC-1985  E.MCLELLAN */

/*  PURPOSE:  COMPRESS STRINGS OF BLANK CHARACTERS TO A SINGLE BLANK */

/*  CALLING SEQUENCE: */
/*                   CALL CMPRES(STRING,SLEN) */

/*  ARGUMENTS: */
/*                   TYPE       DESCRIPTION */
/*      STRING       CHARACTER  CHARACTER STRING TO BE COMPRESSED */
/*      SLEN         INTEGER    LENGTH OF ORIGINAL STRING ON INPUT */
/*                              AND COMPRESSED STRING ON OUTPUT */

/*  GLOBAL VARIABLES:  NONE */

/*  LOCAL VARIABLES:  NONE */

/*  FILES:  NONE */

/*  SUBSIDIARIES:  NONE */

/* Subroutine */ int cmpres_(char *string, integer *slen, ftnlen string_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];

    /* Builtin functions */
    integer i_len(char *, ftnlen), i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__;



    *slen = i_len(string, string_len);
    for (i__ = *slen; i__ >= 1; --i__) {
	if (*(unsigned char *)&string[i__ - 1] != ' ') {
	    *slen = i__;
	    goto L20;
	}
/* L10: */
    }

L20:
    i__ = i_indx(string, "  ", (*slen), (ftnlen)2);
    if (i__ != 0) {
	i__1 = i__;
/* Writing concatenation */
	i__2[0] = *slen - i__1, a__1[0] = string + i__1;
	i__2[1] = 1, a__1[1] = " ";
	s_cat(string + (i__ - 1), a__1, i__2, &c__2, string_len - (i__ - 1));
	--(*slen);
	goto L20;
    } else {
	return 0;
    }

    return 0;
} /* cmpres_ */

