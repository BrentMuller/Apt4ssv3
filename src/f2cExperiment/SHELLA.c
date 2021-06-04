/* SHELLA.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : SHELLA.ORG   *** */

/* Subroutine */ int shella_(doublereal *p, doublereal *phull, integer *np, 
	integer *n3, doublereal *c__, doublereal *r__)
{
    /* System generated locals */
    integer phull_dim1, phull_offset, i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, h__[9]	/* was [3][3] */;
    static integer i__, j, k, l;
    static doublereal a1, a2, r2, v1[3], v2[3], v3[3], v4[3], v5[3], cc[3];
    static integer kk;
    static doublereal vn[3];
    static integer nn3;
    static doublereal rt2, tol;
    static integer nnn3;
    static doublereal half, amax;
    static integer ncase;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), solve3_(doublereal *, doublereal *, doublereal *, integer *), 
	    degsol_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);


/*     CALCULATES CENTER C AND RADIUS R OF THE SMALLEST SPHERE WHICH */
/*     ENCLOSES THE FOUR POINTS P (THE CORNER POINTS OF PATCH). */
/*     THREE CASES, TESTED IN ORDER:- */
/*     1. ONE PAIR OF POINTS DEFINE DIAMETER OF SPHERE ENCLOSING ALL */
/*        FOUR CORNER POINTS. CHOOSE PAIR OF POINTS WITH GREATEST */
/*        SEPARATION, CHECK THAT OTHER TWO POINTS ARE INSIDE THIS SPHERE */
/*     2. THREE POINTS DEFINE EQUATOR OF SPHERE ENCLOSING ALL FOUR */
/*        POINTS. TRY ALL FOUR COMBINATIONS OF THREE POINTS, CHOOSE */
/*        SMALLEST SPHERE ENCLOSING FOUR POINTS */
/*     3. MINIMUM SPHERE DEFINED BY ALL FOUR POINTS */

/*     CHECKS THAT SPHERE FOUND ENCLOSES POLYGONAL CONVEX HALL PHULL */
/*     ADJUSTS RADIUS OF SPHERE BY UP TO 10% TO INCLUDE PHULL */
/*     IF NO SPHERE FOUND, THEN RETURN WITH R=0 */

/*     ON ENTRY, NP, N3 ARE DIMENSIONS OF PHULL */



/* .... COEFF. MATRIX AND WORKSPACE FOR CASE 3 */
/* .... CENTRE OF TRIAL SPHERE */

/* .... TEMP FOR TEST ONLY */

/* .... TOLERANCE */
    /* Parameter adjustments */
    p -= 5;
    phull_dim1 = *np;
    phull_offset = 1 + phull_dim1;
    phull -= phull_offset;
    --c__;

    /* Function Body */
    tol = .001;
    half = 1.;
    half /= 2.;

/*     CASE 1.      TWO POINTS AS DIAMETER */
    ncase = 1;
/* .... INITIALISE RADIUS SQUARED */
    r2 = 0.;
    for (j = 1; j <= 3; ++j) {
	for (k = j + 1; k <= 4; ++k) {
	    rt2 = 0.;
	    for (i__ = 1; i__ <= 3; ++i__) {
		a1 = p[j + (i__ << 2)];
		a2 = p[k + (i__ << 2)];
/* .... CENTRE OF TRIAL SPHERE */
		cc[i__ - 1] = half * (a1 + a2);
		a1 = half * (a1 - a2);
		rt2 += a1 * a1;
/* L20: */
	    }

/*     RT2 IS SQUARE OF RADIUS OF TRIAL SPHERE */
/* .... TEST TRIAL SPHERE */
	    if (r2 == 0. || rt2 <= r2) {
		for (l = 1; l <= 4; ++l) {
		    if (l == j || l == k) {
			goto L40;
		    }
		    a = 0.;
		    for (i__ = 1; i__ <= 3; ++i__) {
			a1 = (d__1 = p[l + (i__ << 2)] - cc[i__ - 1], abs(
				d__1)) - tol;
			a += a1 * a1;
/* L50: */
		    }
/* .... POINT OUTSIDE - REJECT */
		    if (a > rt2) {
			goto L10;
		    }
L40:
		    ;
		}
/*           SPHERE BEST SO FAR: STORE */
		r2 = rt2;
		for (i__ = 1; i__ <= 3; ++i__) {
		    c__[i__] = cc[i__ - 1];
/* L60: */
		}
	    }
/* L15: */
	}
L10:
	;
    }
/* .... ENCLOSING SPHERE FOUND - EXIT */
    if (r2 > 0.) {
	goto L300;
    }

