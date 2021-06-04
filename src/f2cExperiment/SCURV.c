/* SCURV.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c_n4 = -4;
static integer c__1 = 1;
static integer c__3 = 3;

/* *** SOURCE FILE : M0004151.V04   *** */

/* Subroutine */ int scurv_(doublereal *s, integer *irr)
{
    /* Initialized data */

    static doublereal smal1 = 1e-9;
    static doublereal smal2 = 1e-5;
    static doublereal vsmal = 1e-30;
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal three = 3.;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a[9]	/* was [3][3] */, b, c__[16]	/* was [4][4] 
	    */, d__, e;
    static integer i__, j, k, l;
    static doublereal r__[16]	/* was [4][4] */, w, x[5], y[5], a0, a1, a2, 
	    c0, bb, cl[16]	/* was [4][4] */;
    static integer jj, kk;
    static doublereal va[3], vb[3], dt;
    static integer np;
    static doublereal xi;
    static integer nt;
    static doublereal yi, vn[3], xm, ym, xt[5], yt[5];
    extern /* Subroutine */ int bad_();
    static doublereal dif[3];
    static integer nhd, nph;
    static doublereal dot;
    static integer npl;
    static doublereal sum;
    static integer npn1, npn2;
    static doublereal beta;
    extern /* Subroutine */ int gelg_(doublereal *, doublereal *, doublereal *
	    , integer *, integer *, integer *);
    static doublereal disc, alph;
    static integer jlim;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer nphm, nplp, mxct, irrr;
    static doublereal sumx, sumy;
    static integer ndiff;
    static doublereal denom, cnorm, ctolr;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), snorm_(doublereal *, doublereal *, integer *);
    static char badmsg[20];
    static integer ilevel;
    extern /* Subroutine */ int ratcon_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), crvlen_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    integer *), cprint_(char *, ftnlen), ssplin_(doublereal *, 
	    integer *);
    static integer numint;

/* ------ INPUT IS A STREAM OF POINTS TOGETHER WITH VARIOUS */
/* ------ TANSPL,CRSSPL,NORMAL,WEIGHT,LIMIT CONSTRAINTS */
/* ------ ALL OF THIS INPUT IS STRUCTURED INTO THE S ARRAY */
/* ------ THE OBJECTIVE OF THIS ROUTINE IS TO CREATE EITHER */
/* ------ A CONIC ARC(S(3,1,1)=3.) OR A SPLINE CURVE(S(3,1,1)=2.) */
/* ------ THE FINAL PROCESSED CURVE IS PACKED INTO THE S ARRAY */
/* ------ REVISED VERSION, CRANFIELD 1981, R.J.G./M.J.P. */


    /* Parameter adjustments */
    s -= 29;

    /* Function Body */
    irrr = 0;
    *irr = 0;

/* -------  FIRST CHECK FOR PRESENCE OF NULL ARC */
    nhd = (integer) s[30];
    npl = nhd + 1;
    np = (integer) s[32];
    nph = nhd + np;
    nplp = npl + 1;
    nphm = nph - 1;

    if (ibugg_1.ibug != 11) {
	goto L7;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " ENTRY TO SCURV", (ftnlen)20, (ftnlen)15);
    cprint_(badmsg, (ftnlen)20);
    jlim = (integer) (s[32] + one);
    i__1 = jlim;
    for (j = 1; j <= i__1; ++j) {
	for (i__ = 1; i__ <= 6; ++i__) {
	    bad_(&c_n4, &c__1, "SC  ", &s[(i__ + j * 6 << 2) + 1], (ftnlen)4);
/* L8: */
	}
    }
L7:

    if (np != 2) {
	goto L1;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L2: */
	dif[i__ - 1] = s[i__ + (nph * 6 + 1 << 2)] - s[i__ + (npl * 6 + 1 << 
		2)];
    }
    dotf_(&w, dif, dif);
    if (w > vsmal) {
	goto L1;
    }
/* -------  NULL ARC INPUT CONFIRMED, PROCESS CURVE DEFINITION HERE */

