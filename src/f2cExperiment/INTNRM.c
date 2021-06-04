/* INTNRM.f -- translated by f2c (version 20100827).
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
    doublereal bb[256]	/* was [64][4] */, uu[4], vv[4];
    integer iitop[96]	/* was [6][4][4] */, iiflag[16]	/* was [4][4] */, 
	    ipnum[4];
} ssarlm_;

#define ssarlm_1 ssarlm_

struct {
    integer ikeep[255];
} intcom_;

#define intcom_1 intcom_

/* Table of constant values */

static integer c__0 = 0;
static integer c__2 = 2;

/* *** SOURCE FILE : M0012323.V01   *** */

/* Subroutine */ int intnrm_(integer *ns, doublereal *u, doublereal *v, 
	doublereal *pta, doublereal *spva, integer *irc)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;
    static doublereal equiv_4[32];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k;
    static doublereal d1, d2, u1, v1, u2, v2, cs, du, dv, dx, dy, ui, vi, dz, 
	    ou, ov, us, vs;
#define xu (equiv_4 + 4)
#define xv (equiv_4 + 8)
    static doublereal dd1, dd2, ux0, vx0, den, det, cos__, dsq, fuv, guv, rtu,
	     rtv, usv, vsv;
#define xuu (equiv_4 + 12)
#define xuv (equiv_4 + 16)
#define xvv (equiv_4 + 20)
    static doublereal dfdu, dfdv, dgdu, dgdv, delu, delv, secu, secv, dtol;
    static integer ntim;
    static doublereal umin, vmin;
#define spvi (equiv_4)
    static doublereal rnum, utol, vtol, ulim0, ulim1, vlim0, vlim1;
    static integer iscan;
    static doublereal odelu, odelv, dumin, dvmin, uvinc, dsqmin;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
    static doublereal tuvinc;


/*     INTNRM COMPUTES THE POINT  ON A SURFACE FROM WHICH A SURFACE */
/*     NORMAL PASSES THRU POINT 'PTA'. THE UV VALUES ARE USED FOR A */
/*     CLOSE APPROXIMATION ON INPUT AND ARE ADJUSTED TO THE ACTUAL */
/*     UV OF SURFACE ON OUTPUT. */



/* SS - ARELEM - COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/* CCCC EQUIVALENCE (IKEEP(249),ITRACE) */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* CCCC IF(ITRACE.EQ.1) */
/* CCCC*WRITE(6,1000) */
/* 1000 FORMAT(' ***TRACE***INTNRM') */
    /* Parameter adjustments */
    spva -= 5;
    --pta;

    /* Function Body */
    *irc = 0;
    dtol = 1e-12;
    ui = *u;
    vi = *v;

    iscan = 0;
    ntim = 0;
    goto L25;

/* SCAN ENTIRE SURFACE FOR GLOBAL MIN. DIST. POINT */
/* ----------------------------------------------- */
L15:
    iscan = 1;
    d1 = 9e31;
    u1 = .5;
    v1 = .5;
    tuvinc = 1.;
    for (k = 1; k <= 3; ++k) {
	tuvinc /= 10.;
	uvinc = tuvinc;
	if (k > 1) {
	    uvinc *= 2.;
	}
	us = u1 - uvinc * 5.;
	vs = v1 - uvinc * 5.;
	for (i__ = 1; i__ <= 11; ++i__) {
	    *v = vs + uvinc * (i__ - 1);
	    for (j = 1; j <= 11; ++j) {
		*u = us + uvinc * (j - 1);
		cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], &spva[5], &
			ssarlm_1.iiflag[(*ns << 2) - 4], &c__0);
/* Computing 2nd power */
		d__1 = spva[5] - pta[1];
/* Computing 2nd power */
		d__2 = spva[6] - pta[2];
/* Computing 2nd power */
		d__3 = spva[7] - pta[3];
		d2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		if (d2 >= d1) {
		    goto L320;
		}
		d1 = d2;
		u1 = *u;
		v1 = *v;
L320:
/* L330: */
		;
	    }
/* L340: */
	}
/* L350: */
    }
    *u = u1;
    *v = v1;

