/* GCYL.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : M0000909.V01   *** */

/* ...  FORTRAN SUBROUTINE GCYL                    6/70      RW */

/*        CANONICAL FORM OF CYLINDER */
/*        1. X-COORDINATE OF POINT ON AXIS         (XO) */
/*        2. Y-COORDINATE OF POINT ON AXIS         (YO) */
/*        3. Z-COORDINATE OF POINT ON AXIS         (ZO) */
/*        4. X-COMPONENT OF NORMALIZED AXIS VECTOR (A) */
/*        5. Y-COMPONENT OF NORMALIZED AXIS VECTOR (B) */
/*        6. Z-COMPONENT OF NORMALIZED AXIS VECTOR (C) */
/*        7. RADIUS OF CYLINDER                    (R) */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* Subroutine */ int gcyl_(doublereal *canon, doublereal *quadbf)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11, d__12, d__13;

    /* Local variables */
    static doublereal a, b, c__;
    static integer j;
    static doublereal r__, di, xo, yo, zo;


/*        INITALIZATION */

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
    r__ = canon[7];
/* Computing 2nd power */
    d__1 = c__;
    di = 1.f - d__1 * d__1;


/*       DEFAULT CASE */

    if (a != b) {
	goto L10;
    }
    if (a != 0.) {
	goto L10;
    }

    for (j = 1; j <= 2; ++j) {
/* L2: */
	quadbf[j] = 1.f;
    }

    for (j = 3; j <= 6; ++j) {
/* L3: */
	quadbf[j] = 0.f;
    }

    quadbf[7] = xo * -2.f;
    quadbf[8] = yo * -2.f;
    quadbf[9] = 0.f;
/* Computing 2nd power */
    d__1 = xo;
/* Computing 2nd power */
    d__2 = yo;
/* Computing 2nd power */
    d__3 = r__;
    quadbf[10] = d__1 * d__1 + d__2 * d__2 - d__3 * d__3;

    goto L50;



L10:
/* Computing 2nd power */
    d__1 = a;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = b;
    quadbf[1] = (d__1 * d__1 * (d__2 * d__2) + d__3 * d__3) / di;

/* Computing 2nd power */
    d__1 = b;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = a;
    quadbf[2] = (d__1 * d__1 * (d__2 * d__2) + d__3 * d__3) / di;

    quadbf[3] = di;

    quadbf[4] = b * -2.f * c__;

    quadbf[5] = a * -2.f * c__;

/* Computing 2nd power */
    d__1 = c__;
    quadbf[6] = (a * b * (d__1 * d__1) - a * b) / di * 2.f;

/* Computing 2nd power */
    d__1 = a;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = c__;
/* Computing 2nd power */
    d__4 = b;
    quadbf[7] = ((-xo * (d__1 * d__1) * (d__2 * d__2) - yo * a * b * (d__3 * 
	    d__3) - xo * (d__4 * d__4) + yo * a * b) / di + zo * a * c__) * 
	    2.f;

/* Computing 2nd power */
    d__1 = b;
/* Computing 2nd power */
    d__2 = c__;
/* Computing 2nd power */
    d__3 = c__;
/* Computing 2nd power */
    d__4 = a;
    quadbf[8] = ((-yo * (d__1 * d__1) * (d__2 * d__2) - xo * a * b * (d__3 * 
	    d__3) + xo * a * b - yo * (d__4 * d__4)) / di + zo * b * c__) * 
	    2.f;

    quadbf[9] = (-zo * di + a * c__ * xo + yo * b * c__) * 2.f;

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
    d__13 = r__;
    quadbf[10] = (d__1 * d__1 * (d__2 * d__2) * (d__3 * d__3) + d__4 * d__4 * 
	    (d__5 * d__5) * (d__6 * d__6) + xo * 2.f * yo * a * b * (d__7 * 
	    d__7) + d__8 * d__8 * (d__9 * d__9) - xo * 2.f * yo * a * b + 
	    d__10 * d__10 * (d__11 * d__11)) / di + d__12 * d__12 * di - xo * 
	    2.f * zo * a * c__ - yo * 2.f * zo * b * c__ - d__13 * d__13;

L50:
/*       RETURN TO CALLING PROGRAM */
    return 0;
} /* gcyl_ */

