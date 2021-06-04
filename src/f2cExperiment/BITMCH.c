/* BITMCH.f -- translated by f2c (version 20100827).
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

/* Common Block Declarations */

struct {
    integer bit[32];
} bitcom_;

#define bitcom_1 bitcom_

/* *** SOURCE FILE : M0006623.V01   *** */


/*              FORTRAN SUBROUTINE BITMCH */

/* LINKAGE      LOGICAL FUNCTION BITMCH(WORD,N) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    COMSTR */

logical bitmch_(integer *word, integer *n)
{
    /* System generated locals */
    logical ret_val;



/*       32.    COMMON BLOCK FOR SETBIT AND BITMCH */
/*              CONTAINS ONE WORD FOR EACH BIT WITH ONLY THAT BIT SET */
/* * */
/* PURPOSE      TO DETERMINE WHETHER THE BIT POSITION DESIGNATED */
/*              BY THE SECOND ARGUMENT N IS SET IN THE FIRST */
/*              ARGUMENT WORD. */

/* ARGUMENTS    WORD    ELEMENT WHOSE BIT POSITION IS BEING EXAMINED */
/*              N       BIT POSITION */
/* ** */
    ret_val = FALSE_;
    if (*word / bitcom_1.bit[*n] % 2 == 1) {
	ret_val = TRUE_;
    }
/* L2: */
    return ret_val;
} /* bitmch_ */

