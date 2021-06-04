/* APT034.f -- translated by f2c (version 20100827).
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
static doublereal c_b42 = 9e7;

/* *** SOURCE FILE : M0000784.V06   *** */



/*              FORTRAN SUBROUTINE APT034 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CIRCLE,OF A */
/*              GIVEN RADIUS, TANGENT TO A LINE AND A TABULATED */
/*              CYLINDER IN THE XYPLANE. */

/*              A CIRCLE IS DEFINED BY THE FOLLOWING STATEMENT */
/*                RESULT = CIRCLE/ TANTO,LIN,****,TAB,****, $ */
/*                                 PT,RADIUS,RADI */
/*                **** = XLARGE, YLARGE, XSMALL, YSMALL */

/* LINKAGE      CALL APT034 (RESULT, LIN, M1, TAB, M2, PT, RADI) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF */
/*                      THE RESULTING CIRCLE */
/*              LIN     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT LINE */
/*              M1      INTEGER EQUIVALENT OF THE FIRST MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              TAB     ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT TABCYL */
/*              M2      INTEGER EQUIVALENT OF THE SECOND MODIFIER */
/*                             1 = XLARGE       2 = YLARGE */
/*                             4 = XSMALL       5 = YSMALL */
/*              PT      ARRAY CONTAINING THE CANONICAL FORM OF */
/*                      THE INPUT POINT */


/* Subroutine */ int apt034_(doublereal *result, doublereal *lin, integer *m1,
	 doublereal *tab, integer *m2, doublereal *pt, doublereal *radi)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;
    static doublereal equiv_5[1];

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), atan(doublereal), cos(
	    doublereal), sin(doublereal), sqrt(doublereal);

    /* Local variables */
#define d__ ((doublereal *)&_BLNK__1)
    static integer i__;
    static doublereal cc, dd[5];
    static integer j11;
    static doublereal xn[11], yn[11];
    static integer nt, iz;
    static doublereal ra, xf, yf, xi, px, py, xp, yp, x11, y11, xa, ya;
    static integer j111;
#define can ((doublereal *)&_BLNK__1 + 40)
    static doublereal rad, xaa, yaa, xbb, ybb, dis, rra;
    static integer ihu, itl, ntz, imod;
    static doublereal vmod[8]	/* was [4][2] */;
    static integer inum, ihut, itfr, more, less;
#define unit (equiv_5)
#define uint (equiv_5)
    static doublereal dotp, xxaa;
    static integer lout;
    static doublereal yyaa;
    static integer iizz;
    static doublereal disp;
    static integer itry;
    static doublereal dist;
    extern /* Subroutine */ int apt011_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), apt083_(doublereal *, integer *), 
	    apt094_(integer *, doublereal *, integer *);
    static doublereal savd6, uint2;
    extern logical ckdef_(doublereal *);
    static doublereal delta;
#define canon ((doublereal *)&_BLNK__1)
    static doublereal diamt, bnlin;
    extern /* Subroutine */ int schtb_(doublereal *);
    static doublereal bplin;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer isave;
    static doublereal clope, dmove;
    static integer imore, ilast, iless;
    static doublereal deltx, slope, toler, xcomp, ycomp, xlong, ylong;
    static integer ilout;
    static doublereal xaxis, yaxis;
    static integer kount;
    static doublereal xmove, ymove, xtest, d3save, d6save;
    static integer ibacfg;
    static doublereal x1plin, y1plin;
    static integer kcheck;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern logical lindef_(doublereal *, integer *);
    static integer idecrs;
    extern /* Subroutine */ int defext_(doublereal *), chkret_(integer *, 
	    doublereal *, integer *, doublereal *, doublereal *);
    static doublereal costha;
    static integer incres;
    static doublereal savxbb, cslope, vecnrl[11], epsiln, dpvalu;
    static integer itbpnt, icount;
    static doublereal radsqr;
    static integer ihuint;
    extern /* Subroutine */ int tranro_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static integer intrct;
    static doublereal slplin, xlenth;
    static integer ifirst;
    static doublereal vecnrx, vecnry, slpnor, sauint;
    static integer iontst;
    static doublereal axisxv, axisyv, xstart, xintrs[11], yintrs[11];




