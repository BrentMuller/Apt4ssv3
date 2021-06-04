/* UNDEF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000981.V02   *** */

/* .....FORTRAN SUBROUTINE             UNDEF....              3/1/68   GK */

/*             FORTRAN SUBROUTINE UNDEF */

/* PURPOSE     TO STORE THE BCD WORD *TRASH IN THE FIRST WORD OF THE */
/*             CANONICAL FORM ARRAY SET AN UNDEFINED SURFACE */

/* LINKAGE     CALL UNDEF(A) */

/* ARG MENT    A    ARRAY CONTAINING ELEMENT TO BE DECLA RED UNDEFINED */
/* Subroutine */ int undef_(doublereal *a)
{
    extern /* Subroutine */ int strtsh_(doublereal *);


    /* Parameter adjustments */
    --a;

    /* Function Body */
    strtsh_(&a[1]);
    return 0;
} /* undef_ */

