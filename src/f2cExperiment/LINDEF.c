/* LINDEF.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0002844.V04   *** */


/* .....FORTRAN SUBROUTINE             LINDEF...              5/1/68   GK */

/*              FORTRAN LOGICAL FUNCTION LINDEF */

/* PURPOSE      TO DETERMINE WHETHER A LINE HAS BEEN DEFINED */
/*              AND IS A VERTICAL PLANE. */

/* LINKAGE      CALL LINDEF (A, N) */

/* ARGUMENTS    A       ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE LINE */
/*              N       ERROR CODE OF THE DIAGNOSTIC TO BE PRINTED */
/*                      IN CASE THE PLANE IS NOT VERTICAL */

/* SUBSIDIARIES TYPE                ERROR */
/*              REAL FUNCTION       ABS */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */

logical lindef_(doublereal *lin, integer *nm)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer mn;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    /* Parameter adjustments */
    --lin;

    /* Function Body */
    mn = *nm;


/* ...     CHECK WHETHER INPUT CANONICAL FORM IS DEFINED */

    if (ckdef_(&lin[1])) {
	goto L1;
    }

/* ...     CHECK WHETHER LINE IS WITHIN TOLERANCE OF VERTICAL */

    if (abs(lin[3]) <= znumbr_1.z1em5) {
	goto L2;
    }

/* ...     ISSUE DIAGNOSTIC */

    error_(&mn, "LINDEF  ", (ftnlen)8);
    if (mn == 2 || mn == 3 || mn == 92) {
	goto L2;
    }

/* ...     RETURN VALUE TRUE */

L1:
    ret_val = TRUE_;
    goto L9;

/* ...     RETURN VALUE FALSE */

L2:
    ret_val = FALSE_;
L9:
    return ret_val;
} /* lindef_ */