/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */






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
    --pt;
    --tab;
    --lin;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 2; ++i__) {
	dshar3_1.p[i__ - 1] = pt[i__];
	dshar3_1.l[i__ - 1] = lin[i__];
/* L777: */
	dshar3_1.v[i__ - 1] = tab[i__];
    }
    dshar3_1.l[2] = lin[3];
    dshar3_1.l[3] = lin[4];
    ldef_1.unflag = lindef_(dshar3_1.l, &knumbr_1.k5) || ckdef_(dshar3_1.p) ||
	     ckdef_(dshar3_1.v);
    if (ldef_1.unflag) {
	goto L9998;
    }

/* ...  RETRIEVE TABCYL EXTERNAL CANONICAL FORM. STORE CANON INDEX IN J11. */

    apt094_(&c__3, &tab[1], &j11);
    j11 += -2;










/* .....INITIALIZE */

    idef_1.ierror = 0;
    toler = 2.5e-5f;

/* ...   INUM=1 IF RADIUS PARALLEL LINE INTERSECTS TABCYL, */
/*           2 IF DIA. + TOL. PARALLEL LINE INTERSECTS, */
/*           3 IF LINE + TOL. INTERSECTS */

    inum = 0;

/* ...   IBACFG=0 IF DIRECTION OF SEARCH IS FWD,1 IF BACKWARD */

    ibacfg = 0;

/* ...   ICOUNT IS COUNTER ON TABCYL INTERVALS SEARCHED */

    icount = 1;
    kcheck = 0;
    iontst = 0;
    itbpnt = 0;
    vmod[0] = 1.f;
    vmod[1] = -1.f;
    vmod[2] = 0.f;
    vmod[3] = 0.f;
    vmod[4] = 0.f;
    vmod[5] = 0.f;
    vmod[6] = 1.f;
    vmod[7] = -1.f;

/* .....CHECK FOR NEGATIVE P IN LINE CANONICAL FORM.  LX+MY+NZ=P */

    if (dshar3_1.l[3] >= znumbr_1.z0) {
	goto L921;
    }
    dshar3_1.l[3] = -dshar3_1.l[3];
    dshar3_1.l[1] = -dshar3_1.l[1];
    dshar3_1.l[2] = -dshar3_1.l[2];
    dshar3_1.l[0] = -dshar3_1.l[0];
L921:
    ilout = 0;
    lout = 0;
    nt = (integer) ((d__[j11 + 11] - znumbr_1.z1) * 7.f + 18.1f);
    ntz = nt - 2;
    rad = *radi;
    radsqr = rad * rad;
    epsiln = znumbr_1.z2 * znumbr_1.z1em5 * rad;
    delta = znumbr_1.z1em5 / rad;
    diamt = znumbr_1.z2 * rad + toler;
    itry = 0;
    schtb_(&d__[j11]);
    ihu = (integer) (d__[j11 + 12] + .1f + j11);
    ihut = ihu;
    itl = nt - 4 + j11;
    itfr = j11 + 14;
    d6save = dshar3_1.l[3];

/* .....EXAMINE MOD 1 AND SET A LINE PARALLEL TO THE GIVEN LINE, ON */
/* .....WHICH THE CENTER OF THE TANGENT CIRCLE WILL LIE. */

    if (*m1 == 1) {
	imod = 1;
    }
    if (*m1 == 2) {
	imod = 3;
    }
    if (*m1 == 4) {
	imod = 2;
    }
    if (*m1 == 5) {
	imod = 4;
    }
    xtest = dshar3_1.l[0] * vmod[imod - 1] + dshar3_1.l[1] * vmod[imod + 3];
    if (abs(xtest) > znumbr_1.z1em7) {
	goto L12;
    }

/* .....IF MODIFIER 1 IS IN ERROR */

L10:
    idef_1.ierror = 77;
    goto L9999;
L12:
    if (xtest < 0.) {
	goto L13;
    } else if (xtest == 0) {
	goto L10;
    } else {
	goto L14;
    }
L13:
    dshar3_1.l[3] = abs(dshar3_1.l[3]) - abs(rad);
    savd6 = dshar3_1.l[3];
    goto L102;
L14:
    dshar3_1.l[3] = abs(dshar3_1.l[3]) + abs(rad);
    savd6 = dshar3_1.l[3];
