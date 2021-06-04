/* GOLOVO.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer id[26];
} plgol_;

#define plgol_1 plgol_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__5157 = 5157;

/* *** SOURCE FILE : M0012236.V02   *** */

/* Subroutine */ int golovo_(doublereal *adress)
{
    /* Initialized data */

    static char uconst[6] = "UCONST";
    static char vconst[6] = "VCONST";
    static char start[6] = "START ";
    static char thru[6] = "THRU  ";
    static char at[6] = "AT    ";
    static char to[6] = "TO    ";
    static char on[6] = "ON    ";
    static char past[6] = "PAST  ";
    static char param[6] = "PARAM ";
    static char flow[6] = "FLOW  ";
    static char rincr[6] = "INCR  ";
    static char chord[6] = "CHORD ";
    static char rmiror[6] = "MIRROR";
    static char rinvrs[6] = "INVERS";
    static char rlengt[6] = "LENGTH";
    static doublereal rlw = 21.;
    static logical first = TRUE_;

    /* System generated locals */
    doublereal d__1;
    static doublereal equiv_6[1];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k;
#define vl ((doublereal *)&plgol_1 + 4)
#define nu ((integer *)&plgol_1 + 10)
#define nv ((integer *)&plgol_1 + 11)
#define can ((doublereal *)&_BLNK__1 + 40)
#define uva ((doublereal *)&plgol_1 + 1)
#define uve ((doublereal *)&plgol_1 + 2)
#define tol ((doublereal *)&plgol_1 + 3)
#define iat ((integer *)&plgol_1 + 17)
    static integer nwd;
    extern /* Subroutine */ int gol_(doublereal *);
#define ipl1 ((integer *)&plgol_1 + 20)
#define ipl2 ((integer *)&plgol_1 + 21)
    extern integer bcdf_(char *, ftnlen);
    static doublereal hmod;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define incr ((integer *)&plgol_1 + 16)
#define iart ((integer *)&plgol_1 + 12)
#define cosl ((doublereal *)&tlldat_1 + 16)
#define jart ((integer *)&plgol_1 + 17)
    static integer icur;
#define sinl ((doublereal *)&tlldat_1 + 8)
#define word (equiv_6)
    static char test[6];
    extern /* Subroutine */ int apt234_(doublereal *, doublereal *);
    extern logical ckdef_(doublereal *);
#define iscan ((integer *)&plgol_1 + 22)
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define iword ((integer *)equiv_6)
#define ithru ((integer *)&plgol_1 + 19)
#define istrt ((integer *)&plgol_1 + 18)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
#define normal ((integer *)&plgol_1 + 15)
#define invers ((integer *)&plgol_1 + 13)
#define mirror ((integer *)&plgol_1 + 14)
#define uvcons ((doublereal *)&plgol_1)


/* ...  1.MAIN CDE PACKAGE. INCLUDED IN EVERY PROGRAM IN THE SUBROUTINE */
/* ...    LIBRARY. */



/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */



/*   *** 12.  ISV BLOCK  *** */

/*   INTEGER SURFACE VARIABLES */







/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */






/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/* UVCONS: U-, V- CONSTANTS, GIVEN BY "UCONST,U" OR "VCONST,V" */
/*    UVA: START PARAMETER GIVEN BY "START,S" */
/*    UVE: END PARAMETER GIVEN BY "THRU,T" */
/*    TOL: INCREMENTS BY "INCR,I", ERROR OF CHORD BY "CHORD,C" */
/*     VL: LENGTH-PARAMETER GIVEN BY "LENGTH,L" */
/*     NU: AMOUNT OF INTERMEDIATE LINES IN DIRECTION    UCONST */
/*     NV: AMOUNT OF INTERMEDIATE LINES IN DIRECTION    VCONST */
/* IART:      IART = 1   PLOTFT/SCURV,.........,PARAM,.... */
/*            IART = 2   PLOTFT/SCURV,.........,FLOW ,.... */
/*            IART = 3   PLOTFT/SSURF,UCONST,U,........... */
/*            IART = 4   PLOTFT/SSURF,VCONST,V,........... */
/*            IART = 5   PLOTFT/SSURF,GRID,............... */
/*            IART = 6   GOLOFT/SSURF,UCONST,U,........... */
/*            IART = 7   GOLOFT/SSURF,VCONST,V,........... */
/* INVERS: INVERT THE TRAVEL DIRECTION IF =1 */
/* MIRROR: INVERT NORMAL DIRECTION IF =1 */
/* NORMAL: TAKE THE SURFACE NORMAL AS TOOL AXIS IF =1 */
/*   INCR: =1 IF "INCR,I", =0 IF "CHORD,C" GIVEN */
/*           CURVATURE CALCULATION NECESSARY IF NOT =1 */
/*    IAT: IAT   = 0 AT NOT PROGRAMMED */
/*         IAT   = 1 AT   "AT,A",        = 2 AT   "AT,TO,PL1" */
/*         IAT   = 3 AT   "AT,ON,PL1,    = 4 AT   "AT,PAST,PL1 */
/*  ISTRT: ISTRT = 0 START NOT PROGRAMMED */
/*         ISTRT = 1 AT   "START,A",     = 2 AT   "START,TO,PL1" */
/*         ISTRT = 3 AT   "START,ON,PL1, = 4 AT   "START,PAST,PL1 */
/*  ITHRU: ITHRU = 0 THRU NOT PROGRAMMED */
/*         ITHRU = 1 AT   "THRU,A",      = 2 AT   "THRU,TO,PL1" */
/*         ITHRU = 3 AT   "THRU,ON,PL1,  = 4 AT   "THRU,PAST,PL1 */
/*   IPL1: CF-BEGIN OF THE "AT" OR "START" PLANE IN THE ARRAY SSCAN */
/*   IPL2: CF-BEGIN OF THE "THRU" PLANE IN THE ARRAY SSCAN */
/*  ISCAN: FIRST FREE LOCATION IN SSCAN AFTER GOLOFT DATA */



    /* Parameter adjustments */
    --adress;

    /* Function Body */

    if (first) {
	iword[0] = bcdf_("TO  ", (ftnlen)4);
	iword[1] = bcdf_("    ", (ftnlen)4);
	hmod = *word;
	first = FALSE_;
    }

    if (ckdef_(&adress[1])) {
	goto L170;
    }
/*  INITIALIZE PART SURFACE */
    ifxcor_1.is = ifxcor_1.ips;
    apt234_(&hmod, &adress[1]);
    uva[0] = -1e30;
    *uve = 1e30;
    *tol = .05f;
/*  USE OF MAXDP/DPMAX,... AS DEFAULT */
    *vl = fxcor_1.dpmax;
    *nu = -1;
    *nv = -1;
    for (i__ = 14; i__ <= 22; ++i__) {
/* L1: */
	plgol_1.id[i__ - 1] = 0;
    }
    *incr = 1;
    if (fxcor_1.gamma != 0. || ifxcor_1.numax != 1) {
	goto L5;
    }
    if (abs(fxcor_1.alp) == 0.) {
	*normal = isv_1.jtlflg[ifxcor_1.ips - 1];
    }
L5:
    *iart = (integer) sscan[0];
    *iscan = (integer) sscan[1];
    switch (*iart) {
	case 1:  goto L45;
	case 2:  goto L45;
	case 3:  goto L20;
	case 4:  goto L20;
	case 5:  goto L30;
	case 6:  goto L10;
	case 7:  goto L10;
    }
L10:
    holfrm_(&sscan[*iscan - 4], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, rlengt, (ftnlen)6, (ftnlen)6) != 0) {
	goto L20;
    }
    *vl = sscan[*iscan - 2];
    *iscan += -4;
