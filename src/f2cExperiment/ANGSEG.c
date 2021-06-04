/* ANGSEG.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n4 = -4;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0001031.V03   *** */

/* Subroutine */ int angseg_(doublereal *c__, doublereal *fl, doublereal *
	tolr, integer *num, integer *numax, integer *irr, doublereal *p, 
	doublereal *an)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-6;
    static doublereal vsmal = 1e-30;
    static doublereal half = .5;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__;
    static doublereal r__, aa, bb, cc, cv[16], dv;
    static integer nx;
    extern /* Subroutine */ int bad_();
    static doublereal dif, der[3];
    static integer now;
    static doublereal unx, del1, del2, hdel;
    static integer ichk;
    static doublereal disc, udel, cnow, unow, hdel2;
    extern /* Subroutine */ int angder_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
    static doublereal anglen;
    extern /* Subroutine */ int cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);

/* ---     PURPOSE IS TO REPARAMETERIZE A COONS RATIONAL CUBIC ARC */
/* ---     C BASED ON PROPORTION OF ANGLE FROM A CENTRAL POINT P. */
/* ---     THE ANGLE WILL BE MEASURED IN A PLANE THRU P WITH NORMAL */
/* ---     VECTOR AN IF AN IS NON-ZERO. */
/* ---     INPUT C=COONS RATIONAL PARAMETRIC COEFFICIENTS */
/* ---     INPUT TOLR=TOLERANCE FACTOR FOR FLOW RATE FIT(DEFAULT=.001) */
/* ---     INPUT P=CENTRAL POINT FOR CALCULATION OF ANGULAR FLOW */
/* ---     INPUT AN=OPTIONAL NORMAL VECTOR FOR MEASUREMENT OF ANGLE */
/* ---           IN A SPECIFIED PLANE. AN=(0,0,0) FOR NO PLANE. */
/* ---     OUTPUT FL=STRING OF CUBICS REPRESENTING NEW FLOW RATE */
/* ---            THESE CUBICS EXPRESS COONS PARAMETER AS A FUNCTION OF AN */
/* ---     OUTPUT NUM=NUMBER OF CUBICS+1 WHICH DETERMINE FLOW RATE. */
/* ---     OUTPUT IRR=0 FOR NO ERROR, NON-ZERO FOR ERROR */
/* ---     INPUT NUMAX=MAXIMUM NUMBER OF CUBICS PERMITTED IN FL ARRAY. */

    /* Parameter adjustments */
    --an;
    --p;
    fl -= 5;
    --c__;

    /* Function Body */
    now = 1;
    anglen = zero;
    unow = zero;
    cncurv_(&unow, &c__[1], cv, &c__1);
/* ---     COMPUTE RATES OF CHANGE OF ANGLE WRT COONS AND INVERT. */
    angder_(cv, &p[1], &an[1], der, &c__0, irr);
    if (*irr != 0) {
	goto L999;
    }
    fl[(now << 2) + 1] = der[0] + vsmal;
    fl[(now << 2) + 2] = unow;
    fl[(now << 2) + 3] = one / der[1];
/* Computing 3rd power */
    d__1 = der[1];
    fl[(now << 2) + 4] = -der[2] / (d__1 * (d__1 * d__1));

    cnow = fl[(now << 2) + 1];
    unx = .76f;
L40:
    ichk = 1;
L50:
    cncurv_(&unx, &c__[1], cv, &c__1);
    nx = now + 1;
/* ---     COMPUTE RATES OF CHANGE OF ANGLE WRT COONS AND INVERT. */
    angder_(cv, &p[1], &an[1], der, &c__1, irr);
    if (*irr != 0) {
	goto L999;
    }
    fl[(nx << 2) + 1] = der[0] + vsmal;
    fl[(nx << 2) + 2] = unx;
    fl[(nx << 2) + 3] = one / der[1];
/* Computing 3rd power */
    d__1 = der[1];
    fl[(nx << 2) + 4] = -der[2] / (d__1 * (d__1 * d__1));

/* ---     FIRST CHECK ACCURACY OF SPLINE REPRESENTATION */
    del1 = fl[(nx << 2) + 1] - cnow;
    del2 = (fl[(nx << 2) + 2] - fl[(now << 2) + 2]) * 3.f * (fl[(nx << 2) + 4]
	     + fl[(now << 2) + 4]);
    dv = fl[(nx << 2) + 4] * (fl[(now << 2) + 3] * 2.f + fl[(nx << 2) + 3]) + 
	    fl[(now << 2) + 4] * (fl[(now << 2) + 3] + fl[(nx << 2) + 3] * 
	    2.f);
    if (abs(dv) < vsmal) {
	goto L59;
    }
    del2 /= dv;
/* ---     IF SECOND DERIVATIVES VANISH, ANOTHER FORMULA IS NEEDED */
    goto L60;
