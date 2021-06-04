/* APT238.f -- translated by f2c (version 20100827).
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
    integer ibrkpt[51];
} ibrkpt_;

#define ibrkpt_1 ibrkpt_

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

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0001132.W01   *** */

/* .....FORTRAN SUBROUTINE  ....APT238         8/68                    HG */
/* .....FORTRAN SUBROUTINE             APT238...              3/1/68   GK */
/* Subroutine */ int apt238_(integer *number)
{
    /* Local variables */
    static integer n, nn1, nn2;
    extern /* Subroutine */ int bad_();
    static integer is01, is02;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static integer kfix;






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






/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */






/*   *** IBRKPT *** */



/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */






/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    n = *number;
    if (ibrkpt_1.ibrkpt[n - 1] != 0) {
	goto L2;
    } else {
	goto L1;
    }
L2:
    kfix = (integer) fxcor_1.strtno;
    if (ifxcor_1.nmpnts - ifxcor_1.numpt1 < kfix) {
	goto L1;
    }
    is01 = ifxcor_1.is + 1;
    is02 = ifxcor_1.is + 2;
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    nn1 = *number / 10 + 1;
    nn2 = *number % 10;
    nn1 = nn1 * 100 + nn2;
    bad_(&c__1, &c__0, "DYND", &nn1, (ftnlen)4);
    bad_(&c_n1, &c__0, "SEQN", &ifxcor_1.iseqno, (ftnlen)4);
    switch (n) {
	case 1:  goto L101;
	case 2:  goto L102;
	case 3:  goto L103;
	case 4:  goto L104;
	case 5:  goto L105;
	case 6:  goto L106;
	case 7:  goto L107;
	case 8:  goto L999;
	case 9:  goto L999;
	case 10:  goto L999;
	case 11:  goto L201;
	case 12:  goto L202;
	case 13:  goto L203;
	case 14:  goto L204;
	case 15:  goto L205;
	case 16:  goto L206;
	case 17:  goto L207;
	case 18:  goto L208;
	case 19:  goto L209;
	case 20:  goto L210;
	case 21:  goto L211;
	case 22:  goto L212;
	case 23:  goto L213;
	case 24:  goto L214;
	case 25:  goto L215;
	case 26:  goto L216;
	case 27:  goto L217;
	case 28:  goto L999;
	case 29:  goto L999;
	case 30:  goto L999;
	case 31:  goto L401;
	case 32:  goto L402;
	case 33:  goto L403;
	case 34:  goto L404;
	case 35:  goto L999;
	case 36:  goto L999;
	case 37:  goto L999;
	case 38:  goto L999;
	case 39:  goto L999;
	case 40:  goto L999;
	case 41:  goto L501;
	case 42:  goto L502;
	case 43:  goto L503;
	case 44:  goto L504;
	case 45:  goto L505;
	case 46:  goto L999;
	case 47:  goto L999;
	case 48:  goto L999;
	case 49:  goto L999;
	case 50:  goto L999;
    }
/* *101 CALL APT239(1,S(IS),TP(IS),TP(IS01),TP(IS02),TN(IS),TN(IS01), */
/* *   C TN(IS02)) */
/* *    GO TO 1 */
/* *102 CALL APT239(2,S(IS),SP(IS),SP(IS01),SP(IS02),SN(IS), */
/* *   C SN(IS01),SN(IS02)) */
/* *    GO TO 1 */
/* *103 CALL APT239(3,IS,JENT(IS),JTN(IS),IOPSET(IS),JU1(IS), */
/* *   C TE(1),TE(2),TE(3),TA(1),TA(2),TA(3)) */
/* *    GO TO 1 */
/* *104 CALL APT239(4,IS,S(IS),ISIGCR(IS),Z(IS),RC(IS),CC(IS),CC(IS01), */
/* *   C CC(IS02),SP(IS),SP(IS01),SP(IS02),SPL(IS),SPL(IS01),SPL(IS02), */
/* *   2 SN(IS),SN(IS01),SN(IS02)) */
/* *    GO TO 1 */
/* *105 CALL APT239 (5,IS,TP(IS),TP(IS01),TP(IS02),TN(IS), */
/* *   C TN(IS01),TN(IS02)) */
/* *    GO TO 1 */
/* *106 CALL APT239(6,IS,S(IS),Z(IS),FLIPCK,IAMDCT,SP(IS), */
/* *   C SP(IS01),SP(IS02),SN(IS),SN(IS01),SN(IS02), */
/* *   2 TP(IS),TP(IS01),TP(IS02),TN(IS),TN(IS01),TN(IS02)) */
/* *    GO TO 1 */
/* *107 CALL APT239(7,IS,S(IS),TAU1(IS),TAU2(IS),Z(IS), */
/* *   C FLIPCK,IAMDCT,TH(IS),RC(IS), */
/* *   2 SP(IS),SP(IS01),SP(IS02),SN(IS),SN(IS01),SN(IS02),TP(IS),TP(IS01) */
/* *   3,TP(IS02),TN(IS),TN(IS01),TN(IS02),CC(IS),CC(IS01),CC(IS02), */
/* *   4 VT(IS),VT(IS01),VT(IS02)) */
/* *    GO TO 1 */
/* *201 CALL APT239(11,TEK(1),TEK(2),TEK(3),TAK(1),TAK(2),TAK(3), */
/* *   C TIK(1),TIK(2),TIK(3),SPK(IPS),SPK(IPS+1),SPK(IPS+2), */
/* *   2 TPK(IPS),TPK(IPS+1),TPK(IPS+2),SPK(IDS),SPK(IDS+1),SPK(IDS+2), */
/* *   3 TPK(IDS),TPK(IDS+1),TPK(IDS+2)) */
/* *    GO TO 1 */
/* *202 CALL APT239(12,DP,DPI) */
/* *    GO TO 1 */
/* *203 CALL APT239(13,IS,CSD(IS),DPI) */
/* *    GO TO 1 */
/* *204 CALL APT239(14,DP,CMOVE(1),CMOVE(2),CMOVE(3),TEL(1),TEL(2),TEL(3), */
/* *   C TAL(1),TAL(2),TAL(3),TE(1),TE(2),TE(3),TA(1),TA(2),TA(3)) */
/* *    GO TO 1 */
/* *205 CALL APT239(15,IS,JCR,TE(1),TE(2),TE(3),TA(1),TA(2),TA(3)) */
/* *    GO TO 1 */
/* *206 CALL APT239(16,JDR,DP) */
/* *    GO TO 1 */
/* *207 CALL APT239(17,IS,JCKR,CSD(IS)) */
/* *    GO TO 1 */
/* *208 CALL APT239(18,VL,NUMPT1) */
/* *    GO TO 1 */
/* *209 CALL APT239(19,JCR,IWS,TEE(IS),TEE(IS01),TEE(IS02)) */
/* *    GO TO 1 */
/* *210 CALL APT239(20,IS,S(IS),Z(IS),J23(IS),STCK(IS),STCK1(IS)) */
/* *    GO TO 1 */
/* *211 CALL APT239(21,IS,J23(IS),STCK2(IS),STCK(IS), */
/* *   C SN(IS),SN(IS01),SN(IS02)) */
/* *    GO TO 1 */
/* *212 CALL APT239 (22,IS,JDR,DP,VL) */
/* *    GO TO 1 */
/* *213 CALL APT239(23,IS,DP) */
/* *    GO TO 1 */
/* *214 CALL APT239(24,IS,JPR,CSD(IS)) */
/* *    GO TO 1 */
/* *215 CALL APT239(25,IS,ISFTYP(IS),J23(IS),S(IS),Z(IS),STCK(IS), */
/* *   C STCK1(IS),STCK2(IS)) */
/* *    GO TO 1 */
/* *216 CALL APT239(26,ISFTYP(IS),J23(IS),STCK2(IS),STCKN(IS), */
/* *   C SN(IS),SN(IS01),SN(IS02),TI(1),TI(2),TI(3)) */
/* *    GO TO 1 */
/* *217 CALL APT239(27,IS,IFAR(IS),TE(1),TE(2),TE(3),TA(1),TA(2),TA(3)) */
/* *    GO TO 1 */
/* *401 CALL APT239(31,JPXR,PLND(IS),PLNV(IS),PLNV(IS01),PLNV(IS02), */
/* *   C CMOVE(1),CMOVE(2),CMOVE(3)) */
/* *    GO TO 1 */
/* *402 CALL APT239(32,CPTST(IS),CPLFL(IS),PLND(IS),PLNV(IS),PLNV(IS01), */
/* *   C PLNV(IS02)) */
/* *    GO TO 1 */
/* *403 CALL APT239(33,IS,PLND1(IS),PLTST(IS)) */
/* *    GO TO 1 */
/* *404 CALL APT239(34,IT,S(IT),ISIGCR(IT),Z(IT),RC(IT),SP(IT),SP(IT+1), */
/* *   C SP(IT+2),CC(IT),CC(IT+1),CC(IT+2),SPL(IT),SPL(IT+1),SPL(IT+2), */
/* *   2 SN(IT),SN(IT+1),SN(IT+2)) */
/* *    GO TO 1 */
/* *501 CALL APT239(41,INOPS,NUMSUR,IAUTPS) */
/* *    GO TO 1 */
/* *502 CALL APT239(42,IS,INDIR(IS)) */
/* *    GO TO 1 */
/* *503 CALL APT239(43,IS,VNDIR(IS),VNDIR(IS01),VNDIR(IS02), */
/* *   C TE(1),TE(2),TE(3)) */
/* *    GO TO 1 */
/* *504 CALL APT239(44,IS,ISVFL(IS),CSD(IS),SN(IS),SN(IS01),SN(IS02)) */
/* *999 GO TO 1 */
/* *505 CALL APT239(45,TE(1),TE(2),TE(3)) */
/* *  1 RETURN */
/* *    END */
L101:
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "TP  ", &sv_1.tp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TN  ", &sv_1.tn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L102:
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L103:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "JENT", &isv_1.jent[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "JTN ", &isv_1.jtn[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "IOPS", &isv_1.iopset[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "JU1 ", &isv_1.ju1[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__0, "ITLN", &isv_1.itlon[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", fxcor_1.ta, (ftnlen)4);
    goto L1;
L104:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "ISGC", &isv_1.isigcr[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "RC  ", &sv_1.rc[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "SPL ", &sv_1.spl[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "CC  ", &sv_1.cc[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L105:
    bad_(&c_n1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__3, &c__1, "TP  ", &sv_1.tp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TN  ", &sv_1.tn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L106:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "FLCK", &dshar4_1.flipck, (ftnlen)4);
    bad_(&c_n1, &c__0, "AMCT", &ishr18_1.iamdct, (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "TP  ", &sv_1.tp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TN  ", &sv_1.tn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L107:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "TAU1", &sv_1.tau1[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "TAU2", &sv_1.tau2[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "FLCK", &dshar4_1.flipck, (ftnlen)4);
    bad_(&c__1, &c__0, "AMCT", &ishr18_1.iamdct, (ftnlen)4);
    bad_(&c__1, &c__1, "TH  ", &sv_1.th[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "RC  ", &sv_1.rc[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "TP  ", &sv_1.tp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TN  ", &sv_1.tn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "CC  ", &sv_1.cc[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "VT  ", &sv_1.vt[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L201:
    bad_(&c__3, &c__1, "TEK ", fxcor_1.tek, (ftnlen)4);
    bad_(&c_n3, &c__1, "TAK ", fxcor_1.tak, (ftnlen)4);
    bad_(&c__3, &c__1, "SPKP", &sv_1.spk[ifxcor_1.ips * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SPKD", &sv_1.spk[ifxcor_1.ids * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "TPKP", &sv_1.tpk[ifxcor_1.ips * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TPK ", &sv_1.tpk[ifxcor_1.ids * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TIK ", fxcor_1.tik, (ftnlen)4);
    goto L1;
L202:
    bad_(&c__1, &c__1, "DP  ", &dshar4_1.dp, (ftnlen)4);
    bad_(&c_n1, &c__1, "DPI ", &dshar4_1.dpi, (ftnlen)4);
    goto L1;
L203:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "CSD ", &sv1_1.csd[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "DPI ", &dshar4_1.dpi, (ftnlen)4);
    goto L1;
L204:
    bad_(&c__3, &c__1, "CMOV", dshar4_1.cmove, (ftnlen)4);
    bad_(&c_n1, &c__1, "DP  ", &dshar4_1.dp, (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", fxcor_1.ta, (ftnlen)4);
    bad_(&c__3, &c__1, "TEL ", fxcor_1.tel, (ftnlen)4);
    bad_(&c_n3, &c__1, "TAL ", fxcor_1.tal, (ftnlen)4);
    goto L1;
L205:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c_n1, &c__0, "JCR ", &ishr18_1.jcr, (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", fxcor_1.ta, (ftnlen)4);
    goto L1;
L206:
    bad_(&c__1, &c__0, "JDR ", &ishr18_1.jdr, (ftnlen)4);
    bad_(&c_n1, &c__0, "DP  ", &dshar4_1.dp, (ftnlen)4);
    goto L1;
L207:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "JCKR", &ishr18_1.jckr, (ftnlen)4);
    bad_(&c_n1, &c__0, "CSD ", &sv1_1.csd[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L208:
    bad_(&c__1, &c__0, "NMPT", &ifxcor_1.numpt1, (ftnlen)4);
    bad_(&c_n1, &c__1, "VL  ", &dshar4_1.vl, (ftnlen)4);
    goto L1;
L209:
    bad_(&c__1, &c__0, "JCR ", &ishr18_1.jcr, (ftnlen)4);
    bad_(&c__1, &c__0, "IWS ", &ishr18_1.iws, (ftnlen)4);
    bad_(&c_n3, &c__1, "TEE ", &sv1_1.tee[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L210:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "J23 ", &isv1_1.j23[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "STCK", &sv1_1.stck[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "STK1", &sv1_1.stck1[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L211:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "J23 ", &isv1_1.j23[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "STK2", &sv1_1.stck2[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "STCK", &sv1_1.stck[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L212:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "JDR ", &ishr18_1.jdr, (ftnlen)4);
    bad_(&c__1, &c__1, "DP  ", &dshar4_1.dp, (ftnlen)4);
    bad_(&c_n1, &c__1, "VL  ", &dshar4_1.vl, (ftnlen)4);
    goto L1;
L213:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c_n1, &c__1, "DP  ", &dshar4_1.dp, (ftnlen)4);
    goto L1;
L214:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "JPR ", &ishr18_1.jpr, (ftnlen)4);
    bad_(&c_n1, &c__1, "CSD ", &sv1_1.csd[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L215:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "ISFT", &isv_1.isftyp[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "J23 ", &isv1_1.j23[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "STCK", &sv1_1.stck[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "STK1", &sv1_1.stck1[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "STK2", &sv1_1.stck2[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L216:
    bad_(&c__1, &c__0, "ISFT", &isv_1.isftyp[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "J23 ", &isv1_1.j23[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "STK2", &sv1_1.stck2[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "STKN", &sv1_1.stckn[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TI  ", fxcor_1.ti, (ftnlen)4);
    goto L1;
L217:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c_n1, &c__0, "IFAR", &isv1_1.ifar[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", fxcor_1.ta, (ftnlen)4);
    goto L1;
L401:
    bad_(&c__1, &c__0, "JPXR", &ishr18_1.jpxr, (ftnlen)4);
    bad_(&c_n1, &c__1, "PLND", &sv_1.plnd[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "PLNV", &sv_1.plnv[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "CMOV", dshar4_1.cmove, (ftnlen)4);
    goto L1;
L402:
    bad_(&c__1, &c__1, "CPTS", &sv1_1.cptst[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "CPLF", &sv1_1.cplfl[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "PLND", &sv_1.plnd[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n3, &c__1, "PLNV", &sv_1.plnv[ifxcor_1.is * 3 - 3], (ftnlen)4);
    goto L1;
L403:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__1, "PLD1", &sv1_1.plnd1[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "PLTS", &sv1_1.pltst[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L404:
    bad_(&c__1, &c__0, "IT  ", &ifxcor_1.it, (ftnlen)4);
    bad_(&c__1, &c__1, "S   ", &sv_1.s[ifxcor_1.it - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "ISGC", &isv_1.isigcr[ifxcor_1.it - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "Z   ", &sv_1.z__[ifxcor_1.it - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "RC  ", &sv_1.rc[ifxcor_1.it - 1], (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.it * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.it * 3 - 3], (ftnlen)4);
    bad_(&c__3, &c__1, "SPL ", &sv_1.spl[ifxcor_1.it * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "CC  ", &sv_1.cc[ifxcor_1.it * 3 - 3], (ftnlen)4);
    goto L1;
L501:
    bad_(&c__1, &c__0, "INPS", &ifxcor_1.inops, (ftnlen)4);
    bad_(&c__1, &c__0, "NMSR", &ifxcor_1.numsur, (ftnlen)4);
    bad_(&c_n1, &c__0, "IAUT", &ifxcor_1.iautps, (ftnlen)4);
    goto L1;
L502:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c_n1, &c__0, "INDR", &isv_1.indir__[ifxcor_1.is - 1], (ftnlen)4);
    goto L1;
L503:
    bad_(&c_n1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__3, &c__1, "VNDR", &sv_1.vndir[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    goto L1;
L504:
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c__1, &c__0, "ISVF", &isv_1.isvfl[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "CSD ", &sv1_1.csd[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
L999:
    goto L1;
L505:
    bad_(&c_n3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
L1:
    return 0;
} /* apt238_ */

#undef sinl
#undef cosl


