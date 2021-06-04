/* DDSSRF.f -- translated by f2c (version 20100827).
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

struct {
    integer modess, msschk, mssarl;
} modess_;

#define modess_1 modess_

struct {
    integer iddst;
} iddst_;

#define iddst_1 iddst_

struct {
    integer ibug, i1, i2;
} ibugg_;

#define ibugg_1 ibugg_

struct {
    doublereal b[256]	/* was [64][4] */, u[4], v[4];
    integer itop[96]	/* was [6][4][4] */, iflag[16]	/* was [4][4] */, 
	    ipnum[4], iseqls, nlast, mcat, iddlas[4], jenlas[4], lodflg[4], 
	    ncalmx, ncmx;
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    integer ichekf;
} chekfl_;

#define chekfl_1 chekfl_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c_n3 = -3;
static integer c__3 = 3;
static logical c_false = FALSE_;

/* *** SOURCE FILE : M0004316.W03   *** */

/* Subroutine */ int ddssrf_(doublereal *ss)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-12;
    static doublereal z5em1 = .5;
    static doublereal zm5em1 = -.5;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, k1;
    static doublereal w1;
    static integer ip;
    static doublereal ua, uu, vv, va;
    static integer ii, ll, ib1, ib2;
    extern /* Subroutine */ int bad_();
    static doublereal dck, dif[3];
    static integer irr, iur, ivr, mode, lod63;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal dsav[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal dist;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    ), aerr_(integer *, char *, ftnlen);
    static integer iaer1, ickbn, ipchn;
    static doublereal spsav[3], usave, vsave;
    static integer isqno, modes, idebug, idebux, ipsave, iclcur;
    extern /* Subroutine */ int lodint_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), pchprc_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, logical *);
    static integer nopatc;
    extern /* Subroutine */ int record_(integer *);
    static integer iequal, kretry;
    extern /* Subroutine */ int sqrcut_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    static doublereal uvdist;

/* ------ BEGIN SCULPTURED SURFACE TOOL RAY INTERSECTION ALGORITHM */



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










/* ---- FLAG INTRODUCED BY VW - USED TO DETERMINE 'CORRECT' SIDE OF CUTTER */




    /* Parameter adjustments */
    --ss;

    /* Function Body */

    ifxcor_1.iaerr = 0;
    lod63 = 0;
    idebug = 0;
    idebux = 0;
    if (ibugg_1.ibug == 1 || ibugg_1.ibug == 2) {
	idebug = 1;
    }
    if (ibugg_1.ibug == 2) {
	idebux = 1;
    }


    ++ssarlm_1.nlast;
    ip = ifxcor_1.is - 1;
/*             /-SAVE UV,PATCH NUMBER IN CASE OF TROUBLE */
    usave = ssarlm_1.u[ip - 1];
    vsave = ssarlm_1.v[ip - 1];
    ipsave = ssarlm_1.ipnum[ip - 1];
/*             /-SAVE OLD SP VALUE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L8: */
	spsav[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4];
    }
    if (ssarlm_1.iseqls == ifxcor_1.iseqno) {
	goto L20;
    }
/*             /-RESET INITIALIZING DATA FOR ALL SURFACES FOR NEW STATEME */
    for (i__ = 1; i__ <= 4; ++i__) {
/* L30: */
	ssarlm_1.lodflg[i__ - 1] = 1;
    }
L20:
    if (isv_1.jent[ifxcor_1.is - 1] == 1 && ssarlm_1.jenlas[ip - 1] == 0) {
	ssarlm_1.lodflg[ip - 1] = 1;
    }
/*             /-SET COUNT OF NUMBER OR RETRY-S WITHIN DDSSRF */
    kretry = 0;

/*             /-NLAST RECORDS TOTAL NUMBER OF CALLS TO DDSSRF */
/*             /-NCALMX IS NUMBER OF CALLS SINCE LAST CUT VECTOR */
/*             /-NCMX IS MAX NUMBER OF CALLS ALLOWED FOR ONE CUT VECTOR */
/*             /-ICLCUR IS NUMBER OF CURRENT CL POINT IN CUT RECORD */
/*             /-MCAT IS LAST VALUE OF ICLCUR ON EXIT FROM DDSSRF */
    iclcur = ifxcor_1.nmpnts - ifxcor_1.numpt1 + 1;
    if (iclcur != ssarlm_1.mcat) {
	ssarlm_1.ncalmx = 0;
    }
