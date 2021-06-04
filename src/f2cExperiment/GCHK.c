/* GCHK.f -- translated by f2c (version 20100827).
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

static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : GCHK.V01   *** */

/* Subroutine */ int gchk_(doublereal *surf, doublereal *side, doublereal *
	r__, doublereal *te, doublereal *ta, integer *npat, doublereal *up, 
	doublereal *vp, doublereal *rl, doublereal *tel, doublereal *tal, 
	integer *npatl, doublereal *upl, doublereal *vpl, doublereal *tolcom, 
	doublereal *toli, doublereal *tolo, doublereal *gfac, integer *iret)
{
    /* Initialized data */

    static doublereal z1em10 = 1e-10;
    static doublereal zero = 0.;
    static doublereal one = 1.;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal rm[32], tn[3], tp[3];
    extern /* Subroutine */ int bad_();
    static doublereal dev[3], tpl[3], xtp[3], skrm, xtpl[3];
    static char badmsg[20];
    extern /* Subroutine */ int devcal_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal devmin, devmax, offset;
    extern /* Subroutine */ int midpnt_(doublereal *, integer *, doublereal *,
	     doublereal *, integer *, doublereal *, doublereal *, doublereal *
	    ), midkur_(doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *), xtpcal_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), cprint_(char *, ftnlen);







/* .... DEBUG FLAGS */


    /* Parameter adjustments */
    --tal;
    --tel;
    --rl;
    --ta;
    --te;
    --r__;
    --surf;

    /* Function Body */

/* .... COMPUTE PARAMETRIC MIDPINT */

    midpnt_(&surf[1], npat, up, vp, npatl, upl, vpl, rm);

/* .... COMPUTE SURFACE CURVATURE AT MIDPOINT IN CHORD DIRECTION */

    midkur_(rm, &r__[1], &rl[1], side, &skrm);

/* .... COMPUTE TOOL CONTACT POINT AT CURRENT AND LAST LOCATION */
/*     AND TOOL NORMAL AT MIDPOINT */

    offset = *tolcom * *side;
    for (i__ = 1; i__ <= 3; ++i__) {
	tp[i__ - 1] = r__[i__] + offset * r__[i__ + 28];
	tpl[i__ - 1] = rl[i__] + offset * rl[i__ + 28];
	tn[i__ - 1] = *side * rm[i__ + 27];
/* L10: */
    }

/* .... COMPUTE THE TWO TOOL POINTS, XTP AND XTPL THAT CORRESPOND */
/*     TO THE TOOL CONTACT POINT AT THE ALTERNATIVE TOOL LOCATION */

    xtpcal_(tp, &te[1], &ta[1], tpl, &tel[1], &tal[1], xtp, xtpl);

/* .... COMPUTE DEVIATION OF MIDPOINT FROM CHORD */
/*     BETWEEN TOOL CONTACT POINTS */

    devcal_(rm, tn, tp, tpl, dev);

/* .... COMPUTE DEVIATION OF MIDPOINT FROM CHORD */
/*     BETWEEN TOOL CONTACT POINT AND CORRESPONDING POINT (XTP OR XTPL) */
/*     FOR BOTH TOOL LOCATIONS */

    devcal_(rm, tn, tp, xtpl, &dev[1]);
    devcal_(rm, tn, tpl, xtp, &dev[2]);

/* .... COMPUTE MAXIMUM AND MINIMUM DEVIATION */

    devmax = zero;
    devmin = zero;
    for (i__ = 1; i__ <= 3; ++i__) {
	if (dev[i__ - 1] > devmax) {
	    devmax = dev[i__ - 1];
	}
	if (dev[i__ - 1] < devmin) {
	    devmin = dev[i__ - 1];
	}
/* L20: */
    }

/* .... IS THE APPROPRIATE TOLERANCE BAND VIOLATED */

    if (skrm > zero && abs(devmin) > *tolo) {
/* .... EXCESS MATERIAL WILL BE LEFT ON */
	*iret = -1;
/* .... COMPUTE STEP REDUCTION FACTOR */
	if (*tolo > z1em10) {
	    *gfac = *tolo / abs(devmin);
	    *gfac = min(*gfac,.95);
	} else {
	    *gfac = .75f;
	}
    } else if (skrm < zero && devmax > *toli) {
/* .... GOUGING OF SURFACE WILL OCCUR */
	*iret = 1;
/* .... COMPUTE STEP REDUCTION FACTOR */
	if (*toli > z1em10) {
	    *gfac = *toli / devmax;
	    *gfac = min(*gfac,.95);
	} else {
	    *gfac = .75f;
	}
    } else {
	*iret = 0;
	*gfac = one;
    }

    if (ibugg_1.ibug == 11) {
	s_copy(badmsg, " AFTER GCHK", (ftnlen)20, (ftnlen)11);
	cprint_(badmsg, (ftnlen)20);
	bad_(&c__1, &c__1, "SKRM", &skrm, (ftnlen)4);
	bad_(&c__1, &c__1, "TOLI", toli, (ftnlen)4);
	bad_(&c_n1, &c__1, "TOLO", tolo, (ftnlen)4);
	bad_(&c__1, &c__1, "DVMX", &devmax, (ftnlen)4);
	bad_(&c__1, &c__1, "DVMN", &devmin, (ftnlen)4);
	bad_(&c__1, &c__0, "IRET", iret, (ftnlen)4);
	bad_(&c_n1, &c__1, "GFAC", gfac, (ftnlen)4);
    }

    return 0;
} /* gchk_ */

