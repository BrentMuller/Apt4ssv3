/* GCONE.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000907.V01   *** */

/* ...  FORTRAN SUBROUTINE GCONE                   7/70      RW */

/*        CANONICAL FORM OF CONE */
/*        1. X-COORDINATE OF VERTEX                (XO) */
/*        2. Y-COORDINATE OF VERTEX                (YO) */
/*        3. Z-COORDINATE OF VERTEX                (ZO) */
/*        4. X-COMPONENT OF NORMALIZED AXIS VECTOR (A) */
/*        5. Y-COMPONENT OF NORMALIZED AXIS VECTOR (B) */
/*        6. Z-COMPONENT OF NORMALIZED AXIS VECTOR (C) */
/*        7. COSINE OF VERTEX HALF-ANGLE           (V) */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Subroutine */ int gcone_(doublereal *canon, doublereal *quadbf)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11, d__12, d__13, d__14, d__15, d__16, d__17, d__18;

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j;
    static doublereal v, di, fr;
    static integer it;
    static doublereal xo, yo, zo;


/*        INITIALIZATION */

    /* Parameter adjustments */
    --quadbf;
    --canon;

    /* Function Body */
    xo = canon[1];
    yo = canon[2];
    zo = canon[3];
    a = canon[4];
    b = canon[5];
    c__ = canon[6];
    v = canon[7];
/* Computing 2nd power */
    d__1 = c__;
    di = 1.f - d__1 * d__1;
/* Computing 2nd power */
    d__1 = v;
/* Computing 2nd power */
    d__2 = v;
    fr = d__1 * d__1 / (1.f - d__2 * d__2);

/*     CHECK FOR DEFAULT CASE */

    if (a != b) {
	goto L10;
    }
    if (a != 0.) {
	goto L10;
    }

    for (j = 1; j <= 2; ++j) {
/* L2: */
	quadbf[j] = fr;
    }

    quadbf[3] = -1.f;

    for (j = 4; j <= 6; ++j) {
/* L3: */
	quadbf[j] = 0.f;
    }

    quadbf[7] = xo * -2.f * fr;
    quadbf[8] = yo * -2.f * fr;
    quadbf[9] = zo * 2.f;
/* Computing 2nd power */
    d__1 = xo;
/* Computing 2nd power */
    d__2 = yo;
/* Computing 2nd power */
    d__3 = zo;
    quadbf[10] = fr * (d__1 * d__1) + fr * (d__2 * d__2) - d__3 * d__3;

    goto L100;

/*     ALL OTHER CASES */

L10:
/* Computing 2nd power */
    d__1 = c__;
/* Computing 2nd power */
    d__2 = a;
/* Computing 2nd power */
    d__3 = b;
/* Computing 2nd power */
    d__4 = a;
    quadbf[1] = fr * ((d__1 * d__1 * (d__2 * d__2) + d__3 * d__3) / di) - 
	    d__4 * d__4;
/* Computing 2nd power */
    d__1 = c__;
/* Computing 2nd power */
    d__2 = b;
/* Computing 2nd power */
    d__3 = a;
/* Computing 2nd power */
    d__4 = b;
    quadbf[2] = fr * ((d__1 * d__1 * (d__2 * d__2) + d__3 * d__3) / di) - 
	    d__4 * d__4;
/* Computing 2nd power */
    d__1 = c__;
    quadbf[3] = fr * di - d__1 * d__1;
    quadbf[4] = (b * c__ * fr + b * c__) * -2.f;
    quadbf[5] = (a * c__ * fr + a * c__) * -2.f;
/* Computing 2nd power */
    d__1 = c__;
    quadbf[6] = (fr * ((a * b * (d__1 * d__1) - a * b) / di) - a * b) * 2.f;
/* Computing 2nd power */
    d__1 = a;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = c__;
/* Computing 2nd power */
    d__4 = b;
/* Computing 2nd power */
    d__5 = a;
    quadbf[7] = (fr * ((-xo * (d__1 * d__1) * (d__2 * d__2) - yo * a * b * (
	    d__3 * d__3) - xo * (d__4 * d__4) + yo * a * b) / di + zo * a * 
	    c__) + xo * (d__5 * d__5) + yo * a * b + zo * a * c__) * 2.f;
/* Computing 2nd power */
    d__1 = b;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = c__;
/* Computing 2nd power */
    d__4 = a;
/* Computing 2nd power */
    d__5 = b;
    quadbf[8] = (fr * ((-yo * (d__1 * d__1) * (d__2 * d__2) - xo * a * b * (
	    d__3 * d__3) - yo * (d__4 * d__4) + xo * a * b) / di + zo * b * 
	    c__) + yo * (d__5 * d__5) + xo * a * b + zo * b * c__) * 2.f;
/* Computing 2nd power */
    d__1 = c__;
    quadbf[9] = (fr * (-di * zo + xo * a * c__ + yo * b * c__) + zo * (d__1 * 
	    d__1) + xo * a * c__ + yo * b * c__) * 2.f;
/* Computing 2nd power */
    d__1 = xo;
/* Computing 2nd power */
    d__2 = a;
/* Computing 2nd power */
    d__3 = c__;
/* Computing 2nd power */
    d__4 = yo;
/* Computing 2nd power */
    d__5 = b;
/* Computing 2nd power */
    d__6 = c__;
/* Computing 2nd power */
    d__7 = c__;
/* Computing 2nd power */
    d__8 = xo;
/* Computing 2nd power */
    d__9 = b;
/* Computing 2nd power */
    d__10 = yo;
/* Computing 2nd power */
    d__11 = a;
/* Computing 2nd power */
    d__12 = zo;
/* Computing 2nd power */
    d__13 = xo;
/* Computing 2nd power */
    d__14 = a;
/* Computing 2nd power */
    d__15 = yo;
/* Computing 2nd power */
    d__16 = b;
/* Computing 2nd power */
    d__17 = zo;
/* Computing 2nd power */
    d__18 = c__;
    quadbf[10] = fr * ((d__1 * d__1 * (d__2 * d__2) * (d__3 * d__3) + d__4 * 
	    d__4 * (d__5 * d__5) * (d__6 * d__6) + xo * 2.f * yo * a * b * (
	    d__7 * d__7) + d__8 * d__8 * (d__9 * d__9) + d__10 * d__10 * (
	    d__11 * d__11) - xo * 2.f * yo * a * b) / di + di * (d__12 * 
	    d__12) - xo * 2.f * zo * a * c__ - yo * 2.f * zo * b * c__) - 
	    d__13 * d__13 * (d__14 * d__14) - d__15 * d__15 * (d__16 * d__16) 
	    - d__17 * d__17 * (d__18 * d__18) - xo * 2.f * yo * a * b - xo * 
	    2.f * zo * a * c__ - yo * 2.f * zo * b * c__;

/*     ONLY ONE OF THE THREE SQUARED-TERM COEFFICIENTS SHOULD BE NEGATIVE */
/*     IF TWO ARE NEGATIVE, MULTIPLY THE EQUATION BY MINUS ONE. */

    it = 0;
    if (quadbf[1] < 0.f) {
	++it;
    }
    if (quadbf[2] < 0.f) {
	++it;
    }
    if (quadbf[3] < 0.f) {
	++it;
    }
    if (it <= 1) {
	goto L100;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
/* L60: */
	quadbf[i__] = -quadbf[i__];
    }
L100:
    return 0;
} /* gcone_ */

