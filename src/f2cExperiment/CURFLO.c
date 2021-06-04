/* CURFLO.f -- translated by f2c (version 20100827).
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
    char darray[120];
} darray_;

#define darray_1 darray_

struct {
    integer ibug, ipcolc, ipcomc;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n1 = -1;
static integer c_n4 = -4;
static integer c__24 = 24;
static integer c__333 = 333;

/* *** SOURCE FILE : M0001061.V07   *** */

/* Subroutine */ int curflo_(doublereal *uin, doublereal *sc, doublereal *cv, 
	integer *mode, integer *nnseg)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-7;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, l;
    static doublereal u, w, w1, w2, ua, ub;
    static integer nn;
    static doublereal pu, up;
    extern /* Subroutine */ int bad_();
    static doublereal uma, umb, ulo, upp, frac;
    static integer iarc, iseg;
    static doublereal span;
    static integer nmax;
    static doublereal temp[16]	/* was [4][4] */;
    static integer merr, ispl;
    static doublereal upsq;
    static integer iarc1, iarc2, inseg;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), cross_(doublereal *, doublereal *, doublereal *),
	     vnorm_(doublereal *, doublereal *);
    static integer iflow1, iflow2, locarc;
    extern /* Subroutine */ int crblen_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer locseg;
    extern /* Subroutine */ int scdump_(integer *, doublereal *), cprint_(
	    char *, ftnlen), cncurv_(doublereal *, doublereal *, doublereal *,
	     integer *);

/* ---     PURPOSE IS TO COMPUTE CURVE POINT AND DERIVATIVES FROM AN */
/* ---     INPUT PARAMETRIC VALUE U.  SC IS THE COMPLETE INPUT CURVE */
/* ---     CANONICAL FORM AND MODE IS ZERO FOR POINT EXTRACTION, */
/* ---     AND NON ZERO IF FIRST AND SECONDERIVATIVES ARE ALSO */
/* ---     DESIRED.   CV IS THE OUTPUT ARRAY. CV(1-3) CONTAINS */
/* ---     THE CURVE POINT, CV(5-7) CONTAINS THE FIRST DERIVATIVE, */
/* ---     CV(9-11) THE SECOND DERIVATIVE AND CV(13-15) CONTAINS */
/* ---     THE UNITIZED TANGENT VECTOR */
/* ---     IF MODE=2 ON INPUT THEN CV(17-19) CONTAINS THE CRSSPL VECOTR, */
/* ---     CV(21-23) THE TWIST ETC. ANALAGOUS TO THE CURVE POINT */
/* ---     AND TANGENT VECTOR ETC. */
/* ---     IF THESE QUANTITIES DO NOT EXIST, THE UPPER PART IS ZEROED. */
/* ---     INPUT  INSEG IS NORMALLY 0.  HOWEVER, IF INSEG */
/* ---     IS POSITIVE THEN INSEG IS INTERPRETED AS A SPECIFIC */
/* ---     SEGMENT NUMBER AND UIN IS A PARAMETER */
/* ---     RELATIVE TO THIS SEGMENT ONLY.  IF UIN IS OUTSIDE THE */
/* ---     0,1 RANGE THE A POINT ON THE LINEAR EXTENSION OF THIS */
/* ---     SEGMENT WILL BE GENERATED.  IF INSEG IS NEGATIVE, THEN */
/* ---     THE ABSOLUTE VALUE REFERS TO A SEGMENT COUNTING BACKWARD FROM */
/* ---     THE LAST SEGMENT OF THE CURVE. */
/* ---     IN EITHER CASE, INSEG MUST REFER TO A LEGITIMATE SEGMENT. */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --cv;
    --sc;

    /* Function Body */

    inseg = *nnseg;
    merr = 0;


    nmax = (integer) sc[8];
