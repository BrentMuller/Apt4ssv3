/* APT063.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** SOURCE FILE : M0000813.V02   *** */

/* .....FORTRAN SUBROUTINE             APT063...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT063 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A TRANSLATION */
/*              MATRIX FROM THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/TRANSL, D1, D2, D3 */

/* LINKAGE      CALL APT063 (RESULT, D1, D2, D3) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              D1      REAL VARIABLE CONTAINING THE AMOUNT OF */
/*                      TRANSLATION IN THE X DIRECTION */
/*              D2      REAL VARIABLE CONTAINING THE AMOUNT OF */
/*                      TRANSLATION IN THE Y DIRECTION */
/*              D3      REAL VARIABLE CONTAINING THE AMOUNT OF */
/*                      TRANSLATION IN THE Z DIRECTION */

/* SUBSIDIARIES NONE */

/* Subroutine */ int apt063_(doublereal *result, doublereal *d1, doublereal *
	d2, doublereal *d3)
{
    static integer i__;





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */






/* ...     ROTATION MATRIX IS IDENTITY MATRIX */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --result;

    /* Function Body */
    result[1] = znumbr_1.z1;
    for (i__ = 2; i__ <= 10; ++i__) {
/* L10: */
	result[i__] = def_1.r__[i__ - 1];
    }
    result[11] = znumbr_1.z1;

/* ...     ADD TRANSLATION PART OF MATRIX */

    result[4] = *d1;
    result[8] = *d2;
    result[12] = *d3;
    return 0;
} /* apt063_ */

