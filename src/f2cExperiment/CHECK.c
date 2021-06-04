/* CHECK.f -- translated by f2c (version 20100827).
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

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer ichekf;
} chekfl_;

#define chekfl_1 chekfl_

/* Table of constant values */

static integer c_b10 = -24201;
static integer c_b61 = -24202;

/* *** SOURCE FILE : M0002746.W04   *** */

/* .....FORTRAN SUBROUTINE  ....CHECK          8/68                 PH,HG */

/* Subroutine */ int check_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, k, jwr;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), dotf_(
	    doublereal *, doublereal *, doublereal *);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer itry;
    extern /* Subroutine */ int ddst_(void), amind_(void), ddlim_(void), 
	    cplan_(void);
    static doublereal tiold[3];
    static integer itang;
    static doublereal dtisn;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static doublereal tnhelp[3];






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





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ---- FLAG INTRODUCED BY VW - USED TO DETERMINE 'CORRECT' SIDE OF CUTTER */





    if (isv_1.isftyp[ifxcor_1.is - 1] >= knumbr_1.k4) {
	goto L401;
    }
    itang = 0;
    fxcor_1.temp[7] = znumbr_1.z10 * fxcor_1.dpmax;
    if (isv_1.jent[ifxcor_1.is - 1] != knumbr_1.k1) {
	dotf_(&dtisn, fxcor_1.ti, &sv_1.sn[ifxcor_1.is * 3 - 3]);
	if (abs(dtisn) < .05) {
	    itang = 1;
	    isv1_1.j21[ifxcor_1.is - 1] = knumbr_1.k1;
	    goto L401;
	}
    }
    sv_1.tn[ifxcor_1.is * 3 - 3] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[2];
L401:
    if ((i__1 = isv1_1.j20[ifxcor_1.is - 1] - knumbr_1.k1) < 0) {
	goto L1;
    } else if (i__1 == 0) {
	goto L8;
    } else {
	goto L3;
    }
L1:
    jwr = 0;
    sv1_1.stck[ifxcor_1.is - 1] = znumbr_1.z1e6;
    sv1_1.csd[ifxcor_1.is - 1] = znumbr_1.z0;
    isv1_1.j20[ifxcor_1.is - 1] = knumbr_1.k1;
    isv1_1.j21[ifxcor_1.is - 1] = knumbr_1.k1;
    isv1_1.j22[ifxcor_1.is - 1] = 0;
    isv_1.jent[ifxcor_1.is - 1] = knumbr_1.k1;
