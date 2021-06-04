/* PENCUT.f -- translated by f2c (version 20100827).
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

static doublereal c_b4 = 1.;

/* *** SOURCE FILE : PENCUT.V01   *** */

/* Subroutine */ int pencut_(doublereal *r__, doublereal *rn, doublereal *
	toolce, doublereal *toolax, doublereal *tul, doublereal *pside, 
	doublereal *pthick, doublereal *t, doublereal *tn, doublereal *pen, 
	integer *iseg)
{
    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal a, b;
    static integer k;
    static doublereal s, v[3], w[3], x, v1[3], xr[3];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), norma_(doublereal *, doublereal *, doublereal *);


/*     CALCS. PENETRATION OF POINT R INTO CUTTER */


/*     T            NEAREST POINT ON TOOL TO R */
/*     TN           TOOL NORMAL AT T */
/*     ISEG  =  0   T ON:-   BOTTOM FLAT */
/*              1            BALL OR CORNER RADIUS */
/*              2            CYLINDRICAL SHANK */
/*     PEN      = PENETRATION: DISTANCE R-T (+VE FOR HIT) */
/*     PSIDE    = TOOL SIDE OF SURFACE */
/*     PTHICK   = PART SURFACE THICKNESS */
/* .... SURFACE POINT AND NORMAL */
/* .... TOOL AXIS */
/* .... TOOLCENTRE */
/* .... CUTTER GEOMETRY */

/* .... WORKSPACE */
/* .... ASSOCIATED CORNER RADIUS CENTER */
/* .... ASSOCIATED POINT ON TOOL AND TOOL NORMAL */


/* .... CALCULATE HEIGHT,A OF POINT R ABOVE TOOL CENTER */

    /* Parameter adjustments */
    --tn;
    --t;
    --tul;
    --toolax;
    --toolce;
    --rn;
    --r__;

    /* Function Body */
    for (k = 1; k <= 3; ++k) {
	v[k - 1] = r__[k] - toolce[k];
/* L10: */
    }
    dotf_(&a, v, &toolax[1]);

/* .... CALCULATE RADIAL DIRECTION,W AND DISTANCE,B FROM TOOL AXIS */

    for (k = 1; k <= 3; ++k) {
	v1[k - 1] = v[k - 1] - a * toolax[k];
/* L20: */
    }
    norma_(v1, w, &b);

/* .... COMPUTE SURFACE SIDE OF TOOL */

    if (b > tul[2]) {
	s = -(*pside);
    } else {
	dotf_(&s, &rn[1], w);
	s *= *pside;
	s = d_sign(&c_b4, &s);
    }

/* .... COMPUTATION OF ASSOCIATED POINT, TOOL NORMAL AND PENETRATION */
/*     WILL DEPEND ON RELATIVE LOCATION OF SURFACE POINT TO TOOL CENTER */

    if (a >= 0.) {
/* .... CYLINDER CASES */
	if (b >= tul[3]) {
/* .... 'OUTER' CYLINDER CASE */
	    *iseg = 2;
	    *pen = tul[2] + s * b + *pthick;
	    for (k = 1; k <= 3; ++k) {
		tn[k] = s * w[k - 1];
		t[k] = toolce[k] - tul[2] * tn[k] + a * toolax[k];
/* L30: */
	    }

	} else {
/* .... 'INNER' CYLINDER CASE */
	    for (k = 1; k <= 3; ++k) {
		xr[k - 1] = toolce[k] - s * tul[3] * w[k - 1];
		v1[k - 1] = r__[k] - xr[k - 1];
/* L40: */
	    }
	    norma_(v1, &tn[1], &x);
	    *iseg = 1;
	    *pen = x + tul[1] + *pthick;
	    for (k = 1; k <= 3; ++k) {
		t[k] = xr[k - 1] - tul[1] * tn[k];
/* L50: */
	    }
	}

    } else {
/* .... CORNER RADIUS OR BASE */
	if (b <= tul[3]) {
/*     BOTTOM FLAT CASE */
	    *iseg = 0;
	    *pen = tul[4] + tul[1] + a + *pthick;
	    for (k = 1; k <= 3; ++k) {
		tn[k] = toolax[k];
		t[k] = toolce[k] + v1[k - 1] - (tul[4] + tul[1]) * toolax[k];
/* L60: */
	    }
	} else {
/*     CORNER RADIUS */
	    *iseg = 1;
	    for (k = 1; k <= 3; ++k) {
		xr[k - 1] = toolce[k] + tul[3] * w[k - 1];
/* L70: */
	    }

	    for (k = 1; k <= 3; ++k) {
		v1[k - 1] = xr[k - 1] - r__[k];
/* L80: */
	    }
	    norma_(v1, &tn[1], &x);

	    *pen = tul[1] - x + *pthick;

	    for (k = 1; k <= 3; ++k) {
		t[k] = xr[k - 1] - tul[1] * tn[k];
/* L90: */
	    }

	}

    }

    return 0;
} /* pencut_ */

