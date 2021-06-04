/* BINBCD.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__2 = 2;

/* *** SOURCE FILE : M0000502.W01   *** */


/* *  BINBCD  *  FORTRAN 77 SUBROUTINE   E.MCLELLAN  06.85 */

/* Subroutine */ int binbcd_(integer *jntger, char *symbol, integer *count, 
	ftnlen symbol_len)
{
    /* Initialized data */

    static char blank[1] = " ";

    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static char bcd[8];
    static integer intger;

    /* Fortran I/O blocks */
    static icilist io___5 = { 0, bcd, 0, "(I8)", 8, 1 };



    intger = *jntger;
    *count = 0;
    s_copy(bcd, blank, (ftnlen)8, (ftnlen)1);
    if (intger < 0) {
	s_copy(symbol, bcd, symbol_len, (ftnlen)8);
    } else {
	s_wsfi(&io___5);
	do_fio(&c__1, (char *)&intger, (ftnlen)sizeof(integer));
	e_wsfi();
	for (i__ = 1; i__ <= 8; ++i__) {
	    if (*(unsigned char *)&bcd[i__ - 1] != *(unsigned char *)&blank[0]
		    ) {
		j = i__;
		goto L20;
	    }
/* L10: */
	}

L20:
	*count = 9 - j;
/* Writing concatenation */
	i__1[0] = 8 - (j - 1), a__1[0] = bcd + (j - 1);
	i__1[1] = 1, a__1[1] = blank;
	s_cat(symbol, a__1, i__1, &c__2, symbol_len);
    }
    return 0;
} /* binbcd_ */

