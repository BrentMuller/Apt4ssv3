/* NUMF.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    logical cldfg;
    integer iclcod, iclcnt, icline, iclblk, iclrcd, icltab[500]	/* was [5][
	    100] */, iptvec[9];
} cldt_;

#define cldt_1 cldt_

struct {
    char pntvct[72];
} chcldt_;

#define chcldt_1 chcldt_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__3 = 3;
static integer c__36 = 36;
static integer c__96 = 96;

/* *** SOURCE FILE : M0011451.V08   *** */


/* ...  FORTRAN SUBROUTINE     NUMF1 */

/* PURPOSE      TO DETERMINE THE NUMBER OF POINTS IN A PATERN,SCURV,SSURF */
/*              OR PREVIOUS CL DATA */

/* LINKAGE      CALL NUMF1(RESULT,PAT) */
/*              CALL NUMF2(RESULT,PAT,ARG2) */

/* ARGUMENTS    RESULT  REAL VARIABLE TO CONTAIN THE RESULTING */
/*                      NUMBER OF POINTS */
/*              PAT     ARRAY CONTAINING THE I.C.F. OF THE PATERN */
/*              OR BCD 'CLDATA' */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT094 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */

/* Subroutine */ int numf1_(doublereal *result, doublereal *pat)
{
    /* Initialized data */

    static char hclda[8] = "CLDATA  ";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, mode, iloc, isub;
    static char test[8];
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);



/* ...  REFERENCE TO LOCAL VARIABLE, IS, CHANGED TO ISIZE, */
/* ...  BECAUSE IS OCCURS IN IFXCOR.INC */

/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --pat;
    --result;

    /* Function Body */

    holfrm_(&pat[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, hclda, (ftnlen)8, (ftnlen)8) == 0) {
	goto L95;
    }
/* L1: */
    if (ckdef_(&pat[1])) {
	goto L90;
    }
    unpack_(&pat[1], &mode, &isize, &isub);
    if (mode != 26 && mode != 29 && mode != 30) {
	goto L90;
    }

/*          MOVE THE EXTERNAL CANONICAL FORM TO  CANON */

    apt094_(&c__3, &pat[1], &iloc);
    if (ckdef_(&pat[1])) {
	goto L90;
    }
    if (mode != 26) {
	goto L20;
    }

/*  NUMBER OF POINTS IS NOW IN CANON(ILOC+3)  (PATERN) */

    result[1] = canon[iloc + 2];

    return 0;

/*  COMPUTATIONS */
/*      SCURV ? */
L20:
    if (mode != 30) {
	goto L30;
    }
/*         SCURV GIVEN */
/*  OUTPUT NUMBER OF ARCS WITH >NUMF(C)< */
/* L21: */
    result[1] = canon[iloc + 2];
    return 0;
/*      SSURF ? */
L30:
    if (mode != 29) {
	goto L90;
    }
/*         SSURF GIVEN */
/*  OUTPUT NUMBER OF PATCHES WITH >NUMF(S)< */
/* L31: */
    result[1] = canon[iloc + 2];
    return 0;

/*   OUTPUT OF NUMBER OF POINTS IN LAST CUTTER PATH WITH >NUMF(CLDATA)< */

L95:
    result[1] = (doublereal) ifxcor_1.numcnt;
    return 0;

/*     USED GEOMETRY UNDEFINED OR WRONG INPUT */

L90:
    error_(&c__36, "NUMF1   ", (ftnlen)8);
L120:
    result[1] = 0.;
    return 0;

/*     ERROR DIAGNOSTIC 96 */
/*     CLDAT SECTION NOT FOUND OR NOT CLOSED */
/* L110: */
    error_(&c__96, "NUMF1   ", (ftnlen)8);
    goto L120;

} /* numf1_ */

#undef bcanon
#undef sscan
#undef canon
#undef can



/* Subroutine */ int numf2_(doublereal *result, doublereal *pat, doublereal *
	arg2)
{
    /* Initialized data */

    static char hclda[8] = "CLDATA  ";
    static char arc[8] = "ARC     ";
    static char seg[8] = "SEG     ";
    static char patch[8] = "PATCH   ";
    static char spline[8] = "SPLINE  ";
    static char crsspl[8] = "CRSSPL  ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer l;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, mode, iloc, isub, iarg2;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    static char test1[8], test2[8];
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isize;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);



