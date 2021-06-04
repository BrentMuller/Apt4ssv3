/* APT042.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000792.V03   *** */

/* .....FORTRAN SUBROUTINE ....APT042              8/68                SR */
/* .... FORTRAN SUBROUTINE              APT042               5/6/68 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR WHICH */
/*              MAKES A GIVEN ANGLE WITH A GIVEN LINE DEFINED BY */
/*              THE FOLLOWING APT STATEMENT */
/*              VEC = VECTOR/ATANGL,VAL,LN,*** */
/*              *** = POSX,POSY,NEGX,NEGY */

/* LINKAGE      CALL APT042(RESULT,VAL,LN,MN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING VECTOR */
/*              VAL     MEASURE (IN DEGREES) OF THE GIVEN ANGLE */
/*              LN      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE GIVEN LINE */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = POSX  2 = POSY  4 = NEGX  5 = NEGY */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT077 */
/*              SUBROUTINE          APT078 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       DSIGN */
/*              REAL FUNCTION       DCOS */

/* Subroutine */ int apt042_(doublereal *result, doublereal *val, doublereal *
	ln, integer *mn)
{
    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    static doublereal va, cosa, sina;
    extern /* Subroutine */ int apt077_(doublereal *, integer *), apt078_(
	    doublereal *, integer *), defext_(doublereal *);




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



/* ...     TRANSFORM CANONICAL FORM AND CHECK VALIDITY */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --ln;
    --result;

    /* Function Body */
    apt077_(&ln[1], &knumbr_1.k0);

    va = *val * znumbr_1.degrad;
    sina = sin(va);
    cosa = cos(va);

/* ...     DETERMINE REQUIRED VECTOR */
    dshar3_1.v[0] = dshar3_1.l[0] * sina + dshar3_1.l[1] * cosa;
    dshar3_1.v[1] = dshar3_1.l[1] * sina - dshar3_1.l[0] * cosa;

/* ...     IF VECTOR HAS WRONG ORIENTATION, REVERSE DIRECTION */

    if (*mn == knumbr_1.k1 && dshar3_1.v[0] >= znumbr_1.z0 || *mn == 
	    knumbr_1.k2 && dshar3_1.v[1] >= znumbr_1.z0 || *mn == knumbr_1.k4 
	    && dshar3_1.v[0] < znumbr_1.z0 || *mn == knumbr_1.k5 && 
	    dshar3_1.v[1] < znumbr_1.z0) {
	goto L10;
    }
    dshar3_1.v[0] = -dshar3_1.v[0];
    dshar3_1.v[1] = -dshar3_1.v[1];
L10:
    dshar3_1.v[2] = znumbr_1.z0;

    apt078_(dshar3_1.v, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt042_ */