/* L2: */
    isv_1.iopset[ifxcor_1.is - 1] = 0;
    isv_1.jtn[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.ju1[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.jiops[ifxcor_1.is - 1] = 0;
    goto L9;
L3:
    if (fxcor_1.tik[0] * (sv1_1.tee[ifxcor_1.is * 3 - 3] - fxcor_1.tek[0]) + 
	    fxcor_1.tik[1] * (sv1_1.tee[ifxcor_1.is * 3 - 2] - fxcor_1.tek[1])
	     + fxcor_1.tik[2] * (sv1_1.tee[ifxcor_1.is * 3 - 1] - fxcor_1.tek[
	    2]) - sv_1.eps1[ifxcor_1.is - 1] <= 0.) {
	goto L4;
    } else {
	goto L66;
    }
L4:
    aerr_(&c_b10, "CHECK   ", (ftnlen)8);
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z3 * dshar4_1.dp;
    sv1_1.csd[ifxcor_1.is - 1] = znumbr_1.z0;
    goto L11;
L66:
    isv1_1.j21[ifxcor_1.is - 1] = 0;
    dshar4_1.cmove[0] = sv1_1.tee[ifxcor_1.is * 3 - 3] - fxcor_1.tek[0];
    fxcor_1.temp[0] = fxcor_1.te[0] - fxcor_1.tek[0];
    dshar4_1.cmove[1] = sv1_1.tee[ifxcor_1.is * 3 - 2] - fxcor_1.tek[1];
    fxcor_1.temp[1] = fxcor_1.te[1] - fxcor_1.tek[1];
    dshar4_1.cmove[2] = sv1_1.tee[ifxcor_1.is * 3 - 1] - fxcor_1.tek[2];
    fxcor_1.temp[2] = fxcor_1.te[2] - fxcor_1.tek[2];
    vnorm_(dshar4_1.cmove, fxcor_1.tem);
    sv1_1.csd[ifxcor_1.is - 1] = fxcor_1.vtem;
    vnorm_(fxcor_1.temp, fxcor_1.temp);
    if (abs(dshar4_1.zl) < znumbr_1.z1em9) {
	dshar4_1.zl = znumbr_1.z1em9;
    }
    sv1_1.csd[ifxcor_1.is - 1] = (sv1_1.csd[ifxcor_1.is - 1] - fxcor_1.vtem) *
	     (dshar4_1.dpi / dshar4_1.zl) * znumbr_1.z11em1;
    if (sv1_1.csd[ifxcor_1.is - 1] - sv_1.eps1[ifxcor_1.is - 1] <= 0.) {
	goto L7;
    } else {
	goto L16;
    }
L7:
    fxcor_1.te[0] = sv1_1.tee[ifxcor_1.is * 3 - 3];
    fxcor_1.te[1] = sv1_1.tee[ifxcor_1.is * 3 - 2];
    fxcor_1.te[2] = sv1_1.tee[ifxcor_1.is * 3 - 1];
    goto L18;
L8:
    if (isv_1.isftyp[ifxcor_1.is - 1] - 4 >= 0) {
	goto L84;
    } else {
	goto L85;
    }
L84:
    if (isv1_1.jph[ifxcor_1.is - 1] != 0) {
	goto L11;
    } else {
	goto L9;
    }
L85:
    sv_1.s[ifxcor_1.is - 1] -= dshar4_1.dp;
    if (sv_1.s[ifxcor_1.is - 1] < znumbr_1.z5 || sv_1.s[ifxcor_1.is - 1] < 
	    znumbr_1.z5 * dshar4_1.dp) {
	goto L9;
    }
/* L86: */
    if (fxcor_1.ti[0] * tiold[0] + fxcor_1.ti[1] * tiold[1] + fxcor_1.ti[2] * 
	    tiold[2] - .9f >= 0.) {
	goto L11;
    } else {
	goto L9;
    }
L9:
    itry = 0;
    chekfl_1.ichekf = 1;
L901:
    for (i__ = 1; i__ <= 3; ++i__) {
	tnhelp[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
/* L98: */
    }
    ++itry;
    ishr18_1.jminr = knumbr_1.k1;
L99:
    amind_();
    chekfl_1.ichekf = 0;
    ishr18_1.jminr = knumbr_1.k0;
    for (i__ = 1; i__ <= 3; ++i__) {
	tiold[i__ - 1] = fxcor_1.ti[i__ - 1];
/* L87: */
    }
    if (ifxcor_1.iaerr != 0) {
	goto L17;
    } else {
	goto L91;
    }
L91:
    if (ishr18_1.jmin != 0) {
	goto L10;
    } else {
	goto L19;
    }
L10:
    if (itry == 1) {
	goto L901;
    }
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z0;
L11:
    isv1_1.j21[ifxcor_1.is - 1] = 0;
L12:
    if (sv1_1.csd[ifxcor_1.is - 1] - sv_1.eps1[ifxcor_1.is - 1] >= 0.) {
	goto L15;
    } else {
	goto L13;
    }
L13:
    if (ifxcor_1.istrup <= 0) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    sv1_1.csd[ifxcor_1.is - 1] = znumbr_1.z2 * sv1_1.dpmx1[ifxcor_1.is - 1];
L15:
    if (sv1_1.stck[ifxcor_1.is - 1] <= znumbr_1.z0) {
	goto L18;
    }
    if (itang == knumbr_1.k1 && fxcor_1.temp[7] < dshar4_1.dp && sv1_1.stck[
	    ifxcor_1.is - 1] < znumbr_1.z2 * sv_1.tau[ifxcor_1.is - 1]) {
	goto L18;
    }
L16:
    ishr18_1.jckr = 0;
L17:
    isv1_1.jph[ifxcor_1.is - 1] = knumbr_1.k0;
    return 0;
L18:
    isv1_1.j50[ifxcor_1.is - 1] = knumbr_1.k1;
    isv1_1.j51[ifxcor_1.is - 1] = knumbr_1.k1;
    sv1_1.plnd1[ifxcor_1.is - 1] = znumbr_1.z0;
    isv1_1.notan[ifxcor_1.is - 1] = 0;
    ishr18_1.jckr = knumbr_1.k1;
    goto L17;
L19:
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k4 >= 0) {
	goto L22;
    } else {
	goto L190;
    }
L190:
    if (isv1_1.j23[ifxcor_1.is - 1] != 0) {
	goto L20;
    } else {
	goto L21;
    }
L20:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) < znumbr_1.z1em9) {
	goto L2001;
    }
    d__1 = sv_1.z__[ifxcor_1.is - 1] * sv_1.s[ifxcor_1.is - 1];
    sv1_1.stck1[ifxcor_1.is - 1] = d_sign(&znumbr_1.z1, &d__1);
    isv1_1.j23[ifxcor_1.is - 1] = 0;
    goto L22;
