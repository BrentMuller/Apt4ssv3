/* CLOCUB.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000613.V01   *** */

/* Subroutine */ int clocub_(doublereal *ax, doublereal *ay, doublereal *bx, 
	doublereal *by, doublereal *gx, doublereal *gy, doublereal *hx, 
	doublereal *hy, doublereal *ca, doublereal *cb, doublereal *alph, 
	doublereal *beta, integer *irr)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__, d__, e, f;
    static integer l;
    static doublereal p, q, r__, w, e1, f1, at, bt, dx, dy;
    static integer nz;
    static doublereal hca, hcb, one;
    static integer nct;
    static doublereal rts[4];
    static integer ichk;
    static doublereal z1em7, zero, rpp0x, rpp0y, rpp1x, rpp1y;
    static integer idiag;
    extern /* Subroutine */ int biquad_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;

/* ------THIS SUBROUTINE ACCEPTS AS INPUT TWO END POINTS AX,AY $ BX,BY */
/* ------TWO END DIRECTION VECTORS GX,GY $ HX,HY AND TWO END CURVATURES */
/* ------CA,CB(SIGNED BY DR X DDR).  GX,GY AND HX,HY ARE CONVERTED TO */
/* ------UNIT TANGENT VECTORS FOR THE PLANAR PARAMETRIC CUBIC */
/* ------ OUTPUT CONSISTS OF SCALARS ALPH AND BETA WHICH ARE MULTIPLIERS */
/* ------SATISFIES END CONDITIONS OF POINTS,DIRECTION AND CURVATURE */
    idiag = 19000;
    z1em7 = 1e-7f;
    zero = 0.f;
    one = 1.f;
    w = *gx * *gx + *gy * *gy;
    *irr = idiag + 1;
    if (w < z1em7) {
	return 0;
    }
    *gx /= sqrt(w);
    *gy /= sqrt(w);
    w = *hx * *hx + *hy * *hy;
    *irr = idiag + 2;
    if (w < z1em7) {
	return 0;
    }
    *hx /= sqrt(w);
    *hy /= sqrt(w);
    dx = *bx - *ax;
    dy = *by - *ay;
    p = *gx * dy - *gy * dx;
    q = *gx * *hy - *gy * *hx;
    r__ = dx * *hy - dy * *hx;
/* ------THE FOLLOWING SETS UP A SOLUTION TO TWO SIMULTANEOUS IN ALPH, */
/* ------BETA WHICH ARE THE DESIRED TANGENT MULTIPLIERS */
/* ------3GXD-BETAGXH=SGN(ALPH)*ALPH**2*CA/2 */
/* ------3DXH-ALPH*GXH=SGN(BETA)*BETA**2*CB/2 */
    nct = 0;
    ichk = 0;
    hca = *ca / 2;
    hcb = *cb / 2;
/* Computing 2nd power */
    d__1 = hcb;
    a = hca * (d__1 * d__1);
    b = 0.f;
    c__ = hca * -6 * hcb * r__;
/* Computing 3rd power */
    d__1 = q;
    d__ = d__1 * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = q;
/* Computing 2nd power */
    d__2 = r__;
    e = p * -3 * (d__1 * d__1) + hca * 9 * (d__2 * d__2);
    biquad_(&a, &b, &c__, &d__, &e, rts, &nz);
    if (nz == 0) {
	*irr = 1;
    }
    if (*irr != 0) {
	goto L200;
    }
/* ------ NOW CHECK FOR A VALID ALPH,BETA PAIR */
    i__1 = nz;
    for (l = 1; l <= i__1; ++l) {
	*beta = rts[l - 1];
	if (*beta < 0.f) {
	    goto L10;
	}
/* Computing 2nd power */
	d__1 = *beta;
	*alph = (r__ * 3 - hcb * (d__1 * d__1)) / q;
	if (*alph < 0.f) {
	    goto L10;
	}
	rpp0x = (dx * 3 - *gx * 2 * *alph - *beta * *hx) * 2;
	rpp0y = (dy * 3 - *gy * 2 * *alph - *beta * *hy) * 2;
	rpp1x = (dx * -3 + *gx * *alph + *beta * 2 * *hx) * 2;
	rpp1y = (dy * -3 + *gy * *alph + *beta * 2 * *hy) * 2;
/* Computing 2nd power */
	d__1 = *alph;
	e = (*gx * rpp0y - *gy * rpp0x) / (d__1 * d__1);
/* Computing 2nd power */
	d__1 = *beta;
	f = (*hx * rpp1y - *hy * rpp1x) / (d__1 * d__1);
	e1 = e - *ca;
	f1 = f - *cb;
	e1 /= *ca;
	f1 /= *cb;
	if (abs(e1) > .01 || abs(f1) > .01) {
	    goto L10;
	}
	ichk = 1;
	at = *alph;
	bt = *beta;
L10:
	;
    }
L200:
    *irr = idiag + 3;
    if (ichk == 0) {
	return 0;
    }
    *alph = at;
    *beta = bt;
    *irr = 0;
    return 0;
} /* clocub_ */

