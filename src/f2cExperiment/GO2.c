/* GO2.f -- translated by f2c (version 20100827).
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
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
} hblock_;

#define hblock_1 hblock_

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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__20202 = 20202;
static integer c__20203 = 20203;
static integer c__41 = 41;
static integer c__20204 = 20204;
static integer c__42 = 42;
static integer c__43 = 43;
static integer c__20205 = 20205;
static integer c__20206 = 20206;
static integer c__45 = 45;

/* *** SOURCE FILE : M0002768.V08   *** */

/* ...  FORTRAN SUBROUTINE     GO2 */
/* Subroutine */ int go2_(doublereal *hmod, doublereal *adress)
{
    /* Initialized data */

    static doublereal zlit1 = 1e-4;
    static doublereal zlit2 = .9999;
    static integer klit3 = 21;
    static char hgo[2] = "GO";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, ia, id, ib;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer iii;
    static doublereal tem1, tem3, tem2;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static doublereal xdir;
    extern /* Subroutine */ int ddst_(void);
    static integer issv;
    extern /* Subroutine */ int apt240_(integer *), apt234_(doublereal *, 
	    doublereal *), apt238_(integer *), apt235_(void), apt236_(void), 
	    check_(void), amind_(void), atape_(void);
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer issto, isssv;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), cross_(
	    doublereal *, doublereal *, doublereal *), centr_(void);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define kdynfl ((integer *)&addcom_1 + 48)
    static doublereal cansav[4];
    static integer icnsav, numdim, ngosrf;
    extern /* Subroutine */ int svcopy_(integer *, integer *), isvcpy_(
	    integer *, integer *);







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





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */









/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --adress;

    /* Function Body */

    icnsav = knumbr_1.k0;
    dshar4_1.zl = znumbr_1.z1;

/*                 SET IAFL FLAG */

    numdim = 0;
    ldef_1.jcs = FALSE_;
    if (ifxcor_1.igoto == knumbr_1.k0) {
	goto L1;
    }
    if (ifxcor_1.isrch != knumbr_1.k0) {
	goto L9600;
    }
/* L502: */
    aerr_(&c__20202, "GO2     ", (ftnlen)8);
    goto L9100;
L1:
    if (ifxcor_1.icscnt - knumbr_1.k1 <= 0) {
	goto L1101;
    } else {
	goto L1102;
    }
L1102:
    aerr_(&c__20203, "GO2     ", (ftnlen)8);
    goto L9100;
L1101:
    ifxcor_1.istrup = knumbr_1.k1;
    dshar4_1.dp = -1.f;
    isv_1.jent[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.jent[ifxcor_1.ids - 1] = knumbr_1.k1;
    ifxcor_1.is = ifxcor_1.ids;
    apt234_(hmod, &adress[1]);
    if (ifxcor_1.iaerr <= 0) {
	goto L503;
    } else {
	goto L9100;
    }
L503:
    fxcor_1.tek[0] = fxcor_1.te[0];
    fxcor_1.tek[1] = fxcor_1.te[1];
    fxcor_1.tek[2] = fxcor_1.te[2];
    xdir = (doublereal) knumbr_1.k1;
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&c__41);
    }
/* L1000: */
    if (ifxcor_1.inops <= 0) {
	goto L6;
    } else {
	goto L2;
    }
L2:
    if (ifxcor_1.icscnt <= 0) {
	goto L3;
    } else {
	goto L1020;
    }
L3:
    ngosrf = knumbr_1.k1;
    goto L7;
L1020:
    aerr_(&c__20204, "GO2     ", (ftnlen)8);
    goto L9100;
L6:
    ngosrf = ifxcor_1.icscnt + knumbr_1.k2;
L7:
    s_copy(charct_1.modfer, hgo, (ftnlen)6, (ftnlen)2);
    apt235_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L9100;
    }
    if (ifxcor_1.inops != knumbr_1.k1) {
	goto L1610;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L1605: */
	cansav[i__ - 1] = canon[i__ - 1];
    }
    icnsav = knumbr_1.k1;
L1610:
    apt240_(&numdim);
    id = 0;
L1070:
    ia = knumbr_1.k1;
    ib = knumbr_1.k1;
    tem1 = znumbr_1.z0;
