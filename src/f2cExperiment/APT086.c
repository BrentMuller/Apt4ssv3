/* APT086.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000833.V02   *** */

/* .....FORTRAN SUBROUTINE             APT086...              5/1/68   GK */

/*              FORTRAN SUBROUTINE APT086 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A MATRIX AS */
/*              THE TRANSPOSE OF A GIVEN SQUARE MATRIX. */

/* LINKAGE      CALL APT086 (RESULT, AIN, NM) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              AIN     ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE INPUT MATRIX */
/*              NM      INTEGER CONTAINING THE NUMBER OF ROWS */
/*                      IN THE INPUT MATRIX */

/* SUBSIDIARIES NONE */

/* Subroutine */ int apt086_(doublereal *result, doublereal *ain, integer *nm)
{
    /* System generated locals */
    integer result_dim1, result_offset, ain_dim1, ain_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */





/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    ain_dim1 = *nm;
    ain_offset = 1 + ain_dim1;
    ain -= ain_offset;
    result_dim1 = *nm;
    result_offset = 1 + result_dim1;
    result -= result_offset;

    /* Function Body */
    i__1 = *nm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nm;
	for (j = 1; j <= i__2; ++j) {
/* L10: */
	    result[j + i__ * result_dim1] = ain[i__ + j * ain_dim1];
	}
    }
    return 0;
} /* apt086_ */

