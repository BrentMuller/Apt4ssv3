/* TECALC.f -- translated by f2c (version 20100827).
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
    doublereal tlhite[8], tanhi[8], tanlo[8], umax[8], ri[8], corrad[8], 
	    tcont[9], tlinc[9];
} tlldat_;

#define tlldat_1 tlldat_

struct {
    char darray[120];
} darray_;

#define darray_1 darray_

/* Table of constant values */

static doublereal c_b3 = 1.;
static integer c__1 = 1;
static integer c__38 = 38;
static integer c__71 = 71;
static integer c__101 = 101;
static integer c_n1 = -1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c_n3 = -3;

/* *** SOURCE FILE : TECALC.ORG   *** */

/* Subroutine */ int tecalc_(doublereal *r__, doublereal *ta, doublereal *u, 
	doublereal *pside, doublereal *pthick, doublereal *tolcom, doublereal 
	*tul, doublereal *te)
{
    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k;
    static doublereal v[3], vn[3];
    extern /* Subroutine */ int bad_();
    static doublereal vec[3], cang;
    static real tbef;
    static integer ibug;
    static doublereal sang, tang;
#define cosl ((doublereal *)&tlldat_1 + 16)
#define sinl ((doublereal *)&tlldat_1 + 8)
    extern /* Subroutine */ int dotv_(doublereal *, doublereal *, doublereal *
	    );
    static doublereal vlen2;
    extern /* Subroutine */ int cform_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), cross_(doublereal *, doublereal *, doublereal *),
	     vnorm_(doublereal *, doublereal *);
    static char badmsg[20];
    static doublereal offset;
    extern /* Subroutine */ int cprint_(char *, ftnlen), crossv_(doublereal *,
	     doublereal *, doublereal *);


/*     PURPOSE: COMPUTE TE GIVEN CURRENT CONTACT POINT R AND TA */


/*     ARGUMENTS: */
/*      R      - INPUT SURFACE CONTACT POINT/DERIVATIVES(SEE CNSURF) */
/*      TA     - INPUT TOOL AXIS */
/*      U      - LOCAL FORWARD DIRECTION */
/*      PSIDE  - INPUT 1 OR -1, DEFINES CUTTER SIDE OF SURFACE */
/*      PTHICK - PART GEOMETRY THICK SPECIFICATION */
/*      TOLCOM - TOLERANCE BAND COMPENSATION */
/*      TUL    - CUTTER PARAMETERS */
/*      TE     - OUTPUT TOOL END */


/*     GLOBAL VARIABLES: */


/*    TOOL DATA STORAGE */

/*    NOTE: 'TANHI' AND 'SINL' SHARE LOCATIONS AS DO 'TANLO' AND 'COSL' */
/*           THIS IS DELIBERATE. */





/*     LOCAL VARIABLES: */

/*       OFFSET - TOOL OFFSET FROM SURFACE */
/*       VEC    - TOOL RADIAL AXIS */
/*       VLEN2  - LENGTH OF VEC SQUARED */
/*       V,VN   - WORK VECTORS */
/*       CANG   - COS(ANGLE BETWEEN TOOL NORMAL AND TOOL RADIAL AXES) */
/*       SANG   - SINE OF SAME ANGLE */
/*       TANG   - TANGENT OF SAME ANGLE */
/*       BADMSG - DIAGNOSTIC MESSAGE */


/*   ***  20.  DARRAY BLOCK  *** */

/*   PRINT BUFFER */




/*     GENERAL CASE,TOOL OFFSET FROM SURFACE */
    /* Parameter adjustments */
    --te;
    --tul;
    --u;
    --ta;
    --r__;

    /* Function Body */
    offset = *pside * (*pthick + *tolcom);
/*     COMPUTE TOOL RADIAL AXIS */
    cross_(&ta[1], &r__[29], vec);
/* ...IF TA IS PARALLEL TO SN USE U (FWD) TO DETERMINE TOOL RADIAL AXIS */
    vlen2 = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
    if (vlen2 < 1e-12) {
	crossv_(&ta[1], &u[1], vec);
    } else {
	for (i__ = 1; i__ <= 3; ++i__) {
	    vec[i__ - 1] = *pside * vec[i__ - 1];
/* L20: */
	}
    }
    crossv_(vec, &ta[1], vec);
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
		te[k] = r__[k] + (offset + *pside * tlldat_1.corrad[i__ - 1]) 
			* r__[k + 28] + tlldat_1.ri[i__ - 1] * vec[k - 1] - 
			tlldat_1.tlhite[i__ - 1] * ta[k];
/* L25: */
	    }
	    goto L999;
	}
/* L30: */
    }
/* ...NO - IS ANGLE VALID FOR TOOL TIP */
    if (tlldat_1.tcont[1] > 0. && (tang - tlldat_1.tanlo[0]) * (tang - 
	    tlldat_1.tanhi[0]) <= 0.) {
/* ...YES - OUTPUT WARNING */
	cform_(" *** WARNING - CUTTING ON TOOL TIP ***", darray_1.darray, &
		c__1, &c__38, (ftnlen)38, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	for (k = 1; k <= 3; ++k) {
	    te[k] = r__[k] + offset * r__[k + 28];
/* L40: */
	}
/* ...NO - IS ANGLE VALID FOR TOP OF UPPER LINE SEGMENT */
    } else if (tlldat_1.tcont[7] > 0. && (tang - tlldat_1.tanlo[6]) * (tang - 
	    tlldat_1.tanhi[6]) <= 0.) {
/* ...YES - OUTPUT WARNING */
	cform_(" *** WARNING - CUTTING ON POINT CIRCLE AT TOP OF UPPER LINE "
		"SEGMENT ***", darray_1.darray, &c__1, &c__71, (ftnlen)71, (
		ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);
	for (k = 1; k <= 3; ++k) {
	    te[k] = r__[k] + offset * r__[k + 28] + tlldat_1.ri[6] * vec[k - 
		    1] - tlldat_1.tlhite[6] * ta[k];
/* L50: */
	}
/* ...NO - INVALID ANGLE FOR THIS CUTTER */
    } else {
	cform_(" *** WARNING - UNABLE TO POSITION 7 SEGMENT CUTTER AT CURREN"
		"T SURFACE POINT - SPHERICAL CUTTER ASSUMED", darray_1.darray, 
		&c__1, &c__101, (ftnlen)102, (ftnlen)120);
	cprint_(darray_1.darray, (ftnlen)120);

    }
L999:
    if (ibug != 11) {
	goto L1999;
    }
    bad_(&c_n1, &c__0, " ", &c__0, (ftnlen)1);
    s_copy(badmsg, " AFTER TECALC", (ftnlen)20, (ftnlen)13);
    cprint_(badmsg, (ftnlen)20);
    bad_(&c_n1, &c__1, "TCOM", tolcom, (ftnlen)4);
    bad_(&c__3, &c__1, "TE  ", &te[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TA  ", &ta[1], (ftnlen)4);
    bad_(&c_n3, &c__1, "TBEF", &tbef, (ftnlen)4);
L1999:

    return 0;
} /* tecalc_ */

#undef sinl
#undef cosl


