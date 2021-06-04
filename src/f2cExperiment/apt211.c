/* apt211.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

struct {
    doublereal saveh[50];
} hsave_;

#define hsave_1 hsave_

struct {
    integer lseqno;
} sqnc_;

#define sqnc_1 sqnc_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__20104 = 20104;
static integer c__20109 = 20109;
static integer c__20102 = 20102;
static integer c__20103 = 20103;
static integer c__20105 = 20105;
static integer c__20106 = 20106;
static integer c__20107 = 20107;
static integer c__20108 = 20108;
static integer c__20110 = 20110;

integer apt211_(doublereal *adress, doublereal *hdrect, integer *iaeee)
{
    /* Initialized data */

    static integer modtyp[18]	/* was [3][6] */ = { 1,2,3,2,1,3,4,4,4,4,4,4,
	    1,2,3,2,1,3 };
    static doublereal zlit2 = .0349;
    static logical first = TRUE_;
    static integer holdpp[8] = { 0,0,1308622848,1,1308622848,1,1308622848,1 };
    static char hnocs[8] = "NOCS    ";

    /* System generated locals */
    integer ret_val;
    doublereal d__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, j6, nr, ir, jj, kk;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer jap, tds[2], i20106;
    static logical kcs;
    static integer nwd, kfl4, iit;
    extern integer bcdf_(char *, ftnlen);
    static integer kcan, kfar;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static char test[8];
    static integer isav, lsav, kipl;
    extern /* Subroutine */ int cuth_(void), apt200_(integer *, doublereal *, 
	    doublereal *), apt240_(integer *), apt234_(integer *, doublereal *
	    ), apt235_(void), apt236_(void), arlm3_(void), arlm2_(void), 
	    amind_(void);
    static integer kfidn;
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer klmfl, kunfl, kstyp, ktlon;
    static doublereal spast;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *), cross_(
	    doublereal *, doublereal *, doublereal *);
#define holrth ((char *)&hblock_1 + 24)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal cssave[10];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer kseqno, jseqno, kcscnt;
    extern /* Subroutine */ int ewrite_(integer *, integer *, integer *, 
	    integer *, integer *);
    static integer numdim;
    extern /* Subroutine */ int outmsg_(char *, ftnlen), tolerh_(void), 
	    cutteh_(void), dntcuh_(void), intolh_(void), outtoh_(void), 
	    maxdph_(void), indrvh_(void), indrph_(void), thickh_(void);




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





/*     *** 8.  HOLRTH BLOCK *** */

/*     ALPHA-NUMERIC LITERAL CONSTANTS. */




/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* ...            SYSTEM I/O FILE NAMES */


/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/* ...                SYSTEM I/O FILES */






