/* APT030.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000780.V03   *** */


/* .....FORTRAN SUBROUTINE             APT030...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT030 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED */
/*              AS TANGENT TO EACH OF TWO GIVEN LINES AND HAVING */
/*              A GIVEN RADIUS BY THE FOLLOWING APT STATEMENT */
/*              RESULT = CIRCLE/+***, LI, ****, L2, RADIUS, RAD */
/*                **** = XLARGE, YLARGE, XSMALL, YSMALL */

/* LINKAGE      CALL APT030 (RESULT, M1, L1, M2, L2, RAD) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              M1      INTEGER EQUIVALENT OF THE FIRST MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              L1      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT LINE */
/*              M2      INTEGER EQUIVALENT OF THE SECOND MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              L2      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT LINE */
/*              RAD     REAL VARIABLE CONTAINING THE VALUE OF THE */
/*                      DESIRED RADIUS */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT003 */
/*              SUBROUTINE          APT020 */
/*              SUBROUTINE          APT078 */

/* Subroutine */ int apt030_(doublereal *result, integer *m1, doublereal *l1, 
	integer *m2, doublereal *l2, doublereal *rad)
{
    static integer i__;
    extern /* Subroutine */ int apt020_(doublereal *, doublereal *, integer *,
	     doublereal *), apt003_(doublereal *, doublereal *, doublereal *),
	     apt078_(doublereal *, integer *);





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





/* ...     DEFINE C1 WITH AXIS OF DESIRED CYLINDER */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --l2;
    --l1;
    --result;

    /* Function Body */
    apt078_(&def_1.r__[3], &knumbr_1.km1);
    for (i__ = 1; i__ <= 3; ++i__) {
	def_1.c1[i__] = def_1.r__[i__ - 1];
/* L10: */
	def_1.r__[i__ - 1] = znumbr_1.z0;
    }
    def_1.c1[4] = *rad;
/* ...     DEFINE LINES PARALLEL TO L1,L2 AT DISTANCE RAD */

    apt020_(&def_1.ln1[1], &l1[1], m1, &def_1.c1[4]);
    for (i__ = 2; i__ <= 5; ++i__) {
/* L30: */
	dshar3_1.sc[i__ + 10] = def_1.ln1[i__ - 1];
    }
    apt020_(&def_1.ln1[1], &l2[1], m2, &def_1.c1[4]);

/* ...     SOLVE FOR INTERSECTION OF LN1 AND SC(13) -GIVES CIRCLE CENTER */

    for (i__ = 4; i__ <= 7; ++i__) {
/* L50: */
	def_1.r__[i__ - 1] = def_1.c1[i__ - 3];
    }
    apt003_(&result[1], &dshar3_1.sc[12], &def_1.ln1[1]);
    for (i__ = 4; i__ <= 7; ++i__) {
/* L20: */
	result[i__] = def_1.c1[i__ - 3];
    }
    return 0;
} /* apt030_ */

