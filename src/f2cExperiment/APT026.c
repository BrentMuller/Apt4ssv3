/* APT026.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000776.V02   *** */

/* .....FORTRAN SUBROUTINE             APT026...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT026 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE DEFINED */
/*              AS HAVING ITS CENTER AT A GIVEN POINT AND PASSING */
/*              THROUGH A GIVEN POINT BY THE FOLLOWING APT STATEMENT */
/*              RESULT = CIRCLE/CENTER, PNT1, PNT2 */

/* LINKAGE      CALL APT026 (RESULT, PNT1, PNT2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              PNT1    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT POINT (CENTER) */
/*              PNT2    ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT POINT (ON CIRCUMFERENCE) */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          APT083 */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt026_(doublereal *result, doublereal *pnt1, doublereal 
	*pnt2)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int apt081_(doublereal *, integer *), apt083_(
	    doublereal *, integer *), defext_(doublereal *);





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




/* ...     TRANSFORM COORDINATES, CHECK VALIDITY */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pnt2;
    --pnt1;
    --result;

    /* Function Body */
    apt081_(&pnt1[1], &c__0);
    def_1.r__[0] = dshar3_1.p[0];
    def_1.r__[1] = dshar3_1.p[1];
    apt081_(&pnt2[1], &c__0);

/* ...     RADIUS,R(7),OF CIRCLE IS DISTANCE BETWEEN PNT1 AND PNT2 */

/* Computing 2nd power */
    d__1 = def_1.r__[0] - dshar3_1.p[0];
/* Computing 2nd power */
    d__2 = def_1.r__[1] - dshar3_1.p[1];
    def_1.r__[6] = sqrt(d__1 * d__1 + d__2 * d__2);
    apt083_(def_1.r__, &knumbr_1.km1);
    defext_(&result[1]);
    return 0;
} /* apt026_ */

