/* REMSCN.f -- translated by f2c (version 20100827).
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

/* *** SOURCE FILE : REMSCN.ORG   *** */

/* Subroutine */ int remscn_(doublereal *te, doublereal *ta, doublereal *tul, 
	doublereal *r__, doublereal *pside, doublereal *pthick, doublereal *
	tolin, integer *npat, integer *lsusp, integer *nsusp)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static doublereal a, d__;
    static integer i__, j, k;
    static doublereal d2, v1[3], v2[3];
    static logical ball;
    static integer iret;
    extern doublereal dist2_(doublereal *, doublereal *);
    static doublereal tcrad, tcent[3];
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vecmod_(doublereal *, doublereal *);
    static doublereal tccent[3], tlcent[3];
    extern /* Subroutine */ int tcsphr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), hulcut_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);


/*     PURPOSE: TO TEST ALL REMOTE (NON-CURRENT) PATCHES FOR POSSIBLE */
/*              INTEFERENCE */

/*     ARGUMENTS: */

/*     TE      -  TOOL END COORDINATES */
/*     TA      -  TOOL AXIS VECTOR */
/*     TUL     -  TOOL GEOMETRY */
/*     R       -  SURFACE CONTACT POINT AND DERIVATIVES */
/*     PSIDE   -  1 OR -1 TO AJUST SURFACE NORMAL (RU X RV) */
/*     PTHICK  -  THICKNESS OFFSET FROM SURFACE */
/*     TOLIN   -  TOLERANCE (PS INTOL) */
/*     NPAT    -  PATCH NUMBER FOR CONTACT POINT */
/*     LSUSP   -  SUSPECT PATCHES */
/*     NSUSP   -  NUMBER OF SUSPECT PATCHES */







/* .... LOCAL VARIABLES */

/*     TCCENT  -  CENTRE OF TOOL CONTACT SPHERE */
/*     TCRAD   -  RADIUS OF TOOL CONTACT SPHERE */
/*     TLCENT  -  CENTRE OF LARGE SHALLOW SPHERE THROUGH TE, RADIUS BIG5 */
/*     TCENT   -  CENTRE OF TIGHT SPHERE ENVELOPING TOOL, RADIUS=TUL(2) */
/*     BALL    -  CUTTER TYPE FLAG = .TRUE. IF CUTTER IS BALLENDED */
/*                                 = .FALSE. OTHERWISE */
/*     ISEG    -  INDICATES SEGMENT OF TOOL THAT PENETRATES */
/*                         = -1 IF NO PENETRATION */
/*                         =  0   BOTTOM FLAT */
/*                         =  1   CORNER RADIUS */
/*                         =  2   CYLINDER */
/*     V1      -  VECTOR FROM TOOL TIP TO CENTRE OF PATCH SPHERE */
/*     V2      -  V1 X TA */
/*     D       -  MINIMUM DISTANCE BETWEEN CENTRE OF PATCH SPHERE */
/*                AND TOOL AXIS */
/*     D2      -  SQUARE OF DISTANCE BETWEEN TWO SPHERE CENTRES */
/*     A       -  MINIMUM DISTANCE BETWEEN SPHERE CENTRES TO AVOID */
/*                INTERFERENCE */





/* .... CALCULATE TOOL CONTACT SPHERE FOR CURRENT TOOL POSITION */


/* .... INTERFERENCE CHECKING INITIAL DATA */



/* .... SPHERICAL SURFACE ENCLOSURES (HULLS) */
/* .... NUMBER OF HULLS */
/* .... DU ITERATION LIMIT FOR PATCHES */
/* .... DV ITERATION LIMIT FOR PATCHES */
/* .... MAXIMUM AND MINIMUM CURVATURE OF PATCHES */

/*     MXNP   -  MAXIMUM NUMBER OF PATCHES PER SURFACE */
/*     NGP    -  NUMBER OF PATCHES IN CURRENT SURFACE */
/*     ICURSF -  EXTERNAL LDA FILE RECORD NUMBER FOR CURRENT SURFACE */


    /* Parameter adjustments */
    --lsusp;
    --r__;
    --tul;
    --ta;
    --te;

    /* Function Body */
    tcsphr_(&te[1], &ta[1], &tul[1], &r__[1], pside, pthick, tccent, &tcrad);

