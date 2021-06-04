/* CPLDST.f -- translated by f2c (version 20100827).
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
    logical ssprt, sstest;
} ssprt_;

#define ssprt_1 ssprt_

struct {
    integer id[24];
    doublereal obnam1;
    integer jcseg, ncseg, icseg[10], nlioci[10];
    doublereal cosal[10], sinal[10], cuty[10], cutx[10], cutl[10];
} plgol_;

#define plgol_1 plgol_

/* Table of constant values */

static integer c__22223 = 22223;
static integer c__1 = 1;
static integer c__0 = 0;

/* *** SOURCE FILE : M0012230.V01   *** */

/* Subroutine */ int cpldst_(doublereal *spv, doublereal *plane, doublereal *
	th, integer *iwas, doublereal *dist, integer *iret)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal tp[3], vt[3], vt2[3];
    extern /* Subroutine */ int bad_(integer *, integer *, char *, integer *, 
	    ftnlen);
    static doublereal vll, fact;
    extern /* Subroutine */ int aerr_(integer *, char *, ftnlen), cross_(
	    doublereal *, doublereal *, doublereal *);
    static doublereal cosang;


/*   ROUTINE TO CALCULATE THE DISTANCE OF A CUTTER TO/ON/PAST POINT */
/*    TO A PLANE */



/*  CONTROL OF TEST-OUTPUT */

/*  INPUT EVALUATION VALUES OF CUTTER POSITION */

/*  INPUT PLANE */

/*  INPUT THICKNES */

/*  INPUT TO/ON/PAST TYPE (2/3/4) */

/*  OUTPUT DISTANCE */

/*  OUTPUT RETURN CODE (=0 IF OK) */

/*  TOOL POINT,HELP VECTORS */

/*  GOLOFT/PLOTFT COMMON */

/*  USED CUTTER SEGMENT */

/*  NUMBER OF VALID CUTTER SEGMENTS */

/*  CUTTER SEGMENT IN TLLDAT ARRAYS */

/*  NATURE OF SEGMENT */

/*  COMPONENTS OF SEGMENT AND UNIT NORMAL POINTING INTO THE CUTTER */

/*  DISTANCE PARALLEL TO THE CUTTER AXIS */

/*  DISTANCE TO THE CUTTER AXIS */

/*  ELEMENT LENGTH */


/* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA */

/* CHECK TOOL POSITION INFORMATION */
    /* Parameter adjustments */
    --plane;
    --spv;

    /* Function Body */
    if (*iwas >= 2 && *iwas <= 4) {
	goto L5;
    }
    *iret = max(*iret,1);
    if (! ssprt_1.sstest) {
	return 0;
    }

/*  WRONG TOOL AXIS INFORMATION. */
    aerr_(&c__22223, "CPLDST  ", (ftnlen)8);
    bad_(&c__1, &c__0, "IWAS", iwas, (ftnlen)4);
    return 0;

/*  MOVE TOOL TIP */
L5:
    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
	tp[i__ - 1] = spv[i__ + 32];
    }

/*  ON-CONDITION ? */
    if (*iwas == 3) {
	goto L90;
    }

/*  COMPUTE COSIN OF ANGLE BETWEEN TOOL AXIS AND PLANE */
    cosang = spv[37] * plane[1] + spv[38] * plane[2] + spv[39] * plane[3];
    if (*iwas == 4) {
	cosang = -cosang;
    }

/*  FIND TOOL SEGMENT */
    i__1 = plgol_1.ncseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (plgol_1.nlioci[i__ - 1] == 1) {
	    goto L20;
	}
	plgol_1.jcseg = i__;
	if (plgol_1.cosal[i__ - 1] <= cosang) {
	    goto L25;
	}
L20:
	;
    }

/*  COMPUTE VECTOR PERPTO AXIS AND PERPTO PLANE NORMAL */
L25:
    cross_(&plane[1], &spv[37], vt);

/*  COMPUTE LENGTH OF THIS VECTOR */
    vll = vt[0] * vt[0] + vt[1] * vt[1] + vt[2] * vt[2];

/*  TAKE ONLY TOOL TIP, IF VLL TOO SMALL */
    if (vll <= 1e-10) {
	goto L90;
    }
    vll = sqrt(vll);

/*  COMPUTE VECTOR PERPENTICULAR TO TOOL AXIS AND POINTING TO PLANE */
    cross_(vt, &spv[37], vt2);

/*  INVERT VLL FOR PAST CONDITION */
    if (*iwas == 4) {
	vll = -vll;
    }

/*  COMPUTE FACTOR FOR TO AND PAST CONDITION */
    fact = 1.;
    if (*iwas == 4) {
	fact = -1.;
    }

/*  COMPUTE CUTTER POINT */
    for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	tp[i__ - 1] = tp[i__ - 1] + spv[i__ + 36] * plgol_1.cuty[
		plgol_1.jcseg - 1] + vt2[i__ - 1] * plgol_1.cutx[
		plgol_1.jcseg - 1] / vll - plane[i__] * (plgol_1.cutl[
		plgol_1.jcseg - 1] + *th) * fact;
    }

/*  COMPUTE DISTANCE */
L90:
    *dist = tp[0] * plane[1] + tp[1] * plane[2] + tp[2] * plane[3] - plane[4];

    return 0;
} /* cpldst_ */

