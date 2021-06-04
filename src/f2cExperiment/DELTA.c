/* DELTA.f -- translated by f2c (version 20100827).
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

struct {
    integer jteneu;
} chang_;

#define chang_1 chang_

/* *** SOURCE FILE : M0000893.W04   *** */

/* .....FORTRAN SUBROUTINE  ....DELTA          8/68                    HG */
/* .....FORTRAN SUBROUTINE              DELTA...              3/27/68  GK */
/* Subroutine */ int delta_(void)
{
    /* Initialized data */

    static doublereal zlit1 = 1e-4;
    static doublereal zlit3 = 4.;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal f;
    static integer i__, j, k, iu, iv;
    static doublereal zl2, aap, bap;
    static integer kap;
    static doublereal dps, zls;
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal prod1, prod2, stau1, stau2;
#define elmax ((doublereal *)&addcom_1)
    extern /* Subroutine */ int ccurv_(integer *, doublereal *, doublereal *, 
	    doublereal *), gouge_(void);
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)



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








/* ---- FLAG INTRODUCED BY VW - USED TO INDICATE IF TE HAS CHANGED */
/*                             JTENEU = 1 NO CHANGE FOR TE */
/*                                    = 0 TE HAS CHANGED */



    aap = sv_1.rc[(560 + (0 + (ifxcor_1.ips - 1 << 3)) - 560) / 8];
    bap = sv_1.rc[ifxcor_1.ids - 1];
    stau1 = sv_1.tau[ifxcor_1.ips - 1];
    stau2 = sv_1.tau[ifxcor_1.ids - 1];
    kap = ifxcor_1.is;
/*        USE RC1   FOR PROPER UNITS/ IMPLEMENTATION */
    dshar4_1.dpe = fxcor_1.rc1 * 1e10 / 4500.;
    dshar4_1.dpi = dshar4_1.dp;
    j = 0;
    if (*jlin - 1 != 0) {
	goto L101;
    } else {
	goto L601;
    }
L601:
    sv_1.tau[ifxcor_1.ips - 1] *= .4f;
    sv_1.tau[ifxcor_1.ids - 1] *= .4f;
/* 1.2      DO FOR PART SURFACE FIRST */
L101:
    ifxcor_1.is = ifxcor_1.ips;
L901:
    if (isv_1.ipl[ifxcor_1.is - 1] - 1 != 0) {
	goto L501;
    } else {
	goto L500;
    }
L500:
/* Computing 2nd power */
    d__1 = fxcor_1.te[0] - fxcor_1.tek[0];
/* Computing 2nd power */
    d__2 = fxcor_1.te[1] - fxcor_1.tek[1];
/* Computing 2nd power */
    d__3 = fxcor_1.te[2] - fxcor_1.tek[2];
    dshar4_1.zl = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L570: */
    dshar4_1.dp = fxcor_1.dpmax;
    goto L303;
L501:
    if (isv_1.isftyp[ifxcor_1.is - 1] - 3 != 0) {
	goto L503;
    } else {
	goto L502;
    }
L502:
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.p1[i__ - 1] = fxcor_1.te[i__ - 1];
/* L504: */
	dshar4_1.p2[i__ - 1] = fxcor_1.tek[i__ - 1];
    }
    goto L401;
L503:
    if ((d__1 = sv_1.sn[ifxcor_1.is * 3 - 3] * fxcor_1.ta[0] + sv_1.sn[
	    ifxcor_1.is * 3 - 2] * fxcor_1.ta[1] + sv_1.sn[ifxcor_1.is * 3 - 
	    1] * fxcor_1.ta[2], abs(d__1)) - zlit1 <= 0.) {
	goto L506;
    } else {
	goto L505;
    }
L506:
    if ((d__1 = sv_1.snk[ifxcor_1.is * 3 - 3] * fxcor_1.ta[0] + sv_1.snk[
	    ifxcor_1.is * 3 - 2] * fxcor_1.ta[1] + sv_1.snk[ifxcor_1.is * 3 - 
	    1] * fxcor_1.ta[2], abs(d__1)) - zlit1 <= 0.) {
	goto L507;
    } else {
	goto L505;
    }
