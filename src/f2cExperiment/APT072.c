/* APT072.f -- translated by f2c (version 20100827).
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

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000822.V02   *** */

/* .....FORTRAN SUBROUTINE              APT072 */

/*              FORTRAN SUBROUTINE APT072 */

/* PURPOSE      TO GENERATE A MATRIX FOR MIRRORING BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/ MIRROR, **, ** , ** */
/*                **   = XYPLAN, YZPLAN, OR ZXPLAN */

/* LINKAGE      CALL APT072 (RESULT,MN1,MN2,MN3) */

/* ARGUMENT    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              MN1,MN2,MN3 */
/*                      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      0 = NOT INDICATED */
/*                      1 = XYPLAN 2 = YZPLAN 3 = ZXPLAN */

/* SUBSIDIARY NONE */

/* Subroutine */ int apt072_(doublereal *result, integer *mn1, integer *mn2, 
	integer *mn3)
{
    static integer i__, mn[3];





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



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --result;

    /* Function Body */
    mn[0] = *mn1;
    mn[1] = *mn2;
    mn[2] = *mn3;

/*     INITIALIZE MATRIX VALUES */
    result[1] = znumbr_1.z1;
    result[12] = znumbr_1.z0;
    for (i__ = 2; i__ <= 10; ++i__) {
/* L10: */
	result[i__] = def_1.r__[i__ - 1];
    }
    result[11] = znumbr_1.z1;

/*      TEST MODIFIER CODE */

    for (i__ = 1; i__ <= 3; ++i__) {
	if (mn[i__ - 1] == 1) {
	    result[11] = -znumbr_1.z1;
	}
	if (mn[i__ - 1] == 2) {
	    result[1] = -znumbr_1.z1;
	}
	if (mn[i__ - 1] == 3) {
	    result[6] = -znumbr_1.z1;
	}
/* L20: */
    }
    return 0;
} /* apt072_ */

