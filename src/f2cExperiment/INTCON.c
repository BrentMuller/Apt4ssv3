/* INTCON.f -- translated by f2c (version 20100827).
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

static integer c__2 = 2;
static integer c__1 = 1;

/* *** SOURCE FILE : M0004614.V01   *** */

/* Subroutine */ int intcon_(doublereal *pt, integer *npt, integer *ks)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal d1, d2, d3;
#define ck ((doublereal *)&intcom_1 + 120)
    static doublereal co, cs, pl[4], dx, dy, dz, hx, hy;
#define un ((doublereal *)&intcom_1 + 82)
    static doublereal hz, si;
#define uv ((doublereal *)&intcom_1 + 64)
    static doublereal dx1, dy1, dz1, pt0[3], fac, cal, hco, sec, sal, orc;
#define ctp ((doublereal *)&intcom_1 + 116)
#define dtp ((doublereal *)&intcom_1 + 108)
    static doublereal oya, oyb, oyc;
    static integer ipt;
#define ptp ((doublereal *)&intcom_1 + 112)
    static doublereal radc, rfac;
    static integer ipar;
    static doublereal dist;
#define ipnr ((integer *)&intcom_1 + 253)
#define step ((doublereal *)&intcom_1 + 122)
#define npts ((integer *)&intcom_1 + 250)
#define oxyz ((doublereal *)&intcom_1 + 105)
#define pxyz ((doublereal *)&intcom_1 + 102)
    static doublereal step2, calsq;
#define isfer ((integer *)&intcom_1 + 251)
    static integer iptck, icont;
    static logical lskip;
    static doublereal hstep;
    static integer ndrop;
    static doublereal odist;
#define ostep ((doublereal *)&intcom_1 + 123)
    static doublereal stmin;
    static logical lplane;
    extern /* Subroutine */ int intbnd_(integer *, integer *);
    static integer nbound, istate;
    static doublereal curvck, rcnext;
#define iptknt ((integer *)&intcom_1 + 249)
    extern /* Subroutine */ int inttpl_(integer *, doublereal *, doublereal *,
	     integer *);
#define stepmx ((doublereal *)&intcom_1 + 121)
    static integer istout;



/* SS - ARELEM - COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/*   LAST THREE U,V PAIRS OF PS AND DS */
/*   HISTORY OF UNIT NORMALS AT INTERSECTION POINTS ON PS AND DS */
/*   POINT OF INTERSECTION */
/*   OLD POINT OF INTERSECTION */
/*   DS TANGENT PLANE */
/*   PS TANGENT PLANE */
/*   PLANE PERPENTICULAR TO INTERSECTION DIRECTION */
/*   8 TIMES ABSOLUTE TOLERANCE */
/*   MAXIMUM STEP */
/*   STEP LENGTH */
/*   OLD STEP LENGTH */
/*   TRACE */
/* CCCC EQUIVALENCE (IKEEP(249),ITRACE) */
/*   INTERNAL POINT COUNT */
/*   MAXIMUM NUMBER OF POINTS */
/*   OUT OF BOUND SIGNAL FOR PS AND DS */
/*   PATCH NUMBER FOR PS AND DS (SURFACE RECNO*1000 + PATCH NO) */


/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* INITIAL STARTUP INFO. */

/* CCCC IF(ITRACE.EQ.1) */
/* CCCC*WRITE(6,1000)KS,PXYZ */
/* 1000 FORMAT(' ***TRACE***INTCON-KS,START PXYZ=',I5,3G12.5) */
    /* Parameter adjustments */
    pt -= 10;

    /* Function Body */
    istate = 1;
    nbound = 0;
    ipt = 1;
    *npt = 0;
    *iptknt = *npts;
    iptck = *iptknt - 2;
    hstep = *stepmx;
/* MAX. STEP = .25 FOR FIRST TWO POINTS: */
    *stepmx = 6.3499999999999996;
    stmin = .254;
    if (*stepmx != 0.) {
	goto L50;
    }
    *stepmx = .25;
    stmin = .25;
L50:

