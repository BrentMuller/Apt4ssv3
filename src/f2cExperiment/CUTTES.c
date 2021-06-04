/* CUTTES.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

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
    integer iaerfg;
} aercom_;

#define aercom_1 aercom_

struct {
    integer jhldfg, ithcnt, itabh[100];
} hold_;

#define hold_1 hold_

struct {
    doublereal saveh[50];
} hsave_;

#define hsave_1 hsave_

/* Table of constant values */

static integer c__1 = 1;
static integer c_b39 = -22207;
static integer c_b59 = -22211;
static integer c_b99 = -22216;

/* *** SOURCE FILE : M0002827.W01   *** */


/* ...  FORTRAN SUBROUTINE               CUTTER */
/* Subroutine */ int cutter_(integer *nmbr, doublereal *prm)
{
    extern /* Subroutine */ int libsrevert_(void);
    static logical flg;
    extern /* Subroutine */ int apt241_(void), cuttes_(integer *, doublereal *
	    , logical *);


/* -VAX.... MODIFICATION TO PERMIT RESTART PROCEDURE USING */
/* -VAX     VAX CONDITION HANDLING FACILITIES */
    flg = FALSE_;
/* .... ESTABLISH CONDITION HANDLER FRO AERR ERROR */
    apt241_();
L1:
    cuttes_(nmbr, prm, &flg);
    if (flg) {
	goto L1;
    }
/* .... REVERT TO DEFAULT CONDITION HANDLER */
/*      CALL LIB$REVERT */
    libsrevert_();
    return 0;
} /* cutter_ */


/* Subroutine */ int cuttes_(integer *nmbr, doublereal *prm, logical *flg)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer i__, j, kk, jj;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt299_();
#define param ((doublereal *)&hsave_1 + 5)
    static integer hcuter[2];
#define number ((integer *)&hsave_1 + 28)
    extern /* Subroutine */ int tlconv_(void);
    static integer numerr;




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */








/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/*     25.   COMMON FOR AERR INFORMATION */


/*     ----------------------------------------------------------- */


/* ...  DEFINES CUTTER SHAPE AND SETS UP TOOL DATA BLOCKS */
    /* Parameter adjustments */
    --prm;

    /* Function Body */
    hcuter[0] = bcdf_("CUTT", (ftnlen)4);
    hcuter[1] = bcdf_("ER  ", (ftnlen)4);
    if (*flg) {
	goto L9990;
    }
    *flg = TRUE_;
    for (i__ = 1; i__ <= 9; ++i__) {
/* L500: */
	param[i__ - 1] = prm[i__];
    }
    *number = *nmbr;
    if (hold_1.jhldfg == 0) {
	goto L501;
    }
    hold_1.itabh[hold_1.ithcnt - 1] = 5;
    ++hold_1.ithcnt;
    return 0;

L501:
L105:
    ifxcor_1.ictdef = knumbr_1.k1;
/* ...  ZERO CUTTER PARAMETER STORAGE AREA */
    for (j = 1; j <= 7; ++j) {
/* L110: */
	fxcor_1.cutdat[j - 1] = znumbr_1.z0;
    }
    fxcor_1.cutdat[6] = fxcor_1.tlhit;
    if (*number - knumbr_1.k7 <= 0) {
	goto L126;
    } else {
	goto L125;
    }
L125:
    numerr = 22201;
    goto L1000;
L126:
    i__1 = *number;
    for (j = 1; j <= i__1; ++j) {
/* L127: */
	fxcor_1.cutdat[j - 1] = param[j - 1];
    }
/*  WRITE CUTTER STATEMENT ON EXFILE */
    apt299_(number, hcuter, &c__1, param);
    if (*number <= 1) {
	goto L129;
    }
    kk = 1;
    i__1 = *number;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	if (i__ == *number) {
	    kk = 0;
	}
/* L128: */
	apt299_(&c__1, &param[i__ - 1], &kk, &param[i__]);
    }

/*  PLACE ZEROES IN TLLDAT BLOCK */

L129:
    for (i__ = 1; i__ <= 8; ++i__) {
	tlldat_1.tlhite[i__ - 1] = znumbr_1.z0;
	sinl[i__ - 1] = znumbr_1.z0;
	cosl[i__ - 1] = znumbr_1.z0;
	tlldat_1.umax[i__ - 1] = znumbr_1.z0;
	tlldat_1.ri[i__ - 1] = znumbr_1.z0;
	tlldat_1.corrad[i__ - 1] = znumbr_1.z0;
	tlldat_1.tcont[i__] = znumbr_1.z0;
	tlldat_1.tlinc[i__] = znumbr_1.z0;
/* L1: */
    }
/*  MAKE SURE TOOL DIAMETER NOT LESS THAN ZERO */
    if (fxcor_1.cutdat[0] < 0.) {
	goto L2;
    } else if (fxcor_1.cutdat[0] == 0) {
	goto L92;
    } else {
	goto L3;
    }
L2:
    numerr = 22202;
    goto L1000;
/*  EXAMINE TOOL HEIGHT. IF LESS THAN ZERO ERROR. SET TO 5 IF = ZERO. */
/*  OKAY OTHERWISE */
L3:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L5;
    } else {
	goto L6;
    }
L4:
    numerr = 22203;
    goto L1000;
L5:
/*  SUM OF ANGLES A AND B MUST BE LESS THAN 90 DEGREES */
L6:
    if (znumbr_1.z90 - fxcor_1.cutdat[4] - fxcor_1.cutdat[5] <= 0.) {
	goto L7;
    } else {
	goto L8;
    }
L7:
    numerr = 22204;
    goto L1000;
L8:
    tlldat_1.ri[5] = znumbr_1.z5em1 * fxcor_1.cutdat[0];
    fxcor_1.cutdat[0] = tlldat_1.ri[5];
/*  ERROR IF ANGLE A NEGATIVE */
    if (fxcor_1.cutdat[4] < 0.) {
	goto L9;
    } else if (fxcor_1.cutdat[4] == 0) {
	goto L10;
    } else {
	goto L11;
    }
L9:
    numerr = 22205;
    goto L1000;
L10:
    cosl[1] = znumbr_1.z1;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L12;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR A GREATER THAN ZERO */
L11:
    tlldat_1.tlhite[7] = znumbr_1.degrad * fxcor_1.cutdat[4];
    sinl[1] = sin(tlldat_1.tlhite[7]);
    cosl[1] = cos(tlldat_1.tlhite[7]);
    tlldat_1.tcont[1] = sinl[1] / cosl[1];
    tlldat_1.tlhite[5] = tlldat_1.tcont[1] * tlldat_1.ri[5];
    tlldat_1.tanhi[0] = znumbr_1.z1 / tlldat_1.tcont[1];
/*  MAKE SURE HEIGHT OF BOTTOM LINE SEGMENT DOES NOT EXCEED TOOL HEIGHT */
L12:
    if (znumbr_1.z1em5 - (d__1 = fxcor_1.cutdat[6] - tlldat_1.tlhite[5], abs(
	    d__1)) <= 0.) {
	goto L13;
    } else {
	goto L15;
    }
L13:
    if (fxcor_1.cutdat[6] - tlldat_1.tlhite[5] <= 0.) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    numerr = 22206;
    goto L1000;
L15:
    tlldat_1.tlhite[5] = fxcor_1.cutdat[6];
/*  ERROR IF ANGLE B NEGATIVE */
L16:
    ifxcor_1.ipt1 = knumbr_1.k1;
    if (fxcor_1.cutdat[5] < 0.) {
	goto L17;
    } else if (fxcor_1.cutdat[5] == 0) {
	goto L18;
    } else {
	goto L19;
    }
/*                    BELL SHAPED CUTTER */
L17:
    aerr_(&c_b39, "CUTTER  ", (ftnlen)8);
    goto L19;
L18:
    sinl[5] = znumbr_1.z1;
    goto L20;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR B GREATER THAN ZERO */
L19:
    tlldat_1.tanhi[7] = znumbr_1.degrad * fxcor_1.cutdat[5];
    sinl[5] = cos(tlldat_1.tanhi[7]);
    cosl[5] = sin(tlldat_1.tanhi[7]);
    tlldat_1.tanlo[6] = cosl[5] / sinl[5];
/*  FURTHER CALCULATIONS */
L20:
    tlldat_1.umax[1] = tlldat_1.ri[5] / cosl[1];
    tlldat_1.umax[5] = (fxcor_1.cutdat[6] - tlldat_1.tlhite[5]) / sinl[5];
    tlldat_1.ri[6] = tlldat_1.ri[5] + cosl[5] * tlldat_1.umax[5];
    tlldat_1.tcont[2] = znumbr_1.z1;
    tlldat_1.tcont[6] = znumbr_1.z1;
/*  EXAMINE TOOL RADIUS. IF GREATER THAN ZERO, CORNER CIRCLE WILL BE PART */
/*  OF TOOL CONFIGURATION. IF = ZERO, TOOL WILL CONSIST ONLY OF LINE AND */
/*  POINT CIRCLE SEGMENTS. ERROR IF NEGATIVE. */
    if (fxcor_1.cutdat[1] < 0.) {
	goto L21;
    } else if (fxcor_1.cutdat[1] == 0) {
	goto L22;
    } else {
	goto L25;
    }
L21:
    numerr = 22208;
    goto L1000;
/*  COMPARE LENGTH OF UPPER LINE SEGMENT TO ZERO. SET VALUES IN TLLDAT */
/*  BLOCK ACCORDINGLY */
L22:
    if (tlldat_1.umax[5] <= 0.) {
	goto L23;
    } else {
	goto L24;
    }
