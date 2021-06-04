/* GOP.f -- translated by f2c (version 20100827).
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
    integer regflg;
    logical ringfg;
    integer motdir, iautog;
} glflgs_;

#define glflgs_1 glflgs_

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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

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
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4], ifeedf;
} cclear_;

#define cclear_1 cclear_

struct {
    integer id[24];
    doublereal obnam1;
    integer jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10], vta[3];
} plgol_;

#define plgol_1 plgol_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

/* Table of constant values */

static integer c__0 = 0;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__22222 = 22222;
static integer c_n2 = -2;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__14 = 14;
static integer c__4 = 4;
static integer c__28 = 28;
static integer c__43 = 43;
static integer c__61 = 61;
static integer c__6 = 6;
static integer c__76 = 76;
static integer c__91 = 91;
static integer c__15 = 15;
static integer c__30 = 30;
static integer c__45 = 45;
static integer c__63 = 63;
static integer c__78 = 78;
static integer c__93 = 93;

/* *** SOURCE FILE : M0012240.V01   *** */

/* Subroutine */ int gop_(integer *mod, doublereal *u, doublereal *v, 
	doublereal *spv, integer *j11, integer *iret)
{
    /* Initialized data */

    static char cmodf[8*7] = "PLOTKP  " "PLOTKF  " "PLOTFU  " "PLOTFV  " 
	    "PLOTGR  " "GOFLU   " "GOFLV   ";
    static integer itest5 = 1;
    static integer j11o = -1;
    static logical first = TRUE_;
    static struct {
	doublereal e_1[4];
	} equiv_15 = { 1.903e7, 0., 0., 0. };

    static struct {
	doublereal e_1[4];
	} equiv_16 = { 2.003e7, 0., 0., 0. };

    static struct {
	integer e_1[18];
	doublereal e_2;
	} equiv_2 = { 0, 0, 1308622848, 0, 1308622848, 6, 1308622848, 1, 0, 0,
		 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0. };

    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_3 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 2, 0, 0,
		 0. };

    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_4 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 2, 0, 0,
		 0. };

    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_5 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 1, 0, 0,
		 0. };


    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_6[7];

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal);

    /* Local variables */
    static doublereal a, b, c__, e, f, g;
    static integer i__, j;
    static doublereal q[3], w, t1, t2, t3, t4, al[2], ax[6]	/* was [3][2] 
	    */;
#define pt ((doublereal *)&equiv_15 + 1)
    static doublereal dm[3];
    static integer mm, iu, iv;
    static doublereal up, vp, vn, vm, vq, xl, xn, xm, pl, we, dv, du;
    static integer nr, ir;
#define pt1 ((doublereal *)&equiv_15)
#define vt0 ((doublereal *)&equiv_16 + 1)
#define vt1 ((doublereal *)&equiv_16)
    static doublereal vt2[3];
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer iwo;
    static doublereal vll, xnl;
    extern integer bcdf_(char *, ftnlen);
#define modf (equiv_6)
    static doublereal cosd[2];
#define incr ((integer *)&plgol_1 + 16)
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static doublereal sind[2];
#define cosl ((doublereal *)&tlldat_1 + 16)
#define leit ((doublereal *)&equiv_2)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define iart ((integer *)&plgol_1 + 12)
    static integer itop[24]	/* was [6][4] */, nspl, npnt;
    static doublereal supi, svpi;
    static integer iflag[4];
#define ifedr ((integer *)&equiv_5)
#define ipend ((integer *)&equiv_4)
#define imodf ((integer *)equiv_6)
#define ileit ((integer *)&equiv_2)
#define penup ((doublereal *)&equiv_3)
#define ipenu ((integer *)&equiv_3)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static doublereal patch[64];
    static integer npato;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal xnorm;
    extern /* Subroutine */ int atape_(void), cform_(char *, char *, integer *
	    , integer *, ftnlen, ftnlen), fconv_(doublereal *, char *, 
	    integer *, integer *, integer *, ftnlen);
    static doublereal cgamma;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define fedrat ((doublereal *)&equiv_5)
