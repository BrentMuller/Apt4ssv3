/* ANDF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ANDF0000.ORG   *** */

integer andf_(integer *a, integer *b)
{
    /* System generated locals */
    integer ret_val;


/* .   THIS ROUTINE IS COMPILER DEPENDENT. */

/*    TWO POSSIBLE SOLUTIONS ARE OUTLINED HERE */

/* -VAX-VERSION */

    ret_val = *a & *b;

/* -PRIME=VERSION */

/*      INTEGER */
/*      ANDF=AND(A,B) */

    return ret_val;
} /* andf_ */