L23:
    tlldat_1.tanlo[6] = tlldat_1.tanhi[0];
    tlldat_1.tcont[6] = znumbr_1.z0;
    goto L87;
L24:
    tlldat_1.tlhite[3] = tlldat_1.tlhite[5];
    tlldat_1.ri[3] = tlldat_1.ri[5];
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
    goto L86;
/*  COMPUTE CENTER OF CORNER CIRCLE */
L27:
    fxcor_1.cutdat[2] = tlldat_1.ri[5] - tlldat_1.corrad[3];
    fxcor_1.cutdat[3] = tlldat_1.corrad[3];
    goto L26;
/*  STORE RADIUS OF CORNER CIRCLE AND COMPUTE DISTANCE FROM CENTER OF */
/*  CIRCLE TO BOTTOM LINE (UMAX(3)) */
L25:
    tlldat_1.corrad[3] = fxcor_1.cutdat[1];
L26:
    tlldat_1.umax[2] = fxcor_1.cutdat[3] * cosl[1] - fxcor_1.cutdat[2] * sinl[
	    1];
    tlldat_1.tanlo[0] = fxcor_1.cutdat[2] * fxcor_1.cutdat[2] + 
	    fxcor_1.cutdat[3] * fxcor_1.cutdat[3];
/*  IF = 0, CENTER OF CORNER CIRCLE HAS TO BE CALCULATED */
    if (tlldat_1.tanlo[0] + fxcor_1.cutdat[4] + fxcor_1.cutdat[5] * 
	    fxcor_1.cutdat[5] != 0.) {
	goto L28;
    } else {
	goto L27;
    }
/*  DISTANCE FROM CENTER OF CIRCLE TO INTERSECTION OF LINE SEGMENTS */
L28:
    tlldat_1.umax[0] = sqrt((fxcor_1.cutdat[2] - tlldat_1.ri[5]) * (
	    fxcor_1.cutdat[2] - tlldat_1.ri[5]) + (fxcor_1.cutdat[3] - 
	    tlldat_1.tlhite[5]) * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]));
    tlldat_1.umax[6] = tlldat_1.tanlo[6] * (fxcor_1.cutdat[6] - 
	    tlldat_1.tlhite[5]);
/*  DISTANCE FROM CENTER OF CIRCLE TO UPPER END OF UPPER LINE SEGMENT */
    tlldat_1.umax[3] = sqrt((fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) * (
	    fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) + (fxcor_1.cutdat[2] - 
	    tlldat_1.ri[6]) * (fxcor_1.cutdat[2] - tlldat_1.ri[6]));
/*  IF THE Y COORD. (F) OF THE CENTER OF THE CORNER CIRCLE IS LESS THAN */
/*  THE Y COORD. OF THE INTERSECTION OF THE LINES, THEN ERROR */
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] <= 0.) {
	goto L29;
    } else {
	goto L30;
    }
L29:
    numerr = 22209;
    goto L1000;
/*  IF THE RADIUS IS BOTH LARGER THAN THE DISTANCE TO THE INTERSECTION */
/*  OF THE LINES AND DIFFERENT THAN THE DISTANCE TO THE ORIGIN OF THE */
/*  BOTTOM LINE SEGMENT, WE HAVE AN INVALID TOOL CONFIGURATION */
L33:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.tanlo[0] - tlldat_1.corrad[3] * 
	    tlldat_1.corrad[3], abs(d__1)) <= 0.) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    numerr = 22210;
    goto L1000;
/*  IF E GREATER THAN ZERO, WE HAVE AN INVALID TOOL CONFIGURATION */
L35:
    if (fxcor_1.cutdat[2] < 0.) {
	goto L53;
    } else if (fxcor_1.cutdat[2] == 0) {
	goto L37;
    } else {
	goto L34;
    }
L53:
    aerr_(&c_b59, "CUTTER  ", (ftnlen)8);
    tlldat_1.tanhi[0] = fxcor_1.cutdat[3] / fxcor_1.cutdat[2];
    tlldat_1.tcont[1] = fxcor_1.cutdat[2] / fxcor_1.cutdat[3];
/*  NO LOWER LINE SEGMENT */
L54:
    tlldat_1.tcont[2] = znumbr_1.z0;
/*  FURTHER TLLDAT VARIABLES */
L55:
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
L56:
    tlldat_1.umax[4] = (tlldat_1.ri[5] - fxcor_1.cutdat[2]) * sinl[5] + cosl[
	    5] * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]);
/*  IF = 0, THERE IS NO UPPER LINE SEGMENT AND IN THIS CASE TOOL NO GOOD */
    if (tlldat_1.umax[5] != 0.) {
	goto L67;
    } else {
	goto L57;
    }
/*  IF GREATER THAN ZERO, RADIUS AND DISTANCE FROM CENTER OF CORNER */
/*  CIRCLE TO INTERSECTION OF LINES EQUAL. */
L67:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L68;
    } else {
	goto L62;
    }
L68:
    tlldat_1.tcont[7] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[4] * tlldat_1.umax[4];
/*  LENGTH OF UPPER LINE SEGMENT */
    tlldat_1.umax[5] = tlldat_1.umax[5] + sqrt((abs(tlldat_1.tcont[7]))) - 
	    sqrt(tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[4] * 
	    tlldat_1.umax[4]);
    tlldat_1.umax[7] = fxcor_1.cutdat[3] - fxcor_1.cutdat[6] - tlldat_1.tanlo[
	    6] * (tlldat_1.umax[6] + tlldat_1.ri[5] - fxcor_1.cutdat[2]);
    if (znumbr_1.z1em5 - abs(tlldat_1.umax[7]) <= 0.) {
	goto L72;
    } else {
	goto L69;
    }
L72:
    if (tlldat_1.umax[7] <= 0.) {
	goto L73;
    } else {
	goto L77;
    }
/*  IF GREATER THAN ZERO, UPPER LINE SEGMENT WITH CORNER CIRCLE TANGENT. */
/*  OTHERWISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN PT. CIRCLE */
L73:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L75;
    } else {
	goto L74;
    }
L75:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L76;
    } else {
	goto L83;
    }
L76:
    goto L41;
L57:
    numerr = 22212;
    goto L1000;
/*  WE MUST CHANGE PARAMETERS FOR BOTTOM POINT CIRCLE DUE TO NATURE OF */
/*  CORNER CIRCLE */
L37:
    aerr_(&c_b59, "CUTTER  ", (ftnlen)8);
    tlldat_1.tcont[1] = znumbr_1.z0;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L54;
/*  IF GREATER THAN OR EQUAL TO ZERO, CORNER CIRCLE IS A POINT CIRCLE */
L30:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[0], abs(
	    d__1)) >= 0.) {
	goto L31;
    } else {
	goto L32;
    }
L31:
    tlldat_1.corrad[3] = 0.f;
    tlldat_1.tanlo[0] = 0.f;
    tlldat_1.umax[0] = 0.f;
    tlldat_1.umax[2] = 0.f;
    tlldat_1.umax[3] = 0.f;
    tlldat_1.umax[6] = 0.f;
    fxcor_1.cutdat[1] = 0.f;
    fxcor_1.cutdat[2] = 0.f;
    fxcor_1.cutdat[3] = 0.f;
    goto L22;
L32:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L38;
    } else {
	goto L33;
    }
L38:
    if (tlldat_1.ri[5] + tlldat_1.tcont[1] * (tlldat_1.tlhite[5] - 
	    fxcor_1.cutdat[3]) - fxcor_1.cutdat[2] + znumbr_1.z1em5 <= 0.) {
	goto L39;
    } else {
	goto L40;
    }
/*  CORNER CIRCLE INTERSECTS LOWER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L39:
    numerr = 22213;
    goto L1000;
L40:
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] - 
	    tlldat_1.tanlo[6] * (tlldat_1.ri[5] - fxcor_1.cutdat[2]) <= 0.) {
	goto L41;
    } else {
	goto L42;
    }
/*  CORNER CIRCLE INTERSECTS UPPER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L41:
    numerr = 22214;
    goto L1000;
L42:
    tlldat_1.tanlo[2] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[2] * tlldat_1.umax[2];
    if (tlldat_1.tanlo[2] < znumbr_1.z0) {
	goto L39;
    }
/*  LENGTH OF LOWER LINE SEGMENT */
    tlldat_1.umax[1] = tlldat_1.umax[1] + sqrt(tlldat_1.tanlo[2]) - sqrt(
	    tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[2] * 
	    tlldat_1.umax[2]);
    tlldat_1.tanlo[7] = fxcor_1.cutdat[2] + tlldat_1.tcont[1] * 
	    fxcor_1.cutdat[3];
    if (abs(tlldat_1.tanlo[7]) - znumbr_1.z1em5 >= 0.) {
	goto L46;
    } else {
	goto L43;
    }
/*  IF GREATER THAN ZERO, PT. CIRCLE FOLLOWED BY CORNER CIRCLE OR JUST */
/*  CORNER CIRCLE. OTHERWISE PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. */
/*  CIRCLE, AND THEN CORNER CIRCLE */
L43:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L44;
    } else {
	goto L54;
    }
L44:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L45;
    } else {
	goto L50;
    }
L45:
    goto L39;
L46:
    if (tlldat_1.tanlo[7] >= 0.) {
	goto L47;
    } else {
	goto L51;
    }
/*  IF GREATER THAN ZERO,PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. CIR- */
/*  CLE, AND THEN CORNER CIRCLE. IF = 0, PT. CIRCLE AND CORNER CIRCLE. */
/*  ERROR LESS THAN ZERO */
L51:
    if ((d__1 = tlldat_1.corrad[3] * tlldat_1.corrad[3] - tlldat_1.tanlo[0]) <
	     0.) {
	goto L52;
    } else if (d__1 == 0) {
	goto L53;
    } else {
	goto L50;
    }
