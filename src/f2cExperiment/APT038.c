/* APT038.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000788.V02   *** */

/* .....FORTRAN SUBROUTINE             APT038...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT038 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR DEFINED */
/*              AS THE CROSS PRODUCT OF TWO VECTORS BY THE FOLLOWING */
/*              APT STATEMENT */
/*              RESULT = VECTOR/VEC1, CROSS, VEC2 */

/* LINKAGE      CALL APT038 (RESULT, VEC1, VEC2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING VECTOR */
/*              VEC1    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT VECTOR */
/*              VEC2    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DEFEXT */
/*              REMAINDERING FUNCTION MOD */

/* Subroutine */ int apt038_(doublereal *result, doublereal *vec1, doublereal 
	*vec2)
{
    static integer i__, j, k;
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





/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --vec2;
    --vec1;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar3_1.sc[i__ - 1] = vec1[i__];
/* L10: */
	dshar3_1.sc[i__ + 2] = vec2[i__];
    }
    ldef_1.unflag = ckdef_(dshar3_1.sc) || ckdef_(&dshar3_1.sc[3]);
    for (k = 1; k <= 3; ++k) {
	i__ = k % knumbr_1.k3 + knumbr_1.k1;
	j = i__ % knumbr_1.k3 + knumbr_1.k1;
/* L20: */
	def_1.r__[k - 1] = dshar3_1.sc[i__ - 1] * dshar3_1.sc[j + 2] - 
		dshar3_1.sc[j - 1] * dshar3_1.sc[i__ + 2];
    }
    defext_(&result[1]);
    return 0;
} /* apt038_ */

