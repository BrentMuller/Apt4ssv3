/* DDQUAD.f -- translated by f2c (version 20100827).
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
    doublereal a, b, c__, cendis, cmove[3], com1, com4, dir[3], dp, dpe, 
	    dpcnt, dpi, dpl, dp1, d1, d2a, flipck, fwd[3], ogle[3], p1[3], p2[
	    3], rdrn, refpnt[3], tangl, tes[3], tew[3], uvec[3], u2[3], v[3], 
	    vl, zl, zlnorm[3], zlpnt[3], zl1, param[6], r__[6], savpar[4], 
	    seg[9], slope, sqroot, unn, upp, vint, vnn, vpp;
} dshar4_;

#define dshar4_1 dshar4_

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

/* *** SOURCE FILE : M0000888.V05   *** */


/* .....FORTRAN SUBROUTINE             DDQUAD...              3/1/68   GK */
/* Subroutine */ int ddquad_(doublereal *srface)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__, e;
    static integer i__;
    extern /* Subroutine */ int quad_(void);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  4.  DSHARE BLOCK 4  *** */





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




    /* Parameter adjustments */
    --srface;

    /* Function Body */
    ifxcor_1.ier = 0;
    if (ifxcor_1.istrup == 5) {
	goto L1015;
    }
    if (ifxcor_1.jsw == 5 || ifxcor_1.jsw == 9) {
	goto L5;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
/* L1: */
	fxcor_1.tem[i__ - 1] = srface[i__];
    }
/* Computing 2nd power */
    d__1 = sv_1.tn[ifxcor_1.is * 3 - 3];
/* Computing 2nd power */
    d__2 = sv_1.tn[ifxcor_1.is * 3 - 2];
/* Computing 2nd power */
    d__3 = sv_1.tn[ifxcor_1.is * 3 - 1];
    dshar4_1.a = znumbr_1.z2 * (fxcor_1.tem[5] * sv_1.tn[ifxcor_1.is * 3 - 1] 
	    * sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.tem[6] * sv_1.tn[
	    ifxcor_1.is * 3 - 3] * sv_1.tn[ifxcor_1.is * 3 - 2] + fxcor_1.tem[
	    4] * sv_1.tn[ifxcor_1.is * 3 - 2] * sv_1.tn[ifxcor_1.is * 3 - 1]) 
	    + d__1 * d__1 * fxcor_1.tem[0] + d__2 * d__2 * fxcor_1.tem[1] + 
	    d__3 * d__3 * fxcor_1.tem[2];
    dshar4_1.b = (fxcor_1.tem[0] * sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.tem[
	    6] * sv_1.tn[ifxcor_1.is * 3 - 2] + fxcor_1.tem[5] * sv_1.tn[
	    ifxcor_1.is * 3 - 1]) * sv_1.tp[ifxcor_1.is * 3 - 3] + (
	    fxcor_1.tem[6] * sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.tem[1] * 
	    sv_1.tn[ifxcor_1.is * 3 - 2] + fxcor_1.tem[4] * sv_1.tn[
	    ifxcor_1.is * 3 - 1]) * sv_1.tp[ifxcor_1.is * 3 - 2] + (
	    fxcor_1.tem[5] * sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.tem[4] * 
	    sv_1.tn[ifxcor_1.is * 3 - 2] + fxcor_1.tem[2] * sv_1.tn[
	    ifxcor_1.is * 3 - 1]) * sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.tn[
	    ifxcor_1.is * 3 - 3] * fxcor_1.tem[7] + sv_1.tn[ifxcor_1.is * 3 - 
	    2] * fxcor_1.tem[8] + sv_1.tn[ifxcor_1.is * 3 - 1] * fxcor_1.tem[
	    9];
/* Computing 2nd power */
    d__1 = sv_1.tp[ifxcor_1.is * 3 - 3];
/* Computing 2nd power */
    d__2 = sv_1.tp[ifxcor_1.is * 3 - 2];
/* Computing 2nd power */
    d__3 = sv_1.tp[ifxcor_1.is * 3 - 1];
    dshar4_1.c__ = znumbr_1.z2 * (fxcor_1.tem[5] * sv_1.tp[ifxcor_1.is * 3 - 
	    1] * sv_1.tp[ifxcor_1.is * 3 - 3] + fxcor_1.tem[6] * sv_1.tp[
	    ifxcor_1.is * 3 - 3] * sv_1.tp[ifxcor_1.is * 3 - 2] + fxcor_1.tem[
	    4] * sv_1.tp[ifxcor_1.is * 3 - 2] * sv_1.tp[ifxcor_1.is * 3 - 1] 
	    + sv_1.tp[ifxcor_1.is * 3 - 3] * fxcor_1.tem[7] + sv_1.tp[
	    ifxcor_1.is * 3 - 2] * fxcor_1.tem[8] + sv_1.tp[ifxcor_1.is * 3 - 
	    1] * fxcor_1.tem[9]) + d__1 * d__1 * fxcor_1.tem[0] + d__2 * d__2 
	    * fxcor_1.tem[1] + d__3 * d__3 * fxcor_1.tem[2] + fxcor_1.tem[3];
    goto L1000;