L507:
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.p1[i__ - 1] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
/* L509: */
	dshar4_1.p2[i__ - 1] = sv_1.tpk[i__ + ifxcor_1.is * 3 - 4];
    }
    goto L401;
L505:
    iu = isv_1.itseg[ifxcor_1.is - 1];
    iv = isv_1.itsegk[ifxcor_1.is - 1];
    if (tlldat_1.tlinc[iu] != 0.) {
	goto L508;
    } else {
	goto L510;
    }
L510:
    if (iu - iv != 0) {
	goto L508;
    } else {
	goto L512;
    }
L512:
    if (sv_1.u1k[ifxcor_1.is * 3 - 3] * sv_1.u1[ifxcor_1.is * 3 - 3] + 
	    sv_1.u1k[ifxcor_1.is * 3 - 2] * sv_1.u1[ifxcor_1.is * 3 - 2] + 
	    sv_1.u1k[ifxcor_1.is * 3 - 1] * sv_1.u1[ifxcor_1.is * 3 - 1] - 
	    .01f >= 0.) {
	goto L513;
    } else {
	goto L508;
    }
L513:
    for (i__ = 1; i__ <= 3; ++i__) {
	dshar4_1.p1[i__ - 1] = fxcor_1.te[i__ - 1] + tlldat_1.ri[iu - 1] * 
		sv_1.u1[i__ + ifxcor_1.is * 3 - 4] + tlldat_1.tlhite[iu - 1] *
		 fxcor_1.ta[i__ - 1];
/* L514: */
	dshar4_1.p2[i__ - 1] = fxcor_1.tek[i__ - 1] + tlldat_1.ri[iv - 1] * 
		sv_1.u1k[i__ + ifxcor_1.is * 3 - 4] + tlldat_1.tlhite[iv - 1] 
		* fxcor_1.tak[i__ - 1];
    }
L401:
    prod1 = 0.f;
    prod2 = 0.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	prod1 += (dshar4_1.p1[i__ - 1] - fxcor_1.te[i__ - 1]) * fxcor_1.ta[
		i__ - 1];
/* L102: */
	prod2 += (dshar4_1.p2[i__ - 1] - fxcor_1.tek[i__ - 1]) * fxcor_1.tak[
		i__ - 1];
    }
    dshar4_1.zl = 0.f;
    for (k = 1; k <= 3; ++k) {
	dshar4_1.p1[k - 1] = fxcor_1.te[k - 1] + prod1 * fxcor_1.ta[k - 1];
	dshar4_1.p2[k - 1] = fxcor_1.tek[k - 1] + prod2 * fxcor_1.tak[k - 1];
/* L105: */
/* Computing 2nd power */
	d__1 = dshar4_1.p1[k - 1] - dshar4_1.p2[k - 1];
	dshar4_1.zl += d__1 * d__1;
    }
    if (j == 0) {
/* 1.4      FIND RC=RADIUS OF CURVATURE ALONG NORMAL AT P1 */
	ccurv_(&ifxcor_1.is, dshar4_1.p1, dshar4_1.p2, &sv_1.sn[ifxcor_1.is * 
		3 - 3]);
    } else {
	ccurv_(&ifxcor_1.is, dshar4_1.p1, dshar4_1.p2, &sv_1.snk[ifxcor_1.is *
		 3 - 3]);
    }

/* ...                IF APPARANT PLANE,USE LARGE RADIUS OF CURVATURE */

    if (isv_1.isigcr[ifxcor_1.is - 1] - 1 != 0) {
	goto L301;
    } else {
	goto L1301;
    }
L1301:
    sv_1.rc[ifxcor_1.is - 1] = d_sign(&fxcor_1.rc1, &sv_1.rc[ifxcor_1.is - 1])
	    ;
L301:
    dshar4_1.d1 = (d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) * 2.f;
    goto L115;