/* -------  SET UP COONS CANON FORM FOR NULL CURVE */
    for (i__ = 1; i__ <= 3; ++i__) {
	c__[(i__ << 2) - 4] = s[i__ + (npl * 6 + 1 << 2)];
	c__[(i__ << 2) - 3] = s[i__ + (nph * 6 + 1 << 2)];
	c__[(i__ << 2) - 2] = zero;
	c__[(i__ << 2) - 1] = zero;
/* L3: */
    }
    c__[12] = one;
    c__[13] = one;
    c__[14] = zero;
    c__[15] = zero;
/* -------  NOW MOVE ALL VECTOR CONSTRAINTS */
    for (i__ = 1; i__ <= 4; ++i__) {
	s[i__ + ((npl - 1) * 6 + 5 << 2)] = s[i__ + (npl * 6 + 3 << 2)];
	s[i__ + ((npl - 1) * 6 + 6 << 2)] = s[i__ + (npl * 6 + 4 << 2)];
	s[i__ + (npl * 6 + 5 << 2)] = s[i__ + (nph * 6 + 3 << 2)];
	s[i__ + (npl * 6 + 6 << 2)] = s[i__ + (nph * 6 + 4 << 2)];
	for (j = 1; j <= 4; ++j) {
	    s[i__ + (j + npl * 6 << 2)] = c__[i__ + (j << 2) - 5];
/* L5: */
	}
/* L4: */
    }

/* -------  REDUCE POINT BLOCK COUNT BY 1 AND QUIT */
    s[32] -= one;
    goto L1000;

L1:
/* ------ ELIMINATE ALL SMALL CONSTRAINT VECTORS BEFORE SSPLIN */
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	if (s[(i__ * 6 + 3 << 2) + 4] < smal2) {
	    goto L12;
	}
	dotf_(&w, &s[(i__ * 6 + 3 << 2) + 1], &s[(i__ * 6 + 3 << 2) + 1]);
	if (w > vsmal) {
	    goto L12;
	}
/* ------ CONSTRAINT VECTOR IS SMALL, SO ELIMINATE IT */
	for (l = 1; l <= 4; ++l) {
/* L13: */
	    s[l + (i__ * 6 + 3 << 2)] = zero;
	}
L12:
	;
    }

/* ------ CALL SSPLIN FOR SMOOTHING AND GENERATION OF TANGENTS, */
/* ------ DISCRIMINATION OF INPUT ERRORS AND GENERATION OF TANGENT */
/* ------ DIRECTIONS AT EACH POINT IN THE CASE OF A SPLINE DEFINITION */

    ssplin_(&s[29], irr);
    if (*irr != 0) {
	goto L998;
    }
/* ------ JUMP TO LABEL 700 FOR SPLINE PROCESSING */

/* ------ THE CASE OF A CURSEG DEFINITION */
/* ------ TEST FOR COPLANARITY OF THE NUMERICAL INPUT */
/* ------ BEGIN BY CONSTRUCTING THE FIRST CHORD VECTOR */
    nhd = (integer) s[30];
    npl = nhd + 1;
    np = (integer) s[32];
    nph = nhd + np;
    nplp = npl + 1;
    nphm = nph - 1;
    if (s[31] != three) {
	goto L700;
    }
    for (l = 1; l <= 3; ++l) {
/* L10: */
	va[l - 1] = s[l + (nplp * 6 + 1 << 2)] - s[l + (npl * 6 + 1 << 2)];
    }
    snorm_(va, va, &irrr);
    if (np == 2) {
	goto L25;
    }
/* ------ CONSTRUCT A SECOND NON PARALLEL CHORD VECTOR */
    i__1 = nphm;
    for (i__ = nplp; i__ <= i__1; ++i__) {
	for (l = 1; l <= 3; ++l) {
	    vb[l - 1] = s[l + ((i__ + 1) * 6 + 1 << 2)] - s[l + (npl * 6 + 1 
		    << 2)];
/* L30: */
	}
	cross_(vb, va, vn);
/* Computing 2nd power */
	d__1 = vn[0];
/* Computing 2nd power */
	d__2 = vn[1];
/* Computing 2nd power */
	d__3 = vn[2];
	d__ = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	if (d__ > smal1) {
	    goto L50;
	}
/* L20: */
    }
