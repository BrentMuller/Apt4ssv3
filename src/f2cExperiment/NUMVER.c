/* NUMVER.f -- translated by f2c (version 20100827).
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
    doublereal com[36000];
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal dirmot[12]	/* was [3][4] */, gofeed[4], glfeed, reglda[2]
	    ;
    integer iretro[4], idirmo[4], icanin[4];
} cclear_;

#define cclear_1 cclear_

/* Table of constant values */

static integer c_b3 = -22820;
static integer c_b12 = -22821;

/* *** SOURCE FILE : M0012316.V02   *** */

/* Subroutine */ int numver_(doublereal *u1, doublereal *v1, doublereal *u2, 
	doublereal *v2, doublereal *adress, doublereal *uv, integer *nseg)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j, k;
    static doublereal u, v;
    static integer i1, j1;
    static doublereal w1[4], ab, hs[50], ab1, ab2, ab3, ab4, w1a[4];
#define can ((doublereal *)&_BLNK__1 + 40)
    static integer npt;
    static doublereal pos1, pos2;
    static integer npt1, lreg, mark[50];
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen);
    static integer ires, mark1;
    extern /* Subroutine */ int apt094_(integer *, doublereal *, integer *);
    static doublereal conv1, conv2;
#define canon ((doublereal *)&_BLNK__1)
    static integer nrege;
#define sscan ((doublereal *)&_BLNK__1 + 40)
    static integer ldaflg;
#define bcanon ((doublereal *)&_BLNK__1 + 40)
    extern /* Subroutine */ int getver_(doublereal *, doublereal *, integer *)
	    , setver_(doublereal *);


/* ROUTINE TO CALCULATE THE SECTIONS OF A SINGLE PATH, GIVEN IN */
/*  U/V-SPACE ON A GIVEN REGION. */


/* INPUT : (U1,V1) START POINT */
/*  -"-  : (U2,V2) END   POINT */
/*  -"-  : ADRESS  CANONICAL FORM OF SURFACE */
/* OUTPUT: UV(2,I) RESULT POSITIONS (U,V) OF INTERSECTIONS */
/*                 (I=2*NSEG) */
/*  -"-  : NSEG    NUMBER OF SEGMENTS FOUND */

/* CANONICAL FORM OF SURFACE */

/* RESULT POSITIONS (50 ELEMENTS ASSUMED) */

/* HELP-STORAGE FOR ORDERING THE POINT-SEQUENCE */
/*  DISTANCE OF UV(...,I) FROM (U1,V1) */

/* CROSSING CHARACTERISTIC: */
/*  AT THE CROSS-POINT BETWEEN THE GIVEN PATH AND THE REGION BOUNDARY */
/*  THE SITUATION >OUT TO IN< IS MARKED WITH 1, AND >IN TO OUT> WITH 2 */
/*  THE PRIMARY POINTS (U1,V1) AND (U2,V2) ARE MARKED WITH 0. */

/* BLANK COMMON */

/* STORAGE FOR GIVEN PATH IN UV-SPACE */

/*     UNLABELLED COMMON */

/* ---     SIZE OF BLANK COMMON IS ALLOCATED RIGHT HERE. */





/* COMMON FOR REGIONAL STARTUP AND RETRACT VALUES */

/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

    /* Parameter adjustments */
    uv -= 3;
    --adress;

    /* Function Body */
    ldaflg = 3;
    apt094_(&ldaflg, cclear_1.reglda, &lreg);

/* ADDRESSING WITH BLANK COMMON VARIABLE COM: */
    --lreg;

/* COMPARE SURFACE OF GIVEN REGION WITH THE SURFACE INVOLVED */
/*  IN THE CUT-SEQUENCE */
    i__ = (integer) _BLNK__1.com[lreg + 1];
    if (adress[1] == _BLNK__1.com[i__ - 1] && adress[2] == _BLNK__1.com[i__]) 
	    {
	goto L10;
    }

/* WARNING: ACTIVE REGION BELONGS NOT TO THE SURFACE INVOLVED */
/*          IN THIS MOTION (NO SEGMENTATION TAKES PLACE) */
    aerr_(&c_b3, "NUMVER  ", (ftnlen)8);
    uv[3] = *u1;
    uv[4] = *v1;
    uv[5] = *u2;
    uv[6] = *v2;
    return 0;