#define pendwn ((doublereal *)&equiv_4)
#define normal ((integer *)&plgol_1 + 15)
#define mirror ((integer *)&plgol_1 + 14)
    extern /* Subroutine */ int curflo_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), transm_(doublereal *, 
	    doublereal *, integer *, integer *, integer *);
    static integer npatch;
    static doublereal canold;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), cnsurf_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
    static integer invers;
    static doublereal sinalf, cosalf;
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, doublereal *, integer *, integer *), cprint_(char *, 
	    ftnlen);





/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/* .... GOLOFT FLAGS */



/*     REGFLG:    REGION FLAG */
/*     RINGFG:    RING CUTTER FLAG */
/*     MOTDIR:    MOTION DIRECTION FLAG OF TLAXIS */
/*     IAUTOG:    TLAXIS/...,AUTO FLAG */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   *** 9.  SV BLOCK *** */

/*   REAL SURFACE VARIABLES */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/* SS - ARELEM - COMMON */

/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/*  LENGTH OF PROJECTION OF NEW AXIS ON OLD AXIS */

/*  PAIRS OF SIN AND COSIN VALUES */

/*  TWO POSSIBLE TOOL AXIS IN 4 OR 5 AXIS CASE */

/*  OUTPUT-ARRAY OF THE HEADER */


/*   GOLOFT/PLOTFT-COMMON */


/*     EQUIVALENCE (ID(1),UVCONS) */
/*     EQUIVALENCE (ID(3),UVA) */
/*     EQUIVALENCE (ID(5),UVE) */
/*     EQUIVALENCE (ID(7),TOL) */
/*     EQUIVALENCE (ID(9),VL) */
/*     EQUIVALENCE (ID(11),NU) */
/*     EQUIVALENCE (ID(12),NV) */

/*   IART: 1,2: PLOTING CURVES; 3,4: PLOTING SURFACE LINES */
/*           5: PLOT SURF GRID; 6,7: SURFACE CUTTING */
/* INVERS: INVERT THE TRAVEL DIRECTION IF =1 */
/*     EQUIVALENCE (ID(14),INVERS) */
/* MIRROR: INVERT NORMAL DIRECTION IF =1 */
/* NORMAL: TAKE THE SURFACE NORMAL AS TOOL AXIS IF =1 */
/*   INCR: CURVATURE CALCULATION NECESSARY IF NOT =1 */

/*  JCSEG: USED CUTTER SEGMENT */
/*  NCSEG: NUMBER OF VALID CUTTER SEGMENTS */
/*  ICSEG: CUTTER SEGMENT IN TLLDAT ARRAYS */
/* NLIOCI: NATURE OF SEGMENT */
/*  COSAL: COMPONENTS OF SEGMENT AND UNIT NORMAL */
/*  SINAL: POINTING INTO THE CUTTER */
/*   CUTY: DISTANCE PARALLEL TO THE CUTTER AXIS */
/*   CUTX: DISTANCE TO THE CUTTER AXIS */
/*   CUTL: ELEMENT LENGTH */
/*    VTA: VECTOR-COMPONENTS OF THE TOOL-AXIS-VECTOR */

/*     BLANK-COMMON */

/* SYSTEM - I/O NAMES */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*   POINT STORAGE FOR TRANSFORMATION PURPOSE */

/* ...                SYSTEM I/O FILES */



/*   VECTOR STORAGE FOR TRANSFORMATION PURPOSE */
/*   MOTION DIRECTION AND CROSS VECTOR */
/*   EVALUATION FIELDS */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/*       SS PRINT CONTROL */



    /* Parameter adjustments */
    --spv;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/*     INITIALISE CHARACTER ITEMS FOR OUTPUT TO EXFILE */

    if (first) {
	for (i__ = 1; i__ <= 7; ++i__) {
	    imodf[(i__ << 1) - 2] = bcdf_(cmodf + (i__ - 1 << 3), (ftnlen)4);
	    imodf[(i__ << 1) - 1] = bcdf_(cmodf + ((i__ - 1 << 3) + 4), (
		    ftnlen)4);
/* L5: */
	}
	ileit[0] = bcdf_("CLDA", (ftnlen)4);
	ileit[1] = bcdf_("TA  ", (ftnlen)4);
	leit[4] = modf[4];
	ipenu[0] = bcdf_("PENU", (ftnlen)4);
	ipenu[1] = bcdf_("P   ", (ftnlen)4);
	ipenu[8] = bcdf_("    ", (ftnlen)4);
	ipenu[9] = ipenu[8];
	ipend[0] = bcdf_("PEND", (ftnlen)4);
	ipend[1] = bcdf_("WN  ", (ftnlen)4);
	pendwn[4] = penup[4];
	ifedr[0] = bcdf_("FEDR", (ftnlen)4);
	ifedr[1] = bcdf_("AT  ", (ftnlen)4);
	first = FALSE_;
    }
