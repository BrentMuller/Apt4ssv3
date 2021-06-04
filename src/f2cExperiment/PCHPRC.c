/* PCHPRC.f -- translated by f2c (version 20100827).
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
    doublereal dist, uvdist, spbond[40];
    integer istart;
} cstart_;

#define cstart_1 cstart_

/* Table of constant values */

static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c_n3 = -3;

/* *** SOURCE FILE : M0004323.W03   *** */

/* Subroutine */ int pchprc_(doublereal *ss, doublereal *b, doublereal *ust, 
	doublereal *vst, doublereal *tp, doublereal *tn, doublereal *ua, 
	doublereal *va, doublereal *sp, doublereal *sn, doublereal *slx, 
	integer *iflag, integer *itop, integer *ipnum, integer *mode, integer 
	*idebug, integer *irr, logical *lgeom)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal uchg[8] = { 0.,1.,1.,1.,0.,-1.,-1.,-1. };
    static doublereal vchg[8] = { 1.,1.,0.,-1.,-1.,-1.,0.,1. };
    static integer nits = 30;
    static integer mexchg = 10;
    static doublereal stepmx = .64;
    static doublereal stepln = .7;
    static doublereal one = 1.;
    static doublereal half = .5;
    static doublereal flck0 = .99998;
    static doublereal flck2 = .999;
    static doublereal smal = 1e-10;
    static doublereal vsmal = 1e-20;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__;
    static integer i__, j, k;
    static doublereal u, v, u1, v1, dm;
    static integer ii;
    static doublereal dr, cu, cv, dt;
    static integer ir;
    static doublereal ct;
    static integer iz;
    extern /* Subroutine */ int bad_();
    static doublereal daf[3], dif[3], dhu, dhv, ctm, spv[32], dmax__;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer ilev, jmax;
    static doublereal umax, vmax, step;
    static integer ickbn;
    static doublereal ubond, vbond, drmax;
    static integer ipmax;
    extern /* Subroutine */ int aprix_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *);
    static doublereal ulast, vlast, udist, vdist;
    static integer ipnst;
    extern /* Subroutine */ int vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int bonchk_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *), lodpch_(doublereal *, doublereal *, 
	    integer *, integer *, integer *, integer *);
    static integer kinpat, ipsave, iexcnt;
    extern /* Subroutine */ int cprint_(char *, ftnlen), cnsurf_(doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *);
    static integer kretry;
    extern /* Subroutine */ int sqrcut_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;

/* ------ THIS PROGRAM ACCEPTS A CURRENT PATCH B AND U,V VALUES. */
/* ------ IT MUST DETERMINE A LINEUP WITH AN INPUT TOOL POINT AND */
/* ------  TOOL NORMAL .  IF THE LINEUP IS NOT ON THE CURRENT */
/* ------ PATCH THEN THE LOGIC FREELY EXCHANGES PATCHES UNTIL AN ANSWER */
/* ------ IS FOUND.  NO MORE THAN TEN PATCH EXCHANGES ARE ALLOWED. */





    /* Parameter adjustments */
    itop -= 7;
    --iflag;
    --slx;
    --sn;
    --sp;
    --tn;
    --tp;
    --b;
    --ss;

    /* Function Body */
/* ---      NITS IS THE NUMBER OR ITERATIONS ALLOWED ON 1 SURFACE */
/* ---      MEXCHG IS THE NUMBER OF PATCH EXCHANGES ALLOWED */
/* ---      STEPMX IS A MAXIMUM STEP WITHIN THE PARAMETRIC UNIT SQUARE */
/* ---      STEPLN IS THE REDUCTION OF STEP SIZE IF IT IS TOO LARGE. */
/* --- */
/* --- */
/* --- */
/* --- */
    kretry = 0;
    *ua = *ust;
    *va = *vst;
    ulast = half;
    vlast = half;
    drmax = 0.;
    ipnst = *ipnum;
