/* SETBIT.f -- translated by f2c (version 20100827).
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
    logical bit[32];
} bitcom_;

#define bitcom_1 bitcom_

/* *** SOURCE FILE : M0006684.V01   *** */


/*              FORTRAN SUBROUTINE SETBIT */

/* LINKAGE      SUBROUTINE SETBIT (WORD,N) */

/*          SUBSIDIARIES                  CALLED BY */
/*          NONE                          TYPE          ENTRY */
/*                                        SUBROUTINE    MATCH */

/* Subroutine */ int setbit_(real *word, integer *n)
{
    /* System generated locals */
    static real equiv_0[1];

    /* Local variables */
#define wordl ((logical *)equiv_0)
#define wordr (equiv_0)



/*       32.    COMMON BLOCK FOR SETBIT AND BITMCH */
/*              CONTAINS ONE WORD FOR EACH BIT WITH ONLY THAT BIT SET */
/* * */
/* ARGUMENTS    WORD    CELL WHOSE BIT POSITION IS REFERENCED */
/*              N       BIT POSITION OF WORD TO BE SET */
/* ** */
    *wordr = *word;
    *wordl = *wordl || bitcom_1.bit[*n];
    *word = *wordr;
    goto L1040;
L1040:
    return 0;
} /* setbit_ */

#undef wordr
#undef wordl