/*  PREPARATION OF THE EVALUATION RESULT STORAGE */
    if (*incr == 1) {
	goto L11;
    }
    for (i__ = 33; i__ <= 52; ++i__) {
/* L10: */
	spv[i__] = 0.;
    }

/*   CURVE OR SURFACE ? */
L11:
    if (*iart >= 3) {
	goto L1000;
    }
    mm = 0;
    if (*mod != 2) {
	mm = 2;
    }
    curflo_(u, &sscan[*j11], &spv[1], &mm, &c__0);
    for (i__ = 1; i__ <= 3; ++i__) {
	pt[i__ - 1] = spv[i__];
/* L80: */
	spv[i__ + 32] = spv[i__];
    }
    if (*mod == 1) {
	return 0;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L90: */
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
    goto L7100;

/*    COMPUTATION OF PATCH NUMBER AND FETCHING OF THE PATCH */
L1000:
    nspl = (integer) (sscan[*j11 + 8] - 1.);
    npnt = (integer) (sscan[*j11 + 9] - 1.);
    iu = (integer) (*u);
    iv = (integer) (*v);
    if (iu < npnt) {
	goto L2110;
    }
    iu = npnt - 1;
L2130:
    up = *u - iu;
L2140:
    if (iv < nspl) {
	goto L2120;
    }
    iv = nspl - 1;
L2150:
    vp = *v - iv;
L2160:
    npatch = iv * npnt + iu + 1;
    goto L2310;
L2110:
    if (iu >= 0) {
	goto L2130;
    }
    iu = 0;
    up = *u;
    goto L2140;
L2120:
    if (iv >= 0) {
	goto L2150;
    }
    iv = 0;
    vp = *v;
    goto L2160;
L2310:
    if (*j11 == j11o && npatch == npato && sscan[*j11] == canold) {
	goto L2315;
    }
    lodpch_(&sscan[*j11], patch, iflag, itop, &npatch, &c__1);
    j11o = *j11;
    npato = npatch;
    canold = sscan[*j11];
L2315:
    mm = 2;
    cnsurf_(&up, &vp, patch, &spv[1], iflag, &mm);

/* STORE VALUES FOR ATAPE */
    ssarlm_1.uu[0] = up;
    ssarlm_1.vv[0] = vp;
    ssarlm_1.ipnum[0] = npatch;

/* STORE SURFACE POINT WITH NORMAL FOR ATAPE */
    for (i__ = 1; i__ <= 3; ++i__) {
	pt[i__ - 1] = spv[i__];
	vt0[i__ - 1] = spv[i__ + 28];
/* L2320: */
    }
    transm_(&sv_1.sp[ifxcor_1.ips * 3 - 3], pt, &c__2, &c__3, &c__0);
    transm_(&sv_1.sn[ifxcor_1.ips * 3 - 3], vt0, &c__3, &c__3, &c__0);

/*  CALCULATION OF MOTION DIRECTION */
    iwo = 8;
    if (*iart == 7) {
	iwo = 4;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4080: */
	dm[i__ - 1] = spv[iwo + i__];
    }

/*  LENGTH OF MOTION DIRECTION */
    vll = sqrt(dm[0] * dm[0] + dm[1] * dm[1] + dm[2] * dm[2]);
/*  INVERT LENGTH IF MOTION DIRECTION IS INVERS */
    if (invers == 1) {
	vll = -vll;
    }
/*  NORMALIZE MOTION DIRECTION */
    for (i__ = 1; i__ <= 3; ++i__) {
	dm[i__ - 1] /= vll;
/* L4090: */
	vt0[i__ - 1] = dm[i__ - 1];
    }
    transm_(fxcor_1.ti, vt0, &c__3, &c__3, &c__0);

/*   INVERSION OF NORMAL */
    if (*mirror != 1) {
	goto L4000;
    }
    for (i__ = 29; i__ <= 31; ++i__) {
/* L3090: */
	spv[i__] = -spv[i__];
    }

/*   IS THE SURFACE NORMAL TO BE USED AS TOOL AXIS ? */
L4000:
    if (*normal == 1) {
	goto L4050;
    }
    if (isv_1.jtlflg[ifxcor_1.ips - 1] != 0) {
	goto L4070;
    }

/*  GIVEN TOOL-AXIS IS USED */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4010: */
	vt0[i__ - 1] = fxcor_1.ta[i__ - 1];
    }
    transm_(&spv[37], vt0, &c__3, &c__3, &c_n1);
    goto L5000;

