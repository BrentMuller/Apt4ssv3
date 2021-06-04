/* GORETR.f -- translated by f2c (version 20100827).
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
    integer id[24];
    doublereal obnam1;
} plgol_;

#define plgol_1 plgol_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

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
    integer iaerr, iautps, ibegin, ic, icl, ics, icscnt, ictdef, icut, ids, 
	    ier, igo, igoto, igoug, igs, inops, ipsdef, ips, ipt1, is, iseqno,
	     isrch, istrup, it, i3dflg, jbr, jsw, lsv, lsv1, motmod, mulout, 
	    mantax, nmpnts, nrec, numax, numcnt, nump, numpt1, numsfs, numsur,
	     nw, icheck, iseg, nmbseg, nwds, msav;
} ifxcor_;

#define ifxcor_1 ifxcor_

struct {
    integer clfilp, clfile, clfil3, exfile, infile__, vlfile, pnchfl, xcan, 
	    mactxt, xnum, elfil1, elfil2, elfil3, elfil4, cpfile, axfile, 
	    pofile, elfile, ldafil, tifile, pxfile, nfil12, nfil13, libfil, 
	    ispare[26];
} symfil_;

#define symfil_1 symfil_

struct {
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4], ifeedf;
} cclear_;

#define cclear_1 cclear_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__0 = 0;
static integer c__2 = 2;

/* *** SOURCE FILE : M0011489.V01   *** */

/* Subroutine */ int goretr_(integer *lseg, doublereal *u, doublereal *v, 
	doublereal *spv, integer *j11, integer *iret)
{
    /* Initialized data */

    static char cmodf[8*9] = "PLOTKP  " "PLOTKF  " "PLOTFU  " "PLOTFV  " 
	    "PLOTGR  " "GOFLU   " "GOFLV   " "CLEARS  " "CLEARP  ";
    static logical first = TRUE_;
    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_11 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 2, 0, 
		0, 0. };

    static struct {
	integer e_1[10];
	doublereal e_2;
	} equiv_12 = { 0, 0, 1308622848, 0, 1308622848, 2, 1308622848, 1, 0, 
		0, 0. };

    static struct {
	doublereal e_1[4];
	} equiv_6 = { 1.903e7, 0., 0., 0. };

    static struct {
	doublereal e_1[4];
	} equiv_7 = { 2.003e7, 0., 0., 0. };

    static struct {
	integer e_1[18];
	doublereal e_2;
	} equiv_9 = { 0, 0, 1308622848, 0, 1308622848, 6, 1308622848, 1, 0, 0,
		 1308622848, 0, 0, 0, 1308622848, 0, 1308622848, 0, 0. };


    /* System generated locals */
    static doublereal equiv_10[9];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal dm[3], cp[3];
    static integer ir, nr;
#define pt ((doublereal *)&equiv_6 + 1)
#define vt ((doublereal *)&equiv_7 + 1)
#define pt1 ((doublereal *)&equiv_6)
#define vt1 ((doublereal *)&equiv_7)
#define can ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int gop_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
    static doublereal vll;
    static integer iwo;
    extern integer bcdf_(char *, ftnlen);
#define modf (equiv_10)
    static integer icls;
#define leit ((doublereal *)&equiv_9)
#define iart ((integer *)&plgol_1 + 12)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
#define ifedr ((integer *)&equiv_12)
    extern /* Subroutine */ int atape_(void);
#define canon ((doublereal *)&_BLNK__1)
#define imodf ((integer *)equiv_10)
#define rapid ((doublereal *)&equiv_11)
    static integer iblnk;
#define irapi ((integer *)&equiv_11)
#define ileit ((integer *)&equiv_9)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
#define obname ((doublereal *)&equiv_9 + 6)
#define fedrat ((doublereal *)&equiv_12)
    extern /* Subroutine */ int record_(integer *), ewrite_(integer *, 
	    integer *, doublereal *, integer *, integer *);