L1:
    iexcnt = 0;
    kinpat = 0;

    i__1 = nits;
    for (k = 1; k <= i__1; ++k) {

	if (kretry == 5) {
	    goto L8;
	}
	if (kretry == 0) {
	    goto L8;
	}
	if (*ipnum != ipmax) {
	    goto L8;
	}
	if ((d__1 = *ua - umax, abs(d__1)) > .01) {
	    goto L8;
	}
	if ((d__1 = *va - vmax, abs(d__1)) > .01) {
	    goto L8;
	}
	goto L1400;
L8:
	++kinpat;
	if (*idebug == 0) {
	    goto L9;
	}
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(badmsg, " PCHPRC LOOP", (ftnlen)20, (ftnlen)12);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c__1, &c__0, "PNUM", ipnum, (ftnlen)4);
	bad_(&c__1, &c__1, "UA  ", ua, (ftnlen)4);
	bad_(&c__1, &c__1, "VA  ", va, (ftnlen)4);
	bad_(&c_n1, &c__0, "KNPT", &kinpat, (ftnlen)4);
L9:

/* ------EVALUATE THE SURFACE DIFFERENTIAL ELEMENTS AT UA,VA */
/* ------PLACE THE ELEMENTS IN ARRAY SPV */

	cnsurf_(ua, va, &b[1], spv, &iflag[1], &c__1);
	if (*idebug == 0) {
	    goto L10;
	}
	bad_(&c__3, &c__1, "SP  ", spv, (ftnlen)4);
	bad_(&c_n3, &c__1, "SPN ", &spv[28], (ftnlen)4);
	bad_(&c__3, &c__1, "SPU ", &spv[4], (ftnlen)4);
	bad_(&c_n3, &c__1, "SP-V", &spv[8], (ftnlen)4);
	bad_(&c__3, &c__1, "SPUU", &spv[12], (ftnlen)4);
	bad_(&c_n3, &c__1, "SPVV", &spv[20], (ftnlen)4);
	bad_(&c_n3, &c__1, "SPUV", &spv[16], (ftnlen)4);
L10:


/* ------BEFORE SEEKING A NEW UV PAIR, CHECK THE ACCURACY OF THE */
/* ------PRESENT SURFACE POINT,NORMAL */
/* ------ ERROR COMPUTATIONS DEPEND ON THE VARIABLE MODE */
/* ------ MODE=-1, POSITIVE DDST. =0 SNXP OR CLOSEST POINT. =1 */
/* ------ DDST IN EITHER DIRECTION ALONG TOOL RAY. */
	for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	    dif[i__ - 1] = tp[i__] - spv[i__ - 1];
	}
	dotf_(&d__, dif, dif);
	d__ = sqrt(d__);
/* ---      IF D IS TOO SMALL, THEN SET IT TO A LARGER VALUE */
	d__ = max(d__,vsmal);
	for (i__ = 1; i__ <= 3; ++i__) {
	    daf[i__ - 1] = dif[i__ - 1] / d__;
/* L25: */
	}

	if (*mode != 0) {
	    goto L30;
	}
/* ---      COMPUTE ANGLE BETWEEN DIF AND SURFACE NORMAL */
	dotf_(&dr, daf, &spv[28]);
	goto L35;

L30:
/* ---      COMPUTE ANGLE BETWEEN DIF AND TOOL RAY */
	dotf_(&dr, daf, &tn[1]);
/* ---      NORMALIZE ANGLE BY DIVIDING BY LENGTH OF DIF */
L35:
	dr = abs(dr);

	if (*idebug == 0) {
	    goto L41;
	}
	bad_(&c__1, &c__1, "ERR*", &dr, (ftnlen)4);
	bad_(&c__1, &c__1, "DIST", &d__, (ftnlen)4);
	bad_(&c_n3, &c__1, "SPTP", dif, (ftnlen)4);
L41:

/* ---      IF THE RAY IS AT RIGHT ANGLES TO THE SURFACE, QUIT NOW. */
	if (dr < smal && *mode != 0) {
	    goto L9999;
	}
