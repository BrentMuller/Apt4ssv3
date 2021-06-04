/* MIXAL.f -- translated by f2c (version 20100827).
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
    integer ibug, ipcolc, ipcolm;
} ibugg_;

#define ibugg_1 ibugg_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c_n3 = -3;
static integer c__9 = 9;
static integer c__11 = 11;
static integer c__13 = 13;
static integer c__6 = 6;

/* *** SOURCE FILE : MIXAL.ORG   *** */

/* Subroutine */ int mixal_(integer *npatch, integer *isize, doublereal *geo, 
	doublereal *pside, doublereal *pthick, doublereal *tul, doublereal *
	toolce, doublereal *ta, doublereal *u, doublereal *v, doublereal *
	dumin, doublereal *dvmin, doublereal *upen, doublereal *vpen, 
	doublereal *ppoint, doublereal *tpoint, doublereal *pnorm, doublereal 
	*penmax, integer *ipen, integer *iflag, integer *iedge, integer *
	nitera)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal p[3], r__[3], t[3], ca, du, dv;
    static integer it;
    static doublereal pn[3], rn[3], tn[12]	/* was [3][4] */, sp[12]	
	    /* was [3][4] */, tp[12]	/* was [3][4] */, up[4], vp[4], ru[3],
	     rv[3], du1, dv1, du2, dv2;
    extern /* Subroutine */ int bad_();
    static logical iok;
    static doublereal pen[4];
    static char msg[120];
    static doublereal ruu[3], ruv[3], rvv[3];
    static integer iedg[4], mode, iold, jpen[4];
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal ucon, vcon;
    static integer iext;
    extern /* Subroutine */ int algo1_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *), 
	    algo2_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, logical *)
	    ;
    static doublereal difca;
    static logical lbase;
    extern /* Subroutine */ int calct_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    logical *);
    static integer iedgp, ialgo;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), fconv_(doublereal *, char *, integer *, integer *
	    , integer *, ftnlen), jmplt2_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), evalss_(integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *), pencut_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), cprint_(char *, ftnlen);
    static doublereal prevdu, prevdv;
    static integer normok;
    static doublereal ustart, vstart;


/*     PURPOSE: INTERFERENCE SEARCH USING MIXED ALGORITHMS */

/*     METHOD: */

/*     FOR INITIAL ESTIMATE U, V ON PATCH NPATCH */
/*     EVALUATES SURFACE POINT R, DERIVATIVES, AND NORMAL AT U,V */
/*     CALCULATES POINT T ON TOOL WITH SAME NORMAL */
/*     CALCULATES ASSOCIATED POINT P ON TOOL, AND TOOL NORMAL PN AT P */
/*     ESTIMATES DU,DV TO GIVE A BETTER ESTIMATE OF PENETRATION POINT */
/*     USING VALUES COMPUTED BY BOTH ALGO1 (DU1,DV1) AND ALGO2 (DU2,DV2) */
/*     WHERE POSSIBLE OTHERWISE RESULTS OF EITHER ALGO1 OR ALGO2 ARE USED */

/*          DU1*DU2             DV1*DV2 */
/*     DU = -------        DV = ------- */
/*          DU1+DU2             DV1+DV2 */

/*     ARGUMENTS: */
/*         ISIZE  - DIMENSION OF GEO */
/*         PSIDE  - TOOL SIDE OF SURFACE */
/*         PTHICK - THICK ALLOWANCE REQUIRED */
/*         TUL    - TOOL GEOMETRY */



/*     LOCAL VARIABLES : */

/* .... TOOL NORMAL AT P */
/* .... WORKSPACE */


/* .... STORAGE FOR DATA FROM LAST FOUR ITERATIONS IF CONVERGENCE */
/*     NOT ACHIEVED BY NITLIM */


/*     RETURNS:- */
/* .... MAXIMUM PENETRATION FOUND, FOR UPEN, VPEN */
/*     MAY NOT BE FINAL POINT IN ITERATION, BUT IS FOR TRUE (EVALUATED, N */
/*     EXTRAPOLATED) SURFACE POINT */
/* .... CORRESPONDING TOOL POINT */
/* .... COMMON NORMAL AT PPOINT, TPOINT */

/*     PENMAX      PENETRATION (+VE FOR HIT) */

/*     IFLAG = -1  NO CONVERGENCE */
/*              0  CONVERGENCE */