L20:
    *uvcons = sscan[8];
    icur = 11;
    goto L50;

L30:
    icur = 9;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, uconst, (ftnlen)6, (ftnlen)6) != 0) {
	goto L40;
    }
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    *nu = 1;
    if (sscan[icur - 2] != rlw) {
	goto L40;
    }
    *nu = (d__1 = sscan[icur - 1], (integer) abs(d__1));
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
L40:
    if (s_cmp(test, vconst, (ftnlen)6, (ftnlen)6) != 0) {
	goto L140;
    }
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    *nv = 1;
    if (sscan[icur - 2] != rlw) {
	goto L140;
    }
    *nv = (d__1 = sscan[icur - 1], (integer) abs(d__1));
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    goto L140;

L45:
    icur = 7;
L50:
    if (icur >= *iscan) {
	goto L160;
    }
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    if (s_cmp(test, at, (ftnlen)6, (ftnlen)6) != 0) {
	goto L60;
    }
    k = 1;
    goto L80;
L60:
    if (s_cmp(test, start, (ftnlen)6, (ftnlen)6) != 0) {
	goto L70;
    }
    k = 2;
    goto L80;
L70:
    if (s_cmp(test, thru, (ftnlen)6, (ftnlen)6) != 0) {
	goto L120;
    }
    k = 3;

