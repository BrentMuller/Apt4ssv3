/* CRBLEN.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__0 = 0;
static integer c__16 = 16;

/* *** SOURCE FILE : M0000620.V04   *** */

/* Subroutine */ int crblen_(doublereal *u, doublereal *sc, doublereal *cv, 
	integer *mode)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal zero = 0.;
    static doublereal smal = 1e-15;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b;
    static integer i__, k;
    static doublereal w, pa[3], pb[3], ta[3], tb[3], fu[12], wp, wpp, temp1, 
	    temp2;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), blendf_(doublereal *, doublereal *), cprint_(
	    char *, ftnlen);

/* ---     CALLING ARGUMENTS ARE ANALAGOUS TO THOSE OF CNCURV */
/* ---     HOWEVER , THE BLEND FORMULA IS DESIGNED TO PRSERVE */
/* ---     DIRECTIONALITY OF POINTS AS A FUNCTION OF THE NATURAL */
/* ---     FLOW PARAMETER */

/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */



    /* Parameter adjustments */
    --cv;
    --sc;

    /* Function Body */

    blendf_(u, fu);
    a = sc[1] * sc[1] + sc[5] * sc[5] + sc[9] * sc[9];
    b = sc[2] * sc[2] + sc[6] * sc[6] + sc[10] * sc[10];
    a = sqrt(a) + smal;
    b = sqrt(b) + smal;

    k = 0;
    for (i__ = 1; i__ <= 9; i__ += 4) {
	++k;
	pa[k - 1] = sc[i__] / a;
	pb[k - 1] = sc[i__ + 1] / b;
	ta[k - 1] = sc[i__ + 2] / a;
	tb[k - 1] = sc[i__ + 3] / b;
/* L10: */
    }

    w = fu[0] * a + fu[1] * b;
    wp = fu[4] * a + fu[5] * b;
    wpp = fu[8] * a + fu[9] * b;

    for (i__ = 1; i__ <= 3; ++i__) {
	temp1 = fu[0] * pa[i__ - 1] + fu[1] * pb[i__ - 1] + fu[2] * ta[i__ - 
		1] + fu[3] * tb[i__ - 1];
	cv[i__] = w * temp1;
	if (*mode < 1) {
	    goto L20;
	}
	temp2 = fu[4] * pa[i__ - 1] + fu[5] * pb[i__ - 1] + fu[6] * ta[i__ - 
		1] + fu[7] * tb[i__ - 1];
	cv[i__ + 4] = temp1 * wp + temp2 * w;
	cv[i__ + 8] = wpp * temp1 + temp2 * 2.f * wp + w * (fu[8] * pa[i__ - 
		1] + fu[9] * pb[i__ - 1] + fu[10] * ta[i__ - 1] + fu[11] * tb[
		i__ - 1]);
L20:
	;
    }
    cv[4] = one;
    cv[8] = zero;
    cv[12] = zero;
    cv[16] = zero;
    if (*mode < 1) {
	goto L999;
    }
    cv[8] = one;
    cv[12] = one;
    goto L999;

/* L998: */
    cform_(" ERROR IN CRBLEN", darray_1.darray, &c__0, &c__16, (ftnlen)16, (
	    ftnlen)120);
    cprint_(darray_1.darray, (ftnlen)120);
    goto L999;

L999:
    return 0;
} /* crblen_ */