/*     CASE 2.      THREE POINTS ON DIAMETRAL PLANE */

    ncase = 2;
    for (j = 1; j <= 2; ++j) {
	for (k = j + 1; k <= 3; ++k) {
/* .... FOR POINTS J, K, AND L */
	    for (l = k + 1; l <= 4; ++l) {
/* .... CALC. CIRCUMCIRCLE */
		for (i__ = 1; i__ <= 3; ++i__) {
		    v1[i__ - 1] = p[k + (i__ << 2)] - p[j + (i__ << 2)];
		    v2[i__ - 1] = p[l + (i__ << 2)] - p[j + (i__ << 2)];
		    v5[i__ - 1] = v2[i__ - 1] - v1[i__ - 1];
/* L110: */
		}
/* .... VN IS NORMAL TO PLANE OF THREE POINTS */
		cross_(v1, v2, vn);
		cross_(v1, vn, v3);
		cross_(vn, v2, v4);

		degsol_(v5, v3, v4, &a, &b, &i__);

		rt2 = 0.;
		for (i__ = 1; i__ <= 3; ++i__) {
		    a1 = half * (v1[i__ - 1] + a * v3[i__ - 1]);
/* .... CC IS CENTRE OF TRIAL SPHERE */
		    cc[i__ - 1] = p[j + (i__ << 2)] + a1;
/* .... RT2 IS SQUARE OF RADIUS OF TRIAL SPHERE */
		    rt2 += a1 * a1;
/* L120: */
		}

/* .... TEST TRIAL SPHERE */
		if (r2 == 0. || rt2 <= r2) {
		    for (kk = 1; kk <= 4; ++kk) {
			a = 0.;
			for (i__ = 1; i__ <= 3; ++i__) {
			    a1 = (d__1 = p[kk + (i__ << 2)] - cc[i__ - 1], 
				    abs(d__1)) - tol;
			    a += a1 * a1;
/* L140: */
			}
/* .... POINT OUTSIDE - REJECT */
			if (a > rt2) {
			    goto L160;
			}
/* L130: */
		    }
/*           SPHERE BEST SO FAR: STORE */
		    r2 = rt2;
		    for (i__ = 1; i__ <= 3; ++i__) {
			c__[i__] = cc[i__ - 1];
/* L150: */
		    }
		}
L160:
		;
	    }
/* L170: */
	}
/* L180: */
    }
/* .... ENCLOSING SPHERE FOUND - EXIT */
    if (r2 > 0.) {
	goto L300;
    }

/*     CASE 3.      FOUR POINT SPHERE */
    ncase = 3;
/* .... CALC. COEFFS H(K,I), V1(I) */
    a = 0.;
    for (k = 1; k <= 3; ++k) {
	a1 = p[(k << 2) + 4];
	a += a1 * a1;
/* L200: */
    }
    b = 0.;
    for (k = 1; k <= 3; ++k) {
	b = a;
	for (j = 1; j <= 3; ++j) {
	    a1 = p[k + (j << 2)];
	    b -= a1 * a1;
	    h__[k + j * 3 - 4] = p[(j << 2) + 4] - p[k + (j << 2)];
/* L220: */
	}
	v1[k - 1] = half * b;
/* L210: */
    }

    *n3 = 3;
    nn3 = 3;
    nnn3 = 3;
    k = 0;

/*     SOLVE 3 X 3 EQNS. FOR CENTRE C */

    solve3_(h__, v1, &c__[1], &k);

/* .... NO SOLUTION */
    if (k == 1) {
	goto L300;
    }
    r2 = 0.;
/* .... NOW CALC. RADIUS */
    for (k = 1; k <= 3; ++k) {
	a1 = p[(k << 2) + 1] - c__[k];
/* .... R2 IS RADIUS SQUARED */
	r2 += a1 * a1;
/* L230: */
    }

/* .... R IS RADIUS */
L300:
    *r__ = sqrt(r2);
/*     CHECK AGAINST CONVEX POLYGON */

    amax = 0.;
    i__1 = *np;
    for (k = 1; k <= i__1; ++k) {
	a = 0.;
	for (i__ = 1; i__ <= 3; ++i__) {
	    a1 = phull[k + i__ * phull_dim1] - c__[i__];
	    a += a1 * a1;
/* L320: */
	}
	if (a > r2 && a > amax) {
	    amax = a;
	}
/* L310: */
    }
/* .... ACCEPT RADIUS */
    if (amax == 0.) {
	goto L330;
    }
    a1 = sqrt(amax);
/*     A1 IS MAXIMUM DISTANCE OF HULL POINT FROM CENTRE */
/*     IF A1 SUCH THAT R < A1 < 1.1*R, THEN USE A1 AS RADIUS */
    if (a1 > *r__ && a1 <= *r__ * 1.1) {
	*r__ = a1;
/* .... NO SPHERE FOUND */
    } else {
	*r__ = 0.;
    }
L330:

    return 0;
} /* shella_ */

