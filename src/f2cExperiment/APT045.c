/* APT045.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0000795.V03   *** */

/* .....FORTRAN SUBROUTINE             APT045...              3/1/68   GK */

/*                                                6/70      RW */

/*              FORTRAN SUBROUTINE APT045 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A PLANE */
/*              DEFINED AS PASSING THROUGH THREE POINTS BY THE */
/*              FOLLOWING APT STATEMENT */
/*              RESULT = PLANE/PN1, PN2, PN3 */

/* LINKAGE      CALL APT045 (RESULT, PN1, PN2, PN3) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING PLANE */
/*              PN1     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FIRST INPUT POINT */
/*              PN2     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE SECOND INPUT POINT */
/*              PN3     ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE THIRD INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT073 */
/*              LOGICAL FUNCTION    CKDEF */

/* Subroutine */ int apt045_(doublereal *result, doublereal *pn1, doublereal *
	pn2, doublereal *pn3)
{
    static integer i__;
    extern /* Subroutine */ int apt073_(doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int print_(integer *, doublereal *, integer *), 
	    defext_(doublereal *);





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






/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */







/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --pn3;
    --pn2;
    --pn1;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&pn2[1]) || ckdef_(&pn3[1]);

/* ...     VECTORS FROM PN1 TO PN2 AND PN3 */

    for (i__ = 1; i__ <= 3; ++i__) {
	dshar3_1.sc[i__ - 1] = pn1[i__] - pn2[i__];
/* L10: */
	dshar3_1.sc[i__ + 2] = pn1[i__] - pn3[i__];
    }

/* ...     USE APT073 TO FIND PLANE CONTAINING VECTORS AND PN1 */

    apt073_(&result[1], dshar3_1.sc, &dshar3_1.sc[3], &pn1[1]);
    if (ldef_1.unflag || idef_1.ierror != 0) {
	defext_(&result[1]);
    }
    if (ldef_1.prnton) {
	print_(&c__3, &result[1], &c__1);
    }
    return 0;
} /* apt045_ */

