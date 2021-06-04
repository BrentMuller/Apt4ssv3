/* TULPOS.f -- translated by f2c (version 20100827).
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
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    doublereal alpha, beta, cosa, cosb, sina, sinb;
    integer itac;
} tac_;

#define tac_1 tac_

/* Table of constant values */

static doublereal c_b3 = 1.;
static integer c__1 = 1;
static integer c__38 = 38;
static integer c__71 = 71;
static integer c__101 = 101;
static integer c__3 = 3;
static integer c_n3 = -3;
static integer c_n1 = -1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0001126.W07   *** */

/* Subroutine */ int tulpos_(doublereal *r__, doublereal *side, doublereal *
	dr, doublereal *tul, doublereal *pthick, doublereal *tolcom, integer *
	iptool, integer *idtool, doublereal *te, doublereal *ta, doublereal *
	tbef, doublereal *pdir)
{
    /* Initialized data */

    static doublereal vecl[3] = { 0.,0.,0. };
    static logical lfirst = TRUE_;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k;
    static doublereal v[3], vn[3];
    extern /* Subroutine */ int bad_();
    static doublereal vec[3], fwd[3], sgn, nps[3], cang, sang, tang;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    static doublereal roll[3];
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal vlen2;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    static doublereal pitch[3];
    extern /* Subroutine */ int cross_(doublereal *, doublereal *, doublereal 
	    *), vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    extern /* Subroutine */ int vscale_(doublereal *, doublereal *, 
	    doublereal *);
    static char darray[120];
    static doublereal offset;
    extern /* Subroutine */ int cprint_(char *, ftnlen), crossv_(doublereal *,
	     doublereal *, doublereal *);


/* -- R     INPUT SURFACE CONTACT POINT/DERIVATIVES(SEE CNSURF) */
/* -- SIDE  INPUT 1 OR -1, DEFINES CUTTER SIDE OF SURFACE */
/* -- DR    DRIVE ELEMENT POINT/DERIVATIVES(SEE DGEOM) */
/* -- TUL   CUTTER PARAMETERS */
/* -- PTHICK PART GEOMETRY THICK SPECIFICATION */
/* -- TOLCOM TOLERANCE BAND COMPENSATION */
/* -- IPTOOL PART SURFACE CONTROL FLAG( 0 FOR ON, 1 FOR TO) */
/* -- IDTOOL DRIVE ELEMENT CONTROL FLAG */
/* -- TE   OUTPUT TOOL END */
/* -- TA   OUTPUT TOOL AXIS */
/* -- TBEF OUTPUT EFFECTIVE TOOL END BASED ON SPHERICAL CUTTER */
/* -- PDIR DIRECTION OF MOTION WRT INCREASING PARAMETER (+1 OR -1) */
/* --PURPOSE IS TO COMPUTE TOOL END AND TOOL AXIS WHEN AN A */
/* --ACCEPTABLE SURFACE CONTACT POINT HAS BEEN FOUND */
/* --TOOL CANONICAL DATA */
/* --TOOL AXIS CONTROL DATA */

/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */




/* --INITIALZE VECL AND FIRST CALL FLAG */


/*     ALPHA  TOOL AXIS SLEW ANGLE WRT SN */
/*            IN GUIDE SURFACE CRSSPL DIRN. IF PATH IN TANSPL DIRN. */
/*            AND VICE VERSA */
/*     BETA   TOOL AXIS TILT ANGLE (CUTANG) WRT SN */
/*            IN PATH DIRECTION */
/*     COSA   COS(ALPHA) */
/*     COSB   COS(BETA) */
/*     SINA   SIN(ALPHA) */
/*     SINB   SIN(BETA) */
/*     ITAC   FLAG INDICATING THAT ATANGL TYPE TOOL AXIS CONTROL */
/*            IS REQUIRED =1, =0 FOR FIXED OR NORMDS */

/* --SAVE LAST DIRECTION FROM SP TOWARDS TOOL AXIS,AND FLAG LFIRST */

    /* Parameter adjustments */
    --tbef;
    --ta;
    --te;
    --tul;
    --dr;
    --r__;

    /* Function Body */

/* --FOR FIRST CALL (LFIRST=.TRUE.) SET VECL TO REV. MOTION DIRECTION */
    if (lfirst) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    vecl[i__ - 1] = *pdir * -1.f * dr[i__ + 12];
/* L5: */
	}
	lfirst = FALSE_;
    }
