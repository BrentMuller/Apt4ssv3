/* CHDSEG.f -- translated by f2c (version 20100827).
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

static integer c__3 = 3;
static integer c__1 = 1;
static integer c_n3 = -3;
static integer c_n4 = -4;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0001049.V04   *** */

/* Subroutine */ int chdseg_(doublereal *c__, doublereal *fl, doublereal *
	tolr, integer *num, integer *numax, integer *irr, doublereal *p, 
	doublereal *d__, doublereal *v)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-6;
    static doublereal vsmal = 1e-30;
    static doublereal half = .5;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__;
    static doublereal r__, t[3], aa, bb, cc, dt, cv[16], dv;
    static integer nx;
    extern /* Subroutine */ int bad_();
    static doublereal dif;
    static integer now;
    static doublereal unx, del1, del2;
    static integer ichk;
    static doublereal disc, udel, temp, cnow, unow, chdlen;
    extern /* Subroutine */ int cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);

/* ---     SUBROUTINE PURPOSE IS TO PARAMETERIZE A RATIONAL CUBIC */
/* ---     ARC IN TERMS OF A PROJECTION IN DIRECTION V UPON AN */
/* ---     ARBITRARY LINE IN SPACE DETERMINED BY A POINT P AND */
/* ---      A DIRECTION VECTOR D */
/* ---     INPUT  C IS A RATIONAL PARAMETRIC CUBIC CURVE C */
/* ---     INPUT  NUMAX IS THE MAXIMUM NUMBER OF ARCS WHICH CAN */
/* ---            BE GENERATED(DUE TO BUFFER SPACE) */
/* ---    INPUT  TOLR THE TOLERANCE TO BE USED IN FITTING(.001 NORMAL) */
/* ---    OUTPUT IRR ERROR FLAG, ZERO IS CORRECT, NONZERO IS ERROR. */
/* ---     OUTPUT IS A SET OF FLOW FUNCTIONS FL(4,NUM) WHERE */
/* ---     FL(1,) IS ACCUMULATED CHORD LENGTH */
/* ---     FL(2,) IS CORRESPONDING COONS PARAMETER */
/* ---     FL(3,) IS RATE OF CHANGE OF PARAMETER */
/* ---     FL(4,) IS SECOND DERIVATIVE. */
/* ---  OUTPUT  NUM IS USUALLY NUMBER OF SEGMENTS, NEGATIVE IS ERROR. */

    /* Parameter adjustments */
    --v;
    --d__;
    --p;
    fl -= 5;
    --c__;

    /* Function Body */

/* ---     METHOD IS TO SPLIT ARC INTO SMALLER AND SMALLER SUBARCS */
/* ---     UNTIL WHOLE ARC HAS BEEN FIT TO ACCEPTABLE ACCURACY. */
/* ---     BEGIN BY DEVELOPING VECTOR CONSTANTS */

    a = sqrt(v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
    *irr = 2;
    if (a < vsmal) {
	goto L999;
    }
    t[0] = v[1] / a;
    t[1] = v[2] / a;
    t[2] = v[3] / a;

    if (ibugg_1.ibug != 11) {
	goto L2;
    }
    bad_(&c__3, &c__1, "P   ", &p[1], (ftnlen)4);
    bad_(&c__3, &c__1, "D   ", &d__[1], (ftnlen)4);
    bad_(&c__3, &c__1, "V   ", &v[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "T   ", t, (ftnlen)4);
L2:

    *irr = 3;
    dt = d__[1] * t[0] + d__[2] * t[1] + d__[3] * t[2];
    if (abs(dt) < vsmal) {
	goto L999;
    }
    now = 1;
    chdlen = zero;
    unow = zero;
    cncurv_(&unow, &c__[1], cv, &c__1);
/* ---     CHECK FOR VALIDITY OF PROJECTION */
    temp = cv[12] * t[0] + cv[13] * t[1] + cv[14] * t[2];
    if (temp > smal) {
	goto L5;
    }
    *irr = 4;
    if (abs(temp) < smal) {
	goto L999;
    }
/* ---     REVERSE THE DIRECTION OF T */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L6: */
	t[i__ - 1] = -t[i__ - 1];
    }
    dt = -dt;
L5:
    if (dt > zero) {
	goto L8;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L7: */
	d__[i__] = -d__[i__];
    }
    dt = -dt;
L8:

/* ---     DETERMINE PROJECTION VALUE AND DERIVATIVES */
    fl[(now << 2) + 1] = (cv[0] - p[1]) * t[0] + (cv[1] - p[2]) * t[1] + (cv[
	    2] - p[3]) * t[2];
    fl[(now << 2) + 1] /= dt;
    a = (cv[4] * t[0] + cv[5] * t[1] + cv[6] * t[2]) / dt + vsmal;
    b = (cv[8] * t[0] + cv[9] * t[1] + cv[10] * t[2]) / dt;
    fl[(now << 2) + 2] = unow;
    fl[(now << 2) + 3] = one / a;
/* Computing 3rd power */
    d__1 = a;
    fl[(now << 2) + 4] = -b / (d__1 * (d__1 * d__1));
    cnow = fl[(now << 2) + 1];
    unx = .76f;

L40:
    ichk = 1;
L50:
    cncurv_(&unx, &c__[1], cv, &c__1);
    nx = now + 1;
/* ---     CHECK FOR VALIDITY OF PROJECTION */
    temp = cv[12] * t[0] + cv[13] * t[1] + cv[14] * t[2];
/* ---     ERROR IF CURVE IS MOVING IN OPPOSITE DIRECTION TO CHORD */
    *irr = 5;
    if (temp < smal) {
	goto L999;
    }
/* ---     DETERMINE PROJECTION VALUE AND DERIVATIVES */
    fl[(nx << 2) + 1] = (cv[0] - p[1]) * t[0] + (cv[1] - p[2]) * t[1] + (cv[2]
	     - p[3]) * t[2];
    fl[(nx << 2) + 1] /= dt;
    a = (cv[4] * t[0] + cv[5] * t[1] + cv[6] * t[2]) / dt + vsmal;
    b = (cv[8] * t[0] + cv[9] * t[1] + cv[10] * t[2]) / dt;
    fl[(nx << 2) + 2] = unx;
    fl[(nx << 2) + 3] = one / a;
/* Computing 3rd power */
    d__1 = a;
    fl[(nx << 2) + 4] = -b / (d__1 * (d__1 * d__1));
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
    *irr = 4;
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
    fl[(now << 2) + 1] = del2 + chdlen;
    chdlen += del2;
    udel = unx - unow;
    unow = unx;
    unx = unow + udel * 4.f;
    unx = min(one,unx);
    if (unow > one - smal) {
	goto L500;
    }
    *irr = 6;
    if (now > *numax - 2) {
	goto L999;
    }
    goto L40;

/* ---     DECREASE UNX AND TRY AGAIN */
L100:
    unx = (unow + unx) * half;
    ++ichk;
    *irr = 7;
    if (ichk > 10) {
	goto L999;
    }
    goto L50;

L500:
    *irr = 0;
    fl[(now << 2) + 2] = one;
/* ---     TRANSLATE FLOW RATES TO ORIGIN */
    fl[5] = zero;
L999:
    *num = now;
    return 0;
} /* chdseg_ */

