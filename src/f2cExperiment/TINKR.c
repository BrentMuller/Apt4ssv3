/* TINKR.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000733.W01   *** */


/* .....FORTRAN SUBROUTINE             TINKR....              4/1/68   GK */
/* Subroutine */ int tinkr_(void)
{
    /* Initialized data */

    static doublereal zlit1 = .999999;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, kdb;
    static doublereal tdb;
    static integer itl, itt;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);






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




/* ...  NOTE- IN THIS PROGRAM BOTH ITL AND ITT ARE PROGRAM VARIABLES */
/*           AND DO NOT APPEAR IN COMMON */
    ishr18_1.jtr = 1;
    ifxcor_1.ips = ifxcor_1.ips;
    ifxcor_1.ids = ifxcor_1.ids;
/* ...     MULTAX = 1 - FIXED TA, MULTAX = 2 - PS CONTROL, MULTAX = 3 */
/* ...     DS CONTROL. */
    itl = ifxcor_1.ids;
    itt = ifxcor_1.ips;
    if ((i__1 = ifxcor_1.mantax - 2) < 0) {
	goto L350;
    } else if (i__1 == 0) {
	goto L10;
    } else {
	goto L20;
    }
L10:
    itl = ifxcor_1.ips;
    itt = ifxcor_1.ids;
/* ...     NUMAX = 0 - 4-AXIS, NUMAX = 1 - 5-AXIS, NUMAX = 2 - */
/* ...     RULED SURFACE, NUMAX = 3 - NEW SURFACE, NUMAX = 4 - */
/* ...     PIVOT POINT */
L20:
    i__ = ifxcor_1.numax + 1;
    switch (i__) {
	case 1:  goto L230;
	case 2:  goto L30;
	case 3:  goto L270;
	case 4:  goto L40;
	case 5:  goto L320;
    }
L30:
    fxcor_1.ax4[0] = sv_1.tn[itt * 3 - 3];
    fxcor_1.ax4[1] = sv_1.tn[itt * 3 - 2];
    fxcor_1.ax4[2] = sv_1.tn[itt * 3 - 1];
/* ...     AX4 IS NORMAL TO SECONDARY SURFACE. */
/* ...     TEMP(7) IS NORMAL TO PLANE OF AX4 AND TN(ITL). */
L40:
    cross_(fxcor_1.ax4, &sv_1.tn[itl * 3 - 3], &fxcor_1.temp[6]);
    vnorm_(&fxcor_1.temp[6], &fxcor_1.temp[6]);
    if (ifxcor_1.ier != 0) {
	goto L50;
    } else {
	goto L60;
    }
/* ...     NORMALS COINCIDE - LET TEMP(7) = TI */
L50:
    fxcor_1.temp[6] = fxcor_1.ti[0];
    fxcor_1.temp[7] = fxcor_1.ti[1];
    fxcor_1.temp[8] = fxcor_1.ti[2];
/* ...     TEMP IS X-AXIS OF PLANE OF NEW TOOL AXIS. */
L60:
    cross_(&sv_1.tn[itl * 3 - 3], &fxcor_1.temp[6], fxcor_1.temp);
    vnorm_(fxcor_1.temp, fxcor_1.temp);
    if (ifxcor_1.ier != 0) {
	goto L340;
    } else {
	goto L70;
    }
/* ...     TEMP(10),TEMP(11) ARE SIN AND COS OF LEAD-LAG ANGLE */
L70:
    fxcor_1.temp[9] = sin(fxcor_1.alp);
    fxcor_1.temp[10] = cos(fxcor_1.alp);
    if (fxcor_1.temp[6] * fxcor_1.ti[0] + fxcor_1.temp[7] * fxcor_1.ti[1] + 
	    fxcor_1.temp[8] * fxcor_1.ti[2] >= 0.) {
	goto L90;
    } else {
	goto L80;
    }
L80:
    fxcor_1.temp[9] = -fxcor_1.temp[9];
/* ...     ROTATE PLANE OF CALCULATION - TEMP(4) IS Y-AXIS OF TA PLANE */
L90:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L100: */
	fxcor_1.temp[i__ + 2] = fxcor_1.temp[9] * fxcor_1.temp[i__ + 5] + 
		fxcor_1.temp[10] * sv_1.tn[i__ + itl * 3 - 4];
    }
    vnorm_(&fxcor_1.temp[3], &fxcor_1.temp[3]);

/*     COMPUTE NEW TA W/O ANY MODIFICATIONS = T7 */