/* ---      ACCEPTANCE CRITERIA, ANGULAR LINEUP BETTER THAN FLIPCK */
	if (*mode == 0 && dr > flck0) {
	    goto L2000;
	}
	if (*mode != 0 && dr > flck2) {
	    goto L2000;
	}
	if (dr < smal) {
	    goto L63;
	}
	if (dr < drmax) {
	    goto L60;
	}
	dmax__ = d__;
	drmax = dr;
	umax = *ua;
	vmax = *va;
	ipmax = *ipnum;

/* ------ ALL INDICATIONS ARE THAT U,V SHOULD BE R MODIFIED */
L60:
	cu = zero;
	cv = zero;
	dt = zero;
	ilev = 3;
	if (kretry < 5) {
	    ilev = 2;
	}
	aprix_(&cu, &cv, &dt, spv, &tp[1], &tn[1], mode, &ilev, &ir, idebug);
/* ---      IF IR.NE.0, THEN ARBITRARILY ALTER CU,CV SLIGHTLY */
/* L640: */
	if (ir == 0) {
	    goto L65;
	}
L63:
	dm = zero;
	ct = .025;
	for (iz = 1; iz <= 2; ++iz) {
	    for (j = 1; j <= 8; ++j) {
		dhu = *ua + ct * uchg[j - 1];
		dhv = *va + ct * uchg[j - 1];
		cnsurf_(&dhu, &dhv, &b[1], spv, &iflag[1], &c__1);
		for (i__ = 1; i__ <= 3; ++i__) {
/* L641: */
		    dif[i__ - 1] = tp[i__] - spv[i__ - 1];
		}
		dotf_(&d__, dif, dif);
		d__ = sqrt(d__);
		d__ = max(d__,vsmal);
		for (i__ = 1; i__ <= 3; ++i__) {
/* L642: */
		    daf[i__ - 1] = dif[i__ - 1] / d__;
		}
		if (*mode != 0) {
		    goto L643;
		}
		dotf_(&dt, daf, &spv[28]);
		goto L644;
L643:
		dotf_(&dt, daf, &tn[1]);
L644:
		dt = abs(dt);
		if (dt <= dm) {
		    goto L648;
		}
		jmax = j;
		ctm = ct;
		dm = dt;
L648:
		;
	    }
	    ct = .075;
/* L649: */
	}
	if (*idebug != 0) {
	    bad_(&c__1, &c__1, "ERRT", &dm, (ftnlen)4);
	}
	if (*idebug != 0) {
	    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	    s_copy(badmsg, " AFTER UV CHANGE", (ftnlen)20, (ftnlen)16);
	    cprint_(badmsg, (ftnlen)20);
	}
	if (dt * 1.1 < drmax || dt < smal) {
	    goto L1400;
	}
	cu = uchg[jmax - 1] * ctm;
	cv = vchg[jmax - 1] * ctm;
L65:

	u1 = *ua + cu;
	v1 = *va + cv;

	if (*idebug == 0) {
	    goto L42;
	}
	bad_(&c__1, &c__1, "UNXT", &u1, (ftnlen)4);
	bad_(&c__1, &c__1, "VNXT", &v1, (ftnlen)4);
	bad_(&c__1, &c__1, "UCHG", &cu, (ftnlen)4);
	bad_(&c_n1, &c__1, "VCHG", &cv, (ftnlen)4);
L42:

/* ------ SQRCUT DETERMINES IF A BOUNDARY IS BEING CROSSED.  IF IT IS, */
/* ------ IT WILL THEN DETERMINE IF AN EXCHANGE SHOULD BE CONSIDERED */
/* ------ ON THE BOUNDARY ICKBN. */

	sqrcut_(ua, va, &u1, &v1, &u, &v, &ickbn);
