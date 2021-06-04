/* U1COMP.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__26401 = 26401;

/* *** SOURCE FILE : M0002930.V03   *** */

/* .....FORTRAN SUBROUTINE             U1COMP...              3/1/68   GK */
/* Subroutine */ int u1comp_(void)
{
    /* Initialized data */

    static doublereal zlit1 = 9e-5;
    static doublereal zlit2 = 1e-10;
    static doublereal zlit3 = 1e-4;
    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__;
    static doublereal w1;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), dotf_(
	    doublereal *, doublereal *, doublereal *);
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




/*             /-COMPUTE UNIT VECTOR U1 PERPENDICULAR TO TA TO SELECT */
/*             /-PROPER SIDE OF CUTTER */
/*             /-U1 SHOULD POINT OUTWARD FROM TA */
/*             /-CURRENT CENTER OF CURVATURE CC IS THE PRIMARY INPUT. */


/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */





    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ - 1] = sv_1.cc[i__ + ifxcor_1.is * 3 - 4] - 
		fxcor_1.te[i__ - 1];
/* L1: */
    }
    dotf_(&w1, fxcor_1.temp, fxcor_1.ta);
/*             /-INTIAL U1 POINTS FROM TA OUTWARD TO CC */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2: */
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = fxcor_1.temp[i__ - 1] - w1 * 
		fxcor_1.ta[i__ - 1];
    }
    vnorm_(&sv_1.u1[ifxcor_1.is * 3 - 3], &sv_1.u1[ifxcor_1.is * 3 - 3]);
/*             /-FIRST U1 POINTS DIRECTLY FROM CC TOWARD TOOL AXIS */
    if (ifxcor_1.ier != 0) {
	goto L3;
    }
/*              /-U1 SHOULD BE PERPENDICULAR TO TA IN NORMAL CASE */
    dotf_(&w1, fxcor_1.ta, &sv_1.u1[ifxcor_1.is * 3 - 3]);
    if (abs(w1) < zlit3) {
	goto L18;
    }

/*             /-U1 TOO SMALL, SELECT ANOTHER U1 */
L3:
    if (abs(fxcor_1.ta[2]) >= zlit1) {
	goto L4;
    }
/*             /-K OF TOOL AXIS TOO SMALL, GIVE U1 A K COMPONENT */
    sv_1.u1[ifxcor_1.is * 3 - 3] = zero;
    sv_1.u1[ifxcor_1.is * 3 - 2] = zero;
    sv_1.u1[ifxcor_1.is * 3 - 1] = one;
    goto L18;
L4:
/* Computing 2nd power */
    d__1 = fxcor_1.ta[0];
/* Computing 2nd power */
    d__2 = fxcor_1.ta[1];
    w1 = d__1 * d__1 + d__2 * d__2;
    if (abs(w1) >= zlit2) {
	goto L5;
    }
/*             /-TA IS INSIGNIFICANT, SET U1 IN I DIRECTION */
    sv_1.u1[ifxcor_1.is * 3 - 3] = one;
    sv_1.u1[ifxcor_1.is * 3 - 2] = zero;
    sv_1.u1[ifxcor_1.is * 3 - 1] = zero;
    goto L18;
L5:
    fxcor_1.temp[0] = fxcor_1.ta[0];
    fxcor_1.temp[1] = fxcor_1.ta[1];
    fxcor_1.temp[2] = -w1 / fxcor_1.ta[2];
    vnorm_(fxcor_1.temp, &sv_1.u1[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.ier == 0) {
	goto L18;
    }
/*             /-U1 IS NOT COMPUTABLE DUE TO POORLY CONDITIONED TA */
    aerr_(&c__26401, "U1COMP  ", (ftnlen)8);
    goto L999;

L18:
/*             /-U1 NOW SET, MODIFY SIGN DEPENDING ON TOOL TO SURF RELAT */
    dotf_(&w1, &sv_1.u1[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
/*             /-U1 OPPOSED TO SN FOR SN CONTROL */
    if (w1 < zlit3 && isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L999;
    }
/*             /-U1 AGREES WITH SN(AND TN) FOR TN CONTROL */
    if (w1 >= zero && isv_1.jtn[ifxcor_1.is - 1] != 0) {
	goto L999;
    }
/*             /-REVERSE SIGN OF U1 */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.u1[i__ + ifxcor_1.is * 3 - 4] = -sv_1.u1[i__ + ifxcor_1.is * 3 - 
		4];
/* L12: */
    }
L999:
    return 0;
} /* u1comp_ */

#undef sinl
#undef cosl


