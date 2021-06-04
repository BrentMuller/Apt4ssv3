/* APT059.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__40 = 40;

/* *** SOURCE FILE : M0002234.V05   *** */


/* .....FORTRAN SUBROUTINE             APT059...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT059 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF AN ELLIPSE OR */
/*              HYPERBOLA, GIVEN THE CENTER, ROTATION ANGLE, */
/*              AND MAJOR AND MINOR AXIS. */

/* LINKAGE      CALL APT059 (RESULT, PN, MA, MI, BETA, SGN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE SECOND DEGREE EQUATION */
/*              PN      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE CENTER POINT */
/*              MA      REAL VARIABLE CONTAINING THE LENGTH OF */
/*                      THE SEMI-MAJOR AXIS */
/*              MI      REAL VARIABLE CONTAINING THE LENGTH */
/*                      OF THE SEMI-MINOR AXIS */
/*              BETA    REAL VARIABLE CONTAINING THE VALUE OF */
/*                      THE ANGLE BETWEEN THE MAJOR AXIS AND THE */
/*                      X-AXIS */
/*              SGN     REAL VARIABLE CONTAINING THE SURFACE */
/*                      INDICATOR */
/*                           1 = ELLIPSE;   -1 = HYPERBOLA */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT079 */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       COS */
/*              REAL FUNCTION       SIN */

/* Subroutine */ int apt059_(doublereal *result, doublereal *pn, doublereal *
	ma, doublereal *mi, doublereal *beta, doublereal *sgn)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
#define s3 ((doublereal *)&dshar3_1 + 39)
#define s4 ((doublereal *)&dshar3_1 + 40)
#define s5 ((doublereal *)&dshar3_1 + 41)
#define s6 ((doublereal *)&dshar3_1 + 42)
#define s7 ((doublereal *)&dshar3_1 + 43)
    static doublereal swop;
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt079_(
	    doublereal *, integer *), error_(integer *, char *, ftnlen), 
	    defext_(doublereal *);





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





/* ...     TRANSFORM POINT TO LOCAL SYSTEM, CHECK VALIDITY */

    /* Parameter adjustments */
    --pn;
    --result;

    /* Function Body */
    apt081_(&pn[1], &knumbr_1.k0);
    if (*ma > *mi) {
	goto L10;
    }
    error_(&c__40, "APT059  ", (ftnlen)8);
    swop = *ma;
    *ma = *mi;
    *mi = swop;
    *beta += 90;
L10:
    *s1 = *beta * znumbr_1.degrad;
    *s2 = sin(*s1);
    *s3 = cos(*s1);
/* Computing 2nd power */
    d__1 = *s2;
    *s4 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = *s3;
    *s5 = d__1 * d__1;
/* Computing 2nd power */
    d__1 = *ma;
    *s6 = *sgn * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = *mi;
    *s7 = d__1 * d__1;
    def_1.r__[0] = *s7 * *s5 + *s6 * *s4;
    def_1.r__[1] = *s7 * *s4 + *s6 * *s5;
/* Computing 2nd power */
    d__1 = dshar3_1.p[0] * *s3 + dshar3_1.p[1] * *s2;
/* Computing 2nd power */
    d__2 = dshar3_1.p[0] * *s2 - dshar3_1.p[1] * *s3;
/* Computing 2nd power */
    d__3 = *ma;
    def_1.r__[3] = *s7 * (d__1 * d__1) + *s6 * (d__2 * d__2) - *s7 * (d__3 * 
	    d__3);
    def_1.r__[5] = znumbr_1.z0;
    def_1.r__[6] = *s2 * *s3 * (*s7 - *s6);
    def_1.r__[7] = -dshar3_1.p[1] * def_1.r__[6] - dshar3_1.p[0] * def_1.r__[
	    0];
    def_1.r__[8] = -dshar3_1.p[0] * def_1.r__[6] - dshar3_1.p[1] * def_1.r__[
	    1];
    apt079_(def_1.r__, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt059_ */

#undef s7
#undef s6
#undef s5
#undef s4
#undef s3
#undef s2
#undef s1


