/* APT019.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : M0000769.V02   *** */

/* .....FORTRAN SUBROUTINE              APT019                3/6/68 */

/*              FORTRAN SUBROUTINE APT019 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS PASSING THROUGH A POINT AND PERPENDICULAR TO */
/*              A GIVEN LINE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = LINE/PNT, PERPTO, LN */

/* LINKAGE      CALL APT019 (RESULT, PNT, LN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING LINE */
/*              PNT     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */
/*              LN      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT LINE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT022 */

/* Subroutine */ int apt019_(doublereal *result, doublereal *pnt, doublereal *
	ln)
{
    extern /* Subroutine */ int apt022_(doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */






/* ...     USE APT022 TO FIND LINE THRU PNT, AT 90 DEGREES WITH LN */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --ln;
    --pnt;
    --result;

    /* Function Body */
    apt022_(&result[1], &pnt[1], &c__1, &znumbr_1.z90, &ln[1]);
    return 0;
} /* apt019_ */

