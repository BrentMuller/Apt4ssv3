/* APT027.f -- translated by f2c (version 20100827).
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

static integer c__0 = 0;

/* *** SOURCE FILE : M0002795.V03   *** */


/* .....FORTRAN SUBROUTINE             APT027...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT027 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED */
/*              AS PASSING THROUGH THREE GIVEN POINTS BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = CIRCLE/PN1, PN2, PN3 */

/* LINKAGE      CALL APT027 (RESULT, PN1, PN2, PN3) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              PN1     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT POINT */
/*              PN2     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT POINT */
/*              PN3     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE THIRD INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT075 */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          APT083 */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          ERROR */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt027_(doublereal *result, doublereal *pn1, doublereal *
	pn2, doublereal *pn3)
{
    /* Initialized data */

    static doublereal zlit1 = 4.;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt075_(
	    doublereal *, doublereal *), apt083_(doublereal *, integer *), 
	    error_(integer *, char *, ftnlen), defext_(doublereal *);





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



    /* Parameter adjustments */
    --pn3;
    --pn2;
    --pn1;
    --result;

    /* Function Body */

/* ...     TRANSFORM COORDINATES, FORM P ARRAY, CHECK VALIDITY */
/* ...     WARNING IF POINTS NOT IN HORIZONTAL PLANE */
    apt081_(&pn3[1], &c__0);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	dshar3_1.p[i__ + 7] = dshar3_1.p[i__ - 1];
    }
    apt081_(&pn2[1], &c__0);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	dshar3_1.p[i__ + 3] = dshar3_1.p[i__ - 1];
    }
    apt081_(&pn1[1], &c__0);
    if (dshar3_1.p[2] != dshar3_1.p[6] || dshar3_1.p[2] != dshar3_1.p[10]) {
	error_(&knumbr_1.k30, "APT027  ", (ftnlen)8);
    }


/* ...     SOLVE 3 SIMULTANEOUS EQUATIONS FOR COEFFICIENTS OF CIRCLE EQ. */
/* L30: */
    for (i__ = 1; i__ <= 9; i__ += 4) {
/* Computing 2nd power */
	d__1 = dshar3_1.p[i__ - 1];
/* Computing 2nd power */
	d__2 = dshar3_1.p[i__];
	dshar3_1.p[i__ + 2] = d__1 * d__1 + d__2 * d__2;
/* L40: */
	dshar3_1.p[i__ + 1] = znumbr_1.z1;
    }
    apt075_(def_1.r__, dshar3_1.p);
    if (idef_1.ierror != 0) {
	idef_1.ierror = knumbr_1.k29;
    }
/* L50: */
/* Computing 2nd power */
    d__1 = def_1.r__[0];
/* Computing 2nd power */
    d__2 = def_1.r__[1];
    def_1.r__[6] = sqrt(d__1 * d__1 + d__2 * d__2 + zlit1 * def_1.r__[2]) / 
	    znumbr_1.z2;
    for (i__ = 1; i__ <= 2; ++i__) {
	def_1.r__[i__ - 1] /= znumbr_1.z2;
/* L60: */
	def_1.r__[i__ + 1] = znumbr_1.z0;
    }
    def_1.r__[4] = znumbr_1.z0;
    def_1.r__[5] = znumbr_1.z1;
    apt083_(def_1.r__, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt027_ */

