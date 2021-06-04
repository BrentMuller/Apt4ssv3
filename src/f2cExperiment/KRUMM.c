/* KRUMM.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0008176.V01   *** */

/* Subroutine */ int krumm_(doublereal *spv, doublereal *e, doublereal *f, 
	doublereal *g, doublereal *xl, doublereal *xm, doublereal *xn, 
	doublereal *hkr, doublereal *rk1, doublereal *rk2)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__;
    static doublereal t1, t2, t3, t4, du, dv, we, vt[3], vt2[3], xnl, supi, 
	    svpi;
    extern /* Subroutine */ int kreuz_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal xnorm, cosalf, sinalf;


/* SUBROUTINE FOR THE OUTPUT OF THE CURVING OF PATCHES */

/*  SPV :   SURFACE POINTS AND DERIVATIVES */
/*  E   :   COEFFICIENTS OF FIRST AND SECOND GAUSSIAN FUNDAMENTAL FORM */
/*  F   : */
/*  G   : */
/*  XL  : */
/*  XM  : */
/*  XN  : */
/*  HKR :   MAIN CURVATURE DIRECTION */
/*  RK1 :   1.CURVATURE */
/*  RK2 :   2.CURVATURE */

/*  HELP STORAGE */

/*  COMPUTATION OF THE FUNDAMENTAL COEFFICIENTS */
    /* Parameter adjustments */
    --hkr;
    spv -= 5;

    /* Function Body */
    *e = 0.;
    *f = 0.;
    *g = 0.;
    *xl = 0.;
    *xn = 0.;
    *xm = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	supi = spv[i__ + 8];
	svpi = spv[i__ + 12];
	*e = supi * supi + *e;
	*f = supi * svpi + *f;
	*g = svpi * svpi + *g;
	xnorm = spv[i__ + 32];
	*xl = spv[i__ + 16] * xnorm + *xl;
	*xm = spv[i__ + 20] * xnorm + *xm;
	*xn = spv[i__ + 24] * xnorm + *xn;
/* L7002: */
    }
/*   THE LENGTH OF THE NORMAL */
    xnl = sqrt(*e * *g - *f * *f) + 1e-12;
/*   COMPUTATION OF ONE MAIN CURVATURE DIRECTION */
/*   A=G*M-F*N */
    a = *g * *xm - *f * *xn;
/*   B=G*L-E*N */
    b = *g * *xl - *e * *xn;
/*   C=F*L-E*M */
    c__ = *f * *xl - *e * *xm;
    t1 = b * b - a * 4. * c__;
    t2 = sqrt(t1);
    t3 = *e * b - *f * 2. * c__;
    if (t3 < 0.) {
	t2 = -t2;
    }
    t4 = sqrt(*e * 2. * *e * t1 + *e * 2. * t3 * t2);
    if (abs(t4) > 0.) {
	goto L7060;
    }
/*   NO MAIN DIRECTION GIVEN */
    sinalf = 0.;
    cosalf = 1.;
    goto L7070;
L7060:
    sinalf = (t3 + *e * t2) / t4;
    cosalf = c__ * 2. * xnl / t4;
L7070:
    we = sqrt(*e);
    for (i__ = 1; i__ <= 3; ++i__) {
/*  U-TANGENT */
/* L7300: */
	vt[i__ - 1] = spv[i__ + 8] / we;
    }
/*  VECTOR, PERPENTICULAR TO U-TANGENT */
    kreuz_(&spv[33], vt, vt2);
/*   DIRECTION OF 1. MAIN CURVATURE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L7310: */
	hkr[i__] = cosalf * vt[i__ - 1] + sinalf * vt2[i__ - 1];
    }
/*  COMPUTATION OF 1.CURVATURE: */
    dv = *e * sinalf;
    du = xnl * cosalf - *f * sinalf;
    *rk1 = (*xl * du * du + *xm * 2. * du * dv + *xn * dv * dv) / (*e * du * 
	    du + *f * 2. * du * dv + *g * dv * dv);
/*  COMPUTATION OF 2.CURVATURE: */
    dv = *e * cosalf;
    du = -xnl * sinalf - *f * cosalf;
    *rk2 = (*xl * du * du + *xm * 2. * du * dv + *xn * dv * dv) / (*e * du * 
	    du + *f * 2. * du * dv + *g * dv * dv);

    return 0;
} /* krumm_ */

