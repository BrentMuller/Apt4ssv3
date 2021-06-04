/* APT014.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0000764.V02   *** */

/* .....FORTRAN SUBROUTINE             APT014...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT014 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE */
/*              DEFINED AS PASSING THROUGH TWO SYMBOLIC POINTS */
/*              BY THE FOLLOWING APT STATEMENT */
/*                   RESULT = LINE/P1, P2 */

/* LINKAGE      CALL APT014 (RESULT, P1, P2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN CANONICAL FORM OF THE */
/*                      RESULTING LINE */
/*              P1      ARRAY CONTAINING CANONICAL FORM OF THE */
/*                      FIRST INPUT POINT */
/*              P2      ARRAY CONTAINING CANONICAL FORM OF THE */
/*                      SECOND INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT081 */
/*              SUBROUTINE          APT012 */

/* Subroutine */ int apt014_(doublereal *result, doublereal *p1, doublereal *
	p2)
{
    extern /* Subroutine */ int apt012_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), apt081_(doublereal *, 
	    integer *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */







/* ...     CHECK INPUT VALIDITY AND TRANSFORM CANONICAL FORMS */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --p2;
    --p1;
    --result;

    /* Function Body */
    apt081_(&p1[1], &c__0);
    dshar3_1.sc[0] = dshar3_1.p[0];
    dshar3_1.sc[1] = dshar3_1.p[1];
    apt081_(&p2[1], &c__0);

/* ...     LINE THRU TWO POINTS FROM APT012 */

    apt012_(&result[1], dshar3_1.sc, &dshar3_1.sc[1], dshar3_1.p, &dshar3_1.p[
	    1]);
    return 0;
} /* apt014_ */

