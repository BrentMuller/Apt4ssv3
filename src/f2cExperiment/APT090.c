/* APT090.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__65 = 65;
static integer c__66 = 66;
static integer c__1 = 1;
static integer c__8 = 8;
static integer c__2 = 2;
static integer c__67 = 67;
static integer c__63 = 63;
static integer c__64 = 64;

/* *** SOURCE FILE : M0002774.V05   *** */


/* ...  FORTRAN SUBROUTINE               APT090    3/69      SR */

/*              FORTRAN SUBROUTINE APT090 */

/* PURPOSE      TO GENERATE THE EXTERNAL CANONICAL FORM FOR A SURFACE */
/*              DEFINED AS A PATERN  AND WRITE IT ON PERIPHERAL STORAGE */

/* LINKAGE      CALL APT090(MM,RESULT,KLL,ARG1,ARG2,ARG3,ARG4,ARG5) */

/* ARGUMENTS    MM      BCANON INDEX OF ARRAY IN WHICH GENERATED */
/*                      EXTERNAL CANONICAL FORM IS TO BE STORED */
/*              RESULT  ARRAY CONTAINING THE INTERNAL CANONICAL FORM OF */
/*                      THE SURFACE */
/*              KLL     PATERN  SUBTYPE CODE AND DEFINITION FORMAT */
/*                      INDICATOR, K = SUBTYPE CODE, LL = DEFINITION */
/*                      FORMAT NUMBER */
/*                      K=1,LINEAR,   =2,CIRCULAR,  =3,GRID, */
/*                       =4,RANDOM,   =5,PERIPHERAL */
/*              ARG1    ONE-TO-ONE REPRESENTATION IN E.L. EQUIVALENT */
/*              THROUGH OF PATERN DEFINITION STATEMENT AS SPECIFIED BY */
/*              ARG5    PART PROGRAM EXCEPT FOR RANDOM PATERN WHERE */
/*                      ARG1 = NUMBER OF POINTS AND/OR PATERNS SPECIFIED */
/*                      IN DEFINITION STATEMENT */

/* SUBSIDIARIES TYPE                ENTRY */

/*              SUBROUTINE          APT094 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          UNDEF */
/*              SUBROUTINE          VNORM */

/* Subroutine */ int apt090_(integer *mm, doublereal *result, integer *kll, 
	doublereal *arg1, doublereal *arg2, doublereal *arg3, doublereal *
	arg4, doublereal *arg5)
{
    /* Initialized data */

    static doublereal d360 = 360.;
    static char at[8] = "AT      ";
    static char c__[8] = "CLW     ";
    static char pat[8] = "ZPATRN  ";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double d_mod(doublereal *, doublereal *);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, m, ll, jj;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer nwd, mmm;
    static doublereal diff, barg[110];
    static integer necf, ninc, ilim;
    static doublereal sinc;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static char test[8];
    static doublereal size;
    static integer icvt;
    static doublereal save;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    ;
    extern logical ckdef_(doublereal *);
    static doublereal enang;
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int undef_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int error_(integer *, char *, ftnlen), vnorm_(
	    doublereal *, doublereal *);
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal dirvec[3];
    extern /* Subroutine */ int holfrm_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen);
    static integer ndlist;
    static doublereal pntcnt;




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --arg5;
    --arg4;
    --arg2;
    --arg1;
    --result;

    /* Function Body */

/*     BRANCH ON PATERN SUBTYPE CODE */
    k = *kll / 100;
    switch (k) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L300;
    }

/*     LINEAR PATERN , STORE SUBTYPE CODE */
L100:
    bcanon[*mm] = znumbr_1.z1;

/*     C.F. EXISTS FOR STARTING POINT */
    if (ckdef_(&arg1[1])) {
	goto L1300;
    }
/*     YES, STORE COORDS. OF STARTING POINT */
    for (i__ = 1; i__ <= 3; ++i__) {
	ll = *mm + 3 + i__;
/* L101: */
	bcanon[ll - 1] = arg1[i__];
    }
/*     BRANCH ON DEFINITION FORMAT NUMBER */
    k = *kll - 100;
    switch (k) {
	case 1:  goto L105;
	case 2:  goto L110;
	case 3:  goto L125;
    }
/*     DEFN. BY STARTING,ENDING AND NO. OF PTS.,C.F. EXISTS FOR END PT. */
L105:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
/*     YES, COMPUTE DIFFERENCE VECTOR,NORMALIZE AND STORE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L106: */
	dirvec[i__ - 1] = arg2[i__] - arg1[i__];
    }
    vnorm_(dirvec, dirvec);
    goto L112;
