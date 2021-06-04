/* ARCSEG.f -- translated by f2c (version 20100827).
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
static integer c_n1 = -1;
static integer c_n4 = -4;
static integer c__3 = 3;

/* *** SOURCE FILE : M0001909.W01   *** */

/* Subroutine */ int arcseg_(doublereal *c__, doublereal *fl, doublereal *
	tolr, integer *num, integer *numax, integer *irr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal half = .5;
    static doublereal smal = 1e-6;
    static doublereal vsmal = 1e-30;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__, j;
    static doublereal r__, u, a1, a2, d1;
    static integer j1, j2;
    static doublereal aa, bb, cc;
    static integer ia, ib;
    static doublereal cv[16];
    static integer nx, nx1;
    extern /* Subroutine */ int bad_();
    static integer iii;
    static doublereal err, cvv[20]	/* was [4][5] */;
    static integer now;
    static doublereal unx;
    static integer ichk;
    static doublereal disc, sarc[3], udel, unow, tolri, ucheck, arclen;
    extern /* Subroutine */ int cncurv_(doublereal *, doublereal *, 
	    doublereal *, integer *);

/* ---     INPUT  C A RATIONAL PARAMETRIC CUBIC CURVE SEGMENT */
/* ---     INPUT  NUMAX THE MAXIMUM NUMBER OF FLO RATE SPLINES ALLWD */
/* ---    INPUT  TOLR THE TOLERANCE TO BE USED IN FITTING(.001 NORMAL) */
/* ---    OUTPUT IRR ERROR FLAG, ZERO IS CORRECT, NONZERO IS ERROR. */
/* ---     OUTPUT NUM  NUMBER OF FLOW SPLINES GENERATED */
/* ---     OUTPUT FL(4,NUM) 4-POSITION FLOW FUNCTIONS CREATED. */
/* ---            FL(1,I) IS THE ACCUMULATED ARC LENGTH */
/* ---            FL(2,I) IS THE CORRESPONDING COONS PARAMETER */
/* ---            FL(3,I) IS THE RATE OF CHANGE OF COONS PARAM */
/* ---            FL(4,I) IS THE SECOND DERIVATIVE OF COON'S PARAMETER */

/* ---     PURPOSE IS GENERATE A CUBIC SEGMENT WITH ARC AS FLOW RATE. */

/*   HILFSSPEICHER FUER 5 ZWISCHENPUNKTE */
    /* Parameter adjustments */
    --c__;
    fl -= 5;

    /* Function Body */
/* ---     NOW=CURRENT ACCEPTED POINT, NX=NEXT CADIDATE POINT */
/* ---     ALGORITHM PROCEEDS BY SUBDIVIDING REMAINING ARC BY TWO */
/* ---     UNTIL A SATISFACTORY PARAMETERIZATION OF A SUBARC IS OBTAINED */
    now = 1;
    arclen = zero;
    unow = zero;
    cncurv_(&unow, &c__[1], cv, &c__1);
/* ---     DETERMINE RATES OF CHANGE AT THIS POINT */
/* Computing 2nd power */
    d__1 = cv[4];
/* Computing 2nd power */
    d__2 = cv[5];
/* Computing 2nd power */
    d__3 = cv[6];
    a = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) + vsmal;
    b = (cv[4] * cv[8] + cv[5] * cv[9] + cv[6] * cv[10]) / a;
/* ---     LOAD THE KEY VALUES FOR THE STARTING POINT */
    fl[(now << 2) + 1] = arclen;
    fl[(now << 2) + 2] = unow;
    fl[(now << 2) + 3] = one / a;
/* Computing 3rd power */
    d__1 = a;
    fl[(now << 2) + 4] = -b / (d__1 * (d__1 * d__1));
    unx = .76f;
/*   'FLOW,ARC,...'  KORREKTOR BEI GERADEN 'SPLINE/CURSEG'-BOEGEN */
    if (c__[13] != one || c__[14] != one || c__[15] != zero || c__[16] != 
	    zero) {
	goto L45;
    }
    if ((d__1 = c__[2] - c__[1] - c__[3], abs(d__1)) > smal || (d__2 = c__[3] 
	    - c__[4], abs(d__2)) > smal) {
	goto L45;
    }
    if ((d__1 = c__[6] - c__[5] - c__[7], abs(d__1)) > smal || (d__2 = c__[7] 
	    - c__[8], abs(d__2)) > smal) {
	goto L45;
    }
    if ((d__1 = c__[10] - c__[9] - c__[11], abs(d__1)) > smal || (d__2 = c__[
	    11] - c__[12], abs(d__2)) > smal) {
	goto L45;
    }
    goto L49;
