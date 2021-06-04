/* FINI.f -- translated by f2c (version 20100827).
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
    integer iamdct, ipdpl, ipt, iws, jckr, jcnt1, jcnt2, jcnt3, jcpr, jcr, 
	    jdr, jfind, jgr, jmin, jminr, jpr, jpxr, jtkf, jtr, j10, j12, j13,
	     j54, mdic;
} ishr18_;

#define ishr18_1 ishr18_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

/* Table of constant values */

static integer c__4 = 4;
static integer c__8 = 8;
static integer c_n2 = -2;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0000903.V06   *** */

/* .....FORTRAN SUBROUTINE  ....FINI           8/68                 AR,HG */
/* .....FORTRAN SUBROUTINE             FINI.....              3/1/68   GK */
/* Subroutine */ int fini_(void)
{
    /* Initialized data */

    static integer kfini[8] = { 0,0,1308622848,0,1308622848,1,1308622848,1 };
    static logical first = TRUE_;

    static doublereal x;
    static integer nr, ir;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int apt298_(integer *, doublereal *, doublereal *)
	    , tapop_(integer *, integer *), record_(integer *), ewrite_(
	    integer *, integer *, integer *, integer *, integer *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */





/* ...            SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...                SYSTEM I/O FILES */




/* ... INITIALIZE FINI RECORD */
    if (first) {
	kfini[0] = bcdf_("FINI", (ftnlen)4);
	kfini[1] = bcdf_("    ", (ftnlen)4);
	first = FALSE_;
    }

/* ...  WRITE EXFILE RECORD */

    apt298_(&c__4, &x, &x);
    record_(&kfini[3]);
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, kfini, &c__8, &ir);
    tapop_(&symfil_1.exfile, &c_n2);
    tapop_(&symfil_1.elfil2, &c_n1);
    tapop_(&symfil_1.elfil3, &c_n1);
    tapop_(&symfil_1.axfile, &c_n1);
    tapop_(&symfil_1.xnum, &c_n1);
    return 0;
} /* fini_ */

