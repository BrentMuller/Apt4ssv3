/* DDRLSR.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    logical tracfl;
} tracfl_;

#define tracfl_1 tracfl_

/* Table of constant values */

static integer c__2 = 2;

/* *** SOURCE FILE : M0000889.V07   *** */

/* .....FORTRAN SUBROUTINE  ....DDRLSR         8/68                 RN,PH */
/* ...  FORTRAN SUBROUTINE               DDRLSR */

/*              FORTRAN SUBROUTINE DDRLSR */

/* PURPOSE      TO CALCULATE THE SCALAR S,GIVEN THE VECTORS TP AND TN, */
/*              SUCH THAT TP+S*TN IS A POINT ON THE RULED SURFACE AND */
/*              ALSO TO CALCULATE THE SURFACE NORMAL AT THAT POINT */

/* LINKAGE      CALL DDRLSR */

/* CALLS        VNORM,CROSS */


/* Subroutine */ int ddrlsr_(void)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Local variables */
    static doublereal d__[3], e[3];
#define f ((doublereal *)&_BLNK__1)
    static doublereal g;
    static integer i__;
#define p ((doublereal *)&_BLNK__1)
#define w ((doublereal *)&_BLNK__1)
    static doublereal x[3];
#define r0 ((doublereal *)&_BLNK__1 + 9)
#define r2 ((doublereal *)&_BLNK__1 + 15)
#define r3 ((doublereal *)&_BLNK__1 + 12)
    static doublereal q1[3], w1[3], v1[3], q2[3], w2[3], v2[3], t1[3], s1[3], 
	    aa[3], bb[3], dc[3], fc[3], sc[3], dv[3];
#define pp ((doublereal *)&_BLNK__1)
#define wp ((doublereal *)&_BLNK__1)
#define vp ((doublereal *)&_BLNK__1)
#define sl ((doublereal *)&_BLNK__1 + 6)
#define zn ((doublereal *)&_BLNK__1 + 3)
    static doublereal po[3], cp[3];
    static integer lp, lw, lv;
    static doublereal ep;
    static integer iv;
    static doublereal ep2, ep5, ep6;
    static integer ls1, ls2;
    static doublereal ut1[3];
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal dcp[3], dvp[3];
    static integer lsd, lpp, lwp, lvp;
    static doublereal dot, sig, xll, sum, csl, csm, csn, sma, smb;
    static integer jsw1, jsw2, jsw3, lcic[12];
    static doublereal beta, alph;
    static integer ilim, ilsd;
    static doublereal delt;
#define cosl ((doublereal *)&tlldat_1 + 16)
    static integer icss;
#define sinl ((doublereal *)&tlldat_1 + 8)
#define ifst ((doublereal *)&_BLNK__1)
    static doublereal spll[3], snll[3];
    static integer iops, loop;
    static doublereal sign1, sign2;
    static integer icss2;
    static doublereal xdis1, xdis2;
#define delta ((doublereal *)&_BLNK__1 + 1)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal splll[3];
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), cross_(
	    doublereal *, doublereal *, doublereal *);
    static doublereal sigma;
    extern /* Subroutine */ int ddtabc_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddplan_(doublereal *), ddquad_(doublereal *);
#define zlambd ((doublereal *)&_BLNK__1 + 2)
#define lcanon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int ddcyln_(doublereal *), polcon_(doublereal *, 
	    integer *);
    static integer iguess;


/* ...  ALL REFERENCES TO ARRAY R HAVE BEEN CHANGED TO R0, */
/* ...  BECAUSE R OCCURS IN DSHAR4.INC. */

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






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/*              COMMON,DIMENSION AND EQUIVALENCE FOR RLDSR */