/*   UNTERSUCHUNG AUF ANNAEHERND GERADEN BOEGEN */
L45:
    for (j = 1; j <= 5; ++j) {
	u = (doublereal) j;
	u = (u - 1.) / 4.;
/* L46: */
	cncurv_(&u, &c__[1], &cvv[(j << 2) - 4], &c__0);
    }
/* BERECHNUNG DER DISTANZEN */
    for (j = 1; j <= 5; ++j) {
	j1 = j;
	j2 = j + 1;
	if (j != 5) {
	    goto L48;
	}
	j1 = 1;
	j2 = 5;
L48:
/* Computing 2nd power */
	d__1 = cvv[(j2 << 2) - 4] - cvv[(j1 << 2) - 4];
/* Computing 2nd power */
	d__2 = cvv[(j2 << 2) - 3] - cvv[(j1 << 2) - 3];
/* Computing 2nd power */
	d__3 = cvv[(j2 << 2) - 2] - cvv[(j1 << 2) - 2];
	cvv[(j << 2) - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L47: */
    }
    a1 = cvv[3] + cvv[7] + cvv[11] + cvv[15];
    tolri = (a1 - cvv[19]) / cvv[19];
    if (abs(tolri) > *tolr) {
	goto L50;
    }
    a2 = cvv[19] / 4.;
    for (j = 1; j <= 4; ++j) {
	if ((d__1 = (cvv[(j << 2) - 1] - a2) / a2, abs(d__1)) > *tolr) {
	    goto L50;
	}
/* L42: */
    }
/*    TESTDRUCKE  *************** */
    bad_(&c_n1, &c__1, "TOLI", &tolri, (ftnlen)4);
    bad_(&c__1, &c__1, "TOLR", tolr, (ftnlen)4);
    bad_(&c__1, &c__1, "A   ", &a, (ftnlen)4);
    bad_(&c__1, &c__1, "A1  ", &a1, (ftnlen)4);
    bad_(&c_n1, &c__1, "B   ", &b, (ftnlen)4);
    a = a1;
L49:
    *irr = 22;
    now = 2;
    fl[9] = a - vsmal;
    fl[10] = one;
    fl[7] = one / fl[9];
    fl[11] = fl[7];
    fl[8] = zero;
    fl[12] = fl[8];
    if (now > *numax - 2) {
	goto L999;
    }
    goto L500;
/* --- */
L50:
    ichk = 1;
L60:
    cncurv_(&unx, &c__[1], cv, &c__1);
    nx = now + 1;
/* ---     DETERMINE RATES OF CHANGE AT THIS POINT */
/* Computing 2nd power */
    d__1 = cv[4];
/* Computing 2nd power */
    d__2 = cv[5];
/* Computing 2nd power */
    d__3 = cv[6];
    a = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) + vsmal;
    b = (cv[4] * cv[8] + cv[5] * cv[9] + cv[6] * cv[10]) / a;
/* ---     LOAD THE KEY VALUES */
    fl[(nx << 2) + 1] = arclen;
    fl[(nx << 2) + 2] = unx;
    fl[(nx << 2) + 3] = one / a;
/* Computing 3rd power */
    d__1 = a;
    fl[(nx << 2) + 4] = -b / (d__1 * (d__1 * d__1));

/* ---     CALCULATE THE MID PT BETWEEN UNOW AND UNX AND CHECK FOR */
/* ---     TOLERANCE BETWEEN TOTAL ARC AND SUM OF SUBARCS. */
/* L100: */
    ucheck = (unow + unx) * half;
    cncurv_(&ucheck, &c__[1], cv, &c__1);
/* ---     DETERMINE RATES OF CHANGE AT THIS POINT */
/* Computing 2nd power */
    d__1 = cv[4];
/* Computing 2nd power */
    d__2 = cv[5];
/* Computing 2nd power */
    d__3 = cv[6];
    a = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) + vsmal;
    b = (cv[4] * cv[8] + cv[5] * cv[9] + cv[6] * cv[10]) / a;
/* ---     LOAD THE KEY VALUES */
    fl[(nx + 1 << 2) + 2] = ucheck;
    fl[(nx + 1 << 2) + 3] = one / a;
/* Computing 3rd power */
    d__1 = a;
    fl[(nx + 1 << 2) + 4] = -b / (d__1 * (d__1 * d__1));
