/* ARLM3.f -- translated by f2c (version 20100827).
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
    doublereal talt[3], svgl, shilf, gflg, tpg[3], spg[3];
} cgoug_;

#define cgoug_1 cgoug_

/* *** SOURCE FILE : M0004302.W04   *** */

/* .....FORTRAN SUBROUTINE   ...ARLM3              8/68                PH */
/* .....FORTRAN SUBROUTINE             ARLM3...               4/8/68   GK */
/* Subroutine */ int arlm3_(void)
{
    /* Initialized data */

    static integer k14 = 14;
    static integer k17 = 17;
    static integer k20 = 20;
    static integer k21 = 21;
    static integer k22 = 22;
    static doublereal zero = 0.;
    static doublereal zlit1 = .125;
    static integer k11 = 11;

    /* Format strings */
    static char fmt_175[] = "";
    static char fmt_190[] = "";
    static char fmt_230[] = "";
    static char fmt_330[] = "";
    static char fmt_360[] = "";
    static char fmt_440[] = "";
    static char fmt_550[] = "";
    static char fmt_560[] = "";
    static char fmt_565[] = "";
    static char fmt_630[] = "";
    static char fmt_635[] = "";
    static char fmt_740[] = "";
    static char fmt_745[] = "";
    static char fmt_760[] = "";
    static char fmt_810[] = "";
    static char fmt_820[] = "";
    static char fmt_846[] = "";
    static char fmt_875[] = "";
    static char fmt_950[] = "";
    static char fmt_980[] = "";
    static char fmt_1000[] = "";
    static char fmt_1025[] = "";
    static char fmt_1140[] = "";
    static char fmt_1145[] = "";
    static char fmt_1220[] = "";
    static char fmt_1260[] = "";
    static char fmt_1265[] = "";
    static char fmt_1348[] = "";
    static char fmt_1350[] = "";
    static char fmt_1415[] = "";
    static char fmt_1430[] = "";
    static char fmt_1445[] = "";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal ps1, ps2, ps3, ps4, ps5, ps6, ps7, ps8, ps9, ds1, ds2, 
	    ds3, ds4, ds5, ds6, ds7, ds8, ds9, aab, tv;
    static integer jaa, jwr, jpr1, jpr2, ils1;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer isto;
    static doublereal rc1sc;
    extern /* Subroutine */ int apt238_(integer *);
    static doublereal u1sav[3];
    extern /* Subroutine */ int check_(void), amind_(void), delta_(void), 
	    atape_(void), plane_(void);
    static doublereal tnsav[3], tpsav[3];
#define elmax ((doublereal *)&addcom_1)
    static doublereal vtsav[3], spsav[3];
    static integer inmbr, iretn, itsav;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);
    static integer ipchn;
    extern /* Subroutine */ int centr_(void);
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
    static integer ipchnl;
#define kdynfl ((integer *)&addcom_1 + 48)

    /* Assigned format variables */
    static char *iretn_fmt;






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





/* ...  21. ADDCOM BLOCK */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */








/*        USE RC1SC FOR PROPER UNITS/ IMPLEMENTATION */
    rc1sc = fxcor_1.rc1 / 4500.;
    cgoug_1.gflg = zero;
    ifxcor_1.numpt1 = ifxcor_1.nmpnts;
    *clngth = (doublereal) knumbr_1.k0;
    jpr1 = knumbr_1.k0;
    jpr2 = ifxcor_1.icscnt;
    ils1 = ifxcor_1.ics + (ifxcor_1.icscnt - knumbr_1.k1) * ifxcor_1.lsv1;
/*                  INITIALIZATION FOR EACH CS. */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
	dshar4_1.tew[i__ - 1] = fxcor_1.te[i__ - 1];
/* L100: */
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
    }
    if (isv_1.ipl[ifxcor_1.ips - 1] == knumbr_1.k0 || isv_1.ipl[ifxcor_1.ids 
	    - 1] == knumbr_1.k0) {
	goto L130;
    }
    ishr18_1.ipdpl = knumbr_1.k1;
    goto L140;
L130:
    ishr18_1.ipdpl = 0;
L140:
    for (i__ = 1; i__ <= 3; ++i__) {
/* ... SAVE PREVIOUS TI VALUE IN TALT */
	cgoug_1.talt[i__ - 1] = fxcor_1.ti[i__ - 1];
	fxcor_1.tik[i__ - 1] = fxcor_1.ti[i__ - 1];
	i__1 = ils1;
	i__2 = ifxcor_1.lsv1;
	for (k = ifxcor_1.ics; i__2 < 0 ? k >= i__1 : k <= i__1; k += i__2) {
	    sv_1.tn[i__ + k * 3 - 4] = fxcor_1.ti[i__ - 1];
/* L150: */
	}
    }
L160:
    ishr18_1.j12 = 0;
    jaa = knumbr_1.k0;
    ifxcor_1.is = ifxcor_1.ics;
    ishr18_1.j10 = knumbr_1.k1;
    dshar4_1.dp = fxcor_1.dpmax;
    dshar4_1.dpl = fxcor_1.dpmax;
    i__2 = ils1;
    i__1 = ifxcor_1.lsv1;
    for (i__ = ifxcor_1.ics; i__1 < 0 ? i__ >= i__2 : i__ <= i__2; i__ += 
	    i__1) {
	isv1_1.j20[i__ - 1] = 0;
	isv1_1.j23[i__ - 1] = knumbr_1.k1;
	isv1_1.j50[i__ - 1] = -ishr18_1.ipdpl;
	isv1_1.j51[i__ - 1] = 0;
	isv1_1.jph[i__ - 1] = 0;
	isv1_1.notan[i__ - 1] = 0;
/* L170: */
	sv1_1.dpmx1[i__ - 1] = fxcor_1.dpmax;
    }
    inmbr = k11;
    iretn = 0;
    iretn_fmt = fmt_175;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L175:
    if (ishr18_1.ipdpl != 0) {
	goto L180;
    } else {
	goto L310;
    }