/* SAVE INITIAL TANGENT FOR DETECTING LOOPAROUND TO START: */
    pl[0] = ctp[0];
    pl[1] = ctp[1];
    pl[2] = ctp[2];
    pl[3] = ctp[0] * pxyz[0] + ctp[1] * pxyz[1] + ctp[2] * pxyz[2];
    icont = 1;
    ndrop = -3;
    *step = 0.;
    *ostep = *step;
    radc = 2e3;
    dx = 0.;
    dy = 0.;
    dz = 0.;
    istout = 0;
    curvck = *ck * 2.;
    dist = 0.;
    lplane = FALSE_;
/* IS S1 A PLANE? */
    if (ssarlm_1.iiflag[4] <= 0) {
	lplane = TRUE_;
    }

/* PROCEED TO NEXT POINT; SAVE ALL CURRENT POSITIONS */
L100:
/* HISTORY OF UNIT NORMAL "UN": */
    for (i__ = 1; i__ <= 3; ++i__) {
	un[i__ + 5] = un[i__ + 2];
	un[i__ + 14] = un[i__ + 11];
	un[i__ + 2] = un[i__ - 1];
	un[i__ + 11] = un[i__ + 8];
/* L110: */
    }
/* PREVIOUS TANGENT YABC & PREVIOUS INTERSECTION PT. PXYZ: */
    oya = ctp[0];
    oyb = ctp[1];
    oyc = ctp[2];
    oxyz[0] = pxyz[0];
    oxyz[1] = pxyz[1];
    oxyz[2] = pxyz[2];
/* DISTANCE ALONG INTERSECTION: */
    odist = dist;
/* SHIFT U,V PARAMETERS FOR BOTH SURFACES WITHIN THE HISTORY TABLE */
/*  (LATEST U,V ARE STORED BY INTTPL): */
    for (i__ = 1; i__ <= 2; ++i__) {
/* STACK U HISTORY: */
	uv[(i__ * 3 + 3 << 1) - 8] = uv[(i__ * 3 + 2 << 1) - 8];
	uv[(i__ * 3 + 2 << 1) - 8] = uv[(i__ * 3 + 1 << 1) - 8];
/* STACK V HISTORY: */
	uv[(i__ * 3 + 3 << 1) - 7] = uv[(i__ * 3 + 2 << 1) - 7];
/* L114: */
	uv[(i__ * 3 + 2 << 1) - 7] = uv[(i__ * 3 + 1 << 1) - 7];
    }
    isfer[0] = 0;
    isfer[1] = 0;
/* AFTER FIRST TWO PTS. RESTORE MAX. STEP TO INPUT VALUE: */
    if (iptck == *iptknt) {
	*stepmx = hstep;
    }
/* DECREMENT POINT COUNTDOWN COUNTER: */
    --(*iptknt);
    if (*iptknt <= 0) {
	goto L920;
    }
/* IPAR = COUNTER OF RETRIES WHEN TANGENT PLANES ARE PARALLEL */
    ipar = 0;
    lskip = FALSE_;

/* CONTINUE ITERATING TO FIND A POINT: */
L120:

/*  EXTRAPOLATE NEXT POINT */
/*  ---------------------- */
    hx = oxyz[0] + *step * oya;
    hy = oxyz[1] + *step * oyb;
    hz = oxyz[2] + *step * oyc;
    pxyz[0] = hx + dx;
    pxyz[1] = hy + dy;
    pxyz[2] = hz + dz;

L125:

/* COMPUTE TANGENT PLANES */
/* ---------------------- */
/*  COMPUTE SCALED DISTANCE ALONG INTERSECTION: */
/* Computing 2nd power */
    d__1 = pxyz[0] - oxyz[0];
/* Computing 2nd power */
    d__2 = pxyz[1] - oxyz[1];
/* Computing 2nd power */
    d__3 = pxyz[2] - oxyz[2];
    dist = odist + sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* COMPUTE PLANE DTP, TANGENT TO DS */
    inttpl_(&c__2, pxyz, dtp, &isfer[1]);
/* COMPUTE PLANE PTP, TANGENT TO PS */
    inttpl_(&c__1, pxyz, ptp, isfer);

