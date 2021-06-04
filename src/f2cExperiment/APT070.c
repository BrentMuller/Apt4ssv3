/* APT070.f -- translated by f2c (version 20100827).
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
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

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
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__3 = 3;
static doublereal c_b32 = 1e-14;

/* *** SOURCE FILE : M0002232.V06   *** */


/* .....FORTRAN SUBROUTINE  ....APT070         8/68                 HG,RN */

/*              FORTRAN SUBROUTINE APT070 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A LINE THRU */
/*              A POINT AND TANGENT OR NORMAL TO A TABCYL IN */
/*              THE XY PLANE DEFINED BY THE FOLLOWING APT */
/*              STATEMENT */
/*                RESULT = LINE/PT,TANTO,TAB,PT2 */
/*                RESULT = LINE/PT,PERPTO,TAB,PT2 */

/* LINKAGE      CALL APT070 (RESULT,PT,MM,TAB,PT2) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING LINE */
/*              PT      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */
/*              MM      INTEGER EQUIVALENT OF THE MODIFIER */
/*                          1=TANTO    2=PERPTO */
/*              TAB     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT TABCYL */
/*              PT2     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          TRANRO */
/*              SUBROUTINE          POLYR */
/*              SUBROUTINE          APT094 */
/*              LOGICAL FUNCTION    CKDEF */
/*              SUBROUTINE          SCHTB */



/* Subroutine */ int apt070_(doublereal *result, doublereal *pt, integer *mm, 
	doublereal *tab, doublereal *pt2)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), atan(doublereal), sqrt(
	    doublereal);

    /* Local variables */
#define d__ ((doublereal *)&_BLNK__1)
    static integer i__, j;
    static doublereal a1, b1, r1, aa[22], cc;
    static integer j11, nt;
    static doublereal xa;
    static integer iz;
    static doublereal ya, ra, xb, yb, xc, yc, xd, yd, ry;
    static integer ii, nn, it;
    static doublereal x11, y11, sq;
    static integer kx, jj, mx;
    static doublereal eq1, eq2;
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer ine[3], ite, ihu;
    static doublereal tol;
    static integer inz, izt;
    static doublereal equ2;
    static integer luck, ihut;
    static doublereal slop;
    static integer itry;
    extern /* Subroutine */ int apt014_(doublereal *, doublereal *, 
	    doublereal *), apt094_(integer *, doublereal *, integer *);
    extern logical ckdef_(doublereal *);
    static integer ifall;
    static doublereal delta;
#define canon ((doublereal *)&_BLNK__1)
    extern /* Subroutine */ int schtb_(doublereal *);
#define sscan ((doublereal *)&_BLNK__1 + 40)
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int defext_(doublereal *);
    static doublereal borslp;
    extern /* Subroutine */ int tranro_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static doublereal sqroot;


/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* ...  VARIABLES XA,YA,RA,XB,YB,XC,YC,XD,YD,TOL,EQU2,SLOP,R1,RY,BORSLP, */
/* ...  X11,Y11,EQ1,EQ2 & DELTA WERE ALL EQUIVALENCED TO SUCCESSIVE */
/* ...  ELEMENTS OF SC.  AS THEIR USEAGE SEEMED TO BE LOCAL, THE */
/* ...  EQUIVALENCE HAS BEEN REMOVED. */




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */




/*   *** 16.  ISHARE16 BLOCK *** */

/*   THESE ALL APPEAR TO BE USED AS LOCAL VARIABLES */

/*   I.E.  I,J,K,M,N,J11,L11,M11 */



/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */




    /* Parameter adjustments */
    --pt2;
    --tab;
    --pt;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 2; ++i__) {
	dshar3_1.p[i__ - 1] = pt2[i__];
	dshar3_1.v[i__ - 1] = pt[i__];
/* L10: */
	dshar3_1.c__[i__ - 1] = tab[i__];
    }
    ldef_1.unflag = ckdef_(dshar3_1.p) || ckdef_(dshar3_1.v) || ckdef_(
	    dshar3_1.c__);
    if (ldef_1.unflag) {
	goto L9998;
    }

