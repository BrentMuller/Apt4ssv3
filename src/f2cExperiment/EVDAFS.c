/* EVDAFS.f -- translated by f2c (version 20100827).
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

static integer c__9 = 9;
static integer c__1 = 1;

/* *** SOURCE FILE : EVDAFS.ORG   *** */

/* Subroutine */ int evdafs_(doublereal *u, doublereal *v, doublereal *geo, 
	doublereal *result, integer *mode)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer n;
    static doublereal cu[25], ax[625], ay[625], az[625], cv[25];
    static integer mu, mv;
    extern /* Subroutine */ int cvdafs_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *);

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, 0, 0 };


/* THIS SUBROUTINE EVALUATES POINT COORDINATES AND DERIVATIVES ON */
/* A PATCH OF A VDAFS DEFINED SURFACE. SUBROUTINE BIPROD IS CALLED */
/* FOR BASIC BILINEAR MATRIX PRODUCT EVALUATION. */
/* SUBROUTINE CVDAFS ORGANISES ENTIRE COMPUTATION EVDAFS CHECKS INPUT DAT */
    /* Parameter adjustments */
    result -= 5;
    --geo;

    /* Function Body */
    mu = (integer) geo[1];
    mv = (integer) geo[2];
    n = mu * mv;
    if (mu > 25 || mv > 25) {
	s_wsle(&io___4);
	do_lio(&c__9, &c__1, " DEGREE U OR DEGREE V TOO LARGE FOR ARRAY DIME"
		"NSIONS", (ftnlen)52);
	e_wsle();
	return 0;
    }
    cvdafs_(u, v, &geo[1], &result[5], mode, &mu, &mv, &n, ax, ay, az, cu, cv)
	    ;
    return 0;
} /* evdafs_ */

/* Subroutine */ int cvdafs_(doublereal *u, doublereal *v, doublereal *geo, 
	doublereal *result, integer *mode, integer *mu, integer *mv, integer *
	n, doublereal *ax, doublereal *ay, doublereal *az, doublereal *cu, 
	doublereal *cv)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal x, y, z__, res[3];
    extern /* Subroutine */ int biprod_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);

/* THIS SUBROUTINE PERFORMS ALL BASIC EVALUATION COMPUTATIONS ON VDA SURF */
/* MU=DEGREE+1 IN U, MV=DEGREE+1 IN V FOR THIS PATCH, COEFF MAT IS MU*MV. */
/*     N=MU*MV */
/* SET UP COEFFICIENT MATRICES. */
    /* Parameter adjustments */
    --geo;
    result -= 5;
    --cu;
    --cv;
    --az;
    --ay;
    --ax;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ax[i__] = geo[i__ + 2];
	ay[i__] = geo[i__ + 2 + *n];
/* L10: */
	az[i__] = geo[i__ + 2 + (*n << 1)];
    }
/* INITIALISE RESULT ARRAY USED TO RETURN POINT ADD DERIVATIVE DATA. */
    for (i__ = 1; i__ <= 4; ++i__) {
	for (j = 1; j <= 8; ++j) {
/* L15: */
	    result[i__ + (j << 2)] = 0.f;
	}
    }
    i__1 = *mu;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	cu[i__] = 1.f;
    }
    i__1 = *mv;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	cv[i__] = 1.f;
    }
/* EVALUATE POINT COORDINATES */
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, &x);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &y);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &z__);
    result[5] = x;
    result[6] = y;
    result[7] = z__;
    result[8] = 1.f;
    if (*mode == 0) {
	return 0;
    }
/* MODE=0 INDICATES THAT ONLY POINT COORDINATES ARE REQUIRED. */
/* EVALUATE FIRST DERIVATIVES, STORE IN COLS 2 AND 3 OF RESULT. */
    i__1 = *mu;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L40: */
	cu[i__] = i__ - 1.f;
    }
    cu[1] = 0.f;
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, res);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &res[1]);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &res[2]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L50: */
	result[i__ + 8] = res[i__ - 1];
    }
    i__1 = *mu;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	cu[i__] = 1.f;
    }
    i__1 = *mv;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L70: */
	cv[i__] = i__ - 1.f;
    }
    cv[1] = 0.f;
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, res);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &res[1]);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &res[2]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L80: */
	result[i__ + 12] = res[i__ - 1];
    }
