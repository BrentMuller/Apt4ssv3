/* APT058.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000808.V02   *** */

/* .....FORTRAN SUBROUTINE             APT058...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT058 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A HYPERBOLA */
/*              DEFINED AS HAVING A GIVEN CENTER POINT, GIVEN */
/*              LENGTHS OF SEMI-TRANSVERSE AND SEMI-CONJUGATE */
/*              AXIS, AND A GIVEN ANGLE BETWEEN THE TRANSVERSE */
/*              AXIS AND THE X AXIS BY THE FOLLOWING APT STATEMENT */
/*              RESULT = HYPERB/CENTER, PN, STA, SCA, BETA */

/* LINKAGE      CALL APT058 (RESULT, PN, STA, SCA, BETA) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING HYPERBOLA */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */
/*              STA     REAL VARIABLE CONTAINING THE LENGTH */
/*                      OF SEMI-TRANSVERSE AXIS */
/*              SCA     REAL VARIABLE CONTAINING THE LENGTH OF */
/*                      THE SEMI-CONJUGATE AXIS */
/*              BETA    REAL VARIABLE CONTAINING THE ANGLE */
/*                      BETWEEN THE TRANSVERSE AXIS AND THE */
/*                      X AXIS (DEGREES) */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT059 */

/* Subroutine */ int apt058_(doublereal *result, doublereal *pn, doublereal *
	sta, doublereal *sca, doublereal *beta)
{
    extern /* Subroutine */ int apt059_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */



    /* Parameter adjustments */
    --pn;
    --result;

    /* Function Body */
    apt059_(&result[1], &pn[1], sta, sca, beta, &znumbr_1.zm1);
    return 0;
} /* apt058_ */