L105:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L110: */
	fxcor_1.temp[i__ + 5] = -fxcor_1.sagl * fxcor_1.temp[i__ - 1] - 
		fxcor_1.cagl * fxcor_1.temp[i__ + 2];
    }
    vnorm_(&fxcor_1.temp[6], &fxcor_1.temp[6]);
    if (ifxcor_1.ier != 0) {
	goto L340;
    } else {
	goto L120;
    }

/*     DOT NEW TA AND OLD TA = T12 */

L120:
    fxcor_1.temp[11] = fxcor_1.temp[6] * fxcor_1.ta[0] + fxcor_1.temp[7] * 
	    fxcor_1.ta[1] + fxcor_1.temp[8] * fxcor_1.ta[2];

/*     IF DOT .LT. 0 REVERSE NEW TA */

    if (fxcor_1.temp[11] >= 0.) {
	goto L125;
    } else {
	goto L121;
    }
L121:
    fxcor_1.temp[6] = -fxcor_1.temp[6];
    fxcor_1.temp[7] = -fxcor_1.temp[7];
    fxcor_1.temp[8] = -fxcor_1.temp[8];
    fxcor_1.temp[11] = -fxcor_1.temp[11];

/* 6    IF DOT .GT. .999995 SET JTKF = 1 + RETURN */

L125:
    if (fxcor_1.temp[11] - zlit1 >= 0.) {
	goto L130;
    } else {
	goto L135;
    }
L130:
    ishr18_1.jtkf = 1;
    goto L350;

L135:
    if (ishr18_1.jcnt1 + ishr18_1.jcnt3 - 45 <= 0) {
	goto L136;
    } else {
	goto L138;
    }
L136:
    ++kdb;
    tdb = (doublereal) kdb;
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[11] = fxcor_1.ta[i__ - 1];
	fxcor_1.ta[i__ - 1] = (tdb * fxcor_1.temp[i__ + 5] + fxcor_1.ta[i__ - 
		1]) / (tdb + 1.f);
/* L137: */
	fxcor_1.temp[i__ + 5] = fxcor_1.temp[11];
    }
    vnorm_(fxcor_1.ta, fxcor_1.ta);
    goto L140;
L138:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[11] = fxcor_1.ta[i__ - 1];
	fxcor_1.ta[i__ - 1] = fxcor_1.temp[i__ + 5];
/* L1385: */
	fxcor_1.temp[i__ + 5] = fxcor_1.temp[11];
    }
/* L1388: */
    kdb = 0;
L140:
    ishr18_1.jtr = 0;
/* L145: */
    if (ifxcor_1.numax - 4 != 0) {
	goto L150;
    } else {
	goto L350;
    }
/* ...     ROTATE TOOL ABOUT CONTACT POINT OF CONTROLLING SURFACE */
/* ...     DETERMINE INITIAL ORIENTATION OF TE TO TA. */
/* ...     TEMP(4) IS PERP. TO PLANE OF OLD TA,TE,AND TP(ITL) */
L150:
    fxcor_1.temp[0] = fxcor_1.te[0] - sv_1.tp[itl * 3 - 3] + sv_1.th[itl - 1] 
	    * sv_1.tn[itl * 3 - 3];
    fxcor_1.temp[1] = fxcor_1.te[1] - sv_1.tp[itl * 3 - 2] + sv_1.th[itl - 1] 
	    * sv_1.tn[itl * 3 - 2];
    fxcor_1.temp[2] = fxcor_1.te[2] - sv_1.tp[itl * 3 - 1] + sv_1.th[itl - 1] 
	    * sv_1.tn[itl * 3 - 1];
    cross_(&fxcor_1.temp[6], fxcor_1.temp, &fxcor_1.temp[3]);
    vnorm_(&fxcor_1.temp[3], &fxcor_1.temp[3]);
    if (ifxcor_1.ier != 0) {
	goto L350;
    } else {
	goto L160;
    }

/* ...     TEMP IS PERP. TO NEW TA IN PLANE OF TN(ITL) */
L160:
    cross_(&sv_1.tn[itl * 3 - 3], fxcor_1.ta, fxcor_1.temp);
    cross_(fxcor_1.ta, fxcor_1.temp, fxcor_1.temp);
/* L170: */
    vnorm_(fxcor_1.temp, fxcor_1.temp);
    if (ifxcor_1.ier != 0) {
	goto L180;
    } else {
	goto L190;
    }
