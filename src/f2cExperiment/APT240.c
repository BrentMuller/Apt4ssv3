/* APT240.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__3 = 3;
static integer c__20101 = 20101;

/* *** SOURCE FILE : M0002734.V07   *** */

/* .....FORTRAN SUBROUTINE  ....APT240         8/68                 RN,PH */
/* .....FORTRAN SUBROUTINE             APT240...              4/16/68  GK */

/*              FORTRAN SUBROUTINE APT240 (NUMDIM) */

/* PURPOSE      TO SET THE IAFL FLAG FOR AMIND AND THE NUMDIM FLAG FOR */
/*              APT201. THIS ROUTINE CALLED BY APT201 AND GO. */
/*                FLAG SETTINGS */
/*                 IAFL = -1  NORMAL CASE */
/*                 IAFL = 0   TOOL PERP. TO PS PLANE OR PARL. TO DS OR CS */
/*                 IAFL = 1   TA PARLEL SURF. LINE ELEMENT */
/*                 NUMDIM = 0  USE 2D ROURES */
/*                 NUMDIM = 1  USE 3D ROUTES */

/* Subroutine */ int apt240_(integer *numdim)
{
    /* System generated locals */
    static doublereal equiv_2[1];

    /* Local variables */
    static integer l, m, n;
#define j11 ((integer *)equiv_2)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), dotf_(
	    doublereal *, doublereal *, doublereal *);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define real8 (equiv_2)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)




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






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*    ALIGN J11 ON DOUBLE WORD BOUNDRY. */

/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    *numdim = knumbr_1.k0;
    if (knumbr_1.k2 - ifxcor_1.mantax <= 0) {
	goto L22;
    } else {
	goto L3;
    }
L22:
    *numdim = knumbr_1.k1;
    goto L14;
L3:
    l = ifxcor_1.lsv;
    m = ifxcor_1.ics + ifxcor_1.lsv1 * (ifxcor_1.icscnt - knumbr_1.k1);
    n = ifxcor_1.ips;
    if (isv_1.isfidn[ifxcor_1.ips - 1] > knumbr_1.k2) {
	goto L7;
    }
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.ips - 1];
    dotf_(fxcor_1.temp, fxcor_1.ta, &canon[ifxcor_1.ic - 1]);
    if (abs(fxcor_1.temp[0]) < .9999999f) {
	goto L10;
    }
    isv_1.iafl[n - 1] = 0;
    isv_1.itseg[n - 1] = 1;
L23:
    ifxcor_1.it = isv_1.itseg[n - 1];
    sv_1.toolht[n * 3 - 3] = tlldat_1.tlhite[ifxcor_1.it - 1] * fxcor_1.ta[0];
    sv_1.toolht[n * 3 - 2] = tlldat_1.tlhite[ifxcor_1.it - 1] * fxcor_1.ta[1];
    sv_1.toolht[n * 3 - 1] = tlldat_1.tlhite[ifxcor_1.it - 1] * fxcor_1.ta[2];
    sv_1.toolwd[n - 1] = tlldat_1.corrad[ifxcor_1.it - 1] + tlldat_1.ri[
	    ifxcor_1.it - 1];
    goto L10;
L7:
    *numdim = knumbr_1.k1;
L10:
    if (n >= m) {
	goto L14;
    }
    n += l;
    if (n == ifxcor_1.ics) {
	l = ifxcor_1.lsv1;
    }
    ifxcor_1.ic = isv_1.icanon[n - 1];
    ifxcor_1.jsw = isv_1.isfidn[n - 1];
    if (ifxcor_1.jsw == 29 || ifxcor_1.jsw == 30) {
	goto L115;
    }
    if (ifxcor_1.jsw <= 0 || ifxcor_1.jsw > 15) {
	goto L8010;
    }
    switch (ifxcor_1.jsw) {
	case 1:  goto L110;
	case 2:  goto L110;
	case 3:  goto L111;
	case 4:  goto L111;
	case 5:  goto L115;
	case 6:  goto L112;
	case 7:  goto L112;
	case 8:  goto L112;
	case 9:  goto L115;
	case 10:  goto L112;
	case 11:  goto L113;
	case 12:  goto L115;
	case 13:  goto L115;
	case 14:  goto L115;
	case 15:  goto L115;
    }
L110:
    dotf_(fxcor_1.temp, fxcor_1.ta, &canon[ifxcor_1.ic - 1]);
    if (abs(fxcor_1.temp[0]) > 1e-7f) {
	goto L115;
    }
    isv_1.iafl[n - 1] = 0;
    goto L117;
L111:
    dotf_(fxcor_1.temp, fxcor_1.ta, &canon[ifxcor_1.ic + 2]);
    if (abs(fxcor_1.temp[0]) < .9999999f) {
	goto L115;
    }
L116:
    isv_1.iafl[n - 1] = knumbr_1.k1;
    goto L117;
L115:
    *numdim = knumbr_1.k1;
    goto L10;
L112:
    *numdim = knumbr_1.k1;
    if (abs(fxcor_1.ta[2]) == znumbr_1.z1) {
	goto L116;
    }
    goto L10;
L113:
    apt094_(&c__3, &canon[ifxcor_1.ic - 1], j11);
    --(*j11);
    dotf_(fxcor_1.temp, fxcor_1.ta, &canon[*j11 + 7]);
    if (abs(fxcor_1.temp[0]) < .9999999f) {
	goto L115;
    }
    *numdim = knumbr_1.k1;
    goto L116;
L117:
    if (isv_1.itlon[n - 1] == 0) {
	goto L120;
    }
    if (cosl[6] < 0.) {
	goto L200;
    } else if (cosl[6] == 0) {
	goto L300;
    } else {
	goto L119;
    }
L200:
    isv_1.iafl[n - 1] = knumbr_1.km1;
    goto L115;
L300:
    if (tlldat_1.tcont[5] != 0.f) {
	goto L122;
    }
    isv_1.itseg[n - 1] = 4;
    goto L23;
L120:
    isv_1.itseg[n - 1] = 1;
    goto L23;
L119:
    isv_1.itseg[n - 1] = 7;
    goto L23;
L122:
    isv_1.itseg[n - 1] = 5;
    goto L23;
L8010:
    aerr_(&c__20101, "APT240  ", (ftnlen)8);
L14:
    return 0;
} /* apt240_ */

#undef bcanon
#undef sscan
#undef canon
#undef real8
#undef sinl
#undef cosl
#undef can
#undef j11


