/* PARINT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000646.V02   *** */


/* Subroutine */ int parint_(doublereal *pa, doublereal *pd, doublereal *pc, 
	doublereal *udir, doublereal *rad, integer *kk, integer *irr)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal b, c__;
    static integer i__;
    static doublereal s, w, x, x1, x2, y2, pb[3], wa, wb, dx[3], dy[3], rd2, 
	    ycc, vela, velb, crit, hdst, pdst;
    static integer idiag, kcase;
    static doublereal slope;

/* ------ALRP SCULPTURED SURFACE ROUTINE--MARCH 1970 JKH */
/* ------THIS SUBROUTINE IS MODULAR AND SHOULD NOT HAVE ANY COMMON BLOCKS */
/* ------INPUT IS THREE SPACE POINTS PA,PB,PC */
/* ------KCASE=1,2,3 INDICATES THAT OUTPUT OF CURVATURE AND TANGENT */
/* ------ IS DESIRED AT POINT P= PA, PB OR PC RESPECTIVELY */
/* ------OUTPUT SHOULD CONSIST OF A UNITIZED DIRECTION VECTOR UDIR AND A */
/* ------RADIUS AT POINT P  OF A PARABOLA WHICH PASSES THROUGH PA,PB,PC */
/* ------IRR NE 0 INDICATES A FAILURE IN INPUT */
    /* Parameter adjustments */
    --udir;
    --pc;
    --pd;
    --pa;

    /* Function Body */
    idiag = 2000;
    crit = 1e-10;
/* Computing 2nd power */
    d__1 = pc[1] - pa[1];
/* Computing 2nd power */
    d__2 = pc[2] - pa[2];
/* Computing 2nd power */
    d__3 = pc[3] - pa[3];
    x1 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    *irr = idiag + 1;
    if (x1 < crit) {
	return 0;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	dx[i__ - 1] = (pc[i__] - pa[i__]) / x1;
    }
    kcase = *kk % 10;
    if (*kk > 10) {
	goto L100;
    }
    pb[0] = pd[1];
    pb[1] = pd[2];
    pb[2] = pd[3];
    goto L200;
L100:
    wa = sqrt(pd[1] * pd[1] + pd[2] * pd[2] + pd[3] * pd[3]);
    *irr = idiag + 3;
    if (wa < crit) {
	return 0;
    }
    wb = (dx[0] * pd[1] + dx[1] * pd[2] + dx[2] * pd[3]) / wa;
    s = 1.f / wa;
    if (wb < 0.) {
	s = -s;
    }
    pb[0] = s * pd[1];
    pb[1] = s * pd[2];
    pb[2] = s * pd[3];
    hdst = x1 / 2.f;
    wb = abs(wb);
    if (wb > crit) {
	goto L130;
    }
    *irr = idiag + 5;
    return 0;
L130:
    pdst = hdst / wb;
    for (i__ = 1; i__ <= 3; ++i__) {
	pb[i__ - 1] = (pdst * pb[i__ - 1] - hdst * dx[i__ - 1]) / 2.f + hdst *
		 dx[i__ - 1];
	if (*kk < 20) {
	    pb[i__ - 1] = pa[i__] + pb[i__ - 1];
	}
	if (*kk > 20) {
	    pb[i__ - 1] = pc[i__] - pb[i__ - 1];
	}
/* L150: */
    }
L200:
/* ------PROJECT THE THIRD POINT PB ONTO THE PA,PC AXIS */
    x2 = (pb[0] - pa[1]) * dx[0] + (pb[1] - pa[2]) * dx[1] + (pb[2] - pa[3]) *
	     dx[2];
    *irr = idiag + 2;
    if (x2 < crit || x2 > x1 - crit) {
	return 0;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	dy[i__ - 1] = pb[i__ - 1] - (pa[i__] + x2 * dx[i__ - 1]);
    }
    y2 = sqrt(dy[0] * dy[0] + dy[1] * dy[1] + dy[2] * dy[2]);
    if (y2 < crit) {
	goto L5000;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	dy[i__ - 1] /= y2;
    }
/* ------NOW DX,DY FORM A PLANAR RECTANGULAR COORDINATE SYSTEM IN WHICH */
/* ------A PARABOLA Y=B*X+C*X**2 CAN BE DETERMINED SO THAT IT LIES ON */
/* ------PA = (0,0), PC = (X1,0), PB = (X2,Y2) */
    c__ = y2 / (x2 * (x2 - x1));
    b = -c__ * x1;
    x = 0.;
    if (kcase == 2) {
	x = x2;
    }
    if (kcase == 3) {
	x = x1;
    }
    w = c__ + c__;
    slope = b + w * x;
    vela = sqrt(slope * slope + 1);
    velb = slope / vela;
/* -------RAD IS THE RADIUS OF THE CIRCLE THRU THREE POINTS */
    rd2 = 1e6;
    if (y2 > 1e-6) {
/* Computing 2nd power */
	d__1 = x2;
/* Computing 2nd power */
	d__2 = y2;
	ycc = (d__1 * d__1 + d__2 * d__2 - x1 * x2) / (y2 * 2);
    }
    if (y2 > 1e-6) {
/* Computing 2nd power */
	d__1 = ycc;
	rd2 = sqrt(d__1 * d__1 + x1 * x1 / 4);
    }
    *rad = rd2;
/* ------UDIR IS CHOSEN TO POINT IN THE DIRECTION OF PA TO PB */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	udir[i__] = dx[i__ - 1] / vela + dy[i__ - 1] * velb;
    }
    *irr = 0;
    return 0;
/* ------STRAIGHT LINE CASE */
L5000:
    *rad = 1.f / crit;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L5010: */
	udir[i__] = dx[i__ - 1];
    }
    *irr = 0;
    return 0;
} /* parint_ */

