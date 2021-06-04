/* UNPACK.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000983.V01   *** */

/* .....FORTRAN SUBROUTINE             UNPACK...              3/1/68   GK */

/*                                                7/69      RW */

/*             FORTRAN SUBROUTINE UNPACK */

/* PURPOSE     TO UNPACK THE INDICATOR WORD FOR AN ENTRY IN THE */
/*             CANONICAL FORM TABLE */

/* LINKAGE     CALL UNPACK (RESULT,MODE,SIZE,SUB) */

/* ARGUMENTS   RESULT  AN ARRAY WITHIN THE CANONICAL FORM TABLE */
/*            IMODE  INTEGER TO CONTAIN MODE OF THE SURFACE */
/*            ISIZE  INTEGER TO CONTAIN SIZE OF CANONICAL FORM */
/*            ISUB   INTEGER TO CONTAIN TEH NAME SUBSCRIPT OF SURFACE */

/* Subroutine */ int unpack_(doublereal *result, integer *imode, integer *
	isize, integer *isub)
{
    /* Initialized data */

    static integer klit1 = 1000000;
    static integer klit2 = 10000;

    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer j, ipack;

    /* Parameter adjustments */
    --result;

    /* Function Body */
    j = 0;
/* L10: */
    ipack = (d__1 = result[j], (integer) abs(d__1));
    *imode = ipack / klit1;
    *isize = (ipack - *imode * klit1) / klit2;
    *isub = ipack - *imode * klit1 - *isize * klit2;
    return 0;
} /* unpack_ */