/* ALLOW ONLY UNIT SQUARE UV */
L25:
    if (*u < 0.) {
	*u = 0.;
    }
    if (*v < 0.) {
	*v = 0.;
    }
    if (*u > 1.) {
	*u = 1.;
    }
    if (*v > 1.) {
	*v = 1.;
    }
/* SAVE BEST SOLN FOR RESET */
    dsqmin = 999.;
    umin = *u;
    vmin = *v;
    ulim0 = 0.;
    ulim1 = 1.;
    vlim0 = 0.;
    vlim1 = 1.;
    ux0 = 0.;
    vx0 = 0.;
    dumin = 1.;
    dvmin = 1.;

/* ITERATE (31 TIMES MAX.) TO FIND LOCAL MIN. DIST PTA */
/* --------------------------------------------------- */
    for (i__ = 1; i__ <= 31; ++i__) {
	++ntim;
	usv = *u;
	vsv = *v;
	if (i__ < 11) {
	    goto L440;
	}

/* FIRST TIME HERE, DO DIAGONAL MINI-SEARCH FOR BEST SOLN */
	if (i__ != 11) {
	    goto L430;
	}
	d1 = 9e31;
	*u = ux0;
	du = dumin / 10.;
	*v = vx0;
	dv = dvmin / 10.;
	for (k = 1; k <= 2; ++k) {
	    for (j = 1; j <= 9; ++j) {
		*u += du;
		*v += dv;
		cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], &spva[5], &
			ssarlm_1.iiflag[(*ns << 2) - 4], &c__0);
/* Computing 2nd power */
		d__1 = spva[5] - pta[1];
/* Computing 2nd power */
		d__2 = spva[6] - pta[2];
/* Computing 2nd power */
		d__3 = spva[7] - pta[3];
		d2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		if (d2 >= d1) {
		    goto L400;
		}
		d1 = d2;
		ui = *u;
		vi = *v;
L400:
/* L410: */
		;
	    }
/* SEARCH OPPOSITE DIAGONAL */
	    *u = ux0;
	    *v += dv;
	    dv = -dv;
/* L420: */
	}
	*u = ui;
	*v = vi;
L430:

/* IF HERE, USE NEWTON'S METHOD */
/* ---------------------------- */
/*  COMPUTE POINT, 1ST & 2ND DERIVATIVES */
	cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], spvi, &ssarlm_1.iiflag[(*
		ns << 2) - 4], &c__2);
	dx = pta[1] - spvi[0];
	dy = pta[2] - spvi[1];
	dz = pta[3] - spvi[2];
/* SOLVE FOR F(U,V) & G(U,V) = 0 *** */
	fuv = dx * xu[0] + dy * xu[1] + dz * xu[2];
	guv = dx * xv[0] + dy * xv[1] + dz * xv[2];
/* CONVERGENCE ? */
	if (abs(fuv) < dtol && abs(guv) < dtol) {
	    goto L110;
	}
/* EVALUATE PARTIALS OF F & G */
/* Computing 2nd power */
	d__1 = xu[0];
/* Computing 2nd power */
	d__2 = xu[1];
/* Computing 2nd power */
	d__3 = xu[2];
	dfdu = dx * xuu[0] + dy * xuu[1] + dz * xuu[2] - (d__1 * d__1 + d__2 *
		 d__2 + d__3 * d__3);
	dfdv = dx * xuv[0] + dy * xuv[1] + dz * xuv[2] - (xu[0] * xv[0] + xu[
		1] * xv[1] + xu[2] * xv[2]);
	dgdu = dfdv;
/* Computing 2nd power */
	d__1 = xv[0];
/* Computing 2nd power */
	d__2 = xv[1];
/* Computing 2nd power */
	d__3 = xv[2];
	dgdv = dx * xvv[0] + dy * xvv[1] + dz * xvv[2] - (d__1 * d__1 + d__2 *
		 d__2 + d__3 * d__3);
	det = dfdu * dgdv - dfdv * dgdu;