/* ... RETRIEVE TABCYL EXTERNAL CANONICAL FORM. STORE CANON INDEX IN J11. */

    apt094_(&c__3, &tab[1], &j11);
    if (ckdef_(&tab[1])) {
	goto L9998;
    }

/* ...  FIND PART OF TABCYL CLOSEST TO INPUT P,USING SCHTB */

    schtb_(&canon[j11 - 2]);
    ihu = (integer) (canon[j11 + 10] + znumbr_1.z1em2);
    itry = knumbr_1.k0;
    nt = (integer) ((canon[j11 + 9] - znumbr_1.z1) * 7.f + 21.1f);
    --j11;
    ihu = ihu + j11 - knumbr_1.k1;
    goto L2;
/* .....TRANSLATE AND ROTATE INTO COORDINATE SYSTEM OF THE SELECTED */
/* .....TABCYL INTERBAL */

L12:
    if (itry - 7 >= 0) {
	goto L13;
    } else {
	goto L2;
    }
L2:
    xa = d__[ihu + 6] - d__[ihu - 1];
    ihut = ihu;
    if (*mm != 1) {
	goto L412;
    }
/* L411: */
    ite = j11 + nt - 16;
    izt = j11 + 13;
    goto L413;
/* .....EXTENSION INTERVALS ARE INCLUDED IN THE NORMAL LINE SEARCH. */
L412:
    ite = j11 + nt - 9;
    izt = j11 + 6;
L413:
    iz = 1;
    ya = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(ya / d_sign(&d__1, &xa));
    if (xa >= 0.) {
	goto L1001;
    } else {
	goto L1000;
    }
L1000:
    ra += znumbr_1.pi;
L1001:
    tranro_(&xa, &ya, &xb, &yb, &ra, &iz);
    xc = dshar3_1.v[0] - d__[ihu - 1];
    yc = dshar3_1.v[1] - d__[ihu];
    tranro_(&xc, &yc, &xd, &yd, &ra, &iz);

/* .... TEST TO SEE IF GIVEN POINT IS ON OR OFF TABCYL */

    tol = znumbr_1.z1em5;
    if (xb + tol - xd >= 0.) {
	goto L71;
    } else {
	goto L206;
    }
L71:
    if (xd + tol >= 0.) {
	goto L72;
    } else {
	goto L206;
    }
L72:
/* Computing 3rd power */
    d__1 = xd;
/* Computing 2nd power */
    d__2 = xd;
    equ2 = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * 
	    d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 
	    3] * xd);
    if ((d__1 = yd - equ2, abs(d__1)) - tol <= 0.) {
	goto L70;
    } else {
	goto L206;
    }
L206:
    if (*mm != 1) {
	goto L207;
    }
    goto L73;
L70:
/* Computing 2nd power */
    d__1 = xd;
    slop = znumbr_1.z3 * d__[ihu + 1] * (d__1 * d__1) + znumbr_1.z2 * d__[ihu 
	    + 2] * xd - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[
	    ihu + 3];
/* ---    CORRECTION FOR LINE/PT,PERPTO,TAB,REF */
    if (*mm == 2) {
	goto L200;
    }
L290:
    if (slop != 0.) {
	goto L291;
    } else {
	goto L76;
    }
L291:
    if (abs(slop) - znumbr_1.z1 >= 0.) {
	goto L74;
    } else {
	goto L76;
    }
L74:
    r1 = xd - znumbr_1.z1 / slop;
    ry = yd - znumbr_1.z1;
    goto L79;
L76:
    r1 = xd - znumbr_1.z1;
    ry = yd - slop;
    goto L79;
L200:
    if (abs(slop) - znumbr_1.z1em6 >= 0.) {
	goto L202;
    } else {
	goto L201;
    }
L201:
    if (slop >= 0.) {
	goto L204;
    } else {
	goto L203;
    }
L203:
    borslp = 9999999.f;
    goto L205;
L204:
    borslp = -9999999.f;
    goto L205;
L202:
    borslp = -1.f / slop;
L205:
    slop = borslp;
    goto L290;

