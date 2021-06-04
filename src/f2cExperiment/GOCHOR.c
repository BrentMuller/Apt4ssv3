/* GOCHOR.f -- translated by f2c (version 20100827).
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
    integer id[24];
} plgol_;

#define plgol_1 plgol_

/* Table of constant values */

static integer c__3 = 3;
static integer c_b17 = -22221;
static integer c__1 = 1;

/* *** SOURCE FILE : M0012232.V01   *** */

/* Subroutine */ int gochor_(integer *modc, doublereal *u1, doublereal *u2, 
	integer *j11, integer *iret)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal k1, r1, ab, du;
    static integer it;
    static doublereal ui, uj, tl;
#define vl ((doublereal *)&plgol_1 + 4)
    static doublereal zr, vl1;
    extern /* Subroutine */ int gop_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
    static doublereal anz, spi;
#define tol ((doublereal *)&plgol_1 + 3)
    static doublereal spv[156]	/* was [52][3] */, tol2;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static integer ianz;
    static doublereal sppi, spsp, spspp;
    extern doublereal qabpst_(doublereal *, doublereal *, doublereal *);
#define uvcons ((doublereal *)&plgol_1)
    static doublereal udummy, sppspp;





/*  POINT STORAGE AND CURVATURE */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

    tol2 = *tol * *tol;
    ui = *u1;
    uj = *u1;

/*  TANGENT IN SPV (-1) */
    it = 4;
    if (*modc == 2 || *modc == 3) {
	it = 8;
    }

/*  DIFFERENT KINDS OF CALCULATION */
L1:
    switch (*modc) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
    }

/*  CURVE */
L10:
    gop_(&c__3, &ui, &udummy, spv, j11, iret);

/*  CURVATURE OF A CURVE */
    spsp = 0.;
    sppspp = 0.;
    spspp = 0.;
    for (i__ = 1; i__ <= 3; ++i__) {
	spi = spv[i__ + 3];
	sppi = spv[i__ + 7];
	spsp = spi * spi + spsp;
	sppspp = sppi * sppi + sppspp;
/* L11: */
	spspp = spi * sppi + spspp;
    }

/*  OFFSET OF RADIUS */
    zr = 0.;
    if (abs(spsp) < 1e-12) {
	goto L12;
    }

/*  LENGTH OF THE TANGENT */
    tl = sqrt(spsp);
    k1 = sqrt((d__1 = spsp * sppspp - spspp * spspp, abs(d__1)) / spsp / spsp 
	    / spsp);
    goto L60;
L12:
    k1 = 1e18;
    goto L60;

/*  CURVATURE AT VARIABLE V */
L20:
L30:
    gop_(&c__3, uvcons, &ui, spv, j11, iret);

/*  K=N/G */
    k1 = spv[50] / spv[46];

/*  LENGTH OF TANGENT */
    tl = sqrt(spv[46]);

/*  OFFSET OF RADIUS */
    zr = spv[51];
    goto L60;

/*  CURVATURE AT VARIABLE  U */
L40:
L50:
    gop_(&c__3, &ui, uvcons, spv, j11, iret);

/*  K=L/E */
    k1 = spv[48] / spv[44];

/*  LENGTH OF THE TANGENT */
    tl = sqrt(spv[44]);

/*  OFFSET OF RADIUS */
    zr = spv[51];
    goto L60;

/*  CACULATION OF THE STEP OUT U-DISTANCE */
L60:
    if (k1 < 0.) {
	zr = -zr;
    }
    k1 = abs(k1);
    r1 = 1. / (k1 + 1e-12);
    if (r1 < *tol) {
	goto L61;
    }
    if (zr == 0.) {
	goto L63;
    }
    r1 += zr;
    if (r1 <= 0.) {
	goto L61;
    }
    tl = tl / (r1 - zr) * r1;
L63:
    du = sqrt(*tol * (r1 + r1 - *tol)) * 2. / tl;
    goto L62;