L5:
    dshar4_1.a = sv_1.tn[ifxcor_1.is * 3 - 3] * sv_1.tn[ifxcor_1.is * 3 - 3] 
	    + sv_1.tn[ifxcor_1.is * 3 - 2] * sv_1.tn[ifxcor_1.is * 3 - 2] + 
	    sv_1.tn[ifxcor_1.is * 3 - 1] * sv_1.tn[ifxcor_1.is * 3 - 1];
    fxcor_1.tem[0] = sv_1.tp[ifxcor_1.is * 3 - 3] - srface[1];
    fxcor_1.tem[1] = sv_1.tp[ifxcor_1.is * 3 - 2] - srface[2];
    fxcor_1.tem[2] = sv_1.tp[ifxcor_1.is * 3 - 1] - srface[3];
    dshar4_1.b = fxcor_1.tem[0] * sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.tem[
	    1] * sv_1.tn[ifxcor_1.is * 3 - 2] + fxcor_1.tem[2] * sv_1.tn[
	    ifxcor_1.is * 3 - 1];
    e = fxcor_1.tem[0] * fxcor_1.tem[0] + fxcor_1.tem[1] * fxcor_1.tem[1] + 
	    fxcor_1.tem[2] * fxcor_1.tem[2];
    if (ifxcor_1.jsw == 9) {
	goto L10;
    }
    dshar4_1.c__ = e - srface[4] * srface[4];
    goto L1000;
L10:
    fxcor_1.tem[3] = srface[7] * srface[7];
    fxcor_1.tem[4] = dshar4_1.a;
    dshar4_1.a = sv_1.tn[ifxcor_1.is * 3 - 3] * srface[4] + sv_1.tn[
	    ifxcor_1.is * 3 - 2] * srface[5] + sv_1.tn[ifxcor_1.is * 3 - 1] * 
	    srface[6];
    d__ = fxcor_1.tem[0] * srface[4] + fxcor_1.tem[1] * srface[5] + 
	    fxcor_1.tem[2] * srface[6];
    dshar4_1.b = dshar4_1.a * d__ - fxcor_1.tem[3] * dshar4_1.b;
    dshar4_1.a = dshar4_1.a * dshar4_1.a - fxcor_1.tem[4] * fxcor_1.tem[3];
    dshar4_1.c__ = d__ * d__ - fxcor_1.tem[3] * e;
    quad_();
    if (ifxcor_1.ier <= 0) {
	goto L20;
    } else {
	goto L3000;
    }
L20:
    if ((fxcor_1.tem[0] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 
	    3]) * srface[4] + (fxcor_1.tem[1] + sv_1.s[ifxcor_1.is - 1] * 
	    sv_1.tn[ifxcor_1.is * 3 - 2]) * srface[5] + (fxcor_1.tem[2] + 
	    sv_1.s[ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 1]) * srface[
	    6] <= 0.) {
	goto L25;
    } else {
	goto L1011;
    }

/*     **SOLUTION INVALID** */

L25:
    if (fxcor_1.surd < 0.) {
	goto L30;
    } else if (fxcor_1.surd == 0) {
	goto L50;
    } else {
	goto L40;
    }
L30:
    if (isv_1.iop[ifxcor_1.is - 1] <= 0) {
	goto L40;
    } else {
	goto L50;
    }
L40:
    sv_1.s[ifxcor_1.is - 1] = fxcor_1.surd;
    fxcor_1.surd = znumbr_1.z0;
    goto L20;
L50:
    ifxcor_1.ier = 1;
    goto L3000;
L1000:
    quad_();
/* L1010: */
    if (ifxcor_1.ier == 1) {
	goto L3000;
    }
