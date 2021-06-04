/* APT053.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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

/* *** SOURCE FILE : M0000803.V03   *** */


/* .....FORTRAN SUBROUTINE             APT053...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT053 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A SPHERE */
/*              DEFINED AS PASSING THROUGH FOUR GIVEN POINTS */
/*              BY THE FOLLOWING APT STATEMENT */
/*              RESULT = SPHERE/PT1, PT2, PT3, PT4 */

/* LINKAGE      CALL APT053 (RESULT, PT1, PT2, PT3, PT4) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING SPHERE */
/*              PT1     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FIRST INPUT POINT */
/*              PT2     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE SECOND INPUT POINT */
/*              PT3     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE THIRD INPUT POINT */
/*              PT4     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FOURTH INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT075 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt053_(doublereal *result, doublereal *pt1, doublereal *
	pt2, doublereal *pt3, doublereal *pt4)
{
    /* Initialized data */

    static integer k57 = 57;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
#define pt ((doublereal *)&dshar3_1 + 21)
#define st ((doublereal *)&dshar3_1 + 37)
    extern /* Subroutine */ int apt075_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int defext_(doublereal *);





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




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --pt4;
    --pt3;
    --pt2;
    --pt1;
    --result;

    /* Function Body */
/* ...     MOVE INPUTS TO SCRATCH STORAGE, CHECK INPUT */

    ldef_1.unflag = ckdef_(&pt4[1]);
    for (i__ = 1; i__ <= 3; ++i__) {
	st[i__ * 3 - 3] = pt1[i__];
	st[i__ * 3 - 2] = pt2[i__];
	st[i__ * 3 - 1] = pt3[i__];
/* L10: */
	ldef_1.unflag = ldef_1.unflag || ckdef_(&st[i__ - 1]);
    }

/* ...     FORM EQUATION COEFFICIENTS */

    for (i__ = 1; i__ <= 3; ++i__) {
	pt[(i__ << 2) - 1] = znumbr_1.z0;

	for (j = 1; j <= 3; ++j) {
	    pt[i__ + (j << 2) - 5] = st[j + i__ * 3 - 4] - pt4[i__];
/* L20: */
/* Computing 2nd power */
	    d__1 = st[i__ + j * 3 - 4];
/* Computing 2nd power */
	    d__2 = pt4[j];
	    pt[(i__ << 2) - 1] = pt[(i__ << 2) - 1] + d__1 * d__1 - d__2 * 
		    d__2;
	}
/* L30: */
/* Computing 2nd power */
	d__1 = pt4[i__];
	def_1.r__[3] += d__1 * d__1;
    }

/* ...     SOLVE FOR SPHERE EQUATION COEFFS. */

    apt075_(def_1.r__, pt);

/* ...     CHECK FOR COPLANAR POINTS */

    if (idef_1.ierror >= knumbr_1.k1) {
	idef_1.ierror = k57;
    }

/* ...     COMPUTE RADIUS TERM */

    for (i__ = 1; i__ <= 3; ++i__) {
	def_1.r__[i__ - 1] /= znumbr_1.z2;
/* L40: */
	def_1.r__[3] += def_1.r__[i__ - 1] * (def_1.r__[i__ - 1] - 
		znumbr_1.z2 * pt4[i__]);
    }
    def_1.r__[3] = sqrt(def_1.r__[3]);
    defext_(&result[1]);
    return 0;
} /* apt053_ */

#undef st
#undef pt


