/* APT200.f -- translated by f2c (version 20100827).
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
    integer iafl[5], icanon[5], index[5], indir__[5], iop[5], iopset[5], ipl[
	    5], isfidn[5], isftyp[5], isigcr[5], isvfl[5], itlon[5], itseg[5],
	     iunfl[5], jent[5], jiops[5], jtlflg[5], jtn[5], ju1[5], limfl[5],
	     itsegk[5];
} isv_;

#define isv_1 isv_

struct {
    integer ifar[5], ifl4[5], j20[5], j21[5], j22[5], j23[5], j50[5], j51[5], 
	    notan[5], jph[5];
} isv1_;

#define isv1_1 isv1_

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
    integer iaerfg, npctpt;
    doublereal pctpts[60]	/* was [3][20] */, pctpln[4], errpts[9]	/* 
	    was [3][3] */;
} aercom_;

#define aercom_1 aercom_

/* Table of constant values */

static integer c__20001 = 20001;

/* *** SOURCE FILE : M0002819.V04   *** */

/* .....FORTRAN SUBROUTINE  ....APT200         8/68                    PH */
/* .....FORTRAN SUBROUTINE             APT200...              3/1/68   GK */
/* Subroutine */ int apt200_(doublereal *hmod, doublereal *adress, doublereal 
	*xntsct)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), apt234_(
	    doublereal *, doublereal *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*     25. COMMON FOR AERR INFORMATION */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...  ESTABLISHES CHECK SURFACE PARAMETERS FOR EACH CHECK SURFACE */
/* ...  ADVANCE THE CHECK SURFACE COUNTER */
    /* Parameter adjustments */
    --adress;

    /* Function Body */
    if (ifxcor_1.iaerr == 1) {
	goto L1000;
    }
    ifxcor_1.icscnt += knumbr_1.k1;
    if (ifxcor_1.numsfs >= ifxcor_1.icscnt + knumbr_1.k2) {
	goto L1;
    }
    aercom_1.iaerfg = 1;
    aerr_(&c__20001, "APT200  ", (ftnlen)8);
    goto L1000;
L1:
    ifxcor_1.is = ifxcor_1.ics + (ifxcor_1.icscnt - knumbr_1.k1) * 
	    ifxcor_1.lsv1;
    apt234_(hmod, &adress[1]);
    if (ifxcor_1.iaerr <= 0) {
	goto L5;
    } else {
	goto L1000;
    }
/* ...  SET IFL4=1 IF PSTAN,0 IF TANTO */
L5:
    if ((i__1 = isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k4) < 0) {
	goto L30;
    } else if (i__1 == 0) {
	goto L10;
    } else {
	goto L20;
    }
L10:
    isv1_1.ifl4[ifxcor_1.is - 1] = 0;
    goto L30;
L20:
    isv1_1.ifl4[ifxcor_1.is - 1] = knumbr_1.k1;
/* ...  SET CS INTERSECTION COUNTER */
L30:
    isv1_1.ifar[ifxcor_1.is - 1] = (integer) (*xntsct);
    ldef_1.jcs = TRUE_;
L1000:
    return 0;
} /* apt200_ */