/* ------ THE POINTS ARE COLINEAR SO FIND A NONPARALLEL TANGENT */
L25:
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	kk = 0;
	if (s[(i__ * 6 + 4 << 2) + 4] != zero) {
	    kk = 4;
	}
	if (s[(i__ * 6 + 2 << 2) + 4] != zero) {
	    kk = 2;
	}
	if (kk == 0) {
	    goto L40;
	}
	if (i__ == nph) {
	    goto L42;
	}
	cross_(va, &s[(kk + i__ * 6 << 2) + 1], vn);
	goto L45;
L42:
	cross_(&s[(kk + i__ * 6 << 2) + 1], va, vn);
L45:
/* Computing 2nd power */
	d__1 = vn[0];
/* Computing 2nd power */
	d__2 = vn[1];
/* Computing 2nd power */
	d__3 = vn[2];
	d__ = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	if (d__ > smal1) {
	    goto L50;
	}
L40:
	;
    }
/* ------ THERE IS NO UNIQUE NORMAL, CONDITIONS INDICATE A STRAIGHT LINE */
    goto L200;

/* ------ VN IS THE POTENTIAL NORMAL TO THE BASE PLANE */
L50:
    snorm_(vn, vn, &irrr);
/* ------ NOW CHECK ALL INPUT POINTS AND VECTORS TO SEE IF THEY */
/* ------ DO LIE IN THE BASE PLANE */
    i__1 = nph;
    for (i__ = nplp; i__ <= i__1; ++i__) {
	for (l = 1; l <= 3; ++l) {
/* L110: */
	    dif[l - 1] = s[l + (i__ * 6 + 1 << 2)] - s[l + (npl * 6 + 1 << 2)]
		    ;
	}
	snorm_(dif, dif, &irrr);
	dot = dif[0] * vn[0] + dif[1] * vn[1] + dif[2] * vn[2];
/* ------ NON COPLANAR POINTS */
	*irr = 5751;
	if (abs(dot) > smal2) {
	    goto L998;
	}
/* L100: */
    }
/* ------ NOW CHECK FOR NON COPLANAR TANGENTS */
/* ------ NT GIVES TOTAL NUMBER OF TANGENT CONSTRAINTS */
    *irr = 5752;
    nt = 0;
    i__1 = nph;
    for (i__ = npl; i__ <= i__1; ++i__) {
	if (s[(i__ * 6 + 2 << 2) + 4] == zero) {
	    goto L120;
	}
	++nt;
	dot = vn[0] * s[(i__ * 6 + 2 << 2) + 1] + vn[1] * s[(i__ * 6 + 2 << 2)
		 + 2] + vn[2] * s[(i__ * 6 + 2 << 2) + 3];
	if (abs(dot) > smal2) {
	    goto L998;
	}
L120:
	;
    }
    *irr = 5753;
    if (np + nt > 5) {
	goto L998;
    }
/* ------ ERROR IF MORE THAN 5 IMPOSED CONSTRAINTS */
    goto L300;
/* ------ INPUT DOES LIE IN A PLANE */

/* ------ LINEAR CASE */
L200:
    for (k = 1; k <= 2; ++k) {
	i__ = npl;
	if (k == 2) {
	    i__ = nph;
	}
	for (l = 1; l <= 3; ++l) {
	    c__[k + (l << 2) - 5] = s[l + (i__ * 6 + 1 << 2)];
/* L210: */
	    c__[k + 2 + (l << 2) - 5] = s[l + (nph * 6 + 1 << 2)] - s[l + (
		    npl * 6 + 1 << 2)];
	}
    }
    c__[12] = one;
    c__[13] = one;
    c__[14] = zero;
    c__[15] = zero;
    goto L604;

/* ------ NON-LINEAR CASES; CONSTRUCT NEW COORDINATE SYSTEM */
L300:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L305: */
	va[i__ - 1] = dif[i__ - 1];
    }
    cross_(vn, va, vb);
    snorm_(vb, vb, irr);
