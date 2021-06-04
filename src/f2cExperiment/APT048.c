/* APT048.f -- translated by f2c (version 20100827).
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

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0000798.V03   *** */


/* .....FORTRAN SUBROUTINE             APT048...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT048 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE */
/*              DEFINED AS PERPENDICULAR TO A GIVEN PLANE */
/*              AND PASSING THROUGH TWO GIVEN POINTS BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = PLANE/PERPTO, PL, PN1, PN2 */

/* LINKAGE      CALL APT048 (RESULT, PL, PN1, PN2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING PLANE */
/*              PL      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT PLANE */
/*              PN1     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FIRST INPUT POINT */
/*              PN2     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE SECOND INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT035 */
/*              SUBROUTINE          APT073 */

/* Subroutine */ int apt048_(doublereal *result, doublereal *pl, doublereal *
	pn1, doublereal *pn2)
{
    extern /* Subroutine */ int apt035_(doublereal *, doublereal *, 
	    doublereal *), apt073_(doublereal *, doublereal *, doublereal *, 
	    doublereal *), print_(integer *, doublereal *, integer *);



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







/* ...     DEFINE A VECTOR IN THE DESIRED PLANE */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --pn2;
    --pn1;
    --pl;
    --result;

    /* Function Body */
    apt035_(&def_1.ln1[1], &pn2[1], &pn1[1]);

/* ...     DEFINE THE PLANE CONTAINING A POINT, THE DEFINED VECTOR, AND A */
/* ...     NORMAL VECTOR TO THE ORIGINAL PLANE */

    apt073_(&result[1], &pl[1], &def_1.ln1[1], &pn1[1]);
    if (ldef_1.prnton) {
	print_(&c__3, &result[1], &c__1);
    }
    return 0;
} /* apt048_ */