L303:
    if (ifxcor_1.is - ifxcor_1.ips != 0) {
	goto L113;
    } else {
	goto L112;
    }
/* 1.7      STORE RESULTS IN D2A,ZL1, AND RETURN FOR LIKE CALC. FOR DS */
L112:
    dps = dshar4_1.dp;
    zls = dshar4_1.zl;
    ifxcor_1.is = ifxcor_1.ids;
    goto L901;
/* 1.8        USE RESULTS OF SURFACE, PS OR DS, HAVING SMALLEST DP */
L113:
    if (dshar4_1.dp - dps <= 0.) {
	goto L516;
    } else {
	goto L114;
    }
/* 1.9      RESTORE PS RESULTS (MOST CONSERVATIVE AFTER ALL) */
L114:
    dshar4_1.dp = dps;
    dshar4_1.zl = zls;
    goto L516;
L115:
    dshar4_1.zl = sqrt(dshar4_1.zl);
    dshar4_1.dp = sqrt(zlit3 * sv_1.tau[ifxcor_1.is - 1] * (d__1 = 
	    dshar4_1.d1 - sv_1.tau[ifxcor_1.is - 1], abs(d__1)));
    goto L303;
/* 1.12     IF BEGINNING CUT VECTOR CANDIDATE BEING TESTED, STORE */
/* 1.12    CURRENT RESULTS (BASED ON NORMALS AT TERMINUS OF CUT VECTOR) */
/* 1.12    AND RETURN FOR CALCULATIONS BASED ON NORMALS AT ORIGIN OF */
/* 1.12    CUT VECTOR */
L516:
    if ((i__1 = ishr18_1.j12 - 1) < 0) {
	goto L116;
    } else if (i__1 == 0) {
	goto L117;
    } else {
	goto L119;
    }
L116:
    dshar4_1.dpe = dshar4_1.dp;
    zl2 = dshar4_1.zl;
    j = 1;
    ishr18_1.j12 = 1;
    goto L101;
/* 1.14     COMPARE CUT VECTOR LENGHTS BASED ON NORMALS AT ORIGIN AND */
/* 1.14    TERMINUS OF CUT VECTOR.  IF BEGINNING CUT VECTOR CANDIDATE */
/* 1.14    IS UNDER CONSIDERATION DPE IS TOO LARGE--TRANSFER TO C1.15 */
L117:
    ishr18_1.j12 = 2;
    if (dshar4_1.dp - dshar4_1.dpe <= 0.) {
	goto L119;
    } else {
	goto L118;
    }
/* 1.15     RESTORE RESULTS BASED ON NORMALS AT TERMINUS */
/* 1.15    OF CUT VECTOR CANDIDATE */
L118:
    dshar4_1.dp = dshar4_1.dpe;
    dshar4_1.zl = zl2;

/* 1.16     PRESERVE UNTRUNCATED DP FOR USE IN ANOTHER PROGRAM */
L119:
    dshar4_1.dpl = dshar4_1.dp;

/* 2.1      TRUNCATE DP SO AS TO LIE BETWEEN TAU AND DPMAX */
    if ((d__1 = dshar4_1.dp - fxcor_1.dpmax) < 0.) {
	goto L122;
    } else if (d__1 == 0) {
	goto L125;
    } else {
	goto L121;
    }
L122:
    if (dshar4_1.dp - sv_1.tau[ifxcor_1.is - 1] >= 0.) {
	goto L125;
    } else {
	goto L124;
    }
L124:
    dshar4_1.dp = sv_1.tau[ifxcor_1.is - 1];
    goto L125;
L121:
    dshar4_1.dp = fxcor_1.dpmax;

L125:
    if (dshar4_1.dp - dshar4_1.zl + sv_1.tau[ifxcor_1.is - 1] >= 0.) {
	goto L151;
    } else {
	goto L130;
    }
L155:
    if (dshar4_1.dp - dshar4_1.dpi * .6f + sv_1.tau[ifxcor_1.is - 1] >= 0.) {
	goto L127;
    } else {
	goto L129;
    }