L1011:
    if (ifxcor_1.istrup == 4) {
	goto L1012;
    }
    sv_1.spl[ifxcor_1.is * 3 - 3] = sv_1.sp[ifxcor_1.is * 3 - 3];
    sv_1.spl[ifxcor_1.is * 3 - 2] = sv_1.sp[ifxcor_1.is * 3 - 2];
    sv_1.spl[ifxcor_1.is * 3 - 1] = sv_1.sp[ifxcor_1.is * 3 - 1];
    sv_1.snl[ifxcor_1.is * 3 - 3] = sv_1.sn[ifxcor_1.is * 3 - 3];
    sv_1.snl[ifxcor_1.is * 3 - 2] = sv_1.sn[ifxcor_1.is * 3 - 2];
    sv_1.snl[ifxcor_1.is * 3 - 1] = sv_1.sn[ifxcor_1.is * 3 - 1];
L1012:
    sv_1.sp[ifxcor_1.is * 3 - 3] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.sp[ifxcor_1.is * 3 - 2] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.sp[ifxcor_1.is * 3 - 1] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 1];
L1015:
    if (ifxcor_1.jsw == 5 || ifxcor_1.jsw == 9) {
	goto L2000;
    }
    fxcor_1.tem[0] = srface[1] * sv_1.sp[ifxcor_1.is * 3 - 3] + srface[7] * 
	    sv_1.sp[ifxcor_1.is * 3 - 2] + srface[6] * sv_1.sp[ifxcor_1.is * 
	    3 - 1] + srface[8];
    fxcor_1.tem[1] = srface[7] * sv_1.sp[ifxcor_1.is * 3 - 3] + srface[2] * 
	    sv_1.sp[ifxcor_1.is * 3 - 2] + srface[5] * sv_1.sp[ifxcor_1.is * 
	    3 - 1] + srface[9];
    fxcor_1.tem[2] = srface[6] * sv_1.sp[ifxcor_1.is * 3 - 3] + srface[5] * 
	    sv_1.sp[ifxcor_1.is * 3 - 2] + srface[3] * sv_1.sp[ifxcor_1.is * 
	    3 - 1] + srface[10];
    vnorm_(fxcor_1.tem, &sv_1.sn[ifxcor_1.is * 3 - 3]);
    goto L3000;
L2000:
    sv_1.sn[ifxcor_1.is * 3 - 3] = sv_1.sp[ifxcor_1.is * 3 - 3] - srface[1];
    sv_1.sn[ifxcor_1.is * 3 - 2] = sv_1.sp[ifxcor_1.is * 3 - 2] - srface[2];
    sv_1.sn[ifxcor_1.is * 3 - 1] = sv_1.sp[ifxcor_1.is * 3 - 1] - srface[3];
    vnorm_(&sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.jsw == 5) {
	goto L3000;
    }
    if (ifxcor_1.ier <= 0) {
	goto L2002;
    } else {
	goto L2009;
    }
L2009:
    ifxcor_1.ier = 0;
    sv_1.sn[ifxcor_1.is * 3 - 3] = -srface[4];
    sv_1.sn[ifxcor_1.is * 3 - 2] = -srface[5];
    sv_1.sn[ifxcor_1.is * 3 - 1] = -srface[6];
    goto L3000;
L2002:
    fxcor_1.tem[3] = sv_1.sn[ifxcor_1.is * 3 - 3] * srface[4] + sv_1.sn[
	    ifxcor_1.is * 3 - 2] * srface[5] + sv_1.sn[ifxcor_1.is * 3 - 1] * 
	    srface[6];
    fxcor_1.tem[5] = sqrt(znumbr_1.z1 - fxcor_1.tem[3] * fxcor_1.tem[3]);
    fxcor_1.tem[6] = sqrt(znumbr_1.z1 - srface[7] * srface[7]);
    fxcor_1.tem[7] = fxcor_1.tem[3] * srface[7] + fxcor_1.tem[5] * 
	    fxcor_1.tem[6];
    if (fxcor_1.tem[7] >= 0.) {
	goto L2005;
    } else {
	goto L3000;
    }
L2005:
    sv_1.sn[ifxcor_1.is * 3 - 3] = (srface[7] * sv_1.sn[ifxcor_1.is * 3 - 3] 
	    - fxcor_1.tem[7] * srface[4]) / fxcor_1.tem[5];
    sv_1.sn[ifxcor_1.is * 3 - 2] = (srface[7] * sv_1.sn[ifxcor_1.is * 3 - 2] 
	    - fxcor_1.tem[7] * srface[5]) / fxcor_1.tem[5];
    sv_1.sn[ifxcor_1.is * 3 - 1] = (srface[7] * sv_1.sn[ifxcor_1.is * 3 - 1] 
	    - fxcor_1.tem[7] * srface[6]) / fxcor_1.tem[5];
L3000:
    return 0;
} /* ddquad_ */

#undef sinl
#undef cosl


