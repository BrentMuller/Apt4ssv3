/* BALSRF.f -- translated by f2c (version 20100827).
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

/* Table of constant values */

static integer c__3 = 3;
static integer c__1 = 1;

/* *** SOURCE FILE : M0001043.V03   *** */

/* Subroutine */ int balsrf_(doublereal *surf, doublereal *side, doublereal *
	tc, doublereal *rad, doublereal *td, integer *npat, doublereal *u, 
	doublereal *v, doublereal *dist, doublereal *r__, doublereal *tol, 
	integer *mode, integer *irr)
{
    /* Initialized data */

    static doublereal one = 1.;
    static doublereal half = .5;
    static doublereal onebig = 1.00001;
    static integer mxsrch = 1;
    static integer mxnits = 25;
    static integer mxexch = 15;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal b[64], w, u1, v1, u2, v2, da, du, dv;
    static integer ir;
    static doublereal du1, dv1;
    static integer iok;
    static doublereal duk, dvk;
    static integer itop[24]	/* was [6][4] */;
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static integer nits, iflag[6], ifree, isrch;
    extern /* Subroutine */ int sqrbn_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *), balloc_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *), balone_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), balscn_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
    static integer iexchg;
    extern /* Subroutine */ int lodpch_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *), baltol_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static integer ioklas;
    extern /* Subroutine */ int chktop_(doublereal *, doublereal *, integer *,
	     integer *), baltwo_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *);
    static integer maxrep;
    extern /* Subroutine */ int cnsurf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);

/*           /-PURPOSE IS TO DETERMINE CONTACT POINT FROM TOOL TO SURFACE */
/*           /-INPUT */
/*           /-SURF INPUT SCULPTURED SURFACE */
/*           /- 1 OR -1 TO INDICATE CUTTING SIDE OF SURFACE */
/*           /-TC,TD,RAD TOOL CENTER, RADIUS AND DIRECTION */
/*           /-TOL TOLERANCE FOR TOOL ALIGNMENT */
/*           /-MODE 0 FOR FIRST CALL, 1 FOR CONTINUING CALLS */
/*           /-OUTPUT */
/*           /-NPAT,U,V OUTPUT PATCH NUMBER AND U,V COORDS AT CONTACT */
/*           /-DIST DISTANCE TOOL MUST MOVE TO CONTACT POINT */
/*           /-R SURFACE DERIVATIVES AT POINT OF CONTACT */
/*           /-IRR ERROR FLAG, 0 IF NO ERROR, NON ZERO OTHERWISE. */

    /* Parameter adjustments */
    --r__;
    --td;
    --tc;
    --surf;

    /* Function Body */

/*            /-ISRCH IS A COUNT OF CALLS FOR GLOBAL SEARCH */
/*            /-IEXCHG IS A COUNT OF PATCH EXCHANGES */
    isrch = 0;
    iexchg = 0;
    u1 = *u;
    v1 = *v;
/* ***  CALL BAD(-1,0,4HMODE,MODE) */
/* ***  CALL BAD(1,0,4HU   ,U) */
/* ***  CALL BAD(-1,0,4HV   ,V) */

    if (*mode == 0) {
	goto L20;
    }
L10:
/*           /-INITIAL ENTRY OR RELOAD PATH */
    ++isrch;
    *irr = 1;
    if (isrch > mxsrch) {
	goto L999;
    }

    balscn_(&surf[1], side, &tc[1], rad, &td[1], &u1, &v1, dist, npat, &ir);
/* ***  CALL BAD(1,0,4HBSCN,IR) */
/* ***  CALL BAD(1,1,4HDIST,DIST) */
/* ***  CALL BAD(1,1,4HU1  ,U1) */
/* ***  CALL BAD(1,1,4HV1  ,V1) */
/* ***  CALL BAD(-1,0,4HNPAT,NPAT) */
    *irr = 2;
    if (ir != 0) {
	goto L999;
    }

    lodpch_(&surf[1], b, iflag, itop, npat, &c__3);

L20:
/*           /-SET ITERATION COUNTER FOR PATCH TO TOOL LINEUP */
    nits = 0;
    ioklas = 0;

L30:
/* ***  CALL BAD(-1,0,4HNITS,NITS) */
    ++nits;
    if (nits > mxnits) {
	goto L10;
    }
/*           /-CALCULATE SURFACE DERIVATIVES AT THIS U,V */
    cnsurf_(&u1, &v1, b, &r__[1], iflag, &c__1);
/* ***  CALL BAD(-12,1,4HCNSF,R) */
/*           /- DETERMINE IF PATCH IS WITHIN TOLERANCE OF TOOL YET */
    baltol_(&r__[1], side, &tc[1], rad, &td[1], dist, tol, &iok);
/* ***  CALL BAD(1,1,4HTOL ,TOL) */
/* ***  CALL BAD(1,1,4HDIST,DIST) */
/* ***  CALL BAD(-1,0,4HIOK ,IOK) */
    if (iok != 0) {
	goto L40;
    }
/*           /-TOOL IN TOLERANCE , EXAMINE U,V VALUES FURTHER */
    chktop_(&u1, &v1, itop, &iok);
/* ***  CALL BAD(2,2,4HU1  ,U1) */
/* ***  CALL BAD(2,2,4HV1   ,V1) */
/* ***  CALL BAD(-1,0,4HCTOP,IOK) */
    *irr = 0;
    if (iok == 0) {
	goto L100;
    }