/* PRESENT INTERSECTION ROUTINE WITH GIVEN SINGLE PATH */
L10:
    w1[0] = *u1;
    w1[1] = *v1;
    w1[2] = *u2 - *u1;
    w1[3] = *v2 - *v1;

/* RESET RESULT POSITIONS UV WITH THE START AND END POINT */
    uv[3] = *u1;
    uv[4] = *v1;
    uv[5] = *u2;
    uv[6] = *v2;

    mark[0] = 0;
    mark[1] = 0;
    hs[0] = 0.;
/* Computing 2nd power */
    d__1 = *u2 - *u1;
/* Computing 2nd power */
    d__2 = *v2 - *v1;
    hs[1] = d__1 * d__1 + d__2 * d__2;

/* OUTSIDE POINTS */
    ab1 = (_BLNK__1.com[lreg + 4] - *u1) * w1[2] + (_BLNK__1.com[lreg + 6] - *
	    v1) * w1[3];
    ab2 = (_BLNK__1.com[lreg + 5] - *u1) * w1[2] + (_BLNK__1.com[lreg + 6] - *
	    v1) * w1[3];
    ab3 = (_BLNK__1.com[lreg + 5] - *u1) * w1[2] + (_BLNK__1.com[lreg + 7] - *
	    v1) * w1[3];
    ab4 = (_BLNK__1.com[lreg + 4] - *u1) * w1[2] + (_BLNK__1.com[lreg + 7] - *
	    v1) * w1[3];

/* MINIMUM OUTSIDE POINT */
/* Computing MIN */
    d__1 = min(ab1,ab2), d__1 = min(d__1,ab3), d__1 = min(d__1,ab4);
    hs[2] = min(d__1,hs[0]) - 1.;
    uv[7] = w1[0] + w1[2] * hs[2] / hs[1];
    uv[8] = w1[1] + w1[3] * hs[2] / hs[1];

/* MAXIMUM OUTSIDE POINT */
/* Computing MAX */
    d__1 = max(ab1,ab2), d__1 = max(d__1,ab3), d__1 = max(d__1,ab4);
    hs[3] = max(d__1,hs[1]) + 1.;
    uv[9] = w1[0] + w1[2] * hs[3] / hs[1];
    uv[10] = w1[1] + w1[3] * hs[3] / hs[1];
    w1a[0] = uv[7];
    w1a[1] = uv[8];
    w1a[2] = uv[9] - uv[7];
    w1a[3] = uv[10] - uv[8];
    setver_(w1a);

/* SET OUT TO IN */
    mark[2] = 1;
    mark[3] = 2;
    if (_BLNK__1.com[lreg + 3] == 1.) {
	goto L15;
    }

/* SET OUT TO IN, IF REGION/...IN */
    mark[2] = 2;
    mark[3] = 1;
L15:
    npt = 4;

/* CALCULATE INTERSECTIONS */
/*  NUMBER OF ELEMENTS */
    nrege = (integer) _BLNK__1.com[lreg + 2];
    i__1 = nrege;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = lreg + 5 + (i__ << 2);
	getver_(&_BLNK__1.com[j - 1], &uv[(npt + 1 << 1) + 1], &ires);
	if (ires == 0) {
	    goto L80;
	}
	if (ires != 1) {
	    goto L30;
	}

/* SINGLE POINT FOUND, >OUT TO IN< OR >IN TO OUT< IS TO BE DETERMINED */
	++npt;
	mark[npt - 1] = 1;
	hs[npt - 1] = (uv[(npt << 1) + 1] - *u1) * w1[2] + (uv[(npt << 1) + 2]
		 - *v1) * w1[3];
	if (_BLNK__1.com[j + 1] * (uv[8] - _BLNK__1.com[j]) - _BLNK__1.com[j 
		+ 2] * (uv[7] - _BLNK__1.com[j - 1]) > 0. || _BLNK__1.com[j + 
		1] * (uv[10] - _BLNK__1.com[j]) - _BLNK__1.com[j + 2] * (uv[9]
		 - _BLNK__1.com[j - 1]) < 0.) {
	    goto L80;
	}

/* MUST BE >IN TO OUT< */
	mark[npt - 1] = 2;

