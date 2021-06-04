/* APT001.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000752.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT001         8/68                 SR */

/* LINKAGE      CALL APT001 (RESULT) */

/* ARGUMENT     RESULT  ARRAY CONTAINING THE X AND Y CO- */
/*              ORDINATES OF THE INPUT POINT. */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          APT081 */

/* Subroutine */ int apt001_(doublereal *result)
{
    static integer i__;
    extern /* Subroutine */ int defext_(doublereal *), transf_(doublereal *, 
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
    --result;

    /* Function Body */
    if (ldef_1.unflag) {
	goto L40;
    }

    result[3] = znumbr_1.z0;

/* ...     TEST FOR ZSURF */

    if (ldef_1.zflag) {
	goto L30;
    }

/* ...     TEST FOR REFSYS */

    i__ = knumbr_1.k1;
    if (ldef_1.refflg) {
	i__ = knumbr_1.k2;
    }
    if (def_1.ref[i__ + 3] == znumbr_1.z0) {
	goto L10;
    }
    result[3] = (def_1.ref[i__ + 5] - def_1.ref[i__ - 1] * result[1] - 
	    def_1.ref[i__ + 1] * result[2]) / def_1.ref[i__ + 3];

/* ...     CONVERT TO BASE SYSTEM */

L30:
    transf_(dshar3_1.p, &result[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.km1)
	    ;
L40:
    defext_(&result[1]);

    return 0;
L10:
    ldef_1.unflag = TRUE_;
    goto L40;
} /* apt001_ */

