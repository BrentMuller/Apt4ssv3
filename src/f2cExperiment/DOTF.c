/* DOTF.f -- translated by f2c (version 20100827).
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

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__10 = 10;

/* *** SOURCE FILE : M0002836.V02   *** */

/* .....FORTRAN SUBROUTINE             DOTF.....              5/1/68   GK */
/*                      THE FIRST INPUT VECTOR */
/*              ARG2    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */

/* Subroutine */ int dotf_(doublereal *result, doublereal *arg1, doublereal *
	arg2)
{
    static integer i__;
    static doublereal ds[6];
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --arg2;
    --arg1;

    /* Function Body */
    if (ckdef_(&arg1[1]) || ckdef_(&arg2[1])) {
	goto L20;
    }

/* ...     MOVE ARGUMENTS TO DOUBLE PRECISION SCRATCH LOCATIONS */


    for (i__ = 1; i__ <= 3; ++i__) {
	ds[i__ - 1] = arg1[i__];
	ds[i__ + 2] = arg2[i__];
/* L10: */
    }

/* ...     COMPUTE DOT PRODUCT */

    *result = ds[0] * ds[3] + ds[1] * ds[4] + ds[2] * ds[5];
    goto L9;

/* ...     ISSUE DIAGNOSTIC, INPUT UNDEFINED, RESULT=0 */

L20:
    error_(&c__10, "DOTF   ", (ftnlen)7);
    *result = znumbr_1.z0;
L9:
    return 0;
} /* dotf_ */