/* SURFACE NORMAL AS TOOL-AXIS */
L4050:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4060: */
	spv[i__ + 36] = spv[i__ + 28];
    }
    goto L5000;

/* ********** 4 AND 5 AXIS CALCULATION ************** */

/*  ONLY GOLOFT ALLOWED */
L4070:
    if (*iart != 6 && *iart != 7) {
	goto L5000;
    }

/* TLAXIS PARLELL CASE */
    if (ifxcor_1.mantax == 2 && ifxcor_1.numax == 2) {
	goto L4300;
    }

/*  CALCULATE CROSS VECTOR */
    cross_(dm, &spv[29], q);

/* 5 AXIS CALCULATION */
/* L4100: */
    if (ifxcor_1.mantax != 2 || ifxcor_1.numax != 1) {
	goto L4200;
    }
/*  NEAR NORMAL SURFACE CONDITION */
    if (abs(fxcor_1.sagl) < 1e-5) {
	goto L4110;
    }
/*  INTERSECTION CONDITION */
    if ((d__1 = sin(fxcor_1.alp) / fxcor_1.sagl, abs(d__1)) <= 1.) {
	goto L4120;
    }
/*  TOOL AXIS CAN NOT BE COMPUTED */
L4110:
    *iret = max(*iret,2);
    if (! ssprt_1.sstest) {
	goto L4115;
    }

/*  TOOL-AXIS CAN NOT BE COMPUTED. */
    aerr_(&c__22222, "GOP     ", (ftnlen)8);

    bad_(&c__1, &c__1, "SAGL", &fxcor_1.sagl, (ftnlen)4);
    bad_(&c__1, &c__1, "CAGL", &fxcor_1.cagl, (ftnlen)4);
    bad_(&c__1, &c__1, "VN  ", &vn, (ftnlen)4);
    bad_(&c__1, &c__1, "VM  ", &vm, (ftnlen)4);
    bad_(&c_n1, &c__1, "VQ  ", &vq, (ftnlen)4);
    bad_(&c__2, &c__1, "SIND", sind, (ftnlen)4);
    bad_(&c_n2, &c__1, "COSD", cosd, (ftnlen)4);
    bad_(&c__1, &c__1, "A   ", &a, (ftnlen)4);
    bad_(&c__1, &c__1, "B   ", &b, (ftnlen)4);
    bad_(&c_n1, &c__1, "W   ", &w, (ftnlen)4);

L4115:
    spv[37] = 0.;
    spv[38] = 0.;
    spv[39] = 1.;
    goto L5000;

/*  SIN OF DELTA */
L4120:
    sind[0] = -sin(fxcor_1.alp) / fxcor_1.sagl;
    sind[1] = sind[0];

/*  COSIN OF DELTA */
    cosd[0] = sqrt(1. - sind[0] * sind[0]);
    cosd[1] = -cosd[0];
    goto L4280;

/* 4 AXIS CALCULATION */
L4200:
    if (ifxcor_1.mantax != 2 || ifxcor_1.numax != 0) {
	goto L5000;
    }
/*  NEAR NORMAL SURFACE CONDITION */
    if (abs(fxcor_1.sagl) < 1e-5) {
	goto L4110;
    }