L2001:
    isv1_1.j20[ifxcor_1.is - 1] = 0;
    goto L16;
L21:
    sv1_1.stck[ifxcor_1.is - 1] = sv1_1.stck1[ifxcor_1.is - 1] * sv_1.z__[
	    ifxcor_1.is - 1] * sv_1.s[ifxcor_1.is - 1];
L22:
    sv1_1.cos1[ifxcor_1.is - 1] = sv_1.tn[ifxcor_1.is * 3 - 3] * fxcor_1.ti[0]
	     + sv_1.tn[ifxcor_1.is * 3 - 2] * fxcor_1.ti[1] + sv_1.tn[
	    ifxcor_1.is * 3 - 1] * fxcor_1.ti[2];

    if ((i__1 = isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k2) < 0) {
	goto L23;
    } else if (i__1 == 0) {
	goto L30;
    } else {
	goto L39;
    }
L23:
    if (sv1_1.cos1[ifxcor_1.is - 1] >= 0.) {
	goto L25;
    } else {
	goto L24;
    }
L24:
    sv_1.tn[ifxcor_1.is * 3 - 3] = -sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = -sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.tn[ifxcor_1.is * 3 - 1] = -sv_1.tn[ifxcor_1.is * 3 - 1];
    sv_1.rc[ifxcor_1.is - 1] = -sv_1.rc[ifxcor_1.is - 1];
    isv1_1.j23[ifxcor_1.is - 1] = knumbr_1.k1;
    goto L99;
L25:
    if (sv_1.tau[ifxcor_1.is - 1] > sv_1.s[ifxcor_1.is - 1]) {
	goto L32;
    }
    if (itang == knumbr_1.k1 && znumbr_1.z5 * sv_1.tau[ifxcor_1.is - 1] > 
	    sv_1.s[ifxcor_1.is - 1]) {
	goto L32;
    }
L26:
    if (sv1_1.cos1[ifxcor_1.is - 1] != 0.) {
	goto L27;
    } else {
	goto L28;
    }
L27:
    sv1_1.csd[ifxcor_1.is - 1] = (d__1 = sv_1.s[ifxcor_1.is - 1] / sv1_1.cos1[
	    ifxcor_1.is - 1], abs(d__1));
    goto L29;
L28:
    sv1_1.csd[ifxcor_1.is - 1] = (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) 
	    + sv_1.tau[ifxcor_1.is - 1];
L29:
    if (dshar4_1.dp - sv1_1.csd[ifxcor_1.is - 1] >= 0.) {
	goto L201;
    } else {
	goto L11;
    }