/*     DEFN. BY POINT, VECTOR AND NO. OF PTS.,C.F. EXISTS FOR VECTOR */
L110:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
    vnorm_(&arg2[1], dirvec);
L112:
    if (ifxcor_1.ier <= 0) {
	goto L116;
    } else {
	goto L114;
    }
L114:
    error_(&c__65, "APT090  ", (ftnlen)8);
    goto L1300;
L116:
    for (i__ = 1; i__ <= 3; ++i__) {
	ll = *mm + 6 + i__;
/* L117: */
	bcanon[ll - 1] = dirvec[i__ - 1];
    }
    if (*arg3 <= 0.) {
	goto L118;
    } else {
	goto L120;
    }
L118:
    error_(&c__66, "APT090  ", (ftnlen)8);
    goto L1300;
/*     STORE NO.OF POINTS IN PATERN */
L120:
    bcanon[*mm + 2] = *arg3;
/*     COMPUTE INCREMENTAL SPACING AND SET UP INCR LIST */

    sinc = fxcor_1.vtem / (*arg3 - znumbr_1.z1);
    if (k == knumbr_1.k2) {
	sinc = fxcor_1.vtem;
    }
    ninc = (integer) (bcanon[*mm + 2] + znumbr_1.z1em5 - znumbr_1.z1);
    i__1 = ninc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ll = *mm + 9 + i__;
/* L122: */
	bcanon[ll - 1] = sinc;
    }
/*     SAVE FINAL BCANON INDEX */
    necf = ll;
