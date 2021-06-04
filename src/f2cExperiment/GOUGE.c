/* GOUGE.f -- translated by f2c (version 20100827).
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
    integer iamdct, ipdpl, ipt, iws, jckr, jcnt1, jcnt2, jcnt3, jcpr, jcr, 
	    jdr, jfind, jgr, jmin, jminr, jpr, jpxr, jtkf, jtr, j10, j12, j13,
	     j54, mdic;
} ishr18_;

#define ishr18_1 ishr18_

struct {
    doublereal talt[3], svgl, shilf, gflg, tpg[3], spg[3];
} cgoug_;

#define cgoug_1 cgoug_

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

/* *** SOURCE FILE : M0000916.V01   *** */


/* .....FORTRAN SUBROUTINE ...GOUGE          SUPPLIED BY VW  6/88 */

/*                         MODIFIED FOR SSV..  E.MCLELLAN */

/* Subroutine */ int gouge_(void)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal hilf[3];
    static integer iflg;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal ssav, zahl, hilf1, u1sav[3], tpsav[3], tnsav[3], spsav[
	    3], snsav[3], vtsav[3], durch, rcsav;
    static integer itsav;
    static doublereal flipab;
    extern /* Subroutine */ int ajundd_(void);
    static doublereal flipmx;

/*     VERSION K1 VOM 8.6.86 */


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






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */











/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++ */
/* +++  KORR  6-GOUGE -2 */
/* +++ */
    durch = tlldat_1.ri[5];
/*     INITIALISIERUNG */
    ishr18_1.jgr = 0;
    iflg = (integer) cgoug_1.gflg;
