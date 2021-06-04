/* APT044.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000794.V02   *** */

/* .....FORTRAN SUBROUTINE             APT044...              6/10/68 EAN */

/*              FORTRAN SUBROUTINE APT044 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE */
/*              FROM THE COEFFICIENTS OF ITS EQUATION BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = PLANE/A, B, C, D */

/* LINKAGE      CALL APT044 (RESULT, AN, BN, CN, DN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING PLANE */
/*              AN      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF COEFFICIENT OF X */
/*              BN      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF COEFFICIENT OF Y */
/*              CN      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF COEFFICIENT OF Z */
/*              DN      REAL VARIABLE CONTAINING THE VALUE */
/*                      OF CONSTANT TERM */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt044_(doublereal *result, doublereal *an, doublereal *
	bn, doublereal *cn, doublereal *dn)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal s1;
    extern /* Subroutine */ int apt077_(doublereal *, integer *), defext_(
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



    /* Parameter adjustments */
    --result;

    /* Function Body */
/* Computing 2nd power */
    d__1 = *an;
/* Computing 2nd power */
    d__2 = *bn;
/* Computing 2nd power */
    d__3 = *cn;
    s1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    if (s1 <= znumbr_1.z1em5) {
	goto L20;
    }
    s1 = sqrt(s1);
    def_1.r__[0] = *an / s1;
    def_1.r__[1] = *bn / s1;
    def_1.r__[2] = *cn / s1;
    def_1.r__[3] = *dn / s1;
    apt077_(def_1.r__, &knumbr_1.km1);
L10:
    defext_(&result[1]);
    return 0;
L20:
    idef_1.ierror = knumbr_1.k44;
    goto L10;
} /* apt044_ */

