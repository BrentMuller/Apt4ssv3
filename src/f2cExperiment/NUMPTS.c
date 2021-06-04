/* NUMPTS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000940.V04   *** */

/* .....FORTRAN SUBROUTINE             NUMPTS...              3/1/68   GK */
/* Subroutine */ int numpts_(doublereal *xnumbr)
{
    /* Initialized data */

    static char ppword[8] = "NUMPTS  ";

    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt299_(integer *, integer *, integer *, 
	    doublereal *);
    static integer ippwrd[2];






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */






/* ...  USE THIS AS THE MAXIMUM NUMBER OF CUTTER CENTERS ON ONE */
/* ...  ELEMENTARY CUT SEQUENCE */
    ippwrd[0] = bcdf_(ppword, (ftnlen)4);
    ippwrd[1] = bcdf_(ppword + 4, (ftnlen)4);
    apt299_(&c__1, ippwrd, &c__1, xnumbr);
    ifxcor_1.nmpnts = (integer) (*xnumbr);
    return 0;
} /* numpts_ */