/* EVALUATE MIXED DERIVATIVE (TWIST VECTOR), COL 5 OF RESULT. */
    i__1 = *mu;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L90: */
	cu[i__] = i__ - 1.f;
    }
    cu[1] = 0.f;
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, res);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &res[1]);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &res[2]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L95: */
	result[i__ + 20] = res[i__ - 1];
    }
    if (*mu <= 2) {
	goto L135;
    }
/* 2ND DERIVATIVE ZERO IF U DEGREE=1 */
/* EVALUATE 2ND DERIVATIVES, STORE IN COLS 4,6 OF RESULT. */
    i__1 = *mu;
    for (i__ = 3; i__ <= i__1; ++i__) {
/* L110: */
	cu[i__] *= i__ - 2.f;
    }
    cu[2] = 0.f;
    i__1 = *mv;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L120: */
	cv[i__] = 1.f;
    }
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, res);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &res[1]);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &res[2]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L130: */
	result[i__ + 16] = res[i__ - 1];
    }
L135:
    if (*mv <= 2) {
	goto L165;
    }
    i__1 = *mu;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L140: */
	cu[i__] = 1.f;
    }
    i__1 = *mv;
    for (i__ = 3; i__ <= i__1; ++i__) {
/* L150: */
	cv[i__] = (i__ - 1.f) * (i__ - 2.f);
    }
    cv[2] = 0.f;
    cv[1] = 0.f;
    biprod_(&ax[1], mu, mv, &cu[1], &cv[1], u, v, res);
    biprod_(&ay[1], mu, mv, &cu[1], &cv[1], u, v, &res[1]);
    biprod_(&az[1], mu, mv, &cu[1], &cv[1], u, v, &res[2]);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L160: */
	result[i__ + 24] = res[i__ - 1];
    }
L165:
/* COMPUTE NORMAL AND UNIT NORMAL, STORE IN COLS 7,8 OF RESULT. */
    result[29] = result[10] * result[15] - result[11] * result[14];
    result[30] = result[11] * result[13] - result[9] * result[15];
    result[31] = result[9] * result[14] - result[10] * result[13];
    x = 0.f;
    for (i__ = 1; i__ <= 3; ++i__) {
/* L170: */
	x += result[i__ + 28] * result[i__ + 28];
    }
    x = sqrt(x);
    if (x < 1e-8f) {
	return 0;
    }
/* NORMAL VECTOR IS NOT WELL DEFINED IF X(VECTOR LENGTH) SMALL. */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L180: */
	result[i__ + 32] = result[i__ + 28] / x;
    }
    result[36] = 1.f;
/* RESULT(4,8)=1 INDICATES A WELL DEFINED UNIT NORMAL IN COL 8. */
    return 0;
} /* cvdafs_ */

/* Subroutine */ int biprod_(doublereal *a, integer *mu, integer *mv, 
	doublereal *cu, doublereal *cv, doublereal *u, doublereal *v, 
	doublereal *res)
{
    /* System generated locals */
    integer a_dim1, a_offset;

    /* Local variables */
    static integer i__, j;
    static doublereal sum;

/* SUBROUTINE TO EVALUATE BILINEAR PRODUCT (PU)'A(PV), WHERE PU, PV ARE */
/* POWER SERIES WITH COEFFICIENTS CU,CV; LEADIONG 0.0 COEFFICIENTS INDICA */
/* DERIVATIVE TERMS OF LOWER DEGREE. FINAL (SCALAR) PRODUCT IS RETURNED A */
    /* Parameter adjustments */
    --cu;
    --cv;
    a_dim1 = *mu;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    *res = 0.f;
    for (i__ = *mu; i__ >= 1; --i__) {
	if (cu[i__] <= 0.f) {
	    goto L30;
	}
	sum = 0.f;
	for (j = *mv; j >= 1; --j) {
	    if (cv[j] <= 0.f) {
		goto L15;
	    }
/* L10: */
	    sum = sum * *v + cv[j] * a[i__ + j * a_dim1];
	}
L15:
/* L20: */
	*res = *res * *u + sum * cu[i__];
    }
L30:
/* RES NOW CONTAINS THE EVALUATED PRODUCT (PU)'A(PV) AT PARAMETRIC POINT */
/* THIS WILL CORRESPOND TO A POINT COORDINATE OR A DERIVATIVE VECTOR COMP */
    return 0;
} /* biprod_ */