/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*              NOTE THIS SUBROUTINE HAS BEEN COPIED FORM THE APT SYSTEM */
/*                   CURRANT AS OF 9/1/67. NONE OF THE NAMES HAVE BEEN */
/*                   CHANGED TO PROTECT THE INNOCENT. */
/* ...           (EXCEPT FOR R, AS MENTIONED WITH THE INCLUDE STATEMENTS) */
/*     INITIALIZE */

    ilim = ifxcor_1.ic + 160;
    icss = ifxcor_1.ic;
    iops = isv_1.iop[ifxcor_1.is - 1];
    i__ = isv_1.icanon[ifxcor_1.is - 1];
    jsw1 = isv_1.isfidn[ifxcor_1.is - 1];
    isv_1.iop[ifxcor_1.is - 1] = -1;
    iguess = 0;
    loop = 25;
    ep2 = 1e-5f;
    for (i__ = 1; i__ <= 3; ++i__) {
	d__[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
	po[i__ - 1] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
	spll[i__ - 1] = sv_1.spl[i__ + ifxcor_1.is * 3 - 4];
	snll[i__ - 1] = sv_1.snl[i__ + ifxcor_1.is * 3 - 4];
	splll[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sp[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.snl[i__ + ifxcor_1.is * 3 - 4] = sv_1.sn[i__ + ifxcor_1.is * 3 - 
		4];
/* L10: */
    }


/*     COMPUTE VARIABLE SUBSCRIPTS */
    for (i__ = 2; i__ <= 12; ++i__) {
/* L11: */
	lcic[i__ - 1] = (integer) (lcanon[ifxcor_1.ic + i__ - 1] + .1f);
    }
    lsd = ifxcor_1.ic + lcic[1] + 4;
    ls1 = ifxcor_1.ic + lcic[2];
    lp = ifxcor_1.ic + lcic[3];
    lw = ifxcor_1.ic + lcic[4];
    lv = ifxcor_1.ic + lcic[5];
    ls2 = ifxcor_1.ic + lcic[6];

    jsw2 = (integer) lcanon[ls1 - 2];
    jsw3 = (integer) lcanon[ls2 - 2];
    q1[0] = p[lp - 1];
    q1[1] = p[lp];
    q1[2] = p[lp + 1];
    w1[0] = w[lw - 1] - q1[0];
    w1[1] = w[lw] - q1[1];
    w1[2] = w[lw + 1] - q1[2];
    vnorm_(w1, dv);

/*     STORE LENGTH OF W1 IN EP5 */

    ep5 = fxcor_1.vtem;
    v1[0] = f[lv - 1];
    v1[1] = f[lv];
    v1[2] = f[lv + 1];

/* .... FIRST TIME. SET TN */
    i__ = isv_1.icanon[ifxcor_1.is - 1];
    if (iops != 2) {
	goto L12;
    }
    d__[0] = v1[0];
    d__[1] = v1[1];
    d__[2] = v1[2];
L12:
    icss2 = (integer) (lcanon[icss + 1] + .1f);

    if (icss2 == 5) {
	goto L20;
    }
    lpp = ifxcor_1.ic + lcic[7];
    lwp = ifxcor_1.ic + lcic[8];
    lvp = ifxcor_1.ic + lcic[9];
    q2[0] = pp[lpp - 1];
    q2[1] = pp[lpp];
    q2[2] = pp[lpp + 1];
    w2[0] = wp[lwp - 1] - q2[0];
    w2[1] = wp[lwp] - q2[1];
    w2[2] = wp[lwp + 1] - q2[2];
    vnorm_(w2, dvp);
    ep6 = fxcor_1.vtem;
    v2[0] = vp[lvp - 1];
    v2[1] = vp[lvp];
    v2[2] = vp[lvp + 1];
    goto L30;
L20:
    cp[0] = pp[ls2 - 1];
    cp[1] = pp[ls2];
    cp[2] = pp[ls2 + 1];
    dcp[0] = 0.f;
    dcp[1] = 0.f;
    dcp[2] = 0.f;
L30:
    if (ifst[lsd - 1] != 0.f) {
	goto L220;
    }
    ifst[lsd - 1] = 1.f;
L40:
    loop = 25;
    ++iguess;
    zlambd[lsd - 1] = .5f;
    isv_1.isfidn[ifxcor_1.is - 1] = jsw1;
    if (iguess <= 8) {
	goto L60;
    }
    ifxcor_1.ier = 1;
L50:
    sv_1.tp[ifxcor_1.is * 3 - 3] = po[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = po[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = po[2];
    sv_1.tn[ifxcor_1.is * 3 - 3] = d__[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = d__[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = d__[2];
    isv_1.isfidn[ifxcor_1.is - 1] = jsw1;
    isv_1.iop[ifxcor_1.is - 1] = iops;
    if (ifxcor_1.ier == 1) {
	goto L53;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[i__ + ifxcor_1.is * 3 
		- 4];
/* L52: */
    }
    goto L55;
L53:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = splll[i__ - 1];
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = sv_1.snl[i__ + ifxcor_1.is * 3 - 
		4];
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = spll[i__ - 1];
	sv_1.snl[i__ + ifxcor_1.is * 3 - 4] = snll[i__ - 1];
/* L54: */
    }
L55:
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.is - 1];
    return 0;

L60:
    switch (iguess) {
	case 1:  goto L65;
	case 2:  goto L70;
	case 3:  goto L80;
	case 4:  goto L90;
	case 5:  goto L100;
	case 6:  goto L110;
	case 7:  goto L120;
	case 8:  goto L130;
    }
L65:
    if (isv_1.indir__[ifxcor_1.is - 1] == 1) {
	goto L68;
    }
/* Computing 2nd power */
    d__1 = po[0] - p[lp - 1];
/* Computing 2nd power */
    d__2 = po[1] - p[lp];
/* Computing 2nd power */
    d__3 = po[2] - p[lp + 1];
    xdis1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* Computing 2nd power */
    d__1 = po[0] - w[lw - 1];
/* Computing 2nd power */
    d__2 = po[1] - w[lw];
/* Computing 2nd power */
    d__3 = po[2] - w[lw + 1];
    xdis2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    delta[lsd - 1] = .3f;
    if (xdis2 < xdis1) {
	delta[lsd - 1] = .7f;
    }
    goto L140;
L68:
    ++iguess;
L70:
    delta[lsd - 1] = .5f;
    goto L140;
L80:
    delta[lsd - 1] = .999f;
    goto L140;
L90:
    delta[lsd - 1] = .001f;
    goto L140;
L100:
    delta[lsd - 1] = .75f;
    goto L140;
L110:
    delta[lsd - 1] = .25f;
    goto L140;
L120:
    delta[lsd - 1] = -.2f;
    goto L140;
L130:
    delta[lsd - 1] = 1.2f;

L140:
    icss2 = (integer) (lcanon[icss + 1] + .1f);
    if (icss2 == 5) {
	goto L160;
    }

    for (i__ = 1; i__ <= 3; ++i__) {
	x[i__ - 1] = q2[i__ - 1] + delta[lsd - 1] * w2[i__ - 1];
/* L150: */
	bb[i__ - 1] = dvp[i__ - 1];
    }
    sv_1.tn[ifxcor_1.is * 3 - 3] = v2[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = v2[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = v2[2];
    ep = ep6;
    ifxcor_1.ic = ls2;
    isv_1.isfidn[ifxcor_1.is - 1] = jsw3;
    cross_(v2, dvp, sc);
    goto L180;

L155:
    cp[0] = e[0];
    cp[1] = e[1];
    cp[2] = e[2];
    dcp[0] = dc[0];
    dcp[1] = dc[1];
    dcp[2] = dc[2];


L160:
    for (i__ = 1; i__ <= 3; ++i__) {
	x[i__ - 1] = q1[i__ - 1] + delta[lsd - 1] * w1[i__ - 1];
/* L170: */
	bb[i__ - 1] = dv[i__ - 1];
    }
    ep = ep5;
    sv_1.tn[ifxcor_1.is * 3 - 3] = v1[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = v1[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = v1[2];
    ifxcor_1.ic = ls1;
    isv_1.isfidn[ifxcor_1.is - 1] = jsw2;
    cross_(v1, dv, sc);
L180:
    vnorm_(sc, fc);
    sign1 = fxcor_1.vtem;
    if (ifxcor_1.ier != 0) {
	goto L40;
    }
    sv_1.tp[ifxcor_1.is * 3 - 3] = x[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = x[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = x[2];
    aa[0] = 0.f;
    dshar4_1.a = 0.f;
    dshar4_1.b = 0.f;
    dshar4_1.c__ = 0.f;

    ifxcor_1.jsw = isv_1.isfidn[ifxcor_1.is - 1];
    iv = ifxcor_1.istrup;
    ifxcor_1.istrup = 4;
    switch (ifxcor_1.jsw) {
	case 1:  goto L250;
	case 2:  goto L250;
	case 3:  goto L255;
	case 4:  goto L255;
	case 5:  goto L265;
	case 6:  goto L265;
	case 7:  goto L265;
	case 8:  goto L265;
	case 9:  goto L265;
	case 10:  goto L265;
	case 11:  goto L275;
	case 12:  goto L182;
	case 13:  goto L280;
	case 14:  goto L265;
    }
L250:
    ddplan_(&canon[ifxcor_1.ic - 1]);
    goto L182;
L255:
    ddcyln_(&canon[ifxcor_1.ic - 1]);
    goto L182;
L265:
    ddquad_(&canon[ifxcor_1.ic - 1]);
    goto L182;
L275:
    ddtabc_(&canon[ifxcor_1.ic - 2]);
    goto L182;
L280:
    polcon_(&canon[ifxcor_1.ic - 1], &c__2);
L182:
    ifxcor_1.istrup = iv;
    if (ifxcor_1.ier > 0) {
	goto L40;
    }
    e[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 3];
    e[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 2];
    e[2] = sv_1.tp[ifxcor_1.is * 3 - 1] + sv_1.s[ifxcor_1.is - 1] * sv_1.tn[
	    ifxcor_1.is * 3 - 1];
    sv_1.sp[ifxcor_1.is * 3 - 3] = e[0];
    sv_1.sp[ifxcor_1.is * 3 - 2] = e[1];
    sv_1.sp[ifxcor_1.is * 3 - 1] = e[2];
/* L184: */
    cross_(fc, &sv_1.sn[ifxcor_1.is * 3 - 3], ut1);
    vnorm_(ut1, t1);
    dot = t1[0] * bb[0] + t1[1] * bb[1] + t1[2] * bb[2];
    if (dot > 0.f) {
	goto L190;
    }
    sig = -1.f;
    goto L200;
L190:
    sig = 1.f;
L200:
    cross_(t1, &sv_1.tn[ifxcor_1.is * 3 - 3], s1);
    vnorm_(s1, ut1);
    sign2 = fxcor_1.vtem;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L210: */
	dc[i__ - 1] = t1[i__ - 1] * sig * sign1 * ep / sign2;
    }
    if (ifxcor_1.ic == ls2) {
	goto L155;
    }

/*   RB AND R2 ARE PARTIAL DERIVATIVES WRT DELTA AND LAMBDA REGSPECTIVELY */

    r3[lsd - 1] = dc[0] + zlambd[lsd - 1] * (dcp[0] - dc[0]);
    r3[lsd] = dc[1] + zlambd[lsd - 1] * (dcp[1] - dc[1]);
    r3[lsd + 1] = dc[2] + zlambd[lsd - 1] * (dcp[2] - dc[2]);
    r2[lsd - 1] = cp[0] - e[0];
    r2[lsd] = cp[1] - e[1];
    r2[lsd + 1] = cp[2] - e[2];
    vnorm_(&r3[lsd - 1], &zn[lsd - 1]);
    if (ifxcor_1.ier > 0) {
	goto L40;
    }
    vnorm_(&r2[lsd - 1], &sl[lsd - 1]);
    if (ifxcor_1.ier > 0) {
	goto L40;
    }
    cross_(&zn[lsd - 1], &sl[lsd - 1], sc);
    vnorm_(sc, &zn[lsd - 1]);
/*     ZN(LSD) CONTAINS THE SURFACE NORMAL */
    if (ifxcor_1.ier > 0) {
	goto L40;
    }

/*     R0(LSD) CONTAINS THE SURFACE POINT */

    r0[lsd - 1] = e[0] + zlambd[lsd - 1] * r2[lsd - 1];
    r0[lsd] = e[1] + zlambd[lsd - 1] * r2[lsd];
    r0[lsd + 1] = e[2] + zlambd[lsd - 1] * r2[lsd + 1];
    ilsd = lsd + 2;

/*     TAKE DOT PRODUCT OF TOOL NORMAL AND SURFACE NORMAL */
    if (iops != 2) {
	goto L220;
    }
    x[0] = r0[lsd - 1] - po[0];
    x[1] = r0[lsd] - po[1];
    x[2] = r0[lsd + 1] - po[2];
    vnorm_(x, d__);
    sv_1.vndir[ifxcor_1.is * 3 - 3] = d__[0];
    sv_1.vndir[ifxcor_1.is * 3 - 2] = d__[1];
    sv_1.vndir[ifxcor_1.is * 3 - 1] = d__[2];
    isv_1.indir__[ifxcor_1.is - 1] = 1;

L220:
    g = d__[0] * zn[lsd - 1] + d__[1] * zn[lsd] + d__[2] * zn[lsd + 1];
    if (abs(g) < .01f) {
	goto L40;
    }
    x[0] = po[0] - r0[lsd - 1];
    x[1] = po[1] - r0[lsd];
    x[2] = po[2] - r0[lsd + 1];
    xll = -(x[0] * zn[lsd - 1] + x[1] * zn[lsd] + x[2] * zn[lsd + 1]) / g;
    vnorm_(x, aa);
    x[0] += xll * d__[0];
    x[1] += xll * d__[1];
    x[2] += xll * d__[2];

/*     SUM IS THE DISTANCE BETWEEN THE POINT OF INTERSECTION OF TOOL */
/*         NORMAL WITH THE PLANE AND THE SURFACE POINT */
/*     SIGMA IS THE COSINE OF THE ANGLE BETWEEN TOOL NORMAL AND */
/*         NORMALIZED (TOOL POINT - SURFACE POINT) */

    sum = abs(x[0]) + abs(x[1]) + abs(x[2]);
    sigma = (d__1 = aa[0] * d__[0] + aa[1] * d__[1] + aa[2] * d__[2], abs(
	    d__1));

/*     DECLARE CONVERGENCE IF EITHER ANGLE OR DIST. LT. TEST QUANTITIES */

    if (sigma < .99995f && sum > ep2) {
	goto L230;
    }
    ifxcor_1.ier = 1;
    if (iops > 0 && xll < 0.f) {
	goto L50;
    }
    ifxcor_1.ier = 0;
    sv_1.s[ifxcor_1.is - 1] = xll;
    fxcor_1.tem[7] = zn[lsd - 1];
    fxcor_1.tem[8] = zn[lsd];
    fxcor_1.tem[9] = zn[lsd + 1];
    sv_1.slx[ifxcor_1.is * 3 - 3] = sl[lsd - 1];
    sv_1.slx[ifxcor_1.is * 3 - 2] = sl[lsd];
    sv_1.slx[ifxcor_1.is * 3 - 1] = sl[lsd + 1];
    vnorm_(&fxcor_1.tem[7], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    goto L50;

/*     UPDATE COUNTERS PICKUP NEW PARAMETERS IF COUNTERS EXHAUSTED */

L230:
    --loop;
    if (loop <= 0) {
	goto L40;
    }

/*     ALPH AND BETA ARE LINEAR CORRECTIONS TO DELTA AND LAMBDA */

/* Computing 2nd power */
    d__1 = r3[lsd - 1];
/* Computing 2nd power */
    d__2 = r3[lsd];
/* Computing 2nd power */
    d__3 = r3[lsd + 1];
    csl = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    csm = r3[lsd - 1] * r2[lsd - 1] + r3[lsd] * r2[lsd] + r3[lsd + 1] * r2[
	    lsd + 1];
/* Computing 2nd power */
    d__1 = r2[lsd - 1];
/* Computing 2nd power */
    d__2 = r2[lsd];
/* Computing 2nd power */
    d__3 = r2[lsd + 1];
    csn = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    sma = r3[lsd - 1] * x[0] + r3[lsd] * x[1] + r3[lsd + 1] * x[2];
    smb = r2[lsd - 1] * x[0] + r2[lsd] * x[1] + r2[lsd + 1] * x[2];
    delt = csl * csn - csm * csm;
    if (delt < 1e-5f) {
	goto L40;
    }
    alph = (sma * csn - smb * csm) / delt;
    beta = (smb * csl - sma * csm) / delt;
    delta[lsd - 1] += alph * .8f;
    zlambd[lsd - 1] += beta * .8f;
    goto L140;
} /* ddrlsr_ */

#undef lcanon
#undef zlambd
#undef bcanon
#undef sscan
#undef canon
#undef delta
#undef ifst
#undef sinl
#undef cosl
#undef can
#undef zn
#undef sl
#undef vp
#undef wp
#undef pp
#undef r3
#undef r2
#undef r0
#undef w
#undef p
#undef f