L180:
    cross_(&fxcor_1.temp[6], &fxcor_1.temp[3], fxcor_1.temp);
    vnorm_(fxcor_1.temp, fxcor_1.temp);
/* ...     CALCULATE VECTOR IN PLANE OF TA AND TEMP WHICH WILL BE */
/* ...     FROM TP(ITL) TO NEW TE. RA, HI ARE COORDINATES OF RING. */
L190:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L200: */
	fxcor_1.temp[i__ + 8] = fxcor_1.ra * fxcor_1.temp[i__ - 1] - 
		fxcor_1.hi * fxcor_1.ta[i__ - 1];
    }
/* ...     TEMP(13) IS PERP. TO PLANE OF NEW TA,TP(ITL), AND NEW TE. */
/* ...     ORIENTATION OF TEMP(4) AND TEMP(13) MUST BE SAME. */
    cross_(fxcor_1.ta, &fxcor_1.temp[9], &fxcor_1.temp[12]);
    fxcor_1.temp[13] = fxcor_1.temp[3] * fxcor_1.temp[12] + fxcor_1.temp[4] * 
	    fxcor_1.temp[13] + fxcor_1.temp[5] * fxcor_1.temp[14];
    if (fxcor_1.temp[13] >= 0.) {
	goto L220;
    } else {
	goto L210;
    }
L210:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L215: */
	fxcor_1.temp[i__ + 8] = -(fxcor_1.ra * fxcor_1.temp[i__ - 1] + 
		fxcor_1.hi * fxcor_1.ta[i__ - 1]);
    }
L220:
    fxcor_1.te[0] = fxcor_1.temp[9] + sv_1.tp[itl * 3 - 3];
    fxcor_1.te[1] = fxcor_1.temp[10] + sv_1.tp[itl * 3 - 2];
    fxcor_1.te[2] = fxcor_1.temp[11] + sv_1.tp[itl * 3 - 1];
    goto L350;

/* ...     4-AXIS CASE - TA MUST LIE IN PLANE PERP. TO AX4 */
/*        TEMP IS X-AXIS OF PLANE OF NEW TA. */
L230:
    cross_(&sv_1.tn[itl * 3 - 3], fxcor_1.ax4, fxcor_1.temp);
    vnorm_(fxcor_1.temp, fxcor_1.temp);
    if (ifxcor_1.ier != 0) {
	goto L350;
    } else {
	goto L240;
    }
/* ...     TEMP MUST BE IN DIRECTION OF TN(ITT). */
L240:
    fxcor_1.temp[9] = sv_1.tn[itt * 3 - 3] * fxcor_1.temp[0] + sv_1.tn[itt * 
	    3 - 2] * fxcor_1.temp[1] + sv_1.tn[itt * 3 - 1] * fxcor_1.temp[2];
    if (fxcor_1.temp[9] >= 0.) {
	goto L260;
    } else {
	goto L250;
    }
L250:
    fxcor_1.temp[0] = -fxcor_1.temp[0];
    fxcor_1.temp[1] = -fxcor_1.temp[1];
    fxcor_1.temp[2] = -fxcor_1.temp[2];
/* ...     TEMP(4) IS X-AXIS IN PLANE OF NEW TA. */
L260:
    cross_(fxcor_1.ax4, fxcor_1.temp, &fxcor_1.temp[3]);
    vnorm_(&fxcor_1.temp[3], &fxcor_1.temp[3]);
    if (ifxcor_1.ier != 0) {
	goto L340;
    } else {
	goto L105;
    }
/* ...     RULED SURFACE. */
/*        TA WILL BE PARALLEL TO RULING. */
L270:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L280: */
	fxcor_1.temp[i__ + 5] = sv_1.slx[i__ + itl * 3 - 4];
    }
    goto L120;
/* ...     PIVOT POINT - AXIS WILL PASS THRU POINT AX4, ROTATE AROUND TE. */
L320:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ + 5] = fxcor_1.ta[i__ - 1];
/* L330: */
	fxcor_1.ta[i__ - 1] = fxcor_1.ax4[i__ - 1] - fxcor_1.te[i__ - 1];
    }
    vnorm_(fxcor_1.ta, fxcor_1.ta);
    if (ifxcor_1.ier != 0) {
	goto L335;
    } else {
	goto L120;
    }
L335:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L336: */
	fxcor_1.ta[i__ - 1] = fxcor_1.temp[i__ + 5];
    }
    goto L350;
L340:
    ishr18_1.jtr = -1;
L350:
    return 0;
} /* tinkr_ */

#undef sinl
#undef cosl


