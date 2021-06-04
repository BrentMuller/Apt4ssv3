/* ARLM2.f -- translated by f2c (version 20100827).
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
    doublereal ccentr[3], cend[3], cenlen, chord, costh, crdius, ctool, alpha,
	     dcentr[3], drdius, dinc, delmot[3], dnmot[3], dif, difout, dsmov,
	     d2[3], el1, el2, fipnt[3], hchord, hafdia, offset, psi, radno, 
	    rone, rzero[3], rzerol, sinth, stvec[3], tanmot[3], theta, zdotc, 
	    zign, zgamma, zpnts;
} dshar5_;

#define dshar5_1 dshar5_

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

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* *** SOURCE FILE : M0002738.V06   *** */



/* .....FORTRAN SUBROUTINE             ARLM2...               4/8/68   GK */
/* Subroutine */ int arlm2_(void)
{
    /* Initialized data */

    static doublereal zlit1 = 1e-4;

    /* Format strings */
    static char fmt_24[] = "";
    static char fmt_1410[] = "";
    static char fmt_270[] = "";
    static char fmt_1300[] = "";
    static char fmt_1256[] = "";
    static char fmt_1271[] = "";
    static char fmt_1281[] = "";
    static char fmt_1320[] = "";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *), atan(
	    doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    static doublereal a[9]	/* was [3][3] */, b[9]	/* was [3][3] */, d__;
    static integer i__, j;
    static doublereal v;
    static integer ia, ib;
    static doublereal zz, dk;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal ten, dot, flip;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal proj, prok;
    static integer npts;
    extern /* Subroutine */ int atape_(void);
#define canon ((doublereal *)&_BLNK__1)
    static doublereal daxis[3], caxis[3];
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer ifrot, idone;
    extern /* Subroutine */ int rotat_(doublereal *, doublereal *);
    static integer iretn, lretn;
    static doublereal ctocl;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static integer jretn;
    static doublereal znpts;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal temdif;
#define cnrmal ((doublereal *)&dshar5_1)
    static doublereal cansto[3], dvalui, dopsta;
#define zmoshn ((doublereal *)&fxcor_1 + 69)
    static doublereal sinzta, cosxta, sinxta;

    /* Assigned format variables */
    static char *iretn_fmt, *lretn_fmt, *jretn_fmt;








/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  5.  DSHARE BLOCK 5  *** */





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






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    fxcor_1.tek[0] = fxcor_1.te[0];
    fxcor_1.tek[1] = fxcor_1.te[1];
    fxcor_1.tek[2] = fxcor_1.te[2];
    ifxcor_1.is = ifxcor_1.ics;
    i__ = isv_1.icanon[ifxcor_1.ids - 1];
    dshar5_1.dcentr[0] = canon[i__ - 1];
    dshar5_1.dcentr[1] = canon[i__];
    dshar5_1.dcentr[2] = canon[i__ + 1];
    daxis[0] = canon[i__ + 2];
    daxis[1] = canon[i__ + 3];
    daxis[2] = canon[i__ + 4];
    dshar5_1.drdius = canon[i__ + 5];
    i__ = isv_1.icanon[ifxcor_1.ics - 1];
    dshar5_1.ccentr[0] = canon[i__ - 1];
    dshar5_1.ccentr[1] = canon[i__];
    dshar5_1.ccentr[2] = canon[i__ + 1];
    caxis[0] = canon[i__ + 2];
    caxis[1] = canon[i__ + 3];
    caxis[2] = canon[i__ + 4];
    dshar5_1.crdius = canon[i__ + 5];

/*     PRELIMINARY Z-CORRECTION CALCULATIONS */

    ifrot = 0;
    idone = 0;
    i__ = isv_1.icanon[ifxcor_1.ips - 1];
    fxcor_1.tem[0] = fxcor_1.ta[0] * canon[i__ - 1] + fxcor_1.ta[1] * canon[
	    i__] + fxcor_1.ta[2] * canon[i__ + 1];
    flip = znumbr_1.z1;
    if (fxcor_1.tem[0] < znumbr_1.z0) {
	flip = -znumbr_1.z1;
    }
    cansto[0] = canon[i__ - 1] * flip;
    cansto[1] = canon[i__] * flip;
    cansto[2] = canon[i__ + 1] * flip;
    dvalui = fxcor_1.te[0] * cansto[0] + fxcor_1.te[1] * cansto[1] + 
	    fxcor_1.te[2] * cansto[2];
    dopsta = fxcor_1.ta[0] * cansto[0] + fxcor_1.ta[1] * cansto[1] + 
	    fxcor_1.ta[2] * cansto[2];

/*     DETERMINE IF ROTATION NECCESSARY. IF SO, ROTATE. */

    if (abs(fxcor_1.ta[2]) == znumbr_1.z1) {
	goto L90;
    }
    ifrot = 1;

/*     ROTATION MATRIX  CONSTRUCTION. */

    sinzta = sqrt(fxcor_1.ta[0] * fxcor_1.ta[0] + fxcor_1.ta[1] * fxcor_1.ta[
	    1]);
    cosxta = fxcor_1.ta[0] / sinzta;
    sinxta = fxcor_1.ta[1] / sinzta;
    a[0] = fxcor_1.ta[2] * cosxta;
    a[1] = fxcor_1.ta[2] * sinxta;
    a[2] = -sinzta;
    a[3] = -sinxta;
    a[4] = cosxta;
    a[5] = 0.f;
    a[6] = fxcor_1.ta[0];
    a[7] = fxcor_1.ta[1];
    a[8] = fxcor_1.ta[2];
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    b[i__ + j * 3 - 4] = a[j + i__ * 3 - 4];
	}
    }

/*     ROTATIONS DEPEND ON SURFACE TYPE */

L11:
    if ((i__1 = ifxcor_1.jbr - 2) < 0) {
	goto L12;
    } else if (i__1 == 0) {
	goto L14;
    } else {
	goto L16;
    }

L12:
    rotat_(dshar5_1.ccentr, a);
    if (isv_1.isfidn[ifxcor_1.ics - 1] > knumbr_1.k2) {
	rotat_(caxis, a);
    }
    rotat_(dshar5_1.dcentr, a);
    rotat_(daxis, a);
    i__ = isv_1.icanon[ifxcor_1.ids - 1];
    canon[i__ - 1] = dshar5_1.dcentr[0];
    canon[i__] = dshar5_1.dcentr[1];
    canon[i__ + 1] = dshar5_1.dcentr[2];
    canon[i__ + 2] = daxis[0];
    canon[i__ + 3] = daxis[1];
    canon[i__ + 4] = daxis[2];
    rotat_(fxcor_1.tek, a);
    goto L20;