L52:
    goto L39;
/*  IF GREATER THAN ZERO, CORNER CIRCLE TANGENT TO LOWER LINE SEGMENT */
L47:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L48;
    } else {
	goto L55;
    }
L48:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L49;
    } else {
	goto L50;
    }
L49:
    goto L39;
/*  LOWER LINE SEGMENT, PT. CIRCLE, AND CORNER CIRCLE PARAMETER CALC. */
L50:
    tlldat_1.tcont[3] = sqrt(tlldat_1.tanlo[2]) / tlldat_1.umax[2];
    tlldat_1.tanhi[2] = (znumbr_1.z1 - tlldat_1.tcont[1] * tlldat_1.tcont[3]) 
	    / (tlldat_1.tcont[1] + tlldat_1.tcont[3]);
    tlldat_1.tlhite[2] = sinl[1] * tlldat_1.umax[1];
    tlldat_1.ri[2] = cosl[1] * tlldat_1.umax[1];
    tlldat_1.tanlo[2] = tlldat_1.tanhi[0];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[2];
    goto L56;
L62:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.umax[3] - tlldat_1.corrad[3], abs(
	    d__1)) <= 0.) {
	goto L63;
    } else {
	goto L64;
    }
L63:
    numerr = 22215;
    goto L1000;
/*  IF GREATER THAN ZERO, CORNER CIRCLE MEETS UPPER PT. CIRCLE AT UNAC- */
/*  CEPTABLE ANGLE. IF = 0 WE MUST CHANGE PARAMETERS FOR UPPER PT. CIRCLE */
L64:
    if ((d__1 = fxcor_1.cutdat[6] - fxcor_1.cutdat[3]) < 0.) {
	goto L78;
    } else if (d__1 == 0) {
	goto L66;
    } else {
	goto L63;
    }
L78:
    aerr_(&c_b99, "CUTTER  ", (ftnlen)8);
    tlldat_1.tanlo[6] = (fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) / (
	    tlldat_1.ri[5] + sinl[5] - fxcor_1.cutdat[2]);
L79:
    tlldat_1.tcont[6] = znumbr_1.z0;
/* L80: */
    tlldat_1.tanhi[3] = znumbr_1.z0;
    goto L85;
/*  NO UPPER LINE SEGMENT. CHANGE IN PARAMETERS FOR UPPER POINT CIRCLE */
/*  NECESSARY DUE TO NATURE OF CORNER CIRCLE */
L66:
    aerr_(&c_b99, "CUTTER  ", (ftnlen)8);
    tlldat_1.tanlo[6] = znumbr_1.z0;
    goto L79;
/*  IF GREATER THAN ZERO,CORNER CIRCLE AND THEN UPPER PT. CIRCLE. OTHER- */
/*  WISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN UPPER PT. CIRCLE */
L69:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L70;
    } else {
	goto L79;
    }
L70:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L71;
    } else {
	goto L83;
    }
L71:
    goto L41;
L74:
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    goto L84;
L77:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[3], abs(
	    d__1)) <= 0.) {
	goto L81;
    } else {
	goto L78;
    }
L81:
    if (tlldat_1.corrad[3] - tlldat_1.umax[3] <= 0.) {
	goto L82;
    } else {
	goto L83;
    }
L82:
    goto L41;
/*  FURTHER CALCULATIONS FOR TLLDAT BLOCK PARAMETERS */
L83:
    tlldat_1.tcont[5] = sqrt(tlldat_1.tcont[7]) / tlldat_1.umax[4];
    tlldat_1.tanhi[3] = (tlldat_1.tcont[5] + tlldat_1.tanlo[6]) / (
	    znumbr_1.z1 - tlldat_1.tcont[5] * tlldat_1.tanlo[6]);
    tlldat_1.tanlo[4] = tlldat_1.tanhi[3];
    tlldat_1.tanhi[4] = tlldat_1.tanlo[6];
L84:
    tlldat_1.ri[4] = tlldat_1.ri[6] - cosl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[4] = fxcor_1.cutdat[6] - sinl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[5] = tlldat_1.tlhite[4];
    tlldat_1.ri[5] = tlldat_1.ri[4];
L85:
    tlldat_1.tlhite[3] = fxcor_1.cutdat[3];
    tlldat_1.ri[3] = fxcor_1.cutdat[2];
L86:
    tlldat_1.tcont[4] = znumbr_1.z1;
L87:
    tlldat_1.tanlo[0] = znumbr_1.z1e38;
    tlldat_1.tlinc[2] = znumbr_1.z1;
    tlldat_1.tlinc[6] = znumbr_1.z1;
    tlldat_1.tlhite[6] = fxcor_1.cutdat[6];
/* L200: */
    ifxcor_1.ibegin = 1;
/*  WE NOW SEARCH EACH OF THE 7 POSSIBLE SEGMENTS TO DETERMINE FIRST ONE */
L91:
    if (tlldat_1.tcont[ifxcor_1.ibegin] != 0.) {
	goto L90;
    } else {
	goto L88;
    }
L90:
    tlldat_1.tcont[ifxcor_1.ibegin - 1] = -znumbr_1.z1;
    tlldat_1.tcont[8] = -znumbr_1.z1;
    tlldat_1.tcont[7] = znumbr_1.z1;
    tlldat_1.tanhi[6] = -znumbr_1.z1e38;
    tlldat_1.tanhi[7] = -znumbr_1.z1e38;
    tlldat_1.tanlo[7] = znumbr_1.z1e38;
    tlldat_1.tlinc[8] = znumbr_1.z0;
    tlldat_1.corrad[7] = znumbr_1.z0;
    ifxcor_1.ictdef = 0;
    ifxcor_1.iaerr = 0;
    tlconv_();
    goto L9999;
L88:
    ++ifxcor_1.ibegin;
    if (7 - ifxcor_1.ibegin >= 0) {
	goto L91;
    } else {
	goto L89;
    }
L89:
    numerr = 22217;
    goto L1000;
L92:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L93;
    } else {
	goto L10;
    }
L93:
    ifxcor_1.ipt1 = 0;
    tlldat_1.tanlo[6] = znumbr_1.z1e38;
    ifxcor_1.ibegin = 7;
    goto L90;

/*        ** CUTTER PARAMETER ERROR-CALL AERR AND DEFINE POINT CUTTER */

L1000:
    aercom_1.iaerfg = 1;
    ifxcor_1.ictdef = 0;
    aerr_(&numerr, "CUTTER  ", (ftnlen)8);
L9990:
    for (jj = 1; jj <= 7; ++jj) {
/* L1001: */
	param[jj - 1] = znumbr_1.z0;
    }
    *number = knumbr_1.k7;
    *flg = FALSE_;
    goto L105;
L9999:
    *flg = FALSE_;
    return 0;
} /* cuttes_ */

#undef number
#undef param
#undef sinl
#undef cosl






/* Subroutine */ int cutteh_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer i__, j, kk, jj;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt299_();
#define param ((doublereal *)&hsave_1 + 5)
    static integer hcuter[2];
#define number ((integer *)&hsave_1 + 28)
    extern /* Subroutine */ int tlconv_(void);
    static integer numerr;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */








/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/*     25.   COMMON FOR AERR INFORMATION */


/*     ----------------------------------------------------------- */


/* ...  DEFINES CUTTER SHAPE AND SETS UP TOOL DATA BLOCKS */
    hcuter[0] = bcdf_("CUTT", (ftnlen)4);
    hcuter[1] = bcdf_("ER  ", (ftnlen)4);

L105:
    ifxcor_1.ictdef = knumbr_1.k1;
/* ...  ZERO CUTTER PARAMETER STORAGE AREA */
    for (j = 1; j <= 7; ++j) {
/* L110: */
	fxcor_1.cutdat[j - 1] = znumbr_1.z0;
    }
    fxcor_1.cutdat[6] = fxcor_1.tlhit;
    if (*number - knumbr_1.k7 <= 0) {
	goto L126;
    } else {
	goto L125;
    }
L125:
    numerr = 22201;
    goto L1000;
L126:
    i__1 = *number;
    for (j = 1; j <= i__1; ++j) {
/* L127: */
	fxcor_1.cutdat[j - 1] = param[j - 1];
    }
/*  WRITE CUTTER STATEMENT ON EXFILE */
    apt299_(number, hcuter, &c__1, param);
    if (*number <= 1) {
	goto L129;
    }
    kk = 1;
    i__1 = *number;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	if (i__ == *number) {
	    kk = 0;
	}
/* L128: */
	apt299_(&c__1, &param[i__ - 1], &kk, &param[i__]);
    }

/*  PLACE ZEROES IN TLLDAT BLOCK */

L129:
    for (i__ = 1; i__ <= 8; ++i__) {
	tlldat_1.tlhite[i__ - 1] = znumbr_1.z0;
	sinl[i__ - 1] = znumbr_1.z0;
	cosl[i__ - 1] = znumbr_1.z0;
	tlldat_1.umax[i__ - 1] = znumbr_1.z0;
	tlldat_1.ri[i__ - 1] = znumbr_1.z0;
	tlldat_1.corrad[i__ - 1] = znumbr_1.z0;
	tlldat_1.tcont[i__] = znumbr_1.z0;
	tlldat_1.tlinc[i__] = znumbr_1.z0;
/* L1: */
    }
/*  MAKE SURE TOOL DIAMETER NOT LESS THAN ZERO */
    if (fxcor_1.cutdat[0] < 0.) {
	goto L2;
    } else if (fxcor_1.cutdat[0] == 0) {
	goto L92;
    } else {
	goto L3;
    }