/* SAL = COS OF ANGLE BETWEEN PLANES: */
    sal = ptp[0] * dtp[0] + ptp[1] * dtp[1] + ptp[2] * dtp[2];
    calsq = 1. - sal * sal;

/* ARE THE SURFACES PARALLEL? */
    if (calsq > 1e-20) {
	goto L260;
    }
/*   ON FIRST PT., TRY ANYWAY: */
    if (*ks < 0) {
	goto L240;
    }
/* TANGENT PLANES ARE PARALLEL; INCREASE STEP SIZE: */
    *step *= 1.7;
    ++ipar;
/* DON'T REDUCE STEP SIZE: */
    if (istate == 5) {
	istate = 6;
    }
    if (ipar <= 2) {
	goto L120;
    }
    goto L920;
L240:
    calsq = 1e-20;
L260:
    cal = sqrt(calsq) * ctp[3];

/* DS UNIT NORMALS */
    un[9] = dtp[0];
    un[10] = dtp[1];
    un[11] = dtp[2];
/* PS UNIT NORMALS */
    un[0] = ptp[0];
    un[1] = ptp[1];
    un[2] = ptp[2];
/* COMPUTE UNIT TANGENT VECTOR YABC: */
    ctp[0] = (dtp[1] * ptp[2] - ptp[1] * dtp[2]) / cal;
    ctp[1] = (dtp[2] * ptp[0] - ptp[2] * dtp[0]) / cal;
    ctp[2] = (dtp[0] * ptp[1] - ptp[0] * dtp[1]) / cal;
/* HCO = COS OF ANGLE BETWEEN THIS TANGENT & PREVIOUS ONE: */
    hco = ctp[0] * oya + ctp[1] * oyb + ctp[2] * oyc;
/* MAKE SURE CTP HAS NOT REVERSED: */
    if (hco >= -.9) {
	goto L270;
    }
    ctp[0] = -ctp[0];
    ctp[1] = -ctp[1];
    ctp[2] = -ctp[2];
    ctp[3] = -ctp[3];
    hco = -hco;

/* PROJECT EXTRAPOLATED POINT ONTO INTERSECTION OF TANGENT PLANES: */
/* --------------------------------------------------------------- */
L270:
    d1 = (ptp[3] - sal * dtp[3]) / calsq;
    d2 = dtp[3] - sal * d1;
    d3 = ctp[0] * pxyz[0] + ctp[1] * pxyz[1] + ctp[2] * pxyz[2];
    pxyz[0] = ptp[0] * d1 + dtp[0] * d2 + ctp[0] * d3;
    pxyz[1] = ptp[1] * d1 + dtp[1] * d2 + ctp[1] * d3;
    pxyz[2] = ptp[2] * d1 + dtp[2] * d2 + ctp[2] * d3;

/* IF START UP (KS=-1), SAVE PT. & EXIT: */
    if (*ks < 0) {
	goto L540;
    }

/* TEST FOR BOUNDARY, IF APPROPRIATE: */
/* ---------------------------------- */
/* STILL WITHIN BOUNDS? */
/* L280: */
    if (isfer[0] == 0 && isfer[1] == 0) {
	goto L290;
    }
    if (istate == 8 || istate == 10) {
	goto L290;
    }
/* NO; CUT STEP SIZE AND TRY FOR MORE POINTS: */
    ++nbound;
    if (istate < 6 || istate == 9) {
	istate = 6;
    }
    ++istate;
    *step /= 10.;
    if (abs(*step) < stmin) {
	*step = stmin;
    }
    *ostep = *step;
    if (istate < 8) {
	goto L120;
    }
L290:

/* BRANCH TO THE STEP CONTROL LOGIC: */
/* --------------------------------- */
    switch (istate) {
	case 1:  goto L300;
	case 2:  goto L300;
	case 3:  goto L310;
	case 4:  goto L400;
	case 5:  goto L320;
	case 6:  goto L350;
	case 7:  goto L350;
	case 8:  goto L500;
	case 9:  goto L540;
	case 10:  goto L540;
    }
L300:
    *step = 0.;
    ++istate;
    goto L120;
