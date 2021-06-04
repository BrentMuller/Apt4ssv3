/* CLOSPE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : CLOSPE00.ORG   *** */

/* Subroutine */ int clospe_(integer *id, integer *iret)
{
    /* System generated locals */
    integer i__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_clos(cllist *);



    cl__1.cerr = 1;
    cl__1.cunit = *id;
    cl__1.csta = "KEEP";
    i__1 = f_clos(&cl__1);
    if (i__1 != 0) {
	goto L10;
    }
    *iret = 0;
    return 0;

L10:
    *iret = 1;
    return 0;
} /* clospe_ */

