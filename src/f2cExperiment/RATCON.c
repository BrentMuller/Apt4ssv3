/* RATCON.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0004147.V02   *** */

/* Subroutine */ int ratcon_(doublereal *x1, doublereal *xm, doublereal *ym, 
	doublereal *xi, doublereal *yi, doublereal *cx)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer j;
    static doublereal s0, s1, w0, w1, det, ratio;

/* ---  THIS SUBROUTINE ACCEPTS AS INPUT COORDINATES OF THREE */
/* ---  POINTS IN THE X,Y-PLANE OF A LOCAL SYSTEM OF COORDINATES. */
/* ---  THE OUTPUT CX IS THE CANONICAL FORM IN THE SAME COORDINATE */
/* ---  SYSTEM OF A CONIC ARC WITH ENDPOINTS (0,0) AND (X1,0), */
/* ---  WHOSE END TANGENTS INTERSECT AT (XI,YI), AND WHICH ALSO */
/* ---  INTERPOLATES THE POINT (XM,YM). THE ARC IS PARAMETRISED SO */
/* ---  THAT THE MAGNITUDES OF ITS END TANGENTS ARE EQUAL. */
/* ---  REVISED AND CORRECTED, CRANFIELD 1981, M.J.P. */
    /* Parameter adjustments */
    --cx;

    /* Function Body */
/* Computing 2nd power */
    d__1 = *xi;
/* Computing 2nd power */
    d__2 = *yi;
/* Computing 2nd power */
    d__3 = *xi - *x1;
/* Computing 2nd power */
    d__4 = *yi;
    ratio = sqrt((d__1 * d__1 + d__2 * d__2) / (d__3 * d__3 + d__4 * d__4));
    det = *x1 * *ym;
    s0 = ((*xi - *xm) * *ym - (*xm - *x1) * (*yi - *ym)) * 2 / det;
    s1 = (*xm * (*yi - *ym) - (*xi - *xm) * *ym) * 2 / det;
    w0 = sqrt(s0 * s1 * ratio);
    w1 = w0 / ratio;
/* ---  IN THE STANDARD RATIONAL QUADRATIC FORMULA FOR A CONIC ARC */
/* ---  THE WEIGHT ASSOCIATED WITH THE TANGENT INTERSECTION POINT */
/* ---  HAS BEEN ARBITRARILY TAKEN AS 1.0. W0 AND W1 ARE THE WEIGHTS */
/* ---  ASSOCIATED WITH THE END POINTS.  WE NEXT SET UP THE CANONICAL */
/* ---  MATRIX FOR THE ARC, CONTAINING THE TWO PROJECTIVE END POINTS */
/* ---  AND END TANGENTS. */
    cx[1] = 0.f;
    cx[2] = w1 * *x1;
    cx[3] = *xi * 2;
    cx[4] = (cx[2] - *xi) * 2;
    cx[5] = 0.f;
    cx[6] = 0.f;
    cx[7] = *yi * 2;
    cx[8] = *yi * -2;
    for (j = 9; j <= 12; ++j) {
/* L10: */
	cx[j] = 0.;
    }
/* ---  ALL Z-COORDINATES ARE ZERO IN LOCAL COORDINATE SYSTEM */
    cx[13] = w0;
    cx[14] = w1;
    cx[15] = (1 - w0) * 2;
    cx[16] = (w1 - 1) * 2;
    return 0;
} /* ratcon_ */