L310:
    *step = stmin;
    istate = 4;
    goto L120;

/* DECREASE STEP SIZE UNLESS BEND IN INTERSECTION IS NEGLIGIBLE */
/*  AND TRY AGAIN WITH SAME POINT. */
/* ------------------------------- */
/*  CHECK CHORDAL TOLERANCE */
L320:
    ++ndrop;
    if (ndrop >= 0) {
	istate = 6;
    }
/* CHECK CURVATURE FIRST */
    co = abs(hco);
    if (co > .999999997) {
	goto L325;
    }
    si = sqrt(1. - co * co);
    fac = si * *step / curvck;
    if (co < .707) {
	fac = 100.;
    }
    goto L326;

/* IF HERE, RADC IS CLOSE TO BEING STRAIGHT LINE, CHECK DROP */
L325:
    d1 = pxyz[0] - oxyz[0];
    d2 = pxyz[1] - oxyz[1];
    d3 = pxyz[2] - oxyz[2];
    sec = sqrt(d1 * d1 + d2 * d2 + d3 * d3);
    if (sec == 0.) {
	sec = 1.;
    }
    d1 /= sec;
    d2 /= sec;
    d3 /= sec;
    co = (d__1 = d1 * oya + d2 * oyb + d3 * oyc, abs(d__1));
    if (co > .9999999) {
	goto L350;
    }
    si = sqrt(1. - co * co);
    fac = sec * si / *ck;
L326:
    if (fac < 1.1) {
	goto L350;
    }
/* SCALE DOWN STEP SIZE: */
    *step /= sqrt(fac);

/* LOAD OLD UV FOR STEP FIX POINT ON SURFACE */
    for (j = 1; j <= 2; ++j) {
	for (i__ = 1; i__ <= 3; i__ += 2) {
	    uv[(i__ + j * 3 << 1) - 8] = uv[(j * 3 + 2 << 1) - 8];
	    uv[(i__ + j * 3 << 1) - 7] = uv[(j * 3 + 2 << 1) - 7];
/* L340: */
	}
    }
    goto L120;

/* COMPUTE CORRECTION DX & STEP SIZE FOR NEXT POINT: */
/* ------------------------------------------------- */
L350:
    ndrop = -3;
/* IF NOT AT EDGE, ITERATE ON NEXT POINT: */
    if (istate == 6) {
	istate = 5;
    }
    dx = pxyz[0] - hx;
    dy = pxyz[1] - hy;
    dz = pxyz[2] - hz;

    if (istout != 0) {
	goto L400;
    }
    istout = 1;
    goto L120;

/* EXTRAPOLATE STEP SIZE FOR NEXT PXYZ */
/* ----------------------------------- */
L400:
/* Computing 2nd power */
    d__1 = ctp[0];
/* Computing 2nd power */
    d__2 = ctp[1];
/* Computing 2nd power */
    d__3 = ctp[2];
    if (d__1 * d__1 + d__2 * d__2 + d__3 * d__3 < 1e-10) {
	goto L920;
    }

    *ostep = abs(*step);
    if (nbound == 2) {
	goto L540;
    }
    orc = radc;
/* COMPUTE STEP SIZE: */
    d1 = 1. - hco * hco;
    if (d1 - 2e-9 <= 0.) {
	goto L410;
    } else {
	goto L420;
    }
/* USE MAXIMUM STEP SIZE: */
L410:
    *step = *stepmx;
    radc = 2e3;
    goto L430;
L420:
    si = sqrt(d1);

    if (*step > .001) {
	radc = (d__1 = *step / si, abs(d__1));
    }
    if (istate == 4) {
	orc = radc;
    }

/* EXTRAP ONLY WHEN ORC & RADC IS REASONABLE */
    rfac = orc / radc;
    if (rfac > 1.9 || rfac < .55) {
	orc = radc;
    }
    rcnext = radc * 2. - orc;
    if (rcnext < .015) {
	rcnext = .015;
    }
    *step = sqrt(*ck * 2. * rcnext);
    if (*step < .011) {
	*step = .011;
    }