/* ++++ FLAG TO ALLOW A SECOND TRY WITHOUT CHECKING TA TO OVERCOME */
/* ++++ ERROR 20106 */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





    /* Parameter adjustments */
    --adress;

    /* Function Body */

    if (first) {
	holdpp[0] = bcdf_("HOLD", (ftnlen)4);
	holdpp[1] = bcdf_("PP  ", (ftnlen)4);
	tds[0] = bcdf_(hblock_1.hds, (ftnlen)4);
	tds[1] = bcdf_(hblock_1.hds + 4, (ftnlen)4);
	first = FALSE_;
    }

    holfrm_(hdrect, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (*iaeee == 1) {
	goto L8010;
    }
    if (ifxcor_1.iaerr == 1) {
	goto L1000;
    }
    if (s_cmp(test, hnocs, (ftnlen)8, (ftnlen)8) == 0) {
	goto L8000;
    }
    if (ifxcor_1.igoto + ifxcor_1.ictdef <= 0) {
	goto L1;
    } else {
	goto L3000;
    }
L1:
    for (i__ = 1; i__ <= 6; ++i__) {
	if (s_cmp(test, holrth + (i__ - 1 << 3), (ftnlen)8, (ftnlen)8) == 0) {
	    goto L4002;
	}
/* L4001: */
    }
    aerr_(&c__20104, "APT211  ", (ftnlen)8);
    goto L1000;
L4002:
    isav = i__;
    if (! ldef_1.jds) {
	goto L4000;
    }
    kseqno = sqnc_1.lseqno;
    sqnc_1.lseqno = jseqno;
    kcscnt = ifxcor_1.icscnt;
    kcs = ldef_1.jcs;
    lsav = isv_1.isftyp[ifxcor_1.ids - 1];
    isv_1.isftyp[ifxcor_1.ids - 1] = ifxcor_1.msav;
    ifxcor_1.icscnt = 0;
    kipl = isv_1.ipl[ifxcor_1.ics - 1];
    klmfl = isv_1.limfl[ifxcor_1.ics - 1];
    kunfl = isv_1.iunfl[ifxcor_1.ics - 1];
    kfidn = isv_1.isfidn[ifxcor_1.ics - 1];
    kstyp = isv_1.isftyp[ifxcor_1.ics - 1];
    ktlon = isv_1.itlon[ifxcor_1.ics - 1];
    spast = sv_1.past[ifxcor_1.ics - 1];
    kcan = isv_1.icanon[ifxcor_1.ics - 1];
    kfl4 = isv1_1.ifl4[ifxcor_1.ics - 1];
    kfar = isv1_1.ifar[ifxcor_1.ics - 1];
    for (iit = 1; iit <= 10; ++iit) {
/* L1530: */
	cssave[iit - 1] = canon[iit + 19];
    }
    apt200_(tds, &adress[1], &znumbr_1.z1);
    if (ifxcor_1.iaerr != 0) {
	goto L1000;
    }
    if (ifxcor_1.motmod == 0) {
	goto L4004;
    }
    isv_1.isftyp[ifxcor_1.ics - 1] = modtyp[ifxcor_1.motmod + isav * 3 - 4];
    if (isv_1.isftyp[ifxcor_1.ics - 1] == 2) {
	sv_1.past[ifxcor_1.ics - 1] = (doublereal) (-knumbr_1.k1);
    }
    ifxcor_1.is = ifxcor_1.ids;
    goto L9200;
L4000:
    s_copy(charct_1.modfer, test, (ftnlen)6, (ftnlen)8);
    ifxcor_1.igo = isav;
    ifxcor_1.msav = isv_1.isftyp[ifxcor_1.ids - 1];
    ifxcor_1.is = ifxcor_1.ids;
    apt234_(tds, &adress[1]);
    if (ifxcor_1.iaerr != 0) {
	goto L1000;
    }
    if (ldef_1.jcs) {
	goto L9200;
    }
    jseqno = sqnc_1.lseqno;
    ldef_1.jds = TRUE_;
/*     INTEG.ON EXFILE DP. 1ST WD UNNORM POWER,2ND INTEG VALUE */
    nr = 0;
    ewrite_(&symfil_1.exfile, &nr, holdpp, &c__8, &ir);
    hold_1.jhldfg = 1;
    goto L9999;
L4004:
    aerr_(&c__20109, "APT211  ", (ftnlen)8);
    goto L1000;
L9200:
    apt235_();
    if (ifxcor_1.iaerr <= 0) {
	goto L6000;
    } else {
	goto L1000;
    }
L6000:
    apt240_(&numdim);
/* L14: */
    ifxcor_1.icl = knumbr_1.k2;
    ifxcor_1.nw = 0;
/* L19: */
    if (fxcor_1.cutdat[5] == 0.f) {
	goto L32;
    }
    numdim = knumbr_1.k1;
    goto L32;
L72:
    apt236_();
    if (ifxcor_1.iaerr != 0) {
	goto L4006;
    }
    if (ldef_1.jds) {
	goto L4005;
    }
L4006:
    hold_1.jhldfg = 0;
    hold_1.ithcnt = 1;
    ldef_1.jcs = FALSE_;
    ldef_1.jds = FALSE_;
    goto L9999;
L4005:
    ldef_1.jcs = kcs;
    hold_1.jhldfg = 0;
    goto L9500;
L9600:
    nr = 0;
    holdpp[7] = knumbr_1.k2;
    ewrite_(&symfil_1.exfile, &nr, holdpp, &c__8, &ir);
    holdpp[7] = knumbr_1.k1;
    isv_1.isftyp[ifxcor_1.ids - 1] = lsav;
    sqnc_1.lseqno = kseqno;
    if (! ldef_1.jcs) {
	goto L4000;
    }
    isv_1.ipl[ifxcor_1.ics - 1] = kipl;
    isv_1.limfl[ifxcor_1.ics - 1] = klmfl;
    isv_1.isfidn[ifxcor_1.ics - 1] = kfidn;
    isv_1.isftyp[ifxcor_1.ics - 1] = kstyp;
    isv_1.itlon[ifxcor_1.ics - 1] = ktlon;
    sv_1.past[ifxcor_1.ics - 1] = spast;
    isv_1.icanon[ifxcor_1.ics - 1] = kcan;
    isv1_1.ifl4[ifxcor_1.ics - 1] = kfl4;
    isv1_1.ifar[ifxcor_1.ics - 1] = kfar;
    ifxcor_1.icscnt = kcscnt;
    ldef_1.jds = FALSE_;
    for (iit = 1; iit <= 10; ++iit) {
/* L1531: */
	canon[iit + 19] = cssave[iit - 1];
    }
    goto L4000;
L32:
    j6 = 0;
    ifxcor_1.is = ifxcor_1.ips;
/*  INITIALIZE VARIABLES FOR AMIND */
L33:
    if (isv_1.jent[ifxcor_1.is - 1] != 0) {
	goto L301;
    } else {
	goto L302;
    }
L301:
    isv_1.jtn[ifxcor_1.is - 1] = knumbr_1.k0;
    isv_1.iopset[ifxcor_1.is - 1] = 0;
    isv_1.ju1[ifxcor_1.is - 1] = 0;
    isv_1.jiops[ifxcor_1.is - 1] = 0;
L302:
    jap = knumbr_1.k1;
L201:
    amind_();
    if (ifxcor_1.iaerr != 0) {
	goto L1000;
    } else {
	goto L2000;
    }
L2000:
    if (isv_1.ipl[ifxcor_1.is - 1] != 0) {
	goto L141;
    } else {
	goto L140;
    }
L141:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1]) < 0.) {
	goto L142;
    } else if (d__1 == 0) {
	goto L39;
    } else {
	goto L143;
    }
