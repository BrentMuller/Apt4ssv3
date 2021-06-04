/* FORCUB.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__1 = 1;

/* *** SOURCE FILE : M0000629.V01   *** */

/* Subroutine */ int forcub_(doublereal *pa, doublereal *pb, doublereal *pc, 
	doublereal *pd, doublereal *ta, doublereal *td, integer *irr)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal t1[3], t2[3], qa[3], qb[3], qc[3], qd[3], cn[3], dx[3], 
	    dy[3], ra, rd, gx, gy, hx, hy, gl, hl, dif[3], one, pav[3], beta, 
	    difl, alph, cosa, cosd, sina, sind, temp;
    static integer idiag;
    static doublereal vnull[3];
    extern /* Subroutine */ int norml3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), clocub_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *), parint_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);

/* ------INPUT IS FOUR SPACE POINTS PA,PB,PC,PD.   OUTPUT TA, TD DEFINES */
/* ------A PARAMETRIC CUBIC CURVE WITH END POINTS PA,PD AND END TANGENT */
/* ------VECTORS TA,TD  WHICH APPROXIMATES SMOOTHLY THE POINTS PB AND PC */
/* ------THIS IS A COMPLETELY MODULAR APT SCULPTURED SURFACE ROUTINE */
/* ------ WRITTEN AT IITRI APRIL 1970 --- JKH */
    /* Parameter adjustments */
    --td;
    --ta;
    --pd;
    --pc;
    --pb;
    --pa;

    /* Function Body */
    one = 1.f;
    idiag = 18000;
/* ------AVERAGE INTERIOR POINTS PB,PC INTO PAV */
    for (i__ = 1; i__ <= 3; ++i__) {
	dif[i__ - 1] = pd[i__] - pa[i__];
/* L10: */
	pav[i__ - 1] = (pb[i__] + pc[i__]) / 2.f;
    }
/* Computing 2nd power */
    d__1 = dif[0];
/* Computing 2nd power */
    d__2 = dif[1];
/* Computing 2nd power */
    d__3 = dif[2];
    difl = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    *irr = idiag + 1;
    if (difl < 1e-10) {
	return 0;
    }
/* ------CONSTRUCT THE AVERAGED NORMAL TO PA,PAV,PD */
    norml3_(&pa[1], pav, &pd[1], cn, irr);
    if (*irr != 0) {
	norml3_(&pa[1], &pb[1], &pd[1], cn, irr);
    }
    if (*irr != 0) {
	norml3_(&pa[1], &pc[1], &pd[1], cn, irr);
    }
    if (*irr == 0) {
	goto L20;
    }
/* ------STRAIGHT LINE CASE */
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = dif[i__ - 1];
/* L30: */
	td[i__] = dif[i__ - 1];
    }
    *irr = 0;
    return 0;
L20:
/* ------CONSIDER THE COMMON PLANE THROUGH PA,PB WITH NORMAL CN */
/* ------CONSTRUCT ORTHOGONAL COORDINATE VECTORS DX AND DY IN THIS PLANE */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	dx[i__ - 1] = dif[i__ - 1] / difl;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L50: */
	vnull[i__ - 1] = 0.f;
    }
    norml3_(vnull, cn, dx, dy, irr);
/* ------NOW PROJECT ALL POINTS PA,PB,PC,PD ONTO THE AVERAGED PLANE. */
/* ------CALL THE PROJECTIONS BY QA,QB,QC,QD */
    qa[0] = 0.f;
    qa[1] = 0.f;
    qa[2] = 0.f;
    qd[0] = difl;
    qd[1] = 0.f;
    qd[2] = 0.f;
    for (j = 1; j <= 3; ++j) {
	qb[j - 1] = 0.f;
/* L300: */
	qc[j - 1] = 0.f;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	qb[0] += (pb[i__] - pa[i__]) * dx[i__ - 1];
	qb[1] += (pb[i__] - pa[i__]) * dy[i__ - 1];
	qc[0] += (pc[i__] - pa[i__]) * dx[i__ - 1];
	qc[1] += (pc[i__] - pa[i__]) * dy[i__ - 1];
/* L310: */
    }
