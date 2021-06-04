/* PSIGN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002773.V01   *** */

/* ....    FORTRAN FUNCTION SUBPROGRAM      PSIGN      4/1/69     RC */

/*      REAL FUNCTION PSIGN(A,B) */
doublereal psign_(doublereal *a, doublereal *b)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);


/*  PURPOSE         TO MULTIPLY THE FIRST ARGUMENT BY THE SIGN OF THE */
/*                  SECOND ARGUMENT  -AND- IF THE SECOND ARGUMENT */
/*                  IS EQUAL TO ZERO, TO RETURN THE VALUE ZERO */

/*  LINKAGE         VALUE=PSIGN(A,B) */

/*  ARGUMENTS       A AND B ANY REAL VARIABLES */

/*  CALLED BY       QSD */

/*     ------------------------------------------------------------ */

    if (*b != 0.) {
	goto L10;
    } else {
	goto L20;
    }

L10:
    ret_val = d_sign(a, b);
    return ret_val;

L20:
    ret_val = 0.f;
    return ret_val;
} /* psign_ */