/* ------ VA,VB,VN ARE NEW AXES CENTRED AT FIRST POINT */
/* ------ R IS RATIONAL TRANSFORMATION MATRIX */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L310: */
	r__[i__ + 11] = 0.f;
    }
    r__[15] = 1.f;
    for (j = 1; j <= 3; ++j) {
	r__[(j << 2) - 4] = va[j - 1];
	r__[(j << 2) - 3] = vb[j - 1];
	r__[(j << 2) - 2] = vn[j - 1];
/* L320: */
	r__[(j << 2) - 1] = s[j + (npl * 6 + 1 << 2)];
    }
/* ------ NEW COORDINATES STORED IN ARRAYS X,Y,TANGENTS IN XT,YT */
    npn1 = np - 1;
    i__1 = npn1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sumx = 0.f;
	sumy = 0.f;
	for (j = 1; j <= 3; ++j) {
	    sumx += (s[j + ((npl + i__) * 6 + 1 << 2)] - s[j + (npl * 6 + 1 <<
		     2)]) * va[j - 1];
/* L330: */
	    sumy += (s[j + ((npl + i__) * 6 + 1 << 2)] - s[j + (npl * 6 + 1 <<
		     2)]) * vb[j - 1];
	}
	x[i__] = sumx;
/* L340: */
	y[i__] = sumy;
    }
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = npl + i__ - 1;
	if (s[(j * 6 + 2 << 2) + 4] == zero) {
	    goto L350;
	}
	xt[i__ - 1] = s[(j * 6 + 2 << 2) + 1] * va[0] + s[(j * 6 + 2 << 2) + 
		2] * va[1] + s[(j * 6 + 2 << 2) + 3] * va[2];
	yt[i__ - 1] = s[(j * 6 + 2 << 2) + 1] * vb[0] + s[(j * 6 + 2 << 2) + 
		2] * vb[1] + s[(j * 6 + 2 << 2) + 3] * vb[2];
L350:
	;
    }
    x[0] = 0.f;
    y[0] = 0.f;

/* ------ CHECK CONVEXITY OF POINTS AND CONDITIONS DEFINED */
    *irr = 5770;
    if (np == 2) {
	goto L361;
    }
    npn1 = np - 1;
    i__1 = npn1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	d__ = (y[i__ - 1] - y[i__ - 2]) * (x[i__] - x[i__ - 2]) - (x[i__ - 1] 
		- x[i__ - 2]) * (y[i__] - y[i__ - 2]);
	if (d__ <= smal1) {
	    goto L998;
	}
/* L360: */
    }
L361:

    if (nt == 0) {
	goto L372;
    }
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s[((npl + i__ - 1) * 6 + 2 << 2) + 4] == zero) {
	    goto L371;
	}
	i__2 = np;
	for (j = 1; j <= i__2; ++j) {
	    if (j == i__) {
		goto L370;
	    }
	    dt = (x[j - 1] - x[i__ - 1]) * yt[i__ - 1] - (y[j - 1] - y[i__ - 
		    1]) * xt[i__ - 1];
	    if (dt <= smal1) {
		goto L998;
	    }
L370:
	    ;
	}
L371:
	;
    }
L372:

/* ------ FIT CONIC X*X+B*Y*Y+C0*X*Y+D*X+E*Y=0 TO DATA */
    d__ = -x[np - 1];
    *irr = 5772;
    if (np + nt == 4) {
	goto L400;
    }
    if (np + nt == 5) {
	goto L500;
    }
/* ------ 3 CONDITIONS DEFINE UNIQUE CIRCULAR ARC */
    if (nt == 0) {
	goto L381;
    }
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s[((npl + i__ - 1) * 6 + 2 << 2) + 4] == zero) {
	    goto L380;
	}
	e = -(x[i__ - 1] * 2.f * xt[i__ - 1] + y[i__ - 1] * 2.f * yt[i__ - 1] 
		+ d__ * xt[i__ - 1]) / yt[i__ - 1];
