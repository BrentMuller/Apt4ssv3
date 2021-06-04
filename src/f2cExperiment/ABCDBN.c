/* ABCDBN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ABCDBN00.ORG   *** */


/*  * ABCDBN *    FORTRAN 77 VERSION  11-JUL-1986  E.MCLELLAN */

/*   PURPOSE      TO CONVERT FLOATING POINT NUMBERS */
/*                FROM LEFT JUSTIFIED CHARACTER FORM */
/*                TO DOUBLE PRECISION VALUES */

/*   CALLING SEQUENCE */
/*                CALL ABCDBN(STR,VALUE,NUM) */

/*   ARGUMENTS */
/*       STR     CHARACTER   STRING ARRAY CONTAINING NUMBERS */
/*                           LEFT JUSTIFIEDIN 12 BYTES, */
/*                           TO BE CONVERTED TO FLOATING POINT */
/*       VALUE   DOUBLE      ARRAY TO CONTAIN CONVERTED NUMBERS */
/*               PRECISION */
/*       NUM     INTEGER     NUMBER OF ITEMS IN ARRAY */

/* Subroutine */ int abcdbn_(char *str, doublereal *value, integer *num, 
	ftnlen str_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), do_fio(
	    integer *, char *, ftnlen), e_rsfi(void);

    /* Local variables */
    static integer i__, j, k;
    static char tstr[12];

    /* Fortran I/O blocks */
    static icilist io___5 = { 0, tstr, 0, "(F12.0)", 12, 1 };




    /* Parameter adjustments */
    --value;
    str -= 12;

    /* Function Body */
    i__1 = *num;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(tstr, str + i__ * 12, (ftnlen)12, (ftnlen)12);
	k = i_indx(tstr, ".", (ftnlen)12, (ftnlen)1);
	if (k == 0) {
	    j = i_indx(tstr, " ", (ftnlen)12, (ftnlen)1);
	    if (j != 0) {
		*(unsigned char *)&tstr[j - 1] = '.';
	    }
	}
	s_rsfi(&io___5);
	do_fio(&c__1, (char *)&value[i__], (ftnlen)sizeof(doublereal));
	e_rsfi();
/* L10: */
    }
    return 0;
} /* abcdbn_ */

