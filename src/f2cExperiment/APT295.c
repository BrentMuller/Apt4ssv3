/* APT295.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000861.V02   *** */

/* .....FORTRAN SUBROUTINE              APT295               4/30/68 */

/* PURPOSE      TO HANDLE EXPONENTIATION */

/* LINKAGE      CALL APT295 (RESULT,A,B) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN RESULT */
/*              A       BASE */
/*              B       EXPONENT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              REAL FUNCTION       DABS */

/* Subroutine */ int apt295_(doublereal *result, doublereal *a, doublereal *b)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), pow_di(doublereal *, integer *)
	    ;

    /* Local variables */
    static doublereal babs;
    static integer ibabs;




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    /* Parameter adjustments */
    --b;
    --a;
    --result;

    /* Function Body */
    babs = abs(b[1]);
    d__1 = abs(a[1]);
    result[1] = pow_dd(&d__1, &babs);
    if (a[1] >= znumbr_1.z0) {
	goto L10;
    }

/*          WARNING - THE FOLLOWING PROCEDURE WILL GIVE AN INCORRECT */
/*          RESULT FOR THE PART PROGRAM COMBINATION NEGATIVE A */
/*          AND NON-INTEGER B */

    ibabs = (integer) (babs + znumbr_1.z1em2);
    result[1] = pow_di(&znumbr_1.zm1, &ibabs) * result[1];
L10:
    if (b[1] >= znumbr_1.z0) {
	goto L20;
    }
    result[1] = znumbr_1.z1 / result[1];
L20:
    return 0;
} /* apt295_ */

