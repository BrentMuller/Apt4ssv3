/* ICONV.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ICONV000.ORG   *** */


/*  *  ICONV  *    VAX11 FORTRAN VERSION   8.4.81   E.MCLELLAN */

/*                              MODIFEED  25.06.82  E.MCLELLAN */
/*                              MODIFIED  16.07.85  E.MCLELLAN */
/*                              MODIFIED  07.07.86  E.MCLELLAN */

/*  PURPOSE     TO CONVERT INTEGERS TO ALPHAMERIC REPRESENTATAION */

/*  CALLING SEQUENCE */
/*              CALL ICONV(I,A,N,K) */
/*  ARGUMENTS */
/*              I   INTEGER VALUE TO BE CONVERTED TO CHARACTER */
/*              A   CHARACTER STRING TO CONTAIN THE CONVERTED INTEGER */
/*              N   INTEGER INDICATING THE START BYTE POSITION TO */
/*                  STORE THE CHARACTERS IN A */
/*              K   INTEGER INDICATING TOTAL NUMBER OF CHARACTERS */
/*                  DESIRED */

/* Subroutine */ int iconv_(integer *i__, char *a, integer *n, integer *k, 
	ftnlen a_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j, l, i1, i2;
    static char intfil[11];

    /* Fortran I/O blocks */
    static icilist io___2 = { 0, intfil, 0, "(I11)", 11, 1 };



    s_wsfi(&io___2);
    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
    e_wsfi();
    for (j = 1; j <= 11; ++j) {
	if (*(unsigned char *)&intfil[j - 1] != ' ') {
	    goto L20;
	}
/* L10: */
    }
    j = 11;

L20:
    l = 12 - j;
    if (l > *k) {
	goto L30;
    }

    i2 = *n + *k - 1;
    i1 = i2 - l + 1;
    s_copy(a + (i1 - 1), intfil + (j - 1), i2 - (i1 - 1), 11 - (j - 1));
    goto L99;
/* ---- OVERFLOW */
L30:
    i1 = *n;
    i__1 = *k;
    for (j = 1; j <= i__1; ++j) {
	*(unsigned char *)&a[i1 - 1] = '*';
/* L35: */
	++i1;
    }

L99:
    return 0;
} /* iconv_ */