L2:
    numerr = 22202;
    goto L1000;
/*  EXAMINE TOOL HEIGHT. IF LESS THAN ZERO ERROR. SET TO 5 IF = ZERO. */
/*  OKAY OTHERWISE */
L3:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L5;
    } else {
	goto L6;
    }
L4:
    numerr = 22203;
    goto L1000;
L5:
/*  SUM OF ANGLES A AND B MUST BE LESS THAN 90 DEGREES */
L6:
    if (znumbr_1.z90 - fxcor_1.cutdat[4] - fxcor_1.cutdat[5] <= 0.) {
	goto L7;
    } else {
	goto L8;
    }
L7:
    numerr = 22204;
    goto L1000;
L8:
    tlldat_1.ri[5] = znumbr_1.z5em1 * fxcor_1.cutdat[0];
    fxcor_1.cutdat[0] = tlldat_1.ri[5];
/*  ERROR IF ANGLE A NEGATIVE */
    if (fxcor_1.cutdat[4] < 0.) {
	goto L9;
    } else if (fxcor_1.cutdat[4] == 0) {
	goto L10;
    } else {
	goto L11;
    }
L9:
    numerr = 22205;
    goto L1000;
L10:
    cosl[1] = znumbr_1.z1;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L12;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR A GREATER THAN ZERO */
L11:
    tlldat_1.tlhite[7] = znumbr_1.degrad * fxcor_1.cutdat[4];
    sinl[1] = sin(tlldat_1.tlhite[7]);
    cosl[1] = cos(tlldat_1.tlhite[7]);
    tlldat_1.tcont[1] = sinl[1] / cosl[1];
    tlldat_1.tlhite[5] = tlldat_1.tcont[1] * tlldat_1.ri[5];
    tlldat_1.tanhi[0] = znumbr_1.z1 / tlldat_1.tcont[1];
/*  MAKE SURE HEIGHT OF BOTTOM LINE SEGMENT DOES NOT EXCEED TOOL HEIGHT */
L12:
    if (znumbr_1.z1em5 - (d__1 = fxcor_1.cutdat[6] - tlldat_1.tlhite[5], abs(
	    d__1)) <= 0.) {
	goto L13;
    } else {
	goto L15;
    }
L13:
    if (fxcor_1.cutdat[6] - tlldat_1.tlhite[5] <= 0.) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    numerr = 22206;
    goto L1000;
L15:
    tlldat_1.tlhite[5] = fxcor_1.cutdat[6];
/*  ERROR IF ANGLE B NEGATIVE */
L16:
    ifxcor_1.ipt1 = knumbr_1.k1;
    if (fxcor_1.cutdat[5] < 0.) {
	goto L17;
    } else if (fxcor_1.cutdat[5] == 0) {
	goto L18;
    } else {
	goto L19;
    }
/*                    BELL SHAPED CUTTER */
L17:
    aerr_(&c_b39, "CUTTEH  ", (ftnlen)8);
    goto L19;
L18:
    sinl[5] = znumbr_1.z1;
    goto L20;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR B GREATER THAN ZERO */
L19:
    tlldat_1.tanhi[7] = znumbr_1.degrad * fxcor_1.cutdat[5];
    sinl[5] = cos(tlldat_1.tanhi[7]);
    cosl[5] = sin(tlldat_1.tanhi[7]);
    tlldat_1.tanlo[6] = cosl[5] / sinl[5];
/*  FURTHER CALCULATIONS */
L20:
    tlldat_1.umax[1] = tlldat_1.ri[5] / cosl[1];
    tlldat_1.umax[5] = (fxcor_1.cutdat[6] - tlldat_1.tlhite[5]) / sinl[5];
    tlldat_1.ri[6] = tlldat_1.ri[5] + cosl[5] * tlldat_1.umax[5];
    tlldat_1.tcont[2] = znumbr_1.z1;
    tlldat_1.tcont[6] = znumbr_1.z1;
/*  EXAMINE TOOL RADIUS. IF GREATER THAN ZERO, CORNER CIRCLE WILL BE PART */
/*  OF TOOL CONFIGURATION. IF = ZERO, TOOL WILL CONSIST ONLY OF LINE AND */
/*  POINT CIRCLE SEGMENTS. ERROR IF NEGATIVE. */
    if (fxcor_1.cutdat[1] < 0.) {
	goto L21;
    } else if (fxcor_1.cutdat[1] == 0) {
	goto L22;
    } else {
	goto L25;
    }
L21:
    numerr = 22208;
    goto L1000;
/*  COMPARE LENGTH OF UPPER LINE SEGMENT TO ZERO. SET VALUES IN TLLDAT */
/*  BLOCK ACCORDINGLY */
L22:
    if (tlldat_1.umax[5] <= 0.) {
	goto L23;
    } else {
	goto L24;
    }
L23:
    tlldat_1.tanlo[6] = tlldat_1.tanhi[0];
    tlldat_1.tcont[6] = znumbr_1.z0;
    goto L87;
L24:
    tlldat_1.tlhite[3] = tlldat_1.tlhite[5];
    tlldat_1.ri[3] = tlldat_1.ri[5];
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
    goto L86;
/*  COMPUTE CENTER OF CORNER CIRCLE */
L27:
    fxcor_1.cutdat[2] = tlldat_1.ri[5] - tlldat_1.corrad[3];
    fxcor_1.cutdat[3] = tlldat_1.corrad[3];
    goto L26;
/*  STORE RADIUS OF CORNER CIRCLE AND COMPUTE DISTANCE FROM CENTER OF */
/*  CIRCLE TO BOTTOM LINE (UMAX(3)) */
L25:
    tlldat_1.corrad[3] = fxcor_1.cutdat[1];
L26:
    tlldat_1.umax[2] = fxcor_1.cutdat[3] * cosl[1] - fxcor_1.cutdat[2] * sinl[
	    1];
    tlldat_1.tanlo[0] = fxcor_1.cutdat[2] * fxcor_1.cutdat[2] + 
	    fxcor_1.cutdat[3] * fxcor_1.cutdat[3];
/*  IF = 0, CENTER OF CORNER CIRCLE HAS TO BE CALCULATED */
    if (tlldat_1.tanlo[0] + fxcor_1.cutdat[4] + fxcor_1.cutdat[5] * 
	    fxcor_1.cutdat[5] != 0.) {
	goto L28;
    } else {
	goto L27;
    }
/*  DISTANCE FROM CENTER OF CIRCLE TO INTERSECTION OF LINE SEGMENTS */
L28:
    tlldat_1.umax[0] = sqrt((fxcor_1.cutdat[2] - tlldat_1.ri[5]) * (
	    fxcor_1.cutdat[2] - tlldat_1.ri[5]) + (fxcor_1.cutdat[3] - 
	    tlldat_1.tlhite[5]) * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]));
    tlldat_1.umax[6] = tlldat_1.tanlo[6] * (fxcor_1.cutdat[6] - 
	    tlldat_1.tlhite[5]);
/*  DISTANCE FROM CENTER OF CIRCLE TO UPPER END OF UPPER LINE SEGMENT */
    tlldat_1.umax[3] = sqrt((fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) * (
	    fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) + (fxcor_1.cutdat[2] - 
	    tlldat_1.ri[6]) * (fxcor_1.cutdat[2] - tlldat_1.ri[6]));
/*  IF THE Y COORD. (F) OF THE CENTER OF THE CORNER CIRCLE IS LESS THAN */
/*  THE Y COORD. OF THE INTERSECTION OF THE LINES, THEN ERROR */
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] <= 0.) {
	goto L29;
    } else {
	goto L30;
    }
L29:
    numerr = 22209;
    goto L1000;
/*  IF THE RADIUS IS BOTH LARGER THAN THE DISTANCE TO THE INTERSECTION */
/*  OF THE LINES AND DIFFERENT THAN THE DISTANCE TO THE ORIGIN OF THE */
/*  BOTTOM LINE SEGMENT, WE HAVE AN INVALID TOOL CONFIGURATION */
L33:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.tanlo[0] - tlldat_1.corrad[3] * 
	    tlldat_1.corrad[3], abs(d__1)) <= 0.) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    numerr = 22210;
    goto L1000;
/*  IF E GREATER THAN ZERO, WE HAVE AN INVALID TOOL CONFIGURATION */
L35:
    if (fxcor_1.cutdat[2] < 0.) {
	goto L53;
    } else if (fxcor_1.cutdat[2] == 0) {
	goto L37;
    } else {
	goto L34;
    }
L53:
    aerr_(&c_b59, "CUTTEH  ", (ftnlen)8);
    tlldat_1.tanhi[0] = fxcor_1.cutdat[3] / fxcor_1.cutdat[2];
    tlldat_1.tcont[1] = fxcor_1.cutdat[2] / fxcor_1.cutdat[3];
/*  NO LOWER LINE SEGMENT */
L54:
    tlldat_1.tcont[2] = znumbr_1.z0;
/*  FURTHER TLLDAT VARIABLES */
L55:
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
L56:
    tlldat_1.umax[4] = (tlldat_1.ri[5] - fxcor_1.cutdat[2]) * sinl[5] + cosl[
	    5] * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]);
/*  IF = 0, THERE IS NO UPPER LINE SEGMENT AND IN THIS CASE TOOL NO GOOD */
    if (tlldat_1.umax[5] != 0.) {
	goto L67;
    } else {
	goto L57;
    }
/*  IF GREATER THAN ZERO, RADIUS AND DISTANCE FROM CENTER OF CORNER */
/*  CIRCLE TO INTERSECTION OF LINES EQUAL. */
L67:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L68;
    } else {
	goto L62;
    }
