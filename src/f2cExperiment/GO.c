/* GO.f -- translated by f2c (version 20100827).
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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

/* Table of constant values */

static integer c__0 = 0;
static integer c__20201 = 20201;

/* *** SOURCE FILE : M0004132.V07   *** */



/* Subroutine */ int go_(doublereal *hmod, doublereal *adress)
{
    extern /* Subroutine */ int go2_(doublereal *, doublereal *), libsrevert_(
	    void), aerr_(integer *, char *, ftnlen);
    static integer idum;
    extern doublereal apt211_(integer *, char *, integer *, ftnlen);
    extern /* Subroutine */ int apt241_(void);
    static doublereal dummy;



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */



/*      IF(JDS) CALL APT211(0,'NOCS    ',IDUM) */
    /* Parameter adjustments */
    --adress;

    /* Function Body */
    if (ldef_1.jds) {
	dummy = apt211_(&c__0, "nocs    ", &idum, (ftnlen)8);
    }
/* -IBM-      CALL APT241 */
    if (ifxcor_1.iaerr == 1) {
	goto L10;
    }
/* -VAX-ESTABLISH CONDITION HANDLER */
    apt241_();
L20:
    if (ifxcor_1.ictdef != 0 && ifxcor_1.igoto == 0) {
	aerr_(&c__20201, "GO      ", (ftnlen)8);
    }
    if (ifxcor_1.iaerr == 1) {
	goto L10;
    }
    go2_(hmod, &adress[1]);
    if (ifxcor_1.iaerr == 1) {
	goto L20;
    }
/* -VAX- REVERT TO DEFAULT CONDITION HANDLER */
/*   10 CALL LIB$REVERT */
L10:
    libsrevert_();
    return 0;
} /* go_ */

