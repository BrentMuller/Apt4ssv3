/* SCHTB.f -- translated by f2c (version 20100827).
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

static integer c__11 = 11;

/* *** SOURCE FILE : M0002860.V04   *** */

/* .....FORTRAN SUBROUTINE  ....SCHTB          8/68                    RN */
/* .....FORTRAN SUBROUTINE             SCHTB....              3/1/68   GK */

/*              FORTRAN SUBROUTINE SCHTB */

/* PURPOSE      TO IDENTIFY A POINT ON THE INPUT TABCYL WHICH IS */
/*              CLOSE TO THE POINT P. */

/* LINKAGE      CALL SCHTB (TAB) */

/* ARGUMENTS    TAB     ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                      INPUT TABCYL */
/*              P       ARRAY (IN COMMON) CONTAINING THE CANONICAL */
/*                      FORM OF THE INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          ERROR */

/* Subroutine */ int schtb_(doublereal *tab)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, n;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */







/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --tab;

    /* Function Body */
    n = (integer) ((tab[12] - 2.f) * 7.f + 14.1f);
    i__1 = n;
    for (i__ = 14; i__ <= i__1; i__ += 7) {
	j = i__;
	if ((d__1 = tab[i__] - dshar3_1.p[0], abs(d__1)) > znumbr_1.z1em2) {
	    goto L10;
	}
	if ((d__1 = tab[i__ + 1] - dshar3_1.p[1], abs(d__1)) <= 
		znumbr_1.z1em2) {
	    goto L20;
	}
L10:
	;
    }
    error_(&c__11, "SCHTB   ", (ftnlen)8);
    ldef_1.unflag = TRUE_;
    goto L9;
L20:
    tab[13] = (doublereal) j;
    ldef_1.unflag = FALSE_;
L9:
    return 0;
} /* schtb_ */