L380:
	;
    }
L381:
    if (np != 3) {
	goto L390;
    }
    e = -(x[1] * x[1] + y[1] * y[1] + d__ * x[1]) / y[1];
L390:

/* ------ GENERATE CANONICAL FORM MATRIX CL */
    a0 = (sqrt(d__ * d__ + e * e) - e) / abs(d__);
    a2 = a0 * a0;
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L391: */
	    cl[i__ + (j << 2) - 5] = 0.f;
	}
    }
    cl[12] = a2 + 1.f;
    cl[1] = -d__ * (a2 + 1.f);
    cl[13] = a2 + 1.f;
    cl[2] = -d__ * (1.f - a2);
    cl[6] = a0 * -2.f * d__;
    cl[14] = a2 * -4.f;
    cl[3] = -d__ * (a2 * 3.f + 1.f);
    cl[7] = a0 * 2.f * d__;
    cl[15] = a2 * 4.f;
    goto L600;
/* ------ FOUR CONDITIONS,CURVE IS ELLIPSE OR PARABOLA */
L400:
    if (nt != 2) {
	goto L410;
    }
    e = -d__ * xt[0] / yt[0];
    c0 = -(xt[1] / yt[1] + xt[0] / yt[0]);
/* ------ MINIMUM ECCENTRICITY ELLIPSE HAS B=C0*C0/2+1, PARABOLA B=C0*C0/4 */
    b = c0 * c0 / 2.f + 1.f;
    goto L550;
L410:
    if (nt != 1) {
	goto L425;
    }
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (s[((npl + i__ - 1) * 6 + 2 << 2) + 4] == zero) {
	    goto L420;
	}
/* ------ FORM QUADRATIC A2*C0*C0+A1*C0+A0=0 FOR C,TRY B=1+C0*C0/2 FIRST */
	a2 = y[1] * yt[i__ - 1] * (y[i__ - 1] - y[1] * .5f);
	a1 = y[1] * (x[i__ - 1] * yt[i__ - 1] + y[i__ - 1] * xt[i__ - 1] - x[
		1] * yt[i__ - 1]);
	a0 = xt[i__ - 1] * y[1] * (x[i__ - 1] * 2.f + d__) - x[1] * yt[i__ - 
		1] * (x[1] + d__) + a2 * 2.f;
L420:
	;
    }
    goto L430;
L425:
    a2 = y[1] * y[2] * (y[1] - y[2]) / 2.f;
/* ------ CASE OF 4 DEFINED POINTS */
    a1 = y[1] * y[2] * (x[1] - x[2]);
    a0 = x[1] * y[2] * (x[1] + d__) - x[2] * y[1] * (x[2] + d__) + a2 * 2.f;
L430:
    if (abs(a2) <= smal1) {
	goto L450;
    }
    disc = a1 * a1 - a2 * 4.f * a0;
    if (disc < zero) {
	goto L460;
    }
    if (disc > smal1) {
	goto L435;
    }
    c0 = -a1 / (a2 * 2.f);
    goto L455;
L435:
    for (k = 1; k <= 3; k += 2) {
	c0 = (-a1 + (k - 2) * sqrt(disc)) / (a2 * 2.f);
	b = c0 * c0 / 2.f + 1.f;
	e = (x[1] * x[1] + b * y[1] * y[1] + c0 * x[1] * y[1] + d__ * x[1]) / 
		(-y[1]);
	if (d__ * e < zero && d__ * (e - c0 * d__) < zero) {
	    goto L550;
	}
/* L440: */
    }
    goto L460;
L450:
    c0 = -a0 / a1;
/* ------ EQUAL ROOTS OR LINEAR EQUATION FOR C */
L455:
    b = c0 * c0 / 2.f + 1.f;
    e = (x[1] * x[1] + b * y[1] * y[1] + c0 * x[1] * y[1] + d__ * x[1]) / (-y[
	    1]);
    if (d__ * e < zero && d__ * (e - c0 * d__) < zero) {
	goto L550;
    }
L460:
    a2 /= 2.f;