L70:
/* ***  CALL BAD(-1,0,4HEXCG,IEXCHG) */
    ++iexchg;
    *irr = 3;
    if (iexchg > mxexch) {
	goto L999;
    }
    *npat = iok;
/*            /-IOK IS A CANDIDATE PATCH IF NON ZERO. */
    u1 = half;
    v1 = half;
    lodpch_(&surf[1], b, iflag, itop, npat, &c__3);
    ifree = 0;
    maxrep = 5;
    balloc_(b, iflag, itop, side, &tc[1], rad, &td[1], &u1, &v1, dist, &
	    maxrep, &ifree, irr);
/* ***  CALL BAD(1,0,4HBLOC,IRR) */
/* ***  CALL BAD(1,1,4HU1  ,U1) */
/* ***  CALL BAD(1,1,4HV1  ,V1) */
/* ***  CALL BAD(-1,1,4HDIST,DIST) */
    if (*irr != 0) {
	goto L10;
    }
    goto L20;

L40:
    balone_(&r__[1], side, &tc[1], rad, &td[1], &du, &dv, &da, irr);
/* ***  CALL BAD(1,0,4HBONE,IRR) */
/* ***  CALL BAD(1,1,4HDU  ,DU) */
/* ***  CALL BAD(1,1,4HDV  ,DV) */
/* ***  CALL BAD(-1,1,4HDA  ,DA) */
    duk = du;
    dvk = dv;
    maxrep = 25;
    baltwo_(&r__[1], side, &tc[1], rad, &td[1], &du, &dv, &da, &maxrep, tol, 
	    irr);
/* ***  CALL BAD(1,0,4HBTWO,IRR) */
/* ***  CALL BAD(1,1,4HDU  ,DU) */
/* ***  CALL BAD(1,1,4HDV  ,DV) */
/* ***  CALL BAD(-1,1,4HDA  ,DA) */
    if (*irr == 0) {
	goto L50;
    }
    du = duk;
    dv = dvk;
L50:
/* ***  CALL BAD(2,2,4HU1  ,U1) */
/* ***  CALL BAD(-2,2,4HV1  ,V1) */
/* ***  CALL BAD(2,2,4HDU  ,DU) */
/* ***  CALL BAD(-2,2,4HDV  ,DV) */
    sqrbn_(&u1, &v1, &du, &dv, &duk, &dvk, &one, &iok);
/* ***  CALL BAD(2,2,4HDUK ,DUK) */
/* ***  CALL BAD(-2,2,4HDVK ,DVK) */
/* ***  CALL BAD(-1,0,4HSRBN,IOK) */
    if (iok == 0 || iok == 5) {
	goto L60;
    }
    if (ioklas != 0) {
	goto L55;
    }
/*             /-CASE.  IOK.NE.0.AND.IOKLAS.EQ.0 */
/*             /-CUT DU,DV TO LIE WITHIN PRESENT SECTOR AND PROCEED AGAIN */
    du = duk;
    dv = dvk;
    goto L60;
L55:
/*             /-CASE.  IOK.NE.0.AND.IOKLAS.NE.0 */
/*             /-SET DU,DV SO THAT POINT MOVES TO NEW SECTOR */
/*             /-CHECK TO SEE IF THE NEW MOVEMENT IS SMALL */
    dotv_(&w, &r__[5], &r__[5]);
    du1 = du * sqrt(w);
    dotv_(&w, &r__[9], &r__[9]);
    dv1 = dv * sqrt(w);
/* Computing 2nd power */
    d__1 = du1;
/* Computing 2nd power */
    d__2 = dv1;
    if (sqrt(d__1 * d__1 + d__2 * d__2) > *tol / 2.f) {
	goto L56;
    }
/*             /-MOVEMENT IS WITHIN TOLERANCE BAND */
    iok = 0;
    du = duk;
    dv = dvk;
    goto L60;

L56:
    du = duk * onebig;
    dv = dvk * onebig;
    u2 = u1 + du;
    v2 = v1 + dv;
/*             /-CHECK TO SEE IF NEW U,V LIE IN LEGITIMATE REGION */
/*             /-ELSE, OBTAIN A NEW PATCH. */
    chktop_(&u2, &v2, itop, &iok);
/* ***  CALL BAD(-1,0,4HCKTP,IOK) */
/* ***  CALL BAD(2,2,4HU2  ,U2) */
/* ***  CALL BAD(2,2,4HV2  ,V2) */
/* ***  CALL BAD(1,1,4HU2  ,U2) */
/* ***  CALL BAD(-1,1,4HV2  ,V2) */
    if (iok == 0) {
	goto L60;
    }
    ioklas = 0;
    *npat = iok;
    goto L70;

L60:
    ioklas = iok;
    u1 += du;
    v1 += dv;
    *dist = da;
/* ***  CALL BAD(1,0,4H101 ,IOK) */
/* ***  CALL BAD(1,1,4HU1  ,U1) */
/* ***  CALL BAD(1,1,4HV1  ,V1) */
/* ***  CALL BAD(-1,1,4HDIST,DIST) */
    *irr = 0;
    goto L30;

L100:
    *u = u1;
    *v = v1;

L999:
    return 0;
} /* balsrf_ */