L80:
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    jart[k - 1] = 1;
    if (sscan[icur - 2] != rlw) {
	goto L90;
    }
    uva[k / 3] = sscan[icur - 1];
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    goto L110;
L90:
    if (s_cmp(test, to, (ftnlen)6, (ftnlen)6) == 0) {
	jart[k - 1] = 2;
    }
    if (s_cmp(test, on, (ftnlen)6, (ftnlen)6) == 0) {
	jart[k - 1] = 3;
    }
    if (s_cmp(test, past, (ftnlen)6, (ftnlen)6) == 0) {
	jart[k - 1] = 4;
    }
    icur += 2;
    if (ckdef_(&sscan[icur - 1])) {
	goto L170;
    }
    plgol_1.id[k / 3 + 20] = icur;
    icur += 5;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
L110:
    if (k == 2) {
	goto L70;
    }

L120:
    if (icur > *iscan) {
	goto L160;
    }
    if (s_cmp(test, param, (ftnlen)6, (ftnlen)6) == 0 || s_cmp(test, flow, (
	    ftnlen)6, (ftnlen)6) == 0) {
	icur += 2;
	holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    }
    if (s_cmp(test, rinvrs, (ftnlen)6, (ftnlen)6) != 0) {
	goto L130;
    }
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    *invers = 1;
L130:
    if (s_cmp(test, rmiror, (ftnlen)6, (ftnlen)6) != 0) {
	goto L140;
    }
    icur += 2;
    holfrm_(&sscan[icur - 1], test, &c__1, &c__6, &nwd, (ftnlen)6);
    *mirror = 1;

L140:
    if (s_cmp(test, rincr, (ftnlen)6, (ftnlen)6) == 0) {
	goto L150;
    }
    if (s_cmp(test, chord, (ftnlen)6, (ftnlen)6) != 0) {
	goto L160;
    }
    *incr = 0;
L150:
    *tol = sscan[icur + 1];

L160:
    if (*iart != 5) {
	goto L161;
    }
    if (*nu != -1 || *nv != -1) {
	goto L161;
    }
    *nu = 0;
    *nv = 0;
L161:
    gol_(&adress[1]);
    return 0;
L170:
    aerr_(&c__5157, "GOLOVO  ", (ftnlen)8);
    ifxcor_1.iaerr = 1;
    return 0;
} /* golovo_ */

#undef uvcons
#undef mirror
#undef invers
#undef normal
#undef bcanon
#undef istrt
#undef ithru
#undef iword
#undef sscan
#undef canon
#undef iscan
#undef word
#undef sinl
#undef jart
#undef cosl
#undef iart
#undef incr
#undef ipl2
#undef ipl1
#undef iat
#undef tol
#undef uve
#undef uva
#undef can
#undef nv
#undef nu
#undef vl


