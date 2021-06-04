/* APT071.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0003393.V02   *** */

/* .....FORTRAN SUBROUTINE              APT071 */

/*              FORTRAN SUBROUTINE APT071 */

/* PURPOSE      TO GENERATE A MATRIX FOR MIRRORING OF */
/*              A PLANE (LINE) BY THE FOLLOWING APT STATEMENT */
/*              RESULT = MATRIX/ MIRROR,PLN */
/*              RESULT = MATRIX/ MIRROR,LN */

/* LINKAGE      CALL APT071 (RESULT,PLN) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING MATRIX */
/*              PLN     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      INPUT ARRAY */

/* SUBSIDIARY  TYPE                ENTRY */
/*             LOGICAL FUNCTION    CKDEF */

/* Subroutine */ int apt071_(doublereal *result, doublereal *pln)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static integer i__, j;
    static doublereal scc;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int undef_(doublereal *), error_(integer *, char *
	    , ftnlen), print_(integer *, doublereal *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





    /* Parameter adjustments */
    --pln;
    result -= 5;

    /* Function Body */
    if (ckdef_(&pln[1])) {
	goto L99;
    }
    pln[4] = -pln[4];
/* Computing 2nd power */
    d__1 = pln[1];
/* Computing 2nd power */
    d__2 = pln[2];
/* Computing 2nd power */
    d__3 = pln[3];
    scc = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    result[j + (i__ << 2)] = pln[i__] * -2. * pln[j] / scc;
	    if (i__ == j) {
		result[j + (i__ << 2)] += 1.;
	    }
/* L10: */
	}
    }
    pln[4] = -pln[4];
    if (ldef_1.prnton) {
	print_(&c__3, &result[5], &c__1);
    }
    return 0;
L99:
    error_(&c__1, "APT071  ", (ftnlen)8);
    undef_(&result[5]);
    return 0;
} /* apt071_ */