/* PATH NEAR PARALLEL TO SEGMENT */
L30:
	if (ires != 2) {
	    goto L80;
	}

/* CONCAVE/CONVEX CONDITION ON 1ST COMER OF */
/*  REGION SEGMENT INVOLVED (CONCAVE IF NEGATIVE) */
	i1 = i__ - 1;
	if (i1 == 0) {
	    i1 = nrege;
	}
	j1 = lreg + 5 + (i1 << 2);
	conv1 = _BLNK__1.com[j + 1] * _BLNK__1.com[j1 + 2] - _BLNK__1.com[j + 
		2] * _BLNK__1.com[j1 + 1];

/* CONCAVE/CONVEX CONDITION ON 2ND CCSSER OF */
/*  REGION SEGMENT INVOLVED */
	i1 = i__ - 1;
	if (i1 > nrege) {
	    i1 = 1;
	}
	j1 = lreg + 5 + (i1 << 2);
	conv2 = _BLNK__1.com[j1 + 1] * _BLNK__1.com[j + 2] - _BLNK__1.com[j1 
		+ 2] * _BLNK__1.com[j + 1];

/* NO MARK, IF BOTH SEGMENT ENDS ARE CONCAVE */
	if (conv1 < 0. && conv2 < 0.) {
	    goto L80;
	}

/* POSITION OF INPUT POINTS ON GIVEN REGION SEGMENT */
/* Computing 2nd power */
	d__1 = _BLNK__1.com[j + 1];
/* Computing 2nd power */
	d__2 = _BLNK__1.com[j + 2];
	ab = d__1 * d__1 + d__2 * d__2;
	pos1 = ((uv[7] - _BLNK__1.com[j - 1]) * _BLNK__1.com[j + 1] + (uv[8] 
		- _BLNK__1.com[j]) * _BLNK__1.com[j + 2]) / ab;
	pos2 = ((uv[9] - _BLNK__1.com[j - 1]) * _BLNK__1.com[j + 1] + (uv[10] 
		- _BLNK__1.com[j]) * _BLNK__1.com[j + 2]) / ab;

/*   NO POINT IF BOTH POINTS ARE ON SEGMENT */
	if (pos1 >= 0. && pos1 <= 1. && pos2 >= 0. && pos2 <= 1.) {
	    goto L80;
	}

/*   PARALLEL OR ANTIPARALLEL */
	if (pos2 > pos1) {
	    goto L40;
	}

/*   SINGL PATH AND SEGMENT ARE PARALLEL */
/*    1. POINT */
	if (pos1 >= 0. || conv1 > 0.) {
	    goto L35;
	}
	++npt;
	mark[npt - 1] = 2;
	uv[(npt << 1) + 1] = _BLNK__1.com[j - 1];
	uv[(npt << 1) + 2] = _BLNK__1.com[j];
	hs[npt - 1] = (uv[(npt << 1) + 1] - *u1) * w1[2] + (uv[(npt << 1) + 2]
		 - *v1) * w1[3];
/*    2. POINT */
L35:
	if (pos2 <= 1. || conv2 > 0.) {
	    goto L80;
	}
	++npt;
	mark[npt - 1] = 1;
	uv[(npt << 1) + 1] = _BLNK__1.com[j - 1] + _BLNK__1.com[j + 1];
	uv[(npt << 1) + 2] = _BLNK__1.com[j] + _BLNK__1.com[j + 2];
	hs[npt - 1] = (uv[(npt << 1) + 1] - *u1) * w1[2] + (uv[(npt << 1) + 2]
		 - *v1) * w1[3];
	goto L80;
/*   SINGL PATH AND SEGMENT ARE ANTIPARALLEL */
/*    1. POINT */
L40:
	if (pos1 <= 1. || conv2 > 0.) {
	    goto L45;
	}
	++npt;
	mark[npt - 1] = 2;
	uv[(npt << 1) + 1] = _BLNK__1.com[j - 1] + _BLNK__1.com[j + 1];
	uv[(npt << 1) + 2] = _BLNK__1.com[j] + _BLNK__1.com[j + 2];
	hs[npt - 1] = (uv[(npt << 1) + 1] - *u1) * w1[2] + (uv[(npt << 1) + 2]
		 - *v1) * w1[3];
