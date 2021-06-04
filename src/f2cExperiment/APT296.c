/* APT296.f -- translated by f2c (version 20100827).
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
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__8 = 8;

/* *** SOURCE FILE : M0000706.W01   *** */

/* Subroutine */ int apt296_(void)
{
    /* Initialized data */

    static integer kholdp[8] = { 0,0,1308622848,0,1308622848,1,1308622848,3 };
    static logical first = TRUE_;

    static integer ir, nr;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, integer *, integer *, integer *);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* ...            SYSTEM I/O FILE NAMES */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...                SYSTEM I/O FILES */




/*     THIS SUBROUTINE WRITES THE HOLDPP */
/*      RECORD ON EXFILE AT THE BEGINNING OF MACRO OUT PUT */

    if (first) {
	kholdp[0] = bcdf_("HOLD", (ftnlen)4);
	kholdp[1] = bcdf_("PP  ", (ftnlen)4);
	first = FALSE_;
    }
    record_(&kholdp[3]);
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, kholdp, &c__8, &ir);
    return 0;
} /* apt296_ */


/* ---    APT297 ENTERED TO WRITE END RECORD FOR MACRO ON EXFILE */
/* Subroutine */ int apt297_(void)
{
    /* Initialized data */

    static integer kholdp[8] = { 0,0,1308622848,0,1308622848,1,1308622848,4 };
    static logical first = TRUE_;

    static integer ir, nr;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, integer *, integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */

/* ...            SYSTEM I/O FILE NAMES */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...                SYSTEM I/O FILES */




/*     THIS SUBROUTINE WRITES THE HOLDPP */
/*      RECORD ON EXFILE AT THE BEGINNING OF MACRO OUT PUT */

    if (first) {
	kholdp[0] = bcdf_("HOLD", (ftnlen)4);
	kholdp[1] = bcdf_("PP  ", (ftnlen)4);
	first = FALSE_;
    }
    record_(&kholdp[3]);
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, kholdp, &c__8, &ir);
    return 0;
} /* apt297_ */

