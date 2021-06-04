/* CLDAT.f -- translated by f2c (version 20100827).
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

static integer c__94 = 94;
static integer c__95 = 95;

/* *** SOURCE FILE : M0011486.W01   *** */


/* Subroutine */ int cldat_(integer *arg1, integer *arg2, integer *arg3, 
	integer *arg4)
{
    /* Initialized data */

    static integer icldm = 100;
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1;
    static doublereal equiv_0[1];

    /* Local variables */
    static integer i__, j, k, ii;
#define clr (equiv_0)
    extern integer bcdf_(char *, ftnlen);
#define nclr ((integer *)equiv_0)
    static integer nomo, norm, ityp;
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    static integer clwrd;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer start, iclidx, nptvct[18]	/* was [2][9] */;


/*   PURPOSE: TO CONTROL AND STORE CLDAT PARAMETERS AND INDICATORS. */

/*     ICLTAB   (1,X)  INDEX OF THE CLDAT SECTION. */
/*     ICLTAB   (2,X)  NUMBER OF POINTS IN THE CLDAT SECTION. */
/*     ICLTAB   (3,X)  FORM OF STORAGE ON EXFILE (TP,TA,TV,...). */
/*     ICLTAB   (4,X)  FIRST EXFILE BLOCK  OF THE CLDAT SECTION. */
/*     ICLTAB   (5,X)  FIRST EXFILE RECORD OF THE CLDAT SECTION. */
/*     CLDFG           FLAG TRUE = A CLDAT-SECTION IS OPENED, COUNTING */
/*                     OF THE POINTS IN ATAPE. */
/*     ICLCNT          POINTER TO THE LAST ICLTAB ENTRY. */
/*     ICLINE          ICLTAB INDEX. */
/*     ICLIDX          ICLTAB INDEX. */

/*     ICLCOD = ICLTAB   (3,X)    ;   ICLBLK = ICLTAB   (4,X) */
/*     ICLRCD = ICLTAB   (5,X) */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */











    /* Parameter adjustments */
    --arg4;
    --arg3;
    --arg2;
    --arg1;

    /* Function Body */



    if (first) {
	start = bcdf_("STAR", (ftnlen)4);
	clwrd = bcdf_("CLDA", (ftnlen)4);
	norm = bcdf_("NORM", (ftnlen)4);
	nomo = bcdf_("NOMO", (ftnlen)4);
	first = FALSE_;
    }
    for (i__ = 1; i__ <= 9; ++i__) {
	nptvct[(i__ << 1) - 2] = bcdf_(chcldt_1.pntvct + (i__ - 1 << 3), (
		ftnlen)4);
/* L2: */
    }
    if (arg2[1] != clwrd) {
	goto L10;
    }
    ityp = arg4[1];
    if (ityp == norm) {
	goto L75;
    }
    if (ityp != start && ityp != nomo) {
	goto L5;
    }
    goto L100;

/* CLDAT/TP,TA,TV,...ETC. */

L5:
    cldt_1.iclcod = 1;
    j = ityp;
    goto L85;

L10:
    if (arg1[1] != 1) {
	goto L80;
    }
    nclr[0] = arg2[1];
    nclr[1] = arg2[2];
    j = arg4[1];
    if (ityp != start) {
	goto L50;
    }

/* CLDAT/START,IDX,......... */

    iclidx = (integer) (*clr);
    i__1 = cldt_1.iclcnt;
    for (cldt_1.icline = 1; cldt_1.icline <= i__1; ++cldt_1.icline) {
	if (cldt_1.icltab[cldt_1.icline * 5 - 5] != iclidx) {
	    goto L20;
	}
/* WARNING DIAGNOSTIC 94 */
/* MULTIPLE DEFINED CLDAT-SECTION. FORMER SECTION DELETED. */
	error_(&c__94, "CLDAT   ", (ftnlen)8);
	goto L40;
L20:
	;
    }
/* IS ICLTAB FILLED ? */
    if (cldt_1.iclcnt < icldm) {
	goto L30;
    }
/* ERROR DIAGNOSTIC 95 */
/* ARRAY ICLTAB FILLED. USE A FORMER DEFINED INDEX OR REDIMENSION ARRAY. */
    error_(&c__95, "CLDAT   ", (ftnlen)8);
    goto L100;
L30:
    ++cldt_1.iclcnt;
    cldt_1.icline = cldt_1.iclcnt;
L40:
    cldt_1.cldfg = TRUE_;
    cldt_1.iclcod = 1;
    cldt_1.icltab[cldt_1.icline * 5 - 5] = iclidx;
    cldt_1.icltab[cldt_1.icline * 5 - 4] = 0;
    cldt_1.icltab[cldt_1.icline * 5 - 3] = cldt_1.iclcod;
    cldt_1.icltab[cldt_1.icline * 5 - 2] = cldt_1.iclblk + 1;
    cldt_1.icltab[cldt_1.icline * 5 - 1] = cldt_1.iclrcd + 3;
    ifxcor_1.numcnt = 0;
    if (j == 0) {
	goto L100;
    }
    goto L85;

/* CLDAT/NOMORE,IDX */

L50:
    ii = (integer) (*clr);
/* WARNING DIAGNOSTIC 94 */
/* CLDAT INDEXES ARE DIFFERENT. FIRST INDEX REMAINS VALID. */
/* L70: */
    if (ii != iclidx) {
	error_(&c__94, "CLDAT   ", (ftnlen)8);
    }
    cldt_1.icltab[cldt_1.icline * 5 - 4] += ifxcor_1.numcnt;
    cldt_1.cldfg = FALSE_;

/* CLDAT/NORMAL */

L75:
    cldt_1.iclcod = 0;
    goto L100;

L80:
    if (cldt_1.iclcod == 0) {
	goto L100;
    }
    j = arg2[1];
L85:
    k = arg4[1];
    for (ii = 1; ii <= 9; ++ii) {
	if (j != nptvct[(ii << 1) - 2] && k != nptvct[(ii << 1) - 2]) {
	    goto L90;
	}
	if (cldt_1.iclcod % cldt_1.iptvec[ii - 1] != 0) {
	    cldt_1.iclcod *= cldt_1.iptvec[ii - 1];
	}
	if (cldt_1.cldfg) {
	    cldt_1.icltab[cldt_1.icline * 5 - 3] = cldt_1.iclcod;
	}
L90:
	;
    }

/* OUTPUT CLDAT COMMAND ON EXFILE */

L100:
    apt299_(&arg1[1], &arg2[1], &arg3[1], &arg4[1]);

    return 0;
} /* cldat_ */

#undef nclr
#undef clr