/* ------ PARABOLIC CASE */
    a0 -= a2 * 4.f;
    if (abs(a2) <= smal1) {
	goto L480;
    }
    disc = a1 * a1 - a0 * 4.f * a2;
    if (disc < 0.f) {
	goto L998;
    }
    if (disc > smal1) {
	goto L465;
    }
    c0 = -a1 / (a2 * 2.f);
    goto L485;
L465:
    for (k = 1; k <= 3; k += 2) {
	c0 = (-a1 + (k - 2) * sqrt(disc)) / (a2 * 2.f);
	b = c0 * c0 / 4.f;
	e = (x[1] * x[1] + b * y[1] * y[1] + c0 * x[1] * y[1] + d__ * x[1]) / 
		(-y[1]);
	if (d__ * e < zero && d__ * (e - c0 * d__) < zero) {
	    goto L550;
	}
/* L470: */
    }
    goto L998;
/* ------ NO SATISFACTORY CONIC FOUND */
L480:
    c0 = -a0 / a1;
/* ------ EQUAL ROOTS OR LINEAR EQUATIONS FOR C */
L485:
    b = c0 * c0 / 4.f;
    e = (x[1] * x[1] + b * y[1] * y[1] + c0 * x[1] * y[1] + d__ * x[1]) / (-y[
	    1]);
    if (d__ * e < zero && d__ * (e - c0 * d__) < zero) {
	goto L550;
    }
    goto L998;
L500:

/* ------ UNIQUE CONIC DEFINED BY 5 CONDITIONS; */
/* ------ SET UP EQUATIONS FOR COEFFICIENTS */
    npn2 = np - 2;
    i__1 = npn2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = i__ + 1;
	a[i__ - 1] = y[j - 1] * y[j - 1];
	a[i__ + 2] = x[j - 1] * y[j - 1];
	a[i__ + 5] = y[j - 1];
/* L510: */
	va[i__ - 1] = -(x[j - 1] + d__) * x[j - 1];
    }
    if (nt == 0) {
	goto L530;
    }
    i__ = np - 2;
    i__1 = np;
    for (j = 1; j <= i__1; ++j) {
	if (s[((npl + j - 1) * 6 + 2 << 2) + 4] == zero) {
	    goto L520;
	}
	++i__;
	a[i__ - 1] = y[j - 1] * 2.f * yt[j - 1];
	a[i__ + 2] = y[j - 1] * xt[j - 1] + x[j - 1] * yt[j - 1];
	a[i__ + 5] = yt[j - 1];
	va[i__ - 1] = -(x[j - 1] * 2.f + d__) * xt[j - 1];
L520:
	;
    }
/* ------ SOLVE LINEAR EQUATIONS */
L530:
    gelg_(va, a, &smal1, &c__3, &c__1, irr);
    if (*irr == 0) {
	goto L540;
    }
    *irr = 5772;
    goto L998;
L540:
    b = va[0];
    c0 = va[1];
    e = va[2];

/* ------ COEFFICIENTS OF CONIC HAVE BEEN DETERMINED,FIND MID POINT OF */
/* ------ ARC (XM,YM) AND TANGENT INTERSECTION (XI,YI) */
L550:
    *irr = 5760;
    xm = d__ * -.5f;
    if (abs(b) > smal2) {
	goto L560;
    }
    if (c0 < smal2) {
	goto L555;
    }
    if ((d__1 = e / c0 + .5f, abs(d__1)) < .5f) {
	goto L998;
    }
/* ------ DISCONTINUOUS HYPERBOLIC CASES REJECTED */
L555:
    ym = xm * xm / (e - c0 * xm);
    goto L570;
L560:
    bb = e - c0 * .5f * d__;
    disc = bb * bb + b * d__ * d__;
    if (disc < 0.f) {
	goto L998;
    }
    ym = (-bb + sqrt(disc)) / (b * 2.f);
L570:
    denom = e * 2.f - c0 * d__;
    if (abs(denom) <= smal1) {
	goto L998;
    }
