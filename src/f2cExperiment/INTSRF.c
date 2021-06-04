/* INTSRF.f -- translated by f2c (version 20100827).
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

struct {
    doublereal tabext, ssext;
    integer iold;
} xunits_;

#define xunits_1 xunits_

struct {
    char oldmod[6];
} xunitc_;

#define xunitc_1 xunitc_

/* Table of constant values */

static integer c__0 = 0;
static doublereal c_b18 = .5;

/* *** SOURCE FILE : M0012321.V02   *** */

/* Subroutine */ int intsrf_(doublereal *sp, doublereal *tol, doublereal *pt, 
	integer *npt, integer *irc)
{
    /* Initialized data */

    static doublereal scale[4] = { 25.4,2.54,1.,.0833333333 };

    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal u, v, d1, u1, v1, u2, v2;
#define ck ((doublereal *)&intcom_1 + 120)
    static integer ii;
    static doublereal cs, dx, dy;
    static integer ks, np;
    static doublereal tl;
    static integer ns;
    static doublereal hx;
#define un ((doublereal *)&intcom_1 + 82)
    static doublereal hy, hz, dz;
#define uv ((doublereal *)&intcom_1 + 64)
    static doublereal sec, dis;
#define ctp ((doublereal *)&intcom_1 + 116)
    static doublereal dsq, htx, hty, htz;
#define spv ((doublereal *)&intcom_1)
    static integer itim;
    static doublereal smax;
    static integer mcut;
#define step ((doublereal *)&intcom_1 + 122)
#define npts ((integer *)&intcom_1 + 250)
#define pxyz ((doublereal *)&intcom_1 + 102)
#define isfer ((integer *)&intcom_1 + 251)
#define ostep ((doublereal *)&intcom_1 + 123)
    static logical start, lxbnd1, lxbnd2;
    extern /* Subroutine */ int intbnd_(integer *, integer *), intcon_(
	    doublereal *, integer *, integer *), cnsurf_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
#define iptknt ((integer *)&intcom_1 + 249)
#define stepmx ((doublereal *)&intcom_1 + 121)


/*     EXECUTIVE ROUTINE TO COMPUTE THE INTERSECTION BETWEEN TWO */
/*     ARBITRARY SURFACES. */


/* SS - ARELEM - COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/*   EVALUATION VECTOR FOR PS AND DS */
/*   LAST THREE U,V PAIRS OF PS AND DS */
/*   HISTORY OF UNIT NORMALS AT INTERSECTION POINTS ON PS AND DS */
/*   POINT OF INTERSECTION */
/*   PLANE PERPENTICULAR TO INTERSECTION DIRECTION */
/*   MULTIBLE OF ABSOLUT TOLERANCE */
/*   MAXIMUM STEP */
/*   STEP LENGTH */
/*   OLD STEP LENGTH */
/*   INTERNAL POINT COUNT */
/*   MAXIMUM NUMBER OF POINTS */
/*   OUT OF BOUND SIGNAL FOR PS AND DS */

/* ARGUMENTS */

/* LOCAL VARIABLES */






/*                  MM    CM    INCH   FEET */
    /* Parameter adjustments */
    pt -= 10;
    --sp;

    /* Function Body */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

    *npts = *npt;
    lxbnd1 = FALSE_;
    lxbnd2 = FALSE_;
    *irc = 0;
    *npt = 0;

/*         INITIAL STARTUP INFO */
    ctp[0] = 1.;
    ctp[1] = 1.;
    ctp[2] = 1.;
    ctp[3] = 1.;
    pxyz[0] = sp[1];
    pxyz[1] = sp[2];
    pxyz[2] = sp[3];
    pt[10] = sp[1];
    pt[11] = sp[2];
    pt[12] = sp[3];
    tl = abs(*tol);
    if (tl < 1e-5) {
	tl = 1e-5;
    }
    *ck = tl * 8.;
    *stepmx = scale[xunits_1.iold - 1] * .01 + tl * 1e3;
/* MAX. STEP IS <= 4.0 INCHES *** AEQUIVALENT TO 100 MM */
    smax = scale[xunits_1.iold - 1] * 4.;

    if (*stepmx > smax) {
	*stepmx = smax;
    }
    *step = 0.;
    *ostep = *step;
/* TURN CUT FLAG OFF FOR PASS 1: */
    mcut = 1;
    for (i__ = 1; i__ <= 18; ++i__) {
	un[i__ - 1] = 0.;
/* L10: */
    }

/* I N I T I A L I Z A T I O N */
/*  LOOP UNTIL START POINT "PXYZ" CONVERGES (MAX. 15 LOOPS) **** */
    for (ii = 1; ii <= 15; ++ii) {
	itim = ii;
	if (ii > 2) {
	    goto L60;
	}

/* ON FIRST TWO ITERATIONS, SCAN SURFACES FOR START U,V: */
	for (i__ = 1; i__ <= 2; ++i__) {

/* IF SURFACE IS A PLANE, FORGET IT */
	    if (ssarlm_1.iiflag[(i__ << 2) - 4] <= 0) {
		goto L50;
	    }

/* SCAN SURFACE FOR PT. ON SURFACE CLOSEST TO "PXYZ": */
	    dis = 9e21;
	    v = -.1;
	    for (j = 1; j <= 5; ++j) {
		u = -.1;
		v += .2;
		for (k = 1; k <= 5; ++k) {
		    u += .2;
		    cnsurf_(&u, &v, &ssarlm_1.bb[(i__ << 6) - 64], &spv[((i__ 
			    << 3) + 1 << 2) - 36], &ssarlm_1.iiflag[(i__ << 2)
			     - 4], &c__0);
/* Computing 2nd power */
		    d__1 = pxyz[0] - spv[((i__ << 3) + 1 << 2) - 36];
/* Computing 2nd power */
		    d__2 = pxyz[1] - spv[((i__ << 3) + 1 << 2) - 35];
/* Computing 2nd power */
		    d__3 = pxyz[2] - spv[((i__ << 3) + 1 << 2) - 34];
		    d1 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		    if (dis < d1) {
			goto L30;
		    }
		    dis = d1;

/* SAVE UV OF SURFACE */
		    for (l = 1; l <= 3; ++l) {
			uv[(l + i__ * 3 << 1) - 8] = u;
			uv[(l + i__ * 3 << 1) - 7] = v;
/* L20: */
		    }
L30:
		    ;
		}
/* L40: */
	    }
L50:
	    ;
	}

/* UV OF SURFACE IS KNOWN; COMPUTE A SINGLE INTERSECTION PT.: */
L60:
	ks = -1;
	for (l = 1; l <= 3; ++l) {
	    intcon_(&pt[10], &np, &ks);
	    if (l > 2) {
		goto L70;
	    }
	    pt[10] = pxyz[0];
	    pt[11] = pxyz[1];
	    pt[12] = pxyz[2];
L70:
	    ;
	}

/* IF POINT NOT OVER DS, MOVE IT TO DS BOUNDARY */
	if (isfer[1] >= 0) {
	    goto L80;
	}
	ns = 2;
/* SET SURFACE 2 BOUNDARY FLAG: */
	lxbnd2 = TRUE_;

/* IF POINT NOT OVER PS, MOVE IT TO PS BOUNDARY */
	goto L90;
L80:
	if (isfer[0] >= 0) {
	    goto L100;
	}
	ns = 1;
/* SET SURFACE 1 BOUNDARY FLAG: */
	lxbnd1 = TRUE_;
L100:
L90:

	if (! lxbnd1 && ! lxbnd2) {
	    goto L110;
	}
/* FIND AN INTERSECTION PT. ON THE BOUNDARY: */
	intbnd_(&ns, irc);
/* STILL OUT OF BOUNDS? *** */
	if (*irc < 0) {
	    goto L130;
	}
L110:

/* EXIT IF NO CHANGE IN PXYZ */
/* Computing 2nd power */
	d__1 = pt[10] - pxyz[0];
/* Computing 2nd power */
	d__2 = pt[11] - pxyz[1];
/* Computing 2nd power */
	d__3 = pt[12] - pxyz[2];
	dsq = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	start = dsq < 1e-8 && ii > 1;
	if (start) {
	    goto L140;
	}
	pt[10] = pxyz[0];
	pt[11] = pxyz[1];
	pt[12] = pxyz[2];
L130:
	;
    }
L140:
/* END OF LOOP TO FIND START POINT */
/*  IF HERE; CANNOT FIND A START INTERS. POINT */
    if (! start) {
	goto L999;
    }

/* COMPUTE START UP DIR OF YA YB YC */
/*  SET DIR. FROM CURRENT POS. TO UV=.5 */
    hx = pxyz[0];
    hy = pxyz[1];
    hz = pxyz[2];
    ks = 1;
    itim = 0;
/* IF S1 IS A PLANE, USE S2 FOR START DIRECTION: */
    if (ssarlm_1.iiflag[4] <= 0) {
	goto L120;
    }
/* IF NEAR EDGE OF S2, USE S2 FOR START DIRECTION: */
    if (lxbnd2 && ! lxbnd1) {
	goto L120;
    }

/* USE SURFACE 1 FOR START DIR. */
    cnsurf_(&c_b18, &c_b18, &ssarlm_1.bb[64], spv, &ssarlm_1.iiflag[4], &c__0)
	    ;
    goto L135;

/* USE SURFACE 2 FOR START DIR. */
L120:
    cnsurf_(&c_b18, &c_b18, ssarlm_1.bb, spv, ssarlm_1.iiflag, &c__0);

/* COMPUTE DIR. FROM PXYZ TO TO SPV(1-3,1,1) */
L135:
    dx = spv[0] - pxyz[0];
    dy = spv[1] - pxyz[1];
    dz = spv[2] - pxyz[2];
    sec = sqrt(dx * dx + dy * dy + dz * dz);
    if (sec == 0.) {
	sec = 1.;
    }
    dx /= sec;
    dy /= sec;
    dz /= sec;
    cs = dx * ctp[0] + dy * ctp[1] + dz * ctp[2];
/* IS "YABC" ORIENTED TOWARD MIDDLE OF SURFACE? */
    if (cs >= 0.) {
	goto L150;
    }

/*  FLIP CURRENT DIR. OF YA YB YC */
    ctp[0] = -ctp[0];
    ctp[1] = -ctp[1];
    ctp[2] = -ctp[2];
    ctp[3] = -ctp[3];
L150:
L160:

/* P A S S   1  &  2 */
/*  COMPUTE POINTS UNTIL A BOUNDARY IS INTERSECTED */
    intcon_(&pt[10], &np, &ks);
    ++itim;
/* ERROR? */
    if (*iptknt > 0) {
	goto L220;
    }

/* NORMAL ENDUP IF IPTKNT.LT.0 */
/*   IS INTERSECTION PASS 2 COMPLETE? */
    if (mcut != 0) {
	goto L190;
    }

/* IF POINTS, EXIT; ELSE TURN FORWARD AROUND AND REDO */
    if (np > 2) {
	goto L220;
    }
    if (itim > 2) {
	goto L999;
    }
    if (itim != 2) {
	goto L180;
    }

/* RELOAD FIRST START POSITION & UV */
    pxyz[0] = htx;
    pxyz[1] = hty;
    pxyz[2] = htz;
    for (i__ = 1; i__ <= 3; ++i__) {
	uv[(i__ + 3 << 1) - 8] = u1;
	uv[(i__ + 3 << 1) - 7] = v1;
	uv[(i__ + 6 << 1) - 8] = u2;
	uv[(i__ + 6 << 1) - 7] = v2;
/* L170: */
    }

/* FLIP CURRENT DIR. OF YA YB YC */
    ctp[0] = -ctp[0];
    ctp[1] = -ctp[1];
    ctp[2] = -ctp[2];
    ctp[3] = -ctp[3];
L180:
    goto L210;
L190:

/* PASS 1 COMPLETE; REVERSE DIRECTION & DO PASS 2. */
/*  SAVE CURRENT POSITION: */
    htx = pxyz[0];
    hty = pxyz[1];
    htz = pxyz[2];
    if (np > 2) {
	goto L200;
    }
    pxyz[0] = hx;
    pxyz[1] = hy;
    pxyz[2] = hz;
    htx = pxyz[0];
    hty = pxyz[1];
    htz = pxyz[2];
L200:
    u1 = uv[2];
    v1 = uv[3];
    u2 = uv[8];
    v2 = uv[9];
    ks = 0;
/* SET CUT FLAG ON FOR PASS 2: */
    mcut = 0;
    *ck = tl * 4.;

/* FLIP CURRENT DIR. OF YA YB YC */
    ctp[0] = -ctp[0];
    ctp[1] = -ctp[1];
    ctp[2] = -ctp[2];
    ctp[3] = -ctp[3];
L210:
    goto L160;
L220:

/* MAX. POINT REACHED, IF CUT ON, RETURN THESE */
    if (mcut == 1) {
	goto L999;
    }
    *npt = np;

L999:
    return 0;
} /* intsrf_ */

#undef stepmx
#undef iptknt
#undef ostep
#undef isfer
#undef pxyz
#undef npts
#undef step
#undef spv
#undef ctp
#undef uv
#undef un
#undef ck


