/* APT089.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    doublereal b, c__, d__[12], dx1, dx2, sb, tem[3], temp, v[3], x2, y2;
} dshar6_;

#define dshar6_1 dshar6_

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
    integer i__, inc, i1, j, j1, k, l, lim, l1, m, n, nm1;
} ishr17_;

#define ishr17_1 ishr17_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

struct {
    doublereal tabext, ssext;
    integer iold;
} xunits_;

#define xunits_1 xunits_

struct {
    char oldmod[6];
} xunitc_;

#define xunitc_1 xunitc_

/* Table of constant values */

static integer c__15 = 15;
static integer c__1 = 1;
static integer c__112 = 112;
static doublereal c_b21 = 360.;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__20 = 20;
static integer c__6 = 6;
static integer c__35 = 35;
static integer c__50 = 50;
static integer c__65 = 65;
static integer c__80 = 80;
static integer c__95 = 95;
static integer c__2 = 2;
static integer c__92 = 92;
static integer c__12 = 12;
static integer c__17 = 17;
static integer c__29 = 29;
static integer c__41 = 41;
static integer c__7 = 7;
static integer c__53 = 53;
static integer c__10 = 10;
static integer c__75 = 75;
static integer c__13 = 13;
static integer c__42 = 42;
static integer c__67 = 67;
static integer c__113 = 113;
static integer c__119 = 119;
static integer c__18 = 18;
static integer c__3 = 3;
static integer c__103 = 103;
static integer c__26 = 26;
static integer c__27 = 27;
static integer c__8 = 8;
static integer c__46 = 46;
static integer c__49 = 49;
static integer c__16 = 16;
static integer c__100 = 100;

/* *** SOURCE FILE : M0002233.V12   *** */

/* .....FORTRAN SUBROUTINE  ....APT089         8/68                 HG,RN */
/* .....FORTRAN SUBROUTINE             APT089...              3/1/68   GK */
/*          PART 2 OF APT088 */
/*              FORTRAN SUBROUTINE APT089 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A TABULATED */
/*              CYLINDER DEFINED BY THE POINTS THROUGH WHICH IT */
/*              MUST PASS BY THE FOLLOWING APT STATEMENT */
/*                TABCYL/+, V, TRFORM, MI, P1, **, K1, P2, */
/*                   P3, ..., PN, ***, KN */
/*                * = NOX, NOY, NOZ, XYZ, RTHETA, OR THETAR */
/*                ** = SLOPE OR NORMAL */
/*                 *** = SLOPE OR NORMAL */

/* LINKAGE      CALL APT089 (A) */


/* ARGUMENTS    A       ARRAY CONTAINING THE INFORMATION NECESSARY */
/*                      TO PLACE THE TABCYL CANONICAL FORM ON TAPE */
/*                      AND LATER RETRIEVE IT FROM TAPE */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT040 */
/*              SUBROUTINE          APT087 */
/*              SUBROUTINE          APT094 */
/*              REAL FUNCTION       ATAN */
/*              REAL FUNCTION       ATAN2 */
/*              LOGICAL FUNCTION    CKDEF */
/*              REAL FUNCTION       COS */
/*              SUBROUTINE          DOTF */
/*              SUBROUTINE          ERROR */
/*              REAL FUNCTION       MINO */
/*              REAL FUNCTION       SIN */
/*              REAL FUNCTION       SQRT */
/*              SUBROUTINE          TABTAP */
/*              LOGICAL FUNCTION    ZVECT */

/*        ADDITIONS FOR PRINT /TABPRT,ON OR OFF */
/*        TABPRT FLAG IS CHECKED  EACH TIME BEFORE PRINTING */
/*        FLAG IS SET IN PRINT ROUTINE AND INITIALIZED IN APT227 */
/* Subroutine */ int apt089_(doublereal *a)
{
    /* Initialized data */

    static char form4[28] = " EXTENSION INTERSECTION U=  ";
    static char form5[4] = " V= ";
    static char form7[16] = " ROTATION MATRIX";
    static char form9[100] = "0      U              V              A        "
	    "     B            LENGTH         MAX           MIN    ";
    static doublereal table[8] = { .05,.1,.2,.5,1.,2.,5.,10. };
    static doublereal zlit2 = 1e10;
    static doublereal zlit3 = 50.;
    static doublereal zlit4 = 52.5001;
    static doublereal zlit6 = 5e-5;
    static char form1[112] = " NUM        THETA        RADIUS         X-CORD"
	    "         Y-CORD          SEG LENGTH       SEG ANGLE      EXT ANG"
	    "LE";
    static char form2[92] = " NUM     SLOPE        NORMAL      ALPHA   TANGE"
	    "NT A   TANGENT B     CURVA    DELTA CURV     ";
    static char form3[120] = "    CURVATURE    .+........................+.."
	    "......................+........................+................"
	    "........+.";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11, d__12, d__13, d__14, d__15, d__16;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), d_sign(doublereal *, doublereal *
	    ), atan(doublereal), sqrt(doublereal);

    /* Local variables */
    static doublereal x, y, a1, b1, a2, b2, s1, t1, ga, al, xa, ta, tb;
    static integer kp;
    static doublereal ga1, se2;