/* ---      SAVE THE NUMBER OF THE CURRENT PATCH */
	ipsave = *ipnum;
	if (*idebug == 0) {
	    goto L43;
	}
	bad_(&c__1, &c__1, "UCUT", &u, (ftnlen)4);
	bad_(&c__1, &c__1, "VCUT", &v, (ftnlen)4);
	bad_(&c__1, &c__0, "ICKB", &ickbn, (ftnlen)4);
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(badmsg, " AFTER SQRCUT", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
L43:
/* ---      RESTRICT A PARAMETER CHANGE WITHIN THE UNIT SQUARE */
	if (kinpat <= 1) {
	    goto L130;
	}
	if ((d__1 = ulast - half, abs(d__1)) > half) {
	    goto L130;
	}
	if ((d__1 = vlast - half, abs(d__1)) > half) {
	    goto L130;
	}
	if ((d__1 = u - half, abs(d__1)) > half) {
	    goto L130;
	}
	if ((d__1 = v - half, abs(d__1)) > half) {
	    goto L130;
	}
/* ---      BOTH POINTS ARE WITHIN THE UNIT SQUARE, SO CHECK FOR LENGTH */
/* Computing 2nd power */
	d__1 = u - ulast;
/* Computing 2nd power */
	d__2 = v - vlast;
	step = d__1 * d__1 + d__2 * d__2;
	if (step < stepmx) {
	    goto L130;
	}
/* ---      MODIFY STEP LENGTH TO AVOID TRAVERSING COMPLETE PATCH */
	u = ulast + stepln * (u - ulast);
	v = vlast + stepln * (v - vlast);
	ickbn = 0;
	if (*idebug == 0) {
	    goto L130;
	}
	bad_(&c__1, &c__1, "ULIM", &u, (ftnlen)4);
	bad_(&c_n1, &c__1, "VLIM", &v, (ftnlen)4);
L130:

/* ------ BONCHK WILL SEARCH BOUNDARY ICKBN AND IF ANOTHER PATCH IS */
/* ------ FOUND, WILL EXCHANGE THE CURRENT PATCH VALUES. */

	if (ickbn == 0) {
	    goto L110;
	}
/* --- */
	bonchk_(&ss[1], &b[1], &u, &v, &iflag[1], &itop[7], ipnum, &ickbn, 
		idebug);
	if (ipsave != *ipnum) {
	    goto L1300;
	}
	goto L110;
/* ---      A PATCH EXCHANGE OCCURRED SO INCREMENT THE EXCHANGE COUNT */
L1300:
	++iexcnt;
/* ---      RESET COUNTER FOR ITERATIONS ON THIS PATCH TO ZERO */
	kinpat = 0;

	if (*idebug == 0) {
	    goto L120;
	}
	bad_(&c__1, &c__1, "UNEW", &u, (ftnlen)4);
	bad_(&c__1, &c__1, "VNEW", &v, (ftnlen)4);
	bad_(&c__1, &c__0, "PNUM", ipnum, (ftnlen)4);
	bad_(&c__1, &c__0, "EXCT", &iexcnt, (ftnlen)4);
	bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
	s_copy(badmsg, " AFTER BONCHK", (ftnlen)20, (ftnlen)13);
	cprint_(badmsg, (ftnlen)20);
L120:

	*ua = u;
	*va = v;
L110:
	if (iexcnt > mexchg) {
	    goto L1400;
	}

/* L1100: */
	ulast = *ua;
	vlast = *va;
	*ua = u;
	*va = v;
/* L1000: */
    }
/* ---      ACCEPT A LESSER TOLERANCE, IF NECESSARY. */
L1400:
    if (drmax > flck2) {
	goto L1500;
    }
    if (dr > flck2) {
	goto L2000;
    }
