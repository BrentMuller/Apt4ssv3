/* APT075.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000825.V03   *** */


/* .....FORTRAN SUBROUTINE             APT075...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT075 */

/* PURPOSE      TO GENERATE THE SOLUTION OF THREE SIMULTANEOUS */
/*              EQUATIONS IN THREE UNKNOWS. */

/* LINKAGE      CALL APT075 (RESULT, AIN) */

/* ARGUMENTS    RESULT              ARRAY TO CONTAIN VALUES OF X, Y, */
/*                                  AND Z AS RESULT (1), RESULT (2), */
/*                                  AND RESULT (3), RESPECTIVELY. */
/*              AIN (1-3, 1)        COEFFICIENTS OF X, Y, Z IN THE */
/*                                  FIRST EQUATION */
/*              AIN (1-3, 2)        COEFFICIENTS OF X, Y, Z IN THE */
/*                                  SECOND EQUATION */
/*              AIN (1-3, 3)        COEFFICIENTS OF X, Y, Z IN THE */
/*                                  THIRD EQUATION */
/*              AIN (4, 1-3)        CONSTANT TERM IN EACH OF THE */
/*                                  THREE EQUATIONS */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          CROSS */
/*              SUBROUTINE          DOTF */

/* Subroutine */ int apt075_(doublereal *result, doublereal *ain)
{
    /* Local variables */
    static integer i__, j;
#define st ((doublereal *)&dshar3_1 + 37)
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal denom;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);





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





/* ...     STORE ARRAY IN S, INTERCHANGING ROWS AND COLUMNS */

    /* Parameter adjustments */
    ain -= 5;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L10: */
	    st[i__ + j * 3 - 4] = ain[j + (i__ << 2)];
	}
    }

/* ...     SOLVE EQUATIONS BY KRAMER'S RULE */

    cross_(&st[3], &st[6], dshar3_1.v);
    dotf_(&denom, st, dshar3_1.v);
    if (abs(denom) <= znumbr_1.z1em6) {
	goto L30;
    }
    dotf_(&result[1], dshar3_1.v, &st[9]);
    result[1] /= denom;
    cross_(&st[9], &st[6], dshar3_1.v);
    dotf_(&result[2], dshar3_1.v, st);
    result[2] /= denom;
    cross_(&st[3], &st[9], dshar3_1.v);
    dotf_(&result[3], dshar3_1.v, st);
    result[3] /= denom;
    goto L99;
L30:
    idef_1.ierror = knumbr_1.k52;
L99:
    return 0;
} /* apt075_ */

#undef st