#define invers ((integer *)&plgol_1 + 13)
    extern /* Subroutine */ int transm_(doublereal *, doublereal *, integer *,
	     integer *, integer *);


/*  RETRACT AND MOVEIN ROUTINE FOR >GOL< */


/*  GOLOFT COMMON */

/* IART:      IART = 1   PLOTFT/SCURV,.........,PARAM,.... */
/*            IART = 2   PLOTFT/SCURV,.........,FLOW ,.... */
/*            IART = 3   PLOTFT/SSURF,UCONST,U,........... */
/*            IART = 4   PLOTFT/SSURF,VCONST,V,........... */
/*            IART = 5   PLOTFT/SSURF,GRID,............... */
/*            IART = 6   GOLOFT/SSURF,UCONST,U,........... */
/*            IART = 7   GOLOFT/SSURF,VCONST,V,........... */

/* INVERS:    INVERSION OF THE POINT-SEQUENCE */

/*  BLANK-COMMON */

/*   POINT STORAGE FOR TRANSFORMATION PURPOSE */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*   VECTOR STORAGE FOR TRANSFORMATION PURPOSE */

/*  OUTPUT-ARRAY OF THE HEADER */


/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*  SYSTEM - INPUT/OUTPUT-NAMES */

/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*  STORAGE OF POINTS */

/* ...                SYSTEM I/O FILES */




/*  MOTION DIRECTIONS (LATER RETRACT POINT), CLEAR POINT */



    /* Parameter adjustments */
    --spv;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* .... INITIALIZE CHARACTER ITEMS FOR EXFILE RECORD */

    if (first) {
	for (i__ = 1; i__ <= 9; ++i__) {
	    imodf[(i__ << 1) - 2] = bcdf_(cmodf + (i__ - 1 << 3), (ftnlen)4);
	    imodf[(i__ << 1) - 1] = bcdf_(cmodf + ((i__ - 1 << 3) + 4), (
		    ftnlen)4);
/* L5: */
	}
	ileit[0] = bcdf_("CLDA", (ftnlen)4);
	ileit[1] = bcdf_("TA  ", (ftnlen)4);
	irapi[0] = bcdf_("RAPI", (ftnlen)4);
	irapi[1] = bcdf_("D   ", (ftnlen)4);
	ifedr[0] = bcdf_("FEDR", (ftnlen)4);
	ifedr[1] = bcdf_("AT  ", (ftnlen)4);
	iblnk = bcdf_("    ", (ftnlen)4);
	irapi[8] = iblnk;
	irapi[9] = iblnk;
	first = FALSE_;
    }

/*  SET FLAG FOR GLOBAL FEED */
    cclear_1.ifeedf = 0;

/*  SAVE CL-FLAG */
    icls = ifxcor_1.icl;

/*  RETRACT AND FEEDRAT ONLY FOR GOLOFT */
    if (*iart <= 5) {
	goto L90;
    }

/*  EXTRA MOTION IF FLAG IS ONE */
    if (cclear_1.iretro[*lseg - 1] == 0) {
	goto L90;
    }

/*  COMPUTE THE POINT IF PLUNGE IN MOTION */
    if (*invers == 0 && (*lseg == 1 || *lseg == 3) || *invers == 1 && (*lseg 
	    == 2 || *lseg == 4)) {
	gop_(&c__1, u, v, &spv[1], j11, iret);
    }

/*  CALCULATION OF MOTION DIRECTION */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L9: */
	dm[i__ - 1] = 0.;
    }
    if (cclear_1.idirmo[*lseg - 1] != 1) {
	goto L20;
    }
    iwo = 8;
    if (*iart == 7) {
	iwo = 4;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	dm[i__ - 1] = spv[iwo + i__];
    }

/*  LENGTH OF MOTION DIRECTION */
    vll = sqrt(dm[0] * dm[0] + dm[1] * dm[1] + dm[2] * dm[2]);