/* IF RAD. CURV. SMALL, REDUCE DXYZ CORRECTIONS */
    if (radc > .1) {
	goto L430;
    }
    rfac = radc * 10.;
    dx *= rfac;
    dy *= rfac;
    dz *= rfac;
L430:
    if (*step > *stepmx) {
	*step = *stepmx;
    }

    if (*ostep - .011 <= 0.) {
	goto L460;
    } else {
	goto L450;
    }
L450:
    step2 = *ostep * 1.5;
    if (*step > step2) {
	*step = step2;
    }
L460:
/* GO TO NEXT POINT UNLESS 4TH ITERATION ON 1ST POINT: */
    if (istate > 4) {
	goto L530;
    }
    istate = 5;
    goto L120;

/* AT EDGE; SOLVE FOR BOUNDARY POINT: */
/* ---------------------------------- */
L500:
    if (isfer[0] != 0) {
	intbnd_(&c__1, isfer);
    }
    if (isfer[1] != 0) {
	intbnd_(&c__2, &isfer[1]);
    }
    istate = 10;
/* SET IPTKNT FOR NORMAL RETURN: */
    *iptknt = -1;
    goto L125;

/* STORE THE OUTPUT DATA */
/* --------------------- */
/*  IF BEND IN INTERSECTION > 100 DEG., EXIT: */
L530:
    if (hco + .174 <= 0.) {
	goto L920;
    } else {
	goto L540;
    }

/* OUT OF BOUNDS? */
L540:
    if (isfer[0] < 0 || isfer[1] < 0) {
	goto L920;
    }
/* ACCUMULATE THE LENGTH ALONG INTERSECTION *** */
/* Computing 2nd power */
    d__1 = pxyz[0] - oxyz[0];
/* Computing 2nd power */
    d__2 = pxyz[1] - oxyz[1];
/* Computing 2nd power */
    d__3 = pxyz[2] - oxyz[2];
    dist = odist + sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if (*ks != 0) {
	goto L510;
    }
    if (ipt >= *npts) {
	goto L920;
    }
    ++ipt;
L510:
/* STORE  THE INTERSECTION PT */
    pt[ipt * 9 + 1] = pxyz[0];
    pt[ipt * 9 + 2] = pxyz[1];
    pt[ipt * 9 + 3] = pxyz[2];
    if (*npt != 0) {
	goto L550;
    }
/* SAVE THE START PT */
    pt0[0] = pxyz[0];
    pt0[1] = pxyz[1];
    pt0[2] = pxyz[2];
L550:
    if (istate >= 10) {
	goto L700;
    }

/* CHECK FOR LOOPAROUND TO START (CLOSED SURFACE) */
/* ---------------------------------------------- */
/*  HAS TANGENT VECTOR GONE NEGATIVE? */
    if (icont != 1) {
	goto L560;
    }
    cs = pl[0] * ctp[0] + pl[1] * ctp[1] + pl[2] * ctp[2];
    if (cs < -.707) {
	icont = -1;
    }
    goto L650;
L560:
    if (icont != -1) {
	goto L570;
    }
/* HAS TANGENT VECTOR GONE NEGATIVE & BACK TO POSITIVE? */
/*  IF CS GOES POSITIVE, BEGIN CHECKS */
    cs = pl[0] * ctp[0] + pl[1] * ctp[1] + pl[2] * ctp[2];
    if (cs > .707) {
	icont = 0;
    }
    goto L650;
L570:
/* BACK TO START POSITION? */
/*  CONTINOUS CUT FLAG IS ON, CHECK CURRENT POSITION */
    d1 = pl[0] * pxyz[0] + pl[1] * pxyz[1] + pl[2] * pxyz[2] - pl[3];
    if (d1 < 0.) {
	goto L620;
    }

/* PASSED START POSITION, CHECK DISTANCE FROM CURRENT POSITION */
/*  TO START POINT. */
    dx1 = pxyz[0] - pt0[0];
    dy1 = pxyz[1] - pt0[1];
    dz1 = pxyz[2] - pt0[2];
    d1 = (d__1 = ctp[0] * dx1 + ctp[1] * dy1 + ctp[2] * dz1, abs(d__1));
    if (d1 > *ostep * 3.) {
	goto L620;
    }