/*     IPEN  =  0  CONVERGENCE ON BOTTOM FLAT OF CRC */
/*              1  CONVERGENCE ON SPHERE FOR BE CUTTER, ON CR FOR CRC */
/*              2  CONVERGENCE ON SHANK */

/*     IEDGE =  0  LAST DU, DV NOT LIMITED */
/*              1  LAST DU,DV LIMITED */




/* .... DEBUG FLAGS */



    /* Parameter adjustments */
    --geo;
    --tul;
    --toolce;
    --ta;
    --ppoint;
    --tpoint;
    --pnorm;

    /* Function Body */
    ucon = 1.;
    vcon = 1.;
    ialgo = 0;
    ustart = *u;
    vstart = *v;

    *iflag = 0;
/* .... 1ST AND 2ND DERIVATIVES FROM EVALUATOR */
    mode = 2;
/* .... ITERATION COUNT */
    *nitera = 0;
    iext = 0;
    du = 0.;
    dv = 0.;
    *penmax = -1e6f;
/* .... LOOP START */
L10:
    ++(*nitera);

    iold = ialgo;
    prevdu = du;
    prevdv = dv;
    ialgo = 0;
    iok = TRUE_;

    evalss_(npatch, u, v, isize, &geo[1], &mode, r__, ru, rv, ruu, ruv, rvv, 
	    rn, &normok);

    pencut_(r__, rn, &toolce[1], &ta[1], &tul[1], pside, pthick, p, pn, 
	    penmax, ipen);

/* .... CALCULATE POINT T ON TOOL CORRESPONDING TO SURFACE NORMAL RN */

    calct_(&tul[1], &toolce[1], &ta[1], r__, rn, pside, t, &lbase);
    if (lbase) {
/* .... T ON BASE FLAT OF TOOL - FORCE ALGORITHM 2 WHERE POSSIBLE */
	ialgo = 2;
    }

/* .... ESTIMATE DU AND DV USING ALGORITHM 1 */

    algo1_(t, r__, rn, ru, rv, &du1, &dv1);

/* .... ESTIMATE DU AND DV USING ALGORITHM 2 */

    algo2_(pn, ru, rv, ruu, ruv, rvv, &du2, &dv2, &iok);
    if (! iok) {
/* .... UNABLE TO COMPUTE DU,DV USING ALGORITHM 2, FORCE USE OF DU1,DV1 */

	ialgo = 1;
    }

/* .... SELECT DU,DV */

    if (ialgo == 1) {
	du = du1;
	dv = dv1;
    } else if (ialgo == 2) {
	du = du2;
	dv = dv2;
    } else {
/* .... MIX ALGORITHMS */
	if ((d__1 = du1 + du2, abs(d__1)) <= 1e-6 || abs(du2) <= 1e-6) {
	    du = du1;
	} else if (abs(du1) <= 1e-6) {
	    du = du2;
	} else {
	    du = du1 * du2 / (du1 + du2);
	}
	if ((d__1 = dv1 + dv2, abs(d__1)) <= 1e-6 || abs(dv2) <= 1e-6) {
	    dv = dv1;
	} else if (abs(dv1) <= 1e-6) {
	    dv = dv2;
	} else {
	    dv = dv1 * dv2 / (dv1 + dv2);
	}
    }

/* .... SAVE PREVIOUS SETTING OF IEDGE BEFORE CALLING JMPLT2 */
    iedgp = *iedge;

    jmplt2_(u, v, &du, &dv, iedge);

