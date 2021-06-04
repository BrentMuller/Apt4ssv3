/* APT015.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0000765.V02   *** */

/* .....FORTRAN SUBROUTINE             APT015...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT015 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE DEFINED */
/*              AS TANGENT TO A CIRCLE AND PASSING THROUGH A */
/*              GIVEN POINT BY THE FOLLOWING APT STATEMENT */
/*              RESULT = LINE/POINT1, ****, TANTO, CIRC1, */
/*                       **** = RIGHT OR LEFT */

/* LINKAGE      CALL APT015 (RESULT, PNT, N, CIRC1) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING LINE */
/*              PNT     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT POINT */
/*              N       INTEGER EQUIVALENT OF THE MODIFIER */
/*                      1 = RIGHT     2 = LEFT */
/*              CIRC1   ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT CIRCLE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT016 */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          APT083 */

/* Subroutine */ int apt015_(doublereal *result, doublereal *pnt, integer *mn,
	 doublereal *circ1)
{
    static integer i__;
    extern /* Subroutine */ int apt016_(doublereal *, integer *, doublereal *,
	     integer *, doublereal *), apt081_(doublereal *, integer *), 
	    apt083_(doublereal *, integer *);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/* ...       TRANSFORM CANONICAL FORM TO LOCAL COORDINATE SYSTEM */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --circ1;
    --pnt;
    --result;

    /* Function Body */
    apt081_(&pnt[1], &c__0);


/* ...       MAKE THE POINT A ZERO RADIUS VERTICAL CYLINDER */

    for (i__ = 3; i__ <= 7; ++i__) {
/* L10: */
	dshar3_1.p[i__ - 1] = def_1.r__[i__ - 1];
    }


/* ...       TRANSFORM TO BASE SYSTEM AND CALL APT016 TO GET LINE */

    apt083_(dshar3_1.p, &knumbr_1.km1);
    apt016_(&result[1], mn, def_1.r__, mn, &circ1[1]);
    return 0;
} /* apt015_ */