/* 2.9      CUT VECTOR CANDIDATE MUCH TOO LONG.  REDUCE IT TO .6 OF ITS */
/* 2.9     CURRENT VALUE, SUBMIT TO ONE MORE TEST AND EXIT FAILING */
L129:
    dshar4_1.dp = dshar4_1.dpi * .6f;
    goto L127;
L130:
    fxcor_1.temp[0] = dshar4_1.dp / dshar4_1.zl;
    if ((d__1 = fxcor_1.temp[0] - .6f) < 0.) {
	goto L310;
    } else if (d__1 == 0) {
	goto L340;
    } else {
	goto L320;
    }
L310:
    fxcor_1.temp[0] = .6f;
L340:
    if (dshar4_1.dpi - dshar4_1.dp >= 0.) {
	goto L360;
    } else {
	goto L350;
    }
L350:
    dshar4_1.dp = dshar4_1.dpi;
L360:
    dshar4_1.dp = fxcor_1.temp[0] * dshar4_1.dp;
    goto L145;
L320:
    if (.9f - fxcor_1.temp[0] >= 0.) {
	goto L340;
    } else {
	goto L330;
    }
L330:
    fxcor_1.temp[0] = .9f;
    goto L340;
/* 2.14     REJECT CUT VECTOR CANDIDATE */
L145:
    ishr18_1.jdr = 1;
/* .... COULD BE ACCEPTED IF */
/* .... CUTTER HAS NOT MOVED SINCE LAST CALL TO CENTR */
    if (chang_1.jteneu == 1) {
	goto L160;
    }
/* .... CUT VECTOR LENGTH .LT. TAU */
    if (dshar4_1.dpi < sv_1.tau[ifxcor_1.is - 1]) {
	goto L160;
    }
/* .... OR CUT VECTOR .LT. 5*TAU AND .LT. HALF LAST ACCEPTED CUT VECTOR */
    if (dshar4_1.dpi < sv_1.tau[ifxcor_1.is - 1] * 5. && dshar4_1.dpi < 
	    dshar4_1.dpl * .5) {
	goto L160;
    }
L201:
    ifxcor_1.is = kap;
    sv_1.rc[ifxcor_1.ips - 1] = aap;
    sv_1.rc[ifxcor_1.ids - 1] = bap;
    sv_1.tau[ifxcor_1.ips - 1] = stau1;
    sv_1.tau[ifxcor_1.ids - 1] = stau2;
    return 0;


/*         TENTATIVELY ACCEPT CUT VECTOR (MUST PASS GOUGCK YET) */
/* 2.16     CUT DP DOWN TO 2DPI IF IT EXCEEDS THIS NO.  THIS PREVENTS */
/* 2.16    WILD FLUCUATIONS OF THE DP CAUSED BY RAPID CHANGE */
/* 2.16    IN SURFACE CURVATURE ALSO PRESENTS POINT SPACING */
/* 2.16    TO POST PROCESSOR ADAPTABLE TO FEED RATES. */
L151:
    if (dshar4_1.dp - dshar4_1.dpi * 2.f + sv_1.tau[ifxcor_1.is - 1] <= 0.) {
	goto L155;
    } else {
	goto L153;
    }
L153:
    dshar4_1.dp = dshar4_1.dpi * 2.f;


L127:
    if (ifxcor_1.igoug <= 0) {
	goto L160;
    } else {
	goto L157;
    }
L157:
    gouge_();
/* 2.22     IF GOUGCK FAILS, REJECT CUT VECTOR AND REDUCE DP TO .75DP */
    if (ishr18_1.jgr != 0) {
	goto L159;
    } else {
	goto L160;
    }
L159:
    dshar4_1.dp = dshar4_1.dpi * .75f;
    goto L145;

/* 2.23     ACCEPT CUT VECTOR CANDIDATE */
L160:
    ishr18_1.jdr = 0;
    goto L201;
L508:
/* Computing 2nd power */
    d__1 = sv_1.tp[ifxcor_1.is * 3 - 3] - sv_1.tpk[ifxcor_1.is * 3 - 3];