/* .... CALCULATE CENTRE OF LARGE SHALLOW SPHERE THROUGH TE */
/*     AND CENTRE OF TIGHT SPHERE ENVELOPING TOOL */

    for (i__ = 1; i__ <= 3; ++i__) {
	tlcent[i__ - 1] = te[i__] + ta[i__] * 1e5;
	tcent[i__ - 1] = te[i__] + tul[2] * ta[i__];
/* L10: */
    }

/* .... SET FLAG INDICATING CUTTER TYPE */

    if ((d__1 = tul[1] - tul[2], abs(d__1)) <= 1e-6) {
/* .... BALL-ENDED */
	ball = TRUE_;
    } else {
	ball = FALSE_;
    }

/* .... TEST NON-CURRENT PATCHES FOR POSSIBLE INTERFERENCE */

    *nsusp = 0;
    i__1 = inidat_1.ngp;
    for (k = 1; k <= i__1; ++k) {
	if (k != *npat) {

/* .... TEST FOR INTERFERENCE OF INFINITE TOOL CYLINDER WITH */
/*     MINIMUM PATCH SPHERE */

	    for (i__ = 1; i__ <= 3; ++i__) {
		v1[i__ - 1] = inidat_1.cxhull[i__ + (k * 6 + 1 << 2) - 29] - 
			te[i__];
/* L100: */
	    }
	    cross_(v1, &ta[1], v2);
	    vecmod_(v2, &d__);
	    if (d__ >= inidat_1.cxhull[(k * 6 + 1 << 2) - 25] + *pthick + tul[
		    2] - *tolin) {
		goto L1000;
	    }

/* .... STILL POSSIBLE INTERFERENCE WITH THIS PATCH */

/* .... TEST FOR INTERFERENCE OF TIGHT TOOL SPHERE */
/*     WITH ALL PATCH CONVEX HULL SPHERES */

	    i__2 = inidat_1.ncxhul[k - 1];
	    for (j = 1; j <= i__2; ++j) {
		d2 = dist2_(&inidat_1.cxhull[(j + k * 6 << 2) - 28], tcent);
		a = inidat_1.cxhull[(j + k * 6 << 2) - 25] + *pthick + tul[2] 
			- *tolin;
		if (d__ >= a * a) {
		    goto L1000;
		}
/* L200: */
	    }

/* .... STILL POSSIBLE INTERFERENCE WITH THIS PATCH */

/* .... TEST FOR INTERFERENCE OF SHALLOW TOOL SPHERE */
/*     WITH ALL PATCH CONVEX HULL SPHERES */

	    i__2 = inidat_1.ncxhul[k - 1];
	    for (j = 1; j <= i__2; ++j) {
		d2 = dist2_(&inidat_1.cxhull[(j + k * 6 << 2) - 28], tlcent);
		a = inidat_1.cxhull[(j + k * 6 << 2) - 25] + *pthick + 1e5 - *
			tolin;
		if (d__ >= a * a) {
		    goto L1000;
		}
/* L300: */
	    }

/* .... STILL POSSIBLE INTERFERENCE WITH THIS PATCH */

/* .... TEST FOR INTERFERENCE OF TOOL CONTACT SPHERE */
/*     WITH ALL PATCH CONVEX HULL SPHERES */

	    i__2 = inidat_1.ncxhul[k - 1];
	    for (j = 1; j <= i__2; ++j) {
		d2 = dist2_(&inidat_1.cxhull[(j + k * 6 << 2) - 28], tccent);
		a = inidat_1.cxhull[(j + k * 6 << 2) - 25] + *pthick + tcrad 
			- *tolin;
		if (d__ >= a * a) {
		    goto L1000;
		}
/* L400: */
	    }

/* .... STILL POSSIBLE INTERFERENCE WITH THIS PATCH */

/* .... TEST FOR INTERFERENCE OF ACTUAL TOOL */
/*     WITH ALL PATCH CONVEX HULL SPHERES */
/*     UNLESS CUTTER IS BALL-ENDED */

	    if (! ball) {
		i__2 = inidat_1.ncxhul[k - 1];
		for (j = 1; j <= i__2; ++j) {
		    hulcut_(&te[1], &ta[1], &tul[1], &inidat_1.cxhull[(j + k *
			     6 << 2) - 28], &iret);
		    if (iret < 0) {
			goto L1000;
		    }
/* L500: */
		}
	    }

/* .... PATCH NOT CLEARED - ADD TO SUSPECT LIST */

	    ++(*nsusp);
	    lsusp[*nsusp] = k;
	}
L1000:
	;
    }

    return 0;
} /* remscn_ */

