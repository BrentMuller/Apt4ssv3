/* CRVLEN.f -- translated by f2c (version 20100827).
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

static integer c_n6 = -6;
static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0004287.V03   *** */

/* Subroutine */ int crvlen_(doublereal *pa, doublereal *pb, doublereal *ta, 
	doublereal *tb, doublereal *a, doublereal *b, integer *numint, 
	integer *mxct, doublereal *ctolr, integer *ilevel)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal smal = 1e-15;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal h__;
    static integer i__, j;
    static doublereal u, w, a1, b1, h3, x1, x2, x3, da, db;
    extern /* Subroutine */ int bad_();
    static doublereal dif[3], det;
    static integer ict;
    static doublereal sum[6], area[6];
    extern /* Subroutine */ int ader_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, integer *, doublereal 
	    *);
    static integer iend, mode;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal temp, asave, bsave, ratio;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    static doublereal simfac;
    extern /* Subroutine */ int cprint_(char *, ftnlen);
    static integer istart;

/* ---MAIN ROUTINE TO DETERMINE OPTIMUM VECTOR LENGTHS FOR TANGENT */
/* ---VECTORS OF A CUBIC.  INPUT CONSTRAINTS INCLUDE */
/* --- PA,PB  START AND END POINTS OF PARAMETRIC CUBIC */
/* --- TA,TB  START AND END UNIT TANGENT VECTORS */
/* --- NUMINT IS NUMBER OF SIMPSON INTERVALS FOR DETERMINING AREA */
/* --- MXCT IS THE MAXIMUM NUMBER OF NEWTON-RHAPSON ITERATIONS */
/* --- CTOLR IS THE RATIO OF CHANGE FOR TERMINATION OF ITERATIONS */
/* --- ILEVEL CONTROLS THE LEVEL OF CALCULATION FOR A,B */
/* --- =1 CHORD LENGTH, =2 MINIMIZE DDR, =3 NEWTON RHAPSON */
/* --- A,B ARE THE OUTPUT LENGTHS OF TANGENTS. */
/* --- A,B ARE SELECTED TO MINIMZE INTEGRAL OF K*K*DS OVER 0,1 */
/* --- METHOD IS NEWTON-RHAPSON WITH ITERATIONS AND */
/* --- SIMPSONS RULE TO DETERMINE APPROXIMATE AREA */

    /* Parameter adjustments */
    --tb;
    --ta;
    --pb;
    --pa;

    /* Function Body */

    for (i__ = 1; i__ <= 3; ++i__) {
/* L5: */
	dif[i__ - 1] = pb[i__] - pa[i__];
    }
    vnorm_(&ta[1], &ta[1]);
    vnorm_(&tb[1], &tb[1]);
    istart = 1;
    iend = (*numint << 1) + 1;
    h__ = 1.f / (*numint * 2.f);
    h3 = h__ / 3.f;
    w = h__ + h__;

/* ---      INITIAL ESTIMATE OF A,B IS FROM CHORD LENGTH */
    dotf_(a, dif, dif);
    *a = sqrt(*a);
    *b = *a;
    if (*ilevel <= 1) {
	goto L70;
    }
/* ---      A SECOND INITIAL ESTIMATE IS FROM MINIMIZE DDR AT ENDS */
    dotf_(&x1, &ta[1], dif);
    dotf_(&x2, &tb[1], dif);
    dotf_(&x3, &ta[1], &tb[1]);
/* Computing 2nd power */
    d__1 = x3;
    temp = 3.f / (4.f - d__1 * d__1);
    a1 = (x1 * 2.f - x3 * x2) * temp;
    b1 = (x2 * 2.f - x3 * x1) * temp;
/* ---      IF A1 OR B1 IS NEGATIVE, IGNORE THESE VALUES */
    if (a1 < smal || b1 < smal) {
	goto L7;
    }
    *a = a1;
    *b = b1;
