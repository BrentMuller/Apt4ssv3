/* UNITS.f -- translated by f2c (version 20100827).
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
    doublereal cc[15]	/* was [3][5] */, eps1[5], eps2[5], eps3[5], eps4[5], 
	    eps6[5], eps8[5], past[5], plnd[5], plnv[15]	/* was [3][5] 
	    */, rc[5], s[5], save[5], sfvct[15]	/* was [3][5] */, slx[15]	
	    /* was [3][5] */, sn[15]	/* was [3][5] */, snk[15]	/* 
	    was [3][5] */, snl[15]	/* was [3][5] */, sp[15]	/* 
	    was [3][5] */, spk[15]	/* was [3][5] */, spl[15]	/* 
	    was [3][5] */, tau[5], tau1[5], tau2[5], th[5], tn[15]	/* 
	    was [3][5] */, toolht[15]	/* was [3][5] */, toolwd[5], tp[15]	
	    /* was [3][5] */, tpk[15]	/* was [3][5] */, u1[15]	/* 
	    was [3][5] */, vndir[15]	/* was [3][5] */, vt[15]	/* 
	    was [3][5] */, z__[5], varble[5], u1k[15]	/* was [3][5] */, sk[
	    15]	/* was [3][5] */;
} sv_;

#define sv_1 sv_

struct {
    doublereal cos1[5], cplfl[5], cptst[5], csd[5], dplan[15]	/* was [3][5] 
	    */, dpmx1[5], plncs[5], plnd1[5], pltst[5], stck[5], stckn[5], 
	    stck1[5], stck2[5], tee[15]	/* was [3][5] */, tnl[15]	/* 
	    was [3][5] */;
} sv1_;

#define sv1_1 sv1_

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
    doublereal elmax, addc[24];
} addcom_;

#define addcom_1 addcom_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal tabext, ssext;
    integer iold;
} xunits_;

#define xunits_1 xunits_

struct {
    char oldmod[6];
} xunitc_;

#define xunitc_1 xunitc_

/* Table of constant values */

static integer c__91 = 91;
static integer c__1 = 1;
static integer c__4 = 4;
static integer c__10 = 10;

/* *** SOURCE FILE : M0002783.W02   *** */


/* Subroutine */ int units_(integer *imod)
{
    /* Initialized data */

    static integer w[10] = { 0,0,1308622848,0,1308622848,2,1308622848,2,0,0 };
    static logical first = TRUE_;
    static doublereal unitc[4] = { 304.8,30.48,12.,1. };

    /* Local variables */
    static integer i__, j, nr, ir, ibl, ins, nwd;
    extern integer bcdf_(char *, ftnlen);
    static integer modc[4];
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal scale;
    static integer numod;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static integer ioldmd;
    extern /* Subroutine */ int holfrm_(integer *, char *, integer *, integer 
	    *, integer *, ftnlen), cutred_(void), record_(integer *), ewrite_(
	    integer *, integer *, integer *, integer *, integer *);

/*        NEW ROUTINE TO HANDLE UNITS/ IMPLEMENTATION */

/*        IMOD= FIRST FOUR CHAR. OF UNITS/ ARGUMENT */

/*        CALLED BY NO OTHER ROUTINE */

/*        CALLS SUBROUTINES  RECORD, ERROR, CUTTER(ENTRY CUTRED) */





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */








/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...                SYSTEM I/O FILES */






    if (first) {
	w[0] = bcdf_("UNIT", (ftnlen)4);
	w[1] = bcdf_("S   ", (ftnlen)4);
	ibl = bcdf_("    ", (ftnlen)4);
	ins = bcdf_("ES  ", (ftnlen)4);
	modc[0] = bcdf_("MM  ", (ftnlen)4);
	modc[1] = bcdf_("CM  ", (ftnlen)4);
	modc[2] = bcdf_("INCH", (ftnlen)4);
	modc[3] = bcdf_("FEET", (ftnlen)4);
	first = FALSE_;
    }

    numod = *imod;
    ioldmd = bcdf_(xunitc_1.oldmod, (ftnlen)4);
    if (numod == ioldmd) {
	return 0;
    }

    for (i__ = 1; i__ <= 4; ++i__) {
/* L1: */
	if (numod == modc[i__ - 1]) {
	    goto L2;
	}
    }
    error_(&c__91, "UNITS   ", (ftnlen)8);
    return 0;

L2:
    scale = unitc[i__ - 1] / unitc[xunits_1.iold - 1];
    ioldmd = numod;
    holfrm_(&ioldmd, xunitc_1.oldmod, &c__1, &c__4, &nwd, (ftnlen)6);
    xunits_1.iold = i__;
    xunits_1.tabext *= scale;
    xunits_1.ssext *= scale;
    fxcor_1.tlhit *= scale;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L3: */
	fxcor_1.cutdat[i__ - 1] *= scale;
    }
    fxcor_1.cutdat[0] *= 2.f;
    fxcor_1.cutdat[6] *= scale;
    fxcor_1.dpmax *= scale;
    addcom_1.elmax *= scale;
    fxcor_1.hi *= scale;
    fxcor_1.ra *= scale;
    fxcor_1.rc1 *= scale;
    i__ = ifxcor_1.ips;
    j = 1;
L10:
    sv_1.tau[i__ - 1] *= scale;
    sv_1.tau1[i__ - 1] *= scale;
    sv_1.tau2[i__ - 1] *= scale;
    sv_1.eps1[i__ - 1] *= scale;
    sv_1.eps2[i__ - 1] *= scale;
    sv_1.eps3[i__ - 1] *= scale;
    sv_1.eps4[i__ - 1] *= scale;
    sv_1.eps6[i__ - 1] *= scale;
    sv_1.eps8[i__ - 1] *= scale;
    if (i__ - ifxcor_1.ics >= 0) {
	goto L5;
    } else {
	goto L4;
    }
L4:
    i__ += ifxcor_1.lsv;
    ++j;
    goto L10;
L5:
    if (j - 4 >= 0) {
	goto L7;
    } else {
	goto L6;
    }
L6:
    i__ += ifxcor_1.lsv1;
    ++j;
    goto L10;
L7:
    cutred_();
    isv_1.jent[ifxcor_1.ips - 1] = 1;
    isv_1.jent[ifxcor_1.ips + ifxcor_1.lsv - 1] = 1;
    record_(&w[3]);
    w[8] = ioldmd;
    w[9] = ibl;
    if (xunits_1.iold == 3) {
	w[9] = ins;
    }
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, w, &c__10, &ir);
    return 0;
} /* units_ */

#undef sinl
#undef cosl


