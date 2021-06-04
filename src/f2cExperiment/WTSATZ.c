/* WTSATZ.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : WTSATZ00.ORG   *** */

/* Subroutine */ int wtsatz_(integer *id, doublereal *array, integer *ianz, 
	integer *iret)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___1 = { 1, 0, 0, 0, 0 };




    /* Parameter adjustments */
    --array;

    /* Function Body */
    io___1.ciunit = *id;
    i__1 = s_wsue(&io___1);
    if (i__1 != 0) {
	goto L90;
    }
    i__2 = *ianz;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&array[i__], (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L90;
	}
    }
    i__1 = e_wsue();
    if (i__1 != 0) {
	goto L90;
    }
    *iret = 0;
    return 0;

L90:
    *iret = 3;
    return 0;
} /* wtsatz_ */

