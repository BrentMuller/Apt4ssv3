/* LNTHF.f -- translated by f2c (version 20100827).
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

static integer c__56 = 56;

/* *** SOURCE FILE : M0002848.V02   *** */

/* .....FORTRAN SUBROUTINE             LNTHF....              3/1/68   GK */

/*              FORTRAN SUBROUTINE LNTHF */

/* PURPOSE      TO COMPUTE THE LENGTH OF A VECTOR. */

/* LINKAGE      CALL LNTHF (RES, ARG) */

/* ARGUMENTS    RES     REAL VARIABLE TO CONTAIN THE RESULT */
/*              ARG     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              REAL FUNCTION       SQRT */
/* Subroutine */ int lnthf_(doublereal *res, doublereal *arg)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */






/* ...     CHECK DEFINITION OF INPUT VECTOR */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --arg;

    /* Function Body */
    if (ckdef_(&arg[1])) {
	goto L20;
    }

/* ...     COMPUTE LENGTH OF VECTOR */

/* Computing 2nd power */
    d__1 = arg[1];
/* Computing 2nd power */
    d__2 = arg[2];
/* Computing 2nd power */
    d__3 = arg[3];
    *res = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    goto L9;

/* ...     DIAGNOSE UNDEFINED INPUT */

L20:
    error_(&c__56, "LNTHF   ", (ftnlen)8);
    *res = znumbr_1.z0;
L9:
    return 0;
} /* lnthf_ */

