/* APT066.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000816.V02   *** */

/* ...  FORTRAN SUBROUTINE               APT066 */

/*              FORTRAN SUBROUTINE APT066 */

/* PURPOSE      TO GENERATE A MATRIX DEFINED AS THE PRODUCT OF */
/*              TWO MATRICES BY THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/M1, M2 */

/* LINKAGE      CALL APT066(RESULT,M1,M2,MN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING MATRIX */
/*              M1      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT MATRIX */
/*              M2      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT MATRIX */
/*              MN      INTEGER SET TO ONE IF APT III ORDER OF */
/*                      MULTIPLICATION FOR THIS CASE IS OPPOSITE TO */
/*                      APT IV ORDER */

/* Subroutine */ int apt066_(doublereal *result, doublereal *m1, doublereal *
	m2, integer *mn)
{
    static integer i__, j, j11, l11;
    static logical switch__;



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/*        CHECK FOR APT III ORDER OF MATRIX MULTIPLICATION */

    /* Parameter adjustments */
    --m2;
    --m1;
    --result;

    /* Function Body */
    switch__ = FALSE_;
    if (ldef_1.altmlt && *mn == 1) {
	switch__ = TRUE_;
    }

/* ...     MAKE MATRIX SQUARE,TRANSFER */

    for (i__ = 1; i__ <= 3; ++i__) {

	l11 = i__ - 1 << 2;
	for (j = 1; j <= 4; ++j) {
	    j11 = l11 + j;
	    if (switch__) {
		goto L5;
	    }
	    result[j11] = m2[l11 + 1] * m1[j] + m2[l11 + 2] * m1[j + 4] + m2[
		    l11 + 3] * m1[j + 8];
	    if (j == 4) {
		result[j11] += m2[l11 + 4];
	    }
	    goto L10;
L5:
	    result[j11] = m1[l11 + 1] * m2[j] + m1[l11 + 2] * m2[j + 4] + m1[
		    l11 + 3] * m2[j + 8];
	    if (j == 4) {
		result[j11] += m1[l11 + 4];
	    }
L10:
	    ;
	}
    }
    return 0;
} /* apt066_ */

