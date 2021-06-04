/* APT064.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000814.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT064         8/68                    RN */
/* .....FORTRAN SUBROUTINE             APT064...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT064 */

/* PURPOSE      TO GENERATE A ROTATION MATRIX WITHIN A COORDINATE */
/*              PLANE FROM THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/+***, BETA */
/*                **** = XYROT, YZROT, OR ZXROT */

/* LINKAGE      CALL APT064 (RESULT, MN, BETA) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = XYROT     2 = YZROT    3 = ZXROT */
/*              BETA    REAL VARIABLE CONTAING THE VALUE OF */
/*                      ROTATION ANGLE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              REAL FUNCTION       COS */
/*              REAL FUNCTION       SIN */
/*              REAL FUNCTION       MOD */

/* Subroutine */ int apt064_(doublereal *result, integer *mn, doublereal *
	beta)
{
    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, j, k;
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)





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
    result -= 5;

    /* Function Body */
    *s1 = *beta * znumbr_1.degrad;
    *s2 = cos(*s1);
    *s1 = sin(*s1);
    if (abs(*s2) < znumbr_1.z1em9) {
	*s2 = znumbr_1.z0;
    }
    if (abs(*s1) < znumbr_1.z1em9) {
	*s1 = znumbr_1.z0;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
	for (k = 1; k <= 3; ++k) {
/* L10: */
	    result[i__ + (k << 2)] = znumbr_1.z0;
	}
    }

/* ...     FORM ROTATION MATRIX */

    j = *mn;
    k = j % knumbr_1.k3 + knumbr_1.k1;
    i__ = k % knumbr_1.k3 + knumbr_1.k1;
    result[j + (j << 2)] = *s2;
    result[k + (k << 2)] = *s2;
    result[j + (k << 2)] = *s1;
    result[k + (j << 2)] = -(*s1);
    result[i__ + (i__ << 2)] = znumbr_1.z1;
    return 0;
} /* apt064_ */

#undef s2
#undef s1