/*  COMPUTE COMPONENTS OF 4 AXIS VECTOR IN NORMAL MOTION AND CROSS DIR */
    vn = 0.;
    vm = 0.;
    vq = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	vn += spv[i__ + 28] * fxcor_1.ax4[i__ - 1];
	vm += dm[i__ - 1] * fxcor_1.ax4[i__ - 1];
/* L4210: */
	vq += q[i__ - 1] * fxcor_1.ax4[i__ - 1];
    }
/*  COMPUTE SOLUTIONS FOR QUADRATIC EQUATION FOR COSIN(DELTA) */
    b = fxcor_1.cagl / fxcor_1.sagl * vn * vq;
    a = vq * vq + vm * vm;
/*  4 AXIS VECTOR NEAR NORMAL SURFACE */
    if (a < 1e-10) {
	goto L4110;
    }
/* Computing 2nd power */
    d__1 = fxcor_1.cagl / fxcor_1.sagl * vn;
    w = a - d__1 * d__1;
/*  NO INTERSECTION */
    if (w < 0.) {
	goto L4110;
    }
    w = vm * sqrt(w);
    cosd[0] = (b + w) / a;
    cosd[1] = (b - w) / a;
    if (abs(cosd[0]) > 1.) {
	cosd[0] = cosd[1];
    }
    if (abs(cosd[1]) > 1.) {
	cosd[1] = cosd[0];
    }
    if (abs(cosd[1]) > 1.) {
	goto L4110;
    }
    sind[0] = (fxcor_1.cagl / fxcor_1.sagl * vn - cosd[0] * vq) / vm;
    sind[1] = (fxcor_1.cagl / fxcor_1.sagl * vn - cosd[1] * vq) / vm;
/*  COMPUTE THE TWO POSSIBLE AXIS VECTORS AND THE SCALAR PRODUCT */
/*   WITH THE PREVIOUS AXIS VECTOR */
L4280:
    for (j = 1; j <= 2; ++j) {
	al[j - 1] = 0.;
	for (i__ = 1; i__ <= 3; ++i__) {
	    ax[i__ + j * 3 - 4] = fxcor_1.sagl * (q[i__ - 1] * cosd[j - 1] + 
		    dm[i__ - 1] * sind[j - 1]) - fxcor_1.cagl * spv[i__ + 28];
	    al[j - 1] += ax[i__ + j * 3 - 4] * plgol_1.vta[i__ - 1];
/* L4285: */
	}
    }
/*  SELECTION OF THE NEW TOOL AXIS VECTOR WICH IS CLOSER TO THE OLD ONE */
    j = 1;
    if (al[1] > al[0]) {
	j = 2;
    }
/*  NEW AXIS DIRECTION */
    for (i__ = 1; i__ <= 3; ++i__) {
	plgol_1.vta[i__ - 1] = ax[i__ + j * 3 - 4];
/* L4290: */
	spv[i__ + 36] = plgol_1.vta[i__ - 1];
    }
    goto L5000;
/* PARALLEL AXIS CALCULATION (ALONG RULINGS) */
/*  SELECTION OF CROSS DIRECTION */
L4300:
    iwo = 4;
    if (*iart == 7) {
	iwo = 8;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4310: */
	q[i__ - 1] = spv[iwo + i__];
    }
/*  LENGTH OF CROSS DIRECTION */
/* Computing 2nd power */
    d__1 = q[0];
/* Computing 2nd power */
    d__2 = q[1];
/* Computing 2nd power */
    d__3 = q[2];
    vll = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/*  USE INVERTED LENGTH IF CROSS DIRECTION HAS TO BE INVERTED */
/*   NEW AXIS SHOULD HAVE THE SAME ORIENTATION AS THE OLD ONE */
    if (q[0] * plgol_1.vta[0] + q[1] * plgol_1.vta[1] + q[2] * plgol_1.vta[2] 
	    < 0.) {
	vll = -vll;
    }
/*  NEW AXIS DIRECTION PLUS A SMALL AMOUNT IN ORDER TO AVOID JUMPING */
    for (i__ = 1; i__ <= 3; ++i__) {
	plgol_1.vta[i__ - 1] = q[i__ - 1] / vll + spv[i__ + 28] * 1e-12;
/* L4320: */
	spv[i__ + 36] = plgol_1.vta[i__ - 1];
    }