/* ---     IF NMAX IS ZERO THERE IS NO FLOW STRUCTURE */
/* ---     THEN TREAT INDIVIDUAL ARCS AS CURVE SEGMENTS USING */
/* ---     THE NATURAL COON PARAMETER AS FLOW. */
    if (nmax == 0) {
	goto L300;
    }
    if (inseg == 0) {
	goto L5;
    }

    merr = 1;
    if (abs(inseg) > nmax) {
	goto L998;
    }
    iseg = abs(inseg);
    if (inseg < 0) {
	iseg = nmax - iseg + 1;
    }
    u = *uin;
    if (inseg < 0) {
	u = one - u;
    }
    frac = u;
    locseg = (integer) (sc[9] + (iseg - 1 << 2));
    if (sc[locseg + 3] < smal) {
	goto L200;
    }
    if (u >= zero && u <= one) {
	goto L30;
    }
    locarc = (integer) sc[7];
    iarc = (integer) (locarc + sc[locseg] * 4.f);
    if (u > one) {
	iarc = (integer) (iarc + (sc[locseg + 1] - one) * 4.f);
    }
    ispl = (integer) sc[iarc];
    if (u > one) {
	ispl = (integer) (ispl + (sc[iarc + 1] - one - one) * 4.f);
    }
    iarc = (iarc - locarc) / 4 + 1;
    goto L80;

L5:
    u = *uin;
    if (u < zero) {
	goto L10;
    }
    if (u > sc[8]) {
	goto L20;
    }
/* ---      OBTAIN SEGMENT NUMBER AND FRACTIONAL AMOUNT */
    iseg = (integer) u;
    frac = u - iseg;
    nmax = (integer) sc[8];
    ++iseg;
    if (iseg > nmax) {
	frac = one;
    }
    if (iseg > nmax) {
	--iseg;
    }
    goto L30;

L10:
    iseg = 1;
    frac = u;
    ispl = (integer) sc[11];
    iarc = 1;

    locseg = (integer) (sc[9] + (iseg - 1 << 2));
/* ---     BRANCH FOR CASE OF A DEGENERATE SEGMENT */
    if (sc[locseg + 3] < smal) {
	goto L200;
    }
    goto L80;

L20:
    iseg = (integer) sc[8];
    frac = u - sc[8] + one;
    ispl = (integer) (sc[11] + sc[10] * 4.f - 8.f);
    iarc = (integer) sc[4];

    locseg = (integer) (sc[9] + (iseg - 1 << 2));
/* ---     BRANCH FOR CASE OF A DEGENERATE SEGMENT */
    if (sc[locseg + 3] < smal) {
	goto L200;
    }
    goto L80;

L30:

    locseg = (integer) (sc[9] + (iseg - 1 << 2));
/* ---     BRANCH FOR CASE OF A DEGENERATE SEGMENT */
    if (sc[locseg + 3] < smal) {
	goto L200;
    }
/* ---     COMPUTE STARTING AND ENDING ARCS FOR THIS SEGMENT(ISEG) */
    locarc = (integer) sc[7];
    iarc1 = (integer) (locarc + sc[locseg] * 4.f);
    iarc2 = (integer) (iarc1 + (sc[locseg + 1] - one) * 4.f);
/* ---     FIND  AN ARC WHICH INCLUDES THE FRACTIONAL VALUE */
    i__1 = iarc2;
    for (iarc = iarc1; iarc <= i__1; iarc += 4) {
	iflow1 = (integer) sc[iarc];
	iflow2 = (integer) ((sc[iarc + 1] - one) * 4.f + sc[iarc]);
	if (frac >= sc[iflow1] && frac < sc[iflow2] + smal) {
	    goto L60;
	}
/* L50: */
    }
    merr = 2;
    goto L998;
/* --- */
L60:
/* ---     CONVERT ARC REFERENCE TO AN ABSOLUTE */
    iarc = (iarc - locarc) / 4 + 1;
/* ---     LOCATE FRAC WITHIN THE RANGE OF ONE FLOW FUNCTION */
    i__1 = iflow2;
    for (ispl = iflow1; ispl <= i__1; ispl += 4) {
	if (frac >= sc[ispl] && frac < sc[ispl + 4] + smal) {
	    goto L80;
	}
/* L70: */
    }
    merr = 3;
    goto L998;

L80:
    if (ibugg_1.ibug != 11) {
	goto L83;
    }
    bad_(&c__1, &c__1, "U   ", &u, (ftnlen)4);
    bad_(&c__1, &c__1, "FRAC", &frac, (ftnlen)4);
    bad_(&c__1, &c__0, "SEG ", &iseg, (ftnlen)4);
    bad_(&c__1, &c__0, "IARC", &iarc, (ftnlen)4);
    bad_(&c__1, &c__0, "ISPL", &ispl, (ftnlen)4);
    bad_(&c_n1, &c__0, "LOCS", &locseg, (ftnlen)4);