/*                  CALL CHECK FOR CSD. ADJUST DP SO CS NOT PASSED ON */
/*                  FIRST DP STEP-OUT. */
L180:
    inmbr = knumbr_1.k12;
    iretn = 1;
    iretn_fmt = fmt_190;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L190:
    for (l = 1; l <= 3; ++l) {
/* L200: */
	fxcor_1.ta[l - 1] = fxcor_1.tak[l - 1];
    }
L210:
    ifxcor_1.is = ifxcor_1.ics;
    jpr2 = -knumbr_1.k1;
    ishr18_1.iws = ifxcor_1.is;
    dshar4_1.dp1 = znumbr_1.z1e6 * rc1sc;
L220:
    if (isv_1.isftyp[ifxcor_1.is - 1] - 99 >= 0) {
	goto L460;
    } else {
	goto L221;
    }
L221:
    fxcor_1.te[0] = dshar4_1.tew[0];
    fxcor_1.te[1] = dshar4_1.tew[1];
    fxcor_1.te[2] = dshar4_1.tew[2];
    jpr2 = ifxcor_1.icscnt;
    iretn = 2;
    iretn_fmt = fmt_230;
    goto L9010;
L230:
    if (ifxcor_1.ier != 0) {
/* .... OUTPUT WARNING IF NEGATIVE DISTANCE TO CS AT START OF CUT */
	inmbr = -24007;
	aerr_(&inmbr, "ARLM3", (ftnlen)5);
    }
    isv1_1.j50[ifxcor_1.is - 1] = (isv1_1.j50[ifxcor_1.is - 1] + knumbr_1.k1) 
	    / knumbr_1.k2;
/* L231: */
    if (znumbr_1.z1 * rc1sc - sv1_1.csd[ifxcor_1.is - 1] >= 0.) {
	goto L238;
    } else {
	goto L232;
    }
L232:
    if (ishr18_1.ipdpl != 0) {
	goto L236;
    } else {
	goto L260;
    }
L260:
    if (dshar4_1.dp - sv1_1.csd[ifxcor_1.is - 1] <= 0.) {
	goto L234;
    } else {
	goto L239;
    }
L234:
    if (sv1_1.csd[ifxcor_1.is - 1] - znumbr_1.z2 * dshar4_1.dp >= 0.) {
	goto L241;
    } else {
	goto L235;
    }
L235:
    dshar4_1.dp = znumbr_1.z6em1 * sv1_1.csd[ifxcor_1.is - 1];
    goto L241;
L236:
    if (sv1_1.csd[ifxcor_1.is - 1] - dshar4_1.dp <= 0.) {
	goto L237;
    } else {
	goto L241;
    }
L237:
    dshar4_1.dp = znumbr_1.z9em1 * sv1_1.csd[ifxcor_1.is - 1];
    goto L241;
L238:
    if ((d__1 = sv1_1.csd[ifxcor_1.is - 1], abs(d__1)) - sv_1.tau[ifxcor_1.is 
	    - 1] >= 0.) {
	goto L260;
    } else {
	goto L240;
    }
L239:
    dshar4_1.dp = sv1_1.csd[ifxcor_1.is - 1];
    goto L241;
L240:
    dshar4_1.dp = sv_1.tau[ifxcor_1.is - 1];
L241:
    goto L430;
/*                  DS AND PS NOT BOTH PLANE. THUS INITIAL STEP-OUT + */
/*                  CENTR + DELTA FOR INITIAL VALUE DP. */
L310:
    for (l = 1; l <= 3; ++l) {
/* L320: */
	fxcor_1.te[l - 1] += zlit1 * rc1sc * fxcor_1.ti[l - 1];
    }
    iretn = 3;
    iretn_fmt = fmt_330;
    goto L9020;
L330:
    if (ishr18_1.jcr == knumbr_1.k0) {
	goto L350;
    }
    dshar4_1.dp = znumbr_1.z1em2 * fxcor_1.dpmax;
    goto L180;
L350:
    iretn = 4;
    iretn_fmt = fmt_360;
    goto L9030;
L360:
    if (ishr18_1.jdr != knumbr_1.k0) {
	goto L180;
    }
    if (dshar4_1.dpl > fxcor_1.dpmax) {
	goto L390;
    }
    dshar4_1.dp = dshar4_1.dpl;
    goto L180;

L390:
    dshar4_1.dp = fxcor_1.dpmax;
    goto L180;
/*                  DO ADJUSTMENT OF DP FOR ALL CS. SET DP TO ITS MIN */
/*                  VALUE, AND IWS TO THE CORRESPONDING IS. */
L430:
    inmbr = knumbr_1.k13;
    iretn = 5;
    iretn_fmt = fmt_440;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L440:
    if (dshar4_1.dp - dshar4_1.dp1 >= 0.) {
	goto L460;
    } else {
	goto L450;
    }
L450:
    ishr18_1.iws = ifxcor_1.is;
    dshar4_1.dp1 = dshar4_1.dp;
L460:
    ifxcor_1.is += ifxcor_1.lsv1;
    if (ils1 >= ifxcor_1.is) {
	goto L220;
    }
    ifxcor_1.is = ishr18_1.iws;
    if (jpr2 >= 0) {
	goto L462;
    } else {
	goto L461;
    }
L461:
    inmbr = 24006;
    goto L9040;
/*                  SET DPCNT TO 10. (ERROR 801 WHEN 0.0). IF CS NEAR */
/*                  (J50=1) AND PS,DS NOT BOTH PLANE THEN BRANCH */
L462:
    dshar4_1.dpcnt = 30.f;
    dshar4_1.dp = dshar4_1.dp1;
    if (isv1_1.j50[ifxcor_1.is - 1] > knumbr_1.k0 && ishr18_1.ipdpl == 
	    knumbr_1.k0) {
	goto L750;
    }
