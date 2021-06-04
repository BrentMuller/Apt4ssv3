/* SQRBN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0001094.V01   *** */

/* Subroutine */ int sqrbn_(doublereal *u0, doublereal *v0, doublereal *zu1, 
	doublereal *zv1, doublereal *zu2, doublereal *zv2, doublereal *dummy, 
	integer *ickbn)
{
    /* Initialized data */

    static integer ibchk[16]	/* was [4][4] */ = { 2,3,0,0,1,0,4,0,0,1,0,4,
	    0,0,2,3 };
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal vsmal = 1e-25;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal d__, u, v, a1, a2, a3, d2;
    static integer i1, i2;
    static doublereal u1, v1, u2, v2, dt;
    static integer iu, iv;
    static doublereal ut, vt;
    static integer ic0, ic1, ic2;

/* ------INPUT IS AN OLD POINT U0,V0 IN UV SPACE AND A TRIAL */
/* ------ NEW POINT U1,V1.  IF THESE TWO PTS ARE IN THE SAME */
/* ------ SECTOR OF SPACE( UNIT SQUARE DIVIDES SPACE INTO NINE */
/* ------ SECTORS) THEN U,V IS SET EQUAL TO U1,V1 AND NO */
/* ------ BOUNDARY CHECKING IS REQUIRED( I.E. SET ICKBN=0). */
/* ------ OTHERWISE U,V IS SET EQUAL TO THE CLOSEST */
/* ------ BOUNDARY POINT TO U0,V0 WHICH LIES BETWEEN U0,V0 AND */
/* ------ U1,V1.  IN ADDITION THE ROUTINE DETERMINES WHICH */
/* ------  BOUNDARY OF THE PATCH SHOULD BE CHECKED. */

/* ---      ARRAY WHICH RECORDS BOUNDARY TO CHECK IN MOVING FROM SECTOR */
/* ---      J TO SECTOR I (IBCHK(I,J)). */

/* ---      FUNCTION F GIVES SQUARE OF DISTANCE FROM (A,B) TO (C,D) */
/* ---      FUNCTION G IS POSITIVE WHEN C IS OUTSIDE THE A,B INTERVAL */

    u1 = *u0 + *zu1;
    v1 = *v0 + *zv1;
    *ickbn = 0;
    u = u1;
    v = v1;
    iu = 2;
    if (*u0 < zero) {
	iu = 1;
    }
    if (*u0 > one) {
	iu = 3;
    }
    iv = 3;
    if (*v0 < zero) {
	iv = 0;
    }
    if (*v0 > one) {
	iv = 6;
    }
    ic0 = iu + iv;
    iu = 2;
    if (u1 < zero) {
	iu = 1;
    }
    if (u1 > one) {
	iu = 3;
    }
    iv = 3;
    if (v1 < zero) {
	iv = 0;
    }
    if (v1 > one) {
	iv = 6;
    }
    ic1 = iu + iv;
    if (ic0 == ic1) {
	goto L999;
    }

/* ------DETERMINE THE BOUNDARY INTERCEPT CLOSEST TO U0,V0 */
/* ---      EQN OF LINE IS (U0-U1)*V+(V1-V0)*U+(V0*U1-U0*V1)=0 */
/* ---      EQN OF LINE IS      A1*V+     A2*U+     A3      =0 */
    a1 = *u0 - u1;
    a2 = v1 - *v0;
    a3 = *v0 * u1 - v1 * *u0;
/* ---      SET U,V AND DISTANCE D TO DEFAULT VALUES */
    u = u1;
    v = v1;
/* Computing 2nd power */
    d__1 = u1 - *u0;
/* Computing 2nd power */
    d__2 = v1 - *v0;
    d__ = d__1 * d__1 + d__2 * d__2;
/* ---      SET INITIAL VALUES FOR SECOND POINT BETWEEN P0 AND P1. */
    d2 = d__;
    u2 = u;
    v2 = v;

/* ---      LINE IS HORIZONTAL, SKIP INTERCEPT CALCULATION WITH U=0 OR U=1 */
    if (abs(a1) < vsmal) {
	goto L100;
    }
    ut = zero;
    vt = -a3 / a1;
/* Computing 2nd power */
    d__1 = ut - *u0;
/* Computing 2nd power */
    d__2 = vt - *v0;
    dt = d__1 * d__1 + d__2 * d__2;
    if ((*u0 - ut) * (u1 - ut) >= zero || dt > d__) {
	goto L10;
    }
    d__ = dt;
    u = ut;
    v = vt;
L10:
    ut = one;
    vt = -(a2 + a3) / a1;
/* Computing 2nd power */
    d__1 = ut - *u0;
/* Computing 2nd power */
    d__2 = vt - *v0;
    dt = d__1 * d__1 + d__2 * d__2;
    if ((*u0 - ut) * (u1 - ut) >= zero || dt >= d2) {
	goto L100;
    }
/* ---      SAVE THE SECOND CLOSEST INTERCEPT TO UO,VO FIRST */
    if (dt < d__) {
	goto L20;
    }
/* ---      U2,V2 IS NEW SECOND CLOSEST INTERCEPT ( DT.GT.D) */
    if (dt == d__) {
	goto L100;
    }
    u2 = ut;
    v2 = vt;
    d2 = dt;
    goto L100;
L20:
/* ---      U2,V2 TAKES ON THE OLD U,V VALUE OF CLOSEST INTERCEPT */
    u2 = u;
    v2 = v;
    d2 = d__;
/* ---      CLOSEST INTERCEPT U,V IS NOW UT,VT */
    u = ut;
    v = vt;
    d__ = dt;
/* ---      LINE IS VERTICAL, SKIP INTERCEPT CALC WITH V=0 OR V=1. */
L100:
    if (abs(a2) < vsmal) {
	goto L200;
    }
    vt = zero;
    ut = -a3 / a2;
/* Computing 2nd power */
    d__1 = ut - *u0;
/* Computing 2nd power */
    d__2 = vt - *v0;
    dt = d__1 * d__1 + d__2 * d__2;
    if ((*v0 - vt) * (v1 - vt) >= zero || dt >= d2) {
	goto L110;
    }
/* ---      SAVE THE SECOND CLOSEST INTERCEPT TO UO,VO FIRST */
    if (dt < d__) {
	goto L40;
    }
/* ---      U2,V2 IS NEW SECOND CLOSEST INTERCEPT ( DT.GT.D) */
    if (dt == d__) {
	goto L110;
    }
    u2 = ut;
    v2 = vt;
    d2 = dt;
    goto L110;
L40:
/* ---      U2,V2 TAKES ON THE OLD U,V VALUE OF CLOSEST INTERCEPT */
    u2 = u;
    v2 = v;
    d2 = d__;
/* ---      CLOSEST INTERCEPT U,V IS NOW UT,VT */
    u = ut;
    v = vt;
    d__ = dt;
L110:
    vt = one;
    ut = -(a1 + a3) / a2;
/* Computing 2nd power */
    d__1 = ut - *u0;
/* Computing 2nd power */
    d__2 = vt - *v0;
    dt = d__1 * d__1 + d__2 * d__2;
    if ((*v0 - vt) * (v1 - vt) >= zero || dt >= d2) {
	goto L200;
    }
/* ---      SAVE THE SECOND CLOSEST INTERCEPT TO UO,VO FIRST */
    if (dt < d__) {
	goto L60;
    }
/* ---      U2,V2 IS NEW SECOND CLOSEST INTERCEPT ( DT.GT.D) */
    if (dt == d__) {
	goto L200;
    }
    u2 = ut;
    v2 = vt;
    d2 = dt;
    goto L200;
L60:
/* ---      U2,V2 TAKES ON THE OLD U,V VALUE OF CLOSEST INTERCEPT */
    u2 = u;
    v2 = v;
    d2 = d__;
/* ---      CLOSEST INTERCEPT U,V IS NOW UT,VT */
    u = ut;
    v = vt;
    d__ = dt;
L200:
/* ---      DETERMINE UT,VT JUST INSIDE THE SECTOR BEYOND U,V */
/* ---      ICKBN IS SET TO ZERO IF NO ADJACENT PATCH NEED BE CHECKED */
/* ---      OTHERWISE ICKBN SHOULD POINT TO THE PATCH BOUNDARY (1,2,3,OR 4 */
/* ---      WHICH SHOULD BE CHECKED. */
    *ickbn = 0;
/* ---      NEXT DETERMINE THE SECTOR WHICH THE PATH FROM U0,V0 TO U,V */
/* ---      IS ENTERING. */
    ut = (u + u2) / two;
    vt = (v + v2) / two;
    if ((zero - *u0) * (one - *u0) != zero && (zero - *v0) * (one - *v0) != 
	    zero) {
	goto L210;
    }
/* ---      STARTING POINT IS ON BOUNDARY, SO CUT UT,VT BACK */
    ut = (*u0 + u) / two;
    vt = (*v0 + v) / two;
L210:

    iu = 2;
    if (ut < zero) {
	iu = 1;
    }
    if (ut > one) {
	iu = 3;
    }
    iv = 3;
    if (vt < zero) {
	iv = 0;
    }
    if (vt > one) {
	iv = 6;
    }
/* ---      IC2 IS THE SECTOR NUMBER ( 1 THRU 9) WHICH IS BEING ENTERED. */
    ic2 = iu + iv;
/* ---      IF THE CENTER SQUARE IS BEING ENTERED, THEN CHECK NO BOUNDARY */
    if (ic2 == 5) {
	goto L999;
    }
    if (ic2 % 2 == 0) {
	goto L310;
    }
    if (ic2 % 2 == 1) {
	goto L320;
    }

L310:
/* ---      AN EVEN-NUMBERED SECTOR IS BEING ENTERED -- BOUNDARY CALCULATI */
/* ---      IS STRAIGHT FORWARD. */
    *ickbn = ic2 / 2;
    goto L999;

L320:
/* ---      AN ODD SECTOR IS BEING ENTERED, BOUNDARY DEPENDS ON BOTH POINT */
/* ---      (I.E. ON SECTOR OF UT,VT AND ON SECTOR OF U0,V0) */
    i1 = ic2 / 3 + 1;
    if (ic0 % 2 != 0) {
	goto L999;
    }
    i2 = ic0 / 2;
    *ickbn = ibchk[i1 + (i2 << 2) - 5];
    goto L999;

L999:

    *zu2 = u - *u0;
    *zv2 = v - *v0;
    return 0;
} /* sqrbn_ */

