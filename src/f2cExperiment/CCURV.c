/* CCURV.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001877.V04   *** */

/* .....FORTRAN SUBROUTINE             CCURV ...              3/1/68   GK */
/* Subroutine */ int ccurv_(integer *issto, doublereal *sp3, doublereal *spl3,
	 doublereal *sn3)
{
    /* Initialized data */

    static doublereal z1em3 = .001;
    static doublereal z1em4 = 1e-5;
    static doublereal z1em9 = 1e-9;
    static doublereal zero = 0.;
    static doublereal z100 = 100.;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, n;
    static doublereal w1;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


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




    /* Parameter adjustments */
    --sn3;
    --spl3;
    --sp3;

    /* Function Body */

/*             /-INPUT SURFACE PT -SP3, AND NORMAL SN3, AND LAST POINT SP */
/*             /-ISSTO IS INDEX TO CURRENT SURFACE(2=PART,3=DRIVE ETC) */
/*             /-FIND SURFACE CENTER OF CURVATURE AND RADIUS(CC,RC) */

    if (isv_1.ipl[(120 + (0 + (*issto - 1 << 2)) - 120) / 4] == 0) {
	goto L1;
    }
/*             /-PLANAR SURFACE CASE - IPL=1 */
    isv_1.isigcr[*issto - 1] = -1;
    goto L6;
L1:
/*             /-NON-PLANAR GENERAL CASE */
/*             /-CHECK FOR SIGNIFICANCE OF SP-SPL */
/*             /-N=0 MEANS SP-SPL IS TOO SMALL FOR CALCULATION */
    n = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ - 1] = sp3[i__] - spl3[i__];
	if ((d__1 = fxcor_1.temp[i__ - 1], abs(d__1)) > z1em3) {
	    n = 0;
	}
/* L2: */
    }
    if (n <= 0) {
	goto L3;
    }
/*             /-SP-SPL INSIGNIFICANT, USE LAST RC */
    isv_1.isigcr[*issto - 1] = 1;
    goto L6;
L3:
/*             /-NORMAL CASE FOR GENERAL SURFACE */
    vnorm_(fxcor_1.temp, &fxcor_1.temp[3]);
    dotf_(&w1, &fxcor_1.temp[3], &sn3[1]);
    if (abs(w1) >= z1em4) {
	goto L4;
    }
/*             /-SP-SPL ALMOST PERPENDICULAR TO SN . SET RC 45 INCH */
L30:
    d__1 = fxcor_1.rc1 / z100;
    sv_1.rc[*issto - 1] = d_sign(&d__1, &sv_1.rc[*issto - 1]);
    isv_1.isigcr[*issto - 1] = -1;
    goto L6;
L4:
/*     CHECK, WHETHER SURFACE IS LOCALLY ALMOST PLANAR */
    dotf_(&w1, fxcor_1.ta, &sn3[1]);
    if (abs(w1) >= 1. - z1em4 && ifxcor_1.mantax < 2) {
	goto L30;
    }
/*             /-GENERAL CASE, CALCULATE R SO THAT (SP-R*SN-SPL)**2=R**2 */
/*             /-CENTER OF CURV. IS ON SIDE OF SN IF RC NEGATIVE. */
    dotf_(&w1, fxcor_1.temp, &sn3[1]);
    dotf_(&sv_1.rc[*issto - 1], fxcor_1.temp, fxcor_1.temp);
/*             /-R=D**2/(2*(D,SN)) WHERE D=SP-SPL */
    sv_1.rc[*issto - 1] /= w1 + w1;
/*             /-SET FLAG TO NORMAL CASE */
    isv_1.isigcr[*issto - 1] = 0;
/*             /-COMMON RETURN POINT FOR ALL CASES */
L6:
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.cc[i__ + *issto * 3 - 4] = sp3[i__] - sv_1.rc[*issto - 1] * sn3[
		i__];
	if ((d__1 = sv_1.cc[i__ + *issto * 3 - 4], abs(d__1)) < z1em9) {
	    sv_1.cc[i__ + *issto * 3 - 4] = zero;
	}
/* L7: */
    }
    return 0;
} /* ccurv_ */

#undef sinl
#undef cosl


