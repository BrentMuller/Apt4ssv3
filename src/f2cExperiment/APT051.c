/* APT051.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000801.V02   *** */

/* .....FORTRAN SUBROUTINE             APT051...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT051 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A SPHERE */
/*              DEFINED AS HAVING ITS CENTER AT A GIVEN POINT */
/*              AND PASSING THROUGH A GIVEN POINT BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = SPHERE/CENTER, PN1, PN2 */

/* LINKAGE      CALL APT051 (RESULT, PN1, PN2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN CANONICAL FORM OF THE */
/*                      RESULTING SPHERE */
/*              PN1     ARRAY CONTAINING CANONICAL FORM OF THE */
/*                      INPUT POINT (CENTER) */
/*              PN2     ARRAY CONTAINING CANONICAL FORM OF THE */
/*                      INPUT POINT (ON SPHERE) */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DEFEXT */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt051_(doublereal *result, doublereal *pn1, doublereal *
	pn2)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
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






/* ...     COMPUTE RADIUS OF RESULT, MOVE PN1 TO CENTER */


/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --pn2;
    --pn1;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	def_1.r__[i__ - 1] = pn1[i__];
/* L10: */
/* Computing 2nd power */
	d__1 = def_1.r__[i__ - 1] - pn2[i__];
	def_1.r__[3] += d__1 * d__1;
    }
    ldef_1.unflag = ckdef_(def_1.r__) || ckdef_(&pn2[1]);

    def_1.r__[3] = sqrt(def_1.r__[3]);
    defext_(&result[1]);
    return 0;
} /* apt051_ */

