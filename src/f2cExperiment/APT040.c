/* APT040.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000790.V03   *** */

/* .....FORTRAN SUBROUTINE  ....APT040         8/68                    RN */
/* .....FORTRAN SUBROUTINE             APT040...              3/1/68   GK */
/*                                      6/69      RW */

/*              FORTRAN SUBROUTINE APT040 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A VECTOR */
/*              DEFINED AS THE NORMALIZATION OF A GIVEN VECTOR */
/*              BY THE FOLLOWING APT STATEMENT */
/*              RESULT = VECTOR/UNIT, VC */

/* LINKAGE      CALL APT040 (RESULT, VC) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM */
/*                      OF THE RESULTING VECTOR */
/*              VC      ARRAY CONTAINING THE CANONICAL FORM */
/*                      OF THE INPUT VECTOR */

/* SUBSIDIARIES TYPE                ENTRY */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          VNORM */

/* Subroutine */ int apt040_(doublereal *result, doublereal *vc)
{
    static integer mode;
    extern logical ckdef_(doublereal *);
    extern /* Subroutine */ int undef_(doublereal *), print_(integer *, 
	    doublereal *, integer *), vnorm_(doublereal *, doublereal *), 
	    unpack_(doublereal *, integer *, integer *, integer *);
    static integer idummy;



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






    /* Parameter adjustments */
    --vc;
    --result;

    /* Function Body */
    if (ckdef_(&vc[1])) {
	goto L10;
    }
    vnorm_(&vc[1], &result[1]);
    if (ldef_1.prnton) {
	goto L20;
    }
    return 0;
L10:
    undef_(&result[1]);
    return 0;
/* ...  IF PRINTON WANT TO PRINT ONLY IF CALLED BY PART PROGRAM. */
L20:
    unpack_(&result[1], &mode, &idummy, &idummy);
    if (mode == 20) {
	print_(&c__3, &result[1], &c__1);
    }
    return 0;
} /* apt040_ */