/* .... IF TOOL AXIS CONTROL WRT PS - COMPUTE LOCAL PITCH AND ROLL AXES */
    if (tac_1.itac == 2) {
/* .... GUIDE SURFACE FORWARD DIRECTION - PDIR*(DRIVE TANGENT VECTOR) */
	vscale_(pdir, &dr[13], fwd);
/* .... CUTTER SIDE OF PART SURFACE */
	vscale_(side, &r__[29], nps);
/* .... COMPUTE UNIT VECTOR PERPENDICULAR TO GUIDE SURFACE FORWARD AND */
/*     PROJECTION VECTORS */
	crossv_(fwd, &dr[21], v);
/* .... COMPUTE LOCAL FORWARD MOTION DIRECTION IN PS TANGENT PLANE */
/*           (ROLL AXIS) */
	crossv_(nps, v, roll);
/* .... COMPUTE LOCAL AXIS ORTHOGONAL WITH ROLL AXIS AND PS NORMAL */
/*           (PITCH AXIS) */
	crossv_(nps, roll, pitch);
/* .... DETERMINE DIRECTION IN WHICH ROLL ANGLE IS TO BE APPLIED */
/*     POSITIVE IN STEPOVER DIRECTION */
	dotv_(&sgn, pitch, &dr[29]);
	sgn = d_sign(&c_b3, &sgn);
    }
/* -- TWO MAIN CASES, TOOL ON PS OR NOT ON. */
    if (*iptool != 0) {
	goto L50;
    }
/* --GENERAL CASE, TOOL OFFSET FROM SURFACE */
    offset = *side * (*pthick + *tolcom + tul[1]);
    for (i__ = 1; i__ <= 3; ++i__) {
	if (tac_1.itac == 1) {
/* .... APPLY CUTANG BETA TO TA IN DIRECTION OF MOTION */
	    ta[i__] = tac_1.cosb * dr[i__ + 16] + *pdir * tac_1.sinb * dr[i__ 
		    + 12];
	} else if (tac_1.itac == 2) {
/* .... APPLY BETA WRT TO PS NORMAL IN MOTION DIRECTION */
/*     AND ALPHA IN PLANE PERPENDICULAR TO MOTION DIRECTION */
	    ta[i__] = tac_1.cosa * tac_1.cosb * nps[i__ - 1] + tac_1.sinb * 
		    roll[i__ - 1] + sgn * tac_1.sina * tac_1.cosb * pitch[i__ 
		    - 1];
	} else {
	    ta[i__] = dr[i__ + 16];
	}
	tbef[i__] = r__[i__] + offset * r__[i__ + 28] - tul[1] * ta[i__];
/* L10: */
    }
/* --GENERAL CUTTER CALCULATION. */
    cross_(&ta[1], &r__[29], vec);
/* ...IF TA IS PARALLEL TO SN USE PREVIOUS VALUE OF VEC INSTEAD OF SN */
    vlen2 = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
    if (vlen2 < 1e-12) {
	cross_(&ta[1], vecl, vec);
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L20: */
	vec[i__ - 1] = *side * vec[i__ - 1];
    }
    cross_(vec, &ta[1], vec);
    vnorm_(vec, vec);
/* ...MODIFY OFFSET FOR 7 SEGMENT CUTTER CALCULATION */
    offset -= *side * tul[1];
    for (i__ = 1; i__ <= 3; ++i__) {
	vecl[i__ - 1] = vec[i__ - 1];
/* L32: */
    }
/* ...COMPUTE TANGENT OF ANGLE BETWEEN TOOL NORMAL AND TOOL RADIAL AXIS */
    dotv_(&cang, vec, &r__[29]);
    cross_(vec, &r__[29], v);
    vnorm_(v, vn);
    dotv_(&sang, v, vn);
    if (abs(cang) > 1e-15) {
	tang = sang / cang;
    } else {
	tang = d_sign(&c_b3, &sang) * 1e15;
    }
