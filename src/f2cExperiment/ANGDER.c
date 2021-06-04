/* ANGDER.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n3 = -3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0002659.V03   *** */

/* Subroutine */ int angder_(doublereal *cv, doublereal *p, doublereal *an, 
	doublereal *der, integer *mode, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-6;
    static doublereal vsmal = 1e-20;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal);

    /* Local variables */
    static doublereal c__;
    static integer i__;
    static doublereal t[3], v[3], w, w3, cp, wn, vp[3], wp, ss, vt, vv;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, doublereal 
	    *, ftnlen);
    static doublereal cpp, vpp[3], wpp, vpt, vvp, vppt, vvpp, vpvp;
    extern doublereal darcos_(doublereal *);

/* ---     PURPOSE IS TO CALCULATE RATES OF CHANGE OF ANGLE FROM */
/* ---     POINT P TO CURVE AT POINT CV. */
/*     INPUT CV POINT, FIRST DERIVATIVE, SECOND DERIVATIVE OF CURVE */
/*     INPUT P=CENTRAL POINT FROM WHICH ANGLE IS CALCULATED */
/*     INPUT AN(OPTIONAL) IS A PLANAR NORMAL IN CASE ANGLE IS */
/*            TO BE MEASURED IN A PLANE. */
/*     INPUT MODE IS 0 ON FIRST CALL, NON-ZERO ON OTHER CALLS. */
/*     OUTPUT DER ARRAY CONTAINING CURRENT ANGLE AND RATES OF CHANGE */
/*     OUTPUT IRR NON ZERO ON OUTPUT INDICATES AN ERROR. */

    /* Parameter adjustments */
    --der;
    --an;
    --p;
    --cv;

    /* Function Body */

    if (*mode != 0) {
	goto L100;
    }
/* ---     FIRST CHECK AN - NORMALIZE IF NOT ZERO. */
    w = sqrt(an[1] * an[1] + an[2] * an[2] + an[3] * an[3]);
    if (w > smal) {
	goto L20;
    }
/* ---     ZERO OUT AN COMPLETELY */
    an[1] = zero;
    an[2] = zero;
    an[3] = zero;
    wn = zero;
    goto L30;
L20:
/* ---     NORMALIZE AN */
    an[1] /= w;
    an[2] /= w;
    an[3] /= w;
    wn = (cv[1] - p[1]) * an[1] + (cv[2] - p[2]) * an[2] + (cv[3] - p[3]) * 
	    an[3];
L30:
    w = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
/* Computing 2nd power */
	d__1 = cv[i__] - p[i__];
	w += d__1 * d__1;
/* L25: */
    }
    w = sqrt(w);
    *irr = 19;
    if (w < smal) {
	goto L999;
    }
    w = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	t[i__ - 1] = cv[i__] - p[i__] - wn * an[i__];
	w += t[i__ - 1] * t[i__ - 1];
/* L40: */
    }
    w = sqrt(w);
    *irr = 11;
    if (w < smal) {
	goto L999;
    }
/* ---      T IS THE BASE VECTOR FOR MEASURING ANGLE */
    t[0] /= w;
    t[1] /= w;
    t[2] /= w;
L100:

/* ---     NOW COMPUTE ANGLE W AND DERIVATIVES FROM GENERAL FORMULA */
/* ---     COS(ANGLE)=(V,T)/DSQRT(V,V) WHERE V=CV-(CV-P,AN)AN. */

    c__ = zero;
    cp = zero;
    cpp = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	c__ += (cv[i__] - p[i__]) * an[i__];
	cp += cv[i__ + 4] * an[i__];
	cpp += cv[i__ + 8] * an[i__];
/* L110: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	v[i__ - 1] = cv[i__] - p[i__] - c__ * an[i__];
	vp[i__ - 1] = cv[i__ + 4] - cp * an[i__];
	vpp[i__ - 1] = cv[i__ + 8] - cpp * an[i__];
/* L120: */
    }
/* ---     CALCULATE NECESSARY INNER PRODUCTS */
    vv = zero;
    vt = zero;
    vvp = zero;
    vvpp = zero;
    vpt = zero;
    vppt = zero;
    vpvp = zero;

    for (i__ = 1; i__ <= 3; ++i__) {
	vv += v[i__ - 1] * v[i__ - 1];
	vvp += v[i__ - 1] * vp[i__ - 1];
	vvpp += v[i__ - 1] * vpp[i__ - 1];
	vt += v[i__ - 1] * t[i__ - 1];
	vpt += vp[i__ - 1] * t[i__ - 1];
	vppt += vpp[i__ - 1] * t[i__ - 1];
	vpvp += vp[i__ - 1] * vp[i__ - 1];
/* L130: */
    }
/* ---     NOW CALCULATE RATES OF CHANGE OF W=1/DSQRT(V,V) */
    w = sqrt(vv);
    *irr = 12;
    if (w < smal) {
	goto L999;
    }
    w = one / w;
    w3 = w * w * w;
    wp = -vvp * w3;
    wpp = w3 * 3.f * w * w * vvp * vvp;
    wpp -= w3 * (vpvp + vvpp);
    c__ = vt * w;
    c__ = min(c__,one);
/* Computing MAX */
    d__1 = c__, d__2 = -one;
    c__ = max(d__1,d__2);
    der[1] = darcos_(&c__);
    ss = sin(der[1]) + vsmal;
    if (abs(ss) > smal) {
	goto L140;
    }
/* ---      DEGENERATE CASE, USE LHOSPITALS RULE. */
    der[2] = -(vppt * w + vpt * 2.f * wp + vt * wpp) / c__;
    der[2] = abs(der[2]);
    der[2] = sqrt(der[2]);
/* ---      THE FOLLOWING IS A ROUGH CUT AT SECOND DERIVATIVE. */
    der[3] = (vppt * wp + vpt * wpp) * 3.f;
/* Computing 3rd power */
    d__1 = der[2];
    der[3] = (ss * (d__1 * (d__1 * d__1)) - der[3]) / (c__ * 2.f * (der[2] + 
	    vsmal));
    goto L150;
L140:
    der[2] = -(vpt * w + vt * wp) / ss + vsmal;
/* Computing 2nd power */
    d__1 = der[2];
    der[3] = vppt * w + vpt * 2.f * wp + vt * wpp + vt * w * (d__1 * d__1);
    der[3] = -der[3] / ss;
L150:
    *irr = 0;
L999:
    if (ibugg_1.ibug != 11) {
	goto L997;
    }
    bad_(&c_n3, &c__1, "DER ", &der[1], (ftnlen)4);
L997:
    return 0;
} /* angder_ */

