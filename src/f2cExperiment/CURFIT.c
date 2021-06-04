/* CURFIT.f -- translated by f2c (version 20100827).
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
static integer c__3 = 3;

/* *** SOURCE FILE : M0000623.V01   *** */

/* Subroutine */ int curfit_(doublereal *pa, doublereal *pb, doublereal *pc, 
	doublereal *pd, doublereal *ta, doublereal *td, integer *ktyp, 
	integer *irr)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal b, c__;
    static integer i__;
    static doublereal r__, s, x, d1, d2, d3, dt, df1, df2, df3, bcb, ddf, del,
	     bsq, crit, suma, sumb;
    static integer idiag;
    static doublereal ccoef[12]	/* was [3][4] */;
    extern /* Subroutine */ int forcub_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    , parint_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), parmpt_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);

    /* Parameter adjustments */
    --td;
    --ta;
    --pd;
    --pc;
    --pb;
    --pa;

    /* Function Body */
    idiag = 27000;
    *irr = 0;
/* ------INPUT IS FOUR POINTS PA,PB,PC,PD IN LINEAR ORDER */
/* ------OUTPUT IS TANGENT VECTORS TA,TD OF A SMOOTH CUBIC CURVE */
/* ------WHICH PASSES THRU THE INPUT POINTS.  IF IRR.NE.0 , THEN */
/* ------THERE IS POTENTIAL TROUBLE IN THE INPUT POINTS */
/* ------THE FIRST STEP IS A CHECK FOR EQUALITY OF PB AND PC */
/* ------KTYP IS OUTPUT CURVE TYPE. 1=NULL CURVE, */
/* ------2=STRAIGHT SEGMENT, 3= THREE POINT CURVE, 4= FOUR PT CURVE */
/* Computing 2nd power */
    d__1 = pb[1] - pa[1];
/* Computing 2nd power */
    d__2 = pb[2] - pa[2];
/* Computing 2nd power */
    d__3 = pb[3] - pa[3];
    d1 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* Computing 2nd power */
    d__1 = pc[1] - pb[1];
/* Computing 2nd power */
    d__2 = pc[2] - pb[2];
/* Computing 2nd power */
    d__3 = pc[3] - pb[3];
    d2 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* Computing 2nd power */
    d__1 = pd[1] - pc[1];
/* Computing 2nd power */
    d__2 = pd[2] - pc[2];
/* Computing 2nd power */
    d__3 = pd[3] - pc[3];
    d3 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    dt = d1 + d2 + d3;
/* ------VARIOUS CHECKS ARE MADE ON THE INPUT TO DETECT DEGENERATE CASES */
/* ------FOR EXAMPLE PA=PB=PC.NE.PD WILL INDICATE A SRAIGHT LINE THRU */
/* ------PA AND PD. */
    crit = 1e-5f;
    if (dt > crit) {
	goto L100;
    }
/* ------THIS IS CASE OF A ZERO CURVE */
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = 0.f;
/* L10: */
	td[i__] = 0.f;
    }
    *ktyp = 1;
    goto L999;
L100:
    if (d1 > crit && d2 > crit) {
	goto L200;
    }
    if (d1 > crit && d3 > crit) {
	goto L200;
    }
    if (d2 > crit && d3 > crit) {
	goto L200;
    }
/* ------THE STRAIGHT LINE CASE */
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = pd[i__] - pa[i__];
/* L120: */
	td[i__] = ta[i__];
    }
    *ktyp = 2;
    goto L999;
/* ------FINALLY CHECK FOR THREE POINT DEGENERACY */
L200:
    if (d1 < crit) {
	goto L400;
    }
    if (d2 < crit) {
	goto L400;
    }
    if (d3 < crit) {
	goto L400;
    }
/* ------THE NON TRIVIAL FOUR POINT CURVE FOLLOWS */
    forcub_(&pa[1], &pb[1], &pc[1], &pd[1], &ta[1], &td[1], irr);
    if (*irr == 0) {
	goto L310;
    }
