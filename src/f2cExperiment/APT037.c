/* APT037.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000787.V02   *** */

/* .....FORTRAN SUBROUTINE             APT037...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT037 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR DEFINED */
/*              AS A GIVEN SCALAR TIMES A GIVEN VECTOR OR POINT */
/*              BY THE FOLLOWING APT STATEMENT */
/*              RESULT  VECTOR/SCA, TIMES, VEC */

/* LINKAGE      CALL APT037 (RESULT, SCA, VEC) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING VECTOR */
/*              SCA     REAL VARIABLE CONTAINING THE VALUE OF */
/*                      THE SCALAR */
/*              VEC     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT VECTOR OR POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          DEFEXT */

/* Subroutine */ int apt037_(doublereal *result, doublereal *sca, doublereal *
	vec)
{
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






/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */

    /* Parameter adjustments */
    --vec;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&vec[1]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	def_1.r__[i__ - 1] = *sca * vec[i__];
    }
    defext_(&result[1]);
    return 0;
} /* apt037_ */

