/* INTBND.f -- translated by f2c (version 20100827).
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
static integer c__1 = 1;

/* *** SOURCE FILE : M0012365.V01   *** */

/* Subroutine */ int intbnd_(integer *ns, integer *irc)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer j, k, l, m;
    static doublereal u, v, d1, d2, d3;
    static integer i1, j1, k1;
    static doublereal p1[3], p2[3];
    static integer jj, kk;
    static doublereal pl[12]	/* was [4][3] */;
    static integer is;
    static doublereal hu, hv;
    static integer nt;
#define un ((doublereal *)&intcom_1 + 82)
#define uv ((doublereal *)&intcom_1 + 64)
    static doublereal cal, den, sec, det, sal, dis;
#define ctp ((doublereal *)&intcom_1 + 116)
#define dtp ((doublereal *)&intcom_1 + 108)
    static doublereal duv;
#define ptp ((doublereal *)&intcom_1 + 112)
    static doublereal htx, hty, htz;
#define spv ((doublereal *)&intcom_1)
    static doublereal uuu, vvv, ubnd, vbnd, ctpi[4];
    static integer iypl;
    static doublereal dxyz[6]	/* was [3][2] */;
#define oxyz ((doublereal *)&intcom_1 + 105)
#define pxyz ((doublereal *)&intcom_1 + 102)
#define thick ((doublereal *)&intcom_1 + 100)
    static doublereal calsq;
    static logical uxbnd, vxbnd;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *), intnrm_(
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     integer *), inttpl_(integer *, doublereal *, doublereal *, 
	    integer *);


/*     CALCULATES A SURFACE BOUNDARY PT ON THE INTERSECTION OF */
/*     TWO SURFACES. */

/* SS - ARELEM - COMMON */

/*   COMMON FOR 2 SURFACE INTERSECTION */
/*   EVALUATION VECTOR FOR PS AND DS */
/*   LAST THREE U,V PAIRS OF PS AND DS */
/*   HISTORY OF UNIT NORMALS AT INTERSECTION POINTS ON PS AND DS */
/*   THICKNESS ON PS AND DS */
/*   POINT OF INTERSECTION */
/*   OLD POINT OF INTERSECTION */
/*   DS TANGENT PLANE */
/*   PS TANGENT PLANE */
/*   PLANE PERPENTICULAR TO INTERSECTION DIRECTION */
/*  TRACE */
/* CCCC EQUIVALENCE (IKEEP(249),ITRACE) */


/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* CCCC IF(ITRACE.EQ.1) */
/* CCCC*WRITE(6,1000)KS */
/* 1000 FORMAT(' ***TRACE***INTBND-KS=',I5) */
    uxbnd = FALSE_;
    vxbnd = FALSE_;
    u = uv[(*ns * 3 + 1 << 1) - 8];
    v = uv[(*ns * 3 + 1 << 1) - 7];

/* DETERMINE PARAMETRIC VALUE OF BOUNDARY (UBND OR VBND) */
/* ----------------------------------------------------- */
/*  TEST FIRST FOR U OR V OR U&V OUT OF BOUNDS */
    uuu = (d__1 = u - .5, abs(d__1)) + 1e-12;
    vvv = (d__1 = v - .5, abs(d__1)) + 1e-12;
    nt = 0;
    ubnd = 0.;
/* IS U OUT OF BOUNDS? */
    if (uuu < .5) {
	goto L30;
    }
/* U OUT OF BOUNDS; LIMIT: 0 <= UBND <= 1. */
    if (u > .5) {
	ubnd = 1.;
    }
    ++nt;
    uxbnd = TRUE_;
L30:
    vbnd = 0.;
/* IS V OUT OF BOUNDS? */
    if (vvv < .5) {
	goto L50;
    }
/* V OUT OF BOUNDS; LIMIT: 0 <= VBND <= 1. */
    if (v > .5) {
	vbnd = 1.;
    }
    ++nt;
    vxbnd = TRUE_;
L50:
/* RESET U,V HISTORY TABLE: */
    uv[(*ns * 3 + 1 << 1) - 8] = u;
    uv[(*ns * 3 + 2 << 1) - 8] = u;
    uv[(*ns * 3 + 3 << 1) - 8] = u;
    uv[(*ns * 3 + 1 << 1) - 7] = v;
    uv[(*ns * 3 + 2 << 1) - 7] = v;
    uv[(*ns * 3 + 3 << 1) - 7] = v;
    if (! uxbnd) {
	goto L60;
    }
