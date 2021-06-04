/* APT020.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__92 = 92;

/* *** SOURCE FILE : M0000770.V03   *** */


/* .....FORTRAN SUBROUTINE             APT020...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT020 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS PARALLEL TO, AND AT A GIVEN DISTANCE FROM A */
/*              GIVEN LINE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = LINE/PARLEL, LN, ****, DT */
/*                   **** = XLARGE, YLARGE, XSMALL, YSMALL */

/* LINKAGE      CALL APT020 (RESULT, LN, M, DT) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING LINE */
/*              LN      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT LINE */
/*              M       INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XLARGE */
/*                      2 = YLARGE */
/*                      4 = XSMALL */
/*                      5 = YSMALL */
/*              DT      REAL VARIABLE CONTAINING THE DISTANCE */
/*                      BETWEEN THE LINES */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT047 */
/*              SUBROUTINE          APT077 */

/* Subroutine */ int apt020_(doublereal *result, doublereal *ln, integer *mn, 
	doublereal *dt)
{
    extern /* Subroutine */ int apt047_(doublereal *, doublereal *, integer *,
	     doublereal *), apt077_(doublereal *, integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/* ...     CHECK VALIDITY OF LN IN LOCAL SYSTEM */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --ln;
    --result;

    /* Function Body */
    apt077_(&ln[1], &c__92);

/* ...     SOLVE FOR PLANE PARLEL TO LN, DISTANCE DT - APT047 (BASE SYS) */

    apt047_(&result[1], &ln[1], mn, dt);
    return 0;
} /* apt020_ */

