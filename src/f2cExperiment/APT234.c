/* APT234.f -- translated by f2c (version 20100827).
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
    char hps[8], hds[8], hcs[8], hlft[8], hrgt[8], hfwd[8], hback[8], hup[8], 
	    hdown[8], hto[8], hpast[8], hon[8], htanto[8], hpstan[8], hdynp[8]
	    , haerr[8], hcldat[8], hgerr[8];
} hblock_;

#define hblock_1 hblock_

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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__0 = 0;

/* *** SOURCE FILE : M0000854.W01   *** */

/* .....FORTRAN SUBROUTINE  ....APT234         8/68                 AR */

/* Subroutine */ int apt234_(doublereal *hmod, doublereal *adress)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ir;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, kis;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static char test[8];
    extern /* Subroutine */ int apt202_(doublereal *, integer *);
    extern logical ckdef_(doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer isrflg;
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), transm_(doublereal *, doublereal *, integer *, 
	    integer *, integer *);






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */








/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */






/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ...  ESTABLISHES SURFACE PARAMETERS FOR PS,DS,CS AND CALCULATES THE */
/* ...  INDEX OF CANON FOR THE CANONICAL INFORMATION STORAGE */
/* ...  CALLED BY SUBPROGRAMS - APT200,APT201,GO,PSIS */
    /* Parameter adjustments */
    --adress;

    /* Function Body */
    if (ifxcor_1.iaerr != 0) {
	goto L900;
    }
    if (ckdef_(&adress[1])) {
	goto L900;
    }
/* ...  PRE-SET SURFACE CONDITION FLAGS */
    isv_1.ipl[ifxcor_1.is - 1] = 0;
    isv_1.limfl[ifxcor_1.is - 1] = 0;
    isv_1.iunfl[ifxcor_1.is - 1] = 0;
    sv_1.past[ifxcor_1.is - 1] = (doublereal) knumbr_1.k1;
    isv_1.jent[ifxcor_1.is - 1] = 1;
/* ...  SET ISFTYP BASED ON HOLERITH CONTENTS OF HMOD */
    holfrm_(hmod, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, hblock_1.hds, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k1;
    if (s_cmp(test, hblock_1.hto, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k2;
    if (s_cmp(test, hblock_1.hpast, (ftnlen)8, (ftnlen)8) == 0) {
	goto L60;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k3;
    if (s_cmp(test, hblock_1.hon, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k4;
    if (s_cmp(test, hblock_1.htanto, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k8;
    if (s_cmp(test, hblock_1.hpstan, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    isv_1.isftyp[ifxcor_1.is - 1] = knumbr_1.k1;
/* ...  SET SURFACE TYPE CODE IN ISFIDN */
L10:
    isrflg = ifxcor_1.is / ifxcor_1.lsv - 1;
    apt202_(&adress[1], &isrflg);
    unpack_(&adress[1], &isv_1.isfidn[ifxcor_1.is - 1], &j, &k);
    l = (ifxcor_1.is - knumbr_1.k2) * knumbr_1.k10 + knumbr_1.k1;
    isv_1.icanon[ifxcor_1.is - 1] = l;
    if (! ldef_1.refflg && ! ldef_1.refmot) {
	goto L88;
    }
    kis = isv_1.isfidn[ifxcor_1.is - 1];
    if (kis <= 0 || kis > 20) {
	goto L88;
    }
    switch (kis) {
	case 1:  goto L82;
	case 2:  goto L82;
	case 3:  goto L83;
	case 4:  goto L83;
	case 5:  goto L84;
	case 6:  goto L85;
	case 7:  goto L85;
	case 8:  goto L85;
	case 9:  goto L83;
	case 10:  goto L85;
	case 11:  goto L88;
	case 12:  goto L88;
	case 13:  goto L88;
	case 14:  goto L85;
	case 15:  goto L88;
	case 16:  goto L88;
	case 17:  goto L88;
	case 18:  goto L88;
	case 19:  goto L84;
	case 20:  goto L86;
    }
    goto L88;
L82:
    ir = 4;
    goto L87;
L83:
    ir = 5;
    goto L87;
L84:
    ir = 2;
    goto L87;
L85:
    ir = 1;
    goto L87;
L86:
    ir = 3;
L87:
    transm_(&canon[l - 1], &adress[1], &ir, &j, &c__0);
    goto L13;
L88:
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	canon[l - 1] = adress[i__];
/* L12: */
	++l;
    }
L13:
    if ((i__1 = isv_1.isfidn[ifxcor_1.is - 1] - knumbr_1.k3) < 0) {
	goto L50;
    } else if (i__1 == 0) {
	goto L55;
    } else {
	goto L20;
    }
L20:
    if (isv_1.isfidn[ifxcor_1.is - 1] - knumbr_1.k5 <= 0) {
	goto L55;
    } else {
	goto L30;
    }
L30:
    if (isv_1.isfidn[ifxcor_1.is - 1] == 9) {
	goto L55;
    }
    if (isv_1.isfidn[ifxcor_1.is - 1] == 29 || isv_1.isfidn[ifxcor_1.is - 1] 
	    == 30) {
	goto L1000;
    }
    goto L1000;
L50:
    isv_1.ipl[ifxcor_1.is - 1] = knumbr_1.k1;
/* ...  SET IUNFL=1 IF UN CAN BE CALCULATED USING AN OFF SURFACE POINT, */
/* ...  SET TO 0 OTHERWISE */
L55:
    isv_1.iunfl[ifxcor_1.is - 1] = knumbr_1.k1;
L1000:
    return 0;
/* ...  SET PAST=-1 IF A CONDITION OF PAST EXISTS, -1 OTHERWISE */
L60:
    sv_1.past[ifxcor_1.is - 1] = (doublereal) (-knumbr_1.k1);
    goto L10;
/*     SURFACE NOT CORRECTLY DEFINED */
L900:
    ifxcor_1.iaerr = 1;
    goto L1000;
} /* apt234_ */

#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