L68:
    tlldat_1.tcont[7] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[4] * tlldat_1.umax[4];
/*  LENGTH OF UPPER LINE SEGMENT */
    tlldat_1.umax[5] = tlldat_1.umax[5] + sqrt((abs(tlldat_1.tcont[7]))) - 
	    sqrt(tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[4] * 
	    tlldat_1.umax[4]);
    tlldat_1.umax[7] = fxcor_1.cutdat[3] - fxcor_1.cutdat[6] - tlldat_1.tanlo[
	    6] * (tlldat_1.umax[6] + tlldat_1.ri[5] - fxcor_1.cutdat[2]);
    if (znumbr_1.z1em5 - abs(tlldat_1.umax[7]) <= 0.) {
	goto L72;
    } else {
	goto L69;
    }
L72:
    if (tlldat_1.umax[7] <= 0.) {
	goto L73;
    } else {
	goto L77;
    }
/*  IF GREATER THAN ZERO, UPPER LINE SEGMENT WITH CORNER CIRCLE TANGENT. */
/*  OTHERWISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN PT. CIRCLE */
L73:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L75;
    } else {
	goto L74;
    }
L75:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L76;
    } else {
	goto L83;
    }
L76:
    goto L41;
L57:
    numerr = 22212;
    goto L1000;
/*  WE MUST CHANGE PARAMETERS FOR BOTTOM POINT CIRCLE DUE TO NATURE OF */
/*  CORNER CIRCLE */
L37:
    aerr_(&c_b59, "CUTTEH  ", (ftnlen)8);
    tlldat_1.tcont[1] = znumbr_1.z0;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L54;
/*  IF GREATER THAN OR EQUAL TO ZERO, CORNER CIRCLE IS A POINT CIRCLE */
L30:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[0], abs(
	    d__1)) >= 0.) {
	goto L31;
    } else {
	goto L32;
    }
L31:
    tlldat_1.corrad[3] = 0.f;
    tlldat_1.tanlo[0] = 0.f;
    tlldat_1.umax[0] = 0.f;
    tlldat_1.umax[2] = 0.f;
    tlldat_1.umax[3] = 0.f;
    tlldat_1.umax[6] = 0.f;
    fxcor_1.cutdat[1] = 0.f;
    fxcor_1.cutdat[2] = 0.f;
    fxcor_1.cutdat[3] = 0.f;
    goto L22;
L32:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L38;
    } else {
	goto L33;
    }
L38:
    if (tlldat_1.ri[5] + tlldat_1.tcont[1] * (tlldat_1.tlhite[5] - 
	    fxcor_1.cutdat[3]) - fxcor_1.cutdat[2] + znumbr_1.z1em5 <= 0.) {
	goto L39;
    } else {
	goto L40;
    }
/*  CORNER CIRCLE INTERSECTS LOWER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L39:
    numerr = 22213;
    goto L1000;
L40:
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] - 
	    tlldat_1.tanlo[6] * (tlldat_1.ri[5] - fxcor_1.cutdat[2]) <= 0.) {
	goto L41;
    } else {
	goto L42;
    }
/*  CORNER CIRCLE INTERSECTS UPPER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L41:
    numerr = 22214;
    goto L1000;
L42:
    tlldat_1.tanlo[2] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[2] * tlldat_1.umax[2];
    if (tlldat_1.tanlo[2] < znumbr_1.z0) {
	goto L39;
    }
/*  LENGTH OF LOWER LINE SEGMENT */
    tlldat_1.umax[1] = tlldat_1.umax[1] + sqrt(tlldat_1.tanlo[2]) - sqrt(
	    tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[2] * 
	    tlldat_1.umax[2]);
    tlldat_1.tanlo[7] = fxcor_1.cutdat[2] + tlldat_1.tcont[1] * 
	    fxcor_1.cutdat[3];
    if (abs(tlldat_1.tanlo[7]) - znumbr_1.z1em5 >= 0.) {
	goto L46;
    } else {
	goto L43;
    }
/*  IF GREATER THAN ZERO, PT. CIRCLE FOLLOWED BY CORNER CIRCLE OR JUST */
/*  CORNER CIRCLE. OTHERWISE PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. */
/*  CIRCLE, AND THEN CORNER CIRCLE */
L43:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L44;
    } else {
	goto L54;
    }
L44:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L45;
    } else {
	goto L50;
    }
L45:
    goto L39;
L46:
    if (tlldat_1.tanlo[7] >= 0.) {
	goto L47;
    } else {
	goto L51;
    }
/*  IF GREATER THAN ZERO,PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. CIR- */
/*  CLE, AND THEN CORNER CIRCLE. IF = 0, PT. CIRCLE AND CORNER CIRCLE. */
/*  ERROR LESS THAN ZERO */
L51:
    if ((d__1 = tlldat_1.corrad[3] * tlldat_1.corrad[3] - tlldat_1.tanlo[0]) <
	     0.) {
	goto L52;
    } else if (d__1 == 0) {
	goto L53;
    } else {
	goto L50;
    }
L52:
    goto L39;
/*  IF GREATER THAN ZERO, CORNER CIRCLE TANGENT TO LOWER LINE SEGMENT */
L47:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L48;
    } else {
	goto L55;
    }
L48:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L49;
    } else {
	goto L50;
    }
L49:
    goto L39;
/*  LOWER LINE SEGMENT, PT. CIRCLE, AND CORNER CIRCLE PARAMETER CALC. */
L50:
    tlldat_1.tcont[3] = sqrt(tlldat_1.tanlo[2]) / tlldat_1.umax[2];
    tlldat_1.tanhi[2] = (znumbr_1.z1 - tlldat_1.tcont[1] * tlldat_1.tcont[3]) 
	    / (tlldat_1.tcont[1] + tlldat_1.tcont[3]);
    tlldat_1.tlhite[2] = sinl[1] * tlldat_1.umax[1];
    tlldat_1.ri[2] = cosl[1] * tlldat_1.umax[1];
    tlldat_1.tanlo[2] = tlldat_1.tanhi[0];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[2];
    goto L56;
L62:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.umax[3] - tlldat_1.corrad[3], abs(
	    d__1)) <= 0.) {
	goto L63;
    } else {
	goto L64;
    }
L63:
    numerr = 22215;
    goto L1000;
/*  IF GREATER THAN ZERO, CORNER CIRCLE MEETS UPPER PT. CIRCLE AT UNAC- */
/*  CEPTABLE ANGLE. IF = 0 WE MUST CHANGE PARAMETERS FOR UPPER PT. CIRCLE */
L64:
    if ((d__1 = fxcor_1.cutdat[6] - fxcor_1.cutdat[3]) < 0.) {
	goto L78;
    } else if (d__1 == 0) {
	goto L66;
    } else {
	goto L63;
    }
L78:
    aerr_(&c_b99, "CUTTEH  ", (ftnlen)8);
    tlldat_1.tanlo[6] = (fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) / (
	    tlldat_1.ri[5] + sinl[5] - fxcor_1.cutdat[2]);
L79:
    tlldat_1.tcont[6] = znumbr_1.z0;
/* L80: */
    tlldat_1.tanhi[3] = znumbr_1.z0;
    goto L85;
/*  NO UPPER LINE SEGMENT. CHANGE IN PARAMETERS FOR UPPER POINT CIRCLE */
/*  NECESSARY DUE TO NATURE OF CORNER CIRCLE */
L66:
    aerr_(&c_b99, "CUTTEH  ", (ftnlen)8);
    tlldat_1.tanlo[6] = znumbr_1.z0;
    goto L79;
/*  IF GREATER THAN ZERO,CORNER CIRCLE AND THEN UPPER PT. CIRCLE. OTHER- */
/*  WISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN UPPER PT. CIRCLE */
L69:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L70;
    } else {
	goto L79;
    }
L70:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L71;
    } else {
	goto L83;
    }
L71:
    goto L41;
L74:
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    goto L84;
L77:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[3], abs(
	    d__1)) <= 0.) {
	goto L81;
    } else {
	goto L78;
    }
L81:
    if (tlldat_1.corrad[3] - tlldat_1.umax[3] <= 0.) {
	goto L82;
    } else {
	goto L83;
    }
L82:
    goto L41;
/*  FURTHER CALCULATIONS FOR TLLDAT BLOCK PARAMETERS */
L83:
    tlldat_1.tcont[5] = sqrt(tlldat_1.tcont[7]) / tlldat_1.umax[4];
    tlldat_1.tanhi[3] = (tlldat_1.tcont[5] + tlldat_1.tanlo[6]) / (
	    znumbr_1.z1 - tlldat_1.tcont[5] * tlldat_1.tanlo[6]);
    tlldat_1.tanlo[4] = tlldat_1.tanhi[3];
    tlldat_1.tanhi[4] = tlldat_1.tanlo[6];
L84:
    tlldat_1.ri[4] = tlldat_1.ri[6] - cosl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[4] = fxcor_1.cutdat[6] - sinl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[5] = tlldat_1.tlhite[4];
    tlldat_1.ri[5] = tlldat_1.ri[4];
L85:
    tlldat_1.tlhite[3] = fxcor_1.cutdat[3];
    tlldat_1.ri[3] = fxcor_1.cutdat[2];
L86:
    tlldat_1.tcont[4] = znumbr_1.z1;
L87:
    tlldat_1.tanlo[0] = znumbr_1.z1e38;
    tlldat_1.tlinc[2] = znumbr_1.z1;
    tlldat_1.tlinc[6] = znumbr_1.z1;
    tlldat_1.tlhite[6] = fxcor_1.cutdat[6];
/* L200: */
    ifxcor_1.ibegin = 1;
