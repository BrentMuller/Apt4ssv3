/* FCONV.f -- translated by f2c (version 20100827).
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

static real c_b2 = 10.f;
static integer c__1 = 1;
static doublereal c_b7 = 10.;
static doublereal c_b8 = .5;

/* *** SOURCE FILE : FCONV000.ORG   *** */


/*  *  FCONV  *    VAX11  FORTRAN VERSION 8.6.82  E.MCLELLAN */

/*                          IMPROVED      25.06.82  E.MCLELLAN */
/*                          MODIFIED      16.07.85  E.MCLELLAN */

/*  PURPOSE     TO CONVERT FLOATING POINT NUMBERS TO ALPHAMERIC */
/*              REPRESENTATION */
/*  CALLING SEQUENCE */
/*              CALL FCONV(F,A,N,I,J) */
/*  ARGUMENTS */
/*              F   DOUBLE PRECISION NUMBER TO BE CONVERTED */
/*              A   CHARACTER STRING TO CONTAIN THE CHARACTERS */
/*              N   INTEGER INDICATING THE STARTING BYTE POSITION */
/*                  FROM THE LEFT, TO STORE THE CHARACTERS IN A */
/*              I   NUMBER OF CHARCTERS DESIRED */
/*              J   NUMBER OF FRACTIONAL DIGITS REQUIRED */

/* Subroutine */ int fconv_(doublereal *f, char *a, integer *n, integer *i__, 
	integer *j, ftnlen a_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double pow_ri(real *, integer *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    ;
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double pow_di(doublereal *, integer *), d_sign(doublereal *, doublereal *)
	    ;

    /* Local variables */
    static integer k, l, i1, i2, k1;
    static doublereal fj;
    static integer lsd, msd;
    static doublereal dlsd;
    static char infil[35];
    static doublereal tentoj;

    /* Fortran I/O blocks */
    static icilist io___2 = { 0, infil, 0, "(D35.15)", 35, 1 };
    static icilist io___12 = { 0, infil, 0, "(F35.10)", 35, 1 };




/* .... CHECK SIZE OF VALUE F */

    i__1 = *i__ - *j - 2;
    i__2 = *i__ - *j - 1;
    if (*f < -2147483648.f || *f > 2147483647.f || *f <= -pow_ri(&c_b2, &i__1)
	     || *f >= pow_ri(&c_b2, &i__2)) {
/* .... FOR LARGE NUMBERS AND VALUES WHICH WOULD OVERFLOW */
/*     REQUESTED FIELD - OUTPUT IN D FORMAT */

	s_wsfi(&io___2);
	do_fio(&c__1, (char *)&(*f), (ftnlen)sizeof(doublereal));
	e_wsfi();
	k = 14;
	if (*(unsigned char *)&infil[k - 1] == ' ') {
	    k = 15;
	}
/* .... STORE MANTISSA TO MAX NO OF SIGNIFICANT FIGS FOR FIELD */
	i1 = *n;
	i2 = *n + *i__ - 5;
	k1 = k + *i__ - 5;
	s_copy(a + (i1 - 1), infil + (k - 1), i2 - (i1 - 1), k1 - (k - 1));
/* .... NOW ADD EXPONENT */
	i1 = i2 + 1;
	i2 += 4;
	s_copy(a + (i1 - 1), infil + 31, i2 - (i1 - 1), (ftnlen)4);

    } else {

/* .... NORMAL ROUTE */

/* .... ROUND F TO J DECIMAL PLACES */
	tentoj = pow_di(&c_b7, j);
	msd = (integer) (*f);
	dlsd = *f - (doublereal) msd;
	lsd = (integer) (dlsd * tentoj + d_sign(&c_b8, f));
	fj = (doublereal) msd + (doublereal) lsd / tentoj;
	s_wsfi(&io___12);
	do_fio(&c__1, (char *)&fj, (ftnlen)sizeof(doublereal));
	e_wsfi();
	for (k = 1; k <= 35; ++k) {
	    if (*(unsigned char *)&infil[k - 1] != ' ') {
		goto L20;
	    }
/* L10: */
	}
	k = 35;

L20:
	l = 25 - k + 1 + *j;

	i2 = *n + *i__ - 1;
	i1 = i2 - l + 1;
	k1 = *j + 25;
	s_copy(a + (i1 - 1), infil + (k - 1), i2 - (i1 - 1), k1 - (k - 1));

    }

    return 0;
} /* fconv_ */

