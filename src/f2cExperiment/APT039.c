/* APT039.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000789.V02   *** */

/* .....FORTRAN SUBROUTINE             APT039...              3/1/68   GK */

/*              FORTRAN SUBROUTINE APT039 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR */
/*              DEFINED AS THE SUM OF TWO GIVEN VECTORS BY */
/*              THE APT FOLLOWING STATEMENTS */
/*              RESULT = VECTOR/VEC1, PLUS, VEC2 */

/* LINKAGE      CALL APT039 (RESULT, VEC1, VEC2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING VECTOR */
/*              VEC1    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE FIRST INPUT VECTOR */
/*              VEC2    ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE SECOND INPUT VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          DEFEXT */
/*              LOGICAL FUNCTION    CKDEF */

/* Subroutine */ int apt039_(doublereal *result, doublereal *vec1, doublereal 
	*vec2)
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
    --vec2;
    --vec1;
    --result;

    /* Function Body */
    ldef_1.unflag = ckdef_(&vec1[1]) || ckdef_(&vec2[1]);

/* ...     RESULTANT VECTOR IS SUM OF COMPONENTS OF VEC1,VEC2 */

    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	def_1.r__[i__ - 1] = vec1[i__] + vec2[i__];
    }
    defext_(&result[1]);
    return 0;
} /* apt039_ */