L83:

    if (frac < zero) {
	goto L85;
    }
    if (frac > one) {
	goto L87;
    }
/* ---      CASE WHERE FRAC IS BETWEEN ZERO AND ONE */

    pu = frac - sc[ispl];
    span = sc[ispl + 4] - sc[ispl];
    if (span == zero) {
	goto L81;
    }
    pu /= span;
    ua = sc[ispl + 1];
    ub = sc[ispl + 5];
    uma = sc[ispl + 2] * span;
    umb = sc[ispl + 6] * span;
    goto L89;

L85:
/* ---      CASE WHERE FRAC IS LT ZERO */
    pu = frac - sc[ispl];
    span = sc[ispl + 4] - sc[ispl];
    if (span == zero) {
	goto L81;
    }
    pu /= span;
    ua = sc[ispl + 1];
    uma = sc[ispl + 2] * span;
    ub = uma;
    umb = uma;
    goto L89;

L87:
    pu = frac - sc[ispl];
    span = sc[ispl] - sc[ispl - 4];
    if (span == zero) {
	goto L81;
    }
    pu /= span;
    ub = one;
    umb = sc[ispl + 2] * span;
    ua = ub - umb;
    uma = umb;
    goto L89;

L81:
    u = ua;
    up = zero;
    upp = zero;
    upsq = zero;
    goto L92;

L89:
    if (ibugg_1.ibug != 11) {
	goto L88;
    }
    bad_(&c__1, &c__1, "PU  ", &pu, (ftnlen)4);
    bad_(&c__1, &c__1, "SPAN", &span, (ftnlen)4);
    bad_(&c__1, &c__1, "UA  ", &ua, (ftnlen)4);
    bad_(&c__1, &c__1, "UB  ", &ub, (ftnlen)4);
    bad_(&c__1, &c__1, "UMA ", &uma, (ftnlen)4);
    bad_(&c_n1, &c__1, "UMB ", &umb, (ftnlen)4);
L88:
/* ---     COMPUTE EXACT CORRESPONDING VALUE U OF COONS PARAMETER */
    w1 = (ub - ua) * 3.f - uma - uma - umb;
    w2 = (ua - ub) * 2.f + uma + umb;
    u = ua + pu * (uma + pu * (w1 + pu * w2));
    up = uma + pu * (w1 + w1 + pu * 3.f * w2);
    upp = w1 + w1 + pu * 6.f * w2;
    up /= span;
    upp /= span * span;
    upsq = up * up;
L92:
    nn = (integer) (sc[5] + (iarc - 1) * 24);
    if (ibugg_1.ibug != 11) {
	goto L91;
    }
    bad_(&c__1, &c__1, "U   ", &u, (ftnlen)4);
    bad_(&c__1, &c__1, "UP  ", &up, (ftnlen)4);
    bad_(&c_n1, &c__1, "UPP ", &upp, (ftnlen)4);
L91:
    cncurv_(&u, &sc[nn], &cv[1], mode);
/*     DO 556 I=1,13,4 */
/*     CALL BAD(-4,1,'CNCV',CV(I)) */
/* 556 CONTINUE */
    if (*mode == 0) {
	goto L999;
    }
/* ---     CHANGE DERIVATIVES TO COMPENSATE FOR FLOW RATE. */
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__ + 8] = cv[i__ + 4] * upp + cv[i__ + 8] * upsq;
	cv[i__ + 4] *= up;
/* L90: */
    }
/* ---     WORK COMPLETED IF MODE.LT.2 */
    if (*mode < 2) {
	goto L999;
    }
/* ---     CHECK IF A CRSSPL IS AVAILABLE AT EACH END OF THE ARC */
    if ((d__1 = sc[nn - 5] - one, abs(d__1)) + (d__2 = sc[nn + 19] - one, abs(
	    d__2)) < smal) {
	goto L100;
    }
    if ((d__1 = sc[nn - 5] - one, abs(d__1)) < smal && abs(u) < smal) {
	goto L130;
    }
    if ((d__1 = sc[nn + 19] - one, abs(d__1)) < smal && (d__2 = one - u, abs(
	    d__2)) < smal) {
	goto L140;
    }

/* ---     NO CROSS SPLINES ARE THERE, SO ZERO OUT CV(17-32) */
    for (i__ = 17; i__ <= 32; ++i__) {
/* L101: */
	cv[i__] = zero;
    }
    goto L999;