L490:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L500: */
	fxcor_1.tel[i__ - 1] = fxcor_1.te[i__ - 1];
    }
    if (ishr18_1.ipdpl != knumbr_1.k0) {
	goto L600;
    }
    itsav = isv_1.itseg[ifxcor_1.ips - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	tnsav[i__ - 1] = sv_1.tn[i__ + ifxcor_1.ips * 3 - 4];
	tpsav[i__ - 1] = sv_1.tp[i__ + ifxcor_1.ips * 3 - 4];
	u1sav[i__ - 1] = sv_1.u1[i__ + ifxcor_1.ips * 3 - 4];
	vtsav[i__ - 1] = sv_1.vt[i__ + ifxcor_1.ips * 3 - 4];
	spsav[i__ - 1] = sv_1.sp[i__ + ifxcor_1.ips * 3 - 4];
/* L520: */
	dshar4_1.tes[i__ - 1] = fxcor_1.tek[i__ - 1];
    }
/*                  ********** MAIN LOOP. STEP-OUT DP. ***************** */
/*                  ***** BRANCH IF DS,PS BOTH PLANE. ELSE CENTR TO **** */
/*                  ***** PS,DS AND THEN DELTA. IF CUT VECTOR TOO   **** */
/*                  ***** LONG (JDR=1),THEN TRY AGAIN WITH SHORTER  **** */
/*                  ***** CUT VECTOR. IF DPCNT=1, FAIL           ******* */
/*                        CODING 580 TO 600 FOR SETTING CS FAR AWAY */
L530:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.ta[i__ - 1] = fxcor_1.tak[i__ - 1];
	dshar4_1.cmove[i__ - 1] = dshar4_1.dp * fxcor_1.tik[i__ - 1];
/* L540: */
	fxcor_1.te[i__ - 1] = dshar4_1.tes[i__ - 1] + dshar4_1.cmove[i__ - 1];
    }
    inmbr = k14;
    iretn = 6;
    iretn_fmt = fmt_550;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L550:
    if (ishr18_1.ipdpl != knumbr_1.k0) {
	goto L1250;
    }
    iretn = 7;
    iretn_fmt = fmt_560;
    goto L9020;
L560:
    inmbr = knumbr_1.k15;
    iretn = 8;
    iretn_fmt = fmt_565;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L565:
    if (ishr18_1.jcr == knumbr_1.k0) {
	goto L620;
    }
    if (dshar4_1.dpcnt > znumbr_1.z1) {
	goto L636;
    }
    inmbr = 24001;
    goto L9040;
L580:
    isv1_1.j20[ifxcor_1.is - 1] = knumbr_1.k1;
    isv1_1.j21[ifxcor_1.is - 1] = knumbr_1.k1;
    sv1_1.csd[ifxcor_1.is - 1] = znumbr_1.z0;
    sv1_1.stck[ifxcor_1.is - 1] = znumbr_1.z1;
    isv1_1.jph[ifxcor_1.is - 1] = knumbr_1.k1;
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] = fxcor_1.tek[i__ - 1];
/* L590: */
	fxcor_1.ta[i__ - 1] = fxcor_1.tak[i__ - 1];
    }
    isv1_1.j50[ifxcor_1.is - 1] = 0;
    isv1_1.j51[ifxcor_1.is - 1] = 0;
    goto L490;
L600:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L610: */
	dshar4_1.tes[i__ - 1] = fxcor_1.te[i__ - 1];
    }
    goto L530;
L620:
    ishr18_1.j10 = 0;
    iretn = 9;
    iretn_fmt = fmt_630;
    goto L9030;
L630:
    inmbr = knumbr_1.k16;
    iretn = 10;
    iretn_fmt = fmt_635;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L635:
    if (ishr18_1.jdr == knumbr_1.k0) {
	goto L700;
    }
    if (dshar4_1.dpcnt == znumbr_1.z1) {
	goto L1460;
    }
L636:
    dshar4_1.dpcnt -= znumbr_1.z1;
    isv_1.itseg[ifxcor_1.ips - 1] = itsav;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tp[i__ + ifxcor_1.ips * 3 - 4] = tpsav[i__ - 1];
	sv_1.tn[i__ + ifxcor_1.ips * 3 - 4] = tnsav[i__ - 1];
	sv_1.u1[i__ + ifxcor_1.ips * 3 - 4] = u1sav[i__ - 1];
	sv_1.vt[i__ + ifxcor_1.ips * 3 - 4] = vtsav[i__ - 1];
	sv_1.sp[i__ + ifxcor_1.ips * 3 - 4] = spsav[i__ - 1];
/* L660: */
    }
    goto L530;
/*                  CUT VECTOR OKED BY DELTA. COMPUTE NEW TI */
L670:
    if (fxcor_1.ti[0] * fxcor_1.tik[0] + fxcor_1.ti[1] * fxcor_1.tik[1] + 
	    fxcor_1.ti[2] * fxcor_1.tik[2] >= 0.) {
	goto L730;
    } else {
	goto L680;
    }
L680:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L690: */
	fxcor_1.ti[i__ - 1] = -fxcor_1.ti[i__ - 1];
    }
    goto L730;
L700:
    for (i__ = 1; i__ <= 3; ++i__) {
	cgoug_1.talt[i__ - 1] = fxcor_1.ti[i__ - 1];
/* L701: */
    }
    cross_(&sv_1.sn[ifxcor_1.ips * 3 - 3], &sv_1.sn[ifxcor_1.ids * 3 - 3], 
	    fxcor_1.ti);
    vnorm_(fxcor_1.ti, fxcor_1.ti);
    if (ifxcor_1.ier != 0) {
	goto L710;
    } else {
	goto L670;
    }
L710:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L720: */
	fxcor_1.ti[i__ - 1] = fxcor_1.te[i__ - 1] - fxcor_1.tek[i__ - 1];
    }
    vnorm_(fxcor_1.ti, fxcor_1.ti);
/*                  CALL CHECK FOR CSD. IF JCKR = 0, CS NOT NEAR AND TE */
/*                  IS OUTPUT TO ATAPE. IF JCKR = 1, CS NEAR. THEN SET */
/*                  TEE TO TE AND DO 3 SURF CENTR,DS,PS,CS. */
L730:
    iretn = 11;
    iretn_fmt = fmt_740;
    goto L9010;