/*  INVERT LENGTH IF MOTION DIRECTION IS INVERS */
    if (*invers == 1) {
	vll = -vll;
    }
/*  NORMALIZE MOTION DIRECTION */
    for (i__ = 1; i__ <= 3; ++i__) {
	dm[i__ - 1] /= vll;
/* L11: */
	vt[i__ - 1] = dm[i__ - 1];
    }

/*  CALCULATE EXTRA MOTION */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L12: */
	dm[i__ - 1] = dm[i__ - 1] * cclear_1.dirmot[*lseg * 3 - 3] + spv[i__ 
		+ 28] * cclear_1.dirmot[*lseg * 3 - 2];
    }
    goto L30;

/*  VECTOR MOTION */
L20:
    if (cclear_1.idirmo[*lseg - 1] != 2) {
	goto L30;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L22: */
	dm[i__ - 1] = cclear_1.dirmot[i__ + *lseg * 3 - 4];
    }

/*  COMPUTE STEP IN OR RETRACT POINT */
L30:
    vll = 1.;
    if (*invers == 1) {
	vll = -1.;
    }
    if (*invers == 0 && (*lseg == 1 || *lseg == 3) || *invers == 1 && (*lseg 
	    == 2 || *lseg == 4)) {
	vll = -vll;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L32: */
	dm[i__ - 1] = spv[i__ + 32] + dm[i__ - 1] * vll;
    }

/*  COMPUTE CLEARENCE POSITION */
    if (cclear_1.icanin[*lseg - 1] == 0) {
	goto L45;
    }

/*  COMPUTE POINT DISTANCE */
    vll = _BLNK__1.com[cclear_1.icanin[*lseg - 1] - 1] * dm[0] + _BLNK__1.com[
	    cclear_1.icanin[*lseg - 1]] * dm[1] + _BLNK__1.com[
	    cclear_1.icanin[*lseg - 1] + 1] * dm[2] - _BLNK__1.com[
	    cclear_1.icanin[*lseg - 1] + 2];

/*  COMPUTE CLEAR POINT ON CLEAR PLANE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	cp[i__ - 1] = dm[i__ - 1] - _BLNK__1.com[cclear_1.icanin[*lseg - 1] + 
		i__ - 2] * vll;
    }
L45:

/*  DECISION IF STEP IN OR STEP OUT */
    if (*invers == 0 && (*lseg == 2 || *lseg == 4) || *invers == 1 && (*lseg 
	    == 1 || *lseg == 3)) {
	goto L70;
    }

/*  STEP IN ****************************** */
    if (cclear_1.icanin[*lseg - 1] == 0) {
	goto L55;
    }

/*   RAPID */
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    irapi[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, rapid, &j, &ir);

/*   CLEAR POINT */
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[7];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = 3;

/*  STORING TOOL AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L50: */
	vt[i__ - 1] = spv[i__ + 36];
    }
    transm_(fxcor_1.ta, vt, &c__3, &c__3, &c__0);

/*  STORING TOOL TIP */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
/* L51: */
	pt[i__ - 1] = cp[i__ - 1];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
    atape_();

/* NEAR POINT ? */
L55:
    if (cclear_1.idirmo[*lseg - 1] == 0) {
	goto L90;
    }

/*   RAPID */
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    irapi[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, rapid, &j, &ir);

/*  NEAR POINT */
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[8];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = 3;

/*  STORING TOOL AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L61: */
	vt[i__ - 1] = spv[i__ + 36];
    }
    transm_(fxcor_1.ta, vt, &c__3, &c__3, &c__0);

/*  STORING TOOL TIP */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
/* L62: */
	pt[i__ - 1] = dm[i__ - 1];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
    atape_();

