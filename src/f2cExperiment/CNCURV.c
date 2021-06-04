/* CNCURV.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001054.V01   *** */

/* Subroutine */ int cncurv_(doublereal *uin, doublereal *c__, doublereal *cv,
	 integer *mode)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-14;
    static doublereal two = 2.;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal f[12];
    static integer i__;
    static doublereal u, wsq;
    static integer klim;
    static doublereal uinc, twpw;
    static integer iuout;
    extern /* Subroutine */ int blendf_(doublereal *, doublereal *);

/* ---    PURPOSE IS TO RETRIEVE CURVE POINT, DERIVATIVE AND SECOND */
/* ---    DERIVATIVE AT A PARAMETER VALUE U */
/* ---    C IS THE CANON FORM OF A RATIONAL PARAMETRIC CUBIC CURVE */
/* ---    CV(1 THRU 3) CONTAINS THE CURVE POINT OUTPUT, */
/* ---    CV(5 THRU 7) THE FIRST DERIVATIVE, CV(9 THRU 11), THE */
/* ---    SECOND DERIVATIVE AND CV(13 THRU 15 ) THE NORMALISED */
/* ---    FIRST DERIVATIVE. */
    /* Parameter adjustments */
    --cv;
    --c__;

    /* Function Body */

/* ---      SET IUOUT FLAG TO 1 WHEN U IS OUTSIDE (0,1) */
    iuout = 0;
    u = *uin;
    if (u >= zero && u <= one) {
	goto L9;
    }
    iuout = 1;
    if (u < zero) {
	u = zero;
    }
    if (u > one) {
	u = one;
    }
L9:

    blendf_(&u, f);

/* ---  CV(1)=F(1)*C(1)+F(2)*C(2)+F(3)*C(3)+F(4)*C(4) */
/* ---  CV(2)=F(1)*C(5)+F(2)*C(6)+F(3)*C(7)+F(4)*C(8) */
/* ---  CV(3)=F(1)*C(9)+F(2)*C(10)+F(3)*C(11)+F(4)*C(12) */
/* ---  CV(4)=F(1)*C(13)+F(2)*C(14)+F(3)*C(15)+F(4)*C(16) */
/* ---  CV(5)=F(5)*C(1)+F(6)*C(2)+F(7)*C(3)+F(8)*C(4) */
/* ---  CV(6)=F(5)*C(5)+F(6)*C(6)+F(7)*C(7)+F(8)*C(8) */
/* ---  CV(7)=F(5)*C(9)+F(6)*C(10)+F(7)*C(11)+F(8)*C(12) */
/* ---  CV(8)=F(5)*C(13)+F(6)*C(14)+F(7)*C(15)+F(8)*C(16) */
/* ---  CV(9)=F(9)*C(1)+F(10)*C(2)+F(11)*C(3)+F(12)*C(4) */
/* ---  CV(10)=F(9)*C(5)+F(10)*C(6)+F(11)*C(7)+F(12)*C(8) */
/* ---  CV(11)=F(9)*C(9)+F(10)*C(10)+F(11)*C(11)+F(12)*C(12) */
/* ---  CV(12)=F(9)*C(13)+F(10)*C(14)+F(11)*C(15)+F(12)*C(16) */
    klim = 9;
    if (*mode == 0) {
	klim = 1;
    }
    i__1 = klim;
    for (i__ = 1; i__ <= i__1; i__ += 4) {
	cv[i__] = f[i__ - 1] * c__[1] + f[i__] * c__[2] + f[i__ + 1] * c__[3] 
		+ f[i__ + 2] * c__[4];
	cv[i__ + 1] = f[i__ - 1] * c__[5] + f[i__] * c__[6] + f[i__ + 1] * 
		c__[7] + f[i__ + 2] * c__[8];
	cv[i__ + 2] = f[i__ - 1] * c__[9] + f[i__] * c__[10] + f[i__ + 1] * 
		c__[11] + f[i__ + 2] * c__[12];
	cv[i__ + 3] = f[i__ - 1] * c__[13] + f[i__] * c__[14] + f[i__ + 1] * 
		c__[15] + f[i__ + 2] * c__[16];
/* L10: */
    }
    if (*mode == 0) {
	goto L100;
    }
/* ---     NOW CHECK IF THE FORM IS RATIONAL OR SIMPLE */
    wsq = one;
    for (i__ = 13; i__ <= 16; ++i__) {
	if (i__ > 14) {
	    wsq = zero;
	}
	if ((d__1 = c__[i__] - wsq, abs(d__1)) > smal) {
	    goto L30;
	}
/* L25: */
    }
/* ---     FORM IS SIMPLE NON-RATIONAL SO SKIP THESE CALCULATIONS */
    goto L100;
/* ---     CALCULATE DERIVATIVES BASED ON FORMULA PV(I)=CV(I)/CV(4) */
L30:
    wsq = cv[4] * cv[4];
    twpw = two * cv[8] / cv[4];
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__ + 4] = (cv[i__ + 4] * cv[4] - cv[i__] * cv[8]) / wsq;
	cv[i__ + 8] = (cv[i__ + 8] * cv[4] - cv[i__] * cv[12]) / wsq - cv[i__ 
		+ 4] * twpw;
/* L40: */
    }

L100:
    wsq = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__] /= cv[4];
	if (*mode == 0) {
	    goto L110;
	}
/* Computing 2nd power */
	d__1 = cv[i__ + 4];
	wsq += d__1 * d__1;
L110:
	;
    }
    cv[4] = one;
    if (*mode == 0) {
	goto L200;
    }
/* ---      UNITIZE FIRST DERIVATIVE */
    wsq = sqrt(wsq);
    if (wsq < smal) {
	wsq = one;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__ + 12] = cv[i__ + 4] / wsq;
	cv[(i__ << 2) + 4] = one;
/* L120: */
    }

L200:

    if (iuout == 0 || *mode == 0) {
	goto L999;
    }
    uinc = *uin;
    if (*uin > one) {
	uinc = *uin - one;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__] += uinc * cv[i__ + 4];
	cv[i__ + 8] = zero;
/* L210: */
    }

L999:
    return 0;
} /* cncurv_ */