#define can ((doublereal *)&_BLNK__1 + 40)
#define tab ((doublereal *)&_BLNK__1 + 40)
    static doublereal dcp, phi, dst, cen1, cen2, tem1, tem2, tem3, tem4, cmin,
	     cmax;
#define rotm ((doublereal *)&_BLNK__1 + 41)
    extern /* Subroutine */ int apt094_(integer *, doublereal *, doublereal *)
	    , apt087_(doublereal *, doublereal *);
    static doublereal delta, dcmax;
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
#define sscan ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int fconv_(doublereal *, char *, integer *, 
	    integer *, integer *, ftnlen), iconv_(integer *, char *, integer *
	    , integer *, ftnlen);
    static integer idumy;
    extern /* Subroutine */ int print_(integer *, doublereal *, integer *);
    static doublereal curti1, curti2;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    static doublereal center;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static doublereal tlengt, curvrg;




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */








/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  6.  DSHARE BLOCK 6  *** */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   *** 17.  ISHARE17 BLOCK  *** */

/*   TABCYL SHARED INTEGER VARIABLES */
/*   SOME OF THESE MAY BE ONLY USED AS LOCAL VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */










    /* Parameter adjustments */
    --a;

    /* Function Body */
/*        ARITHMETIC STATEMENT FUNCTIONS */
    ishr17_1.l1 = 0;
L560:
    dcmax = znumbr_1.z0;
    i__1 = ishr17_1.nm1;
    for (ishr17_1.i1 = 14; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	if ((d__1 = tab[ishr17_1.i1 + 17], abs(d__1)) < dcmax) {
	    goto L570;
	}
	dcmax = (d__1 = tab[ishr17_1.i1 + 17], abs(d__1));
	ishr17_1.j1 = ishr17_1.i1;
L570:
	;
    }
/*        MINIMIZE MAXIMUM CURVATURE, USING NEWTON'S METHOD */
    if (dcmax <= znumbr_1.z1em3 || ishr17_1.l1 >= knumbr_1.k4 * ishr17_1.i__) 
	    {
	goto L640;
    }
    a1 = tab[ishr17_1.j1 + 7] - tab[ishr17_1.j1 + 8];
    a2 = tab[ishr17_1.j1 + 14] - tab[ishr17_1.j1 + 15];
    b2 = tab[ishr17_1.j1 + 21] - tab[ishr17_1.j1 + 15];
    dcp = (tab[ishr17_1.j1 + 9] + tab[ishr17_1.j1 + 16]) * -4.f / tab[
	    ishr17_1.j1 + 9] / tab[ishr17_1.j1 + 16];
/*        OBTAIN NEW APPROXIMATION FOR SLOPE AT P(J1), NEW CURVATURE */
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= 4; ++ishr17_1.i1) {
	d__1 = cos(a2);
/* Computing MAX */
	d__3 = abs(d__1);
	d__2 = max(d__3,znumbr_1.z1em9);
	a2 = atan(sin(a2) / d_sign(&d__2, &d__1) - tab[ishr17_1.j1 + 17] / 
		dcp);
	tab[ishr17_1.j1 + 14] = a2 + tab[ishr17_1.j1 + 15];
	b1 = tab[ishr17_1.j1 + 14] - tab[ishr17_1.j1 + 8];
	d__1 = cos(a2);
	d__2 = cos(b2);
	d__4 = cos(b1);
	d__5 = cos(a1);
/* Computing MAX */
	d__8 = abs(d__1);
	d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
	d__10 = abs(d__2);
	d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
	d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
	d__13 = abs(d__4);
	d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
	d__15 = abs(d__5);
	d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
	d__16 = (d__6 = cos(b1), abs(d__6));
	tab[ishr17_1.j1 + 17] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 
		2.f * (sin(b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * 
		d__11)) / tab[ishr17_1.j1 + 16] + -(4.f * (sin(b1) / d_sign(&
		d__12, &d__4)) + 2.f * (sin(a1) / d_sign(&d__14, &d__5))) * (
		d__16 * (d__16 * d__16)) / tab[ishr17_1.j1 + 9];
	if ((d__1 = tab[ishr17_1.j1 + 17], abs(d__1)) <= znumbr_1.z1em3) {
	    goto L590;
	}
/* L580: */
    }
