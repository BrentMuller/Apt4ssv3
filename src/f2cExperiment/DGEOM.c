/* DGEOM.f -- translated by f2c (version 20100827).
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

static integer c__0 = 0;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c_n1 = -1;
static integer c_n4 = -4;

/* *** SOURCE FILE : M0001067.W02   *** */

/* Subroutine */ int dgeom_(doublereal *dsurf, integer *idtype, doublereal *u,
	 doublereal *v, integer *idaxis, doublereal *daxis, integer *itldir, 
	doublereal *tldir, doublereal *dtol, doublereal *dr, doublereal *u1, 
	doublereal *v1, integer *npat, doublereal *cx)
{
    /* Initialized data */

    static integer nlast = 0;
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal smal = 1e-38;
    static doublereal hsmal = 1e-19;
    static doublereal big = 1e10;
    static doublereal arecsv = 0.;
    static doublereal qsmal = 1e-6;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal b[64];
    static integer i__;
    static doublereal ck;
    extern /* Subroutine */ int bad_();
    static doublereal rad, vec[3], siz;
    static integer jacc, jlim, jtan;
    extern /* Subroutine */ int dotf_(doublereal *, doublereal *, doublereal *
	    );
    static integer jcrs, itop[24]	/* was [6][4] */;
    static doublereal step, tnsq;
    static integer iflag[6], icros;
    static doublereal vecsq;
    extern /* Subroutine */ int axset_(integer *, doublereal *, doublereal *, 
	    doublereal *);
    static integer jnorm;
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *);
    static char badmsg[20];
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), mescon_(doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     integer *), curflo_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *), cprint_(char *, ftnlen), cnsurf_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *);

/* --PURPOSE IS TO GENERATE ALL NECESSARY INFORMATION AT CURRENT */
/* --POINT U,V OF DRIVE GEOMETRY.  INPUT PARAMETERS ALL EXPLAINED */
/* --IN PATH */
/* --OUTPUT */
/* --DR  ARRAY CONTAINING ALL RELEVANT CURVE INFORMATION AT POINT U,V */
/* -- DR(1-3) = DRIVE GEOMETRY POINT */
/* -- DR(5-7) = DRIVE GEOMETRY TANSPL VECTOR */
/* -- DR(9-11) = DRIVE GEOMETRY SECOND DERIVATIVE */
/* -- DR(13-15) = DRIVE GEOMETRY UNIT TANGENT VECTOR */
/* -- DR(17-19) = TOOL AXIS ORIENTATION */
/* -- DR(21-23) = TOOL DIRECTION TOWARD PART SURFACE */
/* -- DR(25,26)  CURVATURE AND STEP SIZE BASED ON DTOL */
/* --- DR(27) = MAXIMUM STEP IN THE DRIVE SURFACE DIRECTION. */
/* -- DR(29-31) = CRSSPL TANGENT(IF AVAILABLE) */
/* -- DR(33-35) = DRIVE GEOMETRY SURFACE NORMAL(IF AVAILABLE) */

    /* Parameter adjustments */
    --cx;
    --dr;
    --tldir;
    --daxis;
    --dsurf;

    /* Function Body */

    for (i__ = 1; i__ <= 36; ++i__) {
/* L5: */
	dr[i__] = zero;
    }
/* --SEPARATE CURVE AND SURFACE CASES IMMEDIATLY */
    if (*idtype != 0) {
	goto L100;
    }
/* --SCURV DRIVE GEOMETRY.  EVALUATE CROSS DERIVS ONLY IF VARIABLE */
/* --TOOL AXIS OR DIRECTION IS REQUESTED */
    icros = 1;
    if (*itldir != 0 || *idaxis != 0) {
	icros = 2;
    }
    curflo_(u, &dsurf[1], &cx[1], &icros, &c__0);
    if (ibugg_1.ibug != 11) {
	goto L8809;
    }
    jlim = icros << 4;
    i__1 = -jlim;
    bad_(&i__1, &c__1, "CFLO", &cx[1], (ftnlen)4);
L8809:
    for (i__ = 1; i__ <= 16; ++i__) {
/* L10: */
	dr[i__] = cx[i__];
    }
