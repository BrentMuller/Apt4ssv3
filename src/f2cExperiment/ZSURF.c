/* ZSURF.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__49 = 49;

/* *** SOURCE FILE : M0002876.V03   *** */


/* .....FORTRAN SUBROUTINE             ZSURF....              6/10/68 EAN */

/*              FORTRAN SUBROUTINE ZSURF */

/* PURPOSE      TO DEFINE A PLANE WHICH WILL GIVE THE Z COORDINATE */
/*              OF A POINT WHICH HAS NOT BEEN EXPLICITY DEFINED, BY */
/*              THE FOLLOWING APT STATEMENT */
/*                   ZSURF/P */

/* LINKAGE      CALL ZSURF (PL) */

/* ARGUMENTS    PL      ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT PLANE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              REAL FUNCTION       ABS */
/*              SUBROUTINE          ERROR */

/* Subroutine */ int zsurf_(doublereal *pl)
{
    /* Initialized data */

    static doublereal zlit1 = .1;

    static integer i__;
    extern /* Subroutine */ int apt077_(doublereal *, integer *), error_(
	    integer *, char *, ftnlen);






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



/* ...  13. IBRKPT BLOCK. USED FOR DYNDMP BREAKPNTS. INTEGER EQUIVALENCED */
/* ...      TO ISV(30). */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pl;

    /* Function Body */



/* ...     CHECK VALIDITY AND TRANSFORM */

    apt077_(&pl[1], &knumbr_1.k0);
    if (ldef_1.unflag) {
	goto L30;
    }
/* .... ERROR WHEN ZSURF IS PARALEL TO ZAXIS OF LOCAL SYSTEM */
    if (abs(dshar3_1.l[2]) < zlit1) {
	goto L30;
    }
    ldef_1.zflag = FALSE_;

/* ...     MOVE ZSURF INTO REF ARRAY */

    for (i__ = 1; i__ <= 4; ++i__) {
	def_1.ref[(i__ << 1) - 2] = pl[i__];
/* L10: */
	def_1.ref[(i__ << 1) - 1] = dshar3_1.l[i__ - 1];
    }

L20:
    return 0;
L30:
    error_(&c__49, "ZSURF   ", (ftnlen)8);
    goto L20;
} /* zsurf_ */