/* COMPUTE CORRECTIONS TO U & V */
	delu = -(dgdv * fuv - dfdv * guv) / det;
	delv = -(dfdu * guv - dgdu * fuv) / det;
/* SAVE UPPER & LOWER BOUNDS ON U & V */
	if (delu > 0.) {
	    ulim0 = max(ulim0,*u);
	}
	if (delu > 0.) {
	    ulim1 = max(ulim1,*u);
	}
	if (delv > 0.) {
	    vlim0 = max(vlim0,*v);
	}
	if (delv > 0.) {
	    vlim1 = max(vlim1,*v);
	}
	if (delu < 0.) {
	    ulim1 = min(ulim1,*u);
	}
	if (delu < 0.) {
	    ulim0 = min(ulim0,*u);
	}
	if (delv < 0.) {
	    vlim1 = min(vlim1,*v);
	}
	if (delv < 0.) {
	    vlim0 = min(vlim0,*v);
	}
	goto L490;
L440:

/* 1ST 11 TIMES USE  PLANE CONVERGENCE APPROACH */
/* -------------------------------------------- */
	cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], spvi, &ssarlm_1.iiflag[(*
		ns << 2) - 4], &c__2);

/* GET LENGTH OF PARTIALS */
/* Computing 2nd power */
	d__1 = xu[0];
/* Computing 2nd power */
	d__2 = xu[1];
/* Computing 2nd power */
	d__3 = xu[2];
	secu = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* Computing 2nd power */
	d__1 = xv[0];
/* Computing 2nd power */
	d__2 = xv[1];
/* Computing 2nd power */
	d__3 = xv[2];
	secv = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);

	dx = pta[1] - spvi[0];
	dy = pta[2] - spvi[1];
	dz = pta[3] - spvi[2];
	d1 = (xu[0] * dx + xu[1] * dy + xu[2] * dz) / secu;
	d2 = (xv[0] * dx + xv[1] * dy + xv[2] * dz) / secv;

/* CAL. COS-1 BETWEEN PARTIALS */
	cos__ = (xu[0] * xv[0] + xu[1] * xv[1] + xu[2] * xv[2]) / (secu * 
		secv);
	cs = 1. - cos__ * cos__;
	if (cs < 1e-20) {
	    cs = 1e-20;
	}

	delu = (d1 - d2 * cos__) / cs;
	if (abs(delu) < 1e-20) {
	    delu = 1e-20;
	}
	dsq = sqrt(delu * delu * cs + d2 * d2);

/* IF DISTANCE IS LT 1.D-12; EXIT */
	if (dsq < dtol) {
	    goto L110;
	}
/* SAVE BEST SOLN FOR RESET */
	if (dsq >= dsqmin) {
	    goto L450;
	}
	dsqmin = dsq;
	umin = *u;
	vmin = *v;
L450:

/* RECALCULATE U & V */
/* ----------------- */
	delv = (d2 - delu * cos__) / secv;
	delu /= secu;
/* SAVE MIN. OSCILLATION DIST. *** */
	if (i__ == 1) {
	    goto L480;
	}
	if (odelu * delu >= 0. || (d__1 = *u - ou, abs(d__1)) >= abs(dumin)) {
	    goto L460;
	}
	ux0 = ou;
	dumin = *u - ou;
L460:
	if (odelv * delv >= 0. || (d__1 = *v - ov, abs(d__1)) >= abs(dvmin)) {
	    goto L470;
	}
	vx0 = ov;
	dvmin = *v - ov;
L470:
L480:
L490:
	if (abs(delu) > .25) {
	    delu = delu * .25 / abs(delu);
	}
	if (abs(delv) > .25) {
	    delv = delv * .25 / abs(delv);
	}
	du = delu;
	dv = delv;
	if (i__ == 1 || i__ == 11) {
	    goto L540;
	}
/* AITKEN DEL SQUARE ALGORITHM --------------------------- */
/*  USE SECANT TO EXTRAPOLATE/INTERPOLATE NEXT U & V */
	den = odelu - delu;
	if (abs(den) <= 1e-20) {
	    goto L510;
	}
	rnum = *u - ou;
	if (abs(rnum) <= 1e-20) {
	    goto L500;
	}
	rtu = rnum / den;
	if (rtu > 1e-12) {
	    du = delu * rtu;
	}
	if (odelu * delu < 0.) {
	    du *= .67;
	}