/*             /-RESET NUMBER OF CALLS FOR NEW DS */
    if (ssarlm_1.jenlas[ip - 1] == 0 && isv_1.jent[ifxcor_1.is - 1] == 1) {
	ssarlm_1.ncalmx = 0;
    }
    ++ssarlm_1.ncalmx;
    if (ssarlm_1.ncalmx > ssarlm_1.ncmx) {
	ifxcor_1.iaerr = 25403;
    }
    if (ifxcor_1.iaerr != 0) {
	goto L999;
    }

    if (idebug <= 0) {
	goto L40;
    }
    bad_(&c_n1, &c__0, "DSRF", &ssarlm_1.nlast, (ftnlen)4);
    bad_(&c__1, &c__0, "ISEQ", &ifxcor_1.iseqno, (ftnlen)4);
    bad_(&c__1, &c__0, "CLPT", &iclcur, (ftnlen)4);
    bad_(&c__1, &c__0, "MODS", &modess_1.modess, (ftnlen)4);
    bad_(&c__1, &c__0, "MSCK", &modess_1.msschk, (ftnlen)4);
    bad_(&c__1, &c__0, "IS  ", &ifxcor_1.is, (ftnlen)4);
    bad_(&c_n1, &c__0, "DDST", &iddst_1.iddst, (ftnlen)4);
    bad_(&c__1, &c__0, "JTN ", &isv_1.jtn[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "MDIC", &ishr18_1.mdic, (ftnlen)4);
    bad_(&c__1, &c__0, "INDR", &isv_1.indir__[ifxcor_1.is - 1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TE  ", fxcor_1.te, (ftnlen)4);
    bad_(&c__3, &c__1, "TP  ", &sv_1.tp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "TN  ", &sv_1.tn[ifxcor_1.is * 3 - 3], (ftnlen)4);
L40:

/*             /-SET MODE FOR DD CALCULATION- USE SNXP WITH MODE=0, */
/*             /-OR ELSE USE DDST WITH MODE=-1 */
/*             /-FOR VERY FIRST ENTRY USE MODE=0 */
    mode = -1;
    if (ishr18_1.mdic > 0) {
	goto L50;
    }
    if (isv_1.indir__[ifxcor_1.is - 1] == 1 && ifxcor_1.istrup != 0 && 
	    isv_1.jent[ifxcor_1.is - 1] == 1) {
	goto L50;
    }
    if (modess_1.msschk == 0 && modess_1.modess != 11) {
	goto L50;
    }
/*             /-SET MODE TO SNXP IF ABOVE CONDITIONS DO NOT EXIST */
    mode = 0;
L50:

/*             /-INITIAL PHASE, SCAN SURFACE FOR BEST CANDIDATE */
/*             /-THIS IS USED FOR ERROR RESTART OR INITIAL PROCESSING */
/*             /-LOAD INITIAL PATCH IF DDST MODE OR MODE HAS CHANGED */
    if (ssarlm_1.iddlas[ip - 1] != iddst_1.iddst) {
	goto L63;
    }
/*             /-DO NOT LOAD IF LODFLG IS ZERO AND MDIC IS ZERO */
    if (ssarlm_1.lodflg[ip - 1] == 0 && ishr18_1.mdic == 0) {
	goto L60;
    }
L63:
/*             /-LOAD A PATCH DURING ERROR PROCESSING OR INITIAL PROCESSI */

    lodint_(&ss[1], &ssarlm_1.b[(ip << 6) - 64], &ssarlm_1.u[ip - 1], &
	    ssarlm_1.v[ip - 1], &sv_1.tp[ifxcor_1.is * 3 - 3], &sv_1.tn[
	    ifxcor_1.is * 3 - 3], &ssarlm_1.iflag[(ip << 2) - 4], &
	    ssarlm_1.itop[((ip << 2) + 1) * 6 - 30], &ssarlm_1.ipnum[ip - 1], 
	    &mode);
    if (idebug <= 0) {
	goto L66;
    }
    bad_(&c__1, &c__0, "LODI", &mode, (ftnlen)4);
    bad_(&c__1, &c__1, "UIP ", &ssarlm_1.u[ip - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "VIP ", &ssarlm_1.v[ip - 1], (ftnlen)4);
L66:

/*             /-TRUNCATE INITIAL U,V TO LIE INSIDE PATCH BOUNDARY */
    sqrcut_(&z5em1, &z5em1, &ssarlm_1.u[ip - 1], &ssarlm_1.v[ip - 1], &uu, &
	    vv, &ickbn);
    ssarlm_1.u[ip - 1] = z5em1 + (uu - z5em1) * .9999;
    ssarlm_1.v[ip - 1] = z5em1 + (vv - z5em1) * .9999;
/* L80: */
    ssarlm_1.lodflg[ip - 1] = 0;
    if (idebug <= 0) {
	goto L70;
    }
    bad_(&c__1, &c__0, "LINT", &ssarlm_1.ipnum[ip - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "ICKB", &ickbn, (ftnlen)4);
    bad_(&c__1, &c__1, "UU  ", &uu, (ftnlen)4);
    bad_(&c_n1, &c__1, "VV  ", &vv, (ftnlen)4);
L70:

L60:

/*             /-CALL THE MAIN ALGORITHM FOR DETERMINING THE RELATION */
/*             /-BETWEEN THE SURFACE AND EXTERIOR POINT OR TOOL RAY */
/* ...CALL PCHPRC.  LAST PARAMETER .FALSE. FOR NO GEOMETRIC CONSTRUCTION */

    pchprc_(&ss[1], &ssarlm_1.b[(ip << 6) - 64], &ssarlm_1.u[ip - 1], &
	    ssarlm_1.v[ip - 1], &sv_1.tp[ifxcor_1.is * 3 - 3], &sv_1.tn[
	    ifxcor_1.is * 3 - 3], &ua, &va, &sv_1.sp[ifxcor_1.is * 3 - 3], &
	    sv_1.sn[ifxcor_1.is * 3 - 3], &sv_1.slx[ifxcor_1.is * 3 - 3], &
	    ssarlm_1.iflag[(ip << 2) - 4], &ssarlm_1.itop[((ip << 2) + 1) * 6 
	    - 30], &ssarlm_1.ipnum[ip - 1], &mode, &idebux, &irr, &c_false);

    if (idebug <= 0) {
	goto L100;
    }
    bad_(&c__1, &c__0, "PCHP", &irr, (ftnlen)4);
    bad_(&c__1, &c__0, "MODE", &mode, (ftnlen)4);
    bad_(&c__1, &c__0, "PCNO", &ssarlm_1.ipnum[ip - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "UA  ", &ua, (ftnlen)4);
    bad_(&c_n1, &c__1, "VA  ", &va, (ftnlen)4);
    bad_(&c__3, &c__1, "SP  ", &sv_1.sp[ifxcor_1.is * 3 - 3], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &sv_1.sn[ifxcor_1.is * 3 - 3], (ftnlen)4);
L100:

    if (irr != 0) {
	goto L800;
    }


    if (chekfl_1.ichekf != 1 || lod63 == 1) {
    } else {
	lod63 = 1;
	for (i__ = 1; i__ <= 3; ++i__) {
	    dif[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - sv_1.tp[i__ + 
		    ifxcor_1.is * 3 - 4];
/* L109: */
	}
	dotf_(&dck, fxcor_1.ti, dif);
	if (dck < zm5em1) {
	    goto L63;
	}
    }
/*             /-CHECK FURTHER TO SEE WHETHER U,V ARE VALID */
    nopatc = (integer) ss[4];
    irr = 0;
    if (ssarlm_1.ipnum[ip - 1] < 1 || ssarlm_1.ipnum[ip - 1] > nopatc) {
	goto L70;
    }
/* ---  DOUBLE CHECK TO SEE IF UA,VA ARE ON A LEGAL EXTENSION */
    iur = 2;
    if (ua < zero) {
	iur = 1;
    }
    if (ua > one) {
	iur = 3;
    }
    ivr = 2;
    if (va < zero) {
	ivr = 1;
    }
    if (va > one) {
	ivr = 3;
    }
    isqno = iur + (ivr - 1) * 3;
/* ---  IF UA,VA ARE INSIDE THE PATCH BOUNDS ITS O.K. */
    if (ifxcor_1.iseqno == 5 && ip == k1) {
	ipchn = 0;
    }
    if (isqno == 5) {
	goto L230;
    }
    if (isqno % 2 != 0) {
	goto L240;
    }
/* ---  UA,VA IS ON EXT DIRECTLY OPPOSITE A BOUNDARY */
    ib1 = isqno / 2;
/* ---  CHECK IF A PATCH IS HOOKED TO THIS BOUNDARY */
    if (ssarlm_1.itop[(ib1 + (ip << 2)) * 6 - 29] == 0) {
	goto L230;
    }
    irr = 2;
    goto L230;
L240:
/* ---  UA,VA ARE ON A CORNER EXTENSION, CHECK TWO BOUNDARIES */
    ib1 = 1;
    ib2 = 2;
    if (isqno == 7) {
	ib1 = 4;
    }
    if (isqno == 3) {
	ib2 = 3;
    }
    if (isqno == 9) {
	ib1 = 4;
    }
    if (isqno == 9) {
	ib2 = 3;
    }
/* ---  IB1,IB2 ARE THE BOUNDARIES, CHECK IF EITHER HAS A PATCH */
    if (ssarlm_1.itop[(ib1 + (ip << 2)) * 6 - 29] == 0 && ssarlm_1.itop[(ib2 
	    + (ip << 2)) * 6 - 29] == 0) {
	goto L230;
    }
    irr = 3;
L230:

    if (irr == 0 || idebug <= 0) {
	goto L885;
    }
    record_(&ii);
    bad_(&c__1, &c__0, "ISEQ", &ii, (ftnlen)4);
    bad_(&c__1, &c__0, "IRR ", &irr, (ftnlen)4);
    bad_(&c__1, &c__0, "IPNM", &ssarlm_1.ipnum[ip - 1], (ftnlen)4);
    bad_(&c__1, &c__1, "U   ", &ssarlm_1.u[ip - 1], (ftnlen)4);
    bad_(&c_n1, &c__1, "V   ", &ssarlm_1.v[ip - 1], (ftnlen)4);
    bad_(&c__1, &c__0, "ISQN", &isqno, (ftnlen)4);
    bad_(&c__1, &c__1, "UA  ", &ua, (ftnlen)4);
    bad_(&c_n1, &c__1, "VA  ", &va, (ftnlen)4);
    for (ll = 1; ll <= 4; ++ll) {
	bad_(&c__1, &c__0, "ITOP", &ssarlm_1.itop[(ll + (ip << 2)) * 6 - 29], 
		(ftnlen)4);
/* L825: */
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
L885:
/*             /-QUIT IF IRR IS  NOT ZERO NOW */
    if (irr != 0) {
	goto L800;
    }
    ifxcor_1.ier = 0;
/*             /-SET TN ONLY IF MODE=0 AND MODESS.NE.11(Z DETERMINATION) */
    if (mode != 0) {
	goto L310;
    }
    w1 = one;
    if (isv_1.jtn[ifxcor_1.is - 1] == 0) {
	w1 = -one;
    }
    w1 *= sv_1.z__[ifxcor_1.is - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = w1 * sv_1.sn[i__ + ifxcor_1.is * 
		3 - 4];
/* L320: */
    }
L310:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.temp[i__ - 1] = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - sv_1.tp[
		i__ + ifxcor_1.is * 3 - 4];
/* L300: */
    }
/*             /-MODIFY TN FOR CASE OF MODESS.EQ.11 */
    if (modess_1.modess != 11) {
	goto L330;
    }
    dotf_(&w1, &sv_1.tn[ifxcor_1.is * 3 - 3], fxcor_1.temp);
    if (w1 >= zero) {
	goto L330;
    }
/*             /-REVERSE TN TO POINT TOWARD SP */
    for (i__ = 1; i__ <= 3; ++i__) {
	sv_1.tn[i__ + ifxcor_1.is * 3 - 4] = -sv_1.tn[i__ + ifxcor_1.is * 3 - 
		4];
/* L360: */
    }
L330:
    dotf_(&sv_1.s[ifxcor_1.is - 1], fxcor_1.temp, fxcor_1.temp);
    sv_1.s[ifxcor_1.is - 1] = sqrt(sv_1.s[ifxcor_1.is - 1]);
    dotf_(&w1, fxcor_1.temp, &sv_1.tn[ifxcor_1.is * 3 - 3]);
    sv_1.s[ifxcor_1.is - 1] = d_sign(&one, &w1) * sv_1.s[ifxcor_1.is - 1];

    ssarlm_1.u[ip - 1] = ua;
    ssarlm_1.v[ip - 1] = va;
/*             /-SET THE VALUE OF THE LAST SURFACE POINT */
    iequal = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	w1 = sv_1.sp[i__ + ifxcor_1.is * 3 - 4] - spsav[i__ - 1];
	if (abs(w1) > smal) {
	    iequal = 0;
	}
/* L410: */
    }
/*             /-IF SPSAV IS DIFFERENT AND MODESS.NE.11, SET SPL=SPSAV */
    if (iequal == 1 || modess_1.modess == 11) {
	goto L420;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L430: */
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = spsav[i__ - 1];
    }
    goto L999;
L420:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L440: */
	sv_1.spl[i__ + ifxcor_1.is * 3 - 4] = spsav[i__ - 1];
    }

    goto L999;

/*             /-ERROR PROCESSING */
L800:
    ++kretry;
    if (kretry == 1) {
	goto L340;
    }
/* .... ACCEPT SURFACE POINT */
/* .... IF DISTANCE BETWEEN CUTTER AND SP IS LARGE (DIST.GE.10) */
/* .... AND DISTANCE TO PATCH BOUNDARY IS SMALL (UVDIST.LE.0.05) */
    if (dist >= 10. && uvdist <= .05) {
	irr = 0;
	goto L885;
    }
    if (kretry == 2) {
	goto L350;
    }
    goto L355;
/*             /-RELOAD INITIAL DATA AND RETRY */
L340:
    ssarlm_1.u[ip - 1] = usave;
    ssarlm_1.v[ip - 1] = vsave;
    ssarlm_1.ipnum[ip - 1] = ipsave;
/*             /-BRANCH BACK TO LOAD INITIAL PATCH */
    ssarlm_1.lodflg[ip - 1] = 1 - ssarlm_1.lodflg[ip - 1];
    if (mode != 0 || modes != 11) {
	goto L50;
    }
/*     IF MODE=0, RETRY WITH NEW TE,TP */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L345: */
	dsav[i__ - 1] = fxcor_1.te[i__ - 1] - sv_1.tp[i__ + ifxcor_1.is * 3 - 
		4];
    }
    dotv_(&w1, dsav, dsav);
    w1 = sqrt(w1);
    if (abs(w1) < smal) {
	goto L355;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	dsav[i__ - 1] /= w1;
/* L346: */
    }
    w1 *= .5;
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.te[i__ - 1] += w1 * dsav[i__ - 1];
/* L347: */
	sv_1.tp[i__ + ifxcor_1.is * 3 - 4] += w1 * dsav[i__ - 1];
    }
    goto L50;

L350:
    ifxcor_1.ier = irr;
    if (mode == 0) {
	goto L355;
    }
    ifxcor_1.ier = 0;
    if (iddst_1.iddst == 1) {
	goto L999;
    }
    ifxcor_1.ier = 0;
    mode = 0;
    ishr18_1.mdic = 1;
    goto L63;

L355:
/*             /- FATAL ERROR IN SNXP MODE */
/*                IF IBUG=1 OR 2, DO AGAIN TO GET DYDMP-LIST */
    if (ibugg_1.ibug <= 0) {
	goto L356;
    }
    idebug = 1;
    idebux = 1;
    goto L50;
L356:
    ifxcor_1.iaerr = 25402;
    goto L999;
L999:
    if (idebug > 0) {
	bad_(&c__1, &c__0, "IER ", &ifxcor_1.ier, (ftnlen)4);
    }
    if (idebug > 0) {
	bad_(&c_n1, &c__0, "AERR", &ifxcor_1.iaerr, (ftnlen)4);
    }
    ssarlm_1.mcat = iclcur;
    ssarlm_1.iseqls = ifxcor_1.iseqno;
    ssarlm_1.iddlas[ip - 1] = iddst_1.iddst;
    ssarlm_1.jenlas[ip - 1] = isv_1.jent[ifxcor_1.is - 1];
    if (ifxcor_1.iaerr != 0) {
	ibugg_1.ibug = 0;
    }
    if (ifxcor_1.iaerr != 0) {
	iaer1 = ifxcor_1.iaerr;
    }
    if (ifxcor_1.iaerr != 0) {
	aerr_(&iaer1, "DDSSRF  ", (ftnlen)8);
    }
    return 0;
} /* ddssrf_ */

#undef sinl
#undef cosl