/*        CHANGE IN A2 - CHANGE IN CURVATURE AT P(J1-1), P(J1+1) */
/*        AT START OR END OF TABCYL, REFLECT ANGLE */
L590:
    dshar6_1.x2 = a2;
    dshar6_1.y2 = b2;
    ishr17_1.l1 += knumbr_1.k1;
    if ((i__1 = ishr17_1.j1 + ishr17_1.k - knumbr_1.k15) < 0) {
	goto L620;
    } else if (i__1 == 0) {
	goto L630;
    } else {
	goto L600;
    }
L600:
    if ((i__1 = ishr17_1.j1 + ishr17_1.l - ishr17_1.nm1) < 0) {
	goto L610;
    } else if (i__1 == 0) {
	goto L601;
    } else {
	goto L630;
    }
L601:
    b2 = znumbr_1.pi - a2;
    tab[ishr17_1.i__ - 7] = tab[ishr17_1.i__ - 13] + b2;
    d__1 = cos(a2);
    d__2 = cos(b2);
    d__4 = cos(b1);
    d__5 = cos(a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(b1), abs(d__6));
    tab[ishr17_1.i__ - 11] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 2.f * 
	    (sin(b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / 
	    tab[ishr17_1.i__ - 12] + -(4.f * (sin(b1) / d_sign(&d__12, &d__4))
	     + 2.f * (sin(a1) / d_sign(&d__14, &d__5))) * (d__16 * (d__16 * 
	    d__16)) / tab[ishr17_1.i__ - 19];
L610:
    a2 = a1;
    b2 = b1;
    a1 = tab[ishr17_1.j1] - tab[ishr17_1.j1 + 1];
    b1 = tab[ishr17_1.j1 + 7] - tab[ishr17_1.j1 + 1];
    d__1 = cos(a2);
    d__2 = cos(b2);
    d__4 = cos(b1);
    d__5 = cos(a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(b1), abs(d__6));
    tab[ishr17_1.j1 + 10] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 2.f * (
	    sin(b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / 
	    tab[ishr17_1.j1 + 9] + -(4.f * (sin(b1) / d_sign(&d__12, &d__4)) 
	    + 2.f * (sin(a1) / d_sign(&d__14, &d__5))) * (d__16 * (d__16 * 
	    d__16)) / tab[ishr17_1.j1 + 2];
    goto L630;
L620:
    a1 = znumbr_1.pi - b1;
    tab[21] = tab[22] + a1;
    d__1 = cos(a2);
    d__2 = cos(b2);
    d__4 = cos(b1);
    d__5 = cos(a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(b1), abs(d__6));
    tab[31] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 2.f * (sin(b2) / 
	    d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / tab[30] + -(
	    4.f * (sin(b1) / d_sign(&d__12, &d__4)) + 2.f * (sin(a1) / d_sign(
	    &d__14, &d__5))) * (d__16 * (d__16 * d__16)) / tab[23];
L630:
    if (ishr17_1.j1 == ishr17_1.nm1) {
	goto L560;
    }
    a1 = dshar6_1.x2;
    b1 = dshar6_1.y2;
    a2 = tab[ishr17_1.j1 + 21] - tab[ishr17_1.j1 + 22];
    b2 = tab[ishr17_1.j1 + 28] - tab[ishr17_1.j1 + 22];
    d__1 = cos(a2);
    d__2 = cos(b2);
    d__4 = cos(b1);
    d__5 = cos(a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(b1), abs(d__6));
    tab[ishr17_1.j1 + 24] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 2.f * (
	    sin(b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / 
	    tab[ishr17_1.j1 + 23] + -(4.f * (sin(b1) / d_sign(&d__12, &d__4)) 
	    + 2.f * (sin(a1) / d_sign(&d__14, &d__5))) * (d__16 * (d__16 * 
	    d__16)) / tab[ishr17_1.j1 + 16];
    goto L560;
/*        SAVE END SLOPES AND WRITE OUT DATA */
L640:
    if (ishr17_1.l != 0) {
	goto L642;
    }
    a1 = tab[ishr17_1.i__ - 21] - tab[ishr17_1.i__ - 20];
    b1 = tab[ishr17_1.i__ - 14] - tab[ishr17_1.i__ - 20];
    a2 = tab[ishr17_1.i__ - 14] - tab[ishr17_1.i__ - 13];
    b2 = znumbr_1.pi - a2;
    tab[ishr17_1.i__ - 7] = tab[ishr17_1.i__ - 13] + b2;
    d__1 = cos(a2);
    d__2 = cos(b2);
    d__4 = cos(b1);
    d__5 = cos(a1);
/* Computing MAX */
    d__8 = abs(d__1);
    d__7 = max(d__8,znumbr_1.z1em9);
/* Computing MAX */
    d__10 = abs(d__2);
    d__9 = max(d__10,znumbr_1.z1em9);
/* Computing 3rd power */
    d__11 = (d__3 = cos(a2), abs(d__3));
/* Computing MAX */
    d__13 = abs(d__4);
    d__12 = max(d__13,znumbr_1.z1em9);
/* Computing MAX */
    d__15 = abs(d__5);
    d__14 = max(d__15,znumbr_1.z1em9);
/* Computing 3rd power */
    d__16 = (d__6 = cos(b1), abs(d__6));
    tab[ishr17_1.i__ - 11] = -(4.f * (sin(a2) / d_sign(&d__7, &d__1)) + 2.f * 
	    (sin(b2) / d_sign(&d__9, &d__2))) * (d__11 * (d__11 * d__11)) / 
	    tab[ishr17_1.i__ - 12] + -(4.f * (sin(b1) / d_sign(&d__12, &d__4))
	     + 2.f * (sin(a1) / d_sign(&d__14, &d__5))) * (d__16 * (d__16 * 
	    d__16)) / tab[ishr17_1.i__ - 19];
L642:
    d__1 = cos(tab[21]);
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,znumbr_1.z1em9);
    dshar6_1.sb = sin(tab[21]) / d_sign(&d__2, &d__1);
    d__1 = cos(tab[ishr17_1.i__ - 7]);
/* Computing MAX */
    d__3 = abs(d__1);
    d__2 = max(d__3,znumbr_1.z1em9);
    se2 = sin(tab[ishr17_1.i__ - 7]) / d_sign(&d__2, &d__1);
/*        CHECK TABPRT FLAG */
    if (ldef_1.tabprt) {
	goto L643;
    }
/* ...     CALL PRINT TO OUTPUT ISN AND TABCYL IDENTIFICATION INFORMATION */
    print_(&c__15, &a[1], &c__1);

    cform_(form1, darray_1.darray, &c__1, &c__112, (ftnlen)112, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L643:
    i__1 = ishr17_1.n;
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= i__1; ++ishr17_1.i1) {
	ishr17_1.j1 = knumbr_1.k7 * ishr17_1.i1;
	apt087_(dshar6_1.tem, &tab[ishr17_1.j1 + 12]);
	tab[ishr17_1.j1 + 18] = dshar6_1.tem[1];
/*        CHECK TABPRT FLAG */
	if (ldef_1.tabprt) {
	    goto L672;
	}
/*        GA IS SEGMENT ANGLE, XA EXTERIOR ANGLE */
	ga1 = ga;
	if (ishr17_1.i1 == ishr17_1.n) {
	    goto L650;
	}
	ga = tab[ishr17_1.j1 + 15] / znumbr_1.degrad;
	if (ishr17_1.i1 == knumbr_1.k1) {
	    goto L660;
	}
	xa = ga - ga1;
	if (abs(xa) > znumbr_1.z2 * znumbr_1.z90) {
	    xa -= d_sign(&c_b21, &xa);
	}
	goto L670;
/*        NO SEGMENT ANGLE FOR LAST POINT */
L650:
	ga = znumbr_1.z0;
L660:
	xa = znumbr_1.z0;
L670:
	iconv_(&ishr17_1.i1, darray_1.darray, &c__1, &c__4, (ftnlen)120);
	fconv_(&dshar6_1.tem[1], darray_1.darray, &c__5, &c__15, &c__4, (
		ftnlen)120);
	fconv_(dshar6_1.tem, darray_1.darray, &c__20, &c__15, &c__6, (ftnlen)
		120);
	fconv_(&tab[ishr17_1.j1 + 12], darray_1.darray, &c__35, &c__15, &c__6,
		 (ftnlen)120);
	fconv_(&tab[ishr17_1.j1 + 13], darray_1.darray, &c__50, &c__15, &c__6,
		 (ftnlen)120);
	fconv_(&tab[ishr17_1.j1 + 16], darray_1.darray, &c__65, &c__15, &c__6,
		 (ftnlen)120);
	fconv_(&ga, darray_1.darray, &c__80, &c__15, &c__4, (ftnlen)120);
	fconv_(&xa, darray_1.darray, &c__95, &c__15, &c__4, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
L672:
	;
    }
/*        WRITE MATCHED CURVATURES */
/*        CHECK TABPRT FLAG */
    if (ldef_1.tabprt) {
	goto L674;
    }
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    cform_(form2, darray_1.darray, &c__2, &c__92, (ftnlen)92, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L674:
    cmin = zlit2;
    cmax = -zlit2;
    i__1 = ishr17_1.n;
    for (ishr17_1.i1 = 1; ishr17_1.i1 <= i__1; ++ishr17_1.i1) {
	ishr17_1.j1 = knumbr_1.k7 * ishr17_1.i1;
	if (ishr17_1.i1 == ishr17_1.n) {
	    goto L675;
	}
	ta = tab[ishr17_1.j1 + 14] - tab[ishr17_1.j1 + 15];
	tb = tab[ishr17_1.j1 + 21] - tab[ishr17_1.j1 + 15];
	d__1 = cos(ta);
	d__2 = cos(tb);
/* Computing MAX */
	d__5 = abs(d__1);
	d__4 = max(d__5,znumbr_1.z1em9);
/* Computing MAX */
	d__7 = abs(d__2);
	d__6 = max(d__7,znumbr_1.z1em9);
/* Computing 3rd power */
	d__8 = (d__3 = cos(ta), abs(d__3));
	dshar6_1.tem[1] = -(4.f * (sin(ta) / d_sign(&d__4, &d__1)) + 2.f * (
		sin(tb) / d_sign(&d__6, &d__2))) * (d__8 * (d__8 * d__8)) / 
		tab[ishr17_1.j1 + 16];
	goto L680;
L675:
	ta = znumbr_1.z0;
	tb = znumbr_1.z0;
	tab[24] = znumbr_1.z0;
	dshar6_1.tem[1] = 0.f;
L680:
	d__1 = cos(ta);
/* Computing MAX */
	d__3 = abs(d__1);
	d__2 = max(d__3,znumbr_1.z1em9);
	ta = sin(ta) / d_sign(&d__2, &d__1);
	d__1 = cos(tb);
/* Computing MAX */
	d__3 = abs(d__1);
	d__2 = max(d__3,znumbr_1.z1em9);
	tb = sin(tb) / d_sign(&d__2, &d__1);
	d__1 = cos(tab[ishr17_1.j1 + 14]);
/* Computing MAX */
	d__3 = abs(d__1);
	d__2 = max(d__3,znumbr_1.z1em9);
	tab[ishr17_1.j1 + 14] = sin(tab[ishr17_1.j1 + 14]) / d_sign(&d__2, &
		d__1);
/* Computing MAX */
	d__3 = (d__1 = tab[ishr17_1.j1 + 14], abs(d__1));
	d__2 = max(d__3,znumbr_1.z1em9);
	phi = atan(znumbr_1.zm1 / d_sign(&d__2, &tab[ishr17_1.j1 + 14])) / 
		znumbr_1.degrad;
	al = phi - tab[ishr17_1.j1 + 18];
	tab[ishr17_1.j1 + 18] = dshar6_1.tem[1];
/*        CHECK TABPRT FLAG */
	if (ldef_1.tabprt) {
	    goto L685;
	}
	iconv_(&ishr17_1.i1, darray_1.darray, &c__1, &c__4, (ftnlen)120);
	fconv_(&tab[ishr17_1.j1 + 14], darray_1.darray, &c__5, &c__12, &c__5, 
		(ftnlen)120);
	fconv_(&phi, darray_1.darray, &c__17, &c__12, &c__4, (ftnlen)120);
	fconv_(&al, darray_1.darray, &c__29, &c__12, &c__4, (ftnlen)120);
	fconv_(&ta, darray_1.darray, &c__41, &c__12, &c__7, (ftnlen)120);
	fconv_(&tb, darray_1.darray, &c__53, &c__12, &c__7, (ftnlen)120);
	fconv_(&tab[ishr17_1.j1 + 18], darray_1.darray, &c__65, &c__10, &c__4,
		 (ftnlen)120);
	fconv_(&tab[ishr17_1.j1 + 17], darray_1.darray, &c__75, &c__13, &c__4,
		 (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
/*        PLOT CURVATURES */
L685:
	tab[ishr17_1.j1 + 14] = ta;
	tab[ishr17_1.j1 + 15] = tb;
/* Computing MIN */
	d__1 = cmin, d__2 = tab[ishr17_1.j1 + 18];
	cmin = min(d__1,d__2);
/* L690: */
/* Computing MAX */
	d__1 = cmax, d__2 = tab[ishr17_1.j1 + 18];
	cmax = max(d__1,d__2);
    }
    cen2 = (cmax - cmin) / znumbr_1.z2;
    for (ishr17_1.j1 = 1; ishr17_1.j1 <= 7; ++ishr17_1.j1) {
	ishr17_1.i1 = ishr17_1.j1;
	if (cen2 <= table[ishr17_1.j1 - 1]) {
	    goto L710;
	}
/* L700: */
    }
    ishr17_1.i1 = 8;
L710:
    curvrg = table[ishr17_1.i1 - 1];
    cen1 = 50.f / curvrg;
    center = cen2 + cmin;
    idumy = (integer) (center * cen1 + d_sign(&znumbr_1.z5em1, &center));
    center = (doublereal) idumy;
    center /= cen1;
    curti1 = center - curvrg;
    curti2 = center - znumbr_1.z5em1 * curvrg;
    dshar6_1.temp = center + znumbr_1.z5em1 * curvrg;
    dshar6_1.tem[0] = center + curvrg;
/*        CHECK TABPRT FLAG */
    if (ldef_1.tabprt) {
	goto L732;
    }
    cform_("0", darray_1.darray, &c__1, &c__1, (ftnlen)1, (ftnlen)120);
    fconv_(&curti1, darray_1.darray, &c__17, &c__7, &c__4, (ftnlen)120);
    fconv_(&curti2, darray_1.darray, &c__42, &c__7, &c__4, (ftnlen)120);
    fconv_(&center, darray_1.darray, &c__67, &c__7, &c__4, (ftnlen)120);
    fconv_(&dshar6_1.temp, darray_1.darray, &c__92, &c__7, &c__4, (ftnlen)120)
	    ;
    fconv_(dshar6_1.tem, darray_1.darray, &c__113, &c__7, &c__4, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);

    cform_(form3, darray_1.darray, &c__1, &c__119, (ftnlen)120, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    kp = knumbr_1.k7 * ishr17_1.n;
    i__1 = kp;
    for (ishr17_1.i1 = 7; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	cform_(".", darray_1.darray, &c__18, &c__1, (ftnlen)1, (ftnlen)120);
	cform_(".", darray_1.darray, &c__119, &c__1, (ftnlen)1, (ftnlen)120);
	ishr17_1.j1 = (integer) (zlit4 - zlit3 * center / curvrg);
/* Computing MIN */
	i__2 = max(ishr17_1.j1,2);
	ishr17_1.j1 = min(i__2,102) + 17;
	cform_(".", darray_1.darray, &ishr17_1.j1, &c__1, (ftnlen)1, (ftnlen)
		120);
	ishr17_1.j1 = (integer) (zlit3 * (tab[ishr17_1.i1 + 18] - center) / 
		curvrg + zlit4);
/* Computing MIN */
	i__2 = max(ishr17_1.j1,2);
	ishr17_1.j1 = min(i__2,102) + 17;
	cform_("*", darray_1.darray, &ishr17_1.j1, &c__1, (ftnlen)1, (ftnlen)
		120);
	ishr17_1.l1 = ishr17_1.i1 / 7;
	iconv_(&ishr17_1.l1, darray_1.darray, &c__1, &c__3, (ftnlen)120);
	fconv_(&tab[ishr17_1.i1 + 18], darray_1.darray, &c__4, &c__12, &c__6, 
		(ftnlen)120);
/* L730: */
	cprint_(darray_1.darray, (ftnlen)120);
    }
    cform_(form3 + 16, darray_1.darray, &c__17, &c__103, (ftnlen)104, (ftnlen)
	    120);
    cprint_(darray_1.darray, (ftnlen)120);
/*        FIT CUBICS TO GIVEN SLOPES - TRANSLATE AND ROTATE TO ELIMINATE */
/*        CONSTANT TERM */
L732:
    i__1 = ishr17_1.nm1;
    for (ishr17_1.i1 = 7; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	tlengt = tab[ishr17_1.i1 + 16];
	s1 = tab[ishr17_1.i1 + 14];
	t1 = tab[ishr17_1.i1 + 15];
/*        COMPUTE COEFFICIENTS OF CUBIC, STORE IN TAB ARRAY */
/* Computing 2nd power */
	d__1 = tab[ishr17_1.i1 + 16];
	tab[ishr17_1.i1 + 14] = (t1 + s1) / (d__1 * d__1);
	tab[ishr17_1.i1 + 15] = (-znumbr_1.z2 * s1 - t1) / tab[ishr17_1.i1 + 
		16];
	tab[ishr17_1.i1 + 16] = s1;
/*        COMPUTE MAXIMUM AND MINIMUM VALUES ON EACH CURVE */
	if ((d__1 = tab[ishr17_1.i1 + 14], abs(d__1)) > znumbr_1.z1em7) {
	    goto L750;
	}
	tab[ishr17_1.i1 + 18] = znumbr_1.z0;
	tab[ishr17_1.i1 + 14] = znumbr_1.z0;
	if ((d__1 = tab[ishr17_1.i1 + 15], abs(d__1)) > znumbr_1.z1em7) {
	    goto L740;
	}
/*        EQUATION IS LINEAR - MUST BE  Y = 0 */
	tab[ishr17_1.i1 + 15] = znumbr_1.z0;
	tab[ishr17_1.i1 + 16] = znumbr_1.z0;
	tab[ishr17_1.i1 + 17] = znumbr_1.z0;
	goto L770;
/*        EQUATION IS QUADRATIC - EXTREMUM AT  -C/2B */
L740:
/* Computing 2nd power */
	d__1 = tab[ishr17_1.i1 + 16];
	tab[ishr17_1.i1 + 17] = -(d__1 * d__1) / (tab[ishr17_1.i1 + 15] * 4.f)
		;
	goto L760;
/*        EQUATION IS CUBIC - SOLVE FOR FIRST DERIVATIVE ZERO */
L750:
/* Computing 2nd power */
	d__1 = tab[ishr17_1.i1 + 15];
	dshar6_1.temp = d__1 * d__1;
	tem1 = tab[ishr17_1.i1 + 14] * 3.f * s1;
	tem3 = (dshar6_1.temp - tem1) * sqrt(dshar6_1.temp - tem1) * 2.f;
	tem2 = tab[ishr17_1.i1 + 15] * (dshar6_1.temp * 2.f - tem1 * 3.f);
	tem4 = tem2 + d_sign(&tem3, &tem2);
/* Computing 2nd power */
	d__1 = s1;
	tem3 = d__1 * d__1 * (tem1 * 1.3333333f - dshar6_1.temp);
/* Computing 2nd power */
	d__1 = tab[ishr17_1.i1 + 14];
	dshar6_1.temp = tem4 / (d__1 * d__1 * 27.f);
	if (znumbr_1.z1 <= 0.) {
	    goto L760;
	} else {
	    goto L755;
	}
L755:
	tem1 = tem3 / tem4;
	tab[ishr17_1.i1 + 17] = dshar6_1.temp;
	tab[ishr17_1.i1 + 18] = tem1;
/*        TEST FOR MAX GREATER THAN MIN */
L760:
	if (tab[ishr17_1.i1 + 17] >= tab[ishr17_1.i1 + 18]) {
	    goto L769;
	}
	dshar6_1.temp = tab[ishr17_1.i1 + 17];
	tab[ishr17_1.i1 + 17] = tab[ishr17_1.i1 + 18];
	tab[ishr17_1.i1 + 18] = dshar6_1.temp;
/*        MAX OR MIN MUST BE WITHIN INTERVAL */
L769:
	if (s1 <= znumbr_1.z0 && t1 >= znumbr_1.z0) {
	    tab[ishr17_1.i1 + 17] = znumbr_1.z0;
	}
	if (s1 >= znumbr_1.z0 && t1 <= znumbr_1.z0) {
	    tab[ishr17_1.i1 + 18] = znumbr_1.z0;
	}
L770:
	tab[ishr17_1.i1 + 17] /= tlengt;
	tab[ishr17_1.i1 + 18] /= tlengt;
	tab[ishr17_1.i1 + 16] = tlengt;
/* L771: */
    }
/*        COMPUTE EXTENSION INTERVALS */
/*        EXTENSION EQUIVALENT TO  10 INCH. REGARDLESS OF UNITS */
    dst = xunits_1.tabext;
/* Computing 2nd power */
    d__1 = dshar6_1.sb;
    delta = dst / sqrt(znumbr_1.z1 + d__1 * d__1);
    if ((tab[20] - tab[27]) * dshar6_1.sb + tab[19] - tab[26] < znumbr_1.z0) {
	delta = -delta;
    }
    tab[12] = tab[19] + delta;
    tab[13] = tab[20] + delta * dshar6_1.sb;
/* Computing 2nd power */
    d__1 = se2;
    delta = dst / sqrt(znumbr_1.z1 + d__1 * d__1);
    if ((tab[ishr17_1.i__ - 8] - tab[ishr17_1.i__ - 15]) * se2 + tab[
	    ishr17_1.i__ - 9] - tab[ishr17_1.i__ - 16] < znumbr_1.z0) {
	delta = -delta;
    }
    tab[ishr17_1.i__ - 2] = tab[ishr17_1.i__ - 9] + delta;
    tab[ishr17_1.i__ - 1] = tab[ishr17_1.i__ - 8] + delta * se2;
    for (ishr17_1.i1 = 15; ishr17_1.i1 <= 19; ++ishr17_1.i1) {
	tab[ishr17_1.i1 - 1] = znumbr_1.z0;
	ishr17_1.j1 = knumbr_1.k7 * ishr17_1.n + ishr17_1.i1;
/* L780: */
	tab[ishr17_1.j1 - 1] = znumbr_1.z0;
    }
/*        REDUCE EXTENSION IF NECESSARY */
    if ((d__1 = dshar6_1.sb - se2, abs(d__1)) < zlit6) {
	goto L790;
    }
    x = (tab[ishr17_1.i__ - 8] - tab[13] + dshar6_1.sb * tab[12] - se2 * tab[
	    ishr17_1.i__ - 9]) / (dshar6_1.sb - se2);
    a1 = x - tab[12];
    b1 = dshar6_1.sb * a1;
/* Computing 2nd power */
    d__1 = a1;
/* Computing 2nd power */
    d__2 = b1;
/* Computing 2nd power */
    d__3 = dst;
    if (d__1 * d__1 + d__2 * d__2 > d__3 * d__3) {
	goto L790;
    }
    y = b1 + tab[13];
/* Computing 2nd power */
    d__1 = x - tab[ishr17_1.i__ - 9];
/* Computing 2nd power */
    d__2 = y - tab[ishr17_1.i__ - 8];
/* Computing 2nd power */
    d__3 = dst;
    if (d__1 * d__1 + d__2 * d__2 > d__3 * d__3) {
	goto L790;
    }
    if ((x - tab[19]) * (tab[26] - tab[19]) + (y - tab[20]) * (tab[27] - tab[
	    20]) > znumbr_1.z0) {
	goto L790;
    }
    if ((x - tab[ishr17_1.i__ - 9]) * (tab[ishr17_1.i__ - 16] - tab[
	    ishr17_1.i__ - 9]) + (y - tab[ishr17_1.i__ - 8]) * (tab[
	    ishr17_1.i__ - 15] - tab[ishr17_1.i__ - 8]) > znumbr_1.z0) {
	goto L790;
    }
    tab[12] = x - znumbr_1.z1em2 * (x - tab[19]);
    tab[13] = y - znumbr_1.z1em2 * (y - tab[20]);
    tab[ishr17_1.i__ - 2] = x - znumbr_1.z1em2 * (x - tab[ishr17_1.i__ - 9]);
    tab[ishr17_1.i__ - 1] = y - znumbr_1.z1em2 * (y - tab[ishr17_1.i__ - 8]);
    cform_(form4, darray_1.darray, &c__1, &c__26, (ftnlen)28, (ftnlen)120);
    fconv_(&x, darray_1.darray, &c__27, &c__15, &c__8, (ftnlen)120);
    cform_(form5, darray_1.darray, &c__46, &c__3, (ftnlen)4, (ftnlen)120);
    fconv_(&y, darray_1.darray, &c__49, &c__15, &c__8, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
L790:
/* Computing 2nd power */
    d__1 = tab[19] - tab[12];
/* Computing 2nd power */
    d__2 = tab[20] - tab[13];
    tab[16] = sqrt(d__1 * d__1 + d__2 * d__2);
/* Computing 2nd power */
    d__1 = tab[ishr17_1.i__ - 1] - tab[ishr17_1.i__ - 8];
/* Computing 2nd power */
    d__2 = tab[ishr17_1.i__ - 2] - tab[ishr17_1.i__ - 9];
    tab[ishr17_1.i__ - 5] = sqrt(d__1 * d__1 + d__2 * d__2);
/*        CHECK TABPRT FLAG */
    if (ldef_1.tabprt) {
	goto L796;
    }
    cform_(form7, darray_1.darray, &c__1, &c__16, (ftnlen)16, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    ishr17_1.l = 1;
    for (ishr17_1.i1 = 2; ishr17_1.i1 <= 10; ++ishr17_1.i1) {
	fconv_(&tab[ishr17_1.i1 - 1], darray_1.darray, &ishr17_1.l, &c__13, &
		c__6, (ftnlen)120);
/* L791: */
	ishr17_1.l += 13;
    }
    cprint_(darray_1.darray, (ftnlen)120);
    cform_(form9, darray_1.darray, &c__1, &c__100, (ftnlen)100, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    i__1 = ishr17_1.i__;
    for (ishr17_1.i1 = 13; ishr17_1.i1 <= i__1; ishr17_1.i1 += 7) {
	ishr17_1.l = 1;
	for (ishr17_1.j1 = 1; ishr17_1.j1 <= 7; ++ishr17_1.j1) {
	    ishr17_1.l1 = ishr17_1.i1 + ishr17_1.j1 - 1;
	    if (ishr17_1.l1 > ishr17_1.i__) {
		goto L9094;
	    }
	    fconv_(&tab[ishr17_1.l1 - 1], darray_1.darray, &ishr17_1.l, &
		    c__15, &c__8, (ftnlen)120);
/* L9096: */
	    ishr17_1.l += 15;
	}
L9094:
	cprint_(darray_1.darray, (ftnlen)120);
/* L9095: */
    }
L796:
    a[2] = tab[0];
    apt094_(&c__1, &a[1], tab);
    return 0;
} /* apt089_ */

#undef bcanon
#undef sscan
#undef canon
#undef rotm
#undef tab
#undef can


