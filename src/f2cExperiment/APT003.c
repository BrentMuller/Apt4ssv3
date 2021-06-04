/* APT003.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;

/* *** SOURCE FILE : M0000753.V03   *** */


/* .....FORTRAN SUBROUTINE             APT003...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT003 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT */
/*              DEFINED AS THE INTERSECTION OF TWO LINES BY */
/*              THE FOLLOWING APT STATEMENT */
/*              RESULT = POINT/INTOF, LINE1, LINE2 */


/* LINKAGE      CALL APT003  (RESULT, LINE1, LINE2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING POINT. */
/*              LINE1   ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF ONE INPUT LINE. */
/*              LINE2   ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE OTHER INPUT LINE. */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT001 */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       ABS */

/* Subroutine */ int apt003_(doublereal *result, doublereal *line1, 
	doublereal *line2)
{
    static integer i__;
    static doublereal pll[12]	/* was [4][3] */;
    extern /* Subroutine */ int apt001_(doublereal *), apt075_(doublereal *, 
	    doublereal *), apt077_(doublereal *, integer *), defext_(
	    doublereal *);





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




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




/* ...     TRANSFORM CANONICAL FORM TO LOCAL SYSTEM */

    /* Parameter adjustments */
    --line2;
    --line1;
    --result;

    /* Function Body */
    apt077_(&line1[1], &c__2);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L10: */
	pll[i__ - 1] = dshar3_1.l[i__ - 1];
    }
    apt077_(&line2[1], &c__3);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L11: */
	pll[i__ + 3] = dshar3_1.l[i__ - 1];
    }
    pll[8] = znumbr_1.z0;
    pll[9] = znumbr_1.z0;
    pll[10] = znumbr_1.z1;
    pll[11] = znumbr_1.z0;

/* ....   COMPUTE SIMULTANEOUS SOLUTION OF 3 PLANE EQUATIONS */

    apt075_(&result[1], pll);
    if (idef_1.ierror == knumbr_1.k52) {
	goto L20;
    }
    apt001_(&result[1]);
    goto L30;
L20:
    idef_1.ierror = knumbr_1.k4;
    defext_(&result[1]);
L30:
    return 0;
} /* apt003_ */

