/* APT065.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000815.V02   *** */

/* .....FORTRAN SUBROUTINE             APT065...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT065 */

/* PURPOSE      TO GENERATE A MATRIX DEFINED AS A POINT AND TWO */
/*              VECTORS BY THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/PT,V1,V2 */

/* LINKAGE      CALL APT065 (RESULT, PT, V1, V2) */

/* ARGUMENTS    RESULT ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                     THE RESULTING MATRIX */
/*              PT     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                     THE INPUT POINT */
/*              V1     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                     THE FIRST INPUT VECTOR */
/*              V2     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                     THE SECOND INPUT VECTOR */

/* SUBSIDIARIES TYPE               ENTRY */
/*              SUBROUTINE         CROSS */
/*              SUBROUTINE         DOTF */
/*              SUBROUTINE         VNORM */
/*              LOGICAL FUNCTION   ZVECT */
/*              LOGICAL FUNCTION   CKDEF */

/* Subroutine */ int apt065_(doublereal *result, doublereal *pt, doublereal *
	v1, doublereal *v2)
{
    static integer j;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), apt067_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --v2;
    --v1;
    --pt;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&pt[1]) || ckdef_(&v1[1]) || ckdef_(&v2[1]);

/* ...     CALCULATE A VECTOR DEFINING Z,Y,X-AXIS */

    cross_(&v1[1], &v2[1], &dshar3_1.t1[8]);

    cross_(&dshar3_1.t1[8], &v1[1], &dshar3_1.t1[4]);
    for (j = 1; j <= 3; ++j) {
/* L10: */
	dshar3_1.t1[j - 1] = v1[j];
    }

/* ...  CALCULATE DISTANCES FROM ORIGIN TO YZPLANE,ZXPLANE,AND XYPLANE */

    for (j = 1; j <= 9; j += 4) {
	vnorm_(&dshar3_1.t1[j - 1], &dshar3_1.t1[j - 1]);
	dotf_(&dshar3_1.t1[j + 2], &dshar3_1.t1[j - 1], &pt[1]);
/* L20: */
	dshar3_1.t1[j + 2] = -dshar3_1.t1[j + 2];
    }

/* ...     INVERSE MATRIX */

    apt067_(&result[1], dshar3_1.t1);
    return 0;
} /* apt065_ */

