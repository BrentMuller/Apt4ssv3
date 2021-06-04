/* APT074.f -- translated by f2c (version 20100827).
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
    doublereal a[24]	/* was [12][2] */, ahold[8]	/* was [2][4] */, c1[
	    8], ln1[5], r__[10], ref[8]	/* was [2][4] */;
} def_;

#define def_1 def_

struct {
    doublereal c__[7], g[10], l[4], p[16], sc[16], t[12], t1[12], v[10];
} dshar3_;

#define dshar3_1 dshar3_

struct {
    doublereal z0, z1, z2, z3, z5, z10, z90, z1e6, z1e38, z5em1, z6em1, z9em1,
	     z11em1, z12em1, z1em2, z1em3, z1em5, z5em6, z1em6, z1em7, z1em9, 
	    z1em1, zm1, degrad, pi;
} znumbr_;

#define znumbr_1 znumbr_

struct {
    logical jcs, prnton, refflg, subflg, unflag, zflag, jds, boundf, pchlst, 
	    canflg, bnderr, tabprt, refmot, altmlt;
} ldef_;

#define ldef_1 ldef_

struct {
    integer ldasiz, ierror, surfad[4], kwrdsz, iblk1;
} idef_;

#define idef_1 idef_

struct {
    integer k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k12, k13, k15, k16, 
	    k18, k19, k23, k24, k25, k26, k27, k29, k30, k31, k32, k33, k34, 
	    k44, k45, k46, k47, k48, k50, k51, k52, k1013, k1e4, k1e6, km1;
} knumbr_;

#define knumbr_1 knumbr_

/* Table of constant values */

static integer c__71 = 71;

/* *** SOURCE FILE : M0002803.V03   *** */


/* .....FORTRAN SUBROUTINE           APT074        2/69      SR */

/*              FORTRAN SUBROUTINE APT074 */

/* PURPOSE      TO GENERATE THE CANONICAL FORM OF A CONIC */
/*              DEFINED BY ONE OF THE FOLLOWING APT STATEMENTS */
/*              RESULT = LCONIC/5PT,P1,P2,P3,P4,P5 */
/*              RESULT = LCONIC/5PT,X1,Y1,X2,Y2,X3,Y3,X4,Y4,X5,Y5 */
/*              RESULT = LCONIC/4PT1SL,P1,S1,P2,P3,P4 */
/*              RESULT = LCONIC/4PT1SL,X1,Y1,S1,X2,Y2,X3,Y3,X4,Y4 */
/*              RESULT = LCONIC/3PT2SL,P1,S1,P2,S2,P3 */
/*              RESULT = LCONIC/3PT2SL,X1,Y1,S1,X2,Y2,S2,X3,Y3 */

/* LINKAGE      CALL APT074(RESULT,MN,PP1,PP2,PP3,PP4,PP5) */

/* ARGUMENTS    RESULT  ARRAY TO CONTAIN THE CANONICAL FORM OF THE */
/*                      RESULTING CONIC */
/*              MN      INTEGER EQUIVALENT OF THE MODIFIER */
/*                      5PT = 1   4PT1SL = 2   3PT2SL = 3 */
/*              PP1     ARRAY CONTAINING THE CANONICAL FORM OF AN */
/*                      INPUT POINT */
/*              PP2     ARRAY CONTAINING THE CANONICAL FORM OF AN */
/*                      CANONICAL FORM OF AN INPUT POINT */
/*              PP3     ARRAY CONTAINING THE CANONICAL FORM OF AN */
/*                      INPUT POINT */
/*              PP4     ARRAY CONTAINING THE CANONICAL FORM OF AN */
/*                      CANONICAL FORM OF AN INPUT POINT */
/*              PP5     ARRAY CONTAINING THE CANONICAL FORM OF AN */
/*                      INPUT POINT */

/* SUBSIDIARIES TYPE                ENTRY */
/*              SUBROUTINE          APT079 */
/*              SUBROUTINE          DEFEXT */
/*              SUBROUTINE          ERROR */
/*              SUBROUTINE          TRANSF */
/*              REAL FUNCTION       DABS */
/*              REAL FUNCTION       DSQRT */

/* Subroutine */ int apt074_(doublereal *result, integer *mn, doublereal *pp1,
	 doublereal *pp2, doublereal *pp3, doublereal *pp4, doublereal *pp5)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal s[4], p1[3], p2[3], p3[3], p4[3], p5[3], aa[4], bb[4], 
	    cc[4], sr[2], det, div;
    extern /* Subroutine */ int apt079_(doublereal *, integer *), error_(
	    integer *, char *, ftnlen), defext_(doublereal *), transf_(
	    doublereal *, doublereal *, integer *, integer *, integer *);