/*     IF (IABS(IFLG) .GT. 1) STOP ' BETRAG VON GFLG GROESSER 1 ' */
    if (iflg >= 0) {

	cgoug_1.gflg = zero;
	ifxcor_1.is = ifxcor_1.ips;

/*     WRITE(6,1006) (TE(I), I=1,3) */
/*     WRITE(6,1007) (TP(I,IS), I=1,3) */

/*      PRINT *, 'GOUGE1:STORE DATA(FLIPMX,RCSAV,TPSAV,....' */
/* +++ */
/* +++  KORR  6-GOUGE -2 ENDE */
/* +++ */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

	flipmx = dshar4_1.flipck;
	flipab = abs(dshar4_1.flipck);
	rcsav = sv_1.rc[ifxcor_1.is - 1];
	ssav = sv_1.s[ifxcor_1.is - 1];
	itsav = isv_1.itseg[ifxcor_1.is - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
	    tpsav[i__ - 1] = sv_1.tp[i__ + ifxcor_1.is * 3 - 4];
	    tnsav[i__ - 1] = sv_1.tn[i__ + ifxcor_1.is * 3 - 4];
	    spsav[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
	    snsav[i__ - 1] = sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
	    u1sav[i__ - 1] = sv_1.u1[i__ + ifxcor_1.is * 3 - 4];
	    vtsav[i__ - 1] = sv_1.vt[i__ + ifxcor_1.is * 3 - 4];
/* L2900: */
	}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
/* +++ */
/* +++  KORR  6-GOUGE -3 */
/* +++ */
/* KEINE PRUEFUNG WENN DP SCHON KLEIN */
/* ---  IF (DP .LT. 0.5D0)  GOTO 106 */
	if (dshar4_1.dp < 2.) {
	    goto L106;
	}


	dotf_(&zahl, fxcor_1.ti, cgoug_1.talt);
/* --T--WRITE(6,1003) ZAHL */
/*      PRINT *, 'GOUGE1 AUFRUF AJUNDD' */
	for (i__ = 1; i__ <= 3; ++i__) {
	    sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + durch *
		     fxcor_1.ti[i__ - 1];
/* L100: */
	}
/* --T--WRITE(6,1008) (TP(I,IS), I=1,3) */
	modess_1.modess = 11;
	ajundd_();
	modess_1.modess = 0;
/*     VERLETZUNG DER OBERFLAECHE */
	for (i__ = 1; i__ <= 3; ++i__) {
	    hilf[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - sv_1.tp[i__ 
		    + ifxcor_1.is * 3 - 4];
/* L101: */
	}
	dotf_(&cgoug_1.shilf, hilf, hilf);
	cgoug_1.shilf = sqrt(cgoug_1.shilf);
	dotf_(&hilf1, hilf, &sv_1.sn[ifxcor_1.is * 3 - 3]);
	if (hilf1 > 0.) {
	    cgoug_1.shilf = -cgoug_1.shilf;
	}
	if (cgoug_1.shilf > 0.) {
	    goto L103;
	}
/* ---  IF (DABS(SHILF) .LT. 2.0D0*TAU(IS) ) GOTO 106 */
/*   WARNUNG AUSGEBEN */
	if (abs(cgoug_1.shilf) < sv_1.tau[ifxcor_1.is - 1] * 10.) {
	    goto L106;
	}
/* --T--WRITE(6,7015)(TE(I),I=1,3) */
/* L7015: */
	goto L106;

/* --- RESTORE DATA */

L103:
/*     KEIN LOOK AHEAD, WENN DP NICHT GROSS GENUG */
	if (abs(cgoug_1.shilf) > sv_1.tau[ifxcor_1.is - 1] * 2.f) {
	    goto L106;
	}
	if (dshar4_1.dp < 2.) {
	    goto L106;
	}
/*      PRINT *, 'GOUGE1 AUFRUF AJUNDD MIT LOOK AHEAD' */
	for (i__ = 1; i__ <= 3; ++i__) {
	    sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.te[i__ - 1] + (
		    dshar4_1.dp + durch) * fxcor_1.ti[i__ - 1];
/* L104: */
	}
/* --T--WRITE(6,1008) (TP(I,IS), I=1,3) */
	modess_1.modess = 11;
	ajundd_();
	modess_1.modess = 0;
/*     VERLETZUNG DER OBERFLAECHE */
	for (i__ = 1; i__ <= 3; ++i__) {
	    hilf[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - sv_1.tp[i__ 
		    + ifxcor_1.is * 3 - 4];
/* L105: */
	}
	dotf_(&cgoug_1.shilf, hilf, hilf);
	cgoug_1.shilf = sqrt(cgoug_1.shilf);
	dotf_(&hilf1, hilf, &sv_1.sn[ifxcor_1.is * 3 - 3]);
	if (hilf1 > 0.) {
	    cgoug_1.shilf = -cgoug_1.shilf;
	}
	if (cgoug_1.shilf > 0.) {
	    goto L106;
	}
	if (abs(cgoug_1.shilf) < sv_1.tau[ifxcor_1.is - 1] * 15.) {
	    goto L106;
	}
/* --   IF (DABS(SHILF) .LT. 2.5D1*TAU(IS) ) GOTO 106 */
/* ZUSAETZLICHES KRITERIUM */
	cgoug_1.gflg = 1.;
	ishr18_1.jgr = -1;
/* +++ */
/* +++  KORR  6-GOUGE -3 ENDE */
/* +++ */
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

L106:
/*      PRINT *, 'GOUGE1 RESTORE DATA , GFLG = ', GFLG */
	sv_1.rc[ifxcor_1.is - 1] = rcsav;
	sv_1.s[ifxcor_1.is - 1] = ssav;
	isv_1.itseg[ifxcor_1.is - 1] = itsav;
	for (i__ = 1; i__ <= 3; ++i__) {
	    sv_1.tp[i__ + ifxcor_1.is * 3 - 4] = tpsav[i__ - 1];
	    sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = tnsav[i__ - 1];
	    sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = spsav[i__ - 1];
	    sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = snsav[i__ - 1];
	    sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = u1sav[i__ - 1];
	    sv_1.vt[i__ + ifxcor_1.is * 3 - 4] = vtsav[i__ - 1];
/* L2910: */
	}

    } else {
	cgoug_1.gflg = zero;
    }

/* L1000: */
/* L1001: */
/* L1002: */
/* L1003: */
/* L1004: */
/* L1006: */
/* L1007: */
/* L1008: */
    return 0;
} /* gouge_ */

#undef sinl
#undef cosl