/* ------ PARALLEL TANGENTS */
    xi = -d__ * e / denom;
    yi = d__ * d__ / denom;
    if (yi * ym < zero) {
	goto L998;
    }
/* ------ POINTS ON OPPOSITE SIDES OF CHORD */
    d__1 = -d__;
    ratcon_(&d__1, &xm, &ym, &xi, &yi, cl);

/* ------ NOW REVERSE THE COORDINATE TRANSFORMATION */
L600:
    cnorm = 0.f;
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    sum = 0.f;
	    for (k = 1; k <= 4; ++k) {
/* L601: */
		sum += cl[i__ + (k << 2) - 5] * r__[k + (j << 2) - 5];
	    }
	    if (abs(sum) > cnorm) {
		cnorm = sum;
	    }
/* L602: */
	    c__[i__ + (j << 2) - 5] = sum;
	}
    }
/* ------ NORMALISE THE C MATRIX */
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 4; ++j) {
/* L603: */
	    c__[i__ + (j << 2) - 5] = c__[i__ + (j << 2) - 5] * 10.f / cnorm;
	}
    }
/* ------ BUILD THE NEW DATA BASE CONSISTING OF A SINGLE RATIONAL */
/* ------ CUBIC CURVE WITH POSSIBLE CRRSPL AND NORMAL CONSTRAINTS */
/* ------ AT CURVE ENDS */
/* ------ SHIFT THE FIRST AND LAST CONSTRAINT VECTORS INTO APPROPRIATE */
/* ------ PARTS OF THE FINAL ARRAY */
L604:
    ndiff = nph - npl;
    i__1 = nph;
    i__2 = ndiff;
    for (i__ = npl; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	k = nhd;
	if (i__ == nph) {
	    k = nhd + 1;
	}
	for (j = 3; j <= 4; ++j) {
	    jj = j + 2;
	    for (l = 1; l <= 4; ++l) {
/* L620: */
		s[l + (jj + k * 6 << 2)] = s[l + (j + i__ * 6 << 2)];
	    }
/* L610: */
	}
    }
/* ------ NOW LOAD THE RATIONAL PARAMETRIC CUBIC CANON FORM */
/* ------ INTO THE DATA BASE */
    for (k = 1; k <= 4; ++k) {
	for (l = 1; l <= 4; ++l) {
/* L630: */
	    s[l + (k + npl * 6 << 2)] = c__[l + (k << 2) - 5];
	}
    }
/* ------ ZERO OUT THE REST OF THE ARRAY */
    i__2 = nph;
    for (i__ = nplp; i__ <= i__2; ++i__) {
	for (k = 1; k <= 6; ++k) {
	    for (l = 1; l <= 4; ++l) {
/* L640: */
		s[l + (k + i__ * 6 << 2)] = zero;
	    }
	}
    }
    s[32] = one;
    goto L1000;
/* ------ THE INPUT HERE IS A PARTIALLY COMPLETED SPLINE DATA BASE */
/* ------ IN THIS SECTION FINAL LENGTHS ARE ASSIGNED TO TANGENT VECTORS */
/* ------ COONS MATRICES ARE CONSTRUCTED FOR EACH SEGMENT, AND THE */
/* ------ COMPLETE DATA BASE IS CONSTRUCTED */

L700:
/* ------ FIRST SHIFT THE LOCATION OF ALL CROSS SPLINE AND NORMAL */
/* ------ CONSTRAINTS */
    i__2 = nph;
    for (i__ = npl; i__ <= i__2; ++i__) {
	for (k = 3; k <= 4; ++k) {
	    for (l = 1; l <= 4; ++l) {
		s[l + (k + 2 + (i__ - 1) * 6 << 2)] = s[l + (k + i__ * 6 << 2)
			];
/* L710: */
	    }
	}
    }