/*    THE ORIGINAL COMMON-DIMENSION-EQUIVALENCE (CDE) PACKAGE TOTAL */
/*    HAS BEEN REPLACED BY INDIVIDUAL COMMON BLOCKS, AND EQUIVALENCE */
/*    STATEMENTS HAVE BEEN ELIMINATED AS FAR AS POSSIBLE. */


/*   ***  2.  DEF BLOCK    *** */

/*   REAL VARIABLES USED BY DEFINITION ROUTINES */
/*   WHICH MUST REMAIN INVIOLATE */




/*   ***  3.  DSHARE BLOCK 3  *** */

/*   USED FOR REAL VARIABLES AND SHARED WITH ARELEM */





/*   ***  10.  ZNUMBR BLOCK  *** */

/*   REAL LITERALS */




/*   ***  11.  LDEF BLOCK  *** */

/*   LOGICAL VARIABLES WHICH MUST REMAIN INVIOLATE */




/*   ***  14.  IDEF BLOCK  *** */

/*   INVIOLATE INTEGER VARIABLES */





/*   ***  19.  KNUMBR BLOCK  *** */

/*      INTEGER LITERALS */



    /* Parameter adjustments */
    --pp5;
    --pp4;
    --pp3;
    --pp2;
    --pp1;
    --result;

    /* Function Body */
    for (i__ = 1; i__ <= 4; ++i__) {
	switch (i__) {
	    case 1:  goto L100;
	    case 2:  goto L200;
	    case 3:  goto L300;
	    case 4:  goto L400;
	}
L100:
	transf_(p1, &pp1[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.k0);
	if (ldef_1.unflag) {
	    goto L910;
	}
	transf_(p3, &pp3[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.k0);
	if (ldef_1.unflag) {
	    goto L910;
	}
	transf_(p5, &pp5[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.k0);
	if (ldef_1.unflag) {
	    goto L910;
	}
	if (*mn != knumbr_1.k1) {
	    goto L110;
	}
	transf_(p2, &pp2[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.k0);
	if (ldef_1.unflag) {
	    goto L910;
	}
	sr[0] = p2[1] - p1[1];
	sr[1] = p2[0] - p1[0];
	goto L500;

/*        4PT1SL OR 3PT2SL FORMAT */
/*        OBTAIN FIRST SLOPE FROM P2(1), SET P2 = P1 */

L110:
	s[i__ - 1] = pp2[1];
	p2[0] = p1[0];
	p2[1] = p1[1];
	goto L600;
L200:
	if (*mn == knumbr_1.k3) {
	    goto L210;
	}
	transf_(p4, &pp4[1], &knumbr_1.k2, &knumbr_1.k3, &knumbr_1.k0);
	if (ldef_1.unflag) {
	    goto L910;
	}
	sr[0] = p5[1] - p4[1];
	sr[1] = p5[0] - p4[0];
	goto L500;

/*        3PT2SL FORMAT */
/*        OBTAIN SECOND SLOPE FROM P4(1), SET P4 = P5 */

L210:
	s[i__ - 1] = pp4[1];
	for (j = 1; j <= 2; ++j) {
	    p4[j - 1] = p3[j - 1];
	    p3[j - 1] = p5[j - 1];
/* L220: */
	    p5[j - 1] = p4[j - 1];
	}
	goto L600;
L300:
	sr[0] = p4[1] - p1[1];
	sr[1] = p4[0] - p1[0];
	goto L500;
L400:
	sr[0] = p5[1] - p2[1];
	sr[1] = p5[0] - p2[0];
/*        COMPUTE THE I TH SLOPE, S(I) */

L500:
	if (sr[0] == znumbr_1.z0 && sr[1] == znumbr_1.z0) {
	    goto L900;
	}
	if (abs(sr[0]) > abs(sr[1]) * znumbr_1.z1e6) {
	    goto L510;
	}
	s[i__ - 1] = sr[0] / sr[1];
	goto L600;
L510:
	s[i__ - 1] = sr[0] / abs(sr[0]) * znumbr_1.z1e6;

/*        COMPUTE COEFFICIENTS AA(I), BB(I), CC(I), OF THE EQUATION */
/*        OF THE I TH LINE */

L600:
	div = znumbr_1.z1;
	if ((d__1 = s[i__ - 1], abs(d__1)) > znumbr_1.z1) {
/* Computing 2nd power */
	    d__2 = s[i__ - 1];
	    div = sqrt(d__2 * d__2 + znumbr_1.z1);
	}
	aa[i__ - 1] = s[i__ - 1] / div;
	bb[i__ - 1] = znumbr_1.zm1 / div;
	if ((d__1 = bb[i__ - 1], abs(d__1)) < znumbr_1.z1em6) {
	    bb[i__ - 1] = znumbr_1.z0;
	}
/* L620: */
	if (i__ == knumbr_1.k2 || i__ == knumbr_1.k4) {
	    goto L630;
	}
	cc[i__ - 1] = -aa[i__ - 1] * p1[0] - bb[i__ - 1] * p1[1];
	goto L700;
L630:
	cc[i__ - 1] = -aa[i__ - 1] * p5[0] - bb[i__ - 1] * p5[1];
L700:
	;
    }

/*        COMPUTE COEFFICIENTS OF THE QUADRIC EQUATION */

    sr[0] = (aa[2] * p3[0] + bb[2] * p3[1] + cc[2]) * (aa[3] * p3[0] + bb[3] *
	     p3[1] + cc[3]);
    sr[1] = -(aa[0] * p3[0] + bb[0] * p3[1] + cc[0]) * (aa[1] * p3[0] + bb[1] 
	    * p3[1] + cc[1]);
    def_1.r__[0] = sr[0] * aa[0] * aa[1] + sr[1] * aa[2] * aa[3];
    def_1.r__[1] = sr[0] * bb[0] * bb[1] + sr[1] * bb[2] * bb[3];
    def_1.r__[2] = znumbr_1.z0;
    def_1.r__[3] = sr[0] * cc[0] * cc[1] + sr[1] * cc[2] * cc[3];
    def_1.r__[4] = znumbr_1.z0;
    def_1.r__[5] = znumbr_1.z0;
    def_1.r__[6] = znumbr_1.z5em1 * (sr[0] * (bb[0] * aa[1] + aa[0] * bb[1]) 
	    + sr[1] * (bb[2] * aa[3] + aa[2] * bb[3]));
    def_1.r__[7] = znumbr_1.z5em1 * (sr[0] * (cc[0] * aa[1] + aa[0] * cc[1]) 
	    + sr[1] * (cc[2] * aa[3] + aa[2] * cc[3]));
    def_1.r__[8] = znumbr_1.z5em1 * (sr[0] * (cc[0] * bb[1] + bb[0] * cc[1]) 
	    + sr[1] * (cc[2] * bb[3] + bb[2] * cc[3]));
    def_1.r__[9] = znumbr_1.z0;
/* Computing 2nd power */
    d__1 = def_1.r__[7];
/* Computing 2nd power */
    d__2 = def_1.r__[6];
/* Computing 2nd power */
    d__3 = def_1.r__[8];
    det = def_1.r__[0] * def_1.r__[1] * def_1.r__[3] - def_1.r__[1] * (d__1 * 
	    d__1) - def_1.r__[3] * (d__2 * d__2) - def_1.r__[0] * (d__3 * 
	    d__3) + def_1.r__[6] * 2 * def_1.r__[7] * def_1.r__[8];

/*        PRINT WARNING IF THIS IS A DEGENERATE CONIC */

    if (abs(det) < znumbr_1.z1em9) {
	error_(&c__71, "APT074  ", (ftnlen)8);
    }
/* Computing MAX */
    d__2 = max(def_1.r__[0],def_1.r__[1]), d__2 = max(d__2,def_1.r__[3]), 
	    d__2 = max(d__2,def_1.r__[6]), d__2 = max(d__2,def_1.r__[7]);
    if ((d__1 = det / max(d__2,def_1.r__[8]), abs(d__1)) < znumbr_1.z1em9 && 
	    abs(det) >= znumbr_1.z1em9) {
	error_(&c__71, "APT074  ", (ftnlen)8);
    }

/*        TRANSFORM TO BASE SYSTEM AND STORE ANSWER IN RESULT */

    apt079_(def_1.r__, &knumbr_1.km1);
L800:
    defext_(&result[1]);
    return 0;

/*        ERROR - TWO INPUT POINTS COINCIDE */

L900:
    idef_1.ierror = 70;
    goto L800;

/*        ERROR - INPUT POINT IS UNDEFINED */

L910:
    idef_1.ierror = 69;
    goto L800;
} /* apt074_ */

