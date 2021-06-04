/* PUVLOC.f -- translated by f2c (version 20100827).
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

struct {
    integer ichekf;
} chekfl_;

#define chekfl_1 chekfl_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static integer c_n1 = -1;

/* *** SOURCE FILE : M0001084.W02   *** */

/* Subroutine */ int puvloc_(doublereal *bmat, doublereal *tp, doublereal *tn,
	 doublereal *ust, doublereal *vst, doublereal *dist, integer *mode, 
	integer *iflag)
{
    /* Initialized data */

    static doublereal big = 1e6;
    static doublereal plo = .005;
    static doublereal phi = .995;
    static integer ilev = 1;
    static integer nits = 1;
    static integer ifree = 0;
    static integer idebug = 0;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal d1, d2, du, dv;
    extern /* Subroutine */ int bad_();
    static doublereal dif[3];
    static integer irr;
    static doublereal spv[32];
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal zero;
    extern /* Subroutine */ int aprix_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *), cross_(doublereal *, doublereal *, 
	    doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int cprint_(char *, ftnlen), cnsurf_(doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *);


/* ---      PURPOSE IS TO DETERMINE STARTUP U,V VALUES AND APPROXIMATE */
/* ---      DISTANCE OF A PATCH FROM A TOOL RAY OR POINT. */
/* ---      SPECIAL ENTRY POINT PUVINT IS TO INITIALIZE PUV PARAMETERS */
/* ---      ENTRY PUVLOC PARAMETERS */
/* ---      INPUT TP   INPUT TOOL POINT */
/* ---      INPUT TN   INPUT TOOL RAY VECTOR(SHOULD BE UNITIZED) */
/* ---      INPUT MODE  =0 MEANS FIND CLOSEST POINT ON PATCH TO TP ONLY */
/* ---                  =1 MEANS FIND CLOSEST POINT TO POSITIVE TOOL RAY */
/* ---                  =-1 MEANS FIND CLOSEST POINT TO TOOL SPACE LINE. */
/* ---      INPUT ILEV  =1 MEANS USE FIRST ORDER DERIVATIVES ONLY */
/* ---                  =2 MEANS USE SECOND ORDER DERIVATIVES AS WELL */
/* ---      INPUT NITS  NUMBER OF ITERATIONS TO DETERMINE CLOSEST POINT */
/* ---      INPUT IFREE =0 MEANS NOT FREE - THAT IS KEEP SOLUTION WITHIN */
/* ---                  UNIT SUARE. =1 MEANS OBTAIN SOLUTION ANYWHERE. */

/* ---      INPUT BMAT COONS MATRIX COEFFICIENTS OR ELSE TYPE OF GENCUR */
/* ---            SURFACE */
/* ---      INPUT IFLAG FLAGS FOR TYPE OF COORDINATE MATRIX OR LOCATION */
/* ---            OF GENCUR DEFINING CURVES */
/* ---      OUTPUT UST,VST COMPUTED ROUGH LOCATION OF CLOSEST PATCH POINT */
/* ---      OUTPUT DIST COMPUTED DISTANCE BETWEEN PATCH AND POINT OR RAY. */




/* ---- FLAG INTRODUCED BY VW - USED TO DETERMINE 'CORRECT' SIDE OF CUTTER */



    /* Parameter adjustments */
    --iflag;
    --tn;
    --tp;
    --bmat;

    /* Function Body */

/* ---      MAIN ENTRY POINT FOR PUVLOC */

    i__1 = nits;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* ---      EVALUATE SURFACE POINT AND DERIVATIVES AT UST,VST */
	cnsurf_(ust, vst, &bmat[1], spv, &iflag[1], &c__1);

/* ---      CALL APRIX TO COMPUTE A CLOSER LINEUP */
	aprix_(&du, &dv, dist, spv, &tp[1], &tn[1], mode, &ilev, &irr, &
		idebug);
/* ---      IF AN ERROR OCCURRED THEN USE CURRENT SURFACE POINT */
	if (irr != 0) {
	    goto L60;
	}
/* ---      IF IFREE IS 0, THEN INSURE PARAMETERS ARE IN UNIT SQUARE */
	*ust += du;
	*vst += dv;
	if (ifree == 1) {
	    goto L10;
	}
/* ---      SELECT UST,VST IN UNIT SQUARE CLOSEST TO ESTIMATED UST,VST */
	*ust = max(*ust,plo);
	*ust = min(*ust,phi);
	*vst = max(*vst,plo);
	*vst = min(*vst,phi);

L10:
	;
    }

/* ---      NOW REEVALUATE SURFACE AT NEW UST,VST COORDINATES */
    cnsurf_(ust, vst, &bmat[1], spv, &iflag[1], &c__0);

/* ---      ITERATION COMPLETE, NOW COMPUTE EFFECTIVE DISTANCE */
L60:
/* ---      COMPUTE DIFFERENCE BETWEEN EFFECTIVE POINT AND TP */
    for (j = 1; j <= 3; ++j) {
/* L90: */
	dif[j - 1] = spv[j - 1] - tp[j];
    }

    if (*mode != 0) {
	goto L120;
    }
/* ---      CASE OF CLOSEST POINT, MODE=0 */
    dotv_(dist, dif, dif);
    *dist = sqrt(*dist);

    dotv_(&d1, dif, &tn[1]);
    dotv_(&d2, &spv[28], &tn[1]);
    if (d1 < zero && chekfl_1.ichekf == 1) {
	*dist = abs(*dist) * big;
    }
    goto L190;

L120:
/* ---      MODE=1 OR -1 */
    dotv_(&d1, dif, &tn[1]);
    if (*mode > 0) {
	goto L140;
    }
/* ---      MODE=-1 */
/* ---      DISTANCE IS NORMAL DISTANCE FROM CALCULATED POINT TO TOOL RAY */
    cross_(dif, &tn[1], dif);
    dotv_(dist, dif, dif);
    *dist = sqrt(*dist);
    if (d1 < zero && chekfl_1.ichekf == 1) {
	*dist = abs(*dist) * big;
    }
    goto L190;

L140:
/* ---      MODE=1 */
    if (d1 < zero) {
	*dist = abs(*dist) * big;
    }

L190:
/* ---      INCREASE DIST TO ADD A BIAS IN CASE AN ERROR OCCURRED EARLIER */
    if (irr > 0) {
	*dist *= big;
    }
/* ---      CALCULATION OF UST,VST,DIST IS COMPLETE */

/* L999: */

    if (ibugg_1.ibug != 2) {
	goto L998;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER PUVLOC", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "UST ", ust, (ftnlen)4);
    bad_(&c__1, &c__1, "VST ", vst, (ftnlen)4);
    bad_(&c_n1, &c__1, "DIST", dist, (ftnlen)4);

L998:
    return 0;
} /* puvloc_ */

