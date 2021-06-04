/* DDST.f -- translated by f2c (version 20100827).
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
    doublereal addcom[25];
} addcom_;

#define addcom_1 addcom_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer iddst;
} iddst_;

#define iddst_1 iddst_

/* Table of constant values */

static integer c__2 = 2;
static integer c__26203 = 26203;
static integer c__1 = 1;
static integer c__26204 = 26204;

/* *** SOURCE FILE : M0002893.V06   *** */

/* Subroutine */ int ddst_(void)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* System generated locals */
    static doublereal equiv_11[1];

    /* Local variables */
    static integer i__;
#define j11 ((integer *)equiv_11)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal stem[6];
#define real8 (equiv_11)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *), 
	    apt238_(integer *);
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddtabc_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer ifetch;
    extern /* Subroutine */ int ddplan_(doublereal *), ddquad_(doublereal *);
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
    extern /* Subroutine */ int ddcyln_(doublereal *);
#define kdynfl ((integer *)&addcom_1 + 48)
    extern /* Subroutine */ int ddrlsr_(void), polcon_(doublereal *, integer *
	    ), ddpars_(doublereal *), ddssrf_(doublereal *);


/*              /-DDST FOR DIRECTED DISTANCE TO SURFACE */



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




/* ...  21. ADDCOM BLOCK */

/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*              /-ARRAY TO SAVE SP,SN DATA */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*              /-J11 IS AN INDEX TO THE LOCATION OF LARGE DATA IN CANON */
/*              /-J11 MUST BE ON A DOUBLE WORD BOUNDARY PER APT094 REQS. */




    iddst_1.iddst = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	stem[i__ - 1] = sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
	stem[i__ + 2] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
/* L100: */
    }
    dshar4_1.a = zero;
    dshar4_1.b = zero;
    dshar4_1.c__ = zero;

/*              /-IC IS THE INDEX TO THE INTERNAL CANON FORM OF SURF IS */
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.is - 1];
/*              /-JSW IS THE SURFACE NUMERIC TYPE(1 THRU 30) */
    ifxcor_1.jsw = isv_1.isfidn[ifxcor_1.is - 1];
/*             /-SET MODE TO FETCH LARGE DATA FROM EXTERNAL STORAGE. */
    ifetch = 3;

    switch (ifxcor_1.jsw) {
	case 1:  goto L1;
	case 2:  goto L1;
	case 3:  goto L3;
	case 4:  goto L3;
	case 5:  goto L6;
	case 6:  goto L6;
	case 7:  goto L6;
	case 8:  goto L6;
	case 9:  goto L6;
	case 10:  goto L6;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L6;
	case 15:  goto L15;
	case 16:  goto L99;
	case 17:  goto L99;
	case 18:  goto L99;
	case 19:  goto L99;
	case 20:  goto L99;
	case 21:  goto L99;
	case 22:  goto L99;
	case 23:  goto L99;
	case 24:  goto L99;
	case 25:  goto L99;
	case 26:  goto L99;
	case 27:  goto L99;
	case 28:  goto L99;
	case 29:  goto L29;
	case 30:  goto L30;
    }
L99:
/*              /-ERROR, JSW INDEX IS OUT OF RANGE */
    ifxcor_1.ier = 1;
    goto L999;
L1:
    ddplan_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L3:
    ddcyln_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L6:
    ddquad_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L11:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    --(*j11);
    ddtabc_(&canon[*j11 - 1]);
    goto L1000;

L12:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    ifxcor_1.ic = *j11;
    ddrlsr_();
    goto L1000;

L13:
    polcon_(&canon[ifxcor_1.ic - 1], &c__2);
    goto L1000;
/*              /- */
L15:
    ddpars_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L29:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    ddssrf_(&canon[*j11 - 1]);
    goto L1000;

/*             /-SYNTHETIC CURVE NOT NOW PROGRAMMED FOR ARELEM */
L30:
    aerr_(&c__26203, "DDST    ", (ftnlen)8);
    goto L999;

L1000:

    if (*kdynfl != 0) {
	apt238_(&c__1);
    }

/*              /-EXIT POINT FOR DDST ROUTINE */
/*              /-RESTORE SURFACE DATA */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = stem[i__ - 1];
/* L700: */
	sv_1.sp[i__ + ifxcor_1.is * 3 - 4] = stem[i__ + 2];
    }


L999:
    iddst_1.iddst = 0;
    return 0;
} /* ddst_ */

#undef kdynfl
#undef clngth
#undef ibtflg
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef real8
#undef sinl
#undef cosl
#undef jlin
#undef can
#undef j11






/* Subroutine */ int ajundd_(void)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* System generated locals */
    static doublereal equiv_11[1];

    /* Local variables */
    static integer i__;
    static doublereal w1;
#define j11 ((integer *)equiv_11)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define jlin ((integer *)&addcom_1 + 46)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
#define real8 (equiv_11)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *), 
	    apt238_(integer *), radar_(void);
#define canon ((doublereal *)&_BLNK__1)
#define elmax ((doublereal *)&addcom_1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int ddtabc_(doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static integer ifetch;
    extern /* Subroutine */ int ddplan_(doublereal *), ddquad_(doublereal *);
