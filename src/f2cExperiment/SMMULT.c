/* SMMULT.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000658.V02   *** */

/* Subroutine */ int smmult_(integer *l, integer *m, integer *n, integer *ks, 
	doublereal *a, doublereal *b, doublereal *c__)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static doublereal d__[16];
    static integer k, ka, jc, kb, kk, ir, kloc, msize;

/* --- SCULPTURED SURFACE ROUTINE FOR MATRIX MULTIPLY */
/* ---  A IS AN INPUT MATRIX L ROWS BY M COLUMNS */
/* --- B IS AN INPUT MATRIX M ROWS X N COLUMNS */
/* --- KS DETERMINES WHERE THE OUTPUT IS LOADED */
/* --- KS =1 A  KS=2 B  KS=3 C */
/* --- NO INPUT MATRIX IS ALTERED UNLESS REQUESTED */
    /* Parameter adjustments */
    --c__;
    --b;
    --a;

    /* Function Body */
    i__1 = *n;
    for (jc = 1; jc <= i__1; ++jc) {
	i__2 = *l;
	for (ir = 1; ir <= i__2; ++ir) {
	    kloc = ir + (jc - 1) * *l;
	    d__[kloc - 1] = 0.f;
	    i__3 = *m;
	    for (kk = 1; kk <= i__3; ++kk) {
		ka = ir + (kk - 1) * *l;
		kb = kk + (jc - 1) * *m;
		d__[kloc - 1] += a[ka] * b[kb];
/* L20: */
	    }
/* L10: */
	}
    }
    msize = *l * *n;
    switch (*ks) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
    }
L100:
    i__2 = msize;
    for (k = 1; k <= i__2; ++k) {
/* L110: */
	a[k] = d__[k - 1];
    }
    goto L999;
L200:
    i__2 = msize;
    for (k = 1; k <= i__2; ++k) {
/* L210: */
	b[k] = d__[k - 1];
    }
    goto L999;
L300:
    i__2 = msize;
    for (k = 1; k <= i__2; ++k) {
/* L310: */
	c__[k] = d__[k - 1];
    }
L999:
    return 0;
} /* smmult_ */