/* ------TRY A MORE RUDIMENTARY ESTIMATE OF TA AND TD */
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = (pb[i__] - pa[i__]) * dt / d1;
	td[i__] = (pd[i__] - pc[i__]) * dt / d3;
/* L320: */
    }
L310:
/* ------NOW PROJECT PB AND PC ONTO THE INITIAL ESTIMATED CURVE */
    for (i__ = 1; i__ <= 3; ++i__) {
	ccoef[i__ - 1] = pa[i__];
	ccoef[i__ + 2] = pd[i__];
	ccoef[i__ + 5] = ta[i__];
/* L330: */
	ccoef[i__ + 8] = td[i__];
    }
    df1 = pd[1] - pa[1];
    df2 = pd[2] - pa[2];
    df3 = pd[3] - pa[3];
    ddf = df1 * df1 + df2 * df2 + df3 * df3 + 1e-30;
    b = ((pb[1] - pa[1]) * df1 + (pb[2] - pa[2]) * df2 + (pb[3] - pa[3]) * 
	    df3) / ddf;
    c__ = ((pc[1] - pa[1]) * df1 + (pc[2] - pa[2]) * df2 + (pc[3] - pa[3]) * 
	    df3) / ddf;
    parmpt_(&pa[1], &pd[1], &pb[1], &b, &pc[1], &c__, &ta[1], &td[1], irr);
    *ktyp = 4;
    goto L999;
/* ------THE THREE POINT DEGENERATE CASE FOLLOWS */
L400:
/* ------PB SHOULD BE THE NONTRIVIAL THIRD POINT */
    if (d1 > crit) {
	goto L410;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L420: */
	pb[i__] = pc[i__];
    }
L410:
    parint_(&pa[1], &pb[1], &pd[1], &ta[1], &r__, &c__1, irr);
    if (*irr != 0) {
	goto L430;
    }
    parint_(&pa[1], &pb[1], &pd[1], &td[1], &r__, &c__3, irr);
    goto L450;
L430:
    *irr = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = (pb[i__] - pa[i__]) / max(d1,d2);
	td[i__] = (pd[i__] - pb[i__]) / max(d2,d3);
/* L440: */
    }
L450:
/* ------NOW PROJECT THE PB ONTO THE INITIAL CURVE */
    df1 = pd[1] - pa[1];
    df2 = pd[2] - pa[2];
    df3 = pd[3] - pa[3];
    ddf = df1 * df1 + df2 * df2 + df3 * df3 + 1e-12;
    b = ((pb[1] - pa[1]) * df1 + (pb[2] - pa[2]) * df2 + (pb[3] - pa[3]) * 
	    df3) / ddf;
/* ------DETERMINE A SCALAR X SUCH THAT THE VECTORS X*TA AND X*TD */
/* ------MAKE A CLOSEST APPROACH TO THE POINT PB AT THE PARAMETER */
/* ------VALUE B. */
    bsq = b * b;
    bcb = b * bsq;
    suma = 0.f;
    sumb = 0.f;
    for (i__ = 1; i__ <= 3; ++i__) {
	del = pd[i__] - pa[i__];
	r__ = pa[i__] + del * (bsq * 3 - bcb * 2);
	s = ta[i__] * (b - bsq - bsq + bcb) + td[i__] * (-bsq + bcb);
/* ------MINIMIZE THE FORM (R+ X*S - PB)**2 WITH RESPECT TO X */
	r__ -= pb[i__];
	suma += r__ * s;
	sumb += s * s;
/* L470: */
    }
    if (abs(sumb) < 1e-8) {
	x = 1.f;
    }
    if (abs(sumb) >= 1e-8) {
	x = -suma / sumb;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	ta[i__] = x * ta[i__];
/* L480: */
	td[i__] = x * td[i__];
    }
    *ktyp = 3;
    *irr = 0;
L999:
    return 0;
} /* curfit_ */