/* ---     COMPARE UNOW,UNX  UNOW,UCHECK  UCHECK,UNX */
    for (i__ = 1; i__ <= 3; ++i__) {
	ia = now;
	ib = nx;
	if (i__ == 3) {
	    ia += 2;
	}
	if (i__ == 2) {
	    ++ib;
	}
/* ---     COMPUTE ARC LENGTH BY SPECIAL SPLINE FUNCTION FORMULA. */
	sarc[i__ - 1] = (fl[(ib << 2) + 2] - fl[(ia << 2) + 2]) * 3.f * (fl[(
		ib << 2) + 4] + fl[(ia << 2) + 4]);
	a = fl[(ib << 2) + 4] * (fl[(ia << 2) + 3] * 2.f + fl[(ib << 2) + 3]) 
		+ fl[(ia << 2) + 4] * (fl[(ia << 2) + 3] + fl[(ib << 2) + 3] *
		 2.f);
	if (abs(a) < vsmal) {
	    goto L109;
	}
	sarc[i__ - 1] /= a;
	goto L110;
/* ---     SPECIAL PATH WHEN SECOND DERIVATIVE IS ZERO */
L109:
	d1 = zero;
	if ((d__1 = fl[(ia << 2) + 3], abs(d__1)) > vsmal * smal) {
	    d1 = one / fl[(ia << 2) + 3];
	}
	if ((d__1 = fl[(ib << 2) + 3], abs(d__1)) > vsmal * smal) {
	    d1 += one / fl[(ib << 2) + 3];
	}
	*irr = 23;
	if (d1 == zero) {
	    goto L999;
	}
	sarc[i__ - 1] = (fl[(ib << 2) + 2] - fl[(ia << 2) + 2]) * d1 / 2.;
L110:
	;
    }

    err = (sarc[0] - sarc[1] - sarc[2]) / (sarc[0] + vsmal);
    if (ibugg_1.ibug != 11) {
	goto L23;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    nx1 = nx + 1;
    i__1 = nx1;
    for (iii = now; iii <= i__1; ++iii) {
	bad_(&c_n4, &c__1, "FL  ", &fl[(iii << 2) + 1], (ftnlen)4);
/* L24: */
    }
    bad_(&c__3, &c__1, "SARC", sarc, (ftnlen)4);
    bad_(&c_n1, &c__1, "ERR ", &err, (ftnlen)4);
L23:
    if (abs(err) > *tolr) {
	goto L150;
    }
/* ---     ACCURACY IS OKAY, NOW CHECK IF SPLINE IS INCREASING */
    if (fl[(now << 2) + 2] >= fl[(now + 1 << 2) + 2]) {
	goto L150;
    }
    if (fl[(now << 2) + 3] <= zero) {
	goto L150;
    }
    if (fl[(nx << 2) + 3] <= zero) {
	goto L150;
    }
/* ---     NOW CHECK FOR A MAX OR MIN WITHIN THE INTERVAL */
    a = fl[(now << 2) + 3] * sarc[0];
    b = fl[(nx << 2) + 3] * sarc[0];
    aa = (b + a - (fl[(nx << 2) + 2] - fl[(now << 2) + 2]) * 2.) * 3.;
    if (abs(aa) < vsmal) {
	aa = vsmal;
    }
    bb = ((fl[(nx << 2) + 2] - fl[(now << 2) + 2]) * 3.f - a * 2.f - b) * 2.f;
    cc = a;
    disc = bb * bb - aa * 4.f * cc;
    if (disc < zero) {
	goto L140;
    }
    disc = sqrt(disc);
    r__ = (-bb - disc) / (aa * 2.f);
    if ((d__1 = r__ - half, abs(d__1)) < half) {
	goto L150;
    }
    r__ = (-bb + disc) / (aa * 2.f);
    if ((d__1 = r__ - half, abs(d__1)) < half) {
	goto L150;
    }
L140:
/* ---     FUNCTION MEETS ALL CONDITIONS, NOW CONSOLIDATE AND TRY */
/* ---     TO FIT NEXT SUBARC. */
    fl[(nx << 2) + 1] = sarc[0] + arclen;
    arclen += sarc[0];
/* ---     UPDATE POINTER AND TRY TO FIT NEXT SUBARC */
    ++now;
    udel = unx - unow;
    unow = unx;
    unx = unow + udel * 4.f;
    unx = min(one,unx);
    if (unow >= one - vsmal) {
	goto L500;
    }
    *irr = 22;
    if (now > *numax - 2) {
	goto L999;
    }
    goto L50;
/* ---     CUT SUBARC IN HALF AND TRY TO FIT AGAIN */
L150:
    unx = ucheck;
    ++ichk;
    *irr = 1;
    if (ichk > 10) {
	goto L999;
    }
    goto L60;
/* ---     PROPER END OF PROCESSING */
L500:
    *irr = 0;
L999:
    *num = now;
    return 0;
} /* arcseg_ */

