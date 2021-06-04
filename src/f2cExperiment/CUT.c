/* CUT.f -- translated by f2c (version 20100827).
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
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
} hblock_;

#define hblock_1 hblock_

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

static integer c__1 = 1;
static integer c__27 = 27;

/* *** SOURCE FILE : M0000713.V09   *** */

/* .....FORTRAN SUBROUTINE  ....CUT            8/68                 PH,HG */
/* .....FORTRAN SUBROUTINE             CUT   ...              3/1/68   GK */
/* Subroutine */ int cut_(void)
{
    /* Initialized data */

    static char ppword[4] = "CUT ";
    static char mesage[32] = " ...LOCATION WHERE CUT RESUMES..";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, i4;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt233_(void), apt299_(integer *, integer *, 
	    integer *, integer *);
    static integer msgary[10], ippwrd[2];






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/* ... */


    if (hold_1.jhldfg == 0) {
	goto L1;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = 6;
    ++hold_1.ithcnt;
    return 0;

L1:
/* ...  OUTPUT CUTTER CENTERS ON EXFILE */
    if (ifxcor_1.icut <= 0) {
	goto L20;
    } else {
	goto L10;
    }

/* ...     WRITE ON EXFILE A MESSAGE INDICATING START OF CUT SEQUENCE */
L10:
    msgary[0] = 10;
    msgary[1] = 32;
    for (i__ = 1; i__ <= 8; ++i__) {
	i4 = i__ << 2;
	i__1 = i4 - 4;
	msgary[i__ + 1] = bcdf_(mesage + i__1, i4 - i__1);
/* L15: */
    }
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_("    ", (ftnlen)4);
    apt299_(&c__1, ippwrd, &c__27, msgary);
    ifxcor_1.icl = knumbr_1.k3;
    ifxcor_1.icut = 0;
    apt233_();
L20:
    return 0;
} /* cut_ */




/* Subroutine */ int cuth_(void)
{
    /* Initialized data */

    static char ppword[4] = "CUT ";
    static char mesage[32] = " ...LOCATION WHERE CUT RESUMES..";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, i4;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt233_(void), apt299_(integer *, integer *, 
	    integer *, integer *);
    static integer msgary[10], ippwrd;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/* ... */



/* L1: */
/* ...  OUTPUT CUTTER CENTERS ON EXFILE */
    if (ifxcor_1.icut <= 0) {
	goto L20;
    } else {
	goto L10;
    }

/* ...     WRITE ON EXFILE A MESSAGE INDICATING START OF CUT SEQUENCE */
L10:
    msgary[0] = 10;
    msgary[1] = 32;
    for (i__ = 1; i__ <= 8; ++i__) {
	i4 = i__ << 2;
	i__1 = i4 - 4;
	msgary[i__ + 1] = bcdf_(mesage + i__1, i4 - i__1);
/* L15: */
    }
    ippwrd = bcdf_(ppword, (ftnlen)4);
    apt299_(&c__1, &ippwrd, &c__27, msgary);
    ifxcor_1.icl = knumbr_1.k3;
    ifxcor_1.icut = 0;
    apt233_();
L20:
    return 0;
} /* cuth_ */