/*  STORING NEW POINT */
L5000:
    for (i__ = 1; i__ <= 3; ++i__) {
/*  PART SURFACE THICKNES IS USED */
/* L5090: */
	spv[i__ + 32] = spv[i__] + sv_1.th[ifxcor_1.ips - 1] * spv[i__ + 28];
    }
/*  END OF CALCULATION IF PLOTING */
    if (*iart < 6) {
	goto L7000;
    }
/*  END OF CALCULATION IF NORMAL CONDITION */
    if (*normal == 1) {
	goto L7000;
    }
/*  END OF CALCULATION IF ZERO CUTTER */
    if (fxcor_1.cutdat[0] < .001f) {
	goto L7000;
    }
/*  CALCULATION OF VECTOR PERPENDICULAR TO SURFACE NORMAL AND TOOL AXIS */
    cross_(&spv[29], &spv[37], vt0);
/*  LENGTH OF CROSS VECTOR */
    vll = vt0[0] * vt0[0] + vt0[1] * vt0[1] + vt0[2] * vt0[2];
/*  END OF CALCULATION IF SURFACE NORMAL AND TOOL AXIS ARE PARALLEL */
    if (vll <= 1e-10) {
	goto L7000;
    }
    vll = sqrt(vll);
/*  PROJECTION OF SURFACE NORMAL */
    cross_(&spv[37], vt0, vt2);
/*  NEW TOOL-TIP CALCULATION */
/*  IS RING CUTTER GIVEN ? */
    if (! glflgs_1.ringfg) {
	goto L6070;
    }
/*  STORE RING AS 10TH SEGMENT */
    plgol_1.jcseg = 10;
    plgol_1.cutl[plgol_1.jcseg - 1] = 0.;
    plgol_1.cutx[plgol_1.jcseg - 1] = tlldat_1.ri[7];
    plgol_1.cuty[plgol_1.jcseg - 1] = tlldat_1.tlhite[7];
    goto L6075;
/*   COMPUTATION OF THE COSIN OF THE ANGLE BETWEEN THE TOOL-AXIS */
/*   AND THE SURFACE NORMAL */
L6070:
    cgamma = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L6080: */
	cgamma = spv[i__ + 36] * spv[i__ + 28] + cgamma;
    }
    i__1 = plgol_1.ncseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	plgol_1.jcseg = i__;
	if (plgol_1.nlioci[i__ - 1] == 1) {
	    goto L6081;
	}
	if (plgol_1.cosal[i__ - 1] <= cgamma) {
	    goto L6082;
	}
L6081:
	;
    }
L6082:

/* NEW TOOL-TIP CALCULATION */
L6075:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L6090: */
	spv[i__ + 32] = spv[i__ + 32] + spv[i__ + 28] * plgol_1.cutl[
		plgol_1.jcseg - 1] + vt2[i__ - 1] * plgol_1.cutx[
		plgol_1.jcseg - 1] / vll - spv[i__ + 36] * plgol_1.cuty[
		plgol_1.jcseg - 1];
    }
/*  NO CURVATURE CALCULATION IF INCR=1 */
L7000:
    if (*incr == 1) {
	goto L7005;
    }
/*  COMPUTATION OF THE FUNDAMENTAL FORMS */
    e = 0.;
    f = 0.;
    g = 0.;
    xl = 0.;
    xn = 0.;
    xm = 0.;
/*  PROJECTION LENGTH */
    pl = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	supi = spv[i__ + 4];
	svpi = spv[i__ + 8];
	e = supi * supi + e;
	f = supi * svpi + f;
	g = svpi * svpi + g;
	xnorm = spv[i__ + 28];
	xl = spv[i__ + 12] * xnorm + xl;
	xm = spv[i__ + 16] * xnorm + xm;
	xn = spv[i__ + 20] * xnorm + xn;
/*  PROJECTION LENGTH */
/* L7002: */
	pl = (spv[i__ + 32] - spv[i__]) * spv[i__ + 28] + pl;
    }
    spv[45] = e;
    spv[46] = f;
    spv[47] = g;
    spv[49] = xl;
    spv[50] = xm;
    spv[51] = xn;
/*  PROJECTION LENGTH */
    spv[52] = pl;
