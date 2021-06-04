/* SHIFT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : SHIFT000.ORG   *** */

/* Subroutine */ int shift_(char *word, char *jchar, ftnlen word_len, ftnlen 
	jchar_len)
{
    /* System generated locals */
    address a__1[2];
    integer i__1[2];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j;
    static char temp[6];


/*  *  SHIFT  *  VAX11 VERSION   4.10.85    E.MCLELLAN */

/*  PURPOSE     TO APPEND A SINGLE CHARACTER 'JCHAR' TO THE CHARACTER */
/*              STRING BEING SET UP IN 'WORD' TO FORM A LEFT-JUSTIFIED */
/*              'NAME' IN 'WORD' */

/*  CALLING SEQUENCE */
/*              CALL SHIFT(WORD,JCHAR) */
/*  ARGUMENTS   WORD   CHARACTER STRING IN WHICH A 'NAME' */
/*                     IS BEING BUILT UP */
/*              JCHAR  CONTAINS THE NEXT CHARACTER (LEFT JUSTIFIED) */
/*                     TO BE PLACED IN WORD */


    j = i_indx(word, " ", (ftnlen)6, (ftnlen)1);
    if (j != 0) {
	*(unsigned char *)&word[j - 1] = *(unsigned char *)jchar;
    } else {
/*  LEFT SHIFT CONTENTS OF WORD AND APPEND CHARACTER */
/* Writing concatenation */
	i__1[0] = 5, a__1[0] = word + 1;
	i__1[1] = 1, a__1[1] = jchar;
	s_cat(temp, a__1, i__1, &c__2, (ftnlen)6);
	s_copy(word, temp, (ftnlen)6, (ftnlen)6);
    }
    return 0;
} /* shift_ */