/* ...IS ANGLE VALID FOR SEGMENTS 3,4,5 OF CUTTER */
/*   I.E. CORNER RADIUS AND ADJACENT POINT CIRCLE SEGMENTS */
    for (i__ = 3; i__ <= 5; ++i__) {
	if (tlldat_1.tcont[i__] > 0. && (tang - tlldat_1.tanlo[i__ - 1]) * (
		tang - tlldat_1.tanhi[i__ - 1]) <= 0.) {
/* ...COMPUTE TOOL END COORDS */
	    for (k = 1; k <= 3; ++k) {
		te[k] = r__[k] + (offset + *side * tlldat_1.corrad[i__ - 1]) *
			 r__[k + 28] + tlldat_1.ri[i__ - 1] * vec[k - 1] - 
			tlldat_1.tlhite[i__ - 1] * ta[k];
/* L34: */
	    }
	    goto L999;
	}
/* L35: */
    }
/* ...NO - IS ANGLE VALID FOR TOOL TIP */
    if (tlldat_1.tcont[1] > 0. && (tang - tlldat_1.tanlo[0]) * (tang - 
	    tlldat_1.tanhi[0]) <= 0.) {
/* ...YES - OUTPUT WARNING */
	cform_(" *** WARNING - CUTTING ON TOOL TIP ***", darray, &c__1, &
		c__38, (ftnlen)38, (ftnlen)120);
	cprint_(darray, (ftnlen)120);
	for (k = 1; k <= 3; ++k) {
	    te[k] = r__[k] + offset * r__[k + 28];
/* L40: */
	}
/* ...NO - IS ANGLE VALID FOR TOP OF UPPER LINE SEGMENT */
    } else if (tlldat_1.tcont[7] > 0. && (tang - tlldat_1.tanlo[6]) * (tang - 
	    tlldat_1.tanhi[6]) <= 0.) {
/* ...YES - OUTPUT WARNING */
	cform_(" *** WARNING - CUTTING ON POINT CIRCLE AT TOP OF UPPER LINE "
		"SEGMENT ***", darray, &c__1, &c__71, (ftnlen)71, (ftnlen)120);
	cprint_(darray, (ftnlen)120);
	for (k = 1; k <= 3; ++k) {
	    te[k] = r__[k] + offset * r__[k + 28] + tlldat_1.ri[6] * vec[k - 
		    1] - tlldat_1.tlhite[6] * ta[k];
/* L42: */
	}
/* ...NO - INVALID ANGLE FOR THIS CUTTER */
    } else {
	cform_(" *** WARNING - UNABLE TO POSITION 7 SEGMENT CUTTER AT CURREN"
		"T SURFACE POINT - SPHERICAL CUTTER ASSUMED", darray, &c__1, &
		c__101, (ftnlen)102, (ftnlen)120);
	cprint_(darray, (ftnlen)120);

	for (k = 1; k <= 3; ++k) {
	    te[k] = tbef[k];
/* L45: */
	}
    }
/* ...PRINT USEFUL DIAGNOSTIC INFORMATION WHEN WARNINGS OCCUR */
    bad_(&c__3, &c__1, "SP  ", &r__[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "SN  ", &r__[29], (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", &ta[1], (ftnlen)4);
    bad_(&c__3, &c__1, "VEC ", vec, (ftnlen)4);
    bad_(&c_n3, &c__1, "VECL", vecl, (ftnlen)4);
    bad_(&c_n1, &c__1, "TANG", &tang, (ftnlen)4);
    goto L999;
L50:
/* --TOOL TIP ON PART SURFACE */
    for (i__ = 1; i__ <= 3; ++i__) {
	if (tac_1.itac == 1) {
/* .... APPLY CUTANG BETA TO TA IN DIRECTION OF MOTION */
	    ta[i__] = tac_1.cosb * dr[i__ + 16] + *pdir * tac_1.sinb * dr[i__ 
		    + 12];
	} else {
	    ta[i__] = dr[i__ + 16];
	}
	te[i__] = r__[i__] + *side * *tolcom * r__[i__ + 28];
	tbef[i__] = te[i__];
/* L60: */
    }

L999:
    if (ibugg_1.ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER TULPOS", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c_n1, &c__1, "TCOM", tolcom, (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", &ta[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TBEF", &tbef[1], (ftnlen)4);
L1999:

    return 0;
} /* tulpos_ */

#undef sinl
#undef cosl