/* --SET AXIS ACCORDING TO IDAXIS SETTING */
    if (abs(*idaxis) <= 1) {
	axset_(idaxis, &daxis[1], &cx[17], &dr[17]);
    } else {
	axset_(idaxis, &cx[13], &cx[17], &dr[17]);
    }
/* --SET THE TOOL DIRECTION NEXT */
    axset_(itldir, &tldir[1], &cx[17], &dr[21]);
    goto L200;

L100:
/* --CASE OF MESH STRUCTURED DRIVE SURFACE. */
    mescon_(&dsurf[1], u, v, npat, u1, v1, &c__1);
    if (nlast != *npat || dsurf[1] != arecsv) {
	lodpch_(&dsurf[1], b, iflag, itop, npat, &c__3);
    }
    nlast = *npat;
    arecsv = dsurf[1];
    cnsurf_(u1, v1, b, &cx[1], iflag, &c__1);
/* --PICK UP TANSPL FIRST AND SECOND DERIVATIVES IF IDTYPE=1 */
/* --PICK UP CRSSPL FIRST AND SECOND DERIVATIVES IF IDTYPE=2 */
    jtan = 4;
    if (*idtype == 2) {
	jtan = 8;
    }
    jacc = 12;
    if (*idtype == 2) {
	jacc = 20;
    }
    jcrs = 8;
    if (*idtype == 2) {
	jcrs = 4;
    }
    jnorm = 28;
    for (i__ = 1; i__ <= 4; ++i__) {
	dr[i__] = cx[i__];
	dr[i__ + 4] = cx[jtan + i__];
	dr[i__ + 8] = cx[jacc + i__];
	dr[i__ + 28] = cx[i__ + jcrs];
	dr[i__ + 32] = cx[i__ + jnorm];
/* L110: */
    }
    dotf_(&siz, &dr[5], &dr[5]);
    if (siz < smal) {
	goto L120;
    }
    siz = sqrt(siz);
    for (i__ = 1; i__ <= 3; ++i__) {
/* L130: */
	dr[i__ + 12] = dr[i__ + 4] / siz;
    }
    dr[16] = one;
L120:
/* --SET THE TOOL AXIS FIRST */
    if (abs(*idaxis) <= 1) {
	axset_(idaxis, &daxis[1], &cx[29], &dr[17]);
    } else {
	axset_(idaxis, &dr[29], &cx[29], &dr[17]);
    }
/* --SET THE TOOL DIRECTION NEXT */
    axset_(itldir, &tldir[1], &cx[29], &dr[21]);

L200:
/* --COMPUTE CURVATURE AND STEP SIZE OF CURVE AT THIS POINT */

    dotf_(&tnsq, &dr[5], &dr[5]);
    if (tnsq < hsmal) {
	goto L230;
    }

    cross_(&dr[5], &dr[9], vec);
    dotf_(&vecsq, vec, vec);
    if (vecsq < smal) {
	goto L230;
    }
/* Computing 3rd power */
    d__1 = sqrt(tnsq);
    ck = sqrt(vecsq) / (d__1 * (d__1 * d__1));
    if (ck > hsmal) {
	goto L240;
    }
L230:
/* --CURVATURE IS VERY SLIGHT */
    ck = zero;
    step = big;
    goto L300;

L240:
    rad = one / ck;
    step = (rad + rad - *dtol) * *dtol;
    if (step < qsmal) {
	goto L230;
    }
    step = sqrt(step) * 2.f;

L300:
    dr[25] = ck;
    dr[26] = step;
    dr[27] = one;
    if (tnsq > smal) {
	dr[27] = step / sqrt(tnsq);
    }

/* L999: */
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER DGEOM", (ftnlen)20, (ftnlen)12);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c__1, &c__1, "U   ", u, (ftnlen)4);
    bad_(&c__1, &c__1, "V   ", v, (ftnlen)4);
    bad_(&c__1, &c__0, "IDTP", idtype, (ftnlen)4);
    bad_(&c__1, &c__0, "IDAX", idaxis, (ftnlen)4);
    bad_(&c_n1, &c__0, "ITLD", itldir, (ftnlen)4);
    for (i__ = 1; i__ <= 33; i__ += 4) {
	bad_(&c_n4, &c__1, "DR  ", &dr[i__], (ftnlen)4);
/* L1998: */
    }
L1999:
    return 0;
} /* dgeom_ */