/* .....CALCULATE COEFFICIENTS OF THE CUBIC EQUATION AND SOLVE FOR */
/*     THE POINTS OF TANGENCY */

L73:
    aa[0] = znumbr_1.z2 * d__[ihu + 1];
    if (abs(aa[0]) - 1e-14 >= 0.) {
	goto L1237;
    } else {
	goto L1236;
    }
L1236:
    aa[0] = d_sign(&c_b32, aa);
L1237:
    aa[1] = d__[ihu + 2] - znumbr_1.z3 * d__[ihu + 1] * xd;
    aa[2] = -znumbr_1.z2 * d__[ihu + 2] * xd;
    aa[3] = yd + (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] 
	    * xd);
    for (i__ = 1; i__ <= 22; ++i__) {
/* L16: */
	dshar3_1.t[i__ - 1] = znumbr_1.z0;
    }
    ifall = knumbr_1.k0;
    ii = knumbr_1.k3;
    nn = knumbr_1.k7;
    goto L500;
L540:

/* .....TEST FOR ERRORS */

/* L21: */
    if (ifall == knumbr_1.k0) {
	goto L3;
    }
    idef_1.ierror = 75;
    goto L9999;

/* .....ROOTS FOUND OK, TEST THEIR POSITIONS WITH RESPECT TO THE */
/* .....BOUNDARY POINTS OF THE INTERVAL */

L3:
    it = -1;
    luck = knumbr_1.k0;
    for (i__ = 1; i__ <= 3; ++i__) {
	ine[i__ - 1] = knumbr_1.k0;
	it += knumbr_1.k2;
	if (dshar3_1.t[it] != 0.) {
	    goto L24;
	} else {
	    goto L30;
	}
L30:
	if (dshar3_1.t[it - 1] + znumbr_1.z1em6 <= 0.) {
	    goto L24;
	} else {
	    goto L25;
	}
L25:
	if (dshar3_1.t[it - 1] * (xb - dshar3_1.t[it - 1]) >= 0.) {
	    goto L26;
	} else {
	    goto L24;
	}
L26:
	luck += knumbr_1.k1;
	ine[i__ - 1] = it;
L24:
	;
    }
    if ((i__1 = luck - 1) < 0) {
	goto L27;
    } else if (i__1 == 0) {
	goto L28;
    } else {
	goto L4;
    }

/* .....MULTIPLE TANGENCY POINTS IN THE INTERVAL */

L4:
    xa = d__[ihu + 6] - d__[ihu - 1];
    ya = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(ya / d_sign(&d__1, &xa));
    if (xa >= 0.) {
	goto L1003;
    } else {
	goto L1002;
    }
L1002:
    ra += znumbr_1.pi;