L61:
    du = *tol;
/*  R1 LESS THAN THE TOLERANCE */
    aerr_(&c_b17, "GOCHOR  ", (ftnlen)8);
L62:

/*  LENGTH COMPUTING OF THE CUT */
    if (du * tl < *vl) {
	goto L64;
    }
    du = du * *vl * .99 / tl;
L64:
    switch (*modc) {
	case 1:  goto L110;
	case 2:  goto L120;
	case 3:  goto L130;
	case 4:  goto L140;
	case 5:  goto L150;
    }

/*  U2 IS BIGGER THAN   U1 */
L110:
L120:
L140:
    ianz = (integer) ((*u2 - ui) / du);
    anz = (doublereal) (ianz + 1);
    du = (*u2 - ui) / anz;
    uj = ui + du + 1e-7;
    if (uj > *u2) {
	uj = *u2;
    }
    goto L160;

/*  U1 IS BIGGER THAN  U2 */
L130:
L150:
    ianz = (integer) ((ui - *u2) / du);
    anz = (doublereal) (ianz + 1);
    du = (ui - *u2) / anz;
    uj = ui - du - 1e-7;
    if (uj < *u2) {
	uj = *u2;
    }
    goto L160;

/*  COMPUTATION OF THE NEW ENDPOINT AND CONTROL OF THE CHORD */
L160:
    switch (*modc) {
	case 1:  goto L210;
	case 2:  goto L220;
	case 3:  goto L230;
	case 4:  goto L240;
	case 5:  goto L250;
    }
L210:
L240:
L250:
    gop_(&c__1, &uj, uvcons, &spv[52], j11, iret);
    d__1 = (uj + ui) / 2.;
    gop_(&c__1, &d__1, uvcons, &spv[104], j11, iret);
    goto L260;
L220:
L230:
    gop_(&c__1, uvcons, &uj, &spv[52], j11, iret);
    d__1 = (uj + ui) / 2.;
    gop_(&c__1, uvcons, &d__1, &spv[104], j11, iret);
    goto L260;

/*  DISTANCE VALUES : */
L260:
    ab = qabpst_(spv, &spv[52], &spv[104]);
    if (ab <= tol2) {
	goto L270;
    }
    uj = (ui + uj) / 2.;
    goto L160;

/*  CONTROL OF THE LENGTH OF A CUT */
L270:
/* Computing 2nd power */
    d__1 = spv[52] - spv[0];
/* Computing 2nd power */
    d__2 = spv[53] - spv[1];
/* Computing 2nd power */
    d__3 = spv[54] - spv[2];
    vl1 = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);

    if (vl1 <= *vl) {
	goto L280;
    }
    du = du * *vl * .9 / vl1;
    goto L64;

/*  CONTROL OF THE TURNING POINT */
L280:
    if ((spv[it + 1] * spv[it + 106] - spv[it + 2] * spv[it + 105]) * (spv[it 
	    + 105] * spv[it + 54] - spv[it + 106] * spv[it + 53]) + (spv[it + 
	    2] * spv[it + 104] - spv[it] * spv[it + 106]) * (spv[it + 106] * 
	    spv[it + 52] - spv[it + 104] * spv[it + 54]) + (spv[it] * spv[it 
	    + 105] - spv[it + 1] * spv[it + 104]) * (spv[it + 104] * spv[it + 
	    53] - spv[it + 105] * spv[it + 52]) >= 0.) {
	goto L290;
    } else {
	goto L285;
    }
L285:
    uj = (ui + uj) / 2.;
    goto L160;
L290:
    ui = uj;

/*  FINISHED ? */
    if (uj != *u2) {
	goto L1;
    }

/*  THE LAST POINT WILL BE OUTPUT IN THE CALLING PROGRAM */
    return 0;
} /* gochor_ */

#undef uvcons
#undef tol
#undef vl