/* ---     NOW INTERPOLATE A CROSS SPLINE VECTOR AND DERIVATIVES */
L100:
    w1 = (d__1 = sc[nn - 1] - 3.f, abs(d__1));
    w2 = (d__1 = sc[nn + 23] - 3.f, abs(d__1));
/* ---    SET UP CANON FORM FOR CRSSPL VECTOR AS A CUBIC ARC */
    for (i__ = 1; i__ <= 3; ++i__) {
	temp[(i__ << 2) - 4] = sc[nn - 9 + i__];
	temp[(i__ << 2) - 3] = sc[nn + 15 + i__];
	temp[(i__ << 2) - 2] = zero;
	if (w1 < smal) {
	    temp[(i__ << 2) - 2] = sc[nn - 5 + i__];
	}
	temp[(i__ << 2) - 1] = zero;
	if (w2 < smal) {
	    temp[(i__ << 2) - 1] = sc[nn + 19 + i__];
	}
/* L110: */
    }

    temp[12] = one;
    temp[13] = one;
    temp[14] = zero;
    temp[15] = zero;

    crblen_(&u, temp, &cv[17], &c__1);
/*     DO 557 I=17,32,4 */
/*     CALL BAD(-4,1,'CRBN',CV(I)) */
/* 557 CONTINUE */
    for (i__ = 1; i__ <= 3; ++i__) {
	cv[i__ + 24] = cv[i__ + 20] * upp + cv[i__ + 24] * upsq;
	cv[i__ + 20] *= up;
/* L120: */
    }
/* ---     FINALLY COMPUTE THE NORMAL (TAN CROSSED WITH CRS) */
L121:
    cross_(&cv[5], &cv[17], temp);
/* Computing 2nd power */
    d__1 = temp[0];
/* Computing 2nd power */
    d__2 = temp[1];
/* Computing 2nd power */
    d__3 = temp[2];
    w = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    w = sqrt(w);
    if (w < smal) {
	w = one;
    }
    cv[29] = temp[0] / w;
    cv[30] = temp[1] / w;
    cv[31] = temp[2] / w;
    cv[32] = one;
    goto L999;
/* ---     SIMPLE EXTRACTION OF AVAILABLE VECTORS FROM JUNCTION */
L130:
    for (l = 1; l <= 3; ++l) {
	cv[l + 16] = sc[nn - 9 + l];
	if ((d__1 = sc[nn - 1] - 3.f, abs(d__1)) < smal) {
	    cv[l + 20] = sc[nn - 5 + l];
	}
	cv[l + 24] = zero;
/* L131: */
    }
    cv[20] = one;
    cv[28] = zero;
    goto L121;

L140:
    for (l = 1; l <= 3; ++l) {
	cv[l + 16] = sc[nn + 15 + l];
	if ((d__1 = sc[nn + 23] - 3.f, abs(d__1)) < smal) {
	    cv[l + 20] = sc[nn + 19 + l];
	}
	cv[l + 24] = zero;
/* L141: */
    }
    cv[20] = one;
    cv[28] = zero;
    if ((d__1 = sc[nn + 23] - 3.f, abs(d__1)) < smal) {
	cv[24] = one;
    }
    goto L121;


L999:
    if (ibugg_1.ibug != 11) {
	goto L997;
    }
    bad_(&c_n4, &c__1, "CV1 ", &cv[1], (ftnlen)4);
    bad_(&c_n4, &c__1, "CV5 ", &cv[5], (ftnlen)4);
    bad_(&c_n4, &c__1, "CV9 ", &cv[9], (ftnlen)4);
    bad_(&c_n4, &c__1, "CV17", &cv[17], (ftnlen)4);
    bad_(&c_n4, &c__1, "CV21", &cv[21], (ftnlen)4);
L997:
    return 0;

