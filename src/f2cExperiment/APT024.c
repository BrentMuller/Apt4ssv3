/* APT024.f -- translated by f2c (version 20100827).
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

struct {
    integer kcomt, kcomf;
    logical cilprt;
    integer kcbn;
} const_;

#define const_1 const_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static integer c__1 = 1;
static integer c__18 = 18;
static integer c__19 = 19;

/* *** SOURCE FILE : M0000695.V06   *** */


/*              FORTRAN SUBROUTINE APT024 */

/* PURPOSE      TO SET XECUTION FLAGS SPECIFIED BY THE PPOPTN STATEMENT. */

/* LINKAGE      CALL APT024(IARG) */

/* ARGUMENT     IARG  =1, REFMOT ON */
/*                    =2, REFMOT OFF */
/*                    =3, ALTMLT ON */
/*                    =4, ALTMLT OFF */

/* Subroutine */ int apt024_(integer *iarg)
{
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), cprint_(char *, ftnlen);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    switch (*iarg) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
    }
L1:
    ldef_1.refmot = TRUE_;
    goto L9;
L2:
    ldef_1.refmot = FALSE_;
    goto L9;
L3:
    ldef_1.altmlt = TRUE_;
    goto L9;
L4:
    ldef_1.altmlt = FALSE_;
    goto L9;
L5:
    const_1.cilprt = TRUE_;
    cform_("0 CILPRT TURNED ON", darray_1.darray, &c__1, &c__18, (ftnlen)18, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L9;
L6:
    const_1.cilprt = FALSE_;
    cform_("0 CILPRT TURNED OFF", darray_1.darray, &c__1, &c__19, (ftnlen)19, 
	    (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L9;
L9:
    return 0;
} /* apt024_ */

