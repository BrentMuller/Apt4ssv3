/* APT085.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000832.V04   *** */


/* .....FORTRAN SUBROUTINE             APT085...              5/1/68   GK */

/*              FORTRAN SUBROUTINE APT085 */

/* PURPOSE      TO SET THE REFSYS FLAG, REFFLG, .FALSE. AND */
/*              SET UP THE CANONICAL FORM OF THE ZSURF PLANE */
/*              EQUATION IN THE LOCAL COORDINATE SYSTEM EQUAL */
/*              TO THE CANONICAL FORM IN THE BASE SYSTEM. */

/* LINKAGE      CALL APT085 */

/* ARGUMENTS    NONE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          ZSURF */

/* Subroutine */ int apt085_(void)
{
    static integer i__;
    static doublereal sc[4];
    extern /* Subroutine */ int zsurf_(doublereal *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */







/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */



    ldef_1.refflg = FALSE_;
    if (ldef_1.zflag) {
	goto L20;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L10: */
	sc[i__ - 1] = def_1.ref[(i__ << 1) - 1];
    }
    zsurf_(sc);
L20:
    return 0;
} /* apt085_ */