/* ...  REFERENCE TO LOCAL VARIABLE, IS, CHANGED TO ISIZE, */
/* ...  BECAUSE IS OCCURS IN IFXCOR.INC */

/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */












/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --arg2;
    --pat;
    --result;

    /* Function Body */

    holfrm_(&pat[1], test1, &c__1, &c__8, &nwd, (ftnlen)8);
    holfrm_(&arg2[1], test2, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test1, hclda, (ftnlen)8, (ftnlen)8) != 0) {
	goto L1;
    }
    iarg2 = (integer) arg2[1];
    i__1 = cldt_1.iclcnt;
    for (l = 1; l <= i__1; ++l) {
	if (iarg2 == cldt_1.icltab[l * 5 - 5]) {
	    goto L100;
	}
/* L15: */
    }
    goto L110;

L1:
    if (ckdef_(&pat[1])) {
	goto L90;
    }
    unpack_(&pat[1], &mode, &isize, &isub);
    if (mode != 26 && mode != 29 && mode != 30) {
	goto L90;
    }

/*          MOVE THE EXTERNAL CANONICAL FORM TO  CANON */

    apt094_(&c__3, &pat[1], &iloc);
    if (ckdef_(&pat[1])) {
	goto L90;
    }
    if (mode == 26) {
	goto L90;
    }

/*  COMPUTATIONS */
/*      SCURV ? */
/* L20: */
    if (mode != 30) {
	goto L30;
    }
/*         SCURV GIVEN */
    if (s_cmp(test2, arc, (ftnlen)8, (ftnlen)8) == 0) {
	goto L21;
    }
    if (s_cmp(test2, seg, (ftnlen)8, (ftnlen)8) == 0) {
	goto L22;
    }
    goto L90;
/*  OUTPUT NUMBER OF ARCS WITH >NUMF(C,ARC)< */
L21:
    result[1] = canon[iloc + 2];
    return 0;
/*  OUTPUT NUMBER OF SEGMENTS WITH >NUMF(C,SEG)< */
L22:
    result[1] = canon[iloc + 6];
    if (result[1] == 0.) {
	goto L90;
    }
    return 0;
/*      SSURF ? */
L30:
    if (mode != 29) {
	goto L90;
    }
/*         SSURF GIVEN */
    if (s_cmp(test2, patch, (ftnlen)8, (ftnlen)8) == 0) {
	goto L31;
    }
/*  ERROR , IF NOT MESH TYPE */
    if (canon[iloc + 3] != 2.) {
	goto L90;
    }
    if (s_cmp(test2, spline, (ftnlen)8, (ftnlen)8) == 0) {
	goto L32;
    }
    if (s_cmp(test2, crsspl, (ftnlen)8, (ftnlen)8) == 0) {
	goto L33;
    }
    goto L90;
/*  OUTPUT NUMBER OF PATCHES WITH >NUMF(S,PATCH)< */
L31:
    result[1] = canon[iloc + 2];
    return 0;
/*  OUTPUT NUMBER OF SPLINES WITH >NUMF(S,SPLINE)< */
L32:
    result[1] = canon[iloc + 7];
    return 0;
/*  OUTPUT NUMBER OF CROSS SPLINES WITH >NUMF(S,CRSSPL)< */
L33:
    result[1] = canon[iloc + 8];
    return 0;

/*   OUTPUT OF NUMBER OF POINTS IN LAST CUTTER PATH WITH >NUMF(CLDATA)< */

/* L95: */
    result[1] = (doublereal) ifxcor_1.numcnt;
    return 0;
L100:
    result[1] = (doublereal) cldt_1.icltab[l * 5 - 4];
    return 0;

/*     USED GEOMETRY UNDEFINED OR WRONG INPUT */

L90:
    error_(&c__36, "NUMF2   ", (ftnlen)8);
L120:
    result[1] = 0.;
    return 0;

/*     ERROR DIAGNOSTIC 96 */
/*     CLDAT SECTION NOT FOUND OR NOT CLOSED */
L110:
    error_(&c__96, "NUMF2   ", (ftnlen)8);
    goto L120;

} /* numf2_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


