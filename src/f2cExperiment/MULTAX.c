/* MULTAX.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__4 = 4;

/* *** SOURCE FILE : M0001497.V03   *** */

/* .....FORTRAN SUBROUTINE                MULTAX...            8/1/68  AR */
/* Subroutine */ int multax_(doublereal *donoff)
{
    /* Initialized data */

    static char doff[4] = "OFF ";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer nwd;
    extern integer bcdf_(char *, ftnlen);
    static char test[4];
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    doublereal *), holfrm_(doublereal *, char *, integer *, integer *,
	     integer *, ftnlen);
    static integer ppword[2];






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/* ...  ALL CUTTER CENTERS WILL BE OUTPUT WITH TOOL AXIS VECTORS */
/* IF DONOFF .NE. 'OFF' */
    ppword[0] = bcdf_("MULT", (ftnlen)4);
    ppword[1] = bcdf_("AX  ", (ftnlen)4);

    apt299_(&c__1, ppword, &c__2, donoff);
    ifxcor_1.mulout = 1;
    holfrm_(donoff, test, &c__1, &c__4, &nwd, (ftnlen)4);
    if (s_cmp(test, doff, (ftnlen)4, (ftnlen)4) == 0) {
	ifxcor_1.mulout = 0;
    }
    return 0;
} /* multax_ */

