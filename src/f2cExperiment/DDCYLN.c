/* DDCYLN.f -- translated by f2c (version 20100827).
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

/* ** SOURCE FILE : M0000714.V04   *** */


/* .....FORTRAN SUBROUTINE             DDCYLN...              4/1/68   GK */
/* Subroutine */ int ddcyln_(doublereal *srface)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int quad_(void);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);






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
	goto L47;
    }
    fxcor_1.tem[0] = sv_1.tn[ifxcor_1.is * 3 - 3] * srface[4] + sv_1.tn[
	    ifxcor_1.is * 3 - 2] * srface[5] + sv_1.tn[ifxcor_1.is * 3 - 1] * 
	    srface[6];
    dshar4_1.a = sv_1.tn[ifxcor_1.is * 3 - 3] * sv_1.tn[ifxcor_1.is * 3 - 3] 
	    + sv_1.tn[ifxcor_1.is * 3 - 2] * sv_1.tn[ifxcor_1.is * 3 - 2] + 
	    sv_1.tn[ifxcor_1.is * 3 - 1] * sv_1.tn[ifxcor_1.is * 3 - 1];
    fxcor_1.tem[1] = sv_1.tp[ifxcor_1.is * 3 - 3] - srface[1];
    fxcor_1.tem[2] = sv_1.tp[ifxcor_1.is * 3 - 2] - srface[2];
    fxcor_1.tem[3] = sv_1.tp[ifxcor_1.is * 3 - 1] - srface[3];
    fxcor_1.tem[4] = fxcor_1.tem[1] * srface[4] + fxcor_1.tem[2] * srface[5] 
	    + fxcor_1.tem[3] * srface[6];
    dshar4_1.b = sv_1.tn[ifxcor_1.is * 3 - 3] * fxcor_1.tem[1] + sv_1.tn[
	    ifxcor_1.is * 3 - 2] * fxcor_1.tem[2] + sv_1.tn[ifxcor_1.is * 3 - 
	    1] * fxcor_1.tem[3];
    dshar4_1.c__ = fxcor_1.tem[1] * fxcor_1.tem[1] + fxcor_1.tem[2] * 
	    fxcor_1.tem[2] + fxcor_1.tem[3] * fxcor_1.tem[3];
    dshar4_1.a -= fxcor_1.tem[0] * fxcor_1.tem[0];
    dshar4_1.b -= fxcor_1.tem[0] * fxcor_1.tem[4];
/*              CHOOSE WELL-CONDITIONED FORMULA */
    if (abs(dshar4_1.c__) < znumbr_1.z1em9) {
	goto L42;
    }
    if (fxcor_1.tem[4] * fxcor_1.tem[4] / dshar4_1.c__ - .9f <= 0.) {
	goto L42;
    } else {
	goto L44;
    }
L42:
    dshar4_1.c__ = dshar4_1.c__ - fxcor_1.tem[4] * fxcor_1.tem[4] - srface[7] 
	    * srface[7];
    goto L46;
L44:
    cross_(&srface[4], &fxcor_1.tem[1], &fxcor_1.tem[5]);
    dshar4_1.c__ = fxcor_1.tem[5] * fxcor_1.tem[5] + fxcor_1.tem[6] * 
	    fxcor_1.tem[6] + fxcor_1.tem[7] * fxcor_1.tem[7] - srface[7] * 
	    srface[7];
L46:
    quad_();
    if (ifxcor_1.ier == 1) {
	goto L1000;
    }
    if (ifxcor_1.istrup == 4) {
	goto L50;
    }
    sv_1.spl[ifxcor_1.is * 3 - 3] = sv_1.sp[ifxcor_1.is * 3 - 3];
    sv_1.spl[ifxcor_1.is * 3 - 2] = sv_1.sp[ifxcor_1.is * 3 - 2];
    sv_1.spl[ifxcor_1.is * 3 - 1] = sv_1.sp[ifxcor_1.is * 3 - 1];
    sv_1.snl[ifxcor_1.is * 3 - 3] = sv_1.sn[ifxcor_1.is * 3 - 3];
    sv_1.snl[ifxcor_1.is * 3 - 2] = sv_1.sn[ifxcor_1.is * 3 - 2];
    sv_1.snl[ifxcor_1.is * 3 - 1] = sv_1.sn[ifxcor_1.is * 3 - 1];
L50:
    sv_1.sp[ifxcor_1.is * 3 - 3] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.sp[ifxcor_1.is * 3 - 2] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.sp[ifxcor_1.is * 3 - 1] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[
	    ifxcor_1.is - 1] * sv_1.tn[ifxcor_1.is * 3 - 1];
L47:
    fxcor_1.tem[0] = sv_1.sp[ifxcor_1.is * 3 - 3] - srface[1];
    fxcor_1.tem[1] = sv_1.sp[ifxcor_1.is * 3 - 2] - srface[2];
    fxcor_1.tem[2] = sv_1.sp[ifxcor_1.is * 3 - 1] - srface[3];
    fxcor_1.tem[3] = fxcor_1.tem[0] * srface[4] + fxcor_1.tem[1] * srface[5] 
	    + fxcor_1.tem[2] * srface[6];
    fxcor_1.tem[0] -= fxcor_1.tem[3] * srface[4];
    fxcor_1.tem[1] -= fxcor_1.tem[3] * srface[5];
    fxcor_1.tem[2] -= fxcor_1.tem[3] * srface[6];
    fxcor_1.tem[4] = fxcor_1.tem[0] * fxcor_1.tem[0] + fxcor_1.tem[1] * 
	    fxcor_1.tem[1] + fxcor_1.tem[2] * fxcor_1.tem[2];
    if (fxcor_1.tem[4] <= 0.) {
	goto L3;
    } else {
	goto L4;
    }
L3:
    ifxcor_1.ier = knumbr_1.k1;
    goto L1000;
L4:
    fxcor_1.tem[4] = sqrt(fxcor_1.tem[4]);
    sv_1.sn[ifxcor_1.is * 3 - 3] = fxcor_1.tem[0] / fxcor_1.tem[4];
    sv_1.sn[ifxcor_1.is * 3 - 2] = fxcor_1.tem[1] / fxcor_1.tem[4];
    sv_1.sn[ifxcor_1.is * 3 - 1] = fxcor_1.tem[2] / fxcor_1.tem[4];
L1000:
    return 0;
} /* ddcyln_ */

#undef sinl
#undef cosl