L1080:
    id += knumbr_1.k1;
/* L1090: */
    if (ngosrf - id >= 0) {
	goto L1100;
    } else {
	goto L1300;
    }
L1100:
    if ((i__1 = id - knumbr_1.k2) < 0) {
	goto L1110;
    } else if (i__1 == 0) {
	goto L1120;
    } else {
	goto L1130;
    }
L1110:
    ifxcor_1.is = ifxcor_1.ids;
    goto L1140;
L1120:
    ifxcor_1.is = ifxcor_1.ips;
    goto L1140;
L1130:
    ifxcor_1.is = ifxcor_1.ics;
L1140:
    if (isv_1.indir__[ifxcor_1.is - 1] == 0 && isv_1.isfidn[ifxcor_1.is - 1] 
	    != 12) {
	goto L1160;
    }
/* L1150: */
    ia += knumbr_1.k1;
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&c__42);
    }
    goto L1080;
L1160:
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&c__43);
    }
/* L1161: */
    if ((i__1 = isv_1.isvfl[ifxcor_1.is - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1180;
    } else {
	goto L1170;
    }
L1170:
    fxcor_1.ti[0] = sv_1.sfvct[ifxcor_1.is * 3 - 3];
    fxcor_1.ti[1] = sv_1.sfvct[ifxcor_1.is * 3 - 2];
    fxcor_1.ti[2] = sv_1.sfvct[ifxcor_1.is * 3 - 1];
    if (ifxcor_1.is == ifxcor_1.ics) {
	goto L1173;
    }
    issto = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ics + 1;
    svcopy_(&issto, &ifxcor_1.is);
    isvcpy_(&issto, &ifxcor_1.is);
L1173:
    sv_1.tn[ifxcor_1.is * 3 - 3] = sv_1.sfvct[ifxcor_1.is * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = sv_1.sfvct[ifxcor_1.is * 3 - 2];
    sv_1.tn[ifxcor_1.is * 3 - 1] = sv_1.sfvct[ifxcor_1.is * 3 - 1];
    isv1_1.j20[ifxcor_1.is - 1] = 0;
    isv1_1.j23[ifxcor_1.is - 1] = knumbr_1.k1;
    dshar4_1.dp = 0.f;
    ifxcor_1.istrup = 2;
    check_();
    if (ifxcor_1.iaerr != 0) {
	goto L9100;
    } else {
	goto L100;
    }
L100:
    if (ifxcor_1.is == ifxcor_1.ics) {
	goto L1175;
    }
    svcopy_(&ifxcor_1.is, &issto);
    isvcpy_(&ifxcor_1.is, &issto);
    ifxcor_1.is = issto;
    if (tem3 != 0.) {
	goto L1240;
    } else {
	goto L1210;
    }
L1175:
    if (sv1_1.csd[ifxcor_1.is - 1] != 0.) {
	goto L1239;
    } else {
	goto L1210;
    }
L1180:
    if (ifxcor_1.is == ifxcor_1.ips) {
	goto L1181;
    }
    if (isv_1.indir__[ifxcor_1.ids - 1] == 1) {
	goto L1182;
    }
    if (isv_1.indir__[ifxcor_1.ics - 1] == 1) {
	goto L1183;
    }
    sv_1.tn[ifxcor_1.is * 3 - 3] = znumbr_1.z1;
    sv_1.tn[ifxcor_1.is * 3 - 2] = znumbr_1.z0;
    sv_1.tn[ifxcor_1.is * 3 - 1] = znumbr_1.z0;
    goto L1190;
L1181:
    sv_1.tn[ifxcor_1.is * 3 - 3] = -fxcor_1.ta[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = -fxcor_1.ta[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = -fxcor_1.ta[2];
    goto L1190;
L1182:
    k = ifxcor_1.ids;
    goto L1184;
L1183:
    k = ifxcor_1.ics;
L1184:
    sv_1.tn[ifxcor_1.is * 3 - 3] = sv_1.vndir[k * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = sv_1.vndir[k * 3 - 2];
    sv_1.tn[ifxcor_1.is * 3 - 1] = sv_1.vndir[k * 3 - 1];
L1190:
    isv_1.iopset[ifxcor_1.is - 1] = 0;
    isv_1.jent[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.jtn[ifxcor_1.is - 1] = 0;
    isv_1.ju1[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.jiops[ifxcor_1.is - 1] = 0;
    ishr18_1.jminr = knumbr_1.k1;
/* L1200: */
    amind_();
    ishr18_1.jminr = knumbr_1.k0;
    if (ifxcor_1.iaerr != 0) {
	goto L9100;
    } else {
	goto L1210;
    }
L1210:
    tem3 = (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1));
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&knumbr_1.k44);
    }
    goto L1240;
L1239:
    tem3 = sv1_1.csd[ifxcor_1.is - 1];
L1240:
    if (tem1 - (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) <= 0.) {
	goto L1250;
    } else {
	goto L1260;
    }
L1250:
    tem1 = (d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1));
L1260:
    switch (ib) {
	case 1:  goto L1080;
	case 2:  goto L1310;
	case 3:  goto L1270;
    }
L1270:
    ib = knumbr_1.k2;
    goto L1500;
L1300:
    id = 0;
    ib = knumbr_1.k2;
L1310:
    ia -= knumbr_1.k1;
/* L1320: */
    if (ia < 0) {
	goto L9000;
    } else if (ia == 0) {
	goto L2000;
    } else {
	goto L1330;
    }
L1330:
    id += knumbr_1.k1;
/* L1340: */
    if (ngosrf - id >= 0) {
	goto L1350;
    } else {
	goto L9000;
    }
L1350:
    if ((i__1 = id - knumbr_1.k2) < 0) {
	goto L1360;
    } else if (i__1 == 0) {
	goto L1370;
    } else {
	goto L1380;
    }
L1360:
    ifxcor_1.is = ifxcor_1.ids;
    goto L1390;
L1370:
    ifxcor_1.is = ifxcor_1.ips;
    goto L1390;
L1380:
    ifxcor_1.is = ifxcor_1.ics;
L1390:
    if ((i__1 = isv_1.indir__[ifxcor_1.is - 1]) < 0) {
	goto L9000;
    } else if (i__1 == 0) {
	goto L1391;
    } else {
	goto L1400;
    }
L1391:
    if (isv_1.isfidn[ifxcor_1.is - 1] != 12) {
	goto L1330;
    }
    sv_1.vndir[ifxcor_1.is * 3 - 3] = znumbr_1.z0;
    sv_1.vndir[ifxcor_1.is * 3 - 2] = znumbr_1.z0;
    sv_1.vndir[ifxcor_1.is * 3 - 1] = znumbr_1.z0;
L1400:
    for (k = 1; k <= 3; ++k) {
	sv_1.tp[k + ifxcor_1.is * 3 - 4] = fxcor_1.te[k - 1] + znumbr_1.z5em1 
		* fxcor_1.cutdat[6] * fxcor_1.ta[k - 1] + sv_1.th[ifxcor_1.is 
		- 1] * sv_1.vndir[k + ifxcor_1.is * 3 - 4];
/* L1420: */
	sv_1.tn[k + ifxcor_1.is * 3 - 4] = sv_1.vndir[k + ifxcor_1.is * 3 - 4]
		;
    }
    isv_1.iop[ifxcor_1.is - 1] = knumbr_1.k1;
    if (isv_1.isfidn[ifxcor_1.is - 1] == 12 && isv_1.indir__[ifxcor_1.is - 1] 
	    == 0) {
	isv_1.iop[ifxcor_1.is - 1] = knumbr_1.k2;
    }
    ddst_();
    isv_1.iop[ifxcor_1.is - 1] = knumbr_1.k1;
    if (ifxcor_1.ier != 0) {
	goto L1410;
    } else {
	goto L1430;
    }
L1410:
    ib = knumbr_1.k3;
    goto L1160;
L1430:
    tem2 = sv_1.s[ifxcor_1.is - 1];
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k3 != 0) {
	goto L1445;
    } else {
	goto L1440;
    }
L1445:
    tem2 -= fxcor_1.cutdat[0];
L1440:
    issv = ifxcor_1.is;
    for (i__ = 1; i__ <= 3; ++i__) {
/*          CHECK FOR ALL SURFACE */
	if (i__ == 1) {
	    ifxcor_1.is = ifxcor_1.ids;
	}
	if (i__ == 2) {
	    ifxcor_1.is = ifxcor_1.ips;
	}
	if (i__ == 3 && ifxcor_1.icscnt == 0) {
	    goto L1431;
	}
	if (i__ == 3) {
	    ifxcor_1.is = ifxcor_1.ics;
	}
/*    IF ALREADY CHECKED SKIP */
/* L1435: */
	if (ifxcor_1.is == issv) {
	    goto L1431;
	}
	fxcor_1.temp[0] = sv_1.tn[ifxcor_1.is * 3 - 3];
	fxcor_1.temp[1] = sv_1.tn[ifxcor_1.is * 3 - 2];
	fxcor_1.temp[2] = sv_1.tn[ifxcor_1.is * 3 - 1];
	fxcor_1.temp[6] = sv_1.tp[ifxcor_1.is * 3 - 3];
	fxcor_1.temp[7] = sv_1.tp[ifxcor_1.is * 3 - 2];
	fxcor_1.temp[8] = sv_1.tp[ifxcor_1.is * 3 - 1];
	for (k = 1; k <= 3; ++k) {
	    sv_1.tp[k + ifxcor_1.is * 3 - 4] = fxcor_1.te[k - 1] + 
		    znumbr_1.z5em1 * fxcor_1.cutdat[6] * fxcor_1.ta[k - 1] + 
		    sv_1.th[ifxcor_1.is - 1] * sv_1.vndir[k + issv * 3 - 4];
/* L1436: */
	    sv_1.tn[k + ifxcor_1.is * 3 - 4] = sv_1.vndir[k + issv * 3 - 4];
	}
	isv_1.iop[ifxcor_1.is - 1] = knumbr_1.k1;
	ddst_();
	if (ifxcor_1.ier == 1) {
	    goto L1438;
	}
	tem3 = sv_1.s[ifxcor_1.is - 1];
	if (isv_1.isftyp[ifxcor_1.is - 1] != knumbr_1.k3) {
	    tem3 -= fxcor_1.cutdat[0];
	}
	if (tem3 < 1e-8f) {
	    goto L1438;
	}
	if (tem3 < tem2) {
	    tem2 = tem3;
	}
L1438:
	sv_1.tn[ifxcor_1.is * 3 - 3] = fxcor_1.temp[0];
	sv_1.tn[ifxcor_1.is * 3 - 2] = fxcor_1.temp[1];
	sv_1.tn[ifxcor_1.is * 3 - 1] = fxcor_1.temp[2];
	sv_1.tp[ifxcor_1.is * 3 - 3] = fxcor_1.temp[6];
	sv_1.tp[ifxcor_1.is * 3 - 2] = fxcor_1.temp[7];
	sv_1.tp[ifxcor_1.is * 3 - 1] = fxcor_1.temp[8];
L1431:
	;
    }
    ifxcor_1.is = issv;
    fxcor_1.temp[4] = tem2 - sv_1.tau[ifxcor_1.is - 1];
    fxcor_1.te[0] += fxcor_1.temp[4] * sv_1.vndir[ifxcor_1.is * 3 - 3];
    fxcor_1.te[1] += fxcor_1.temp[4] * sv_1.vndir[ifxcor_1.is * 3 - 2];
    fxcor_1.te[2] += fxcor_1.temp[4] * sv_1.vndir[ifxcor_1.is * 3 - 1];
    if (isv_1.indir__[ifxcor_1.ics - 1] == 1 || isv_1.isvfl[ifxcor_1.ics - 1] 
	    == 1 || ifxcor_1.icscnt == 0) {
	goto L1160;
    }
    isv_1.jent[ifxcor_1.ics - 1] = 1;
    ishr18_1.jminr = 1;
    isssv = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ics;
    amind_();
    ishr18_1.jminr = 0;
    ifxcor_1.is = isssv;
    goto L1160;
L1500:
    if (tem3 - tem1 <= 0.) {
	goto L1510;
    } else {
	goto L1520;
    }
/*              USE SMALLEST MINIMUM DIST WHICH IS */
/*              GREATER THAN TWO TOLERANCES */
L1510:
    tem2 = tem1;
    i__1 = ifxcor_1.ics;
    i__2 = ifxcor_1.lsv;
    for (iii = ifxcor_1.ips; i__2 < 0 ? iii >= i__1 : iii <= i__1; iii += 
	    i__2) {
	if (isv_1.isvfl[iii - 1] == 0) {
	    goto L1501;
	}
	if (sv1_1.csd[iii - 1] - znumbr_1.z2 * sv_1.tau[ifxcor_1.is - 1] <= 
		0.) {
	    goto L1501;
	} else {
	    goto L1502;
	}
L1502:
/* Computing MIN */
	d__1 = tem2, d__2 = sv1_1.csd[iii - 1];
	tem2 = min(d__1,d__2);
L1501:
	;
    }
    goto L1440;
L1511:
    tem2 = tem1;
    goto L1440;
L1520:
    if (tem3 - znumbr_1.z10 >= 0.) {
	goto L1511;
    } else {
	goto L1530;
    }
L1530:
    tem2 = tem3;
    goto L1440;
L2000:
    if ((i__2 = ngosrf - knumbr_1.k2) < 0) {
	goto L2010;
    } else if (i__2 == 0) {
	goto L3000;
    } else {
	goto L3120;
    }
L2010:
    if ((i__2 = isv_1.indir__[ifxcor_1.ids - 1]) < 0) {
	goto L9000;
    } else if (i__2 == 0) {
	goto L2030;
    } else {
	goto L2020;
    }
L2020:
    dshar4_1.dir[0] = sv_1.vndir[ifxcor_1.ids * 3 - 3];
    dshar4_1.dir[1] = sv_1.vndir[ifxcor_1.ids * 3 - 2];
    dshar4_1.dir[2] = sv_1.vndir[ifxcor_1.ids * 3 - 1];
    goto L2040;
L2030:
    dshar4_1.dir[0] = sv_1.tn[ifxcor_1.ids * 3 - 3];
    dshar4_1.dir[1] = sv_1.tn[ifxcor_1.ids * 3 - 2];
    dshar4_1.dir[2] = sv_1.tn[ifxcor_1.ids * 3 - 1];
L2040:
    if (abs(dshar4_1.dir[2]) - zlit1 <= 0.) {
	goto L2050;
    } else {
	goto L2060;
    }
L2050:
    sv_1.plnv[ifxcor_1.ics * 3 - 3] = dshar4_1.dir[1];
    sv_1.plnv[ifxcor_1.ics * 3 - 2] = -dshar4_1.dir[0];
    sv_1.plnv[ifxcor_1.ics * 3 - 1] = znumbr_1.z0;
    goto L2090;
L2060:
    if (abs(dshar4_1.dir[1]) - zlit1 <= 0.) {
	goto L2070;
    } else {
	goto L2080;
    }
L2070:
    sv_1.plnv[ifxcor_1.ics * 3 - 3] = dshar4_1.dir[2];
    sv_1.plnv[ifxcor_1.ics * 3 - 2] = znumbr_1.z0;
    sv_1.plnv[ifxcor_1.ics * 3 - 1] = -dshar4_1.dir[0];
    goto L2090;
L2080:
    if (abs(dshar4_1.dir[0]) - zlit1 <= 0.) {
	goto L2085;
    } else {
	goto L2087;
    }
L2085:
    sv_1.plnv[ifxcor_1.ics * 3 - 3] = znumbr_1.z0;
    sv_1.plnv[ifxcor_1.ics * 3 - 2] = dshar4_1.dir[2];
    sv_1.plnv[ifxcor_1.ics * 3 - 1] = -dshar4_1.dir[1];
    goto L2090;
L2087:
    if (abs(dshar4_1.dir[1]) - abs(dshar4_1.dir[2]) <= 0.) {
	goto L2070;
    } else {
	goto L2050;
    }
L2090:
    vnorm_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], &sv_1.plnv[ifxcor_1.ics * 3 - 3])
	    ;
    cross_(dshar4_1.dir, &sv_1.plnv[ifxcor_1.ics * 3 - 3], &sv_1.plnv[
	    ifxcor_1.ips * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.ips * 3 - 3], &sv_1.plnv[ifxcor_1.ips * 3 - 3])
	    ;
/* L2110: */
    sv_1.plnd[ifxcor_1.ips - 1] = sv_1.plnv[ifxcor_1.ips * 3 - 3] * 
	    fxcor_1.tek[0] + sv_1.plnv[ifxcor_1.ips * 3 - 2] * fxcor_1.tek[1] 
	    + sv_1.plnv[ifxcor_1.ips * 3 - 1] * fxcor_1.tek[2];
    sv_1.plnd[ifxcor_1.ics - 1] = sv_1.plnv[ifxcor_1.ics * 3 - 3] * 
	    fxcor_1.tek[0] + sv_1.plnv[ifxcor_1.ics * 3 - 2] * fxcor_1.tek[1] 
	    + sv_1.plnv[ifxcor_1.ics * 3 - 1] * fxcor_1.tek[2];
/* L2120: */
    isv_1.icanon[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.isfidn[ifxcor_1.ips - 1] = knumbr_1.k2;
    isv_1.isftyp[ifxcor_1.ips - 1] = knumbr_1.k3;
    isv_1.itlon[ifxcor_1.ips - 1] = 0;
    canon[0] = sv_1.plnv[ifxcor_1.ips * 3 - 3];
    canon[1] = sv_1.plnv[ifxcor_1.ips * 3 - 2];
    canon[2] = sv_1.plnv[ifxcor_1.ips * 3 - 1];
    canon[3] = sv_1.plnd[ifxcor_1.ips - 1];
    isv_1.ipl[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.iunfl[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.jent[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.jtn[ifxcor_1.ips - 1] = 0;
    isv_1.iopset[ifxcor_1.ips - 1] = 0;
    isv_1.ju1[ifxcor_1.ips - 1] = knumbr_1.k1;
    isv_1.jiops[ifxcor_1.ips - 1] = 0;
    sv_1.tn[ifxcor_1.ips * 3 - 3] = sv_1.plnv[ifxcor_1.ips * 3 - 3];
    sv_1.tn[ifxcor_1.ips * 3 - 2] = sv_1.plnv[ifxcor_1.ips * 3 - 2];
    sv_1.tn[ifxcor_1.ips * 3 - 1] = sv_1.plnv[ifxcor_1.ips * 3 - 1];
    sv_1.past[ifxcor_1.ips - 1] = znumbr_1.z1;
    goto L3110;
L3000:
    if ((i__2 = isv_1.indir__[ifxcor_1.ids - 1]) < 0) {
	goto L9000;
    } else if (i__2 == 0) {
	goto L3030;
    } else {
	goto L3010;
    }
L3010:
    if ((i__2 = isv_1.indir__[ifxcor_1.ips - 1]) < 0) {
	goto L9000;
    } else if (i__2 == 0) {
	goto L3050;
    } else {
	goto L3020;
    }
L3020:
    isv1_1.j50[ifxcor_1.ics - 1] = 0;
    isv1_1.j51[ifxcor_1.ics - 1] = 0;
    ifxcor_1.is = ifxcor_1.ics;
    centr_();
    if (ifxcor_1.iaerr != 0) {
	goto L9100;
    } else {
	goto L101;
    }
L101:
    if (ishr18_1.jcr != 0) {
	goto L3152;
    } else {
	goto L9999;
    }
L3030:
    if ((i__2 = isv_1.indir__[ifxcor_1.ips - 1]) < 0) {
	goto L9000;
    } else if (i__2 == 0) {
	goto L3020;
    } else {
	goto L3040;
    }
L3040:
    ifxcor_1.is = ifxcor_1.ips;
    goto L3060;
L3050:
    ifxcor_1.is = ifxcor_1.ids;
L3060:
    dshar4_1.dir[0] = sv_1.vndir[ifxcor_1.is * 3 - 3];
    dshar4_1.dir[1] = sv_1.vndir[ifxcor_1.is * 3 - 2];
    dshar4_1.dir[2] = sv_1.vndir[ifxcor_1.is * 3 - 1];
    if ((d__1 = sv_1.tn[ifxcor_1.ips * 3 - 3] * sv_1.tn[ifxcor_1.ids * 3 - 3] 
	    + sv_1.tn[ifxcor_1.ips * 3 - 2] * sv_1.tn[ifxcor_1.ids * 3 - 2] + 
	    sv_1.tn[ifxcor_1.ips * 3 - 1] * sv_1.tn[ifxcor_1.ids * 3 - 1], 
	    abs(d__1)) > zlit1) {
	goto L3020;
    }
    cross_(&sv_1.tn[ifxcor_1.ips * 3 - 3], &sv_1.tn[ifxcor_1.ids * 3 - 3], &
	    sv_1.plnv[ifxcor_1.ics * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], &sv_1.plnv[ifxcor_1.ics * 3 - 3])
	    ;
    if (ifxcor_1.ier != 0) {
	goto L3020;
    } else {
	goto L3065;
    }
L3065:
    cross_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], dshar4_1.dir, &sv_1.plnv[
	    ifxcor_1.ics * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], &sv_1.plnv[ifxcor_1.ics * 3 - 3])
	    ;
    if (ifxcor_1.ier != 0) {
	goto L3020;
    } else {
	goto L3070;
    }
L3070:
    cross_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], dshar4_1.dir, &sv_1.plnv[
	    ifxcor_1.ics * 3 - 3]);
/* L3080: */
    vnorm_(&sv_1.plnv[ifxcor_1.ics * 3 - 3], &sv_1.plnv[ifxcor_1.ics * 3 - 3])
	    ;
/* L3090: */
    if (ifxcor_1.ier != 0) {
	goto L3020;
    } else {
	goto L4100;
    }
L4100:
    if (isv_1.ipl[ifxcor_1.ips - 1] != 0) {
	goto L4107;
    } else {
	goto L4105;
    }
L4105:
    if (isv_1.ipl[ifxcor_1.ids - 1] != 0) {
	goto L4108;
    } else {
	goto L3020;
    }
L4107:
    k = ifxcor_1.ips;
    goto L4109;
L4108:
    k = ifxcor_1.ids;
L4109:
    ifxcor_1.ic = isv_1.icanon[k - 1];
    if ((d__1 = sv_1.plnv[ifxcor_1.ics * 3 - 3] * canon[ifxcor_1.ic - 1] + 
	    sv_1.plnv[ifxcor_1.ics * 3 - 2] * canon[ifxcor_1.ic] + sv_1.plnv[
	    ifxcor_1.ics * 3 - 1] * canon[ifxcor_1.ic + 1], abs(d__1)) - 
	    zlit2 <= 0.) {
	goto L3100;
    } else {
	goto L3020;
    }
L3100:
    sv_1.plnd[ifxcor_1.ics - 1] = sv_1.plnv[ifxcor_1.ics * 3 - 3] * 
	    fxcor_1.tek[0] + sv_1.plnv[ifxcor_1.ics * 3 - 2] * fxcor_1.tek[1] 
	    + sv_1.plnv[ifxcor_1.ics * 3 - 1] * fxcor_1.tek[2];
L3110:
    isv_1.icanon[ifxcor_1.ics - 1] = klit3;
    isv_1.isfidn[ifxcor_1.ics - 1] = knumbr_1.k1;
    canon[20] = sv_1.plnv[ifxcor_1.ics * 3 - 3];
    canon[21] = sv_1.plnv[ifxcor_1.ics * 3 - 2];
    canon[22] = sv_1.plnv[ifxcor_1.ics * 3 - 1];
    canon[23] = sv_1.plnd[ifxcor_1.ics - 1];
    isv_1.isftyp[ifxcor_1.ics - 1] = knumbr_1.k3;
    isv_1.itlon[ifxcor_1.ics - 1] = 0;
    isv_1.iunfl[ifxcor_1.ics - 1] = knumbr_1.k1;
    isv_1.ipl[ifxcor_1.ics - 1] = knumbr_1.k1;
    isv_1.jent[ifxcor_1.ics - 1] = knumbr_1.k1;
    isv_1.jtn[ifxcor_1.ics - 1] = 0;
    isv_1.iopset[ifxcor_1.ics - 1] = 0;
    isv_1.ju1[ifxcor_1.ics - 1] = knumbr_1.k1;
    sv_1.tn[ifxcor_1.ics * 3 - 3] = sv_1.plnv[ifxcor_1.ics * 3 - 3];
    sv_1.tn[ifxcor_1.ics * 3 - 2] = sv_1.plnv[ifxcor_1.ics * 3 - 2];
    sv_1.tn[ifxcor_1.ics * 3 - 1] = sv_1.plnv[ifxcor_1.ics * 3 - 1];
    isv_1.jiops[ifxcor_1.ics - 1] = 0;
    sv_1.past[ifxcor_1.ics - 1] = znumbr_1.z1;
    isv_1.iafl[ifxcor_1.ics - 1] = knumbr_1.km1;
    ifxcor_1.icscnt = knumbr_1.k1;
L3120:
    isv1_1.j50[ifxcor_1.ics - 1] = knumbr_1.k1;
    isv1_1.j51[ifxcor_1.ics - 1] = knumbr_1.k1;
/* L3130: */
    ifxcor_1.is = ifxcor_1.ics;
/* L3140: */
    centr_();
    if (ifxcor_1.iaerr != 0) {
	goto L9100;
    } else {
	goto L102;
    }
L102:
    if (ishr18_1.jcr - knumbr_1.k1 != 0) {
	goto L3141;
    } else {
	goto L9999;
    }
L3141:
    if (ifxcor_1.numsur - knumbr_1.k3 >= 0) {
	goto L3150;
    } else {
	goto L3020;
    }
/*         TRY MOVING TO PS AND DS FIRST */
L3150:
    if (xdir <= 0.) {
	goto L3152;
    } else {
	goto L3151;
    }
L3151:
    xdir = (doublereal) knumbr_1.km1;
    isv1_1.j50[ifxcor_1.is - 1] = 0;
    isv1_1.j51[ifxcor_1.is - 1] = 0;
    ifxcor_1.is = ifxcor_1.ics;
    centr_();
    if (ishr18_1.jcr != 0) {
	goto L3152;
    } else {
	goto L1070;
    }
L3152:
    aerr_(&c__20205, "GO2     ", (ftnlen)8);
    goto L9100;
L9000:
    aerr_(&c__20206, "GO2     ", (ftnlen)8);
    goto L9100;
L9999:
    ifxcor_1.icl = knumbr_1.k3;
    atape_();
    if (ifxcor_1.iaerr != 0) {
	goto L9100;
    } else {
	goto L103;
    }
L103:
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&c__45);
    }
    goto L9500;
