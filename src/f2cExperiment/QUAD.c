/* QUAD.f -- translated by f2c (version 20100827).
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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* *** SOURCE FILE : M0000955.V02   *** */

/* .....FORTRAN SUBROUTINE             QUAD.....              4/1/68   GK */
/* Subroutine */ int quad_(void)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal hold;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)






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







/*   S(IS) IS PRIMARY ROOT IF EXTANT.  SURD IS SECONDARY IF EXTANT. */

/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    fxcor_1.surd = znumbr_1.z0;
    if (abs(dshar4_1.a) > znumbr_1.z1em7) {
	goto L100;
    }
    if (abs(dshar4_1.b) > znumbr_1.z1em7) {
	goto L30;
    }
L20:
    ifxcor_1.ier = knumbr_1.k1;
    goto L999;
/*   EQUATION IS LINEAR */
L30:
    sv_1.s[ifxcor_1.is - 1] = -znumbr_1.z5em1 * dshar4_1.c__ / dshar4_1.b;
L40:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - znumbr_1.z1em7 <= 0.) {
	goto L70;
    } else {
	goto L50;
    }
L50:
    if (isv_1.iop[ifxcor_1.is - 1] != 0) {
	goto L60;
    } else {
	goto L80;
    }
L60:
    if (sv_1.s[ifxcor_1.is - 1] <= 0.) {
	goto L130;
    } else {
	goto L80;
    }
L70:
    sv_1.s[ifxcor_1.is - 1] = znumbr_1.z0;
L80:
    ifxcor_1.ier = 0;
L999:
    return 0;
/*   EQUATION IS QUADRATIC */
L100:
    fxcor_1.surd = dshar4_1.b * dshar4_1.b - dshar4_1.a * dshar4_1.c__;
    if (abs(fxcor_1.surd) > znumbr_1.z1em7) {
	goto L110;
    }
/*   ROOTS ARE EQUAL */
    fxcor_1.surd = -dshar4_1.b / dshar4_1.a;
    sv_1.s[ifxcor_1.is - 1] = fxcor_1.surd;
    goto L40;
L110:
    if (fxcor_1.surd <= 0.) {
	goto L20;
    } else {
	goto L120;
    }
/*   ROOTS ARE REAL, UNEQUAL. */
L120:
    d__1 = sqrt(fxcor_1.surd);
    fxcor_1.surd = -dshar4_1.b - d_sign(&d__1, &dshar4_1.b);
    sv_1.s[ifxcor_1.is - 1] = dshar4_1.c__ / fxcor_1.surd;
    fxcor_1.surd /= dshar4_1.a;
/*   THUS SURD ABSOLUTELY LARGER THAN S(IS) */
    goto L40;
L130:
    if (fxcor_1.surd <= 0.) {
	goto L135;
    } else {
	goto L140;
    }
L135:
    if (isv_1.iop[ifxcor_1.is - 1] <= 0) {
	goto L80;
    } else {
	goto L20;
    }
/*   LEAST POSITIVE ROOT REQUIRED.  S(IS) NEG, SURD POS, SO EXCHANGE. */
L140:
    hold = fxcor_1.surd;
    fxcor_1.surd = sv_1.s[ifxcor_1.is - 1];
    sv_1.s[ifxcor_1.is - 1] = hold;
    goto L80;
} /* quad_ */

#undef sinl
#undef cosl


