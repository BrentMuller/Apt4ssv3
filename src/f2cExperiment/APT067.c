/* APT067.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000817.V03   *** */


/* .....FORTRAN SUBROUTINE             APT067...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT067 */

/* PURPOSE      TO GENERATE A MATRIX DEFINED AS THE INVERSE OF */
/*              A GIVEN MATRIX OF ROTATION AND/OR TRANSLATION BY */
/*              THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/INVERS, MX */

/* LINKAGE      CALL APT067 (RESULT, MX) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              MX      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT MATRIX */

/* SUBSIDIARIES NONE */

/* Subroutine */ int apt067_(doublereal *result, doublereal *mx)
{
    /* Local variables */
    static integer i__, j;
#define st ((doublereal *)&dshar3_1 + 37)





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
    mx -= 5;
    result -= 5;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	st[(i__ << 2) - 1] = znumbr_1.z0;
	for (j = 1; j <= 3; ++j) {
	    st[j + (i__ << 2) - 5] = mx[i__ + (j << 2)];
/* L10: */
	    st[(i__ << 2) - 1] -= st[j + (i__ << 2) - 5] * mx[(j << 2) + 4];
	}
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L20: */
	    result[i__ + (j << 2)] = st[i__ + (j << 2) - 5];
	}
    }
    return 0;
} /* apt067_ */

#undef st