L142:
    if (sv_1.s[ifxcor_1.is - 1] - sv_1.tau2[ifxcor_1.is - 1] + 1e-4 >= 0.) {
	goto L39;
    } else {
	goto L36;
    }
L143:
    if (sv_1.s[ifxcor_1.is - 1] - sv_1.tau1[ifxcor_1.is - 1] - 1e-4 <= 0.) {
	goto L39;
    } else {
	goto L36;
    }
L140:
    if ((d__1 = sv_1.rc[ifxcor_1.is - 1] * sv_1.s[ifxcor_1.is - 1]) < 0.) {
	goto L34;
    } else if (d__1 == 0) {
	goto L39;
    } else {
	goto L35;
    }
L34:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - znumbr_1.z9em1 * 
	    sv_1.tau[ifxcor_1.is - 1] - 1e-4 <= 0.) {
	goto L39;
    } else {
	goto L36;
    }
L35:
    if ((d__1 = sv_1.s[ifxcor_1.is - 1], abs(d__1)) - sv_1.eps1[ifxcor_1.is - 
	    1] - .01 <= 0.) {
	goto L39;
    } else {
	goto L36;
    }
L36:
    switch (jap) {
	case 1:  goto L505;
	case 2:  goto L508;
	case 3:  goto L504;
	case 4:  goto L204;
    }
L505:
    if (isv_1.ipl[ifxcor_1.is - 1] != 0) {
	goto L506;
    } else {
	goto L202;
    }
L202:
    if (isv_1.isftyp[ifxcor_1.is - 1] - knumbr_1.k3 != 0) {
	goto L504;
    } else {
	goto L507;
    }
L504:
    sv_1.rc[ifxcor_1.is - 1] = -sv_1.rc[ifxcor_1.is - 1];
    jap += knumbr_1.k1;
    goto L201;
L506:
    if (sv_1.th[ifxcor_1.is - 1] <= 0.) {
	goto L510;
    } else {
	goto L204;
    }
L507:
    jap = knumbr_1.k4;