/*     SIZE OF E.C.F.= FINAL BCANON INDEX MINUS INITIAL BCANON INDEX */
/*     STORE IN E.C.F. AND I.C.F. */
    size = (doublereal) (necf - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    goto L1200;
/*     DEFN. BY POINT, VECTOR AND INCR. LIST, C.F. EXISTS FOR VECTOR */
L125:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
    vnorm_(&arg2[1], dirvec);
/* L127: */
    if (ifxcor_1.ier <= 0) {
	goto L130;
    } else {
	goto L128;
    }
L128:
    error_(&c__65, "APT090  ", (ftnlen)8);
    goto L1300;
/*     STORE COMPONENTS OF NORMALIZED VECTOR AND PROCESS INCR LIST DATA */
L130:
    for (i__ = 1; i__ <= 3; ++i__) {
	ll = *mm + 6 + i__;
/* L132: */
	bcanon[ll - 1] = dirvec[i__ - 1];
    }

/*     INITIALIZE BCANON INDEX FOR STORAGE OF INCREMENTS */
    j = *mm + knumbr_1.k10;
    goto L1010;
/*     RETURN FROM INCR LIST PROCESSING */
/*     COMPUTE AND STORE SIZE OF E.C.F. AND NO. OF PTS. */
L135:
    size = (doublereal) (necf - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    bcanon[*mm + 2] = size - 8.f;
    goto L1200;
/*     CIRCULAR PATERN, STORE SUBTYPE CODE */
L200:
    bcanon[*mm] = znumbr_1.z2;
/*     C.F. EXISTS FOR SPECIFIED CIRCLE */
    if (ckdef_(&arg1[1])) {
	goto L1300;
    }
/*     YES, STORE COORDS. OF CIRCLE CENTER AND CIRCLE RADIUS */
    for (i__ = 1; i__ <= 3; ++i__) {
	ll = *mm + 3 + i__;
/* L202: */
	bcanon[ll - 1] = arg1[i__];
    }
    if (ldef_1.zflag) {
	goto L201;
    }
    bcanon[*mm + 5] = znumbr_1.z0;
    if (def_1.ref[4] == znumbr_1.z0) {
	goto L201;
    }
    bcanon[*mm + 5] = (def_1.ref[6] - def_1.ref[0] * bcanon[*mm + 3] - 
	    def_1.ref[2] * bcanon[*mm + 4]) / def_1.ref[4];
L201:
    bcanon[*mm + 6] = arg1[7];

/*     STORE STARTING ANGLE - IF GREATER THAN 360, REDUCE MOD 360, */
/*     IF NEGATIVE, CHANGE TO POSITIVE */

    bcanon[*mm + 7] = arg2[1];
    if ((d__1 = bcanon[*mm + 7], abs(d__1)) < d360) {
	goto L206;
    }
/* L204: */
    bcanon[*mm + 7] = d_mod(&bcanon[*mm + 7], &d360);
L206:
    if (bcanon[*mm + 7] >= 0.) {
	goto L210;
    } else {
	goto L208;
    }
L208:
    bcanon[*mm + 7] += d360;

/*     BRANCH ON DEFN FORMAT NUMBER */
L210:
    k = *kll - 200;
    switch (k) {
	case 1:  goto L215;
	case 2:  goto L250;
    }

/*     DEFN BY STARTING AND ENDING ANGLES AND NUMBER OF PTS. */
/*     STORE DIRECTION OF GENERATION,  +1.0 FOR CCLW, -1.0 FOR CLW */

L215:
    holfrm_(&arg4[1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, c__, (ftnlen)8, (ftnlen)8) == 0) {
	goto L217;
    }
/*     ASSUME CCLW */
    bcanon[*mm + 8] = znumbr_1.z1;
    goto L218;
L217:
    bcanon[*mm + 8] = znumbr_1.zm1;

/*     USE   SPECIFIED ENDING ANGLE AS EQUIV. POSITIVE ANGLE, MOD 360 */
L218:
    enang = *arg3;
    if (abs(enang) < d360) {
	goto L222;
    }
/* L220: */
    enang = d_mod(&enang, &d360);
L222:
    if (enang >= 0.) {
	goto L226;
    } else {
	goto L224;
    }
L224:
    enang += d360;

/*     ADJUST COMPUTED DIFFERENCE BETWEEN ENDING AND STARTING ANGLES */
/*     TO BE COMPATIBLE WITH SPECIFIED DIRECTION OF GENERATION */

L226:
    diff = enang - bcanon[*mm + 7];
    if (diff < 0.) {
	goto L228;
    } else if (diff == 0) {
	goto L232;
    } else {
	goto L234;
    }
L228:
    if (bcanon[*mm + 8] == znumbr_1.z1) {
	goto L236;
    }
/* L230: */
    diff = abs(diff);
    goto L238;
L232:
    diff = d360;
    goto L238;
L234:
    if (bcanon[*mm + 8] == znumbr_1.z1) {
	goto L238;
    }
L236:
    diff = d360 - abs(diff);

L238:
    if (arg5[1] >= 0.) {
	goto L242;
    } else {
	goto L240;
    }
L240:
    error_(&c__66, "APT090  ", (ftnlen)8);
    goto L1300;
/*     STORE NUMBER OF PTS. IN PATERN */
L242:
    bcanon[*mm + 2] = arg5[1];

/*     COMPUTE INCREMENTAL SPACING AND SET UP INCR LIST */

    sinc = diff / (arg5[1] - znumbr_1.z1);
    ninc = (integer) (bcanon[*mm + 2] + znumbr_1.z1em5 - znumbr_1.z1);
    i__1 = ninc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ll = *mm + 9 + i__;
/* L244: */
	bcanon[ll - 1] = sinc;
    }
/*     SAVE FINAL BCANON INDEX */
    necf = ll;
/*     SIZE OF E.C.F. = FINAL INDEX MINUS INITIAL INDEX */
/*     STORE IN E.C.F. AND I.C.F. */
    size = (doublereal) (necf - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    goto L1200;

/*     DEFN BY STARTING ANGLE AND INCREMENT LIST */
/*     STORE DIRECTION OF GENERATION, +1.0 FOR CCLW, -1.0 FOR CLW */

L250:
    holfrm_(arg3, test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, c__, (ftnlen)8, (ftnlen)8) == 0) {
	goto L252;
    }
/*     ASSUME CCLW */
    bcanon[*mm + 8] = znumbr_1.z1;
    goto L254;
L252:
    bcanon[*mm + 8] = znumbr_1.zm1;
/*     INITIALIZE BCANON INDEX FOR STORAGE OF INCREMENTS */
L254:
    j = *mm + knumbr_1.k10;
    goto L1020;

/*     RETURN FROM INCR LIST PROCESSING */
/*     COMPUTE AND STORE SIZE OF E.C.F. AND NO. OF PTS. */
L255:
    size = (doublereal) (necf - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    bcanon[*mm + 2] = size - 8.f;
    goto L1200;
/*     GRID OR PERIPHERAL PATERN STORE RELATED SUBTYPE CODE */
L300:
    bcanon[*mm] = znumbr_1.z3;
    if (k == knumbr_1.k5) {
	bcanon[*mm] = znumbr_1.z5;
    }

/*     C.F. EXISTS FOR FIRST PATERN */
/* L302: */
    if (ckdef_(&arg1[1])) {
	goto L1300;
    }
/*     YES, RETRIEVE E.C.F. AND STORE IN BCANON */

    apt094_(&c__2, &arg1[1], &bcanon[*mm + 2]);
/*     RETRIEVAL O.K. */
    if (ckdef_(&arg1[1])) {
	goto L1300;
    }

/*     YES - PATERN IS LINEAR */
    if (bcanon[*mm + 3] == znumbr_1.z1) {
	goto L306;
    }
/* L304: */
    error_(&c__67, "APT090  ", (ftnlen)8);
    goto L1300;
/*     COMPUTE BCANON INDEX FOR STORAGE OF SECOND PATERN,INITIAL VALUE=M */
L306:
    icvt = (integer) (bcanon[*mm + 5] + znumbr_1.z1em5);
    m = *mm + icvt + knumbr_1.k12;
/*     BRANCH ON DEFINITION FORMAT INDICATOR */
    i__ = *kll - k * 100;
    switch (i__) {
	case 1:  goto L310;
	case 2:  goto L320;
	case 3:  goto L340;
    }
/*     DEFINITION BY TWO LINEAR PATERNS, C.F. EXISTS FOR SECOND PATERN */
L310:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
/*     YES - RETRIEVE AND STORE IN BCANON */
    save = bcanon[m - 2];
    apt094_(&c__2, &arg2[1], &bcanon[m - 2]);
    bcanon[m - 2] = save;
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
/*     IS THIS PATERN LINEAR */
    if (bcanon[m - 1] == znumbr_1.z1) {
	goto L314;
    }
/* L312: */
    error_(&c__67, "APT090  ", (ftnlen)8);
    goto L1300;
/*     YES, TRANSLATE ORIGIN OF SECOND PATERN TO THAT OF FIRST PATERN */
L314:
    for (i__ = 1; i__ <= 3; ++i__) {
	jj = m + 2 + i__;
	ll = *mm + 6 + i__;
/* L316: */
	bcanon[jj - 1] = bcanon[ll - 1];
    }

/*     COMPUTE AND STORE E.C.F. SIZE */
    size = bcanon[*mm + 5] + bcanon[m + 1] + 19.f;
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    goto L357;
/*     DEFINITION BY PATERN,VECTOR, AND NO. OF ROWS OR COLUMNS */
L320:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
    vnorm_(&arg2[1], dirvec);
    if (ifxcor_1.ier <= 0) {
	goto L324;
    } else {
	goto L322;
    }
L322:
    error_(&c__65, "APT090  ", (ftnlen)8);
    goto L1300;
/*     SET SUBTYPE CODE = 1 FOR SECOND PATERN AND SET ORIGIN SAME AS */
/*     THAT OF FIRST PATERN, STORE COMPONENTS OF NORMALIZED VECTOR */
L324:
    bcanon[m - 1] = znumbr_1.z1;
    for (i__ = 1; i__ <= 3; ++i__) {
	jj = m + 2 + i__;
	ll = *mm + 6 + i__;
/* L326: */
	bcanon[jj - 1] = bcanon[ll - 1];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	jj = m + 5 + i__;
/* L328: */
	bcanon[jj - 1] = dirvec[i__ - 1];
    }
    if (*arg3 <= 0.) {
	goto L330;
    } else {
	goto L332;
    }
L330:
    error_(&c__63, "APT090  ", (ftnlen)8);
    goto L1300;
/*     STORE NO. OF PTS. IN PATERN */
L332:
    bcanon[m + 1] = *arg3;
/*        COMPUTE AND STORE ECF SIZE FOR SECOND PATERN */
    bcanon[m] = bcanon[m + 1] + 8.f;
/*     COMPUTE INCREMENTAL SPACING AND SET UP INCR LIST */
    sinc = fxcor_1.vtem;
    ninc = (integer) (bcanon[m + 1] + znumbr_1.z1em5 - znumbr_1.z1);
    i__1 = ninc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = m + 8 + i__;
/* L334: */
	bcanon[jj - 1] = sinc;
    }
/*     SAVE FINAL BCANON INDEX */
    necf = jj;
/*     COMPUTE AND STORE E.C.F. SIZE */
    size = (doublereal) (necf - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    goto L357;
/*     DEFN. BY PATERN, VECTOR, AND INCR LIST */
L340:
    if (ckdef_(&arg2[1])) {
	goto L1300;
    }
    vnorm_(&arg2[1], dirvec);
    if (ifxcor_1.ier <= 0) {
	goto L344;
    } else {
	goto L342;
    }
L342:
    error_(&c__65, "APT090  ", (ftnlen)8);
    goto L1300;
/*     STORE FOR SECOND PATERN - SUBTYPE CODE,COORDS. OF ORIGIN AND */
/*     COMPONENTS OF NORMALIZED VECTOR */
L344:
    bcanon[m - 1] = znumbr_1.z1;
    for (i__ = 1; i__ <= 3; ++i__) {
	jj = m + 2 + i__;
	ll = *mm + 6 + i__;
/* L346: */
	bcanon[jj - 1] = bcanon[ll - 1];
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	jj = m + 5 + i__;
/* L348: */
	bcanon[jj - 1] = dirvec[i__ - 1];
    }
/*     INITIALIZE BCANON INDEX FOR STORAGE OF INCREMENTS */
    j = m + 9;
    goto L1010;
/*     RETURN FROM INCR LIST PROCESSING - COMPUTE AND STORE NO. OF PTS. */
/*     AND SIZE OF SECOND PATERN */
L355:
    size = (doublereal) (necf - *mm);
    bcanon[m + 1] = size - bcanon[*mm + 5] - 19.f;
    bcanon[m] = bcanon[m + 1] + 8.f;
/*     STORE SIZE OF E.C.F. */
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
/*     COMPUTE NO. OF PTS.IN PATERN BEING DEFINED BASED ON */
/*     PATERN SUBTYPE */
L357:
    if (bcanon[*mm] == znumbr_1.z5) {
	goto L359;
    }
/*     PATERN IS GRID */
    bcanon[*mm + 2] = bcanon[*mm + 5] * bcanon[m + 1];
    goto L1200;

/*     PATERN IS PERIPHERAL */
L359:
    bcanon[*mm + 2] = znumbr_1.z2 * (bcanon[*mm + 5] + bcanon[m + 1]) - 4.f;
    goto L1200;

/*     RANDOM PATERN, STORE SUBTYPE CODE */

L400:
    bcanon[*mm] = 4.f;
/*        CHECK FOR DEFINITION OF REQUIRED POINTS AND PATTERNS */
    if (bcanon[*mm - 1] < 0.f) {
	goto L1300;
    }
/*     INITIALIZE COUNTER FOR NUMBER OF PTS. IN RANDOM PATERN */
    pntcnt = znumbr_1.z0;
/*     INITIALIZE POINTER TO FIRST ELEMENT OF POINT OR PATERN DATA */
/*     BEING PROCESSED - THIS POINTER WILL BE ADVANCED IN SCANNING */
/*     THE RANDOM PATERN E.C.F. WHICH HAS BEEN STORED IN BCANON */
    j = *mm + knumbr_1.k4;

/*     INITIALIZE DATA SET COUNTER */
    i__ = knumbr_1.k1;

/*     ARG1 IS NUMBER OF DATA SETS, THAT IS, NUMBER OF PTS. AND/OR */
/*     PATERNS SPECIFIED IN RANDOM PATERN DEFN STATEMENT */
    ilim = (integer) arg1[1];
/*     IS DATA FOR POINT OR PATERN */

L405:
    holfrm_(&bcanon[j - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, pat, (ftnlen)8, (ftnlen)8) == 0) {
	goto L415;
    }
/*        INCREMENT POINT COUNTER AND ADVANCE J TO NEXT DATA SET */
    pntcnt += knumbr_1.k1;
    j += knumbr_1.k4;
    goto L420;
/*     UPDATE POINT COUNTER AND ADVANCE J TO NEXT DATA SET */
L415:
    pntcnt += bcanon[j + 2];
    icvt = (integer) (bcanon[j + 1] + znumbr_1.z1em5);
    j = j + icvt + knumbr_1.k1;

/*     HAVE ALL DATA SETS BEEN PROCESSED */
L420:
    if (i__ == ilim) {
	goto L425;
    }
    i__ += knumbr_1.k1;
    goto L405;

/*     COMPUTE AND STORE E.C.F. SIZE AND NUMBER OF PTS. IN PATERN */
L425:
    size = (doublereal) (j - knumbr_1.k1 - *mm);
    bcanon[*mm + 1] = size;
    result[2] = size + znumbr_1.z1;
    bcanon[*mm + 2] = pntcnt;
    goto L1200;
/*     TRANSFER INCREMENT LIST TO LOCAL WORKING STORAGE */
/*     NDLIST IS INDEX FOR END OF INCREMENT LIST DATA */

/*     SET UP FOR LINEAR,GRID,OR PERIPHERAL */
L1010:
    barg[0] = arg4[1];
    ndlist = (integer) barg[0];
    ndlist += knumbr_1.k1;
    i__1 = ndlist;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L1011: */
	barg[i__ - 1] = arg4[i__];
    }
    goto L1099;

/*     SET UP FOR CIRCULAR */
L1020:
    barg[0] = arg5[1];
    ndlist = (integer) barg[0];
    ndlist += knumbr_1.k1;
    i__1 = ndlist;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L1021: */
	barg[i__ - 1] = arg5[i__];
    }