L1003:
    it = -1;
    iz = -1;
    for (i__ = 1; i__ <= 3; ++i__) {
	it += knumbr_1.k2;
	if (ine[i__ - 1] != 0) {
	    goto L299;
	} else {
	    goto L301;
	}
L299:
	r1 = dshar3_1.t[it - 1];
/* Computing 3rd power */
	d__1 = r1;
/* Computing 2nd power */
	d__2 = r1;
	ry = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (d__2 * 
		d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * (d__[
		ihu + 3] * r1);
	tranro_(&r1, &ry, &xa, &ya, &ra, &iz);
	r1 = xa + d__[ihu - 1];
	ry = ya + d__[ihu];
L301:
	;
    }
    idef_1.ierror = 73;
    goto L9999;

/* .....TEST FOR NORMAL LINE WHEN GIVEN POINT */
/*     IS NOT A POINT ON THE TABCYL */
/*     CALCULATE COEFFICIENTS FOR A FIFTH-ORDER EQUATION */
/*     WHICH DEFINES A POINT ON THE TABCYL INTERVAL (CUBIC EQUATION) */
/*     WHERE THE NORMAL TO THE INTERVAL PASSES THRU THE GIVEN POINT. */

L207:
/* Computing 2nd power */
    d__1 = d__[ihu + 1];
    dshar3_1.t1[0] = znumbr_1.z3 * (d__1 * d__1);
    dshar3_1.t1[1] = znumbr_1.z5 * d__[ihu + 1] * d__[ihu + 2];
/* Computing 2nd power */
    d__1 = d__[ihu + 2];
    dshar3_1.t1[2] = d__[ihu + 1] * 4.f * (znumbr_1.zm1 * (d__[ihu + 1] * d__[
	    ihu + 3] + d__[ihu + 2]) * d__[ihu + 3]) + znumbr_1.z2 * (d__1 * 
	    d__1);
    dshar3_1.t1[3] = znumbr_1.z3 * d__[ihu + 2] * (-(d__[ihu + 1] * d__[ihu + 
	    3] + d__[ihu + 2]) * d__[ihu + 3]) - znumbr_1.z3 * d__[ihu + 1] * 
	    yd;
/* Computing 2nd power */
    d__1 = -(d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * d__[ihu + 3];
    dshar3_1.t1[4] = d__1 * d__1 - znumbr_1.z2 * d__[ihu + 2] * yd + 
	    znumbr_1.z1;
    dshar3_1.t1[5] = xd - yd * (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * 
	    d__[ihu + 3];
    dshar3_1.t1[6] = znumbr_1.z5 * dshar3_1.t1[0];
    dshar3_1.t1[7] = dshar3_1.t1[1] * 4.f;
    dshar3_1.t1[8] = znumbr_1.z3 * dshar3_1.t1[2];
    dshar3_1.t1[9] = znumbr_1.z2 * dshar3_1.t1[3];
    dshar3_1.t1[10] = dshar3_1.t1[4];
/* .....(X11,Y11) IS THE END POINT OF THE INTERVAL BEING */
/* .....CONSIDERED THAT IS NEAREST TO THE SPECIFIED POINT. */
    tranro_(&d__[nt - 1], &d__[nt], &x11, &y11, &ra, &iz);
    if (x11 < 0.) {
	goto L40;
    } else if (x11 == 0) {
	goto L44;
    } else {
	goto L41;
    }
L40:
    x11 = znumbr_1.z0;
    goto L44;
L41:
    if ((d__1 = x11 - znumbr_1.z5em1 * xb) < 0.) {
	goto L40;
    } else if (d__1 == 0) {
	goto L44;
    } else {
	goto L43;
    }
L43:
    x11 = xb;
/* .....NEWTONS METHOD IS USED TO SOLVE THE FIFTH ORDER */
/*     EQUATION. X11 IS THE INITIAL ESTIMATE OF THE ROOT. */
L44:
    for (j = 1; j <= 200; ++j) {
	eq1 = ((((dshar3_1.t1[0] * x11 + dshar3_1.t1[1]) * x11 + dshar3_1.t1[
		2]) * x11 + dshar3_1.t1[3]) * x11 + dshar3_1.t1[4]) * x11 - 
		dshar3_1.t1[5];
	eq2 = (((dshar3_1.t1[6] * x11 + dshar3_1.t1[7]) * x11 + dshar3_1.t1[8]
		) * x11 + dshar3_1.t1[9]) * x11 + dshar3_1.t1[10];
	if (znumbr_1.z1 >= 0.) {
	    goto L461;
	} else {
	    goto L46;
	}
L461:
	delta = -eq1 / eq2;
	if (abs(delta) - 3e-6 >= 0.) {
	    goto L46;
	} else {
	    goto L47;
	}
L46:
	x11 += delta;
/* L45: */
    }
    goto L27;
L47:
    if (x11 + znumbr_1.z5em6 >= 0.) {
	goto L112;
    } else {
	goto L27;
    }
L112:
    if (xb + znumbr_1.z5em6 - x11 >= 0.) {
	goto L113;
    } else {
	goto L27;
    }
L113:
    y11 = (d__[ihu + 1] * x11 + d__[ihu + 2]) * x11 * x11 - (d__[ihu + 1] * 
	    d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] * x11);
    r1 = x11;
    ry = y11;
    goto L79;

/* .....TANGENCY POINT NOT FOUND OR NOT IN INTERVAL, */
/*     SET UP FOR RE-TRY UNTIL 3 INTERVALS ON EACH SIDE OF THE INITIAL */
/*     INTERVAL HAVE BEEN TRIED------A TOTAL OF 7 INTERVALS. */
/* .....  (EXTENSION INTERVALS ARE INCLUDED FOR NORMAL LINE ONLY) */

L27:
    ++itry;
    switch (itry) {
	case 1:  goto L29;
	case 2:  goto L900;
	case 3:  goto L904;
	case 4:  goto L905;
	case 5:  goto L906;
	case 6:  goto L907;
	case 7:  goto L13;
    }
L29:
    ihu += 7;
L902:
    if (ihu - ite >= 0) {
	goto L27;
    } else {
	goto L12;
    }
L900:
    ihu += -14;
L903:
    if (ihu - izt <= 0) {
	goto L27;
    } else {
	goto L12;
    }
L904:
    ihu += 21;
    goto L902;
L905:
    ihu += -28;
    goto L903;
L906:
    ihu += 35;
    goto L902;
L907:
    ihu += -42;
    goto L903;
L13:
    if (*mm != 1) {
	goto L408;
    }
    idef_1.ierror = 74;
    goto L9999;
L408:
    idef_1.ierror = 74;
    goto L9999;

/* .....TANGENCY POINT FOUND, CALCULATE SECOND COORDINATE AND TRANSFORM */
/*     THE POINT BACK TO THE XY-PLANE */

L28:
    for (i__ = 1; i__ <= 3; ++i__) {
	if (ine[i__ - 1] != 0) {
	    goto L33;
	}
/* L32: */
    }
L33:
    inz = ine[i__ - 1];
    r1 = dshar3_1.t[inz - 1];
/* L9: */
/* Computing 2nd power */
    d__1 = r1;
    ry = (d__[ihu + 1] * r1 + d__[ihu + 2]) * (d__1 * d__1) - (d__[ihu + 1] * 
	    d__[ihu + 3] + d__[ihu + 2]) * (d__[ihu + 3] * r1);
L79:
    iz = -1;
    xa = d__[ihu + 6] - d__[ihu - 1];
    ya = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(ya / d_sign(&d__1, &xa));
    if (xa >= 0.) {
	goto L1005;
    } else {
	goto L1004;
    }
L1004:
    ra += znumbr_1.pi;
L1005:
    tranro_(&r1, &ry, &xa, &ya, &ra, &iz);
    dshar3_1.g[0] = d__[ihu - 1] + xa;
    dshar3_1.g[1] = d__[ihu] + ya;
    dshar3_1.g[2] = znumbr_1.z0;

/* .....CALCULATE CANONICAL FORM OF A LINE THRU TWO POINTS IN */
/*     THE XY-PLANE */

    dshar3_1.v[2] = znumbr_1.z0;
    apt014_(&result[1], dshar3_1.v, dshar3_1.g);
L163:
    return 0;
L9998:
    idef_1.ierror = 76;
L9999:
    defext_(&result[1]);
    goto L163;
L500:
    a1 = znumbr_1.z3 * aa[0];
    b1 = znumbr_1.z2 * aa[1];
    cc = aa[2];
    sqroot = d__[ihu + 3];
/* Computing 2nd power */
    d__1 = b1;
    sq = d__1 * d__1 - a1 * 4.f * cc;
    if (abs(sq) >= znumbr_1.z1em7) {
	goto L501;
    }
    kx = knumbr_1.k2;
    dshar3_1.t[1] = -b1 / (znumbr_1.z2 * a1);
    goto L504;
L501:
    if (sq <= 0.) {
	goto L502;
    } else {
	goto L503;
    }
L502:
    kx = knumbr_1.k0;
    goto L504;
L503:
    kx = knumbr_1.k3;
    d__1 = sqrt(sq);
    sq = -b1 - d_sign(&d__1, &b1);
    if (sq <= znumbr_1.z0) {
	goto L502;
    }
    dshar3_1.t[1] = znumbr_1.z2 * cc / sq;
    if (sq <= znumbr_1.z0) {
	goto L502;
    }
    dshar3_1.t[2] = sq / (znumbr_1.z2 * a1);
    goto L521;
L504:
    dshar3_1.t[0] = znumbr_1.z5em1 * sqroot;
    goto L510;
L521:
    for (jj = 1; jj <= 2; ++jj) {
/* L505: */
	dshar3_1.t1[jj - 1] = ((aa[0] * dshar3_1.t[jj] + aa[1]) * dshar3_1.t[
		jj] + aa[2]) * dshar3_1.t[jj] + aa[3];
    }
    if (dshar3_1.t1[0] * dshar3_1.t1[1] >= 0.) {
	goto L507;
    } else {
	goto L506;
    }
L506:
    dshar3_1.t[0] = (dshar3_1.t[1] + dshar3_1.t[2]) * znumbr_1.z5em1;
    goto L510;
L507:
    if (abs(dshar3_1.t1[0]) - abs(dshar3_1.t1[1]) >= 0.) {
	goto L509;
    } else {
	goto L508;
    }
L508:
    dshar3_1.t[0] = znumbr_1.z12em1 * dshar3_1.t[2] - dshar3_1.t[1] * .2f;
    goto L510;
L509:
    dshar3_1.t[0] = znumbr_1.z12em1 * dshar3_1.t[1] - dshar3_1.t[2] * .2f;
L510:
/* Computing MIN */
    d__1 = max(dshar3_1.t[0],znumbr_1.z0);
    dshar3_1.t[0] = min(d__1,sqroot);
    dshar3_1.t1[0] = znumbr_1.z3 * aa[0];
    dshar3_1.t1[1] = znumbr_1.z2 * aa[1];
    dshar3_1.t1[2] = aa[2];
    for (mx = 1; mx <= 100; ++mx) {
	dshar3_1.t1[3] = (dshar3_1.t1[0] * dshar3_1.t[0] + dshar3_1.t1[1]) * 
		dshar3_1.t[0] + dshar3_1.t1[2];
	if (abs(dshar3_1.t1[3]) - 1e-20 >= 0.) {
	    goto L512;
	} else {
	    goto L511;
	}
L511:
	dshar3_1.t[0] += znumbr_1.z1em6;
	goto L520;
L512:
	dshar3_1.t1[3] = (((aa[0] * dshar3_1.t[0] + aa[1]) * dshar3_1.t[0] + 
		aa[2]) * dshar3_1.t[0] + aa[3]) / dshar3_1.t1[3];
	if (abs(dshar3_1.t1[3]) < znumbr_1.z1em6 * abs(dshar3_1.t[0])) {
	    goto L530;
	}
	dshar3_1.t[0] -= dshar3_1.t1[3];
L520:
	;
    }
    ifall = 1;
L530:
    dshar3_1.t[1] = znumbr_1.z0;
    a1 = aa[0];
    b1 = aa[0] * dshar3_1.t[0] + aa[1];
    cc = b1 * dshar3_1.t[0] + aa[2];
/* Computing 2nd power */
    d__1 = b1;
    sq = d__1 * d__1 - a1 * 4.f * cc;
    if (abs(sq) >= znumbr_1.z1em7) {
	goto L531;
    }
    dshar3_1.t[2] = -b1 / (znumbr_1.z2 * a1);
    dshar3_1.t[3] = znumbr_1.z0;
    dshar3_1.t[5] = znumbr_1.z1;
    goto L539;
L531:
    if (sq <= 0.) {
	goto L532;
    } else {
	goto L533;
    }
L532:
    dshar3_1.t[3] = znumbr_1.z1;
    dshar3_1.t[5] = znumbr_1.z1;
    goto L539;
L533:
    d__1 = sqrt(sq);
    sq = -b1 - d_sign(&d__1, &b1);
    if (sq <= znumbr_1.z0) {
	goto L532;
    }
    dshar3_1.t[2] = znumbr_1.z2 * cc / sq;
    if (sq <= znumbr_1.z0) {
	goto L532;
    }
    dshar3_1.t[4] = sq / (znumbr_1.z2 * a1);
    dshar3_1.t[3] = znumbr_1.z0;
    dshar3_1.t[5] = znumbr_1.z0;
L539:
    goto L540;
} /* apt070_ */

#undef bcanon
#undef sscan
#undef canon
#undef can
#undef d__