L740:
    inmbr = k17;
    iretn = 12;
    iretn_fmt = fmt_745;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L745:
    if (ishr18_1.jckr == knumbr_1.k0) {
	goto L840;
    }
L750:
    sv1_1.tee[ifxcor_1.is * 3 - 3] = fxcor_1.te[0];
    sv1_1.tee[ifxcor_1.is * 3 - 2] = fxcor_1.te[1];
    sv1_1.tee[ifxcor_1.is * 3 - 1] = fxcor_1.te[2];
    iretn = 13;
    iretn_fmt = fmt_760;
    goto L9020;
/*                  JCR RETURN FROM 3 SURF PS,DS,CS CENTR  HAS 3 VALUES. */
/*                  JCR =-1,RESTART CONDITION. IF GT 1 CS, SET FIRST */
/*                  CS FAR AWAY. STEP-OUT DP ETC. JCR =2, FALSE TANGENCY. */
/*                  IN THIS CASE IF CENTR MOVE IN TI DIRECTION, RESET */
/*                  CS FAR AWAY. OTHERWISE IGNORE THIS CENTR MOVE. */
/*                  IF JCR=0, 3 SURF O.K. GO TO 940. */
L760:
    if ((i__1 = ishr18_1.jcr - knumbr_1.k1) < 0) {
	goto L770;
    } else if (i__1 == 0) {
	goto L940;
    } else {
	goto L790;
    }
L770:
    if (ifxcor_1.icscnt > knumbr_1.k1) {
	goto L830;
    }
    inmbr = 24002;
    goto L9040;
L790:
    if ((fxcor_1.te[0] - sv1_1.tee[ifxcor_1.is * 3 - 3]) * fxcor_1.ti[0] + (
	    fxcor_1.te[1] - sv1_1.tee[ifxcor_1.is * 3 - 2]) * fxcor_1.ti[1] + 
	    (fxcor_1.te[2] - sv1_1.tee[ifxcor_1.is * 3 - 1]) * fxcor_1.ti[2] 
	    <= 0.) {
	goto L800;
    } else {
	goto L1090;
    }
L800:
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z0;
    fxcor_1.te[0] = sv1_1.tee[ifxcor_1.is * 3 - 3];
    fxcor_1.te[1] = sv1_1.tee[ifxcor_1.is * 3 - 2];
    fxcor_1.te[2] = sv1_1.tee[ifxcor_1.is * 3 - 1];
    isto = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ips;
    iretn = 14;
    iretn_fmt = fmt_810;
    goto L9050;
L810:
    ifxcor_1.is = ifxcor_1.ids;
    iretn = 15;
    iretn_fmt = fmt_820;
    goto L9050;
L820:
    ifxcor_1.is = isto;
    goto L840;
L830:
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z5 * dshar4_1.dp;
    goto L180;
/*                  CS NOT REACHED IN DP STEP-OUT. THEREFORE TE OUTPUT.** */
/*                  CHECK NMPNTS AND CLNGTH O.K. UPDATE TEK ETC */
L840:
    iretn = 16;
    iretn_fmt = fmt_846;
    goto L9060;
L846:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L847: */
	fxcor_1.temp[i__ - 1] = fxcor_1.te[i__ - 1] - fxcor_1.tek[i__ - 1];
    }
/* L848: */
    fxcor_1.temp[3] = sqrt(fxcor_1.temp[0] * fxcor_1.temp[0] + fxcor_1.temp[1]
	     * fxcor_1.temp[1] + fxcor_1.temp[2] * fxcor_1.temp[2]);
    *clngth += fxcor_1.temp[3];
    if (*elmax - *clngth >= 0.) {
	goto L850;
    } else {
	goto L849;
    }
L849:
    inmbr = 24005;
    goto L9040;
L850:
    if (ifxcor_1.numpt1 > knumbr_1.k0) {
	goto L870;
    }
    inmbr = 24003;
    goto L9040;
L870:
    ifxcor_1.numpt1 -= knumbr_1.k1;
    inmbr = knumbr_1.k18;
    iretn = 17;
    iretn_fmt = fmt_875;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L875:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
	fxcor_1.tik[i__ - 1] = fxcor_1.ti[i__ - 1];
	i__1 = ifxcor_1.numsur;
	for (j = ifxcor_1.ips; j <= i__1; ++j) {
	    sv_1.tpk[i__ + j * 3 - 4] = sv_1.tp[i__ + j * 3 - 4];
	    sv_1.spk[i__ + j * 3 - 4] = sv_1.sp[i__ + j * 3 - 4];
	    sv_1.snk[i__ + j * 3 - 4] = sv_1.sn[i__ + j * 3 - 4];
	    sv_1.sk[i__ + j * 3 - 4] = sv_1.s[j - 1];
	    sv_1.u1k[i__ + j * 3 - 4] = sv_1.u1[i__ + j * 3 - 4];
/* L900: */
	}
    }
    ipchnl = ipchn;
    dshar4_1.dp1 = dshar4_1.dp;
    isv_1.itsegk[ifxcor_1.ips - 1] = isv_1.itseg[ifxcor_1.ips - 1];
    isv_1.itsegk[ifxcor_1.ids - 1] = isv_1.itseg[ifxcor_1.ids - 1];
    if (isv1_1.j20[ifxcor_1.is - 1] != knumbr_1.k2) {
	goto L920;
    }
