/* CPLAN.f -- translated by f2c (version 20100827).
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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* *** SOURCE FILE : M0000878.V07   *** */


/* .....FORTRAN SUBROUTINE             CPLAN....              4/1/68   GK */

/* Subroutine */ int cplan_(void)
{
    /* Initialized data */

    static doublereal zlit1 = .05;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal tv;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer itt, iss, its;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer isis;
    extern /* Subroutine */ int ddst_(void), apt238_(integer *);
    static doublereal temp1;
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *), ccurv_(integer *, 
	    doublereal *, doublereal *, doublereal *), u1comp_(void);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define kdynfl ((integer *)&addcom_1 + 48)
    extern /* Subroutine */ int tlnorm_(doublereal *);





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








/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






    fxcor_1.temp[19] = sv_1.rc[(560 + (0 + (ifxcor_1.is - 1 << 3)) - 560) / 8]
	    ;
/*                  TEST IF CYLINDER IT SURF,PLANE IS SURF */

    if (isv_1.ipl[ifxcor_1.is - 1] != 0) {
	goto L10;
    } else {
	goto L1010;
    }
L10:
    if (isv1_1.ifl4[ifxcor_1.is - 1] != 0) {
	goto L20;
    } else {
	goto L30;
    }
L20:
    ifxcor_1.it = ifxcor_1.ips;
    goto L50;
L30:
    ifxcor_1.it = ifxcor_1.ids;
L50:
    goto L3000;
L1010:
    cross_(&sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.snk[ifxcor_1.is * 3 - 3], 
	    fxcor_1.temp);
/* L1020: */
    vnorm_(fxcor_1.temp, fxcor_1.temp);
/* L1030: */
    if (ifxcor_1.ier != 0) {
	goto L1040;
    } else {
	goto L1050;
    }
L1050:
    temp1 = fxcor_1.temp[0] * (sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.spk[
	    ifxcor_1.is * 3 - 3]) + fxcor_1.temp[1] * (sv_1.sp[ifxcor_1.is * 
	    3 - 2] - sv_1.spk[ifxcor_1.is * 3 - 2]) + fxcor_1.temp[2] * (
	    sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.spk[ifxcor_1.is * 3 - 1]);
/* L1060: */
    fxcor_1.tem[0] = sv_1.spk[ifxcor_1.is * 3 - 3] + temp1 * fxcor_1.temp[0];
    fxcor_1.tem[1] = sv_1.spk[ifxcor_1.is * 3 - 2] + temp1 * fxcor_1.temp[1];
    fxcor_1.tem[2] = sv_1.spk[ifxcor_1.is * 3 - 1] + temp1 * fxcor_1.temp[2];
/* L1090: */
    ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], fxcor_1.tem, &sv_1.tn[
	    ifxcor_1.is * 3 - 3]);
L1120:
    if (isv1_1.ifl4[ifxcor_1.is - 1] != 0) {
	goto L1130;
    } else {
	goto L1140;
    }
L1130:
    ifxcor_1.it = ifxcor_1.ips;
    itt = ifxcor_1.ids;
    goto L1150;
L1040:
    sv_1.rc[ifxcor_1.is - 1] = fxcor_1.rc1 * d_sign(&znumbr_1.z1, &sv_1.rc[
	    ifxcor_1.is - 1]);
    goto L1120;
L1140:
    ifxcor_1.it = ifxcor_1.ids;
    itt = ifxcor_1.ips;
L1150:
    if ((d__1 = sv_1.sp[ifxcor_1.it * 3 - 1] - sv_1.spk[ifxcor_1.it * 3 - 1], 
	    abs(d__1)) - znumbr_1.z1em3 >= 0.) {
	goto L1;
    } else {
	goto L2;
    }
L2:
    fxcor_1.tem[0] = fxcor_1.ti[0];
    fxcor_1.tem[1] = fxcor_1.ti[1];
    fxcor_1.tem[2] = fxcor_1.ti[2];
    goto L5;
L1:
    cross_(&sv_1.sn[ifxcor_1.it * 3 - 3], &sv_1.sn[itt * 3 - 3], fxcor_1.tem);
    vnorm_(fxcor_1.tem, fxcor_1.tem);
    if (ifxcor_1.ier != 0) {
	goto L2;
    } else {
	goto L3;
    }
L3:
    if (fxcor_1.ti[0] * fxcor_1.tem[0] + fxcor_1.ti[1] * fxcor_1.tem[1] + 
	    fxcor_1.ti[2] * fxcor_1.tem[2] >= 0.) {
	goto L5;
    } else {
	goto L4;
    }