/* Computing 2nd power */
    d__1 = dx1;
/* Computing 2nd power */
    d__2 = dy1;
/* Computing 2nd power */
    d__3 = dz1;
    d1 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    if (d1 < .01) {
	goto L605;
    }
    co = ctp[0] * dx1 / d1 + ctp[1] * dy1 / d1 + ctp[2] * dz1 / d1;
    if (abs(co) > .9999999) {
	goto L605;
    }
    si = sqrt(1. - co * co);
    if (d1 * si / *ck > 1.2) {
	goto L620;
    }

/* LOAD START POINT HERE & SET EXIT FLAG */
L605:
    *iptknt = -1;
    istate = 11;
    if (*ks != 0) {
	goto L640;
    }

/* SET LAST POSITION DATA TO FIRST POSITION DATA */
    for (i__ = 1; i__ <= 3; ++i__) {
	pt[i__ + ipt * 9] = pt[i__ + 9];
	pt[i__ + 3 + ipt * 9] = pt[i__ + 12];
	pt[i__ + 6 + ipt * 9] = pt[i__ + 15];
/* L630: */
    }
    goto L920;
L640:
L650:
L700:
L620:
    if (*ks != 0 && istate <= 9 && *npt != 0) {
	goto L720;
    }
/* STORE PT, NORMAL & TANGENT ... */
/*  TZCK = PXYZ(1)*DTP(1) + PXYZ(2)*DTP(2) + PXYZ(3)*DTP(3) - DTP(4) */
/*  TXCK = PXYZ(1)*PTP(1) + PXYZ(2)*PTP(2) + PXYZ(3)*PTP(3) - PTP(4) */
/*   COMPUTE PLANE DTP, TANGENT TO DS */
    inttpl_(&c__2, pxyz, dtp, &isfer[1]);
/* COMPUTE PLANE PTP, TANGENT TO PS */
    inttpl_(&c__1, pxyz, ptp, isfer);
/* SAL = COS OF ANGLE BETWEEN PLANES: */
    sal = ptp[0] * dtp[0] + ptp[1] * dtp[1] + ptp[2] * dtp[2];
    calsq = 1. - sal * sal;
    if (calsq < 1e-20) {
	calsq = 1e-20;
    }
    cal = sqrt(calsq) * ctp[3];
/* COMPUTE UNIT TANGENT VECTOR YABC: */
    ctp[0] = (dtp[1] * ptp[2] - ptp[1] * dtp[2]) / cal;
    ctp[1] = (dtp[2] * ptp[0] - ptp[2] * dtp[0]) / cal;
    ctp[2] = (dtp[0] * ptp[1] - ptp[0] * dtp[1]) / cal;
    pt[ipt * 9 + 4] = uv[6];
    pt[ipt * 9 + 5] = uv[7];
    pt[ipt * 9 + 6] = (doublereal) ipnr[1];
    pt[ipt * 9 + 7] = uv[0];
    pt[ipt * 9 + 8] = uv[1];
    pt[ipt * 9 + 9] = (doublereal) ipnr[0];
L720:
    ++(*npt);
/* START PT. ONLY? */
    if (*ks < 0) {
	goto L920;
    }
/* IF OUTSIDE EDGE, QUIT; IF INTERPATCH BOUNDARY, CONTINUE: */
    if (istate == 10) {
	goto L920;
    }
    if (istate == 9) {
	istate = 5;
    }
/* GO FOR ANOTHER PT. IF NOT AT EDGE OR BACK AT START: */
    if (istate < 10) {
	goto L100;
    }

/* RETURN THE LENGTH ALONG INTERSECTION */
/* ------------------------------------ */
L920:
    if (*ks == 0) {
	*npt = ipt;
    }
    *stepmx = hstep;

    return 0;
} /* intcon_ */

#undef stepmx
#undef iptknt
#undef ostep
#undef isfer
#undef pxyz
#undef oxyz
#undef npts
#undef step
#undef ipnr
#undef ptp
#undef dtp
#undef ctp
#undef uv
#undef un
#undef ck