/*                  TERMINATING CUT SEQUENCE COMPUTATION. RESTORE SURF */
/*                  DATA AT TEE POSITION. */
    fxcor_1.te[0] = sv1_1.tee[ifxcor_1.is * 3 - 3];
    fxcor_1.te[1] = sv1_1.tee[ifxcor_1.is * 3 - 2];
    fxcor_1.te[2] = sv1_1.tee[ifxcor_1.is * 3 - 1];
    fxcor_1.ta[0] = fxcor_1.tal[0];
    fxcor_1.ta[1] = fxcor_1.tal[1];
    fxcor_1.ta[2] = fxcor_1.tal[2];
    sv_1.tp[ifxcor_1.ips * 3 - 3] = ps1;
    sv_1.tp[ifxcor_1.ips * 3 - 2] = ps2;
    sv_1.tp[ifxcor_1.ips * 3 - 1] = ps3;
    sv_1.sn[ifxcor_1.ips * 3 - 3] = ps4;
    sv_1.sn[ifxcor_1.ips * 3 - 2] = ps5;
    sv_1.sn[ifxcor_1.ips * 3 - 1] = ps6;
    sv_1.sp[ifxcor_1.ips * 3 - 3] = ps7;
    sv_1.sp[ifxcor_1.ips * 3 - 2] = ps8;
    sv_1.sp[ifxcor_1.ips * 3 - 1] = ps9;
    sv_1.tp[ifxcor_1.ids * 3 - 3] = ds1;
    sv_1.tp[ifxcor_1.ids * 3 - 2] = ds2;
    sv_1.tp[ifxcor_1.ids * 3 - 1] = ds3;
    sv_1.sn[ifxcor_1.ids * 3 - 3] = ds4;
    sv_1.sn[ifxcor_1.ids * 3 - 2] = ds5;
    sv_1.sn[ifxcor_1.ids * 3 - 1] = ds6;
    sv_1.sp[ifxcor_1.ids * 3 - 3] = ds7;
    sv_1.sp[ifxcor_1.ids * 3 - 2] = ds8;
    sv_1.sp[ifxcor_1.ids * 3 - 1] = ds9;
    goto L1070;
/*                  NON-TERMINATING CUT VECTOR. IF MORE THAN ONE CS, */
/*                  RETURN TO FIND CRITICAL CS.ELSE GO TO DP STEP-OUT. */
L920:
    ifxcor_1.is = ifxcor_1.ics;
    if (ifxcor_1.icscnt <= knumbr_1.k1) {
	goto L260;
    }
    dshar4_1.tew[0] = fxcor_1.te[0];
    dshar4_1.tew[1] = fxcor_1.te[1];
    dshar4_1.tew[2] = fxcor_1.te[2];
    goto L220;
/*                  3 SURF CENTR TO PS,DS,CS O.K. IF ANY CS VIOLATED */
/*                  IN THIS MOVE,INDEX THIS AS CRITICAL CS,AND AGAIN DO */
/*                  3 SURF CENTR. */
L940:
    sv1_1.tee[ifxcor_1.is * 3 - 3] = fxcor_1.te[0];
    sv1_1.tee[ifxcor_1.is * 3 - 2] = fxcor_1.te[1];
    sv1_1.tee[ifxcor_1.is * 3 - 1] = fxcor_1.te[2];
    ishr18_1.iws = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ics;
    inmbr = knumbr_1.k19;
    iretn = 18;
    iretn_fmt = fmt_950;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L950:
    if (ifxcor_1.is > ils1) {
	goto L1040;
    }
    if (ifxcor_1.is == ishr18_1.iws) {
	goto L1030;
    }
    iretn = 19;
    iretn_fmt = fmt_980;
    goto L9050;
L980:
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k4 != 0) {
	goto L981;
    } else {
	goto L1010;
    }
L981:
    if (isv1_1.j23[ifxcor_1.is - 1] > knumbr_1.k0) {
	goto L1030;
    }
    sv1_1.stck[ifxcor_1.is - 1] = sv_1.s[ifxcor_1.is - 1] * sv_1.z__[
	    ifxcor_1.is - 1] * sv1_1.stck1[ifxcor_1.is - 1];
    inmbr = k20;
    iretn = 20;
    iretn_fmt = fmt_1000;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1000:
    if (sv1_1.stck[ifxcor_1.is - 1] <= 0.) {
	goto L750;
    } else {
	goto L1030;
    }
L1010:
    if (isv1_1.j22[ifxcor_1.is - 1] <= 0) {
	goto L1030;
    } else {
	goto L1020;
    }
L1020:
    ifxcor_1.it = ifxcor_1.ids;
    if (isv1_1.ifl4[ifxcor_1.is - 1] != 0) {
	goto L1021;
    } else {
	goto L1022;
    }
L1021:
    ifxcor_1.it = ifxcor_1.ips;
L1022:
    fxcor_1.temp[0] = (sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.sp[ifxcor_1.it * 3 
	    - 3]) * sv_1.tn[ifxcor_1.is * 3 - 3] + (sv_1.sp[ifxcor_1.is * 3 - 
	    2] - sv_1.sp[ifxcor_1.it * 3 - 2]) * sv_1.tn[ifxcor_1.is * 3 - 2] 
	    + (sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.sp[ifxcor_1.it * 3 - 1]) * 
	    sv_1.tn[ifxcor_1.is * 3 - 1];
    sv1_1.stckn[ifxcor_1.is - 1] = fxcor_1.temp[0] * (sv_1.tn[ifxcor_1.is * 3 
	    - 3] * fxcor_1.ti[0] + sv_1.tn[ifxcor_1.is * 3 - 2] * fxcor_1.ti[
	    1] + sv_1.tn[ifxcor_1.is * 3 - 1] * fxcor_1.ti[2]);
    inmbr = k21;
    iretn = 21;
    iretn_fmt = fmt_1025;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1025:
    if (sv1_1.stckn[ifxcor_1.is - 1] <= 0.) {
	goto L750;
    } else {
	goto L1030;
    }
L1030:
    ifxcor_1.is += ifxcor_1.lsv1;
    goto L950;
