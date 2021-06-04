/* ETORUS.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : ETORUS.ORG   *** */

/* Subroutine */ int etorus_(doublereal *u, doublereal *v, doublereal *geo, 
	doublereal *result, integer *mode)
{
    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static real r1, r2;
    static doublereal ap[3], ua, va, cu, cv, sn[3], rp, su, sv, tot;

/* PARAMETRIC EVALUATOR FOR TORUS. */
/* TORUS PATCH CANONICAL DATA IS IN GEO(15) */
/*  GEO(1)-GEO(3) = AXIS OF TORUS */
/*  GEO(4)-GEO(6) = CENTRE OF TORUS */
/*  GEO(7)-GEO(9) = REF. AXIS (I.E. DEFINES U=0,V=0) */
/*  GEO(10)       = MAJOR RADIUS R1 */
/*  GEO(11)       = MINOR RADIUS R2 */
/*  GEO(12)       = UMIN (IN RADIANS) */
/*  GEO(13)       = UMAX (IN RADIANS) */
/*  GEO(14)       = VMIN (IN RADIANS) */
/*  GEO(15)       = VMAX (IN RADIANS) */
/* RESULT RETURNS IN HOMOGENEOUS COORDINATES POINT, FIRST DERIVATIVES, */
/* 2ND DERIVATIVES, NORMAL AND UNIT NORMAL AT (U,V) */
    /* Parameter adjustments */
    result -= 5;
    --geo;

    /* Function Body */
    ua = *u * (geo[13] - geo[12]) + geo[12];
    va = *v * (geo[15] - geo[14]) + geo[14];
    su = sin(ua);
    sv = sin(va);
    cu = cos(ua);
    cv = cos(va);
    r1 = geo[10];
    r2 = geo[11];
/* AP IS THIRD ORTHOGONAL AXIS P*A */
    ap[0] = -geo[2] * geo[9] + geo[3] * geo[8];
    ap[1] = -geo[3] * geo[7] + geo[1] * geo[9];
    ap[2] = -geo[1] * geo[8] + geo[2] * geo[7];
    rp = r1 + r2 * cu;
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__ + 4] = geo[i__ + 3] + r2 * su * geo[i__] + cv * rp * geo[
		i__ + 6] + sv * rp * ap[i__ - 1];
/* L10: */
    }
    result[8] = 1.f;
/* POINT EVALUATED, NOW FIND DERIVATIVES RU,RV */
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__ + 8] = r2 * cu * geo[i__] - r2 * cv * su * geo[i__ + 6] - 
		r2 * sv * su * ap[i__ - 1];
	result[i__ + 12] = -rp * sv * geo[i__ + 6] + cv * rp * ap[i__ - 1];
/* L20: */
    }
/* FIND 2ND DERIVATIVES RUU, RUV AND RVV */
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__ + 16] = -r2 * su * geo[i__] - r2 * cu * (cv * geo[i__ + 6] 
		+ sv * ap[i__ - 1]);
	result[i__ + 20] = r2 * su * (sv * geo[i__ + 6] - cv * ap[i__ - 1]);
	result[i__ + 24] = -rp * (cv * geo[i__ + 6] + sv * ap[i__ - 1]);
/* L30: */
    }
/* EVALUATE SURFACE NORMAL SN */
    sn[0] = result[10] * result[15] - result[11] * result[14];
    sn[1] = result[11] * result[13] - result[9] * result[15];
    sn[2] = result[9] * result[14] - result[10] * result[13];
    tot = 0.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__ + 28] = sn[i__ - 1];
	tot += sn[i__ - 1] * sn[i__ - 1];
/* L40: */
    }
    tot = sqrt(tot);
    if (tot <= 1e-8f) {
	goto L55;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	result[i__ + 32] = sn[i__ - 1] / tot;
/* L50: */
    }
/* SET W COMPONENT OF ALL VECTOR QUANTITIES TO 0.0 (?) */
L55:
    for (i__ = 2; i__ <= 8; ++i__) {
	result[(i__ << 2) + 4] = 0.f;
/* L60: */
    }
    return 0;
} /* etorus_ */