L7:
/* ---      NOW SAVE THESE A,B ESTIMATES AS A BACKUP */
    asave = *a;
    bsave = *b;

    if (*ilevel <= 2) {
	goto L70;
    }
    ict = 0;

L10:
/* ---      ICT IS THE COUNT OF THE NUMBER OF NEWTON RHAPSON ITERATIONS */
    if (ict > *mxct) {
	goto L70;
    }
    for (i__ = 1; i__ <= 6; ++i__) {
/* L20: */
	area[i__ - 1] = zero;
    }

/* ---      PERFORM INTEGRATION TO OBTAIN ESTIMATES OF TENSION AND DERIVS. */
    i__1 = iend;
    for (i__ = istart; i__ <= i__1; ++i__) {
	simfac = 4.f;
	if (i__ % 2 == 1) {
	    simfac = 2.f;
	}
	if (i__ == istart || i__ == iend) {
	    simfac = 1.f;
	}
	simfac *= h3;
	mode = 0;
	if (i__ == istart) {
	    mode = 1;
	}
	u = (i__ - 1.f) * h__;

	ader_(dif, &ta[1], &tb[1], a, b, &u, &mode, sum);

	if (ibugg_1.ibug == 11) {
	    bad_(&c_n6, &c__1, "SUM ", sum, (ftnlen)4);
	}
	for (j = 1; j <= 6; ++j) {
/* L40: */
	    area[j - 1] = simfac * sum[j - 1] + area[j - 1];
	}

/* L30: */
    }

    if (ibugg_1.ibug == 11) {
	bad_(&c_n6, &c__1, "AREA", area, (ftnlen)4);
    }

/* ---      ESTIMATE CHANGE DA,DB IN A,B TO REDUCE TENSION IN CURVE */
/* Computing 2nd power */
    d__1 = area[4];
    det = area[3] * area[5] - d__1 * d__1;
    if (abs(det) > smal) {
	goto L50;
    }
/* ---      USE THE PREVIOUS VALUES FOR A,B */
    *a = asave;
    *b = bsave;
    goto L70;

L50:

    da = (-area[1] * area[5] + area[2] * area[4]) / det;
    db = (-area[3] * area[2] + area[4] * area[1]) / det;

/* Computing 2nd power */
    d__1 = da;
/* Computing 2nd power */
    d__2 = db;
/* Computing 2nd power */
    d__3 = *a;
/* Computing 2nd power */
    d__4 = *b;
    ratio = sqrt(d__1 * d__1 + d__2 * d__2) / sqrt(d__3 * d__3 + d__4 * d__4);
    if (ibugg_1.ibug != 11) {
	goto L93;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " ENTRY TO CRVLEN", (ftnlen)20, (ftnlen)16);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "A   ", a, (ftnlen)4);
    bad_(&c__1, &c__1, "B   ", b, (ftnlen)4);
    bad_(&c__1, &c__1, "DA  ", &da, (ftnlen)4);
    bad_(&c__1, &c__1, "DB  ", &db, (ftnlen)4);
    bad_(&c_n1, &c__1, "RATI", &ratio, (ftnlen)4);
L93:
    *a += da;
    *b += db;
    if (ratio < *ctolr) {
	goto L70;
    }

    ++ict;
    goto L10;

L70:
/* ---      A NEGATIVE A OR B IS NOT ACCEPTABLE SO USE THE BACKUP */
/* ---      VALUES IF A OR B ARE NEGATIVE */
    if (*a > zero && *b > zero) {
	goto L999;
    }
    *a = asave;
    *b = bsave;
L999:
    if (ibugg_1.ibug != 11) {
	goto L998;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " EXIT FROM CRVLEN", (ftnlen)20, (ftnlen)17);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "A   ", a, (ftnlen)4);
    bad_(&c__1, &c__1, "B   ", b, (ftnlen)4);
    bad_(&c__1, &c__1, "ASAV", &asave, (ftnlen)4);
    bad_(&c_n1, &c__1, "BSAV", &bsave, (ftnlen)4);
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
L998:

    return 0;
} /* crvlen_ */