/*                  CRITICAL CS INDEXED. COMPUTE TI AND SAVE SURF DATA. */
/*                  COMPUTE V=TEE - TEK. IF THIS MOVE BACKWARDS,SET */
/*                  S = 5*DP TO  SET THIS CS FAR AWAY */
L1040:
    ifxcor_1.is = ishr18_1.iws;
    fxcor_1.tal[0] = fxcor_1.ta[0];
    fxcor_1.tal[1] = fxcor_1.ta[1];
    fxcor_1.tal[2] = fxcor_1.ta[2];
    cross_(&sv_1.sn[ifxcor_1.ips * 3 - 3], &sv_1.sn[ifxcor_1.ids * 3 - 3], 
	    fxcor_1.til);
    vnorm_(fxcor_1.til, fxcor_1.til);
    if (ifxcor_1.ier == knumbr_1.k0) {
	goto L1060;
    }
    fxcor_1.til[0] = fxcor_1.te[0] - fxcor_1.tek[0];
    fxcor_1.til[1] = fxcor_1.te[1] - fxcor_1.tek[1];
    fxcor_1.til[2] = fxcor_1.te[2] - fxcor_1.tek[2];
    vnorm_(fxcor_1.til, fxcor_1.til);
L1060:
    ps1 = sv_1.tp[ifxcor_1.ips * 3 - 3];
    ps2 = sv_1.tp[ifxcor_1.ips * 3 - 2];
    ps3 = sv_1.tp[ifxcor_1.ips * 3 - 1];
    ps4 = sv_1.sn[ifxcor_1.ips * 3 - 3];
    ps5 = sv_1.sn[ifxcor_1.ips * 3 - 2];
    ps6 = sv_1.sn[ifxcor_1.ips * 3 - 1];
    ps7 = sv_1.sp[ifxcor_1.ips * 3 - 3];
    ps8 = sv_1.sp[ifxcor_1.ips * 3 - 2];
    ps9 = sv_1.sp[ifxcor_1.ips * 3 - 1];
    ds1 = sv_1.tp[ifxcor_1.ids * 3 - 3];
    ds2 = sv_1.tp[ifxcor_1.ids * 3 - 2];
    ds3 = sv_1.tp[ifxcor_1.ids * 3 - 1];
    ds4 = sv_1.sn[ifxcor_1.ids * 3 - 3];
    ds5 = sv_1.sn[ifxcor_1.ids * 3 - 2];
    ds6 = sv_1.sn[ifxcor_1.ids * 3 - 1];
    ds7 = sv_1.sp[ifxcor_1.ids * 3 - 3];
    ds8 = sv_1.sp[ifxcor_1.ids * 3 - 2];
    ds9 = sv_1.sp[ifxcor_1.ids * 3 - 1];
L1070:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1080: */
	dshar4_1.v[i__ - 1] = fxcor_1.te[i__ - 1] - fxcor_1.tek[i__ - 1];
    }
    aab = dshar4_1.v[0] * fxcor_1.tik[0] + dshar4_1.v[1] * fxcor_1.tik[1] + 
	    dshar4_1.v[2] * fxcor_1.tik[2];
/*     IF(DABS(AAB)- 0.2*TAU(IS))1090,1090,1085 */
/* L1085: */
    if (aab >= 0.) {
	goto L1100;
    } else {
	goto L1090;
    }
L1090:
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z5 * dshar4_1.dp;
    goto L580;
/*                  MOVE V FORWARD. REVERSE TN(CS) AND RE-DO 3 SURF */
/*                  CENTR FOR 'PAST' CASE. TEST IF V O.K. BY DELTA */
L1100:
    dshar4_1.vl = sqrt(dshar4_1.v[0] * dshar4_1.v[0] + dshar4_1.v[1] * 
	    dshar4_1.v[1] + dshar4_1.v[2] * dshar4_1.v[2]);
    if (isv_1.isftyp[ifxcor_1.is - 1] == knumbr_1.k4) {
	goto L1130;
    }
    if ((sv_1.tn[ifxcor_1.is * 3 - 3] * (fxcor_1.te[0] - fxcor_1.tek[0]) + 
	    sv_1.tn[ifxcor_1.is * 3 - 2] * (fxcor_1.te[1] - fxcor_1.tek[1]) + 
	    sv_1.tn[ifxcor_1.is * 3 - 1] * (fxcor_1.te[2] - fxcor_1.tek[2])) *
	     sv_1.past[ifxcor_1.is - 1] >= 0.) {
	goto L1130;
    } else {
	goto L1120;
    }
L1120:
    isv1_1.j50[ifxcor_1.is - 1] = knumbr_1.k1;
    isv1_1.j51[ifxcor_1.is - 1] = knumbr_1.k1;
    sv1_1.plnd1[ifxcor_1.is - 1] = 0.;
    isv1_1.notan[ifxcor_1.is - 1] = 0;
    sv_1.tn[ifxcor_1.is * 3 - 3] = -sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = -sv_1.tn[ifxcor_1.is * 3 - 2];
    sv_1.tn[ifxcor_1.is * 3 - 1] = -sv_1.tn[ifxcor_1.is * 3 - 1];
    goto L750;
L1130:
    ishr18_1.j10 = knumbr_1.k1;
    iretn = 22;
    iretn_fmt = fmt_1140;
    goto L9030;
L1140:
    inmbr = k22;
    iretn = 23;
    iretn_fmt = fmt_1145;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1145:
    if (ishr18_1.jdr == knumbr_1.k0) {
	goto L1200;
    }
/*                  MOVE V NOT O.K. BY DELTA. CSD = 1.2*LENGTH V */
/*                  ADJUST VALUE OF DP. SET J20=2 FOR SPECIAL */
/*                  CUT SEQUENCE TERMINATING CALCULATIONS. */
    sv1_1.csd[ifxcor_1.is - 1] = znumbr_1.z12em1 * dshar4_1.vl;
    if (dshar4_1.dp > sv1_1.csd[ifxcor_1.is - 1]) {
	goto L1180;
    }
    if (sv1_1.csd[ifxcor_1.is - 1] < znumbr_1.z2 * dshar4_1.dp) {
	dshar4_1.dp = znumbr_1.z6em1 * sv1_1.csd[ifxcor_1.is - 1];
    }
    goto L1190;
