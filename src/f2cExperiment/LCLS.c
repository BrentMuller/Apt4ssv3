/* LCLS.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__27003 = 27003;
static integer c__27002 = 27002;
static integer c_b15 = -27001;

/* *** SOURCE FILE : M0002840.V05   *** */

/* CCCCCCCC */
/* ....    FORTRAN SUBROUTINE ....  LCLS             RC  4/70 */

/* Subroutine */ int lcls_(doublereal *u, doublereal *v, doublereal *ssp, 
	doublereal *dderu, doublereal *dderv, integer *mmode)
{
    /* Initialized data */

    static doublereal dd = 0.;

    /* Local variables */
    static integer i__;
    static doublereal r2[3], r3[3], u2, u4, v1, v2;
    static integer mm;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ker, kkk;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define canon ((doublereal *)&_BLNK__1)
    static doublereal dincx;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)


/* ...CALLS TO PARCHK & FCN HAVE BEEN COMMENTED OUT AS THE PARSRF */
/* ....FACILITY IS NOT PROVIDED.   24/9/86.   E.MCLELLAN. */


/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




    /* Parameter adjustments */
    --dderv;
    --dderu;
    --ssp;

    /* Function Body */

/*  --------------------------------------------------------------~ */

    if (*mmode != 1) {
	goto L5;
    }
/*      CALL PARCHK(CANON(IC),KER) */
    if (ker == 1) {
	aerr_(&c__27003, "LCLS    ", (ftnlen)8);
    }
L5:
/* ------MM=1  DERIV CASE.  MM=0  NODER CASE. */
L4000:
    mm = (integer) canon[ifxcor_1.ic + 2];
    if (mm == 0) {
	goto L10;
    }
/*      CALL FCN (CANON(IC),U,V,SSP,DDERU,DDERV,W1,W2,W3,W4,W5,W6) */
    if (*mmode == 1) {
	goto L1000;
    }
L2000:
    goto L60;

L10:
    dincx = 1e-4f;
/* ------COMPUTE THE SURFACE POINT */
/*      CALL FCN (CANON(IC),U,V,SSP,DDERU,DDERV,W1,W2,W3,W4,W5,W6) */
    if (*mmode == 1) {
	goto L1000;
    }
L3000:
/* ------COMPUTE THE PARTIAL DERIVATIVE WITH RESPECT TO U */
    u4 = *u + dincx;
/*      CALL FCN (CANON(IC),U4,V,R3,DDERU,DDERV,W1,W2,W3,W4,W5,W6) */
    u2 = *u - dincx;
/*      CALL FCN (CANON(IC),U2,V,R2,DDERU,DDERV,W1,W2,W3,W4,W5,W6) */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	dderu[i__] = (r3[i__ - 1] - r2[i__ - 1]) / (dincx * 2);
    }
/* ------COMPUTE THE PARTIAL WITH RESPECT TO V */
    v1 = *v + dincx;
/*      CALL FCN (CANON(IC),U,V1,R3,DDERV,DDERV,W1,W2,W3,W4,W5,W6) */
    v2 = *v - dincx;
/*      CALL FCN (CANON(IC),U,V2,R2,DDERV,DDERV,W1,W2,W3,W4,W5,W6) */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	dderv[i__] = (r3[i__ - 1] - r2[i__ - 1]) / (dincx * 2);
    }

L60:
    cross_(&dderu[1], &dderv[1], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    vnorm_(&sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    if (ifxcor_1.ier == 1) {
	aerr_(&c__27002, "LCLS    ", (ftnlen)8);
    }
    return 0;
L1000:
    kkk = 1;
    if (dderu[1] == dd && dderu[2] == dd && dderu[3] == dd && dderv[1] == dd 
	    && dderv[2] == dd && dderv[3] == dd) {
	kkk = 0;
    }
    if (mm == 1 && kkk == 1) {
	goto L2000;
    }
    if (mm == 0 && kkk == 0) {
	goto L3000;
    }
    aerr_(&c_b15, "LCLS    ", (ftnlen)8);
    canon[ifxcor_1.ic + 2] = (doublereal) kkk;
    goto L4000;
} /* lcls_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