L4:
    fxcor_1.tem[0] = -fxcor_1.tem[0];
    fxcor_1.tem[1] = -fxcor_1.tem[1];
    fxcor_1.tem[2] = -fxcor_1.tem[2];
L5:
    isis = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.it;
    fxcor_1.temp[3] = sv_1.s[ifxcor_1.is - 1];
    fxcor_1.temp[0] = sv_1.tp[ifxcor_1.is * 3 - 3];
    fxcor_1.temp[1] = sv_1.tp[ifxcor_1.is * 3 - 2];
    fxcor_1.temp[2] = sv_1.tp[ifxcor_1.is * 3 - 1];
    sv_1.tp[ifxcor_1.is * 3 - 3] -= zlit1 * fxcor_1.tem[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] -= zlit1 * fxcor_1.tem[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] -= zlit1 * fxcor_1.tem[2];
    ddst_();
    fxcor_1.tem[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[ifxcor_1.is - 1] * 
	    sv_1.tn[ifxcor_1.is * 3 - 3];
    fxcor_1.tem[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[ifxcor_1.is - 1] * 
	    sv_1.tn[ifxcor_1.is * 3 - 2];
    fxcor_1.tem[2] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[ifxcor_1.is - 1] * 
	    sv_1.tn[ifxcor_1.is * 3 - 1];
    sv_1.tp[ifxcor_1.is * 3 - 3] = fxcor_1.temp[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = fxcor_1.temp[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = fxcor_1.temp[2];
    sv_1.s[ifxcor_1.is - 1] = fxcor_1.temp[3];
    ifxcor_1.is = isis;
/* L1200: */
    sv1_1.plncs[ifxcor_1.is - 1] = sv_1.tn[ifxcor_1.it * 3 - 3] * sv_1.tn[
	    ifxcor_1.is * 3 - 3] + sv_1.tn[ifxcor_1.it * 3 - 2] * sv_1.tn[
	    ifxcor_1.is * 3 - 2] + sv_1.tn[ifxcor_1.it * 3 - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 1];
/* L1210: */
    if (sv_1.eps2[ifxcor_1.is - 1] - (d__1 = sv1_1.plncs[ifxcor_1.is - 1], 
	    abs(d__1)) >= 0.) {
	goto L1240;
    } else {
	goto L1220;
    }
L1220:
    if (sv1_1.cplfl[ifxcor_1.is - 1] != 0.) {
	goto L1250;
    } else {
	goto L1230;
    }
L1230:
    sv1_1.dplan[ifxcor_1.is * 3 - 3] = sv_1.tn[itt * 3 - 3];
    sv1_1.dplan[ifxcor_1.is * 3 - 2] = sv_1.tn[itt * 3 - 2];
    sv1_1.dplan[ifxcor_1.is * 3 - 1] = sv_1.tn[itt * 3 - 1];
    goto L1250;
L1240:
    cross_(&sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.tn[ifxcor_1.it * 3 - 3], &
	    sv1_1.dplan[ifxcor_1.is * 3 - 3]);
L1250:
    if (isv_1.ipl[ifxcor_1.it - 1] != 0) {
	goto L1600;
    } else {
	goto L1260;
    }
/*        USE RC1   FOR PROPER UNITS/ IMPLEMENTATION */
L1600:
    if ((d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) - fxcor_1.rc1 >= 0.) {
	goto L1620;
    } else {
	goto L1610;
    }
L1610:
    fxcor_1.temp[0] = sv_1.tn[ifxcor_1.it * 3 - 3];
    fxcor_1.temp[1] = sv_1.tn[ifxcor_1.it * 3 - 2];
    fxcor_1.temp[2] = sv_1.tn[ifxcor_1.it * 3 - 1];
    goto L1380;
L1620:
    sv1_1.cptst[ifxcor_1.is - 1] = -znumbr_1.z1;
    sv_1.plnd[ifxcor_1.is - 1] = sv_1.s[ifxcor_1.is - 1];
    sv1_1.cplfl[ifxcor_1.is - 1] = -znumbr_1.z1;
    sv_1.plnv[ifxcor_1.is * 3 - 3] = sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.plnv[ifxcor_1.is * 3 - 2] = sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.plnv[ifxcor_1.is * 3 - 1] = sv_1.tn[ifxcor_1.is * 3 - 1];
L9998:
    ishr18_1.jcpr = 0;
L9999:
    sv_1.rc[ifxcor_1.is - 1] = fxcor_1.temp[19];
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&knumbr_1.k31);
    }
    return 0;
L1260:
    ccurv_(&ifxcor_1.it, &sv_1.sp[ifxcor_1.it * 3 - 3], fxcor_1.tem, &sv_1.sn[
	    ifxcor_1.it * 3 - 3]);
    if (*kdynfl != knumbr_1.k0) {
	apt238_(&knumbr_1.k34);
    }
/* L1310: */
    if ((d__1 = sv_1.rc[ifxcor_1.it - 1], abs(d__1)) - fxcor_1.rc1 >= 0.) {
	goto L1600;
    } else {
	goto L1320;
    }
L1320:
    if (isv_1.ipl[ifxcor_1.is - 1] != 0) {
	goto L1340;
    } else {
	goto L1330;
    }
L1340:
    sv_1.cc[ifxcor_1.is * 3 - 3] = sv_1.cc[ifxcor_1.it * 3 - 3];
    sv_1.cc[ifxcor_1.is * 3 - 2] = sv_1.cc[ifxcor_1.it * 3 - 2];
    sv_1.cc[ifxcor_1.is * 3 - 1] = sv_1.cc[ifxcor_1.it * 3 - 1];
    fxcor_1.temp[0] = sv_1.tn[ifxcor_1.is * 3 - 3];
    fxcor_1.temp[1] = sv_1.tn[ifxcor_1.is * 3 - 2];
    fxcor_1.temp[2] = sv_1.tn[ifxcor_1.is * 3 - 1];
    goto L1380;
L1330:
    if ((d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) - fxcor_1.rc1 >= 0.) {
	goto L1340;
    } else {
	goto L1370;
    }
L1370:
    fxcor_1.temp[0] = sv_1.cc[ifxcor_1.it * 3 - 3] - sv_1.cc[ifxcor_1.is * 3 
	    - 3];
    fxcor_1.temp[1] = sv_1.cc[ifxcor_1.it * 3 - 2] - sv_1.cc[ifxcor_1.is * 3 
	    - 2];
    fxcor_1.temp[2] = sv_1.cc[ifxcor_1.it * 3 - 1] - sv_1.cc[ifxcor_1.is * 3 
	    - 1];
    vnorm_(fxcor_1.temp, fxcor_1.temp);
    if (ifxcor_1.ier <= 0) {
	goto L1380;
    } else {
	goto L1340;
    }
L1380:
    cross_(fxcor_1.temp, &sv1_1.dplan[ifxcor_1.is * 3 - 3], &sv_1.plnv[
	    ifxcor_1.is * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.is * 3 - 3], &sv_1.plnv[ifxcor_1.is * 3 - 3]);
/* L1390: */
    if (ifxcor_1.ier != 0) {
	goto L1400;
    } else {
	goto L1410;
    }

L1400:
    ishr18_1.jcpr = 1;
    goto L9999;

/*                  FIND EXTREME POINT ON TOOL IN DIRECTION OF TEMP */

L1410:
    iss = ifxcor_1.is;
    ifxcor_1.igs = 1;
    ifxcor_1.is = ifxcor_1.igs;
    its = ifxcor_1.it;

/*                  IF TAXIS NORM IT SURF, THEN TP = TE */

    if ((i__1 = ifxcor_1.mantax - 2) < 0) {
	goto L1460;
    } else if (i__1 == 0) {
	goto L1415;
    } else {
	goto L1417;
    }
L1415:
    if (ifxcor_1.it - ifxcor_1.ips != 0) {
	goto L1460;
    } else {
	goto L1418;
    }
L1417:
    if (ifxcor_1.it - ifxcor_1.ids != 0) {
	goto L1460;
    } else {
	goto L1418;
    }
L1418:
    sv_1.tp[ifxcor_1.is * 3 - 3] = fxcor_1.te[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = fxcor_1.te[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = fxcor_1.te[2];
    goto L1470;
L1460:

    tv = fxcor_1.temp[0] * sv_1.tn[ifxcor_1.it * 3 - 3] + fxcor_1.temp[1] * 
	    sv_1.tn[ifxcor_1.it * 3 - 2] + fxcor_1.temp[2] * sv_1.tn[
	    ifxcor_1.it * 3 - 1];
    fxcor_1.tem[0] = d_sign(&znumbr_1.z1, &tv);
    sv_1.sn[ifxcor_1.is * 3 - 3] = -fxcor_1.tem[0] * fxcor_1.temp[0];
    sv_1.sn[ifxcor_1.is * 3 - 2] = -fxcor_1.tem[0] * fxcor_1.temp[1];
    sv_1.sn[ifxcor_1.is * 3 - 1] = -fxcor_1.tem[0] * fxcor_1.temp[2];
/*                  USE TLNORM TO ESTABLISH CORRECT TOOL POINT */

    sv_1.rc[ifxcor_1.is - 1] = fxcor_1.rc1;
    sv_1.cc[ifxcor_1.is * 3 - 3] = sv_1.tp[ifxcor_1.it * 3 - 3] - sv_1.rc[
	    ifxcor_1.is - 1] * sv_1.sn[ifxcor_1.is * 3 - 3];
    sv_1.cc[ifxcor_1.is * 3 - 2] = sv_1.tp[ifxcor_1.it * 3 - 2] - sv_1.rc[
	    ifxcor_1.is - 1] * sv_1.sn[ifxcor_1.is * 3 - 2];
    sv_1.cc[ifxcor_1.is * 3 - 1] = sv_1.tp[ifxcor_1.it * 3 - 1] - sv_1.rc[
	    ifxcor_1.is - 1] * sv_1.sn[ifxcor_1.is * 3 - 1];
    isv_1.jtn[ifxcor_1.is - 1] = (integer) znumbr_1.z0;
    u1comp_();

    isv_1.itseg[ifxcor_1.is - 1] = 1;
    isv_1.itlon[ifxcor_1.is - 1] = isv_1.itlon[iss - 1];
    isv_1.iafl[ifxcor_1.is - 1] = -1;
    isv_1.jtlflg[ifxcor_1.is - 1] = isv_1.jtlflg[iss - 1];
    isv_1.ipl[ifxcor_1.is - 1] = (integer) znumbr_1.z1;
    tlnorm_(&sv_1.u1[ifxcor_1.is * 3 - 3]);

/*                  COMPUTE MOVE TO BRING THIS TP ON TO THE CPLAN */

L1470:
    sv_1.plnd[iss - 1] = sv_1.plnv[iss * 3 - 3] * (sv_1.cc[iss * 3 - 3] - 
	    sv_1.tp[ifxcor_1.is * 3 - 3]) + sv_1.plnv[iss * 3 - 2] * (sv_1.cc[
	    iss * 3 - 2] - sv_1.tp[ifxcor_1.is * 3 - 2]) + sv_1.plnv[iss * 3 
	    - 1] * (sv_1.cc[iss * 3 - 1] - sv_1.tp[ifxcor_1.is * 3 - 1]);

/*                  RETURN */

    ifxcor_1.is = iss;
    ifxcor_1.it = its;
/* L1510: */
    sv1_1.cplfl[ifxcor_1.is - 1] = 1.f;
L1520:
    sv1_1.cptst[ifxcor_1.is - 1] += sv1_1.cplfl[ifxcor_1.is - 1];
/* L1530: */
    if (sv1_1.cptst[ifxcor_1.is - 1] != 0.) {
	goto L9998;
    } else {
	goto L1520;
    }

/*                  SPECIAL ROUTE FOR CYLINDER IT SURF + PLANE IS SURF */
/*                  COMPUTE CPLAN POISTION FROM CANONICAL FORMS */

L3000:
    if (isv_1.isfidn[ifxcor_1.it - 1] > knumbr_1.k4 || isv_1.isfidn[
	    ifxcor_1.it - 1] < knumbr_1.k3) {
	goto L1010;
    }
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.it - 1];
    fxcor_1.temp[6] = canon[ifxcor_1.ic + 2];
    fxcor_1.temp[7] = canon[ifxcor_1.ic + 3];
    fxcor_1.temp[8] = canon[ifxcor_1.ic + 4];
    cross_(&fxcor_1.temp[6], &sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.plnv[
	    ifxcor_1.is * 3 - 3]);
    vnorm_(&sv_1.plnv[ifxcor_1.is * 3 - 3], &sv_1.plnv[ifxcor_1.is * 3 - 3]);

    sv_1.cc[ifxcor_1.is * 3 - 3] = canon[ifxcor_1.ic - 1];
    sv_1.cc[ifxcor_1.is * 3 - 2] = canon[ifxcor_1.ic];
    sv_1.cc[ifxcor_1.is * 3 - 1] = canon[ifxcor_1.ic + 1];
    sv1_1.plncs[ifxcor_1.is - 1] = sv_1.tn[ifxcor_1.it * 3 - 3] * sv_1.tn[
	    ifxcor_1.is * 3 - 3] + sv_1.tn[ifxcor_1.it * 3 - 2] * sv_1.tn[
	    ifxcor_1.is * 3 - 2] + sv_1.tn[ifxcor_1.it * 3 - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 1];
    fxcor_1.temp[0] = sv_1.tn[ifxcor_1.is * 3 - 3];
    fxcor_1.temp[1] = sv_1.tn[ifxcor_1.is * 3 - 2];
    fxcor_1.temp[2] = sv_1.tn[ifxcor_1.is * 3 - 1];
    goto L1410;
} /* cplan_ */

#undef kdynfl
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef sinl
#undef cosl
#undef can


