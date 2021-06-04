/* APT010.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000760.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT010         8/68                    AR */
/* .....FORTRAN SUBROUTINE             APT010...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT010 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A POINT */
/*              DEFINED IN A COORDINATE PLANE BY A POLAR COOR- */
/*              DINATE AND THE RADIUS VALUE BY THE FOLLOWING */
/*              APT STATEMENT */
/*              RESULT = POINT/RTHETA, ****, VAL */
/*                       **** = XYPLAN, YZPLAN, OR ZXPLAN */
/*              OR TO DETERMINE A VECTOR IN A COORDINATE PLANE */
/*              DEFINED BY ITS LENGTH AND AN ANGLE BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = VECTOR/LENGTH, VAL, ATANGL, THETA, **** */
/*                       **** = XYPLAN, YZPLAN OR ZXPLAN */

/* LINKAGE      CALL APT010 (RESULT, M, VAL, THETA) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING POINT OR VECTOR */
/*              M       INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XYPLAN, 2 = YZPLAN, 3 = ZXPLAN */
/*              VAL     REAL VARIABLE CONTAINING THE VALUE */
/*                      OF THE POLAR COORDINATE RADIUS OR LENGTH */
/*                      OF THE VECTOR */
/*              THETA   REAL VARIABLE CONTAINING THE VALUE */
/*                      OF THE POLAR COORDINATE ANGLE IN DEGREES */
/*                      OR ANGLE OF THE VECTOR IN DEGREES */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          DEFEXT */
/*              REMAINDERING FUNCTION MOD */

/* Subroutine */ int apt010_(doublereal *result, integer *mn, doublereal *val,
	 doublereal *theta)
{
    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, j, k, m;
#define s1 ((doublereal *)&dshar3_1 + 37)
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt078_(
	    doublereal *, integer *), defext_(doublereal *), unpack_(
	    doublereal *, integer *, integer *, integer *);





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




/* ...     CONVERT THETA TO RADIANS */

    /* Parameter adjustments */
    --result;

    /* Function Body */
    *s1 = *theta * znumbr_1.degrad;
    def_1.r__[*mn - 1] = *val * cos(*s1);
    m = *mn % knumbr_1.k3 + 1;
    def_1.r__[m - 1] = *val * sin(*s1);
    m = m % knumbr_1.k3 + 1;
    def_1.r__[m - 1] = znumbr_1.z0;

/* ...     CONVERT TO BASE SYSTEM IF NECESSARY */

    unpack_(&result[1], &i__, &j, &k);
/* ...    CHECK FOR POINT OR VECTOR */
    if (i__ == 20) {
	goto L10;
    }
    apt081_(def_1.r__, &knumbr_1.km1);
    goto L20;
L10:
    apt078_(def_1.r__, &knumbr_1.km1);
L20:
    defext_(&result[1]);
    return 0;
} /* apt010_ */

#undef s1