/*     BEGIN PROCESSING INCR. LIST DATA - LOGIC ASSUMES MIN(NDLIST) = 3 */

L1099:
    i__ = 2;
L1100:
    if (barg[i__ - 1] <= 0.) {
	goto L1160;
    } else {
	goto L1101;
    }
L1101:
    ++i__;
    if (i__ - ndlist >= 0) {
	goto L1145;
    } else {
	goto L1105;
    }
L1105:
    holfrm_(&barg[i__ - 1], test, &c__1, &c__8, &nwd, (ftnlen)8);
    if (s_cmp(test, at, (ftnlen)8, (ftnlen)8) != 0) {
	goto L1135;
    }

/* L1110: */
    ++i__;
    if (barg[i__ - 1] <= 0.) {
	goto L1160;
    } else {
	goto L1115;
    }

/*     INCR. LIST DATA OF FORM - N AT I */

L1115:
    ninc = (integer) barg[i__ - 3];
    mmm = j + ninc - 1;
    ll = j - 1;
    i__1 = mmm;
    for (jj = j; jj <= i__1; ++jj) {
	++ll;
/* L1120: */
	bcanon[jj - 1] = barg[i__ - 1];
    }
    j = ll;
/*     IS THAT ALL */
    if (i__ - ndlist >= 0) {
	goto L1125;
    } else {
	goto L1130;
    }