#define ibtflg ((integer *)&addcom_1 + 44)
#define clngth ((doublereal *)&addcom_1 + 1)
    extern /* Subroutine */ int ddcyln_(doublereal *);
#define kdynfl ((integer *)&addcom_1 + 48)
    extern /* Subroutine */ int ddrlsr_(void), polcon_(doublereal *, integer *
	    ), ddpars_(doublereal *), ddssrf_(doublereal *);


/*              /-AJUNDD FOR DISTANCE AND LINEUP WITH SURFACE. */



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




/* ...  21. ADDCOM BLOCK */

/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*              /-ARRAY TO SAVE SP,SN DATA */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*              /-J11 IS AN INDEX TO THE LOCATION OF LARGE DATA IN CANON */
/*              /-J11 MUST BE ON A DOUBLE WORD BOUNDARY PER APT094 REQS. */





/*              /-GIVEN TP,TN FIND SP,SN,S ON SURFACE */
/*              /-SUCH THAT TP+S*TN=SP */

    iddst_1.iddst = 2;
    ishr18_1.mdic = 0;

L200:
/*              /-IC IS THE INDEX TO THE INTERNAL CANON FORM OF SURF IS */
    ifxcor_1.ic = isv_1.icanon[ifxcor_1.is - 1];
/*              /-JSW IS THE SURFACE NUMERIC TYPE(1 THRU 30) */
    ifxcor_1.jsw = isv_1.isfidn[ifxcor_1.is - 1];
/*             /-SET MODE TO FETCH LARGE DATA FROM EXTERNAL STORAGE. */
    ifetch = 3;

    switch (ifxcor_1.jsw) {
	case 1:  goto L1;
	case 2:  goto L1;
	case 3:  goto L3;
	case 4:  goto L3;
	case 5:  goto L6;
	case 6:  goto L6;
	case 7:  goto L6;
	case 8:  goto L6;
	case 9:  goto L6;
	case 10:  goto L6;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L6;
	case 15:  goto L15;
	case 16:  goto L99;
	case 17:  goto L99;
	case 18:  goto L99;
	case 19:  goto L99;
	case 20:  goto L99;
	case 21:  goto L99;
	case 22:  goto L99;
	case 23:  goto L99;
	case 24:  goto L99;
	case 25:  goto L99;
	case 26:  goto L99;
	case 27:  goto L99;
	case 28:  goto L99;
	case 29:  goto L29;
	case 30:  goto L30;
    }
L99:
/*              /-ERROR, JSW INDEX IS OUT OF RANGE */
    ifxcor_1.ier = 1;
    goto L999;
L1:
    ddplan_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L3:
    ddcyln_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L6:
    ddquad_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L11:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    --(*j11);
    ddtabc_(&canon[*j11 - 1]);
    goto L1000;

L12:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    ifxcor_1.ic = *j11;
    ddrlsr_();
    goto L1000;

L13:
    polcon_(&canon[ifxcor_1.ic - 1], &c__2);
    goto L1000;
/*              /- */
L15:
    ddpars_(&canon[ifxcor_1.ic - 1]);
    goto L1000;

L29:
    apt094_(&ifetch, &canon[ifxcor_1.ic - 1], j11);
    ddssrf_(&canon[*j11 - 1]);
    goto L1000;

/*             /-SYNTHETIC CURVE NOT NOW PROGRAMMED FOR ARELEM */
L30:
    aerr_(&c__26203, "AJUNDD  ", (ftnlen)8);
    goto L999;

L1000:

    if (*kdynfl != 0) {
	apt238_(&c__1);
    }

    if (ifxcor_1.ier == 0) {
	goto L810;
    }
/*              /-CALL RADAR TO GENERATE A NEW TP,TN FOR INTERSECTION */
    radar_();
/*              /-RESTART IF RADAR HAS OBTAINED A GOOD TP,TN */
    if (ifxcor_1.iaerr == 0) {
	goto L200;
    }
/*              /-OTHERWISE, TERMINATE WITH THIS IAERR SETTING. */
    goto L999;

L810:
    if (*kdynfl != 0) {
	apt238_(&c__2);
    }
/*              /-RADAR EXHAUSTED ALL TRIES */
    if (ifxcor_1.ier != 0) {
	aerr_(&c__26204, "AJUNDD  ", (ftnlen)8);
    }
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	goto L820;
    }
/*              /-ADJUST Z EACH TIME FOR CS, SN,TN SHOULD LIE SAME WAY. */
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], &sv_1.sn[ifxcor_1.is * 3 - 3]);
    sv_1.z__[ifxcor_1.is - 1] = one;
    if (w1 < zero) {
	sv_1.z__[ifxcor_1.is - 1] = -one;
    }
L820:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L830: */
	sv_1.sn[i__ + ifxcor_1.is * 3 - 4] = sv_1.z__[ifxcor_1.is - 1] * 
		sv_1.sn[i__ + ifxcor_1.is * 3 - 4];
    }


/*              /-EXIT POINT */
L999:
    iddst_1.iddst = 0;
    return 0;
} /* ajundd_ */

#undef kdynfl
#undef clngth
#undef ibtflg
#undef bcanon
#undef sscan
#undef elmax
#undef canon
#undef real8
#undef sinl
#undef cosl
#undef jlin
#undef can
#undef j11


