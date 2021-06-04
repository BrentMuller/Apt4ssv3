/* ZVECT.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** aOURCE FILE : M0000991.V03   *** */

/* .....FORTRAN SUBROUTINE             ZVECT....              3/1/68   GK */

/*              FORTRAN LOGICAL FUNCTION ZVECT */

/* PURPOSE      TO DETERMINE WHETHER A VECTOR HAS BEEN DEFINED */
/*              AND IS NOT WITHIN TOLERANCE OF ZERO. */

/* LINKAGE      CALL AVECT (RESULT) */

/* ARGUMENTS    RESULT  ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              REAL FUNCTION       ABS */
/*              LOGICAL FUNCTION    CKDEF */

logical zvect_(doublereal *result)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    extern logical ckdef_(doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    /* Parameter adjustments */
    --result;

    /* Function Body */
    ret_val = ! ckdef_(&result[1]) && abs(result[1]) + abs(result[2]) + abs(
	    result[3]) > znumbr_1.z5em6;
    return ret_val;
} /* zvect_ */