L203:
    sv_1.z__[ifxcor_1.is - 1] = -sv_1.z__[ifxcor_1.is - 1];
    goto L201;
L510:
    if (isv_1.iafl[ifxcor_1.is - 1] != 0) {
	goto L507;
    } else {
	goto L511;
    }
L511:
    isv_1.jent[ifxcor_1.is - 1] = -knumbr_1.k1;
    jap = knumbr_1.k4;
    goto L201;
L508:
    if (sv_1.th[ifxcor_1.is - 1] >= 0.) {
	goto L204;
    } else {
	goto L509;
    }
L509:
    jap += knumbr_1.k1;
    goto L203;
L204:
    if (j6 != 0) {
	goto L38;
    } else {
	goto L37;
    }
/*  CUTTER NOT WITHIN TOLERANCE OF DRIVE SURFACE AT START OF CUT SEQUENCE */
L38:
    aerr_(&c__20102, "APT211  ", (ftnlen)8);
    goto L1000;
/*  CUTTER NOT WITHIN TOLERANCE OF PART SURFACE AT START OF CUT SEQUENCE */
L37:
    aerr_(&c__20103, "APT211  ", (ftnlen)8);
    goto L1000;
L40:
    j6 = knumbr_1.k1;
    ifxcor_1.is = ifxcor_1.ids;
    goto L33;
L39:
    if (jap - knumbr_1.k1 != 0) {
	goto L480;
    } else {
	goto L481;
    }
L480:
    sv_1.tpk[ifxcor_1.is * 3 - 3] = sv_1.tp[ifxcor_1.is * 3 - 3];
    sv_1.tpk[ifxcor_1.is * 3 - 2] = sv_1.tp[ifxcor_1.is * 3 - 2];
    sv_1.tpk[ifxcor_1.is * 3 - 1] = sv_1.tp[ifxcor_1.is * 3 - 1];
    sv_1.snk[ifxcor_1.is * 3 - 3] = sv_1.sn[ifxcor_1.is * 3 - 3];
    sv_1.snk[ifxcor_1.is * 3 - 2] = sv_1.sn[ifxcor_1.is * 3 - 2];
    sv_1.snk[ifxcor_1.is * 3 - 1] = sv_1.sn[ifxcor_1.is * 3 - 1];
    sv_1.sk[ifxcor_1.is * 3 - 3] = sv_1.s[ifxcor_1.is - 1];
L481:
    if (j6 != 0) {
	goto L41;
    } else {
	goto L40;
    }
/*  DETERMINE GENERAL DIRECTION OF FIRST CUT VECTOR AND STORE IN FWD */
L41:
    for (k = 1; k <= 3; ++k) {
/* L42: */
	dshar4_1.fwd[k - 1] = fxcor_1.te[k - 1] - fxcor_1.tek[k - 1];
    }
/* L2001: */
    vnorm_(dshar4_1.fwd, dshar4_1.fwd);
/*  IGO =1 IF LFT, =2 IF RGT, =3 IF FWD, =4 IF BACK, =5 IF UP, =6 IF DOWN */
/*  RELATIVE TO LAST COMMAND */
    if (knumbr_1.k4 - ifxcor_1.igo >= 0) {
	goto L45;
    } else {
	goto L43;
    }
L43:
    for (k = 1; k <= 3; ++k) {
/* L44: */
	dshar4_1.fwd[k - 1] = fxcor_1.ta[k - 1];
    }
    goto L50;
L45:
    cross_(dshar4_1.fwd, fxcor_1.ta, dshar4_1.fwd);
    vnorm_(dshar4_1.fwd, dshar4_1.fwd);
    if (fxcor_1.vtem > znumbr_1.z1em6) {
	goto L48;
    }
/* L46: */
    cross_(fxcor_1.pmove, fxcor_1.ta, dshar4_1.fwd);
    vnorm_(dshar4_1.fwd, dshar4_1.fwd);
    if (ifxcor_1.ier != 0) {
	goto L47;
    } else {
	goto L48;
    }
/*  FWD DIRECTION CANNOT BE DETERMINED */
L47:
    aerr_(&c__20105, "APT211  ", (ftnlen)8);
    goto L1000;