L998:
    cform_(" WARNING ERROR IN CURFLO", darray_1.darray, &c__1, &c__24, (
	    ftnlen)24, (ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    bad_(&c__1, &c__1, "UIN ", uin, (ftnlen)4);
    bad_(&c__1, &c__0, "MERR", &merr, (ftnlen)4);
    bad_(&c__1, &c__0, "INSG", &inseg, (ftnlen)4);
    bad_(&c__1, &c__1, "U   ", &u, (ftnlen)4);
    bad_(&c__1, &c__1, "FRAC", &frac, (ftnlen)4);
    bad_(&c__1, &c__0, "SEG ", &iseg, (ftnlen)4);
    bad_(&c__1, &c__0, "IARC", &iarc, (ftnlen)4);
    bad_(&c__1, &c__0, "ISPL", &ispl, (ftnlen)4);
    bad_(&c_n1, &c__0, "LOCS", &locseg, (ftnlen)4);
    scdump_(&c__333, &sc[1]);
    goto L999;

L200:
/* ---     SPECIAL ENTRY FOR A DEGENERATE SEGMENT */
    locarc = (integer) sc[7];
    iarc = (integer) sc[locseg];
    if (iarc == 0) {
	goto L210;
    }

    --iarc;
    pu = one;
    goto L220;

L210:
    iarc = 1;
    pu = zero;

L220:
    nn = (integer) (sc[5] + (iarc - 1) * 24);
    cncurv_(&pu, &sc[nn], &cv[1], mode);
/* ---      ZERO OUT FIRST AND SECOND DERIVATIVES */
    for (j = 1; j <= 2; ++j) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    cv[i__ + (j << 2)] = zero;
/* L230: */
	}
    }
    goto L999;

/* ---      UIN AND INSEG REFER TO ARC STRUCTURE AND COONS NATURAL */
/* ---      FLOW PARAMETER DIRECTLY */
L300:
    u = *uin;
    nmax = (integer) sc[4];
    if (inseg < 0) {
	goto L310;
    } else if (inseg == 0) {
	goto L320;
    } else {
	goto L330;
    }

L310:
/* ---     CONVERT INSEG AND UIN TO CASE OF POSITIVE INSEG */
    inseg = nmax - abs(inseg) + 1;
    *uin = one - *uin;
    goto L330;

L320:
    iarc = (integer) (*uin + one);
    iarc = min(nmax,iarc);
    iarc = max(1,iarc);
    ulo = (doublereal) (iarc - 1);
    u = *uin - ulo;
    goto L340;

L330:
/* ****    SEGMENT REFERENCE IS OUT OF VALID RANGE */
    merr = 4;
    if (inseg < 1 || inseg > nmax) {
	goto L998;
    }

    iarc = inseg;
    u = *uin;

L340:
/* ---     COMPUTE ARC LOCATION IN SC ARRAY */
    nn = (integer) ((sc[2] - one + iarc) * 24 + 1);
    cncurv_(&u, &sc[nn], &cv[1], mode);
    if (*mode < 2) {
	goto L999;
    }

    if ((d__1 = sc[nn - 5] - one, abs(d__1)) + (d__2 = sc[nn + 19] - one, abs(
	    d__2)) < smal) {
	goto L345;
    }
    if ((d__1 = sc[nn - 5] - one, abs(d__1)) < smal && abs(u) < smal) {
	goto L130;
    }
    if ((d__1 = sc[nn + 19] - one, abs(d__1)) < smal && (d__2 = one - u, abs(
	    d__2)) < smal) {
	goto L140;
    }

L345:

    w1 = (d__1 = sc[nn - 1] - 3.f, abs(d__1));
    w2 = (d__1 = sc[nn + 23] - 3.f, abs(d__1));
/* ---    SET UP CANON FORM FOR CRSSPL VECTOR AS A CUBIC ARC */
    for (i__ = 1; i__ <= 3; ++i__) {
	temp[(i__ << 2) - 4] = sc[nn - 9 + i__];
	temp[(i__ << 2) - 3] = sc[nn + 15 + i__];
	temp[(i__ << 2) - 2] = zero;
	if (w1 < smal) {
	    temp[(i__ << 2) - 2] = sc[nn - 5 + i__];
	}
	temp[(i__ << 2) - 1] = zero;
	if (w2 < smal) {
	    temp[(i__ << 2) - 1] = sc[nn + 19 + i__];
	}
/* L350: */
    }

    temp[3] = one;
    temp[7] = one;
    temp[11] = zero;
    temp[15] = zero;

    crblen_(&u, temp, &cv[17], &c__1);
/* ---     FINALLY COMPUTE THE NORMAL (TAN CROSSED WITH CRS) */
    cross_(&cv[5], &cv[17], temp);
    vnorm_(temp, &cv[29]);
    cv[32] = one;
    goto L999;

} /* curflo_ */

