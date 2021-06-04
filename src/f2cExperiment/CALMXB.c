/* CALMXB.f -- translated by f2c (version 20100827).
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
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

/* *** SOURCE FILE : CALMXB.ORG   *** */

/* Subroutine */ int calmxb_(doublereal *rs, doublereal *tul, doublereal *w, 
	doublereal *u, doublereal *sn, doublereal *beta, logical *lret)
{
    /* Builtin functions */
    double sqrt(doublereal), asin(doublereal);

    /* Local variables */
    static doublereal a, b, c__, b1, b2, d1, sb1, sb2, disc, cphi, bnew;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal sphi;


/*     PURPOSE: TO COMPUTE MAXIMUM TILT ANGLE WHERE TOOL WILL FIT */
/*              INTO CONCAVE SURFACE */

/*     ARGUMENTS: */
/*       RS     - MINIMUM RADIUS OF CURVATURE OF SURFACE AT CONTACT POINT */
/*       TUL    - TOOL GEOMETRY */
/*       W      - ORIGINAL TOOL AXIS */
/*       U      - LOCAL AXIS DIRECTION ORTHOGONAL TO W IN DIRECTION */
/*                OF POSITIVE TILT */
/*       SN     - SURFACE NORMAL AT POINT OF CONTACT (TOWARDS TOOL) */
/*       BETA   - TILT ANGLE */
/*                  VALUE ON INPUT WILL BE IDEAL TILT TO CLEAR SURFACE */
/*                  AND WILL BE USED TO DETERMINE WHICH OF THE */
/*                  TWO ALTERNATIVE IS TO BE RETURNED AS THE MAXIMUM */
/*       LRET   - RETURN FLAG = .TRUE. - COMPUTED OK, ELSE .FALSE. */


/*     GLOBAL VARIABLES: */


/*     LOCAL VARIABLES: */

/*       SPHI     - SIN(PHI)   WHERE PHI IS ANGLE BETWEEN TA AND SN */
/*       CPHI     - COS(PHI)   WHEN TOOL AND SURFACE CURVATURES MATCH */
/*       A,B,C,D1 - WORK VARIABLES */
/*       DISC     - DISCRIMINANT OF QUADRATIC EQUATION */
/*       SB1,SB2  - TWO POSSIBLE VALUES FOR SIN(BETA) */
/*       B1,B2    - TWO POSSIBLE VALUES OF BETA */
/*       BNEW     - NEW VALUE OF BEAT */


/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/* .... COMPUTE SINE OF ANGLE BETWEEN TOOL AXIS (W) AND SN SUCH THAT */
/*     TOOL CURVATURE WILL FIT SURFACE CURVATURE AT POINT OF CONTACT */

    /* Parameter adjustments */
    --sn;
    --u;
    --w;
    --tul;

    /* Function Body */
    sphi = tul[3] / (*rs - tul[1]);
    a = znumbr_1.z1 - sphi * sphi;
    if (abs(a) <= znumbr_1.z1em6) {
	cphi = znumbr_1.z1;
    } else {
	cphi = sqrt(a);
    }

/* .... BETA HAS TO SATISFY TWO EQUATIONS */

/*      TA = COS(BETA)*W + SIN(BETA)*U   (1) */
/*      TA.SN = COS(PHI)                 (2) */

/*      TAKING SN DOT (1) AND SUBSTITUTING FOR TA.SN, RESULTS IN */

/*      COS(PHI)=COS(BETA)*(W.SN)+SIN(BETA)*(U.SN) */

/*                                       2 */
/*      SQUARING AND SUBSTITUTING FOR COS (BETA) */
/*      WILL GIVE A QUADRATIC IN SIN(BETA) - HENCE BETA */

    dotf_(&a, &w[1], &sn[1]);
    dotf_(&b, &u[1], &sn[1]);

    d1 = a * a + b * b;
    disc = d1 - cphi * cphi;

    if (disc > znumbr_1.z1em6 && d1 > znumbr_1.z1em6) {

	c__ = sqrt(disc);

	sb1 = (b * cphi + a * c__) / d1;
	sb2 = (b * cphi - a * c__) / d1;
	b1 = asin(sb1);
	b2 = asin(sb2);

/* .... SELECT APPROPRIATE SOLUTION DEPENDENT ON IDEAL BETA TO CLEAR SURF */

	if (*beta > znumbr_1.z0) {
	    bnew = max(b1,b2);
	    if (bnew > znumbr_1.z0) {
		*beta = bnew;
		*lret = TRUE_;
	    } else {
		*beta = znumbr_1.z0;
		*lret = FALSE_;
	    }
	} else if (*beta < znumbr_1.z0) {
	    bnew = min(b1,b2);
	    if (bnew < znumbr_1.z0) {
		*beta = bnew;
		*lret = TRUE_;
	    } else {
		*beta = znumbr_1.z0;
		*lret = FALSE_;
	    }
	} else {
	    *beta = znumbr_1.z0;
	    *lret = FALSE_;
	}
    } else {
/* .... NO SOLUTION TO QUADRATIC */
	*beta = znumbr_1.z0;
	*lret = FALSE_;
    }

    return 0;
} /* calmxb_ */