L48:
    if (knumbr_1.k3 - ifxcor_1.igo <= 0) {
	goto L49;
    } else {
	goto L50;
    }
L49:
    cross_(fxcor_1.ta, dshar4_1.fwd, dshar4_1.fwd);
    vnorm_(dshar4_1.fwd, dshar4_1.fwd);
    if (ifxcor_1.ier != 0) {
	goto L147;
    } else {
	goto L50;
    }
L147:
    goto L47;
L50:
    switch (ifxcor_1.igo) {
	case 1:  goto L52;
	case 2:  goto L54;
	case 3:  goto L54;
	case 4:  goto L52;
	case 5:  goto L54;
	case 6:  goto L52;
    }
L52:
    for (k = 1; k <= 3; ++k) {
/* L53: */
	dshar4_1.fwd[k - 1] = -dshar4_1.fwd[k - 1];
    }
/*  CALCULATE TI VECTOR PERPENDICULAR TO BOTH PART AND DRIVE SURFACE */
/*  NORMALS */
L54:
    cross_(&sv_1.sn[ifxcor_1.ips * 3 - 3], &sv_1.sn[ifxcor_1.ids * 3 - 3], 
	    fxcor_1.ti);
    vnorm_(fxcor_1.ti, fxcor_1.ti);
    if (ifxcor_1.ier != 0) {
	goto L58;
    } else {
	goto L60;
    }
L58:
    for (k = 1; k <= 3; ++k) {
/* L59: */
	fxcor_1.ti[k - 1] = dshar4_1.fwd[k - 1];
    }
    goto L67;
/*  TI VECTOR AND FWD VECTOR SHOULD NOT BE ORTHOGONAL. IF SO CALL AERR */
L60:
    fxcor_1.tem[0] = fxcor_1.ti[0] * dshar4_1.fwd[0] + fxcor_1.ti[1] * 
	    dshar4_1.fwd[1] + fxcor_1.ti[2] * dshar4_1.fwd[2];
    if (abs(fxcor_1.tem[0]) - zlit2 <= 0.) {
	goto L64;
    } else {
	goto L63;
    }
L64:
    if (i20106 == 0) {
/* ++++ HAVE SECOND TRY WITHOUT CHECKING TA TO AVOID ERROR 20106 */
	i20106 = 1;
	outmsg_("*** WARNING: ERROR 20106 IN APT201 ***", (ftnlen)38);
	outmsg_("*** TRY WITHOUT CHECKING TA        ***", (ftnlen)38);
	for (k = 1; k <= 3; ++k) {
	    dshar4_1.fwd[k - 1] = fxcor_1.te[k - 1] - fxcor_1.tek[k - 1];
/* L641: */
	}
	vnorm_(dshar4_1.fwd, dshar4_1.fwd);
	goto L50;
    } else {
	aerr_(&c__20106, "APT211  ", (ftnlen)8);
	goto L1000;
    }
L63:
    if (fxcor_1.tem[0] <= 0.) {
	goto L65;
    } else {
	goto L67;
    }
L65:
    for (k = 1; k <= 3; ++k) {
/* L66: */
	fxcor_1.ti[k - 1] = -fxcor_1.ti[k - 1];
    }
L67:
    if (numdim <= 0) {
	goto L68;
    } else {
	goto L73;
    }
/*  ICSCNT = NUMBER OF CHECK SURFACES. IF MORE THAN ONE CHECK SURFACE 3D */
/*  ROUTES USED */
L68:
/* L168: */
    if (ifxcor_1.i3dflg - knumbr_1.k1 != 0) {
	goto L130;
    } else {
	goto L73;
    }
L130:
    if (ifxcor_1.icscnt - knumbr_1.k2 >= 0) {
	goto L73;
    } else {
	goto L69;
    }
/*  IF THICKNESS OF PART, DRIVE, AND CHECK SURFACE NOT ZERO 3D ROUTES */
/*  FOLLOWED */
L69:
    if (sv_1.th[ifxcor_1.ips - 1] != 0.) {
	goto L173;
    } else {
	goto L70;
    }
L173:
    goto L73;
L70:
    if (sv_1.th[ifxcor_1.ids - 1] != 0.) {
	goto L174;
    } else {
	goto L71;
    }