L1410:
    ++kretry;
    if (kretry > 4) {
	if (kretry > 5) {
	    goto L9999;
	}
	*ua = umax;
	*va = vmax;
	*ipnum = ipmax;
	lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], ipnum, &c__3);
    } else {
	*ua = *ust;
	*va = *vst;
	if (kretry == 1) {
	    *va = -half;
	}
	if (kretry == 2) {
	    *ua = -half;
	}
	if (kretry == 3) {
	    *ua = 1.5;
	}
	if (kretry == 4) {
	    *va = 1.5;
	}
	*ipnum = ipnst;
	lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], ipnum, &c__3);
	sqrcut_(ust, vst, ua, va, &u, &v, &ickbn);
	if (ickbn == 0) {
	    goto L1410;
	}
	bonchk_(&ss[1], &b[1], &u, &v, &iflag[1], &itop[7], ipnum, &ickbn, 
		idebug);
	*ua = u;
	*va = v;
	if (kretry == 1) {
	    *va -= half;
	}
	if (kretry == 2) {
	    *ua -= half;
	}
	if (kretry == 3) {
	    *ua += half;
	}
	if (kretry == 4) {
	    *va += half;
	}
    }
    if (*idebug == 0) {
	goto L1;
    }
    bad_(&c__1, &c__1, "UA  ", ua, (ftnlen)4);
    bad_(&c__1, &c__1, "VA  ", va, (ftnlen)4);
    bad_(&c__1, &c__0, "PNUM", ipnum, (ftnlen)4);
    bad_(&c_n1, &c__0, "RETY", &kretry, (ftnlen)4);
    goto L1;
/* ---      ERROR, ROUTINE FAILED TO DETERMINE SURFACE PT WITHIN TOLERANCE */
L9999:
/* .... FOR MODE=0 (CALC. SP WITH MINIMUM DISTANCE TO TE) */
/* .... AND (DMAX.GT.10) AND (DRMAX.GT.0.8) TAKE BEST SOLUTION */
    if (*mode == 0 && dmax__ > 10. && drmax > .8) {
	goto L1500;
    }
    *irr = 7001;
    goto L3000;

/* --- THE BEST LINE-UP IS ACCEPTED WITH A LESSER TOLERANCE */

L1500:
    *ipnum = ipmax;
    lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], ipnum, &c__3);
    *ua = umax;
    *va = vmax;
    cnsurf_(ua, va, &b[1], spv, &iflag[1], &c__1);

L2000:
    *irr = 0;
    if (nits != 20) {
	goto L2003;
    }
    nits = 30;
    goto L1;
L2003:

    if (*ua < zero) {
	udist = -(*ua);
	ubond = zero;
    } else {
	if (*ua <= one) {
	    udist = zero;
	    ubond = *ua;
	} else {
	    udist = *ua - one;
	    ubond = one;
	}
    }

    if (*va < zero) {
	vdist = -(*va);
	vbond = zero;
    } else {
	if (*va <= one) {
	    vdist = zero;
	    vbond = *va;
	} else {
	    vdist = *va - one;
	    vbond = one;
	}
    }

    cstart_1.uvdist = udist + vdist;

    cstart_1.dist = d__;

    if (cstart_1.uvdist >= .1) {
	lodpch_(&ss[1], &b[1], &iflag[1], &itop[7], ipnum, &c__3);
	cnsurf_(&ubond, &vbond, &b[1], cstart_1.spbond, &iflag[1], &c__1);
    }

    for (i__ = 1; i__ <= 3; ++i__) {
	sp[i__] = spv[i__ - 1];
	sn[i__] = spv[i__ + 27];
/* L2005: */
    }

/* ---  LGEOM=.TRUE. SIGNIFIES A SPECIAL CALL FOR GEOMETRIC CONSTRUCTION */
    if (*lgeom) {
	for (ii = 4; ii <= 32; ++ii) {
	    sp[ii] = spv[ii - 1];
/* L2001: */
	}
    }
/* ---      SLX VECTOR IS SET IN THE DIRECTION OF THE CRSSPL VECTOR */
/* ---      THIS IS FOR SPECIAL ARELEM TOOL AXIS PRORATING. */
    vnorm_(&spv[8], &slx[1]);


L3000:
    return 0;
} /* pchprc_ */