/* ------ NOW GENERATE LENGTHS FOR VECTORS AND THEN COONS MATRICES */

    i__2 = nphm;
    for (i__ = npl; i__ <= i__2; ++i__) {
/* -------  THREE LOGIC LEVELS FOR TANGENT VECTOR LENGTHS ARE AVAILABLE */
/* -------  ILEVEL=2, DEFAULT, MINIMIZES DDR(0)**2+DDR(1)**2 */
	ilevel = 2;
/* -------  ILEVEL=1 USE CHORD LENGTH FOR TANGENT VECTORS */
/* -------  ILEVEL=3 USED LENGTHS WHICH MINIMIZE TENSION */
	if (ibugg_1.ibug == 9) {
	    ilevel = 1;
	}
	if (ibugg_1.ibug == 10) {
	    ilevel = 3;
	}
/* -------  CTOLR SETS THE TOLERANCE LEVEL FOR TERMINATING THE */
/* -------  ITERATIVE PROCESS OF ADJUSTING TANGENT LENGTHS FOR */
/* -------  THE PURPOSE OF REDUCING CURVE TENSION. */
	ctolr = .005f;
/* -------  NUMINT IS THE NUMBER OF INTERVALS USED FOR APPROXIMATING */
/* -------  TENSION.  VALUE 5 IS ECONOMIC BUT MORE MAY PRODUCE */
/* -------  MORE ACCURATE RESULTS, BUT WITH GREATER RUN TIMES */
	numint = 5;
/* -------  MXCT IS AN UPPER LIMIT ON THE NUMBER OF ITERATIONS */
/* -------  THIS IS TO LIMIT TOTAL CPU TIME FOR SPLINING. */
	mxct = 10;
/* -------  ALPH AND BETA ARE THE DESIRED LENGTHS OF TANGENT VECTORS */

	crvlen_(&s[(i__ * 6 + 1 << 2) + 1], &s[((i__ + 1) * 6 + 1 << 2) + 1], 
		&s[(i__ * 6 + 2 << 2) + 1], &s[((i__ + 1) * 6 + 2 << 2) + 1], 
		&alph, &beta, &numint, &mxct, &ctolr, &ilevel);

/* ------ THIS ASSIGNMENT OF LENGTHS IS BASED ON A MINIMUM VALUE */
/* ------ FOR THE INTEGRAL OF THE SECOND DERIVATIVE SQUARED */
	for (l = 1; l <= 3; ++l) {
	    c__[(l << 2) - 4] = s[l + (i__ * 6 + 1 << 2)];
	    c__[(l << 2) - 3] = s[l + ((i__ + 1) * 6 + 1 << 2)];
	    c__[(l << 2) - 2] = alph * s[l + (i__ * 6 + 2 << 2)];
	    c__[(l << 2) - 1] = beta * s[l + ((i__ + 1) * 6 + 2 << 2)];
/* L750: */
	}
	c__[12] = one;
	c__[13] = one;
	c__[14] = zero;
	c__[15] = zero;
/* ------ NOW LOAD THE COONS MATRIX INTO THE S ARRAY */
	for (k = 1; k <= 4; ++k) {
	    for (l = 1; l <= 4; ++l) {
/* L760: */
		s[l + (k + i__ * 6 << 2)] = c__[l + (k << 2) - 5];
	    }
	}
/* L720: */
    }

/* ------ ZERO OUT THE LAST BLOCK AND RESET THE POINT BLOCK NUMBER */
    s[32] = (doublereal) (np - 1);
    for (k = 1; k <= 6; ++k) {
	for (l = 1; l <= 4; ++l) {
/* L770: */
	    s[l + (k + nph * 6 << 2)] = zero;
	}
    }
    goto L1000;
L1000:
    *irr = 0;
L998:

    if (ibugg_1.ibug != 11) {
	goto L917;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " EXIT FROM SCURV", (ftnlen)20, (ftnlen)16);
    cprint_(badmsg, (ftnlen)20);
    jlim = (integer) (s[32] + one);
    i__2 = jlim;
    for (j = 1; j <= i__2; ++j) {
	for (i__ = 1; i__ <= 6; ++i__) {
	    bad_(&c_n4, &c__1, "SC  ", &s[(i__ + j * 6 << 2) + 1], (ftnlen)4);
/* L918: */
	}
    }
L917:

    return 0;
} /* scurv_ */