L174:
    goto L73;
L71:
    if (sv_1.th[ifxcor_1.ics - 1] != 0.) {
	goto L73;
    } else {
	goto L76;
    }
L73:
/*  ENTRY FOR 3D CALCULATIONS */
/* L732: */
    arlm3_();
    ret_val = (integer) (fxcor_1.temp[0] + .5f);
L101:
    if (ifxcor_1.iaerr != 0) {
	goto L1000;
    } else {
	goto L72;
    }
L76:
    ifxcor_1.is = ifxcor_1.ics;
    if (isv_1.isfidn[ifxcor_1.ids - 1] - knumbr_1.k3 >= 0) {
	goto L86;
    } else {
	goto L80;
    }
L80:
    if (isv_1.isfidn[ifxcor_1.ics - 1] - knumbr_1.k3 >= 0) {
	goto L81;
    } else {
	goto L82;
    }
/*  LINE TO LINE CASE */
L82:
    ifxcor_1.jbr = knumbr_1.k3;
    goto L83;
/*  CIRCLE TO LINE OR CIRCLE TO CIRCLE CASE */
L86:
    ifxcor_1.jbr = knumbr_1.k1;
/*  ENTRY FOR 2D CALCULATIONS */
L83:
    arlm2_();
    ret_val = (integer) znumbr_1.z1;
    goto L101;
/*  LINE TO CIRCLE CASE */
L81:
    ifxcor_1.jbr = knumbr_1.k2;
    goto L83;
L6001:
    if (ifxcor_1.igoto <= 0) {
	goto L3001;
    } else {
	goto L3002;
    }
L3001:
    aerr_(&c__20107, "APT211  ", (ftnlen)8);
    goto L1000;
L3002:
    aerr_(&c__20108, "APT211  ", (ftnlen)8);
L1000:
L6002:
    ret_val = (integer) znumbr_1.z1;
    goto L72;
L3000:
    if (ifxcor_1.isrch <= 0) {
	goto L6001;
    } else {
	goto L6002;
    }
L9999:
    return ret_val;
L9500:
    jj = 0;
L9510:
    ++jj;
    if (jj == hold_1.ithcnt) {
	goto L9590;
    }
    kk = hold_1.itabh[jj - 1];
    switch (kk) {
	case 1:  goto L9510;
	case 2:  goto L9510;
	case 3:  goto L9510;
	case 4:  goto L9504;
	case 5:  goto L9505;
	case 6:  goto L9506;
	case 7:  goto L9507;
	case 8:  goto L9508;
	case 9:  goto L9509;
	case 10:  goto L9550;
	case 11:  goto L9511;
	case 12:  goto L9512;
	case 13:  goto L9513;
    }
L9504:
    tolerh_();
    goto L9510;
L9505:
    cutteh_();
    goto L9510;
L9506:
    cuth_();
    goto L9510;
L9507:
    dntcuh_();
    goto L9510;
L9508:
    intolh_();
    goto L9510;
L9509:
    outtoh_();
    goto L9510;
L9550:
    maxdph_();
    goto L9510;
L9511:
    indrvh_();
    goto L9510;
L9512:
    indrph_();
    goto L9510;
L9513:
    thickh_();
    goto L9510;
L9590:
    hold_1.ithcnt = 1;
    if (*iaeee == 1) {
	goto L8020;
    }
    goto L9600;
L8000:
    kseqno = sqnc_1.lseqno;
    sqnc_1.lseqno = jseqno;
    apt235_();
    *iaeee = 1;
    aerr_(&c__20110, "APT211  ", (ftnlen)8);
L8010:
    ifxcor_1.iaerr = 0;
    goto L9500;
L8020:
    ifxcor_1.iaerr = 1;
    nr = 0;
    holdpp[7] = knumbr_1.k2;
    ewrite_(&symfil_1.exfile, &nr, holdpp, &c__8, &ir);
    holdpp[7] = knumbr_1.k1;
    sqnc_1.lseqno = kseqno;
/* ....   RETURN TO CALLER */
    goto L1000;
} /* apt211_ */

#undef bcanon
#undef holrth
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