L14:
    rotat_(dshar5_1.ccentr, a);
    rotat_(caxis, a);
    rotat_(&sv_1.sn[ifxcor_1.ids * 3 - 3], a);
    goto L20;

L16:
    rotat_(cnrmal, a);

L20:
    rotat_(fxcor_1.te, a);
    i__ = isv_1.icanon[ifxcor_1.ics - 1];
    canon[i__ - 1] = cnrmal[0];
    canon[i__] = cnrmal[1];
    canon[i__ + 1] = cnrmal[2];
    canon[i__ + 2] = caxis[0];
    canon[i__ + 3] = caxis[1];
    canon[i__ + 4] = caxis[2];
    if (idone != 1) {
	goto L24;
    }
    iretn = 0;
    iretn_fmt = fmt_24;
    goto L1341;
L24:
    rotat_(fxcor_1.ti, a);

/*     DO NECCESSARY INVERSE ROTATIONS AND Z-CORRECTIONS */

    if (idone != 1) {
	goto L90;
    }
    rotat_(&sv_1.tn[ifxcor_1.ics * 3 - 3], a);
    rotat_(&sv_1.tp[ifxcor_1.ics * 3 - 3], a);
    if (dopsta == znumbr_1.z0) {
	goto L1410;
    }
    proj = sv_1.tn[ifxcor_1.ics * 3 - 3] * cansto[0] + sv_1.tn[ifxcor_1.ics * 
	    3 - 2] * cansto[1] + sv_1.tn[ifxcor_1.ics * 3 - 1] * cansto[2];
    prok = sv_1.tp[ifxcor_1.ics * 3 - 3] * cansto[0] + sv_1.tp[ifxcor_1.ics * 
	    3 - 2] * cansto[1] + sv_1.tp[ifxcor_1.ics * 3 - 1] * cansto[2];
    proj = (proj - dvalui) / dopsta;
    prok = (prok - dvalui) / dopsta;
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.ics * 3 - 4] += proj * (-fxcor_1.ta[i__ - 1]);
/* L29: */
	sv_1.tp[i__ + ifxcor_1.ics * 3 - 4] += prok * (-fxcor_1.ta[i__ - 1]);
    }
    goto L1410;

L90:
    ten = sqrt(fxcor_1.ti[0] * fxcor_1.ti[0] + fxcor_1.ti[1] * fxcor_1.ti[1]);
    zmoshn[0] = fxcor_1.ti[0] / ten;
    zmoshn[1] = fxcor_1.ti[1] / ten;
    zmoshn[2] = znumbr_1.z0;

/*     BEGIN CUTTER OFFSET CALCULATIONS */

    fxcor_1.temp[6] = fxcor_1.cutdat[0];
    if (isv_1.isftyp[ifxcor_1.ids - 1] == knumbr_1.k3) {
	fxcor_1.temp[6] = znumbr_1.z0;
    }
    ifxcor_1.jsw = isv_1.isftyp[ifxcor_1.is - 1];
    fxcor_1.temp[19] = (doublereal) (isv1_1.ifar[ifxcor_1.is - 1] - 
	    knumbr_1.k1);
    dshar5_1.radno = (doublereal) ((isv1_1.ifar[ifxcor_1.is - 1] - 
	    knumbr_1.k1) / knumbr_1.k2);
    isv1_1.ifar[ifxcor_1.is - 1] = knumbr_1.k2 - (isv1_1.ifar[ifxcor_1.is - 1]
	     - knumbr_1.k2 * (isv1_1.ifar[ifxcor_1.is - 1] / knumbr_1.k2));
    switch (ifxcor_1.jsw) {
	case 1:  goto L140;
	case 2:  goto L140;
	case 3:  goto L170;
	case 4:  goto L130;
    }
L130:
    dshar5_1.radno = fxcor_1.temp[19];
    dshar5_1.offset = fxcor_1.temp[6];
    goto L180;
L140:
    dshar5_1.offset = fxcor_1.cutdat[0];
    if (isv1_1.ifar[ifxcor_1.is - 1] == ifxcor_1.jsw) {
	dshar5_1.offset = -dshar5_1.offset;
    }
    goto L180;
L170:
    dshar5_1.offset = znumbr_1.z0;
L180:
    if ((i__1 = ifxcor_1.jbr - knumbr_1.k2) < 0) {
	goto L190;
    } else if (i__1 == 0) {
	goto L810;
    } else {
	goto L1310;
    }

/* ...  2D ROUTE--CIRCLE DS,CIRCLE OR LINE CS */

L190:
    dshar5_1.rzero[0] = dshar5_1.dcentr[0] - fxcor_1.te[0];
    dshar5_1.rzero[1] = dshar5_1.dcentr[1] - fxcor_1.te[1];
/* Computing 2nd power */
    d__1 = dshar5_1.rzero[0];
/* Computing 2nd power */
    d__2 = dshar5_1.rzero[1];
    dshar5_1.rzerol = sqrt(d__1 * d__1 + d__2 * d__2);
    if (dshar5_1.rzerol <= znumbr_1.z1em6) {
	goto L1410;
    }
    d__1 = dshar5_1.rzero[0] * fxcor_1.ti[1] - dshar5_1.rzero[1] * fxcor_1.ti[
	    0];
    fxcor_1.temp[14] = d_sign(&znumbr_1.z1, &d__1);
    fxcor_1.temp[0] = znumbr_1.z1;
    fxcor_1.temp[1] = znumbr_1.z1;
    fxcor_1.temp[4] = abs(dshar5_1.offset);
    fxcor_1.temp[5] = -sv_1.past[ifxcor_1.is - 1] * fxcor_1.temp[14];
    if (dshar5_1.rzerol >= dshar5_1.drdius) {
	goto L250;
    }
    if (isv_1.isftyp[ifxcor_1.is - 1] == knumbr_1.k4) {
	dshar5_1.offset = -dshar5_1.offset;
    }
    dshar5_1.dif = dshar5_1.drdius - fxcor_1.temp[6] - (d__1 = sv_1.tau2[
	    ifxcor_1.ids - 1], abs(d__1));
    temdif = dshar5_1.drdius - fxcor_1.temp[6];
    if (dshar5_1.dif <= 0.) {
	goto L1380;
    } else {
	goto L260;
    }
L250:
    dshar5_1.dif = dshar5_1.drdius + fxcor_1.temp[6] + sv_1.tau1[ifxcor_1.ids 
	    - 1];
    temdif = dshar5_1.drdius + fxcor_1.temp[6];
