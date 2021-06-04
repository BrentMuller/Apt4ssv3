/* CALCB.f -- translated by f2c (version 20100827).
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
    doublereal dintr[1000], uintr[1000], vintr[1000], ldintr[1000], luintr[
	    1000], lvintr[1000], tpintr[3000]	/* was [3][1000] */, spintr[
	    3000]	/* was [3][1000] */, snintr[3000]	/* was [3][
	    1000] */;
    integer pintr[1000], lpintr[1000], iseg[1000], npintr, lnpint;
} interf_;

#define interf_1 interf_

/* Table of constant values */

static doublereal c_b9 = 1.;

/* *** SOURCE FILE : CALCB.V01   *** */

/* Subroutine */ int calcb_(doublereal *w, doublereal *fwd, doublereal *r__, 
	integer *intloc, doublereal *b, char *type__, doublereal *tl, ftnlen 
	type_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double acos(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal a[3], c__;
    static integer i__;
    static doublereal s[3], t[3], u[3], v[3], si, su, sv, phi, spa[3], tpa[3],
	     cphi;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    ), cross_(doublereal *, doublereal *, doublereal *), vnorm_(
	    doublereal *, doublereal *), crossv_(doublereal *, doublereal *, 
	    doublereal *);


/*     PURPOSE:  TO COMPUTE TILT ANGLE B TO AVOID INTERFERENCE */
/*               AT WORST LOCATION (INTLOC) */

/*     ARGUMENTS: */
/*       W      - AXIS THROUGH CONTACT POINT PARLLEL TO TA */
/*       FWD    - DS FORWARD DIRECTION */
/*       R      - SURFACE CONTACT POINT AND DERIVATIVES */
/*       INTLOC - LOCATION IN INTERFERENCE TABLE OF WORST PENETRATION */
/*       B      - TILT ANGLE TO CLEAR INTERFERENCE */
/*       TYPE   - TYPE OF TILT (ROLL OR PITCH) */
/*       TL     - APPROP. LOCAL AXIS THAT DEFINES PLANE OF TILT WITH TA */


/*     GLOBAL VARIABLES: */


/*     LOCAL VARIABLES: */

/*       U      - LOCAL AXIS IN FORWARD DIRECTION PERPTO W */
/*       V      - LOCAL AXIS ORTHOGONAL TO W AND U */
/*       S      - SPINTR AT INTLOC WRT LOCAL ORIGIN AT CONTACT POINT */
/*       T      - TPINTR AT INTLOC WRT LOCAL ORIGIN AT CONTACT POINT */
/*       SPA    - PROJECTION OF S ONTO WU PLANE */
/*       TPA    - PROJECTION OF T ONTO WU PLANE */
/*       CPHI   - COS(PHI) */
/*       PHI    - TILT ANGLE */
/*       A      - TPA X SPA */
/*       SI     - DIRECTION OF PHI (+VE IN FWD DIRECTION) */
/*       SU,SV  - PROJECTIONS OF S ONTO U AND V AXES */
/*       C      - WORK VARIABLE */


/*    INTERFERENCE TABLE */







/* .... COMPUTE LOCAL AXES AT CONTACT POINT */

    /* Parameter adjustments */
    --tl;
    --r__;
    --fwd;
    --w;

    /* Function Body */
    crossv_(&w[1], &fwd[1], v);
    crossv_(v, &w[1], u);

/* .... COMPUTE S,T */

    for (i__ = 1; i__ <= 3; ++i__) {
	s[i__ - 1] = interf_1.spintr[i__ + *intloc * 3 - 4] - r__[i__];
	t[i__ - 1] = interf_1.tpintr[i__ + *intloc * 3 - 4] - r__[i__];
/* L10: */
    }

/* .... PROJECT S ONTO LOCAL UV PLANE */

    dotf_(&su, s, u);
    dotf_(&sv, s, v);

    if (abs(sv) < 1e-6) {
	c__ = 1e6;
    } else {
	c__ = su / sv;
    }

/* .... SELECT DIRECTION OF TILT */

    if (abs(c__) >= 1.) {
/* .... PITCH TOOL - TILT ABOUT V */
	s_copy(type__, "PITCH", (ftnlen)5, (ftnlen)5);
	for (i__ = 1; i__ <= 3; ++i__) {
	    tl[i__] = u[i__ - 1];
/* L20: */
	}
    } else {
/* .... ROLL TOOL - TILT ABOUT U */
	s_copy(type__, "ROLL", (ftnlen)5, (ftnlen)4);
	for (i__ = 1; i__ <= 3; ++i__) {
	    tl[i__] = v[i__ - 1];
/* L30: */
	}
    }

/* .... PROJECT S,T ONTO LOCAL PLANE OF TILT */

    if (s_cmp(type__, "PITCH", (ftnlen)5, (ftnlen)5) == 0) {
	dotf_(spa, s, u);
	spa[1] = 0.;
	dotf_(tpa, t, u);
	tpa[1] = 0.;
    } else {
	spa[0] = 0.;
	dotf_(&spa[1], s, v);
	tpa[0] = 0.;
	dotf_(&tpa[1], s, v);
    }
    dotf_(&spa[2], s, &w[1]);
    dotf_(&tpa[2], t, &w[1]);

/* .... COMPUTE TILT ANGLE PHI */

    vnorm_(spa, spa);
    vnorm_(tpa, tpa);
    dotf_(&cphi, spa, tpa);
    phi = acos(cphi);

/* .... DETERMINE DIRECTION OF PHI */

    cross_(tpa, spa, a);
    if (s_cmp(type__, "PITCH", (ftnlen)5, (ftnlen)5) == 0) {
	dotf_(&si, a, v);
    } else {
	dotf_(&si, a, u);
    }
    si = d_sign(&c_b9, &si);

/* .... COMPUTE TILT ANGLE */

    *b = si * phi;

    return 0;
} /* calcb_ */

