/* APT018.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000768.V03   *** */


/* .....FORTRAN SUBROUTINE             APT018...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT018 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS PASSING A GIVEN POINT AND PARALLEL TO A GIVEN */
/*              LINE BY THE FOLLOWING APT STATEMENT */
/*              RESULT = LINE/PNT, PARLEL, LN */

/* LINKAGE      CALL APT018 (RESULT, PNT, LN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING LINE */
/*              PNT     ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT POINT */
/*              LN      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT LINE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT046 */
/*              SUBROUTINE          APT077 */

/* Subroutine */ int apt018_(doublereal *result, doublereal *pnt, doublereal *
	ln)
{
    extern /* Subroutine */ int apt046_(doublereal *, doublereal *, 
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
    --pnt;
    --result;

    /* Function Body */
    apt077_(&ln[1], &c__92);

/* ...     SOLVE FOR PLANE PARLEL TO LN-PLANE  (APT046) */

    apt046_(&result[1], &pnt[1], &ln[1]);
    return 0;
} /* apt018_ */