L260:
    if (isv_1.isfidn[ifxcor_1.is - 1] > knumbr_1.k2) {
	goto L440;
    }

/*     LINE  CS, CYLINDER DS. */

    sv_1.tp[ifxcor_1.is * 3 - 3] = dshar5_1.dcentr[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = dshar5_1.dcentr[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = fxcor_1.te[2];
    sv_1.tn[ifxcor_1.is * 3 - 3] = cnrmal[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = cnrmal[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = znumbr_1.z0;
    lretn = 0;
    lretn_fmt = fmt_270;
    goto L1420;
L270:
    if (sv_1.s[ifxcor_1.is - 1] >= znumbr_1.z0) {
	goto L280;
    }
    sv_1.s[ifxcor_1.is - 1] = -sv_1.s[ifxcor_1.is - 1];
    sv_1.tn[ifxcor_1.is * 3 - 3] = -sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.tn[ifxcor_1.is * 3 - 2] = -sv_1.tn[ifxcor_1.is * 3 - 2];
L280:
    if (isv_1.isftyp[ifxcor_1.is - 1] != knumbr_1.k4) {
	goto L300;
    }
    if ((d__1 = sv_1.s[ifxcor_1.is - 1] - dshar5_1.drdius, abs(d__1)) - 
	    sv_1.tau[ifxcor_1.is - 1] >= znumbr_1.z0) {
	goto L1370;
    }
    ten = sv_1.s[ifxcor_1.is - 1] + dshar5_1.offset;
    dshar5_1.fipnt[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + ten * sv_1.tn[
	    ifxcor_1.is * 3 - 3];
    dshar5_1.fipnt[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + ten * sv_1.tn[
	    ifxcor_1.is * 3 - 2];
    goto L1030;
L300:
    fxcor_1.temp[8] = sv_1.s[ifxcor_1.is - 1] + dshar5_1.rzero[0] * sv_1.tn[
	    ifxcor_1.is * 3 - 3] + dshar5_1.rzero[1] * sv_1.tn[ifxcor_1.is * 
	    3 - 2];
    if (fxcor_1.temp[8] < znumbr_1.z0) {
	fxcor_1.temp[1] = -znumbr_1.z1;
    }
    fxcor_1.temp[9] = sv_1.s[ifxcor_1.is - 1] - fxcor_1.temp[4] - 
	    znumbr_1.z1em5;
    if (fxcor_1.temp[9] >= dshar5_1.dif) {
	goto L1390;
    }
    if (fxcor_1.temp[9] + dshar5_1.dif <= znumbr_1.z0) {
	goto L1380;
    }
    if (dshar5_1.dif - sv_1.s[ifxcor_1.is - 1] - fxcor_1.temp[4] > zlit1) {
	goto L360;
    }
    dshar5_1.radno = fxcor_1.temp[19];
    goto L430;
L360:
    if (abs(fxcor_1.temp[8]) - fxcor_1.temp[4] > znumbr_1.z1em5) {
	goto L420;
    }
    if (sv_1.past[ifxcor_1.is - 1] >= znumbr_1.z0) {
	goto L390;
    }
    if (abs(fxcor_1.temp[8]) + znumbr_1.z1em5 > fxcor_1.temp[4]) {
	goto L420;
    }
L390:
    dshar5_1.zdotc = dshar5_1.rzero[0] * sv_1.tn[ifxcor_1.is * 3 - 2] - 
	    dshar5_1.rzero[1] * sv_1.tn[ifxcor_1.is * 3 - 3];
    if (abs(dshar5_1.zdotc) - znumbr_1.z1em7 > znumbr_1.z0) {
	goto L410;
    }
    fxcor_1.temp[0] = sv_1.past[ifxcor_1.is - 1] * fxcor_1.temp[1];
    goto L420;
L410:
    fxcor_1.temp[0] = fxcor_1.temp[1] * fxcor_1.temp[5] * d_sign(&znumbr_1.z1,
	     &dshar5_1.zdotc);
L420:
    fxcor_1.temp[5] = -fxcor_1.temp[0] * fxcor_1.temp[1] * fxcor_1.temp[14];
    if (isv1_1.ifar[ifxcor_1.is - 1] == knumbr_1.k2) {
	fxcor_1.temp[5] = -fxcor_1.temp[5];
    }
L430:
    fxcor_1.temp[2] = sv_1.s[ifxcor_1.is - 1] + fxcor_1.temp[5] * 
	    fxcor_1.temp[14] * sv_1.past[ifxcor_1.is - 1] * fxcor_1.temp[4];
/* Computing 2nd power */
    d__2 = temdif;
/* Computing 2nd power */
    d__3 = fxcor_1.temp[2];
    fxcor_1.temp[3] = sqrt((d__1 = d__2 * d__2 - d__3 * d__3, abs(d__1)));
    dshar5_1.fipnt[0] = sv_1.tp[ifxcor_1.is * 3 - 3] + fxcor_1.temp[2] * 
	    sv_1.tn[ifxcor_1.is * 3 - 3] + fxcor_1.temp[5] * fxcor_1.temp[3] *
	     sv_1.tn[ifxcor_1.is * 3 - 2];
    dshar5_1.fipnt[1] = sv_1.tp[ifxcor_1.is * 3 - 2] + fxcor_1.temp[2] * 
	    sv_1.tn[ifxcor_1.is * 3 - 2] - fxcor_1.temp[5] * fxcor_1.temp[3] *
	     sv_1.tn[ifxcor_1.is * 3 - 3];
    goto L1030;

/*     CYLINDER CS, CYLINDER DS. */

L440:
    dshar5_1.cend[0] = dshar5_1.ccentr[0] - dshar5_1.dcentr[0];
    dshar5_1.cend[1] = dshar5_1.ccentr[1] - dshar5_1.dcentr[1];
/* Computing 2nd power */
    d__1 = dshar5_1.cend[0];
/* Computing 2nd power */
    d__2 = dshar5_1.cend[1];
    ctocl = sqrt(d__1 * d__1 + d__2 * d__2);
    if (ctocl <= znumbr_1.z1em7) {
	goto L1360;
    }
    dshar5_1.cend[0] /= ctocl;
    dshar5_1.cend[1] /= ctocl;
    if (ifxcor_1.jsw != knumbr_1.k4) {
	goto L520;
    }
    if (ctocl - dshar5_1.crdius + znumbr_1.z1em3 >= dshar5_1.drdius) {
	goto L800;
    }
    if ((d__1 = ctocl + dshar5_1.drdius - dshar5_1.crdius, abs(d__1)) < 
	    znumbr_1.z1em3) {
	goto L500;
    }
    if ((d__1 = ctocl + dshar5_1.crdius - dshar5_1.drdius, abs(d__1)) - 
	    znumbr_1.z1em3 >= 0.) {
	goto L1370;
    } else {
	goto L510;
    }
L500:
    fxcor_1.temp[0] = -znumbr_1.z1;
L510:
    d__ = (dshar5_1.drdius + dshar5_1.offset) * fxcor_1.temp[0];
    dshar5_1.fipnt[0] = dshar5_1.dcentr[0] + d__ * dshar5_1.cend[0];
    dshar5_1.fipnt[1] = dshar5_1.dcentr[1] + d__ * dshar5_1.cend[1];
    goto L1030;
L520:
    fxcor_1.temp[8] = temdif - ctocl;
    fxcor_1.temp[10] = fxcor_1.temp[4];
    if (abs(fxcor_1.temp[8]) - dshar5_1.crdius - fxcor_1.temp[10] >= 0.) {
	goto L1390;
    } else {
	goto L530;
    }
L530:
    fxcor_1.temp[9] = ctocl - dshar5_1.crdius;
    if (fxcor_1.temp[9] + temdif + fxcor_1.temp[4] + znumbr_1.z1em5 <= 0.) {
	goto L1390;
    } else {
	goto L540;
    }
L540:
    if ((d__1 = fxcor_1.temp[9] + temdif, abs(d__1)) > fxcor_1.temp[10]) {
	goto L570;
    }
    if (fxcor_1.temp[9] >= znumbr_1.z0) {
	goto L1380;
    }
    fxcor_1.temp[0] = -znumbr_1.z1;
L570:
    if ((d__1 = dshar5_1.crdius - fxcor_1.temp[8], abs(d__1)) > fxcor_1.temp[
	    10]) {
	goto L600;
    }
    if (fxcor_1.temp[0] <= 0.) {
	goto L1380;
    } else {
	goto L720;
    }
L600:
    if ((d__1 = fxcor_1.temp[9] - temdif, abs(d__1)) > fxcor_1.temp[10]) {
	goto L620;
    }
    if (fxcor_1.temp[0] <= 0.) {
	goto L1380;
    } else {
	goto L720;
    }
L620:
    if (fxcor_1.temp[0] < 0.) {
	goto L740;
    } else if (fxcor_1.temp[0] == 0) {
	goto L720;
    } else {
	goto L630;
    }
L630:
/* Computing 2nd power */
    d__1 = fxcor_1.te[0] - dshar5_1.ccentr[0];
/* Computing 2nd power */
    d__2 = fxcor_1.te[1] - dshar5_1.ccentr[1];
    fxcor_1.temp[3] = sqrt(d__1 * d__1 + d__2 * d__2) - dshar5_1.crdius;
    if (fxcor_1.temp[3] < znumbr_1.z0) {
	fxcor_1.temp[1] = -znumbr_1.z1;
    }
    if (abs(fxcor_1.temp[3]) > fxcor_1.temp[10]) {
	goto L700;
    }
    dshar5_1.zdotc = dshar5_1.rzero[0] * dshar5_1.cend[1] - dshar5_1.rzero[1] 
	    * dshar5_1.cend[0];
    if (dshar5_1.zdotc == znumbr_1.z0) {
	goto L1380;
    }
    if (sv_1.past[ifxcor_1.is - 1] >= znumbr_1.z0) {
	goto L690;
    }
    if (abs(fxcor_1.temp[3]) - fxcor_1.temp[4] + zlit1 >= 0.) {
	goto L700;
    } else {
	goto L690;
    }
L690:
    fxcor_1.temp[0] = fxcor_1.temp[1] * fxcor_1.temp[5] * d_sign(&znumbr_1.z1,
	     &dshar5_1.zdotc);
L700:
    fxcor_1.temp[5] = -fxcor_1.temp[0] * fxcor_1.temp[1] * fxcor_1.temp[14];
    if (isv1_1.ifar[ifxcor_1.is - 1] == knumbr_1.k2) {
	fxcor_1.temp[5] = -fxcor_1.temp[5];
    }
    if ((d__1 = sv_1.past[ifxcor_1.is - 1] * fxcor_1.temp[14] * fxcor_1.temp[
	    5]) < 0.) {
	goto L730;
    } else if (d__1 == 0) {
	goto L1380;
    } else {
	goto L750;
    }
L720:
    dshar5_1.radno = fxcor_1.temp[19];
L730:
    dshar5_1.hafdia = dshar5_1.crdius + fxcor_1.temp[10];
    goto L760;
L740:
    dshar5_1.radno = fxcor_1.temp[19];
    fxcor_1.temp[5] = -fxcor_1.temp[5];
L750:
    dshar5_1.hafdia = dshar5_1.crdius - fxcor_1.temp[4];
L760:
/* Computing 2nd power */
    d__1 = ctocl;
/* Computing 2nd power */
    d__2 = temdif;
/* Computing 2nd power */
    d__3 = dshar5_1.hafdia;
    dshar5_1.dsmov = (d__1 * d__1 + d__2 * d__2 - d__3 * d__3) / (znumbr_1.z2 
	    * ctocl);
/* Computing 2nd power */
    d__1 = temdif;
/* Computing 2nd power */
    d__2 = dshar5_1.dsmov;
    fxcor_1.temp[0] = d__1 * d__1 - d__2 * d__2;
    if (fxcor_1.temp[0] >= znumbr_1.z0) {
	goto L790;
    }
    ifxcor_1.ier = 23908;
    goto L1400;
L790:
    ten = sqrt(fxcor_1.temp[0]) * fxcor_1.temp[5];
    dshar5_1.fipnt[0] = dshar5_1.dcentr[0] + dshar5_1.dsmov * dshar5_1.cend[0]
	     + ten * dshar5_1.cend[1];
    dshar5_1.fipnt[1] = dshar5_1.dcentr[1] + dshar5_1.dsmov * dshar5_1.cend[1]
	     - ten * dshar5_1.cend[0];
    goto L1030;
L800:
    if (ctocl - dshar5_1.crdius - dshar5_1.drdius - znumbr_1.z1em3 <= 0.) {
	goto L510;
    } else {
	goto L1370;
    }

/*     LINE DS, CYLINDER CS */

L810:
    dshar5_1.cend[0] = dshar5_1.ccentr[0] - fxcor_1.te[0];
    dshar5_1.cend[1] = dshar5_1.ccentr[1] - fxcor_1.te[1];
/* Computing 2nd power */
    d__1 = dshar5_1.cend[0];
/* Computing 2nd power */
    d__2 = dshar5_1.cend[1];
    dshar5_1.cenlen = sqrt(d__1 * d__1 + d__2 * d__2);
    sv_1.s[ifxcor_1.is - 1] = dshar5_1.cend[0] * zmoshn[0] + dshar5_1.cend[1] 
	    * zmoshn[1];
    dshar5_1.dsmov = dshar5_1.cend[0] * sv_1.sn[ifxcor_1.ids * 3 - 3] + 
	    dshar5_1.cend[1] * sv_1.sn[ifxcor_1.ids * 3 - 2];
    if (ifxcor_1.jsw == knumbr_1.k4) {
	goto L950;
    }
    dshar5_1.offset = abs(dshar5_1.offset);
    if (sv_1.s[ifxcor_1.is - 1] <= znumbr_1.z0) {
	dshar5_1.offset = -dshar5_1.offset;
    }
    if (ifxcor_1.jsw == knumbr_1.k2) {
	goto L900;
    }
    if (dshar5_1.cenlen - dshar5_1.offset - dshar5_1.crdius < sv_1.tau1[
	    ifxcor_1.is - 1]) {
	goto L880;
    }
    if (isv1_1.ifar[ifxcor_1.is - 1] == knumbr_1.k2) {
	goto L880;
    }
    dshar5_1.zign = -znumbr_1.z1;
L870:
    dshar5_1.dif = dshar5_1.crdius + abs(dshar5_1.offset);
    goto L990;
L880:
    dshar5_1.zign = znumbr_1.z1;
L890:
    dshar5_1.dif = dshar5_1.crdius - abs(dshar5_1.offset);
    goto L990;
L900:
    if (dshar5_1.cenlen + dshar5_1.offset - dshar5_1.crdius < sv_1.tau1[
	    ifxcor_1.is - 1]) {
	goto L940;
    }
    if (sv_1.s[ifxcor_1.is - 1] <= znumbr_1.z0) {
	goto L1390;
    }
    if (isv1_1.ifar[ifxcor_1.is - 1] == knumbr_1.k2) {
	goto L940;
    }
    if (abs(dshar5_1.dsmov) + fxcor_1.cutdat[0] - dshar5_1.crdius - sv_1.tau2[
	    ifxcor_1.is - 1] <= 0.) {
	goto L930;
    } else {
	goto L940;
    }
L930:
    dshar5_1.zign = -znumbr_1.z1;
    goto L890;
L940:
    dshar5_1.zign = znumbr_1.z1;
    goto L870;
L950:
    if (sv_1.s[ifxcor_1.is - 1] <= znumbr_1.z0) {
	goto L1380;
    }
    dshar5_1.dsmov += dshar5_1.offset;
    if ((d__2 = dshar5_1.crdius - (d__1 = dshar5_1.dsmov + sv_1.s[
	    ifxcor_1.ids - 1], abs(d__1)), abs(d__2)) > sv_1.tau[ifxcor_1.is 
	    - 1]) {
	goto L1370;
    }
    ten = dshar5_1.offset - d_sign(&znumbr_1.z1, &dshar5_1.dsmov) * 
	    dshar5_1.crdius;
    dshar5_1.fipnt[0] = dshar5_1.ccentr[0] + ten * sv_1.sn[ifxcor_1.ids * 3 - 
	    3];
    dshar5_1.fipnt[1] = dshar5_1.ccentr[1] + ten * sv_1.sn[ifxcor_1.ids * 3 - 
	    2];
    goto L1300;
L990:
/* Computing 2nd power */
    d__1 = dshar5_1.dif;
/* Computing 2nd power */
    d__2 = dshar5_1.dsmov;
    fxcor_1.temp[0] = d__1 * d__1 - d__2 * d__2;
    if (fxcor_1.temp[0] < 0.) {
	goto L1380;
    } else if (fxcor_1.temp[0] == 0) {
	goto L1010;
    } else {
	goto L1000;
    }
L1000:
    sv_1.s[ifxcor_1.is - 1] += dshar5_1.zign * sqrt(fxcor_1.temp[0]);
L1010:
    if (sv_1.s[ifxcor_1.is - 1] + znumbr_1.z1em5 <= 0.) {
	goto L1390;
    } else {
	goto L1020;
    }
L1020:
    dshar5_1.fipnt[0] = fxcor_1.te[0] + sv_1.s[ifxcor_1.is - 1] * zmoshn[0];
    dshar5_1.fipnt[1] = fxcor_1.te[1] + sv_1.s[ifxcor_1.is - 1] * zmoshn[1];
    goto L1300;

/*     COMPUTE INTERMEDIATE CUT VECTORS AROUND CYLINDRICAL DS */

L1030:
    dshar5_1.difout = dshar5_1.dif;
    dshar5_1.rone = (d__1 = dshar5_1.dif - sv_1.tau[ifxcor_1.ids - 1], abs(
	    d__1));
    dshar5_1.costh = dshar5_1.rone / dshar5_1.rzerol;
/* Computing 2nd power */
    d__1 = dshar5_1.costh;
    fxcor_1.temp[0] = znumbr_1.z1 - d__1 * d__1;
    if (fxcor_1.temp[0] + znumbr_1.z1em5 <= 0.) {
	goto L1350;
    } else {
	goto L1050;
    }
L1050:
    dshar5_1.sinth = sqrt((abs(fxcor_1.temp[0])));
    dshar5_1.hchord = dshar5_1.sinth * dshar5_1.rzerol;
    dshar5_1.chord = znumbr_1.z2 * dshar5_1.hchord;
    dshar5_1.dnmot[0] = dshar5_1.rzero[0] / dshar5_1.rzerol;
    dshar5_1.dnmot[1] = dshar5_1.rzero[1] / dshar5_1.rzerol;
    dshar5_1.zign = znumbr_1.z1;
    dshar5_1.tanmot[0] = dshar5_1.dnmot[1];
    dshar5_1.tanmot[1] = -dshar5_1.dnmot[0];
    if (dshar5_1.tanmot[0] * fxcor_1.ti[0] + dshar5_1.tanmot[1] * fxcor_1.ti[
	    1] >= 0.) {
	goto L1080;
    } else {
	goto L1070;
    }
L1070:
    dshar5_1.tanmot[0] = -dshar5_1.tanmot[0];
    dshar5_1.tanmot[1] = -dshar5_1.tanmot[1];
    dshar5_1.zign = -znumbr_1.z1;
L1080:
    fxcor_1.te[0] = fxcor_1.tek[0] + dshar5_1.chord * (dshar5_1.sinth * 
	    dshar5_1.dnmot[0] + dshar5_1.costh * dshar5_1.tanmot[0]);
    fxcor_1.te[1] = fxcor_1.tek[1] + dshar5_1.chord * (dshar5_1.sinth * 
	    dshar5_1.dnmot[1] + dshar5_1.costh * dshar5_1.tanmot[1]);
    dshar5_1.d2[0] = fxcor_1.te[0] - fxcor_1.tek[0];
    dshar5_1.d2[1] = fxcor_1.te[1] - fxcor_1.tek[1];
    dshar5_1.d2[2] = znumbr_1.z0;
    d__ = sqrt(dshar5_1.d2[0] * dshar5_1.d2[0] + dshar5_1.d2[1] * dshar5_1.d2[
	    1]);
    if (d__ <= znumbr_1.z0) {
	goto L1095;
    }
    dshar5_1.d2[0] /= d__;
    dshar5_1.d2[1] /= d__;
    goto L1100;
L1095:
    dshar5_1.d2[0] = zmoshn[0];
    dshar5_1.d2[1] = zmoshn[1];
    dshar5_1.hchord = znumbr_1.z0;
L1100:
/* Computing 2nd power */
    d__1 = dshar5_1.difout;
/* Computing 2nd power */
    d__2 = dshar5_1.rone;
    fxcor_1.temp[9] = sqrt(d__1 * d__1 - d__2 * d__2);
    dshar5_1.delmot[0] = fxcor_1.temp[9] - dshar5_1.hchord;
    fxcor_1.te[0] += dshar5_1.delmot[0] * dshar5_1.d2[0];
    fxcor_1.te[1] += dshar5_1.delmot[0] * dshar5_1.d2[1];
    dshar5_1.stvec[0] = dshar5_1.fipnt[0] - dshar5_1.dcentr[0];
    dshar5_1.stvec[1] = dshar5_1.fipnt[1] - dshar5_1.dcentr[1];
/* Computing 2nd power */
    d__1 = dshar5_1.stvec[0];
/* Computing 2nd power */
    d__2 = dshar5_1.stvec[1];
    fxcor_1.temp[0] = sqrt(d__1 * d__1 + d__2 * d__2);
    fxcor_1.temp[1] = dshar5_1.stvec[0] / fxcor_1.temp[0];
    fxcor_1.temp[2] = dshar5_1.stvec[1] / fxcor_1.temp[0];
    if (dshar5_1.rone <= znumbr_1.z1em5) {
	goto L1250;
    }
    fxcor_1.temp[0] = fxcor_1.temp[1] * dshar5_1.dnmot[0] + fxcor_1.temp[2] * 
	    dshar5_1.dnmot[1];
    fxcor_1.temp[7] = zmoshn[0] * dshar5_1.stvec[0] + zmoshn[1] * 
	    dshar5_1.stvec[1];
    if (abs(fxcor_1.temp[0]) - znumbr_1.z1em7 < znumbr_1.z0) {
	goto L1150;
    }
/* Computing 2nd power */
    d__1 = fxcor_1.temp[0];
    fxcor_1.temp[10] = znumbr_1.z1 - d__1 * d__1;
    if (fxcor_1.temp[10] < znumbr_1.z0) {
	fxcor_1.temp[10] = znumbr_1.z0;
    }
    dshar5_1.zgamma = atan(sqrt(fxcor_1.temp[10]) / fxcor_1.temp[0]);
    if (fxcor_1.temp[0] >= 0.) {
	goto L1190;
    } else {
	goto L1160;
    }
L1150:
    dshar5_1.zgamma = -znumbr_1.pi / znumbr_1.z2;
L1160:
    if (fxcor_1.temp[7] - znumbr_1.z1em7 <= 0.) {
	goto L1180;
    } else {
	goto L1170;
    }
L1170:
    dshar5_1.psi = -dshar5_1.zgamma;
    goto L1220;
L1180:
    dshar5_1.psi = znumbr_1.z2 * znumbr_1.pi + dshar5_1.zgamma;
    goto L1220;
L1190:
    if (fxcor_1.temp[7] < znumbr_1.z0) {
	goto L1210;
    }
    dshar5_1.psi = znumbr_1.pi - dshar5_1.zgamma;
    goto L1220;
L1210:
    dshar5_1.psi = znumbr_1.pi + dshar5_1.zgamma;
L1220:
    fxcor_1.temp[0] = atan(fxcor_1.temp[9] / dshar5_1.rone);
    dshar5_1.theta = fxcor_1.temp[0] + atan(dshar5_1.sinth / dshar5_1.costh);
    dshar5_1.alpha = znumbr_1.z2 * fxcor_1.temp[0];
    dshar5_1.psi += znumbr_1.z2 * znumbr_1.pi * dshar5_1.radno;
    if (dshar5_1.psi - dshar5_1.theta >= 0.) {
	goto L1240;
    } else {
	goto L1230;
    }
L1230:
/* Computing 2nd power */
    d__1 = dshar5_1.fipnt[0] - fxcor_1.tek[0];
/* Computing 2nd power */
    d__2 = dshar5_1.fipnt[1] - fxcor_1.tek[1];
    if (sqrt(d__1 * d__1 + d__2 * d__2) - znumbr_1.z2 * sv_1.eps1[ifxcor_1.is 
	    - 1] >= 0.) {
	goto L1300;
    } else {
	goto L1260;
    }
L1240:
    if (dshar5_1.psi - dshar5_1.theta - dshar5_1.alpha >= 0.) {
	goto L1270;
    } else {
	goto L1250;
    }
L1250:
    zz = znumbr_1.z1;
    ia = knumbr_1.k2;
    ib = knumbr_1.k1;
    if (fxcor_1.temp[1] * dshar5_1.dnmot[0] + fxcor_1.temp[2] * 
	    dshar5_1.dnmot[1] - znumbr_1.z1 != 0.) {
	goto L1251;
    } else {
	goto L1252;
    }
L1251:
    zz = -znumbr_1.z1;
    ia = knumbr_1.k1;
    ib = knumbr_1.k2;
L1252:
    fxcor_1.temp[0] = fxcor_1.temp[1] + zz * dshar5_1.dnmot[0];
    fxcor_1.temp[1] = fxcor_1.temp[2] + zz * dshar5_1.dnmot[1];
    fxcor_1.temp[2] = znumbr_1.z0;
    vnorm_(fxcor_1.temp, fxcor_1.temp);
/*     CALCULATE TOOL POSITION AFTER FIRST CUT AS BEING MIDWAY BETWEEN */
/*     STARTING POSITION AND FINAL POINT */
    fxcor_1.te[0] = dshar5_1.difout * fxcor_1.temp[ia - 1] + dshar5_1.dcentr[
	    0];
    fxcor_1.te[1] = -zz * dshar5_1.difout * fxcor_1.temp[ib - 1] + 
	    dshar5_1.dcentr[1];
    jretn = 0;
    jretn_fmt = fmt_1300;
    if (ia - knumbr_1.k1 <= 0) {
	goto L1255;
    } else {
	goto L1253;
    }
L1253:
    if (fxcor_1.te[0] * zmoshn[0] + fxcor_1.te[1] * zmoshn[1] >= 0.) {
	goto L1255;
    } else {
	goto L1254;
    }
L1254:
    fxcor_1.te[0] = -fxcor_1.te[0];
    fxcor_1.te[1] = -fxcor_1.te[1];

/*     INTERMEDIATE TE OUTPUT. INVERSE ROTATE + Z-CORRECT. */

L1257:
    fxcor_1.tek[2] = fxcor_1.te[2];
L1258:
    fxcor_1.tek[0] = fxcor_1.te[0];
    fxcor_1.tek[1] = fxcor_1.te[1];
L1255:
    if (ifrot == 1) {
	rotat_(fxcor_1.te, b);
    }
    iretn = 1;
    iretn_fmt = fmt_1256;
    goto L1341;
L1256:
    atape_();
    switch (jretn) {
	case 0: goto L1300;
	case 1: goto L1271;
	case 2: goto L1281;
    }
L1260:
    dshar5_1.psi += znumbr_1.z2 * znumbr_1.pi;
L1270:
    dshar5_1.psi -= dshar5_1.theta;
    jretn = 1;
    jretn_fmt = fmt_1271;
    goto L1257;
L1271:
    npts = (integer) (dshar5_1.psi / dshar5_1.alpha + znumbr_1.z1);
    znpts = (doublereal) npts;
    dshar5_1.theta = znumbr_1.z5em1 * dshar5_1.psi / znpts;
    dshar5_1.costh = cos(dshar5_1.theta);
    dshar5_1.sinth = sin(dshar5_1.theta);
    dshar5_1.chord = znumbr_1.z2 * dshar5_1.difout * dshar5_1.sinth;
    dshar5_1.el1 = dshar5_1.chord * dshar5_1.costh;
    dshar5_1.el2 = dshar5_1.chord * dshar5_1.sinth;
    dshar5_1.dnmot[0] = dshar5_1.dcentr[0] - fxcor_1.tek[0];
    dshar5_1.dnmot[1] = dshar5_1.dcentr[1] - fxcor_1.tek[1];
/* Computing 2nd power */
    d__1 = dshar5_1.dnmot[0];
/* Computing 2nd power */
    d__2 = dshar5_1.dnmot[1];
    fxcor_1.temp[0] = sqrt(d__1 * d__1 + d__2 * d__2);
    dshar5_1.dnmot[0] /= fxcor_1.temp[0];
    dshar5_1.dnmot[1] /= fxcor_1.temp[0];
L1280:
    dshar5_1.tanmot[0] = dshar5_1.dnmot[1] * dshar5_1.zign;
    dshar5_1.tanmot[1] = -dshar5_1.dnmot[0] * dshar5_1.zign;
    dshar5_1.delmot[0] = dshar5_1.el1 * dshar5_1.tanmot[0] + dshar5_1.el2 * 
	    dshar5_1.dnmot[0];
    dshar5_1.delmot[1] = dshar5_1.el1 * dshar5_1.tanmot[1] + dshar5_1.el2 * 
	    dshar5_1.dnmot[1];
    dshar5_1.dnmot[0] = (dshar5_1.dcentr[0] - fxcor_1.tek[0] - 
	    dshar5_1.delmot[0]) / fxcor_1.temp[0];
    dshar5_1.dnmot[1] = (dshar5_1.dcentr[1] - fxcor_1.tek[1] - 
	    dshar5_1.delmot[1]) / fxcor_1.temp[0];
    fxcor_1.te[0] = dshar5_1.dcentr[0] - dshar5_1.difout * dshar5_1.dnmot[0];
    fxcor_1.te[1] = dshar5_1.dcentr[1] - dshar5_1.difout * dshar5_1.dnmot[1];
    fxcor_1.te[2] = fxcor_1.tek[2];
    npts -= knumbr_1.k1;
    jretn = 2;
    jretn_fmt = fmt_1281;
    goto L1258;

/*     INTERMEDIATE TE OUTPUT. INVERSE ROTATE + Z-CORRECT. */

L1281:
    if (npts - knumbr_1.k1 <= 0) {
	goto L1300;
    } else {
	goto L1280;
    }
L1300:
    fxcor_1.te[0] = dshar5_1.fipnt[0];
    fxcor_1.te[1] = dshar5_1.fipnt[1];
    sv_1.tn[ifxcor_1.ics * 3 - 1] = 0.f;
    if (isv_1.isfidn[ifxcor_1.is - 1] > knumbr_1.k2) {
	goto L1301;
    }
    sv_1.tn[ifxcor_1.ics * 3 - 3] = dshar5_1.ccentr[0];
    sv_1.tn[ifxcor_1.ics * 3 - 2] = dshar5_1.ccentr[1];
    goto L1302;
L1301:
    sv_1.tn[ifxcor_1.ics * 3 - 3] = dshar5_1.ccentr[0] - fxcor_1.te[0];
    sv_1.tn[ifxcor_1.ics * 3 - 2] = dshar5_1.ccentr[1] - fxcor_1.te[1];
    vnorm_(&sv_1.tn[ifxcor_1.ics * 3 - 3], &sv_1.tn[ifxcor_1.ics * 3 - 3]);
L1302:
    if (isv_1.itlon[ifxcor_1.ics - 1] != 0) {
	goto L1305;
    } else {
	goto L1304;
    }
L1304:
    sv_1.tp[ifxcor_1.ics * 3 - 3] = fxcor_1.te[0];
    sv_1.tp[ifxcor_1.ics * 3 - 2] = fxcor_1.te[1];
    sv_1.tp[ifxcor_1.ics * 3 - 1] = fxcor_1.te[2];
    goto L1306;
L1305:
    sv_1.tp[ifxcor_1.ics * 3 - 3] = fxcor_1.te[0] + sv_1.toolwd[ifxcor_1.ics 
	    - 1] * sv_1.tn[ifxcor_1.ics * 3 - 3];
    sv_1.tp[ifxcor_1.ics * 3 - 2] = fxcor_1.te[1] + sv_1.toolwd[ifxcor_1.ics 
	    - 1] * sv_1.tn[ifxcor_1.ics * 3 - 2];
    sv_1.tp[ifxcor_1.ics * 3 - 1] = fxcor_1.te[2] + sv_1.toolht[ifxcor_1.ics *
	     3 - 1];

/*     SYSTEM INVERSE ROTATION + ZCORRECTION */

L1306:
    if (ifrot == knumbr_1.k0) {
	goto L1308;
    }
    idone = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L1307: */
	    a[i__ + j * 3 - 4] = b[i__ + j * 3 - 4];
	}
    }
    goto L11;
L1308:
    iretn = 2;
    iretn_fmt = fmt_1410;
    goto L1341;

/*     LINE DS, LINE CS */

L1310:
    sv_1.tn[ifxcor_1.is * 3 - 3] = zmoshn[0];
    sv_1.tn[ifxcor_1.is * 3 - 2] = zmoshn[1];
    sv_1.tn[ifxcor_1.is * 3 - 1] = znumbr_1.z0;
    sv_1.tp[ifxcor_1.is * 3 - 3] = fxcor_1.te[0];
    sv_1.tp[ifxcor_1.is * 3 - 2] = fxcor_1.te[1];
    sv_1.tp[ifxcor_1.is * 3 - 1] = fxcor_1.te[2];
    lretn = 1;
    lretn_fmt = fmt_1320;
    goto L1420;
L1320:
    if (isv_1.isftyp[ifxcor_1.is - 1] == knumbr_1.k3) {
	goto L1010;
    }
    dshar5_1.dinc = fxcor_1.cutdat[0] / (d__1 = cnrmal[0] * zmoshn[0] + 
	    cnrmal[1] * zmoshn[1], abs(d__1));
    if (isv_1.isftyp[ifxcor_1.is - 1] != knumbr_1.k1) {
	goto L1340;
    }
    sv_1.s[ifxcor_1.is - 1] -= dshar5_1.dinc;
    goto L1010;
L1340:
    sv_1.s[ifxcor_1.is - 1] += dshar5_1.dinc;
    goto L1010;
L1341:
    if (dopsta == znumbr_1.z0) {
	goto L1345;
    }
    proj = fxcor_1.te[0] * cansto[0] + fxcor_1.te[1] * cansto[1] + fxcor_1.te[
	    2] * cansto[2];
    proj = (proj - dvalui) / dopsta;
    fxcor_1.te[0] -= proj * fxcor_1.ta[0];
    fxcor_1.te[1] -= proj * fxcor_1.ta[1];
    fxcor_1.te[2] -= proj * fxcor_1.ta[2];
L1345:
    switch (iretn) {
	case 0: goto L24;
	case 1: goto L1256;
	case 2: goto L1410;
    }
L1350:
    ifxcor_1.ier = 23901;
    goto L1400;
L1360:
    ifxcor_1.ier = 23902;
    goto L1400;
L1370:
    ifxcor_1.ier = 23903;
    goto L1400;
L1380:
    ifxcor_1.ier = 23904;
    goto L1400;
L1390:
    ifxcor_1.ier = 23905;
L1400:
    aerr_(&ifxcor_1.ier, "ARLM2   ", (ftnlen)8);
L1410:
    ifxcor_1.icl = knumbr_1.k3;
    atape_();
    goto L1470;
L1420:
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.is - 1];
    if (isv_1.isfidn[ifxcor_1.is - 1] > knumbr_1.k2) {
	goto L1430;
    }

/*     ***PLANES AND LINES*** */

    dk = canon[ifxcor_1.ic + 2] - canon[ifxcor_1.ic - 1] * sv_1.tp[
	    ifxcor_1.is * 3 - 3] - canon[ifxcor_1.ic] * sv_1.tp[ifxcor_1.is * 
	    3 - 2] - canon[ifxcor_1.ic + 1] * sv_1.tp[ifxcor_1.is * 3 - 1];
    dot = canon[ifxcor_1.ic - 1] * sv_1.tn[ifxcor_1.is * 3 - 3] + canon[
	    ifxcor_1.ic] * sv_1.tn[ifxcor_1.is * 3 - 2] + canon[ifxcor_1.ic + 
	    1] * sv_1.tn[ifxcor_1.is * 3 - 1];
/* --- CII UPDATE TO DIAGNOZE NON-PARALLEL DRIVE-CHECK SURFACE */
    if (abs(dot) < znumbr_1.z1em7) {
	goto L1390;
    }
    sv_1.s[ifxcor_1.is - 1] = dk / dot;
    goto L1460;

/*     ***CIRCLES AND CYLINDERS*** */

L1430:
    fxcor_1.tem[0] = sv_1.tp[ifxcor_1.is * 3 - 3] - canon[ifxcor_1.ic - 1];
    fxcor_1.tem[1] = sv_1.tp[ifxcor_1.is * 3 - 2] - canon[ifxcor_1.ic];
    dk = sqrt(fxcor_1.tem[0] * fxcor_1.tem[0] + fxcor_1.tem[1] * fxcor_1.tem[
	    1]);
    if (dk >= 1e-4f) {
	goto L1440;
    }
    sv_1.snl[0] = sv_1.tn[ifxcor_1.is * 3 - 3];
    sv_1.snl[1] = sv_1.tn[ifxcor_1.is * 3 - 2];
    v = 1.f;
    goto L1450;
L1440:
    sv_1.snl[0] = fxcor_1.tem[0] / dk;
    sv_1.snl[1] = fxcor_1.tem[1] / dk;
    dk = -sv_1.snl[0] * fxcor_1.tem[0] - sv_1.snl[1] * fxcor_1.tem[1];
    v = d_sign(&znumbr_1.z1, &dk);
L1450:
    sv_1.sp[ifxcor_1.is * 3 - 3] = v * sv_1.snl[0] * canon[ifxcor_1.ic + 5];
    sv_1.sp[ifxcor_1.is * 3 - 2] = v * sv_1.snl[1] * canon[ifxcor_1.ic + 5];
    sv_1.s[ifxcor_1.is - 1] = (sv_1.sp[ifxcor_1.is * 3 - 3] - fxcor_1.tem[0]) 
	    * sv_1.tn[ifxcor_1.is * 3 - 3] + (sv_1.sp[ifxcor_1.is * 3 - 2] - 
	    fxcor_1.tem[1]) * sv_1.tn[ifxcor_1.is * 3 - 1];
L1460:
    switch (lretn) {
	case 0: goto L270;
	case 1: goto L1320;
    }
L1470:
    return 0;
} /* arlm2_ */

#undef zmoshn
#undef cnrmal
#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