/* FEDRATE FOR NEAR POINT */
    if (cclear_1.gofeed[*lseg - 1] == 0.) {
	goto L90;
    }
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ifedr[3] = ifxcor_1.iseqno;
    fedrat[4] = cclear_1.gofeed[*lseg - 1];
    ewrite_(&symfil_1.exfile, &nr, fedrat, &j, &ir);

/*  SET FLAG FOR GLOBAL FEEDRAT OUTPUT IN >GOP< */
    if (icls == 2) {
	cclear_1.ifeedf = 1;
    }

/*  CONTINUE WITH NORMAL PATH */
    goto L90;

/*  STEP OUT ******************************** */

/*  NEAR POINT ? */
L70:
    if (cclear_1.idirmo[*lseg - 1] == 0) {
	goto L80;
    }

/* FEDRATE FOR NEAR POINT */
    if (cclear_1.gofeed[*lseg - 1] == 0.) {
	goto L75;
    }
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ifedr[3] = ifxcor_1.iseqno;
    fedrat[4] = cclear_1.gofeed[*lseg - 1];
    ewrite_(&symfil_1.exfile, &nr, fedrat, &j, &ir);

/*  NEAR POINT */
L75:
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[8];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = 3;

/*  STORING TOOL AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L76: */
	vt[i__ - 1] = spv[i__ + 36];
    }
    transm_(fxcor_1.ta, vt, &c__3, &c__3, &c__0);

/*  STORING TOOL TIP */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
/* L77: */
	pt[i__ - 1] = dm[i__ - 1];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
    atape_();

/*  FEDRAT FOR NORMAL GOLOFT */
    if (cclear_1.gofeed[*lseg - 1] == 0. || *lseg == 2 || *lseg == 3) {
	goto L80;
    }
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    ifedr[3] = ifxcor_1.iseqno;
    fedrat[4] = cclear_1.glfeed;
    ewrite_(&symfil_1.exfile, &nr, fedrat, &j, &ir);

/*  CLEAR POINT */
L80:
    if (cclear_1.icanin[*lseg - 1] == 0) {
	goto L99;
    }

/*   RAPID */
    nr = 0;
    j = 10;
    record_(&ifxcor_1.iseqno);
    irapi[3] = ifxcor_1.iseqno;
    ewrite_(&symfil_1.exfile, &nr, rapid, &j, &ir);

/*   CLEAR POINT */
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[7];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = 3;

/*  STORING TOOL AXIS */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tak[i__ - 1] = fxcor_1.ta[i__ - 1];
/* L81: */
	vt[i__ - 1] = spv[i__ + 36];
    }
    transm_(fxcor_1.ta, vt, &c__3, &c__3, &c__0);

/*  STORING TOOL TIP */
    for (i__ = 1; i__ <= 3; ++i__) {
	fxcor_1.tek[i__ - 1] = fxcor_1.te[i__ - 1];
/* L82: */
	pt[i__ - 1] = cp[i__ - 1];
    }
    transm_(fxcor_1.te, pt, &c__2, &c__3, &c__0);
    atape_();
    goto L99;

/*  OUTPUT OF THE HEADER */
L90:
    if (*invers == 0 && (*lseg == 2 || *lseg == 4) || *invers == 1 && (*lseg 
	    == 1 || *lseg == 3)) {
	goto L99;
    }
    nr = 0;
    j = 18;
    record_(&ileit[3]);
    ifxcor_1.iseqno = ileit[3];
    leit[4] = modf[*iart - 1];
    leit[6] = plgol_1.obnam1;
    ewrite_(&symfil_1.exfile, &nr, leit, &j, &ir);
    ifxcor_1.icl = icls;

L99:
    return 0;
} /* goretr_ */

#undef invers
#undef fedrat
#undef obname
#undef bcanon
#undef sscan
#undef ileit
#undef irapi
#undef rapid
#undef imodf
#undef canon
#undef ifedr
#undef sinl
#undef cosl
#undef iart
#undef leit
#undef modf
#undef can
#undef vt1
#undef pt1
#undef vt
#undef pt


