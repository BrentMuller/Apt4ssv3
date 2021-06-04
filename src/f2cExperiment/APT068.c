/* APT068.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

/* *** SOURCE FILE : M0000818.V03   *** */


/* .....FORTRAN SUBROUTINE             APT068...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT068 */

/* PURPOSE      TO GENERATE A MATRIX DEFINED AS THREE PLANES BY */
/*              THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/PL1, PL2, PL3 */

/* LINKAGE      CALL APT068 (RESULT, PL1, PL2, PL3) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              PL1     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE FIRST INPUT PLANE */
/*              PL2     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE SECOND INPUT PLANE */
/*              PL3     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE THIRD INPUT PLANE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */

/* Subroutine */ int apt068_(doublereal *result, doublereal *pl1, doublereal *
	pl2, doublereal *pl3)
{
    static integer i__;
    static doublereal t[12];
    extern /* Subroutine */ int apt067_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */







    /* Parameter adjustments */
    --pl3;
    --pl2;
    --pl1;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 4; ++i__) {
	t[i__ - 1] = pl1[i__];
	t[i__ + 3] = pl2[i__];
/* L10: */
	t[i__ + 7] = pl3[i__];
    }
    t[3] = -t[3];
    t[7] = -t[7];
    t[11] = -t[11];
    ldef_1.unflag = ckdef_(def_1.r__) || ckdef_(&def_1.r__[4]) || ckdef_(&
	    def_1.r__[8]);
    apt067_(&result[1], t);

    return 0;
} /* apt068_ */