/* ------NOW INTERPOLATE TANGENT VECTORS AND RADII AT EACH END OF THE */
/* ------CURVE (USING A PARABOLIC APPROXIMATION) */
    parint_(&pa[1], &pb[1], &pc[1], t1, &ra, &c__1, irr);
/* ------ADJUST THE SIGN OF THE RADIUS */
    temp = qb[0] * qc[1] - qb[1] * qc[0];
    ra = abs(ra) * d_sign(&one, &temp);
/* ------CONVERT FROM RADIUS TO CURVATURE */
    if (ra > 1e8) {
	ra = 1e-8;
    }
    if (ra <= 1e8) {
	ra = 1.f / ra;
    }
    parint_(&pd[1], &pc[1], &pb[1], t2, &rd, &c__1, irr);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L60: */
	t2[i__ - 1] = -t2[i__ - 1];
    }
    temp -= difl * (qc[1] - qb[1]);
    rd = abs(rd) * d_sign(&one, &temp);
/* ------CONVERT FROM RADIUS TO CURVATURE */
    if (rd <= 1e8) {
	rd = 1.f / rd;
    }
    if (rd > 1e8) {
	rd = 1e-8;
    }
/* ------NOW END TANGENTS AND END RADII HAVE BEEN APPROXIMATED IN THE */
/* ------AVERAGED PLANE */
/* ------NOW OBTAIN COMPONENTS OF THE INTERPOLATED TANGENTS T1 AND T2 IN */
/* ------THE AVERAGED PLANE */
    gx = t1[0] * dx[0] + t1[1] * dx[1] + t1[2] * dx[2];
    gy = t1[0] * dy[0] + t1[1] * dy[1] + t1[2] * dy[2];
    hx = t2[0] * dx[0] + t2[1] * dx[1] + t2[2] * dx[2];
    hy = t2[0] * dy[0] + t2[1] * dy[1] + t2[2] * dy[2];
    gl = sqrt(gx * gx + gy * gy);
    hl = sqrt(hx * hx + hy * hy);
/* ------MODIFY THE SPACE CURVATURES RA AND RD BY THEIR PROJECTIONS ON THE */
/* ------AVERAGED PLANE */
    cosa = cn[0] * t1[0] + cn[1] * t1[1] + cn[2] * t1[2];
    temp = (d__1 = one - cosa * cosa, abs(d__1));
    sina = sqrt(temp);
    cosd = cn[0] * t2[0] + cn[1] * t2[1] + cn[2] * t2[2];
    temp = (d__1 = one - cosd * cosd, abs(d__1));
    sind = sqrt(temp);
    ra /= sina;
    rd /= sind;
/* ------NOW SOLVE IN THE AVERAGED PLANE FOR A PARAMETRIC PLANAR CUBIC */
/* ------WITH END POINTS QA,QD AND END TANGENTS GX,GY AND HX,HY , AND */
/* ------WITH END CURVATURE RA AND RB */
/* ------THE OUTPUT ALPH,BETA GIVES THE SIGNED MULTIPLIERS OF THE INPUT */
/* ------VECTORS GX ,GY AND HX,HY. */
    clocub_(qa, &qa[1], qd, &qd[1], &gx, &gy, &hx, &hy, &ra, &rd, &alph, &
	    beta, irr);
    if (*irr != 0) {
	return 0;
    }
/* ------PROJECT THE PLANAR SOLUTIONS ONTO THE INTERPOLATED SPACE */
/* ------TANGENTS FOR A FINAL ANSWER */
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = alph * t1[i__ - 1] / gl;
/* L200: */
	td[i__] = beta * t2[i__ - 1] / hl;
    }
    *irr = 0;
    return 0;
} /* forcub_ */