/*  READY IF ONLY PLOTING */
    if (*iart <= 5) {
	goto L7005;
    }
/*   LENGTH OF NORMAL */
    xnl = sqrt(e * g - f * f) + 1e-12;
/*   COMPUTATION OF THE MAIN CURVATURE DIRECTION */
/*   A=G*M-F*N */
    a = g * spv[50] - f * spv[51];
/*   B=G*L-E*N */
    b = g * spv[49] - e * spv[51];
/*   C=F*L-E*M */
    c__ = f * spv[49] - e * spv[50];
    t1 = b * b - a * 4. * c__;
    t2 = sqrt(t1);
    t3 = e * b - f * 2. * c__;
    if (t3 < 0.) {
	t2 = -t2;
    }
    t4 = sqrt(e * 2. * e * t1 + e * 2. * t3 * t2);
    if (abs(t4) > 0.) {
	goto L7060;
    }
/*   NO MAIN CURVATURE DIRECTION FOUND */
    sinalf = 0.;
    cosalf = 1.;
    goto L7070;
L7060:
    sinalf = (t3 + e * t2) / t4;
    cosalf = c__ * 2. * xnl / t4;
L7070:
    we = sqrt(e);
    for (i__ = 1; i__ <= 3; ++i__) {
/*  U-TANGENT */
/* L7300: */
	vt0[i__ - 1] = spv[i__ + 4] / we;
    }
/*  VECTOR PERPENTICULAR TO U-TANGENT */
    if (*mirror != 1) {
	cross_(&spv[29], vt0, vt2);
    }
    if (*mirror == 1) {
	cross_(vt0, &spv[29], vt2);
    }
/*  DIRECTION OF 1. MAIN CURVATURE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L7310: */
	spv[i__ + 40] = cosalf * vt0[i__ - 1] + sinalf * vt2[i__ - 1];
    }
/*  COMPUTATION OF 1. MAIN CURVATURE */
    dv = e * sinalf;
    du = xnl * cosalf - f * sinalf;
    spv[40] = (spv[49] * du * du + spv[50] * 2. * du * dv + spv[51] * dv * dv)
	     / (e * du * du + f * 2. * du * dv + g * dv * dv);
/*  COMPUTATION OF 2. MAIN CURVATURE */
    dv = e * cosalf;
    du = -xnl * sinalf - f * cosalf;
    spv[44] = (spv[49] * du * du + spv[50] * 2. * du * dv + spv[51] * dv * dv)
	     / (e * du * du + f * 2. * du * dv + g * dv * dv);
/*  RETURN ,IF COMPUTATION OF POSITIONS ONLY */
L7005:
    if (*mod == 1) {
	return 0;
    }
/*  IS THE TOOL AXIS TO BE CHANGED */
    if (*normal != 1 && ifxcor_1.mantax != 2) {
	goto L7020;
    }
/*  STORING TOOL AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L7010: */
	vt0[i__ - 1] = spv[i__ + 36];
    }
    transm_(fxcor_1.ta, vt0, &c__3, &c__3, &c__0);
/*  STORING TOOL TIP */
L7020:
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
/* L7030: */
	pt[i__ - 1] = spv[i__ + 32];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
/*   CL FILE OUTPUT */
    if (*iart != 5) {
	goto L7100;
    }
    if (itest5 == 0 && ifxcor_1.icl == 2) {
	goto L7100;
    }
    if (itest5 == 0) {
	goto L7050;
    }
/*   1. POINT OD A 'GRID' CURVE */
    ifxcor_1.icl = 3;
    atape_();
    ifxcor_1.icl = 2;
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ipend[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, pendwn, &j, &ir);
    nr = 0;
    j = 18;
    record_(&ifxcor_1.iseqno);
    ileit[3] = ifxcor_1.iseqno;
    leit[4] = modf[*iart - 1];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    itest5 = 0;
    goto L7200;
/*   LAST POINT */
L7050:
    atape_();
    itest5 = 1;
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ipenu[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, penup, &j, &ir);
    goto L7200;

/*  IS THE GLOBAL FEEDRAT TO BE WRITTEN */
L7100:
    if (cclear_1.ifeedf != 1 || *iart < 6) {
	goto L7150;
    }

