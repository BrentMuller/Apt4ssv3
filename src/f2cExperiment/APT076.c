/* APT076.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000826.V02   *** */

/* .....FORTRAN SUBROUTINE             APT076...              5/1/68   GK */

/*              FORTRAN SUBROUTINE APT076 */

/* PURPOSE      TO GENERATE THE PRODUCT OF TWO SQUARE */
/*              MATRICES OF EQUAL DIMENSION AS A SQUARE */
/*              MATRIX OF THE SAME DIMENSION. */

/* LINKAGE      CALL APT076 (RESULT, XM1, XM2, MN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE RESULTING MATRIX */
/*                      STORED BY ROWS */
/*              XM1     ARRAY CONTAINING THE FIRST INPUT */
/*                      MATRIX STORED BY ROWS */
/*              XM2     ARRAY CONTAINING THE SECOND INPUT */
/*                      MATRIX STORED BY ROWS */
/*              N       NUMBER OF ROWS (OR COLUMNS) IN THE */
/*                      MATRICES */

/* SUBSIDIARIES NONE */

/* Subroutine */ int apt076_(doublereal *result, doublereal *xm1, doublereal *
	xm2, integer *mn)
{
    /* System generated locals */
    integer result_dim1, result_offset, xm1_dim1, xm1_offset, xm2_dim1, 
	    xm2_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, m;





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






/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    xm2_dim1 = *mn;
    xm2_offset = 1 + xm2_dim1;
    xm2 -= xm2_offset;
    xm1_dim1 = *mn;
    xm1_offset = 1 + xm1_dim1;
    xm1 -= xm1_offset;
    result_dim1 = *mn;
    result_offset = 1 + result_dim1;
    result -= result_offset;

    /* Function Body */
    k = *mn;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = k;
	for (j = 1; j <= i__2; ++j) {
	    result[i__ + j * result_dim1] = znumbr_1.z0;

/* ...     ELEMENT I,J IS THE PRODUCT OF J-TH ROW OF MX1 WITH I-TH COLUMN */
/*        OF MX2 */
	    i__3 = k;
	    for (m = 1; m <= i__3; ++m) {
/* L10: */
		result[i__ + j * result_dim1] += xm1[m + j * xm1_dim1] * xm2[
			i__ + m * xm2_dim1];
	    }
	}
    }
    return 0;
} /* apt076_ */

