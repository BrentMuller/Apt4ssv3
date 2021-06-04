/* APT041.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000791.V03   *** */


/* .... FORTRAN SUBROUTINE              APT041               4/17/68 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR DEFINED */
/*              AS PARALLEL TO THE INTERSECTION OF TWO GIVEN PLANES */
/*              BY THE FOLLOWING APT STATEMENT */
/*              VEC = VECTOR/PARLEL,INTOF,PL1,PL2,*** */
/*              *** = POSX,POSY,POSZ,NEGX,NEGY,NEGZ */

/* LINKAGE      CALL APT041 (RESULT,PL1,PL2,MN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING VECTOR */
/*              PL1     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FIRST INPUT PLANE */
/*              PL2     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE SECOND INPUT PLANE */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = POSX  2 = POSY  3 = POSZ */
/*                      4 = NEGX  5 = NEGY  6 = NEGZ */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT078 */
/*              SUBROUTINE          CROSS */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          VNORM */
/*              REMAINDERING FUNCTION  MOD */
/*              REAL FUNCTION       SIGN */
/*              REAL FUNCTION       FLOAT */

/* Subroutine */ int apt041_(doublereal *result, doublereal *pl1, doublereal *
	pl2, integer *mn)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    extern /* Subroutine */ int apt077_(doublereal *, integer *), apt078_(
	    doublereal *, integer *), cross_(doublereal *, doublereal *, 
	    doublereal *), vnorm_(doublereal *, doublereal *);
    static doublereal dummy1;
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




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */




/* ...     TRANSFORM CANONICAL FORMS AND CHECK VALIDITY */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pl2;
    --pl1;
    --result;

    /* Function Body */
    apt077_(&pl1[1], &knumbr_1.k0);
    for (j = 1; j <= 4; ++j) {
/* L10: */
	dshar3_1.sc[j - 1] = dshar3_1.l[j - 1];
    }
    apt077_(&pl2[1], &knumbr_1.k0);

/* ...     DETERMINE VECTOR PARALLEL TO INTERSECTION OF THE TWO PLANES */

    cross_(dshar3_1.sc, dshar3_1.l, dshar3_1.l);
    vnorm_(dshar3_1.l, dshar3_1.l);

/* ...     IF VECTOR HAS WRONG ORIENTATION, REVERSE DIRECTION */

    i__ = knumbr_1.k1 + (*mn - knumbr_1.k1) % knumbr_1.k3;
    dummy1 = (doublereal) (*mn);
    d__1 = dshar3_1.l[i__ - 1] * (3.5 - dummy1);
    dshar3_1.sc[3] = d_sign(&znumbr_1.z1, &d__1);
    for (j = 1; j <= 3; ++j) {
/* L20: */
	dshar3_1.l[j - 1] = dshar3_1.sc[3] * dshar3_1.l[j - 1];
    }

    apt078_(dshar3_1.l, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt041_ */