/*  WE NOW SEARCH EACH OF THE 7 POSSIBLE SEGMENTS TO DETERMINE FIRST ONE */
L91:
    if (tlldat_1.tcont[ifxcor_1.ibegin] != 0.) {
	goto L90;
    } else {
	goto L88;
    }
L90:
    tlldat_1.tcont[ifxcor_1.ibegin - 1] = -znumbr_1.z1;
    tlldat_1.tcont[8] = -znumbr_1.z1;
    tlldat_1.tcont[7] = znumbr_1.z1;
    tlldat_1.tanhi[6] = -znumbr_1.z1e38;
    tlldat_1.tanhi[7] = -znumbr_1.z1e38;
    tlldat_1.tanlo[7] = znumbr_1.z1e38;
    tlldat_1.tlinc[8] = znumbr_1.z0;
    tlldat_1.corrad[7] = znumbr_1.z0;
    ifxcor_1.ictdef = 0;
    ifxcor_1.iaerr = 0;
    tlconv_();
    goto L9999;
L88:
    ++ifxcor_1.ibegin;
    if (7 - ifxcor_1.ibegin >= 0) {
	goto L91;
    } else {
	goto L89;
    }
L89:
    numerr = 22217;
    goto L1000;
L92:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L93;
    } else {
	goto L10;
    }
L93:
    ifxcor_1.ipt1 = 0;
    tlldat_1.tanlo[6] = znumbr_1.z1e38;
    ifxcor_1.ibegin = 7;
    goto L90;

/*        ** CUTTER PARAMETER ERROR-CALL AERR AND DEFINE POINT CUTTER */

L1000:
    aercom_1.iaerfg = 1;
    ifxcor_1.ictdef = 0;
    aerr_(&numerr, "CUTTEH  ", (ftnlen)8);
/* L9990: */
    for (jj = 1; jj <= 7; ++jj) {
/* L1001: */
	param[jj - 1] = znumbr_1.z0;
    }
    *number = knumbr_1.k7;
    goto L105;
L9999:
    return 0;
} /* cutteh_ */

#undef number
#undef param
#undef sinl
#undef cosl






/* Subroutine */ int cutred_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer i__, j, jj, kk;
    extern integer bcdf_(char *, ftnlen);
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int apt299_();
#define param ((doublereal *)&hsave_1 + 5)
    static integer hcuter[2];
#define number ((integer *)&hsave_1 + 28)
    extern /* Subroutine */ int tlconv_(void);
    static integer numerr;






/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*    *** 7.  FXCOR BLOCK  *** */

/*    REAL VARIABLES USED BY ARELEM, WHICH MUST REMAIN INVIOLATE */




/*    SEPARATE /CHARCT/ COMMON BLOCK FOR MODFER, WHICH WAS PART OF FXCOR. */




/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*    *** 15.  IFXCOR BLOCK  *** */

/*    INVIOLATE ARELEM INTEGER VARIABLES */




/*   *** 18.  ISHARE18 BLOCK  *** */

/*   I,J,K,L,M,N HAVE BEEN REMOVED FROM FRONT OF THIS BLOCK, */
/*   AS THEY APPEAR TO BE USED AS LOCAL VARIABLES. */








/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */





/*     25.   COMMON FOR AERR INFORMATION */


/*     ----------------------------------------------------------- */


/* ...  DEFINES CUTTER SHAPE AND SETS UP TOOL DATA BLOCKS */

    hcuter[0] = bcdf_("CUTT", (ftnlen)4);
    hcuter[1] = bcdf_("ER  ", (ftnlen)4);

/*  PLACE ZEROES IN TLLDAT BLOCK */
/*        CUTRED ROUTINE TO REDEFINE EXISTING CUTTER FOR NEW UNITS/ */
L129:
    for (i__ = 1; i__ <= 8; ++i__) {
	tlldat_1.tlhite[i__ - 1] = znumbr_1.z0;
	sinl[i__ - 1] = znumbr_1.z0;
	cosl[i__ - 1] = znumbr_1.z0;
	tlldat_1.umax[i__ - 1] = znumbr_1.z0;
	tlldat_1.ri[i__ - 1] = znumbr_1.z0;
	tlldat_1.corrad[i__ - 1] = znumbr_1.z0;
	tlldat_1.tcont[i__] = znumbr_1.z0;
	tlldat_1.tlinc[i__] = znumbr_1.z0;
/* L1: */
    }
/*  MAKE SURE TOOL DIAMETER NOT LESS THAN ZERO */
    if (fxcor_1.cutdat[0] < 0.) {
	goto L2;
    } else if (fxcor_1.cutdat[0] == 0) {
	goto L92;
    } else {
	goto L3;
    }
L2:
    numerr = 22202;
    goto L1000;
/*  EXAMINE TOOL HEIGHT. IF LESS THAN ZERO ERROR. SET TO 5 IF = ZERO. */
/*  OKAY OTHERWISE */
L3:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L5;
    } else {
	goto L6;
    }
L4:
    numerr = 22203;
    goto L1000;
L5:
/*  SUM OF ANGLES A AND B MUST BE LESS THAN 90 DEGREES */
L6:
    if (znumbr_1.z90 - fxcor_1.cutdat[4] - fxcor_1.cutdat[5] <= 0.) {
	goto L7;
    } else {
	goto L8;
    }
L7:
    numerr = 22204;
    goto L1000;
L8:
    tlldat_1.ri[5] = znumbr_1.z5em1 * fxcor_1.cutdat[0];
    fxcor_1.cutdat[0] = tlldat_1.ri[5];
/*  ERROR IF ANGLE A NEGATIVE */
    if (fxcor_1.cutdat[4] < 0.) {
	goto L9;
    } else if (fxcor_1.cutdat[4] == 0) {
	goto L10;
    } else {
	goto L11;
    }
L9:
    numerr = 22205;
    goto L1000;
L10:
    cosl[1] = znumbr_1.z1;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L12;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR A GREATER THAN ZERO */
L11:
    tlldat_1.tlhite[7] = znumbr_1.degrad * fxcor_1.cutdat[4];
    sinl[1] = sin(tlldat_1.tlhite[7]);
    cosl[1] = cos(tlldat_1.tlhite[7]);
    tlldat_1.tcont[1] = sinl[1] / cosl[1];
    tlldat_1.tlhite[5] = tlldat_1.tcont[1] * tlldat_1.ri[5];
    tlldat_1.tanhi[0] = znumbr_1.z1 / tlldat_1.tcont[1];
/*  MAKE SURE HEIGHT OF BOTTOM LINE SEGMENT DOES NOT EXCEED TOOL HEIGHT */
L12:
    if (znumbr_1.z1em5 - (d__1 = fxcor_1.cutdat[6] - tlldat_1.tlhite[5], abs(
	    d__1)) <= 0.) {
	goto L13;
    } else {
	goto L15;
    }
L13:
    if (fxcor_1.cutdat[6] - tlldat_1.tlhite[5] <= 0.) {
	goto L14;
    } else {
	goto L16;
    }
L14:
    numerr = 22206;
    goto L1000;
L15:
    tlldat_1.tlhite[5] = fxcor_1.cutdat[6];
/*  ERROR IF ANGLE B NEGATIVE */
L16:
    ifxcor_1.ipt1 = knumbr_1.k1;
    if (fxcor_1.cutdat[5] < 0.) {
	goto L17;
    } else if (fxcor_1.cutdat[5] == 0) {
	goto L18;
    } else {
	goto L19;
    }
/*                    BELL SHAPED CUTTER */
L17:
    aerr_(&c_b39, "CUTRED  ", (ftnlen)8);
    goto L19;
L18:
    sinl[5] = znumbr_1.z1;
    goto L20;
/*  COMPUTE PARAMETERS FOR CERTAIN TOOL SEGMENTS FOR B GREATER THAN ZERO */
L19:
    tlldat_1.tanhi[7] = znumbr_1.degrad * fxcor_1.cutdat[5];
    sinl[5] = cos(tlldat_1.tanhi[7]);
    cosl[5] = sin(tlldat_1.tanhi[7]);
    tlldat_1.tanlo[6] = cosl[5] / sinl[5];
/*  FURTHER CALCULATIONS */
L20:
    tlldat_1.umax[1] = tlldat_1.ri[5] / cosl[1];
    tlldat_1.umax[5] = (fxcor_1.cutdat[6] - tlldat_1.tlhite[5]) / sinl[5];
    tlldat_1.ri[6] = tlldat_1.ri[5] + cosl[5] * tlldat_1.umax[5];
    tlldat_1.tcont[2] = znumbr_1.z1;
    tlldat_1.tcont[6] = znumbr_1.z1;
/*  EXAMINE TOOL RADIUS. IF GREATER THAN ZERO, CORNER CIRCLE WILL BE PART */
/*  OF TOOL CONFIGURATION. IF = ZERO, TOOL WILL CONSIST ONLY OF LINE AND */
/*  POINT CIRCLE SEGMENTS. ERROR IF NEGATIVE. */
    if (fxcor_1.cutdat[1] < 0.) {
	goto L21;
    } else if (fxcor_1.cutdat[1] == 0) {
	goto L22;
    } else {
	goto L25;
    }
L21:
    numerr = 22208;
    goto L1000;
/*  COMPARE LENGTH OF UPPER LINE SEGMENT TO ZERO. SET VALUES IN TLLDAT */
/*  BLOCK ACCORDINGLY */
L22:
    if (tlldat_1.umax[5] <= 0.) {
	goto L23;
    } else {
	goto L24;
    }
L23:
    tlldat_1.tanlo[6] = tlldat_1.tanhi[0];
    tlldat_1.tcont[6] = znumbr_1.z0;
    goto L87;
