/* INEX.f -- translated by f2c (version 20100827).
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
    doublereal cxhull[24000]	/* was [4][6][1000] */, dulim[1000], dvlim[
	    1000], curmax[1000], curmin[1000];
    integer ncxhul[1000], ngp, icursf;
} inidat_;

#define inidat_1 inidat_

/* *** SOURCE FILE : INEX.ORG   *** */

/* Subroutine */ int inex_(doublereal *geo, doublereal *side, doublereal *
	toli, doublereal *tolo)
{
    /* Initialized data */

    static integer m1[4] = { 1,2,4,3 };
    static integer m2[4] = { 4,1,3,2 };

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l, m, n;
    static doublereal r__[3], u, v, w[3];
    static integer n3, n4;
    static doublereal ru[3], rv[3], cv1[12]	/* was [4][3] */, cv2[12]	
	    /* was [4][3] */, rad, ruu[3], ruv[3], rvv[3];
    static integer irec, mode;
    static doublereal srad[4];
    static integer ncor[4];
    static doublereal rnet[75]	/* was [25][3] */, amesh, scent[12]	/* 
	    was [4][3] */;
    static integer nhull, isize;
    static doublereal tolin, rnorm[3], rcorn1[12]	/* was [4][3] */, 
	    rcorn2[12]	/* was [4][3] */, curve1, curve2;
    extern /* Subroutine */ int shella_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *, doublereal *), curcal_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    static integer nflags[4];
    extern /* Subroutine */ int shellb_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static integer npatch, nngrid;
    static doublereal crvmin, crvmax;
    extern /* Subroutine */ int evalss_(integer *, doublereal *, doublereal *,
	     integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer normok;


/*     INTERFERENCE CHECKING INITIALISATION PROCEDURE */

/*     CALCULATES: MAXIMUM AND MINIMUM CURVATURES      CURMAX,CURMIN */
/*                 ITERATION LIMITS                    DULIM, DVLIM */
/*                 CONVEX HULLS                        CXHULL */

/*     ARGUMENTS: */
/*            GEO   SURFACE CANONICAL FORM */
/*            SIDE  TOOL SIDE OF SURFACE W.R.T. SURFACE NORMAL */
/*            TOLI  SURFACE INTOL */
/*            TOLO  SURFACE OUTTOL */




/* .... INTERFERENCE CHECKING INITIAL DATA */



/* .... SPHERICAL SURFACE ENCLOSURES (HULLS) */
/* .... NUMBER OF HULLS */
/* .... DU ITERATION LIMIT FOR PATCHES */
/* .... DV ITERATION LIMIT FOR PATCHES */
/* .... MAXIMUM AND MINIMUM CURVATURE OF PATCHES */

/*     MXNP   -  MAXIMUM NUMBER OF PATCHES PER SURFACE */
/*     NGP    -  NUMBER OF PATCHES IN CURRENT SURFACE */
/*     ICURSF -  EXTERNAL LDA FILE RECORD NUMBER FOR CURRENT SURFACE */



/* .... MESH DIMENSION */
/* .... MESH POINTS */
/* .... PATCH CORNER POINTS */
/* .... PATCH CORNER VECTORS */
/* .... POINTERS FOR ABOVE */

/*     CXHULL(I,J,K)   RETURNS CONVEX HULL DATA FOR K TH PATCH */
/*     I = 1 TO 3      CENTRE COORDINATES */
/*     I = 4           RADIUS */
/*     WHERE HULLS ARE CALCULATED, LOADED IN J-ORDER:- */
/*     MINIMUM ENCLOSING SPHERE */
/*     UP TO 4 "EDGE" SPHERES */
/*     "LID" SPHERE */
/*     NCXHUL(K)       NUMBER OF HULLS FOR THE K TH PATCH */

    /* Parameter adjustments */
    --geo;

    /* Function Body */

/* .... CHECK IF THIS SURFACE HAS ALREADY BEEN PROCESSED BY INEX */

/* .... EXTERNAL LDA FILE RECORD NUMBER FOR THIS SURFACE */

    irec = i_dnnt(&geo[1]);

    if (inidat_1.icursf == 0 || irec != inidat_1.icursf) {
/* .... CURRENT SURFACE NOT PREVIOUSLY PROCESSED BY INEX */

	inidat_1.icursf = irec;
/* .... NUMBER OF PATCHES */
	inidat_1.ngp = i_dnnt(&geo[4]);
/* .... SIZE OF CANONICAL FORM */
	isize = i_dnnt(&geo[8]);

	n3 = 3;
	n4 = 4;

/*     TO SET UP MESH PARAMETERS */

/* .... NUMBER OF MESH POINTS */
	nngrid = 25;
	n = 4;
/* .... MESH SIZE */
	amesh = 1.f / (real) n;
	ncor[0] = 1;
	ncor[1] = 5;
	ncor[3] = nngrid;
	ncor[2] = ncor[3] - 4;
/* .... ALL DERIVATIVES FROM EVALUATOR */
	mode = 3;
/* .... DISTANCE TOLERANCE */
	tolin = (*toli + *tolo) * .5;

/* .... FOR ALL PATCHES */
	i__1 = inidat_1.ngp;
	for (npatch = 1; npatch <= i__1; ++npatch) {
	    crvmin = 1e6;
	    crvmax = -1e6;
	    m = 1;
/*     CALC. MESH U,V */
	    i__2 = n;
	    for (k = 0; k <= i__2; ++k) {
		u = k * amesh;
		i__3 = n;
		for (j = 0; j <= i__3; ++j) {
		    v = j * amesh;
		    l = k * 5 + j + 1;

		    evalss_(&npatch, &u, &v, &isize, &geo[1], &mode, r__, ru, 
			    rv, ruu, ruv, rvv, rnorm, &normok);
		    for (i__ = 1; i__ <= 3; ++i__) {
			rnet[l + i__ * 25 - 26] = r__[i__ - 1];
/* L20: */
		    }
/*     IF CORNER, STORE CORNER POINTS AND EDGE VECTORS */
		    if (l == ncor[m - 1]) {
			for (i__ = 1; i__ <= 3; ++i__) {
			    rcorn1[m1[m - 1] + (i__ << 2) - 5] = r__[i__ - 1];
			    rcorn2[m2[m - 1] + (i__ << 2) - 5] = r__[i__ - 1];

			    if (m == 1 || m == 4) {
				cv1[m1[m - 1] + (i__ << 2) - 5] = rv[i__ - 1];
				cv2[m2[m - 1] + (i__ << 2) - 5] = ru[i__ - 1];
			    } else {
				cv1[m1[m - 1] + (i__ << 2) - 5] = ru[i__ - 1];
				cv2[m2[m - 1] + (i__ << 2) - 5] = rv[i__ - 1];
			    }

/* L30: */
			}
			++m;
		    }

/*     CALC. PRINCIPAL CURVATURES */

		    curcal_(ru, rv, ruu, ruv, rvv, rnorm, side, &curve1, &
			    curve2);

/* Computing MAX */
		    d__1 = max(crvmax,curve1);
		    crvmax = max(d__1,curve2);
/* Computing MIN */
		    d__1 = min(crvmin,curve1);
		    crvmin = min(d__1,curve2);
/* L400: */
		}
/* L500: */
	    }

/*     TO STORE MAXIMUM AND MINIMUM CURVATURE */
	    inidat_1.curmax[npatch - 1] = crvmax;
	    inidat_1.curmin[npatch - 1] = crvmin;

/*     TO CALCULATE DULIM, DVLIM */
/* .... A IS SUM OF U-DISTANCES BETWEEN CORNER POINTS */
	    a = 0.;
/* .... B IS SUM OF V-DISTANCES BETWEEN CORNER POINTS */
	    b = 0.;
	    for (i__ = 1; i__ <= 3; ++i__) {
		for (j = 1; j <= 4; ++j) {
		    c__ = rcorn1[j + (i__ << 2) - 5] - rcorn2[j + (i__ << 2) 
			    - 5];
		    if (j == 1 || j == 3) {
			b += c__ * c__;
		    } else {
			a += c__ * c__;
		    }
/* L100: */
		}
/* L150: */
	    }

	    inidat_1.dulim[npatch - 1] = tolin / sqrt(a);
	    inidat_1.dvlim[npatch - 1] = tolin / sqrt(b);
/*     DU, DV LIMITS CALCULATED */

/*     TO CALCULATE SPHERICAL CONVEX HULLS */
	    nhull = 0;
	    shella_(rcorn1, rnet, &nngrid, &n3, w, &rad);
	    if (rad > tolin) {
		++nhull;
		for (i__ = 1; i__ <= 3; ++i__) {
		    inidat_1.cxhull[i__ + (nhull + npatch * 6 << 2) - 29] = w[
			    i__ - 1];
/* L200: */
		}
		inidat_1.cxhull[(nhull + npatch * 6 << 2) - 25] = rad;
	    }

	    shellb_(&nngrid, &n3, &n4, rcorn1, rcorn2, cv1, cv2, rnet, scent, 
		    srad, nflags);
	    for (k = 1; k <= 4; ++k) {
		if (nflags[k - 1] == 1) {
		    ++nhull;
		    for (i__ = 1; i__ <= 3; ++i__) {
			inidat_1.cxhull[i__ + (nhull + npatch * 6 << 2) - 29] 
				= scent[k + (i__ << 2) - 5];
/* L220: */
		    }
		    inidat_1.cxhull[(nhull + npatch * 6 << 2) - 25] = srad[k 
			    - 1];
		}
/* L210: */
	    }
	    inidat_1.ncxhul[npatch - 1] = nhull;

/* L1000: */
	}

    }

    return 0;
} /* inex_ */

