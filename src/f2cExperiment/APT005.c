/* APT005.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000755.V03   *** */


/* .....FORTRAN SUBROUTINE             APT005...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT005 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT */
/*              DEFINED AS THE INTERSECTION OF TWO CIRCLES */
/*              BY THE FOLLOWING APT STATEMENT */
/*              RESULT = POINT/+***, INTOF, CIRC1, CIRC2 */
/*                 **** = XLARGE, YLARGE, XSMALL, YSMALL */

/* LINKAGE      CALL APT005 (RESULT, M, CIRC1, CIRC2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING POINT */
/*              M       INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XLARGE */
/*                      2 = YLARGE */
/*                      4 = XSMALL */
/*                      5 = YSMALL */
/*              CIRC1   ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF ONE INPUT CIRCLE */
/*              CIRC2   ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      OTHER INPUT CIRCLE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT083 */
/*              SUBROUTINE          APT044 */
/*              SUBROUTINE          APT004 */

/* Subroutine */ int apt005_(doublereal *result, integer *mn, doublereal *
	circ1, doublereal *circ2)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int apt004_(doublereal *, integer *, doublereal *,
	     doublereal *), apt044_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt083_(doublereal *, integer *);
    static doublereal rsave[4];





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




/* ...     TRANSFORM CANONICAL FORMS AND CHECK INPUT VALIDITY */

    /* Parameter adjustments */
    --circ2;
    --circ1;
    --result;

    /* Function Body */
    apt083_(&circ1[1], &knumbr_1.k12);
    for (i__ = 1; i__ <= 7; ++i__) {
/* L10: */
	dshar3_1.sc[i__ - 1] = dshar3_1.c__[i__ - 1];
    }
    apt083_(&circ2[1], &knumbr_1.k13);

/* ...     GET CANONICAL FORM OF LINE (APT044) AND THEN POINT (APT004) */

    dshar3_1.sc[7] = znumbr_1.z2 * (dshar3_1.c__[0] - dshar3_1.sc[0]);
    dshar3_1.sc[8] = znumbr_1.z2 * (dshar3_1.c__[1] - dshar3_1.sc[1]);
/* Computing 2nd power */
    d__1 = dshar3_1.sc[6];
/* Computing 2nd power */
    d__2 = dshar3_1.c__[6];
/* Computing 2nd power */
    d__3 = dshar3_1.c__[0];
/* Computing 2nd power */
    d__4 = dshar3_1.sc[0];
/* Computing 2nd power */
    d__5 = dshar3_1.c__[1];
/* Computing 2nd power */
    d__6 = dshar3_1.sc[1];
    dshar3_1.sc[9] = d__1 * d__1 - d__2 * d__2 + d__3 * d__3 - d__4 * d__4 + 
	    d__5 * d__5 - d__6 * d__6;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L20: */
	rsave[i__ - 1] = def_1.r__[i__ + 2];
    }
    apt044_(&def_1.c1[1], &dshar3_1.sc[7], &dshar3_1.sc[8], &znumbr_1.z0, &
	    dshar3_1.sc[9]);
    for (i__ = 1; i__ <= 4; ++i__) {
/* L30: */
	def_1.r__[i__ + 2] = rsave[i__ - 1];
    }
    apt004_(&result[1], mn, &def_1.c1[1], &circ1[1]);
    return 0;
} /* apt005_ */