L102:
    d3save = dshar3_1.l[0];
    inum = 1;
/* L15: */

/* .....IHUINT = INDEX LOCATING INTERVAL IN WHICH INTERSECTION */
/* .....ACTUALLY OCCURS */

    ihuint = 0;

/* .....UNIT = X COORD. IN LOCAL SYSTEM OF INTERSECTION POINT */
/* .....OF PARALLEL LINE AND TABCYL */

    *unit = znumbr_1.z0;
/* L41: */
    ihu = ihut;
    dshar3_1.l[0] = d3save;
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
    iz = knumbr_1.k1;
/* Computing MAX */
    d__2 = abs(xaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(yaa / d_sign(&d__1, &xaa));
    if (xaa >= 0.) {
	goto L1001;
    } else {
	goto L1000;
    }
L1000:
    ra += znumbr_1.pi;
L1001:
    tranro_(&xaa, &yaa, &xbb, &ybb, &ra, &iz);

/* .....TABCYL MODIFIER ACCEPTANCE CRITERION */

    if (*m2 != 1) {
	goto L17;
    }
    dpvalu = znumbr_1.z1;
    goto L504;
L17:
    if (*m2 != 4) {
	goto L19;
    }
    dpvalu = -znumbr_1.z1;
L504:
    xaxis = znumbr_1.z1;
    yaxis = znumbr_1.z0;
    goto L22;
L19:
    if (*m2 != 2) {
	goto L21;
    }
    dpvalu = znumbr_1.z1;
    goto L505;
L21:
    if (*m2 != 5) {
	goto L10;
    }
    dpvalu = -znumbr_1.z1;
L505:
    xaxis = znumbr_1.z0;
    yaxis = znumbr_1.z1;
L22:
L31:
    chkret_(&ihu, &rad, &intrct, d__, dshar3_1.l);
    if (intrct <= 0) {
	goto L42;
    } else {
	goto L400;
    }
L400:
    dis = -(dshar3_1.l[0] * d__[ihu - 1] + dshar3_1.l[1] * d__[ihu] - savd6);
    tranro_(dshar3_1.l, &dshar3_1.l[1], &xf, &yf, &ra, &iz);
    x1plin = xf * dis;
    y1plin = yf * dis;

/* .....CHECK FOR VERTICAL PARALLEL LINE IN LOCAL SYSTEM */

    if (abs(yf) > znumbr_1.z1em7) {
	goto L501;
    }
/* L500: */
    slplin = 9e7;
    goto L502;
L501:
    slplin = -xf / yf;
L502:
    bplin = y1plin - slplin * x1plin;
    kount = 1;
    kcheck = 0;

/* .....DIVISION OF TABCYL INTERVAL INTO 10 EQUAL PARTS. */

L64:
    if (ibacfg == 0) {
	goto L105;
    }
    xstart = xbb;
    xlenth = -xbb;
    goto L107;
L105:
    xstart = znumbr_1.z0;
    xlenth = xbb;
L107:
    kount = 2;
    goto L67;
L866:
    isave = i__ - 1;

/* .....SUBDIVISION OF LIKELY DIVISION. */

/* L65: */
    if (kount - 2 >= 0) {
	goto L103;
    } else {
	goto L64;
    }
L103:
    if (kount - 12 <= 0) {
	goto L66;
    } else {
	goto L42;
    }
L66:
    xlenth = (d__1 = xn[isave] - xn[isave - 1], abs(d__1));
L633:
    xstart = xn[isave - 1];
    if (ibacfg == 0) {
	goto L111;
    }
/* L109: */
    xlenth = -xlenth;
L111:
    ++kount;
L67:
    deltx = xlenth / znumbr_1.z10;

/* .....IF LENGTH OF NORMAL VECTOR FROM TABCYL TO PLINE IS LESS THAN */
/* .....RADSQR MORE=0,WHEN ONE IS FOUND GREATER THAN RADSQR MORE=2 */

/* L671: */
    more = 0;

/* .... INDEX OF FIRST VECTOR IN PROPER DIRECTION */

    ifirst = -1;
/* .... INDEX OF LAST VECTOR IN PROPER DIRECTION */
    ilast = -4;

/* .... LESS=5 UNTIL NORMAL VECTOR IS FOUND LESS THAN,THEN LESS=1 */

    less = 5;
    iless = 0;
    imore = 0;
    for (i__ = 1; i__ <= 11; ++i__) {
	xi = (doublereal) (i__ - 1);
	xn[i__ - 1] = xstart + xi * deltx;
/* Computing 3rd power */
	d__1 = xn[i__ - 1];
/* Computing 2nd power */
	d__2 = xn[i__ - 1];
	yn[i__ - 1] = d__[ihu + 1] * (d__1 * (d__1 * d__1)) + d__[ihu + 2] * (
		d__2 * d__2) - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * 
		(d__[ihu + 3] * xn[i__ - 1]);
/* Computing 2nd power */
	d__1 = xn[i__ - 1];
	slope = znumbr_1.z3 * d__[ihu + 1] * (d__1 * d__1) + znumbr_1.z2 * 
		d__[ihu + 2] * xn[i__ - 1] - (d__[ihu + 1] * d__[ihu + 3] + 
		d__[ihu + 2]) * d__[ihu + 3];
	if (abs(slope) >= znumbr_1.z1em7) {
	    goto L69;
	}
	slpnor = -d_sign(&c_b42, &slope);
	if (abs(slplin) >= 9e7) {
	    goto L79;
	}
	xintrs[i__ - 1] = xn[i__ - 1];
	yintrs[i__ - 1] = slplin * xintrs[i__ - 1] + bplin;
	goto L25;

/* .....SLOPE OF NORMAL AT EACH POINT IS SLPNOR */

L69:
	slpnor = -znumbr_1.z1 / slope;
/* L70: */
	bnlin = yn[i__ - 1] - slpnor * xn[i__ - 1];

/* .....INTERSECTION OF PLINE AND NORMAL TO TABCYL AT EACH TABCYL */
/* .....DIVISION POINT. */
	xintrs[i__ - 1] = (bnlin - bplin) / (slplin - slpnor);
/* ... */
	yintrs[i__ - 1] = slplin * xintrs[i__ - 1] + bplin;
L25:
	vecnrx = xintrs[i__ - 1] - xn[i__ - 1];
	vecnry = yintrs[i__ - 1] - yn[i__ - 1];
	cc = (doublereal) iz;
	axisxv = xaxis * cos(ra) - cc * yaxis * sin(ra);
	axisyv = cc * xaxis * sin(ra) + yaxis * cos(ra);

/* .....CHECK TO SEE IF TABCYL MODIFIER IS ACCEPTABLE FOR THIS NORMAL */

	dotp = vecnrx * axisxv + vecnry * axisyv;
	if (dpvalu * dotp <= znumbr_1.z1em5) {
	    goto L79;
	}

/* .....LENGTH OF NORMAL VECTOR FROM TABCYL POINT TO PLINE */

/* L80: */
/* Computing 2nd power */
	d__1 = vecnrx;
/* Computing 2nd power */
	d__2 = vecnry;
	vecnrl[i__ - 1] = d__1 * d__1 + d__2 * d__2;
	if (ifirst <= 0) {
	    goto L183;
	} else {
	    goto L184;
	}
L183:
	ifirst = i__;
L184:
	ilast = i__;

/* .....HAVE WE FOUND LOCATION OF CIRCLE CENTER */

	if ((d__1 = vecnrl[i__ - 1] - radsqr, abs(d__1)) - epsiln <= 0.) {
	    goto L83;
	} else {
	    goto L82;
	}
L82:
	if ((d__1 = vecnrl[i__ - 1] - radsqr) < 0.) {
	    goto L85;
	} else if (d__1 == 0) {
	    goto L83;
	} else {
	    goto L86;
	}
L85:
	less = 1;
	iless = i__;
	goto L876;
L86:
	more = 2;
	imore = i__;

/* .....DO WE HAVE ONE VECTOR GREATER AND ONE SMALLER THAN RADSQR */

L876:
	if (more <= less) {
	    goto L84;
	}

/* .....YES-ARE THEY ADJACENT */

/* L890: */
	if ((i__1 = iless - imore, abs(i__1)) - knumbr_1.k1 <= 0) {
	    goto L878;
	} else {
	    goto L84;
	}

/* .....YES-HAVE SUBDIVISIONS BECOME SMALL ENOUGH TO ASSUME */
/* .....PERPENDICULARITY */

L878:
	if ((d__1 = xn[0] - xn[1], abs(d__1)) - znumbr_1.z1em7 <= 0.) {
	    goto L5500;
	} else {
	    goto L866;
	}
L79:
	vecnrl[i__ - 1] = -1.f;
L84:
	;
    }

/* .....UTILIZE TABPNT SUBROUTINE TO FIND THE INTERSECTION OF THE PARALLEL */
/* .....LINE AND THE TABCYL. */
    if (itbpnt != 0) {
	goto L867;
    }
/* .. */
/* ..   DD(1),DD(2) ARE UV CORDINATE OF INTERSECTION */
/* ..   DD(3)       SUBSCRIPT OF D LOCATION AT WHICH THE DATA BEGINS */
/* ..               FOR THE TABCYL INTERVAL IN WHICH THE INTERSECTION */
/* ..               POINT WAS FOUND */





    j111 = j11;
    ldef_1.subflg = TRUE_;
    apt011_(dd, dshar3_1.l, &tab[1], &pt[1]);
    j11 = j111;

    itbpnt = 1;
    if (idef_1.ierror != 0) {
	goto L621;
    } else {
	goto L600;
    }
L600:
    ihuint = (integer) (d__[j11 + 12] + .1f + j11);
    xxaa = d__[ihuint + 6] - d__[ihuint - 1];
    yyaa = d__[ihuint + 7] - d__[ihuint];
    iizz = knumbr_1.k1;
/* Computing MAX */
    d__2 = abs(xxaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    rra = -atan(yyaa / d_sign(&d__1, &xxaa));
    if (xxaa < znumbr_1.z0) {
	rra += znumbr_1.pi;
    }
    tranro_(dd, &dd[1], uint, &uint2, &rra, &iizz);
    idef_1.ierror = 0;
    sauint = *uint;
/* Computing 2nd power */
    d__1 = d__[ihuint + 6] - d__[ihuint - 1];
/* Computing 2nd power */
    d__2 = d__[ihuint + 7] - d__[ihuint];
    savxbb = sqrt(d__1 * d__1 + d__2 * d__2);

/* .....IS THIS INTERVAL WITHIN ONE ON EITHER SIDE OF */
/* .....INTERVAL OF INTERSECTION */

L867:
    if ((i__1 = ihu - ihuint, abs(i__1)) - 7 <= 0) {
	goto L800;
    } else {
	goto L621;
    }

/* .... IT IS WITHIN ONE-IS IT BEFORE,IN,OR AFTER THE INTERSECTION */
/* .... INTERVAL */

L800:
    if ((i__1 = ihu - ihuint) < 0) {
	goto L809;
    } else if (i__1 == 0) {
	goto L801;
    } else {
	goto L802;
    }
L809:
    if (abs(sauint) - znumbr_1.z1em6 <= 0.) {
	goto L803;
    } else {
	goto L621;
    }
L803:
    *uint = xbb;
    goto L602;
L801:
    *uint = sauint;
    goto L602;
L802:
    if ((d__1 = sauint - savxbb, abs(d__1)) - znumbr_1.z1em6 <= 0.) {
	goto L806;
    } else {
	goto L621;
    }
L806:
    *unit = znumbr_1.z0;
L602:
/* Computing 2nd power */
    d__1 = *uint;
    cslope = znumbr_1.z3 * d__[ihu + 1] * (d__1 * d__1) + znumbr_1.z2 * d__[
	    ihu + 2] * *unit - (d__[ihu + 1] * d__[ihu + 3] + d__[ihu + 2]) * 
	    d__[ihu + 3];

/* .....TEST FOR LINE PERPENDICULAR TO TABCYL */

    if (abs(slplin) - 1.5e-5f <= 0.) {
	goto L6073;
    } else {
	goto L6071;
    }
L6071:
    if (abs(cslope) - 1.5e-5f >= 0.) {
	goto L6072;
    } else {
	goto L6075;
    }
L6075:
    if (abs(slplin) - 9.9e4f >= 0.) {
	goto L6070;
    } else {
	goto L6073;
    }
L6072:
    costha = (slplin * cslope + znumbr_1.z1) / (d__1 = slplin * cslope, abs(
	    d__1));
    if (abs(costha) - min(znumbr_1.z1em3,delta) <= 0.) {
	goto L6070;
    } else {
	goto L6073;
    }

/* .....LINE NOT PERPENDICULAR TO TABCYL */

L6073:
    if (kcheck - 1 != 0) {
	goto L6074;
    } else {
	goto L603;
    }
L6074:
    if (kount - 12 <= 0) {
	goto L180;
    } else {
	goto L42;
    }
L6070:
    if (abs(dshar3_1.l[1]) - znumbr_1.z1em7 <= 0.) {
	goto L651;
    } else {
	goto L650;
    }
L651:
    xcomp = znumbr_1.z0;
    ycomp = rad;
    clope = 9999999.f;
    goto L652;
L650:
    clope = -dshar3_1.l[0] / dshar3_1.l[1];
/* Computing 2nd power */
    d__1 = clope;
    xcomp = sqrt(radsqr / (znumbr_1.z1 + d__1 * d__1));
    ycomp = (d__1 = clope * xcomp, abs(d__1));
L652:
    iz = -knumbr_1.k1;
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(yaa / d_sign(&d__1, &xaa));
    if (xaa >= 0.) {
	goto L1003;
    } else {
	goto L1002;
    }
L1002:
    ra += znumbr_1.pi;
L1003:
    tranro_(dd, &dd[1], &px, &py, &ra, &iz);
    if ((i__1 = *m2 - 2) < 0) {
	goto L608;
    } else if (i__1 == 0) {
	goto L609;
    } else {
	goto L610;
    }
L608:
    result[1] = d__[ihu - 1] + px + xcomp;
    result[2] = d__[ihu] + py + d_sign(&ycomp, &clope);
    goto L613;
L609:
    result[1] = d__[ihu - 1] + px - xcomp;
    result[2] = d__[ihu] + py - d_sign(&ycomp, &clope);
    goto L613;
L610:
    if (*m2 == 5) {
	goto L612;
    }
    result[1] = d__[ihu - 1] + px + d_sign(&xcomp, &clope);
    result[2] = d__[ihu] + py + ycomp;
    goto L613;
L612:
    result[1] = d__[ihu - 1] + px - d_sign(&xcomp, &clope);
    result[2] = d__[ihu] + py - ycomp;
    goto L613;

/* .... */
/* .... THIS SECTION IS FOR THE CASE WHERE THE RADIUS OF CURVATURE OF THE */
/* .... TABCYL IS SMALL,AND THE NORMALS FROM POINTS VERY CLOSE TOGETHER */
/* .... ON THE TABCYL HIT THE STRAIGHT LINE UPON WHICH THE CIRCLE CENTER */
/* .... IS TO LIE AT POINTS THAT ARE A SIGNIFICANT DISTANCE APART. */

L5500:
    if ((d__1 = xn[0] - dd[0], abs(d__1)) - znumbr_1.z1em7 <= 0.) {
	goto L6070;
    } else {
	goto L5501;
    }
L5501:
/* Computing 2nd power */
    d__1 = slplin;
    xp = (xn[i__ - 1] + slplin * (yn[i__ - 1] - bplin)) / (d__1 * d__1 + 
	    znumbr_1.z1);
/* Computing 2nd power */
    d__1 = slplin;
    yp = (slplin * (xn[i__ - 1] + slplin * yn[i__ - 1]) + bplin) / (d__1 * 
	    d__1 + znumbr_1.z1);
/* Computing 2nd power */
    d__1 = xn[i__ - 1] - xp;
/* Computing 2nd power */
    d__2 = yn[i__ - 1] - yp;
    disp = d__1 * d__1 + d__2 * d__2;
    dmove = radsqr - dist;
/* Computing 2nd power */
    d__1 = slplin;
    xmove = sqrt(dmove / (znumbr_1.z1 + d__1 * d__1));
    ymove = (d__1 = slplin * xmove, abs(d__1));
    if (imore > iless) {
	goto L5503;
    }
    xlong = xintrs[i__ - 2];
    ylong = yintrs[i__ - 2];
    goto L5505;
L5503:
    xlong = xintrs[i__ - 1];
    ylong = yintrs[i__ - 1];
L5505:
    if (xlong > xp) {
	goto L27;
    }
    xintrs[i__ - 1] = xp - xmove;
    goto L28;
L27:
    xintrs[i__ - 1] = xp + xmove;
L28:
    if (ylong > yp) {
	goto L30;
    }
    yintrs[i__ - 1] = yp - ymove;
    goto L83;
L30:
    yintrs[i__ - 1] = yp + ymove;
    goto L83;

/* .....CHECK FOR A HUMP OR VALLEY WHERE THE SUCCESSIVE VECTOR LENGTHS */
/* .....CHANGE FROM INCREASING TO DECREASING OR VICE VERSA */

L621:
    incres = 0;
    idecrs = 0;
    idef_1.ierror = 0;
/* L199: */
    for (i__ = 1; i__ <= 11; ++i__) {
	if (i__ - 9 <= 0) {
	    goto L622;
	} else {
	    goto L42;
	}
L622:
	if (vecnrl[i__ - 1] >= 0.) {
	    goto L625;
	} else {
	    goto L630;
	}
L625:
	if (vecnrl[i__] >= 0.) {
	    goto L6251;
	} else {
	    goto L630;
	}
L6251:
	if (vecnrl[i__ + 1] >= 0.) {
	    goto L6252;
	} else {
	    goto L630;
	}
L6252:
	if ((d__1 = vecnrl[i__] - vecnrl[i__ - 1]) < 0.) {
	    goto L626;
	} else if (d__1 == 0) {
	    goto L630;
	} else {
	    goto L627;
	}
L626:
	idecrs = 1;
	goto L6271;
L627:
	incres = 1;
L6271:
	if ((d__1 = vecnrl[i__ + 1] - vecnrl[i__]) < 0.) {
	    goto L628;
	} else if (d__1 == 0) {
	    goto L630;
	} else {
	    goto L629;
	}
L628:
	idecrs = 1;
	goto L6291;
L629:
	incres = 1;
L6291:
	if (incres - idecrs != 0) {
	    goto L630;
	} else {
	    goto L631;
	}
L630:
	;
    }
    goto L42;
L631:
    if (kount - 12 <= 0) {
	goto L632;
    } else {
	goto L42;
    }
L632:
    if (kount - 12 >= 0) {
	goto L196;
    } else {
	goto L634;
    }
L634:
    xlenth = (d__1 = xn[i__ + 1] - xn[i__ - 1], abs(d__1));
    isave = i__;
    goto L633;

/* .....SUBDIVIDED BETWEEN ADJACENT GOOD AND BAD VECTORS */

L180:
    if (ifirst <= 0) {
	goto L603;
    } else {
	goto L186;
    }
L186:
    if ((d__1 = vecnrl[ifirst - 1] - vecnrl[ilast - 1]) < 0.) {
	goto L181;
    } else if (d__1 == 0) {
	goto L193;
    } else {
	goto L185;
    }
L182:
    if (ifirst - 1 <= 0) {
	goto L196;
    } else {
	goto L187;
    }
L187:
    if (ifirst - 11 >= 0) {
	goto L196;
    } else {
	goto L188;
    }
L188:
    i__ = ifirst - 1;
    goto L632;
L185:
    if (less - 1 != 0) {
	goto L189;
    } else {
	goto L182;
    }
L189:
    if (ilast - 11 >= 0) {
	goto L196;
    } else {
	goto L190;
    }
L190:
    i__ = ilast - 1;
    goto L632;
L181:
    if (less - 1 != 0) {
	goto L182;
    } else {
	goto L189;
    }
L193:
    if (ifirst - 1 <= 0) {
	goto L191;
    } else {
	goto L194;
    }
L194:
    if (ilast - 11 >= 0) {
	goto L192;
    } else {
	goto L188;
    }
L191:
    i__ = 2;
L195:
    if (kount - 12 >= 0) {
	goto L196;
    } else {
	goto L866;
    }
L196:
    if (kcheck - 1 >= 0) {
	goto L42;
    } else {
	goto L197;
    }
L197:
    kcheck = 1;
    kount = 1;
    goto L64;
L192:
    i__ = 11;
    goto L195;
L618:
    if (kount - 12 <= 0) {
	goto L619;
    } else {
	goto L42;
    }

/* .....SUBDIVIDE AROUND THE INTERSECTION OF PARALLEL LINE AND TABCYL */

L619:
    if (i__ - 2 <= 0) {
	goto L720;
    } else {
	goto L721;
    }
L720:
    isave = i__ - 1;
L724:
    xlenth = (d__1 = xn[isave + 1] - xn[isave - 1], abs(d__1));
    goto L633;
L721:
    isave = i__ - 2;
    if (i__ - 11 >= 0) {
	goto L724;
    } else {
	goto L722;
    }
L722:
    xlenth = (d__1 = xn[isave + 2] - xn[isave - 1], abs(d__1));
    goto L633;
L603:
    for (i__ = 2; i__ <= 11; ++i__) {
	if (ibacfg <= 0) {
	    goto L604;
	} else {
	    goto L606;
	}
L604:
	if (*unit - znumbr_1.z1em6 - xn[i__ - 1] <= 0.) {
	    goto L618;
	} else {
	    goto L605;
	}
L606:
	if (*unit + znumbr_1.z1em6 - xn[i__ - 1] >= 0.) {
	    goto L618;
	} else {
	    goto L605;
	}
L605:
	;
    }

/* .....SET-UP RE-TRY IN ANOTHER INTERVAL UNTIL 3 INTERVALS ON EACH SIDE */
/* .....OF THE ESTIMATED INTERVAL HAVE BEEN TRIED----A TOTAL OF 7 */
/* .....INTERVALS.(EXTENSION INTERVALS ARE INCLUDED) */

L42:
    if (icount - 7 >= 0) {
	goto L43;
    } else {
	goto L422;
    }
L422:
    iz = -knumbr_1.k1;
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(yaa / d_sign(&d__1, &xaa));
    if (xaa >= 0.) {
	goto L330;
    } else {
	goto L1004;
    }
L1004:
    ra += znumbr_1.pi;
L330:
    if (icount % 2 != 0) {
	goto L301;
    } else {
	goto L300;
    }
L300:
    ihu += icount * 7;
    ibacfg = 0;
    ++icount;
    if (ihu - itl >= 0) {
	goto L340;
    } else {
	goto L72;
    }
L301:
    ihu -= icount * 7;
    ibacfg = 1;
    ++icount;
    if (ihu - itfr <= 0) {
	goto L350;
    } else {
	goto L72;
    }
L340:
    lout = 1;
    goto L330;
L350:
    ilout = 1;
    if (lout - ilout != 0) {
	goto L330;
    } else {
	goto L43;
    }
L43:
    idef_1.ierror = 77;
    goto L9999;
L72:
    iz = 1;
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(yaa / d_sign(&d__1, &xaa));
    if (xaa >= 0.) {
	goto L1006;
    } else {
	goto L1005;
    }
L1005:
    ra += znumbr_1.pi;
L1006:
    tranro_(&xaa, &yaa, &xbb, &ybb, &ra, &iz);
    goto L31;
L83:
    x11 = xintrs[i__ - 1];
    y11 = yintrs[i__ - 1];

/* .....CENTER FOUND, PUT IT BACK INTO ORIGINAL COORDINATE SYSTEM AND PUT */
/* .....CANONICAL FORM OF CIRCLE IN DEFANS BLOCK. */

/* L50: */
    iz = -1;
    xaa = d__[ihu + 6] - d__[ihu - 1];
    yaa = d__[ihu + 7] - d__[ihu];
/* Computing MAX */
    d__2 = abs(xaa);
    d__1 = max(d__2,znumbr_1.z1em9);
    ra = -atan(yaa / d_sign(&d__1, &xaa));
    if (xaa >= 0.) {
	goto L1008;
    } else {
	goto L1007;
    }
L1007:
    ra += znumbr_1.pi;
L1008:
    tranro_(&x11, &y11, &xa, &ya, &ra, &iz);
    def_1.r__[0] = d__[ihu - 1] + xa;
    def_1.r__[1] = d__[ihu] + ya;
L613:
    def_1.r__[6] = rad;
    apt083_(def_1.r__, &knumbr_1.km1);
L9999:
    defext_(&result[1]);
/* L51: */
    return 0;
L9998:
    idef_1.ierror = 79;
    goto L9999;
} /* apt034_ */

#undef bcanon
#undef sscan
#undef canon
#undef uint
#undef unit
#undef can
#undef d__