L24:
    tlldat_1.tlhite[3] = tlldat_1.tlhite[5];
    tlldat_1.ri[3] = tlldat_1.ri[5];
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
    goto L86;
/*  COMPUTE CENTER OF CORNER CIRCLE */
L27:
    fxcor_1.cutdat[2] = tlldat_1.ri[5] - tlldat_1.corrad[3];
    fxcor_1.cutdat[3] = tlldat_1.corrad[3];
    goto L26;
/*  STORE RADIUS OF CORNER CIRCLE AND COMPUTE DISTANCE FROM CENTER OF */
/*  CIRCLE TO BOTTOM LINE (UMAX(3)) */
L25:
    tlldat_1.corrad[3] = fxcor_1.cutdat[1];
L26:
    tlldat_1.umax[2] = fxcor_1.cutdat[3] * cosl[1] - fxcor_1.cutdat[2] * sinl[
	    1];
    tlldat_1.tanlo[0] = fxcor_1.cutdat[2] * fxcor_1.cutdat[2] + 
	    fxcor_1.cutdat[3] * fxcor_1.cutdat[3];
/*  IF = 0, CENTER OF CORNER CIRCLE HAS TO BE CALCULATED */
    if (tlldat_1.tanlo[0] + fxcor_1.cutdat[4] + fxcor_1.cutdat[5] * 
	    fxcor_1.cutdat[5] != 0.) {
	goto L28;
    } else {
	goto L27;
    }
/*  DISTANCE FROM CENTER OF CIRCLE TO INTERSECTION OF LINE SEGMENTS */
L28:
    tlldat_1.umax[0] = sqrt((fxcor_1.cutdat[2] - tlldat_1.ri[5]) * (
	    fxcor_1.cutdat[2] - tlldat_1.ri[5]) + (fxcor_1.cutdat[3] - 
	    tlldat_1.tlhite[5]) * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]));
    tlldat_1.umax[6] = tlldat_1.tanlo[6] * (fxcor_1.cutdat[6] - 
	    tlldat_1.tlhite[5]);
/*  DISTANCE FROM CENTER OF CIRCLE TO UPPER END OF UPPER LINE SEGMENT */
    tlldat_1.umax[3] = sqrt((fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) * (
	    fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) + (fxcor_1.cutdat[2] - 
	    tlldat_1.ri[6]) * (fxcor_1.cutdat[2] - tlldat_1.ri[6]));
/*  IF THE Y COORD. (F) OF THE CENTER OF THE CORNER CIRCLE IS LESS THAN */
/*  THE Y COORD. OF THE INTERSECTION OF THE LINES, THEN ERROR */
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] <= 0.) {
	goto L29;
    } else {
	goto L30;
    }
L29:
    numerr = 22209;
    goto L1000;
/*  IF THE RADIUS IS BOTH LARGER THAN THE DISTANCE TO THE INTERSECTION */
/*  OF THE LINES AND DIFFERENT THAN THE DISTANCE TO THE ORIGIN OF THE */
/*  BOTTOM LINE SEGMENT, WE HAVE AN INVALID TOOL CONFIGURATION */
L33:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.tanlo[0] - tlldat_1.corrad[3] * 
	    tlldat_1.corrad[3], abs(d__1)) <= 0.) {
	goto L34;
    } else {
	goto L35;
    }
L34:
    numerr = 22210;
    goto L1000;
/*  IF E GREATER THAN ZERO, WE HAVE AN INVALID TOOL CONFIGURATION */
L35:
    if (fxcor_1.cutdat[2] < 0.) {
	goto L53;
    } else if (fxcor_1.cutdat[2] == 0) {
	goto L37;
    } else {
	goto L34;
    }
L53:
    aerr_(&c_b59, "CUTRED  ", (ftnlen)8);
    tlldat_1.tanhi[0] = fxcor_1.cutdat[3] / fxcor_1.cutdat[2];
    tlldat_1.tcont[1] = fxcor_1.cutdat[2] / fxcor_1.cutdat[3];
/*  NO LOWER LINE SEGMENT */
L54:
    tlldat_1.tcont[2] = znumbr_1.z0;
/*  FURTHER TLLDAT VARIABLES */
L55:
    tlldat_1.tanlo[3] = tlldat_1.tanhi[0];
L56:
    tlldat_1.umax[4] = (tlldat_1.ri[5] - fxcor_1.cutdat[2]) * sinl[5] + cosl[
	    5] * (fxcor_1.cutdat[3] - tlldat_1.tlhite[5]);
/*  IF = 0, THERE IS NO UPPER LINE SEGMENT AND IN THIS CASE TOOL NO GOOD */
    if (tlldat_1.umax[5] != 0.) {
	goto L67;
    } else {
	goto L57;
    }
/*  IF GREATER THAN ZERO, RADIUS AND DISTANCE FROM CENTER OF CORNER */
/*  CIRCLE TO INTERSECTION OF LINES EQUAL. */
L67:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L68;
    } else {
	goto L62;
    }
L68:
    tlldat_1.tcont[7] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[4] * tlldat_1.umax[4];
/*  LENGTH OF UPPER LINE SEGMENT */
    tlldat_1.umax[5] = tlldat_1.umax[5] + sqrt((abs(tlldat_1.tcont[7]))) - 
	    sqrt(tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[4] * 
	    tlldat_1.umax[4]);
    tlldat_1.umax[7] = fxcor_1.cutdat[3] - fxcor_1.cutdat[6] - tlldat_1.tanlo[
	    6] * (tlldat_1.umax[6] + tlldat_1.ri[5] - fxcor_1.cutdat[2]);
    if (znumbr_1.z1em5 - abs(tlldat_1.umax[7]) <= 0.) {
	goto L72;
    } else {
	goto L69;
    }
L72:
    if (tlldat_1.umax[7] <= 0.) {
	goto L73;
    } else {
	goto L77;
    }
/*  IF GREATER THAN ZERO, UPPER LINE SEGMENT WITH CORNER CIRCLE TANGENT. */
/*  OTHERWISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN PT. CIRCLE */
L73:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L75;
    } else {
	goto L74;
    }
L75:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L76;
    } else {
	goto L83;
    }
L76:
    goto L41;
L57:
    numerr = 22212;
    goto L1000;
/*  WE MUST CHANGE PARAMETERS FOR BOTTOM POINT CIRCLE DUE TO NATURE OF */
/*  CORNER CIRCLE */
L37:
    aerr_(&c_b59, "CUTRED  ", (ftnlen)8);
    tlldat_1.tcont[1] = znumbr_1.z0;
    tlldat_1.tanhi[0] = znumbr_1.z1e38;
    goto L54;
/*  IF GREATER THAN OR EQUAL TO ZERO, CORNER CIRCLE IS A POINT CIRCLE */
L30:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[0], abs(
	    d__1)) >= 0.) {
	goto L31;
    } else {
	goto L32;
    }
L31:
    tlldat_1.corrad[3] = 0.f;
    tlldat_1.tanlo[0] = 0.f;
    tlldat_1.umax[0] = 0.f;
    tlldat_1.umax[2] = 0.f;
    tlldat_1.umax[3] = 0.f;
    tlldat_1.umax[6] = 0.f;
    fxcor_1.cutdat[1] = 0.f;
    fxcor_1.cutdat[2] = 0.f;
    fxcor_1.cutdat[3] = 0.f;
    goto L22;
L32:
    if (tlldat_1.corrad[3] - tlldat_1.umax[0] <= 0.) {
	goto L38;
    } else {
	goto L33;
    }
L38:
    if (tlldat_1.ri[5] + tlldat_1.tcont[1] * (tlldat_1.tlhite[5] - 
	    fxcor_1.cutdat[3]) - fxcor_1.cutdat[2] + znumbr_1.z1em5 <= 0.) {
	goto L39;
    } else {
	goto L40;
    }
/*  CORNER CIRCLE INTERSECTS LOWER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L39:
    numerr = 22213;
    goto L1000;
L40:
    if (fxcor_1.cutdat[3] + znumbr_1.z1em5 - tlldat_1.tlhite[5] - 
	    tlldat_1.tanlo[6] * (tlldat_1.ri[5] - fxcor_1.cutdat[2]) <= 0.) {
	goto L41;
    } else {
	goto L42;
    }
/*  CORNER CIRCLE INTERSECTS UPPER LINE SEGMENT AT AN UNACCEPTABLE ANGLE */
L41:
    numerr = 22214;
    goto L1000;
L42:
    tlldat_1.tanlo[2] = tlldat_1.corrad[3] * tlldat_1.corrad[3] - 
	    tlldat_1.umax[2] * tlldat_1.umax[2];
    if (tlldat_1.tanlo[2] < znumbr_1.z0) {
	goto L39;
    }
/*  LENGTH OF LOWER LINE SEGMENT */
    tlldat_1.umax[1] = tlldat_1.umax[1] + sqrt(tlldat_1.tanlo[2]) - sqrt(
	    tlldat_1.umax[0] * tlldat_1.umax[0] - tlldat_1.umax[2] * 
	    tlldat_1.umax[2]);
    tlldat_1.tanlo[7] = fxcor_1.cutdat[2] + tlldat_1.tcont[1] * 
	    fxcor_1.cutdat[3];
    if (abs(tlldat_1.tanlo[7]) - znumbr_1.z1em5 >= 0.) {
	goto L46;
    } else {
	goto L43;
    }
/*  IF GREATER THAN ZERO, PT. CIRCLE FOLLOWED BY CORNER CIRCLE OR JUST */
/*  CORNER CIRCLE. OTHERWISE PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. */
/*  CIRCLE, AND THEN CORNER CIRCLE */
L43:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L44;
    } else {
	goto L54;
    }
