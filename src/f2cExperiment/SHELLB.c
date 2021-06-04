/* SHELLB.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : SHELLB.ORG   *** */

/* Subroutine */ int shellb_(integer *nn, integer *n3, integer *n4, 
	doublereal *rcorn1, doublereal *rcorn2, doublereal *cv1, doublereal *
	cv2, doublereal *rnet, doublereal *scent, doublereal *srad, integer *
	nflags)
{
    /* System generated locals */
    integer rcorn1_dim1, rcorn1_offset, rcorn2_dim1, rcorn2_offset, cv1_dim1, 
	    cv1_offset, cv2_dim1, cv2_offset, rnet_dim1, rnet_offset, 
	    scent_dim1, scent_offset;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, d__[3], e[3], f[3];
    static integer i__, j, k;
    static doublereal a1, a2, v1[3], v2[3], ab[3], ea[3], cd[3], eb[3], de[3],
	     ef[3], al, ar;
    static integer jj;
    static doublereal am1, am2, amax;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer jedge;
    static doublereal abmod, efmod;
    extern /* Subroutine */ int vecmod_(doublereal *, doublereal *);
    static integer ncount;


/*     CALCULATES THE FOUR "EDGE" SHELLS FOR A PATCH SPECIFIED BY RNET, E */
/*     ON CALL:- */
/*     N3=3 */
/*     N4=4 */
/*     NN      FIRST DIMENSION OF RNET ARRAY */



/* .... CORNER POINTS */
/* .... CORNER VECTORS */
/* .... NET OF POINTS */



/* .... SPHERE CENTRES */
/* .... SPHERE RADII */
/* .... SET TO 1 IF SPHERE CALCULATED, ELSE 0 */


    /* Parameter adjustments */
    rnet_dim1 = *nn;
    rnet_offset = 1 + rnet_dim1;
    rnet -= rnet_offset;
    --nflags;
    --srad;
    scent_dim1 = *n4;
    scent_offset = 1 + scent_dim1;
    scent -= scent_offset;
    cv2_dim1 = *n4;
    cv2_offset = 1 + cv2_dim1;
    cv2 -= cv2_offset;
    cv1_dim1 = *n4;
    cv1_offset = 1 + cv1_dim1;
    cv1 -= cv1_offset;
    rcorn2_dim1 = *n4;
    rcorn2_offset = 1 + rcorn2_dim1;
    rcorn2 -= rcorn2_offset;
    rcorn1_dim1 = *n4;
    rcorn1_offset = 1 + rcorn1_dim1;
    rcorn1 -= rcorn1_offset;

    /* Function Body */
    jedge = 2;

/* .... MAIN LOOP */
    for (k = 1; k <= 4; ++k) {
	if (k == 3) {
	    jedge = -jedge;
	}
	nflags[k] = 0;
	jj = k + jedge;

/*     CONSTRUCT VECTORS:- */
	for (i__ = 1; i__ <= 3; ++i__) {
	    e[i__ - 1] = (rcorn1[k + i__ * rcorn1_dim1] + rcorn2[k + i__ * 
		    rcorn2_dim1]) / 2.f;
	    ab[i__ - 1] = rcorn2[k + i__ * rcorn2_dim1] - rcorn1[k + i__ * 
		    rcorn1_dim1];
	    ea[i__ - 1] = rcorn1[k + i__ * rcorn1_dim1] - e[i__ - 1];
	    d__[i__ - 1] = rcorn1[jj + i__ * rcorn1_dim1];
	    cd[i__ - 1] = d__[i__ - 1] - rcorn2[jj + i__ * rcorn2_dim1];
	    de[i__ - 1] = e[i__ - 1] - d__[i__ - 1];
/* L20: */
	}
	vecmod_(ab, &abmod);
	if (abmod < .001) {
/* .... PATCH EDGE DEGENERATED TO NEAR POINT */
	    srad[k] = 0.;
/*                         NO SHELL CALCULATED */
	    goto L10;
	}

	dotf_(&a1, de, ab);
	dotf_(&a2, ab, cd);
	al = a1 / a2;
	for (i__ = 1; i__ <= 3; ++i__) {
	    v1[i__ - 1] = cv1[k + i__ * cv1_dim1];
	    v2[i__ - 1] = cv2[k + i__ * cv2_dim1];
	    f[i__ - 1] = d__[i__ - 1] + al * cd[i__ - 1];
	    ef[i__ - 1] = f[i__ - 1] - e[i__ - 1];
/* L30: */
	}

	dotf_(&a1, ea, v1);
	dotf_(&a2, ef, v1);
	if (abs(a2) < 1e-6) {
	    am1 = 1e8;
	} else {
	    am1 = a1 / a2;
	}
	dotf_(&a1, eb, v2);
	dotf_(&a2, ef, v2);
	if (abs(a2) < 1e-6) {
	    am2 = 1e8;
	} else {
	    am2 = a1 / a2;
	}
	if (am1 > 0. && am2 > 0. && am2 < am1) {
	    am1 = am2;
	} else if (am2 > 0. && am1 <= 0.) {
	    am1 = am2;
	}

	vecmod_(ef, &efmod);

	a2 = abmod * abmod / 4.;
	if (am1 <= 0.) {
	    ar = 1e5;
	} else {
	    a1 = am1 * efmod;
	    ar = sqrt(a1 * a1 + a2);
	}

	if (ar >= 1e5) {
	    ar = 1e5;
	    am1 = sqrt(ar * ar - a2) / efmod;
	}


	srad[k] = ar;
	for (i__ = 1; i__ <= 3; ++i__) {
	    scent[k + i__ * scent_dim1] = e[i__ - 1] + am1 * ef[i__ - 1];
/* L60: */
	}

	ncount = 0;
L100:
	++ncount;
/*     SPHERE ENCLOSES V1 AND V2. NOW TEST THAT RNET POINTS ARE INCLUDED */
	amax = 0.;
	for (j = 1; j <= 25; ++j) {
	    a1 = 0.;
	    for (i__ = 1; i__ <= 3; ++i__) {
		a2 = rnet[j + i__ * rnet_dim1] - scent[k + i__ * scent_dim1];
		a1 += a2 * a2;
/* L120: */
	    }
	    if (a1 > amax) {
		amax = a1;
	    }
/* L110: */
	}
/* .... A IS DIST. FROM CENTRE TO FURTHEST POINT OF RNET */
	a = sqrt(amax);
	a1 = a - ar;
/* .... HULL POINTS INSIDE SPHERE */
	if (a1 <= .001) {
/* .... CONVEX HULL FOUND - SET FLAG */
	    nflags[k] = 1;
	    goto L10;
	}
	if (a1 <= abmod * 1.1f) {
/* .... INCREASE RADIUS */
	    ar = a;
	    srad[k] = a;
/* .... TRY FOR FIT */
	    if (ncount <= 2) {
		goto L100;
	    }
	} else {
	    srad[k] = 0.;
	}

L10:
	;
    }

    return 0;
} /* shellb_ */

