/* APT102.f -- translated by f2c (version 20100827).
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
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal sbond0, sbond[9];
    integer mmode, icon;
    doublereal pts[20];
    integer jag;
} ssbond_;

#define ssbond_1 ssbond_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;

/* *** SOURCE FILE : M0001150.V06   *** */

/* Subroutine */ int apt102_(doublereal *boundn, doublereal *surfn, 
	doublereal *hsmod, integer *m)
{
    /* Initialized data */

    static char xposx[8] = "POSX    ";
    static char xposy[8] = "POSY    ";
    static char xnegx[8] = "NEGX    ";
    static char xnegy[8] = "NEGY    ";
    static char xin[8] = "IN      ";
    static char xout[8] = "OUT     ";
    static char xseg[8] = "SEG     ";

    /* System generated locals */
    static doublereal equiv_4[11], equiv_5[1], equiv_15[10];

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define a (equiv_15)
#define b (equiv_15 + 1)
#define c__ (equiv_15 + 2)
#define d__ (equiv_15 + 9)
#define f (equiv_15 + 3)
#define g (equiv_15 + 4)
#define h__ (equiv_15 + 5)
    static integer n;
#define p (equiv_15 + 6)
#define q (equiv_15 + 7)
#define r__ (equiv_15 + 8)
#define ia ((integer *)equiv_5)
    static integer ie, ii;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal hhh;
    static integer jjj, nwd, ity;
#define coef (equiv_15)
    static integer mode, isub;
    static logical err85, err86;
    static char test[8];
    static integer izro;
    extern /* Subroutine */ int apt003_(doublereal *, doublereal *, 
	    doublereal *), apt004_(doublereal *, integer *, doublereal *, 
	    doublereal *), apt005_(doublereal *, integer *, doublereal *, 
	    doublereal *);
#define canon ((doublereal *)&_BLNK__1)
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isize;
#define ttest (equiv_5)
#define resul0 (equiv_4)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int unpack_(doublereal *, integer *, integer *, 
	    integer *), holfrm_(doublereal *, char *, integer *, integer *, 
	    integer *, ftnlen);
#define result (equiv_4 + 1)
    extern /* Subroutine */ int sycurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */





/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */




/*      DIMENSION BOUNDN(1),SURFN(1),X(1),HSMOD(3),COEF(10) */

/*                                                                   *CD* */
    /* Parameter adjustments */
    --hsmod;
    --surfn;
    --boundn;

    /* Function Body */
    hhh = surfn[1];
    holfrm_(&hhh, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, xseg, (ftnlen)8, (ftnlen)8) == 0) {
	goto L400;
    }
    jjj = 4;
    if (ldef_1.boundf) {
	goto L1;
    }
    ldef_1.boundf = TRUE_;
L1:
    if (*m != 1) {
	goto L2;
    }
    ssbond_1.jag = 0;
    ie = 1;
    n = 0;
    ssbond_1.sbond0 = surfn[n];
    err85 = FALSE_;
    err86 = FALSE_;
    for (ii = 1; ii <= 8; ++ii) {
/* L200: */
	ssbond_1.sbond[ii - 1] = surfn[ii];
    }
    izro = 0;
    ssbond_1.icon = 0;
L2:
    hhh = hsmod[1];
    holfrm_(&hhh, test, &c__1, &c__8, &nwd, (ftnlen)8);
    ++ssbond_1.jag;
    if (s_cmp(test, xposx, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(test, xout, (
	    ftnlen)8, (ftnlen)8) == 0) {
	ie = 1;
    }
    if (s_cmp(test, xposy, (ftnlen)8, (ftnlen)8) == 0) {
	ie = 2;
    }
    if (s_cmp(test, xnegx, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(test, xin, (
	    ftnlen)8, (ftnlen)8) == 0) {
	ie = 4;
    }
    if (s_cmp(test, xnegy, (ftnlen)8, (ftnlen)8) == 0) {
	ie = 5;
    }
    unpack_(&surfn[1], &mode, &isize, &isub);
    jjj = 1;
    if (*m == 1) {
	ssbond_1.mmode = mode;
    }
    if (*m == 1) {
	goto L97;
    }
    resul0[0] = 1.903e7;
    if (ssbond_1.mmode == 1 && mode == 1) {
	goto L210;
    }
    if (ssbond_1.mmode == 4 && mode == 1) {
	goto L220;
    }
    if (ssbond_1.mmode == 4 && mode == 4) {
	goto L230;
    }
    if (ssbond_1.mmode == 1 && mode == 4) {
	goto L240;
    }
    goto L97;
L210:
    apt003_(result, ssbond_1.sbond, &surfn[1]);
    goto L300;
L220:
    apt004_(result, &ie, &surfn[1], ssbond_1.sbond);
    goto L300;
L230:
    apt005_(result, &ie, ssbond_1.sbond, &surfn[1]);
    goto L300;
L240:
    apt004_(result, &ie, ssbond_1.sbond, &surfn[1]);
L300:
    jjj = 3;
    ssbond_1.pts[ssbond_1.icon] = result[0];
    ssbond_1.pts[ssbond_1.icon + 1] = result[1];
    ssbond_1.pts[ssbond_1.icon + 2] = result[2];
    ssbond_1.icon += 3;
    goto L97;
L400:
    ity = 1;
/*  ABFRAGE OB KREISDEFINITION (MMODE=4) */
    if (ssbond_1.mmode == 4) {
	ity = 0;
    }
    sycurv_(&boundn[1], ssbond_1.pts, ssbond_1.sbond, &ity);
L97:
    return 0;
} /* apt102_ */

#undef result
#undef bcanon
#undef resul0
#undef ttest
#undef sscan
#undef canon
#undef coef
#undef can
#undef ia
#undef r__
#undef q
#undef p
#undef h__
#undef g
#undef f
#undef d__
#undef c__
#undef b
#undef a