L44:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L45;
    } else {
	goto L50;
    }
L45:
    goto L39;
L46:
    if (tlldat_1.tanlo[7] >= 0.) {
	goto L47;
    } else {
	goto L51;
    }
/*  IF GREATER THAN ZERO,PT. CIRCLE (MAYBE), LOWER LINE SEGMENT, PT. CIR- */
/*  CLE, AND THEN CORNER CIRCLE. IF = 0, PT. CIRCLE AND CORNER CIRCLE. */
/*  ERROR LESS THAN ZERO */
L51:
    if ((d__1 = tlldat_1.corrad[3] * tlldat_1.corrad[3] - tlldat_1.tanlo[0]) <
	     0.) {
	goto L52;
    } else if (d__1 == 0) {
	goto L53;
    } else {
	goto L50;
    }
L52:
    goto L39;
/*  IF GREATER THAN ZERO, CORNER CIRCLE TANGENT TO LOWER LINE SEGMENT */
L47:
    if (znumbr_1.z1em5 - abs(tlldat_1.tanlo[2]) <= 0.) {
	goto L48;
    } else {
	goto L55;
    }
L48:
    if (tlldat_1.tanlo[2] <= 0.) {
	goto L49;
    } else {
	goto L50;
    }
L49:
    goto L39;
/*  LOWER LINE SEGMENT, PT. CIRCLE, AND CORNER CIRCLE PARAMETER CALC. */
L50:
    tlldat_1.tcont[3] = sqrt(tlldat_1.tanlo[2]) / tlldat_1.umax[2];
    tlldat_1.tanhi[2] = (znumbr_1.z1 - tlldat_1.tcont[1] * tlldat_1.tcont[3]) 
	    / (tlldat_1.tcont[1] + tlldat_1.tcont[3]);
    tlldat_1.tlhite[2] = sinl[1] * tlldat_1.umax[1];
    tlldat_1.ri[2] = cosl[1] * tlldat_1.umax[1];
    tlldat_1.tanlo[2] = tlldat_1.tanhi[0];
    tlldat_1.tanlo[3] = tlldat_1.tanhi[2];
    goto L56;
L62:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.umax[3] - tlldat_1.corrad[3], abs(
	    d__1)) <= 0.) {
	goto L63;
    } else {
	goto L64;
    }
L63:
    numerr = 22215;
    goto L1000;
/*  IF GREATER THAN ZERO, CORNER CIRCLE MEETS UPPER PT. CIRCLE AT UNAC- */
/*  CEPTABLE ANGLE. IF = 0 WE MUST CHANGE PARAMETERS FOR UPPER PT. CIRCLE */
L64:
    if ((d__1 = fxcor_1.cutdat[6] - fxcor_1.cutdat[3]) < 0.) {
	goto L78;
    } else if (d__1 == 0) {
	goto L66;
    } else {
	goto L63;
    }
L78:
    aerr_(&c_b99, "CUTRED  ", (ftnlen)8);
    tlldat_1.tanlo[6] = (fxcor_1.cutdat[3] - fxcor_1.cutdat[6]) / (
	    tlldat_1.ri[5] + sinl[5] - fxcor_1.cutdat[2]);
L79:
    tlldat_1.tcont[6] = znumbr_1.z0;
/* L80: */
    tlldat_1.tanhi[3] = znumbr_1.z0;
    goto L85;
/*  NO UPPER LINE SEGMENT. CHANGE IN PARAMETERS FOR UPPER POINT CIRCLE */
/*  NECESSARY DUE TO NATURE OF CORNER CIRCLE */
L66:
    aerr_(&c_b99, "CUTRED  ", (ftnlen)8);
    tlldat_1.tanlo[6] = znumbr_1.z0;
    goto L79;
/*  IF GREATER THAN ZERO,CORNER CIRCLE AND THEN UPPER PT. CIRCLE. OTHER- */
/*  WISE CORNER CIRCLE, PT. CIRCLE, UPPER LINE, AND THEN UPPER PT. CIRCLE */
L69:
    if (znumbr_1.z1em5 - abs(tlldat_1.tcont[7]) <= 0.) {
	goto L70;
    } else {
	goto L79;
    }
L70:
    if (tlldat_1.tcont[7] <= 0.) {
	goto L71;
    } else {
	goto L83;
    }
L71:
    goto L41;
L74:
    tlldat_1.tanhi[3] = tlldat_1.tanlo[6];
    goto L84;
L77:
    if (znumbr_1.z1em5 - (d__1 = tlldat_1.corrad[3] - tlldat_1.umax[3], abs(
	    d__1)) <= 0.) {
	goto L81;
    } else {
	goto L78;
    }
L81:
    if (tlldat_1.corrad[3] - tlldat_1.umax[3] <= 0.) {
	goto L82;
    } else {
	goto L83;
    }
L82:
    goto L41;
/*  FURTHER CALCULATIONS FOR TLLDAT BLOCK PARAMETERS */
L83:
    tlldat_1.tcont[5] = sqrt(tlldat_1.tcont[7]) / tlldat_1.umax[4];
    tlldat_1.tanhi[3] = (tlldat_1.tcont[5] + tlldat_1.tanlo[6]) / (
	    znumbr_1.z1 - tlldat_1.tcont[5] * tlldat_1.tanlo[6]);
    tlldat_1.tanlo[4] = tlldat_1.tanhi[3];
    tlldat_1.tanhi[4] = tlldat_1.tanlo[6];
L84:
    tlldat_1.ri[4] = tlldat_1.ri[6] - cosl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[4] = fxcor_1.cutdat[6] - sinl[5] * tlldat_1.umax[5];
    tlldat_1.tlhite[5] = tlldat_1.tlhite[4];
    tlldat_1.ri[5] = tlldat_1.ri[4];
L85:
    tlldat_1.tlhite[3] = fxcor_1.cutdat[3];
    tlldat_1.ri[3] = fxcor_1.cutdat[2];
L86:
    tlldat_1.tcont[4] = znumbr_1.z1;
L87:
    tlldat_1.tanlo[0] = znumbr_1.z1e38;
    tlldat_1.tlinc[2] = znumbr_1.z1;
    tlldat_1.tlinc[6] = znumbr_1.z1;
    tlldat_1.tlhite[6] = fxcor_1.cutdat[6];
/* L200: */
    ifxcor_1.ibegin = 1;
/*  WE NOW SEARCH EACH OF THE 7 POSSIBLE SEGMENTS TO DETERMINE FIRST ONE */
L91:
    if (tlldat_1.tcont[ifxcor_1.ibegin] != 0.) {
	goto L90;
    } else {
	goto L88;
    }
L90:
    tlldat_1.tcont[ifxcor_1.ibegin - 1] = -znumbr_1.z1;
    tlldat_1.tcont[8] = -znumbr_1.z1;
    tlldat_1.tcont[7] = znumbr_1.z1;
    tlldat_1.tanhi[6] = -znumbr_1.z1e38;
    tlldat_1.tanhi[7] = -znumbr_1.z1e38;
    tlldat_1.tanlo[7] = znumbr_1.z1e38;
    tlldat_1.tlinc[8] = znumbr_1.z0;
    tlldat_1.corrad[7] = znumbr_1.z0;
    ifxcor_1.ictdef = 0;
    ifxcor_1.iaerr = 0;
    tlconv_();
    goto L9999;
L88:
    ++ifxcor_1.ibegin;
    if (7 - ifxcor_1.ibegin >= 0) {
	goto L91;
    } else {
	goto L89;
    }
L89:
    numerr = 22217;
    goto L1000;
L92:
    if (fxcor_1.cutdat[6] < 0.) {
	goto L4;
    } else if (fxcor_1.cutdat[6] == 0) {
	goto L93;
    } else {
	goto L10;
    }
L93:
    ifxcor_1.ipt1 = 0;
    tlldat_1.tanlo[6] = znumbr_1.z1e38;
    ifxcor_1.ibegin = 7;
    goto L90;

/*        ** CUTTER PARAMETER ERROR-CALL AERR AND DEFINE POINT CUTTER */

L1000:
    aercom_1.iaerfg = 1;
    ifxcor_1.ictdef = 0;
    aerr_(&numerr, "CUTRED  ", (ftnlen)8);
/* L9990: */
    for (jj = 1; jj <= 7; ++jj) {
/* L1001: */
	param[jj - 1] = znumbr_1.z0;
    }
    *number = knumbr_1.k7;

    ifxcor_1.ictdef = knumbr_1.k1;
/* ...  ZERO CUTTER PARAMETER STORAGE AREA */
    for (j = 1; j <= 7; ++j) {
/* L110: */
	fxcor_1.cutdat[j - 1] = znumbr_1.z0;
    }
    fxcor_1.cutdat[6] = fxcor_1.tlhit;
    if (*number - knumbr_1.k7 <= 0) {
	goto L126;
    } else {
	goto L125;
    }
L125:
    numerr = 22201;
    goto L1000;
L126:
    i__1 = *number;
    for (j = 1; j <= i__1; ++j) {
/* L127: */
	fxcor_1.cutdat[j - 1] = param[j - 1];
    }
/*  WRITE CUTTER STATEMENT ON EXFILE */
    apt299_(number, hcuter, &c__1, param);
    if (*number <= 1) {
	goto L129;
    }
    kk = 1;
    i__1 = *number;
    for (i__ = 2; i__ <= i__1; i__ += 2) {
	if (i__ == *number) {
	    kk = 0;
	}
/* L128: */
	apt299_(&c__1, &param[i__ - 1], &kk, &param[i__]);
    }
    goto L129;

L9999:
    return 0;
} /* cutred_ */

#undef number
#undef param
#undef sinl
#undef cosl