L1180:
    dshar4_1.dp = sv1_1.csd[ifxcor_1.is - 1];
L1190:
    dshar4_1.dpcnt = znumbr_1.z10;
    isv1_1.j50[ifxcor_1.is - 1] = 0;
    isv1_1.j51[ifxcor_1.is - 1] = 0;
    isv1_1.j20[ifxcor_1.is - 1] = knumbr_1.k2;
    inmbr = knumbr_1.k23;
    iretn = 24;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
    goto L490;
/*                  MOVE V O.K.. TEST IFAR FOR CORRECT INTERSECTION */
L1200:
    jpr2 = ifxcor_1.icscnt;
    if (isv1_1.ifar[ifxcor_1.is - 1] == knumbr_1.k1) {
	goto L1420;
    }
    isv1_1.ifar[ifxcor_1.is - 1] -= knumbr_1.k1;
    if (ishr18_1.ipdpl != knumbr_1.k0) {
	goto L1230;
    }
    iretn = 25;
    iretn_fmt = fmt_1220;
    goto L9060;
L1220:
    tv = fxcor_1.ti[0] * fxcor_1.til[0] + fxcor_1.ti[1] * fxcor_1.til[1] + 
	    fxcor_1.ti[2] * fxcor_1.til[2];
    fxcor_1.temp[0] = d_sign(&znumbr_1.z1, &tv);
    fxcor_1.ti[0] = fxcor_1.temp[0] * fxcor_1.til[0];
    fxcor_1.ti[1] = fxcor_1.temp[0] * fxcor_1.til[1];
    fxcor_1.ti[2] = fxcor_1.temp[0] * fxcor_1.til[2];
L1230:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L1240: */
	dshar4_1.tew[i__ - 1] = znumbr_1.z3 * sv_1.tau[ifxcor_1.is - 1] * 
		fxcor_1.ti[i__ - 1] + fxcor_1.te[i__ - 1];
    }
    jaa = knumbr_1.k1;
    goto L140;

/*                  ********** SPECIAL ROUTE. DS,PS BOTH PLANE, */

L1250:
    iretn = 26;
    iretn_fmt = fmt_1260;
    goto L9070;
L1260:
    inmbr = knumbr_1.k24;
    iretn = 27;
    iretn_fmt = fmt_1265;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1265:
    if (ishr18_1.jpr < 0) {
	goto L1280;
    } else if (ishr18_1.jpr == 0) {
	goto L1270;
    } else {
	goto L1266;
    }
L1266:
    jpr1 = 0;
    goto L1290;
L1270:
    dshar4_1.tew[0] = fxcor_1.te[0];
    dshar4_1.tew[1] = fxcor_1.te[1];
    dshar4_1.tew[2] = fxcor_1.te[2];
    goto L210;

/*     FALSE TANGENCY - MOVE AWAY FROM STOPPING POINT. */

L1280:
    if (ishr18_1.jpr + knumbr_1.k2 <= 0) {
	goto L1351;
    } else {
	goto L1281;
    }
L1281:
    if ((fxcor_1.te[0] - dshar4_1.tew[0]) * fxcor_1.ti[0] + (fxcor_1.te[1] - 
	    dshar4_1.tew[1]) * fxcor_1.ti[1] + (fxcor_1.te[2] - dshar4_1.tew[
	    2]) * fxcor_1.ti[2] <= 0.) {
	goto L1352;
    } else {
	goto L1282;
    }
L1282:
    fxcor_1.te[0] = znumbr_1.z5em1 * rc1sc * fxcor_1.ti[0] + fxcor_1.te[0];
    fxcor_1.te[1] = znumbr_1.z5em1 * rc1sc * fxcor_1.ti[1] + fxcor_1.te[1];
    fxcor_1.te[2] = znumbr_1.z5em1 * rc1sc * fxcor_1.ti[2] + fxcor_1.te[2];

/*     IS THIS THE ONLY CHECK SURFACE */

L1290:
    ishr18_1.iws = ifxcor_1.is;
    ifxcor_1.is = ifxcor_1.ics;
L1300:
    if (ils1 - ifxcor_1.is >= 0) {
	goto L1330;
    } else {
	goto L1310;
    }
L1310:
    ifxcor_1.is = ishr18_1.iws;
    if (ishr18_1.jpr >= 0) {
	goto L1200;
    } else {
	goto L1311;
    }
/*     LOOK FOR TRUE INTERSECTION WITH CHECK SURFACE */
L1311:
    dshar4_1.tew[0] = fxcor_1.te[0];
    dshar4_1.tew[1] = fxcor_1.te[1];
    dshar4_1.tew[2] = fxcor_1.te[2];
    goto L160;
L1320:
    ifxcor_1.is += ifxcor_1.lsv1;
    goto L1300;
L1330:
    if (ifxcor_1.is - ishr18_1.iws != 0) {
	goto L1331;
    } else {
	goto L1320;
    }
L1331:
    if (isv_1.isftyp[ifxcor_1.is - 1] - 99 >= 0) {
	goto L1320;
    } else {
	goto L1332;
    }
L1332:
    if (jpr2 <= 0) {
	goto L1310;
    } else {
	goto L1333;
    }
L1333:
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k4 >= 0) {
	goto L1340;
    } else {
	goto L1334;
    }
L1334:
    sv_1.tn[ifxcor_1.is * 3 - 3] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.ti[2];