/* .... COMPUTE COSINE OF ANGLE BETWEEN TOOL AND SURFACE NORMALS */

    dotf_(&ca, pn, rn);
    difca = 1. - *pside * ca;

    if (abs(du) < *dumin && abs(dv) < *dvmin || difca < 1e-8) {
/* .... CONVERGENCE */
    } else {
	if (*nitera >= 20) {
/* .... NO CONVERGENCE AFTER NITLIM ITERATIONS */
/*     CARRY OUT THREE MORE ITERATIONS AND INTERROGATE PENETRATION VALUES */
	    if (*nitera <= 23) {
		++iext;
/* .... SAVE VALUES FOR SUBSEQUENT INTERROGATION */
		for (i__ = 1; i__ <= 3; ++i__) {
		    sp[i__ + iext * 3 - 4] = r__[i__ - 1];
		    tp[i__ + iext * 3 - 4] = p[i__ - 1];
		    tn[i__ + iext * 3 - 4] = pn[i__ - 1];
/* L12: */
		}
		up[iext - 1] = *u;
		vp[iext - 1] = *v;
		pen[iext - 1] = *penmax;
		jpen[iext - 1] = *ipen;
		iedg[iext - 1] = iedgp;
		if (*nitera < 23) {
/* .... TRY AGAIN */
		    *u += du;
		    *v += dv;
		    goto L10;
		} else {
		    if (ibugg_1.ibug == 11) {

/* .... DEBUG PRINT */

			bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
			s_copy(msg, " NO CONVERGENCE IN MIXAL - LAST FOUR IT"
				"ERATIONS", (ftnlen)120, (ftnlen)47);
			cprint_(msg, (ftnlen)120);
			for (i__ = 1; i__ <= 4; ++i__) {
			    bad_(&c__1, &c__0, "IEXT", &i__, (ftnlen)4);
			    bad_(&c__1, &c__1, "UP  ", &up[i__ - 1], (ftnlen)
				    4);
			    bad_(&c__1, &c__1, "VP  ", &vp[i__ - 1], (ftnlen)
				    4);
			    bad_(&c__1, &c__1, "PEN ", &pen[i__ - 1], (ftnlen)
				    4);
			    bad_(&c__1, &c__0, "JPEN", &jpen[i__ - 1], (
				    ftnlen)4);
			    bad_(&c_n1, &c__0, "IEDG", &iedg[i__ - 1], (
				    ftnlen)4);
			    bad_(&c__3, &c__1, "SP  ", &sp[i__ * 3 - 3], (
				    ftnlen)4);
			    bad_(&c__3, &c__1, "TP  ", &tp[i__ * 3 - 3], (
				    ftnlen)4);
			    bad_(&c_n3, &c__1, "TN  ", &tn[i__ * 3 - 3], (
				    ftnlen)4);
/* L13: */
			}
		    }
/* .... THREE MORE ITERATIONS COMPLETED - INTERROGATE PENETRATIONS */
		    it = 1;
		    *penmax = pen[it - 1];
		    for (i__ = 2; i__ <= 4; ++i__) {
			if (pen[i__ - 1] > *penmax) {
			    *penmax = pen[i__ - 1];
			    it = i__;
			}
/* L14: */
		    }
/* .... RETURN WORST CASE (I.E. LARGEST PENETRATION) */
		    for (i__ = 1; i__ <= 3; ++i__) {
			r__[i__ - 1] = sp[i__ + it * 3 - 4];
			p[i__ - 1] = tp[i__ + it * 3 - 4];
			pn[i__ - 1] = tn[i__ + it * 3 - 4];
/* L16: */
		    }
		    *u = up[it - 1];
		    *v = vp[it - 1];
		    *ipen = jpen[it - 1];
		    *iedge = iedg[it - 1];

		    if (*penmax > 0.) {
/* .... PENETRATION WITHOUT CONVERGENCE */
			*iflag = -1;
			s_copy(msg, "0PENETRATION DETECTED WITHOUT CONVERGEN"
				"CE", (ftnlen)120, (ftnlen)41);
			cprint_(msg, (ftnlen)120);
			cform_(" PENMAX =", msg, &c__1, &c__9, (ftnlen)9, (
				ftnlen)120);
			fconv_(penmax, msg, &c__11, &c__13, &c__6, (ftnlen)
				120);
			cprint_(msg, (ftnlen)120);
		    } else {
/* .... NO CONVERGENCE AND NO OBSERVED PENETRATION */
			*iflag = 0;
		    }
		}
	    }
	} else {
/* .... TRY AGAIN */
	    *u += du;
	    *v += dv;
	    goto L10;
	}

    }

/* .... STORE SURFACE POINT, TOOL POINT AND NORMAL AT CONVERGENCE */
/*     OR FINAL ATTEMPT AT CONVERGENCE */
    for (i__ = 1; i__ <= 3; ++i__) {
	ppoint[i__] = r__[i__ - 1];
	tpoint[i__] = p[i__ - 1];
	pnorm[i__] = pn[i__ - 1];
/* L20: */
    }
/* ... STORE U,V OF SURFACE POINT */
    *upen = *u;
    *vpen = *v;

    return 0;
} /* mixal_ */

