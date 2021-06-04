/* CURINT.f -- translated by f2c (version 20100827).
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

struct {
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

struct {
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;

/* *** SOURCE FILE : CURINT.V01   *** */

/* Subroutine */ int curint_(doublereal *psurf, integer *ipsize, doublereal *
	pside, doublereal *pthick, doublereal *tolin, doublereal *tul, 
	doublereal *te, doublereal *toolax, doublereal *rc, integer *npatch, 
	doublereal *uc, doublereal *vc)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Local variables */
    static doublereal a;
    static integer i__, j, k;
    static doublereal u, v, d1, v1[3], v2[3], v3[3], ct, du, dv, du1, dv1;
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
    static doublereal hrad;
    static integer ipen;
    static doublereal tlen;
    static integer icur, nhit;
    static doublereal upen, vpen, cutr3;
    static integer iedge, iflag;
    static doublereal hcent[3], dumin, dvmin;
    extern /* Subroutine */ int mixal_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *);
    static integer itool;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal pnorm[3];
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static doublereal dumin2, dvmin2;
    extern /* Subroutine */ int jmplt2_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal corrad;
    extern /* Subroutine */ int degsol_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static doublereal cyleng, cutrad, toolce[3];
    static integer nitera;
    static doublereal penmax, patcur, rcnorm[3], prevdu, ppoint[3], curtol, 
	    prevdv, tpoint[3];
    extern /* Subroutine */ int txhull_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);


/*     PURPOSE: TO TEST CURRENT PATCH */
/*     FOR BALL-ENDED AND CORNER RADIUS CUTTERS. */
/*     USES MIXED ALGORITHM METHOD (MIXAL) */

/*     GIVEN :- */
/*     NPATCH      CURRENT PATCH NUMBER */
/*     CUTTING POINT DATA (U, V, POSITION, NORMAL AND DERIVATIVES) */
/*     TOOL DATA, THEN:- */

/*     TEST SCHEDULE FOR CURRENT PATCH :- */
/*     1. TEST FOR PATCH CONVEX. IF TRUE, THEN NO LOCAL INTERFERENCE */
/*     2. CALCULATE THE CURVATURE CT OF THE MINIMUM SPHERICAL CONVEX */
/*        HULL FOR THE TOOL WITH THE CUTTING POINT AS A DIAMETRAL */
/*        POINT.OF CONTACT. TEST AGAINST THE SIGNED MINIMUM CURVATURE */
/*        OF THE PATCH CP. THEN IF CP > CT NO LOCAL INTERFERENCE CAN */
/*        OCCUR */
/*     3. USE MIXAL TO SEARCH FOR INTERFERENCE ON THE PATCH, USING A */
/*        A NUMBER OF STARTING POINTS ARRANGED IN A PATTERN ABOUT THE */
/*        CUTTING POINT. (THE CUTTING POINT CANNOT BE USED AS A */
/*        STARTING POINT FOR THESE SEARCHES, SINCE IT IS A SOLUTION) */

/* .... PATCH DATA */
/* .... CUTTING POINT DATA */
/* .... SURFACE POINT AND DERIVATIVES */
/* .... SECOND DERIVATIVES */
/* .... NORMAL AT R */

/* .... POINT OF MAX. PENETRATION FOUND. */
/*     NOT NECESSARILY THE FINAL POINT OF ITERATION. */
/*     IS TRUE (I.E. EVALUATED, NOT EXTRAPOLATED) SURFACE POINT. */
/* .... CORRESPONDING POINT ON TOOL */
/* .... NORMAL AT PPOINT */
/*     PENMAX          PENETRATION (HIT +VE) */
/*     UPEN, VPEN      U,V VALUES */

/* .... TOOL GEOMETRY DATA */
/* .... ABS. TOOL TIP COORDS */
/* .... TOOL AXES DIRN. COSINES */
/* .... TOOL CENTRE */


/* .... INTERFERENCE CHECKING INITIAL DATA */



/* .... SPHERICAL SURFACE ENCLOSURES (HULLS) */
/* .... NUMBER OF HULLS */
/* .... DU ITERATION LIMIT FOR PATCHES */
/* .... DV ITERATION LIMIT FOR PATCHES */
/* .... MAXIMUM AND MINIMUM CURVATURE OF PATCHES */

/*     MXNP   -  MAXIMUM NUMBER OF PATCHES PER SURFACE */
/*     NGP    -  NUMBER OF PATCHES IN CURRENT SURFACE */
/*     ICURSF -  EXTERNAL LDA FILE RECORD NUMBER FOR CURRENT SURFACE */



/*    INTERFERENCE TABLE */






/* .... WORKSPACE */

/* .... DEBUG FLAGS */



/*     CUTTER DEFINITION FOR BALL-ENDED AND CORNER RADIUS CUTTERS */

/*     ITOOL IS CUTTER TYPE: 1 FOR BALL-ENDED, 2 FOR CORNER RADIUS */
/*     CUTRAD IS RADIUS OF CYLINDER */
/*     CYLENG IS LENGTH OF CYLINDER */
/*     CORRAD IS CORNER RADIUS */
/*     CUTR3  IS CUTRAD-CORRAD */

    /* Parameter adjustments */
    --psurf;
    --tul;
    --te;
    --toolax;
    --rc;

    /* Function Body */
    corrad = tul[1];
    cutrad = tul[2];
    cutr3 = tul[3];
    tlen = tul[7];
    cyleng = tul[7] - tul[4] + tul[1];
    if ((d__1 = tul[1] - tul[2], abs(d__1)) <= 1e-6) {
	itool = 1;
    } else {
	itool = 2;
    }