L201:
    if (sv1_1.csd[ifxcor_1.is - 1] > znumbr_1.z9em1 * dshar4_1.dp) {
	if (dshar4_1.dp > fxcor_1.dpmax * sv_1.tau[ifxcor_1.is - 1]) {
	    dshar4_1.dp *= .75;
	    goto L11;
	}
    }
    if (isv1_1.j50[ifxcor_1.is - 1] >= 0) {
	goto L18;
    } else {
	goto L202;
    }
L202:
    if (sv_1.tau[ifxcor_1.is - 1] - sv1_1.csd[ifxcor_1.is - 1] >= 0.) {
	goto L18;
    } else {
	goto L11;
    }
L30:
    if (sv1_1.cos1[ifxcor_1.is - 1] <= 0.) {
	goto L31;
    } else {
	goto L24;
    }
L31:
    if (sv_1.tau[ifxcor_1.is - 1] - sv_1.s[ifxcor_1.is - 1] <= 0.) {
	goto L32;
    } else {
	goto L26;
    }
L32:
    if (isv1_1.j21[ifxcor_1.is - 1] <= 0) {
	goto L301;
    } else {
	goto L33;
    }
L301:
    if (ishr18_1.ipdpl <= 0) {
	goto L15;
    } else {
	goto L18;
    }
L33:
    for (k = 1; k <= 3; ++k) {
	fxcor_1.temp[k - 1] = sv_1.tp[k + ifxcor_1.is * 3 - 4];
	fxcor_1.temp[k + 2] = sv_1.tn[k + ifxcor_1.is * 3 - 4];
	sv_1.tp[k + ifxcor_1.is * 3 - 4] = sv_1.sp[k + ifxcor_1.is * 3 - 4] + 
		sv_1.tau[ifxcor_1.is - 1] * fxcor_1.ti[k - 1];
/* L37: */
	sv_1.tn[k + ifxcor_1.is * 3 - 4] = fxcor_1.ti[k - 1];
    }
    isv_1.iop[ifxcor_1.is - 1] = knumbr_1.k1;
    fxcor_1.temp[6] = sv_1.s[ifxcor_1.is - 1];
    if (isv_1.limfl[ifxcor_1.is - 1] != 0) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    ddlim_();
    goto L36;
L35:
    chekfl_1.ichekf = 1;
    ddst_();
    chekfl_1.ichekf = 0;
L36:
    for (k = 1; k <= 3; ++k) {
	sv_1.tp[k + ifxcor_1.is * 3 - 4] = fxcor_1.temp[k - 1];
	sv_1.tn[k + ifxcor_1.is * 3 - 4] = fxcor_1.temp[k + 2];
/* L361: */
    }
    if (ifxcor_1.ier != 0) {
	goto L38;
    } else {
	goto L55;
    }
L38:
    sv1_1.csd[ifxcor_1.is - 1] = 0.;
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z5 * dshar4_1.dp;
    goto L12;
L39:
    if (knumbr_1.k3 - isv_1.isftyp[ifxcor_1.is - 1] != 0) {
	goto L40;
    } else {
	goto L23;
    }
L40:
    sv1_1.cptst[ifxcor_1.is - 1] = znumbr_1.z0;
    sv1_1.cplfl[ifxcor_1.is - 1] = znumbr_1.z0;
    cplan_();
    ifxcor_1.it = ifxcor_1.it;
    if (ishr18_1.jcpr != 0) {
	goto L41;
    } else {
	goto L45;
    }
L41:
    aerr_(&c_b61, "CHECK   ", (ftnlen)8);
    goto L11;
L45:
    if (sv1_1.plncs[ifxcor_1.is - 1] >= 0.) {
	goto L46;
    } else {
	goto L24;
    }
L46:
    fxcor_1.temp[0] = sv_1.plnv[ifxcor_1.is * 3 - 3] * fxcor_1.ti[0] + 
	    sv_1.plnv[ifxcor_1.is * 3 - 2] * fxcor_1.ti[1] + sv_1.plnv[
	    ifxcor_1.is * 3 - 1] * fxcor_1.ti[2];
    if (fxcor_1.temp[0] != 0.) {
	goto L47;
    } else {
	goto L48;
    }
