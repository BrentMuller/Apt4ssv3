/* PARMPT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000648.V01   *** */

/* Subroutine */ int parmpt_(doublereal *pa, doublereal *pd, doublereal *pb, 
	doublereal *b, doublereal *pc, doublereal *c__, doublereal *ta, 
	doublereal *td, integer *irr)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal a1, a2, b1, b2, c1, c2, df[3], bsq, csq, disc;
    static integer idiag;

/* ------ A COMPLETELY MODULAR SCULPTURED SURFACE ROUTINE  APRIL 1970 JKH */
/* ------ INPUT CONSISTS OF TWO END POINTS PA,PD AND TWO INTERIOR POINTS */
/* ------PB WITH PARAMETER VALUE B AND PC WITH PARAMETER VALUE C THRU */
/* ------WHICH A CUBIC CURVE MUST PASS. */
/* ------OUTPUT CONSISTS OF TWO COONS TANGENT VECTORS TA AND TD WHICH */
/* -------DEFINE THE DESIRED CURVE.  A CASE OF TROUBLE IS THAT THE */
/* ------PARAMETER VALUES B AND C ARE NEARLY EQUAL */
    /* Parameter adjustments */
    --td;
    --ta;
    --pc;
    --pb;
    --pd;
    --pa;

    /* Function Body */
    idiag = 23000;
    bsq = *b * *b;
    csq = *c__ * *c__;
    disc = *b * *c__ * (*b - 1) * (*c__ - 1) * (*b - *c__);
    *irr = idiag + 1;
    if (abs(disc) < 1e-12) {
	return 0;
    }
/* ------SET UP THE LINEAR EQUATION A * TA() + B * TB() = C() */
/* Computing 2nd power */
    d__1 = 1 - *b;
    a1 = *b * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = 1 - *c__;
    a2 = *c__ * (d__1 * d__1);
    b1 = bsq * (*b - 1);
    b2 = csq * (*c__ - 1);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	df[i__ - 1] = pd[i__] - pa[i__];
    }
/* ------DETERMINE EACH COMPONENT OF TA() AND TD() BY SOLVING TWO EQUNS */
/* ------IN TWO UNKNOWNS */
    for (i__ = 1; i__ <= 3; ++i__) {
	c1 = pb[i__] - (pa[i__] + df[i__ - 1] * bsq * (3 - *b * 2));
	c2 = pc[i__] - (pa[i__] + df[i__ - 1] * csq * (3 - *c__ * 2));
	ta[i__] = (c1 * b2 - c2 * b1) / disc;
	td[i__] = (a1 * c2 - a2 * c1) / disc;
/* L10: */
    }
    *irr = 0;
    return 0;
} /* parmpt_ */

