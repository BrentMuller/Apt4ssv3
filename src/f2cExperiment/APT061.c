/* APT061.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000811.V03   *** */


/* .....FORTRAN SUBROUTINE             APT061...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT061 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A GENERAL */
/*              CONIC IN THE XY PLANE BY THE COEFFICIENTS OF */
/*              THE EXPRESSION OF ONE VARIABLE AS A FUNCTION OF */
/*              THE OTHER */
/*                Y = PX + Q + RX2 + SX + T OR */
/*                X = PY + Q + RY2 + SY + T */
/*              BY THE APT STATEMENTS */
/*                   RESULT = GCONIC/P,Q,RA,S,T OR */
/*                   RESULT = GCONIC/P,Q,RA,S,T, FUNOFY */
/*                            RESPECTIVELY. */

/* LINKAGE      CALL APT061 (RESULT, PM,Q,RA,SM,TM,MN,) */

/* ARGUMENTS    RESULTS ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING CONIC */
/*              PM      COEFFICIENT IN APPROPRIATE EQUATION */
/*                      ABOVE */
/*              Q       COEFFICIENT IN APPROPRIATE EQUATION */
/*                      ABOVE */
/*              RA      COEFFICIENT IN APPROPRIATE EQUATION */
/*                      ABOVE */
/*              SM      COEFFICIENT IN APPROPRIATE EQUATION */
/*                      ABOVE */
/*              TM      COEFFICIENT IN APPROPRIATE EQUATION */
/*                      ABOVE */
/*              MN      INTEGER EQUIVALENT OF MODIFIER */
/*                      1 IF NOT FUNOFY; 2 IF FUNOFY */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT079 */
/*              SUBROUTINE          DEFEXT */

/* Subroutine */ int apt061_(doublereal *result, doublereal *pm, doublereal *
	q, doublereal *ra, doublereal *sm, doublereal *tm, integer *mn)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__, j;
#define s1 ((doublereal *)&dshar3_1 + 37)
#define s2 ((doublereal *)&dshar3_1 + 38)
    extern /* Subroutine */ int apt079_(doublereal *, integer *), defext_(
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




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





    /* Parameter adjustments */
    --result;

    /* Function Body */
    *s1 = *pm;
    *s2 = *q;
    i__ = *mn;
    j = knumbr_1.k3 - i__;
/* Computing 2nd power */
    d__1 = *s1;
    def_1.r__[i__ - 1] = d__1 * d__1 - *ra;
    def_1.r__[i__ + 6] = *s1 * *s2 - *sm / znumbr_1.z2;
    def_1.r__[j - 1] = znumbr_1.z1;
    def_1.r__[j + 6] = -(*s2);
/* Computing 2nd power */
    d__1 = *s2;
    def_1.r__[3] = d__1 * d__1 - *tm;
    def_1.r__[5] = znumbr_1.z0;
    def_1.r__[6] = -(*s1);
    apt079_(def_1.r__, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt061_ */

#undef s2
#undef s1


