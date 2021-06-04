/* APT103.f -- translated by f2c (version 20100827).
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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__85 = 85;
static integer c__86 = 86;

/* *** SOURCE FILE : M0002811.V05   *** */

/* ...  FORTRAN SUBROUTINE APT103                  6/70      RW */

/*                          FORTRAN SUBROUTINE APT103 */


/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A BOUNDED GEOMETRY */
/*              OBJECT DEFINED BY THE FOLLOWING APT STATEMENT. */

/*              OBJCTN=OBJECT/BOUND1,BOUND2,...,BOUNDI */

/* CALLING SEQUENCE  CALL APT103(OBJCTN,BOUNDN,M) */

/* ARGUMENTS    OBJCTN    ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                        BOUNDED GEOMETRY OBJECT */

/*              BOUNDN    ARRAY CONTAINING THE CANONICAL FORM OF THE */
/*                        BOUNDED SURFACE OR OBJECT IN \HE OPERAND LIST */
/*                        CURRENTLY BEING PROCESSED */

/*              M         INDICATOR IDENTIFYING THE POSITION OF BOUNDN */
/*                        IN THE OPERAND LIST */

/*                        TAKES THE FOLLOWING VALUES. */
/*                        3  IF BOUNDN IS THE LAST ARGUMENT */

/*                        2  IF BOUNDN IS ANYTHING BUT THE FIRST */
/*                           OR LAST ARGUMENT */

/*                        1  IF PROCESSING THE FIRST ARGUMENT OF A */
/*                           STATEMENT WITH TWO OR MORE ARGUMENTS */

/*                        0  IF PROCESSING THE FIRST ARGUMENT OF A */
/*                           STATEMENT WITH ONLY ONE ARGUMENT. */

/* CALLED BY    NONE */

/* SUBSIDIARIES TYPE              ENTRY */

/*              INTEGER FUNCTION  ADDRSS */
/*              SUBROUTINE        ERROR */
/*              SUBROUTINE        INCAN */
/*              SUBROUTINE        PRINT */
/*              SUBROUTINE        UNPACK */

/* RESTRICTIONS NONE */

/* DIAGNOSTICS  ERROR CODE  COMMENT */
/*              85          REFERENCED ELEMENT NOT PROPERLY DEFINED. */

/*              86          BOUNDED GEOMETRY ELEMENT HAS BEEN REDEFINED */
/*                          WITH A DIFFERENT NUMBER OF ARGUMENTS. */



/* Subroutine */ int apt103_(doublereal *objctn, doublereal *boundn, integer *
	m)
{
    /* Initialized data */

    static char dlr[1] = "$";

    /* System generated locals */
    static doublereal equiv_4[4];

    /* Local variables */
    static integer n;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, mode, isub;
    static logical err85, err86;
    static char test[1];
    extern /* Subroutine */ int incan_(integer *);
#define canon ((doublereal *)&_BLNK__1)
    static integer iobjn;
    extern /* Subroutine */ int undef_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isize;
    extern logical ckstr_(doublereal *);
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), print_(
	    integer *, doublereal *, integer *);
#define ttest (equiv_4)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern integer addrss_(doublereal *);
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(logical *, char *, integer *, integer *, 
	    integer *, ftnlen);
    static integer iobjsz;
#define dlrtst ((logical *)equiv_4)




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */






/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*                                                                   *CD* */
    /* Parameter adjustments */
    --boundn;
    --objctn;

    /* Function Body */
/*                                                                   *CD* */


    if (*m > 1) {
	goto L2;
    }
    n = 0;
    err85 = FALSE_;
    err86 = FALSE_;
    unpack_(&objctn[1], &mode, &iobjsz, &isub);
    if (*m == 0) {
	*m = 3;
    }
L2:
    n += 2;

/* ...  MAKE SURE OBJCTN IS NOT REDEFINED ERRONEOUSLY. */

    if (n > iobjsz) {
	goto L20;
    }

/* ...  MAKE SURE BOUNDN IS PROPERLY DEFINED. */

    unpack_(&boundn[1], &mode, &isize, &isub);
    if (ckstr_(&boundn[1]) || isub != 0) {
	goto L10;
    }

/*        * STORE NAME IN CANONICAL FORM */
    objctn[n - 1] = boundn[isize + 1];

/* ...  IF BOUNDN IS AN UNASSIGNED NESTED ARGUMENT, GENERATE DIAGNOSTIC. */

    *ttest = objctn[n - 1];
    holfrm_(dlrtst, test, &c__1, &c__1, &nwd, (ftnlen)1);
    if (*(unsigned char *)test == *(unsigned char *)&dlr[0]) {
	err85 = TRUE_;
    }

/* ...  DETERMINE INDEX FOR BOUNDN */
    iobjn = (addrss_(&boundn[1]) - addrss_(_BLNK__1.com)) / idef_1.kwrdsz + 1;
    if (ldef_1.canflg) {
	incan_(&iobjn);
    }
    objctn[n] = (doublereal) (iobjn - idef_1.iblk1);

L5:
    if (*m == 3) {
	goto L30;
    }
    return 0;

/* ...  ERROR 85:  REFERENCED ELEMENT NOT PROPERLY DEFINED. */

L10:
    undef_(&objctn[n - 1]);
    objctn[n] = 0.;
    err85 = TRUE_;
    goto L5;

/* ...  ERROR 86:  BOUNDED GEOMETRY ELEMENT HAS BEEN REDEFINED WITH */
/*     A DIFFERENT NUMBER OF OPERANDS. */

L20:
    err86 = TRUE_;
    if (*m != 3) {
	goto L40;
    }
L30:
    if (n != iobjsz) {
	err86 = TRUE_;
    }

    if (ldef_1.prnton) {
	print_(&c__3, &objctn[1], &c__1);
    }
    if (err85) {
	error_(&c__85, "APT103  ", (ftnlen)8);
    }
    if (err86) {
	error_(&c__86, "APT103  ", (ftnlen)8);
    }
    if (err86 || err85) {
	ldef_1.bnderr = TRUE_;
    }
L40:
    return 0;
} /* apt103_ */

#undef dlrtst
#undef bcanon
#undef ttest
#undef sscan
#undef canon
#undef can