L47:
    sv1_1.csd[ifxcor_1.is - 1] = (d__1 = sv_1.plnd[ifxcor_1.is - 1] / 
	    fxcor_1.temp[0], abs(d__1));
L48:
    fxcor_1.temp[0] = (sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.sp[ifxcor_1.it * 3 
	    - 3]) * sv_1.tn[ifxcor_1.is * 3 - 3] + (sv_1.sp[ifxcor_1.is * 3 - 
	    2] - sv_1.sp[ifxcor_1.it * 3 - 2]) * sv_1.tn[ifxcor_1.is * 3 - 2] 
	    + (sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.sp[ifxcor_1.it * 3 - 1]) * 
	    sv_1.tn[ifxcor_1.is * 3 - 1];
    fxcor_1.temp[0] *= sv_1.tn[ifxcor_1.is * 3 - 3] * fxcor_1.ti[0] + sv_1.tn[
	    i__ * 3 - 2] * fxcor_1.ti[1] + sv_1.tn[ifxcor_1.is * 3 - 1] * 
	    fxcor_1.ti[2];
    if (isv1_1.j22[ifxcor_1.is - 1] != 0) {
	goto L607;
    } else {
	goto L51;
    }
L607:
    sv1_1.stckn[ifxcor_1.is - 1] = sv1_1.stck2[ifxcor_1.is - 1] * 
	    fxcor_1.temp[0];
/*                   STPCK IF SURFACE PASSED */
    if (sv1_1.stckn[ifxcor_1.is - 1] >= 0.) {
	goto L6071;
    } else {
	goto L18;
    }
/*                   STPCK IF SURFACE NEARBY */
L6071:
    if ((d__1 = sv_1.plnd[ifxcor_1.is - 1], abs(d__1)) - znumbr_1.z2 * 
	    dshar4_1.dp <= 0.) {
	goto L6072;
    } else {
	goto L11;
    }
L6072:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - dshar4_1.dp <= 0.) {
	goto L18;
    } else {
	goto L11;
    }
L51:
    sv1_1.stck2[ifxcor_1.is - 1] = fxcor_1.temp[0];
    if (sv1_1.stck2[ifxcor_1.is - 1] >= 0.) {
	goto L502;
    } else {
	goto L11;
    }
L502:
    isv1_1.j22[ifxcor_1.is - 1] = knumbr_1.k1;
    goto L11;
L52:
    if (sv1_1.csd[ifxcor_1.is - 1] - znumbr_1.z2 * dshar4_1.dp >= 0.) {
	goto L12;
    } else {
	goto L53;
    }
L53:
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.cmove[i__ - 1] = fxcor_1.temp[7] * fxcor_1.ti[i__ - 1];
/* L54: */
	fxcor_1.te[i__ - 1] += dshar4_1.cmove[i__ - 1];
    }
    goto L18;
L55:
    sv1_1.csd[ifxcor_1.is - 1] = (d__1 = fxcor_1.temp[6] / sv1_1.cos1[
	    ifxcor_1.is - 1] + sv_1.s[ifxcor_1.is - 1] + sv_1.tau[ifxcor_1.is 
	    - 1], abs(d__1));
    fxcor_1.temp[7] = sv_1.s[ifxcor_1.is - 1];
    if (sv1_1.csd[ifxcor_1.is - 1] - znumbr_1.z5 * dshar4_1.dp >= 0.) {
	goto L102;
    } else {
	goto L101;
    }
L101:
    sv_1.s[ifxcor_1.is - 1] = sv1_1.csd[ifxcor_1.is - 1];
    goto L152;
L102:
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z5 * dshar4_1.dp;
L152:
    if (sv_1.s[ifxcor_1.is - 1] - abs(fxcor_1.temp[6]) >= 0.) {
	goto L52;
    } else {
	goto L153;
    }
L153:
    sv_1.s[ifxcor_1.is - 1] = abs(fxcor_1.temp[6]);
    goto L52;
} /* check_ */

#undef sinl
#undef cosl