L1340:
    jwr = 0;
    isv_1.jent[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.iopset[ifxcor_1.is - 1] = 0;
    isv_1.jtn[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.ju1[ifxcor_1.is - 1] = knumbr_1.k1;
    isv_1.jiops[ifxcor_1.is - 1] = 0;
    iretn = 28;
    iretn_fmt = fmt_1348;
    goto L9050;
L1348:
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k4 != 0) {
	goto L1349;
    } else {
	goto L1400;
    }
L1349:
    if (isv1_1.j23[ifxcor_1.is - 1] > knumbr_1.k0) {
	goto L1320;
    }
    sv1_1.stck[ifxcor_1.is - 1] = sv1_1.stck1[ifxcor_1.is - 1] * sv_1.z__[
	    ifxcor_1.is - 1] * sv_1.s[ifxcor_1.is - 1];
    inmbr = knumbr_1.k25;
    iretn = 29;
    iretn_fmt = fmt_1350;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1350:
    if (sv1_1.stck[ifxcor_1.is - 1] > (doublereal) knumbr_1.k0) {
	goto L1320;
    }
    goto L1380;
/*     MOVE WAS BACKWARDS - RESTART TWICE THEN GIVE UP */

L1351:
    jpr1 += knumbr_1.k1;
    if ((i__1 = jpr1 - knumbr_1.k2) < 0) {
	goto L1270;
    } else if (i__1 == 0) {
	goto L1353;
    } else {
	goto L1352;
    }
/*     THIS SURFACE INVALID - ELIMINATE FROM CONSIDERATION */

L1352:
    isv_1.isftyp[ifxcor_1.is - 1] = 99;
    jpr1 = 0;
    fxcor_1.te[0] = fxcor_1.tek[0];
    fxcor_1.te[1] = fxcor_1.tek[1];
    fxcor_1.te[2] = fxcor_1.tek[2];
    goto L1270;
L1353:
    sv_1.s[ifxcor_1.is - 1] += znumbr_1.z2 * dshar4_1.dp;
    goto L1270;
L1380:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L1390: */
	fxcor_1.te[i__ - 1] = fxcor_1.tel[i__ - 1];
    }
    jpr2 -= knumbr_1.k1;
    dshar4_1.dp = znumbr_1.z11em1 * sv1_1.csd[ifxcor_1.is - 1];
    goto L1250;
L1400:
    if (isv1_1.j22[ifxcor_1.is - 1] <= 0) {
	goto L1320;
    } else {
	goto L1410;
    }
L1410:
    ifxcor_1.it = ifxcor_1.ids;
    if (isv1_1.ifl4[ifxcor_1.is - 1] != 0) {
	goto L1411;
    } else {
	goto L1412;
    }
L1411:
    ifxcor_1.it = ifxcor_1.ips;
L1412:
    fxcor_1.temp[0] = (sv_1.sp[ifxcor_1.is * 3 - 3] - sv_1.sp[ifxcor_1.it * 3 
	    - 3]) * sv_1.tn[ifxcor_1.is * 3 - 3] + (sv_1.sp[ifxcor_1.is * 3 - 
	    2] - sv_1.sp[ifxcor_1.it * 3 - 2]) * sv_1.tn[ifxcor_1.is * 3 - 2] 
	    + (sv_1.sp[ifxcor_1.is * 3 - 1] - sv_1.sp[ifxcor_1.it * 3 - 1]) * 
	    sv_1.tn[ifxcor_1.is * 3 - 1];
    sv1_1.stckn[ifxcor_1.is - 1] = fxcor_1.temp[0] * (sv_1.tn[ifxcor_1.is * 3 
	    - 3] * fxcor_1.ti[0] + sv_1.tn[ifxcor_1.is * 3 - 2] * fxcor_1.ti[
	    1] + sv_1.tn[ifxcor_1.is * 3 - 1] * fxcor_1.ti[2]);
    inmbr = knumbr_1.k26;
    iretn = 30;
    iretn_fmt = fmt_1415;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1415:
    if (sv1_1.stckn[ifxcor_1.is - 1] <= 0.) {
	goto L1380;
    } else {
	goto L1320;
    }
L1420:
    inmbr = knumbr_1.k27;
    iretn = 31;
    iretn_fmt = fmt_1430;
    if (*kdynfl != knumbr_1.k0) {
	goto L9000;
    }
L1430:
    ifxcor_1.icl = knumbr_1.k3;
/* L1440: */
    iretn = 32;
    iretn_fmt = fmt_1445;
    goto L9060;
L1445:
    fxcor_1.temp[0] = (doublereal) ((ifxcor_1.is - ifxcor_1.ics) / 
	    ifxcor_1.lsv1 + knumbr_1.k1);
L1450:
    return 0;
L1460:
    inmbr = 24004;
    goto L9040;

/*     ALL CALLS EXCEPT THOSE TO VNORM AND CROSS HAVE BEEN PLACED IN THIS */
/*     SECTION TO MINIMIZE STORAGE REQUIREMENTS OF THE 360 */

L9000:
    apt238_(&inmbr);
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9010:
    check_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L1450;
    }
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9020:
    centr_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L1450;
    }
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9030:
    delta_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L1450;
    }
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9040:
    aerr_(&inmbr, "ARLM3   ", (ftnlen)8);
    goto L1450;
L9050:
    amind_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L1450;
    }
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9060:
    atape_();
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
L9070:
    plane_();
    if (ifxcor_1.iaerr > knumbr_1.k0) {
	goto L1450;
    }
    switch (iretn) {
	case 0: goto L175;
	case 1: goto L190;
	case 2: goto L230;
	case 3: goto L330;
	case 4: goto L360;
	case 5: goto L440;
	case 6: goto L550;
	case 7: goto L560;
	case 8: goto L565;
	case 9: goto L630;
	case 10: goto L635;
	case 11: goto L740;
	case 12: goto L745;
	case 13: goto L760;
	case 14: goto L810;
	case 15: goto L820;
	case 16: goto L846;
	case 17: goto L875;
	case 18: goto L950;
	case 19: goto L980;
	case 20: goto L1000;
	case 21: goto L1025;
	case 22: goto L1140;
	case 23: goto L1145;
	case 24: goto L490;
	case 25: goto L1220;
	case 26: goto L1260;
	case 27: goto L1265;
	case 28: goto L1348;
	case 29: goto L1350;
	case 30: goto L1415;
	case 31: goto L1430;
	case 32: goto L1445;
    }
} /* arlm3_ */

#undef kdynfl
#undef clngth
#undef ibtflg
#undef elmax
#undef sinl
#undef cosl
#undef jlin