L9100:
    apt236_();
    goto L9900;
L9500:
    apt236_();
    ifxcor_1.istrup = 0;
    if (isv_1.isftyp[ifxcor_1.ips - 1] != knumbr_1.k2) {
	goto L9550;
    }
    isv_1.isftyp[ifxcor_1.ips - 1] = knumbr_1.k1;
    sv_1.past[ifxcor_1.ips - 1] = znumbr_1.z1;
L9550:
    if (isv_1.isftyp[ifxcor_1.ids - 1] != knumbr_1.k2) {
	goto L9600;
    }
    isv_1.isftyp[ifxcor_1.ids - 1] = knumbr_1.k1;
    sv_1.past[ifxcor_1.ids - 1] = znumbr_1.z1;
L9600:
    for (k = 1; k <= 3; ++k) {
	fxcor_1.temp[k - 1] = fxcor_1.te[k - 1] - fxcor_1.tek[k - 1];
	sv_1.tpk[k + ifxcor_1.ips * 3 - 4] = sv_1.tp[k + ifxcor_1.ips * 3 - 4]
		;
	sv_1.spk[k + ifxcor_1.ips * 3 - 4] = sv_1.sp[k + ifxcor_1.ips * 3 - 4]
		;
	sv_1.u1k[k + ifxcor_1.ips * 3 - 4] = sv_1.u1[k + ifxcor_1.ips * 3 - 4]
		;
	sv_1.snk[k + ifxcor_1.ips * 3 - 4] = sv_1.sn[k + ifxcor_1.ips * 3 - 4]
		;
/* L4112: */
    }
    sv_1.sk[ifxcor_1.ips * 3 - 3] = sv_1.s[ifxcor_1.ips - 1];

L9900:
    if (icnsav != knumbr_1.k1) {
	goto L9990;
    }
    for (i__ = 1; i__ <= 4; ++i__) {
/* L9910: */
	canon[i__ - 1] = cansav[i__ - 1];
    }
L9990:
    return 0;
} /* go2_ */

#undef kdynfl
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef sinl
#undef cosl
#undef can