/* Computing 2nd power */
    d__2 = sv_1.tp[ifxcor_1.is * 3 - 2] - sv_1.tpk[ifxcor_1.is * 3 - 2];
/* Computing 2nd power */
    d__3 = sv_1.tp[ifxcor_1.is * 3 - 1] - sv_1.tpk[ifxcor_1.is * 3 - 1];
    dshar4_1.zl = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    dshar4_1.zl = sqrt(dshar4_1.zl);
    if (j == 0) {
	ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spk[
		ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    } else {
	ccurv_(&ifxcor_1.is, &sv_1.sp[ifxcor_1.is * 3 - 3], &sv_1.spk[
		ifxcor_1.is * 3 - 3], &sv_1.snk[ifxcor_1.is * 3 - 3]);
    }

/* ...                IF APPARANT PLANE, USE LARGE RADIUS OF CURVATURE */

    if (isv_1.isigcr[ifxcor_1.is - 1] - 1 != 0) {
	goto L104;
    } else {
	goto L1104;
    }
L1104:
    sv_1.rc[ifxcor_1.is - 1] = d_sign(&fxcor_1.rc1, &sv_1.rc[ifxcor_1.is - 1])
	    ;
L104:
    if (sv_1.rc[ifxcor_1.is - 1] >= 0.) {
	goto L107;
    } else {
	goto L106;
    }
L106:
    if (*jlin - 1 != 0) {
	goto L108;
    } else {
	goto L109;
    }
L108:
    sv_1.rc[ifxcor_1.is - 1] = (d__1 = sv_1.rc[ifxcor_1.is - 1] + sv_1.tau2[
	    ifxcor_1.is - 1], abs(d__1)) - sv_1.th[ifxcor_1.is - 1];
L110:
    dshar4_1.d1 = (d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) * 2.f;
    goto L120;
L107:
    if (*jlin - 1 != 0) {
	goto L111;
    } else {
	goto L812;
    }
L111:
    sv_1.rc[ifxcor_1.is - 1] = sv_1.rc[ifxcor_1.is - 1] + sv_1.tau1[
	    ifxcor_1.is - 1] + sv_1.th[ifxcor_1.is - 1];
    goto L110;
L812:
    sv_1.rc[ifxcor_1.is - 1] = (d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) + 
	    (sv_1.tau1[ifxcor_1.is - 1] + sv_1.tau2[ifxcor_1.is - 1]) * .5f + 
	    sv_1.th[ifxcor_1.is - 1];
    goto L110;
L109:
    sv_1.rc[ifxcor_1.is - 1] = (d__1 = sv_1.rc[ifxcor_1.is - 1], abs(d__1)) + 
	    (sv_1.tau1[ifxcor_1.is - 1] + sv_1.tau2[ifxcor_1.is - 1]) * .5f - 
	    sv_1.th[ifxcor_1.is - 1];
    goto L110;
L120:
    f = 1.f - (d__1 = sv_1.sk[ifxcor_1.is * 3 - 3] - sv_1.s[ifxcor_1.is - 1], 
	    abs(d__1)) / (sv_1.tau[ifxcor_1.is - 1] * 1.8f);
    dshar4_1.dp = sqrt(zlit3 * sv_1.tau[ifxcor_1.is - 1] * (d__1 = 
	    dshar4_1.d1 - sv_1.tau[ifxcor_1.is - 1], abs(d__1)));
    dshar4_1.dp = f * dshar4_1.dp;
/* Computing 2nd power */
    d__1 = fxcor_1.te[0] - fxcor_1.tek[0];
/* Computing 2nd power */
    d__2 = fxcor_1.te[1] - fxcor_1.tek[1];
/* Computing 2nd power */
    d__3 = fxcor_1.te[2] - fxcor_1.tek[2];
    fxcor_1.temp[3] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    goto L303;
} /* delta_ */

#undef clngth
#undef ibtflg
#undef elmax
#undef sinl
#undef cosl
#undef jlin


