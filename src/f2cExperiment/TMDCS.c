/* TMDCS.f -- translated by f2c (version 20100827).
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

static integer c__97 = 97;
static integer c__0 = 0;

/* *** SOURCE FILE : M0008178.V02   *** */

/* Subroutine */ int tmdcs_(doublereal *trm, doublereal *data)
{
    /* Initialized data */

    static doublereal ntrm[12] = { 1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0. };

    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal trm1[12];
    extern /* Subroutine */ int apt066_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal scale;
    extern /* Subroutine */ int error_(integer *, char *, ftnlen);
    static doublereal scales;

/* PROGRAM TO TRANSFORM THE PATCH GEOMETRY */
/*  OF "MASTER DIMENSION CONTOUR SURFACE" */

/*   TRANSFORMATION MATRIX */
/*   PATCH DATA */
/*   AUXILIARY MATRIX */
/*   'NO TRANSFORMATION' MATRIX */
/*   SCALE FACTOR */

    /* Parameter adjustments */
    --data;
    --trm;

    /* Function Body */

/*   TEST PRINT */
/*     WRITE(6,100) */
/* 100 FORMAT('0TMDCSSSS WAS CALLED') */
/*    PRESET OF SCALE FACTOR */
    scale = 1.;
/*    SQUARED SCALE FACTOR */
/* Computing 2nd power */
    d__1 = trm[1];
/* Computing 2nd power */
    d__2 = trm[2];
/* Computing 2nd power */
    d__3 = trm[3];
    scales = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/*    COMPUTATION OF SCALE FACTOR */
    if ((d__1 = scales - 1., abs(d__1)) >= 1e-10) {
	scale = sqrt(scales);
    }
/*    TEST IF ALL SCALE FACTORS EQUAL */
/* Computing 2nd power */
    d__3 = trm[5];
/* Computing 2nd power */
    d__4 = trm[6];
/* Computing 2nd power */
    d__5 = trm[7];
/* Computing 2nd power */
    d__6 = trm[9];
/* Computing 2nd power */
    d__7 = trm[10];
/* Computing 2nd power */
    d__8 = trm[11];
    if ((d__1 = d__3 * d__3 + d__4 * d__4 + d__5 * d__5 - scales, abs(d__1)) <
	     1e-10 && (d__2 = d__6 * d__6 + d__7 * d__7 + d__8 * d__8 - 
	    scales, abs(d__2)) < 1e-10) {
	goto L1;
    }
/*    NO TRANSFORMATION AND ERROR MESSAGE */
    error_(&c__97, "TMDCSSSS", (ftnlen)8);
    goto L99;
/*    MOVE OLD MATRIX TO SCATCH AREA */
L1:
    for (i__ = 1; i__ <= 12; ++i__) {
/* L2: */
	trm1[i__ - 1] = data[i__ + 18];
    }
/*    COMPUTE NEW TRANSFORMATION MATRIX */
    apt066_(&data[19], &trm[1], trm1, &c__0);
/*    PRESET SCALE FACTOR OF MATRIX */
    data[18] = scale;
/*    CHECK THE RESULT MATRIX FOR 'NO TRANSFORMATION' */
    for (i__ = 1; i__ <= 12; ++i__) {
	if ((d__1 = data[i__ + 18] - ntrm[i__ - 1], abs(d__1)) >= 1e-10) {
	    goto L99;
	}
/* L3: */
    }
/*    SWITCH OFF TRANSFORMATION */
    data[18] = 0.;
L99:
    return 0;
} /* tmdcs_ */