/* SET UUU AT APPROPRIATE BOUNDARY: */
    uuu = ubnd;
    j = 2;
    jj = 3;
    goto L80;
L60:
    if (! vxbnd) {
	goto L70;
    }
/* SET VVV AT APPROPRIATE BOUNDARY: */
    vvv = vbnd;
    j = 3;
    jj = 2;
    goto L80;
L70:
    goto L999;
L80:

/* EXECUTE THIS CODE FOR U BOUNDARY OR V BOUNDARY (OR BOTH): */
    i__1 = nt;
    for (is = 1; is <= i__1; ++is) {

/* ITERATE (MAX. 15 TIMES) TO FIND INTERSECTION PT PXYZ ON BOUNDARY */
/* ---------------------------------------------------------------- */
	for (k = 1; k <= 15; ++k) {
	    kk = k;
	    htx = pxyz[0];
	    hty = pxyz[1];
	    htz = pxyz[2];

/* USE PXYZ FROM PREVIOUS LOOP: */
	    for (l = 1; l <= 3; ++l) {
		p1[l - 1] = pxyz[l - 1];
		p2[l - 1] = pxyz[l - 1];
/* L240: */
	    }

/* EVALUATE POINT, NORMAL & PARTIALS ALONG BOUNDARY: */
	    duv = -1e-4;
	    for (l = 1; l <= 3; ++l) {
		if (l == 3) {
		    duv = 0.;
		}
/* ON V BOUNDARY, SET UUU = U-DUV, U+DUV, U. */
		if (j == 3) {
		    uuu = uv[(*ns * 3 + 1 << 1) - 8] + duv;
		}
/* ON U BOUNDARY, SET VVV = V-DUV, V+DUV, V. */
		if (j == 2) {
		    vvv = uv[(*ns * 3 + 1 << 1) - 7] + duv;
		}
/* COMPUTE POINT, NORMAL & PARTIALS AT UUU,VVV ON SURFACE I: */
		cnsurf_(&uuu, &vvv, &ssarlm_1.bb[(*ns << 6) - 64], &spv[((*ns 
			<< 3) + 1 << 2) - 36], &ssarlm_1.iiflag[(*ns << 2) - 
			4], &c__0);
		if (l > 2) {
		    goto L250;
		}
/* ON U BOUNDARY, SAVE V-PARTIALS; ON V BOUNDARY, SAVE U-PARTIALS: */
		dxyz[l * 3 - 3] = spv[(jj + (*ns << 3) << 2) - 36];
		dxyz[l * 3 - 2] = spv[(jj + (*ns << 3) << 2) - 35];
		dxyz[l * 3 - 1] = spv[(jj + (*ns << 3) << 2) - 34];
L250:
		duv = -duv;
/* L190: */
	    }

/* COMPUTE YPL = NORMAL TO PLANE OF BOUNDARY: */
/* ------------------------------------------ */

/* TRY YPL = CROSS PRODUCT OF V-PARTIAL & NORMAL VECTOR: */
	    ctpi[0] = spv[(jj + (*ns << 3) << 2) - 35] * spv[((*ns << 3) + 8 
		    << 2) - 34] - spv[(jj + (*ns << 3) << 2) - 34] * spv[((*
		    ns << 3) + 8 << 2) - 35];
	    ctpi[1] = spv[(jj + (*ns << 3) << 2) - 34] * spv[((*ns << 3) + 8 
		    << 2) - 36] - spv[(jj + (*ns << 3) << 2) - 36] * spv[((*
		    ns << 3) + 8 << 2) - 34];
	    ctpi[2] = spv[(jj + (*ns << 3) << 2) - 36] * spv[((*ns << 3) + 8 
		    << 2) - 35] - spv[(jj + (*ns << 3) << 2) - 35] * spv[((*
		    ns << 3) + 8 << 2) - 36];
	    iypl = 1;
/* Computing 2nd power */
	    d__1 = ctpi[0];
/* Computing 2nd power */
	    d__2 = ctpi[1];
/* Computing 2nd power */
	    d__3 = ctpi[2];
	    sec = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* IS VECTOR LARGE ENOUGH? ... */
	    if (sec <= 1e-10) {
		goto L260;
	    }
/* NORMALIZE YPL: */
	    ctpi[0] /= sec;
	    ctpi[1] /= sec;
	    ctpi[2] /= sec;
/* CTPI(4) = DOT PRODUCT OF YPL & BOUNDARY POINT: */
	    ctpi[3] = ctpi[0] * spv[((*ns << 3) + 1 << 2) - 36] + ctpi[1] * 
		    spv[((*ns << 3) + 1 << 2) - 35] + ctpi[2] * spv[((*ns << 
		    3) + 1 << 2) - 34];
	    goto L270;
L260:

/* TRY YPL = CROSS PRODUCT OF V-PARTIALS AT V +/- DELTA: */

	    iypl = 0;
	    ctpi[0] = dxyz[1] * dxyz[5] - dxyz[2] * dxyz[4];
	    ctpi[1] = dxyz[2] * dxyz[3] - dxyz[0] * dxyz[5];
	    ctpi[2] = dxyz[0] * dxyz[4] - dxyz[1] * dxyz[3];
/* Computing 2nd power */
	    d__1 = ctpi[0];
/* Computing 2nd power */
	    d__2 = ctpi[1];
/* Computing 2nd power */
	    d__3 = ctpi[2];
	    sec = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* IS VECTOR LARGE ENOUGH? *** */
	    if (sec >= 1e-20) {
		goto L280;
	    }

/* USE YPL = U-PARTIAL AT U,V: */

	    iypl = 0;
	    ctpi[0] = spv[(j + (*ns << 3) << 2) - 36];
	    ctpi[1] = spv[(j + (*ns << 3) << 2) - 35];
	    ctpi[2] = spv[(j + (*ns << 3) << 2) - 34];
/* Computing 2nd power */
	    d__1 = ctpi[0];
/* Computing 2nd power */
	    d__2 = ctpi[1];
/* Computing 2nd power */
	    d__3 = ctpi[2];
	    sec = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
L280:
/* NORMALIZE CTPI: */
	    ctpi[0] /= sec;
	    ctpi[1] /= sec;
	    ctpi[2] /= sec;
L270:

/* COMPUTE PLANES TANGENT TO S1 & S2 BELOW PXYZ: */
/* --------------------------------------------- */
/*  COMPUTE PLANE DTP TANGENT TO DS: */
	    inttpl_(&c__2, p1, dtp, irc);
/* COMPUTE PLANE PTP TANGENT TO PS: */
	    inttpl_(&c__1, p2, ptp, irc);

/* RELOAD DT TABLES WITH SURFACE NORMAL OFFSETS */
	    un[9] = dtp[0];
	    un[10] = dtp[1];
	    un[11] = dtp[2];
	    un[0] = ptp[0];
	    un[1] = ptp[1];
	    un[2] = ptp[2];
	    for (l = 1; l <= 3; ++l) {
		un[l + 2] = un[l - 1];
		un[l + 11] = un[l + 8];
		un[l + 5] = un[l + 2];
		un[l + 14] = un[l + 11];
/* EVALUATE THICKNESS */
		spv[l + ((*ns << 3) + 1 << 2) - 37] += un[l + (*ns * 3 + 1) * 
			3 - 13] * thick[*ns - 1];
/* L290: */
	    }
/* IF BOUNDARY ALGORITHM 2 OR 3, YPL(4) = DOT PRODUCT OF YPL AND */
/*  OFFSET BOUNDARY POINT: */
	    if (iypl == 0) {
		ctpi[3] = ctpi[0] * spv[((*ns << 3) + 1 << 2) - 36] + ctpi[1] 
			* spv[((*ns << 3) + 1 << 2) - 35] + ctpi[2] * spv[((*
			ns << 3) + 1 << 2) - 34];
	    }

/* LOAD PL TABLE */
	    for (l = 1; l <= 4; ++l) {
		pl[l - 1] = ptp[l - 1];
		pl[l + 3] = ctpi[l - 1];
		pl[l + 7] = dtp[l - 1];
/* L300: */
	    }

/* SOLVE FOR PXYZ AT INTERSECTION OF PLANES PTP,YPL,DTP: */
/* ----------------------------------------------------- */
	    for (l = 1; l <= 4; ++l) {
		i1 = 1;
		j1 = 2;
		k1 = 3;
		if (l == 2) {
		    i1 = 4;
		}
		if (l == 3) {
		    j1 = 4;
		}
		if (l == 4) {
		    k1 = 4;
		}
/* CRAMER'S RULE: */
		det = pl[i1 - 1] * pl[j1 + 3] * pl[k1 + 7] + pl[i1 + 3] * pl[
			j1 + 7] * pl[k1 - 1] + pl[i1 + 7] * pl[j1 - 1] * pl[
			k1 + 3] - pl[i1 + 7] * pl[j1 + 3] * pl[k1 - 1] - pl[
			i1 + 3] * pl[j1 - 1] * pl[k1 + 7] - pl[i1 - 1] * pl[
			j1 + 7] * pl[k1 + 3];
		if (l != 1) {
		    goto L330;
		}
		den = det;
/* DEGENERATE SOLUTION? */
		if (abs(den) < 1e-16) {
		    goto L320;
		}
		goto L340;
L330:
		pxyz[l - 2] = det / den;
L340:
/* L310: */
		;
	    }
L320:
	    if (abs(den) >= 1e-16) {
		goto L350;
	    }
/* DEGENERATE SOLN; COMPUTE TANGENT YABC & PXYZ ON DTP & PTP: */
	    sal = ptp[0] * dtp[0] + ptp[1] * dtp[1] + ptp[2] * dtp[2];
	    calsq = 1. - sal * sal;
	    if (calsq <= 1e-20) {
		goto L360;
	    }
	    cal = sqrt(calsq) * ctp[3];
	    ctp[0] = (dtp[1] * ptp[2] - ptp[1] * dtp[2]) / cal;
	    ctp[1] = (dtp[2] * ptp[0] - ptp[2] * dtp[0]) / cal;
	    ctp[2] = (dtp[0] * ptp[1] - ptp[0] * dtp[1]) / cal;
	    d1 = (ptp[3] - sal * dtp[3]) / calsq;
	    d2 = dtp[3] - sal * d1;
	    d3 = ctp[0] * pxyz[0] + ctp[1] * pxyz[1] + ctp[2] * pxyz[2];
	    pxyz[0] = ptp[0] * d1 + dtp[0] * d2 + ctp[0] * d3;
	    pxyz[1] = ptp[1] * d1 + dtp[1] * d2 + ctp[1] * d3;
	    pxyz[2] = ptp[2] * d1 + dtp[2] * d2 + ctp[2] * d3;
L360:
L350:
/* Computing 2nd power */
	    d__1 = pxyz[0] - htx;
/* Computing 2nd power */
	    d__2 = pxyz[1] - hty;
/* Computing 2nd power */
	    d__3 = pxyz[2] - htz;
	    dis = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* CONVERGENCE? */
	    if (dis < 1e-12) {
		goto L230;
	    }
/* L220: */
	}
L230:

/* DONE WITH THIS BOUNDARY; CHECK BOUNDS & TRY OTHER ONE IF NECESSARY */
/* ------------------------------------------------------------------ */
	if (nt == 1) {
	    goto L210;
	}

/* BOTH U & V ARE OUT OF BOUNDS, CHECK IF NOW IN BOUNDS: */
	hu = uv[(*ns * 3 + 1 << 1) - 8];
	hv = uv[(*ns * 3 + 1 << 1) - 7];
	intnrm_(ns, &hu, &hv, pxyz, spv, irc);
/* POINT IS ALONG U BOUNDARY; IF TRULY WITHIN BOUNDS, RETURN: *** */
	if (*irc == 0 || j == 3) {
	    goto L210;
	}

/* SET VVV AT APPROPRIATE BOUNDARY: */
	vvv = vbnd;
	j = 3;
	jj = 2;
/* L200: */
    }
L210:

/* LOAD THIS UV FOR LAST CALL TO INTTPL IN INTCON */
    for (m = 1; m <= 3; ++m) {
	uv[(m + *ns * 3 << 1) - 8] = uuu;
	uv[(m + *ns * 3 << 1) - 7] = vvv;
/* L370: */
    }

L999:
    return 0;
} /* intbnd_ */

#undef thick
#undef pxyz
#undef oxyz
#undef spv
#undef ptp
#undef dtp
#undef ctp
#undef uv
#undef un


