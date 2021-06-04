/* APT341.f -- translated by f2c (version 20100827).
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
    doublereal editor[1500];
} editor_;

#define editor_1 editor_

struct {
    doublereal z1, z2, zstart, ystart, xstart, zd, yd, xd, zcv, ycv, xcv, zdo,
	     ydo, xdo, zcc, ycc, xcc, zun, yun, xun, ztr, ytr, xtr, zta, yta, 
	    xta, z__, stang, endang, dang, cang, dlngth, tlngth, cutter, test,
	     cradus;
} r5axis_;

#define r5axis_1 r5axis_

struct {
    integer ivtflg, is, ir, il, ie, jsuber, iabove, nrecex, nreccl, ncflsv;
} i5axis_;

#define i5axis_1 i5axis_

/* *** SOURCE FILE : M0000442.V02   *** */


/* .....FORTRAN SUBROUTINE                APT341...            8/1/68  AR */

/* PURPOSE      COMPUTES THE ALTERED TOOL POSITION. THE TILT */
/*              ANGLE IS PRORATED OVER THE TOTAL MOVE FROM */
/*              VTLAXS/ON TO OFF */
/* LINKAGE      CALL APT341 */
/* ARGUMENTS    NONE */
/* SUBSIDIARIES APT315,APT342 */
/* ******************************************************************** */
/* Subroutine */ int apt341_(void)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
#define x1 ((doublereal *)&editor_1 + 1331)
#define x2 ((doublereal *)&editor_1 + 1332)
#define y1 ((doublereal *)&editor_1 + 1336)
#define y2 ((doublereal *)&editor_1 + 1337)
    static doublereal tcos, tsin;
#define area1 ((doublereal *)&editor_1)
#define area2 ((doublereal *)&editor_1 + 500)
#define area3 ((doublereal *)&editor_1 + 1250)
    extern /* Subroutine */ int apt342_(doublereal *, doublereal *, 
	    doublereal *), apt315_(doublereal *, doublereal *);
    static doublereal tsin1;

/* *********************************************************************** */
/* ******************************************************************** */
/*     SYSTEM COMMON,DIMENSION, AND EQUIVALENCE STATEMENTS */



/* ...    PRORATE TILT ANGLE */
    r5axis_1.cang = r5axis_1.stang + r5axis_1.dlngth / r5axis_1.tlngth * 
	    r5axis_1.dang;
    tsin = sin(r5axis_1.cang);
    tsin1 = abs(tsin);
    tcos = cos(r5axis_1.cang);
    apt342_(&r5axis_1.zcv, &r5axis_1.zun, &r5axis_1.ztr);
    apt315_(&r5axis_1.ztr, &r5axis_1.ztr);
/* ...    IS CANG .GT. 80 DEGREES */
    if (abs(tcos) - .1736f <= 0.) {
	goto L5;
    } else {
	goto L90;
    }
L90:
/* ...    CALCULATE XYZ COORDINATES OF NEW CUTTER POSITION */
    if (r5axis_1.cradus != 0.) {
	goto L100;
    } else {
	goto L110;
    }
L100:
    r5axis_1.z__ = r5axis_1.cradus * (1.f - tcos) + (r5axis_1.cutter - 
	    r5axis_1.cradus) * tsin1;
    goto L120;
L110:
    r5axis_1.z__ = (d__1 = r5axis_1.cutter * tsin, abs(d__1));
L120:
    if (r5axis_1.cang * r5axis_1.zun >= 0.) {
	goto L150;
    } else {
	goto L130;
    }
L130:
    if (r5axis_1.cradus != 0.) {
	goto L140;
    } else {
	goto L170;
    }
L140:
    r5axis_1.test = r5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.f) / tcos) - 
	    r5axis_1.cutter * (tcos - 2.f / tcos + 1.f);
    r5axis_1.test = -r5axis_1.test;
    goto L9;
L150:
    if (r5axis_1.cradus != 0.) {
	goto L160;
    } else {
	goto L8;
    }
L160:
    r5axis_1.test = r5axis_1.cradus * (tcos - tsin1 + (tsin1 - 1.f) / tcos) + 
	    r5axis_1.cutter * (1.f - tcos);
    goto L9;
L170:
    if (i5axis_1.iabove != 0) {
	goto L3;
    } else {
	goto L6;
    }
L3:
    r5axis_1.z__ = -r5axis_1.z__;
    goto L8;
L5:
    i5axis_1.jsuber = 30007;
/* ...    ERROR 30007 - TILT ANGLE IS GREATER THAN 80 DEGREES. */
    goto L40;
L6:
    r5axis_1.test = -(r5axis_1.cutter * 2.f / tcos - r5axis_1.cutter - 
	    r5axis_1.cutter * tcos);
    goto L9;
L8:
    r5axis_1.test = r5axis_1.cutter * (1.f - tcos);
L9:
    r5axis_1.xdo = r5axis_1.test * r5axis_1.xtr;
    r5axis_1.ydo = r5axis_1.test * r5axis_1.ytr;
    r5axis_1.zdo = r5axis_1.test * r5axis_1.ztr;
    r5axis_1.xcc = *x2 + r5axis_1.xdo;
    r5axis_1.ycc = *y2 + r5axis_1.ydo;
    r5axis_1.zcc = r5axis_1.z2 + r5axis_1.z__;
/* ...    CALCULATE IJK COMPONENTS OF NEW TLAXIS VECTOR */
    r5axis_1.xtr = tcos * r5axis_1.xtr;
    r5axis_1.ytr = tcos * r5axis_1.ytr;
    if (r5axis_1.zun >= 0.) {
	goto L20;
    } else {
	goto L10;
    }
L10:
    r5axis_1.ztr = tsin;
    apt342_(&r5axis_1.zcv, &r5axis_1.ztr, &r5axis_1.zta);
    goto L30;
L20:
    r5axis_1.ztr = -tsin;
    apt342_(&r5axis_1.ztr, &r5axis_1.zcv, &r5axis_1.zta);
L30:
    apt315_(&r5axis_1.zta, &r5axis_1.zta);
    *x1 = *x2;
    *y1 = *y2;
    r5axis_1.z1 = r5axis_1.z2;
L40:
    return 0;
} /* apt341_ */

#undef area3
#undef area2
#undef area1
#undef y2
#undef y1
#undef x2
#undef x1