/*     CALC. CURVATURE TOLERANCE CURTOL */

    if (*tolin > 1e-6) {
	d1 = cutrad * 2.;
	a = max(cyleng,d1);
	curtol = 2 / (*tolin + a * a / *tolin);
    } else {
	curtol = 0.;
    }

/* .... ADJUST NORMAL AT CONTACT POINT TO POINT TO TOOL SIDE OF SURFACE */

    for (i__ = 1; i__ <= 3; ++i__) {
	rcnorm[i__ - 1] = *pside * rc[i__ + 28];
/* L10: */
    }

    ipen = 0;
    iedge = 0;

/*     TEST FOR PATCH CONVEX */

    patcur = inidat_1.curmax[*npatch - 1];
    if (patcur > curtol) {
	dumin = inidat_1.dulim[*npatch - 1];
	dumin2 = dumin * 2;
	dvmin = inidat_1.dvlim[*npatch - 1];
	dvmin2 = dvmin * 2;

/* .... CALCULATE TOOL CENTRE */
	for (i__ = 1; i__ <= 3; ++i__) {
	    toolce[i__ - 1] = te[i__] + (tul[4] + tul[1]) * toolax[i__];
/* L100: */
	}

/*     TEST AGAINST TOOL CONVEX HULL CURVATURE */
	txhull_(&rc[1], rcnorm, &cutrad, &corrad, &cutr3, &tlen, &toolax[1], &
		te[1], toolce, &ct, &hrad, hcent);

	if (ct < patcur) {

/*     SEARCH FOR LOCAL INTERFERENCE */
/*     CALC. SEARCH DIRECTIONS IN TANGENT PLANE :- */
	    cross_(rcnorm, &toolax[1], v3);
	    vnorm_(v3, v1);
	    cross_(v1, rcnorm, v3);
	    vnorm_(v3, v2);

/*     V1 AND V2 ARE UNIT VECTORS IN TANGENT PLANE AT CUTTING POINT */
/*     V2 PERPENDICULAR TO TOOL AXIS, V1 PERPENDICULAR TO V2 */

/*     SEARCH AT 5 START POINTS */

/* .... LOCATION IN INTERFERENCE TABLE FOR START OF LOCAL PATCH DATA */

	    icur = interf_1.npintr;
/* .... NUMBER OF HITS ON LOCAL PATCH */
	    nhit = 0;

	    a = cutrad * -.5f;
	    degsol_(v1, &rc[5], &rc[9], &du1, &dv1, &i__);
	    for (k = 1; k <= 5; ++k) {
		if (k == 3) {
		    degsol_(v2, &rc[5], &rc[9], &du1, &dv1, &i__);
		}

		if (k < 5) {
		    a = -a;
		} else {
		    a *= 3;
		}

		du = a * du1;
		dv = a * dv1;
		jmplt2_(uc, vc, &du, &dv, &i__);
		if (abs(du) >= dumin || abs(dv) >= dvmin) {
		    u = *uc + du;
		    v = *vc + dv;
		    penmax = -1e6;
		    if (nitera > 1) {
			prevdu = du1;
			prevdv = dv1;
		    }

		    mixal_(npatch, ipsize, &psurf[1], pside, pthick, &tul[1], 
			    toolce, &toolax[1], &u, &v, &dumin, &dvmin, &upen,
			     &vpen, ppoint, tpoint, pnorm, &penmax, &ipen, &
			    iflag, &iedge, &nitera);

/* .... DEBUG PRINT */

		    if (ibugg_1.ibug == 11) {
			bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
			bad_(&c__1, &c__0, "NPAT", npatch, (ftnlen)4);
			bad_(&c__1, &c__0, "K   ", &k, (ftnlen)4);
			bad_(&c__1, &c__0, "ITER", &nitera, (ftnlen)4);
		    }

		    if (penmax > *tolin) {
/* .... PENETRATION DETECTED */
			if (nhit > 0) {
			    if ((d__1 = *uc - upen, abs(d__1)) > dumin2 || (
				    d__2 = *vc - vpen, abs(d__2)) > dvmin2) {

				i__1 = nhit;
				for (i__ = 1; i__ <= i__1; ++i__) {
				    if ((d__1 = interf_1.uintr[icur + i__ - 1]
					     - upen, abs(d__1)) <= dumin2 && (
					    d__2 = interf_1.vintr[icur + i__ 
					    - 1] - vpen, abs(d__2)) <= dvmin2)
					     {
					goto L520;
				    }
/* L550: */
				}
			    }
			}

/* .... STORE IN INTERFERENCE TABLE */

			++nhit;
			++interf_1.npintr;
			interf_1.uintr[interf_1.npintr - 1] = upen;
			interf_1.vintr[interf_1.npintr - 1] = vpen;
			interf_1.pintr[interf_1.npintr - 1] = *npatch;
			interf_1.dintr[interf_1.npintr - 1] = penmax;
			interf_1.iseg[interf_1.npintr - 1] = ipen;
			for (j = 1; j <= 3; ++j) {
			    interf_1.spintr[j + interf_1.npintr * 3 - 4] = 
				    ppoint[j - 1];
			    interf_1.tpintr[j + interf_1.npintr * 3 - 4] = 
				    tpoint[j - 1];
			    interf_1.snintr[j + interf_1.npintr * 3 - 4] = 
				    pnorm[j - 1];
/* L515: */
			}

		    }

		}

L520:
		;
	    }

	}
    } else {
/* .... PATCH CONVEX OR PSEUDO CONVEX */
	iflag = 0;
    }
    return 0;
} /* curint_ */

