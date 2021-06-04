/* REFSYS.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__53 = 53;

/* *** SOURCE FILE : M0002856.V03   *** */

/* .....FORTRAN SUBROUTINE  ....REFSYS         8/68                    RN */
/* .....FORTRAN SUBROUTINE             REFSYS...              3/1/68   GK */

/*              FORTRAN SUBROUTINE REFSYS */
/* PURPOSE      TO DEFINE THE TRANSFORMATION MATRICES FOR */
/*              LOCAL TO BASE AND BASE TO LOCAL COORDINATE */
/*              SYSTEMS AND TO GENERATE THE ZSURF PLANE CANONICAL */
/*              FORM IN THE LOCAL SYSTEM. */

/* LINKAGE      CALL REFSYS (MATRIX) */

/* ARGUMENTS    MATRIX  ARRAY CONTAINING THE TRANSFORMATION */
/*                      MATRIX RELATING A NEW REFERENCE SYSTEM */
/*                      TO THE BASE COORDINATE SYSTEM */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT067 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          ZSURF */

/* Subroutine */ int refsys_(doublereal *matrix)
{
    static integer i__;
    extern /* Subroutine */ int apt067_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), zsurf_(
	    doublereal *);






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








/* ...     CHECK INPUT DEFINED */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --matrix;

    /* Function Body */
    if (! ckdef_(&matrix[1])) {
	goto L10;
    }
    error_(&c__53, "REFSYS  ", (ftnlen)8);
    goto L9;

/* ...     MOVE MATRIX TO A(1,2) AND THE INVERSE TO A(2,2) FOR TRANSF */

L10:
    for (i__ = 1; i__ <= 12; ++i__) {
/* L20: */
	def_1.a[i__ + 11] = matrix[i__];
    }
    apt067_(def_1.a, &def_1.a[12]);

/* ...     IF ZSURF IS IN EFFECT TRANSFORM ZSURF PLANE */

    if (ldef_1.zflag) {
	goto L30;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L25: */
	dshar3_1.sc[i__ - 1] = def_1.ref[(i__ << 1) - 2];
    }
    zsurf_(dshar3_1.sc);
L30:
    ldef_1.refflg = TRUE_;
L9:
    return 0;
} /* refsys_ */

