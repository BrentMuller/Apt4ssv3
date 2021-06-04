/* CLPUT.f -- translated by f2c (version 20100827).
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
    doublereal ax4[3], cagl, cutdat[7], gamma, hi, pmove[3], ra, rc1, sagl, 
	    surd, ta[3], tak[3], te[3], tek[3], tel[3], tem[10], temp[24], ti[
	    3], tik[3], til[3], tm[3], vtem, alp, tal[3], dpmax, strtno, 
	    tlhit;
} fxcor_;

#define fxcor_1 fxcor_

struct {
    char modfer[6];
} charct_;

#define charct_1 charct_

struct {
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__10 = 10;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001053.W02   *** */

/* Subroutine */ int clput_(doublereal *atex, doublereal *atax, integer *mode)
{
    /* Initialized data */

    static integer kcldat[10] = { 0,0,1308622848,0,1308622848,2,1308622848,1,
	    0,0 };
    static logical first = TRUE_;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, ir, nr;
    extern /* Subroutine */ int bad_();
    extern integer bcdf_(char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int atape_(void);
    static char badmsg[20];
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, integer *, integer *, integer *), cprint_(char *, 
	    ftnlen);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/* ...                SYSTEM I/O FILES */



    /* Parameter adjustments */
    --atax;
    --atex;

    /* Function Body */


    if (first) {
	kcldat[0] = bcdf_("CLDA", (ftnlen)4);
	kcldat[1] = bcdf_("TA  ", (ftnlen)4);
	kcldat[8] = bcdf_("GOTO", (ftnlen)4);
	kcldat[9] = bcdf_("    ", (ftnlen)4);
	first = FALSE_;
    }

    record_(&ifxcor_1.iseqno);
    if (*mode >= 0) {
	goto L100;
    }
    if (*mode < -1) {
	goto L999;
    }
/* --OUTPUT HEADER FOR A RECORD OF CL DATA */
    kcldat[3] = ifxcor_1.iseqno;
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, kcldat, &c__10, &ir);
    goto L999;

L100:
    ifxcor_1.icl = 0;
    if (*mode == 0) {
	ifxcor_1.icl = 2;
    }
    if (*mode == 1) {
	ifxcor_1.icl = 3;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] = atex[i__];
	fxcor_1.ta[i__ - 1] = atax[i__];
/* L110: */
    }
    atape_();
    goto L999;

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER CLPUT", (ftnlen)20, (ftnlen)12);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c_n1, &c__0, "MODE", mode, (ftnlen)4);
    bad_(&c__3, &c__1, "ATEX", &atex[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "ATAX", &atax[1], (ftnlen)4);
L1999:

    return 0;
} /* clput_ */

#undef sinl
#undef cosl


