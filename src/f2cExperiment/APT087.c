/* APT087.f -- translated by f2c (version 20100827).
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
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

/* *** SOURCE FILE : M0000834.V02   *** */

/* .....FORTRAN SUBROUTINE             APT087...              5/1/68   GK */

/*              FORTRAN SUBROUTINE APT087 */

/* PURPOSE      TO GENERATE THE POLAR COORDINATES OF A GIVEN */
/*              POINT. */

/* LINKAGE      CALL APT087 (RESULT, RECT) */

/* ARGUMENTS    RESULT (1)          DISTANCE FROM ORIGIN TO INPUT POINT */
/*              RESULT (2)          ANGLE IN DEGREES BETWEEN INPUT POINT */
/*                                  AND POSITIVE X-AXIS */
/*              RECT                ARRAY CONTAINING THE CANONICAL FORM */
/*                                  OF INPUT POINT IN RECTANGULAR */
/*                                  COORDINATES */

/* SUBSIDIARIES TYPE                ENTRY */
/*              REAL FUNCTION       ATAN2 */
/*              LOGICAL FUNCTION    CKDEF */
/*              REAL FUNCTION       SQRT */

/* Subroutine */ int apt087_(doublereal *result, doublereal *rect)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), atan2(doublereal, doublereal);

    /* Local variables */
    extern logical ckdef_(doublereal *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */







/* ...     CHANGE RECTANGULAR COORDINATES TO POLAR - RESULT(1)=RAD, */
/*        RESULT(2) = ANGLE */

/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */



    /* Parameter adjustments */
    --rect;
    --result;

    /* Function Body */
    dshar3_1.sc[0] = rect[1];
    dshar3_1.sc[1] = rect[2];
    ldef_1.unflag = ckdef_(dshar3_1.sc);
/* Computing 2nd power */
    d__1 = dshar3_1.sc[0];
/* Computing 2nd power */
    d__2 = dshar3_1.sc[1];
    result[1] = sqrt(d__1 * d__1 + d__2 * d__2);
    result[2] = znumbr_1.z0;
    if (result[1] != znumbr_1.z0) {
	result[2] = atan2(dshar3_1.sc[1], dshar3_1.sc[0]) / znumbr_1.degrad;
    }
    return 0;
} /* apt087_ */

