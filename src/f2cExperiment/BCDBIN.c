/* BCDBIN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000500.V03   *** */


/* .....IMPLEMENTATION DEPENDENT SUBROUTINE ...BCDBIN   8/68          HG */
/* .... IMPLEMENTATION DEPENDENT   ....BCDBIN....   HLG  12/67      ..CD. */
/* PURPOSE      TO CONVERT AN INTEGER FROM BCD TO BINARY. */

/* LINKAGE      CALL BCDBIN (WORD, I, COUNT) */

/* ARGUMENTS    WORD     CONTAINS THE BCD REPRESENTATION OF */
/*                       THE NUMBER, LEFT JUSTIFIED. */
/*              I        WILL CONTAIN THE BINARY INTEGER */
/*              COUNT    WILL CONTAIN A COUNT OF THE NUMBER */
/*                       OF DIGITS IN THE NUMBER. */


/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          HELP */


/* Subroutine */ int bcdbin_(char *word, integer *i__, integer *count, ftnlen 
	word_len)
{
    /* Initialized data */

    static char period[1] = ".";
    static char blank[1] = " ";
    static char zero[1] = "0";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j;
    static char w[8];
    static integer num;
    static char char__[1];




    s_copy(w, word, (ftnlen)8, (ftnlen)8);
    *i__ = 0;
    for (j = 1; j <= 8; ++j) {
	*count = j;
	*(unsigned char *)char__ = *(unsigned char *)&w[j - 1];
	if (*(unsigned char *)char__ == *(unsigned char *)&period[0] || *(
		unsigned char *)char__ == *(unsigned char *)&blank[0]) {
	    goto L100;
	}
	num = *(unsigned char *)char__ - *(unsigned char *)&zero[0];
	if (num > 9 || num < 0) {
	    goto L400;
	}
	*i__ = *i__ * 10 + num;
/* L300: */
    }
L200:
    return 0;
L100:
    --(*count);
    goto L200;
L400:
    *count = -1;
    goto L200;
} /* bcdbin_ */