L59:
    del2 = zero;
    if ((d__1 = fl[(now << 2) + 3], abs(d__1)) > vsmal * smal) {
	del2 = one / fl[(now << 2) + 3];
    }
    if ((d__1 = fl[(nx << 2) + 3], abs(d__1)) > vsmal * smal) {
	del2 += one / fl[(nx << 2) + 3];
    }
    *irr = 10;
    if (del2 == zero) {
	goto L999;
    }
L60:

/* ---     COMPARE ACCURACY OF ACTUAL AND ESTIMATED CHORD LENGTH. */
    dif = (del2 - del1) / del1;
    if (ibugg_1.ibug != 11) {
	goto L22;
    }
    bad_(&c_n4, &c__1, "FLNW", &fl[(now << 2) + 1], (ftnlen)4);
    bad_(&c_n4, &c__1, "FLNX", &fl[(nx << 2) + 1], (ftnlen)4);
    bad_(&c__1, &c__1, "DEL1", &del1, (ftnlen)4);
    bad_(&c__1, &c__1, "DEL2", &del2, (ftnlen)4);
    bad_(&c_n1, &c__1, "DIF ", &dif, (ftnlen)4);
L22:
    if (abs(dif) > *tolr) {
	goto L100;
    }
/* ---     ACCURACY IS ACCEPTABLE, IS SPLINE ALSO INCREASING THO. */
    if (fl[(nx << 2) + 2] <= fl[(now << 2) + 2]) {
	goto L100;
    }
    if (fl[(now << 2) + 3] < zero) {
	goto L100;
    }
    if (fl[(nx << 2) + 3] < zero) {
	goto L100;
    }
/* ---     NOW CHECK FOR A MAX OR MIN WITHIN THE INTERVAL */
    a = fl[(now << 2) + 3] * del1;
    b = fl[(nx << 2) + 3] * del1;
    aa = (b + a - (fl[(nx << 2) + 2] - fl[(now << 2) + 2]) * 2.f) * 3.f + 
	    vsmal;
    bb = ((fl[(nx << 2) + 2] - fl[(now << 2) + 2]) * 3.f - a * 2.f - b) * 2.f;
    cc = a;
    disc = bb * bb - aa * 4.f * cc;
    if (ibugg_1.ibug != 11) {
	goto L33;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    bad_(&c__1, &c__1, "AA  ", &aa, (ftnlen)4);
    bad_(&c__1, &c__1, "BB  ", &bb, (ftnlen)4);
    bad_(&c__1, &c__1, "CC  ", &cc, (ftnlen)4);
    bad_(&c_n1, &c__1, "DISC", &disc, (ftnlen)4);
L33:
    if (disc < zero) {
	goto L90;
    }
    disc = sqrt(disc);
    r__ = (-bb - disc) / (aa * 2.f);
    if ((d__1 = r__ - half, abs(d__1)) < half) {
	goto L100;
    }
    r__ = (-bb + disc) / (aa * 2.f);
    if ((d__1 = r__ - half, abs(d__1)) < half) {
	goto L100;
    }
L90:
/* ---     FUNCTION MEETS ALL CRITERIA, SO GO AFTER THE NXT ARC */
    ++now;
    cnow = fl[(now << 2) + 1];
    fl[(now << 2) + 1] = del2 + anglen;
    anglen += del2;
    udel = unx - unow;
    unow = unx;
    unx = unow + udel * 4.f;
    unx = min(one,unx);
    if (unow > one - smal) {
	goto L500;
    }
    *irr = 8;
    if (now > *numax - 2) {
	goto L999;
    }
    goto L40;
/* ---     DECREASE UNX AND TRY AGAIN */
L100:
/* ---      RECOVER SECOND DERIVATIVE FOR FIRST POINT */
    if (unow > smal) {
	goto L110;
    }
    hdel = (fl[(nx << 2) + 1] - fl[(now << 2) + 1]) / 2.f;
    hdel2 = hdel * hdel / 2.f;
    fl[(now << 2) + 4] = (fl[(nx << 2) + 2] - fl[(now << 2) + 2] - hdel * (fl[
	    (now << 2) + 3] + fl[(nx << 2) + 3]) + hdel2 * fl[(nx << 2) + 4]) 
	    / hdel2;
L110:
    unx = (unow + unx) * half;
    ++ichk;
    *irr = 9;
    if (ichk > 10) {
	goto L999;
    }
    goto L50;

L500:
    *irr = 0;
    fl[(now << 2) + 2] = one;
/* ---     TRANSLATE FLOW RATES TO ORIGIN */
    *num = now;
    dif = fl[5];
    i__1 = *num;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fl[(i__ << 2) + 1] -= dif;
/* L510: */
    }
L999:
    *num = now;
    return 0;
} /* angseg_ */

