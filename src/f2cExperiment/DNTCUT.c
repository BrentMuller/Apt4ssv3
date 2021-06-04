/* DNTCUT.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

/* Table of constant values */

static integer c__0 = 0;

/* *** SOURCE FILE : M0000894.V07   *** */


/* .....FORTRAN SUBROUTINES        DNTCUT & DNTCUH  ...       3/1/68   GK */

/* Subroutine */ int dntcut_(void)
{
    /* Initialized data */

    static char ppword[8] = "DNTCUT  ";

    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    static integer ippwrd[2];







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







    if (hold_1.jhldfg == 0) {
	goto L1;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = 7;
    ++hold_1.ithcnt;
    return 0;

L1:
/* ...  DONT OUTPUT CUTTER CENTERS ON CLTAPE */
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + 4, (ftnlen)4);
    apt299_(&c__0, ippwrd, &c__0, &c__0);
    ifxcor_1.icut = knumbr_1.k1;
    return 0;
} /* dntcut_ */





/* .....FORTRAN SUBROUTINE        DNTCUH...                3/1/68   GK */

/* Subroutine */ int dntcuh_(void)
{
    /* Initialized data */

    static char ppword[8] = "DNTCUT  ";

    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    integer *);
    static integer ippwrd[2];







/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */







/* ...  DONT OUTPUT CUTTER CENTERS ON CLTAPE */
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + 4, (ftnlen)4);
    apt299_(&c__0, ippwrd, &c__0, &c__0);
    ifxcor_1.icut = knumbr_1.k1;
    return 0;
} /* dntcuh_ */