/*    2. POINT */
L45:
	if (pos2 >= 0. || conv1 > 0.) {
	    goto L80;
	}
	++npt;
	mark[npt - 1] = 1;
	uv[(npt << 1) + 1] = _BLNK__1.com[j - 1];
	uv[(npt << 1) + 2] = _BLNK__1.com[j];
	hs[npt - 1] = (uv[(npt << 1) + 1] - *u1) * w1[2] + (uv[(npt << 1) + 2]
		 - *v1) * w1[3];
	goto L80;

/*   CHECK IF NOT MORE THAN 50 SEGMENT END POINTS */
L80:
	if (npt < 49) {
	    goto L90;
	}

/* WARNING : MORE THAN 24 SEGMENTS TO BE PROCESSED (REST IS SCIPPED) */
	aerr_(&c_b12, "NUMVER  ", (ftnlen)8);
	goto L95;
L90:
	;
    }

/*  SORT THE RESULTS */
L95:
    npt1 = npt - 1;
    i__1 = npt1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k = i__;
	i1 = i__ + 1;
	i__2 = npt;
	for (j = i1; j <= i__2; ++j) {
	    if (hs[k - 1] <= hs[j - 1]) {
		goto L100;
	    }
	    k = j;
L100:
	    ;
	}
	if (k == i__) {
	    goto L110;
	}
	u = uv[(i__ << 1) + 1];
	v = uv[(i__ << 1) + 2];
	ab = hs[i__ - 1];
	mark1 = mark[i__ - 1];
	uv[(i__ << 1) + 1] = uv[(k << 1) + 1];
	uv[(i__ << 1) + 2] = uv[(k << 1) + 2];
	hs[i__ - 1] = hs[k - 1];
	mark[i__ - 1] = mark[k - 1];
	uv[(k << 1) + 1] = u;
	uv[(k << 1) + 2] = v;
	hs[k - 1] = ab;
	mark[k - 1] = mark1;
L110:
	;
    }
/*  TEST ************************************************************** */
/*     NSEG=0 */
/*     WRITE(6,200)NSEG,NPT,(UV(1,I),UV(2,I),MARK(I),HS(I),I=1,NPT) */
/*  TEST ************************************************************** */

/*  SEARCH FOR START POINT */
    i__1 = npt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (mark[i__ - 1] != 0) {
	    goto L120;
	}

/*  NO PATH IN REGION IF PREVIOUS POINT IS >IN TO OUT< (2) */
/*                    AND NEXT POINT IS THE GIVEN END POINT OF PATH */
	if (mark[i__ - 2] == 2 && mark[i__] == 0) {
	    goto L150;
	}

/*  CASE: PREVIOUS POINT IS >OUT TO IN< (1) */
	npt1 = i__;
	mark[i__ - 1] = 1;
	if (mark[i__ - 2] == 1) {
	    goto L125;
	}

/*  CASE: NEXT POINT IS >OUT TO IN< (1) */
	npt1 = i__ + 1;
	goto L125;
L120:
	;
    }
L125:

/*  COMPRESS DATA */
    i__1 = npt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	uv[(i__ << 1) + 1] = uv[(npt1 << 1) + 1];
	uv[(i__ << 1) + 2] = uv[(npt1 << 1) + 2];
	mark[i__ - 1] = mark[npt1 - 1];

/*   CHECK FOR THE END POINT OF THE PATH */
	if (mark[npt1 - 1] != 0) {
	    goto L130;
	}

/* THIS IS NO END POINT OF THE PATH IF THE PREVIOUS POINT IS >IN TO OUT< */
	mark[i__ - 1] = 2;
	npt1 = i__;
	if (mark[i__ - 2] == 2) {
	    --npt1;
	}
	goto L135;
L130:
	++npt1;
    }
L135:

/*  CHECK THE >OUT TO IN< AND >IN TO OUT< SEQUENCE */
    *nseg = 0;
    i__1 = npt1;
    for (i__ = 1; i__ <= i__1; i__ += 2) {
	if (mark[i__ - 1] == 1 && mark[i__] == 2) {
	    goto L140;
	}
	goto L150;
L140:
	++(*nseg);
    }
    goto L999;

/*  NO PATH IN REGION */
L150:
    *nseg = 0;

L999:
    return 0;
} /* numver_ */

#undef bcanon
#undef sscan
#undef canon
#undef can