/*     YES - INCR LIST PROCESSING IS DONE, SAVE FINAL BCANON INDEX */
L1125:
    necf = j;
    goto L1150;
/*     NO - CONTINUE LIST PROCESSING */
L1130:
    ++i__;
    ++j;

/*     END INCR LIST PROCESSING NOW */
    if (i__ - ndlist >= 0) {
	goto L1131;
    } else {
	goto L1100;
    }
L1131:
    if (barg[i__ - 1] <= 0.) {
	goto L1160;
    } else {
	goto L1132;
    }
L1132:
    bcanon[j - 1] = barg[i__ - 1];
    necf = j;
    goto L1150;
/*     INCR LIST DATA OF FORM NUMBER,NUMBER,NUMBER OR NUMBER,NUMBER,AT */

L1135:
    if (barg[i__ - 1] <= 0.) {
	goto L1160;
    } else {
	goto L1140;
    }
L1140:
    bcanon[j - 1] = barg[i__ - 2];
    ++j;
    goto L1101;

/*     END PROCESSING OF INCR LIST DATA OF FORM NUMBER,NUMBER */
/*     SAVE FINAL BCANON INDEX */
L1145:
    bcanon[j - 1] = barg[i__ - 2];
    bcanon[j] = barg[i__ - 1];
    necf = j + 1;
/*     COMPLETE  E.C.F. BASED ON KLL CODE */
L1150:
    k = *kll / 100;
    switch (k) {
	case 1:  goto L135;
	case 2:  goto L255;
	case 3:  goto L355;
	case 4:  goto L1300;
	case 5:  goto L355;
    }
L1160:
    error_(&c__64, "APT090  ", (ftnlen)8);
    goto L1300;

/*     WRITE E.C.F. ONTO PERIPHERAL STORAGE */

L1200:
    apt094_(&c__1, &result[1], &bcanon[*mm - 1]);
    goto L1310;
L1300:
    undef_(&result[1]);
L1310:
    return 0;
} /* apt090_ */

#undef bcanon
#undef sscan
#undef canon
#undef sinl
#undef cosl
#undef can