L500:
L510:

/* CAL. NEW V */
	den = odelv - delv;
	if (abs(den) <= 1e-20) {
	    goto L530;
	}
	rnum = *v - ov;
	if (abs(rnum) <= 1e-20) {
	    goto L520;
	}
	rtv = rnum / den;
	if (rtv > 1e-12) {
	    dv = delv * rtv;
	}
	if (odelv * delv < 0.) {
	    dv *= .67;
	}
L520:
L530:
L540:

/* UPDATE U & V AND LOOP BACK  --------------------------------- */
	ou = *u;
	*u += du;
	u2 = ou + delu;
	odelu = delu;
	ov = *v;
	*v += dv;
	v2 = ov + delv;
	odelv = delv;

/* KEEP U & V WITHIN LIMITS ------------------------------------ */
	if (*u < 0.) {
	    *u = 0.;
	}
	if (*v < 0.) {
	    *v = 0.;
	}
	if (*u > 1.) {
	    *u = 1.;
	}
	if (*v > 1.) {
	    *v = 1.;
	}
	if (u2 < 0.) {
	    u2 = 0.;
	}
	if (v2 < 0.) {
	    v2 = 0.;
	}
	if (u2 > 1.) {
	    u2 = 1.;
	}
	if (v2 > 1.) {
	    v2 = 1.;
	}

/* CONVERGENCE ? */
	if ((d__1 = *u - usv, abs(d__1)) < 1e-10 && (d__2 = *v - vsv, abs(
		d__2)) < 1e-10) {
	    goto L110;
	}

/*    NO CHANGE IN U OR V, USE THIS POINT NORMAL */
/* WHICH IS BETTER, (U,V) OR (U2,V2) ? */
	cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], spvi, &ssarlm_1.iiflag[(*
		ns << 2) - 4], &c__0);
/* Computing 2nd power */
	d__1 = pta[1] - spvi[0];
/* Computing 2nd power */
	d__2 = pta[2] - spvi[1];
/* Computing 2nd power */
	d__3 = pta[3] - spvi[2];
	dd1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	cnsurf_(&u2, &v2, &ssarlm_1.bb[(*ns << 6) - 64], spvi, &
		ssarlm_1.iiflag[(*ns << 2) - 4], &c__0);
/* Computing 2nd power */
	d__1 = pta[1] - spvi[0];
/* Computing 2nd power */
	d__2 = pta[2] - spvi[1];
/* Computing 2nd power */
	d__3 = pta[3] - spvi[2];
	dd2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	if (dd2 >= dd1) {
	    goto L550;
	}
	*u = u2;
	*v = v2;
L550:
/* L600: */
	;
    }

/* END OF LOOP WITH NO SOL., SCAN ENTIRE SURFACE */
    if (iscan == 0) {
	goto L15;
    }

/* IF U OR V ON OR BEYOND SURFACE BOUNDARY AND THE ENTRY POINT */
/*  DROPPED TO THE SURFACE IS OUT OF BOUNDS BY MORE THAN 1.D-4, */
/*  GENERATE A NEGATIVE RETURN CODE TO INITIATE ENDUP. */
/*  EVALUATE POINT, AND DERIVATIVES ---------------------------------- */
L110:
    cnsurf_(u, v, &ssarlm_1.bb[(*ns << 6) - 64], &spva[5], &ssarlm_1.iiflag[(*
	    ns << 2) - 4], &c__2);
    utol = 1e-4;
    vtol = utol;
    if ((d__1 = *u - .5, abs(d__1)) >= .5 && abs(d1) > utol) {
	*irc = -1;
    }
    if ((d__1 = *v - .5, abs(d__1)) >= .5 && abs(d2) > vtol) {
	*irc = -1;
    }

/* L999: */
    return 0;
} /* intnrm_ */

#undef spvi
#undef xvv
#undef xuv
#undef xuu
#undef xv
#undef xu