/*  OUTPUT POINT */
    ifxcor_1.icl = 3;
    atape_();
    ifxcor_1.icl = 2;

/*  FEDRAT AFTER FIRST GOLOFT POINT */
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ifedr[3] = ifxcor_1.iseqno;
    fedrat[4] = cclear_1.glfeed;
    ewrite_(&symfil_1.exfile, &nr, fedrat, &j, &ir);
    nr = 0;
    j = 18;
    record_(&ifxcor_1.iseqno);
    ileit[3] = ifxcor_1.iseqno;
    leit[4] = modf[*iart - 1];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    cclear_1.ifeedf = 0;
    goto L7200;
L7150:
    atape_();
L7200:
    if (! ssprt_1.sstest) {
	return 0;
    }
    cform_("0PKT.,NORM.:", darray_1.darray, &c__1, &c__12, (ftnlen)12, (
	    ftnlen)120);
    fconv_(&spv[1], darray_1.darray, &c__13, &c__14, &c__4, (ftnlen)120);
    fconv_(&spv[2], darray_1.darray, &c__28, &c__14, &c__4, (ftnlen)120);
    fconv_(&spv[3], darray_1.darray, &c__43, &c__14, &c__4, (ftnlen)120);
    fconv_(&spv[29], darray_1.darray, &c__61, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[30], darray_1.darray, &c__76, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[31], darray_1.darray, &c__91, &c__14, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_(" TE,TA     :   ", darray_1.darray, &c__1, &c__15, (ftnlen)15, (
	    ftnlen)120);
    fconv_(fxcor_1.te, darray_1.darray, &c__15, &c__14, &c__4, (ftnlen)120);
    fconv_(&fxcor_1.te[1], darray_1.darray, &c__30, &c__14, &c__4, (ftnlen)
	    120);
    fconv_(&fxcor_1.te[2], darray_1.darray, &c__45, &c__14, &c__4, (ftnlen)
	    120);
    fconv_(fxcor_1.ta, darray_1.darray, &c__63, &c__14, &c__6, (ftnlen)120);
    fconv_(&fxcor_1.ta[1], darray_1.darray, &c__78, &c__14, &c__6, (ftnlen)
	    120);
    fconv_(&fxcor_1.ta[2], darray_1.darray, &c__93, &c__14, &c__6, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (*incr == 1) {
	return 0;
    }
    cform_(" E,F,G,L,M,N:  ", darray_1.darray, &c__1, &c__15, (ftnlen)15, (
	    ftnlen)120);
    fconv_(&e, darray_1.darray, &c__15, &c__14, &c__6, (ftnlen)120);
    fconv_(&f, darray_1.darray, &c__30, &c__14, &c__6, (ftnlen)120);
    fconv_(&g, darray_1.darray, &c__45, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[49], darray_1.darray, &c__63, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[50], darray_1.darray, &c__78, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[51], darray_1.darray, &c__93, &c__14, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    if (*iart <= 5) {
	return 0;
    }
    cform_(" SIN,COS,K,K:  ", darray_1.darray, &c__1, &c__15, (ftnlen)15, (
	    ftnlen)120);
    fconv_(&sinalf, darray_1.darray, &c__15, &c__14, &c__6, (ftnlen)120);
    fconv_(&cosalf, darray_1.darray, &c__30, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[40], darray_1.darray, &c__45, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[44], darray_1.darray, &c__63, &c__14, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    cform_(" TANGENT    :  ", darray_1.darray, &c__1, &c__15, (ftnlen)15, (
	    ftnlen)120);
    fconv_(&spv[41], darray_1.darray, &c__15, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[42], darray_1.darray, &c__30, &c__14, &c__6, (ftnlen)120);
    fconv_(&spv[43], darray_1.darray, &c__45, &c__14, &c__6, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    return 0;
} /* gop_ */

#undef mirror
#undef normal
#undef pendwn
#undef fedrat
#undef bcanon
#undef sscan
#undef canon
#undef ipenu
#undef penup
#undef ileit
#undef imodf
#undef ipend
#undef ifedr
#undef iart
#undef sinl
#undef leit
#undef cosl
#undef incr
#undef modf
#undef can
#undef vt1
#undef vt0
#undef pt1
#undef pt


