/* DDPLAN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000887.V04   *** */


/* .....FORTRAN SUBROUTINE             DDPLAN...              3/1/68   GK */
/* Subroutine */ int ddplan_(doublereal *srface)
{
    /* Local variables */
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal adumy;






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




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */









/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --srface;

    /* Function Body */
    ifxcor_1.ier = knumbr_1.k0;
    if (ifxcor_1.istrup == 5) {
	goto L5;
    }
    sv_1.s[ifxcor_1.is - 1] = srface[4];
    fxcor_1.tem[0] = sv_1.tn[ifxcor_1.is * 3 - 3] * srface[1] + sv_1.tn[
	    ifxcor_1.is * 3 - 2] * srface[2] + sv_1.tn[ifxcor_1.is * 3 - 1] * 
	    srface[3];
    sv_1.s[ifxcor_1.is - 1] -= sv_1.tp[ifxcor_1.is * 3 - 3] * srface[1] + 
	    sv_1.tp[ifxcor_1.is * 3 - 2] * srface[2] + sv_1.tp[ifxcor_1.is * 
	    3 - 1] * srface[3];
    if (abs(fxcor_1.tem[0]) - znumbr_1.z1em7 <= 0.) {
	goto L3;
    } else {
	goto L2;
    }
L2:
    sv_1.s[ifxcor_1.is - 1] /= fxcor_1.tem[0];
    adumy = (doublereal) isv_1.iop[ifxcor_1.is - 1];
    if (isv_1.iop[ifxcor_1.is - 1] == -1) {
	goto L4;
    }
    if (adumy * sv_1.s[ifxcor_1.is - 1] >= 0.) {
	goto L4;
    } else {
	goto L3;
    }
L3:
    ifxcor_1.ier = knumbr_1.k1;
    return 0;
L4:
    if (ifxcor_1.istrup == 4) {
	goto L6;
    }
    sv_1.spl[ifxcor_1.is * 3 - 3] = sv_1.sp[ifxcor_1.is * 3 - 3];
    sv_1.spl[ifxcor_1.is * 3 - 2] = sv_1.sp[ifxcor_1.is * 3 - 2];
    sv_1.spl[ifxcor_1.is * 3 - 1] = sv_1.sp[ifxcor_1.is * 3 - 1];
    sv_1.snl[ifxcor_1.is * 3 - 3] = sv_1.sn[ifxcor_1.is * 3 - 3];
    sv_1.snl[ifxcor_1.is * 3 - 2] = sv_1.sn[ifxcor_1.is * 3 - 2];
    sv_1.snl[ifxcor_1.is * 3 - 1] = sv_1.sn[ifxcor_1.is * 3 - 1];
L6:
    sv_1.sp[ifxcor_1.is * 3 - 3] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.sp[ifxcor_1.is * 3 - 2] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.sp[ifxcor_1.is * 3 - 1] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 1];
L5:
    sv_1.sn[ifxcor_1.is * 3 - 3] = srface[1];
    sv_1.sn[ifxcor_1.is * 3 - 2] = srface[2];
    sv_1.sn[ifxcor_1.is * 3 - 1] = srface[3];
    return 0;
} /* ddplan_ */

#undef sinl
#undef cosl

